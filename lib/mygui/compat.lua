--- ============================================================================
--- KenshiLua MyGUI Backward Compatibility Module
--- File: lib/mygui/compat.lua
--- ============================================================================
--- Restores legacy MyGUI methods and global convenience functions that were
--- removed or relocated during the modular bindings rewrite (commit 6b40c50).
---
--- Older scripts can simply add:
---   require("mygui.compat")
--- at the top of their script to restore backward compatibility.
--- ============================================================================

local Compat = {}

-- ----------------------------------------------------------------------------
-- 1. Restore Global MyGUI Helper Functions
-- ----------------------------------------------------------------------------
if MyGUI and type(MyGUI) == "table" then

    -- MyGUI.resetKeyFocus()
    if not MyGUI.resetKeyFocus then
        MyGUI.resetKeyFocus = function()
            local im = MyGUI.InputManager and MyGUI.InputManager.getInstance and MyGUI.InputManager.getInstance()
            if im and im.getKeyFocusWidget and im.resetKeyFocusWidget then
                local kw = im:getKeyFocusWidget()
                if kw then
                    im:resetKeyFocusWidget()
                end
            end
        end
    end

    -- MyGUI.setPointerVisible(visible)
    if not MyGUI.setPointerVisible then
        MyGUI.setPointerVisible = function(visible)
            local pm = MyGUI.PointerManager and MyGUI.PointerManager.getInstance and MyGUI.PointerManager.getInstance()
            if pm and pm.setVisible then
                pm:setVisible(visible ~= false)
            end
        end
    end

    -- MyGUI.isResourceExist(name)
    if not MyGUI.isResourceExist then
        MyGUI.isResourceExist = function(name)
            local sm = MyGUI.SkinManager and MyGUI.SkinManager.getInstance and MyGUI.SkinManager.getInstance()
            if sm and sm.isExist then
                return sm:isExist(tostring(name))
            end
            return false
        end
    end

    -- MyGUI.loadResource(file)
    if not MyGUI.loadResource then
        MyGUI.loadResource = function(file)
            local lm = MyGUI.LayoutManager and MyGUI.LayoutManager.getInstance and MyGUI.LayoutManager.getInstance()
            if lm and lm.loadLayout then
                return lm:loadLayout(tostring(file))
            end
            return nil
        end
    end

    -- Legacy MyGUI.createWidget adapter:
    -- Handles old signature: (type, skin, x, y, w, h, name, [parent_or_layer])
    -- along with new signature: (type, skin, x, y, w, h, [align], [layer], [name])
    local rawCreateWidget = MyGUI.createWidget
    if rawCreateWidget then
        MyGUI.createWidget = function(widgetType, skin, x, y, w, h, arg7, arg8, arg9)
            -- If arg7 is a string (widget name) and arg8 is either a widget userdata or string layer:
            if type(arg7) == "string" and (type(arg8) == "userdata" or (type(arg8) == "string" and not arg9)) then
                local name = arg7
                local parentOrLayer = arg8
                if type(parentOrLayer) == "userdata" and parentOrLayer.createWidget then
                    return parentOrLayer:createWidget(widgetType, skin, x, y, w, h, 0, name)
                else
                    local layer = (type(parentOrLayer) == "string" and parentOrLayer ~= "") and parentOrLayer or "Window"
                    return rawCreateWidget(widgetType, skin, x, y, w, h, 0, layer, name)
                end
            end
            return rawCreateWidget(widgetType, skin, x, y, w, h, arg7, arg8, arg9)
        end
    end
end

-- ----------------------------------------------------------------------------
-- 2. Restore Removed Base Methods & Monolithic Fallbacks on Metatables
-- ----------------------------------------------------------------------------
local reg = debug.getregistry()
local widgetMetatables = {
    "KenshiLua.MyGUI.Widget",
    "KenshiLua.MyGUI.Window",
    "KenshiLua.MyGUI.Button",
    "KenshiLua.MyGUI.EditBox",
    "KenshiLua.MyGUI.TextBox",
    "KenshiLua.MyGUI.ListBox",
    "KenshiLua.MyGUI.ComboBox",
    "KenshiLua.MyGUI.MultiListBox",
    "KenshiLua.MyGUI.ImageBox",
    "KenshiLua.MyGUI.ProgressBar",
    "KenshiLua.MyGUI.ScrollView",
    "KenshiLua.MyGUI.TabControl"
}

-- Screen dimension helper for relative coordinate calculations
local function getViewportSize()
    local rm = MyGUI and MyGUI.RenderManager and MyGUI.RenderManager.getInstance and MyGUI.RenderManager.getInstance()
    if rm and rm.getViewSize then
        local size = rm:getViewSize()
        if size and size.width and size.height and size.width > 0 and size.height > 0 then
            return size.width, size.height
        end
    end
    return 1920, 1080
end

-- Shared compatibility methods injected into all widget metatables
local sharedCompatMethods = {
    -- setPositionReal(x, y, [w, h]) / setCoordReal(...)
    setPositionReal = function(self, x, y, w, h)
        local vw, vh = getViewportSize()
        local px = math.floor((x or 0) * vw + 0.5)
        local py = math.floor((y or 0) * vh + 0.5)
        if self.setPosition then self:setPosition(px, py) end
        if w and h and self.setSize then
            self:setSize(math.floor(w * vw + 0.5), math.floor(h * vh + 0.5))
        end
    end,

    setCoordReal = function(self, x, y, w, h)
        return self:setPositionReal(x, y, w, h)
    end,

    -- getImageSize() -> width, height
    getImageSize = function(self)
        if self.getSize then
            return self:getSize()
        end
        return 0, 0
    end,

    -- setImageInfo(texture, ...)
    -- Supports (texture, x, y, w, h, tileW, tileH) AND (texture, coord, tile)
    setImageInfo = function(self, texture, a2, a3, a4, a5, a6, a7)
        if self.setImageTexture and texture then
            self:setImageTexture(texture)
        end
        if a5 ~= nil then
            if self.setImageCoord then
                self:setImageCoord(a2, a3, a4, a5)
            end
            if a6 ~= nil and a7 ~= nil and self.setImageTile then
                self:setImageTile(a6, a7)
            end
        else
            if a2 and self.setImageCoord then
                self:setImageCoord(a2)
            end
            if a3 and self.setImageTile then
                self:setImageTile(a3)
            end
        end
    end,

    -- setImageRect(rect) or setImageRect(x, y, w, h)
    setImageRect = function(self, a1, a2, a3, a4)
        if self.setImageCoord then
            if a4 ~= nil then
                self:setImageCoord(a1, a2, a3, a4)
            else
                self:setImageCoord(a1)
            end
        end
    end,

    -- attachToWidget(parent, [style, layer])
    attachToWidget = function(self, parent, style, layer)
        if parent and parent.getPosition and self.getPosition and self.setPosition then
            local px, py = parent:getPosition()
            local sx, sy = self:getPosition()
            self:setPosition(sx + px, sy + py)
        end
    end,

    -- detachFromWidget([layer])
    detachFromWidget = function(self, layer)
        -- Safe no-op in Lua
    end
}

-- Fallbacks specifically for the base KenshiLua.MyGUI.Widget metatable
-- (Allows scripts calling monolithic methods on generic widget handles to work)
local baseWidgetFallbacks = {
    -- Font & Text
    setFontName = function(self, name)
        if self.setProperty then self:setProperty("FontName", tostring(name)) end
    end,
    getFontName = function(self)
        return self.getProperty and self:getProperty("FontName") or ""
    end,
    setFontHeight = function(self, height)
        if self.setProperty then self:setProperty("FontHeight", tostring(height)) end
    end,
    getFontHeight = function(self)
        local h = self.getProperty and self:getProperty("FontHeight")
        return tonumber(h) or 0
    end,
    setTextAlign = function(self, align)
        if self.setProperty then self:setProperty("TextAlign", tostring(align)) end
    end,
    getTextAlign = function(self)
        local a = self.getProperty and self:getProperty("TextAlign")
        return tonumber(a) or 0
    end,
    setTextColour = function(self, colour)
        if self.setProperty then self:setProperty("TextColour", tostring(colour)) end
    end,
    getTextColour = function(self)
        return self.getProperty and self:getProperty("TextColour") or ""
    end,

    -- EditBox
    setEditReadOnly = function(self, ro)
        if self.setProperty then self:setProperty("EditReadOnly", ro and "true" or "false") end
    end,
    getEditReadOnly = function(self)
        return self.getProperty and self:getProperty("EditReadOnly") == "true"
    end,
    setEditPassword = function(self, pw)
        if self.setProperty then self:setProperty("EditPassword", pw and "true" or "false") end
    end,
    getEditPassword = function(self)
        return self.getProperty and self:getProperty("EditPassword") == "true"
    end,
    setEditMultiLine = function(self, ml)
        if self.setProperty then self:setProperty("EditMultiLine", ml and "true" or "false") end
    end,
    getEditMultiLine = function(self)
        return self.getProperty and self:getProperty("EditMultiLine") == "true"
    end,
    setEditStatic = function(self, st)
        if self.setProperty then self:setProperty("EditStatic", st and "true" or "false") end
    end,
    getEditStatic = function(self)
        return self.getProperty and self:getProperty("EditStatic") == "true"
    end,
    setPasswordChar = function(self, ch)
        if self.setProperty then self:setProperty("PasswordChar", tostring(ch)) end
    end,
    setOnlyText = function(self, ot)
        if self.setProperty then self:setProperty("OnlyText", ot and "true" or "false") end
    end,
    getOnlyText = function(self)
        return self.getProperty and self:getProperty("OnlyText") == "true"
    end,

    -- Window
    setMinSize = function(self, w, h)
        if self.setProperty then self:setProperty("MinSize", string.format("%d %d", w or 0, h or 0)) end
    end,
    getMinSize = function(self)
        local s = self.getProperty and self:getProperty("MinSize") or "0 0"
        local w, h = s:match("(%d+)%s+(%d+)")
        return tonumber(w) or 0, tonumber(h) or 0
    end,
    setMaxSize = function(self, w, h)
        if self.setProperty then self:setProperty("MaxSize", string.format("%d %d", w or 0, h or 0)) end
    end,
    getMaxSize = function(self)
        local s = self.getProperty and self:getProperty("MaxSize") or "0 0"
        local w, h = s:match("(%d+)%s+(%d+)")
        return tonumber(w) or 0, tonumber(h) or 0
    end,
    setMovable = function(self, mov)
        if self.setProperty then self:setProperty("Movable", mov and "true" or "false") end
    end,
    getMovable = function(self)
        return self.getProperty and self:getProperty("Movable") == "true"
    end,
    setVisibleSmooth = function(self, vis)
        if self.setVisible then self:setVisible(vis) end
    end,
    destroySmooth = function(self)
        if self.destroy then self:destroy() end
    end,

    -- Button
    setStateSelected = function(self, sel)
        if self.setProperty then self:setProperty("StateSelected", sel and "true" or "false") end
    end,
    getStateSelected = function(self)
        return self.getProperty and self:getProperty("StateSelected") == "true"
    end,

    -- ImageBox
    setImageTexture = function(self, tex)
        if self.setProperty then self:setProperty("ImageTexture", tostring(tex)) end
    end,
    setImageCoord = function(self, coord)
        if self.setProperty and coord then self:setProperty("ImageCoord", tostring(coord)) end
    end,
    setImageTile = function(self, tile)
        if self.setProperty and tile then self:setProperty("ImageTile", tostring(tile)) end
    end,
    setImageIndex = function(self, idx)
        if self.setProperty then self:setProperty("ImageIndex", tostring(idx)) end
    end,
    getImageIndex = function(self)
        local idx = self.getProperty and self:getProperty("ImageIndex")
        return tonumber(idx) or 0
    end
}

-- Apply patches to all active MyGUI metatables in Lua registry
local function applyPatches()
    local count = 0
    for _, metaName in ipairs(widgetMetatables) do
        local mt = reg[metaName]
        if type(mt) == "table" then
            count = count + 1
            -- Add shared methods if not already present
            for name, fn in pairs(sharedCompatMethods) do
                if not mt[name] then
                    mt[name] = fn
                end
            end
            -- Add monolithic fallbacks onto base Widget metatable
            if metaName == "KenshiLua.MyGUI.Widget" then
                for name, fn in pairs(baseWidgetFallbacks) do
                    if not mt[name] then
                        mt[name] = fn
                    end
                end
            end
        end
    end
    return count
end

Compat.apply = applyPatches
Compat.version = "1.0.0"

-- Automatically apply when required
local patchedCount = applyPatches()
Compat.patchedMetatables = patchedCount

return Compat
