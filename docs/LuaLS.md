# Lua Language Server support

KenshiLua supplies editor-only [Lua Language Server](https://luals.github.io/) definitions in [`luals/generated/kenshilua.lua`](../luals/generated/kenshilua.lua). They declare the whole runtime-registered API and are generated from the C++ binding sources, the KenshiLib headers and documentation, and reviewed metadata. The definitions are not Lua scripts and must not be copied into a mod's `scripts` directory.

The repository root contains a `.luarc.json` that uses LuaJIT mode and loads this definition directory. Opening the repository in VS Code with the Lua Language Server extension therefore enables the definitions automatically.

For a mod in a separate workspace, create a `.luarc.json` in that workspace and point `workspace.library` at the packaged KenshiLua addon library:

```json
{
  "runtime.version": "LuaJIT",
  "workspace.library": [
    "C:/path/to/KenshiLua/luals/addon/kenshilua/library"
  ]
}
```

## Addon package and version selection

Each checkout ships a standard LuaLS addon in [`luals/addon/kenshilua`](../luals/addon/kenshilua): `config.json` configures LuaJIT and `library/kenshilua.lua` is the editor-only definition file. Its header embeds the KenshiLua release version from `src/Version.h`.

For LuaLS addon discovery, add the addon parent directory to the editor's user setting, then enable `kenshilua` through the LuaLS Addon Manager:

```json
{
  "Lua.workspace.userThirdParty": [
    "C:/path/to/KenshiLua/luals/addon"
  ]
}
```

For a mod that targets a released KenshiLua version, use the addon from the matching KenshiLua release tag or package. Do not mix the addon from one release with a different DLL: the definitions intentionally describe that release's registered API. The repository-root `.luarc.json` continues to use the development copy in `luals/generated`.

Dialogue scripts receive `currentDialogue` and `currentDialogueLine` only during synchronous execution of a `run lua script` action. Both are declared nullable. Preserve that type when assigning one to a local value so LuaLS can report an unchecked nil use, matching the runtime requirement.

## Generation

The definitions are built in four steps, each with a checked-in output. Regenerate all four, in this order, after changing a binding, an enum or hook registration, `src/Version.h`, or the metadata:

```powershell
python tools/luals/generate_binding_inventory.py
python tools/luals/generate_definitions.py
python tools/luals/generate_coverage_report.py
python tools/luals/generate_type_audit.py
```

Each script accepts `--check`, which fails without writing anything if its output is out of date. CI runs all four that way. The development output and the packaged addon copy embed the KenshiLua release version from `src/Version.h` in their header, so a version bump also needs a regeneration.

Generation requires the pinned `extern/KenshiLib` submodule. Initialize it with `git submodule update --init --recursive` after cloning. The generator stops without modifying definitions if the header tree is missing or if any registered enum value cannot be resolved exactly.

### Binding inventory

[`binding_inventory.json`](../luals/generated/binding_inventory.json) follows the registration graph rooted at `LuaBindings::registerClasses`, including nested registration such as MyGUI's widget registrations and concrete instances of generic container bindings. It records reachable binding names, Lua type and metatable names, inheritance, method and property names, constructors, API-table globals, directly registered global functions, and source provenance. Each callback's signature is inferred from the arguments it reads from the Lua stack and the values it pushes. Where the callback wraps a KenshiLib function, parameter and return types come from that header declaration (`"type_source": "header"`). A registration call that has no local implementation is listed separately as unresolved.

### Definitions

`generate_definitions.py` builds `kenshilua.lua` from:

- the binding inventory, which supplies every registered member and its inferred signature;
- the reviewed contracts in [`luals/metadata/runtime.json`](../luals/metadata/runtime.json): globals, global functions, aliases, and class members whose inferred type is not precise enough, such as nullable returns, the dialogue context, and the MyGUI factories. A field declared there always wins over the inferred one;
- class, method, and property descriptions in [`kenshilib_descriptions.json`](../luals/metadata/kenshilib_descriptions.json), imported from the KenshiLib-docs repository with `python tools/luals/import_kenshilib_docs.py --docs C:/path/to/KenshiLib-docs/docs`. A method documented only on a parent class is shown with the parent's description, and an `_NV_` override dispatcher with the description of the method it dispatches; and
- the 113 registered enum tables in `EnumBinding.cpp` (67 global enums and 46 nested class enum tables, totaling 1576 enum values), declared as `---@enum` with exact C++ header values, and the event names from the hook registry.

The lowercase engine aliases (`ou`, `player`, `key`, `root`, `con`, `options`, and `gui`) are conditionally installed at Lua startup and are therefore nullable. Prefer their accessor functions, which make that availability requirement explicit. The commented-out capitalized names in the runtime registration source, including `GameWorld` and `PlayerInterface`, are not Lua globals and are deliberately not declared.

MyGUI factory methods are nullable where their C++ bindings can return no widget. Widget event autocomplete uses the canonical `eventMouseButtonClick`-style names in `MyGUI.WidgetEventName`. The former unprefixed names, such as `MouseButtonClick`, are exposed separately as `MyGUI.LegacyWidgetEventName`; the runtime accepts them with a deprecation warning. Additional historical spellings such as `OnClick` and `click` remain accepted as plain strings for compatibility but are intentionally omitted from autocomplete. Widget event callbacks receive a widget sender followed by event-specific values; the current generic handler type preserves that variable tail while the event-specific callback overload design remains future work.

The specialised MyGUI factories require a first creation argument (`skin`, coordinates, or an `IntCoord`) and accept several runtime forms after it. Their definitions preserve the concrete nullable return type while leaving that variable tail as `any`; exact overload selection is future work.

## Coverage

The definitions declare every runtime-registered class, method, property, constructor, API-table member, and global. The generated [`coverage_report.json`](../luals/generated/coverage_report.json) compares the binding inventory with the metadata the definitions are built from, including instance members, registered getter/setter properties, properties exposed by custom index callbacks, static/global-table members, constructors, inheritance, and directly registered global C functions. CI runs `generate_coverage_report.py --check --require-complete`, which fails if any registered member is undeclared or any registration call is unresolved. A property or global exposed outside the recognized registration patterns is invisible to the inventory, so a new registration style needs inventory support before the report covers it.

The report also counts the members that have a KenshiLib description. That number is limited by what KenshiLib-docs documents and does not block CI.

Globals are checked against what `kenshilua.lua` actually declares, not against the metadata the report expands. Every `lua_setglobal` name in `src/` (`.cpp` and `.h`, comments excluded) must be declared; `summary.runtime_globals` and `declared_runtime_globals` count them and `undeclared_runtime_globals` lists any gap. Global tables of static functions (`CombatClass.setup`) are typed as `<Type>Statics` classes holding only the static functions, and the container factories (`lektor`, `ogre_unordered_set`, `ogre_unordered_map`) declare one overload per registered type name, so `lektor.new("Character")` is typed `Lektor<Character>`.

Coverage says every member is declared; it does not say the declared types are right. The generated [`type_audit.json`](../luals/generated/type_audit.json) checks the types in `kenshilua.lua` in two steps. First against the binding, which defines the Lua API: each method must take every argument its callback reads from the stack and return as many values as it pushes. Then against the KenshiLib C++ declaration the binding wraps, mapping C++ types to the Lua values bindings push and treating non-const primitive or pointer references as extra return values.

`summary.blocking_issues` counts definitions that disagree with their binding, `any` types where a type is known, untyped container elements, and `nil`-only returns. CI requires it to be zero (`--require-correct`). Entries where the definitions match the binding but the binding differs from the declaration are reported without blocking: `binding_converts` (an enum pushed as its integer value), `binding_pushes_raw_pointer` (a bound object pushed with `lua_pushlightuserdata`, so Lua gets no methods), and `binding_shape_differs` (a binding taking `left, top` for a `TPoint`). Members whose binding is broken in C++ are listed with a reason in [`known_binding_bugs.json`](../luals/metadata/known_binding_bugs.json) and reported as `known_binding_bug` until the binding is fixed.

Container instances (`lektor<T>`, `Ogre::FastArray<T>`, sets, and maps) are inventoried from both `typedef` aliases and direct `XBinding<T>::registerBinding(L, "...")` calls. Each container template is declared once as a LuaLS generic class named after it (`Lektor<T>`, `OgreFastArray<T>`, `OgreUnorderedSet<T>`, `OgreUnorderedMap<K, V>`, ...) from the reviewed contracts in [`container_contracts.py`](../tools/luals/container_contracts.py), and every instance is typed as an instantiation with the element types from its registered element metatables or template arguments: `PlayerInterface:getAllPlayerCharacters()` returns `Lektor<Character>|nil`. LuaLS 3.19 does not substitute class type parameters inside `T[]` or an inline `fun(): K, V`, so `toTable()` returns `table<integer, T>` and iterators return the `ContainerIterator<K, V>` alias; the `tests/luals/invalid/container_*.lua` fixtures fail if element typing through these forms regresses. `pop()` is declared `T|nil`: the bindings currently raise on an empty container, and returning `nil` instead is part of the planned container binding redesign.

Regenerate the audit after changing definitions:

```text
python tools/luals/generate_type_audit.py
python tools/luals/generate_type_audit.py --check --require-correct
```

## Regression fixtures

[`tests/luals`](../tests/luals) is an isolated LuaLS workspace. Its `valid` scripts must report no diagnostics; an `invalid` script declares its expected diagnostic in an `EXPECT-DIAGNOSTIC` comment. Run the fixture checker with a LuaLS executable:

```powershell
python tools/luals/check_fixtures.py --luals C:/path/to/lua-language-server.exe
python tools/luals/check_fixtures.py --workspace --luals C:/path/to/lua-language-server.exe
python -m unittest discover -s tests/luals -p "test_*.py"
```

The first checker command validates the isolated fixtures. The `--workspace` form also checks repository examples and libraries while honoring the fixture's declared expected diagnostic. Diagnostics are read from LuaLS's `--check_out_path` JSON report; the console report wraps multi-line messages such as type mismatches and cannot be parsed reliably. The checker accepts `LUA_LANGUAGE_SERVER`, a `lua-language-server` executable on `PATH`, or a standard VS Code LuaLS extension installation. LuaLS is an editor dependency and is installed separately from the native build.
