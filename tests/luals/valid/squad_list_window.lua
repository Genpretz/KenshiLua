---@param window SquadListWindow
---@param data GameData
local function check(window, data)
 window:refresh(data); window:itemSelected(data); window:_NV_itemSelected(data)
end
return check
