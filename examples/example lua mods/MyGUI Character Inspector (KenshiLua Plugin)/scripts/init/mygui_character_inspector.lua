-- mygui_character_inspector.lua
-- An example script demonstrating how to use the custom MyGUI Lua bindings.
-- It listens to Character selection/unselection events and displays the selected
-- character's name, strength, dexterity, and toughness in a custom MyGUI window.
-- It also includes buttons to heal the character or buff their strength.

-- Clean up any existing window from a previous run to avoid overlaying zombie windows
if CharInspectorWindow then
    CharInspectorWindow:destroy()
    CharInspectorWindow = nil
end

local log = KenshiLua.log

local inspectingChar = nil
local labelName = nil
local labelStr = nil
local labelDex = nil
local labelTough = nil

-- Update stats labels on the window
local function updateStatsLabels()
    if not inspectingChar or not inspectingChar:isValid() then return end
    
    if labelName then
        labelName:setCaption("Name: " .. inspectingChar:getName())
    end
    
    local stats = inspectingChar:getStats()
    if stats then
        if labelStr then labelStr:setCaption("Strength: " .. string.format("%.1f", stats:getStrength())) end
        if labelDex then labelDex:setCaption("Dexterity: " .. string.format("%.1f", stats:getDexterity())) end
        if labelTough then labelTough:setCaption("Toughness: " .. string.format("%.1f", stats:getToughness())) end
    else
        if labelStr then labelStr:setCaption("Strength: N/A") end
        if labelDex then labelDex:setCaption("Dexterity: N/A") end
        if labelTough then labelTough:setCaption("Toughness: N/A") end
    end
end

-- Lazily create or retrieve the Inspector Window
local function getOrCreateWindow()
    if CharInspectorWindow then return CharInspectorWindow end

    -- Create the main inspector Window (increased size to 450x320 to fit all elements and prevent button text clipping)
    -- The 8th parameter is the layer name ("Window").
    CharInspectorWindow = MyGUI.createWidget("Window", "Kenshi_WindowCX", 150, 150, 450, 320, "CharInspectorWindow", "Window")
    if not CharInspectorWindow then
        log("[CharInspector] Failed to create inspector window")
        return nil
    end

    CharInspectorWindow:setCaption("Character Inspector")
    CharInspectorWindow:setVisible(false)

    CharInspectorWindow:registerCallback("WindowButtonPressed", function(window, buttonName)
        if buttonName == "close" then
            window:setVisible(false)
            MyGUI.resetKeyFocus()
        end
    end)

    -- Get the actual client area widget of the window
    local client = CharInspectorWindow:getClientWidget() or CharInspectorWindow

    -- Helper to create labels using Kenshi_TextboxPaintedText template from kenshi_templates.xml
    local function createLabel(x, y, w, h, name, parent)
        local lbl = MyGUI.createWidget("TextBox", "Kenshi_TextboxPaintedText", x, y, w, h, name, parent)
        if lbl then
            lbl:setProperty("TextAlign", "Left VCenter")
        end
        return lbl
    end

    -- 1. Character Name Label (positioned with generous spacing and width)
    labelName = createLabel(20, 20, 410, 30, "LabelName", client)

    -- 2. Stats Labels
    labelStr = createLabel(20, 60, 410, 30, "LabelStr", client)
    labelDex = createLabel(20, 100, 410, 30, "LabelDex", client)
    labelTough = createLabel(20, 140, 410, 30, "LabelTough", client)

    -- 3. Action Buttons (height 40 to fit skin proportion, widths 190 to avoid text clipping)
    -- Heal Button
    local btnHeal = MyGUI.createWidget("Button", "Kenshi_Button1", 20, 200, 190, 40, "BtnHeal", client)
    if btnHeal then
        btnHeal:setCaption("Heal Completely")
        btnHeal:registerCallback("MouseButtonClick", function(widget)
            if inspectingChar and inspectingChar:isValid() then
                inspectingChar:healCompletely()
                log("[CharInspector] Healed character: " .. inspectingChar:getName())
            end
        end)
    end

    -- Buff Button (Sets Strength to 100)
    local btnBuff = MyGUI.createWidget("Button", "Kenshi_Button1", 230, 200, 190, 40, "BtnBuff", client)
    if btnBuff then
        btnBuff:setCaption("Set Strength 100")
        btnBuff:registerCallback("MouseButtonClick", function(widget)
            if inspectingChar and inspectingChar:isValid() then
                local stats = inspectingChar:getStats()
                if stats then
                    stats._strength = 100.0
                    updateStatsLabels()
                    log("[CharInspector] Set strength of " .. inspectingChar:getName() .. " to 100")
                end
            end
        end)
    end

    return CharInspectorWindow
end

-- Handles Character selection
local function onSelect(character)
    if not character or not character:isValid() then
        return
    end

    inspectingChar = character
    
    local w = getOrCreateWindow()
    if w then
        updateStatsLabels()
        w:setVisible(true)
    end
end

-- Handles Character unselection
local function onUnselect(character)
    inspectingChar = nil
    if CharInspectorWindow then
        CharInspectorWindow:setVisible(false)
    end
end

-- Periodic update to keep stats current
local function onUpdate()
    if inspectingChar and inspectingChar:isValid() then
        updateStatsLabels()
    end
end

log("[CharInspector] Registering character select/unselect/update event handlers")
registerHandler("onCharacterSelect", onSelect)
registerHandler("onCharacterUnselect", onUnselect)
registerHandler("onCharsUpdate", onUpdate)
log("[CharInspector] Initialization complete")
