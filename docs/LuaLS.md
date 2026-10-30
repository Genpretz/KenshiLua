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
* `library/kenshilua.lua`: Type definitions generated from the runtime binding inventory, reviewed metadata, and KenshiLib declarations.
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

### Option 2: LuaLS Addon Manager

If your editor supports the LuaLS Addon Manager:
1. Open the LuaLS Addon Manager in your editor.
2. Select **Add Custom Addon** or point to the extracted `kenshilua` directory containing `config.json`.
3. Enable the addon for your Kenshi mod workspace.

---

## Working with KenshiLua Types

### Engine Singletons and Global Accessors
KenshiLua provides global accessor functions and convenience aliases for primary engine singletons:
* `getGameWorld()` returns [`GameWorld*`](BindingsReference.md#gameworld)
* `getPlayerInterface()` returns [`PlayerInterface*`](BindingsReference.md#playerinterface)
* `ou`, `player`, `key`, `gui`, `root`, `con`, `options` are engine aliases conditionally populated at runtime. Because they may be `nil` before the engine finishes initializing, prefer using the accessor functions or guard checks when accessing aliases.

### Dialogue Script Context
Dialogue scripts executed via `run lua script` receive transient globals:
* `currentDialogue`: [`Dialogue*`](BindingsReference.md#dialogue) or `nil`
* `currentDialogueLine`: [`DialogLineData*`](BindingsReference.md#dialoglinedata) or `nil`

Both globals are declared as nullable in the definitions. When writing dialogue scripts, verify that both values exist before using them to ensure type safety and avoid runtime nil-dereference errors:

```lua
if not currentDialogue or not currentDialogueLine then
    return
end

local speaker = currentDialogue:getCharacter()
if speaker then
    print("Speaker: " .. speaker:getName())
end
```

### Generic Containers
Containers such as `Lektor<T>`, `OgreUnorderedSet<T>`, and `OgreUnorderedMap<K, V>` provide generic type hints:
* `lektor.new("Character*")` is inferred as `Lektor<Character>`
* Indexing with `charList[1]` yields `Character|nil`
* Iterating with `ipairs(charList)` yields `integer, Character`
* Converting with `charList:toTable()` produces `table<integer, Character>`

For detailed container operations and memory lifecycle rules, see the [Containers Reference](ContainersReference.md).

### MyGUI Widgets and Events
MyGUI widgets support autocompletion for canonical event names (prefixed with `event`):
* `button:on("eventMouseButtonClick", function(widget) ... end)`
* Widget hierarchy inherits from `MyGUI.Widget` (`setCaption`, `setVisible`, `setPosition`, etc.).

For comprehensive MyGUI widget methods and factories, see the [MyGUI Reference](MyGUIReference.md).

---

## Annotating Custom Mod Functions

You can leverage LuaLS annotations in your own mod scripts to document types and maintain type safety across multiple files:

```lua
---@param target Character The character to inspect
---@param bonusAmount number Flat bonus to add to calculation
---@return boolean success Whether the operation succeeded
function MyMod_ApplyBuff(target, bonusAmount)
    if not target then
        return false
    end

    local stats = target.stats
    if stats then
        -- Full autocompletion and hover documentation for CharStats
        print("Strength: " .. tostring(stats:getStrength()))
    end
    return true
end
```

## Maintaining Descriptions

Hover descriptions are stored in checked-in metadata and preserved during generation. See the [description maintenance workflow](../tools/README.md#luals-descriptions) for authoritative files, precedence, and importing upstream descriptions for review.
