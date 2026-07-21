-- Example script demonstrating KenshiLua MyGUI bindings using responsive position_real coordinates
-- Save this file as a lua script to be loaded by the mod loader

-- 1. Create a Main Window using relative position_real coordinates (0.0 to 1.0)
-- Coordinates (0.30, 0.20, 0.30, 0.45) scale responsively across all screen resolutions (e.g. 1920x1080, 2560x1600)
-- MyGUI.createWindow(skin, x, y, width, height, name, parentOrLayer)
local mainWindow = MyGUI.createWindow("Kenshi_WindowCX", 0.30, 0.20, 0.30, 0.45, "ExampleWindow", "Window")
mainWindow:setCaption("MyGUI Example Window")
mainWindow:setMovable(true)

-- 2. Create a Button inside the Window (relative to mainWindow)
-- Positioned at x=5%, y=10%, width=45%, height=8% of the parent window
local myButton = MyGUI.createButton("Kenshi_Button1", 0.05, 0.10, 0.45, 0.08, "ExampleButton", mainWindow)
myButton:setCaption("Click Me!")

-- Register a click callback
myButton:registerCallback("click", function(widget)
    print("Button clicked!")
    widget:setCaption("Clicked!")
    -- Let's change the window caption too!
    mainWindow:setCaption("You clicked the button!")
end)

-- 3. Create an EditBox (Text Input)
-- Positioned at x=5%, y=22%, width=55%, height=8% of parent window
local editBox = MyGUI.createEditBox("Kenshi_EditBox", 0.05, 0.22, 0.55, 0.08, "ExampleEditBox", mainWindow)
editBox:setCaption("Type something here...")
editBox:setEditMultiLine(false)

-- Register text change callback
editBox:registerCallback("change", function(widget)
    -- We can read what the user typed:
    local currentText = widget:getCaption()
    print("User typed: " .. currentText)
end)

-- 4. Create a ListBox
-- Positioned at x=5%, y=34%, width=55%, height=38% of parent window
local listBox = MyGUI.createListBox("Kenshi_ListBox", 0.05, 0.34, 0.55, 0.38, "ExampleListBox", mainWindow)
listBox:addItem("First Item")
listBox:addItem("Second Item")
listBox:addItem("Third Item")

-- Register selection callback
listBox:registerCallback("change", function(widget)
    local index = widget:getIndexSelected()
    if index ~= -1 then -- -1 means no selection
        local selectedName = widget:getItemNameAt(index)
        print("Selected item index " .. index .. ": " .. selectedName)
        editBox:setCaption("Selected: " .. selectedName)
    end
end)

-- 5. Creating a generic TextBox (Label)
-- Positioned at x=5%, y=76%, width=60%, height=6% of parent window
local label = MyGUI.createTextBox("Kenshi_TextboxPaintedText", 0.05, 0.76, 0.60, 0.06, "ExampleLabel", mainWindow)
label:setCaption("This is a simple text label.")
-- We can set its text alignment or color using properties
label:setProperty("TextAlign", "Left VCenter")
label:setProperty("TextColour", "1 0 0") -- Red text

-- Finally, make sure the main window is visible
mainWindow:setVisibleSmooth(true)

-- Hook up the window frame close button ("x" icon in the upper-right of Kenshi_WindowCX)
mainWindow:registerCallback("windowButtonPressed", function(window, buttonName)
    print("Window button pressed: " .. tostring(buttonName))
    if buttonName == "close" then
        window:destroySmooth()
    end
end)

-- We can also create an explicit close button inside the window body (x=68%, y=85%, width=27%, height=8%):
local closeBtn = MyGUI.createButton("Kenshi_Button1", 0.68, 0.85, 0.27, 0.08, "CloseButton", mainWindow)
closeBtn:setCaption("Close")
closeBtn:registerCallback("click", function(widget)
    mainWindow:destroySmooth()
end)
