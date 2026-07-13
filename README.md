
# KenshiLua

KenshiLua is a DLL extension for Kenshi that embeds a Lua runtime and exposes selected portions of KenshiLib to Lua.

The goal is to provide a Lua scripting workflow to mod Kenshi and lower the barrier to entry for utilizing KenshiLib through rapid iteration and scripting.

## Overview

Loaded at runtime through RE_Kenshi, KenshiLua exposes selected portions of KenshiLib through a mixture of generated and hand-written Lua bindings, enabling rapid development, experimentation, and mod creation without requiring direct interaction with the underlying C++ APIs.

* Exposes KenshiLib functionality through Lua
* Provides a Script Editor GUI for writing and running scripts in-game
* Allows for Lua scripts to be loaded from a mod folder at runtime
* Exposes selected engine event callbacks to Lua

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
}
```

Then you can use it from Lua like this:
```lua
-- Get pointer to global GameWorld object
local world = getGameWorld()

--Call a method on an object
world:userPause(true)

-- or set a field
world.userPause = false
```

### Ways to load Lua scripts:

#### Loaded On Start
   - When the game starts, KenshiLua will check whether any **active** mods contain any `.lua` files inside of their `./scripts/init/` directory, and if found will automatically load them.
   - So to clarify for a mod named `MyMod`, if you have a script at `./mods/MyMod/scripts/init/my_script.lua`, it will be loaded automatically when the game starts.
   - Scripts found in other directories within `./mods/MyMod/scripts/` (e.g. `./mods/MyMod/scripts/world_scripts.lua`) will not be loaded automatically.

#### Dialogue Scripting Bridge
   - Using FCS Extended ([Github](https://github.com/BFrizzleFoShizzle/FCS_extended) | [Nexus](https://www.nexusmods.com/kenshi/mods/1825)) with KenshiLua enabled, you'll find a new `run lua script` option available for DIALOGUE, DIALOGUE_LINE, or WORD_SWAP. When the given dialogue plays, the script runs.
<img width="2558" height="1540" alt="Screenshot 2026-07-07 101548" src="https://github.com/user-attachments/assets/3d95b861-eb9e-489e-aee2-911492f2e7c5" />
     *The example shown in this image, available in the repository, uses the players Dexterity and Thieving stats to give the player an advatage in a game of dice. The script runs whenever the given dialogue option is chosen by the player.

#### Script Editor GUI
   - Pressing `Ctrl` + `Shift` + `L` in-game will open KenshiLua's Script Editor GUI. From here you can load, edit, save, and run scripts using the buttons on the Script Editor's toolbar.
   - Currently the keybind can be configured using `config.txt` located in the KenshiLua mod directory, e.g. `./mods/KenshiLua/config.txt`
<img width="2560" height="1600" alt="ScriptEditor" src="https://github.com/user-attachments/assets/a6787b96-93b7-4dfc-8045-8cb591357e9a" />

## Compiling from Source - NOT FINISHED

### Quick Guide

1. Build KenshiLib and LuaJit against MSVC2010.
2. Link against both KenshiLib and LuaJit in the KenshiLua project.
3. Build KenshiLua using the Release configuration available in `KenshiLua.vcxproj`. (Debug builds **will not work** as they are not compatible with the release version of Kenshi).
4. Using the FCS, create a new mod named `KenshiLua`.
5. Place the newly built `KenshiLua.dll` binary along with `Kenshi_ScriptEditor_EditBox.xml`, `RE_Kenshi.json` and `fcs.def` into the `KenshiLua` mod directory.
6. ...
7. Profit?

### Prerequisites
* Visual Studio 2010 Professional/Ultimate
* Visual Studio 2026 Community

* LuaJIT
* Boost 1.60.0
* KenshiLib

#### Notes on Toolchain Constraints
* The game and KenshiLib are built against MSVC2010-era assumptions, including C++ ABI layout and runtime library behavior. KenshiLua and all ofther dependencies must match these constraints to ensure stable integration.
* LuaJIT doesn't have any public binaries compiled using MSVC2010. One is included in the repository, but if you choose not to use it, then compiling LuaJIT from source for MSVC2010 is required.

---

### About KenshiLua's Development

Originally, while working on KenshiPy, an analogous Python extension for Kenshi, I discovered that although SWIG made it possible to generate bindings with very little effort, SWIG 3.0.12 became difficult to work with when wrapping certain parts of KenshiLib. The generated bindings ended up as one **huge** monolithic file, totaling **259,649 lines** the last time I checked. Because SWIG generates bindings as a single translation unit, they can't easily be split across multiple source files. This made the generated code difficult to manage, and with compiler optimizations enabled, build times could easily approach an hour. Combined with the fact that KenshiPy relied on the long-outdated Python 3.4, the overall development experience became increasingly frustrating. While SWIG's language-agnostic interface files would have made switching to another language relatively straightforward, changing languages alone wouldn't have solved most of these underlying issues.

Around this time, I decided that Lua was a better fit for the project. Its similarity to Python and widespread use in the modding community made it a natural choice. Lua also had relatively recent release in v5.4 with pre-built MSVC2010 binaries, but luckily building Lua 5.5 with MSVC2010 turned out to be straightforward. I explored several binding libraries, including sol2, luabind, and others, but most were not immediately compatible with the MSVC2010 toolchain used by Kenshi and KenshiLib or were limited in the version of Lua they were compatible with. In the end, I decided to write the bindings manually. Fortunately, once you've implemented the binding code for one method or member variable, the rest largely follows the same pattern, making it easy to reuse and adapt the code. I decided to leverage the use of AI tools to generate scripts for parsing KenshiLib's headers in order to generate all the simplest bindings and scaffolding needed to move forward as well as scripts for generating minimal documentation of the bindings. AI undoubtly expediated the development process, but it led to many issues including duplicated functionality, broken bindings, and orphaned code. One instance in which it was helpful was when the project switched to LuaJIT.

Further research had led me to discover LuaJIT, a just-in-time compiler based on Lua 5.1 that is often reported to deliver performance approaching native C. Since it promised better performance than standard Lua, I wanted to evaluate it before the project grew any larger. After confirming that LuaJIT could also be built with MSVC2010, I created a separate branch using it. That branch has since become the project's main branch. My own benchmarking has shown only very small performance differences between the two implementations so far, so whether LuaJIT's potential performance gains ultimately outweigh the additional language features available in Lua 5.5 remains an open question.

