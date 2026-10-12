# C++ KenshiLib integration demo

This example is a native KenshiLib plugin that discovers KenshiLua at runtime.
It demonstrates:

- registering global native functions;
- registering a `require()`-able native module;
- loading a private Lua script on demand;
- marshalling a `Character*` to and from Lua;
- dispatching a custom event with two arguments; and
- handling API failures without linking against KenshiLua or Lua.

## Build

Build `Cpp_KenshiLib_Integration_Demo.vcxproj` as `Release|x64`. By default the
project uses this repository's `extern/KenshiLib`; set `KENSHILIB_DIR` to another
KenshiLib checkout if its compiled libraries are elsewhere. Set `BOOST_ROOT` to
the Boost version used by KenshiLib.

The project includes the authoritative `include/KenshiLua.h` from the repository
root. It links only to `KenshiLib.lib`.

## Install

1. Install RE_Kenshi, KenshiLib, and KenshiLua.
2. Place the built DLL where RE_Kenshi loads native plugins.
3. Copy this example directory into Kenshi's active mods directory so the two
   Lua scripts resolve under `Cpp_KenshiLib_Integration_Demo/scripts/`.
4. Select a character in game and inspect `KenshiLua.log`.

The startup listener is loaded normally from `scripts/init/`. The native DLL
loads `scripts/modules/combat_ai.lua` explicitly, demonstrating that private
scripts do not need to live in the startup directory.
