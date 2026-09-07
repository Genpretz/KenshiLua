-- KenshiLua MyGUI Theme & Skin Reference Module
-- Contains authentic skin names and template layouts from Kenshi's data/gui XML files
-- (common_skins.xml, kenshi_skins.xml, kenshi_templates.xml)

local Theme = {}

--- Canonical Kenshi Window templates
Theme.Windows = {
    Default      = "Kenshi_WindowCX",         -- Standard window with close button
    Base         = "Kenshi_Window",           -- Plain frame window (no buttons)
    Client       = "Kenshi_WindowC",          -- Client window frame
    WithClose    = "Kenshi_WindowCX",         -- Window with close [X] button
    WithMinimize = "Kenshi_WindowCXM",        -- Window with close [X] and minimize [-] buttons
    WithPin      = "Kenshi_WindowCXP",        -- Window with close [X] and pin buttons
    Inventory    = "Kenshi_InventoryWindowCXP"-- Inventory style window with close + pin
}

--- Canonical Kenshi Button templates
Theme.Buttons = {
    Default      = "Kenshi_Button1",          -- Standard Kenshi clickable button
    Primary      = "Kenshi_Button1",
    Secondary    = "Kenshi_Button2",
    Tick         = "Kenshi_TickButton1",      -- Checkbox / toggle tick button
    Tick2        = "Kenshi_TickButton2"
}

--- Canonical Kenshi TextBox (Label) templates
Theme.TextBoxes = {
    Default        = "Kenshi_TextboxPaintedText",           -- Standard Kenshi UI painted font
    Painted        = "Kenshi_TextboxPaintedText",
    PaintedLarge   = "Kenshi_TextboxPaintedText_Large",
    Standard       = "Kenshi_TextboxStandardText",          -- Clean sans-serif font
    StandardSmall  = "Kenshi_TextboxStandardText_Small",
    StandardLarge  = "Kenshi_TextboxStandardText_Large",
    Generic        = "Kenshi_GenericTextBox",
    Flat           = "Kenshi_GenericTextBoxFlat",
    WordWrap       = "Kenshi_WordWrap",
    WordWrapLarge  = "Kenshi_WordWrapEmpty_StandardText_Large"
}

--- Canonical Kenshi EditBox (Text Input) templates
Theme.EditBoxes = {
    Default      = "Kenshi_EditBox",              -- Standard text input field
    Standard     = "Kenshi_EditBoxStandardText",
    Painted      = "Kenshi_EditBoxPaintedText"
}

--- Canonical Kenshi ComboBox templates
Theme.ComboBoxes = {
    Default      = "Kenshi_ComboBox"              -- Dropdown combo box with button & list
}

--- Canonical Kenshi ListBox templates
Theme.ListBoxes = {
    Default      = "Kenshi_ListBox",              -- Standard scrollable list
    Empty        = "Kenshi_ListBoxEmpty",
    Multi        = "Kenshi_MultiListBox"          -- Multi-column list box
}

--- Canonical Kenshi ScrollBar templates
Theme.ScrollBars = {
    Default      = "Kenshi_ScrollBarH",
    Horizontal   = "Kenshi_ScrollBarH",
    Vertical     = "Kenshi_ScrollBarV",
    BigVertical  = "Kenshi_ScrollBarVBig",
    BigHorizontal= "Kenshi_ScrollBarHBig"
}

--- Canonical Kenshi ScrollView templates
Theme.ScrollViews = {
    Default      = "Kenshi_ScrollView",
    Map          = "Kenshi_ScrollViewMap",
    Empty        = "Kenshi_ScrollViewEmpty"
}

--- Canonical Kenshi ProgressBar templates
Theme.ProgressBars = {
    Default      = "Kenshi_ProgressBarFill"       -- Standard health / action bar fill
}

--- Canonical Kenshi TabControl templates
Theme.Tabs = {
    Default      = "Kenshi_TabControl",           -- Standard multi-page tab bar
    Squad        = "Kenshi_SquadTabControl"
}

--- Engine utility skins from common_skins.xml
Theme.CommonSkins = {
    ImageBox     = "ImageBox",
    Canvas       = "Canvas",
    PanelEmpty   = "PanelEmpty",
    WhiteSkin    = "WhiteSkin",
    RotatingSkin = "RotatingSkin",
    PolygonalSkin= "PolygonalSkin"
}

--- Checks if a skin or template exists in MyGUI's active engine managers.
--- @param skinName string The skin or template name to check
--- @return boolean True if the skin exists in SkinManager or ResourceManager
function Theme.isExist(skinName)
    if not skinName or skinName == "" then return false end
    if MyGUI and MyGUI.isSkinExist then
        return MyGUI.isSkinExist(skinName)
    end
    return false
end

--- Returns the default Kenshi theme skin name for a given widget type.
--- @param widgetType string The MyGUI widget type (e.g. "Button", "Window", "TextBox")
--- @return string The canonical Kenshi skin or template name
function Theme.get(widgetType)
    if widgetType == "Button" then
        return Theme.Buttons.Default
    elseif widgetType == "Window" then
        return Theme.Windows.Default
    elseif widgetType == "TextBox" then
        return Theme.TextBoxes.Default
    elseif widgetType == "EditBox" then
        return Theme.EditBoxes.Default
    elseif widgetType == "ComboBox" then
        return Theme.ComboBoxes.Default
    elseif widgetType == "ListBox" then
        return Theme.ListBoxes.Default
    elseif widgetType == "ScrollBar" or widgetType == "ScrollBarH" then
        return Theme.ScrollBars.Horizontal
    elseif widgetType == "ScrollBarV" then
        return Theme.ScrollBars.Vertical
    elseif widgetType == "ScrollView" then
        return Theme.ScrollViews.Default
    elseif widgetType == "ProgressBar" then
        return Theme.ProgressBars.Default
    elseif widgetType == "TabControl" then
        return Theme.Tabs.Default
    elseif widgetType == "MultiListBox" then
        return Theme.ListBoxes.Multi
    elseif widgetType == "ImageBox" then
        return Theme.CommonSkins.ImageBox
    elseif widgetType == "Canvas" then
        return Theme.CommonSkins.Canvas
    end
    return "Default"
end

--- Resolves a skin name, returning the custom skin if provided or falling back to the Kenshi theme default.
--- @param widgetType string Widget type name ("Button", "Window", etc.)
--- @param customSkin string|nil Optional custom skin name
--- @return string The resolved skin name
function Theme.resolve(widgetType, customSkin)
    if customSkin and customSkin ~= "" then
        return customSkin
    end
    return Theme.get(widgetType)
end

return Theme
