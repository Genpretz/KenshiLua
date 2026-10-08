---@param portrait PortraitImage
---@param image MyGUI.ImageBox
---@param marker MapMarkerCharacter
---@param handle hand
local function check(portrait, image, marker, handle)
 portrait.index, portrait.created, portrait.textureName = 1, true, "fixture"; portrait:updateImageWidget(image, true)
 marker.handle = handle; marker:setVisible(true); assert(marker:getVisible())
end
return check
