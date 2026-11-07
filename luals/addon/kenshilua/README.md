# Lua Language Server Addon Guide

Editor definitions for the KenshiLua Lua API, for the [Lua Language Server](https://luals.github.io/) (LuaLS). With them, the editor completes KenshiLua globals, classes, methods, enums, and event names, shows their types and descriptions, and reports wrong argument types and unchecked `nil` values.

The definitions only describe the API for the editor. Kenshi never loads them, and they must not be copied into a mod's `scripts` folder.

## Requirements

- An editor with LuaLS, for example Visual Studio Code with the **Lua** extension by sumneko.
- The addon zip from the same KenshiLua release as the KenshiLua DLL your mod targets. Each release's definitions describe that release's API only.

## Installation

Extract the zip to a folder outside your mods, for example `C:/KenshiModding/LuaLS`. It contains one folder, `kenshilua`. Then choose one of the following.

### Option 1: Per-Mod Configuration

Create a `.luarc.json` file in the mod's root folder, the folder you open in the editor:

```json
{
  "runtime.version": "LuaJIT",
  "workspace.library": [
    "C:/KenshiModding/LuaLS/kenshilua/library"
  ]
}
```

### Option 2: User Settings for All Mods

Add the definitions to your VS Code user settings (`settings.json`, opened with **Preferences: Open User Settings (JSON)**):

```json
{
  "Lua.runtime.version": "LuaJIT",
  "Lua.workspace.library": [
    "C:/KenshiModding/LuaLS/kenshilua/library"
  ]
}
```

No file is needed in each mod, but these settings apply to every folder you open with LuaLS, including Lua projects that are not Kenshi mods. Use Option 1 to limit the definitions to your mods.

The **Lua: Open Addon Manager** command does not list this addon. It installs only addons published in the LLS-Addons repository.

## Verification

Open a script in the mod and hover over `getGameWorld`. The editor should show its type instead of reporting `Undefined global`.

## Updating

When you move a mod to a newer KenshiLua release, replace the `kenshilua` folder with the one from that release's zip. Mixing the definitions from one release with a different DLL can hide or invent API members.
