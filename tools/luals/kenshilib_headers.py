"""Shared KenshiLib header parsing and C++-to-Lua type mapping.

Used by the binding inventory (to take member types from the KenshiLib
declaration a binding wraps) and by the type audit (to check them).
"""

import pathlib
import re


PROJECT_ROOT = pathlib.Path(__file__).resolve().parents[2]
INCLUDE_ROOT = PROJECT_ROOT / "extern" / "KenshiLib" / "Include"
BINDINGS_ROOT = PROJECT_ROOT / "src" / "Bindings"

CPP_TOKEN = re.compile(
    r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|//[^\r\n]*|/\*.*?\*/',
    re.DOTALL,
)


def strip_cpp_comments(text):
    """Blank C/C++ comments while preserving strings, newlines, and offsets."""
    def replace(match):
        token = match.group(0)
        if token.startswith("//") or token.startswith("/*"):
            return "".join(char if char in "\r\n" else " " for char in token)
        return token

    return CPP_TOKEN.sub(replace, text)


def find_function_body(text, marker):
    start = text.find(marker)
    if start < 0:
        return ""
    brace = text.find("{", start)
    if brace < 0:
        return ""
    depth = 1
    index = brace + 1
    while index < len(text) and depth:
        if text[index] == "{":
            depth += 1
        elif text[index] == "}":
            depth -= 1
        index += 1
    return text[brace + 1:index - 1]


INTEGER_TYPES = {
    "int", "unsigned", "unsigned int", "signed", "signed int", "short", "unsigned short",
    "long", "unsigned long", "long long", "unsigned long long", "__int64", "unsigned __int64",
    "char", "signed char", "unsigned char", "size_t", "uint8", "uint16", "uint32", "uint64",
    "int8", "int16", "int32", "int64", "uint8_t", "uint16_t", "uint32_t", "uint64_t",
    "int8_t", "int16_t", "int32_t", "int64_t", "DWORD", "UINT", "BYTE", "WORD", "uint",
    "Ogre::uint", "Ogre::uint8", "Ogre::uint16", "Ogre::uint32", "Ogre::ushort",
    "MyGUI::uint8", "MyGUI::uint16", "MyGUI::uint32", "MyGUI::uint", "MyGUI::Char",
}


NUMBER_TYPES = {"float", "double", "Ogre::Real", "Real", "long double"}


STRING_TYPES = {
    "std::string", "Ogre::String", "String", "MyGUI::UString", "UString", "Ogre::UTFString",
    "UTFString", "char*", "wchar_t*", "std::basic_string<char>",
}


TABLE_TYPES = {
    "Ogre::Vector2", "Ogre::Vector3", "Ogre::Vector4", "Ogre::Quaternion", "Ogre::ColourValue",
    "Vector2", "Vector3", "Vector4", "Quaternion", "ColourValue",
}


CPP_KEYWORDS = {"return", "if", "else", "while", "for", "switch", "case", "goto", "throw", "delete", "new"}


def split_top_level(text, separator=","):
    parts, depth, current = [], 0, []
    for char in text:
        if char in "<([{":
            depth += 1
        elif char in ">)]}":
            depth -= 1
        if char == separator and depth == 0:
            parts.append("".join(current).strip())
            current = []
        else:
            current.append(char)
    tail = "".join(current).strip()
    if tail:
        parts.append(tail)
    return parts


def normalize_type(raw):
    text = re.sub(r"\s+", " ", raw).strip()
    text = re.sub(r"\s*([*&<>,])\s*", r"\1", text)
    return text.replace(">>", ">>")


def parse_param(raw):
    has_default = "=" in raw
    raw = raw.split("=", 1)[0].strip()
    if not raw or raw == "void" or raw == "...":
        return None
    match = re.match(r"^(.*?[\s*&>])(\w+)(\s*\[[^\]]*\])?$", raw)
    if match and match.group(1).strip() and match.group(1).strip() not in {"const", "unsigned", "signed"}:
        return {"type": normalize_type(match.group(1)), "name": match.group(2), "default": has_default}
    return {"type": normalize_type(raw), "name": "", "default": has_default}


DECL_PREFIX = re.compile(r"^(?:(?:virtual|static|inline|explicit|__forceinline|constexpr|extern|mutable)\s+)+")


METHOD_DECL = re.compile(
    r"^(?P<ret>.*?)\b(?P<name>~?\w+|operator\s*\S+?)\s*\((?P<params>.*)\)"
    r"\s*(?P<const>const)?\s*(?:override|final|noexcept|throw\s*\([^)]*\)|=\s*0|=\s*default|=\s*delete|\s)*$",
    re.DOTALL,
)


class HeaderIndex:
    def __init__(self):
        self.classes = {}
        self.enums = set()

    def entry(self, name):
        return self.classes.setdefault(name, {"bases": [], "methods": {}, "members": {}, "scope": ""})

    def parse_file(self, path):
        text = strip_cpp_comments(path.read_text(encoding="utf-8", errors="ignore"))
        text = re.sub(r"^\s*#.*?(?<!\\)$", "", text, flags=re.MULTILINE)
        text = re.sub(r'"(?:\\.|[^"\\])*"', '""', text)
        stack = []  # (kind, qualified name)
        buffer = []
        for char in text:
            if char == ";":
                self.statement("".join(buffer), stack, inline=False)
                buffer = []
            elif char == "{":
                statement = re.sub(r"\s+", " ", "".join(buffer)).strip()
                statement = re.sub(r"^(?:(?:public|private|protected)\s*:\s*)+", "", statement)
                buffer = []
                scope = self.open_scope(statement, stack)
                stack.append(scope)
            elif char == "}":
                if stack:
                    stack.pop()
                buffer = []
            else:
                buffer.append(char)

    def qualify(self, stack, name):
        prefix = [scope[1] for scope in stack if scope[0] in {"class", "namespace"}]
        return (prefix[-1] + "::" + name) if prefix and prefix[-1] else name

    def open_scope(self, statement, stack):
        in_body = not stack or stack[-1][0] in {"class", "namespace"}
        if not in_body:
            return ("block", "")
        statement = re.sub(r"^template\s*<.*?>\s*", "", statement)
        match = re.match(r"^namespace\s*(\w*)$", statement)
        if match:
            return ("namespace", self.qualify(stack, match.group(1)) if match.group(1) else self.qualify(stack, "").rstrip(":"))
        match = re.match(r"^(?:typedef\s+)?enum(?:\s+class|\s+struct)?\s*(\w*)\s*(?::\s*[\w\s:]+)?$", statement)
        if match:
            if match.group(1):
                self.enums.add(self.qualify(stack, match.group(1)))
            return ("enum", "")
        match = re.match(
            r"^(?:typedef\s+)?(class|struct|union)\s+(?:__declspec\([^)]*\)\s+|[A-Z][A-Z0-9_]+\s+|alignas\([^)]*\)\s+)*(\w+)"
            r"(?:\s+final)?(?:\s*:\s*(.+))?$",
            statement,
        )
        if match:
            name = self.qualify(stack, match.group(2))
            entry = self.entry(name)
            entry["scope"] = self.qualify(stack, "").rstrip(":")
            if match.group(3):
                for base in split_top_level(match.group(3)):
                    base = re.sub(r"^(?:(?:public|private|protected|virtual)\s+)+", "", base).strip()
                    if base:
                        entry["bases"].append(normalize_type(base))
            return ("class", name)
        if stack and stack[-1][0] == "class":
            self.statement(statement, stack, inline=True)
        return ("block", "")

    def statement(self, raw, stack, inline):
        if not stack or stack[-1][0] != "class":
            return
        owner = stack[-1][1]
        text = re.sub(r"\s+", " ", raw).strip()
        text = re.sub(r"^(?:(?:public|private|protected)\s*:\s*)+", "", text)
        if not text or re.match(r"^(?:typedef|using|friend|template|class|struct|enum|union)\b", text):
            return
        text = re.sub(r"\s*:\s*[^:()]*\([^)]*\)(?:\s*,\s*\w+\s*\([^)]*\))*\s*$", "", text) if inline else text
        is_static = bool(re.match(r"^(?:\w+\s+)*?static\s", text))
        text = DECL_PREFIX.sub("", text)
        match = METHOD_DECL.match(text)
        if match and "(" in text:
            ret = normalize_type(DECL_PREFIX.sub("", match.group("ret")))
            name = re.sub(r"\s+", "", match.group("name"))
            if not ret or name.startswith("~") or ret in CPP_KEYWORDS:
                return
            params = [p for p in (parse_param(item) for item in split_top_level(match.group("params"))) if p]
            self.entry(owner)["methods"].setdefault(name, []).append({
                "returns": ret,
                "params": params,
                "static": is_static,
                "const": bool(match.group("const")),
                "decl": text,
            })
            return
        if "(" in text:
            return
        text = re.sub(r"\s*=.*$", "", text)
        declarators = split_top_level(text)
        first = re.match(r"^(.*?[\s*&>])(\w+)\s*(\[[^\]]*\])?(?:\s*:\s*\d+)?$", declarators[0]) if declarators else None
        if not first:
            return
        base_type = normalize_type(first.group(1))
        self.entry(owner)["members"][first.group(2)] = base_type + ("[]" if first.group(3) else "")
        bare_type = base_type.rstrip("*&")
        for extra in declarators[1:]:
            extra_match = re.match(r"^([*&]*)\s*(\w+)", extra)
            if extra_match:
                self.entry(owner)["members"][extra_match.group(2)] = bare_type + extra_match.group(1)

    def resolve_class(self, name, scope=""):
        name = normalize_type(name).replace("const ", "")
        candidates = []
        parts = scope.split("::") if scope else []
        while parts:
            candidates.append("::".join(parts) + "::" + name)
            parts.pop()
        candidates.append(name)
        for candidate in candidates:
            if candidate in self.classes:
                return candidate
        suffix = [key for key in self.classes if key.endswith("::" + name)]
        return suffix[0] if len(suffix) == 1 else None

    def lineage(self, name):
        order, queue, seen = [], [name], set()
        while queue:
            current = queue.pop(0)
            if not current or current in seen:
                continue
            seen.add(current)
            order.append(current)
            entry = self.classes.get(current, {})
            for base in entry.get("bases", []):
                queue.append(self.resolve_class(re.sub(r"<.*$", "", base), entry.get("scope", "")))
        return order

    def find_methods(self, cls, name):
        for owner in self.lineage(cls):
            found = self.classes[owner]["methods"].get(name)
            if found:
                return owner, found
        return None, []

    def find_member(self, cls, name):
        for owner in self.lineage(cls):
            found = self.classes[owner]["members"].get(name)
            if found:
                return owner, found
        return None, None


def build_header_index():
    index = HeaderIndex()
    for path in sorted(INCLUDE_ROOT.rglob("*.h")):
        index.parse_file(path)
    return index


CALLBACK_DEF = re.compile(r"\bint\s+([A-Za-z_][\w:]*)\s*\(\s*lua_State\s*\*\s*\w+\s*\)\s*\{")


TYPE_EVIDENCE = re.compile(
    r"\b(?:checkObject|testObject|pushObject|pushObjectOwned|pushValue|getObject)\s*<\s*([^;]*?)\s*>\s*\("
    r"[^;]*?(?:([A-Za-z_]\w*Binding)::getMetatableName\s*\(|\"([^\"]+)\"\s*\))"
)


def load_binding_sources():
    callbacks = {}
    evidence = []
    for path in sorted(BINDINGS_ROOT.rglob("*.cpp")) + sorted(BINDINGS_ROOT.rglob("*.h")):
        text = strip_cpp_comments(path.read_text(encoding="utf-8", errors="ignore"))
        for match in CALLBACK_DEF.finditer(text):
            name = match.group(1)
            body = find_function_body(text[match.start():], match.group(0))
            callbacks.setdefault(name, body)
            short = name.rsplit("::", 1)[-1]
            callbacks.setdefault("*" + short, body)
        evidence.extend(TYPE_EVIDENCE.findall(text))
    return callbacks, evidence


def callback_body(callbacks, callback, binding):
    # Bare names (``size``) also match helpers in template headers, so try the
    # binding-qualified callback first.
    for candidate in (binding + "::" + callback.rsplit("::", 1)[-1], callback):
        if candidate in callbacks:
            return callbacks[candidate]
    return ""


class TypeMapper:
    def __init__(self, inventory, evidence, headers, lua_enums):
        self.headers = headers
        self.lua_enums = lua_enums
        by_metatable = {
            entry["metatable"]: entry["lua_type"]
            for entry in inventory["classes"]
            if entry.get("metatable") and entry.get("kind") != "global_table"
        }
        # A global-table binding may share an object metatable (MyGUIBinding
        # uses MyGUI.Widget's), so objects pushed with it are that class.
        by_binding = {
            entry["binding"]: (
                by_metatable.get(entry.get("metatable"), entry["lua_type"])
                if entry.get("kind") == "global_table" else entry["lua_type"]
            )
            for entry in inventory["classes"]
        }
        self.by_metatable = by_metatable
        self.cpp_to_lua = {}
        for cpp_type, binding, metatable in evidence:
            lua_type = by_binding.get(binding) if binding else by_metatable.get(metatable)
            key = self.key(cpp_type)
            if lua_type and key and not key.startswith("T"):
                self.cpp_to_lua.setdefault(key, lua_type)
        for entry in inventory["classes"]:
            lua_type = entry["lua_type"]
            self.cpp_to_lua.setdefault(lua_type.replace(".", "::"), lua_type)

    MYGUI_TEMPLATES = {"TPoint": "Point", "TSize": "Size", "TCoord": "Coord", "TRect": "Rect"}

    @classmethod
    def key(cls, cpp_type):
        text = normalize_type(cpp_type)
        text = re.sub(r"\b(?:const|volatile|struct|class|enum|typename)\s*", "", text)
        text = text.rstrip("*& ").strip()
        match = re.match(r"^(?:MyGUI::)?(?:types::)?(T(?:Point|Size|Coord|Rect))<(int|float)>$", text)
        if match:
            prefix = "Int" if match.group(2) == "int" else "Float"
            return "MyGUI::" + prefix + cls.MYGUI_TEMPLATES[match.group(1)]
        return text

    def enum_name(self, base):
        resolved = base if base in self.headers.enums else next(
            (name for name in sorted(self.headers.enums) if name.endswith("::" + base)), None
        )
        if not resolved:
            return None
        parts = resolved.split("::")
        lua_name = parts[-2] if parts[-1] == "Enum" and len(parts) > 1 else parts[-1]
        return lua_name if lua_name in self.lua_enums else "integer"

    def lua_type(self, cpp_type):
        """Map a C++ type to (lua type, nullable)."""
        text = normalize_type(cpp_type)
        # Only pointers outside template arguments: lektor<T*>& is no pointer.
        pointers = re.sub(r"<.*>", "", text).count("*")
        base = self.key(text)
        if base in {"char", "wchar_t"} and pointers == 1:
            return "string", False
        if base == "void":
            return ("lightuserdata", True) if pointers else (None, False)
        if base in {"bool", "BOOL"}:
            primitive = "boolean"
        elif base in INTEGER_TYPES:
            primitive = "integer"
        elif base in NUMBER_TYPES:
            primitive = "number"
        elif base in STRING_TYPES:
            primitive = "string"
        else:
            primitive = None
        if primitive and pointers == 0:
            return primitive, False
        if base not in self.cpp_to_lua and "MyGUI::" + base in self.cpp_to_lua:
            base = "MyGUI::" + base
        if base not in self.cpp_to_lua and "<" in base:
            for candidate in container_key_variants(base):
                if candidate in self.cpp_to_lua:
                    base = candidate
                    break
        if base in self.cpp_to_lua:
            lua_type = self.cpp_to_lua[base]
            return lua_type, pointers > 0
        enum = self.enum_name(base)
        if enum and pointers == 0:
            return enum, False
        if base in TABLE_TYPES and pointers == 0:
            return "table", False
        metatable = self.by_metatable.get(base) or self.by_metatable.get(base.replace("*", " *"))
        if metatable:
            return metatable, pointers > 0
        return "?" + base + ("*" * pointers), False

    def is_out_param(self, cpp_type):
        text = normalize_type(cpp_type)
        if re.search(r"\bconst\b", text):
            return False
        base = self.key(text)
        if text.endswith("**") or text.endswith("*&"):
            return True
        if not text.endswith("&") or text.count("*"):
            return False
        lua_type, _ = self.lua_type(text)
        return lua_type in {"boolean", "integer", "number", "string", "table"} or (
            lua_type in self.lua_enums
        ) or base.startswith("iVector") or base.startswith("MyGUI::") and base.split("::")[-1] in {
            "IntPoint", "IntSize", "IntCoord", "FloatPoint", "FloatSize", "FloatCoord",
        }

    def out_type(self, cpp_type):
        text = normalize_type(cpp_type)
        if text.endswith("**") or text.endswith("*&"):
            inner = text[:-1]
            lua_type, _ = self.lua_type(inner)
            return lua_type, True
        return self.lua_type(text[:-1])


def expected_signature(decl, mapper, outs_as_params=False):
    """Map a declaration to Lua params/returns.

    With ``outs_as_params`` an out reference is also read from Lua first, as
    in/out bindings such as ``limitInputsOutputRate(rate)`` do.
    """
    params, returns = [], []
    ret_type, nullable = mapper.lua_type(decl["returns"])
    if ret_type:
        returns.append(ret_type + ("|nil" if nullable else ""))
    for param in decl["params"]:
        if mapper.is_out_param(param["type"]):
            lua_type, nullable = mapper.out_type(param["type"])
            returns.append(lua_type + ("|nil" if nullable else ""))
            if outs_as_params and not nullable:
                params.append({"name": param["name"], "type": lua_type})
        else:
            lua_type, nullable = mapper.lua_type(param["type"])
            params.append({"name": param["name"], "type": lua_type or "?void"})
    return params, returns


INSTANCE_TYPE = re.compile(
    r"([A-Za-z_][\w:]*(?:<[^;]*?>)?)\s*\*\s*\w+\s*=\s*([^;]*?)\(\s*L\s*,\s*1\s*[,)]"
)


OPERATOR_NAMES = {
    "add": "+", "sub": "-", "mul": "*", "div": "/", "mod": "%", "eq": "==", "ne": "!=",
    "lt": "<", "le": "<=", "gt": ">", "ge": ">=", "assign": "=", "add_assign": "+=",
    "sub_assign": "-=", "mul_assign": "*=", "div_assign": "/=", "index": "[]", "call": "()",
    "unm": "-", "not": "!", "and": "&&", "or": "||", "inc": "++", "dec": "--",
}


def instance_type(body):
    """C++ type of the object a callback reads from Lua argument 1."""
    for match in INSTANCE_TYPE.finditer(body):
        cpp_type, source = match.groups()
        if cpp_type == "auto":
            template = re.search(r"<\s*([^<>]+?)\s*>", source)
            if not template:
                continue
            cpp_type = template.group(1)
        if cpp_type not in {"void", "lua_State"}:
            return cpp_type
    return None


def header_member_name(name):
    if name.startswith("operator_"):
        symbol = OPERATOR_NAMES.get(name[len("operator_"):])
        if symbol:
            return "operator" + symbol
    return name


def cpp_target(body, method_name, static, binding_cpp):
    """Return (C++ class, called member name) for a binding callback body."""
    calls = re.findall(r"\b\w+\s*->\s*(\w+)\s*\(", body)
    cls = instance_type(body) or binding_cpp
    method_name = header_member_name(method_name)
    static_calls = re.findall(r"\b([A-Za-z_][\w:]*)::(\w+)\s*\(", body)
    if static:
        for owner, name in static_calls:
            if name == method_name and not owner.endswith("Binding"):
                return owner, name
    if method_name in calls:
        return cls, method_name
    distinct = [call for call in dict.fromkeys(calls) if call not in {"c_str", "size", "get", "empty"}]
    if len(distinct) == 1:
        return cls, distinct[0]
    return cls, method_name


# ---------------------------------------------------------------------------
# Header-derived signatures for wrapper callbacks


STACK_READ = re.compile(r"\(\s*L\s*,\s*([A-Za-z_]\w*|\d+)\s*(?:\+\s*(\d+))?\s*[,)]")
PLACEHOLDER_NAME = re.compile(r"^_?a\d+$")


def call_arguments(body, target):
    """Argument expressions of the first call to ``target`` in a callback."""
    if target.startswith("operator"):
        return None
    match = re.search(r"(?:->|\.|::)\s*" + re.escape(target) + r"\s*\(", body)
    if not match:
        return None
    depth, index = 1, match.end()
    while index < len(body) and depth:
        if body[index] == "(":
            depth += 1
        elif body[index] == ")":
            depth -= 1
        index += 1
    return split_top_level(body[match.end():index - 1])


def stack_position(expr, static):
    """Lua parameter position (1-based, excluding self) an expression reads."""
    match = STACK_READ.search(expr)
    if not match:
        return None
    base, offset = match.group(1), int(match.group(2) or 0)
    if base.isdigit():
        index = int(base) + offset
        position = index if static else index - 1
    else:
        # Dual-call helpers compute ``idx`` as the first argument after an
        # optional self, so ``idx + k`` is argument k + 1.
        position = 1 + offset
    return position if position >= 1 else None


def argument_source(expr, body, static):
    """Classify a call argument as ("lua", position), ("local", name), or None."""
    text = expr.strip()
    position = stack_position(text, static)
    if position:
        return "lua", position
    match = re.fullmatch(
        r"[&*\s]*(?:\([^()]*\)\s*)?[&*\s]*([A-Za-z_]\w*)(?:\s*\.\s*c_str\s*\(\s*\))?", text
    )
    if not match:
        return None
    name = match.group(1)
    for assign in re.finditer(r"\b" + re.escape(name) + r"\s*=(?!=)\s*([^;]+);", body):
        position = stack_position(assign.group(1), static)
        if position:
            return "lua", position
    for fill in re.finditer(
        r"\w+\s*\(\s*L\s*,\s*([^,()]+?)\s*,\s*&?\s*" + re.escape(name) + r"\s*[,)]", body
    ):
        position = stack_position("(L, " + fill.group(1) + ")", static)
        if position:
            return "lua", position
    return "local", name


def header_signature(body, method_name, static, binding_cpp, headers, mapper):
    """Lua types for a callback that forwards Lua arguments to a KenshiLib member.

    Returns ``{"params": {position: {"type", "name"}}, "returns": [...],
    "result": [...], "decl": text}`` or None when the callback does not call a
    uniquely resolvable declaration.  ``returns`` is the declared return value
    followed by out parameters; ``result`` is the declared return value alone.
    """
    if not body:
        return None
    cls, target = cpp_target(body, method_name, static, binding_cpp)
    resolved = headers.resolve_class(re.sub(r"<.*$", "", cls)) if cls else None
    if not resolved:
        return None
    _, decls = headers.find_methods(resolved, target)
    args = call_arguments(body, target)
    if not decls or args is None:
        return None
    candidates = [
        decl for decl in decls
        if sum(not param.get("default") for param in decl["params"]) <= len(args) <= len(decl["params"])
    ]
    shapes = {
        (decl["returns"], tuple(param["type"] for param in decl["params"][:len(args)]))
        for decl in candidates
    }
    if len(shapes) != 1:
        return None
    decl = candidates[0]
    params, outs = {}, []
    for expr, param in zip(args, decl["params"]):
        source = argument_source(expr, body, static)
        out = mapper.is_out_param(param["type"])
        if out:
            lua_type, nullable = mapper.out_type(param["type"])
            # Locals are pure outputs; Lua-read references are in/out values.
            if source:
                outs.append(lua_type + ("|nil" if nullable else ""))
        else:
            lua_type, _ = mapper.lua_type(param["type"])
        if source and source[0] == "lua" and lua_type:
            name = param["name"] if param["name"] and not PLACEHOLDER_NAME.match(param["name"]) else ""
            params[source[1]] = {"type": lua_type, "name": name}
    ret_type, nullable = mapper.lua_type(decl["returns"])
    result = [ret_type + ("|nil" if nullable else "")] if ret_type else []
    return {"params": params, "returns": result + outs, "result": result, "decl": decl["decl"]}


DUAL_INDEX = re.compile(
    r"\b(?:const\s+)?int\s+([A-Za-z_]\w*)\s*=\s*([^;]*\(\s*L\s*,\s*1\b[^;]*?)\?\s*(\d+)\s*:\s*(\d+)\s*;"
)


DUAL_INDEX_IF = re.compile(
    r"\bint\s+([A-Za-z_]\w*)\s*=\s*(\d+)\s*;\s*if\s*\([^;{}]*\(\s*L\s*,\s*1\b[^;{}]*\)\s*\{?\s*\1\s*=\s*(\d+)\s*;"
)


def normalize_dual_index(body, static):
    """Resolve dual-call index locals to literal stack indexes.

    Helpers callable both as ``obj:m(...)`` and ``Class.m(...)`` compute
    ``idx = isSelf ? 2 : 1`` or ``offset = isSelf ? 1 : 0``.  Substitute the
    value for the calling convention the Lua signature describes (with self
    for instance methods, without for static ones) and fold ``(L, 1 + offset)``
    style arguments to literals.
    """
    found = [(match.group(0), match.group(1), match.group(3), match.group(4)) for match in DUAL_INDEX.finditer(body)]
    # `int idx = 1; if (lua_isuserdata(L, 1)) idx = 2;`
    found += [
        (match.group(0), match.group(1), match.group(3), match.group(2)) for match in DUAL_INDEX_IF.finditer(body)
    ]
    for declaration, name, with_self, without_self in found:
        value = without_self if static else with_self
        # The self test reads slot 1 but is not an argument.
        body = body.replace(declaration, "int " + name + " = " + value + ";")

        def fold(argument):
            expression = re.sub(r"\b" + re.escape(name) + r"\b", value, argument.group(1))
            compact = re.sub(r"\s+", "", expression)
            if re.fullmatch(r"\d+(?:[+-]\d+)*", compact):
                expression = str(sum(int(term) for term in re.findall(r"[+-]?\d+", compact)))
            return "(L, " + expression + argument.group(2)

        body = re.sub(
            r"\(\s*L\s*,\s*([^(),;]*\b" + re.escape(name) + r"\b[^(),;]*)([,)])", fold, body
        )
    return body


def container_key_variants(base):
    """Spellings of a container type to try against registered instances.

    Headers may qualify element types (``ConstructionState::BuildMaterial*``)
    and spell out comparator/allocator arguments (``std::set<hand,
    std::less<hand>, Ogre::STLAllocator<...>>``) that registrations omit.
    """
    match = re.match(r"^([^<]+)<(.*)>(.*)$", base)
    if not match:
        return []
    name, args, suffix = match.groups()
    arguments = split_top_level(args)
    variants = []
    for count in (len(arguments), 2, 1):
        if count > len(arguments):
            continue
        spelling = name + "<" + ",".join(arguments[:count]) + ">" + suffix
        variants.append(spelling)
        variants.append(re.sub(r"\b(?:\w+::)+(?=\w)", "", spelling))
    return variants


def reachable_body(body):
    """Drop statements after the first unconditional top-level ``return``."""
    depth = 0
    for match in re.finditer(r"[{}]|\breturn\b[^;]*;", body):
        token = match.group(0)
        if token == "{":
            depth += 1
        elif token == "}":
            depth -= 1
        elif depth == 0:
            start = max(body.rfind(char, 0, match.start()) for char in ";{}") + 1
            # `if (!instance) return luaL_error(...);` is conditional.
            if re.search(r"\b(?:if|else|for|while|case|default)\b", body[start:match.start()]):
                continue
            return body[:match.end()]
    return body
