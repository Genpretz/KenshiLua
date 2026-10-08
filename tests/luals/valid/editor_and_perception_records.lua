---@param item GameDataEditorWindow_DataItem
---@param visibility WhoSeesMe
---@param state YesNoMaybeValue
---@param ptr lightuserdata
local function check(item, visibility, state, ptr)
    item.name, item.edit, item.label = "fixture", ptr, ptr
    visibility.lastUpdated, visibility.seeState, visibility.progressOfMaybe = 1, state, 0.5
    assert(item.name == "fixture" and visibility.seeState == state)
end
return check
