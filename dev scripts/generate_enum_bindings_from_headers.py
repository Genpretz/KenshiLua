# generate_enum_bindings_from_headers.py

# This script takes a header as an argument and outputs a $(HeaderFilename)EnumBinding.cpp and $(HeaderFilename)EnumBinding.h
# with bindings for any enums found within the header file.

import re
import sys
from pathlib import Path


ENUM_BLOCK_RE = re.compile(
    r"(?:class|namespace)?\s*(\w+)?\s*\{[^}]*enum(?:\s+class)?\s*(\w+)?\s*\{([^}]*)\}",
    re.MULTILINE | re.DOTALL
)

ENUM_VALUE_RE = re.compile(
    r"(\w+)\s*(?:=\s*([^,\n]+))?"
)

def extract_enums(text):
    enums = []

    i = 0
    n = len(text)

    while True:
        # find next enum keyword
        i = text.find("enum", i)
        if i == -1:
            break

        # skip "enum class" / "enum struct"
        header_end = text.find("{", i)
        if header_end == -1:
            i += 4
            continue

        header = text[i:header_end]

        # extract enum name
        m = re.search(r"enum(?:\s+class|\s+struct)?\s*(\w+)?", header)
        enum_name = m.group(1) if m and m.group(1) else "AnonymousEnum"

        # find matching braces
        j = header_end + 1
        depth = 1

        while j < len(text) and depth > 0:
            if text[j] == "{":
                depth += 1
            elif text[j] == "}":
                depth -= 1
            j += 1

        body = text[header_end + 1 : j - 1]

        # parse values
        values = []
        for line in body.split(","):
            line = line.strip()
            if not line:
                continue

            name = line.split("=")[0].strip()

            # filter junk
            if not re.match(r"^[A-Za-z_]\w*$", name):
                continue

            values.append((name, None))

        enums.append((enum_name, values))

        i = j

    return enums


def generate_cpp(filename, enums):
    base = Path(filename).stem
    class_name = f"{base}EnumBinding"

    out = []

    out.append(f"#include \"pch.h\"\n#include \"Lua/BindingHelpers.h\"\n")
    out.append("extern \"C\" {\n#include <lua.h>\n#include <lauxlib.h>\n}\n\n")
    out.append("namespace KenshiLua\n{\n\n")

    for enum_name, values in enums:
        func_name = f"register{enum_name}"

        out.append(f"void {class_name}::{func_name}(lua_State* L)\n{{\n")
        out.append("    lua_newtable(L);\n\n")

        for name, value in values:
            out.append(f"    setEnum(L, \"{name}\", {enum_name}::{name});\n")

        out.append("    lua_setglobal(L, \"" + enum_name + "\");\n")
        out.append("}\n\n")

    out.append("} // namespace KenshiLua\n")

    return "".join(out)


def generate_header(filename, enums):
    base = Path(filename).stem
    class_name = f"{base}EnumBinding"

    out = []
    out.append("#pragma once\n\n")
    out.append("#include <lua.h>\n\n")
    out.append("namespace KenshiLua\n{\n\n")
    out.append(f"class {class_name}\n{{\npublic:\n")

    for enum_name, _ in enums:
        out.append(f"    static void register{enum_name}(lua_State* L);\n")

    out.append("};\n\n} // namespace KenshiLua\n")

    return "".join(out)


def main():
    if len(sys.argv) < 2:
        print("Usage: python generate_enum_bindings_from_headers.py <header.h>")
        return

    file_path = sys.argv[1]
    text = Path(file_path).read_text(errors="ignore")

    enums = extract_enums(text)

    base = Path(file_path).stem

    out_cpp = base + "EnumBinding.cpp"
    out_h   = base + "EnumBinding.h"

    cpp = generate_cpp(file_path, enums)
    header = generate_header(file_path, enums)

    Path(out_cpp).write_text(cpp)
    Path(out_h).write_text(header)

    print(f"Generated {len(enums)} enum bindings")


if __name__ == "__main__":
    main()