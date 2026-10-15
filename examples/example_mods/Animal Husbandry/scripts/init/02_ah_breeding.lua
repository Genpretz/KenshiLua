-- Animal Husbandry: breeding.
--
-- Every breeding.checkIntervalHours, each eligible female animal in the player faction
-- with an eligible male she can mate with nearby rolls her record's "chance of
-- pregnancy". Mates and breeding values come from the animals' ANIMAL_CHARACTER records
-- in FCS (see AnimalHusbandry.animalDef and AnimalHusbandry.canMate); a sterile animal
-- never breeds. A separate, more frequent check handles births: when a pregnancy ends,
-- the mother's "number of offspring" newborns of her template spawn beside her, in her
-- squad. The engine assigns each newborn's sex and ages it like any other animal.

local AH = _G.AnimalHusbandry

local KEY_DUE = "PregnantUntil"
local KEY_COOLDOWN = "BreedCooldownUntil"

-- How often births are checked, in in-game hours. Pregnancy rolls use the slower
-- breeding.checkIntervalHours from the config.
local BIRTH_CHECK_INTERVAL_HOURS = 0.25

-- Config is read at call time so that a hot reload of the config file takes effect.
local function cfg()
    return AH.config.breeding
end

-- Mothers already told they have no room for a newborn, keyed by handle string,
-- so the message appears once per pregnancy rather than every check.
local notifiedNoRoom = {}

local function handleKey(c)
    return tostring(c.handle:toString())
end

-- Returns true, or false and a short reason.
local function canBreed(entry)
    if not entry.def then
        return false, "no record"
    end
    if entry.def.sterile then
        return false, "sterile"
    end
    if AH.age(entry.animal) < cfg().minAge then
        return false, "too young"
    end
    return AH.isHealthy(entry.char)
end

local function nearestMate(female, males)
    local maxDistance = cfg().maxPairDistance
    local best, bestDist
    for i = 1, #males do
        local male = males[i]
        if AH.canMate(female, male) and canBreed(male) then
            local d = AH.distance(female.char, male.char)
            if d <= maxDistance and (not best or d < bestDist) then
                best, bestDist = male, d
            end
        end
    end
    return best, bestDist
end

local function spawnNewborn(mother)
    local c = mother.char
    local pos = c:getPosition()
    local spawnPos = {
        x = pos.x + (math.random() * 4 - 2),
        y = pos.y,
        z = pos.z + (math.random() * 4 - 2),
    }
    local result = getRootObjectFactory():createRandomCharacter(
        c:getFaction(), spawnPos, c:getPlatoon(), c:getGameData(), nil, cfg().babyAge)
    if not result then
        return nil
    end
    return result.handle:getCharacter()
end

local function giveBirth(mother, now)
    local c = mother.char
    local key = handleKey(c)
    local born = 0
    for i = 1, math.max(1, mother.def.offspring) do
        if not AH.squadHasRoom(c) then
            break
        end
        local baby = spawnNewborn(mother)
        if baby then
            born = born + 1
            AH.debugLog("newborn " .. tostring(baby:getName()) .. " female=" .. tostring(AH.isFemale(baby)))
        else
            AH.log("could not spawn a newborn for " .. tostring(c:getName()))
        end
    end

    if born == 0 then
        -- Stay pregnant and retry on the next check, so the birth happens once room frees up.
        if not notifiedNoRoom[key] then
            notifiedNoRoom[key] = true
            AH.notify(c:getName() .. " is ready to give birth, but the squad or faction is full.")
        end
        return
    end

    notifiedNoRoom[key] = nil
    AH.clearValue(c, KEY_DUE)
    AH.setValue(c, KEY_COOLDOWN, now + mother.def.timeBetweenPregnancy)
    if born == 1 then
        AH.notify(c:getName() .. " gave birth.")
    else
        AH.notify(c:getName() .. " gave birth to " .. born .. " young.")
    end
end

local function bySex()
    local females, males = {}, {}
    local animals = AH.playerAnimals()
    for i = 1, #animals do
        local e = animals[i]
        if AH.isFemale(e.char) then
            females[#females + 1] = e
        else
            males[#males + 1] = e
        end
    end
    return females, males
end

-- Gives birth for every pregnant female whose due time has passed.
local function birthCheck(now)
    if AH.syncConstantsFromFCS then
        AH.syncConstantsFromFCS()
    end
    local animals = AH.playerAnimals()
    for i = 1, #animals do
        local e = animals[i]
        if AH.isFemale(e.char) then
            local due = AH.getValue(e.char, KEY_DUE)
            if due and now >= due and e.def then
                giveBirth(e, now)
            end
        end
    end
end

-- Rolls for new pregnancies, once per check for each eligible female.
local function breedingCheck(now)
    if AH.syncConstantsFromFCS then
        AH.syncConstantsFromFCS()
    end
    local females, males = bySex()
    for i = 1, #females do
        local f = females[i]
        local c = f.char
        if not AH.getValue(c, KEY_DUE) then
            local cooldown = AH.getValue(c, KEY_COOLDOWN)
            if not cooldown or now >= cooldown then
                local ok, reason = canBreed(f)
                if ok then
                    local mate, dist = nearestMate(f, males)
                    if mate then
                        local chance = math.max(0, math.min(1, f.def.pregnancyChance / 100))
                        local roll = math.random()
                        AH.debugLog(string.format("%s (%s) mate %s at %.1f: roll %.4f vs %.4f",
                            c:getName(), f.def.name, mate.char:getName(), dist, roll, chance))
                        if roll < chance then
                            AH.setValue(c, KEY_DUE, now + f.def.pregnancyPeriod)
                            AH.notify(c:getName() .. " is pregnant.")
                        end
                    end
                else
                    AH.debugLog(c:getName() .. " cannot breed: " .. tostring(reason))
                end
            end
        end
    end
end

-- Returns a one-line description of an animal entry's breeding state, used by the
-- Husbandry window.
function AH.describeBreeding(entry, now)
    local c = entry.char
    local due = AH.getValue(c, KEY_DUE)
    if due then
        if now >= due then
            return "Due now"
        end
        return string.format("Due in %.1f days", due - now)
    end
    local cooldown = AH.getValue(c, KEY_COOLDOWN)
    if cooldown and cooldown > now then
        return string.format("Resting, %.1f days", cooldown - now)
    end
    local ok, reason = canBreed(entry)
    if not ok then
        return "Cannot breed: " .. tostring(reason)
    end
    if AH.isFemale(c) then
        return "Not pregnant"
    end
    return "Can breed"
end

AH.addTask("births", BIRTH_CHECK_INTERVAL_HOURS, birthCheck)
AH.addTask("breeding", function() return cfg().checkIntervalHours end, breedingCheck)

-- ---------------------------------------------------------------------------
-- Console commands
-- ---------------------------------------------------------------------------

local function fmtDays(v)
    return string.format("%.2f", v)
end

function AH.status()
    if AH.syncConstantsFromFCS then
        AH.syncConstantsFromFCS()
    end
    local now = AH.currentDay()
    local animals = AH.playerAnimals()
    AH.log(string.format("day %.3f, %d player animals", now, #animals))
    for i = 1, #animals do
        local e = animals[i]
        local c = e.char
        local age = AH.age(e.animal)
        local parts = {
            tostring(c:getName()),
            tostring(e.raceName),
            e.def and e.def.name or "no record",
            e.def and (#e.def.products .. " product(s)") or "no products",
            AH.isFemale(c) and "female" or "male",
            AH.stageOf(age) .. string.format(" %.3f", age),
        }
        local ok, reason = canBreed(e)
        parts[#parts + 1] = ok and "can breed" or ("cannot breed: " .. tostring(reason))
        local due = AH.getValue(c, KEY_DUE)
        if due then
            parts[#parts + 1] = "pregnant, due in " .. fmtDays(due - now) .. " days"
        end
        local cooldown = AH.getValue(c, KEY_COOLDOWN)
        if cooldown and cooldown > now then
            parts[#parts + 1] = "cooldown " .. fmtDays(cooldown - now) .. " days"
        end
        AH.log("  " .. table.concat(parts, " | "))
    end
end

function AH.debugPairs()
    if AH.syncConstantsFromFCS then
        AH.syncConstantsFromFCS()
    end
    local females, males = bySex()
    local maxDistance = cfg().maxPairDistance
    AH.log("maxPairDistance = " .. tostring(maxDistance) .. "; " .. #females .. " female(s), " .. #males .. " male(s)")
    for i = 1, #females do
        for j = 1, #males do
            local f, m = females[i], males[j]
            if AH.canMate(f, m) then
                local d = AH.distance(f.char, m.char)
                local notes = {}
                if d > maxDistance then
                    notes[#notes + 1] = "too far"
                end
                local okF, whyF = canBreed(f)
                if not okF then
                    notes[#notes + 1] = "female " .. tostring(whyF)
                end
                local okM, whyM = canBreed(m)
                if not okM then
                    notes[#notes + 1] = "male " .. tostring(whyM)
                end
                AH.log(string.format("  %s + %s: distance %.1f%s", f.char:getName(), m.char:getName(), d,
                    #notes > 0 and (" (" .. table.concat(notes, ", ") .. ")") or ""))
            end
        end
    end
end

function AH.forcePregnant(days)
    local c = AH.selectedCharacter()
    if not c or not c:isAnimal() or not c:isPlayerCharacter() then
        AH.log("Select a female animal in the player faction first.")
        return
    end
    if not AH.isFemale(c) then
        AH.log(tostring(c:getName()) .. " is male.")
        return
    end
    days = days or 0.01
    local now = AH.currentDay()
    AH.setValue(c, KEY_DUE, now + days)
    AH.clearValue(c, KEY_COOLDOWN)
    AH.log(string.format("%s is due in %s days; births are checked every %s in-game hours",
        tostring(c:getName()), fmtDays(days), tostring(BIRTH_CHECK_INTERVAL_HOURS)))
end

function AH.clearBreedingState()
    local c = AH.selectedCharacter()
    if not c then
        AH.log("Select an animal first.")
        return
    end
    AH.clearValue(c, KEY_DUE)
    AH.clearValue(c, KEY_COOLDOWN)
    notifiedNoRoom[handleKey(c)] = nil
    AH.log("cleared breeding state for " .. tostring(c:getName()))
end

AH.log("breeding loaded")

-- Loading this file made KenshiLua remove the event handlers of every Animal
-- Husbandry script; register them again. See the note in 01_ah_core.lua.
if _G.AnimalHusbandry and _G.AnimalHusbandry.rearmEvents then
    _G.AnimalHusbandry.rearmEvents()
end
