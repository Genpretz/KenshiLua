-- LuaLS regression fixture: GameSaveState and its item-type state map.

---@param state GameSaveState
---@param data GameData
---@param container GameDataContainer
---@param instance ObjectInstance
---@param states OgreUnorderedMap<integer, GameData>
local function checkGameSaveState(state, data, container, instance, states)
    state:generateNewInstanceID()
    assert(type(state:generateStateID(0)) == "string")
    local created = state:createState(0)
    if created then
        state:addState(created)
    end
    assert(type(state:hasState(0)) == "boolean")
    local stored = state:getState(0)
    assert(stored == nil or stored == data)
    assert(state:numStates() >= 0)
    assert(type(state:getPos()) == "table" and type(state:getRot()) == "table")
    local instanceData = state:getTheInstancesData()
    assert(instanceData == nil or instanceData == data)
    state:createFromSerialisedInstanceData(container, instance, "fixture")
    assert(state:getInstanceID() ~= nil and type(state:operator_bool()) == "boolean")

    state.baseData = data
    state.dataSource = container
    state.firstTime = false
    state.instance = instance
    state.instanceID = "fixture"
    state.pos = { 0, 0, 0 }
    state.rot = { 1, 0, 0, 0 }
    state.states = states

    assert(type(states:has(0)) == "boolean" and type(states:contains(0)) == "boolean")
    assert(type(states:remove(0)) == "boolean" and type(states:erase(0)) == "boolean")
    assert(states:size() >= 0)
    local stateTable = states:toTable()
    if stateTable then
        local value = stateTable[0]
        assert(value == nil or value == data)
    end
    local iterator, mapState, control = states:pairs()
    assert(type(iterator) == "function" and mapState == states and control == nil)
    states:clear()
end

return checkGameSaveState
