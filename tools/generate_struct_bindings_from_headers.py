# generate_struct_bindings_from_headers.py
#
# Parses top-level and nested C++ structs from header files and generates Lua binding files
# (.h and .cpp) into ./tools/generated/struct/

import argparse
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path


SCALAR_TYPES = {
    "bool": ("lua_pushboolean(L, {expr} ? 1 : 0);", "lua_toboolean(L, {idx}) != 0"),
    "char": ("lua_pushinteger(L, {expr});", "(char)luaL_checkinteger(L, {idx})"),
    "signed char": ("lua_pushinteger(L, {expr});", "(signed char)luaL_checkinteger(L, {idx})"),
    "unsigned char": ("lua_pushinteger(L, {expr});", "(unsigned char)luaL_checkinteger(L, {idx})"),
    "short": ("lua_pushinteger(L, {expr});", "(short)luaL_checkinteger(L, {idx})"),
    "unsigned short": ("lua_pushinteger(L, {expr});", "(unsigned short)luaL_checkinteger(L, {idx})"),
    "int": ("lua_pushinteger(L, {expr});", "(int)luaL_checkinteger(L, {idx})"),
    "unsigned int": ("lua_pushinteger(L, {expr});", "(unsigned int)luaL_checkinteger(L, {idx})"),
    "long": ("lua_pushinteger(L, {expr});", "(long)luaL_checkinteger(L, {idx})"),
    "unsigned long": ("lua_pushinteger(L, {expr});", "(unsigned long)luaL_checkinteger(L, {idx})"),
    "size_t": ("lua_pushinteger(L, (lua_Integer){expr});", "(size_t)luaL_checkinteger(L, {idx})"),
    "float": ("lua_pushnumber(L, {expr});", "(float)luaL_checknumber(L, {idx})"),
    "double": ("lua_pushnumber(L, {expr});", "(double)luaL_checknumber(L, {idx})"),
}

STRING_TYPES = {"std::string", "string"}


@dataclass
class Member:
    type: str
    name: str
    line: int
    array_size: str = ""


@dataclass
class Arg:
    type: str
    name: str


@dataclass
class Constructor:
    args: list[Arg]
    line: int


@dataclass
class StructInfo:
    name: str
    outer_scope: str = ""
    members: list[Member] = field(default_factory=list)
    constructors: list[Constructor] = field(default_factory=list)
    has_equality_op: bool = False
    enums: set[str] = field(default_factory=set)

    @property
    def cpp_full_name(self) -> str:
        return f"{self.outer_scope}::{self.name}" if self.outer_scope else self.name

    @property
    def binding_class_name(self) -> str:
        clean_scope = self.outer_scope.replace("::", "_")
        prefix = f"{clean_scope}_" if clean_scope else ""
        return f"{prefix}{self.name}Binding"

    @property
    def metatable_name(self) -> str:
        clean_scope = self.outer_scope.replace("::", "_")
        prefix = f"{clean_scope}_" if clean_scope else ""
        return f"KenshiLua.{prefix}{self.name}"


def normalize_type(type_text: str) -> str:
    type_text = type_text.strip()
    type_text = re.sub(r"\s+", " ", type_text)
    type_text = type_text.replace(" &", "&").replace("& ", "&")
    type_text = type_text.replace(" *", "*").replace("* ", "*")
    return type_text


def strip_comments_for_parse(line: str) -> str:
    return line.split("//", 1)[0].strip()


def find_matching_brace(text: str, open_index: int) -> int:
    depth = 1
    i = open_index + 1
    while i < len(text):
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return -1


def strip_all_comments(text: str) -> str:
    # Strip /* ... */ multi-line comments while preserving newlines
    def replacer(match):
        s = match.group(0)
        return "\n" * s.count("\n")

    text = re.sub(r"/\*.*?\*/", replacer, text, flags=re.DOTALL)
    # Strip // ... single-line comments
    lines = [line.split("//", 1)[0] for line in text.splitlines()]
    return "\n".join(lines)


def parse_structs(header_text: str, include_classes: bool = False) -> list[StructInfo]:
    clean_text = strip_all_comments(header_text)

    enums = set()
    for m in re.finditer(r"\benum(?:\s+class|\s+struct)?\s+([A-Za-z_]\w*)", clean_text):
        enums.add(m.group(1))

    structs = []

    # Find all struct/class blocks (both top-level and nested)
    pattern = re.compile(r"\b(class|struct)\s+([A-Za-z_]\w*)\s*(?::[^{]+)?\{", re.MULTILINE)
    
    # We maintain scope stacks to detect outer class / struct
    # We parse block by block
    def scan_scope(text_segment: str, current_scope: str, line_offset: int):
        pos = 0
        while pos < len(text_segment):
            match = pattern.search(text_segment, pos)
            if not match:
                break

            kind = match.group(1)
            name = match.group(2)
            should_include = (kind == "struct") or (include_classes and bool(current_scope))

            brace_open = match.end() - 1
            brace_close = find_matching_brace(text_segment, brace_open)
            if brace_close == -1:
                pos = match.end()
                continue

            body = text_segment[match.end():brace_close]
            segment_lines = text_segment[:match.end()].count("\n") + line_offset

            if should_include:
                info = StructInfo(name=name, outer_scope=current_scope, enums=set(enums))
                parse_struct_body(info, body, segment_lines)
                structs.append(info)

            # Recurse into nested structs/classes
            next_scope = f"{current_scope}::{name}" if current_scope else name
            scan_scope(body, next_scope, segment_lines)

            # Advance position past the closing brace to avoid re-parsing nested blocks at outer scope
            pos = brace_close + 1

    scan_scope(clean_text, "", 1)
    return structs


def parse_struct_body(info: StructInfo, body: str, start_line: int):
    access = "public"  # Structs default to public access
    lines = body.splitlines()

    for idx, raw_line in enumerate(lines):
        line_no = start_line + idx
        stripped = strip_comments_for_parse(raw_line)
        if not stripped:
            continue

        if stripped.startswith("public:"):
            access = "public"
            continue
        elif stripped.startswith("private:"):
            access = "private"
            continue
        elif stripped.startswith("protected:"):
            access = "protected"
            continue

        if access != "public":
            continue

        # Check for equality operator
        if "operator==" in stripped:
            info.has_equality_op = True
            continue

        # Skip destructor / nested types / function declarations
        if stripped.startswith("~") or "enum" in stripped or "class " in stripped:
            continue

        # Check for constructors: StructName(...)
        ctor_match = re.match(rf"^{info.name}\s*\((.*?)\)\s*;", stripped)
        if ctor_match:
            args_str = ctor_match.group(1).strip()
            args = []
            if args_str and args_str != "void":
                for arg_idx, arg_part in enumerate(args_str.split(",")):
                    arg_part = arg_part.strip()
                    if arg_part:
                        arg_type = normalize_type(arg_part.split("=")[0].strip())
                        # Extract parameter name if present
                        p_match = re.search(r"([A-Za-z_]\w*)$", arg_type)
                        p_name = p_match.group(1) if p_match else f"arg{arg_idx}"
                        args.append(Arg(arg_type, p_name))
            info.constructors.append(Constructor(args=args, line=line_no))
            continue

        # Check for member variable: Type name; or Type name[N];
        var_match = re.match(r"^([\w:<>*\s&]+)\s+([A-Za-z_]\w*)(?:\s*\[\s*([^\]]+)\s*\])?\s*(?:;|=)", stripped)
        if var_match:
            type_decl = normalize_type(var_match.group(1))
            name = var_match.group(2)
            array_size = (var_match.group(3) or "").strip()

            # Filter out method declarations that return a type
            if "(" in raw_line or "RVA =" in raw_line or "RVA=" in raw_line:
                continue

            info.members.append(Member(type=type_decl, name=name, line=line_no, array_size=array_size))


def generate_struct_cpp(header_rel_path: str, info: StructInfo) -> str:
    out = []
    out.append('#include "pch.h"\n')
    out.append(f'#include "Bindings/struct/{info.binding_class_name}.h"\n')
    out.append('#include "Lua/BindingHelpers.h"\n\n')
    out.append('namespace KenshiLua\n{\n\n')

    out.append(f'static {info.cpp_full_name}* getInstance(lua_State* L, int idx)\n{{\n')
    out.append(f'    return checkObject<{info.cpp_full_name}>(L, idx, {info.binding_class_name}::getMetatableName());\n')
    out.append('}\n\n')

    # Generate Getters
    if info.members:
        out.append(f"// --- Getters for {info.name} ---\n")
        for m in info.members:
            out.append(f'static int {info.name}_get_{m.name}(lua_State* L)\n{{\n')
            out.append(f'    auto* inst = getInstance(L, 1);\n')
            out.append(f'    if (!inst) return luaL_error(L, "{info.cpp_full_name} is nil");\n')

            if m.array_size:
                arr_len = m.array_size
                out.append(f'    if (lua_gettop(L) >= 2 && lua_isnumber(L, 2))\n    {{\n')
                out.append(f'        int idx = (int)luaL_checkinteger(L, 2);\n')
                out.append(f'        if (idx >= 1 && idx <= {arr_len}) idx -= 1;\n')
                out.append(f'        if (idx < 0 || idx >= {arr_len}) return luaL_error(L, "Index out of bounds (1-{arr_len})");\n')
                if m.type in SCALAR_TYPES:
                    push_fmt = SCALAR_TYPES[m.type][0]
                    out.append(f'        {push_fmt.format(expr=f"inst->{m.name}[idx]")}\n')
                    out.append('        return 1;\n')
                elif m.type.endswith("*"):
                    pointee = m.type[:-1].strip()
                    out.append(f'        return pushObject<{pointee}>(L, inst->{m.name}[idx], {pointee}Binding::getMetatableName());\n')
                else:
                    out.append(f'        return pushValue<{m.type}>(L, inst->{m.name}[idx], {m.type}Binding::getMetatableName());\n')
                out.append(f'    }}\n\n')
                out.append(f'    lua_newtable(L);\n')
                out.append(f'    for (int i = 0; i < {arr_len}; ++i)\n    {{\n')
                if m.type in SCALAR_TYPES:
                    push_fmt = SCALAR_TYPES[m.type][0]
                    out.append(f'        {push_fmt.format(expr=f"inst->{m.name}[i]")}\n')
                elif m.type.endswith("*"):
                    pointee = m.type[:-1].strip()
                    out.append(f'        pushObject<{pointee}>(L, inst->{m.name}[i], {pointee}Binding::getMetatableName());\n')
                else:
                    out.append(f'        pushValue<{m.type}>(L, inst->{m.name}[i], {m.type}Binding::getMetatableName());\n')
                out.append('        lua_rawseti(L, -2, i + 1);\n')
                out.append('    }\n')
                out.append('    return 1;\n')
            else:
                if m.type in SCALAR_TYPES:
                    push_fmt = SCALAR_TYPES[m.type][0]
                    out.append(f'    {push_fmt.format(expr=f"inst->{m.name}")}\n')
                    out.append('    return 1;\n')
                elif m.type in ("Ogre::Vector3", "Vector3"):
                    out.append(f'    return pushVector3(L, inst->{m.name});\n')
                elif m.type in ("Ogre::Quaternion", "Quaternion"):
                    out.append(f'    return pushQuaternion(L, inst->{m.name});\n')
                elif m.type == "hand":
                    out.append(f'    return pushObject<hand>(L, &inst->{m.name}, HandBinding::getMetatableName());\n')
                elif m.type in info.enums or m.type.endswith("::Enum") or "Enum" in m.type:
                    out.append(f'    lua_pushinteger(L, (lua_Integer)inst->{m.name});\n')
                    out.append('    return 1;\n')
                elif m.type.endswith("*"):
                    pointee = m.type[:-1].strip()
                    out.append(f'    return pushObject<{pointee}>(L, inst->{m.name}, {pointee}Binding::getMetatableName());\n')
                else:
                    out.append(f'    return pushValue<{m.type}>(L, inst->{m.name}, {m.type}Binding::getMetatableName());\n')

            out.append('}\n\n')

        # Generate Setters
        out.append(f"// --- Setters for {info.name} ---\n")
        for m in info.members:
            out.append(f'static int {info.name}_set_{m.name}(lua_State* L)\n{{\n')
            out.append(f'    auto* inst = getInstance(L, 1);\n')
            out.append(f'    if (!inst) return luaL_error(L, "{info.cpp_full_name} is nil");\n')

            if m.array_size:
                arr_len = m.array_size
                out.append(f'    if (lua_gettop(L) >= 3 && lua_isnumber(L, 2))\n    {{\n')
                out.append(f'        int idx = (int)luaL_checkinteger(L, 2);\n')
                out.append(f'        if (idx >= 1 && idx <= {arr_len}) idx -= 1;\n')
                out.append(f'        if (idx < 0 || idx >= {arr_len}) return luaL_error(L, "Index out of bounds (1-{arr_len})");\n')
                if m.type in SCALAR_TYPES:
                    read_fmt = SCALAR_TYPES[m.type][1]
                    out.append(f'        inst->{m.name}[idx] = {read_fmt.format(idx=3)};\n')
                elif m.type.endswith("*"):
                    pointee = m.type[:-1].strip()
                    out.append(f'        inst->{m.name}[idx] = lua_isnoneornil(L, 3) ? nullptr : checkObject<{pointee}>(L, 3, {pointee}Binding::getMetatableName());\n')
                out.append('        return 0;\n')
                out.append('    }\n\n')
                out.append('    if (lua_istable(L, 2))\n    {\n')
                out.append(f'        for (int i = 0; i < {arr_len}; ++i)\n        {{\n')
                out.append('            lua_rawgeti(L, 2, i + 1);\n')
                if m.type in SCALAR_TYPES:
                    read_fmt = SCALAR_TYPES[m.type][1]
                    out.append(f'            if (!lua_isnil(L, -1)) inst->{m.name}[i] = {read_fmt.format(idx=-1)};\n')
                elif m.type.endswith("*"):
                    pointee = m.type[:-1].strip()
                    out.append(f'            inst->{m.name}[i] = lua_isnoneornil(L, -1) ? nullptr : checkObject<{pointee}>(L, -1, {pointee}Binding::getMetatableName());\n')
                out.append('            lua_pop(L, 1);\n')
                out.append('        }\n')
                out.append('        return 0;\n')
                out.append('    }\n')
                out.append('    return luaL_error(L, "Expected table or index and value");\n')
            else:
                if m.type in SCALAR_TYPES:
                    read_fmt = SCALAR_TYPES[m.type][1]
                    out.append(f'    inst->{m.name} = {read_fmt.format(idx=2)};\n')
                elif m.type in ("Ogre::Vector3", "Vector3"):
                    out.append(f'    inst->{m.name} = readVector3(L, 2);\n')
                elif m.type in ("Ogre::Quaternion", "Quaternion"):
                    out.append(f'    inst->{m.name} = readQuaternion(L, 2);\n')
                elif m.type in info.enums or m.type.endswith("::Enum") or "Enum" in m.type:
                    out.append(f'    inst->{m.name} = ({m.type})luaL_checkinteger(L, 2);\n')
                elif m.type.endswith("*"):
                    pointee = m.type[:-1].strip()
                    out.append(f'    inst->{m.name} = lua_isnoneornil(L, 2) ? nullptr : checkObject<{pointee}>(L, 2, {pointee}Binding::getMetatableName());\n')
                else:
                    out.append(f'    auto* val = checkObject<{m.type}>(L, 2, {m.type}Binding::getMetatableName());\n')
                    out.append(f'    if (val) inst->{m.name} = *val;\n')

            out.append('    return 0;\n')
            out.append('}\n\n')

    # Destructor & GC
    out.append(f'int {info.binding_class_name}::gc(lua_State* L)\n{{\n    return 0;\n}}\n\n')

    out.append(f'int {info.binding_class_name}::tostring(lua_State* L)\n{{\n')
    out.append(f'    lua_pushstring(L, "{info.metatable_name} object");\n')
    out.append('    return 1;\n')
    out.append('}\n\n')

    # Equality Operator
    out.append(f'int {info.binding_class_name}::operator_eq(lua_State* L)\n{{\n')
    out.append('    auto* a = getInstance(L, 1);\n')
    out.append('    auto* b = getInstance(L, 2);\n')
    if info.has_equality_op:
        out.append('    lua_pushboolean(L, (a && b && (*a == *b)) ? 1 : 0);\n')
    else:
        out.append('    lua_pushboolean(L, (a == b) ? 1 : 0);\n')
    out.append('    return 1;\n')
    out.append('}\n\n')

    # Registration
    out.append(f'void {info.binding_class_name}::registerBinding(lua_State* L)\n{{\n')
    out.append('    static const luaL_Reg meta[] = {\n')
    out.append('        { "__eq",       operator_eq },\n')
    out.append('        { "__gc",       gc },\n')
    out.append('        { "__tostring", tostring },\n')
    out.append('        { 0, 0 }\n')
    out.append('    };\n')
    out.append('    static const luaL_Reg methods[] = {\n')
    out.append('        { 0, 0 }\n')
    out.append('    };\n\n')

    out.append('    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);\n\n')

    if info.members:
        out.append('    luaL_getmetatable(L, getMetatableName());\n')
        out.append('    lua_newtable(L); // __getters\n')
        for m in info.members:
            out.append(f'    registerGetter(L, "{m.name}", {info.name}_get_{m.name});\n')
        out.append('    lua_setfield(L, -2, "__getters");\n\n')

        out.append('    lua_newtable(L); // __setters\n')
        for m in info.members:
            out.append(f'    registerSetter(L, "{m.name}", {info.name}_set_{m.name});\n')
        out.append('    lua_setfield(L, -2, "__setters");\n\n')

        out.append('    lua_pop(L, 1);\n')

    out.append('}\n')
    out.append('} // namespace KenshiLua\n')

    return "".join(out)


def generate_struct_header(header_rel_path: str, info: StructInfo) -> str:
    out = []
    out.append('#pragma once\n')
    out.append('#include "pch.h"\n')
    out.append(f'#include "{header_rel_path}"\n\n')
    out.append('namespace KenshiLua\n{\n')
    out.append(f'class {info.binding_class_name}\n{{\npublic:\n')
    out.append(f'    static const char* getMetatableName() {{ return "{info.metatable_name}"; }}\n')
    out.append('    static void registerBinding(lua_State* L);\n\n')
    out.append('    static int gc(lua_State* L);\n')
    out.append('    static int tostring(lua_State* L);\n')
    out.append('    static int operator_eq(lua_State* L);\n')
    out.append('};\n')
    out.append('} // namespace KenshiLua\n')

    return "".join(out)


def main():
    parser = argparse.ArgumentParser(description="Generate Lua binding files for top-level and nested structs in C++ headers.")
    parser.add_argument("header_file", help="Path to header file")
    parser.add_argument("--write-dir", default="tools/generated/struct", help="Output directory for generated struct bindings")
    parser.add_argument("--include-classes", action="store_true", help="Include nested classes with struct-like layout")
    args = parser.parse_args()

    header_path = Path(args.header_file)
    if not header_path.exists():
        print(f"Error: header file '{args.header_file}' not found.")
        sys.exit(1)

    text = header_path.read_text(errors="ignore")
    structs = parse_structs(text, include_classes=args.include_classes)

    if not structs:
        print(f"No struct definitions found in {header_path.name}")
        return

    out_dir = Path(args.write_dir)
    out_dir.mkdir(parents=True, exist_ok=True)

    header_rel_path = f"kenshi/{header_path.name}"

    for s in structs:
        cpp_code = generate_struct_cpp(header_rel_path, s)
        h_code = generate_struct_header(header_rel_path, s)

        out_cpp_path = out_dir / f"{s.binding_class_name}.cpp"
        out_h_path = out_dir / f"{s.binding_class_name}.h"

        out_cpp_path.write_text(cpp_code)
        out_h_path.write_text(h_code)

        print(f"Generated {out_h_path}")
        print(f"Generated {out_cpp_path}")

    print(f"Successfully generated {len(structs)} struct binding(s) in {out_dir}")


if __name__ == "__main__":
    main()
