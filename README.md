
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

A large amount of KenshiLib has been exposed for use from Lua. This includes all major classes and a majority of their contents. View [BindingReference.md](docs/BindingsReference.md) for a full list of methods and properties available from Lua.

To do:
* Additional support for more C++ container classes.
* More comprehensive MyGUI bindings.
* Additional engine event callbacks.

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
   - When the game starts, KenshiLua will check whether any active mods contain any `.lua` files inside of their `./scripts/init/` directory, and if found will automatically load them.

#### Dialogue Scripting Bridge
   - Using FCS Extended ([Github](https://github.com/BFrizzleFoShizzle/FCS_extended) | [Nexus](https://www.nexusmods.com/kenshi/mods/1825)) with KenshiLua enabled, you'll find a new `lua script` field available for DIALOGUE, DIALOGUE_LINE, or WORD_SWAP. When the given dialogue plays, the script runs.
<img width="2558" height="1540" alt="Screenshot 2026-07-07 101548" src="https://github.com/user-attachments/assets/3d95b861-eb9e-489e-aee2-911492f2e7c5" />
     *The example shown in this image, available in the repository, uses the players Dexterity and Thieving stats to give the player an advatage in a game of dice. The script runs whenever the given dialogue option is chosen by the player.

#### Script Editor GUI
   - Pressing `Ctrl` + `Shift` + `L` in-game will open KenshiLua's Script Editor GUI. From here you can load, edit, save, and run scripts using the buttons on the Script Editor's toolbar.
   - Currently the keybind can be configured from config.txt
<img width="2560" height="1600" alt="ScriptEditor" src="https://github.com/user-attachments/assets/a6787b96-93b7-4dfc-8045-8cb591357e9a" />

## Compiling from Source - NOT FINISHED

### Quick Guide

1. Link MSVC2010 build of LuaJIT.
2. Compile Source
3. Place newly built `KenshiLua.dll` binary along with `Kenshi_ScriptEditor_EditBox.xml`, `RE_Kenshi.json` and `fcs.def` into a mod folder named `KenshiLua`.
4. ...
5. Profit?

### Prerequisites
* Visual Studio 2010 Professional/Ultimate
* Visual Studio 2026 Community

* LuaJIT
* Boost 1.60.0
* KenshiLib

#### Notes on Toolchain Constraints
* The game and KenshiLib are built against MSVC2010-era assumptions, including C++ ABI layout and runtime library behavior. KenshiLua and all ofther dependencies must match these constraints to ensure stable integration.
* LuaJIT doesn't have any public binaries compiled using MSVC2010. One is included in the repository, but if you choose not to use it, then compiling LuaJIT from source for MSVC2010 is required.

### About KenshiLua's Development

Originally when working on KenshiPy, an analogous Python extension for Kenshi, I discovered that while SWIG did allow for generating bindings with very little work, SWIG 3.0.12 was difficult to work with when trying to wrap certain parts of KenshiLib. The SWIG generated bindings were too opaque and made it difficult to grasp what parts of KenshiLib had actually been exposed. SWIG was also limited to the use of a single translation unit for it's bindings which meant that if optimizations were enabled the compile time could often be almost an hour. All this coupled with Python 3.4 being so outdated was just too much. I invenstigated various other methods for generating bindings. SWIG allows for generating bindings in a variety of languages using the same interface files and headers and so after some thought with Lua's similarity to Python and its widespread use in modding, it seemed like the right choise.

So I decided to create KenshiLua as a Lua-based scripting extension for Kenshi. I intended to have SWIG generate the Lua bindings, but in order to avoid the previously mentioned issues associated with SWIG, hand-written bindings seemed the best option. Lua 5.4 is the latest release with pre-built MSVC10 binaries available but eventually I built 5.5 (the newest release version) from source. Further research led me to discovering the existence of LuaJIT, a just-in-time compiler built on Lua 5.1 that offers performance close to that of C. Before the project got any larger I made a branch using LuaJIT. The performance `should` be better than standard Lua. My attempts at benchmarking the two branches shows very small differences in performance currently. Whether or not LuaJIT's performance gains outweigh the additional features available in 5.5 is yet to be seen.
