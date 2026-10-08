-- LuaLS regression fixture: direct DialogLineData support bindings.

---@param trigger CampaignTriggerData
---@param time TimeOfDay
---@param otherTime TimeOfDay
---@param states WorldEventStateQueryList
---@param stateMap OgreUnorderedMap<WorldEventStateQuery, boolean>
---@param query WorldEventStateQuery
---@param data GameData
local function checkDialogueSupport(trigger, time, otherTime, states, stateMap, query, data)
    trigger.what = data
    trigger.minTime = 1
    trigger.maxTime = 2
    trigger.chance = 0.5
    assert(trigger.what == data and trigger.minTime < trigger.maxTime)

    time.time = 1
    time:setNull()
    assert(type(time:isUnset()) == "boolean")
    time:setTime(1)
    time:addHours(1)
    time:addMinutes(1)
    assert(type(time:getTotalHours()) == "number" and type(time:getTotalMinutes()) == "number")
    assert(type(time:getTotalSeconds()) == "number" and type(time:getRealLifeSeconds()) == "number")
    assert(type(time:getRealLifeSecondsPassed()) == "number" and type(time:getTotalDays()) == "number")
    time:stampTime()
    assert(type(time:getHoursPassed()) == "number" and type(time:getMinutesPassed()) == "number")
    assert(type(time:getSecondsPassed()) == "number" and type(time:timeOfDayHasPassed(1)) == "boolean")
    assert(type(time:timePassed()) == "number")
    assert(type(time:getTimePassedString()) == "string")
    assert(type(time:getTimeRemainingString()) == "string" and type(time:getTotalTimeString()) == "string")
    assert(type(time:operator_gt(otherTime)) == "boolean" and type(time:operator_ge(otherTime)) == "boolean")
    assert(type(time:operator_lt(otherTime)) == "boolean" and type(time:operator_le(otherTime)) == "boolean")
    assert(type(time:operator_eq(otherTime)) == "boolean")
    assert(time:operator_assign(otherTime) == time)

    assert(type(states:setupFrom(data, "fixture")) == "boolean")
    states:reset()
    assert(type(states:isTrue()) == "boolean")
    states.statesList = stateMap
    assert(states.statesList == stateMap)
    assert(type(stateMap:has(query)) == "boolean" and type(stateMap:contains(query)) == "boolean")
    assert(type(stateMap:remove(query)) == "boolean" and type(stateMap:erase(query)) == "boolean")
    assert(stateMap:size() >= 0 and stateMap:toTable() ~= nil)
    local iterator, mapState, control = stateMap:pairs()
    assert(type(iterator) == "function" and mapState == stateMap and control == nil)
    stateMap:clear()
end

return checkDialogueSupport
