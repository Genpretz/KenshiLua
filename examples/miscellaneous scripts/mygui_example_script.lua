-- Example script demonstrating KenshiLua MyGUI bindings
-- Save this file as a lua script to be loaded by the mod loader

-- 1. Create a Main Window
-- MyGUI.createWindow(skin, x, y, width, height, name, parentOrLayer)
-- We use layer "Window" if there's no parent.
-- Kenshi skins usually prefix with "Kenshi_"
local mainWindow = MyGUI.createWindow("Kenshi_WindowCX", 100, 100, 400, 400, "ExampleWindow", "Window")
mainWindow:setCaption("MyGUI Example Window")
mainWindow:setMovable(true)

-- 2. Create a Button inside the Window
-- We pass `mainWindow` as the 7th argument (parent)
local myButton = MyGUI.createButton("Kenshi_Button1", 20, 40, 150, 30, "ExampleButton", mainWindow)
myButton:setCaption("Click Me!")

-- Register a click callback
myButton:registerCallback("click", function(widget)
    print("Button clicked!")
    widget:setCaption("Clicked!")
    -- Let's change the window caption too!
    mainWindow:setCaption("You clicked the button!")
end)

-- 3. Create an EditBox (Text Input)
local editBox = MyGUI.createEditBox("Kenshi_EditBox", 20, 90, 200, 30, "ExampleEditBox", mainWindow)
editBox:setCaption("Type something here...")
editBox:setEditMultiLine(false)

-- Register text change callback
editBox:registerCallback("change", function(widget)
    -- We can read what the user typed:
    local currentText = widget:getCaption()
    print("User typed: " .. currentText)
end)

-- 4. Create a ListBox
local listBox = MyGUI.createListBox("Kenshi_ListBox", 20, 140, 200, 150, "ExampleListBox", mainWindow)
listBox:addItem("First Item")
listBox:addItem("Second Item")
listBox:addItem("Third Item")

-- Register selection callback
listBox:registerCallback("change", function(widget)
    -- Note: for ListBox, "change" might map to ListChangePosition or ListSelectAccept
    local index = widget:getIndexSelected()
    if index ~= -1 then -- -1 means no selection
        local selectedName = widget:getItemNameAt(index)
        print("Selected item index " .. index .. ": " .. selectedName)
        editBox:setCaption("Selected: " .. selectedName)
    end
end)

-- 5. Creating a generic TextBox (Label)
local label = MyGUI.createTextBox("Kenshi_TextboxPaintedText", 20, 310, 300, 20, "ExampleLabel", mainWindow)
label:setCaption("This is a simple text label.")
-- We can set its text alignment or color using properties
label:setProperty("TextAlign", "Left VCenter")
label:setProperty("TextColour", "1 0 0") -- Red text

-- Finally, make sure the main window is visible
mainWindow:setVisibleSmooth(true)

-- To clean up later or close the window, you could bind a close button:
local closeBtn = MyGUI.createButton("Kenshi_Button1", 250, 310, 100, 30, "CloseButton", mainWindow)
closeBtn:setCaption("Close")
closeBtn:registerCallback("click", function(widget)
    mainWindow:destroySmooth()
end)
