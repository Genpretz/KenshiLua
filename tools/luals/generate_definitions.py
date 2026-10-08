"""Generate the versioned KenshiLua definition library for Lua Language Server.

The reviewed contracts live in luals/metadata/runtime.json. Enum names and event
names are extracted from the C++ registrations so a changed registration makes
the generated output drift until it is reviewed and regenerated.

Usage:
    python tools/luals/generate_definitions.py
    python tools/luals/generate_definitions.py --check
"""

import argparse
import json
import pathlib
import re
import sys

PROJECT_ROOT = pathlib.Path(__file__).resolve().parents[2]
METADATA_PATH = PROJECT_ROOT / "luals" / "metadata" / "runtime.json"
ENUM_BINDING_PATH = PROJECT_ROOT / "src" / "Bindings" / "Kenshi" / "EnumBinding.cpp"
HOOK_REGISTRY_PATH = PROJECT_ROOT / "src" / "Hooks" / "Hooks_Registry.cpp"
VERSION_PATH = PROJECT_ROOT / "src" / "Version.h"
OUTPUT_PATH = PROJECT_ROOT / "luals" / "generated" / "kenshilua.lua"
ADDON_LIBRARY_PATH = PROJECT_ROOT / "luals" / "addon" / "kenshilua" / "library" / "kenshilua.lua"
ADDON_CONFIG_PATH = PROJECT_ROOT / "luals" / "addon" / "kenshilua" / "config.json"
INVENTORY_PATH = PROJECT_ROOT / "luals" / "generated" / "binding_inventory.json"
DESCRIPTION_PATH = PROJECT_ROOT / "luals" / "metadata" / "kenshilib_descriptions.json"

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
from extract_enum_values import parse_header_enums
import container_contracts  # noqa: E402


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


def read_version():
    text = VERSION_PATH.read_text(encoding="utf-8")
    values = {}
    for name in ("MAJOR", "MINOR", "PATCH"):
        match = re.search(r"#define\s+KENSHILUA_VERSION_" + name + r"\s+(\d+)", text)
        if not match:
            raise ValueError("missing KENSHILUA_VERSION_" + name)
        values[name] = match.group(1)
    suffix_match = re.search(r'#define\s+KENSHILUA_VERSION_SUFFIX\s+"([^"]*)"', text)
    if not suffix_match:
        raise ValueError("missing KENSHILUA_VERSION_SUFFIX")
    values["SUFFIX"] = suffix_match.group(1)
    return "{0}.{1}.{2}{3}".format(values["MAJOR"], values["MINOR"], values["PATCH"], values["SUFFIX"])


def parse_enums():
    header_values = parse_header_enums()
    text = ENUM_BINDING_PATH.read_text(encoding="utf-8")
    ns_pos = text.find("namespace KenshiLua")
    reg_pos = text.find("void registerEnumBindings(lua_State* L)")
    body_text = text[ns_pos:reg_pos] if ns_pos >= 0 and reg_pos >= 0 else text

    global_enums = {}
    nested_enums = {}
    unmatched = []

    for match in re.finditer(r"void\s+(register\w+)\s*\(lua_State\*\s*L\)", body_text):
        body = find_function_body(body_text, match.group(0))
        globals_set = re.findall(r'lua_setglobal\s*\(\s*L\s*,\s*"([A-Za-z_]\w*)"\s*\)', body)
        nested_set = re.findall(r'setNestedClassTable\s*\(\s*L\s*,\s*"([A-Za-z_]\w*)"\s*,\s*"([A-Za-z_]\w*)"\s*\)', body)
        raw_entries = re.findall(r'setEnum\s*\(\s*L\s*,\s*"([A-Za-z_]\w*)"\s*,\s*([^)]+)\);', body)

        enum_dict = {}
        for key, cxx_sym in raw_entries:
            cxx_sym = cxx_sym.strip()
            val = None
            if cxx_sym in header_values:
                val = header_values[cxx_sym]
            else:
                parts = cxx_sym.split("::")
                if len(parts) >= 2 and f"{parts[-2]}::{parts[-1]}" in header_values:
                    val = header_values[f"{parts[-2]}::{parts[-1]}"]
            if val is None:
                unmatched.append((key, cxx_sym))
                continue
            enum_dict[key] = val

        if enum_dict:
            for name in globals_set:
                global_enums[name] = enum_dict
            for parent, field in nested_set:
                nested_enums.setdefault(parent, {})[field] = enum_dict

    if unmatched:
        sample = ", ".join("{0} ({1})".format(key, symbol) for key, symbol in unmatched[:10])
        raise ValueError(
            "failed to resolve {0} registered enum values from KenshiLib headers; sample: {1}".format(
                len(unmatched), sample
            )
        )

    return (
        dict(sorted(global_enums.items())),
        {p: dict(sorted(fields.items())) for p, fields in sorted(nested_enums.items())}
    )


def parse_event_names():
    text = HOOK_REGISTRY_PATH.read_text(encoding="utf-8")
    names = re.findall(r'\{\s*"([^"]+)"\s*,\s*InstallHook_', text)
    return sorted(set(names))


def emit_comment(lines, description):
    if description:
        for line in description.splitlines():
            lines.append("--- " + line)


def emit_class(lines, entry):
    parent = entry.get("parent")
    suffix = " : " + parent if parent else ""
    emit_comment(lines, entry.get("description"))
    lines.append("---@class " + entry["name"] + suffix)
    for op in entry.get("operators", []):
        lines.append("---@operator " + op)
    for ov in entry.get("overloads", []):
        lines.append("---@overload " + ov)
    for field in entry.get("fields", []):
        emit_comment(lines, field.get("description"))
        lines.append("---@field {0} {1}".format(field["name"], field["type"]))
    lines.append("")


def emit_global(lines, entry):
    emit_comment(lines, entry.get("description"))
    lines.append("---@type " + entry["type"])
    if entry["initialValue"] == "{}":
        lines.append("---@diagnostic disable-next-line: missing-fields")
    lines.append(entry["name"] + " = " + entry["initialValue"])
    lines.append("")


def emit_function(lines, entry):
    emit_comment(lines, entry.get("description"))
    for ov in entry.get("overloads", []):
        lines.append("---@overload " + ov)
    for param in entry.get("params", []):
        lines.append("---@param {0} {1}".format(param["name"], param["type"]))
    for returned in entry.get("returns", []):
        suffix = " " + returned["name"] if returned.get("name") else ""
        lines.append("---@return " + returned["type"] + suffix)
    lines.append("function " + entry["name"] + "(" + ", ".join(param["name"] for param in entry.get("params", [])) + ") end")
    lines.append("")


def expand_inventory_fields(metadata):
    """Expand inventory-backed classes into conservative LuaLS fields.

    Large engine classes are registered through hundreds of repetitive
    ``class_function``/property calls.  Metadata can opt into exposing every
    registered name while source-audited signatures are added incrementally.
    Existing fields always win, so reviewed contracts remain precise.
    """
    requested = {
        entry["name"]: entry.get("inventory_fields")
        for entry in metadata.get("classes", [])
        if entry.get("inventory_fields")
    }
    if not requested:
        return metadata
    inventory = json.loads(INVENTORY_PATH.read_text(encoding="utf-8"))
    by_type = {entry["lua_type"]: entry for entry in inventory.get("classes", [])}
    by_binding = {entry["binding"]: entry for entry in inventory.get("classes", [])}
    descriptions = {}
    if DESCRIPTION_PATH.exists():
        descriptions = json.loads(DESCRIPTION_PATH.read_text(encoding="utf-8")).get("classes", {})
    expanded = json.loads(json.dumps(metadata))
    for class_entry in expanded.get("classes", []):
        inventory_name = class_entry.get("inventory_fields") or class_entry.get("name")
        if inventory_name not in by_type:
            continue
        source = by_type.get(inventory_name)
        if not source:
            raise ValueError("inventory-backed class not found: " + inventory_name)
        lua_type = class_entry["name"]
        static_only = class_entry.pop("static_only", False)
        doc_entry = descriptions.get(lua_type) or descriptions.get(inventory_name, {})
        if doc_entry.get("description") and not static_only:
            class_entry["description"] = doc_entry["description"]
        documentation_sources = [(lua_type, doc_entry.get("methods", {}))]
        property_descriptions = doc_entry.get("properties", {})
        parent_binding = source.get("parent_binding")
        seen_bindings = set()
        while parent_binding and parent_binding not in seen_bindings:
            seen_bindings.add(parent_binding)
            parent_source = by_binding.get(parent_binding)
            if not parent_source:
                break
            parent_type = parent_source["lua_type"]
            parent_entry = descriptions.get(parent_type, {})
            if parent_entry.get("methods"):
                documentation_sources.append((parent_type, parent_entry["methods"]))
            parent_binding = parent_source.get("parent_binding")

        def method_description(name):
            base_name = name[4:] if name.startswith("_NV_") else name
            for source_index, (owner_type, method_descriptions) in enumerate(documentation_sources):
                description = method_descriptions.get(name)
                used_base_name = False
                if not description and name.startswith("_NV_"):
                    description = method_descriptions.get(base_name)
                    used_base_name = bool(description)
                if description:
                    prefix = ""
                    if source_index:
                        prefix += "Inherited API from `{0}`. ".format(owner_type)
                    if used_base_name:
                        prefix += "Override dispatch for `{0}`. ".format(base_name)
                    return prefix + description
            return None

        fields = class_entry.setdefault("fields", [])
        names = {field["name"] for field in fields}
        indexer = None if static_only else source.get("indexer")
        if indexer and "[" + indexer["key"] + "]" not in names:
            fields.append({
                "name": "[" + indexer["key"] + "]",
                "type": indexer["type"],
                "description": "Element access through the container's `__index` metamethod.",
            })
            names.add("[" + indexer["key"] + "]")
        for method in source.get("methods", []):
            name = method["name"]
            if static_only and not method.get("static"):
                continue
            if name not in names:
                signature = method.get("signature")
                if signature is not None:
                    params = [
                        param["name"] + ("?" if param.get("optional") else "") + ": " + param["type"]
                        for param in signature.get("params", [])
                    ]
                    # Static-style callbacks read argument 1 as a value, so
                    # they are called with a dot and take no self.
                    if not method.get("static") and not signature.get("no_self"):
                        params.insert(0, "self: " + lua_type)
                    method_type = "fun(" + ", ".join(params) + ")"
                    if "return_values" in signature:
                        method_type += ": " + ", ".join(signature["return_values"])
                    elif "returns" not in signature:
                        method_type += ": any"
                    elif signature["returns"]:
                        method_type += ": " + "|".join(signature["returns"])
                else:
                    method_type = "fun(...: any): any" if method.get("static") else "fun(self: " + lua_type + ", ...: any): any"
                fields.append({
                    "name": name,
                    "type": method_type,
                    "description": (
                        method_description(name)
                        or (
                            "Reviewed contract of the `{0}` container template.".format(source.get("template"))
                            if signature is not None and signature.get("type_source") == "container"
                            else "Signature inferred from Lua stack checks and callback return pushes in the binding source."
                            if signature is not None
                            else "Registered engine method; signature pending source audit."
                        )
                    ),
                })
                names.add(name)
        for prop in [] if static_only else source.get("properties", []):
            name = prop["name"]
            if name not in names:
                fields.append({
                    "name": name,
                    "type": prop.get("type", "any"),
                    "description": (
                        property_descriptions.get(name)
                        or (
                            "Property type inferred from the binding setter's checked Lua value."
                            if prop.get("type_source") == "setter"
                            else "Property type inferred from the binding getter's callback return pushes."
                        )
                        if prop.get("type")
                        else "Registered engine property; type pending source audit."
                    ),
                })
                names.add(name)
        for field in fields:
            description = method_description(field["name"])
            if description:
                field["description"] = description
            elif field["name"] in property_descriptions:
                field["description"] = property_descriptions[field["name"]]
    return expanded


def add_inventory_forward_declarations(metadata, global_enums, nested_enums):
    """Declare referenced engine object types even before their full API audit."""
    inventory = json.loads(INVENTORY_PATH.read_text(encoding="utf-8"))
    declared = {entry["name"] for entry in metadata.get("classes", [])}
    declared.update(alias["name"] for alias in metadata.get("aliases", []))
    declared.update(global_enums)
    for entry in inventory.get("classes", []):
        lua_type = entry["lua_type"]
        if lua_type not in declared and re.match(r"^[A-Za-z_]\w*(?:\.[A-Za-z_]\w*)*$", lua_type):
            metadata.setdefault("classes", []).append({
                "name": lua_type,
                "description": (
                    "Lua view of the `{0}` container.".format(entry["metatable"])
                    if entry.get("kind") == "template_instance"
                    else "Forward declaration from the registered binding inventory."
                ),
                "fields": [],
            })
            declared.add(lua_type)
    add_container_generics(metadata, inventory, declared)
    add_static_tables(metadata, inventory)
    return metadata


def add_static_tables(metadata, inventory):
    """Declare global tables of static functions (``CombatClass.setup``).

    Each such global gets a ``<Type>Statics`` class holding only the static
    methods, so the global table does not offer the instance API.
    """
    declared_globals = {entry["name"] for entry in metadata.get("globals", [])}
    declared_classes = {entry["name"] for entry in metadata.get("classes", [])}
    for entry in inventory.get("classes", []):
        if entry.get("kind") != "class":
            continue
        for global_name in entry.get("global_names", []):
            if global_name in declared_globals:
                continue
            class_name = entry["lua_type"] + "Statics"
            if class_name not in declared_classes:
                metadata.setdefault("classes", []).append({
                    "name": class_name,
                    "description": "Static functions registered on the `{0}` global table.".format(global_name),
                    "inventory_fields": entry["lua_type"],
                    "static_only": True,
                    "fields": [],
                })
                declared_classes.add(class_name)
            metadata.setdefault("globals", []).append({
                "name": global_name, "type": class_name, "initialValue": "{}",
            })
            declared_globals.add(global_name)


def emit_container_factories(lines, inventory):
    """Declare ``lektor``, ``ogre_unordered_set`` and ``ogre_unordered_map``.

    Each accepted type-name spelling is an overload returning its instance
    type; the declared signature covers class tables and other spellings.
    """
    overloads = container_contracts.factory_overloads(inventory.get("classes", []))
    for global_name, spec in container_contracts.FACTORIES.items():
        rendered = [
            "fun(" + ", ".join('{0}: "{1}"'.format(name, value) for name, value in params) + "): " + lua_type
            for params, lua_type in overloads.get(global_name, [])
        ]
        if global_name == "ogre_unordered_map":
            fallback_params = [("keyType", "string|table"), ("valueType", "string|table")]
        else:
            fallback_params = [("typeName", "string|table")]
        fallback = "fun(" + ", ".join(n + ": " + t for n, t in fallback_params) + "): " + spec["fallback"]
        emit_comment(lines, spec["description"])
        lines.append("---@class " + spec["class"])
        for overload in rendered + [fallback]:
            lines.append("---@overload " + overload)
        lines.append(global_name + " = {}")
        lines.append("")
        emit_comment(lines, "Creates an empty Lua-owned container; raises for an unknown type name.")
        for overload in rendered:
            lines.append("---@overload " + overload)
        for name, type_ in fallback_params:
            lines.append("---@param {0} {1}".format(name, type_))
        lines.append("---@return " + spec["fallback"])
        lines.append("function {0}.new({1}) end".format(global_name, ", ".join(n for n, _ in fallback_params)))
        lines.append("")


def add_container_generics(metadata, inventory, declared):
    """Declare one generic class per container template (``Lektor<T>``).

    Instances are typed as instantiations (``Lektor<Character>``) in the
    inventory, so their own classes are never emitted.
    """
    generics = {}
    for entry in inventory.get("classes", []):
        family = container_contracts.family(entry.get("template", ""))
        if entry.get("kind") != "template_instance" or not family:
            continue
        template, names = generics.setdefault(family[1], (entry["template"], []))
        for method in entry.get("methods", []):
            if method["name"] not in names:
                names.append(method["name"])
    if not generics:
        return
    if container_contracts.ITERATOR_ALIAS["name"] not in declared:
        metadata.setdefault("aliases", []).append(dict(container_contracts.ITERATOR_ALIAS))
    for name in sorted(generics):
        template, names = generics[name]
        metadata.setdefault("classes", []).append(container_contracts.generic_class(template, names))


def generate(metadata, version, global_enums, nested_enums, event_names):
    metadata = add_inventory_forward_declarations(metadata, global_enums, nested_enums)
    metadata = expand_inventory_fields(metadata)
    lines = [
        "---@meta",
        "",
        "-- Generated by tools/luals/generate_definitions.py; DO NOT EDIT.",
        "-- KenshiLua runtime version: " + version,
        "-- Reviewed contracts: luals/metadata/runtime.json",
        "",
    ]
    for alias in metadata.get("aliases", []):
        lines.append("---@alias {0} {1}".format(alias["name"], alias["definition"]))
    lines.append("")
    lines.append("---@alias KenshiLua.EventName")
    for event_name in event_names:
        lines.append('---| "' + event_name + '"')
    lines.append("")

    # Global enums
    for name, entries in global_enums.items():
        lines.append("---@enum " + name)
        lines.append(name + " = {")
        for key, val in entries.items():
            lines.append("    {0} = {1},".format(key, val))
        lines.append("}")
        lines.append("")

    classes_by_name = {c["name"]: c for c in metadata.get("classes", [])}
    globals_by_name = {g["name"]: g for g in metadata.get("globals", [])}

    # Reviewed classes (injecting nested enum fields)
    for entry in metadata.get("classes", []):
        class_entry = dict(entry)
        fields = list(entry.get("fields", []))
        class_name = entry["name"]
        if class_name in nested_enums:
            for f in sorted(nested_enums[class_name].keys()):
                fields.append({
                    "name": f,
                    "type": class_name + "." + f,
                })
        for g in metadata.get("globals", []):
            if g.get("type") == class_name and g.get("name") in nested_enums and g.get("name") != class_name:
                parent_name = g["name"]
                for f in sorted(nested_enums[parent_name].keys()):
                    fields.append({
                        "name": f,
                        "type": parent_name + "." + f,
                    })
        class_entry["fields"] = fields
        emit_class(lines, class_entry)

    # Standalone parent classes for nested enums
    for parent, fields in nested_enums.items():
        if parent not in classes_by_name and parent not in globals_by_name:
            parent_entry = {
                "name": parent,
                "fields": [
                    {
                        "name": f,
                        "type": parent + "." + f,
                    }
                    for f in sorted(fields.keys())
                ],
            }
            emit_class(lines, parent_entry)

    # Reviewed globals
    for entry in metadata.get("globals", []):
        emit_global(lines, entry)

    # Global tables for nested enum parents
    for parent in nested_enums:
        if parent not in globals_by_name:
            lines.append("---@type " + parent)
            lines.append("---@diagnostic disable-next-line: missing-fields")
            lines.append(parent + " = {}")
            lines.append("")

    # Nested enums
    for parent, fields in nested_enums.items():
        for field, entries in fields.items():
            lines.append("---@enum " + parent + "." + field)
            lines.append(parent + "." + field + " = {")
            for key, val in entries.items():
                lines.append("    {0} = {1},".format(key, val))
            lines.append("}")
            lines.append("")

    emit_container_factories(lines, json.loads(INVENTORY_PATH.read_text(encoding="utf-8")))

    # Reviewed functions
    for entry in metadata.get("functions", []):
        emit_function(lines, entry)
    return "\n".join(lines).rstrip() + "\n"


def validate_addon_config():
    if not ADDON_CONFIG_PATH.exists():
        raise ValueError("missing LuaLS addon config: " + str(ADDON_CONFIG_PATH))
    config = json.loads(ADDON_CONFIG_PATH.read_text(encoding="utf-8"))
    if config.get("settings", {}).get("Lua.runtime.version") != "LuaJIT":
        raise ValueError("LuaLS addon must configure Lua.runtime.version as LuaJIT")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true", help="Fail if the committed definitions are stale.")
    args = parser.parse_args()

    metadata = json.loads(METADATA_PATH.read_text(encoding="utf-8"))
    if metadata.get("schemaVersion") != 1:
        raise ValueError("unsupported LuaLS metadata schema")
    validate_addon_config()

    version = read_version()
    try:
        global_enums, nested_enums = parse_enums()
    except (FileNotFoundError, ValueError) as exc:
        print("LuaLS definition generation failed: " + str(exc))
        return 1
    event_names = parse_event_names()
    generated = generate(metadata, version, global_enums, nested_enums, event_names)

    if args.check:
        if not OUTPUT_PATH.exists():
            print("Missing definitions: " + str(OUTPUT_PATH))
            return 1
        if not ADDON_LIBRARY_PATH.exists():
            print("Missing addon definitions: " + str(ADDON_LIBRARY_PATH))
            return 1
        current = OUTPUT_PATH.read_text(encoding="utf-8")
        addon_current = ADDON_LIBRARY_PATH.read_text(encoding="utf-8")
        if current != generated:
            print("Generated definitions are stale. Run: python tools/luals/generate_definitions.py")
            return 1
        if addon_current != generated:
            print("Generated addon definitions are stale. Run: python tools/luals/generate_definitions.py")
            return 1
        print("LuaLS definitions are up to date.")
        return 0

    OUTPUT_PATH.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT_PATH.write_text(generated, encoding="utf-8")
    print("Generated " + str(OUTPUT_PATH.relative_to(PROJECT_ROOT)))

    ADDON_LIBRARY_PATH.parent.mkdir(parents=True, exist_ok=True)
    ADDON_LIBRARY_PATH.write_text(generated, encoding="utf-8")
    print("Generated " + str(ADDON_LIBRARY_PATH.relative_to(PROJECT_ROOT)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
