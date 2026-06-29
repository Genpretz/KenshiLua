#pragma once

#include <string>
#include <vector>
#include <unordered_map>

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

class ScriptLoader
{
public:
    ScriptLoader();
    ~ScriptLoader();

    static ScriptLoader& get();

    // Walks ou->activeMods, discovers all *.lua files, executes each one in
    // its own sandboxed _ENV table. Safe to call exactly once per game
    // session; subsequent calls without reload() are no-ops.
    void loadAll(lua_State* L);

    // Discards script-introduced globals and re-runs every script.
    void reloadAll(lua_State* L);

    bool hasLoaded() const { return m_loaded; }

    const std::vector<LoadedScript>& scripts() const { return m_scripts; }

    // List of mod names we considered (active mods). Useful for the GUI.
    const std::vector<std::string>& activeModNames() const { return m_activeModNames; }

    // Resolves a script path on-demand by checking active mod directories.
    // Caches the results to prevent performance hitching during game frames.
    std::string resolveScriptPath(const std::string& filename);

    // Centralized sandboxed runner for Lua script files.
    bool runScriptSandboxed(lua_State* L, const std::string& absolutePath, const std::string& chunkName, std::string* outError = NULL);

private:
    ScriptLoader(const ScriptLoader&);
    ScriptLoader& operator=(const ScriptLoader&);

    void discover();
    bool runScript(lua_State* L, LoadedScript& s);

    std::vector<LoadedScript>  m_scripts;
    std::vector<std::string>   m_activeModNames;
    std::unordered_map<std::string, std::string> m_resolvedScriptPaths;
    bool                       m_loaded;
};

} // namespace KenshiLua
