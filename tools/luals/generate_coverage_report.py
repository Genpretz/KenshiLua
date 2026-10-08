"""Generate an inventory-to-metadata coverage report for the LuaLS addon.

The report tracks only API evidence represented by binding_inventory.json. It
does not infer signatures and does not treat a discovered member name as a
reviewed contract.

Usage:
    python tools/luals/generate_coverage_report.py
    python tools/luals/generate_coverage_report.py --check
    python tools/luals/generate_coverage_report.py --check --require-complete
"""

import argparse
import json
import pathlib
import re
import sys


PROJECT_ROOT = pathlib.Path(__file__).resolve().parents[2]
INVENTORY_PATH = PROJECT_ROOT / "luals" / "generated" / "binding_inventory.json"
DEFINITIONS_PATH = PROJECT_ROOT / "luals" / "generated" / "kenshilua.lua"
# Globals the runtime sets for its own use, not part of the scripting API.
INTERNAL_GLOBALS = {"_benchGcStore"}
METADATA_PATH = PROJECT_ROOT / "luals" / "metadata" / "runtime.json"
DESCRIPTION_PATH = PROJECT_ROOT / "luals" / "metadata" / "kenshilib_descriptions.json"
OUTPUT_PATH = PROJECT_ROOT / "luals" / "generated" / "coverage_report.json"


def expand_inventory_fields(metadata, inventory):
    """Mirror generator expansion for inventory-backed class declarations."""
    by_type = {entry["lua_type"]: entry for entry in inventory.get("classes", [])}
    expanded = json.loads(json.dumps(metadata))
    metatable_types = {
        entry["metatable"]: entry["lua_type"]
        for entry in inventory.get("classes", [])
        if entry.get("metatable")
    }
    classes = {entry["name"]: entry for entry in expanded.setdefault("classes", [])}
    globals_ = {entry["name"]: entry for entry in expanded.setdefault("globals", [])}
    for source in inventory.get("classes", []):
        name = source["lua_type"]
        parent = metatable_types.get(source.get("parent_metatable", ""), "")
        class_entry = classes.get(name)
        if class_entry is None:
            class_entry = {"name": name, "fields": []}
            if parent:
                class_entry["parent"] = parent
            if source.get("has_constructor"):
                class_entry["overloads"] = ["fun(...: any): " + name]
            expanded["classes"].append(class_entry)
            classes[name] = class_entry
        elif parent and not class_entry.get("parent"):
            class_entry["parent"] = parent
        if source.get("has_constructor") and not class_entry.get("overloads"):
            class_entry["overloads"] = ["fun(...: any): " + name]
        for global_name in source.get("global_names", []):
            if global_name not in globals_:
                globals_[global_name] = {
                    "name": global_name,
                    "type": name,
                    "initialValue": "{}",
                }
                expanded["globals"].append(globals_[global_name])
    for class_entry in expanded.get("classes", []):
        inventory_name = class_entry.get("inventory_fields") or class_entry.get("name")
        if inventory_name not in by_type:
            continue
        source = by_type.get(inventory_name)
        if not source:
            raise ValueError("inventory-backed class not found: " + inventory_name)
        fields = class_entry.setdefault("fields", [])
        names = {field["name"] for field in fields}
        lua_type = class_entry["name"]
        for method in source.get("methods", []):
            if method["name"] not in names:
                signature = method.get("signature")
                if signature is not None:
                    params = [
                        param["name"] + ("?" if param.get("optional") else "") + ": " + param["type"]
                        for param in signature.get("params", [])
                    ]
                    if not method.get("static"):
                        params.insert(0, "self: " + lua_type)
                    method_type = "fun(" + ", ".join(params) + "): any"
                else:
                    method_type = "fun(...: any): any" if method.get("static") else "fun(self: " + lua_type + ", ...: any): any"
                fields.append({"name": method["name"], "type": method_type})
                names.add(method["name"])
        for prop in source.get("properties", []):
            if prop["name"] not in names:
                fields.append({"name": prop["name"], "type": "any"})
                names.add(prop["name"])
    return expanded


def inherited_fields(class_name, classes):
    """Return fields declared by a metadata class and its reviewed parents."""
    fields = set()
    seen = set()
    current = class_name
    while current and current not in seen:
        seen.add(current)
        entry = classes.get(current)
        if not entry:
            break
        fields.update(field["name"] for field in entry.get("fields", []))
        current = entry.get("parent")
    return fields


def type_from_metatable(metatable, metatable_types):
    if not metatable:
        return ""
    if metatable in metatable_types:
        return metatable_types[metatable]
    prefix = "KenshiLua."
    return metatable[len(prefix):] if metatable.startswith(prefix) else metatable


def emitted_globals():
    """Global names the generated definitions actually declare."""
    text = DEFINITIONS_PATH.read_text(encoding="utf-8") if DEFINITIONS_PATH.exists() else ""
    return set(re.findall(r"^(?:function\s+)?([A-Za-z_]\w*)\s*(?:=|\()", text, re.MULTILINE))


def runtime_globals():
    """Every global the C++ source installs with lua_setglobal, by name."""
    found = {}
    for path in sorted((PROJECT_ROOT / "src").rglob("*")):
        if path.suffix not in (".cpp", ".h"):
            continue
        text = path.read_text(encoding="utf-8", errors="ignore")
        text = re.sub(r"/\*.*?\*/", "", text, flags=re.DOTALL)
        text = re.sub(r"//[^\n]*", "", text)
        for name in re.findall(r'lua_setglobal\s*\(\s*L\s*,\s*"([A-Za-z_]\w*)"', text):
            found.setdefault(name, set()).add(path.relative_to(PROJECT_ROOT).as_posix())
    return {name: sorted(sources) for name, sources in found.items() if name not in INTERNAL_GLOBALS}


def percent(covered, total):
    return round(100.0 * covered / total, 1) if total else 100.0


def has_method_description(name, documentation_sources):
    """Return whether KenshiLib documents this method or its virtual base name."""
    base_name = name[4:] if name.startswith("_NV_") else name
    return any(
        name in methods or (name.startswith("_NV_") and base_name in methods)
        for methods in documentation_sources
    )


def build_report():
    inventory = json.loads(INVENTORY_PATH.read_text(encoding="utf-8"))
    metadata = json.loads(METADATA_PATH.read_text(encoding="utf-8"))
    metadata = expand_inventory_fields(metadata, inventory)
    classes = {entry["name"]: entry for entry in metadata.get("classes", [])}
    globals_ = {entry["name"]: entry for entry in metadata.get("globals", [])}
    functions = {entry["name"]: entry for entry in metadata.get("functions", [])}
    descriptions = {}
    if DESCRIPTION_PATH.exists():
        descriptions = json.loads(DESCRIPTION_PATH.read_text(encoding="utf-8")).get("classes", {})

    inventory_types = [entry["lua_type"] for entry in inventory["classes"]]
    if len(inventory_types) != len(set(inventory_types)):
        raise ValueError("binding inventory contains duplicate Lua type identities")

    metatable_types = {
        entry["metatable"]: entry["lua_type"]
        for entry in inventory["classes"]
        if entry.get("metatable")
    }
    bindings_by_name = {entry["binding"]: entry for entry in inventory["classes"]}
    emitted = emitted_globals()

    totals = {
        "bindings": 0,
        "declared_bindings": 0,
        "complete_bindings": 0,
        "methods": 0,
        "covered_methods": 0,
        "signature_methods": 0,
        "methods_with_signatures": 0,
        "methods_with_inferred_returns": 0,
        "methods_with_kenshilib_descriptions": 0,
        "engine_methods": 0,
        "properties": 0,
        "covered_properties": 0,
        "properties_with_inferred_types": 0,
        "properties_with_kenshilib_descriptions": 0,
        "globals": 0,
        "covered_globals": 0,
        "constructors": 0,
        "covered_constructors": 0,
        "inheritance_links": 0,
        "covered_inheritance_links": 0,
        "functions": 0,
        "covered_functions": 0,
    }
    bindings = []

    for entry in inventory["classes"]:
        lua_type = entry["lua_type"]
        instance_class = classes.get(lua_type)
        instance_fields = inherited_fields(lua_type, classes)
        documentation_sources = []
        current = entry
        seen_bindings = set()
        while current and current["binding"] not in seen_bindings:
            seen_bindings.add(current["binding"])
            documentation_sources.append(
                descriptions.get(current["lua_type"], {}).get("methods", {})
            )
            current = bindings_by_name.get(current.get("parent_binding"))
        property_descriptions = descriptions.get(lua_type, {}).get("properties", {})

        global_results = []
        static_fields = set()
        constructor_declared = not entry.get("has_constructor", False)
        for name in entry.get("global_names", []):
            global_entry = globals_.get(name)
            declared = global_entry is not None and name in emitted
            global_type = global_entry.get("type", "") if global_entry else ""
            global_class = classes.get(global_type)
            if global_class:
                static_fields.update(inherited_fields(global_type, classes))
                if global_class.get("overloads"):
                    constructor_declared = True
            global_results.append({
                "name": name,
                "declared": declared,
                "declared_type": global_type,
            })

        method_results = []
        for method in entry.get("methods", []):
            fields = static_fields if method.get("static") else instance_fields
            covered = method["name"] in fields
            method_results.append({
                "name": method["name"],
                "static": method.get("static", False),
                "covered": covered,
                "has_signature": bool(method.get("signature")),
                "has_inferred_return": (
                    "returns" in method.get("signature", {})
                    or "return_values" in method.get("signature", {})
                ),
                "has_kenshilib_description": has_method_description(
                    method["name"], documentation_sources
                ),
            })
            totals["signature_methods"] += 1
            totals["methods_with_signatures"] += int(bool(method.get("signature")))
            totals["methods_with_inferred_returns"] += int(
                "returns" in method.get("signature", {})
                or "return_values" in method.get("signature", {})
            )
            # Container templates are KenshiLua's own API, not KenshiLib's.
            if entry.get("kind") != "template_instance":
                totals["engine_methods"] += 1
                totals["methods_with_kenshilib_descriptions"] += int(
                    has_method_description(method["name"], documentation_sources)
                )

        property_results = []
        for prop in entry.get("properties", []):
            property_results.append({
                "name": prop["name"],
                "access": prop["access"],
                "covered": prop["name"] in instance_fields,
                "has_inferred_type": bool(prop.get("type")),
                "has_kenshilib_description": prop["name"] in property_descriptions,
            })

        expected_parent = type_from_metatable(entry.get("parent_metatable", ""), metatable_types)
        declared_parent = instance_class.get("parent", "") if instance_class else ""
        inheritance_declared = not expected_parent or declared_parent == expected_parent

        if entry["kind"] == "global_table":
            binding_declared = bool(global_results) and all(item["declared"] for item in global_results)
        else:
            binding_declared = instance_class is not None

        globals_declared = all(item["declared"] for item in global_results)
        methods_declared = all(item["covered"] for item in method_results)
        properties_declared = all(item["covered"] for item in property_results)
        complete = all((
            binding_declared,
            globals_declared,
            methods_declared,
            properties_declared,
            constructor_declared,
            inheritance_declared,
        ))

        totals["bindings"] += 1
        totals["declared_bindings"] += int(binding_declared)
        totals["complete_bindings"] += int(complete)
        totals["methods"] += len(method_results)
        totals["covered_methods"] += sum(item["covered"] for item in method_results)
        totals["properties"] += len(property_results)
        totals["covered_properties"] += sum(item["covered"] for item in property_results)
        totals["properties_with_inferred_types"] += sum(
            item["has_inferred_type"] for item in property_results
        )
        totals["properties_with_kenshilib_descriptions"] += sum(
            item["has_kenshilib_description"] for item in property_results
        )
        totals["globals"] += len(global_results)
        totals["covered_globals"] += sum(item["declared"] for item in global_results)
        if entry.get("has_constructor", False):
            totals["constructors"] += 1
            totals["covered_constructors"] += int(constructor_declared)
        if expected_parent:
            totals["inheritance_links"] += 1
            totals["covered_inheritance_links"] += int(inheritance_declared)

        bindings.append({
            "binding": entry["binding"],
            "lua_type": lua_type,
            "kind": entry["kind"],
            "declared": binding_declared,
            "complete": complete,
            "expected_parent": expected_parent,
            "declared_parent": declared_parent,
            "inheritance_declared": inheritance_declared,
            "constructor_required": entry.get("has_constructor", False),
            "constructor_declared": constructor_declared,
            "globals": global_results,
            "method_count": len(method_results),
            "covered_method_count": sum(item["covered"] for item in method_results),
            "methods_with_inferred_returns": sum(
                item["has_inferred_return"] for item in method_results
            ),
            "methods_with_kenshilib_descriptions": sum(
                item["has_kenshilib_description"] for item in method_results
            ),
            "missing_instance_methods": [
                item["name"]
                for item in method_results
                if not item["covered"] and not item["static"]
            ],
            "missing_static_methods": [
                item["name"]
                for item in method_results
                if not item["covered"] and item["static"]
            ],
            "property_count": len(property_results),
            "covered_property_count": sum(item["covered"] for item in property_results),
            "properties_with_inferred_types": sum(
                item["has_inferred_type"] for item in property_results
            ),
            "properties_with_kenshilib_descriptions": sum(
                item["has_kenshilib_description"] for item in property_results
            ),
            "missing_properties": [
                item["name"]
                for item in property_results
                if not item["covered"]
            ],
        })

    function_results = []
    for entry in inventory.get("global_functions", []):
        covered = entry["name"] in functions
        function_results.append({
            "name": entry["name"],
            "callbacks": entry["callbacks"],
            "sources": entry["sources"],
            "covered": covered,
        })
        totals["functions"] += 1
        totals["covered_functions"] += int(covered)

    installed = runtime_globals()
    undeclared_globals = sorted(name for name in installed if name not in emitted)
    totals["runtime_globals"] = len(installed)
    totals["declared_runtime_globals"] = len(installed) - len(undeclared_globals)

    unresolved = inventory.get("unresolved_registration_calls", [])
    complete = all((
        totals["complete_bindings"] == totals["bindings"],
        totals["covered_functions"] == totals["functions"],
        not undeclared_globals,
        not unresolved,
    ))
    summary = dict(totals)
    summary.update({
        "binding_declaration_percent": percent(totals["declared_bindings"], totals["bindings"]),
        "complete_binding_percent": percent(totals["complete_bindings"], totals["bindings"]),
        "method_percent": percent(totals["covered_methods"], totals["methods"]),
        "signature_percent": percent(totals["methods_with_signatures"], totals["signature_methods"]),
        "inferred_return_percent": percent(
            totals["methods_with_inferred_returns"], totals["signature_methods"]
        ),
        "kenshilib_method_description_percent": percent(
            totals["methods_with_kenshilib_descriptions"], totals["engine_methods"]
        ),
        "property_percent": percent(totals["covered_properties"], totals["properties"]),
        "inferred_property_percent": percent(
            totals["properties_with_inferred_types"], totals["properties"]
        ),
        "kenshilib_property_description_percent": percent(
            totals["properties_with_kenshilib_descriptions"], totals["properties"]
        ),
        "global_percent": percent(totals["covered_globals"], totals["globals"]),
        "function_percent": percent(totals["covered_functions"], totals["functions"]),
        "constructor_percent": percent(totals["covered_constructors"], totals["constructors"]),
        "inheritance_percent": percent(
            totals["covered_inheritance_links"], totals["inheritance_links"]
        ),
        "unresolved_registration_calls": len(unresolved),
        "metadata_classes": len(classes),
        "metadata_globals": len(globals_),
        "metadata_functions": len(functions),
        "complete": complete,
    })

    return {
        "schema_version": 2,
        "runtime_version": inventory["runtime_version"],
        "scope": "runtime bindings represented by binding_inventory.json",
        "summary": summary,
        "bindings": bindings,
        "global_functions": function_results,
        "undeclared_runtime_globals": {name: installed[name] for name in undeclared_globals},
        "unresolved_registration_calls": unresolved,
        "metadata_only_classes": sorted(set(classes) - set(inventory_types)),
        "metadata_only_functions": sorted(
            set(functions) - {entry["name"] for entry in function_results}
        ),
    }


def serialize(report):
    return json.dumps(report, indent=2, sort_keys=True) + "\n"


def print_summary(report):
    summary = report["summary"]
    print(
        "LuaLS coverage: {0}/{1} bindings complete ({2}%), "
        "{3}/{4} methods ({5}%), {6}/{7} properties ({8}%), "
        "{9}/{10} global functions ({11}%), {13}/{14} runtime globals declared, "
        "{12} unresolved registrations.".format(
            summary["complete_bindings"],
            summary["bindings"],
            summary["complete_binding_percent"],
            summary["covered_methods"],
            summary["methods"],
            summary["method_percent"],
            summary["covered_properties"],
            summary["properties"],
            summary["property_percent"],
            summary["covered_functions"],
            summary["functions"],
            summary["function_percent"],
            summary["unresolved_registration_calls"],
            summary["declared_runtime_globals"],
            summary["runtime_globals"],
        )
    )
    for name, sources in sorted(report.get("undeclared_runtime_globals", {}).items()):
        print("  undeclared runtime global: {0} ({1})".format(name, ", ".join(sources)))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true", help="Fail if the committed report is stale.")
    parser.add_argument(
        "--require-complete",
        action="store_true",
        help="Fail until every inventoried binding is reviewed and all registrations resolve.",
    )
    args = parser.parse_args()

    report = build_report()
    generated = serialize(report)
    if args.check:
        existing = OUTPUT_PATH.read_text(encoding="utf-8") if OUTPUT_PATH.exists() else ""
        if existing != generated:
            print("LuaLS coverage report is stale. Run: python tools/luals/generate_coverage_report.py")
            return 1
        print("LuaLS coverage report is up to date.")
    else:
        OUTPUT_PATH.parent.mkdir(parents=True, exist_ok=True)
        OUTPUT_PATH.write_text(generated, encoding="utf-8", newline="\n")
        print("Generated " + str(OUTPUT_PATH.relative_to(PROJECT_ROOT)))

    print_summary(report)
    if args.require_complete and not report["summary"]["complete"]:
        print("LuaLS coverage is incomplete; inspect luals/generated/coverage_report.json.")
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
