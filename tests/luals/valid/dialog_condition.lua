-- LuaLS regression fixture: dialog conditions and line-owned lektors.

---@param condition DialogCondition
---@param action DialogAction
---@param conditions Lektor<DialogCondition>
---@param actions Lektor<DialogAction>
local function checkDialogCondition(condition, action, conditions, actions)
    condition.key = DialogConditionEnum.DC_NONE
    condition.compareBy = ComparisonEnum.CE_EQUALS
    condition.who = TalkerEnum.T_ME
    condition.value = 1
    assert(condition.key == DialogConditionEnum.DC_NONE)
    assert(condition.compareBy == ComparisonEnum.CE_EQUALS)
    assert(condition.who == TalkerEnum.T_ME and condition.value == 1)

    conditions:push(condition)
    assert(conditions:pop() == condition)
    conditions:removeAt(1)
    assert(conditions:size() >= 0 and conditions:toTable() ~= nil)
    conditions:clear()

    actions:push(action)
    assert(actions:pop() == action)
    actions:removeAt(1)
    assert(actions:size() >= 0 and actions:toTable() ~= nil)
    actions:clear()
end

return checkDialogCondition
