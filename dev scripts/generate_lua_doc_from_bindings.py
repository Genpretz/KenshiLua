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
            
            setter_exists = f"{class_name}_set_{lua_name}" in content
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
                    methods.append({"lua_name": lua_name, "c_method": method_name, "class": class_name, "header": header})
        classes.append((class_name, fields, methods))
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
            lines.append("| Lua Name | C++ Method | Example |")
            lines.append("|---|---|---|")
            for m in methods:
                lines.append(f"| {m['lua_name']} | {m['c_method']} | `obj:{m['lua_name']}(...)` |")
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
    for entry in os.listdir(BINDINGS_DIR):
        if not entry.endswith('.cpp') or entry.endswith('EnumBinding.cpp'):
            continue
        path = BINDINGS_DIR / entry
        parsed_classes = parse_binding_file(path)
        for cls, fields, methods in parsed_classes:
            header = find_header_for_class(cls)
            data_by_class[cls] = (fields, methods, header)
    enums = {}
    for entry in os.listdir(BINDINGS_DIR):
        if entry.endswith('EnumBinding.cpp'):
            path = BINDINGS_DIR / entry
            file_enums = parse_enum_file(path)
            enums.update(file_enums)
    md = generate_markdown(data_by_class, enums)
    out_path = DOCS_DIR / "BindingsReference.md"
    out_path.write_text(md, encoding='utf-8')
    print(f"Generated {out_path}")

if __name__ == "__main__":
    main()
