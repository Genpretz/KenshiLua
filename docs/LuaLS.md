# Lua Language Server Guide

KenshiLua provides editor type definitions for the [Lua Language Server (LuaLS)](https://luals.github.io/). These definitions enable autocomplete, signature help, hover documentation, and static type checking for registered Lua classes, methods, properties, enums, containers, and MyGUI widgets within your code editor.

---

## Obtaining the Definitions

Each KenshiLua release on GitHub includes a companion archive named:
```text
KenshiLua-LuaLS-Addon-v<version>.zip
```

This archive contains a standardized LuaLS addon folder named `kenshilua`, including:
* `config.json`: Configuration tuning LuaLS for LuaJIT 2.1 compatibility.
* `library/kenshilua.lua`: Type definitions for the KenshiLua Lua API.
* `README.md`: Quick setup instructions.

> [!NOTE]
> Always use the definitions addon version that matches the KenshiLua DLL your mod targets. Do not copy `kenshilua.lua` directly into your mod's `scripts/` directory, as it is an editor-only definition file and not an executable runtime script.

---

## Configuring Your Mod Project

Extract the `KenshiLua-LuaLS-Addon-v<version>.zip` archive to a folder outside your Kenshi mod directory (for example, in your personal tools or development directory).

### Option 1: Workspace `.luarc.json` (Recommended)

Place a `.luarc.json` file in the root directory of your mod project:

```json
{
  "$schema": "https://raw.githubusercontent.com/LuaLS/vscode-lua/master/setting/schema.json",
  "runtime": {
    "version": "LuaJIT"
  },
  "workspace": {
    "library": [
      "C:/path/to/extracted/kenshilua/library"
    ],
    "checkThirdParty": false
  },
  "diagnostics": {
    "enable": true
  }
}
```

Replace `C:/path/to/extracted/kenshilua/library` with the absolute or relative path to the `library` folder from the extracted addon.

When you open your mod folder in Visual Studio Code (or any editor with LuaLS installed), the server will automatically detect the configuration and load all KenshiLua API definitions.

### Option 2: User Settings for All Workspaces

To load the definitions without a file in each mod, add them to your Visual Studio Code user `settings.json` (**Preferences: Open User Settings (JSON)**):

```json
{
  "Lua.runtime.version": "LuaJIT",
  "Lua.workspace.library": [
    "C:/path/to/extracted/kenshilua/library"
  ]
}
```

These settings apply to every folder you open with LuaLS, including Lua projects that are not Kenshi mods. Use Option 1 to limit the definitions to your mods.

---

## Verifying the Setup

Open a script in your mod and hover over `getGameWorld`. The editor should show its type instead of reporting `Undefined global`.

---

## What the Editor Checks

Besides completion and hover text, the definitions encode some KenshiLua rules that LuaLS checks as you type:

* `currentDialogue`, `currentDialogueLine`, and engine aliases such as `ou`, `gui`, and `con` are typed as possibly `nil`, so LuaLS warns when an open script uses them without a `nil` check. The [Dialogue Scripting Guide](DialogueScriptingBridge.md#runtime-environment) describes when the dialogue globals are set.
* Container factories take the element type from the type name: `lektor.new("Character*")` is typed `Lektor<Character>`, and indexing it yields `Character|nil`. See [Explicit Factory Types](ContainersReference.md#explicit-factory-types).
* `widget:on` completes MyGUI event names such as `eventMouseButtonClick`. See the [MyGUI event reference](MyGUIReference.md#event-callbacks-reference).
