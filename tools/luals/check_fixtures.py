"""Run LuaLS regression fixtures against the generated KenshiLua library.

The checker is intentionally separate from native CI: Lua Language Server is an
editor dependency, not a project build dependency. Install it in an editor, set
LUA_LANGUAGE_SERVER, or pass --luals to run this locally.

Usage:
    python tools/luals/check_fixtures.py --luals C:/path/to/lua-language-server.exe
"""

import argparse
import json
import os
import pathlib
import re
import shutil
import subprocess
import sys
import tempfile
import urllib.parse


PROJECT_ROOT = pathlib.Path(__file__).resolve().parents[2]
FIXTURE_ROOT = PROJECT_ROOT / "tests" / "luals"
EXPECTATION = re.compile(r"^-- EXPECT-DIAGNOSTIC: ([\w-]+)$", re.MULTILINE)


def find_server(explicit):
    if explicit:
        return pathlib.Path(explicit)
    environment_path = os.environ.get("LUA_LANGUAGE_SERVER")
    if environment_path:
        return pathlib.Path(environment_path)
    for name in ("lua-language-server.exe", "lua-language-server"):
        found = shutil.which(name)
        if found:
            return pathlib.Path(found)
    extension_root = pathlib.Path.home() / ".vscode" / "extensions"
    candidates = sorted(extension_root.glob("sumneko.lua-*/server/bin/lua-language-server.exe"))
    if candidates:
        return candidates[-1]
    return None


def lua_paths(root):
    return {
        path.relative_to(PROJECT_ROOT).as_posix(): path
        for path in root.rglob("*.lua")
    }


def expected_diagnostics(paths):
    expected = {}
    for relative, path in paths.items():
        match = EXPECTATION.search(path.read_text(encoding="utf-8"))
        if match:
            expected[relative] = match.group(1)
    return expected


def reported_diagnostics(results_path, paths):
    """Diagnostic codes per fixture from LuaLS's --check_out_path JSON.

    The console report wraps multi-line messages (every type mismatch), so it
    is not parsed; the JSON lists each diagnostic with its code.
    """
    if not results_path.exists():
        return {}
    results = json.loads(results_path.read_text(encoding="utf-8") or "{}")
    reported = {}
    normalized_paths = {relative.lower(): relative for relative in paths}
    root = PROJECT_ROOT.resolve().as_posix().lower() + "/"
    for uri, diagnostics in results.items():
        path = urllib.parse.unquote(urllib.parse.urlparse(uri).path).lstrip("/").replace("\\", "/").lower()
        if not path.startswith(root):
            continue
        fixture = normalized_paths.get(path[len(root):])
        if fixture:
            reported.setdefault(fixture, []).extend(item["code"] for item in diagnostics)
    return reported


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--luals", help="Path to lua-language-server executable.")
    parser.add_argument(
        "--workspace",
        action="store_true",
        help="Check the complete repository workspace instead of only tests/luals.",
    )
    args = parser.parse_args()

    server = find_server(args.luals)
    if not server or not server.is_file():
        print("LuaLS executable not found. Pass --luals or set LUA_LANGUAGE_SERVER.")
        return 2

    check_root = PROJECT_ROOT if args.workspace else FIXTURE_ROOT
    config_path = PROJECT_ROOT / ".luarc.json" if args.workspace else FIXTURE_ROOT / ".luarc.json"
    paths = lua_paths(check_root)
    expected = expected_diagnostics(paths)
    with tempfile.TemporaryDirectory() as temp_dir:
        results_path = pathlib.Path(temp_dir) / "check.json"
        command = [
            str(server),
            "--check=" + str(check_root),
            "--configpath=" + str(config_path),
            "--checklevel=Warning",
            "--check_out_path=" + str(results_path),
        ]
        result = subprocess.run(command, cwd=str(PROJECT_ROOT), text=True, capture_output=True)
        output = result.stdout + result.stderr
        reported = reported_diagnostics(results_path, paths)

    failures = []
    for fixture in sorted(paths):
        actual = reported.get(fixture, [])
        expected_code = expected.get(fixture)
        if expected_code:
            if expected_code not in actual:
                failures.append(fixture + " expected " + expected_code + ", got " + repr(actual))
        elif actual:
            failures.append(fixture + " expected no diagnostics, got " + repr(actual))

    if result.returncode and "Diagnosis complete" not in output and "Diagnosis completed" not in output:
        failures.append("LuaLS exited with code " + str(result.returncode))
    if failures:
        print("LuaLS fixture check failed:")
        for failure in failures:
            print("- " + failure)
        return 1
    scope = "workspace" if args.workspace else "fixtures"
    print("LuaLS {0} passed: {1} valid, {2} expected-diagnostic.".format(
        scope, len(paths) - len(expected), len(expected)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
