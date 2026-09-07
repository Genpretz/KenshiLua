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

The class-binding generator automatically discovers bindings in `src/Bindings`, registered enums in `src/Bindings/EnumBinding.cpp`, and their associated headers. `--bind-map`, `--classes`, and `--enums` remain available for one-off additions or overrides.

## Documentation and audits

| Script | Purpose | Output |
| --- | --- | --- |
| `docs/generate_bindings_reference.py` | Generates the general Lua bindings reference. | `docs/BindingsReference.md` |
| `docs/generate_mygui_reference.py` | Generates the MyGUI Lua bindings reference. | `docs/MyGUIReference.md` |
| `docs/generate_enums_reference.py` | Generates the enum reference from `EnumBinding.cpp`. | `docs/EnumsReference.md` |
| `docs/generate_callbacks_reference.py` | Generates the callbacks reference from callback and hook declarations. | `docs/CallbacksReference.md` |
| `audit/generate_unbound_reference.py` | Reports unsupported or unbound types and methods. | `docs/UnboundRefrence.md` |

Each documentation and audit script can be run directly, for example:

```powershell
python tools/docs/generate_bindings_reference.py
python tools/docs/generate_enums_reference.py
python tools/audit/generate_unbound_reference.py
```

Review generated documentation before committing it.

## Release utility

`release/sync_version.py` checks or updates the version embedded in the mod file from `src/Version.h`.

```powershell
python tools/release/sync_version.py --check
python tools/release/sync_version.py --update
```

Use `python tools/release/sync_version.py --help` for input/output overrides.

## Generated files

`tools/generated/` is a scratch area for generated binding scaffolds and is ignored by Git. Move reviewed files into their final source locations deliberately.
