#!/usr/bin/env python3
"""
tools/release/package_mod.py

Packages the built mod as "KenshiLua v<version>.zip" for a GitHub release.

The zip holds bin/KenshiLua/ as a KenshiLua folder and bin/README.md at its
root, the layout players extract into Kenshi's mods directory. Left out:
- files in KenshiLua/logs/ (the empty folder is kept), so local logs never ship;
- the linker outputs next to the DLL (KenshiLua.pdb, .lib, .exp). RE_Kenshi
  loads only KenshiLua.dll; keep each release's .pdb locally to read crash dumps.
The version comes from src/Version.h.

The Release post-build step runs this script. A zip that already exists for
the current version is kept, so the zip is created once per version bump; pass
--force to rebuild it after further changes to that version.

Usage:
    # Write bin/release/KenshiLua v<version>.zip if it does not exist yet
    python tools/release/package_mod.py

    # Rebuild it even if it exists
    python tools/release/package_mod.py --force
"""

import argparse
import os
import pathlib
import sys
import zipfile

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
from sync_version import DEFAULT_VERSION_H, PROJECT_ROOT, parse_version_h  # noqa: E402

DEFAULT_BIN_DIR = PROJECT_ROOT / "bin"
MOD_FOLDER = "KenshiLua"
REQUIRED_FILES = ("plugin/KenshiLua.dll", "KenshiLua.mod")
EXCLUDED_CONTENT_DIRS = ("logs",)
EXCLUDED_FILES = ("plugin/KenshiLua.pdb", "plugin/KenshiLua.lib", "plugin/KenshiLua.exp")


def zip_name(version: str) -> str:
    return f"KenshiLua v{version}.zip"


def mod_entries(mod_dir: pathlib.Path):
    """Yields (path on disk, path in zip) for every folder and file of the mod, sorted."""
    yield mod_dir, MOD_FOLDER + "/"
    for root, dirs, files in os.walk(mod_dir):
        dirs.sort()
        root_path = pathlib.Path(root)
        relative_root = root_path.relative_to(mod_dir)
        for name in dirs:
            yield root_path / name, (MOD_FOLDER / relative_root / name).as_posix() + "/"
        if relative_root.parts and relative_root.parts[0] in EXCLUDED_CONTENT_DIRS:
            continue
        for name in sorted(files):
            if (relative_root / name).as_posix() in EXCLUDED_FILES:
                continue
            yield root_path / name, (MOD_FOLDER / relative_root / name).as_posix()


def write_zip(output: pathlib.Path, mod_dir: pathlib.Path, readme: pathlib.Path) -> int:
    """Writes the zip through a temporary file, so a failed run leaves no partial zip."""
    output.parent.mkdir(parents=True, exist_ok=True)
    partial = output.with_name(output.name + ".partial")
    count = 0
    try:
        with zipfile.ZipFile(partial, "w", compression=zipfile.ZIP_DEFLATED) as archive:
            for disk_path, archive_path in mod_entries(mod_dir):
                archive.write(disk_path, archive_path)
                count += 1
            archive.write(readme, "README.md")
            count += 1
        os.replace(partial, output)
    finally:
        if partial.exists():
            partial.unlink()
    return count


def main() -> int:
    parser = argparse.ArgumentParser(description="Package the built mod as a release zip.")
    parser.add_argument("--version-h", type=pathlib.Path, default=DEFAULT_VERSION_H,
                        help="Path to Version.h (default: src/Version.h)")
    parser.add_argument("--bin-dir", type=pathlib.Path, default=DEFAULT_BIN_DIR,
                        help="Build output directory holding KenshiLua/ and README.md (default: bin)")
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

    mod_dir = args.bin_dir / MOD_FOLDER
    readme = args.bin_dir / "README.md"
    missing = [str(mod_dir / name) for name in REQUIRED_FILES if not (mod_dir / name).is_file()]
    if not readme.is_file():
        missing.append(str(readme))
    if missing:
        print("Error: cannot package the mod; missing " + ", ".join(missing), file=sys.stderr)
        return 1

    output = (args.output_dir or args.bin_dir / "release") / zip_name(version)
    if output.exists() and not args.force:
        print(f"{output} already exists for v{version}; keeping it. "
              "Run python tools/release/package_mod.py --force to rebuild it.")
        return 0

    count = write_zip(output, mod_dir, readme)
    print(f"Wrote {output} ({count} entries)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
