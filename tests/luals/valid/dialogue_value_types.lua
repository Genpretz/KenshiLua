-- LuaLS regression fixture: dialogue action, choice list, and line lektor.

---@param action DialogAction
---@param choices DialogChoiceList
---@param lines Lektor<DialogLineData>
---@param line DialogLineData
---@param conversation GameData
local function checkDialogueValueTypes(action, choices, lines, line, conversation)
    action.key = DialogActionEnum.DA_NONE
    action.value = 1
    assert(action.key == DialogActionEnum.DA_NONE and action.value == 1)

    choices:add(conversation, line)
    choices.conversationChoices = lines
    assert(choices.conversationChoices == lines)

    lines:push(line)
    assert(lines:pop() == line)
    lines:removeAt(1)
    assert(lines:size() >= 0 and lines:toTable() ~= nil)
    lines:clear()
end

return checkDialogueValueTypes
