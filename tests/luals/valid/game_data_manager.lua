-- LuaLS regression fixture: GameDataManager-specific API.

---@param manager GameDataManager
---@param container GameDataContainer
---@param data GameData
---@param list Lektor<GameData>
local function checkGameDataManager(manager, container, data, list)
    assert(type(manager:reloadGameData("fixture.mod", true, false)) == "boolean")
    manager:postProcessingTheDatas()
    local sector = manager:getMapSector(0, 0)
    assert(sector == nil or sector == data)
    manager:updateDatasOfType(container, 0, true)
    manager:updateData(data, true)
    manager:getBuildings(list, "BUILDING")
end

return checkGameDataManager
