# generate_lua_doc_from_bindings.py

"""Generate a markdown reference of all Lua bindings.

The script scans `src/Bindings/*.cpp` for field and method bindings,
extracts the C++ class names, header locations, read/write flags, and
creates usage examples. It also extracts enum bindings from files
ending with `EnumBinding.cpp`.

Output: `docs/BindingsReference.md`
"""

import os
import re
import pathlib

PROJECT_ROOT = pathlib.Path(__file__).resolve().parents[1]
BINDINGS_DIR = PROJECT_ROOT / "src" / "Bindings"
HEADERS_DIR = PROJECT_ROOT / "extern" / "KenshiLib" / "Include" / "kenshi"
DOCS_DIR = PROJECT_ROOT / "docs"
DOCS_DIR.mkdir(parents=True, exist_ok=True)

def find_header_for_class(class_name: str) -> str:
    """Return relative path to the header declaring the given class, or '???' if not found."""
    for root, _, files in os.walk(HEADERS_DIR):
        for f in files:
            if f.endswith('.h') or f.endswith('.hpp'):
                path = pathlib.Path(root) / f
                try:
                    text = path.read_text(encoding='utf-8', errors='ignore')
                except Exception:
                    continue
                if re.search(r"\bclass\s+" + re.escape(class_name) + r"\b", text):
                    return os.path.relpath(path, PROJECT_ROOT).replace('\\', '/')
    return "???"

def find_function_body(content, marker):
    """Find function body enclosed in braces starting from marker."""
    idx = 0
    while True:
        idx = content.find(marker, idx)
        if idx == -1:
            return ""
        # Check that it's not a substring of a longer identifier
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

def extract_args_from_body(body: str):
    """Extract argument names and types from a C++ function body by analyzing stack index checks.
    Returns list of dicts: [{'name': 'var', 'type': 'type', 'index': idx}]
    """
    if not body:
        return []
    indices = {}
    
    # Pattern A: readVector3/readQuaternion(L, idx, var)
    for m in re.finditer(r"\bread(Vector3|Quaternion)\s*\(\s*L\s*,\s*(\d+)\s*,\s*([\w_]+)\)", body):
        type_name = m.group(1)
        idx = int(m.group(2))
        var = m.group(3)
        if idx >= 2:
            indices[idx] = {"name": var, "type": type_name}
            
    # Pattern B: var = ...checkObject/luaL_check...(L, idx)
    for m in re.finditer(r"\b([\w_]+)\s*=\s*[^;]*?\b(?:lua[lL]?_check(\w+)|lua[lL]?_to(\w+)|checkObject\s*<\s*([\w:*&\s<>]+)\s*>|handBinding::read)\b[^;]*?\(\s*L\s*,\s*(\d+)", body):
        var = m.group(1)
        check_type = m.group(2) or m.group(3)
        check_obj_type = m.group(4)
        idx = int(m.group(5))
        
        if idx >= 2:
            if check_obj_type:
                t = check_obj_type.strip()
            elif check_type:
                t = check_type.lower()
                if t == "integer":
                    t = "integer"
                elif t == "number":
                    t = "number"
                elif t == "string":
                    t = "string"
                elif t == "boolean":
                    t = "boolean"
            else:
                t = "hand"
            indices[idx] = {"name": var, "type": t}
            
    # Pattern C: catch any other L usage with indices to know the max index
    for m in re.finditer(r"\b(?:lua[lL]?_check(\w+)|lua[lL]?_to(\w+)|checkObject\s*<\s*([\w:*&\s<>]+)\s*>|readVector3|readQuaternion|handBinding::read)\b[^;]*?\(\s*L\s*,\s*(\d+)", body):
        check_type = m.group(1) or m.group(2)
        check_obj_type = m.group(3)
        idx = int(m.group(4))
        
        if idx >= 2 and idx not in indices:
            if check_obj_type:
                t = check_obj_type.strip()
            elif check_type:
                t = check_type.lower()
            else:
                t = "unknown"
            indices[idx] = {"name": f"arg{idx - 1}", "type": t}
            
    sorted_args = []
    for idx in sorted(indices.keys()):
        sorted_args.append(indices[idx])
        
    return sorted_args

def extract_return_type_from_body(body: str) -> str:
    """Extract returned type from a C++ function body by analyzing return/push statements."""
    if not body:
        return "void"
        
    m = re.search(r"return\s+pushObject(?:T)?\s*<\s*([\w:*&\s<>]+)\s*>\s*\(", body)
    if m:
        return m.group(1).strip()
        
    if re.search(r"return\s+handBinding::push\s*\(", body) or re.search(r"handBinding::push\s*\(.*?\);\s*return\s+\d+", body):
        return "hand"
        
    m = re.search(r"pushObject(?:T)?\s*<\s*([\w:*&\s<>]+)\s*>\s*\(.*?\);\s*return\s+\d+", body)
    if m:
        return m.group(1).strip()
        
    if re.search(r"pushVector3\s*\(", body):
        return "Vector3"
    if re.search(r"pushQuaternion\s*\(", body):
        return "Quaternion"
        
    pushes = set()
    for m in re.finditer(r"lua_push(\w+)\s*\(", body):
        ptype = m.group(1).lower()
        if ptype != "nil":
            if ptype == "integer":
                pushes.add("integer")
            elif ptype == "number":
                pushes.add("number")
            elif ptype == "boolean":
                pushes.add("boolean")
            elif ptype == "string":
                pushes.add("string")
            elif ptype == "lightuserdata":
                var_match = re.search(r"lua_pushlightuserdata\s*\(\s*L\s*,\s*([^)]+)\)", body)
                if var_match:
                    var_name = var_match.group(1).strip()
                    decl_match = re.search(r"\b([\w_:]+)\s*\*\s+" + re.escape(var_name) + r"\b", body)
                    if decl_match:
                        pushes.add(decl_match.group(1).strip() + "*")
                    else:
                        pushes.add("lightuserdata")
                else:
                    pushes.add("lightuserdata")
                    
    if "lightuserdata" in pushes and len(pushes) > 1:
        pushes.remove("lightuserdata")
        
    if pushes:
        return "|".join(sorted(list(pushes)))
        
    if "return 0;" in body and not pushes:
        return "void"
        
    return "void"

def parse_binding_file(filepath: pathlib.Path):
    """Parse a single binding cpp file and return a list of tuples (class_name, fields, methods)."""
    content = filepath.read_text(encoding='utf-8', errors='ignore')
    
    class_bindings = re.findall(r"\bvoid\s+(\w+Binding)::registerBinding\b", content)
    if not class_bindings:
        class_name_match = re.search(r"class\s+(\w+)Binding", filepath.name)
        class_name = class_name_match.group(1) if class_name_match else filepath.stem.replace('Binding', '')
        class_bindings = [class_name + "Binding"]

    classes = []
    for cb in class_bindings:
        class_name = cb.replace('Binding', '')
        
        # Try to find header directly from #include in the file
        header_match = re.search(r'#\s*include\s+["<](kenshi[/\\][^">]+)[">]', content)
        if header_match:
            rel_header = header_match.group(1).replace('\\', '/')
            header = f"extern/KenshiLib/Include/{rel_header}"
        else:
            header = find_header_for_class(class_name)
        
        index_body = find_function_body(content, cb + "::index")
        newindex_body = find_function_body(content, cb + "::newindex")
        register_body = find_function_body(content, cb + "::registerBinding")
        
        fields = []
        # Support the new getter/setter system
        getters = re.findall(r"\bstatic\s+int\s+" + re.escape(class_name) + r"_get_(\w+)\s*\(\s*lua_State\s*\*\s*\w*\s*\)", content)
        for lua_name in getters:
            marker = f"{class_name}_get_{lua_name}"
            body = find_function_body(content, marker)
            
            member = lua_name
            push_type = "unknown"
            
            if body:
                push_match = re.search(
                    r"(?:lua_push(\w+)|(pushObject(?:T)?)(?:\s*<\s*[\w:*&\s<>]+>\s*)?|(pushVector3)|(pushQuaternion)|(handBinding::push))\s*\(\s*L\s*,\s*([^;)]+)", 
                    body
                )
                if push_match:
                    if push_match.group(1):
                        push_type = push_match.group(1).lower()
                    elif push_match.group(2):
                        template_match = re.search(r"pushObject(?:T)?\s*<\s*([\w:*&\s<>]+)\s*>", body)
                        push_type = template_match.group(1).strip() if template_match else "object"
                    elif push_match.group(3):
                        push_type = "Vector3"
                    elif push_match.group(4):
                        push_type = "Quaternion"
                    elif push_match.group(5):
                        push_type = "hand"
                        
                    expr = push_match.group(6).strip()
                    member_match = re.search(r"\w+\s*->\s*([\w_]+)", expr)
                    if member_match:
                        member = member_match.group(1)
                    else:
                        member = expr
                        
            if push_type == "unknown" and body:
                unsupported_match = re.search(r"Unsupported type for\s+\w+\s+\(([^)]+)\)", body)
                if unsupported_match:
                    push_type = unsupported_match.group(1).strip()
            
            setter_exists = False
            setter_name = f"{class_name}_set_{lua_name}"
            if setter_name in content:
                setter_body = find_function_body(content, setter_name)
                setter_body_lower = setter_body.lower()
                if "read-only" in setter_body_lower or "read only" in setter_body_lower or "unsupported setter" in setter_body_lower:
                    setter_exists = False
                else:
                    setter_exists = True
            rw = "RW" if setter_exists else "R"
            fields.append({"lua_name": lua_name, "member": member, "type": push_type, "rw": rw, "class": class_name, "header": header})
            
        # Fallback to the old strcmp system if no fields were found
        if not fields:
            index_body = find_function_body(content, cb + "::index")
            newindex_body = find_function_body(content, cb + "::newindex")
            
            for m in re.finditer(r"if\s*\(\s*strcmp\(key,\s*\"([^\"]+)\"\)\s*==\s*0\s*\)\s*{[^}]*?lua_push(\w+)\(L,\s*([^;]+)\);", index_body, re.DOTALL):
                lua_name = m.group(1)
                push_type = m.group(2).lower()
                expr = m.group(3).strip()
                member_match = re.search(r"[a-zA-Z_]\w*->([\w_]+)", expr)
                member = member_match.group(1) if member_match else expr
                fields.append({"lua_name": lua_name, "member": member, "type": push_type, "rw": "R", "class": class_name, "header": header})
            for m in re.finditer(r"if\s*\(\s*strcmp\(key,\s*\"([^\"]+)\"\)\s*==\s*0\s*\)\s*{[^}]*?[a-zA-Z_]\w*->([\w_]+)\s*=\s*[^;]+;", newindex_body, re.DOTALL):
                lua_name = m.group(1)
                member = m.group(2)
                for f in fields:
                    if f["lua_name"] == lua_name and f["member"] == member:
                        f["rw"] = "RW"
                        break
                else:
                    fields.append({"lua_name": lua_name, "member": member, "type": "unknown", "rw": "W", "class": class_name, "header": header})
        
        methods = []
        methods_section = re.search(r"static const luaL_Reg methods\[\]\s*=\s*\{(.*?)\};", register_body, re.DOTALL)
        if methods_section:
            content_block = methods_section.group(1)
            clean_lines = []
            for line in content_block.splitlines():
                line = re.sub(r"//.*", "", line).strip()
                if line and line != "{NULL, NULL}":
                    clean_lines.append(line)
            for line in clean_lines:
                m = re.match(r"\{\s*\"([^\"]+)\"\s*,\s*([\w:]+)\s*\}", line.rstrip(','))
                if m:
                    lua_name, func = m.group(1), m.group(2)
                    method_name = func.split('::')[-1]
                    
                    body = find_function_body(content, func)
                    if not body:
                        body = find_function_body(content, cb + "::" + method_name)
                    if not body:
                        body = find_function_body(content, method_name)
                        
                    args = extract_args_from_body(body)
                    ret_type = extract_return_type_from_body(body)
                    methods.append({"lua_name": lua_name, "c_method": method_name, "class": class_name, "header": header, "args": args, "ret_type": ret_type})
        classes.append((class_name, fields, methods, header))
    return classes

def parse_enum_file(filepath: pathlib.Path):
    """Parse enum binding cpp file to extract enum names and their values."""
    content = filepath.read_text(encoding='utf-8', errors='ignore')
    file_enums = {}
    for block_match in re.finditer(r"lua_newtable\(L\);(.*?)lua_setglobal\(L,\s*\"([^\"]+)\"\);", content, re.DOTALL):
        block_body = block_match.group(1)
        enum_name = block_match.group(2)
        values = []
        for m in re.finditer(r"lua_pushinteger\(L,\s*([^)]+)\);\s*lua_setfield\(L, -2,\s*\"([^\"]+)\"\);", block_body):
            val_expr = m.group(1).strip()
            field_name = m.group(2)
            values.append((field_name, val_expr))
        if values:
            file_enums[enum_name] = values
    return file_enums

def generate_markdown(data_by_class, enums):
    lines = ["# Lua Bindings Reference", "", "## Table of Contents"]
    for cls in sorted(data_by_class.keys()):
        lines.append(f"- [{cls}](#{cls.lower()})")
    if enums:
        lines.append("- [Enums](#enums)")
    lines.append("")
    for cls, (fields, methods, header) in sorted(data_by_class.items()):
        lines.append(f"## {cls}")
        lines.append(f"**Header:** `{header}`")
        lines.append("")
        if fields:
            lines.append("### Fields")
            lines.append("| Lua Name | C++ Member | Type | R/W | Example |")
            lines.append("|---|---|---|---|---|")
            for f in fields:
                example = f"obj.{f['lua_name']}" if f['rw'] == 'R' else f"obj.{f['lua_name']} = <value>"
                lines.append(f"| {f['lua_name']} | {f['member']} | {f['type']} | {f['rw']} | `{example}` |")
            lines.append("")
        if methods:
            lines.append("### Methods")
            lines.append("| Lua Name | C++ Method | Arguments | Return Type | Example |")
            lines.append("|---|---|---|---|---|")
            for m in methods:
                args_str = ", ".join([f"{a['name']}: {a['type']}" for a in m['args']])
                example_args = ", ".join([a['name'] for a in m['args']])
                example = f"obj:{m['lua_name']}({example_args})"
                lines.append(f"| {m['lua_name']} | {m['c_method']} | `{args_str}` | `{m['ret_type']}` | `{example}` |")
            lines.append("")
    if enums:
        lines.append("## Enums")
        lines.append("")
        for enum_name, values in enums.items():
            lines.append(f"### {enum_name}")
            lines.append("| Name | Value |")
            lines.append("|---|---|")
            for name, val in values:
                lines.append(f"| {name} | {val} |")
            lines.append("")
    return "\n".join(lines)

def main():
    data_by_class = {}
    for path in BINDINGS_DIR.rglob('*.cpp'):
        if path.name.endswith('EnumBinding.cpp'):
            continue
        parsed_classes = parse_binding_file(path)
        for cls, fields, methods, header in parsed_classes:
            data_by_class[cls] = (fields, methods, header)
    enums = {}
    for path in BINDINGS_DIR.rglob('*.cpp'):
        if path.name.endswith('EnumBinding.cpp'):
            file_enums = parse_enum_file(path)
            enums.update(file_enums)
    md = generate_markdown(data_by_class, enums)
    out_path = DOCS_DIR / "BindingsReference.md"
    out_path.write_text(md, encoding='utf-8')
    print(f"Generated {out_path}")

if __name__ == "__main__":
    main()
