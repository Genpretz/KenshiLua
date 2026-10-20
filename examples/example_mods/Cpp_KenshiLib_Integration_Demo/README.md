# C++ KenshiLib Integration Demo

A native KenshiLib DLL plugin demonstration showing how to discover and communicate with KenshiLua's runtime using the header-only C++ Extension SDK.

## Features Demonstrated

- Dynamic runtime discovery and ABI negotiation via `KenshiLua::IsAvailable()`.
- Registering global native functions callable from Lua (`CppDemo_CalculateBonus`, `CppDemo_PrintCharacter`).
- Registering a `require()`-able native C++ module (`CppDemoNative`).
- Executing a private Lua script module on demand (`scripts/modules/combat_ai.lua`).
- Marshalling KenshiLib types (such as `Character*`) between native C++ and Lua userdata wrappers.
- Dispatching custom named events with arguments from C++ to Lua event listeners (`CppDemo_OnCharacterSelected`).
- Complete isolation without linking against `KenshiLua.lib` or `lua51.lib`.

For the full specification and ABI contract, see the [C++ Extension API Reference](../../../docs/CppExtensionAPI.md).

## Build

Build `Cpp_KenshiLib_Integration_Demo.vcxproj` as `Release|x64`.

- By default, the project references the repository's `extern/KenshiLib`; set `KENSHILIB_DIR` to an alternative KenshiLib directory if necessary.
- Set `BOOST_ROOT` to the Boost distribution path required by KenshiLib.
- The project includes `include/KenshiLua.h` from the repository root and links only against `KenshiLib.lib`.

## Installation & Testing

1. Install RE_Kenshi, KenshiLib, and KenshiLua into your Kenshi installation.
2. Place the built `Cpp_KenshiLib_Integration_Demo.dll` into the directory where RE_Kenshi loads native plugins.
3. Copy this example directory into Kenshi's active `mods/` directory so the scripts resolve under `Cpp_KenshiLib_Integration_Demo/scripts/`.
4. In-game, select any character and check `logs/KenshiLua.log` for output from the native plugin and Lua listener scripts.

