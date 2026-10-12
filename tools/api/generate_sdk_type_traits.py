"""Generate top-level C++ SDK type traits from registered binding sources.

The runtime binding implementation is authoritative: each generated class
binding identifies its receiver type through getInstance() and its Lua
metatable through getMetatableName(). Nested class types are intentionally not
emitted because they cannot be forward-declared without defining their owner;
consumers register those after including the owning KenshiLib header.
"""

from __future__ import print_function

import argparse
import pathlib
import re
import sys


ROOT = pathlib.Path(__file__).resolve().parents[2]
HEADER = ROOT / "include" / "KenshiLua.h"
BINDINGS = ROOT / "src" / "Bindings"
KENSHILIB_INCLUDE = ROOT / "extern" / "KenshiLib" / "Include"

FORWARD_BEGIN = "/* KENSHILUA_GENERATED_FORWARD_DECLARATIONS_BEGIN */"
FORWARD_END = "/* KENSHILUA_GENERATED_FORWARD_DECLARATIONS_END */"
TRAITS_BEGIN = "    /* KENSHILUA_GENERATED_TYPE_TRAITS_BEGIN */"
TRAITS_END = "    /* KENSHILUA_GENERATED_TYPE_TRAITS_END */"

KNOWN_NAMESPACES = frozenset(("KenshiLib", "MyGUI", "Ogre", "OIS", "wraps"))


def replace_region(text, begin, end, body):
    start = text.index(begin) + len(begin)
    finish = text.index(end, start)
    return text[:start] + "\n" + body.rstrip() + "\n" + text[finish:]


def resolve_alias(type_name, source):
    seen = set()
    while "::" not in type_name and type_name not in seen:
        seen.add(type_name)
        match = re.search(
            r"\btypedef\s+([A-Za-z_]\w*(?:::[A-Za-z_]\w*)*)\s+" +
            re.escape(type_name) + r"\s*;",
            source,
        )
        if not match:
            break
        type_name = match.group(1)
    return type_name


def top_level_declarations():
    names = {}
    if not KENSHILIB_INCLUDE.is_dir():
        return names
    pattern = re.compile(
        r"^(class|struct)\s+(?:\w+\s+)*([A-Za-z_]\w*)\b([^\n]*)",
        re.MULTILINE,
    )
    for path in KENSHILIB_INCLUDE.rglob("*.h"):
        source = path.read_text(encoding="utf-8", errors="ignore")
        for kind, name, tail in pattern.findall(source):
            is_definition = "{" in tail
            previous = names.get(name)
            if not previous or is_definition:
                names[name] = (kind, is_definition)
    return names


def binding_records():
    declared = top_level_declarations()
    records = {}
    receiver_pattern = re.compile(
        r"\bstatic\s+([A-Za-z_]\w*(?:::[A-Za-z_]\w*)*)\s*\*\s*"
        r"getInstance\s*\("
    )

    for cpp in BINDINGS.rglob("*Binding.cpp"):
        source = cpp.read_text(encoding="utf-8", errors="ignore")
        receiver = receiver_pattern.search(source)
        if not receiver:
            continue
        cpp_type = resolve_alias(receiver.group(1), source)

        binding = cpp.stem
        header = cpp.with_suffix(".h")
        if not header.is_file():
            candidates = list(BINDINGS.rglob(binding + ".h"))
            if not candidates:
                continue
            header = candidates[0]
        header_source = header.read_text(encoding="utf-8", errors="ignore")
        metatable = re.search(
            r"\bclass\s+" + re.escape(binding) +
            r"\b.*?getMetatableName\s*\(\)\s*\{?\s*return\s*\"([^\"]+)\"",
            header_source,
            re.DOTALL,
        )
        if not metatable:
            continue

        parts = cpp_type.split("::")
        if len(parts) == 1:
            if cpp_type not in declared:
                continue
        elif len(parts) == 2:
            if parts[0] not in KNOWN_NAMESPACES:
                continue
        else:
            continue

        previous = records.get(cpp_type)
        if previous and previous != metatable.group(1):
            raise ValueError("conflicting metatables for {0}: {1}, {2}".format(
                cpp_type, previous, metatable.group(1)))
        records[cpp_type] = metatable.group(1)
    return records, declared


def render(records, declarations):
    globals_ = sorted(name for name in records if "::" not in name)
    namespaces = {}
    for name in records:
        if "::" in name:
            namespace, short_name = name.split("::")
            namespaces.setdefault(namespace, []).append(short_name)

    forward = [
        "{0} {1};".format(declarations.get(name, ("class", False))[0], name)
        for name in globals_
    ]
    for namespace in sorted(namespaces):
        forward.append("namespace {0}".format(namespace))
        forward.append("{")
        forward.extend("    class {0};".format(name) for name in sorted(namespaces[namespace]))
        forward.append("}")

    traits = [
        "    template <> struct TypeTraits<{0}> {{ static const char* Metatable() {{ return \"{1}\"; }} }};".format(
            name, records[name]
        )
        for name in sorted(records)
    ]
    return "\n".join(forward), "\n".join(traits)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()

    text = HEADER.read_text(encoding="utf-8")
    records, declarations = binding_records()
    forward, traits = render(records, declarations)
    generated = replace_region(text, FORWARD_BEGIN, FORWARD_END, forward)
    generated = replace_region(generated, TRAITS_BEGIN, TRAITS_END, traits)

    if args.check:
        if generated != text:
            print(str(HEADER.relative_to(ROOT)) + " is out of date", file=sys.stderr)
            return 1
        return 0

    HEADER.write_text(generated, encoding="utf-8", newline="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
