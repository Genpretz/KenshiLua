#!/usr/bin/env python3
import os
import re
import glob

def main():
    # Paths are relative to the script's grandparent directory (project root)
    script_dir = os.path.dirname(os.path.abspath(__file__))
    project_root = os.path.dirname(os.path.dirname(script_dir))
    bindings_dir = os.path.join(project_root, "src", "Bindings")
    output_file = os.path.join(project_root, "docs", "UnboundRefrence.md")
    enum_file = os.path.join(bindings_dir, "Kenshi", "EnumBinding.cpp")

    # 1. Discover all registered enums
    bound_enums = set()
    if os.path.exists(enum_file):
        with open(enum_file, 'r', encoding='utf-8', errors='ignore') as f:
            enum_content = f.read()
            for m in re.finditer(r'void\s+register(\w+)\s*\(lua_State\*', enum_content):
                bound_enums.add(m.group(1).lower())
            for m in re.finditer(r'setEnum\s*\(\s*L\s*,\s*"[^"]+"\s*,\s*([^:,\s\)]+)::', enum_content):
                bound_enums.add(m.group(1).lower())
            for m in re.finditer(r'setEnum\s*\(\s*L\s*,\s*"[^"]+"\s*,\s*\((\w+)\)', enum_content):
                bound_enums.add(m.group(1).lower())

    # 2. Discover all bound classes / metatables
    bound_classes = set()
    for root, dirs, files in os.walk(bindings_dir):
        for file in files:
            if file.endswith('.h') or file.endswith('.cpp'):
                p = os.path.join(root, file)
                with open(p, 'r', encoding='utf-8', errors='ignore') as f:
                    c = f.read()
                    for m in re.finditer(r'class\s+(\w+Binding)', c):
                        name = m.group(1)[:-7] if m.group(1).endswith('Binding') else m.group(1)
                        bound_classes.add(name.lower())
                    for m in re.finditer(r'struct\s+(\w+Binding)', c):
                        name = m.group(1)[:-7] if m.group(1).endswith('Binding') else m.group(1)
                        bound_classes.add(name.lower())
                    for m in re.finditer(r'getMetatableName\(\)\s*\{\s*return\s*"([^"]+)";', c):
                        raw_meta = m.group(1).replace('KenshiLua.', '')
                        bound_classes.add(raw_meta.lower())
                        bound_classes.add(raw_meta.split('::')[-1].lower())

    # 3. Standard / primitive types to ignore
    ignored_primitives = {
        'void', 'bool', 'BOOL', 'int', 'float', 'double', 'char', 'short', 'long', 'unsigned',
        'unsigned int', 'unsigned short', 'unsigned __int64', 'unsigned char', 'unsigned long',
        'std::string', 'string', 'ogre::vector2', 'vector2', 'ogre::vector3', 'vector3', 'ogre::vector4', 'vector4',
        'ogre::quaternion', 'quaternion', 'size_t',
        'int32_t', 'uint32_t', 'int64_t', 'uint64_t', 'char*', 'const char*', 'float&',
        'const float&', 'void*', 'operator', 'void operator', 'void*operator'
    }

    def is_type_already_bound(t):
        clean = t.replace('*', '').replace('&', '').strip()
        if clean.startswith('const '):
            clean = clean[6:].strip()
        lower_clean = clean.lower()
        if lower_clean in ignored_primitives or clean.lower() in ignored_primitives:
            return True
        if lower_clean in bound_enums or lower_clean in bound_classes:
            return True
        simple = lower_clean.split('::')[-1]
        if simple in bound_enums or simple in bound_classes:
            return True
        if lower_clean.startswith('lektor<') and lower_clean.endswith('>'):
            inner = lower_clean[7:-1].strip()
            return is_type_already_bound(inner)
        return False

    def split_args(args_text):
        args_text = args_text.strip()
        if not args_text or args_text == 'void':
            return []
        parts, current, depth = [], [], 0
        for ch in args_text:
            if ch == '<':
                depth += 1
            elif ch == '>':
                depth = max(0, depth - 1)
            elif ch == ',' and depth == 0:
                parts.append(''.join(current).strip())
                current = []
                continue
            current.append(ch)
        if current:
            parts.append(''.join(current).strip())
        return parts

    def normalize_type(t):
        t = re.sub(r'\s+', ' ', t.strip())
        t = t.replace(' &', '&').replace('& ', '&').replace(' *', '*').replace('* ', '*')
        return t

    def parse_arg(arg_text):
        arg_text = arg_text.split('=', 1)[0].strip()
        b = re.match(r'(.+?)([A-Za-z_]\w*)$', arg_text)
        if not b:
            return normalize_type(arg_text)
        type_text = normalize_type(b.group(1).strip())
        name = b.group(2)
        if name in ('const', 'volatile'):
            return normalize_type(arg_text)
        return type_text

    kenshilib_dir = os.path.join(project_root, "extern", "KenshiLib", "Include")
    header_file_map = {}
    if os.path.exists(kenshilib_dir):
        for root, dirs, files in os.walk(kenshilib_dir):
            for f in files:
                if f.endswith('.h'):
                    full_path = os.path.join(root, f)
                    rel_p = os.path.relpath(full_path, kenshilib_dir).replace('\\', '/').lower()
                    header_file_map[rel_p] = full_path
                    if f.lower() not in header_file_map:
                        header_file_map[f.lower()] = full_path

    header_cache = {}
    def get_header_lines(h_path):
        if h_path not in header_cache:
            try:
                with open(h_path, 'r', encoding='utf-8', errors='ignore') as hf:
                    header_cache[h_path] = hf.read().splitlines()
            except Exception:
                header_cache[h_path] = []
        return header_cache[h_path]

    unsupported_types = set()
    unsupported_properties = {}
    skipped_methods = []

    # Regex 1: // TODO: Unsupported type for <Field> (<Type>)
    prop_re = re.compile(r'//\s*TODO:\s*Unsupported type for\s+(\w+)\s+\(([^)]+)\)')

    # Regex 2: line <num>: <type> <method>(...) - <reason>
    method_re = re.compile(r'^\s*line\s+(\d+):\s+(.+?)\s+(\w+)\(.*?\)\s+-\s+(.*)$')

    # Recursively find and process all .cpp files
    for root, dirs, files in os.walk(bindings_dir):
        for file in files:
            if file.endswith('.cpp'):
                file_path = os.path.join(root, file)
                rel_path = os.path.relpath(file_path, bindings_dir).replace('\\', '/')
                
                try:
                    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                        file_content = f.read()
                        lines = file_content.splitlines()

                        # Collect all implemented methods and static methods
                        defined_methods = set()
                        for m in re.finditer(r'int\s+\w+Binding::(\w+)\s*\(lua_State\*', file_content):
                            defined_methods.add(m.group(1))
                        for m in re.finditer(r'registerStaticMethod\s*\(\s*L\s*,\s*"(\w+)"\s*,\s*\w+Binding::(\w+)\s*\)', file_content):
                            defined_methods.add(m.group(1))
                            defined_methods.add(m.group(2))

                        # Identify header file for this binding
                        header_path = None
                        for inc_match in re.finditer(r'#include\s+["<](kenshi[/\\][^">]+)[">]', file_content, re.IGNORECASE):
                            inc_rel = inc_match.group(1).replace('\\', '/').lower()
                            if inc_rel in header_file_map:
                                header_path = header_file_map[inc_rel]
                                break
                            inc_base = os.path.basename(inc_rel)
                            if inc_base in header_file_map:
                                header_path = header_file_map[inc_base]
                                break
                        if not header_path:
                            base_name = os.path.basename(file_path)
                            if base_name.endswith('Binding.cpp'):
                                h_name = base_name[:-11].lower() + '.h'
                                if h_name in header_file_map:
                                    header_path = header_file_map[h_name]

                        for line in lines:
                            # 1. Search for unsupported properties
                            prop_match = prop_re.search(line)
                            if prop_match:
                                prop = prop_match.group(1)
                                t = prop_match.group(2).strip()
                                if not is_type_already_bound(t):
                                    unsupported_types.add(t)
                                    if t not in unsupported_properties:
                                        unsupported_properties[t] = []
                                    unsupported_properties[t].append(f"{rel_path} (Property: {prop})")
                            
                            # 2. Search for skipped methods in comment blocks
                            method_match = method_re.match(line)
                            if method_match:
                                line_num = int(method_match.group(1))
                                t = method_match.group(2).strip()
                                method = method_match.group(3).strip()
                                reason = method_match.group(4).strip()
                                
                                # Skip methods already implemented in code
                                if method not in defined_methods:
                                    unsupported_for_method = []
                                    if header_path:
                                        h_lines = get_header_lines(header_path)
                                        decl_idx = -1
                                        if 0 <= line_num - 1 < len(h_lines) and method in h_lines[line_num - 1]:
                                            decl_idx = line_num - 1
                                        else:
                                            w_start = max(0, line_num - 15)
                                            w_end = min(len(h_lines), line_num + 15)
                                            for idx in range(w_start, w_end):
                                                if re.search(r'\b' + re.escape(method) + r'\s*\(', h_lines[idx]):
                                                    decl_idx = idx
                                                    break
                                            if decl_idx == -1:
                                                for idx, hl in enumerate(h_lines):
                                                    if re.search(r'\b' + re.escape(method) + r'\s*\(', hl):
                                                        decl_idx = idx
                                                        break

                                        if decl_idx != -1:
                                            accum = []
                                            for idx in range(decl_idx, min(len(h_lines), decl_idx + 5)):
                                                accum.append(h_lines[idx].split('//')[0])
                                                if ')' in h_lines[idx]:
                                                    break
                                            target_decl = ' '.join(accum)

                                            m_args = re.search(r'\b' + re.escape(method) + r'\s*\((.*?)\)', target_decl)
                                            if m_args:
                                                raw_args = split_args(m_args.group(1))
                                                parsed_arg_types = [parse_arg(a) for a in raw_args]

                                                if reason.startswith("unsupported arg type"):
                                                    unsupported_args = [arg_t for arg_t in parsed_arg_types if not is_type_already_bound(arg_t)]
                                                    if unsupported_args:
                                                        reason = f"unsupported arg type ({', '.join(unsupported_args)})"
                                                        unsupported_for_method.extend(unsupported_args)
                                                    elif parsed_arg_types:
                                                        reason = f"unsupported arg type ({', '.join(parsed_arg_types)})"
                                                        unsupported_for_method.extend(parsed_arg_types)
                                                elif reason.startswith("non-string reference arg"):
                                                    ref_args = [arg_t for arg_t in parsed_arg_types if '&' in arg_t]
                                                    if ref_args:
                                                        reason = f"non-string reference arg ({', '.join(ref_args)})"
                                                        for r_t in ref_args:
                                                            if not is_type_already_bound(r_t):
                                                                unsupported_for_method.append(r_t)

                                    if reason.startswith("unsupported return type") and not is_type_already_bound(t):
                                        unsupported_types.add(t)
                                        unsupported_for_method.append(t)
                                    for u_t in unsupported_for_method:
                                        unsupported_types.add(u_t)

                                    skipped_methods.append({
                                        'File': rel_path,
                                        'Type': t,
                                        'Method': method,
                                        'Reason': reason,
                                        'UnsupportedTypes': unsupported_for_method
                                    })
                except Exception as e:
                    print(f"Error reading {file_path}: {e}")

    # Generate Markdown Report
    sorted_types = sorted(list(unsupported_types))

    md = []
    md.append("# Unbound Classes and Types Registry")
    md.append("")
    md.append("This document registers all C++ SDK classes and complex types that are currently unsupported, skipped, or fallback-mapped to `lightuserdata` or placeholders within the Lua bindings.")
    md.append("")
    md.append("*(Automatically generated by `tools/audit/generate_unbound_reference.py`)*")
    md.append("")
    md.append("## Summary of Unique Unbound/Unsupported Types")
    md.append("")
    md.append("| Raw C++ Type | Occurrence Count |")
    md.append("| :--- | :--- |")

    for t in sorted_types:
        # Count occurrences
        count = 0
        if t in unsupported_properties:
            count += len(unsupported_properties[t])
        
        # Count in skipped methods: match t exactly or strip * and &
        stripped_t = t.replace('*', '').replace('&', '').strip()
        for m in skipped_methods:
            m_t = m['Type']
            m_stripped = m_t.replace('*', '').replace('&', '').strip()
            matched = (m_t == t or m_stripped == stripped_t)
            for u_t in m.get('UnsupportedTypes', []):
                u_stripped = u_t.replace('*', '').replace('&', '').strip()
                if u_t == t or u_stripped == stripped_t or u_t == stripped_t:
                    matched = True
                    break
            if matched:
                count += 1
        
        md.append(f"| `{t}` | {count} |")

    md.append("")
    md.append("## Unsupported Properties Detail")
    md.append("")
    md.append("Below are properties in the bindings files that were implemented as read-only because they use unsupported types:")
    md.append("")
    md.append("| File | Type | Property Name |")
    md.append("| :--- | :--- | :--- |")

    for t in sorted_types:
        if t in unsupported_properties:
            for prop_occur in unsupported_properties[t]:
                match = re.match(r'^(.+?)\s+\(Property:\s+(.+?)\)$', prop_occur)
                if match:
                    file_name = match.group(1)
                    prop_name = match.group(2)
                    md.append(f"| {file_name} | `{t}` | {prop_name} |")

    md.append("")
    md.append("## Skipped Methods Detail")
    md.append("")
    md.append("Below are methods that were skipped during binding generation:")
    md.append("")
    md.append("| File | Method Name | Type / Return Type | Reason / Issue |")
    md.append("| :--- | :--- | :--- | :--- |")

    # Sort skipped methods by File, then by Method
    sorted_methods = sorted(skipped_methods, key=lambda x: (x['File'], x['Method']))
    for m in sorted_methods:
        md.append(f"| {m['File']} | {m['Method']} | `{m['Type']}` | {m['Reason']} |")

    # Write output file
    try:
        os.makedirs(os.path.dirname(output_file), exist_ok=True)
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write('\n'.join(md) + '\n')
        print(f"Registry successfully written to {output_file}")
    except Exception as e:
        print(f"Error writing output file {output_file}: {e}")

if __name__ == '__main__':
    main()
