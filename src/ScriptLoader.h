#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <set>

extern "C" {
#include <lua.h>
}

namespace KenshiLua
{

// Information about a single Lua script we found inside an active mod.
struct LoadedScript
{
    std::string modName;       // ModInfo::name, e.g. "RimWorld - Kenshi"
    std::string modPath;       // resolved local or Steam Workshop mod root
    std::string absolutePath;  // full path to the .lua file
    std::string relativePath;  // path relative to modPath
    std::string chunkName;     // "@<mod>/<relative>"
    bool        loaded;        // executed successfully
    std::string lastError;     // last error message, if any
};

class ScriptLoader
{
public:
    enum RunScriptStatus
    {
        RUN_SCRIPT_OK = 0,
        RUN_SCRIPT_FILE_ERROR,
        RUN_SCRIPT_SYNTAX_ERROR,
        RUN_SCRIPT_MEMORY_ERROR,
        RUN_SCRIPT_RUNTIME_ERROR
    };

    ScriptLoader();
    ~ScriptLoader();

    static ScriptLoader& get();

    // Walks ou->activeMods, discovers all *.lua files, executes each one in
    // its own sandboxed _ENV table. Safe to call exactly once per game
    // session; subsequent calls without reload() are no-ops.
    void loadAll(lua_State* L);

    // Discards script-introduced globals and re-runs every script.
    void reloadAll(lua_State* L);

    // Reloads a single script file in its sandboxed environment.
    bool reloadSingleScript(lua_State* L, const std::string& absolutePath);

    // Resets the script loader state so scripts can be re-discovered and loaded again.
    void reset();

    bool hasLoaded() const { return m_loaded; }

    const std::vector<LoadedScript>& scripts() const { return m_scripts; }

    // List of mod names we considered (active mods). Useful for the GUI.
    const std::vector<std::string>& activeModNames() const { return m_activeModNames; }

    // Resolves a script path on-demand by checking active mod directories.
    // Caches the results to prevent performance hitching during game frames.
    std::string resolveScriptPath(const std::string& filename);

    // Explicit cross-mod loading APIs. The requested name accepts either the
    // active ModInfo::name or its .mod descriptor filename. Relative paths
    // are confined to that mod's scripts directory.
    int requireFromMod(lua_State* L, const std::string& modName,
        const std::string& moduleName);
    int dofileFromMod(lua_State* L, const std::string& modName,
        const std::string& filename);
    int loadfileFromMod(lua_State* L, const std::string& modName,
        const std::string& filename);

    // Centralized sandboxed runner for Lua script files.
    bool runScriptSandboxed(lua_State* L, const std::string& absolutePath,
        const std::string& chunkName, std::string* outError = NULL,
        RunScriptStatus* outStatus = NULL);

    void addStoppedScript(const std::string& path) { m_stoppedScripts.insert(path); }
    void removeStoppedScript(const std::string& path) { m_stoppedScripts.erase(path); }
    void clearStoppedScripts() { m_stoppedScripts.clear(); }
    bool isScriptStopped(const std::string& path) const { return m_stoppedScripts.find(path) != m_stoppedScripts.end(); }

    // Walks ou->activeMods, discovers all *.lua files.
    void discover();

private:
    ScriptLoader(const ScriptLoader&);
    ScriptLoader& operator=(const ScriptLoader&);

    bool runScript(lua_State* L, LoadedScript& s);
    void updateScriptStatus(const std::string& absolutePath, bool loaded, const std::string& error = "");
    void clearProviderEnvironments(lua_State* L);

    std::vector<LoadedScript>  m_scripts;
    std::vector<std::string>   m_activeModNames;
    std::unordered_map<std::string, std::string> m_resolvedScriptPaths;
    std::string                m_lastDiscoveredSummary;
    bool                       m_loaded;
    std::set<std::string>      m_stoppedScripts;
};

} // namespace KenshiLua
