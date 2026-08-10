
# KenshiLua

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

A large amount of KenshiLib has been exposed for use from Lua. This includes almost the entirety of KenshiLib 0.3.0.
* [BindingReference.md](docs/BindingsReference.md) - View for a list of methods and properties available from Lua.
* [UnboundReference.md](docs/UnboundReference.md) - View for a list of methods and properties that exist in KenshiLib 0.3.0 but are not currently exposed to Lua.

## Installation

1. Ensure RE_Kenshi v0.3.3 or later is installed.
2. Download the latest release of KenshiLua and extract the archive, placing the contents in Kenshi's mods directory.
3. Activate the mod using the game's launcher like you would any other mod.

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

### Ways to load Lua scripts:

#### Loaded On Start
   - When the game starts, KenshiLua will check whether any **active** mods contain any `.lua` files inside of their `./scripts/init/` directory, and if found will automatically load them.
   - So to clarify for a mod named `MyMod`, if you have a script at `./mods/MyMod/scripts/init/my_script.lua`, it will be loaded automatically when the game starts.
   - Scripts found in other directories within `./mods/MyMod/scripts/` (e.g. `./mods/MyMod/scripts/world_scripts.lua`) will not be loaded automatically.

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
2. Several changes need to be made to KenshiLib v0.3.0's headers for KenshiLua to be able to compile.

   * Add `#pragma once` to the top of every header file that doesn't already have it. These include:
      - CharMovement.h
      - DataPanelLine.h
      - FarmBuilding.h
   * MainBarGUI.h
      - Forward declare class `MainBarGUI` before `class MainTabPortraitPlatoon : public Ogre::GeneralAllocatedObject`.
   * ManagementScreen.h
      - Add `#include <mygui/common/itembox/BaseItemBox.h>`
      - Add `template<typename T> class ReorderableListItem;` before `class ReorderableList : public wraps::BaseItemBox<ReorderableListItem<T2> >, public Ogre::GeneralAllocatedObject`.
      - Remove the `override` from `virtual ~ReorderableList() override;` in `class ReorderableList`.
   * OrdersPanel.h
      - Forward declare `class OrderData;` before `class OrderCellView : public wraps::BaseCellView<OrderData*>, public Ogre::GeneralAllocatedObject`
   * Globals.h
      - Remove the lines declaring `namespace FoliageSystem` and `class EntData`.
   * NavMesh.h
      - Remove `MessageQueue<T>::` prefix from the members within `class MessageQueue` and the nested struct `Node`.
   * Platoon.h
      - Remove the definition for `enum BuildingDesignation` and instead add `#include "Building/Building.h"` to the list of includes.
   * PlayerInterface.h
      - Add the following include, `#include "kenshi/gui/ContextMenu.h"` and remove the definition for `class ContextMenu`.

3. Build KenshiLua using the Release configuration available in `KenshiLua.vcxproj`. (Debug builds **will not work** as they are not compatible with the release version of Kenshi and KenshiLib and are not functional).
4. `KenshiLua.vcxproj` includes a post-build event that will copy the built `KenshiLua.dll` along with all the other files and directories required for KenshiLua to run to `$(ProjectDir)bin/KenshiLua/`

#### Notes on Toolchain Constraints
* The game and KenshiLib are built against MSVC2010-era assumptions, including C++ ABI layout and runtime library behavior. KenshiLua and all ofther dependencies must match these constraints to ensure stable integration.
* There are no official LuaJIT release binaries built for MSVC2010. Therefore, a compatible version is included in the repository. If you wish to compile LuaJIT from source, ensure you build for MSVC2010.

---

### About KenshiLua's Development

Originally, while working on KenshiPy, an analogous Python extension for Kenshi, I discovered that although SWIG made it possible to generate bindings with very little effort, SWIG 3.0.12 became difficult to work with when wrapping certain parts of KenshiLib. The generated bindings ended up as one **huge** monolithic file, totaling **259,649 lines** the last time I checked. Because SWIG generates bindings as a single translation unit, they can't easily be split across multiple source files. This made the generated code difficult to manage, and with compiler optimizations enabled, build times could easily approach an hour. Combined with the fact that KenshiPy relied on the long-outdated Python 3.4, the overall development experience became increasingly frustrating. While SWIG's language-agnostic interface files would have made switching to another language relatively straightforward, changing languages alone wouldn't have solved most of these underlying issues.

Around this time, I decided that Lua was a better fit for the project. Its similarity to Python and widespread use in the modding community made it a natural choice. Lua also had relatively recent release in v5.4 with pre-built MSVC2010 binaries, but luckily building Lua 5.5 with MSVC2010 turned out to be straightforward. I explored several binding libraries, including sol2, luabind, and others, but most were not immediately compatible with the MSVC2010 toolchain used by Kenshi and KenshiLib or were limited in the version of Lua they were compatible with. In the end, I decided to write the bindings manually. Fortunately, once you've implemented the binding code for one method or member variable, the rest largely follows the same pattern, making it easy to reuse and adapt the code. I decided to leverage the use of AI tools to generate scripts for parsing KenshiLib's headers in order to generate all the simplest bindings and scaffolding needed to move forward as well as scripts for generating minimal documentation of the bindings. AI undoubtly expediated the development process, but it led to many issues including duplicated functionality, broken bindings, and orphaned code. One instance in which it was helpful was when the project switched to LuaJIT.

Further research had led me to discover LuaJIT, a just-in-time compiler based on Lua 5.1 that is often reported to deliver performance approaching native C. Since it promised better performance than standard Lua, I wanted to evaluate it before the project grew any larger. After confirming that LuaJIT could also be built with MSVC2010, I created a separate branch using it. That branch has since become the project's main branch. My own benchmarking has shown only very small performance differences between the two implementations so far, so whether LuaJIT's potential performance gains ultimately outweigh the additional language features available in Lua 5.5 remains an open question.

