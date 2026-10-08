---@param editor GameDataEditorWindow
---@param panel DatapanelGUI
---@param data GameData
---@param box PortraitSquadItemBox
local function check(editor, panel, data, box)
 editor.win, editor.data = panel, data; editor:_NV_show(true); editor:initDataValues()
 assert(box:getItemCount() >= 0); box:update()
end
return check
