"""Generate the runtime-registered class inventory used by the LuaLS pipeline.

The inventory records evidence established from registration and callback
source: reachable bindings, Lua member names, metatables, inheritance,
constructor registration, source provenance, and conservative argument/return
contracts. Reviewed metadata remains authoritative for richer contracts.

Usage:
    python tools/luals/generate_binding_inventory.py
    python tools/luals/generate_binding_inventory.py --check
"""

import argparse
import json
import pathlib
import re
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

import container_contracts  # noqa: E402
import kenshilib_headers  # noqa: E402
from kenshilib_headers import (  # noqa: E402,F401
    find_function_body, reachable_body, split_top_level, strip_cpp_comments,
)


PROJECT_ROOT = pathlib.Path(__file__).resolve().parents[2]
REGISTER_BINDINGS_PATH = PROJECT_ROOT / "src" / "Lua" / "RegisterBindings.cpp"
VERSION_PATH = PROJECT_ROOT / "src" / "Version.h"
OUTPUT_PATH = PROJECT_ROOT / "luals" / "generated" / "binding_inventory.json"


def relative(path):
    return path.relative_to(PROJECT_ROOT).as_posix()


def read_version():
    text = VERSION_PATH.read_text(encoding="utf-8")
    parts = []
    for name in ("MAJOR", "MINOR", "PATCH"):
        match = re.search(r"#define\s+KENSHILUA_VERSION_" + name + r"\s+(\d+)", text)
        if not match:
            raise ValueError("missing KENSHILUA_VERSION_" + name)
        parts.append(match.group(1))
    suffix = re.search(r'#define\s+KENSHILUA_VERSION_SUFFIX\s+"([^"]*)"', text)
    if not suffix:
        raise ValueError("missing KENSHILUA_VERSION_SUFFIX")
    return ".".join(parts) + suffix.group(1)


def find_binding_implementations():
    """Map each class binding to its registration implementation and body."""
    implementations = {}
    pattern = re.compile(
        r"\bvoid\s+([A-Za-z_]\w*Binding)::registerBinding\s*"
        r"\(\s*lua_State\s*\*\s*\w+[^)]*\)"
    )
    for path in (PROJECT_ROOT / "src" / "Bindings").rglob("*.cpp"):
        text = path.read_text(encoding="utf-8", errors="ignore")
        parsed_text = strip_cpp_comments(text)
        for match in pattern.finditer(parsed_text):
            binding = match.group(1)
            body = find_function_body(parsed_text, match.group(0))
            if body:
                implementations[binding] = {
                    "path": relative(path),
                    "text": text,
                    "body": body,
                }
    return implementations


def registration_calls(body):
    body = strip_cpp_comments(body)
    return re.findall(
        r"\b([A-Za-z_]\w*Binding)::registerBinding\s*\(\s*L\s*\)",
        body,
    )


def find_template_definitions():
    """Map generic binding template names to their registerBinding bodies."""
    definitions = {}
    bases = {}
    header_pattern = re.compile(
        r"\b(?:class|struct)\s+([A-Za-z_]\w*)\b"
        r"(?:\s*:\s*public\s+([A-Za-z_]\w*)[^\{]*)?\s*\{"
    )
    register_pattern = re.compile(
        r"static\s+void\s+registerBinding\s*\([^;{}]*\)\s*\{"
    )
    for path in (PROJECT_ROOT / "src" / "Bindings").rglob("*.h"):
        text = strip_cpp_comments(path.read_text(encoding="utf-8", errors="ignore"))
        for match in header_pattern.finditer(text):
            name, base = match.groups()
            class_body = find_function_body(text, match.group(0))
            register_match = register_pattern.search(class_body)
            if register_match:
                definitions[name] = {
                    "body": find_function_body(class_body, register_match.group(0)),
                    "text": class_body,
                    "path": relative(path),
                }
            if base:
                bases[name] = base

    for name in list(bases):
        current = name
        seen = set()
        while current not in definitions and current in bases and current not in seen:
            seen.add(current)
            current = bases[current]
        if current in definitions:
            definitions[name] = definitions[current]
    return definitions


CENTRAL_CONTAINER_REGISTRATIONS = (
    "registerLektor", "registerOgreUnordered", "registerStdSet", "registerStdMap",
    "registerStdDeque", "registerFitnessSelector",
)


def parse_template_instances(reached, implementations):
    """Find concrete generic-container registrations nested in reached bindings."""
    definitions = find_template_definitions()
    instances = {}
    alias_metatables = {}
    typedef_pattern = re.compile(
        r"typedef\s+([A-Za-z_]\w*)\s*<([^;]+)>\s+([A-Za-z_]\w*Binding)\s*;"
    )
    # Containers registered without a typedef alias, for example
    # LektorPtrBinding<Character*>::registerBinding(L, "lektor<Character*>", ...).
    direct_pattern = re.compile(
        r"\b([A-Za-z_]\w*Binding)\s*<([^;]*?)>\s*::registerBinding\s*\(\s*L\s*,\s*"
        r"\"([^\"]+)\"([^;]*)\)\s*;"
    )

    def element_refs(rest):
        refs = []
        for argument in split_top_level(rest.lstrip(",").strip()) if rest.strip() else []:
            binding_match = re.match(r"^([A-Za-z_]\w*Binding)::getMetatableName\s*\(\s*\)$", argument)
            literal = re.match(r'^"([^"]+)"$', argument)
            refs.append(
                "binding:" + binding_match.group(1) if binding_match
                else "metatable:" + literal.group(1) if literal
                else None
            )
        return refs

    def record(key, alias, metatable, template, args, rest, owner, implementation):
        definition = definitions.get(template)
        if not definition:
            raise ValueError("missing generic binding definition for " + template)
        entry = instances.setdefault(key, {
            "alias": alias,
            "metatable": metatable,
            "template": template,
            "template_args": split_top_level(args),
            "element_refs": element_refs(rest),
            "definition": definition,
            "owners": set(),
            "registered_from": set(),
        })
        if entry["template"] != template:
            raise ValueError("conflicting generic templates for " + alias)
        entry["owners"].add(owner)
        entry["registered_from"].add(implementation["path"])
        alias_metatables.setdefault(alias, set()).add(metatable)

    direct_aliases = {}
    direct_ids = {}
    # registerAll runs these before registerClasses, and registerClass keeps
    # the first metatable registered under a name, so a central registration
    # defines the runtime type of every later registration that shares its
    # name (lektor<hand> is LektorValueBinding<hand>, not the read-only one).
    central_text = strip_cpp_comments(REGISTER_BINDINGS_PATH.read_text(encoding="utf-8", errors="ignore"))
    central_body = "".join(
        find_function_body(central_text, "void LuaBindings::" + name + "(lua_State* L)")
        for name in CENTRAL_CONTAINER_REGISTRATIONS
    )
    central = {"path": relative(REGISTER_BINDINGS_PATH)}
    central_metatables = set()
    for template, args, metatable, rest in direct_pattern.findall(central_body):
        if template not in definitions:
            continue
        direct_ids.setdefault(metatable, set()).add(template_binding_id(template, args))
        if metatable in central_metatables:
            continue
        alias = direct_aliases.setdefault(metatable, template_binding_id(template, args))
        record((alias, metatable), alias, metatable, template, args, rest, "LuaBindings", central)
        central_metatables.add(metatable)

    for owner in reached:
        implementation = implementations.get(owner)
        if not implementation:
            continue
        aliases = {
            alias: (template, args)
            for template, args, alias in typedef_pattern.findall(implementation["text"])
        }
        for alias, (template, args) in aliases.items():
            call_pattern = re.compile(
                r"\b" + re.escape(alias) +
                r"::registerBinding\s*\(\s*L\s*,\s*\"([^\"]+)\"([^;]*)\)\s*;"
            )
            for metatable, rest in call_pattern.findall(implementation["body"]):
                if metatable in central_metatables:
                    direct_ids[metatable].add(alias)
                    continue
                record((alias, metatable), alias, metatable, template, args, rest, owner, implementation)
    typed_metatables = {key[1] for key in instances}
    for owner in sorted(reached):
        implementation = implementations.get(owner)
        if not implementation:
            continue
        for template, args, metatable, rest in direct_pattern.findall(implementation["body"]):
            if template not in definitions:
                continue
            if metatable in central_metatables:
                direct_ids[metatable].add(template_binding_id(template, args))
                continue
            if metatable in typed_metatables:
                continue
            # Distinct instantiations (StdSetBinding<hand> and one spelling out
            # its allocator) can register one metatable: one Lua class.
            alias = direct_aliases.setdefault(metatable, template_binding_id(template, args))
            direct_ids.setdefault(metatable, set()).add(template_binding_id(template, args))
            record((alias, metatable), alias, metatable, template, args, rest, owner, implementation)

    result = []
    for (alias, metatable), entry in sorted(instances.items()):
        short_name = alias.removesuffix("Binding")
        if "<" in alias:
            # Named after its element types by name_container_instances().
            binding = alias
            lua_type = ""
        elif len(alias_metatables[alias]) == 1:
            binding = alias
            lua_type = short_name
        else:
            owner = sorted(entry["owners"])[0]
            owner_name = owner.removesuffix("Binding")
            binding = owner + "::" + alias
            lua_type = owner_name + "." + short_name
        definition = entry["definition"]
        methods = parse_methods(definition["body"])
        for method in methods:
            signature = infer_method_signature(method, definition, alias)
            if signature is None and method["callback"] == "Base::size":
                signature = {"params": [], "returns": ["integer"]}
            if signature is None and method["callback"] == "Base::toTable":
                signature = {"params": [], "returns": ["table"]}
            if signature is not None:
                method["signature"] = signature
        result.append({
            "binding": binding,
            "kind": "template_instance",
            "lua_type": lua_type,
            "metatable": metatable,
            "source": definition["path"],
            "registered_from": sorted(entry["registered_from"]),
            "parent_binding": None,
            "parent_metatable": "",
            "global_names": [],
            "has_constructor": False,
            "methods": methods,
            "properties": parse_properties(definition["body"], definition["text"]),
            "template": entry["template"],
            "template_args": entry["template_args"],
            "element_refs": entry["element_refs"],
            "owners": sorted(entry["owners"]),
        })
        other_ids = sorted(direct_ids.get(metatable, set()) - {binding})
        if other_ids:
            result[-1]["binding_aliases"] = other_ids
    return result


def parse_runtime_reachability(implementations):
    """Return bindings reached from LuaBindings::registerClasses."""
    registry_text = strip_cpp_comments(REGISTER_BINDINGS_PATH.read_text(encoding="utf-8"))
    root_body = find_function_body(
        registry_text,
        "void LuaBindings::registerClasses(lua_State* L)",
    )
    if not root_body:
        raise ValueError("could not find LuaBindings::registerClasses")

    pending = [(binding, "src/Lua/RegisterBindings.cpp") for binding in registration_calls(root_body)]
    reached = {}
    unresolved = set()
    while pending:
        binding, registered_from = pending.pop()
        paths = reached.setdefault(binding, set())
        if registered_from in paths:
            continue
        paths.add(registered_from)
        implementation = implementations.get(binding)
        if not implementation:
            unresolved.add(binding)
            continue
        for nested in registration_calls(implementation["body"]):
            pending.append((nested, implementation["path"]))
    return reached, sorted(unresolved), registry_text


def parse_inheritance(registry_text):
    body = find_function_body(registry_text, "static void registerInheritance(lua_State* L)")
    result = {}
    pattern = re.compile(
        r"setMetatableParent\s*\(\s*L\s*,\s*"
        r"([A-Za-z_]\w*Binding)::getMetatableName\(\)\s*,\s*"
        r"([A-Za-z_]\w*Binding)::getMetatableName\(\)"
    )
    for child, parent in pattern.findall(body):
        result[child] = parent
    return result


def parse_local_parent(binding, body):
    """Return inheritance installed inside one binding's registration body."""
    body = strip_cpp_comments(body)
    pattern = re.compile(
        r"setMetatableParent\s*\(\s*L\s*,\s*"
        r"(?:" + re.escape(binding) + r"::)?getMetatableName\s*\(\)\s*,\s*"
        r"([A-Za-z_]\w*Binding)::getMetatableName\s*\(\)"
    )
    match = pattern.search(body)
    return match.group(1) if match else None


def parse_methods(body):
    body = strip_cpp_comments(body)
    match = re.search(r"static\s+const\s+luaL_Reg\s+methods\s*\[\]\s*=\s*\{", body)
    if not match:
        return []
    table = find_function_body(body, match.group(0))
    static_names = set(re.findall(r'registerStaticMethod\s*\(\s*L\s*,\s*"([^"]+)"', body))
    names = []
    seen = set()
    for name, callback in re.findall(
        r'\{\s*"([^"]+)"\s*,\s*([A-Za-z_]\w*(?:::\w+)?)\s*\}', table
    ):
        if not name.startswith("__") and name not in seen:
            seen.add(name)
            names.append({"name": name, "callback": callback, "static": name in static_names})
    return names


def find_lua_callback_body(text, name):
    pattern = re.compile(
        r"(?:static\s+)?int\s+" + re.escape(name) +
        r"\s*\(\s*lua_State\s*\*\s*\w+\s*\)"
    )
    match = pattern.search(text)
    return find_function_body(text, match.group(0)) if match else ""


def find_registered_callback_body(text, callback, binding):
    """Resolve a luaL_Reg callback, including free helper callbacks."""
    candidates = [callback]
    if "::" not in callback:
        candidates.append(binding + "::" + callback)
    else:
        candidates.append(callback.rsplit("::", 1)[1])
    for candidate in candidates:
        if "::" in candidate:
            pattern = re.compile(
                r"(?:static\s+)?int\s+" + re.escape(candidate) +
                r"\s*\(\s*lua_State\s*\*\s*\w+\s*\)"
            )
        else:
            pattern = re.compile(
                r"(?:static\s+)?int\s+" + re.escape(candidate) +
                r"\s*\(\s*lua_State\s*\*\s*\w+\s*\)"
            )
        match = pattern.search(text)
        if match:
            return find_function_body(text, match.group(0))
    return ""


def infer_multi_return_values(body, count):
    """Infer ordered value slots returned by a fixed multi-return callback.

    Each slot is a sorted list of type references: primitive Lua types, or
    ``binding:<Name>`` / ``metatable:<name>`` entries resolved later by
    ``build_inventory``.  A push in an ``else`` branch is merged into the
    preceding slot as an alternative.  Otherwise this accepts only a single
    output sequence, or identical sequences from alternate branches; any
    unrecognised push leaves the callback untyped rather than guessed.
    """
    push_patterns = (
        (r"\blua_pushboolean\s*\(", ("boolean",)),
        (r"\blua_pushinteger\s*\(", ("integer",)),
        (r"\blua_pushnumber\s*\(", ("number",)),
        (r"\blua_push(?:l)?string\s*\(", ("string",)),
        (r"\blua_pushlightuserdata\s*\(", ("lightuserdata",)),
        (r"\blua_pushnil\s*\(", ("nil",)),
        (r"\blua_(?:new|create)table\s*\(", ("table",)),
        (r"\bpush(?:Vector[234]|Quaternion|ColourValue)\s*\(", ("table",)),
    )
    matches = []
    for pattern, refs in push_patterns:
        matches.extend((match.start(), refs) for match in re.finditer(pattern, body))
    # pushObject pushes nil for a null pointer; pushValue always pushes a copy.
    for match in re.finditer(
        r"\b(pushObject|pushValue)\s*<[^;]*?>\s*\([^;]*?"
        r"(?:([A-Za-z_]\w*Binding)::getMetatableName\s*\(|\"([^\"]+)\"\s*\))",
        body,
    ):
        ref = (
            "binding:" + match.group(2) if match.group(2)
            else "metatable:" + match.group(3)
        )
        refs = (ref, "nil") if match.group(1) == "pushObject" else (ref,)
        matches.append((match.start(), refs))
    all_pushes = re.findall(
        r"\b(?:lua_(?:new|create)table|\w*push(?!_back)\w*)\s*(?:<[^;()]*>)?\s*\(",
        body,
    )
    if len(all_pushes) != len(matches):
        return []
    slots = []
    previous_end = None
    for start, refs in sorted(matches):
        if slots and re.search(r"\belse\b", body[previous_end:start]):
            slots[-1] = tuple(sorted(set(slots[-1]) | set(refs)))
        else:
            slots.append(tuple(sorted(refs)))
        previous_end = body.find(";", start)
    if len(slots) == count:
        return [list(slot) for slot in slots]
    if len(slots) > count and len(slots) % count == 0:
        sequences = [tuple(slots[index:index + count]) for index in range(0, len(slots), count)]
        if len(set(sequences)) == 1:
            return [list(slot) for slot in sequences[0]]
    return []


TEMPLATE_BINDING_REF = re.compile(
    r"([A-Za-z_]\w*Binding)\s*<([^;]*?)>\s*::\s*(?:getMetatableName\s*\(\s*\)|metaName)"
)


def template_binding_id(template, args):
    """Inventory binding id of a directly registered container instance."""
    return template + "<" + re.sub(r"\s+", "", args) + ">"


def template_binding_refs(text, push_only=False):
    """Binding ids for ``Template<Args>::getMetatableName()`` references."""
    refs = set()
    for match in TEMPLATE_BINDING_REF.finditer(text):
        if push_only:
            statement_start = text.rfind(";", 0, match.start()) + 1
            if not re.search(r"\b(?:pushObject|pushValue)\w*\s*<", text[statement_start:match.start()]):
                continue
        refs.add(template_binding_id(match.group(1), match.group(2)))
    return refs


PUSH_CALL = re.compile(
    r"\b(?:lua_push\w+|pushObject\w*|pushValue|push(?:Vector[234]|Quaternion|ColourValue)"
    r"|\w+Binding::push|MyGUIBindings::pushWidget)\s*(?:<[^;]*?>)?\s*\("
)
PRIMITIVE_PUSHES = (
    (r"\blua_pushboolean\s*\(", "boolean"),
    (r"\blua_pushinteger\s*\(", "integer"),
    (r"\blua_pushnumber\s*\(", "number"),
    (r"\blua_push(?:l)?string\s*\(", "string"),
    (r"\bpush(?:Vector[234]|Quaternion|ColourValue)\s*\(", "table"),
)


def split_array_element_pushes(body):
    """Separate pushes stored into a result table from returned pushes.

    A push immediately followed by ``lua_rawseti`` fills an array being
    built, so its type is an element type, not a return type.  Returns the
    body without those statements and the element references
    (primitive types, ``binding:``/``metatable:`` refs).
    """
    statements = body.split(";")
    elements, kept = set(), []
    single_table = len(re.findall(r"\blua_(?:new|create)table\s*\(", body)) == 1
    for index, statement in enumerate(statements):
        following = statements[index + 1] if index + 1 < len(statements) else ""
        field = re.match(r'^\s*lua_setfield\s*\(\s*L\s*,\s*-2\s*,\s*"(\w+)"', following)
        if PUSH_CALL.search(statement) and field and single_table:
            # A record field of the one table being built: `{ width: integer }`.
            field_types = {lua_type for pattern, lua_type in PRIMITIVE_PUSHES if re.search(pattern, statement)}
            if len(field_types) == 1:
                elements.add("field:" + field.group(1) + "=" + field_types.pop())
            else:
                elements.add("field:" + field.group(1) + "=any")
            kept.append(re.sub(r"\S", " ", statement))
            continue
        if PUSH_CALL.search(statement) and re.match(r"^\s*\}?\s*lua_rawseti\s*\(", following):
            for pattern, lua_type in PRIMITIVE_PUSHES:
                if re.search(pattern, statement):
                    elements.add(lua_type)
            elements.update("binding:" + name for name in re.findall(
                r"([A-Za-z_]\w*Binding)::getMetatableName\s*\(", statement
            ))
            elements.update("metatable:" + name for name in re.findall(r'"([^"]+)"\s*\)', statement))
            if "MyGUIBindings::pushWidget" in statement:
                elements.add("MyGUI.Widget")
            # Keep the statement's line structure but drop the push.
            kept.append(re.sub(r"\S", " ", statement))
        else:
            kept.append(statement)
    return ";".join(kept), elements


def infer_return_contract(body):
    """Infer Lua return types from callback push calls."""
    numeric_returns = {int(value) for value in re.findall(r"\breturn\s+(\d+)\s*;", body)}
    multi_return_counts = {value for value in numeric_returns if value > 1}
    if multi_return_counts:
        if len(multi_return_counts) != 1 or numeric_returns - multi_return_counts:
            return [], [], [], [], False
        return [], [], [], infer_multi_return_values(body, multi_return_counts.pop()), False

    body, array_elements = split_array_element_pushes(body)
    return_types = set()
    if re.search(r"\blua_settop\s*\(\s*L\s*,\s*1\s*\)\s*;\s*return\s+1\s*;", body):
        return_types.add(SELF_TYPE)
    primitive_return_patterns = (
        (r"\blua_pushboolean\s*\(", "boolean"),
        (r"\blua_pushinteger\s*\(", "integer"),
        (r"\blua_pushnumber\s*\(", "number"),
        (r"\blua_push(?:l)?string\s*\(", "string"),
        (r"\blua_pushlightuserdata\s*\(", "lightuserdata"),
        (r"\blua_pushnil\s*\(", "nil"),
        (r"\blua_(?:new|create)table\s*\(", "table"),
        (r"\bpush(?:Vector[234]|Quaternion|ColourValue)\s*\(", "table"),
    )
    if 1 in numeric_returns:
        for pattern, lua_type in primitive_return_patterns:
            if re.search(pattern, body):
                return_types.add(lua_type)
    if "MyGUIBindings::pushWidget" in body:
        widget_match = re.search(
            r"MyGUI::([A-Za-z_]\w*)\s*\*\s*result\s*=", body
        )
        return_types.add(
            "MyGUI." + widget_match.group(1)
            if widget_match else "MyGUI.Widget"
        )
    if re.search(r"\breturn\s+(?:Base::)?len\s*\(\s*L\s*\)", body):
        return_types.add("integer")
    if not return_types and 1 in numeric_returns and "LuaCodec<" in body:
        return_types.add("any")
    return_bindings = set(re.findall(
        r"\b(?:pushObject|pushValue)\s*<.*?>\s*\([^;]*?"
        r"([A-Za-z_]\w*Binding)::getMetatableName\s*\(",
        body,
        re.DOTALL,
    ))
    return_bindings.update(re.findall(
        r"\breturn\s+([A-Za-z_]\w*Binding)::push\s*\(", body
    ))
    # Container metatables named through the template binding, e.g.
    # OgreUnorderedSetBinding<GameData*>::getMetatableName().
    return_bindings.update(template_binding_refs(body, push_only=True))
    if re.search(
        r"\b(?:pushObject|pushValue)\s*<[^;]*?>\s*\([^;]*?(?<![:\w])getMetatableName\s*\(", body
    ):
        return_types.add(SELF_TYPE)
    return_metatables = set(re.findall(
        r'\b(?:pushObject|pushValue)\s*<.*?>\s*\([^;]*?"([^"]+)"\s*\)',
        body,
        re.DOTALL,
    ))
    record_fields = sorted(item[len("field:"):] for item in array_elements if item.startswith("field:"))
    array_elements = {item for item in array_elements if not item.startswith("field:")}
    if record_fields and not array_elements and "table" in return_types:
        return_types.discard("table")
        return_types.add("{ " + ", ".join(
            name + ": " + lua_type for name, _, lua_type in (field.partition("=") for field in record_fields)
        ) + " }")
    if array_elements and "table" in return_types:
        # Resolved to ``T[]`` once element bindings map to Lua types.
        return_types.discard("table")
        return_types.add("array:" + ",".join(sorted(array_elements)))
    if 0 in numeric_returns and (return_types or return_bindings or return_metatables):
        return_types.add("nil")
    return (
        sorted(return_types),
        sorted(return_bindings),
        sorted(return_metatables),
        [],
        numeric_returns == {0},
    )


def lua_object_type(raw):
    raw = re.sub(r"\bconst\s+", "", raw).replace("&", "").replace("*", "").strip()
    if raw == "std::string":
        return "string"
    if raw in {"T", "V", "BaseType"}:
        return "any"
    if raw.startswith("MyGUI::"):
        return raw.replace("::", ".")
    if "::" in raw:
        return "any"
    return raw


def infer_setter_value_types(body):
    """Infer a property's Lua type from stack slot two in its setter."""
    value_types = set()
    patterns = (
        (r"checkObject\s*<\s*([^>]+?)\s*>\s*\(\s*L\s*,\s*2", lambda m: lua_object_type(m.group(1))),
        (r"luaL_(?:opt)?checkinteger\s*\(\s*L\s*,\s*2", lambda m: "integer"),
        (r"luaL_(?:opt)?checknumber\s*\(\s*L\s*,\s*2", lambda m: "number"),
        (r"luaL_(?:opt)?check(?:l)?string\s*\(\s*L\s*,\s*2", lambda m: "string"),
        (r"lua_toboolean\s*\(\s*L\s*,\s*2", lambda m: "boolean"),
        (r"(?:readVector\d|checkVector\d)\s*\(\s*L\s*,\s*2", lambda m: "table"),
    )
    for pattern, type_for in patterns:
        for match in re.finditer(pattern, body):
            value_types.add(type_for(match))
    if value_types and re.search(r"lua_isnoneornil\s*\(\s*L\s*,\s*2", body):
        value_types.add("nil")
    return sorted(value_types)


SELF_TYPE = "@self"
VALUE_READ_AT_FIRST = re.compile(
    r"\b(?:luaL_(?:check|opt)\w+|lua_to(?:number|integer|boolean|l?string)|read\w+)"
    r"\s*\(\s*L\s*,\s*1\s*[,)]"
)
OBJECT_READ_AT_FIRST = re.compile(
    r"\bcheckObject\s*<[^;]*?>\s*\(\s*L\s*,\s*1\s*,\s*([A-Za-z_]\w*Binding)::getMetatableName"
)


ELEMENT_READERS = (
    (r"(?:checkObject|testObject)\s*<[^;]*?>\s*\(\s*L\s*,\s*-1\s*,\s*([A-Za-z_]\w*Binding)::getMetatableName",
     lambda m: "binding:" + m.group(1)),
    (r"(?:luaL_check|lua_to)l?string\s*\(\s*L\s*,\s*-1", lambda m: "string"),
    (r"(?:luaL_checknumber|lua_tonumber)\s*\(\s*L\s*,\s*-1", lambda m: "number"),
    (r"(?:luaL_checkinteger|lua_tointeger)\s*\(\s*L\s*,\s*-1", lambda m: "integer"),
    (r"lua_toboolean\s*\(\s*L\s*,\s*-1", lambda m: "boolean"),
)


def object_reads(body):
    """Stack reads typed by a binding reference rather than a C++ type name.

    Yields ``(index, placeholder)`` pairs resolved in ``build_inventory``:
    objects checked against ``XBinding::getMetatableName()``, containers read
    through ``Template<Args>::get``, and Lua tables whose elements are read
    with ``lua_rawgeti`` (``Faction[]``).
    """
    for match in re.finditer(
        r"(?:checkObject|testObject)\s*<[^;]*?>\s*\(\s*L\s*,\s*(\d+)\s*,\s*"
        r"([A-Za-z_]\w*Binding)::getMetatableName",
        body,
    ):
        yield int(match.group(1)), "ref:binding:" + match.group(2)
    for match in re.finditer(r"([A-Za-z_]\w*Binding)\s*<([^;]*?)>\s*::\s*get\s*\(\s*L\s*,\s*(\d+)", body):
        yield int(match.group(3)), "ref:binding:" + template_binding_id(match.group(1), match.group(2))
    for match in re.finditer(r"\blua_rawgeti\s*\(\s*L\s*,\s*(\d+)\s*,", body):
        window = body[match.end():match.end() + 300]
        for pattern, ref_for in ELEMENT_READERS:
            element = re.search(pattern, window)
            if element:
                yield int(match.group(1)), "array:" + ref_for(element)
                break


def is_static_style(body, binding):
    """True when an instance-registered callback reads argument 1 as a value.

    Such callbacks (``FarmBuilding.getFertilityMultiplier`` reads its first
    number from stack slot 1) only work when called with a dot, so their Lua
    signature has no ``self``.
    """
    if re.search(r"\b(?:getInstance|get[A-Z]\w*)\s*\(\s*L\s*,\s*1\s*[,)]", body):
        return False
    if VALUE_READ_AT_FIRST.search(body):
        return True
    match = OBJECT_READ_AT_FIRST.search(body)
    return bool(match and match.group(1) != binding)


def infer_method_signature(method, implementation, binding):
    """Infer Lua argument contracts from the callback's checked stack slots."""
    callback = method.get("callback", method["name"])
    body = reachable_body(find_registered_callback_body(implementation["text"], callback, binding))
    if not body:
        return None
    static = method.get("static", False)
    no_self = not static and is_static_style(body, binding)
    body = kenshilib_headers.normalize_dual_index(body, static or no_self)
    first_index = 1 if static or no_self else 2

    args = {}
    checked = set()
    patterns = (
        (r"checkObject\s*<\s*([^>]+?)\s*>\s*\(\s*L\s*,\s*(\d+)", lambda m: lua_object_type(m.group(1))),
        # A second object of the binding's own class (operator_assign, compare).
        (r"\bgetInstance\s*\(\s*L\s*,\s*(\d+)", lambda m: SELF_TYPE),
        (r"luaL_(?:check|opt)integer\s*\(\s*L\s*,\s*(\d+)", lambda m: "integer"),
        (r"luaL_(?:check|opt)number\s*\(\s*L\s*,\s*(\d+)", lambda m: "number"),
        (r"luaL_(?:check|opt)l?string\s*\(\s*L\s*,\s*(\d+)", lambda m: "string"),
        (r"lua_toboolean\s*\(\s*L\s*,\s*(\d+)", lambda m: "boolean"),
        (r"lua_tointeger\s*\(\s*L\s*,\s*(\d+)", lambda m: "integer"),
        (r"lua_tonumber\s*\(\s*L\s*,\s*(\d+)", lambda m: "number"),
        (r"lua_to(?:l)?string\s*\(\s*L\s*,\s*(\d+)", lambda m: "string"),
        (r"testObject\s*<\s*([^>]+?)\s*>\s*\(\s*L\s*,\s*(\d+)", lambda m: lua_object_type(m.group(1))),
        (r"(?:readVector\d|checkVector\d)\s*\(\s*L\s*,\s*(\d+)", lambda m: "table"),
        (r"lua_touserdata\s*\(\s*L\s*,\s*(\d+)", lambda m: "lightuserdata"),
        (r"LuaCodec\s*<\s*[^>]+>\s*::read\s*\(\s*L\s*,\s*(\d+)", lambda m: "any"),
    )
    for pattern, type_for in patterns:
        for match in re.finditer(pattern, body):
            index = int(match.group(2) if match.lastindex and match.lastindex > 1 else match.group(1))
            if index < first_index:
                continue
            value_type = type_for(match)
            args.setdefault(index, set()).add(value_type)
            checked.add(index)
    for index, ref in object_reads(body):
        if index >= first_index:
            args.setdefault(index, set()).add(ref)
            checked.add(index)
    for index, values in args.items():
        # An unparsed C++ type name next to a resolvable reference adds nothing.
        if "any" in values and len(values) > 1:
            values.discard("any")

    # A few wrappers use an index local (notably static CharStats helpers).
    if not args and re.search(r"luaL_checkinteger\s*\(\s*L\s*,\s*\w+\s*\)", body):
        args[2] = {"integer"}
        checked.add(2)
    if not args:
        max_index = first_index - 1
    else:
        max_index = max(args)

    params = []
    for index in range(first_index, max_index + 1):
        values = args.get(index, {"any"})
        # Several readers on one slot are type dispatch (testObject<Item>
        # then lua_isstring): the slot accepts their union.
        value_type = "any" if "any" in values else "|".join(sorted(values))
        optional = (
            re.search(r"lua_gettop\s*\(\s*L\s*\)\s*>=\s*" + str(index), body)
            or re.search(r"luaL_opt\w+\s*\(\s*L\s*,\s*" + str(index) + r"\s*,", body)
            or re.search(r"lua_is(?:noneor)?nil\s*\(\s*L\s*,\s*" + str(index) + r"\s*\)", body)
            # `lua_isnumber(L, n) ? lua_tonumber(L, n) : default`
            or re.search(r"lua_is\w+\s*\(\s*L\s*,\s*" + str(index) + r"\s*\)\s*\?", body)
            or (index in checked and "boolean" in values and not re.search(
                r"luaL_\w*check\w*\s*\(\s*L\s*,\s*" + str(index), body
            ))
        )
        params.append({
            "name": "arg" + str(index - first_index + 1), "type": value_type, "optional": bool(optional),
        })
    signature = {"params": params}
    if no_self:
        signature["no_self"] = True
    return_types, return_bindings, return_metatables, return_values, returns_void = infer_return_contract(body)
    if return_types or returns_void:
        signature["returns"] = return_types
    if return_values:
        signature["return_value_refs"] = return_values
    if return_bindings:
        signature["return_bindings"] = return_bindings
    if return_metatables:
        signature["return_metatables"] = return_metatables
    return signature


def parse_custom_property_accessors(body, implementation_text):
    """Find properties implemented by custom registerClass index callbacks."""
    body = strip_cpp_comments(body)
    implementation_text = strip_cpp_comments(implementation_text)
    match = re.search(
        r"registerClass\s*\(\s*L\s*,\s*"
        r"(?:[A-Za-z_]\w*Binding::)?getMetatableName\s*\(\s*\)\s*,\s*"
        r"meta\s*,\s*methods\s*,\s*"
        r"([A-Za-z_]\w*)\s*,\s*([A-Za-z_]\w*)\s*\)",
        body,
        re.DOTALL,
    )
    if not match:
        return set(), set()

    index_name, newindex_name = match.groups()
    generic_names = {"genericPropertyIndex", "genericPropertyNewIndex"}
    index_body = "" if index_name in generic_names else find_lua_callback_body(
        implementation_text, index_name
    )
    newindex_body = "" if newindex_name in generic_names else find_lua_callback_body(
        implementation_text, newindex_name
    )
    pattern = r'strcmp\s*\(\s*key\s*,\s*"([^"]+)"\s*\)'
    return set(re.findall(pattern, index_body)), set(re.findall(pattern, newindex_body))


def parse_properties(body, implementation_text):
    body = strip_cpp_comments(body)
    implementation_text = strip_cpp_comments(implementation_text)
    getter_callbacks = dict(re.findall(
        r'registerGetter\s*\(\s*L\s*,\s*"([^"]+)"\s*,\s*([A-Za-z_][\w:]*)',
        body,
    ))
    setter_callbacks = dict(re.findall(
        r'registerSetter\s*\(\s*L\s*,\s*"([^"]+)"\s*,\s*([A-Za-z_][\w:]*)',
        body,
    ))
    getters = set(getter_callbacks)
    setters = set(setter_callbacks)
    custom_getters, custom_setters = parse_custom_property_accessors(body, implementation_text)
    getters.update(custom_getters)
    setters.update(custom_setters)
    properties = []
    for name in sorted(getters | setters):
        if name in getters and name in setters:
            access = "readwrite"
        elif name in getters:
            access = "readonly"
        else:
            access = "writeonly"
        property_entry = {"name": name, "access": access}
        getter_body = reachable_body(find_lua_callback_body(
            implementation_text, getter_callbacks.get(name, "")
        ))
        if getter_body:
            return_types, return_bindings, return_metatables, _, _ = infer_return_contract(getter_body)
            if return_types:
                property_entry["return_types"] = return_types
            if return_bindings:
                property_entry["return_bindings"] = return_bindings
            if return_metatables:
                property_entry["return_metatables"] = return_metatables
            if "MyGUIBindings::pushWidget" in getter_body:
                # Pushed with the widget's dynamic metatable; see apply_header_types.
                property_entry["_dynamic_widget"] = True
        setter_body = find_lua_callback_body(
            implementation_text, setter_callbacks.get(name, "")
        )
        setter_types = infer_setter_value_types(setter_body) if setter_body else []
        if setter_types:
            property_entry["setter_types"] = setter_types
        properties.append(property_entry)
    return properties


def find_metatable(binding, implementation):
    candidates = [PROJECT_ROOT / implementation["path"].replace(".cpp", ".h")]
    candidates.extend((PROJECT_ROOT / "src" / "Bindings").rglob(binding + ".h"))
    seen = set()
    for path in candidates:
        if path in seen or not path.is_file():
            continue
        seen.add(path)
        text = path.read_text(encoding="utf-8", errors="ignore")
        match = re.search(
            r"\bclass\s+" + re.escape(binding) +
            r"\b.*?getMetatableName\s*\(\)\s*\{?\s*return\s*\"([^\"]+)\"",
            text,
            re.DOTALL,
        )
        if match:
            return match.group(1)

    text = implementation["text"]
    match = re.search(
        re.escape(binding) +
        r"::getMetatableName\s*\(\)\s*\{?\s*return\s*\"([^\"]+)\"",
        text,
    )
    if match:
        return match.group(1)

    matches = set(re.findall(
        r'getMetatableName\s*\(\)\s*\{?\s*return\s*"([^"]+)"',
        text,
    ))
    if len(matches) == 1:
        return matches.pop()
    return ""


def lua_type_from_metatable(metatable, binding):
    prefix = "KenshiLua."
    if metatable.startswith(prefix):
        return metatable[len(prefix):]
    return binding.removesuffix("Binding")


def classify_binding(body):
    """Distinguish a userdata class from a Lua global-table registrar."""
    globals_ = sorted(set(re.findall(
        r'lua_setglobal\s*\(\s*L\s*,\s*"([^"]+)"\s*\)', body
    )))
    if re.search(r"\bregisterClass\s*\(\s*L\s*,", body):
        return "class", globals_
    if globals_:
        return "global_table", globals_
    return "binding", []


def parse_global_functions():
    """Inventory direct C-function globals installed by the runtime."""
    registrations = {}
    pattern = re.compile(
        r"lua_pushcfunction\s*\(\s*L\s*,\s*([A-Za-z_]\w*)\s*\)\s*;\s*"
        r"lua_setglobal\s*\(\s*L\s*,\s*\"([^\"]+)\"\s*\)"
    )
    for path in (PROJECT_ROOT / "src").rglob("*.cpp"):
        text = path.read_text(encoding="utf-8", errors="ignore")
        text = re.sub(r"//[^\n]*", "", text)
        text = re.sub(r"/\*.*?\*/", "", text, flags=re.DOTALL)
        for callback, name in pattern.findall(text):
            entry = registrations.setdefault(name, {"callbacks": set(), "sources": set()})
            entry["callbacks"].add(callback)
            entry["sources"].add(relative(path))
    return [
        {
            "name": name,
            "callbacks": sorted(entry["callbacks"]),
            "sources": sorted(entry["sources"]),
        }
        for name, entry in sorted(registrations.items())
    ]


def validate_inventory(inventory):
    """Fail early if parser changes silently discard known registration evidence."""
    bindings = {entry["binding"]: entry for entry in inventory["classes"]}
    required = {
        "CharacterBinding": ("class", "Character"),
        "WidgetBinding": ("class", "MyGUI.Widget"),
        "MyGUIBinding": ("global_table", "MyGUI"),
    }
    for binding, (kind, lua_type) in required.items():
        entry = bindings.get(binding)
        if not entry or entry["kind"] != kind or entry["lua_type"] != lua_type:
            raise ValueError("inventory did not correctly record " + binding)
    character_methods = {method["name"] for method in bindings["CharacterBinding"]["methods"]}
    character_properties = {prop["name"] for prop in bindings["CharacterBinding"]["properties"]}
    if "getStats" not in character_methods or "stats" not in character_properties:
        raise ValueError("inventory did not record Character members")
    widget_methods = {method["name"] for method in bindings["WidgetBinding"]["methods"]}
    if "setPosition" not in widget_methods:
        raise ValueError("inventory did not record Widget members")
    value_types = {
        "IntPointBinding": "MyGUI.IntPoint",
        "IntSizeBinding": "MyGUI.IntSize",
        "IntCoordBinding": "MyGUI.IntCoord",
        "IntRectBinding": "MyGUI.IntRect",
        "FloatPointBinding": "MyGUI.FloatPoint",
        "FloatSizeBinding": "MyGUI.FloatSize",
        "FloatCoordBinding": "MyGUI.FloatCoord",
        "FloatRectBinding": "MyGUI.FloatRect",
        "ColourBinding": "MyGUI.Colour",
    }
    for binding, lua_type in value_types.items():
        entry = bindings.get(binding)
        if not entry or entry["lua_type"] != lua_type:
            raise ValueError("inventory did not correctly record " + binding)
    global_functions = {entry["name"] for entry in inventory["global_functions"]}
    required_functions = {
        "registerHandler",
        "unregisterHandler",
        "getGameWorld",
        "getPlayerInterface",
        "getInputHandler",
        "getSelectedCharacter",
        "getRootObjectFactory",
        "getGlobalConstants",
        "getOptionsHolder",
        "getForgottenGUI",
        "print",
    }
    if not required_functions.issubset(global_functions):
        raise ValueError("inventory did not record all required global functions")


def name_container_instances(classes, mapper):
    """Name container instances and type them from the reviewed contracts.

    Element types come from the element metatables passed at registration,
    or from the template arguments for primitive and untyped elements.  Each
    instance's C++ spellings are registered with ``mapper`` so declarations
    that take or return the container map to its Lua class.
    """
    by_binding = {}
    by_metatable = {}
    for entry in classes:
        if entry["kind"] == "template_instance" or not entry.get("metatable"):
            continue
        if entry["kind"] != "global_table":
            by_metatable.setdefault(entry["metatable"], entry["lua_type"])
    for entry in classes:
        if entry["kind"] != "template_instance":
            by_binding[entry["binding"]] = (
                by_metatable.get(entry.get("metatable"), entry["lua_type"])
                if entry["kind"] == "global_table" else entry["lua_type"]
            )
    def merge_into(keep, other):
        keep["binding_aliases"] = sorted(
            set(keep.get("binding_aliases", [])) | {other["binding"]} | set(other.get("binding_aliases", []))
        )
        if other["metatable"] != keep["metatable"]:
            keep["metatable_aliases"] = sorted(
                set(keep.get("metatable_aliases", [])) | {other["metatable"]}
                | set(other.get("metatable_aliases", []))
            )
        keep["owners"] = sorted(set(keep.get("owners", [])) | set(other.get("owners", [])))
        keep["registered_from"] = sorted(set(keep["registered_from"]) | set(other["registered_from"]))
        classes.remove(other)

    # Typedef aliases in different bindings can register one metatable
    # (ogre_unordered_set<hand> is SquadsListSet and
    # ForgottenInventoryWindowsPermanentSet): one runtime type, one entry.
    groups = {}
    for entry in classes:
        if entry["kind"] == "template_instance":
            groups.setdefault(entry["metatable"], []).append(entry)
    for group in groups.values():
        for other in group[1:]:
            merge_into(group[0], other)
    # Typedef names given at parse time, which the mapper may already hold.
    old_names = {
        id(entry): entry["lua_type"]
        for entry in classes
        if entry["kind"] == "template_instance" and entry["lua_type"]
    }
    taken = {entry["lua_type"] for entry in classes if entry["lua_type"]}

    def element_type(ref, argument):
        if ref:
            kind, _, name = ref.partition(":")
            resolved = (by_binding if kind == "binding" else by_metatable).get(name)
            if resolved:
                return resolved
        mapped, _ = mapper.lua_type(argument)
        if mapped and not mapped.startswith("?"):
            return mapped
        return "lightuserdata" if "*" in argument else "any"

    for entry in sorted(
        (item for item in classes if item["kind"] == "template_instance"),
        key=lambda item: item["metatable"],
    ):
        template, args = entry["template"], entry["template_args"]
        refs = entry["element_refs"] + [None] * 2
        if not container_contracts.family(template):
            # Helpers without a generic contract keep a concrete class.
            if not entry["lua_type"]:
                entry["lua_type"] = container_contracts.instance_name(template, entry["metatable"], args)
                taken.add(entry["lua_type"])
            continue
        if container_contracts.family(template)[0] == "map":
            key_type = element_type(refs[0], args[0])
            value_type = element_type(refs[1], args[1] if len(args) > 1 else "")
        else:
            key_type = "integer"
            value_type = element_type(refs[0], args[0])
        entry["lua_type"] = container_contracts.generic_type(template, key_type, value_type)
        entry["element_types"] = {"key": key_type, "value": value_type}
        entry["indexer"] = container_contracts.indexer(template, key_type, value_type)
        for method in entry["methods"]:
            signature = container_contracts.method_signature(template, method["name"], key_type, value_type)
            if signature:
                method["signature"] = signature
        for spelling in container_contracts.cpp_spellings(template, args):
            mapper.cpp_to_lua[kenshilib_headers.TypeMapper.key(spelling)] = entry["lua_type"]
        # The mapper was built from the typedef names; repoint them.
        old_name = old_names.get(id(entry))
        if old_name:
            for key, value in list(mapper.cpp_to_lua.items()):
                if value == old_name:
                    mapper.cpp_to_lua[key] = entry["lua_type"]

    # Different metatables with the same element types (two lektor<hand*>
    # registrations) are one LuaLS type.
    by_type = {}
    for entry in [item for item in classes if item["kind"] == "template_instance"]:
        if entry["lua_type"] in by_type:
            merge_into(by_type[entry["lua_type"]], entry)
        else:
            by_type[entry["lua_type"]] = entry


# lightuserdata is not weak: a binding that calls lua_pushlightuserdata hands
# Lua a raw pointer without methods, whatever the declared C++ type.
WEAK_LUA_TYPES = {"any", "nil"}


def is_weak_type(lua_type):
    """True when a source-inferred type carries no useful contract."""
    parts = {part for part in lua_type.split("|") if part} if lua_type else set()
    return not parts or parts <= WEAK_LUA_TYPES


def return_count(body):
    """Number of values a callback returns, or None when it varies."""
    numeric = {int(value) for value in re.findall(r"\breturn\s+(\d+)\s*;", body)}
    if re.search(r"\breturn\s+(?:\w+::)*push\w*\s*(?:<[^;]*?>)?\s*\(", body):
        numeric.add(1)
    positive = numeric - {0}
    if not positive:
        return 0 if numeric else None
    return positive.pop() if len(positive) == 1 else None


def apply_header_types(classes, lua_types_by_metatable, headers, mapper):
    """Fill weak inferred types from the KenshiLib declaration a binding wraps.

    Binding-source evidence stays authoritative where it is concrete; the
    header supplies types only for ``any``/``lightuserdata``/``nil``-only or
    missing slots, a more specific subclass, and parameter names.
    """
    parents = {
        entry["lua_type"]: lua_types_by_metatable.get(entry.get("parent_metatable"))
        for entry in classes
    }

    def is_subtype(child, parent):
        seen = set()
        while child and child not in seen:
            if child == parent:
                return True
            seen.add(child)
            child = parents.get(child)
        return False

    def merge(old, new, narrow):
        """Combine binding evidence ``old`` with the header type ``new``.

        ``narrow`` allows a declared subclass to replace the evidence type:
        right for parameters (a stricter contract) and for objects pushed with
        their dynamic metatable (MyGUIBindings::pushWidget), wrong for objects
        pushed with an explicit base metatable, which only have base methods.
        """
        if not new or new.startswith("?"):
            return old
        if is_weak_type(old):
            return new
        if not narrow:
            return old
        old_set = set(old.split("|")) - {"nil"}
        new_set = set(new.split("|")) - {"nil"}
        if len(old_set) == 1 and len(new_set) == 1:
            old_type, new_type = next(iter(old_set)), next(iter(new_set))
            if old_type != new_type and is_subtype(new_type, old_type):
                return new
        return old

    for entry in classes:
        if entry["kind"] == "template_instance":
            continue
        binding_cpp = None
        for method in entry.get("methods", []):
            body = method.get("_body")
            binding_cpp = binding_cpp or (kenshilib_headers.instance_type(body) if body else None)
        header_class = headers.resolve_class(re.sub(r"<.*$", "", binding_cpp)) if binding_cpp else None
        if not header_class:
            for candidate in (entry["lua_type"].replace(".", "::"), entry["lua_type"].replace("_", "::")):
                header_class = headers.resolve_class(candidate)
                if header_class:
                    break
        binding_cpp = binding_cpp or header_class or entry["lua_type"].replace(".", "::")

        for method in entry.get("methods", []):
            body = method.pop("_body", "")
            signature = method.get("signature")
            if not signature or not body:
                continue
            static = method.get("static", False) or signature.get("no_self", False)
            body = kenshilib_headers.normalize_dual_index(body, static)
            derived = kenshilib_headers.header_signature(
                body, method["name"], static, binding_cpp, headers, mapper
            )
            if not derived:
                continue
            changed = False
            params = signature["params"]
            for position, header_param in sorted(derived["params"].items()):
                while len(params) < position:
                    index = len(params) + (1 if static else 2)
                    params.append({
                        "name": "arg" + str(len(params) + 1),
                        "type": "any",
                        "optional": bool(
                            re.search(r"lua_gettop\s*\(\s*L\s*\)\s*>=\s*" + str(index), body)
                            or re.search(r"lua_is(?:noneor)?nil\s*\(\s*L\s*,\s*" + str(index) + r"\s*\)", body)
                        ),
                    })
                    changed = True
                param = params[position - 1]
                merged = merge(param["type"], header_param["type"], narrow=True)
                if merged != param["type"]:
                    param["type"] = merged
                    changed = True
                if header_param["name"] and re.fullmatch(r"arg\d+", param["name"]):
                    param["name"] = header_param["name"]
                    changed = True

            count = return_count(body)
            dynamic = "MyGUIBindings::pushWidget" in body
            header_returns = None
            if count and len(derived["returns"]) == count:
                header_returns = derived["returns"]
            elif count == 1 and derived["result"]:
                header_returns = derived["result"]
            if header_returns and count == 1:
                old = "|".join(signature.get("returns", [])) if "returns" in signature else ""
                merged = merge(old, header_returns[0], dynamic)
                if merged != old:
                    signature["returns"] = sorted(merged.split("|"))
                    changed = True
            elif header_returns and count and count > 1:
                old_values = signature.get("return_values") or [""] * count
                merged_values = [merge(old, new, dynamic) for old, new in zip(old_values, header_returns)]
                if all(value and not is_weak_type(value) for value in merged_values) and merged_values != old_values:
                    signature["return_values"] = merged_values
                    signature.setdefault("returns", [])
                    changed = True
            if changed:
                signature["type_source"] = "header"

        for prop in entry.get("properties", []):
            dynamic = prop.pop("_dynamic_widget", False)
            if not header_class:
                continue
            member_type = headers.find_member(header_class, prop["name"])[1]
            if not member_type:
                continue
            if member_type.endswith("[]"):
                lua_type = "table"
            else:
                mapped, nullable = mapper.lua_type(member_type)
                if not mapped or mapped.startswith("?"):
                    continue
                lua_type = mapped + ("|nil" if nullable else "")
            if is_weak_type(lua_type):
                continue
            merged = merge(prop.get("type", ""), lua_type, dynamic)
            if merged != prop.get("type", ""):
                prop["type"] = merged
                prop["type_source"] = "header"


def build_inventory():
    implementations = find_binding_implementations()
    reached, unresolved, registry_text = parse_runtime_reachability(implementations)
    inheritance = parse_inheritance(registry_text)
    for binding, implementation in implementations.items():
        parent = parse_local_parent(binding, implementation["body"])
        if parent:
            inheritance[binding] = parent
    classes = []
    for binding in sorted(reached):
        implementation = implementations.get(binding)
        if not implementation:
            continue
        metatable = find_metatable(binding, implementation)
        parent_binding = inheritance.get(binding)
        parent_metatable = ""
        if parent_binding in implementations:
            parent_metatable = find_metatable(parent_binding, implementations[parent_binding])
        body = implementation["body"]
        kind, global_names = classify_binding(body)
        lua_type = lua_type_from_metatable(metatable, binding)
        if kind == "global_table" and len(global_names) == 1:
            lua_type = global_names[0]
        methods = parse_methods(body)
        for method in methods:
            signature = infer_method_signature(method, implementation, binding)
            if signature is not None:
                method["signature"] = signature
                method["_body"] = reachable_body(find_registered_callback_body(
                    implementation["text"], method.get("callback", method["name"]), binding
                ))
        classes.append({
            "binding": binding,
            "kind": kind,
            "lua_type": lua_type,
            "metatable": metatable,
            "source": implementation["path"],
            "registered_from": sorted(reached[binding]),
            "parent_binding": parent_binding,
            "parent_metatable": parent_metatable,
            "global_names": global_names,
            "has_constructor": bool(re.search(r"registerConstructor\s*\(\s*L\s*,", body)),
            "methods": methods,
            "properties": parse_properties(body, implementation["text"]),
        })
    classes.extend(parse_template_instances(reached, implementations))
    headers = kenshilib_headers.build_header_index()
    _, evidence = kenshilib_headers.load_binding_sources()
    mapper = kenshilib_headers.TypeMapper(
        {"classes": [entry for entry in classes if entry["lua_type"]]}, evidence, headers, set()
    )
    name_container_instances(classes, mapper)
    # A binding class named like a registered global enum (YesNoMaybe) is a
    # different runtime type from the enum's integer table: name it apart.
    enum_text = (PROJECT_ROOT / "src" / "Bindings" / "Kenshi" / "EnumBinding.cpp").read_text(
        encoding="utf-8", errors="ignore"
    )
    enum_globals = set(re.findall(r'lua_setglobal\s*\(\s*L\s*,\s*"([A-Za-z_]\w*)"', enum_text))
    for entry in classes:
        if entry["kind"] == "class" and entry["lua_type"] in enum_globals:
            renamed = entry["lua_type"] + "Value"
            for key, value in list(mapper.cpp_to_lua.items()):
                if value == entry["lua_type"]:
                    mapper.cpp_to_lua[key] = renamed
            entry["lua_type"] = renamed
    lua_types_by_metatable = {
        entry["metatable"]: entry["lua_type"]
        for entry in classes
        if entry.get("metatable") and entry["kind"] != "global_table"
    }
    # A global-table binding can share an object metatable (MyGUIBinding uses
    # MyGUI.Widget's), so objects pushed with it are instances of that class.
    lua_types_by_binding = {
        entry["binding"]: (
            lua_types_by_metatable.get(entry.get("metatable"), entry["lua_type"])
            if entry["kind"] == "global_table" else entry["lua_type"]
        )
        for entry in classes
    }
    for entry in classes:
        if entry.get("metatable") and entry["metatable"] not in lua_types_by_metatable:
            lua_types_by_metatable[entry["metatable"]] = entry["lua_type"]
        for alias in entry.get("binding_aliases", []):
            lua_types_by_binding.setdefault(alias, entry["lua_type"])
        for alias in entry.get("metatable_aliases", []):
            lua_types_by_metatable.setdefault(alias, entry["lua_type"])

    def resolve_placeholder(lua_type, owner):
        if "|" in lua_type:
            parts = {resolve_placeholder(part, owner) for part in lua_type.split("|")}
            if parts - {"any", "nil"}:
                parts.discard("any")
            return "|".join(sorted(parts))
        if lua_type == SELF_TYPE:
            return owner
        if lua_type.startswith("ref:"):
            kind, _, name = lua_type[len("ref:"):].partition(":")
            lookup = lua_types_by_binding if kind == "binding" else lua_types_by_metatable
            return lookup.get(name, "any")
        if not lua_type.startswith("array:"):
            return lua_type
        elements = set()
        for ref in lua_type[len("array:"):].split(","):
            kind, _, name = ref.partition(":")
            lookup = {"binding": lua_types_by_binding, "metatable": lua_types_by_metatable}.get(kind)
            resolved = ref if lookup is None else lookup.get(name)
            if not resolved:
                return "table"
            elements.add(resolved)
        joined = "|".join(sorted(elements))
        return ("(" + joined + ")" if len(elements) > 1 else joined) + "[]"

    for entry in classes:
        for method in entry.get("methods", []):
            signature = method.get("signature")
            if not signature:
                continue
            for param in signature.get("params", []):
                param["type"] = resolve_placeholder(param["type"], entry["lua_type"])
            if "returns" in signature:
                signature["returns"] = sorted(
                    resolve_placeholder(item, entry["lua_type"]) for item in signature["returns"]
                )
            return_value_refs = signature.pop("return_value_refs", [])
            return_values = []
            for slot in return_value_refs:
                slot_types = set()
                for ref in slot:
                    kind, _, name = ref.partition(":")
                    lookup = {
                        "binding": lua_types_by_binding,
                        "metatable": lua_types_by_metatable,
                    }.get(kind)
                    if lookup is None:
                        slot_types.add(ref)
                    elif name in lookup:
                        slot_types.add(lookup[name])
                    else:
                        slot_types = None
                        break
                if slot_types is None:
                    return_values = []
                    break
                return_values.append("|".join(sorted(slot_types)))
            if return_values:
                signature["return_values"] = return_values
            has_return_contract = "returns" in signature or "return_values" in signature
            return_bindings = signature.pop("return_bindings", [])
            return_metatables = signature.pop("return_metatables", [])
            return_types = set(signature.get("returns", []))
            return_types.update(
                lua_types_by_binding[binding]
                for binding in return_bindings
                if binding in lua_types_by_binding
            )
            return_types.update(
                lua_types_by_metatable[metatable]
                for metatable in return_metatables
                if metatable in lua_types_by_metatable
            )
            if return_types or has_return_contract:
                signature["returns"] = sorted(return_types)
            elif re.fullmatch(r"operator_(?:[A-Za-z]+_)?assign", method["name"]):
                signature["returns"] = [entry["lua_type"]]
        for prop in entry.get("properties", []):
            has_getter_contract = any(key in prop for key in (
                "return_types", "return_bindings", "return_metatables"
            ))
            return_bindings = prop.pop("return_bindings", [])
            return_metatables = prop.pop("return_metatables", [])
            return_types = {
                resolve_placeholder(item, entry["lua_type"]) for item in prop.pop("return_types", [])
            }
            setter_types = prop.pop("setter_types", [])
            return_types.update(
                lua_types_by_binding[binding]
                for binding in return_bindings
                if binding in lua_types_by_binding
            )
            return_types.update(
                lua_types_by_metatable[metatable]
                for metatable in return_metatables
                if metatable in lua_types_by_metatable
            )
            used_setter_types = bool(setter_types) and (
                not return_types or return_types == {"MyGUI.Widget"}
            )
            if used_setter_types:
                return_types = set(setter_types)
            if return_types:
                prop["type"] = "|".join(sorted(return_types))
                if used_setter_types:
                    prop["type_source"] = "setter"
    apply_header_types(classes, lua_types_by_metatable, headers, mapper)
    inventory = {
        "schema_version": 4,
        "runtime_version": read_version(),
        "sources": {
            "class_registration": "src/Lua/RegisterBindings.cpp",
            "binding_sources": "src/Bindings",
        },
        "classes": classes,
        "global_functions": parse_global_functions(),
        "unresolved_registration_calls": unresolved,
    }
    validate_inventory(inventory)
    return inventory


def serialize(inventory):
    return json.dumps(inventory, indent=2, sort_keys=True) + "\n"


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true", help="Fail if the committed inventory is stale.")
    args = parser.parse_args()
    generated = serialize(build_inventory())
    if args.check:
        existing = OUTPUT_PATH.read_text(encoding="utf-8") if OUTPUT_PATH.exists() else ""
        if existing != generated:
            print("LuaLS binding inventory is stale. Run: python tools/luals/generate_binding_inventory.py")
            return 1
        print("LuaLS binding inventory is up to date.")
        return 0
    OUTPUT_PATH.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT_PATH.write_text(generated, encoding="utf-8", newline="\n")
    print("Generated " + str(OUTPUT_PATH.relative_to(PROJECT_ROOT)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
