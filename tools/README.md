# Development tools

Run these commands from the repository root with a modern Python 3 installation. In the examples, `python` must resolve to that installation.

## Binding scaffolds

| Script | Purpose | Output |
| --- | --- | --- |
| `bindings/generate_class.py` | Generates Lua class-binding scaffolds from a KenshiLib header. Existing bindings, known classes, and registered enums are discovered automatically. | `tools/generated/` by default |
| `bindings/generate_structs.py` | Generates bindings for standalone and nested structs. Use `--include-classes` to also process class-like layouts. | `tools/generated/struct/` by default |
| `bindings/generate_enums.py` | Generates enum-binding source and header files from a header. | `tools/generated/enum/` |

Generate class bindings from a header:

```powershell
python tools/bindings/generate_class.py extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h
```

Override the destination when needed:

```powershell
python tools/bindings/generate_class.py extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h --write-dir path/to/output
```

The class-binding generator automatically discovers bindings in `src/Bindings`, registered enums in `src/Bindings/Kenshi/EnumBinding.cpp`, and their associated headers. `--bind-map`, `--classes`, and `--enums` remain available for one-off additions or overrides.

## Documentation and audits

| Script | Purpose | Output |
| --- | --- | --- |
| `docs/generate_bindings_reference.py` | Generates the general Lua bindings reference. | `docs/BindingsReference.md` |
| `docs/generate_mygui_reference.py` | Generates the MyGUI Lua bindings reference. | `docs/MyGUIReference.md` |
| `docs/generate_enums_reference.py` | Generates the enum reference from `EnumBinding.cpp`. | `docs/EnumsReference.md` |
| `docs/generate_callbacks_reference.py` | Generates the callbacks reference from callback and hook declarations. | `docs/CallbacksReference.md` |
| `luals/generate_definitions.py` | Generates the versioned LuaLS definitions from reviewed metadata and runtime registries. | `luals/generated/kenshilua.lua`, `luals/addon/kenshilua/library/kenshilua.lua` |
| `luals/generate_binding_inventory.py` | Inventories bindings reachable from the runtime registration graph without inferring signatures. | `luals/generated/binding_inventory.json` |
| `luals/generate_coverage_report.py` | Compares inventoried bindings with reviewed LuaLS metadata and reports remaining coverage gaps. | `luals/generated/coverage_report.json` |
| `luals/check_fixtures.py` | Checks LuaLS regression fixtures against the generated definitions. | LuaLS diagnostic result |
| `audit/generate_unbound_reference.py` | Reports unsupported or unbound types and methods. | `docs/UnboundReference.md` |

Each documentation and audit script can be run directly, for example:

```powershell
python tools/docs/generate_bindings_reference.py
python tools/docs/generate_enums_reference.py
python tools/luals/generate_definitions.py --check
python tools/luals/generate_binding_inventory.py --check
python tools/luals/generate_coverage_report.py --check
python tools/luals/check_fixtures.py --luals C:/path/to/lua-language-server.exe
python tools/luals/check_fixtures.py --workspace --luals C:/path/to/lua-language-server.exe
python -m unittest discover -s tests/luals -p "test_*.py"
python tools/audit/generate_unbound_reference.py
```

Review generated documentation before committing it.

## Release utilities

`release/sync_version.py` checks or updates the version embedded in the mod file from `src/Version.h`.

```powershell
python tools/release/sync_version.py --check
python tools/release/sync_version.py --update
```

Use `python tools/release/sync_version.py --help` for input/output overrides.

The Release post-build step runs two packaging scripts that write the zips for a GitHub release to `bin/release/`, with the version taken from `src/Version.h`. Each creates its zip once per version: the first Release build after a version bump writes it, and later builds keep it. Pass `--force` to rebuild a zip after further changes to the same version.

- `release/package_mod.py` writes `KenshiLua v<version>.zip` from `bin/KenshiLua/` and `bin/README.md` (copied from `assets/package/README.md` by the build). It leaves out the linker outputs next to the DLL (`KenshiLua.pdb`, `.lib`, `.exp`) and any files in `logs/`.
- `release/package_luals_addon.py` writes `KenshiLua-LuaLS-Addon-v<version>.zip`. It never packages definitions generated for another version; it warns instead, without failing the build. See [Packaging the addon for a release](../docs/LuaLS.md#packaging-the-addon-for-a-release).

```powershell
python tools/release/package_mod.py --force
python tools/release/package_luals_addon.py --force
```

## In-game automated testing

`testing/run_kenshi_tests.py` executes automated, non-interactive in-game integration test suites against supported Kenshi v1.0.65 installations (GOG and Steam).

| Script | Purpose | Output |
| --- | --- | --- |
| `testing/run_kenshi_tests.py` | Launches Kenshi, handles launcher dismissal, drives test suites via Lua coroutine harness, and records JUnit XML and event streams. | `scratch/kenshi-tests/<run_id>/` |

### Basic usage

Run all default suites across both supported installations sequentially:

```powershell
python tools/testing/run_kenshi_tests.py --platform all --suite harness-self-test,script-loading,world-smoke,binding-smoke
```

Run on a specific platform:

```powershell
python tools/testing/run_kenshi_tests.py --platform gog
python tools/testing/run_kenshi_tests.py --platform steam
```

Filter test cases by name:

```powershell
python tools/testing/run_kenshi_tests.py --platform gog --filter "cross-mod"
```

Preview staging actions without modifying any game files:

```powershell
python tools/testing/run_kenshi_tests.py --platform gog --dry-run
```

Bootstrap or refresh the deterministic vanilla save fixture (`kltest_vanilla_1065`):

```powershell
python tools/testing/run_kenshi_tests.py --platform gog --prepare-save-fixture
```

Recover or replay a staging journal manually if an external process abort occurred:

```powershell
python tools/testing/run_kenshi_tests.py --recover-journal scratch/kenshi-tests/<run_id>/journal.json
```

### Safety and isolation

- **Transactional staging**: Every staged file (`mods.cfg`, `RE_Kenshi.json`, consumer mod scripts) is backed up before modification and tracked in a `journal.json` transaction. On run completion, timeout, or crash, files are verified against their pre-run SHA-256 hashes and restored.
- **Preload plugin neutralization**: Third-party `PreloadPlugins` in `mods/**/RE_Kenshi.json` are temporarily neutralized during the test run to prevent modal dialog crashes, and restored on exit.
- **Save isolation**: User saves are never modified. Staged save fixtures are copied into isolated paths and cleaned up on teardown.
- **Crash and stall detection**: The runner monitors `RE_Kenshi_log.txt` for crash signatures to terminate failed runs immediately without waiting for timeouts.

## Generated files

`tools/generated/` is a scratch area for generated binding scaffolds and is ignored by Git. Move reviewed files into their final source locations deliberately.
