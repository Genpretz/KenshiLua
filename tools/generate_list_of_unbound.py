#!/usr/bin/env python3
import os
import re
import glob

def main():
    # Paths are relative to the script's grandparent directory (project root)
    script_dir = os.path.dirname(os.path.abspath(__file__))
    project_root = os.path.dirname(script_dir)
    bindings_dir = os.path.join(project_root, "src", "Bindings")
    output_file = os.path.join(project_root, "docs", "UnboundRefrence.md")
    enum_file = os.path.join(bindings_dir, "EnumBinding.cpp")

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
        'void', 'bool', 'int', 'float', 'double', 'char', 'short', 'long', 'unsigned',
        'unsigned int', 'unsigned short', 'unsigned __int64', 'unsigned char', 'unsigned long',
        'std::string', 'ogre::vector2', 'vector2', 'ogre::vector3', 'vector3', 'ogre::vector4', 'vector4',
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
        if lower_clean == 'lektor<int>':
            return True
        return False

    unsupported_types = set()
    unsupported_properties = {}
    skipped_methods = []

    # Regex 1: // TODO: Unsupported type for <Field> (<Type>)
    prop_re = re.compile(r'//\s*TODO:\s*Unsupported type for\s+(\w+)\s+\(([^)]+)\)')

    # Regex 2: line <num>: <type> <method>(...) - <reason>
    method_re = re.compile(r'^\s*line\s+\d+:\s+([^-(\s]+(?:\s+\w+)?[\*&]?)\s+(\w+)\(.*?\)\s+-\s+(.*)$')

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
                                t = method_match.group(1).strip()
                                method = method_match.group(2).strip()
                                reason = method_match.group(3).strip()
                                
                                # Skip methods already implemented in code
                                if method not in defined_methods:
                                    if not is_type_already_bound(t):
                                        unsupported_types.add(t)
                                    
                                    skipped_methods.append({
                                        'File': rel_path,
                                        'Type': t,
                                        'Method': method,
                                        'Reason': reason
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
    md.append("*(Automatically generated by `tools/generate_list_of_unbound.py`)*")
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
        stripped_t = t.replace('*', '').replace('&', '')
        for m in skipped_methods:
            m_t = m['Type']
            m_stripped = m_t.replace('*', '').replace('&', '')
            if m_t == t or m_stripped == t:
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
