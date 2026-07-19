import argparse
import re
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


@dataclass
class Arg:
    type: str
    name: str


@dataclass
class Method:
    return_type: str
    name: str
    args: list[Arg]
    const: bool
    static: bool
    virtual: bool
    line: int


@dataclass
class ClassInfo:
    name: str
    bases: str = ""
    members: list[Member] = field(default_factory=list)
    methods: list[Method] = field(default_factory=list)
    enums: set[str] = field(default_factory=set)


def strip_comments_for_parse(line):
    return line.split("//", 1)[0].strip()


def normalize_type(type_text):
    type_text = type_text.strip()
    type_text = re.sub(r"\s+", " ", type_text)
    type_text = type_text.replace(" &", "&").replace("& ", "&")
    type_text = type_text.replace(" *", "*").replace("* ", "*")
    return type_text


def base_type(type_text):
    t = normalize_type(type_text)
    t = re.sub(r"\bconst\b", "", t).strip()
    t = t.replace("&", "").replace("*", "").strip()
    return t


def is_const(type_text):
    return "const" in normalize_type(type_text).split()


def split_args(args_text):
    args_text = args_text.strip()
    if not args_text or args_text == "void":
        return []

    parts = []
    current = []
    depth = 0
    for ch in args_text:
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth = max(0, depth - 1)
        elif ch == "," and depth == 0:
            parts.append("".join(current).strip())
            current = []
            continue
        current.append(ch)
    if current:
        parts.append("".join(current).strip())
    return parts


def parse_arg(arg_text, index):
    arg_text = arg_text.split("=", 1)[0].strip()
    b = re.match(r"(.+?)([A-Za-z_]\w*)$", arg_text)
    if not b:
        return Arg(normalize_type(arg_text), "arg%d" % index)

    type_text = normalize_type(b.group(1).strip())
    name = b.group(2)
    if name in ("const", "volatile"):
        return Arg(normalize_type(arg_text), "arg%d" % index)
    return Arg(type_text, name)


def find_matching_brace(text, open_index):
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


def parse_classes(header_text):
    classes = []
    class_re = re.compile(r"\bclass\s+([A-Za-z_]\w*)\s*(?:\:\s*([^{]+))?\{", re.MULTILINE)
    for match in class_re.finditer(header_text):
        name = match.group(1)

        end = find_matching_brace(header_text, match.end() - 1)
        if end == -1:
            continue

        info = ClassInfo(name=name, bases=(match.group(2) or "").strip())
        parse_class_body(info, header_text[match.end():end], header_text[:match.end()].count("\n") + 1)
        classes.append(info)

    if not classes:
        raise RuntimeError("Could not find any classes in the header")

    return classes


def parse_class_body(info, body, start_line):
    access = "private"
    lines = body.splitlines()
    depth = 0

    for offset, raw in enumerate(lines):
        line_no = start_line + offset
        stripped = raw.strip()
        if not stripped:
            continue

        access_match = re.match(r"^(public|protected|private)\s*:\s*$", stripped)
        if access_match:
            access = access_match.group(1)
            continue

        enum_match = re.match(r"enum(?:\s+class|\s+struct)?\s+([A-Za-z_]\w*)?", stripped)
        if enum_match and enum_match.group(1):
            info.enums.add(enum_match.group(1))

        open_braces = stripped.count("{")
        close_braces = stripped.count("}")
        old_depth = depth
        depth += open_braces - close_braces

        if old_depth > 0 or depth > 0:
            continue

        if access != "public":
            continue

        code = strip_comments_for_parse(stripped)
        if not code.endswith(";"):
            continue
        code = code[:-1].strip()

        if "(" in code and ")" in code:
            method = parse_method(code, line_no)
            if method and method.name not in (info.name, "~" + info.name):
                info.methods.append(method)
            continue

        member = parse_member(code, line_no)
        if member:
            info.members.append(member)


def parse_member(code, line_no):
    if code.startswith("typedef ") or code.startswith("using "):
        return None
    if code.startswith("static "):
        return None
    b = re.match(r"(.+?)\s+([A-Za-z_]\w*)(?:\[[^\]]+\])?$", code)
    if not b:
        return None
    type_text = normalize_type(b.group(1))
    return Member(type_text, b.group(2), line_no)


def parse_method(code, line_no):
    prefix = code[:code.find("(")].strip()
    suffix = code[code.rfind(")") + 1:].strip()
    args_text = code[code.find("(") + 1:code.rfind(")")]

    tokens = prefix.split()
    if len(tokens) < 2:
        return None

    static = "static" in tokens
    virtual = "virtual" in tokens
    tokens = [t for t in tokens if t not in ("static", "virtual", "inline", "friend")]
    if len(tokens) < 2:
        return None

    name = tokens[-1]
    return_type = normalize_type(" ".join(tokens[:-1]))
    args = [parse_arg(arg, i + 1) for i, arg in enumerate(split_args(args_text))]
    return Method(return_type, name, args, "const" in suffix.split(), static, virtual, line_no)


def is_string_type(type_text):
    return base_type(type_text) in STRING_TYPES


def is_scalar_type(type_text):
    return base_type(type_text) in SCALAR_TYPES


def strip_templates(type_text):
    while True:
        next_t, count = re.subn(r"<[^<>]+>", "", type_text)
        if count == 0:
            break
        type_text = next_t
    return type_text


def is_pointer(type_text):
    return "*" in strip_templates(normalize_type(type_text))


def is_reference(type_text):
    return "&" in strip_templates(normalize_type(type_text))


def is_struct_type(type_text):
    return base_type(type_text) in ("Ogre::Vector3", "Vector3", "Ogre::Quaternion", "Quaternion")


def is_enum_type(type_text, info, extra_enums):
    t = base_type(type_text)
    if t in info.enums or t in extra_enums:
        return True
    if "::" in t and "<" not in t and not t.startswith("std::") and not t.startswith("Ogre::") and not t.startswith("MyGUI::"):
        return True
    return False


def cpp_identifier(name):
    cleaned = re.sub(r"[^A-Za-z0-9_]", "_", name)
    if not re.match(r"^[A-Za-z_]", cleaned):
        cleaned = "_" + cleaned
    return cleaned


def binding_for_type(type_text, known_bindings):
    t = base_type(type_text).lower()
    for k, v in known_bindings.items():
        if k.lower() == t:
            return v
    return None


def push_statement(type_text, expr, info, extra_enums, known_bindings, allow_ref=False):
    if is_reference(type_text) and not allow_ref:
        return None
    t = base_type(type_text)
    
    if t == "hand":
        return "return handBinding::push(L, %s);" % expr
        
    binding = binding_for_type(type_text, known_bindings)
    if binding:
        addr = "" if is_pointer(type_text) else "&"
        return "return pushObject<%s>(L, %s%s, %s::getMetatableName());" % (t, addr, expr, binding)
        
    if is_pointer(type_text):
        return "lua_pushlightuserdata(L, (void*)%s);" % expr
        
    if t in ("Ogre::Vector3", "Vector3"):
        return "pushVector3(L, %s);" % expr
    if t in ("Ogre::Quaternion", "Quaternion"):
        return "pushQuaternion(L, %s);" % expr
        
    if t in SCALAR_TYPES:
        return SCALAR_TYPES[t][0].format(expr=expr)
    if is_string_type(type_text):
        return "lua_pushstring(L, %s.c_str());" % expr
    if is_enum_type(type_text, info, extra_enums):
        return "lua_pushinteger(L, (lua_Integer)%s);" % expr
    return None


def read_expression(type_text, idx, info, extra_enums, known_bindings=None):
    t = base_type(type_text)
    if t in SCALAR_TYPES:
        return SCALAR_TYPES[t][1].format(idx=idx)
    if is_string_type(type_text):
        return "luaL_checkstring(L, %s)" % idx
    if is_enum_type(type_text, info, extra_enums):
        return "(%s)luaL_checkinteger(L, %s)" % (t, idx)
    if known_bindings:
        binding = binding_for_type(type_text, known_bindings)
        if binding:
            if is_pointer(type_text):
                return "checkObject<%s>(L, %s, %s::getMetatableName())" % (t, idx, binding)
            else:
                return "*checkObject<%s>(L, %s, %s::getMetatableName())" % (t, idx, binding)
    return None


def method_supported(method, info, extra_enums, known_bindings, overload_counts):
    if method.static:
        return False, "static method"
    if method.name.startswith("operator"):
        return False, "operator"
    if overload_counts.get(method.name, 0) > 1:
        return False, "overloaded method"
    if is_reference(method.return_type):
        return False, "reference return type"
    if push_statement(method.return_type, "result", info, extra_enums, known_bindings) is None and base_type(method.return_type) != "void":
        return False, "unsupported return type"
    for arg in method.args:
        if is_struct_type(arg.type):
            continue 
        if read_expression(arg.type, 0, info, extra_enums, known_bindings) is None:
            return False, "unsupported arg type"
        if is_reference(arg.type) and not (is_string_type(arg.type) and is_const(arg.type)):
            return False, "non-string reference arg"
    return True, ""


def generate_method_stub(info, method, extra_enums, known_bindings):
    out = []
    out.append("int %sBinding::%s(lua_State* L)" % (info.name, cpp_identifier(method.name)))
    out.append("{")
    out.append("    %s* instance = getInstance(L, 1);" % info.name)
    out.append("    if (!instance) return luaL_error(L, \"%s is nil\");" % info.name)
    out.append("")

    arg_names = []
    for i, arg in enumerate(method.args, 2):
        local_name = arg.name if arg.name else "arg%d" % (i - 1)
        arg_names.append(local_name)
        
        if is_struct_type(arg.type):
            t = base_type(arg.type)
            struct_name = "Vector3" if "Vector3" in t else "Quaternion"
            out.append(f"    {t} {local_name};")
            out.append(f"    read{struct_name}(L, {i}, {local_name});")
        else:
            expr = read_expression(arg.type, i, info, extra_enums, known_bindings)
            var_type = arg.type.replace("&", "").strip()
            out.append(f"    {var_type} {local_name} = {expr};")

    call = "instance->%s(%s)" % (method.name, ", ".join(arg_names))
    if base_type(method.return_type) == "void":
        out.append("    %s;" % call)
        out.append("    return 0;")
    else:
        # Use raw method.return_type to preserve pointer asterisks for assignment
        out.append("    %s result = %s;" % (method.return_type, call))
        stmt = push_statement(method.return_type, "result", info, extra_enums, known_bindings)
        out.append("    %s" % stmt)
        if not stmt.startswith("return "):
            out.append("    return 1;")
    out.append("}")
    return "\n".join(out)


def generate_methods(info, extra_enums, known_bindings):
    out = []
    skipped = []
    overload_counts = {}
    for method in info.methods:
        overload_counts[method.name] = overload_counts.get(method.name, 0) + 1
    for method in info.methods:
        ok, reason = method_supported(method, info, extra_enums, known_bindings, overload_counts)
        if ok:
            out.append(generate_method_stub(info, method, extra_enums, known_bindings))
            out.append("")
        else:
            skipped.append((method, reason))

    if skipped:
        out.append("/*")
        out.append("Skipped methods needing manual binding:")
        for method, reason in skipped:
            out.append("  line %d: %s %s(...) - %s" % (method.line, method.return_type, method.name, reason))
        out.append("*/")
    return "\n".join(out).rstrip()


def generated_method_names(info, extra_enums, known_bindings):
    names = []
    overload_counts = {}
    for method in info.methods:
        overload_counts[method.name] = overload_counts.get(method.name, 0) + 1
    for method in info.methods:
        ok, _ = method_supported(method, info, extra_enums, known_bindings, overload_counts)
        if ok:
            names.append(cpp_identifier(method.name))
    return names


def generate_header(info, extra_enums, known_bindings):
    out = []
    out.append("#pragma once")
    out.append("")
    out.append('extern "C" {')
    out.append("#include <lua.h>")
    out.append("#include <lauxlib.h>")
    out.append("}")
    out.append("")
    out.append("namespace KenshiLua")
    out.append("{")
    out.append("class %sBinding" % info.name)
    out.append("{")
    out.append("public:")
    out.append('    static const char* getMetatableName() { return "KenshiLua.%s"; }' % info.name)
    out.append("    static void registerBinding(lua_State* L);")
    out.append("")
    out.append("    static int gc(lua_State* L);")
    out.append("    static int tostring(lua_State* L);")
    out.append("")
    for name in generated_method_names(info, extra_enums, known_bindings):
        out.append("    static int %s(lua_State* L);" % name)
    out.append("};")
    out.append("}")
    return "\n".join(out)

def is_property_supported(member, info, extra_enums, known_bindings):
    stmt = push_statement(member.type, "dummy", info, extra_enums, known_bindings)
    return stmt is not None

def is_setter_supported(member, info, extra_enums, known_bindings):
    if is_struct_type(member.type):
        return True
    if binding_for_type(member.type, known_bindings):
        return True
    expr = read_expression(member.type, 2, info, extra_enums, known_bindings)
    return (expr is not None) and not is_pointer(member.type) and not is_reference(member.type)

def generate_property_getters(info, members, extra_enums, known_bindings):
    out = []
    out.append(f"// --- Getters for {info.name} ---")
    for member in members:
        out.append(f"static int {info.name}_get_{member.name}(lua_State* L)")
        out.append("{")
        out.append(f"    {info.name}* instance = getInstance(L, 1);")
        out.append(f"    if (!instance) return luaL_error(L, \"{info.name} is nil\");")
        
        stmt = push_statement(member.type, "instance->" + member.name, info, extra_enums, known_bindings)
        if stmt.startswith("return "):
            out.append(f"    {stmt}")
        else:
            out.append(f"    {stmt}")
            out.append("    return 1;")
        out.append("}\n")
    return "\n".join(out)

def generate_property_setters(info, members, extra_enums, known_bindings):
    out = []
    out.append(f"// --- Setters for {info.name} ---")
    for member in members:
        if is_setter_supported(member, info, extra_enums, known_bindings):
            out.append(f"static int {info.name}_set_{member.name}(lua_State* L)")
            out.append("{")
            out.append(f"    {info.name}* instance = getInstance(L, 1);")
            out.append(f"    if (!instance) return luaL_error(L, \"{info.name} is nil\");")
            
            if is_struct_type(member.type):
                t = base_type(member.type)
                struct_name = "Vector3" if "Vector3" in t else "Quaternion"
                out.append(f"    read{struct_name}(L, 2, instance->{member.name});")
                out.append("    return 0;")
            else:
                binding = binding_for_type(member.type, known_bindings)
                if binding:
                    t = base_type(member.type)
                    if is_pointer(member.type):
                        out.append(f"    instance->{member.name} = lua_isnoneornil(L, 2) ? nullptr : checkObject<{t}>(L, 2, {binding}::getMetatableName());")
                    else:
                        out.append(f"    instance->{member.name} = *checkObject<{t}>(L, 2, {binding}::getMetatableName());")
                    out.append("    return 0;")
                else:
                    expr = read_expression(member.type, 2, info, extra_enums, known_bindings)
                    out.append(f"    instance->{member.name} = {expr};")
                    out.append("    return 0;")
            out.append("}\n")
    return "\n".join(out)

def generate_cpp(info, header_path, extra_enums, known_bindings, known_headers=None):
    out = []
    
    # 1. Standard Includes
    out.append('#include "pch.h"')
    
    # Strip common include folder prefixes
    h_str = str(header_path).replace("\\", "/")
    for prefix in ["extern/KenshiLib/Include/", "extern/kenshilib/Include/", "extern/KenshiLib/include/", "extern/kenshilib/include/"]:
        if h_str.startswith(prefix):
            h_str = h_str[len(prefix):]
            break
    # Normalize slashes to match project convention
    h_str = h_str.replace("/", "\\")
    out.append(f'#include "{h_str}"')
    out.append(f'#include "{info.name}Binding.h"')
    out.append('#include "Lua/BindingHelpers.h"')
    
    # Add includes for all referenced types that have bindings
    if known_headers:
        referenced_types = set()
        for member in info.members:
            referenced_types.add(base_type(member.type))
        for method in info.methods:
            referenced_types.add(base_type(method.return_type))
            for arg in method.args:
                referenced_types.add(base_type(arg.type))
        if info.bases:
            base_names = [b.strip().split()[-1] for b in info.bases.split(",")]
            for base in base_names:
                referenced_types.add(base)
        
        # We also need HandBinding if hand is used
        has_hand = False
        for member in info.members:
            if "hand" in base_type(member.type):
                has_hand = True
        for method in info.methods:
            if "hand" in base_type(method.return_type):
                has_hand = True
            for arg in method.args:
                if "hand" in base_type(arg.type):
                    has_hand = True
        if has_hand:
            referenced_types.add("hand")
            
        for t in sorted(referenced_types):
            if t in known_headers and t != info.name:
                out.append(f'#include "{known_headers[t]}"')
    out.append("")
    out.append("namespace KenshiLua")
    out.append("{")
    out.append("")
    
    # NEW: Inject the getInstance helper function for this specific class
    out.append(f"static {info.name}* getInstance(lua_State* L, int idx)")
    out.append("{")
    out.append(f"    return checkObject<{info.name}>(L, idx, {info.name}Binding::getMetatableName());")
    out.append("}")
    out.append("")

    supported_members = []
    skipped_properties = []
    for member in info.members:
        if is_property_supported(member, info, extra_enums, known_bindings):
            supported_members.append(member)
        else:
            skipped_properties.append((member, "unsupported type"))

    # 2. Inject Getter and Setter C-Closures
    out.append(generate_property_getters(info, supported_members, extra_enums, known_bindings))
    out.append(generate_property_setters(info, supported_members, extra_enums, known_bindings))

    # 3. Generate Methods
    out.append(generate_methods(info, extra_enums, known_bindings))
    out.append("")

    # 3.5. Commented list of skipped properties
    if skipped_properties:
        out.append("/*")
        out.append("Skipped properties needing manual binding:")
        for member, reason in skipped_properties:
            out.append(f"  line {member.line}: {member.name} ({member.type}) - {reason}")
        out.append("*/")
        out.append("")

    # 4. Generate definitions for GC and Tostring
    out.append(f"int {info.name}Binding::gc(lua_State* L)")
    out.append("{")
    out.append("    // Implementation depends on ownership model")
    out.append("    return 0;")
    out.append("}")
    out.append("")
    out.append(f"int {info.name}Binding::tostring(lua_State* L)")
    out.append("{")
    out.append(f'    lua_pushstring(L, "KenshiLua.{info.name} object");')
    out.append("    return 1;")
    out.append("}")
    out.append("")

    # 5. Registration Function
    out.append(f"void {info.name}Binding::registerBinding(lua_State* L)")
    out.append("{")
    
    # Metamethods
    out.append("    static const luaL_Reg meta[] = {")
    out.append(f'        {{ "__gc",       {info.name}Binding::gc }},')
    out.append(f'        {{ "__tostring", {info.name}Binding::tostring }},')
    out.append("        { 0, 0 }")
    out.append("    };")
    out.append("")
    
    # Methods Native Hook
    out.append("    static const luaL_Reg methods[] = {")
    for name in generated_method_names(info, extra_enums, known_bindings):
        out.append(f'        {{ "{name}", {info.name}Binding::{name} }},')
    out.append("        { 0, 0 }")
    out.append("    };")
    out.append("")

    # Hook up the universal C++ dispatchers
    out.append(f"    registerClass(")
    out.append(f"        L, ")
    out.append(f"        {info.name}Binding::getMetatableName(), ")
    out.append(f"        meta, ")
    out.append(f"        methods, ")
    out.append(f"        genericPropertyIndex, ")
    out.append(f"        genericPropertyNewIndex")
    out.append(f"    );")
    out.append("")

    # 6. Populate the __getters table
    out.append(f"    luaL_getmetatable(L, {info.name}Binding::getMetatableName());")
    out.append("    lua_newtable(L); // Create __getters table")
    for member in supported_members:
        out.append(f"    lua_pushcfunction(L, {info.name}_get_{member.name});")
        out.append(f"    lua_setfield(L, -2, \"{member.name}\");")
    out.append("    lua_setfield(L, -2, \"__getters\"); // Bind to metatable")
    out.append("")
    
    # 7. Populate the __setters table
    out.append("    lua_newtable(L); // Create __setters table")
    for member in supported_members:
        if is_setter_supported(member, info, extra_enums, known_bindings):
            out.append(f"    lua_pushcfunction(L, {info.name}_set_{member.name});")
            out.append(f"    lua_setfield(L, -2, \"{member.name}\");")
    out.append("    lua_setfield(L, -2, \"__setters\"); // Bind to metatable")
    out.append("")
    
    # NEW: Automatically wire up inheritance if a base class exists!
    if info.bases:
        # Strip out "public " or "virtual " keywords to get the raw class name
        base_names = [b.strip().split()[-1] for b in info.bases.split(",")]
        primary_base = base_names[0] # Grab the first inherited class
        
        out.append(f"    // Wire up inheritance to {primary_base}")
        out.append(f"    // setMetatableParent(L, {info.name}Binding::getMetatableName(), {primary_base}Binding::getMetatableName());")
        out.append("")

    out.append("    lua_pop(L, 1); // Pop the metatable off the stack")
    out.append("}")
    out.append("")
    out.append("} // namespace KenshiLua")

    return "\n".join(out)


def discover_known_bindings():
    known = {}
    headers = {}
    bindings_dir = Path("src/Bindings")
    if not bindings_dir.is_dir():
        script_dir = Path(__file__).resolve().parent.parent
        bindings_dir = script_dir / "src" / "Bindings"
    
    if bindings_dir.is_dir():
        for path in bindings_dir.rglob("*Binding.h"):
            filename = path.name
            if filename.endswith("Binding.h"):
                class_name = filename[:-len("Binding.h")]
                if class_name:
                    binding_class = class_name + "Binding"
                    try:
                        content = path.read_text(encoding="utf-8", errors="ignore")
                        m = re.search(r"\b(?:class|struct)\s+(\w+Binding)\b", content)
                        if m:
                            binding_class = m.group(1)
                    except Exception:
                        pass
                    known[class_name] = binding_class
                    try:
                        rel = path.relative_to(bindings_dir.parent)
                        headers[class_name] = str(rel).replace("\\", "/")
                    except ValueError:
                        headers[class_name] = filename
    return known, headers


def parse_known_bindings(values):
    result = {}
    for value in values:
        if "=" not in value:
            raise RuntimeError("--known-binding must look like Type=TypeBinding")
        type_name, binding = value.split("=", 1)
        result[type_name.strip()] = binding.strip()
    return result


def parse_extra_enums(values):
    enums = set()
    for value in values:
        for item in value.split(","):
            item = item.strip()
            if item:
                enums.add(item)
    return enums


def main():
    parser = argparse.ArgumentParser(description="Generate KenshiLua binding scaffolds from KenshiLib-style headers.")
    parser.add_argument("header", help="Header file to parse")
    parser.add_argument("--write-dir", help="Write .h/.cpp files to this directory")
    parser.add_argument("--bind-map", "--known-binding", action="append", default=[], dest="bind_map", help="Map pointer type to binding class, e.g. Character=CharacterBinding")
    parser.add_argument("--classes", "--known-classes", dest="classes", help="Comma-separated list of known classes, automatically mapped to %%classname%%Binding")
    parser.add_argument("--enums", "--enum", action="append", default=[], dest="enums", help="Additional enum type name(s), comma-separated")
    args = parser.parse_args()

    header_path = Path(args.header)
    text = header_path.read_text(errors="ignore")
    text = re.compile(r"/\*.*?\*/", re.DOTALL).sub(lambda b: "\n" * b.group(0).count("\n"), text)
    text = re.compile(r"//.*").sub("", text)

    classes = parse_classes(text)
    known_bindings, known_headers = discover_known_bindings()
    discovered_count = len(known_bindings)
    known_bindings.update(parse_known_bindings(args.bind_map))
    print(f"Discovered {discovered_count} existing bindings in project.")
    if args.classes:
        for c in args.classes.split(","):
            c = c.strip()
            if c:
                known_bindings[c] = c + "Binding"
                
    for c, b in known_bindings.items():
        if c not in known_headers:
            known_headers[c] = f"Bindings/{b}.h"
            
    extra_enums = parse_extra_enums(args.enums)
 
    for info in classes:
        header = generate_header(info, extra_enums, known_bindings)
        cpp = generate_cpp(info, header_path, extra_enums, known_bindings, known_headers)
        if args.write_dir:
            out_dir = Path(args.write_dir)
            out_dir.mkdir(parents=True, exist_ok=True)
            h_path = out_dir / ("%sBinding.h" % info.name)
            cpp_path = out_dir / ("%sBinding.cpp" % info.name)
            h_path.write_text(header)
            cpp_path.write_text(cpp)
            print("Generated %s" % h_path)
            print("Generated %s" % cpp_path)
        else:
            print("// ===== %sBinding.h =====" % info.name)
            print(header)
            print("")
            print("// ===== %sBinding.cpp =====" % info.name)
            print(cpp)
            print("")

if __name__ == "__main__":
    main()