--- ============================================================================
--- KenshiLua MyGUI Layout Helpers Module
--- File: lib/mygui/layout.lua
--- ============================================================================
--- Provides high-level, declarative, and auto-stacking layout containers
--- (VBox, HBox, and Grid) on top of KenshiLua's 1-to-1 C++ MyGUI bindings.
---
--- Usage:
---   local Layout = require("mygui.layout")
---   local vbox = Layout.createVBox(myWindow, { padding = 10, spacing = 6 })
---   vbox:addLabel("Character Statistics:")
---   vbox:addButton("Heal Character", function(sender) ... end)
---   vbox:addRow("Name:", myEditBox)
--- ============================================================================

local Layout = {}

-- ----------------------------------------------------------------------------
-- Helper utilities
-- ----------------------------------------------------------------------------
local function mergeOptions(defaults, opts)
    local res = {}
    for k, v in pairs(defaults) do res[k] = v end
    if opts then
        for k, v in pairs(opts) do res[k] = v end
    end
    return res
end

-- ============================================================================
-- VBox (Vertical Stacking Box)
-- ============================================================================
local VBox = {}
VBox.__index = VBox

local VBOX_DEFAULTS = {
    startX = 10,
    startY = 10,
    padding = 10,
    spacing = 6,
    defaultWidth = 140,
    defaultHeight = 24,
    align = 0 -- MyGUI.Align.Default
}

--- Creates a new VBox vertical layout manager inside a parent widget.
--- @param parent userdata MyGUI.Widget parent
--- @param options table Optional configuration table
function Layout.createVBox(parent, options)
    local self = setmetatable({}, VBox)
    self.parent = parent
    self.opts = mergeOptions(VBOX_DEFAULTS, options)
    self.curX = self.opts.startX
    self.curY = self.opts.startY
    self.maxWidth = 0
    self.widgets = {}
    return self
end

--- Adds an existing widget to the vertical stack, advancing the vertical cursor.
--- @param widget userdata MyGUI.Widget
--- @param width number Optional custom width
--- @param height number Optional custom height
--- @return userdata The added widget
function VBox:addWidget(widget, width, height)
    if not widget then return nil end
    local w = width or (widget.getSize and select(1, widget:getSize())) or self.opts.defaultWidth
    local h = height or (widget.getSize and select(2, widget:getSize())) or self.opts.defaultHeight

    widget:setPosition(self.curX, self.curY)
    if width or height then
        widget:setSize(w, h)
    end

    self.curY = self.curY + h + self.opts.spacing
    if w > self.maxWidth then self.maxWidth = w end
    table.insert(self.widgets, widget)
    return widget
end

--- Alias for addWidget
function VBox:add(widget, width, height)
    return self:addWidget(widget, width, height)
end

--- Adds spacing/padding without adding a widget.
--- @param amount number Optional pixels to advance (defaults to opts.spacing)
function VBox:addSpace(amount)
    self.curY = self.curY + (amount or self.opts.spacing)
end

--- Creates and adds a TextBox label to the VBox.
--- @param text string Caption text
--- @param width number Optional custom width
--- @param height number Optional custom height
--- @param skin string Optional skin (defaults to "TextBox")
--- @return userdata The created TextBox widget
function VBox:addLabel(text, width, height, skin)
    local w = width or self.opts.defaultWidth
    local h = height or 20
    local label = self.parent:createWidget("TextBox", skin or "TextBox", self.curX, self.curY, w, h, self.opts.align)
    label:setCaption(text or "")
    self.curY = self.curY + h + self.opts.spacing
    if w > self.maxWidth then self.maxWidth = w end
    table.insert(self.widgets, label)
    return label
end

--- Creates and adds a clickable Button to the VBox.
--- @param caption string Button text
--- @param onClick function Click callback function(sender)
--- @param width number Optional custom width
--- @param height number Optional custom height
--- @param skin string Optional skin (defaults to "Button")
--- @return userdata The created Button widget
function VBox:addButton(caption, onClick, width, height, skin)
    local w = width or self.opts.defaultWidth
    local h = height or self.opts.defaultHeight
    local btn = self.parent:createWidget("Button", skin or "Button", self.curX, self.curY, w, h, self.opts.align)
    btn:setCaption(caption or "")
    if onClick and type(onClick) == "function" then
        btn:registerCallback("MouseButtonClick", onClick)
    end
    self.curY = self.curY + h + self.opts.spacing
    if w > self.maxWidth then self.maxWidth = w end
    table.insert(self.widgets, btn)
    return btn
end

--- Creates and adds an EditBox text input to the VBox.
--- @param defaultText string Initial text
--- @param onChange function Change callback function(sender)
--- @param width number Optional custom width
--- @param height number Optional custom height
--- @param skin string Optional skin (defaults to "EditBox")
--- @return userdata The created EditBox widget
function VBox:addEditBox(defaultText, onChange, width, height, skin)
    local w = width or self.opts.defaultWidth
    local h = height or self.opts.defaultHeight
    local edit = self.parent:createWidget("EditBox", skin or "EditBox", self.curX, self.curY, w, h, self.opts.align)
    edit:setCaption(defaultText or "")
    if onChange and type(onChange) == "function" then
        edit:registerCallback("EditTextChange", onChange)
    end
    self.curY = self.curY + h + self.opts.spacing
    if w > self.maxWidth then self.maxWidth = w end
    table.insert(self.widgets, edit)
    return edit
end

--- Creates and adds a ComboBox dropdown to the VBox.
--- @param items table Array of string item names
--- @param onSelect function Select callback function(sender, index)
--- @param width number Optional custom width
--- @param height number Optional custom height
--- @param skin string Optional skin (defaults to "ComboBox")
--- @return userdata The created ComboBox widget
function VBox:addComboBox(items, onSelect, width, height, skin)
    local w = width or self.opts.defaultWidth
    local h = height or self.opts.defaultHeight
    local combo = self.parent:createWidget("ComboBox", skin or "ComboBox", self.curX, self.curY, w, h, self.opts.align)
    if items and type(items) == "table" then
        for _, item in ipairs(items) do
            combo:addItem(tostring(item))
        end
        if #items > 0 then
            combo:setIndexSelected(0)
        end
    end
    if onSelect and type(onSelect) == "function" then
        combo:registerCallback("ComboAccept", onSelect)
    end
    self.curY = self.curY + h + self.opts.spacing
    if w > self.maxWidth then self.maxWidth = w end
    table.insert(self.widgets, combo)
    return combo
end

--- Creates a horizontal pair row (e.g. Label + EditBox/Value) inside the VBox.
--- @param labelText string Label text on the left
--- @param rightItem string|userdata Text string or Widget on the right
--- @param labelWidth number Optional width of the label column (defaults to 70)
--- @param totalWidth number Optional total row width
--- @param rowHeight number Optional row height (defaults to 22)
--- @return table { label = TextBox, right = Widget }
function VBox:addRow(labelText, rightItem, labelWidth, totalWidth, rowHeight)
    local lw = labelWidth or 70
    local tw = totalWidth or self.opts.defaultWidth
    local rh = rowHeight or 22
    local rw = math.max(20, tw - lw - self.opts.spacing)

    local lbl = self.parent:createWidget("TextBox", "TextBox", self.curX, self.curY, lw, rh, self.opts.align)
    lbl:setCaption(labelText or "")

    local rightWidget = nil
    if type(rightItem) == "string" then
        rightWidget = self.parent:createWidget("TextBox", "TextBox", self.curX + lw + self.opts.spacing, self.curY, rw, rh, self.opts.align)
        rightWidget:setCaption(rightItem)
    elseif rightItem then
        rightWidget = rightItem
        rightWidget:setPosition(self.curX + lw + self.opts.spacing, self.curY)
        rightWidget:setSize(rw, rh)
    end

    self.curY = self.curY + rh + self.opts.spacing
    if tw > self.maxWidth then self.maxWidth = tw end
    table.insert(self.widgets, lbl)
    if rightWidget then table.insert(self.widgets, rightWidget) end

    return { label = lbl, right = rightWidget }
end

--- Creates a nested HBox within this VBox. When finished with the HBox, call `vbox:commitHBox(hbox)`.
--- @param options table Optional HBox options
--- @return table HBox instance
function VBox:createHBox(options)
    local opts = mergeOptions(self.opts, options)
    opts.startX = self.curX
    opts.startY = self.curY
    return Layout.createHBox(self.parent, opts)
end

--- Commits a child HBox, advancing the VBox vertical cursor past the HBox.
--- @param hbox table The HBox instance
function VBox:commitHBox(hbox)
    if not hbox then return end
    local bounds = hbox:getBounds()
    self.curY = self.curY + bounds.height + self.opts.spacing
    if bounds.width > self.maxWidth then
        self.maxWidth = bounds.width
    end
end

--- Gets layout cursor metrics and bounding box.
--- @return table { x = number, y = number, width = number, height = number }
function VBox:getBounds()
    return {
        x = self.opts.startX,
        y = self.opts.startY,
        width = self.maxWidth,
        height = self.curY - self.opts.startY
    }
end

--- Resets the vertical cursor back to the starting position.
function VBox:reset()
    self.curX = self.opts.startX
    self.curY = self.opts.startY
    self.maxWidth = 0
end

-- ============================================================================
-- HBox (Horizontal Stacking Box)
-- ============================================================================
local HBox = {}
HBox.__index = HBox

local HBOX_DEFAULTS = {
    startX = 10,
    startY = 10,
    padding = 10,
    spacing = 6,
    defaultWidth = 80,
    defaultHeight = 24,
    align = 0
}

--- Creates a new HBox horizontal layout manager inside a parent widget.
--- @param parent userdata MyGUI.Widget parent
--- @param options table Optional configuration table
function Layout.createHBox(parent, options)
    local self = setmetatable({}, HBox)
    self.parent = parent
    self.opts = mergeOptions(HBOX_DEFAULTS, options)
    self.curX = self.opts.startX
    self.curY = self.opts.startY
    self.maxHeight = 0
    self.widgets = {}
    return self
end

--- Adds an existing widget to the horizontal stack, advancing the horizontal cursor.
--- @param widget userdata MyGUI.Widget
--- @param width number Optional custom width
--- @param height number Optional custom height
--- @return userdata The added widget
function HBox:addWidget(widget, width, height)
    if not widget then return nil end
    local w = width or (widget.getSize and select(1, widget:getSize())) or self.opts.defaultWidth
    local h = height or (widget.getSize and select(2, widget:getSize())) or self.opts.defaultHeight

    widget:setPosition(self.curX, self.curY)
    if width or height then
        widget:setSize(w, h)
    end

    self.curX = self.curX + w + self.opts.spacing
    if h > self.maxHeight then self.maxHeight = h end
    table.insert(self.widgets, widget)
    return widget
end

--- Alias for addWidget
function HBox:add(widget, width, height)
    return self:addWidget(widget, width, height)
end

--- Adds spacing/padding without adding a widget.
--- @param amount number Optional pixels to advance (defaults to opts.spacing)
function HBox:addSpace(amount)
    self.curX = self.curX + (amount or self.opts.spacing)
end

--- Creates and adds a TextBox label to the HBox.
function HBox:addLabel(text, width, height, skin)
    local w = width or self.opts.defaultWidth
    local h = height or 20
    local label = self.parent:createWidget("TextBox", skin or "TextBox", self.curX, self.curY, w, h, self.opts.align)
    label:setCaption(text or "")
    self.curX = self.curX + w + self.opts.spacing
    if h > self.maxHeight then self.maxHeight = h end
    table.insert(self.widgets, label)
    return label
end

--- Creates and adds a clickable Button to the HBox.
function HBox:addButton(caption, onClick, width, height, skin)
    local w = width or self.opts.defaultWidth
    local h = height or self.opts.defaultHeight
    local btn = self.parent:createWidget("Button", skin or "Button", self.curX, self.curY, w, h, self.opts.align)
    btn:setCaption(caption or "")
    if onClick and type(onClick) == "function" then
        btn:registerCallback("MouseButtonClick", onClick)
    end
    self.curX = self.curX + w + self.opts.spacing
    if h > self.maxHeight then self.maxHeight = h end
    table.insert(self.widgets, btn)
    return btn
end

--- Gets layout cursor metrics and bounding box.
--- @return table { x = number, y = number, width = number, height = number }
function HBox:getBounds()
    return {
        x = self.opts.startX,
        y = self.opts.startY,
        width = self.curX - self.opts.startX,
        height = self.maxHeight
    }
end

--- Resets the horizontal cursor back to the starting position.
function HBox:reset()
    self.curX = self.opts.startX
    self.curY = self.opts.startY
    self.maxHeight = 0
end

-- ============================================================================
-- Grid (Grid Table Layout)
-- ============================================================================
local Grid = {}
Grid.__index = Grid

local GRID_DEFAULTS = {
    columns = 2,
    colWidth = 110,
    rowHeight = 24,
    startX = 10,
    startY = 10,
    spacingX = 6,
    spacingY = 6,
    align = 0
}

--- Creates a new Grid layout manager inside a parent widget.
--- @param parent userdata MyGUI.Widget parent
--- @param options table Optional grid configuration
function Layout.createGrid(parent, options)
    local self = setmetatable({}, Grid)
    self.parent = parent
    self.opts = mergeOptions(GRID_DEFAULTS, options)
    self.colIndex = 0
    self.rowIndex = 0
    self.widgets = {}
    return self
end

--- Adds a widget at the current grid cell and advances to the next cell.
--- @param widget userdata MyGUI.Widget
--- @param colSpan number Number of columns to span (default 1)
--- @param rowSpan number Number of rows to span (default 1)
function Grid:addWidget(widget, colSpan, rowSpan)
    if not widget then return nil end
    local cs = colSpan or 1
    local rs = rowSpan or 1

    local x = self.opts.startX + self.colIndex * (self.opts.colWidth + self.opts.spacingX)
    local y = self.opts.startY + self.rowIndex * (self.opts.rowHeight + self.opts.spacingY)
    local w = cs * self.opts.colWidth + (cs - 1) * self.opts.spacingX
    local h = rs * self.opts.rowHeight + (rs - 1) * self.opts.spacingY

    widget:setPosition(x, y)
    widget:setSize(w, h)

    self.colIndex = self.colIndex + cs
    if self.colIndex >= self.opts.columns then
        self.colIndex = 0
        self.rowIndex = self.rowIndex + 1
    end

    table.insert(self.widgets, widget)
    return widget
end

--- Creates and adds a label + value/control pair to the grid row.
--- @param labelText string Label text
--- @param rightItem string|userdata String or Widget for second column
function Grid:addRow(labelText, rightItem)
    local lbl = self.parent:createWidget("TextBox", "TextBox", 0, 0, self.opts.colWidth, self.opts.rowHeight, self.opts.align)
    lbl:setCaption(labelText or "")
    self:addWidget(lbl)

    if type(rightItem) == "string" then
        local val = self.parent:createWidget("TextBox", "TextBox", 0, 0, self.opts.colWidth, self.opts.rowHeight, self.opts.align)
        val:setCaption(rightItem)
        self:addWidget(val)
    elseif rightItem then
        self:addWidget(rightItem)
    end
end

-- ============================================================================
-- Module Export
-- ============================================================================
Layout.VBox = VBox
Layout.HBox = HBox
Layout.Grid = Grid

return Layout
