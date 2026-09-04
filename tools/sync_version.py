#!/usr/bin/env python3
"""
sync_version.py

Synchronizes and validates the version string between src/Version.h (single source of truth)
and Kenshi FCS .mod binary files (such as assets/KenshiLua.mod).

Both the binary mod header integer (e.g. 31 for v0.3.1) and the description string
(e.g. 'Version 0.3.1-alpha') are synchronized and validated.

Usage:
    # Check if assets/KenshiLua.mod matches src/Version.h (returns exit code 1 on mismatch)
    python tools/sync_version.py --check

    # Update assets/KenshiLua.mod in-place from src/Version.h
    python tools/sync_version.py --update

    # Read assets/KenshiLua.mod and output updated copy to build directory
    python tools/sync_version.py --input assets/KenshiLua.mod --output bin/KenshiLua/KenshiLua.mod
"""

import argparse
import os
import pathlib
import re
import struct
import sys

PROJECT_ROOT = pathlib.Path(__file__).resolve().parents[1]
DEFAULT_VERSION_H = PROJECT_ROOT / "src" / "Version.h"
DEFAULT_MOD_FILE = PROJECT_ROOT / "assets" / "KenshiLua.mod"


def parse_version_h(header_path: pathlib.Path) -> dict:
    """Extracts version components and constructed version strings from Version.h."""
    if not header_path.exists():
        raise FileNotFoundError(f"Version header not found: {header_path}")

    content = header_path.read_text(encoding="utf-8", errors="ignore")

    major_match = re.search(r"#define\s+KENSHILUA_VERSION_MAJOR\s+(\d+)", content)
    minor_match = re.search(r"#define\s+KENSHILUA_VERSION_MINOR\s+(\d+)", content)
    patch_match = re.search(r"#define\s+KENSHILUA_VERSION_PATCH\s+(\d+)", content)
    suffix_match = re.search(r'#define\s+KENSHILUA_VERSION_SUFFIX\s+"([^"]*)"', content)
    name_match = re.search(r'#define\s+KENSHILUA_VERSION_NAME\s+"([^"]*)"', content)

    if not (major_match and minor_match and patch_match):
        raise ValueError(f"Failed to parse major/minor/patch versions from {header_path}")

    major = int(major_match.group(1))
    minor = int(minor_match.group(1))
    patch = int(patch_match.group(1))
    suffix = suffix_match.group(1) if suffix_match else ""
    name = name_match.group(1) if name_match else "KenshiLua"

    version_str = f"{major}.{minor}.{patch}{suffix}"
    version_full = f"{name} {version_str}"
    version_int = (major * 100) + (minor * 10) + patch

    return {
        "major": major,
        "minor": minor,
        "patch": patch,
        "suffix": suffix,
        "name": name,
        "version_str": version_str,
        "version_full": version_full,
        "version_int": version_int,
    }


def parse_fcs_mod(data: bytes) -> dict:
    """Parses binary FCS .mod file header and description."""
    if len(data) < 16:
        raise ValueError("File is too small to be a valid FCS mod file.")

    pos = 0
    header_version, = struct.unpack_from("<I", data, pos)
    pos += 4

    header_len, = struct.unpack_from("<I", data, pos)
    pos += 4

    mod_version, = struct.unpack_from("<I", data, pos)
    pos += 4

    author_len, = struct.unpack_from("<I", data, pos)
    pos += 4

    if pos + author_len > len(data):
        raise ValueError("Invalid author length in FCS mod file.")
    author_bytes = data[pos : pos + author_len]
    author = author_bytes.decode("utf-8", errors="ignore")
    pos += author_len

    desc_len, = struct.unpack_from("<I", data, pos)
    pos += 4

    if pos + desc_len > len(data):
        raise ValueError("Invalid description length in FCS mod file.")
    desc_bytes = data[pos : pos + desc_len]
    desc = desc_bytes.decode("utf-8", errors="ignore")
    pos += desc_len

    remainder = data[pos:]

    # Extract version from description text if present
    ver_match = re.search(r"Version\s+([^\r\n]+)", desc)
    extracted_version = ver_match.group(1).strip() if ver_match else None

    return {
        "header_version": header_version,
        "header_len": header_len,
        "mod_version": mod_version,
        "author_len": author_len,
        "author_bytes": author_bytes,
        "author": author,
        "desc_len": desc_len,
        "desc_bytes": desc_bytes,
        "desc": desc,
        "remainder": remainder,
        "extracted_version": extracted_version,
    }


def rebuild_fcs_mod(parsed: dict, new_version_str: str, new_mod_version_int: int) -> bytes:
    """Rebuilds the binary FCS .mod file with an updated version integer and description."""
    old_desc = parsed["desc"]
    if re.search(r"Version\s+[^\r\n]+", old_desc):
        new_desc = re.sub(r"Version\s+[^\r\n]+", f"Version {new_version_str}", old_desc)
    else:
        new_desc = old_desc.rstrip() + f"\r\n\r\nVersion {new_version_str}\r\n"

    new_desc_bytes = new_desc.encode("utf-8")
    new_desc_len = len(new_desc_bytes)

    old_desc_len = parsed["desc_len"]
    old_header_len = parsed["header_len"]
    new_header_len = old_header_len + (new_desc_len - old_desc_len)

    header_prefix = struct.pack(
        "<IIII",
        parsed["header_version"],
        new_header_len,
        new_mod_version_int,
        parsed["author_len"],
    )
    desc_header = struct.pack("<I", new_desc_len)

    return (
        header_prefix
        + parsed["author_bytes"]
        + desc_header
        + new_desc_bytes
        + parsed["remainder"]
    )


def check_version(header_path: pathlib.Path, mod_path: pathlib.Path) -> bool:
    """Validates if both the string version and integer version in mod_path match header_path."""
    ver_info = parse_version_h(header_path)
    expected_ver_str = ver_info["version_str"]
    expected_ver_int = ver_info["version_int"]

    if not mod_path.exists():
        print(f"Error: Mod file does not exist: {mod_path}")
        return False

    with open(mod_path, "rb") as f:
        data = f.read()

    parsed = parse_fcs_mod(data)
    actual_ver_str = parsed["extracted_version"]
    actual_ver_int = parsed["mod_version"]

    mismatches = []
    if actual_ver_str != expected_ver_str:
        mismatches.append(f"Description version: expected '{expected_ver_str}', got '{actual_ver_str}'")
    if actual_ver_int != expected_ver_int:
        mismatches.append(f"Header integer version: expected {expected_ver_int}, got {actual_ver_int}")

    if not mismatches:
        print(
            f"Version check passed: {mod_path.name} matches Version.h "
            f"(string='{expected_ver_str}', integer={expected_ver_int})"
        )
        return True
    else:
        print(f"Version mismatch in {mod_path}:")
        for m in mismatches:
            print(f"  - {m}")
        return False


def update_mod(
    header_path: pathlib.Path, input_path: pathlib.Path, output_path: pathlib.Path
) -> bool:
    """Updates the mod file with the version string and integer from header_path."""
    ver_info = parse_version_h(header_path)
    new_version_str = ver_info["version_str"]
    new_version_int = ver_info["version_int"]

    if not input_path.exists():
        print(f"Error: Input mod file does not exist: {input_path}")
        return False

    with open(input_path, "rb") as f:
        data = f.read()

    parsed = parse_fcs_mod(data)
    new_data = rebuild_fcs_mod(parsed, new_version_str, new_version_int)

    output_path.parent.mkdir(parents=True, exist_ok=True)
    with open(output_path, "wb") as f:
        f.write(new_data)

    print(
        f"Successfully updated {output_path} with version '{new_version_str}' "
        f"(integer={new_version_int})."
    )
    return True


def main():
    parser = argparse.ArgumentParser(
        description="Sync and validate version between src/Version.h and Kenshi FCS .mod files."
    )
    parser.add_argument(
        "--header",
        type=pathlib.Path,
        default=DEFAULT_VERSION_H,
        help=f"Path to Version.h (default: {DEFAULT_VERSION_H.relative_to(PROJECT_ROOT)})",
    )
    parser.add_argument(
        "--input",
        "-i",
        type=pathlib.Path,
        default=DEFAULT_MOD_FILE,
        help=f"Path to input .mod file (default: {DEFAULT_MOD_FILE.relative_to(PROJECT_ROOT)})",
    )
    parser.add_argument(
        "--output",
        "-o",
        type=pathlib.Path,
        default=None,
        help="Path to output .mod file (default: same as input file)",
    )
    parser.add_argument(
        "--check",
        "-c",
        action="store_true",
        help="Validate that the .mod file version matches Version.h without modifying files.",
    )
    parser.add_argument(
        "--update",
        "-u",
        action="store_true",
        help="Update the .mod file with the version from Version.h (default action if not checking).",
    )
    parser.add_argument(
        "--version-only",
        action="store_true",
        help="Print the canonical version string from Version.h and exit.",
    )

    args = parser.parse_args()

    if args.version_only:
        ver_info = parse_version_h(args.header)
        print(ver_info["version_str"])
        sys.exit(0)

    if args.check:
        success = check_version(args.header, args.input)
        sys.exit(0 if success else 1)
    else:
        output_file = args.output if args.output else args.input
        success = update_mod(args.header, args.input, output_file)
        sys.exit(0 if success else 1)


if __name__ == "__main__":
    main()
