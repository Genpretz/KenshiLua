# MyGUI Lua API Reference

## Overview

The **MyGUI** subsystem in KenshiLua provides a comprehensive set of UI bindings for creating and managing game user interfaces. It offers:
- **Global Factory & Utility Functions**: Convenient `MyGUI.createButton(...)`, `MyGUI.createWindow(...)`, `MyGUI.loadLayout(...)`, etc.
- **Pixel & Relative Coordinates**: Precise integer pixel positioning or resolution-independent relative positioning (`0.0` to `1.0`).
- **Rich Object-Oriented Widgets**: Full support for buttons, textboxes, editboxes, windows, scrollbars, listboxes, comboboxes, tab controls, menus, and canvases.
- **Metatable Inheritance**: Child widgets inherit all base properties and methods from `MyGUI.Widget` (e.g. `setCaption`, `setPosition`, `setVisible`, `destroy`, `registerCallback`).
- **Lifecycle Safety**: All widgets instantiated from Lua are tracked automatically and cleaned up upon script reload or shutdown.
- **Event Callbacks**: Unified event registration via `widget:registerCallback(eventName, handler)` supporting clicks, text edits, drag/scroll, keys, and focus changes.

For KenshiLib game engine class bindings, see the [KenshiLua Bindings Reference](BindingsReference.md).

---

## Table of Contents

- [Global API (`MyGUI.*`)](#global-api-mygui)
- [Core Types](#core-types)
  - [`IntPoint`](#intpoint)
  - [`IntSize`](#intsize)
  - [`IntCoord`](#intcoord)
  - [`IntRect`](#intrect)
  - [`FloatPoint`](#floatpoint)
  - [`FloatSize`](#floatsize)
  - [`FloatCoord`](#floatcoord)
  - [`FloatRect`](#floatrect)
  - [`Colour`](#colour)
- [Base Widget Class](#base-widget-class)
  - [`Widget`](#widget)
- [Widget Classes](#widget-classes)
  - [`Button`](#button)
  - [`Canvas`](#canvas)
  - [`ComboBox`](#combobox)
  - [`DDContainer`](#ddcontainer)
  - [`EditBox`](#editbox)
  - [`ImageBox`](#imagebox)
  - [`ItemBox`](#itembox)
  - [`ListBox`](#listbox)
  - [`MenuBar`](#menubar)
  - [`MenuControl`](#menucontrol)
  - [`MenuItem`](#menuitem)
  - [`MultiListBox`](#multilistbox)
  - [`PopupMenu`](#popupmenu)
  - [`ProgressBar`](#progressbar)
  - [`ScrollBar`](#scrollbar)
  - [`ScrollView`](#scrollview)
  - [`TabControl`](#tabcontrol)
  - [`TabItem`](#tabitem)
  - [`TextBox`](#textbox)
  - [`Window`](#window)
- [Managers (Singletons)](#managers-singletons)
  - [`ClipboardManager`](#clipboardmanager)
  - [`Gui`](#gui)
  - [`InputManager`](#inputmanager)
  - [`LayoutManager`](#layoutmanager)
  - [`PointerManager`](#pointermanager)
  - [`RenderManager`](#rendermanager)
  - [`SkinManager`](#skinmanager)
- [Event Callbacks Reference](#event-callbacks-reference)
- [Global Enums](#global-enums)

---

## Global API (`MyGUI.*`)

These helper functions are available directly on the global `MyGUI` table.

### Functions
| Function | Parameters | Return Type | Description / Example |
|---|---|---|---|
| `createButton` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `Button` | `MyGUI.createButton(skin, left, top, width, height, name, parentOrLayer)` |
| `createButtonReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `Button` | `MyGUI.createButtonReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createWindow` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, layer: string` | `Window` | `MyGUI.createWindow(skin, left, top, width, height, name, layer)` |
| `createWindowReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, layer: string` | `Window` | `MyGUI.createWindowReal(skin, left, top, width, height, name, layer)` |
| `createTextBox` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `TextBox` | `MyGUI.createTextBox(skin, left, top, width, height, name, parentOrLayer)` |
| `createTextBoxReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `TextBox` | `MyGUI.createTextBoxReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createEditBox` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `EditBox` | `MyGUI.createEditBox(skin, left, top, width, height, name, parentOrLayer)` |
| `createEditBoxReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `EditBox` | `MyGUI.createEditBoxReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createListBox` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `ListBox` | `MyGUI.createListBox(skin, left, top, width, height, name, parentOrLayer)` |
| `createListBoxReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `ListBox` | `MyGUI.createListBoxReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createComboBox` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `ComboBox` | `MyGUI.createComboBox(skin, left, top, width, height, name, parentOrLayer)` |
| `createComboBoxReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `ComboBox` | `MyGUI.createComboBoxReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createTabControl` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `TabControl` | `MyGUI.createTabControl(skin, left, top, width, height, name, parentOrLayer)` |
| `createTabControlReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `TabControl` | `MyGUI.createTabControlReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createMultiListBox` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `MultiListBox` | `MyGUI.createMultiListBox(skin, left, top, width, height, name, parentOrLayer)` |
| `createMultiListBoxReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `MultiListBox` | `MyGUI.createMultiListBoxReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createScrollBar` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `ScrollBar` | `MyGUI.createScrollBar(skin, left, top, width, height, name, parentOrLayer)` |
| `createScrollBarReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `ScrollBar` | `MyGUI.createScrollBarReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createScrollView` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `ScrollView` | `MyGUI.createScrollView(skin, left, top, width, height, name, parentOrLayer)` |
| `createScrollViewReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `ScrollView` | `MyGUI.createScrollViewReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createProgressBar` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `ProgressBar` | `MyGUI.createProgressBar(skin, left, top, width, height, name, parentOrLayer)` |
| `createProgressBarReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `ProgressBar` | `MyGUI.createProgressBarReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createImageBox` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `ImageBox` | `MyGUI.createImageBox(skin, left, top, width, height, name, parentOrLayer)` |
| `createImageBoxReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `ImageBox` | `MyGUI.createImageBoxReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createItemBox` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `ItemBox` | `MyGUI.createItemBox(skin, left, top, width, height, name, parentOrLayer)` |
| `createItemBoxReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `ItemBox` | `MyGUI.createItemBoxReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createDDContainer` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `DDContainer` | `MyGUI.createDDContainer(skin, left, top, width, height, name, parentOrLayer)` |
| `createDDContainerReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `DDContainer` | `MyGUI.createDDContainerReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createCanvas` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `Canvas` | `MyGUI.createCanvas(skin, left, top, width, height, name, parentOrLayer)` |
| `createCanvasReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `Canvas` | `MyGUI.createCanvasReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createMenuBar` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `MenuBar` | `MyGUI.createMenuBar(skin, left, top, width, height, name, parentOrLayer)` |
| `createMenuBarReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `MenuBar` | `MyGUI.createMenuBarReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createPopupMenu` | `skin: string, left: integer, top: integer, width: integer, height: integer, name: string, parentOrLayer: string\|Widget` | `PopupMenu` | `MyGUI.createPopupMenu(skin, left, top, width, height, name, parentOrLayer)` |
| `createPopupMenuReal` | `skin: string, left: number, top: number, width: number, height: number, name: string, parentOrLayer: string\|Widget` | `PopupMenu` | `MyGUI.createPopupMenuReal(skin, left, top, width, height, name, parentOrLayer)` |
| `createWidget` | `type: string, skin: string, left: integer, top: integer, width: integer, height: integer, align: Align, layer: string, name: string` | `Widget` | `MyGUI.createWidget(type, skin, left, top, width, height, align, layer, name)` |
| `createWidgetReal` | `type: string, skin: string, left: number, top: number, width: number, height: number, align: Align, layer: string, name: string` | `Widget` | `MyGUI.createWidgetReal(type, skin, left, top, width, height, align, layer, name)` |
| `findWidget` | `name: string` | `Widget` | `MyGUI.findWidget(name)` |
| `findWidgetT` | `name: string` | `Widget` | `MyGUI.findWidgetT(name)` |
| `destroyWidget` | `widget: Widget` | `void` | `MyGUI.destroyWidget(widget)` |
| `destroyWidgets` | `prefix: string` | `void` | `MyGUI.destroyWidgets(prefix)` |
| `hidePointer` | `` | `void` | `MyGUI.hidePointer()` |
| `showPointer` | `` | `void` | `MyGUI.showPointer()` |
| `isPointerVisible` | `` | `boolean` | `MyGUI.isPointerVisible()` |
| `setPointer` | `pointerName: string` | `void` | `MyGUI.setPointer(pointerName)` |
| `clearPointer` | `` | `void` | `MyGUI.clearPointer()` |
| `getMousePosition` | `` | `integer, integer` | `MyGUI.getMousePosition()` |
| `loadLayout` | `filename: string, prefix: string` | `table` | `MyGUI.loadLayout(filename, prefix)` |
| `unloadLayout` | `layoutWidgets: table` | `void` | `MyGUI.unloadLayout(layoutWidgets)` |
| `getViewSize` | `` | `integer, integer` | `MyGUI.getViewSize()` |
| `getViewWidth` | `` | `integer` | `MyGUI.getViewWidth()` |
| `getViewHeight` | `` | `integer` | `MyGUI.getViewHeight()` |
| `setClipboardText` | `text: string, type: string` | `void` | `MyGUI.setClipboardText(text, type)` |
| `getClipboardText` | `type: string` | `string` | `MyGUI.getClipboardText(type)` |
| `isSkinExist` | `skinName: string` | `boolean` | `MyGUI.isSkinExist(skinName)` |
| `getDefaultSkin` | `widgetType: string` | `string` | `MyGUI.getDefaultSkin(widgetType)` |
| `setDefaultSkin` | `widgetType: string, skinName: string` | `void` | `MyGUI.setDefaultSkin(widgetType, skinName)` |
| `upLayerItem` | `widget: Widget` | `void` | `MyGUI.upLayerItem(widget)` |
| `bringToFront` | `widget: Widget` | `void` | `MyGUI.bringToFront(widget)` |

## Core Types

Value structs used throughout MyGUI for coordinates, dimensions, bounds, and colors.

### IntPoint
**Metatable:** `KenshiLua.MyGUI.IntPoint`  
**Header:** `src/Bindings/MyGUI/TypesBinding.h`

#### Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `left / x` | `integer` | RW | `pt.left = 10 or pt.x = 10` |
| `top / y` | `integer` | RW | `pt.top = 20 or pt.y = 20` |

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `new` | `left: integer, top: integer` | `IntPoint` | `MyGUI.IntPoint.new(left, top)` |

### IntSize
**Metatable:** `KenshiLua.MyGUI.IntSize`  
**Header:** `src/Bindings/MyGUI/TypesBinding.h`

#### Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `width / w` | `integer` | RW | `sz.width = 100 or sz.w = 100` |
| `height / h` | `integer` | RW | `sz.height = 50 or sz.h = 50` |

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `new` | `w: integer, h: integer` | `IntSize` | `MyGUI.IntSize.new(w, h)` |

### IntCoord
**Metatable:** `KenshiLua.MyGUI.IntCoord`  
**Header:** `src/Bindings/MyGUI/TypesBinding.h`

#### Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `left / x` | `integer` | RW | `coord.left = 10 or coord.x = 10` |
| `top / y` | `integer` | RW | `coord.top = 20 or coord.y = 20` |
| `width / w` | `integer` | RW | `coord.width = 100 or coord.w = 100` |
| `height / h` | `integer` | RW | `coord.height = 50 or coord.h = 50` |
| `point` | `IntPoint` | R | `local pt = coord.point` |
| `size` | `IntSize` | R | `local sz = coord.size` |

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `new` | `left: integer, top: integer, width: integer, height: integer` | `IntCoord` | `MyGUI.IntCoord.new(left, top, width, height)` |

### IntRect
**Metatable:** `KenshiLua.MyGUI.IntRect`  
**Header:** `src/Bindings/MyGUI/TypesBinding.h`

#### Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `left` | `integer` | RW | `rect.left = 0` |
| `top` | `integer` | RW | `rect.top = 0` |
| `right` | `integer` | RW | `rect.right = 100` |
| `bottom` | `integer` | RW | `rect.bottom = 100` |
| `width` | `integer` | R | `local w = rect.width` |
| `height` | `integer` | R | `local h = rect.height` |

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `new` | `left: integer, top: integer, right: integer, bottom: integer` | `IntRect` | `MyGUI.IntRect.new(left, top, right, bottom)` |

### FloatPoint
**Metatable:** `KenshiLua.MyGUI.FloatPoint`  
**Header:** `src/Bindings/MyGUI/TypesBinding.h`

#### Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `left / x` | `number` | RW | `pt.left = 0.1 or pt.x = 0.1` |
| `top / y` | `number` | RW | `pt.top = 0.2 or pt.y = 0.2` |

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `new` | `left: number, top: number` | `FloatPoint` | `MyGUI.FloatPoint.new(left, top)` |

### FloatSize
**Metatable:** `KenshiLua.MyGUI.FloatSize`  
**Header:** `src/Bindings/MyGUI/TypesBinding.h`

#### Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `width / w` | `number` | RW | `sz.width = 0.5 or sz.w = 0.5` |
| `height / h` | `number` | RW | `sz.height = 0.3 or sz.h = 0.3` |

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `new` | `w: number, h: number` | `FloatSize` | `MyGUI.FloatSize.new(w, h)` |

### FloatCoord
**Metatable:** `KenshiLua.MyGUI.FloatCoord`  
**Header:** `src/Bindings/MyGUI/TypesBinding.h`

#### Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `left / x` | `number` | RW | `coord.left = 0.1 or coord.x = 0.1` |
| `top / y` | `number` | RW | `coord.top = 0.1 or coord.y = 0.1` |
| `width / w` | `number` | RW | `coord.width = 0.8 or coord.w = 0.8` |
| `height / h` | `number` | RW | `coord.height = 0.8 or coord.h = 0.8` |

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `new` | `left: number, top: number, width: number, height: number` | `FloatCoord` | `MyGUI.FloatCoord.new(left, top, width, height)` |

### FloatRect
**Metatable:** `KenshiLua.MyGUI.FloatRect`  
**Header:** `src/Bindings/MyGUI/TypesBinding.h`

#### Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `left` | `number` | RW | `rect.left = 0.0` |
| `top` | `number` | RW | `rect.top = 0.0` |
| `right` | `number` | RW | `rect.right = 1.0` |
| `bottom` | `number` | RW | `rect.bottom = 1.0` |
| `width` | `number` | R | `local w = rect.width` |
| `height` | `number` | R | `local h = rect.height` |

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `new` | `left: number, top: number, right: number, bottom: number` | `FloatRect` | `MyGUI.FloatRect.new(left, top, right, bottom)` |

### Colour
**Metatable:** `KenshiLua.MyGUI.Colour`  
**Header:** `src/Bindings/MyGUI/TypesBinding.h`

#### Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `red / r` | `number` | RW | `col.red = 1.0 or col.r = 1.0` |
| `green / g` | `number` | RW | `col.green = 0.5 or col.g = 0.5` |
| `blue / b` | `number` | RW | `col.blue = 0.0 or col.b = 0.0` |
| `alpha / a` | `number` | RW | `col.alpha = 1.0 or col.a = 1.0` |

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `new` | `r: number, g: number, b: number, a: number` | `Colour` | `MyGUI.Colour.new(r, g, b, a)` |
| `parse` | `str: string` | `Colour` | `MyGUI.Colour.parse(str)` |

## Base Widget Class

### Widget
**Metatable:** `KenshiLua.MyGUI.Widget`  
**Header:** `src/Bindings/MyGUI/WidgetBinding.h`

> [!NOTE]
> All widget classes (Button, EditBox, Window, etc.) inherit all properties and methods from `MyGUI.Widget`.

#### Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `caption` | `string` | RW | `w.caption = 'Title'` |
| `visible` | `boolean` | RW | `w.visible = true` |
| `enabled` | `boolean` | RW | `w.enabled = false` |
| `alpha` | `number` | RW | `w.alpha = 0.85` |
| `align` | `Align` | RW | `w.align = MyGUI.Align.Center` |
| `position` | `IntPoint` | RW | `w.position = MyGUI.IntPoint.new(100, 50)` |
| `size` | `IntSize` | RW | `w.size = MyGUI.IntSize.new(200, 100)` |
| `coord` | `IntCoord` | RW | `w.coord = MyGUI.IntCoord.new(10, 10, 300, 200)` |
| `pointer` | `string` | RW | `w.pointer = 'hand'` |
| `depth` | `integer` | RW | `w.depth = 10` |
| `needKeyFocus` | `boolean` | RW | `w.needKeyFocus = true` |
| `needMouseFocus` | `boolean` | RW | `w.needMouseFocus = true` |
| `inheritsAlpha` | `boolean` | RW | `w.inheritsAlpha = true` |
| `inheritsPick` | `boolean` | RW | `w.inheritsPick = false` |
| `maskPick` | `boolean` | RW | `w.maskPick = false` |
| `widgetStyle` | `WidgetStyle` | RW | `w.widgetStyle = MyGUI.WidgetStyle.Popup` |
| `name` | `string` | R | `local name = w.name` |
| `type` | `string` | R | `local typeName = w.type` |
| `layerName` | `string` | R | `local layer = w.layerName` |
| `parent` | `Widget` | R | `local parent = w.parent` |
| `rootWidget` | `Widget` | R | `local root = w.rootWidget` |
| `childCount` | `integer` | R | `local count = w.childCount` |

#### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `setPosition` | `x: integer, y: integer` | `void` | `w:setPosition(x, y)` |
| `getPosition` | `` | `integer, integer` | `w:getPosition()` |
| `setSize` | `width: integer, height: integer` | `void` | `w:setSize(width, height)` |
| `getSize` | `` | `integer, integer` | `w:getSize()` |
| `setCoord` | `left: integer, top: integer, width: integer, height: integer` | `void` | `w:setCoord(left, top, width, height)` |
| `getCoord` | `` | `integer, integer, integer, integer` | `w:getCoord()` |
| `setRealPosition` | `left: number, top: number` | `void` | `w:setRealPosition(left, top)` |
| `getRealPosition` | `` | `integer, integer` | `w:getRealPosition()` |
| `setRealSize` | `width: number, height: number` | `void` | `w:setRealSize(width, height)` |
| `getRealSize` | `` | `integer, integer` | `w:getRealSize()` |
| `setRealCoord` | `left: number, top: number, width: number, height: number` | `void` | `w:setRealCoord(left, top, width, height)` |
| `getRealCoord` | `` | `integer, integer, integer, integer` | `w:getRealCoord()` |
| `setCoordReal` | `left: number, top: number, width: number, height: number` | `void` | `w:setCoordReal(left, top, width, height)` |
| `getCoordReal` | `` | `integer, integer, integer, integer` | `w:getCoordReal()` |
| `setVisible` | `v: boolean` | `void` | `w:setVisible(v)` |
| `getVisible` | `` | `boolean` | `w:getVisible()` |
| `getInheritedVisible` | `` | `boolean` | `w:getInheritedVisible()` |
| `setAlign` | `a: integer` | `void` | `w:setAlign(a)` |
| `getAlign` | `` | `integer` | `w:getAlign()` |
| `setAlpha` | `alpha: number` | `void` | `w:setAlpha(alpha)` |
| `getAlpha` | `` | `number` | `w:getAlpha()` |
| `setInheritsAlpha` | `val: boolean` | `void` | `w:setInheritsAlpha(val)` |
| `getInheritsAlpha` | `` | `boolean` | `w:getInheritsAlpha()` |
| `setColour` | `col: Colour` | `void` | `w:setColour(col)` |
| `setDepth` | `depth: integer` | `void` | `w:setDepth(depth)` |
| `getDepth` | `` | `integer` | `w:getDepth()` |
| `setEnabled` | `e: boolean` | `void` | `w:setEnabled(e)` |
| `getEnabled` | `` | `boolean` | `w:getEnabled()` |
| `getInheritedEnabled` | `` | `boolean` | `w:getInheritedEnabled()` |
| `setCaption` | `text: string` | `void` | `w:setCaption(text)` |
| `getCaption` | `` | `string` | `w:getCaption()` |
| `setWidgetStyle` | `style: integer, layer: string` | `void` | `w:setWidgetStyle(style, layer)` |
| `getWidgetStyle` | `` | `integer` | `w:getWidgetStyle()` |
| `setNeedKeyFocus` | `val: boolean` | `void` | `w:setNeedKeyFocus(val)` |
| `getNeedKeyFocus` | `` | `boolean` | `w:getNeedKeyFocus()` |
| `setNeedMouseFocus` | `val: boolean` | `void` | `w:setNeedMouseFocus(val)` |
| `getNeedMouseFocus` | `` | `boolean` | `w:getNeedMouseFocus()` |
| `setInheritsPick` | `val: boolean` | `void` | `w:setInheritsPick(val)` |
| `getInheritsPick` | `` | `boolean` | `w:getInheritsPick()` |
| `setMaskPick` | `filename: string` | `void` | `w:setMaskPick(filename)` |
| `setPointer` | `pointer: string` | `void` | `w:setPointer(pointer)` |
| `getPointer` | `` | `string` | `w:getPointer()` |
| `setUserString` | `key: string, val: string` | `void` | `w:setUserString(key, val)` |
| `getUserString` | `key: string` | `string` | `w:getUserString(key)` |
| `isUserString` | `key: string` | `boolean` | `w:isUserString(key)` |
| `clearUserString` | `key: string` | `void` | `w:clearUserString(key)` |
| `createWidget` | `type: string, skin: string, left: integer, top: integer, width: integer, height: integer, align: Align, name: string` | `Widget` | `w:createWidget(type, skin, left, top, width, height, align, name)` |
| `createWidgetReal` | `type: string, skin: string, left: number, top: number, width: number, height: number, align: Align, name: string` | `Widget` | `w:createWidgetReal(type, skin, left, top, width, height, align, name)` |
| `getParent` | `` | `integer, integer` | `w:getParent()` |
| `getRootWidget` | `` | `Widget` | `w:getRootWidget()` |
| `isRootWidget` | `` | `Widget` | `w:isRootWidget()` |
| `getChildCount` | `` | `integer` | `w:getChildCount()` |
| `getChildAt` | `idx: integer` | `Widget` | `w:getChildAt(idx)` |
| `findWidget` | `name: string` | `Widget` | `w:findWidget(name)` |
| `getClientWidget` | `` | `Widget` | `w:getClientWidget()` |
| `getClientCoord` | `` | `integer, integer, integer, integer` | `w:getClientCoord()` |
| `getType` | `` | `string` | `w:getType()` |
| `getName` | `` | `string` | `w:getName()` |
| `getLayerName` | `` | `string` | `w:getLayerName()` |
| `getAbsoluteCoord` | `` | `integer, integer, integer, integer` | `w:getAbsoluteCoord()` |
| `getAbsolutePosition` | `` | `integer, integer` | `w:getAbsolutePosition()` |
| `getAbsoluteRect` | `` | `integer, integer, integer, integer` | `w:getAbsoluteRect()` |
| `changeWidgetSkin` | `skin: string` | `void` | `w:changeWidgetSkin(skin)` |
| `setProperty` | `key: string, value: string` | `void` | `w:setProperty(key, value)` |
| `destroy` | `` | `void` | `w:destroy()` |
| `registerCallback` | `eventName: string, handler: function` | `void` | `w:registerCallback(eventName, handler)` |
| `upLayerItem` | `` | `void` | `w:upLayerItem()` |
| `bringToFront` | `` | `void` | `w:bringToFront()` |

## Widget Classes

### Button
**Metatable:** `KenshiLua.MyGUI.Button`  
**Header:** `src/Bindings/MyGUI/ButtonBinding.h`  
**Parent Class:** [`MyGUI.Widget`](#widget) *(inherits all methods and properties)*

#### Specific Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `stateSelected` | `boolean` | RW | `btn.stateSelected = true` |
| `selected` | `boolean` | RW | `btn.selected = true` |

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `setStateSelected` | `s: boolean` | `void` | `obj:setStateSelected(s)` |
| `getStateSelected` | `` | `boolean` | `obj:getStateSelected()` |
| `setModeImage` | `m: boolean` | `void` | `obj:setModeImage(m)` |
| `getModeImage` | `` | `boolean` | `obj:getModeImage()` |
| `setImageResource` | `name: string` | `void` | `obj:setImageResource(name)` |

### Canvas
**Metatable:** `KenshiLua.MyGUI.Canvas`  
**Header:** `src/Bindings/MyGUI/CanvasBinding.h`  
**Parent Class:** [`MyGUI.Widget`](#widget) *(inherits all methods and properties)*

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `createTexture` | `w: integer, h: integer, mode: integer` | `void` | `obj:createTexture(w, h, mode)` |
| `destroyTexture` | `` | `void` | `obj:destroyTexture()` |
| `updateTexture` | `` | `void` | `obj:updateTexture()` |
| `isTextureCreated` | `` | `boolean` | `obj:isTextureCreated()` |
| `isTextureManaged` | `` | `boolean` | `obj:isTextureManaged()` |
| `setTextureManaged` | `managed: boolean` | `void` | `obj:setTextureManaged(managed)` |
| `getTextureRealWidth` | `` | `integer` | `obj:getTextureRealWidth()` |
| `getTextureRealHeight` | `` | `integer` | `obj:getTextureRealHeight()` |
| `getTextureRealSize` | `` | `integer, integer` | `obj:getTextureRealSize()` |
| `getTextureSrcWidth` | `` | `integer` | `obj:getTextureSrcWidth()` |
| `getTextureSrcHeight` | `` | `integer` | `obj:getTextureSrcHeight()` |
| `getTextureSrcSize` | `` | `integer, integer` | `obj:getTextureSrcSize()` |
| `isTextureSrcSize` | `` | `boolean` | `obj:isTextureSrcSize()` |
| `getTextureName` | `` | `string` | `obj:getTextureName()` |
| `getTextureFormat` | `` | `integer` | `obj:getTextureFormat()` |
| `setResizeMode` | `mode: integer` | `void` | `obj:setResizeMode(mode)` |
| `getResizeMode` | `` | `integer` | `obj:getResizeMode()` |

### ComboBox
**Metatable:** `KenshiLua.MyGUI.ComboBox`  
**Header:** `src/Bindings/MyGUI/ComboBoxBinding.h`  
**Parent Class:** [`MyGUI.EditBox`](#editbox) *(inherits all methods and properties)*

#### Specific Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `itemCount` | `integer` | R | `local count = cb.itemCount` |
| `indexSelected` | `integer` | RW | `cb.indexSelected = 0` |
| `comboModeDrop` | `boolean` | RW | `cb.comboModeDrop = true` |

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `getItemCount` | `` | `integer` | `obj:getItemCount()` |
| `insertItemAt` | `idx: integer, name: string` | `void` | `obj:insertItemAt(idx, name)` |
| `addItem` | `name: string` | `void` | `obj:addItem(name)` |
| `removeItemAt` | `idx: integer` | `void` | `obj:removeItemAt(idx)` |
| `removeAllItems` | `` | `void` | `obj:removeAllItems()` |
| `setItemNameAt` | `idx: integer, name: string` | `void` | `obj:setItemNameAt(idx, name)` |
| `getItemNameAt` | `idx: integer` | `string` | `obj:getItemNameAt(idx)` |
| `getIndexSelected` | `` | `integer` | `obj:getIndexSelected()` |
| `setIndexSelected` | `idx: integer` | `void` | `obj:setIndexSelected(idx)` |
| `clearIndexSelected` | `` | `void` | `obj:clearIndexSelected()` |
| `findItemIndexWith` | `name: string` | `integer` | `obj:findItemIndexWith(name)` |
| `beginToItemAt` | `idx: integer` | `void` | `obj:beginToItemAt(idx)` |
| `beginToItemFirst` | `` | `void` | `obj:beginToItemFirst()` |
| `beginToItemLast` | `` | `void` | `obj:beginToItemLast()` |
| `beginToItemSelected` | `` | `void` | `obj:beginToItemSelected()` |
| `setComboModeDrop` | `drop: boolean` | `void` | `obj:setComboModeDrop(drop)` |
| `getComboModeDrop` | `` | `boolean` | `obj:getComboModeDrop()` |
| `setSmoothShow` | `smooth: boolean` | `void` | `obj:setSmoothShow(smooth)` |
| `getSmoothShow` | `` | `boolean` | `obj:getSmoothShow()` |
| `setMaxListLength` | `len: integer` | `void` | `obj:setMaxListLength(len)` |
| `getMaxListLength` | `` | `integer` | `obj:getMaxListLength()` |
| `setFlowDirection` | `dir: integer` | `void` | `obj:setFlowDirection(dir)` |
| `getFlowDirection` | `` | `integer` | `obj:getFlowDirection()` |

### DDContainer
**Metatable:** `KenshiLua.MyGUI.DDContainer`  
**Header:** `src/Bindings/MyGUI/DDContainerBinding.h`  
**Parent Class:** [`MyGUI.Widget`](#widget) *(inherits all methods and properties)*

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `setNeedDragDrop` | `nd: boolean` | `void` | `obj:setNeedDragDrop(nd)` |
| `getNeedDragDrop` | `` | `boolean` | `obj:getNeedDragDrop()` |
| `resetDrag` | `` | `void` | `obj:resetDrag()` |

### EditBox
**Metatable:** `KenshiLua.MyGUI.EditBox`  
**Header:** `src/Bindings/MyGUI/EditBoxBinding.h`  
**Parent Class:** [`MyGUI.TextBox`](#textbox) *(inherits all methods and properties)*

#### Specific Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `overflowToTheLeft` | `boolean` | RW | `eb.overflowToTheLeft = false` |
| `maxTextLength` | `integer` | RW | `eb.maxTextLength = 128` |
| `readOnly` | `boolean` | RW | `eb.readOnly = true` |
| `multiLine` | `boolean` | RW | `eb.multiLine = true` |
| `password` | `boolean` | RW | `eb.password = false` |
| `wordWrap` | `boolean` | RW | `eb.wordWrap = true` |
| `cursorPosition` | `integer` | RW | `eb.cursorPosition = 0` |

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `getTextSelection` | `` | `string` | `obj:getTextSelection()` |
| `setTextSelection` | `start: integer, end: integer` | `void` | `obj:setTextSelection(start, end)` |
| `deleteTextSelection` | `` | `void` | `obj:deleteTextSelection()` |
| `isTextSelection` | `` | `boolean` | `obj:isTextSelection()` |
| `getTextSelectionStart` | `` | `integer` | `obj:getTextSelectionStart()` |
| `getTextSelectionEnd` | `` | `integer` | `obj:getTextSelectionEnd()` |
| `getTextSelectionLength` | `` | `integer` | `obj:getTextSelectionLength()` |
| `getTextInterval` | `start: integer, count: integer` | `string` | `obj:getTextInterval(start, count)` |
| `setTextCursor` | `pos: integer` | `void` | `obj:setTextCursor(pos)` |
| `getTextCursor` | `` | `integer` | `obj:getTextCursor()` |
| `getTextLength` | `` | `integer` | `obj:getTextLength()` |
| `setOverflowToTheLeft` | `val: boolean` | `void` | `obj:setOverflowToTheLeft(val)` |
| `getOverflowToTheLeft` | `` | `boolean` | `obj:getOverflowToTheLeft()` |
| `setMaxTextLength` | `len: integer` | `void` | `obj:setMaxTextLength(len)` |
| `getMaxTextLength` | `` | `integer` | `obj:getMaxTextLength()` |
| `setEditWordWrap` | `wrap: boolean` | `void` | `obj:setEditWordWrap(wrap)` |
| `getEditWordWrap` | `` | `boolean` | `obj:getEditWordWrap()` |
| `setEditReadOnly` | `ro: boolean` | `void` | `obj:setEditReadOnly(ro)` |
| `getEditReadOnly` | `` | `boolean` | `obj:getEditReadOnly()` |
| `setEditMultiLine` | `ml: boolean` | `void` | `obj:setEditMultiLine(ml)` |
| `getEditMultiLine` | `` | `boolean` | `obj:getEditMultiLine()` |
| `setEditPassword` | `p: boolean` | `void` | `obj:setEditPassword(p)` |
| `getEditPassword` | `` | `boolean` | `obj:getEditPassword()` |
| `setEditStatic` | `s: boolean` | `void` | `obj:setEditStatic(s)` |
| `getEditStatic` | `` | `boolean` | `obj:getEditStatic()` |
| `setPasswordChar` | `str: string` | `void` | `obj:setPasswordChar(str)` |
| `getPasswordChar` | `` | `string` | `obj:getPasswordChar()` |
| `setOnlyText` | `text: string` | `void` | `obj:setOnlyText(text)` |
| `getOnlyText` | `` | `string` | `obj:getOnlyText()` |
| `addText` | `text: string` | `void` | `obj:addText(text)` |
| `insertText` | `text: string, idx: integer` | `void` | `obj:insertText(text, idx)` |
| `eraseText` | `start: integer, count: integer` | `void` | `obj:eraseText(start, count)` |
| `setTextIntervalColour` | `start: integer, count: integer, col: Colour` | `void` | `obj:setTextIntervalColour(start, count, col)` |
| `setTextSelectionColour` | `col: Colour` | `void` | `obj:setTextSelectionColour(col)` |

### ImageBox
**Metatable:** `KenshiLua.MyGUI.ImageBox`  
**Header:** `src/Bindings/MyGUI/ImageBoxBinding.h`  
**Parent Class:** [`MyGUI.Widget`](#widget) *(inherits all methods and properties)*

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `setImageTexture` | `tex: string` | `void` | `obj:setImageTexture(tex)` |
| `setImageCoord` | `l: integer, t: integer, w: integer, h: integer` | `void` | `obj:setImageCoord(l, t, w, h)` |
| `setImageTile` | `w: integer, h: integer` | `void` | `obj:setImageTile(w, h)` |
| `setImageIndex` | `idx: integer` | `void` | `obj:setImageIndex(idx)` |
| `getImageIndex` | `` | `integer` | `obj:getImageIndex()` |
| `getItemCount` | `` | `integer` | `obj:getItemCount()` |
| `setItemSelect` | `idx: integer` | `void` | `obj:setItemSelect(idx)` |
| `getItemSelect` | `` | `integer` | `obj:getItemSelect()` |
| `resetItemSelect` | `` | `void` | `obj:resetItemSelect()` |
| `setItemResource` | `name: string` | `boolean` | `obj:setItemResource(name)` |
| `setImageResource` | `name: string` | `boolean` | `obj:setImageResource(name)` |

### ItemBox
**Metatable:** `KenshiLua.MyGUI.ItemBox`  
**Header:** `src/Bindings/MyGUI/ItemBoxBinding.h`  
**Parent Class:** [`MyGUI.DDContainer`](#ddcontainer) *(inherits all methods and properties)*

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `getItemCount` | `` | `integer` | `obj:getItemCount()` |
| `insertItemAt` | `idx: integer` | `void` | `obj:insertItemAt(idx)` |
| `addItem` | `` | `void` | `obj:addItem()` |
| `removeItemAt` | `idx: integer` | `void` | `obj:removeItemAt(idx)` |
| `removeAllItems` | `` | `void` | `obj:removeAllItems()` |
| `getIndexSelected` | `` | `integer` | `obj:getIndexSelected()` |
| `setIndexSelected` | `idx: integer` | `void` | `obj:setIndexSelected(idx)` |
| `clearIndexSelected` | `` | `void` | `obj:clearIndexSelected()` |
| `redrawItemAt` | `idx: integer` | `void` | `obj:redrawItemAt(idx)` |
| `redrawAllItems` | `` | `void` | `obj:redrawAllItems()` |
| `resetDrag` | `` | `void` | `obj:resetDrag()` |
| `getWidgetDrag` | `` | `Widget` | `obj:getWidgetDrag()` |
| `getWidgetByIndex` | `idx: integer` | `Widget` | `obj:getWidgetByIndex(idx)` |
| `getIndexByWidget` | `` | `integer` | `obj:getIndexByWidget()` |

### ListBox
**Metatable:** `KenshiLua.MyGUI.ListBox`  
**Header:** `src/Bindings/MyGUI/ListBoxBinding.h`  
**Parent Class:** [`MyGUI.Widget`](#widget) *(inherits all methods and properties)*

#### Specific Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `itemCount` | `integer` | R | `local count = lb.itemCount` |
| `indexSelected` | `integer` | RW | `lb.indexSelected = 0` |

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `getItemCount` | `` | `integer` | `obj:getItemCount()` |
| `insertItemAt` | `idx: integer, name: string` | `void` | `obj:insertItemAt(idx, name)` |
| `addItem` | `name: string` | `void` | `obj:addItem(name)` |
| `removeItemAt` | `idx: integer` | `void` | `obj:removeItemAt(idx)` |
| `removeAllItems` | `` | `void` | `obj:removeAllItems()` |
| `swapItemsAt` | `i1: integer, i2: integer` | `void` | `obj:swapItemsAt(i1, i2)` |
| `setItemNameAt` | `idx: integer, name: string` | `void` | `obj:setItemNameAt(idx, name)` |
| `getItemNameAt` | `idx: integer` | `string` | `obj:getItemNameAt(idx)` |
| `getIndexSelected` | `` | `integer` | `obj:getIndexSelected()` |
| `setIndexSelected` | `idx: integer` | `void` | `obj:setIndexSelected(idx)` |
| `clearIndexSelected` | `` | `void` | `obj:clearIndexSelected()` |
| `findItemIndexWith` | `name: string` | `integer` | `obj:findItemIndexWith(name)` |
| `beginToItemAt` | `idx: integer` | `void` | `obj:beginToItemAt(idx)` |
| `beginToItemFirst` | `` | `void` | `obj:beginToItemFirst()` |
| `beginToItemLast` | `` | `void` | `obj:beginToItemLast()` |
| `beginToItemSelected` | `` | `void` | `obj:beginToItemSelected()` |
| `isItemVisibleAt` | `idx: integer, fill: boolean` | `boolean` | `obj:isItemVisibleAt(idx, fill)` |
| `isItemSelectedVisible` | `fill: boolean` | `boolean` | `obj:isItemSelectedVisible(fill)` |
| `setScrollVisible` | `visible: boolean` | `void` | `obj:setScrollVisible(visible)` |
| `setScrollPosition` | `pos: integer` | `void` | `obj:setScrollPosition(pos)` |
| `getOptimalHeight` | `` | `integer` | `obj:getOptimalHeight()` |
| `getWidgetByIndex` | `idx: integer` | `Widget` | `obj:getWidgetByIndex(idx)` |

### MenuBar
**Metatable:** `KenshiLua.MyGUI.MenuBar`  
**Header:** `src/Bindings/MyGUI/MenuBarBinding.h`  
**Parent Class:** [`MyGUI.MenuControl`](#menucontrol) *(inherits all methods and properties)*

### MenuControl
**Metatable:** `KenshiLua.MyGUI.MenuControl`  
**Header:** `src/Bindings/MyGUI/MenuControlBinding.h`  
**Parent Class:** [`MyGUI.Widget`](#widget) *(inherits all methods and properties)*

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `getItemCount` | `` | `integer` | `obj:getItemCount()` |
| `insertItemAt` | `idx: integer, name: string, type: integer, id: string` | `Widget` | `obj:insertItemAt(idx, name, type, id)` |
| `addItem` | `name: string, type: integer, id: string` | `Widget` | `obj:addItem(name, type, id)` |
| `removeItemAt` | `idx: integer` | `void` | `obj:removeItemAt(idx)` |
| `removeAllItems` | `` | `void` | `obj:removeAllItems()` |
| `getItemNameAt` | `idx: integer` | `string` | `obj:getItemNameAt(idx)` |
| `setItemNameAt` | `idx: integer, name: string` | `void` | `obj:setItemNameAt(idx, name)` |
| `getItemIdAt` | `idx: integer` | `string` | `obj:getItemIdAt(idx)` |
| `setItemIdAt` | `idx: integer, id: string` | `void` | `obj:setItemIdAt(idx, id)` |
| `getItemAt` | `idx: integer` | `Widget` | `obj:getItemAt(idx)` |
| `getItemById` | `id: string` | `Widget` | `obj:getItemById(id)` |
| `getItemIndex` | `` | `integer` | `obj:getItemIndex()` |
| `getItemIndexById` | `id: string` | `integer` | `obj:getItemIndexById(id)` |
| `findItemIndexWith` | `name: string` | `integer` | `obj:findItemIndexWith(name)` |
| `setItemDataAt` | `idx: integer, data: string` | `void` | `obj:setItemDataAt(idx, data)` |
| `clearItemDataAt` | `idx: integer` | `void` | `obj:clearItemDataAt(idx)` |
| `setItemTypeAt` | `idx: integer, type: integer` | `void` | `obj:setItemTypeAt(idx, type)` |
| `getItemTypeAt` | `idx: integer` | `integer` | `obj:getItemTypeAt(idx)` |
| `setItemChildVisibleAt` | `idx: integer, visible: boolean` | `void` | `obj:setItemChildVisibleAt(idx, visible)` |
| `createItemChildAt` | `idx: integer` | `Widget` | `obj:createItemChildAt(idx)` |
| `setPopupAccept` | `mode: boolean` | `void` | `obj:setPopupAccept(mode)` |
| `getPopupAccept` | `` | `boolean` | `obj:getPopupAccept()` |
| `setPopupMode` | `mode: boolean` | `void` | `obj:setPopupMode(mode)` |
| `getPopupMode` | `` | `boolean` | `obj:getPopupMode()` |
| `setVerticalAlignment` | `vert: boolean` | `void` | `obj:setVerticalAlignment(vert)` |
| `getVerticalAlignment` | `` | `boolean` | `obj:getVerticalAlignment()` |

### MenuItem
**Metatable:** `KenshiLua.MyGUI.MenuItem`  
**Header:** `src/Bindings/MyGUI/MenuItemBinding.h`  
**Parent Class:** [`MyGUI.Button`](#button) *(inherits all methods and properties)*

#### Specific Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `itemId` | `string` | RW | `mi.itemId = 'FILE_OPEN'` |
| `itemType` | `MenuItemType` | RW | `mi.itemType = MyGUI.MenuItemType.Normal` |
| `itemIndex` | `integer` | R | `local idx = mi.itemIndex` |

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `setItemName` | `name: string` | `void` | `obj:setItemName(name)` |
| `getItemName` | `` | `string` | `obj:getItemName()` |
| `setItemId` | `id: string` | `void` | `obj:setItemId(id)` |
| `getItemId` | `` | `string` | `obj:getItemId()` |
| `setItemType` | `type: integer` | `void` | `obj:setItemType(type)` |
| `getItemType` | `` | `integer` | `obj:getItemType()` |
| `setItemData` | `data: string` | `void` | `obj:setItemData(data)` |
| `clearItemData` | `` | `void` | `obj:clearItemData()` |
| `getItemIndex` | `` | `integer` | `obj:getItemIndex()` |
| `createItemChild` | `` | `Widget` | `obj:createItemChild()` |
| `removeItemChild` | `` | `void` | `obj:removeItemChild()` |
| `getItemChild` | `` | `Widget` | `obj:getItemChild()` |
| `setItemChildVisible` | `visible: boolean` | `void` | `obj:setItemChildVisible(visible)` |
| `setItemChecked` | `chk: boolean` | `void` | `obj:setItemChecked(chk)` |
| `getItemChecked` | `` | `boolean` | `obj:getItemChecked()` |

### MultiListBox
**Metatable:** `KenshiLua.MyGUI.MultiListBox`  
**Header:** `src/Bindings/MyGUI/MultiListBoxBinding.h`  
**Parent Class:** [`MyGUI.Widget`](#widget) *(inherits all methods and properties)*

#### Specific Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `columnCount` | `integer` | R | `local cols = mlb.columnCount` |
| `itemCount` | `integer` | R | `local items = mlb.itemCount` |
| `indexSelected` | `integer` | RW | `mlb.indexSelected = 0` |

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `getColumnCount` | `` | `integer` | `obj:getColumnCount()` |
| `insertColumnAt` | `col: integer, name: string, width: integer` | `void` | `obj:insertColumnAt(col, name, width)` |
| `addColumn` | `name: string, width: integer` | `void` | `obj:addColumn(name, width)` |
| `removeColumnAt` | `col: integer` | `void` | `obj:removeColumnAt(col)` |
| `removeAllColumns` | `` | `void` | `obj:removeAllColumns()` |
| `setColumnNameAt` | `col: integer, name: string` | `void` | `obj:setColumnNameAt(col, name)` |
| `setColumnWidthAt` | `col: integer, width: integer` | `void` | `obj:setColumnWidthAt(col, width)` |
| `getColumnNameAt` | `col: integer` | `string` | `obj:getColumnNameAt(col)` |
| `getColumnWidthAt` | `col: integer` | `integer` | `obj:getColumnWidthAt(col)` |
| `getItemCount` | `` | `integer` | `obj:getItemCount()` |
| `insertItemAt` | `idx: integer, name: string` | `void` | `obj:insertItemAt(idx, name)` |
| `addItem` | `name: string` | `void` | `obj:addItem(name)` |
| `removeItemAt` | `idx: integer` | `void` | `obj:removeItemAt(idx)` |
| `removeAllItems` | `` | `void` | `obj:removeAllItems()` |
| `swapItemsAt` | `i1: integer, i2: integer` | `void` | `obj:swapItemsAt(i1, i2)` |
| `setItemNameAt` | `idx: integer, name: string` | `void` | `obj:setItemNameAt(idx, name)` |
| `getItemNameAt` | `idx: integer` | `string` | `obj:getItemNameAt(idx)` |
| `getIndexSelected` | `` | `integer` | `obj:getIndexSelected()` |
| `setIndexSelected` | `idx: integer` | `void` | `obj:setIndexSelected(idx)` |
| `clearIndexSelected` | `` | `void` | `obj:clearIndexSelected()` |
| `setSubItemNameAt` | `col: integer, row: integer, name: string` | `void` | `obj:setSubItemNameAt(col, row, name)` |
| `getSubItemNameAt` | `col: integer, row: integer` | `string` | `obj:getSubItemNameAt(col, row)` |
| `findSubItemWith` | `col: integer, name: string` | `integer` | `obj:findSubItemWith(col, name)` |

### PopupMenu
**Metatable:** `KenshiLua.MyGUI.PopupMenu`  
**Header:** `src/Bindings/MyGUI/PopupMenuBinding.h`  
**Parent Class:** [`MyGUI.MenuControl`](#menucontrol) *(inherits all methods and properties)*

### ProgressBar
**Metatable:** `KenshiLua.MyGUI.ProgressBar`  
**Header:** `src/Bindings/MyGUI/ProgressBarBinding.h`  
**Parent Class:** [`MyGUI.Widget`](#widget) *(inherits all methods and properties)*

#### Specific Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `progressRange` | `integer` | RW | `pb.progressRange = 100` |
| `progressPosition` | `integer` | RW | `pb.progressPosition = 50` |
| `progressAutoTrack` | `boolean` | RW | `pb.progressAutoTrack = true` |
| `flowDirection` | `FlowDirection` | RW | `pb.flowDirection = MyGUI.FlowDirection.LeftToRight` |

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `setProgressRange` | `r: integer` | `void` | `obj:setProgressRange(r)` |
| `getProgressRange` | `` | `integer` | `obj:getProgressRange()` |
| `setProgressPosition` | `p: integer` | `void` | `obj:setProgressPosition(p)` |
| `getProgressPosition` | `` | `integer` | `obj:getProgressPosition()` |
| `setProgressAutoTrack` | `at: boolean` | `void` | `obj:setProgressAutoTrack(at)` |
| `getProgressAutoTrack` | `` | `boolean` | `obj:getProgressAutoTrack()` |
| `setFlowDirection` | `dir: integer` | `void` | `obj:setFlowDirection(dir)` |
| `getFlowDirection` | `` | `integer` | `obj:getFlowDirection()` |

### ScrollBar
**Metatable:** `KenshiLua.MyGUI.ScrollBar`  
**Header:** `src/Bindings/MyGUI/ScrollBarBinding.h`  
**Parent Class:** [`MyGUI.Widget`](#widget) *(inherits all methods and properties)*

#### Specific Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `scrollRange` | `integer` | RW | `sb.scrollRange = 100` |
| `scrollPosition` | `integer` | RW | `sb.scrollPosition = 25` |
| `scrollPage` | `integer` | RW | `sb.scrollPage = 10` |
| `viewPage` | `integer` | RW | `sb.viewPage = 20` |

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `setScrollRange` | `range: integer` | `void` | `obj:setScrollRange(range)` |
| `getScrollRange` | `` | `integer` | `obj:getScrollRange()` |
| `setScrollPosition` | `pos: integer` | `void` | `obj:setScrollPosition(pos)` |
| `getScrollPosition` | `` | `integer` | `obj:getScrollPosition()` |
| `setScrollPage` | `page: integer` | `void` | `obj:setScrollPage(page)` |
| `getScrollPage` | `` | `integer` | `obj:getScrollPage()` |
| `setScrollViewPage` | `page: integer` | `void` | `obj:setScrollViewPage(page)` |
| `getScrollViewPage` | `` | `integer` | `obj:getScrollViewPage()` |
| `setScrollWheelPage` | `page: integer` | `void` | `obj:setScrollWheelPage(page)` |
| `getScrollWheelPage` | `` | `integer` | `obj:getScrollWheelPage()` |
| `setVerticalAlignment` | `vert: boolean` | `void` | `obj:setVerticalAlignment(vert)` |
| `getVerticalAlignment` | `` | `boolean` | `obj:getVerticalAlignment()` |
| `setTrackSize` | `sz: integer` | `void` | `obj:setTrackSize(sz)` |
| `getTrackSize` | `` | `integer` | `obj:getTrackSize()` |
| `setMinTrackSize` | `sz: integer` | `void` | `obj:setMinTrackSize(sz)` |
| `getMinTrackSize` | `` | `integer` | `obj:getMinTrackSize()` |
| `getLineSize` | `` | `integer` | `obj:getLineSize()` |
| `setMoveToClick` | `mtc: boolean` | `void` | `obj:setMoveToClick(mtc)` |
| `getMoveToClick` | `` | `boolean` | `obj:getMoveToClick()` |
| `setRepeatEnabled` | `en: boolean` | `void` | `obj:setRepeatEnabled(en)` |
| `getRepeatEnabled` | `` | `boolean` | `obj:getRepeatEnabled()` |

### ScrollView
**Metatable:** `KenshiLua.MyGUI.ScrollView`  
**Header:** `src/Bindings/MyGUI/ScrollViewBinding.h`  
**Parent Class:** [`MyGUI.Widget`](#widget) *(inherits all methods and properties)*

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `setVisibleHScroll` | `v: boolean` | `void` | `obj:setVisibleHScroll(v)` |
| `isVisibleHScroll` | `` | `boolean` | `obj:isVisibleHScroll()` |
| `setVisibleVScroll` | `v: boolean` | `void` | `obj:setVisibleVScroll(v)` |
| `isVisibleVScroll` | `` | `boolean` | `obj:isVisibleVScroll()` |
| `setCanvasAlign` | `a: integer` | `void` | `obj:setCanvasAlign(a)` |
| `getCanvasAlign` | `` | `integer` | `obj:getCanvasAlign()` |
| `setCanvasSize` | `w: integer, h: integer` | `void` | `obj:setCanvasSize(w, h)` |
| `getCanvasSize` | `` | `integer, integer` | `obj:getCanvasSize()` |
| `setViewOffset` | `x: integer, y: integer` | `void` | `obj:setViewOffset(x, y)` |
| `getViewOffset` | `` | `integer, integer` | `obj:getViewOffset()` |
| `getViewCoord` | `` | `integer, integer, integer, integer` | `obj:getViewCoord()` |

### TabControl
**Metatable:** `KenshiLua.MyGUI.TabControl`  
**Header:** `src/Bindings/MyGUI/TabControlBinding.h`  
**Parent Class:** [`MyGUI.Widget`](#widget) *(inherits all methods and properties)*

#### Specific Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `itemCount` | `integer` | R | `local count = tc.itemCount` |
| `indexSelected` | `integer` | RW | `tc.indexSelected = 0` |
| `buttonAutoWidth` | `boolean` | RW | `tc.buttonAutoWidth = true` |

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `getItemCount` | `` | `integer` | `obj:getItemCount()` |
| `insertItemAt` | `idx: integer, name: string` | `Widget` | `obj:insertItemAt(idx, name)` |
| `addItem` | `name: string` | `Widget` | `obj:addItem(name)` |
| `removeItemAt` | `idx: integer` | `void` | `obj:removeItemAt(idx)` |
| `removeAllItems` | `` | `void` | `obj:removeAllItems()` |
| `getItemNameAt` | `idx: integer` | `string` | `obj:getItemNameAt(idx)` |
| `setItemNameAt` | `idx: integer, name: string` | `void` | `obj:setItemNameAt(idx, name)` |
| `getIndexSelected` | `` | `integer` | `obj:getIndexSelected()` |
| `setIndexSelected` | `idx: integer` | `void` | `obj:setIndexSelected(idx)` |
| `clearIndexSelected` | `` | `void` | `obj:clearIndexSelected()` |
| `getItemAt` | `idx: integer` | `Widget` | `obj:getItemAt(idx)` |
| `getItemSelected` | `` | `Widget` | `obj:getItemSelected()` |
| `setButtonWidthAt` | `idx: integer, w: integer` | `void` | `obj:setButtonWidthAt(idx, w)` |
| `getButtonWidthAt` | `idx: integer` | `integer` | `obj:getButtonWidthAt(idx)` |
| `setButtonDefaultWidth` | `w: integer` | `void` | `obj:setButtonDefaultWidth(w)` |
| `getButtonDefaultWidth` | `` | `integer` | `obj:getButtonDefaultWidth()` |
| `setButtonAutoWidth` | `autoW: boolean` | `void` | `obj:setButtonAutoWidth(autoW)` |
| `getButtonAutoWidth` | `` | `boolean` | `obj:getButtonAutoWidth()` |
| `setSmoothShow` | `smooth: boolean` | `void` | `obj:setSmoothShow(smooth)` |
| `getSmoothShow` | `` | `boolean` | `obj:getSmoothShow()` |

### TabItem
**Metatable:** `KenshiLua.MyGUI.TabItem`  
**Header:** `src/Bindings/MyGUI/TabItemBinding.h`  
**Parent Class:** [`MyGUI.TextBox`](#textbox) *(inherits all methods and properties)*

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `setButtonWidth` | `w: integer` | `void` | `obj:setButtonWidth(w)` |

### TextBox
**Metatable:** `KenshiLua.MyGUI.TextBox`  
**Header:** `src/Bindings/MyGUI/TextBoxBinding.h`  
**Parent Class:** [`MyGUI.Widget`](#widget) *(inherits all methods and properties)*

#### Specific Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `caption` | `string` | RW | `tb.caption = 'Hello World'` |
| `text` | `string` | RW | `tb.text = 'Hello World'` |
| `textShadow` | `boolean` | RW | `tb.textShadow = true` |
| `textShadowColour` | `Colour` | RW | `tb.textShadowColour = MyGUI.Colour.new(0, 0, 0, 1)` |
| `textColour` | `Colour` | RW | `tb.textColour = MyGUI.Colour.new(1, 1, 1, 1)` |

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `getTextRegion` | `` | `integer, integer, integer, integer` | `obj:getTextRegion()` |
| `getTextSize` | `` | `integer, integer` | `obj:getTextSize()` |
| `setFontName` | `font: string` | `void` | `obj:setFontName(font)` |
| `getFontName` | `` | `string` | `obj:getFontName()` |
| `setFontHeight` | `h: integer` | `void` | `obj:setFontHeight(h)` |
| `getFontHeight` | `` | `integer` | `obj:getFontHeight()` |
| `setTextAlign` | `a: integer` | `void` | `obj:setTextAlign(a)` |
| `getTextAlign` | `` | `integer` | `obj:getTextAlign()` |
| `setTextColour` | `col: Colour` | `void` | `obj:setTextColour(col)` |
| `getTextColour` | `` | `Colour` | `obj:getTextColour()` |
| `setCaptionWithReplacing` | `text: string` | `void` | `obj:setCaptionWithReplacing(text)` |

### Window
**Metatable:** `KenshiLua.MyGUI.Window`  
**Header:** `src/Bindings/MyGUI/WindowBinding.h`  
**Parent Class:** [`MyGUI.TextBox`](#textbox) *(inherits all methods and properties)*

#### Specific Properties
| Property | Type | R/W | Example |
|---|---|---|---|
| `autoAlpha` | `boolean` | RW | `win.autoAlpha = true` |
| `minSize` | `IntSize` | RW | `win.minSize = MyGUI.IntSize.new(100, 100)` |
| `maxSize` | `IntSize` | RW | `win.maxSize = MyGUI.IntSize.new(800, 600)` |

#### Specific Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `setVisibleSmooth` | `smooth: boolean` | `void` | `obj:setVisibleSmooth(smooth)` |
| `destroySmooth` | `` | `void` | `obj:destroySmooth()` |
| `setAutoAlpha` | `autoAlpha: boolean` | `void` | `obj:setAutoAlpha(autoAlpha)` |
| `getAutoAlpha` | `` | `boolean` | `obj:getAutoAlpha()` |
| `setSnap` | `snap: boolean` | `void` | `obj:setSnap(snap)` |
| `getSnap` | `` | `boolean` | `obj:getSnap()` |
| `setMovable` | `m: boolean` | `void` | `obj:setMovable(m)` |
| `getMovable` | `` | `boolean` | `obj:getMovable()` |
| `setMinSize` | `w: integer, h: integer` | `void` | `obj:setMinSize(w, h)` |
| `getMinSize` | `` | `integer, integer` | `obj:getMinSize()` |
| `setMaxSize` | `w: integer, h: integer` | `void` | `obj:setMaxSize(w, h)` |
| `getMaxSize` | `` | `integer, integer` | `obj:getMaxSize()` |
| `getActionScale` | `` | `IntCoord` | `obj:getActionScale()` |
| `getCaptionWidget` | `` | `Widget` | `obj:getCaptionWidget()` |

## Managers (Singletons)

Managers provide global control over input, cursor pointer, skins, layout templates, clipboard, and rendering.

### ClipboardManager
**Metatable:** `KenshiLua.MyGUI.ClipboardManager`  
**Header:** `src/Bindings/MyGUI/ClipboardManagerBinding.h`

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `getInstance` | `` | `ClipboardManager` | `MyGUI.ClipboardManager.getInstance()` |

#### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `setClipboardData` | `` | `void` | `mgr:setClipboardData()` |
| `clearClipboardData` | `` | `void` | `mgr:clearClipboardData()` |
| `getClipboardData` | `` | `string` | `mgr:getClipboardData()` |
| `setText` | `` | `void` | `mgr:setText()` |
| `getText` | `` | `string` | `mgr:getText()` |

### Gui
**Metatable:** `KenshiLua.MyGUI.Gui`  
**Header:** `src/Bindings/MyGUI/GuiBinding.h`

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `getInstance` | `` | `Gui` | `MyGUI.Gui.getInstance()` |

#### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `createWidget` | `` | `Widget` | `mgr:createWidget()` |
| `createWidgetReal` | `` | `Widget` | `mgr:createWidgetReal()` |
| `findWidget` | `` | `Widget` | `mgr:findWidget()` |
| `findWidgetT` | `` | `void` | `mgr:findWidgetT()` |
| `destroyWidget` | `` | `void` | `mgr:destroyWidget()` |
| `destroyWidgets` | `` | `void` | `mgr:destroyWidgets()` |
| `hidePointer` | `` | `void` | `mgr:hidePointer()` |
| `showPointer` | `` | `void` | `mgr:showPointer()` |
| `isPointerVisible` | `` | `boolean` | `mgr:isPointerVisible()` |

### InputManager
**Metatable:** `KenshiLua.MyGUI.InputManager`  
**Header:** `src/Bindings/MyGUI/InputManagerBinding.h`

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `getInstance` | `` | `InputManager` | `MyGUI.InputManager.getInstance()` |

#### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `injectMouseMove` | `absy: integer, absz: integer` | `boolean` | `mgr:injectMouseMove(absy, absz)` |
| `injectMousePress` | `absy: integer, btn: integer` | `boolean` | `mgr:injectMousePress(absy, btn)` |
| `injectMouseRelease` | `absy: integer, btn: integer` | `boolean` | `mgr:injectMouseRelease(absy, btn)` |
| `injectKeyPress` | `text: integer` | `boolean` | `mgr:injectKeyPress(text)` |
| `injectKeyRelease` | `` | `boolean` | `mgr:injectKeyRelease()` |
| `isControlPressed` | `` | `boolean` | `mgr:isControlPressed()` |
| `isShiftPressed` | `` | `boolean` | `mgr:isShiftPressed()` |
| `isFocusMouse` | `` | `boolean` | `mgr:isFocusMouse()` |
| `isFocusKey` | `` | `boolean` | `mgr:isFocusKey()` |
| `isCaptureMouse` | `` | `boolean` | `mgr:isCaptureMouse()` |
| `setKeyFocusWidget` | `widget: Widget` | `void` | `mgr:setKeyFocusWidget(widget)` |
| `resetKeyFocusWidget` | `` | `void` | `mgr:resetKeyFocusWidget()` |
| `getMouseFocusWidget` | `` | `Widget` | `mgr:getMouseFocusWidget()` |
| `getKeyFocusWidget` | `` | `Widget` | `mgr:getKeyFocusWidget()` |
| `getMousePosition` | `` | `integer, integer` | `mgr:getMousePosition()` |
| `addWidgetModal` | `widget: Widget` | `void` | `mgr:addWidgetModal(widget)` |
| `removeWidgetModal` | `widget: Widget` | `void` | `mgr:removeWidgetModal(widget)` |
| `isModalAny` | `` | `boolean` | `mgr:isModalAny()` |
| `resetMouseCaptureWidget` | `` | `void` | `mgr:resetMouseCaptureWidget()` |

### LayoutManager
**Metatable:** `KenshiLua.MyGUI.LayoutManager`  
**Header:** `src/Bindings/MyGUI/LayoutManagerBinding.h`

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `getInstance` | `` | `LayoutManager` | `MyGUI.LayoutManager.getInstance()` |

#### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `loadLayout` | `filename: string, prefix: string, parent: Widget` | `table` | `mgr:loadLayout(filename, prefix, parent)` |
| `unloadLayout` | `layoutWidgets: table` | `void` | `mgr:unloadLayout(layoutWidgets)` |

### PointerManager
**Metatable:** `KenshiLua.MyGUI.PointerManager`  
**Header:** `src/Bindings/MyGUI/PointerManagerBinding.h`

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `getInstance` | `` | `PointerManager` | `MyGUI.PointerManager.getInstance()` |

#### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `setPointer` | `name: string` | `void` | `mgr:setPointer(name)` |
| `clearPointer` | `` | `void` | `mgr:clearPointer()` |
| `getVisible` | `` | `boolean` | `mgr:getVisible()` |
| `setVisible` | `visible: boolean` | `void` | `mgr:setVisible(visible)` |
| `isVisible` | `` | `boolean` | `mgr:isVisible()` |
| `getDefaultPointer` | `` | `string` | `mgr:getDefaultPointer()` |
| `setDefaultPointer` | `name: string` | `void` | `mgr:setDefaultPointer(name)` |
| `getLayerName` | `` | `string` | `mgr:getLayerName()` |
| `setLayerName` | `name: string` | `void` | `mgr:setLayerName(name)` |

### RenderManager
**Metatable:** `KenshiLua.MyGUI.RenderManager`  
**Header:** `src/Bindings/MyGUI/RenderManagerBinding.h`

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `getInstance` | `` | `RenderManager` | `MyGUI.RenderManager.getInstance()` |

#### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `getViewSize` | `` | `integer, integer` | `mgr:getViewSize()` |
| `getViewWidth` | `` | `integer` | `mgr:getViewWidth()` |
| `getViewHeight` | `` | `integer` | `mgr:getViewHeight()` |

### SkinManager
**Metatable:** `KenshiLua.MyGUI.SkinManager`  
**Header:** `src/Bindings/MyGUI/SkinManagerBinding.h`

#### Static Methods
| Method | Arguments | Return Type | Example |
|---|---|---|---|
| `getInstance` | `` | `SkinManager` | `MyGUI.SkinManager.getInstance()` |

#### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| `isExist` | `skinName: string` | `boolean` | `mgr:isExist(skinName)` |
| `getDefaultSkin` | `` | `string` | `mgr:getDefaultSkin()` |
| `setDefaultSkin` | `skinName: string` | `void` | `mgr:setDefaultSkin(skinName)` |

## Event Callbacks Reference

Event callbacks are attached to widgets using `widget:registerCallback(eventType, callbackFunction)`.

### Usage Example
```lua
local win = MyGUI.createWindow("Kenshi_WindowCX", 100, 100, 300, 200, "ExampleWindow", "Window")
win:upLayerItem()
local btn = win:createWidget("Button", "Kenshi_Button1", 20, 20, 120, 30, 0, "MyButton")
btn:setCaption("Click Me")
btn:registerCallback("OnClick", function(sender)
    print("Button clicked:", sender.caption)
end)
```

### Supported Event Types
| Event Name | Accepted String Aliases | Target Widgets | Handler Signature | Description |
|---|---|---|---|---|
| **`OnClick`** | `"OnClick"`, `"click"` | `Button, MenuItem, Widget` | `function(sender: Widget)` | Triggered when the user clicks on the widget with the mouse. |
| **`OnTextChanged`** | `"EditTextChange"`, `"editTextChange"`, `"change"` | `EditBox, ComboBox` | `function(sender: EditBox)` | Triggered when the text content of an edit box is modified by the user or programmatically. |
| **`OnWindowButtonPressed`** | `"WindowButtonPressed"`, `"windowButtonPressed"` | `Window` | `function(sender: Window, buttonName: string)` | Triggered when a window control button (e.g. close, minimize, maximize) is clicked. |
| **`OnMouseButtonPressed`** | `"MouseButtonPressed"`, `"mouseButtonPressed"`, `"mouseDown"` | `Widget` | `function(sender: Widget, left: integer, top: integer, button: MouseButton)` | Triggered when a mouse button is pressed down over the widget. |
| **`OnMouseButtonReleased`** | `"MouseButtonReleased"`, `"mouseButtonReleased"`, `"mouseUp"` | `Widget` | `function(sender: Widget, left: integer, top: integer, button: MouseButton)` | Triggered when a mouse button is released over the widget. |
| **`OnMouseSetFocus`** | `"MouseSetFocus"`, `"mouseSetFocus"`, `"mouseOver"` | `Widget` | `function(sender: Widget, oldWidget: Widget)` | Triggered when the mouse cursor enters the bounds of the widget. |
| **`OnMouseLostFocus`** | `"MouseLostFocus"`, `"mouseLostFocus"`, `"mouseOut"` | `Widget` | `function(sender: Widget, newWidget: Widget)` | Triggered when the mouse cursor leaves the bounds of the widget. |
| **`OnMouseMove`** | `"MouseMove"`, `"mouseMove"` | `Widget` | `function(sender: Widget, left: integer, top: integer)` | Triggered continuously as the mouse moves across the widget surface. |
| **`OnMouseWheel`** | `"MouseWheel"`, `"mouseWheel"` | `Widget` | `function(sender: Widget, relValue: integer)` | Triggered when the mouse scroll wheel is rotated while hovering over the widget. |
| **`OnKeyButtonPressed`** | `"KeyButtonPressed"`, `"keyButtonPressed"`, `"keyDown"` | `Widget` | `function(sender: Widget, keyCode: KeyCode, charCode: integer)` | Triggered when a keyboard key is pressed while the widget holds key focus. |
| **`OnKeyButtonReleased`** | `"KeyButtonReleased"`, `"keyButtonReleased"`, `"keyUp"` | `Widget` | `function(sender: Widget, keyCode: KeyCode)` | Triggered when a keyboard key is released while the widget holds key focus. |
| **`OnComboAccept`** | `"ComboAccept"`, `"comboAccept"` | `ComboBox` | `function(sender: ComboBox, index: integer)` | Triggered when an item in the combo box drop list is confirmed/accepted. |
| **`OnComboChangePosition`** | `"ComboChangePosition"`, `"comboChangePosition"` | `ComboBox` | `function(sender: ComboBox, index: integer)` | Triggered when the highlighted selection position changes in the combo box. |
| **`OnListSelectAccept`** | `"ListSelectAccept"`, `"listSelectAccept"` | `ListBox` | `function(sender: ListBox, index: integer)` | Triggered when an item in the list box is double-clicked or confirmed with Enter. |
| **`OnListChangePosition`** | `"ListChangePosition"`, `"listChangePosition"` | `ListBox` | `function(sender: ListBox, index: integer)` | Triggered when the selected item index changes in the list box. |
| **`OnWindowChangeCoord`** | `"WindowChangeCoord"`, `"windowChangeCoord"` | `Window` | `function(sender: Window)` | Triggered when a window is moved or resized by the user. |
| **`OnScrollChangePosition`** | `"ScrollChangePosition"`, `"scrollChangePosition"` | `ScrollBar` | `function(sender: ScrollBar, position: integer)` | Triggered when the scroll bar slider position changes. |
| **`OnTabChangeSelect`** | `"TabChangeSelect"`, `"tabChangeSelect"` | `TabControl` | `function(sender: TabControl, index: integer)` | Triggered when the active tab sheet is changed in a tab control. |
| **`OnMenuAccept`** | `"MenuAccept"`, `"menuAccept"`, `"MenuCtrlAccept"` | `MenuControl, MenuBar, PopupMenu` | `function(sender: MenuControl, item: MenuItem)` | Triggered when an item in a menu bar or popup menu is activated/clicked. |

## Global Enums
