"""C++ enum value extractor for KenshiLib headers.

Extracts accurate numeric values for enums declared in KenshiLib header files.
"""

import pathlib
import re

PROJECT_ROOT = pathlib.Path(__file__).resolve().parents[2]
INCLUDE_DIR = PROJECT_ROOT / "extern" / "KenshiLib" / "Include"
ENUM_BINDING_CPP = PROJECT_ROOT / "src" / "Bindings" / "Kenshi" / "EnumBinding.cpp"


def strip_comments(text):
    text = re.sub(r'//[^\n]*', '', text)
    text = re.sub(r'/\*.*?\*/', '', text, flags=re.DOTALL)
    return text


def parse_header_enums(include_dir=INCLUDE_DIR):
    """Parse all enum definitions from KenshiLib header files."""
    if not include_dir.is_dir():
        raise FileNotFoundError(
            "KenshiLib include directory not found: {0}. "
            "Initialize submodules with: git submodule update --init --recursive".format(include_dir)
        )

    headers = sorted(include_dir.rglob("*.h"))
    if not headers:
        raise ValueError(
            "KenshiLib include directory contains no headers: {0}. "
            "Initialize submodules with: git submodule update --init --recursive".format(include_dir)
        )

    enum_values = {}  # key -> int or (scope, key) -> int

    for header in headers:
        content = header.read_text(encoding="utf-8", errors="ignore")
        content = strip_comments(content)

        # Tokenize by class/struct/enum to track current class scope
        # Find all enum blocks, capturing preceding class name if nested
        class_pos = [(m.start(), m.group(1)) for m in re.finditer(r'\b(?:class|struct)\s+(\w+)', content)]

        enum_matches = re.finditer(
            r'\benum\s+(?:class\s+)?(\w+)?\s*\{([^}]+)\}',
            content,
            re.MULTILINE
        )

        for match in enum_matches:
            pos = match.start()
            enum_name = match.group(1) or ""
            body = match.group(2)

            # Find closest preceding class
            parent_class = ""
            for cp, cname in reversed(class_pos):
                if cp < pos:
                    parent_class = cname
                    break

            current_val = 0
            items = body.split(',')
            for item in items:
                item = item.strip()
                if not item:
                    continue
                if '=' in item:
                    parts = item.split('=', 1)
                    key = parts[0].strip()
                    val_str = parts[1].strip()
                    try:
                        val_str_clean = re.sub(r'[uUlL]', '', val_str).strip()
                        if val_str_clean in enum_values:
                            current_val = enum_values[val_str_clean]
                        else:
                            current_val = int(val_str_clean, 0)
                    except Exception:
                        pass
                else:
                    key = item.strip()

                key = key.split()[0] if key else ""
                if key and re.match(r'^\w+$', key):
                    if key not in enum_values:
                        enum_values[key] = current_val
                    if enum_name:
                        enum_values[f"{enum_name}::{key}"] = current_val
                    if parent_class and enum_name:
                        enum_values[f"{parent_class}::{enum_name}::{key}"] = current_val
                    if parent_class:
                        enum_values[f"{parent_class}::{key}"] = current_val
                    current_val += 1

    return enum_values


def match_enum_bindings():
    try:
        values = parse_header_enums()
    except (FileNotFoundError, ValueError) as exc:
        print("Enum extraction failed: " + str(exc))
        return 1
    content = ENUM_BINDING_CPP.read_text(encoding="utf-8", errors="ignore")
    set_enums = re.findall(r'setEnum\(\s*L\s*,\s*"([^"]+)"\s*,\s*([^)]+)\);', content)

    matched = 0
    unmatched = []

    for key, cxx_sym in set_enums:
        cxx_sym = cxx_sym.strip()
        val = None
        if cxx_sym in values:
            val = values[cxx_sym]
        else:
            # Try stripping leading namespaces if any
            parts = cxx_sym.split("::")
            if len(parts) >= 2 and f"{parts[-2]}::{parts[-1]}" in values:
                val = values[f"{parts[-2]}::{parts[-1]}"]

        if val is not None:
            matched += 1
        else:
            unmatched.append((key, cxx_sym))

    print(f"Total in EnumBinding.cpp: {len(set_enums)}")
    print(f"Matched with exact header values: {matched} / {len(set_enums)} ({matched * 100 // len(set_enums)}%)")
    if unmatched:
        print(f"Unmatched count: {len(unmatched)}")
        print(f"Sample unmatched (first 10): {unmatched[:10]}")
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(match_enum_bindings())
