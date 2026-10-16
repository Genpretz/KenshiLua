-- Animal Husbandry: shared helpers.
--
-- Provides logging, time, animal definitions from game data, player animal
-- enumeration, per-animal saved state, condition checks, and a task scheduler driven
-- by GameWorld::charsUpdate.
-- Feature scripts register tasks with AnimalHusbandry.addTask().

local AH = _G.AnimalHusbandry or {}
_G.AnimalHusbandry = AH

local PREFIX = "[AnimalHusbandry] "
local STATE_PREFIX = "AH_"

math.randomseed(os.time())

-- ---------------------------------------------------------------------------
-- Logging and messages
-- ---------------------------------------------------------------------------

local function joinArgs(...)
    local parts = {}
    for i = 1, select("#", ...) do
        parts[#parts + 1] = tostring((select(i, ...)))
    end
    return table.concat(parts, " ")
end

-- print() writes to both the KenshiLua log file and the KenshiLua console.
function AH.log(...)
    print(PREFIX .. joinArgs(...))
end

function AH.debugLog(...)
    if AH.config and AH.config.debug then
        print(PREFIX .. "[debug] " .. joinArgs(...))
    end
end

function AH.setDebug(on)
    AH.config.debug = on and true or false
    AH.log("debug logging", AH.config.debug and "on" or "off")
end

-- Shows a message to the player and adds it to the in-game message log. Messages are
-- queued, so several at once, such as simultaneous births, each get shown.
function AH.notify(message)
    AH.log(message)
    local ok, err = pcall(function()
        getGameWorld():showPlayerAMessage_withLog(message, true)
    end)
    if not ok then
        AH.log("could not show message: " .. tostring(err))
    end
end

-- ---------------------------------------------------------------------------
-- Time
-- ---------------------------------------------------------------------------

-- Total in-game days since the start of the game.
function AH.currentDay()
    return getGameWorld():getTimeStamp_inGameHours():getTotalDays()
end

-- ---------------------------------------------------------------------------
-- Game constants from FCS
--
-- Constants defined in fcs.def under [CONSTANTS] are stored in the engine's Game
-- Constants record (accessible via getGlobalConstants().settings). If set in FCS,
-- they override the defaults in 00_ah_config.lua.
-- ---------------------------------------------------------------------------

local CONSTANT_MAP = {
    { section = "breeding", field = "babyAge",            key = "breeding.babyAge" },
    { section = "breeding", field = "checkIntervalHours",  key = "breeding.checkIntervalHours" },
    { section = "breeding", field = "maxPairDistance",     key = "breeding.maxPairDistance" },
    { section = "breeding", field = "minAge",              key = "breeding.minAge" },
    { section = "harvest",  field = "minAge",              key = "harvest.minAge" },
    { section = "harvest",  field = "maxDistance",         key = "harvest.maxDistance" },
    { section = "harvest",  field = "maxVisibleProducts",  key = "harvest.maxVisibleProducts" },
    { section = "sales",    field = "defaultBasePrice",    key = "sales.defaultBasePrice" },
    { section = "sales",    field = "maxDistance",         key = "sales.maxDistance" },
}

local function getGameConstantsSettings()
    local ok, gc = pcall(function()
        return (getGlobalConstants and getGlobalConstants()) or _G.con
    end)
    if ok and gc and gc.settings then
        return gc.settings
    end
    return nil
end

local function readConstantNum(settings, key)
    if not settings then
        return nil, nil
    end
    local ok, v
    if settings.fdata then
        ok, v = pcall(function() return settings.fdata[key] end)
        if ok and type(v) == "number" then
            return v, "fdata"
        end
    end
    if settings.idata then
        ok, v = pcall(function() return settings.idata[key] end)
        if ok and type(v) == "number" then
            return v, "idata"
        end
    end
    return nil, nil
end

-- Reads game constants from the FCS Game Constants record and updates AH.config.
function AH.syncConstantsFromFCS()
    local settings = getGameConstantsSettings()
    if not settings or not AH.config then
        return false
    end

    local syncedCount = 0
    for i = 1, #CONSTANT_MAP do
        local def = CONSTANT_MAP[i]
        local val = readConstantNum(settings, def.key)
        if val ~= nil then
            if not AH.config[def.section] then
                AH.config[def.section] = {}
            end
            AH.config[def.section][def.field] = val
            syncedCount = syncedCount + 1
        end
    end
    return true, syncedCount
end

-- Console command: displays all Animal Husbandry constants, showing whether each is
-- loaded from FCS or falling back to the 00_ah_config.lua default.
function AH.printConstants()
    AH.syncConstantsFromFCS()
    local settings = getGameConstantsSettings()

    AH.log("Animal Husbandry constants:")
    for i = 1, #CONSTANT_MAP do
        local def = CONSTANT_MAP[i]
        local current = AH.config and AH.config[def.section] and AH.config[def.section][def.field]
        local _, src = readConstantNum(settings, def.key)
        local sourceLabel = src and ("FCS " .. src) or "default"
        AH.log(string.format("  %-28s = %s (%s)", def.key, tostring(current), sourceLabel))
    end
end

-- ---------------------------------------------------------------------------
-- Animal definitions from game data
--
-- The fields that fcs.def adds to ANIMAL_CHARACTER records, read from an animal's
-- own record (Character:getGameData()). The game does not read fcs.def, so a field
-- never set in FCS is absent from the record; FCS_DEFAULTS mirrors the defaults in
-- fcs.def for those. Definitions are cached by record string ID.
-- ---------------------------------------------------------------------------

-- basePrice has no default here: when it is not set in FCS, the sale window uses
-- sales.defaultBasePrice from the config.
local FCS_DEFAULTS = {
    sterile = true,
    offspring = 1,
    pregnancyPeriod = 1.0,
    pregnancyChance = 1.0,
    timeBetweenPregnancy = 1.0,
    matingGroup = "",
}

-- val2 of an "animal products" reference.
AH.PRODUCT_SEX = { [0] = "male", [1] = "female", [2] = "both" }

AH.defCache = {}

local function mapValue(map, key, default)
    local ok, v = pcall(function() return map[key] end)
    if ok and v ~= nil then
        return v, true
    end
    return default, false
end

-- Returns the records in a reference list as { { sid, data, v0, v1, v2 }, ... }.
local function referenceList(d, listName)
    local out = {}
    local list = d:getReferenceListIfExists(listName)
    if not list then
        return out
    end
    local gamedata = getGameWorld().gamedata
    for i = 1, list:size() do
        local ref = list[i]
        local v = ref.values.value
        local sid = tostring(ref.sid)
        out[#out + 1] = { sid = sid, data = gamedata:getData(sid), v0 = v[1], v1 = v[2], v2 = v[3] }
    end
    return out
end

-- Returns the husbandry definition of an ANIMAL_CHARACTER record:
--   { stringID, name, sterile, offspring, pregnancyPeriod, pregnancyChance,
--     timeBetweenPregnancy, basePrice (or nil), matingGroup,
--     set = { field = true for fields set in FCS },
--     products = { { itemID, data, name, amount, days, sex }, ... } }
function AH.defFromData(d)
    local sid = tostring(d.stringID)
    local cached = AH.defCache[sid]
    if cached then
        return cached
    end
    local def = { stringID = sid, name = tostring(d.name), set = {}, products = {} }
    local function read(map, key, field)
        local v, isSet = mapValue(map, key, FCS_DEFAULTS[field])
        def[field] = v
        def.set[field] = isSet or nil
    end
    read(d.bdata, "sterile", "sterile")
    read(d.idata, "number of offspring", "offspring")
    read(d.fdata, "pregnancy period", "pregnancyPeriod")
    read(d.fdata, "chance of pregnancy", "pregnancyChance")
    read(d.fdata, "time between pregnancy", "timeBetweenPregnancy")
    read(d.idata, "base price", "basePrice")
    read(d.sdata, "mating group", "matingGroup")

    local products = referenceList(d, "animal products")
    for i = 1, #products do
        local p = products[i]
        def.products[#def.products + 1] = {
            itemID = p.sid,
            data = p.data,
            name = p.data and tostring(p.data.name) or p.sid,
            amount = p.v0,
            days = p.v1,
            sex = AH.PRODUCT_SEX[p.v2] or ("unknown " .. tostring(p.v2)),
        }
    end

    AH.defCache[sid] = def
    return def
end

-- Returns the husbandry definition of a character's record, or nil.
function AH.animalDef(c)
    local d = c and c:getGameData()
    if not d then
        return nil
    end
    return AH.defFromData(d)
end

function AH.clearDefCache()
    AH.defCache = {}
    AH.syncConstantsFromFCS()
end

-- Console command: logs the definition of every ANIMAL_CHARACTER record used by a
-- player animal. Values marked "(default)" were not set in FCS.
function AH.listDefs()
    AH.clearDefCache()
    local seen = {}
    local chars = AH.playerCharacters()
    for i = 1, #chars do
        local c = chars[i]
        local d = c:isAnimal() and c:getGameData()
        if d and not seen[tostring(d.stringID)] then
            seen[tostring(d.stringID)] = true
            local def = AH.defFromData(d)
            local function show(field)
                return tostring(def[field]) .. (def.set[field] and "" or " (default)")
            end
            local _, raceName = AH.raceOf(c)
            AH.log(string.format("%s (%s), race %s, e.g. %s", def.name, def.stringID, tostring(raceName),
                tostring(c:getName())))
            AH.log("  sterile " .. show("sterile") .. " | offspring " .. show("offspring")
                .. " | pregnancy period (days) " .. show("pregnancyPeriod")
                .. " | chance per check (%) " .. show("pregnancyChance")
                .. " | time between (days) " .. show("timeBetweenPregnancy")
                .. " | mating group " .. (def.matingGroup ~= "" and ('"' .. def.matingGroup .. '"') or "none"))
            AH.log("  base price " .. (def.basePrice and tostring(def.basePrice)
                or (tostring(AH.config.sales.defaultBasePrice) .. " (default)")))
            if #def.products == 0 then
                AH.log("  products: none")
            end
            for j = 1, #def.products do
                local p = def.products[j]
                AH.log(string.format("  product %s (%s): %d at a time, every %d day(s), %s%s", p.name, p.itemID,
                    p.amount, p.days, p.sex, p.data and "" or " [ITEM NOT FOUND]"))
            end
        end
    end
    if next(seen) == nil then
        AH.log("listDefs: no animals in the player faction")
    end
end

-- Returns the race string ID and name of a character, or nil.
function AH.raceOf(c)
    local race = c.myRace
    local d = race and race.data
    if not d then
        return nil, nil
    end
    return d.stringID, d.name
end

-- ---------------------------------------------------------------------------
-- Player animals
-- ---------------------------------------------------------------------------

function AH.playerInterface()
    return getPlayerInterface() or player
end

function AH.playerCharacters()
    local out = {}
    local list = AH.playerInterface():getAllPlayerCharacters()
    if not list then
        return out
    end
    for i = 1, list:size() do
        local c = list[i]
        if c then
            out[#out + 1] = c
        end
    end
    return out
end

-- Returns an animal entry for a character, or nil if it is not an animal:
--   { char = Character, animal = CharacterAnimal, raceID = string, raceName = string,
--     templateID = ANIMAL_CHARACTER string ID, def = AH.animalDef(c) }
function AH.animalEntry(c)
    local a = c and c:isAnimal()
    if not a then
        return nil
    end
    local raceID, raceName = AH.raceOf(c)
    local def = AH.animalDef(c)
    return {
        char = c,
        animal = a,
        raceID = raceID,
        raceName = raceName,
        templateID = def and def.stringID,
        def = def,
    }
end

-- True if two animal entries can mate: they share the same race or record, or both
-- have a non-empty mating group whose names match (case-insensitively).
function AH.canMate(a, b)
    if a.raceID and a.raceID == b.raceID then
        return true
    end
    if a.templateID and a.templateID == b.templateID then
        return true
    end
    local ga = a.def and a.def.matingGroup or ""
    local gb = b.def and b.def.matingGroup or ""
    if ga ~= "" and gb ~= "" and string.lower(ga) == string.lower(gb) then
        return true
    end
    return false
end

-- Returns an animal entry for every animal in the player faction.
function AH.playerAnimals()
    local out = {}
    local chars = AH.playerCharacters()
    for i = 1, #chars do
        local e = AH.animalEntry(chars[i])
        if e then
            out[#out + 1] = e
        end
    end
    return out
end

function AH.selectedCharacter()
    local guiObj = getForgottenGUI() or gui
    local h = guiObj and guiObj.selectedObject
    if not h or h:isNull() then
        return nil
    end
    return h:getCharacter()
end

-- ---------------------------------------------------------------------------
-- Age, sex, and condition
-- ---------------------------------------------------------------------------

function AH.age(animal)
    return animal:getAge0to1()
end

-- Returns "pup", "teen", "adult", or "elder" from the measured stage boundaries.
function AH.stageOf(age)
    local st = AH.config.stages
    if age >= st.elder then
        return "elder"
    elseif age >= st.adult then
        return "adult"
    elseif age >= st.teen then
        return "teen"
    end
    return "pup"
end

-- Returns an animal entry's age as the vanilla character trading window shows it:
-- the life stage, then getAge0to1() x 100 truncated, so a pup at 0.3176 is "Pup (31)".
function AH.ageText(entry)
    local age = AH.age(entry.animal)
    local label = entry.char:getAgeString()
    if not label or label == "" then
        label = AH.stageOf(age)
    end
    return string.format("%s (%d)", tostring(label), math.floor(age * 100))
end

function AH.moneyText(n)
    return "c." .. tostring(math.floor(n))
end

-- Returns the price of an animal in cats, using the vanilla animal trader's formula:
-- (getAge0to1() + 0.1) x base, truncated. The engine's CharacterTrading_AnimalBuying
-- uses a 14000 base unless the CHOOSE_ANIMALS_BUYING dialogue action sets one. Here
-- the base is the "base price" from the animal's ANIMAL_CHARACTER record in FCS, or
-- sales.defaultBasePrice. Ages stop at 1.1, so elders cost 1.2 x base.
function AH.priceOf(entry)
    if not entry or not entry.animal then
        return 0
    end
    local defaultBase = (AH.config and AH.config.sales and AH.config.sales.defaultBasePrice) or 14000
    local base = (entry.def and entry.def.basePrice) or defaultBase
    return math.floor((AH.age(entry.animal) + 0.1) * base)
end

function AH.isFemale(c)
    return c:isFemale() and true or false
end

-- Returns true, or false and a short reason.
function AH.isHealthy(c)
    if c:isDead() then
        return false, "dead"
    end
    if c:isUnconcious() then
        return false, "unconscious"
    end
    if c:isInjured(false) then
        return false, "injured"
    end
    local med = c:getMedical()
    if med and med:isReallyHungry() then
        return false, "hungry"
    end
    if c:isInCombatMode(true, true) then
        return false, "in combat"
    end
    return true
end

function AH.distance(a, b)
    local pa, pb = a:getPosition(), b:getPosition()
    local dx, dy, dz = pa.x - pb.x, pa.y - pb.y, pa.z - pb.z
    return math.sqrt(dx * dx + dy * dy + dz * dz)
end

-- True if the character's squad and the player faction both have room for one more.
function AH.squadHasRoom(c)
    local gc = getGlobalConstants()
    if not gc then
        return false
    end
    local platoon = c:getPlatoon()
    if not platoon then
        return false
    end
    if platoon:getSquadSize() >= gc.MAX_SQUAD_SIZE then
        return false
    end
    if #AH.playerCharacters() >= gc.MAX_FACTION_SIZE then
        return false
    end
    return true
end

-- ---------------------------------------------------------------------------
-- Saved per-animal state
--
-- Values live in the character's appearance data, which the engine saves with the
-- character, so they survive save and load and travel with an animal when it is sold.
-- Keys are prefixed with "AH_". Numbers only.
-- ---------------------------------------------------------------------------

function AH.getValue(c, key)
    local ad = c:getAppearanceData()
    if not ad then
        return nil
    end
    return ad.fdata[STATE_PREFIX .. key]
end

function AH.setValue(c, key, value)
    local ad = c:getAppearanceData()
    if not ad then
        AH.log("cannot store " .. key .. ": no appearance data for " .. tostring(c:getName()))
        return
    end
    ad.fdata[STATE_PREFIX .. key] = value
end

function AH.clearValue(c, key)
    local ad = c:getAppearanceData()
    if ad then
        ad.fdata:remove(STATE_PREFIX .. key)
    end
end

-- ---------------------------------------------------------------------------
-- Task scheduler
--
-- One GameWorld::charsUpdate handler runs registered tasks on an in-game interval.
-- Each task receives (now, elapsedDays). elapsedDays is capped at one day so a long
-- jump, such as loading a later save, does not trigger a burst of catch-up rolls.
-- Loading an earlier save resets the task's clock.
-- ---------------------------------------------------------------------------

AH.tasks = AH.tasks or {}

function AH.addTask(name, intervalHours, fn)
    AH.tasks[name] = { intervalHours = intervalHours, fn = fn, lastDay = nil }
end

function AH.removeTask(name)
    AH.tasks[name] = nil
end

local function taskIntervalDays(task)
    local hours = task.intervalHours
    if type(hours) == "function" then
        local ok, res = pcall(hours)
        if ok and type(res) == "number" then
            hours = res
        else
            hours = 1
        end
    end
    if type(hours) ~= "number" or hours <= 0 then
        hours = 1
    end
    return hours / 24
end

local FRAMES_BETWEEN_CHECKS = 30
local frameCounter = 0

local function onCharsUpdate()
    frameCounter = frameCounter + 1
    if frameCounter < FRAMES_BETWEEN_CHECKS then
        return
    end
    frameCounter = 0

    local ok, now = pcall(AH.currentDay)
    if not ok or not now then
        return
    end

    for name, task in pairs(AH.tasks) do
        local intervalDays = taskIntervalDays(task)
        if task.lastDay == nil or now < task.lastDay then
            task.lastDay = now
        elseif now - task.lastDay >= intervalDays then
            local elapsed = math.min(now - task.lastDay, 1)
            task.lastDay = now
            local okRun, err = pcall(task.fn, now, elapsed)
            if not okRun then
                AH.log("task " .. name .. " failed: " .. tostring(err))
            end
        end
    end
end

-- ---------------------------------------------------------------------------
-- Event registration
--
-- Before KenshiLua loads or reloads any script, it removes event handlers registered
-- by that script. KenshiLua builds up to 0.3.5-alpha treat every script in the same
-- mod as the same source, so loading any Animal Husbandry file also removes handlers
-- that other files registered. To survive that, handlers are recorded here, and every
-- Animal Husbandry script calls AnimalHusbandry.rearmEvents() as its last step to
-- register them again. With a fixed KenshiLua this is redundant but harmless. Handler
-- IDs only increase, so removing a stale ID is harmless.
-- ---------------------------------------------------------------------------

AH.eventSpecs = AH.eventSpecs or {}
AH.eventIds = AH.eventIds or {}

local function registerSpec(key)
    local spec = AH.eventSpecs[key]
    local oldId = AH.eventIds[key]
    if oldId then
        pcall(Events.off, oldId)
    end
    AH.eventIds[key] = Events.on(spec.event, spec.fn)
end

-- Registers fn for eventName under a unique key, replacing any earlier registration
-- with the same key.
function AH.onEvent(key, eventName, fn)
    AH.eventSpecs[key] = { event = eventName, fn = fn }
    registerSpec(key)
end

function AH.rearmEvents()
    AH.syncConstantsFromFCS()
    for key in pairs(AH.eventSpecs) do
        registerSpec(key)
    end
end

AH.onEvent("scheduler", "GameWorld::charsUpdate", onCharsUpdate)
AH.rearmEvents()
AH.syncConstantsFromFCS()

AH.log("core loaded")
