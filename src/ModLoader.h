#pragma once

#include <string>
#include <vector>

extern "C" {
#include <lua.h>
}

namespace KenshiLua
{

// Information about a single Lua script we found inside an active mod.
struct LoadedScript
{
    std::string modName;       // ModInfo::name, e.g. "RimWorld - Kenshi.mod"
    std::string modPath;       // ModInfo::path
    std::string absolutePath;  // full path to the .lua file
    std::string relativePath;  // path relative to modPath
    std::string chunkName;     // "@<mod>/<relative>"
    bool        loaded;        // executed successfully
    std::string lastError;     // last error message, if any
};

class ModLoader
{
public:
    ModLoader();
    ~ModLoader();

    static ModLoader& get();

    // Walks ou->activeMods, discovers all *.lua files, executes each one in
    // its own sandboxed _ENV table.  Safe to call exactly once per game
    // session; subsequent calls without reload() are no-ops.
    void loadAll(lua_State* L);

    // Discards script-introduced globals and re-runs every script.  Used by
    // the GUI's "Reload" button.  This DOES NOT recreate the lua_State, so
    // C-side bindings persist and metatables don't churn.
    void reloadAll(lua_State* L);

    bool hasLoaded() const { return m_loaded; }

    const std::vector<LoadedScript>& scripts() const { return m_scripts; }

    // List of mod names we considered (active mods).  Useful for the GUI.
    const std::vector<std::string>& activeModNames() const { return m_activeModNames; }

private:
    ModLoader(const ModLoader&);
    ModLoader& operator=(const ModLoader&);

    void discover();
    bool runScript(lua_State* L, LoadedScript& s);

    std::vector<LoadedScript>  m_scripts;
    std::vector<std::string>   m_activeModNames;
    bool                       m_loaded;
};

} // namespace KenshiLua
