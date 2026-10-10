---@param item GameDataEditorWindow_DataItem
---@param visibility WhoSeesMe
---@param state YesNoMaybeValue
---@param editBox MyGUI.EditBox
---@param label MyGUI.Widget
local function check(item, visibility, state, editBox, label)
    item.name, item.edit, item.label = "fixture", editBox, label
    visibility.lastUpdated, visibility.seeState, visibility.progressOfMaybe = 1, state, 0.5
    assert(item.name == "fixture" and visibility.seeState == state)
end
return check
