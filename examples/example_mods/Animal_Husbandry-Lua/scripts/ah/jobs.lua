local AH = require("ah.core")
local harvest = require("ah.harvest")

local native, taskType
local plans = {}
local PREFIX = "AH_Job2_"

local function loadNative()
    if native then return true end
    local ok, result = pcall(require, "AnimalHusbandryNative")
    if not ok or type(result.storageRoom) ~= "function"
        or type(result.update) ~= "function" or type(result.getJobLabel) ~= "function" then return false end
    native = result
    taskType = native.taskType()
    native.setActive(true)
    return true
end

local function workerReady(worker)
    return worker and worker:isPlayerCharacter() and not worker:isAnimal()
        and not worker:isDead() and not worker:isUnconcious()
        and not worker:isInCombatMode(true, true)
end

local function playerOutpost(town, pos)
    return town and town:isOutpost() and town:getFaction()
        and town:getFaction().isPlayer ~= nil and town:withinBordersRange(pos, 1)
end

local function outpostAt(pos)
    local shared = getSharedKing()
    local towns = shared and shared.townList
    local town = towns and towns:getNearestPlayerTown(pos, false, 1000000)
    if playerOutpost(town, pos) then return town end
end

local function prefix(subject)
    return PREFIX .. subject .. "_"
end

local function liveJob(worker, subject)
    local orders = worker:getOrdersReciever()
    for i = 0, orders:getPermajobCount() - 1 do
        local job = orders:getPermajobData(i)
        if orders:getPermajob(i) == taskType and job.subject:toString() == subject then return true end
    end
    return false
end

local function groupKey(seed)
    local group = seed.def and seed.def.matingGroup or ""
    if group ~= "" then return "group:" .. string.lower(group) end
    if seed.raceID and seed.raceID ~= "" then return "race:" .. seed.raceID end
    return "animal:" .. (seed.templateID or "")
end

local function groupName(seed)
    local group = seed.def and seed.def.matingGroup or ""
    if group ~= "" then return group end
    local gamedata = getGameWorld().gamedata
    local race = seed.raceID and gamedata:getData(seed.raceID)
    if race then return tostring(race.name) end
    local animal = seed.templateID and gamedata:getData(seed.templateID)
    return animal and tostring(animal.name) or "Animals"
end

local function assignment(worker, subject)
    local data = worker:getAppearanceData()
    local p = prefix(subject)
    if not data or data.sdata[p .. "Animal"] == nil then return nil end
    local townHandle = data:getHandle(p .. "Town")
    return {
        prefix = p,
        subject = subject,
        townHandle = townHandle,
        town = townHandle and townHandle:getTown(),
        seed = {
            templateID = data.sdata[p .. "Animal"],
            raceID = data.sdata[p .. "Race"],
            def = { matingGroup = data.sdata[p .. "Group"] or "" },
        },
        cargo = data.sdata[p .. "Cargo"],
        hauling = data.sdata[p .. "Hauling"] == "1",
        label = data.sdata[p .. "Label"],
    }
end

local function assignmentInRange(worker, subject)
    local assigned = assignment(worker, subject)
    if assigned and playerOutpost(assigned.town, worker:getPosition()) then return assigned end
end

local function refreshPanel(worker)
    local gui = getForgottenGUI()
    if gui and gui.selectedObject and gui.selectedObject:toString() == worker.handle:toString() then
        local panel = gui.mainbar.ordersDataPanel
        if panel then panel:update(worker); panel:refreshOrders() end
    end
end

local function syncLabels(worker)
    local orders = worker:getOrdersReciever()
    local changed = false
    for i = 0, orders:getPermajobCount() - 1 do
        if orders:getPermajob(i) == taskType then
            local subject = orders:getPermajobData(i).subject:toString()
            local assigned = assignment(worker, subject)
            if assigned then
                local label = assigned.label or ("Animal Husbandry: " .. groupName(assigned.seed))
                if native.setJobLabel(worker, subject, label) then changed = true end
            end
        end
    end
    if changed then refreshPanel(worker) end
end

local function exactStorage(storage, product)
    if storage:getSpecialFunction() ~= BuildingFunction.BF_RESOURCE_STORAGE then return false end
    local data = storage:getGameData()
    local limits = data and data:getReferenceListIfExists("limit inventory")
    if not limits then return false end
    for i = 1, limits:size() do
        if tostring(limits[i].sid) == product.itemID then
            return storage:canHaveSomeOfThese(product.data)
        end
    end
    return false
end

local function findStorage(worker, town, product, collecting)
    local buildings = town:findAllBuildingsWithFunction(BuildingFunction.BF_RESOURCE_STORAGE, worker)
    local nearest, distance
    if not buildings then return nil end
    for i = 1, buildings:size() do
        local building = buildings[i]
        local storage = building and building:getFunctionStuff()
        if storage and building:getFaction() and building:getFaction().isPlayer ~= nil
            and town:withinBordersRange(building:getPosition(), 1) and exactStorage(storage, product)
            and not worker:getAI():getTaskSystem():isPathImpossible(building.handle)
            and (not collecting or native.storageRoom(worker, building, product.data)) then
            local d = AH.distance(worker, building)
            if not distance or d < distance then nearest, distance = building, d end
        end
    end
    return nearest
end

local function saveCargo(worker, assigned, items)
    local data = worker:getAppearanceData()
    local old = tonumber(data.sdata[assigned.prefix .. "CargoCount"]) or 0
    for i = 1, math.max(old, #items) do
        data.sdata[assigned.prefix .. "Cargo" .. i] = items[i] and items[i].itemID or ""
    end
    data.sdata[assigned.prefix .. "CargoCount"] = tostring(#items)
    data.sdata[assigned.prefix .. "Cargo"] = ""
end

local function cargoProducts(worker, assigned)
    local data = worker:getAppearanceData()
    local count = tonumber(data.sdata[assigned.prefix .. "CargoCount"]) or 0
    local products = {}
    local gamedata = getGameWorld().gamedata
    if count == 0 and assigned.cargo and assigned.cargo ~= "" then count = 1 end
    for i = 1, count do
        local sid = data.sdata[assigned.prefix .. "Cargo" .. i]
        if (not sid or sid == "") and i == 1 then sid = assigned.cargo end
        local item = sid and sid ~= "" and gamedata:getData(sid)
        if item and native.deliverableCount(worker, item) > 0 then
            products[#products + 1] = { itemID = sid, data = item }
        end
    end
    if #products ~= count or (assigned.cargo and assigned.cargo ~= "") then
        saveCargo(worker, assigned, products)
    end
    return products
end

local function addCargo(worker, assigned, product)
    local products = cargoProducts(worker, assigned)
    for _, existing in ipairs(products) do
        if existing.itemID == product.itemID then return end
    end
    products[#products + 1] = product
    saveCargo(worker, assigned, products)
end

local function deliveryPlan(worker, assigned, cargo)
    for _, product in ipairs(cargo) do
        local storage = findStorage(worker, assigned.town, product)
        if storage then return { storage = storage.handle, product = product, delivering = true } end
    end
end

local function choosePlan(worker, subject)
    if not workerReady(worker) then return nil end
    local assigned = assignmentInRange(worker, subject)
    if not assigned then return nil end
    if native.deliveryPending(worker) then return nil end
    local cargo = cargoProducts(worker, assigned)
    if #cargo == 0 and assigned.hauling then
        worker:getAppearanceData().sdata[assigned.prefix .. "Hauling"] = "0"
        assigned.hauling = false
    end
    if assigned.hauling then return deliveryPlan(worker, assigned, cargo) end
    local nearest, distance
    local storageCache = {}
    for _, entry in ipairs(AH.playerAnimals()) do
        if AH.canMate(assigned.seed, entry)
            and assigned.town:withinBordersRange(entry.char:getPosition(), 1)
            and not worker:getAI():getTaskSystem():isPathImpossible(entry.char.handle) then
            for _, product in ipairs((entry.def and entry.def.products) or {}) do
                local eligible = harvest.canHarvest(entry, worker, product, AH.currentDay(), true)
                if eligible then
                    local storage = storageCache[product.itemID]
                    if storage == nil then
                        storage = findStorage(worker, assigned.town, product, true)
                        storageCache[product.itemID] = storage or false
                    end
                    local d = AH.distance(worker, entry.char)
                    if storage and (not distance or d < distance) then
                        nearest = { animal = entry.char.handle, storage = storage.handle, product = product }
                        distance = d
                    end
                end
            end
        end
    end
    if nearest then return nearest end
    if #cargo > 0 then
        worker:getAppearanceData().sdata[assigned.prefix .. "Hauling"] = "1"
        return deliveryPlan(worker, assigned, cargo)
    end
end

function AH.assignHusbandryJob(targetHandle, workerHandle)
    if not loadNative() then return false, "AnimalHusbandryNative.dll is unavailable or out of date" end
    local animal = targetHandle and targetHandle:getCharacter()
    local worker = workerHandle and workerHandle:getCharacter()
    local entry = animal and AH.animalEntry(animal)
    if not entry or not animal:isPlayerCharacter() then return false, "select a player-owned animal" end
    if not workerReady(worker) then return false, "select an available humanoid" end
    local town = outpostAt(animal:getPosition())
    if not town or not town:withinBordersRange(worker:getPosition(), 1) then
        return false, "the animal and worker must be inside the same player outpost"
    end
    local data = worker:getAppearanceData()
    if not data then return false, "worker save data is unavailable" end
    local orders = worker:getOrdersReciever()
    local subject = animal.handle:toString()
    local key = groupKey(entry)
    for i = 0, orders:getPermajobCount() - 1 do
        if orders:getPermajob(i) == taskType then
            local existingSubject = orders:getPermajobData(i).subject:toString()
            local existing = assignment(worker, existingSubject)
            if existingSubject == subject or (existing and groupKey(existing.seed) == key
                and existing.townHandle and existing.townHandle:toString() == town.handle:toString()) then
                return false, "this worker already has a Husbandry job for this animal group at this outpost"
            end
        end
    end
    local p = prefix(subject)
    local label = "Animal Husbandry: " .. groupName(entry)
    data.sdata[p .. "Animal"] = entry.templateID or ""
    data.sdata[p .. "Race"] = entry.raceID or ""
    data.sdata[p .. "Group"] = entry.def and entry.def.matingGroup or ""
    data.sdata[p .. "Cargo"] = ""
    data.sdata[p .. "CargoCount"] = "0"
    data.sdata[p .. "Hauling"] = "0"
    data.sdata[p .. "Label"] = label
    data:storeHandle(town.handle, p .. "Town", false)
    -- The copied subject identifies the assignment; eligibility uses its saved
    -- group snapshot and does not require the original animal to remain alive.
    orders:addJob(taskType, animal.handle, animal:getPosition(), true)
    native.setJobLabel(worker, subject, label)
    orders:setJobsEnabled(true)
    local panel = getForgottenGUI().mainbar.ordersDataPanel
    if panel then panel:update(worker); panel:refreshOrders() end
    -- AH.notify(worker:getName() .. " assigned " .. label .. " at " .. town:getName() .. ".")
    return true
end

local function score(request, worker, subject)
    syncLabels(worker)
    local plan = choosePlan(worker, subject)
    plans[worker.handle:toString() .. "/" .. subject] = plan
    native.setScore(request, plan and 1 or 0)
end

local function run(request, worker, subject)
    local key = worker.handle:toString() .. "/" .. subject
    local plan = plans[key]
    local orders = worker:getOrdersReciever()
    if not workerReady(worker) or not plan or not liveJob(worker, subject)
        or not orders:isJobsEnabled() or orders:hasPlayerOrders() then
        native.setComplete(request, true)
        return
    end
    local assigned = assignmentInRange(worker, subject)
    local building = plan.storage:getBuilding()
    local storage = building and building:getFunctionStuff()
    if not assigned or not storage or not exactStorage(storage, plan.product) then
        plans[key] = nil
        native.setComplete(request, true)
        return
    end
    if plan.delivering then
        -- The stock fill goal plans movement and transfers the cargo.
        -- This works independently of the player's automatic Ditch items setting.
        native.deliver(worker, building, plan.product.data, subject)
        native.setComplete(request, true)
        return
    end
    local animal = plan.animal:getCharacter()
    local entry = animal and AH.animalEntry(animal)
    if not entry or not animal:isPlayerCharacter() or not AH.canMate(assigned.seed, entry)
        or not assigned.town:withinBordersRange(animal:getPosition(), 1)
        or not harvest.canHarvest(entry, worker, plan.product, AH.currentDay(), true)
        or not native.storageRoom(worker, building, plan.product.data) then
        plans[key] = nil
        native.setComplete(request, true)
        return
    end
    local maxDistance = AH.config.harvest.jobMaxDistance
    if AH.distance(worker, animal) > maxDistance then
        worker:getBody():_move(animal, animal:getPosition())
        native.setComplete(request, false)
        return
    end
    local ok = harvest.harvest(entry, worker, plan.product, 1, true, maxDistance)
    if ok then
        addCargo(worker, assigned, plan.product)
        plans[key] = choosePlan(worker, subject)
    end
    native.setComplete(request, not ok or plans[key] == nil)
end

AH.onEvent("jobs_score", "AnimalHusbandry_JobScore", score)
AH.onEvent("jobs_run", "AnimalHusbandry_JobRun", run)

local function onOrderText(row)
    if not native or not row.task then return end
    local label = native.getJobLabel(row.task)
    if not label then return end
    local at = string.find(row.text, row.task.taskData.description, 1, true)
    if at then row.text = string.sub(row.text, 1, at - 1) .. label end
end

AH.onEvent("jobs_order_text", "OrderData::updateText", onOrderText)

local frame = 0
local function onFrame()
    if not loadNative() then return end
    native.update()
    frame = frame + 1
    if frame % 30 ~= 1 then return end
    for _, worker in ipairs(AH.playerCharacters()) do
        if not worker:isAnimal() and worker:getOrdersReciever():hasPermajob(taskType) then syncLabels(worker) end
    end
end
AH.onEvent("jobs_native", "GameWorld::charsUpdate", onFrame)
loadNative()

return {
    shutdown = function()
        if native then native.setActive(false) end
        plans = {}
    end,
}
