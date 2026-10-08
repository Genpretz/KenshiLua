"""Audit generated LuaLS member types against bindings and KenshiLib headers.

The binding defines the Lua API, so every generated method must take the
arguments its callback reads from the stack and return the values it pushes.
Types are then compared with the C++ declaration the binding wraps, mapping
C++ types to the Lua values bindings push and treating non-const
primitive/pointer references as extra return values.

A disagreement is blocking when the definitions differ from the binding or
are ``any`` where a type is known.  Where the definitions match the binding
but the binding differs from the declaration (it converts a value, pushes a
raw pointer, or defines its own argument shape) the entry is reported but not
blocking.  Members whose binding is broken in C++ are listed in
luals/metadata/known_binding_bugs.json.

Usage:
    python tools/luals/generate_type_audit.py
    python tools/luals/generate_type_audit.py --check
    python tools/luals/generate_type_audit.py --check --require-correct
"""

import argparse
import json
import pathlib
import re
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

import container_contracts  # noqa: E402
import generate_definitions  # noqa: E402
from kenshilib_headers import (  # noqa: E402
    HeaderIndex, TypeMapper, build_header_index, callback_body, cpp_target,
    expected_signature, instance_type, load_binding_sources, normalize_dual_index, reachable_body,
    split_top_level,
)


PROJECT_ROOT = pathlib.Path(__file__).resolve().parents[2]
INVENTORY_PATH = PROJECT_ROOT / "luals" / "generated" / "binding_inventory.json"
METADATA_PATH = PROJECT_ROOT / "luals" / "metadata" / "runtime.json"
INCLUDE_ROOT = PROJECT_ROOT / "extern" / "KenshiLib" / "Include"
BINDINGS_ROOT = PROJECT_ROOT / "src" / "Bindings"
OUTPUT_PATH = PROJECT_ROOT / "luals" / "generated" / "type_audit.json"
KNOWN_BUGS_PATH = PROJECT_ROOT / "luals" / "metadata" / "known_binding_bugs.json"


# ---------------------------------------------------------------------------
# Lua signature parsing and comparison


def parse_lua_function(type_text):
    match = re.match(r"^fun\((.*?)\)\s*(?::\s*(.*))?$", type_text)
    if not match:
        return None
    params = []
    for item in split_top_level(match.group(1)):
        name, _, lua_type = item.partition(":")
        params.append({"name": name.strip().rstrip("?"), "optional": name.strip().endswith("?"), "type": lua_type.strip()})
    returns = split_top_level(match.group(2)) if match.group(2) else []
    return {"params": params, "returns": returns}


def type_set(lua_type):
    return {part.strip() for part in lua_type.split("|") if part.strip()} - {"nil"}


def compare_type(actual, expected, lua_enums):
    """Return None when compatible, else an issue category."""
    if expected.startswith("?"):
        return "unmapped_header_type"
    actual_set, expected_set = type_set(actual), type_set(expected)
    if actual_set == expected_set:
        return None
    # A C array or vector member is a Lua table; an array type is more precise.
    if expected_set == {"table"} and any(
        item.endswith("[]") or item.startswith(("table<", "{")) for item in actual_set
    ):
        return None
    if "any" in actual_set:
        return "any_with_header_type"
    if expected_set == {"integer"} and actual_set == {"number"}:
        return None
    if expected_set <= set(lua_enums) and actual_set == {"integer"}:
        return "enum_typed_as_integer"
    if not expected_set and actual_set == set():
        return None
    # A binding may require a subclass of the declared type, or accept extra
    # overload types alongside it.
    if actual_set and all(any(is_lua_subtype(a, e) for e in expected_set) for a in actual_set):
        return None
    if expected_set and expected_set < actual_set and "any" not in actual_set:
        return None
    return "type_mismatch"


def audit_method(lua_type, method, field_type, decls, mapper, lua_enums):
    actual = parse_lua_function(field_type)
    if not actual:
        return {"category": "unparsed_lua_type"}
    actual_params = [p for p in actual["params"] if p["name"] != "self"]
    best = None
    variants = [(decl, outs) for decl in decls for outs in (False, True)]
    for decl, outs in variants:
        params, returns = expected_signature(decl, mapper, outs)
        issues = []
        if len(params) != len(actual_params):
            issues.append({"category": "param_count_mismatch", "position": None,
                           "actual": len(actual_params), "expected": len(params)})
        for index, (got, want) in enumerate(zip(actual_params, params)):
            category = compare_type(got["type"], want["type"], lua_enums)
            if category:
                issues.append({"category": category, "position": "param " + str(index + 1),
                               "actual": got["type"], "expected": want["type"]})
        actual_returns = actual["returns"]
        if actual_returns == ["any"] and returns:
            unmapped = any(item.startswith("?") for item in returns)
            issues.append({"category": "unmapped_header_type" if unmapped else "any_with_header_type",
                           "position": "return",
                           "actual": "any", "expected": ", ".join(returns)})
        elif len(actual_returns) != len(returns) and not (returns == [] and actual_returns in ([], ["nil"])):
            issues.append({"category": "return_count_mismatch", "position": "return",
                           "actual": ", ".join(actual_returns) or "(none)",
                           "expected": ", ".join(returns) or "(none)"})
        else:
            for index, (got, want) in enumerate(zip(actual_returns, returns)):
                category = compare_type(got, want, lua_enums)
                if category:
                    issues.append({"category": category, "position": "return " + str(index + 1),
                                   "actual": got, "expected": want})
        score = len(issues)
        if best is None or score < best[0]:
            best = (score, issues, decl, params, returns)
    _, issues, decl, params, returns = best
    return {
        "issues": issues,
        "decl": decl["decl"],
        "expected": "fun(" + ", ".join(p["type"] for p in params) + ")" + (
            ": " + ", ".join(returns) if returns else ""
        ),
    }


STACK_READER = re.compile(
    r"\b(?:luaL_\w+|lua_to\w+|lua_is\w+|lua_type|read\w*|check\w*|test\w*|get\w*|\w+::read|\w+::get)"
    r"\s*(?:<[^;()]*?>)?\s*\(\s*L\s*,\s*(\d+)\s*[,)]"
)


def binding_arity(body, static):
    """Highest Lua argument position a callback reads (excluding self)."""
    positions = [
        int(index) - (0 if static else 1) for index in STACK_READER.findall(body)
    ]
    return max([position for position in positions if position >= 1], default=0)


def binding_return_count(body):
    numeric = {int(value) for value in re.findall(r"\breturn\s+(\d+)\s*;", body)}
    if re.search(r"\breturn\s+(?:\w+::)*push\w*\s*(?:<[^;]*?>)?\s*\(", body):
        numeric.add(1)
    positive = numeric - {0}
    if not positive:
        return 0 if numeric else None
    return positive.pop() if len(positive) == 1 else None


def slot_types(signature):
    """Binding-evidence types per slot from the inventory signature."""
    params = [param["type"] for param in signature.get("params", [])]
    if signature.get("return_values"):
        returns = list(signature["return_values"])
    elif signature.get("returns"):
        returns = ["|".join(signature["returns"])]
    else:
        returns = []
    return params, returns


def binding_difference(evidence):
    """Category for definitions that match a binding differing from its header."""
    if "lightuserdata" in evidence.split("|"):
        return "binding_pushes_raw_pointer"
    return "binding_converts"


def classify_against_binding(issues, parsed, method, body, field_type):
    """Re-rate header issues using what the binding itself reads and pushes.

    The binding defines the Lua API, so the definitions must agree with it:
    a missing parameter or a return count that differs from the binding is
    blocking.  Where the definitions agree with the binding, header
    disagreements (a binding building a ``TPoint`` from two integers, or
    pushing a Lua boolean for ``hkBool``) are reported as non-blocking.
    """
    signature = method.get("signature", {})
    static = method.get("static", False) or signature.get("no_self", False)
    body = reachable_body(normalize_dual_index(body, static))
    params = [param for param in parsed["params"] if param["name"] != "self"]
    returns = [item for item in parsed["returns"] if item not in ("nil",)]
    evidence_params, evidence_returns = slot_types(signature)
    result = []

    arity = binding_arity(body, static)
    if len(params) < arity:
        result.append({"category": "params_missing", "position": None,
                       "actual": len(params), "expected": arity})
    count = binding_return_count(body)
    if count is not None and count != len(returns) and not (count == 1 and parsed["returns"] == ["nil"]):
        if not re.match(r"^\s*return\s+luaL_error\b", body.strip()):
            result.append({"category": "return_count_differs_from_binding", "position": "return",
                           "actual": len(returns), "expected": count})

    shape_differs = any(
        issue["category"] in {"param_count_mismatch", "return_count_mismatch"} for issue in issues
    )
    for issue in issues:
        category = issue["category"]
        if category in {"param_count_mismatch", "return_count_mismatch"}:
            result.append(dict(issue, category="binding_shape_differs"))
            continue
        position = issue.get("position") or ""
        if shape_differs and position.startswith(("param", "return")):
            continue  # positions do not line up with the declaration
        if category in {"type_mismatch", "any_with_header_type"}:
            kind, _, number = position.partition(" ")
            index = int(number) - 1 if number.isdigit() else -1
            evidence_list = evidence_params if kind == "param" else evidence_returns
            evidence = evidence_list[index] if 0 <= index < len(evidence_list) else ""
            weak = not evidence or set(evidence.split("|")) <= {"any", "nil"}
            if category == "type_mismatch" and not weak and type_set(evidence) == type_set(issue["actual"]):
                result.append(dict(issue, category=binding_difference(evidence)))
                continue
        result.append(issue)
    return result


def lua_field_types():
    """Read field types from the generated definitions users actually load."""
    classes, parents, current = {}, {}, None
    text = generate_definitions.OUTPUT_PATH.read_text(encoding="utf-8")
    for line in text.splitlines():
        match = re.match(r"^---@class\s+([\w.]+)(?:\s*:\s*([\w.]+))?", line)
        if match:
            current = classes.setdefault(match.group(1), {})
            if match.group(2):
                parents[match.group(1)] = match.group(2)
            continue
        match = re.match(r"^---@field\s+(\w+)\s+(.+)$", line)
        if match and current is not None:
            current.setdefault(match.group(1), match.group(2).strip())
        elif not line.startswith("---"):
            current = None
    resolved = {}
    for name in classes:
        fields, seen, owner = {}, set(), name
        while owner and owner not in seen:
            seen.add(owner)
            for field, field_type in classes.get(owner, {}).items():
                fields.setdefault(field, field_type)
            owner = parents.get(owner)
        resolved[name] = fields
    LUA_PARENTS.clear()
    LUA_PARENTS.update(parents)
    return resolved


LUA_PARENTS = {}


def is_lua_subtype(child, parent):
    seen = set()
    while child and child not in seen:
        if child == parent:
            return True
        seen.add(child)
        child = LUA_PARENTS.get(child)
    return False


def build_report():
    inventory = json.loads(INVENTORY_PATH.read_text(encoding="utf-8"))
    metadata = json.loads(METADATA_PATH.read_text(encoding="utf-8"))
    global_enums, nested_enums = generate_definitions.parse_enums()
    lua_enums = set(global_enums) | {field for fields in nested_enums.values() for field in fields}
    headers = build_header_index()
    callbacks, evidence = load_binding_sources()
    mapper = TypeMapper(inventory, evidence, headers, lua_enums)
    for entry in inventory["classes"]:
        if entry.get("kind") == "template_instance" and container_contracts.family(entry.get("template", "")):
            for spelling in container_contracts.cpp_spellings(entry["template"], entry["template_args"]):
                mapper.cpp_to_lua[TypeMapper.key(spelling)] = entry["lua_type"]
    fields = lua_field_types()

    entries = []
    counts = {}
    known_bugs = {
        (item.get("class") or "metatable:" + item["metatable"], item["member"]): item["reason"]
        for item in json.loads(KNOWN_BUGS_PATH.read_text(encoding="utf-8"))["members"]
    }

    def record(entry, categories):
        owners = [entry["class"]]
        if entry.get("metatable"):
            owners.append("metatable:" + entry["metatable"])
        reason = next((
            known_bugs[key] for owner in owners for key in ((owner, entry["member"]), (owner, "*"))
            if key in known_bugs
        ), None)
        if reason:
            entry = dict(entry, category="known_binding_bug", reason=reason, audited_categories=categories)
            if "issues" in entry:
                entry["audited_issues"] = entry.pop("issues")
            categories = ["known_binding_bug"]
        for category in categories:
            counts[category] = counts.get(category, 0) + 1
        entries.append(entry)

    for binding in sorted(inventory["classes"], key=lambda item: item["lua_type"]):
        lua_type = binding["lua_type"]
        # Container instances (Lektor<Character>) use their generic class.
        class_fields = fields.get(lua_type) or fields.get(lua_type.split("<")[0], {})
        binding_cpp = None
        for method in binding.get("methods", []):
            body = callback_body(callbacks, method["callback"], binding["binding"])
            binding_cpp = binding_cpp or (instance_type(body) if body else None)
        header_class = headers.resolve_class(re.sub(r"<.*$", "", binding_cpp)) if binding_cpp else None
        if not header_class:
            for candidate in (lua_type.replace(".", "::"), lua_type.replace("_", "::")):
                header_class = headers.resolve_class(candidate)
                if header_class:
                    break
        binding_cpp = binding_cpp or header_class or lua_type.replace(".", "::")

        for method in binding.get("methods", []):
            name = method["name"]
            field_type = class_fields.get(name, "")
            base = {"class": lua_type, "member": name, "kind": "method", "lua": field_type}
            if binding.get("kind") == "template_instance":
                base["metatable"] = binding.get("metatable")
            counts["methods"] = counts.get("methods", 0) + 1
            if not field_type:
                record(dict(base, category="missing_field"), ["missing_field"])
                continue
            parsed = parse_lua_function(field_type)
            nil_only = bool(parsed) and parsed["returns"] == ["nil"]
            if binding.get("kind") == "template_instance":
                element_types = set(binding.get("element_types", {}).values())
                if "any" in element_types or re.search(r"\bany\b", field_type) or nil_only:
                    record(dict(base, category="container_element_untyped",
                                cpp=binding.get("metatable")), ["container_element_untyped"])
                else:
                    counts["container_methods_typed"] = counts.get("container_methods_typed", 0) + 1
                continue
            body = callback_body(callbacks, method["callback"], binding["binding"])
            cls, target = cpp_target(body, name, method.get("static", False), binding_cpp) if body else (binding_cpp, name)
            resolved = headers.resolve_class(re.sub(r"<.*$", "", cls)) or header_class
            decls = headers.find_methods(resolved, target)[1] if resolved else []
            if not decls:
                binding_issues = classify_against_binding([], parsed, method, body, field_type) if (
                    parsed and body
                ) else []
                category = "no_header_declaration"
                if re.search(r"\bany\b", field_type):
                    category = "any_without_header"
                elif nil_only:
                    category = "nil_only_return"
                categories = [category] + sorted({issue["category"] for issue in binding_issues})
                record(dict(base, category=category, cpp=(cls or "") + "::" + target,
                            **({"issues": binding_issues} if binding_issues else {})), categories)
                continue
            result = audit_method(lua_type, method, field_type, decls, mapper, lua_enums)
            issues = classify_against_binding(
                result.get("issues", []), parsed, method, body, field_type
            )
            if not issues:
                counts["methods_matching_header"] = counts.get("methods_matching_header", 0) + 1
                continue
            categories = sorted({issue["category"] for issue in issues})
            record(dict(base, category=categories[0] if len(categories) == 1 else "multiple",
                        issues=issues, header=result["decl"], expected=result["expected"]),
                   categories)

        for prop in binding.get("properties", []):
            name = prop["name"]
            field_type = class_fields.get(name, prop.get("type", "any"))
            counts["properties"] = counts.get("properties", 0) + 1
            base = {"class": lua_type, "member": name, "kind": "property", "lua": field_type}
            member_type = headers.find_member(header_class, name)[1] if header_class else None
            if not member_type:
                # lightuserdata for an unbound pointer is the honest type.
                category = "any_without_header" if re.search(r"\bany\b", field_type) else "no_header_declaration"
                record(dict(base, category=category), [category])
                continue
            expected, nullable = mapper.lua_type(member_type.replace("[]", ""))
            expected = (expected or "?void") + ("|nil" if nullable else "")
            if member_type.endswith("[]"):
                expected = "table"
            category = compare_type(field_type, expected, lua_enums)
            if category is None and "lightuserdata" in type_set(field_type) and expected != "lightuserdata|nil":
                category = "type_mismatch"
            if (
                category == "type_mismatch"
                and prop.get("type_source") != "header"
                # Equal, or a reviewed union that also documents what the
                # setter accepts (reads lightuserdata, assigns MyGUI.Widget).
                and type_set(prop.get("type", "")) <= type_set(field_type)
                and type_set(prop.get("type", ""))
                and not set(field_type.split("|")) <= {"any", "nil"}
            ):
                # The definitions match what the getter pushes; the binding
                # differs from the declaration (DataCategory pushed as its
                # integer value, or a widget pushed as a raw pointer).
                category = binding_difference(field_type)
            if category is None:
                counts["properties_matching_header"] = counts.get("properties_matching_header", 0) + 1
                continue
            record(dict(base, category=category, header=member_type, expected=expected), [category])

    blocking = {
        "type_mismatch", "any_with_header_type", "params_missing",
        "return_count_differs_from_binding", "any_without_header", "nil_only_return",
        "container_element_untyped", "missing_field",
    }
    summary = dict(sorted(counts.items()))
    summary["blocking_issues"] = sum(
        1 for entry in entries
        if entry["category"] in blocking or any(
            issue["category"] in blocking for issue in entry.get("issues", [])
        )
    )
    return {
        "schema_version": 1,
        "summary": summary,
        "entries": entries,
    }


def serialize(report):
    return json.dumps(report, indent=2, sort_keys=True) + "\n"


def print_summary(report):
    summary = report["summary"]
    print("LuaLS type audit: {0} blocking issues; {1}/{2} methods and {3}/{4} properties match KenshiLib headers.".format(
        summary["blocking_issues"],
        summary.get("methods_matching_header", 0), summary.get("methods", 0),
        summary.get("properties_matching_header", 0), summary.get("properties", 0),
    ))
    for key, value in summary.items():
        if key not in {"blocking_issues", "methods", "properties", "methods_matching_header", "properties_matching_header"}:
            print("  {0}: {1}".format(key, value))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true", help="Fail if the committed audit is stale.")
    parser.add_argument(
        "--require-correct",
        action="store_true",
        help="Fail when any generated type disagrees with its binding or declaration.",
    )
    args = parser.parse_args()
    report = build_report()
    generated = serialize(report)
    if args.check:
        existing = OUTPUT_PATH.read_text(encoding="utf-8") if OUTPUT_PATH.exists() else ""
        if existing != generated:
            print("LuaLS type audit is stale. Run: python tools/luals/generate_type_audit.py")
            return 1
        print("LuaLS type audit is up to date.")
    else:
        OUTPUT_PATH.write_text(generated, encoding="utf-8", newline="\n")
        print("Generated " + str(OUTPUT_PATH.relative_to(PROJECT_ROOT)))
    print_summary(report)
    if args.require_correct and report["summary"]["blocking_issues"]:
        print("LuaLS types have blocking issues; inspect luals/generated/type_audit.json.")
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
