
# KenshiLua

[![GitHub Release](https://img.shields.io/github/v/release/Genpretz/KenshiLua?include_prereleases)](https://github.com/Genpretz/KenshiLua/releases)
[![GitHub Downloads](https://img.shields.io/github/downloads/Genpretz/KenshiLua/total)](https://github.com/Genpretz/KenshiLua/releases)
[![License](https://img.shields.io/github/license/Genpretz/KenshiLua)](https://github.com/Genpretz/KenshiLua/blob/main/LICENSE)
![Platform](https://img.shields.io/badge/platform-Windows%20x64-0078D4)
![LuaJIT](https://img.shields.io/badge/LuaJIT-2.1-2C2D72?logo=lua&logoColor=white)
![Status](https://img.shields.io/badge/status-alpha-orange)

KenshiLua is a DLL extension for Kenshi that embeds a Lua runtime and exposes selected portions of KenshiLib to Lua.

The goal is to provide a Lua scripting workflow to mod Kenshi and lower the barrier to entry for utilizing KenshiLib through rapid iteration and scripting.

## Overview

Loaded at runtime through RE_Kenshi, KenshiLua exposes selected portions of KenshiLib through a mixture of generated and hand-written Lua bindings, enabling rapid development, experimentation, and mod creation without requiring direct interaction with the underlying C++ APIs.

* Exposes KenshiLib functionality through Lua
* Allows for Lua scripts to be loaded from a mod folder at runtime or exectued dynamically from predefined dialogues using FCS Extended.
* Exposes a varierty of core gameplay events to registered scripts in the form of callbacks
* Provides a GUI that includes:
    - a Script Manager detialing which scripts have been loaded from active mods
    - a Script Editor for creating or editing scripts in-game
    - a Console for executing simple lua commands
    - and a detailed Logger which can be used to troubleshoot issues with any lua scripts

## How much of KenshiLib can be used from Lua?

A large amount of KenshiLib has been exposed for use from Lua. KenshiLua is built against KenshiLib 0.5.0, the version RE_Kenshi ships. It covers almost all of the API that KenshiLib 0.3.0 provided, and the classes added in 0.5.0 are being bound in batches.
* [BindingsReference.md](docs/BindingsReference.md) - View for a list of methods and properties available from Lua.
* [EnumsReference.md](docs/EnumsReference.md) - View for a list of enums available from Lua.
* [CallbacksReference.md](docs/CallbacksReference.md) - View for a list of event callbacks available from Lua.
* [ContainersReference.md](docs/ContainersReference.md) - View for container methods, operators, and memory rules.
* [MyGUIReference.md](docs/MyGUIReference.md) - View for a list of MyGUI methods and properties available from Lua.
* [InGameGUI.md](docs/InGameGUI.md) - Guide for using the in-game GUI, script manager, editor, console, and log viewer.
* [DialogueScriptingBridge.md](docs/DialogueScriptingBridge.md) - Guide for executing Lua scripts from dialogue lines using FCS Extended.
* [LuaLS.md](docs/LuaLS.md) - Configure Lua Language Server editor support for KenshiLua scripts.
* [UnboundReference.md](docs/UnboundReference.md) - View for a list of methods and properties that exist in KenshiLib 0.5.0 but are not currently exposed to Lua.

KenshiLib is a large and complex codebase, and while KenshiLua exposes a large portion of it, there are still many methods and properties that are not yet exposed to Lua. If you find that a method or property you need is not available, please open an issue on the KenshiLua GitHub repository.

## Native C++ extensions

Native KenshiLib plugins can discover KenshiLua at runtime through the
header-only C++ Extension SDK. The SDK does not require linking against
`KenshiLua.lib` or `lua51.lib`; it negotiates a versioned function table from
the loaded `KenshiLua.dll`.

See [CppExtensionAPI.md](docs/CppExtensionAPI.md) for the API contract and
[Cpp_KenshiLib_Integration_Demo](examples/example_mods/Cpp_KenshiLib_Integration_Demo)
for a buildable plugin example.

## Installation

1. Ensure RE_Kenshi v0.3.3 or later is installed.
2. Download the latest release of KenshiLua and extract the archive, placing the contents in Kenshi's mods directory.
3. Activate the mod using the game's launcher like you would any other mod.

To get autocompletion and type checking for KenshiLua scripts in your editor, download `KenshiLua-LuaLS-Addon-v<version>.zip` from the same release and follow the README inside it. See [LuaLS.md](docs/LuaLS.md).

## Usage

### Example Lua Script

For example, if KenshiLib contains the class:
```cpp
class GameWorld
{
    void userPause(bool p);
    bool paused;
}
```

Then you can use it from Lua like this:
```lua
-- Get the global GameWorld instance.
local world = getGameWorld()

-- Call a method on the object.
world:userPause(true)

-- Read or modify one of the object's properties.
if world.paused then
  world.paused = false
end
```

There is also a list of events that you can register callbacks for like so:
```lua
-- This will run every time the InputHandler::keyDownEvent method is called by the game.

-- OIS::KeyCode KC_V is equal to the integer 47
local KC_V = 47

-- The callback receives an InputHandler* and an OIS::KeyCode integer.
local function on_key_down(thisptr, key_code)
-- if that int is equal to 47 (the v key was pressed)
if key_code == KC_V then
toggle_prone()
end
end

-- Register a callback to InputHandler::keyDownEvent
Events.on("InputHandler::keyDownEvent", on_key_down)
```

### Ways to load Lua scripts:

#### Loaded On Start
   - When the game starts, KenshiLua will check whether any **active** mods contain any `.lua` files inside of their `./scripts/init/` directory, and if found will automatically load them.
   - On Steam, active mods are resolved from both `Kenshi/mods/` and `steamapps/workshop/content/233860/<workshop-id>/`. Workshop items are matched to the active mod's `.mod` file; inactive Workshop items are not loaded.
   - So to clarify for a mod named `MyMod`, if you have a script at `./mods/MyMod/scripts/init/my_script.lua`, it will be loaded automatically when the game starts.
   - Scripts found in other directories within `./mods/MyMod/scripts/` (e.g. `./mods/MyMod/scripts/world_scripts.lua`) will not be loaded automatically.
   - Startup and on-demand scripts can load additional files from their own mod. All relative paths start at the mod's `scripts/` directory: `require("config.settings")` checks `scripts/config/settings.lua` and then `scripts/config/settings/init.lua`, while `dofile("config/settings.lua")` and `loadfile("config/settings.lua")` check that exact path. Mod-local `require` results are cached per script sandbox, so another mod can use the same internal module name safely.
   - Use ordinary `require`, such as `require("mygui.layout")`, for modules shipped in KenshiLua's `lib/` directory. Explicit dependencies on another active mod use `KenshiLua.requireFromMod("Shared Framework.mod", "api.shared")`; exact cross-mod files can be loaded with `KenshiLua.dofileFromMod` or `KenshiLua.loadfileFromMod`.

#### Dialogue Scripting Bridge
   - Using FCS Extended ([Github](https://github.com/BFrizzleFoShizzle/FCS_extended) | [Nexus](https://www.nexusmods.com/kenshi/mods/1825)) with KenshiLua enabled, you'll find a new `run lua script` option available for DIALOGUE, DIALOGUE_LINE, or WORD_SWAP. When the given dialogue plays, the script runs.
   - See [DialogueScriptingBridge.md](docs/DialogueScriptingBridge.md) for complete details on FCS setup, mod folder structure, injected Lua globals (`currentDialogue`, `currentDialogueLine`), and diagnostics.
<img width="2558" height="1548" alt="Screenshot 2026-07-13 140858" src="https://github.com/user-attachments/assets/c899339c-05f3-4aa2-aa28-cb6bd3eca7c5" />
     *The example shown in this image, available in the repository, uses the players Dexterity and Thieving stats to give the player an advatage in a game of dice. The script runs whenever the given dialogue option is chosen by the player.

#### In-Game GUI
   - Pressing `Ctrl` + `Shift` + `L` in-game will open KenshiLua's Main GUI. From here you can access the Script Editor and load, edit, save, and run scripts using the buttons on the Script Editor's toolbar as well as access other features.
<img width="2560" height="1600" alt="kenshi Screenshot 2026 07 13 - 14 33 49 79" src="https://github.com/user-attachments/assets/1dd44684-220b-4db2-ba56-7e9fba7f7d91" />

## Building KenshiLua

> [!WARNING]
> This section is **WIP** and is **not** intended for casual users. The process is complex and requires a solid understanding of the C++ build process and toolchain used by Kenshi and KenshiLib.

1. Clone the KenshiLua repository using the --recursive flag to ensure all dependencies are also cloned:
   `git clone --recursive https://github.com/Genpretz/KenshiLua.git`
2. Change the KenshiLib headers. KenshiLua pins the `extern/KenshiLib` submodule at `11cd65d`, KenshiLib 0.5.0, the version RE_Kenshi ships. Its headers need the changes below; paths are relative to `extern/KenshiLib/Include/`. To build a KenshiLua version that pins KenshiLib 0.3.0 (`v0.2.0-alpha` through `v0.3.9-alpha`), follow [Building KenshiLua with KenshiLib 0.3.0](docs/legacy/BuildingWithKenshiLib-0.3.0.md) instead.

   These classes are defined in two headers. Delete the duplicate and include the header that keeps the definition:

   | File | Change |
   | --- | --- |
   | `kenshi/Globals.h` | Delete the `namespace FoliageSystem { class EntData; }` block, which conflicts with `class FoliageSystem`, and add `#include "FoliageSystem.h"`. |
   | `kenshi/SaveInfo.h` | Delete `class GameplayOptions { ... };` and add `#include "GameplayOptions.h"`. |
   | `kenshi/PlayerInterface.h` | Delete `class ContextMenu { ... };` and add `#include "gui/ContextMenu.h"`. |
   | `kenshi/Campaign.h` | Delete `class CampaignTriggerData { ... };` and add `#include "Dialogue.h"`. |
   | `kenshi/ZoneManager.h`, `kenshi/combat/CombatClass.h` | Both define `class ParticlePool`. Move it into a new `kenshi/ParticlePool.h` ([contents](docs/legacy/BuildingWithKenshiLib-0.3.0.md#duplicate-definitions-still-present-in-050)), delete it from both headers, and include the new file: `#include <kenshi/ParticlePool.h>` in `ZoneManager.h` and `#include "../ParticlePool.h"` in `CombatClass.h`. |

   These declarations disagree with the game or with the libraries KenshiLua links against:

   | File | Change | Without it |
   | --- | --- | --- |
   | `kenshi/util/hand.h` | Move the `virtual bool operator==(const hand& a) const;` and `bool _NV_operator_equal(const hand& a) const;` lines above `virtual bool operator==(bool a) const;`. | KenshiLua still builds, but comparing two handles calls `hand::operator==(bool)`. MSVC places overloaded virtual functions in reverse declaration order, which swaps the two `operator==` vtable slots relative to the game. |
   | `kenshi/Havok.h` | Move `enum Mask` out of `hkVector4fComparison` into a new `struct hkVector4ComparisonMask` declared just before it, and add `typedef hkVector4ComparisonMask::Mask Mask;` to `hkVector4fComparison`. | Link errors: KenshiLib exports the class's methods with `hkVector4ComparisonMask::Mask` parameters. |
   | `mygui/MyGUI_ItemBox.h` | Add a trailing `bool update = true` parameter to `insertItemAt`, `addItem`, and `removeItemAt`. | KenshiLua imports `ItemBox` methods that Kenshi's `MyGUIEngine_x64.dll` does not export and fails to load. |
   | `mygui/common/baselayout/BaseLayout.h` | Change `class __declspec(dllimport) BaseLayout` to `class BaseLayout`. | Link error: the linker expects `BaseLayout`'s constructor from a DLL. |

3. Replace `extern/KenshiLib/Libraries/mygui/MyGUIEngine_x64.lib` with an import library generated from Kenshi's `MyGUIEngine_x64.dll`, following [Regenerate the MyGUI import library](docs/legacy/BuildingWithKenshiLib-0.3.0.md#3-regenerate-the-mygui-import-library). Kenshi uses a customized MyGUI, and the library in the KenshiLib repository does not match it.
4. Build `extern/KenshiLib/KenshiLib.vcxproj` using its Release x64 configuration. KenshiLua links the resulting `extern/KenshiLib/x64/Release/KenshiLib.lib`.
5. Build KenshiLua using the Release configuration available in `KenshiLua.vcxproj`. (Debug builds **will not work** as they are not compatible with the release version of Kenshi and KenshiLib and are not functional).
6. `KenshiLua.vcxproj` includes a post-build event that will copy the built `KenshiLua.dll` along with all the other files and directories required for KenshiLua to run to `$(ProjectDir)bin/KenshiLua/`

At runtime, KenshiLua uses the `KenshiLib.dll` that RE_Kenshi installs in the game folder, not the one built in step 4. A build loads only if that DLL and Kenshi's `MyGUIEngine_x64.dll` export every symbol KenshiLua imports; compare `dumpbin /imports` of `KenshiLua.dll` with `dumpbin /exports` of each DLL to check. These changes are the set used for the builds tested in Kenshi 1.0.65 GOG and Steam on 2026-10-23; they have not been rebuilt from a clean checkout on their own.

#### Notes on Toolchain Constraints
* The game and KenshiLib are built against MSVC2010-era assumptions, including C++ ABI layout and runtime library behavior. KenshiLua and all ofther dependencies must match these constraints to ensure stable integration.
* There are no official LuaJIT release binaries built for MSVC2010. Therefore, a compatible version is included in the repository. If you wish to compile LuaJIT from source, ensure you build for MSVC2010.

---

### About KenshiLua's Development

Originally, while working on KenshiPy, an analogous Python extension for Kenshi, I discovered that although SWIG made it possible to generate bindings with very little effort, SWIG 3.0.12 became difficult to work with when wrapping certain parts of KenshiLib. The generated bindings ended up as one **huge** monolithic file, totaling **259,649 lines** the last time I checked. Because SWIG generates bindings as a single translation unit, they can't easily be split across multiple source files. This made the generated code difficult to manage, and with compiler optimizations enabled, build times could easily approach an hour. Combined with the fact that KenshiPy relied on the long-outdated Python 3.4, the overall development experience became increasingly frustrating. While SWIG's language-agnostic interface files would have made switching to another language relatively straightforward, changing languages alone wouldn't have solved most of these underlying issues.

Around this time, I decided that Lua was a better fit for the project. Its similarity to Python and widespread use in the modding community made it a natural choice. Lua also had relatively recent release in v5.4 with pre-built MSVC2010 binaries, but luckily building Lua 5.5 with MSVC2010 turned out to be straightforward. I explored several binding libraries, including sol2, luabind, and others, but most were not immediately compatible with the MSVC2010 toolchain used by Kenshi and KenshiLib or were limited in the version of Lua they were compatible with. In the end, I decided to write the bindings manually. Fortunately, once you've implemented the binding code for one method or member variable, the rest largely follows the same pattern, making it easy to reuse and adapt the code. I decided to leverage the use of AI tools to generate scripts for parsing KenshiLib's headers in order to generate all the simplest bindings and scaffolding needed to move forward as well as scripts for generating minimal documentation of the bindings. AI undoubtly expediated the development process, but it led to many issues including duplicated functionality, broken bindings, and orphaned code. One instance in which it was helpful was when the project switched to LuaJIT.

Further research had led me to discover LuaJIT, a just-in-time compiler based on Lua 5.1 that is often reported to deliver performance approaching native C. Since it promised better performance than standard Lua, I wanted to evaluate it before the project grew any larger. After confirming that LuaJIT could also be built with MSVC2010, I created a separate branch using it. That branch has since become the project's main branch. My own benchmarking has shown only very small performance differences between the two implementations so far, so whether LuaJIT's potential performance gains ultimately outweigh the additional language features available in Lua 5.5 remains an open question.

