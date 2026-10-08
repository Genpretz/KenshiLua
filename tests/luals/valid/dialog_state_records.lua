-- LuaLS regression fixture: dialogue-state record bindings.

---@param flag FlagCondition
---@param state DialogState
local function checkDialogStateRecords(flag, state)
    flag.key = 1
    flag.want = true
    flag.flags = 2
    state.count = 3
    state.lastTimeStamp = 4.5
    state.resetTime = 6.75
    assert(flag.key == 1 and flag.want and flag.flags == 2)
    assert(state.count == 3 and state.lastTimeStamp >= 0 and state.resetTime >= 0)
end

return checkDialogStateRecords
