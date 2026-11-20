-- scripts/world_states/example.lua
-- World state script triggered by WorldStateScriptBridge.
-- Demonstrates inspecting WorldEventStateQuery conditions and GameData metadata.

-- Helper check functions

--- Checks if query.isAllyOf contains a faction with the given name and optional expected boolean.
---@param query WorldEventStateQuery
---@param factionName string
---@param expectedBool boolean|nil
---@return boolean found
---@return boolean|nil actualValue
---@return Faction|nil matchedFaction
local function checkIsAlly(query, factionName, expectedBool)
    for faction, isAlly in pairs(query.isAllyOf) do
        if faction.name == factionName then
            local matches = (expectedBool == nil) or (isAlly == expectedBool)
            return matches, isAlly, faction
        end
    end
    return false, nil, nil
end

--- Checks if query.isEnemyOf contains a faction with the given name and optional expected boolean.
---@param query WorldEventStateQuery
---@param factionName string
---@param expectedBool boolean|nil
---@return boolean found
---@return boolean|nil actualValue
---@return Faction|nil matchedFaction
local function checkIsEnemy(query, factionName, expectedBool)
    for faction, isEnemy in pairs(query.isEnemyOf) do
        if faction.name == factionName then
            local matches = (expectedBool == nil) or (isEnemy == expectedBool)
            return matches, isEnemy, faction
        end
    end
    return false, nil, nil
end

--- Checks if query.uniqueNPCsAre contains an NPC with the given name and optional expected WorldStateEnum.
---@param query WorldEventStateQuery
---@param npcName string
---@param expectedState WorldStateEnum|integer|nil WorldStateEnum (DEAD=0, ALIVE=1, IMPRISONED=2)
---@return boolean found
---@return WorldStateEnum|nil actualState
---@return GameData|nil matchedNpcData
local function checkUniqueNpcState(query, npcName, expectedState)
    for npcData, state in pairs(query.uniqueNPCsAre) do
        if npcData.name == npcName then
            local matches = (expectedState == nil) or (state == expectedState)
            return matches, state, npcData
        end
    end
    return false, nil, nil
end

--- Checks if query.uniqueNPCsAreNot contains an NPC with the given name and optional forbidden WorldStateEnum.
---@param query WorldEventStateQuery
---@param npcName string
---@param forbiddenState WorldStateEnum|integer|nil WorldStateEnum (DEAD=0, ALIVE=1, IMPRISONED=2)
---@return boolean found
---@return WorldStateEnum|nil actualState
---@return GameData|nil matchedNpcData
local function checkUniqueNpcNotState(query, npcName, forbiddenState)
    for npcData, state in pairs(query.uniqueNPCsAreNot) do
        if npcData.name == npcName then
            local matches = (forbiddenState == nil) or (state == forbiddenState)
            return matches, state, npcData
        end
    end
    return false, nil, nil
end

--- Checks if query.towns contains a town with the given name and optional expected WorldStateEnum.
---@param query WorldEventStateQuery
---@param townName string
---@param expectedState WorldStateEnum|integer|nil WorldStateEnum (DEAD=0, ALIVE=1, IMPRISONED=2)
---@return boolean found
---@return WorldStateEnum|nil actualState
---@return GameData|nil matchedTownData
local function checkTownState(query, townName, expectedState)
    for townData, state in pairs(query.towns) do
        if townData.name == townName then
            local matches = (expectedState == nil) or (state == expectedState)
            return matches, state, townData
        end
    end
    return false, nil, nil
end

--- Checks the playerInvolvement flag on the query.
---@param query WorldEventStateQuery
---@return boolean
local function checkPlayerInvolvement(query)
    return query.playerInvolvement
end

--- Evaluates whether the entire compound world state condition evaluates to true right now.
---@param query WorldEventStateQuery
---@return boolean
local function checkWorldStateIsTrue(query)
    return query:isTrue()
end

--- Checks if an FCS reference list exists and has elements on the WORLD_EVENT_STATE GameData.
---@param stateData GameData
---@param listName string e.g. "player ally", "player enemy", "NPC is", "NPC is NOT", "run lua script"
---@return boolean existsAndNotEmpty
---@return integer count
local function checkStateDataList(stateData, listName)
    if not stateData:listExists(listName) then
        return false, 0
    end
    return stateData:listExistsAndNotEmpty(listName), stateData:getListSize(listName)
end

--- Reads the execution modes (0, 1, or 2) of all attached Lua scripts on the world state.
---@param stateData GameData
---@return table<{sid: string, mode: integer}>
local function getAttachedScriptModes(stateData)
    local results = {}
    if not stateData:listExists("run lua script") then
        return results
    end
    local count = stateData:getListSize("run lua script")
    for i = 0, count - 1 do
        local vals = stateData:getValueFromList("run lua script", i)
        local scriptSid = stateData:getFromList("run lua script", i)
        table.insert(results, { sid = scriptSid, mode = vals[1] })
    end
    return results
end

-- Main script execution

KenshiLua.log("[WorldState] Executing example.lua")

-- 1. Guard injected bridge globals
local query = currentWorldEventStateQuery
local stateData = currentWorldEventState

if not query or not stateData then
    KenshiLua.log("[WorldState] Error: currentWorldEventState or currentWorldEventStateQuery is nil.")
    return
end

KenshiLua.log(string.format("[WorldState] Script triggered for '%s' (sid: %s)",
    stateData.name, stateData.stringID))

-- 2. Check overall evaluation
local overallTrue = checkWorldStateIsTrue(query)
KenshiLua.log(string.format("[WorldState] checkWorldStateIsTrue: %s", tostring(overallTrue)))

-- 3. Check player ally condition (e.g. Anti-Slavers == true)
local hasAlly, allyVal = checkIsAlly(query, "Anti-Slavers", true)
if hasAlly then
    KenshiLua.log(string.format("[WorldState] checkIsAlly: Found 'Anti-Slavers' with value %s", tostring(allyVal)))
else
    KenshiLua.log("[WorldState] checkIsAlly: 'Anti-Slavers' (true) not matched in isAllyOf.")
end

-- 4. Check player enemy condition
local hasEnemy, enemyVal, enemyFaction = checkIsEnemy(query, "Holy Nation", true)
if hasEnemy then
    KenshiLua.log(string.format("[WorldState] checkIsEnemy: Found '%s' with value %s", enemyFaction.name, tostring(enemyVal)))
else
    KenshiLua.log("[WorldState] checkIsEnemy: Target faction not matched in isEnemyOf.")
end

-- 5. Check NPC state (e.g. unique NPC is DEAD)
local npcFound, npcState, npcData = checkUniqueNpcState(query, "Holy Lord Phoenix", WorldStateEnum.DEAD)
if npcFound then
    KenshiLua.log(string.format("[WorldState] checkUniqueNpcState: Found NPC '%s' requiring state %d", npcData.name, npcState))
else
    KenshiLua.log("[WorldState] checkUniqueNpcState: NPC condition not found in uniqueNPCsAre.")
end

-- 6. Check NPC NOT state (e.g. unique NPC is NOT ALIVE)
local notFound, notState = checkUniqueNpcNotState(query, "Tinfist", WorldStateEnum.ALIVE)
if notFound then
    KenshiLua.log(string.format("[WorldState] checkUniqueNpcNotState: NPC requires NOT state %d", notState))
end

-- 7. Check town condition
local townFound, townState, townData = checkTownState(query, "Bad Teeth", WorldStateEnum.DEAD)
if townFound then
    KenshiLua.log(string.format("[WorldState] checkTownState: Town '%s' requires state %d", townData.name, townState))
end

-- 8. Check player involvement flag
local requiresPlayer = checkPlayerInvolvement(query)
KenshiLua.log(string.format("[WorldState] checkPlayerInvolvement: %s", tostring(requiresPlayer)))

-- 9. Inspect raw FCS reference lists on stateData
local hasAlliesInFcs, allyListCount = checkStateDataList(stateData, "player ally")
KenshiLua.log(string.format("[WorldState] stateData 'player ally' list: exists=%s, count=%d",
    tostring(hasAlliesInFcs), allyListCount))

-- 10. Inspect attached Lua script modes
local scriptModes = getAttachedScriptModes(stateData)
for _, item in ipairs(scriptModes) do
    KenshiLua.log(string.format("[WorldState] Attached script '%s' configured for mode %d", item.sid, item.mode))
end
