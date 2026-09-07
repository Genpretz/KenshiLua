# generate_mygui_reference.py

"""Generate a dedicated markdown reference for MyGUI Lua bindings.

This script scans `src/Bindings/MyGUI/*.cpp` and `src/Bindings/MyGUI/*.h` to extract:
- Global `MyGUI` table functions (creation helpers, layouts, pointers, clipboards)
- Core types (IntPoint, IntSize, IntCoord, IntRect, FloatPoint, FloatSize, FloatCoord, FloatRect, Colour)
- Base Widget class and its complete property/method set
- All specialized Widget classes with inheritance hierarchy
- Manager singletons (Gui, InputManager, PointerManager, ClipboardManager, LayoutManager, RenderManager, SkinManager)
- Event callbacks system with event names and handler signatures
- Global Enums (Align, WidgetStyle, FlowDirection, MenuItemType, MouseButton, KeyCode, ResizingPolicy)

Output: `docs/MyGUIReference.md`
"""

import os
import re
import pathlib

PROJECT_ROOT = pathlib.Path(__file__).resolve().parents[2]
MYGUI_DIR = PROJECT_ROOT / "src" / "Bindings" / "MyGUI"
DOCS_DIR = PROJECT_ROOT / "docs"
DOCS_DIR.mkdir(parents=True, exist_ok=True)

def strip_cpp_comments(text: str) -> str:
    text = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), text, flags=re.DOTALL)
    text = re.sub(r"//.*", "", text)
    return text

def find_function_body(content: str, marker: str) -> str:
    idx = 0
    while True:
        idx = content.find(marker, idx)
        if idx == -1:
            return ""
        end_idx = idx + len(marker)
        if end_idx < len(content) and (content[end_idx].isalnum() or content[end_idx] == '_'):
            idx = end_idx
            continue
        if idx > 0 and (content[idx-1].isalnum() or content[idx-1] == '_'):
            idx = end_idx
            continue
        break
        
    brace_start = content.find('{', idx)
    if brace_start == -1:
        return ""
    brace_count = 1
    i = brace_start + 1
    while i < len(content) and brace_count > 0:
        if content[i] == '{':
            brace_count += 1
        elif content[i] == '}':
            brace_count -= 1
        i += 1
    return content[brace_start:i]

def extract_args_from_body(body: str, is_static: bool = False):
    if not body:
        return []
    indices = {}
    base_idx = 1 if is_static else 2
    
    for m in re.finditer(r"\bread(Vector2|Vector3|Vector4|Quaternion|IntPoint|IntSize|IntCoord|IntRect|FloatPoint|FloatSize|FloatCoord|FloatRect|Colour|Align)\s*\(\s*L\s*,\s*(\d+)\s*,\s*([\w_]+)\)", body):
        type_name = m.group(1)
        idx = int(m.group(2))
        var = m.group(3)
        if idx >= base_idx:
            indices[idx] = {"name": var, "type": type_name}
            
    for m in re.finditer(r"\b([\w_]+)\s*=\s*[^;]*?\b(?:lua[lL]?_check(\w+)|lua[lL]?_opt(\w+)|lua[lL]?_to(\w+)|checkObject\s*<\s*([\w:*&\s<>]+)\s*>|read(\w+))\b[^;]*?\(\s*L\s*,\s*(\d+)", body):
        var = m.group(1)
        check_type = m.group(2) or m.group(3) or m.group(4)
        check_obj_type = m.group(5)
        read_type = m.group(6)
        idx = int(m.group(7))
        
        if idx >= base_idx:
            if check_obj_type:
                t = check_obj_type.strip().replace("MyGUI::", "")
            elif read_type:
                t = read_type
            elif check_type:
                t = check_type.lower()
                if t in ("integer", "number", "string", "boolean"):
                    t = t
                else:
                    t = check_type
            else:
                t = "any"
            indices[idx] = {"name": var, "type": t}

    for m in re.finditer(r"\b(?:lua[lL]?_check(\w+)|lua[lL]?_opt(\w+)|lua[lL]?_to(\w+)|checkObject\s*<\s*([\w:*&\s<>]+)\s*>|read(\w+))\b[^;]*?\(\s*L\s*,\s*(\d+)", body):
        check_type = m.group(1) or m.group(2) or m.group(3)
        check_obj_type = m.group(4)
        read_type = m.group(5)
        idx = int(m.group(6))
        
        if idx >= base_idx and idx not in indices:
            if check_obj_type:
                t = check_obj_type.strip().replace("MyGUI::", "")
            elif read_type:
                t = read_type
            elif check_type:
                t = check_type.lower()
            else:
                t = "any"
            indices[idx] = {"name": f"arg{idx - base_idx + 1}", "type": t}
            
    sorted_args = []
    for idx in sorted(indices.keys()):
        sorted_args.append(indices[idx])
        
    return sorted_args

def extract_return_type_from_body(body: str) -> str:
    if not body:
        return "void"
    if "return MyGUIBindings::pushWidget(L," in body or "return pushWidget(L," in body:
        return "Widget"
    m = re.search(r"return\s+pushObject(?:T)?\s*<\s*([\w:*&\s<>]+)\s*>\s*\(", body)
    if m:
        return m.group(1).strip().replace("MyGUI::", "")
    m = re.search(r"return\s+pushValue\s*<\s*([\w:*&\s<>]+)\s*>\s*\(", body)
    if m:
        return m.group(1).strip().replace("MyGUI::", "")
    if re.search(r"lua_pushstring\s*\(", body):
        return "string"
    if re.search(r"lua_pushinteger\s*\(", body) or re.search(r"lua_pushnumber\s*\(", body):
        ret_m = re.search(r"return\s+(\d+);", body)
        count = int(ret_m.group(1)) if ret_m else 1
        if count == 1:
            return "number" if "lua_pushnumber" in body else "integer"
        elif count == 2:
            return "integer, integer"
        elif count == 4:
            return "integer, integer, integer, integer"
    if re.search(r"lua_pushboolean\s*\(", body):
        return "boolean"
    if re.search(r"return\s+0;", body):
        return "void"
    return "void"

def make_anchor(name: str) -> str:
    slug = name.lower().replace(" ", "-")
    slug = re.sub(r'[^a-z0-9\-_:]', '', slug)
    return slug

def escape_table_cell(text: str) -> str:
    if not text:
        return ""
    cleaned = re.sub(r'[\r\n]+', ' ', str(text)).strip()
    return re.sub(r'(?<!\\)\|', r'\|', cleaned)

# Manual dictionary of well-documented properties for MyGUI classes
KNOWN_PROPERTIES = {
    "Widget": [
        ("caption", "string", "RW", "w.caption = 'Title'"),
        ("visible", "boolean", "RW", "w.visible = true"),
        ("enabled", "boolean", "RW", "w.enabled = false"),
        ("alpha", "number", "RW", "w.alpha = 0.85"),
        ("align", "Align", "RW", "w.align = MyGUI.Align.Center"),
        ("position", "IntPoint", "RW", "w.position = MyGUI.IntPoint.new(100, 50)"),
        ("size", "IntSize", "RW", "w.size = MyGUI.IntSize.new(200, 100)"),
        ("coord", "IntCoord", "RW", "w.coord = MyGUI.IntCoord.new(10, 10, 300, 200)"),
        ("pointer", "string", "RW", "w.pointer = 'hand'"),
        ("depth", "integer", "RW", "w.depth = 10"),
        ("needKeyFocus", "boolean", "RW", "w.needKeyFocus = true"),
        ("needMouseFocus", "boolean", "RW", "w.needMouseFocus = true"),
        ("inheritsAlpha", "boolean", "RW", "w.inheritsAlpha = true"),
        ("inheritsPick", "boolean", "RW", "w.inheritsPick = false"),
        ("maskPick", "boolean", "RW", "w.maskPick = false"),
        ("widgetStyle", "WidgetStyle", "RW", "w.widgetStyle = MyGUI.WidgetStyle.Popup"),
        ("name", "string", "R", "local name = w.name"),
        ("type", "string", "R", "local typeName = w.type"),
        ("layerName", "string", "R", "local layer = w.layerName"),
        ("parent", "Widget", "R", "local parent = w.parent"),
        ("rootWidget", "Widget", "R", "local root = w.rootWidget"),
        ("childCount", "integer", "R", "local count = w.childCount"),
    ],
    "Button": [
        ("stateSelected", "boolean", "RW", "btn.stateSelected = true"),
        ("selected", "boolean", "RW", "btn.selected = true"),
    ],
    "TextBox": [
        ("caption", "string", "RW", "tb.caption = 'Hello World'"),
        ("text", "string", "RW", "tb.text = 'Hello World'"),
        ("textShadow", "boolean", "RW", "tb.textShadow = true"),
        ("textShadowColour", "Colour", "RW", "tb.textShadowColour = MyGUI.Colour.new(0, 0, 0, 1)"),
        ("textColour", "Colour", "RW", "tb.textColour = MyGUI.Colour.new(1, 1, 1, 1)"),
    ],
    "EditBox": [
        ("overflowToTheLeft", "boolean", "RW", "eb.overflowToTheLeft = false"),
        ("maxTextLength", "integer", "RW", "eb.maxTextLength = 128"),
        ("readOnly", "boolean", "RW", "eb.readOnly = true"),
        ("multiLine", "boolean", "RW", "eb.multiLine = true"),
        ("password", "boolean", "RW", "eb.password = false"),
        ("wordWrap", "boolean", "RW", "eb.wordWrap = true"),
        ("cursorPosition", "integer", "RW", "eb.cursorPosition = 0"),
    ],
    "Window": [
        ("autoAlpha", "boolean", "RW", "win.autoAlpha = true"),
        ("minSize", "IntSize", "RW", "win.minSize = MyGUI.IntSize.new(100, 100)"),
        ("maxSize", "IntSize", "RW", "win.maxSize = MyGUI.IntSize.new(800, 600)"),
    ],
    "ListBox": [
        ("itemCount", "integer", "R", "local count = lb.itemCount"),
        ("indexSelected", "integer", "RW", "lb.indexSelected = 0"),
    ],
    "ComboBox": [
        ("itemCount", "integer", "R", "local count = cb.itemCount"),
        ("indexSelected", "integer", "RW", "cb.indexSelected = 0"),
        ("comboModeDrop", "boolean", "RW", "cb.comboModeDrop = true"),
    ],
    "MultiListBox": [
        ("columnCount", "integer", "R", "local cols = mlb.columnCount"),
        ("itemCount", "integer", "R", "local items = mlb.itemCount"),
        ("indexSelected", "integer", "RW", "mlb.indexSelected = 0"),
    ],
    "ScrollBar": [
        ("scrollRange", "integer", "RW", "sb.scrollRange = 100"),
        ("scrollPosition", "integer", "RW", "sb.scrollPosition = 25"),
        ("scrollPage", "integer", "RW", "sb.scrollPage = 10"),
        ("viewPage", "integer", "RW", "sb.viewPage = 20"),
    ],
    "ProgressBar": [
        ("progressRange", "integer", "RW", "pb.progressRange = 100"),
        ("progressPosition", "integer", "RW", "pb.progressPosition = 50"),
        ("progressAutoTrack", "boolean", "RW", "pb.progressAutoTrack = true"),
        ("flowDirection", "FlowDirection", "RW", "pb.flowDirection = MyGUI.FlowDirection.LeftToRight"),
    ],
    "TabControl": [
        ("itemCount", "integer", "R", "local count = tc.itemCount"),
        ("indexSelected", "integer", "RW", "tc.indexSelected = 0"),
        ("buttonAutoWidth", "boolean", "RW", "tc.buttonAutoWidth = true"),
    ],
    "MenuItem": [
        ("itemId", "string", "RW", "mi.itemId = 'FILE_OPEN'"),
        ("itemType", "MenuItemType", "RW", "mi.itemType = MyGUI.MenuItemType.Normal"),
        ("itemIndex", "integer", "R", "local idx = mi.itemIndex"),
    ],
    "IntPoint": [
        ("left / x", "integer", "RW", "pt.left = 10 or pt.x = 10"),
        ("top / y", "integer", "RW", "pt.top = 20 or pt.y = 20"),
    ],
    "IntSize": [
        ("width / w", "integer", "RW", "sz.width = 100 or sz.w = 100"),
        ("height / h", "integer", "RW", "sz.height = 50 or sz.h = 50"),
    ],
    "IntCoord": [
        ("left / x", "integer", "RW", "coord.left = 10 or coord.x = 10"),
        ("top / y", "integer", "RW", "coord.top = 20 or coord.y = 20"),
        ("width / w", "integer", "RW", "coord.width = 100 or coord.w = 100"),
        ("height / h", "integer", "RW", "coord.height = 50 or coord.h = 50"),
        ("point", "IntPoint", "R", "local pt = coord.point"),
        ("size", "IntSize", "R", "local sz = coord.size"),
    ],
    "IntRect": [
        ("left", "integer", "RW", "rect.left = 0"),
        ("top", "integer", "RW", "rect.top = 0"),
        ("right", "integer", "RW", "rect.right = 100"),
        ("bottom", "integer", "RW", "rect.bottom = 100"),
        ("width", "integer", "R", "local w = rect.width"),
        ("height", "integer", "R", "local h = rect.height"),
    ],
    "FloatPoint": [
        ("left / x", "number", "RW", "pt.left = 0.1 or pt.x = 0.1"),
        ("top / y", "number", "RW", "pt.top = 0.2 or pt.y = 0.2"),
    ],
    "FloatSize": [
        ("width / w", "number", "RW", "sz.width = 0.5 or sz.w = 0.5"),
        ("height / h", "number", "RW", "sz.height = 0.3 or sz.h = 0.3"),
    ],
    "FloatCoord": [
        ("left / x", "number", "RW", "coord.left = 0.1 or coord.x = 0.1"),
        ("top / y", "number", "RW", "coord.top = 0.1 or coord.y = 0.1"),
        ("width / w", "number", "RW", "coord.width = 0.8 or coord.w = 0.8"),
        ("height / h", "number", "RW", "coord.height = 0.8 or coord.h = 0.8"),
    ],
    "FloatRect": [
        ("left", "number", "RW", "rect.left = 0.0"),
        ("top", "number", "RW", "rect.top = 0.0"),
        ("right", "number", "RW", "rect.right = 1.0"),
        ("bottom", "number", "RW", "rect.bottom = 1.0"),
        ("width", "number", "R", "local w = rect.width"),
        ("height", "number", "R", "local h = rect.height"),
    ],
    "Colour": [
        ("red / r", "number", "RW", "col.red = 1.0 or col.r = 1.0"),
        ("green / g", "number", "RW", "col.green = 0.5 or col.g = 0.5"),
        ("blue / b", "number", "RW", "col.blue = 0.0 or col.b = 0.0"),
        ("alpha / a", "number", "RW", "col.alpha = 1.0 or col.a = 1.0"),
    ],
}

def parse_global_methods(mygui_cpp_path: pathlib.Path):
    content = mygui_cpp_path.read_text(encoding='utf-8', errors='ignore')
    m = re.search(r"static const luaL_Reg globalMethods\[\]\s*=\s*\{(.*?)\};", content, re.DOTALL)
    methods = []
    if m:
        for line in m.group(1).splitlines():
            line = re.sub(r"//.*", "", line).strip()
            if line and line != "{ 0, 0 }" and not line.startswith('{ 0,'):
                mat = re.match(r"\{\s*\"([^\"]+)\"\s*,\s*([\w:]+)\s*\}", line.rstrip(','))
                if mat:
                    l_name, func = mat.group(1), mat.group(2)
                    b = find_function_body(content, func)
                    args = extract_args_from_body(b, is_static=True)
                    ret = extract_return_type_from_body(b)
                    methods.append((l_name, args, ret))
    return methods

def parse_global_enums(mygui_cpp_path: pathlib.Path):
    content = mygui_cpp_path.read_text(encoding='utf-8', errors='ignore')
    enums = {}
    for block in re.finditer(r"lua_newtable\(L\);(.*?)lua_setfield\(L,\s*-2,\s*\"([^\"]+)\"\);", content, re.DOTALL):
        tbody = block.group(1)
        ename = block.group(2)
        vals = []
        for m in re.finditer(r"lua_pushinteger\(L,\s*\(int\)(?:MyGUI::)?([^)]+)\);\s*lua_setfield\(L,\s*-2,\s*\"([^\"]+)\"\);", tbody):
            c_val = m.group(1).strip()
            f_name = m.group(2).strip()
            vals.append((f_name, c_val))
        if vals:
            enums[ename] = vals
    return enums

def parse_mygui_class_file(cpp_path: pathlib.Path):
    content = cpp_path.read_text(encoding='utf-8', errors='ignore')
    stem = cpp_path.stem
    class_name = stem.replace("Binding", "")
    
    # Check header
    header_path = f"src/Bindings/MyGUI/{stem}.h"
    h_file = cpp_path.with_suffix('.h')
    h_content = h_file.read_text(encoding='utf-8', errors='ignore') if h_file.is_file() else ""
    
    meta_m = re.search(r'getMetatableName\(\)\s*\{?\s*return\s*\"([^\"]+)\"', h_content + '\n' + content)
    metatable = meta_m.group(1) if meta_m else f"KenshiLua.MyGUI.{class_name}"
    
    parent_m = re.search(r'setMetatableParent\s*\(\s*L\s*,\s*[^,]+,\s*(\w+Binding)::getMetatableName', content)
    parent_class = parent_m.group(1).replace("Binding", "") if parent_m else None
    
    methods = []
    static_methods = []
    
    # Extract methods array
    m = re.search(r"static const luaL_Reg methods\[\]\s*=\s*\{(.*?)\};", content, re.DOTALL)
    if m:
        for line in m.group(1).splitlines():
            line = re.sub(r"//.*", "", line).strip()
            if line and line != "{ 0, 0 }" and not line.startswith('{ 0,'):
                mat = re.match(r"\{\s*\"([^\"]+)\"\s*,\s*([\w:]+)\s*\}", line.rstrip(','))
                if mat:
                    l_name, func = mat.group(1), mat.group(2)
                    func_short = func.split('::')[-1]
                    b = find_function_body(content, func)
                    if not b:
                        b = find_function_body(content, stem + "::" + func_short)
                    if not b:
                        b = find_function_body(content, func_short)
                        
                    is_stat = l_name in ("getInstance", "new", "parse")
                    args = extract_args_from_body(b, is_static=is_stat)
                    ret = extract_return_type_from_body(b)
                    
                    if is_stat:
                        static_methods.append({
                            "lua_name": l_name,
                            "args": args,
                            "ret_type": ret
                        })
                    else:
                        methods.append({
                            "lua_name": l_name,
                            "args": args,
                            "ret_type": ret
                        })
                        
    fields = KNOWN_PROPERTIES.get(class_name, [])
    field_list = []
    for f in fields:
        field_list.append({
            "lua_name": f[0],
            "type": f[1],
            "rw": f[2],
            "example": f[3]
        })
        
    return {
        "class_name": class_name,
        "metatable": metatable,
        "header": header_path,
        "parent_class": parent_class,
        "fields": field_list,
        "methods": methods,
        "static_methods": static_methods
    }

def parse_types_file(types_cpp_path: pathlib.Path):
    content = types_cpp_path.read_text(encoding='utf-8', errors='ignore')
    type_names = ["IntPoint", "IntSize", "IntCoord", "IntRect", "FloatPoint", "FloatSize", "FloatCoord", "FloatRect", "Colour"]
    type_classes = []
    
    for tname in type_names:
        metatable = f"KenshiLua.MyGUI.{tname}"
        fields = KNOWN_PROPERTIES.get(tname, [])
        field_list = [{"lua_name": f[0], "type": f[1], "rw": f[2], "example": f[3]} for f in fields]
        
        static_methods = []
        # Find new/parse
        new_body = find_function_body(content, f"{tname}_new")
        if new_body:
            args = extract_args_from_body(new_body, is_static=True)
            static_methods.append({
                "lua_name": "new",
                "args": args,
                "ret_type": tname
            })
        if tname == "Colour":
            parse_body = find_function_body(content, "Colour_parse")
            if parse_body:
                args = extract_args_from_body(parse_body, is_static=True)
                static_methods.append({
                    "lua_name": "parse",
                    "args": args,
                    "ret_type": "Colour"
                })
                
        type_classes.append({
            "class_name": tname,
            "metatable": metatable,
            "header": "src/Bindings/MyGUI/TypesBinding.h",
            "parent_class": None,
            "fields": field_list,
            "methods": [],
            "static_methods": static_methods
        })
    return type_classes

EVENT_CALLBACKS = [
    {
        "event": "OnClick",
        "aliases": ["OnClick", "click"],
        "widgets": "Button, MenuItem, Widget",
        "signature": "function(sender: Widget)",
        "description": "Triggered when the user clicks on the widget with the mouse."
    },
    {
        "event": "OnTextChanged",
        "aliases": ["EditTextChange", "editTextChange", "change"],
        "widgets": "EditBox, ComboBox",
        "signature": "function(sender: EditBox)",
        "description": "Triggered when the text content of an edit box is modified by the user or programmatically."
    },
    {
        "event": "OnWindowButtonPressed",
        "aliases": ["WindowButtonPressed", "windowButtonPressed"],
        "widgets": "Window",
        "signature": "function(sender: Window, buttonName: string)",
        "description": "Triggered when a window control button (e.g. close, minimize, maximize) is clicked."
    },
    {
        "event": "OnMouseButtonPressed",
        "aliases": ["MouseButtonPressed", "mouseButtonPressed", "mouseDown"],
        "widgets": "Widget",
        "signature": "function(sender: Widget, left: integer, top: integer, button: MouseButton)",
        "description": "Triggered when a mouse button is pressed down over the widget."
    },
    {
        "event": "OnMouseButtonReleased",
        "aliases": ["MouseButtonReleased", "mouseButtonReleased", "mouseUp"],
        "widgets": "Widget",
        "signature": "function(sender: Widget, left: integer, top: integer, button: MouseButton)",
        "description": "Triggered when a mouse button is released over the widget."
    },
    {
        "event": "OnMouseSetFocus",
        "aliases": ["MouseSetFocus", "mouseSetFocus", "mouseOver"],
        "widgets": "Widget",
        "signature": "function(sender: Widget, oldWidget: Widget)",
        "description": "Triggered when the mouse cursor enters the bounds of the widget."
    },
    {
        "event": "OnMouseLostFocus",
        "aliases": ["MouseLostFocus", "mouseLostFocus", "mouseOut"],
        "widgets": "Widget",
        "signature": "function(sender: Widget, newWidget: Widget)",
        "description": "Triggered when the mouse cursor leaves the bounds of the widget."
    },
    {
        "event": "OnMouseMove",
        "aliases": ["MouseMove", "mouseMove"],
        "widgets": "Widget",
        "signature": "function(sender: Widget, left: integer, top: integer)",
        "description": "Triggered continuously as the mouse moves across the widget surface."
    },
    {
        "event": "OnMouseWheel",
        "aliases": ["MouseWheel", "mouseWheel"],
        "widgets": "Widget",
        "signature": "function(sender: Widget, relValue: integer)",
        "description": "Triggered when the mouse scroll wheel is rotated while hovering over the widget."
    },
    {
        "event": "OnKeyButtonPressed",
        "aliases": ["KeyButtonPressed", "keyButtonPressed", "keyDown"],
        "widgets": "Widget",
        "signature": "function(sender: Widget, keyCode: KeyCode, charCode: integer)",
        "description": "Triggered when a keyboard key is pressed while the widget holds key focus."
    },
    {
        "event": "OnKeyButtonReleased",
        "aliases": ["KeyButtonReleased", "keyButtonReleased", "keyUp"],
        "widgets": "Widget",
        "signature": "function(sender: Widget, keyCode: KeyCode)",
        "description": "Triggered when a keyboard key is released while the widget holds key focus."
    },
    {
        "event": "OnComboAccept",
        "aliases": ["ComboAccept", "comboAccept"],
        "widgets": "ComboBox",
        "signature": "function(sender: ComboBox, index: integer)",
        "description": "Triggered when an item in the combo box drop list is confirmed/accepted."
    },
    {
        "event": "OnComboChangePosition",
        "aliases": ["ComboChangePosition", "comboChangePosition"],
        "widgets": "ComboBox",
        "signature": "function(sender: ComboBox, index: integer)",
        "description": "Triggered when the highlighted selection position changes in the combo box."
    },
    {
        "event": "OnListSelectAccept",
        "aliases": ["ListSelectAccept", "listSelectAccept"],
        "widgets": "ListBox",
        "signature": "function(sender: ListBox, index: integer)",
        "description": "Triggered when an item in the list box is double-clicked or confirmed with Enter."
    },
    {
        "event": "OnListChangePosition",
        "aliases": ["ListChangePosition", "listChangePosition"],
        "widgets": "ListBox",
        "signature": "function(sender: ListBox, index: integer)",
        "description": "Triggered when the selected item index changes in the list box."
    },
    {
        "event": "OnWindowChangeCoord",
        "aliases": ["WindowChangeCoord", "windowChangeCoord"],
        "widgets": "Window",
        "signature": "function(sender: Window)",
        "description": "Triggered when a window is moved or resized by the user."
    },
    {
        "event": "OnScrollChangePosition",
        "aliases": ["ScrollChangePosition", "scrollChangePosition"],
        "widgets": "ScrollBar",
        "signature": "function(sender: ScrollBar, position: integer)",
        "description": "Triggered when the scroll bar slider position changes."
    },
    {
        "event": "OnTabChangeSelect",
        "aliases": ["TabChangeSelect", "tabChangeSelect"],
        "widgets": "TabControl",
        "signature": "function(sender: TabControl, index: integer)",
        "description": "Triggered when the active tab sheet is changed in a tab control."
    },
    {
        "event": "OnMenuAccept",
        "aliases": ["MenuAccept", "menuAccept", "MenuCtrlAccept"],
        "widgets": "MenuControl, MenuBar, PopupMenu",
        "signature": "function(sender: MenuControl, item: MenuItem)",
        "description": "Triggered when an item in a menu bar or popup menu is activated/clicked."
    }
]

def generate_mygui_markdown(global_methods, global_enums, type_classes, widget_classes, manager_classes):
    lines = [
        "# MyGUI Lua API Reference",
        "",
        "## Overview",
        "",
        "The **MyGUI** subsystem in KenshiLua provides a comprehensive set of UI bindings for creating and managing game user interfaces. It offers:",
        "- **Global Factory & Utility Functions**: Convenient `MyGUI.createButton(...)`, `MyGUI.createWindow(...)`, `MyGUI.loadLayout(...)`, etc.",
        "- **Pixel & Relative Coordinates**: Precise integer pixel positioning or resolution-independent relative positioning (`0.0` to `1.0`).",
        "- **Rich Object-Oriented Widgets**: Full support for buttons, textboxes, editboxes, windows, scrollbars, listboxes, comboboxes, tab controls, menus, and canvases.",
        "- **Metatable Inheritance**: Child widgets inherit all base properties and methods from `MyGUI.Widget` (e.g. `setCaption`, `setPosition`, `setVisible`, `destroy`, `registerCallback`).",
        "- **Lifecycle Safety**: All widgets instantiated from Lua are tracked automatically and cleaned up upon script reload or shutdown.",
        "- **Event Callbacks**: Unified event registration via `widget:registerCallback(eventName, handler)` supporting clicks, text edits, drag/scroll, keys, and focus changes.",
        "",
        "For KenshiLib game engine class bindings, see the [KenshiLua Bindings Reference](BindingsReference.md).",
        "",
        "---",
        "",
        "## Table of Contents",
        "",
        "- [Global API (`MyGUI.*`)](#global-api-mygui)",
        "- [Core Types](#core-types)"
    ]

    for t in type_classes:
        lines.append(f"  - [`{t['class_name']}`](#{make_anchor(t['class_name'])})")

    lines.append("- [Base Widget Class](#base-widget-class)")
    lines.append("  - [`Widget`](#widget)")

    lines.append("- [Widget Classes](#widget-classes)")
    for w in sorted(widget_classes, key=lambda x: x['class_name']):
        if w['class_name'] != "Widget":
            lines.append(f"  - [`{w['class_name']}`](#{make_anchor(w['class_name'])})")

    lines.append("- [Managers (Singletons)](#managers-singletons)")
    for m in sorted(manager_classes, key=lambda x: x['class_name']):
        lines.append(f"  - [`{m['class_name']}`](#{make_anchor(m['class_name'])})")

    lines.append("- [Event Callbacks Reference](#event-callbacks-reference)")
    lines.append("- [Global Enums](#global-enums)")
    for e in sorted(global_enums.keys()):
        lines.append(f"  - [`MyGUI.{e}`](#{make_anchor('mygui' + e)})")

    lines.append("")
    lines.append("---")
    lines.append("")

    # Section 1: Global API
    lines.append("## Global API (`MyGUI.*`)")
    lines.append("")
    lines.append("These helper functions are available directly on the global `MyGUI` table.")
    lines.append("")
    lines.append("### Functions")
    lines.append("| Function | Parameters | Return Type | Description / Example |")
    lines.append("|---|---|---|---|")
    
    for name, args, ret in global_methods:
        args_str = ", ".join([f"{a['name']}: {a['type']}" for a in args])
        call_args = ", ".join([a['name'] for a in args])
        example = f"`MyGUI.{name}({call_args})`"
        fname = escape_table_cell(name)
        fargs = escape_table_cell(args_str)
        fret = escape_table_cell(ret)
        lines.append(f"| `{fname}` | `{fargs}` | `{fret}` | {example} |")
    lines.append("")

    # Section 2: Core Types
    lines.append("## Core Types")
    lines.append("")
    lines.append("Value structs used throughout MyGUI for coordinates, dimensions, bounds, and colors.")
    lines.append("")

    for t in type_classes:
        cname = t['class_name']
        lines.append(f"### {cname}")
        lines.append(f"**Metatable:** `{t['metatable']}`  ")
        lines.append(f"**Header:** `{t['header']}`")
        lines.append("")

        if t['fields']:
            lines.append("#### Properties")
            lines.append("| Property | Type | R/W | Example |")
            lines.append("|---|---|---|---|")
            for f in t['fields']:
                lines.append(f"| `{f['lua_name']}` | `{f['type']}` | {f['rw']} | `{f['example']}` |")
            lines.append("")

        if t['static_methods']:
            lines.append("#### Static Methods")
            lines.append("| Method | Arguments | Return Type | Example |")
            lines.append("|---|---|---|---|")
            for m in t['static_methods']:
                args_str = ", ".join([f"{a['name']}: {a['type']}" for a in m['args']])
                call_args = ", ".join([a['name'] for a in m['args']])
                example = f"`MyGUI.{cname}.{m['lua_name']}({call_args})`"
                lines.append(f"| `{m['lua_name']}` | `{args_str}` | `{m['ret_type']}` | {example} |")
            lines.append("")

    # Section 3: Base Widget Class
    lines.append("## Base Widget Class")
    lines.append("")
    widget_class = next(w for w in widget_classes if w['class_name'] == "Widget")
    lines.append(f"### {widget_class['class_name']}")
    lines.append(f"**Metatable:** `{widget_class['metatable']}`  ")
    lines.append(f"**Header:** `{widget_class['header']}`")
    lines.append("")
    lines.append("> [!NOTE]")
    lines.append("> All widget classes (Button, EditBox, Window, etc.) inherit all properties and methods from `MyGUI.Widget`.")
    lines.append("")

    if widget_class['fields']:
        lines.append("#### Properties")
        lines.append("| Property | Type | R/W | Example |")
        lines.append("|---|---|---|---|")
        for f in widget_class['fields']:
            lines.append(f"| `{f['lua_name']}` | `{f['type']}` | {f['rw']} | `{f['example']}` |")
        lines.append("")

    if widget_class['methods']:
        lines.append("#### Methods")
        lines.append("| Lua Name | Arguments | Return Type | Example |")
        lines.append("|---|---|---|---|")
        for m in widget_class['methods']:
            args_str = ", ".join([f"{a['name']}: {a['type']}" for a in m['args']])
            call_args = ", ".join([a['name'] for a in m['args']])
            example = f"`w:{m['lua_name']}({call_args})`"
            lines.append(f"| `{m['lua_name']}` | `{args_str}` | `{m['ret_type']}` | {example} |")
        lines.append("")

    # Section 4: Widget Classes
    lines.append("## Widget Classes")
    lines.append("")

    for w in sorted(widget_classes, key=lambda x: x['class_name']):
        if w['class_name'] == "Widget":
            continue
        cname = w['class_name']
        pname = w['parent_class']
        lines.append(f"### {cname}")
        lines.append(f"**Metatable:** `{w['metatable']}`  ")
        lines.append(f"**Header:** `{w['header']}`  ")
        if pname:
            lines.append(f"**Parent Class:** [`MyGUI.{pname}`](#{make_anchor(pname)}) *(inherits all methods and properties)*")
        lines.append("")

        if w['fields']:
            lines.append("#### Specific Properties")
            lines.append("| Property | Type | R/W | Example |")
            lines.append("|---|---|---|---|")
            for f in w['fields']:
                lines.append(f"| `{f['lua_name']}` | `{f['type']}` | {f['rw']} | `{f['example']}` |")
            lines.append("")

        if w['methods']:
            lines.append("#### Specific Methods")
            lines.append("| Lua Name | Arguments | Return Type | Example |")
            lines.append("|---|---|---|---|")
            for m in w['methods']:
                args_str = ", ".join([f"{a['name']}: {a['type']}" for a in m['args']])
                call_args = ", ".join([a['name'] for a in m['args']])
                example = f"`obj:{m['lua_name']}({call_args})`"
                lines.append(f"| `{m['lua_name']}` | `{args_str}` | `{m['ret_type']}` | {example} |")
            lines.append("")

    # Section 5: Managers
    lines.append("## Managers (Singletons)")
    lines.append("")
    lines.append("Managers provide global control over input, cursor pointer, skins, layout templates, clipboard, and rendering.")
    lines.append("")

    for m in sorted(manager_classes, key=lambda x: x['class_name']):
        cname = m['class_name']
        lines.append(f"### {cname}")
        lines.append(f"**Metatable:** `{m['metatable']}`  ")
        lines.append(f"**Header:** `{m['header']}`")
        lines.append("")

        if m['static_methods']:
            lines.append("#### Static Methods")
            lines.append("| Method | Arguments | Return Type | Example |")
            lines.append("|---|---|---|---|")
            for sm in m['static_methods']:
                args_str = ", ".join([f"{a['name']}: {a['type']}" for a in sm['args']])
                call_args = ", ".join([a['name'] for a in sm['args']])
                example = f"`MyGUI.{cname}.{sm['lua_name']}({call_args})`"
                lines.append(f"| `{sm['lua_name']}` | `{args_str}` | `{sm['ret_type']}` | {example} |")
            lines.append("")

        if m['methods']:
            lines.append("#### Methods")
            lines.append("| Lua Name | Arguments | Return Type | Example |")
            lines.append("|---|---|---|---|")
            for meth in m['methods']:
                args_str = ", ".join([f"{a['name']}: {a['type']}" for a in meth['args']])
                call_args = ", ".join([a['name'] for a in meth['args']])
                example = f"`mgr:{meth['lua_name']}({call_args})`"
                lines.append(f"| `{meth['lua_name']}` | `{args_str}` | `{meth['ret_type']}` | {example} |")
            lines.append("")

    # Section 6: Event Callbacks
    lines.append("## Event Callbacks Reference")
    lines.append("")
    lines.append("Event callbacks are attached to widgets using `widget:registerCallback(eventType, callbackFunction)`.")
    lines.append("")
    lines.append("### Usage Example")
    lines.append("```lua")
    lines.append("local btn = MyGUI.createButton(\"Click Me\", { left = 100, top = 100, width = 120, height = 30 })")
    lines.append("btn:registerCallback(\"OnClick\", function(sender)")
    lines.append("    print(\"Button clicked:\", sender.caption)")
    lines.append("end)")
    lines.append("```")
    lines.append("")
    lines.append("### Supported Event Types")
    lines.append("| Event Name | Accepted String Aliases | Target Widgets | Handler Signature | Description |")
    lines.append("|---|---|---|---|---|")

    for ev in EVENT_CALLBACKS:
        aliases = ", ".join([f"`\"{a}\"`" for a in ev['aliases']])
        lines.append(f"| **`{ev['event']}`** | {aliases} | `{ev['widgets']}` | `{ev['signature']}` | {ev['description']} |")
    lines.append("")

    # Section 7: Enums
    lines.append("## Global Enums")
    lines.append("")

    for ename in sorted(global_enums.keys()):
        lines.append(f"### MyGUI.{ename}")
        lines.append("| Enum Field | Underlying Value |")
        lines.append("|---|---|")
        for fname, val in global_enums[ename]:
            lines.append(f"| `MyGUI.{ename}.{fname}` | `{val}` |")
        lines.append("")

    return "\n".join(lines)

def main():
    mygui_cpp_path = MYGUI_DIR / "MyGUIBinding.cpp"
    types_cpp_path = MYGUI_DIR / "TypesBinding.cpp"
    
    global_methods = parse_global_methods(mygui_cpp_path)
    global_enums = parse_global_enums(mygui_cpp_path)
    type_classes = parse_types_file(types_cpp_path)
    
    widget_classes = []
    manager_classes = []
    
    manager_names = {"Gui", "InputManager", "PointerManager", "ClipboardManager", "LayoutManager", "RenderManager", "SkinManager"}
    
    for cpp in sorted(MYGUI_DIR.glob("*Binding.cpp")):
        if cpp.name in ("MyGUIBinding.cpp", "TypesBinding.cpp"):
            continue
        c_info = parse_mygui_class_file(cpp)
        if c_info['class_name'] in manager_names:
            manager_classes.append(c_info)
        else:
            widget_classes.append(c_info)
            
    md = generate_mygui_markdown(global_methods, global_enums, type_classes, widget_classes, manager_classes)
    out_path = DOCS_DIR / "MyGUIReference.md"
    out_path.write_text(md, encoding='utf-8')
    print(f"Generated {out_path} ({len(md)} bytes)")

if __name__ == "__main__":
    main()
