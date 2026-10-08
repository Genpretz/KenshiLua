-- LuaLS regression fixture: GameDataContainer and its registered container userdata.

---@param container GameDataContainer
---@param data GameData
---@param list Lektor<GameData>
---@param byID OgreUnorderedMap<integer, GameData>
---@param bySID BoostUnorderedMap<string, GameData>
---@param dataSet OgreUnorderedSet<GameData>
local function checkGameDataContainer(container, data, list, byID, bySID, dataSet)
    local created = container:createNewData(0, "fixture-id", "Fixture")
    local named = container:getDataByName("Fixture", 0)
    assert(created == nil or created == data)
    assert(named == nil or named == data)
    container:renameData(data, "Renamed")
    container:removeData(data)
    container:removeDuplicatesOf(data)
    container:removeAllDataOfType(0)
    container:clearInstances()
    container:clearButDontDestroy()
    container:clearButDontDestroyPlatoons()
    container:clearAndDestroy()
    assert(type(container:getNewID()) == "number")
    container:destroyData(data)
    container:preLoadAllReferencePtrs()
    container:clearAllReferencePtrs()
    container:setName("Fixture")
    container:checkForDuplicates(data)
    container:addNewData(data, "forced-id")
    container:addNewData(list)
    assert(container:getData(1) == nil or container:getData(1) == data)
    assert(container:getData("fixture-id", 0) == nil or container:getData("fixture-id", 0) == data)
    container:getDataOfType(list, 0)
    assert(container:_getAllData() ~= nil)
    assert(type(container:loadGameDataReturn("fixture.mod", true, false)) == "boolean")
    assert(type(container:load("fixture.mod", "fixture", 0)) == "boolean")
    assert(type(container:save("fixture.mod")) == "boolean")
    container.flushKillList()
    container.destroyHomelessData(data)
    container:findAllDataThatReferencesThis(list, data, 0, "fixture")
    container._addToKillList(data)

    container.currentID = 1
    container.name = "Fixture"
    container.isBaseDatafile = false
    container.readOnly = false
    container.gamedataID = byID
    container.gamedataSID = bySID
    container.mainList = dataSet

    assert(type(byID:has(1)) == "boolean" and type(byID:contains(1)) == "boolean")
    assert(type(byID:remove(1)) == "boolean" and type(byID:erase(1)) == "boolean")
    assert(byID:size() >= 0 and byID:toTable() ~= nil)
    local idIterator, idState, idControl = byID:pairs()
    assert(type(idIterator) == "function" and idState == byID and idControl == nil)
    byID:clear()

    assert(type(bySID:has("fixture-id")) == "boolean")
    assert(type(bySID:remove("fixture-id")) == "boolean")
    assert(bySID:size() >= 0 and bySID:toTable() ~= nil)
    bySID:clear()

    assert(type(dataSet:has(data)) == "boolean" and type(dataSet:contains(data)) == "boolean")
    assert(type(dataSet:add(data)) == "boolean" and type(dataSet:insert(data)) == "boolean")
    assert(type(dataSet:remove(data)) == "boolean" and type(dataSet:erase(data)) == "boolean")
    assert(dataSet:size() >= 0 and dataSet:toTable() ~= nil)
    local setIterator, setState, setControl = dataSet:items()
    assert(type(setIterator) == "function" and setState == dataSet and setControl == nil)
    dataSet:clear()

    list:push(data)
    assert(list:pop() == data)
    list:removeAt(1)
    assert(list:size() >= 0 and list:toTable() ~= nil)
    list:clear()
end

return checkGameDataContainer
