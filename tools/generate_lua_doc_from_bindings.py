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

def strip_cpp_comments(text: str) -> str:
    """Strip C/C++ comments from text while preserving line structure."""
    text = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), text, flags=re.DOTALL)
    text = re.sub(r"//.*", "", text)
    return text

def defines_class_or_struct(text: str, target_name: str) -> bool:
    """Check if stripped C++ text contains a full definition of class or struct target_name (not a forward decl or enum)."""
    pattern = re.compile(
        r"(?:template\s*<[^>]*>\s*)?(?<!\benum\s)(?<!\benum\s\s)\b(?:class|struct)\s+(?:[A-Za-z_]\w*\s+)*"
        + re.escape(target_name)
        + r"(?:\s+final)?\s*(?::\s*[^{;]+)?\{",
        re.MULTILINE
    )
    return bool(pattern.search(text))

_HEADERS_CACHE = None

def get_headers_cache():
    global _HEADERS_CACHE
    if _HEADERS_CACHE is None:
        _HEADERS_CACHE = []
        if HEADERS_DIR.is_dir():
            for root, _, files in os.walk(HEADERS_DIR):
                for f in files:
                    if f.endswith(('.h', '.hpp')):
                        path = pathlib.Path(root) / f
                        try:
                            raw = path.read_text(encoding='utf-8', errors='ignore')
                            stripped = strip_cpp_comments(raw)
                            rel_path = os.path.relpath(path, PROJECT_ROOT).replace('\\', '/')
                            _HEADERS_CACHE.append((rel_path, stripped, f, raw))
                        except Exception:
                            continue
    return _HEADERS_CACHE

def header_matches_class(header_rel: str, class_name: str) -> bool:
    """Check if header_rel (e.g. kenshi/Building/FarmBuilding.h) defines class_name or its outer class."""
    full_path = PROJECT_ROOT / "extern" / "KenshiLib" / "Include" / header_rel
    if not full_path.is_file():
        full_path = PROJECT_ROOT / header_rel
    if not full_path.is_file():
        return False
    try:
        raw = full_path.read_text(encoding='utf-8', errors='ignore')
        stripped = strip_cpp_comments(raw)
    except Exception:
        return False

    if defines_class_or_struct(stripped, class_name):
        return True

    if "_" in class_name or "::" in class_name:
        parts = class_name.replace("::", "_").split("_")
        outer = parts[0]
        inner = parts[-1]
        if defines_class_or_struct(stripped, outer) and (defines_class_or_struct(stripped, inner) or defines_class_or_struct(stripped, f"{outer}::{inner}")):
            return True
        if defines_class_or_struct(stripped, outer):
            return True
    return False

def find_header_for_class(class_name: str) -> str:
    """Return relative path (extern/KenshiLib/Include/...) to the header declaring the given class/struct, or '???' if not found."""
    cache = get_headers_cache()

    # 1. Exact class/struct definition match
    exact_filename = f"{class_name}.h"
    for rel_path, stripped, fname, *_ in cache:
        if fname.lower() == exact_filename.lower():
            if defines_class_or_struct(stripped, class_name):
                return rel_path

    for rel_path, stripped, _, *_ in cache:
        if defines_class_or_struct(stripped, class_name):
            return rel_path

    # 2. Nested class resolution (e.g. FarmBuilding_Plant, Character_CarryMsg, CombatClass_AttackSlotManager_SlotData)
    candidates = []
    if "::" in class_name:
        parts = class_name.split("::")
        for i in range(1, len(parts)):
            outer = parts[i - 1]
            inner = parts[-1]
            candidates.append((outer, inner))
    if "_" in class_name:
        parts = class_name.split("_")
        for i in range(1, len(parts)):
            outer = "_".join(parts[:i])
            inner = "_".join(parts[i:])
            candidates.append((outer, inner))
            candidates.append((parts[0], parts[-1]))

    for outer, inner in candidates:
        outer_filename = f"{outer}.h"
        for rel_path, stripped, fname, *_ in cache:
            if fname.lower() == outer_filename.lower():
                if defines_class_or_struct(stripped, outer) and (defines_class_or_struct(stripped, inner) or defines_class_or_struct(stripped, f"{outer}::{inner}")):
                    return rel_path
        for rel_path, stripped, _, *_ in cache:
            if defines_class_or_struct(stripped, outer) and (defines_class_or_struct(stripped, inner) or defines_class_or_struct(stripped, f"{outer}::{inner}")):
                return rel_path

    for outer, inner in candidates:
        outer_filename = f"{outer}.h"
        for rel_path, stripped, fname, *_ in cache:
            if fname.lower() == outer_filename.lower() and defines_class_or_struct(stripped, outer):
                return rel_path

    for outer, inner in candidates:
        for rel_path, stripped, _, *_ in cache:
            if defines_class_or_struct(stripped, inner):
                return rel_path

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
    
    # Pattern A: readVector2/readVector3/readVector4/readQuaternion(L, idx, var)
    for m in re.finditer(r"\bread(Vector2|Vector3|Vector4|Quaternion)\s*\(\s*L\s*,\s*(\d+)\s*,\s*([\w_]+)\)", body):
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
    for m in re.finditer(r"\b(?:lua[lL]?_check(\w+)|lua[lL]?_to(\w+)|checkObject\s*<\s*([\w:*&\s<>]+)\s*>|readVector2|readVector3|readVector4|readQuaternion|handBinding::read)\b[^;]*?\(\s*L\s*,\s*(\d+)", body):
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
        
    if re.search(r"pushVector2\s*\(", body):
        return "Vector2"
    if re.search(r"pushVector3\s*\(", body):
        return "Vector3"
    if re.search(r"pushVector4\s*\(", body):
        return "Vector4"
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

def extract_class_body(header_text: str, target_class: str) -> str:
    """Extract the definition body {...} of target_class from stripped header text."""
    names_to_try = [target_class]
    if '::' in target_class:
        names_to_try.append(target_class.split('::')[-1])
    if '_' in target_class:
        names_to_try.append(target_class.split('_')[-1])
        
    for name in names_to_try:
        pattern = re.compile(
            r'(?:template\s*<[^>]*>\s*)?(?<!\benum\s)(?<!\benum\s\s)\b(?:class|struct)\s+(?:[A-Za-z_]\w*\s+)*'
            + re.escape(name)
            + r'(?:\s+final)?\s*(?::\s*[^{;]+)?\{',
            re.MULTILINE
        )
        for m in pattern.finditer(header_text):
            brace_start = m.end() - 1
            brace_count = 1
            i = brace_start + 1
            while i < len(header_text) and brace_count > 0:
                if header_text[i] == '{':
                    brace_count += 1
                elif header_text[i] == '}':
                    brace_count -= 1
                i += 1
            if brace_count == 0:
                return header_text[brace_start:i]
    return header_text

def clean_type(t: str) -> str:
    t = re.sub(r'^(?:public|protected|private)\s*:\s*', '', t.strip())
    t = re.sub(r'\b(?:virtual|static|inline|explicit)\b', '', t)
    t = re.sub(r'\s+', ' ', t).strip()
    t = re.sub(r'\bconst\s+', '', t)
    t = t.rstrip('&').rstrip('*').strip()
    type_map = {
        'std::string': 'string',
        'string': 'string',
        'int': 'integer',
        'unsigned int': 'integer',
        'unsigned __int64': 'integer',
        'size_t': 'integer',
        'short': 'integer',
        'float': 'number',
        'double': 'number',
        'bool': 'boolean',
        'Ogre::Vector2': 'Vector2',
        'Vector2': 'Vector2',
        'Ogre::Vector3': 'Vector3',
        'Vector3': 'Vector3',
        'Ogre::Vector4': 'Vector4',
        'Vector4': 'Vector4',
        'Ogre::Quaternion': 'Quaternion',
        'Quaternion': 'Quaternion',
        'hand': 'hand',
        'iVector2': 'iVector2',
    }
    return type_map.get(t, t)

def extract_header_methods_for_class(header_rel: str, target_class: str):
    if not header_rel or header_rel == "???":
        return {}
    full_path = PROJECT_ROOT / header_rel
    if not full_path.is_file():
        full_path = PROJECT_ROOT / "extern" / "KenshiLib" / "Include" / header_rel
    if not full_path.is_file():
        return {}
    
    try:
        text = full_path.read_text(encoding='utf-8', errors='ignore')
    except Exception:
        return {}
        
    text = strip_cpp_comments(text)
    class_body = extract_class_body(text, target_class)
    
    methods = {}
    pattern = re.compile(
        r'^[^\S\r\n]*(?:(?:public|protected|private)\s*:\s*)?(?:virtual[^\S\r\n]+)?(?:static[^\S\r\n]+)?([\w:<>*&]+(?:[^\S\r\n]+[\w:<>*&]+)*)[^\S\r\n]+([~a-zA-Z_]\w*)\s*\(([^)]*)\)\s*(?:const)?\s*(?:=\s*0)?\s*;',
        re.MULTILINE
    )
    for m in pattern.finditer(class_body):
        ret_type = m.group(1).strip()
        method_name = m.group(2).strip()
        args_raw = m.group(3).strip()
        
        if method_name.startswith('~') or method_name in ('_CONSTRUCTOR', '_DESTRUCTOR') or method_name == target_class or '_NV_' in method_name:
            continue
            
        args = []
        if args_raw and args_raw != 'void':
            raw_parts = []
            curr = []
            t_depth = 0
            for c in args_raw:
                if c == '<': t_depth += 1
                elif c == '>': t_depth -= 1
                elif c == ',' and t_depth == 0:
                    raw_parts.append("".join(curr).strip())
                    curr = []
                    continue
                curr.append(c)
            if curr:
                raw_parts.append("".join(curr).strip())
                
            for p in raw_parts:
                p = p.split('=')[0].strip()
                parts = p.split()
                if len(parts) >= 2:
                    arg_name = parts[-1].lstrip('*').lstrip('&')
                    arg_type = clean_type(" ".join(parts[:-1]))
                    args.append({'name': arg_name, 'type': arg_type})
                elif len(parts) == 1:
                    args.append({'name': 'arg', 'type': clean_type(parts[0])})
                    
        clean_ret = clean_type(ret_type)
        if method_name not in methods:
            methods[method_name] = []
        methods[method_name].append({'args': args, 'ret_type': clean_ret})
    return methods

def extract_overloads_from_body(body: str):
    """Extract multiple overload signatures from a method body with branching logic.
    
    Detects branching patterns:
    - lua_gettop(L) >= N  (argument count dispatch)
    - lua_isstring(L, N)  (type dispatch)
    - testObject<T>(L, N, ...) (type dispatch)
    
    Returns a list of overload dicts: [{'args': [...], 'ret_type': str}]
    If no branching is detected, returns an empty list (caller should use flat extraction).
    """
    if not body:
        return []
    
    # Check for branching patterns that indicate overloads
    has_gettop_branch = bool(re.search(r'lua_gettop\s*\(\s*L\s*\)\s*>=\s*\d+', body))
    has_type_branch = bool(re.search(r'(?:testObject\s*<|lua_isstring\s*\(\s*L)', body))
    
    if not has_gettop_branch and not has_type_branch:
        return []
    
    overloads = []
    
    # Strategy: find top-level if/else if/else blocks in the body and extract
    # args + return type from each branch independently.
    # We look for the pattern: if (...) { ... } else if (...) { ... } else { ... }
    # at the top level of the function body (depth 1 relative to function braces).
    
    # Find top-level branching blocks
    # We need to track brace depth. The body starts with '{' at position 0.
    branch_blocks = []
    
    # Search for if/else if/else patterns. We parse the body text to find
    # top-level (depth=1 relative to body) if-statements with overload dispatch conditions.
    inner = body[1:-1] if len(body) > 2 else body  # strip outer braces
    
    # Pattern: find if-blocks that contain overload dispatch conditions
    # We'll use a simpler approach: split by the top-level if/else structure
    
    # Find all top-level if/else-if conditions and their bodies
    pos = 0
    depth = 0
    blocks = []
    current_condition = None
    current_body_start = None
    
    while pos < len(inner):
        c = inner[pos]
        if c == '{':
            if depth == 0 and current_condition is not None:
                current_body_start = pos
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0 and current_body_start is not None:
                block_body = inner[current_body_start:pos+1]
                blocks.append((current_condition, block_body))
                current_condition = None
                current_body_start = None
                # Check for else if / else after this block
                rest = inner[pos+1:].lstrip()
                if rest.startswith('else'):
                    after_else = rest[4:].lstrip()
                    if after_else.startswith('if'):
                        # else if - find condition
                        cond_start = rest.find('if') + 2
                        actual_start = pos + 1 + (len(inner[pos+1:]) - len(rest)) + cond_start
                        # Find the condition in parentheses
                        paren_start = inner.find('(', actual_start)
                        if paren_start >= 0:
                            paren_depth = 0
                            paren_end = paren_start
                            for pi in range(paren_start, len(inner)):
                                if inner[pi] == '(':
                                    paren_depth += 1
                                elif inner[pi] == ')':
                                    paren_depth -= 1
                                    if paren_depth == 0:
                                        paren_end = pi
                                        break
                            current_condition = inner[paren_start+1:paren_end]
                            pos = paren_end + 1
                            continue
                    else:
                        # plain else block
                        current_condition = "else"
                        brace_pos = inner.find('{', pos + 1 + (len(inner[pos+1:]) - len(rest)) + 4)
                        if brace_pos >= 0:
                            pos = brace_pos
                            continue
        elif depth == 0 and current_condition is None:
            # Look for 'if' keyword at depth 0
            if inner[pos:pos+2] == 'if' and (pos == 0 or not inner[pos-1].isalnum()):
                # Check this is an overload-dispatch if
                paren_start = inner.find('(', pos + 2)
                if paren_start >= 0:
                    paren_depth = 0
                    paren_end = paren_start
                    for pi in range(paren_start, len(inner)):
                        if inner[pi] == '(':
                            paren_depth += 1
                        elif inner[pi] == ')':
                            paren_depth -= 1
                            if paren_depth == 0:
                                paren_end = pi
                                break
                    cond = inner[paren_start+1:paren_end]
                    # Only capture branches related to overload dispatch
                    if re.search(r'lua_gettop|testObject|lua_isstring|lua_isuserdata', cond):
                        current_condition = cond
                        pos = paren_end + 1
                        continue
        pos += 1
    
    if not blocks:
        return []
    
    # Now extract args and return type from each branch body
    for condition, block_body in blocks:
        branch_args = extract_args_from_body(block_body)
        branch_ret = extract_return_type_from_body(block_body)
        if branch_args or branch_ret != "void":
            overloads.append({'args': branch_args, 'ret_type': branch_ret})
    
    # If we only found one branch, also check the rest of the body for a fallback/else path
    if len(overloads) == 1 and len(blocks) == 1:
        # There might be code after the if-block that handles the other case
        # Extract args from the full body as a fallback but only if different
        full_args = extract_args_from_body(body)
        full_ret = extract_return_type_from_body(body)
        if full_args != overloads[0]['args']:
            overloads.append({'args': full_args, 'ret_type': full_ret})
    
    # Deduplicate overloads with identical args
    seen = []
    unique = []
    for ov in overloads:
        key = tuple((a['name'], a['type']) for a in ov['args']) + (ov['ret_type'],)
        if key not in seen:
            seen.append(key)
            unique.append(ov)
    
    return unique if len(unique) > 1 else []


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
        
        # Resolve header for class_name:
        # Step 1: Check corresponding *Binding.h file for #include ["<](kenshi[/\\][^">]+)[">]
        header = None
        candidate_h_files = [
            filepath.with_suffix('.h'),
            filepath.parent / f"{class_name}Binding.h",
            BINDINGS_DIR / f"{class_name}Binding.h",
        ]
        
        h_file = None
        for cand in candidate_h_files:
            if cand.is_file():
                h_file = cand
                break
        if not h_file:
            matching = list(BINDINGS_DIR.rglob(f"{class_name}Binding.h"))
            if matching:
                h_file = matching[0]

        if h_file and h_file.is_file():
            h_text = h_file.read_text(encoding='utf-8', errors='ignore')
            h_includes = re.findall(r'#\s*include\s+["<](kenshi[/\\][^">]+)[">]', h_text)
            if h_includes:
                for inc in h_includes:
                    rel_inc = inc.replace('\\', '/')
                    if header_matches_class(rel_inc, class_name):
                        header = f"extern/KenshiLib/Include/{rel_inc}"
                        break
                if not header:
                    rel_inc = h_includes[0].replace('\\', '/')
                    header = f"extern/KenshiLib/Include/{rel_inc}"

        # Step 2: Check .cpp file for #include ["<](kenshi[/\\][^">]+)[">]
        if not header:
            cpp_includes = re.findall(r'#\s*include\s+["<](kenshi[/\\][^">]+)[">]', content)
            if cpp_includes:
                for inc in cpp_includes:
                    rel_inc = inc.replace('\\', '/')
                    if header_matches_class(rel_inc, class_name):
                        header = f"extern/KenshiLib/Include/{rel_inc}"
                        break
                if not header:
                    for inc in cpp_includes:
                        rel_inc = inc.replace('\\', '/')
                        fname = pathlib.Path(rel_inc).name.lower()
                        if fname == f"{class_name.lower()}.h":
                            header = f"extern/KenshiLib/Include/{rel_inc}"
                            break
                        if "_" in class_name:
                            outer = class_name.split("_")[0]
                            if fname == f"{outer.lower()}.h":
                                header = f"extern/KenshiLib/Include/{rel_inc}"
                                break

        # Step 3: Fallback to find_header_for_class(class_name)
        if not header:
            header = find_header_for_class(class_name)

        # Resolve Metatable Name
        meta_m = re.search(r'getMetatableName\(\)\s*\{?\s*return\s*\"([^\"]+)\"', h_text)
        if not meta_m:
            meta_m = re.search(r'getMetatableName\(\)\s*\{?\s*return\s*\"([^\"]+)\"', content)
        metatable = meta_m.group(1) if meta_m else f"KenshiLua.{class_name}"

        # Resolve Display Name and Parent Class for nested types
        display_name = class_name
        parent_class = None

        typedefs = re.findall(r'typedef\s+([^;]+)\s+(\w+);', h_text + '\n' + content)
        get_m = re.search(r'static\s+([A-Za-z0-9_:<>\s]+)\s*\*\s*getInstance\s*\([^)]*\)\s*\{([^}]*)\}', content)
        inst_ret_type = get_m.group(1).strip() if get_m else ''
        inst_body = get_m.group(2) if get_m else ''
        chk_m = re.search(r'checkObject\s*<\s*([^>]+)\s*>', inst_body) if inst_body else None
        chk_type = chk_m.group(1).strip() if chk_m else inst_ret_type

        for src, alias in typedefs:
            src = src.strip()
            if '::' in src and not src.startswith('wraps::') and not src.startswith('MyGUI::'):
                if alias == class_name or alias == chk_type or alias == inst_ret_type:
                    display_name = src
                    break

        if display_name == class_name and '::' in chk_type and not chk_type.startswith('wraps::') and not chk_type.startswith('MyGUI::'):
            display_name = chk_type

        if display_name == class_name and '::' in inst_ret_type and not inst_ret_type.startswith('wraps::') and not inst_ret_type.startswith('MyGUI::'):
            display_name = inst_ret_type

        display_name = display_name.lstrip(':')
        display_name = re.sub(r'<[^>]*>', '', display_name)

        if '::' in display_name:
            parent_class = display_name.split('::')[0]
        elif '_' in class_name:
            parts = class_name.split("_")
            cache = get_headers_cache()
            for i in range(1, len(parts)):
                outer = "::".join(parts[:i])
                inner = "::".join(parts[i:])
                scoped = f"{outer}::{inner}"
                for _, stripped_hdr, _, raw_hdr in cache:
                    if re.search(r'\b(?:class|struct)\s+' + re.escape(parts[i-1]) + r'\b', raw_hdr) and re.search(r'\b(?:class|struct)\s+' + re.escape(parts[-1]) + r'\b', raw_hdr):
                        display_name = scoped
                        parent_class = parts[0]
                        break
                if parent_class:
                    break

        if parent_class:
            parent_class = parent_class.lstrip(':')
            parent_class = re.sub(r'<[^>]*>', '', parent_class)
            if parent_class == class_name or parent_class == display_name:
                parent_class = None
        
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
                    r"(?:lua_push(\w+)|(pushObject(?:T)?)(?:\s*<\s*[\w:*&\s<>]+>\s*)?|(pushVector2)|(pushVector3)|(pushVector4)|(pushQuaternion)|(handBinding::push))\s*\(\s*L\s*,\s*([^;)]+)", 
                    body
                )
                if push_match:
                    if push_match.group(1):
                        push_type = push_match.group(1).lower()
                    elif push_match.group(2):
                        template_match = re.search(r"pushObject(?:T)?\s*<\s*([\w:*&\s<>]+)\s*>", body)
                        push_type = template_match.group(1).strip() if template_match else "object"
                    elif push_match.group(3):
                        push_type = "Vector2"
                    elif push_match.group(4):
                        push_type = "Vector3"
                    elif push_match.group(5):
                        push_type = "Vector4"
                    elif push_match.group(6):
                        push_type = "Quaternion"
                    elif push_match.group(7):
                        push_type = "hand"
                        
                    expr = push_match.group(8).strip()
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
        # Detect static methods by scanning registerStaticMethod calls in registerBinding
        static_method_names = set()
        for sm_match in re.finditer(r'registerStaticMethod\s*\(\s*L\s*,\s*"([^"]+)"', register_body):
            static_method_names.add(sm_match.group(1))
        
        # Extract header methods for class to detect overloads
        header_methods = extract_header_methods_for_class(header, class_name)
        
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
                    if "_NV_" in lua_name or "_NV_" in func:
                        continue
                    method_name = func.split('::')[-1]
                    
                    body = find_function_body(content, func)
                    if not body:
                        body = find_function_body(content, cb + "::" + method_name)
                    if not body:
                        body = find_function_body(content, method_name)
                    
                    is_static = lua_name in static_method_names
                    
                    # Try to extract overload signatures from header first, then body
                    hdr_ovs = header_methods.get(lua_name, [])
                    body_ovs = extract_overloads_from_body(body)
                    
                    # Deduplicate header overloads (e.g. virtual vs non-virtual)
                    unique_hdr_ovs = []
                    seen_hdr = []
                    for ov in hdr_ovs:
                        key = tuple((a['name'], a['type']) for a in ov['args']) + (ov['ret_type'],)
                        if key not in seen_hdr:
                            seen_hdr.append(key)
                            unique_hdr_ovs.append(ov)
                    
                    if len(unique_hdr_ovs) > 1:
                        overloads = unique_hdr_ovs
                    elif len(body_ovs) > 1:
                        overloads = body_ovs
                    else:
                        overloads = []
                    
                    args = extract_args_from_body(body)
                    ret_type = extract_return_type_from_body(body)
                    methods.append({
                        "lua_name": lua_name,
                        "c_method": method_name,
                        "class": class_name,
                        "header": header,
                        "args": args,
                        "ret_type": ret_type,
                        "is_static": is_static,
                        "overloads": overloads
                    })
        classes.append((class_name, fields, methods, header, display_name, parent_class, metatable))
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

def make_anchor(name: str) -> str:
    slug = name.lower().replace(" ", "-")
    slug = re.sub(r'[^a-z0-9\-_:]', '', slug)
    return slug

def escape_table_cell(text: str) -> str:
    """Escape pipe characters and collapse newlines for markdown table cells."""
    if not text:
        return ""
    cleaned = re.sub(r'[\r\n]+', ' ', str(text)).strip()
    return re.sub(r'(?<!\\)\|', r'\|', cleaned)

def generate_markdown(data_by_class, enums):
    lines = [
        "# Lua Bindings Reference",
        "",
        "## Overview & Calling Conventions",
        "",
        "### Method Invocations",
        "- **Instance Methods**: Called on userdata instances using colon syntax: `instance:methodName(args)`.",
        "- **Static Class Methods**: Support dual invocation (both static table calls `ClassName.methodName(args)` and instance calls `instance:methodName(args)`).",
        "- **Overloaded Methods**: Methods supporting multiple argument counts or polymorphic parameter types are documented with explicit overload indexes (e.g. `[1]`, `[2]`), indicating each signature's parameter types and return type.",
        "",
        "## Table of Contents"
    ]
    
    cleaned_data = {}
    for cls, val in data_by_class.items():
        if cls in ("MyGui", "MyGUI"):
            cleaned_data["MyGUI"] = val
        else:
            cleaned_data[cls] = val
    if "MyGUI" not in cleaned_data:
        cleaned_data["MyGUI"] = ([], [], "", "MyGUI", None, None)

    # Separate top-level classes and nested classes
    top_level = []
    nested_by_parent = {}

    for cls, (fields, methods, header, display_name, parent_class, metatable) in cleaned_data.items():
        if parent_class and parent_class in cleaned_data and parent_class != cls:
            nested_by_parent.setdefault(parent_class, []).append(cls)
        else:
            top_level.append(cls)

    # Generate TOC
    for parent in sorted(top_level, key=lambda c: cleaned_data[c][3].lower()):
        p_fields, p_methods, p_header, p_disp, p_parent, p_meta = cleaned_data[parent]
        if parent == "MyGUI":
            lines.append("- [`MyGUI`](MyGUI_Bindings.md)")
        else:
            lines.append(f"- [`{p_disp}`](#{make_anchor(p_disp)})")
        
        if parent in nested_by_parent:
            for child in sorted(nested_by_parent[parent], key=lambda c: cleaned_data[c][3].lower()):
                c_fields, c_methods, c_header, c_disp, c_parent, c_meta = cleaned_data[child]
                lines.append(f"  - [`{c_disp}`](#{make_anchor(c_disp)})")

    if enums:
        lines.append("- [Enums](#enums)")
    lines.append("")

    # Generate Sections (order matches TOC)
    for parent in sorted(top_level, key=lambda c: cleaned_data[c][3].lower()):
        items_to_render = [parent]
        if parent in nested_by_parent:
            items_to_render.extend(sorted(nested_by_parent[parent], key=lambda c: cleaned_data[c][3].lower()))

        for item in items_to_render:
            if item == "MyGUI":
                lines.append("## MyGUI")
                lines.append("For full widget creation, layout loading, property access, and event handling reference, see the dedicated [MyGUI Bindings Documentation](MyGUI_Bindings.md).")
                lines.append("")
                continue

            fields, methods, header, display_name, parent_class, metatable = cleaned_data[item]
            lines.append(f"## {display_name}")
            lines.append(f"**Header:** `{header}`")
            if parent_class and parent_class in cleaned_data and parent_class != item:
                p_disp = cleaned_data[parent_class][3]
                lines.append(f"**Parent Class:** [`{p_disp}`](#{make_anchor(p_disp)})")
            if metatable:
                lines.append(f"**Metatable:** `{metatable}`")
            lines.append("")

            if fields:
                lines.append("### Fields")
                lines.append("| Lua Name | Type | R/W | Example |")
                lines.append("|---|---|---|---|")
                for f in fields:
                    example = f"obj.{f['lua_name']}" if f['rw'] == 'R' else f"obj.{f['lua_name']} = <value>"
                    fname = escape_table_cell(f['lua_name'])
                    ftype = escape_table_cell(f['type'])
                    lines.append(f"| {fname} | `{ftype}` | {f['rw']} | `{example}` |")
                lines.append("")

            if methods:
                lines.append("### Methods")
                lines.append("| Lua Name | Scope | Arguments | Return Type | Example |")
                lines.append("|---|---|---|---|---|")
                for m in methods:
                    is_static = m.get('is_static', False)
                    scope = "Static / Instance" if is_static else "Instance"
                    overloads = m.get('overloads', [])
                    if len(overloads) > 1:
                        for idx, ov in enumerate(overloads, 1):
                            name_display = f"{m['lua_name']} [{idx}]"
                            args_str = ", ".join([f"{a['name']}: {a['type']}" for a in ov['args']])
                            example_args = ", ".join([a['name'] for a in ov['args']])
                            if is_static:
                                example = f"`{display_name}.{m['lua_name']}({example_args})`<br>`obj:{m['lua_name']}({example_args})`"
                            else:
                                example = f"`obj:{m['lua_name']}({example_args})`"
                            mname = escape_table_cell(name_display)
                            margs = escape_table_cell(args_str)
                            mret = escape_table_cell(ov['ret_type'])
                            lines.append(f"| {mname} | {scope} | `{margs}` | `{mret}` | {example} |")
                    else:
                        args_str = ", ".join([f"{a['name']}: {a['type']}" for a in m['args']])
                        example_args = ", ".join([a['name'] for a in m['args']])
                        if is_static:
                            example = f"`{display_name}.{m['lua_name']}({example_args})`<br>`obj:{m['lua_name']}({example_args})`"
                        else:
                            example = f"`obj:{m['lua_name']}({example_args})`"
                        mname = escape_table_cell(m['lua_name'])
                        margs = escape_table_cell(args_str)
                        mret = escape_table_cell(m['ret_type'])
                        lines.append(f"| {mname} | {scope} | `{margs}` | `{mret}` | {example} |")
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
        for cls, fields, methods, header, display_name, parent_class, metatable in parsed_classes:
            data_by_class[cls] = (fields, methods, header, display_name, parent_class, metatable)
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
