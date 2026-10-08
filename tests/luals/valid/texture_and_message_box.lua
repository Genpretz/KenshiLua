-- LuaLS regression fixture: message box and texture-load records.

---@param box Box
---@param widget MyGUI.Widget
---@param textures TextureArrayLoadData
---@param ptr lightuserdata
local function checkTextureAndMessageBox(box, widget, textures, ptr)
    box.modal = true
    box:buttonClick(widget)
    box:buttonClick()
    assert(box.modal and (box.callback == nil or box.callback == ptr))
    textures:loadImage()
    textures:_NV_loadImage()
end

return checkTextureAndMessageBox
