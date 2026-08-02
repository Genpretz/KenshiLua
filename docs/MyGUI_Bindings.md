# MyGUI Lua Bindings Documentation

This guide provides a comprehensive overview of the **MyGUI** bindings available in KenshiLuaJIT for creating, managing, and handling events on custom user interface elements.

---

## 1. Overview & Concepts

MyGUI widgets are created dynamically at runtime via the global `MyGUI` table. Widgets can be created either as root-level elements attached to a MyGUI layer (such as `"Window"`, `"Overlapped"`, or `"Popup"`) or as child elements attached to an existing parent widget.

### Coordinate Systems
MyGUI bindings support both **absolute pixel coordinates** (integers) and **responsive relative coordinates** (floats between `0.0` and `1.0` representing screen/parent percentages).

- **Pixel Coordinates**: `x, y, width, height` integers (e.g. `100, 200, 400, 300`).
- **Responsive Coordinates**: `fx, fy, fw, fh` floats (e.g. `0.30, 0.20, 0.40, 0.35`).

---

## 2. Widget Creation API (`MyGUI`)

### Creation Helpers
All creation functions accept skin name, coordinates, element name, and parent widget or layer name.

```lua
-- Create a Window
local window = MyGUI.createWindow("Kenshi_WindowCX", 0.30, 0.20, 0.40, 0.50, "MyWindow", "Window")

-- Create a Button inside a Window
local button = MyGUI.createButton("Kenshi_Button1", 0.05, 0.10, 0.40, 0.08, "MyButton", window)

-- Create a Text Label (TextBox)
local label = MyGUI.createTextBox("Kenshi_TextboxPaintedText", 0.05, 0.20, 0.90, 0.05, "MyLabel", window)

-- Create a Text Input (EditBox)
local editBox = MyGUI.createEditBox("Kenshi_EditBox", 0.05, 0.28, 0.90, 0.08, "MyEditBox", window)

-- Create a ListBox
local listBox = MyGUI.createListBox("Kenshi_ListBox", 0.05, 0.38, 0.90, 0.35, "MyListBox", window)

-- Create a ComboBox
local comboBox = MyGUI.createComboBox("Kenshi_ComboBox", 0.05, 0.75, 0.40, 0.08, "MyComboBox", window)

-- Generic Widget Creation
local customWidget = MyGUI.createWidget(typeName, skinName, x, y, width, height, name, parentOrLayer)
```

### Additional Constructors
- `MyGUI.createProgressBar(skin, x, y, w, h, name, parent)`
- `MyGUI.createScrollView(skin, x, y, w, h, name, parent)`
- `MyGUI.createTabControl(skin, x, y, w, h, name, parent)`
- `MyGUI.createImageBox(skin, x, y, w, h, name, parent)`

### Layout Loading & Unloading
```lua
-- Load a layout file (.layout)
local widgetTable = MyGUI.loadLayout("MyCustomLayout.layout", parentWidget)

-- Unload a layout widget table
MyGUI.unloadLayout(widgetTable)
```

### Global Utilities & Enums
- `MyGUI.resetKeyFocus()`: Clears active keyboard focus.
- `MyGUI.loadResource(file)`: Loads a MyGUI XML resource file.
- `MyGUI.isResourceExist(name)`: Checks if a resource exists.

#### `MyGUI.Align` Constants
`Left`, `Right`, `Top`, `Bottom`, `HCenter`, `VCenter`, `Center`, `HStretch`, `VStretch`, `Stretch`, `Default`.

#### `MyGUI.WidgetStyle` Constants
`Child`, `Popup`, `Overlapped`.

---

## 3. Common Widget Methods (`Widget`)

These methods are available on all MyGUI widget objects.

### Visibility & State
- `widget:setVisible(bool)`: Set visibility.
- `widget:getVisible()`: Returns boolean visibility.
- `widget:setEnabled(bool)`: Enable or disable widget.
- `widget:getEnabled()`: Returns boolean enabled state.

### Text & Captions
- `widget:setCaption(text)`: Set text or button label.
- `widget:getCaption()`: Returns text caption string.

### Hierarchy & Queries
- `widget:getParent()`: Returns parent widget.
- `widget:findWidget(name)`: Finds child widget by name.
- `widget:getClientWidget()`: Returns client widget (for Windows).
- `widget:getType()`: Returns widget type name string.
- `widget:getName()`: Returns widget internal name string.
- `widget:destroy()`: Instantly destroys the widget.

### Position & Dimensions
- `widget:setPosition(x, y)` / `widget:getPosition()`
- `widget:setSize(w, h)` / `widget:getSize()`
- `widget:setCoord(x, y, w, h)` / `widget:getCoord()`
- `widget:setRealCoord(fx, fy, fw, fh)`: Set relative coordinates (`0.0`-`1.0`).
- `widget:setRealPosition(fx, fy)` / `widget:setRealSize(fw, fh)`

### Properties & Focus
- `widget:setProperty(keyString, valueString)`: Sets MyGUI XML property.
- `widget:setNeedKeyFocus(bool)` / `widget:setNeedMouseFocus(bool)`
- `widget:setUserString(key, value)` / `widget:getUserString(key)`

---

## 4. Specialized Widget Methods

### Window
- `window:setMovable(bool)` / `window:getMovable()`
- `window:setVisibleSmooth(bool)`: Fades window in/out smoothly.
- `window:destroySmooth()`: Fades out and destroys window.
- `window:setMinSize(w, h)` / `window:setMaxSize(w, h)`

### Button
- `button:setStateSelected(bool)` / `button:getStateSelected()`

### TextBox / Labels
- `label:setFontName(fontName)` / `label:getFontName()`
- `label:setFontHeight(height)` / `label:getFontHeight()`
- `label:setTextAlign(alignEnum)` / `label:getTextAlign()`
- `label:setTextColour(colourTableOrString)` (e.g. `"1 0 0"` or `{r=1, g=0, b=0}`)

### EditBox
- `editBox:setEditReadOnly(bool)` / `editBox:getEditReadOnly()`
- `editBox:setEditMultiLine(bool)` / `editBox:getEditMultiLine()`
- `editBox:setEditPassword(bool)` / `editBox:setPasswordChar(char)`
- `editBox:setOnlyText(text)` / `editBox:getOnlyText()`

### ListBox / ComboBox / TabControl (Item Containers)
- `container:addItem(text)`
- `container:insertItemAt(index, text)`
- `container:removeItemAt(index)`
- `container:removeAllItems()`
- `container:getItemCount()`
- `container:getItemNameAt(index)` / `container:setItemNameAt(index, text)`
- `container:getIndexSelected()` / `container:setIndexSelected(index)`
- `container:clearIndexSelected()`

---

## 5. Event Handling (`registerCallback`)

Callbacks are attached to widgets using `widget:registerCallback(eventType, callbackFunction)`.

```lua
myButton:registerCallback("click", function(widget)
    print("Button clicked: " .. widget:getName())
end)
```

### Supported Event Types & Arguments

| Event Name | Aliases | Callback Signature | Description |
| :--- | :--- | :--- | :--- |
| `"click"` | `"MouseButtonClick"` | `func(widget)` | Triggered on mouse click |
| `"change"` | `"EditTextChange"` | `func(widget)` | Triggered when EditBox text changes |
| `"windowButtonPressed"` | `"WindowButtonPressed"` | `func(window, buttonName)` | Titlebar buttons (e.g. `"close"`) |
| `"mouseDown"` | `"MouseButtonPressed"` | `func(widget, left, top, buttonId)` | Mouse button pressed down |
| `"mouseUp"` | `"MouseButtonReleased"` | `func(widget, left, top, buttonId)` | Mouse button released |
| `"mouseOver"` | `"MouseSetFocus"` | `func(widget, oldWidget)` | Cursor enters widget |
| `"mouseOut"` | `"MouseLostFocus"` | `func(widget, newWidget)` | Cursor leaves widget |
| `"mouseMove"` | `"MouseMove"` | `func(widget, left, top)` | Mouse moved over widget |
| `"mouseWheel"` | `"MouseWheel"` | `func(widget, rel)` | Mouse wheel scrolled |
| `"keyDown"` | `"KeyButtonPressed"` | `func(widget, keyCode, charCode)` | Keyboard key pressed |
| `"keyUp"` | `"KeyButtonReleased"` | `func(widget, keyCode)` | Keyboard key released |
| `"comboAccept"` | `"ComboAccept"` | `func(comboBox, index)` | Item selected in ComboBox |
| `"comboChangePosition"` | `"ComboChangePosition"` | `func(comboBox, index)` | Selection changed in ComboBox |
| `"listSelectAccept"` | `"ListSelectAccept"` | `func(listBox, index)` | Item accepted in ListBox |
| `"listChangePosition"` | `"ListChangePosition"` | `func(listBox, index)` | Selection changed in ListBox |

---

## 6. Complete Example Script

```lua
-- Create Main Window
local window = MyGUI.createWindow("Kenshi_WindowCX", 0.30, 0.20, 0.35, 0.40, "ExampleWindow", "Window")
window:setCaption("Sample Interface")
window:setMovable(true)

-- Add Label
local label = MyGUI.createTextBox("Kenshi_TextboxPaintedText", 0.05, 0.10, 0.90, 0.08, "StatusLabel", window)
label:setCaption("Enter text and click Submit")

-- Add Input
local input = MyGUI.createEditBox("Kenshi_EditBox", 0.05, 0.22, 0.90, 0.10, "InputBox", window)
input:setCaption("Default text...")

-- Add Button
local submitBtn = MyGUI.createButton("Kenshi_Button1", 0.05, 0.40, 0.40, 0.12, "SubmitBtn", window)
submitBtn:setCaption("Submit")

-- Submit Click Callback
submitBtn:registerCallback("click", function(widget)
    local userText = input:getCaption()
    label:setCaption("Submitted: " .. userText)
end)

-- Window Close Button Callback
window:registerCallback("windowButtonPressed", function(win, btnName)
    if btnName == "close" then
        win:setVisible(false)
    end
end)
```
