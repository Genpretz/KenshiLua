# KenshiLua

KenshiLua is a DLL extension for Kenshi that embeds a Lua runtime and exposes selected portions of KenshiLib to Lua.

The goal is to provide a Lua scripting workflow to mod Kenshi and lower the barrier to entry for utilizing KenshiLib through rapid iteration and scripting.

## Overview

Loaded at runtime through RE_Kenshi, KenshiLua exposes selected portions of KenshiLib through a mixture of generated and hand-written Lua bindings, enabling rapid development, experimentation, and mod creation without requiring direct interaction with the underlying C++ APIs.

KenshiLua currently provides:
* Exposes KenshiLib functionality through Lua
* Provides a Script Editor GUI for writing and running scripts in-game
* Allows for Lua scripts to be loaded from a mod folder at runtime
* Exposes selected engine event callbacks to Lua

## How much of KenshiLib can be used from Lua?

A large amount of KenshiLib has been exposed for use from Lua. View [BindingReference.md](docs/BindingReference.md) for a full list of available functions and classes.

## Things to Add
* Support for more C++ container classes.
* More comprehensive MyGUI bindings.
* Additional engine event callbacks.

## Installation

1. Ensure RE_Kenshi v0.3.3 or later is installed.
2. Download the latest release of KenshiLua and extract the archive, placing the contents in Kenshi's mods directory.
3. Activate the mod using the game's launcher like you would any other mod.

## Usage

### Script Editor GUI
Pressing Ctrl + Shift + L` in-game will open KenshiLua's Script Editor GUI. From here you can load, edit, save, and run scripts using the buttons on the Script Editor's toolbar.

### Loading Lua Scripts
When the game starts, KenshiLua will check whether any active mods contain any .lua files, and if found will load them.

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

---

## Compiling from Source - NOT FINISHED

### Quick Guide

1. Compile the generated wrappers alongside the rest of KenshiLua's source into `KenshiLua.dll`.
2. Place `KenshiLua.dll` along with `Kenshi_ScriptEditor_EditBox.xml` and `RE_Kenshi.json` into a mod folder named `KenshiLua`.

### Prerequisites
* Visual Studio 2010 Professional/Ultimate
* Visual Studio 2022 Community

#### Notes on Toolchain Constraints
* The game and KenshiLib are built against MSVC2010-era assumptions, including C++ ABI layout, runtime library behavior, and script embedding conventions. KenshiLua must match these constraints to ensure stable integration.
* Lua 5.5 must be compiled from source using MSVC2010 to match the runtime expectations of the host game executable.

### About KenshiLua

Originally when working on KenshiPy, a Python extension for Kenshi, I discovered that while SWIG did allow for generating bindings in other languages, SWIG 3.0.12 was difficult to work with when trying to wrap certain parts of KenshiLib. The SWIG generated bindings were also too opaque and made it difficult to grasp what parts of KenshiLib had actually been exposed. Plus Python 3.4 being so old was another point that I didn't like. This led me to investigate other binding generation tools. I orignally intended to have SWIG generate the Lua bindings, but after getting Lua setup, I found that doing the bindings manually wasn't too difficult and made it easier to keep track of the state of the project. So I decided to create KenshiLua as a Lua-based scripting extension for Kenshi.
