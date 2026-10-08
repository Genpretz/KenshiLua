---@param box SquadItemBox
---@param data SquadData
---@param platoon ActivePlatoon
---@param messageBox Box
local function check(box, data, platoon, messageBox)
 box:setCellSize(10, 10); assert(box:getItemCount() >= 0)
 data:setName("fixture"); data.platoon = platoon; assert(data:getName() == "fixture")
 assert(type(MessageBoxManager.hideMessageBox(true)) == "boolean")
 assert(type(MessageBoxManager.hasModalMessage()) == "boolean")
 MessageBoxManager.removeMessageBox(messageBox, 1)
end
return check
