-- LuaLS regression fixture: WorldEventStateQuery and its returned maps.

---@param query WorldEventStateQuery
---@param factionMap OgreUnorderedMap<Faction, boolean>
---@param stateMap OgreUnorderedMap<GameData, integer>
---@param faction Faction
---@param data GameData
local function checkWorldEventStateQuery(query, factionMap, stateMap, faction, data)
    assert(type(query:isTrue()) == "boolean")
    query.playerInvolvement = true
    query.isAllyOf = factionMap
    query.isEnemyOf = factionMap
    query.towns = stateMap
    query.uniqueNPCsAre = stateMap
    query.uniqueNPCsAreNot = stateMap
    assert(query.isAllyOf == factionMap and query.towns == stateMap)

    assert(type(WorldEventStateQuery.checkAllStatesInObject(data, "fixture")) == "boolean")
    local fromData = WorldEventStateQuery.getFromData(data)
    assert(fromData == nil or fromData == query)

    assert(type(factionMap:has(faction)) == "boolean" and type(factionMap:contains(faction)) == "boolean")
    assert(type(factionMap:remove(faction)) == "boolean" and type(factionMap:erase(faction)) == "boolean")
    assert(factionMap:size() >= 0 and factionMap:toTable() ~= nil)
    factionMap:clear()

    assert(type(stateMap:has(data)) == "boolean" and type(stateMap:contains(data)) == "boolean")
    assert(type(stateMap:remove(data)) == "boolean" and type(stateMap:erase(data)) == "boolean")
    assert(stateMap:size() >= 0 and stateMap:toTable() ~= nil)
    stateMap:clear()
end

return checkWorldEventStateQuery
