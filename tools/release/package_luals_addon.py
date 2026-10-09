#!/usr/bin/env python3
"""
tools/release/package_luals_addon.py

Packages the LuaLS addon (luals/addon/kenshilua) as a zip for a GitHub release.

The zip contains a single `kenshilua` folder with config.json, README.md and
library/kenshilua.lua. The version comes from src/Version.h.

The Release post-build step runs this script next to package_mod.py. A zip that
already exists for the current version is kept, so the zip is created once per
version bump; pass --force to rebuild it after further changes to that version.

Definitions generated for a different version, or an addon copy that differs
from luals/generated/kenshilua.lua, are never packaged. The script then prints a
warning and exits 0, so a version bump does not fail the build; regenerate the
definitions and build again to create the zip.

Usage:
    # Write bin/release/KenshiLua-LuaLS-Addon-v<version>.zip if it does not exist yet
    python tools/release/package_luals_addon.py

    # Rebuild it even if it exists
    python tools/release/package_luals_addon.py --force
"""

import argparse
import pathlib
import re
import sys
import zipfile

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
from sync_version import DEFAULT_VERSION_H, PROJECT_ROOT, parse_version_h  # noqa: E402

ADDON_DIR = PROJECT_ROOT / "luals" / "addon" / "kenshilua"
DEVELOPMENT_LIBRARY = PROJECT_ROOT / "luals" / "generated" / "kenshilua.lua"
DEFAULT_BIN_DIR = PROJECT_ROOT / "bin"

# Paths inside ADDON_DIR, in the order they are written to the zip.
ADDON_FILES = ("config.json", "README.md", "library/kenshilua.lua")

# A fixed timestamp keeps the zip identical for identical inputs.
ZIP_TIMESTAMP = (2026, 1, 1, 0, 0, 0)

VERSION_LINE = re.compile(r"^-- KenshiLua runtime version: (\S+)$", re.MULTILINE)

REGENERATE_HINT = "Regenerate the definitions with the commands in docs/LuaLS.md and build again."


def zip_name(version: str) -> str:
    return f"KenshiLua-LuaLS-Addon-v{version}.zip"


def missing_files() -> list:
    return [str(ADDON_DIR / name) for name in ADDON_FILES if not (ADDON_DIR / name).is_file()]


def stale_reason(version: str):
    """Returns why the definitions must not be packaged for `version`, or None."""
    library = ADDON_DIR / "library" / "kenshilua.lua"
    match = VERSION_LINE.search(library.read_text(encoding="utf-8"))
    if not match:
        return f"{library} has no 'KenshiLua runtime version' line."
    if match.group(1) != version:
        return f"the addon definitions are for {match.group(1)}, but src/Version.h is {version}."
    if library.read_bytes() != DEVELOPMENT_LIBRARY.read_bytes():
        return f"{library} differs from {DEVELOPMENT_LIBRARY}."
    return None


def write_zip(output: pathlib.Path) -> None:
    output.parent.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(output, "w", compression=zipfile.ZIP_DEFLATED) as archive:
        for name in ADDON_FILES:
            info = zipfile.ZipInfo("kenshilua/" + name, date_time=ZIP_TIMESTAMP)
            info.compress_type = zipfile.ZIP_DEFLATED
            info.external_attr = 0o644 << 16
            archive.writestr(info, (ADDON_DIR / name).read_bytes())


def main() -> int:
    parser = argparse.ArgumentParser(description="Package the LuaLS addon as a release zip.")
    parser.add_argument("--version-h", type=pathlib.Path, default=DEFAULT_VERSION_H,
                        help="Path to Version.h (default: src/Version.h)")
    parser.add_argument("--bin-dir", type=pathlib.Path, default=DEFAULT_BIN_DIR,
                        help="Build output directory (default: bin)")
    parser.add_argument("--output-dir", type=pathlib.Path, default=None,
                        help="Directory for the zip (default: <bin-dir>/release)")
    parser.add_argument("--force", action="store_true",
                        help="Rebuild the zip even if one exists for this version")
    args = parser.parse_args()

    try:
        version = parse_version_h(args.version_h)["version_str"]
    except (OSError, ValueError) as error:
        print(f"Error: {error}", file=sys.stderr)
        return 1

    missing = missing_files()
    if missing:
        print("Error: cannot package the LuaLS addon; missing " + ", ".join(missing), file=sys.stderr)
        return 1

    output = (args.output_dir or args.bin_dir / "release") / zip_name(version)
    if output.exists() and not args.force:
        print(f"{output} already exists for v{version}; keeping it. "
              "Run python tools/release/package_luals_addon.py --force to rebuild it.")
        return 0

    reason = stale_reason(version)
    if reason:
        print(f"Warning: LuaLS addon zip not created: {reason} {REGENERATE_HINT}")
        return 0

    write_zip(output)
    print(f"Wrote {output}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
