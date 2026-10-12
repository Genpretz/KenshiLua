#include "pch.h"
#include "ScriptLoader.h"
#include "Logger.h"
#include "EventSystem.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Util/PathUtils.h"

#include <kenshi/Globals.h>
#include <kenshi/GameWorld.h>
#include <kenshi/ModInfo.h>
#include <kenshi/util/lektor.h>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/system/error_code.hpp>

#include <algorithm>
#include <cctype>
#include <cstring>

#include "Lua/LuaState.h"

namespace KenshiLua
{

namespace fs = boost::filesystem;

static std::string makeChunkName(const std::string& modName, const std::string& relPath)
{
    std::string out = "@";
    out += modName;
    out += "/";
    out += relPath;
    return out;
}

static void createSandboxEnv(lua_State* L)
{
    lua_newtable(L);
    lua_newtable(L);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_setfield(L, -2, "__index");
    lua_setmetatable(L, -2);
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "_ENV");
}

static char lowerPathCharacter(char value)
{
    return static_cast<char>(std::tolower(static_cast<unsigned char>(value)));
}

static std::string lowerPath(std::string value)
{
    normalizePathSlashes(value);
    std::transform(value.begin(), value.end(), value.begin(), lowerPathCharacter);
    return value;
}

static bool canonicalFileInside(const fs::path& root, const fs::path& candidate,
    std::string& resolved)
{
    boost::system::error_code ec;
    if (!fs::exists(candidate, ec) || ec || !fs::is_regular_file(candidate, ec) || ec)
        return false;

    fs::path canonicalRoot = fs::canonical(root, ec);
    if (ec) return false;
    fs::path canonicalCandidate = fs::canonical(candidate, ec);
    if (ec) return false;

    std::string rootString = lowerPath(canonicalRoot.string());
    std::string candidateString = lowerPath(canonicalCandidate.string());
    if (!rootString.empty() && rootString[rootString.size() - 1] != '/')
        rootString += '/';
    if (candidateString.size() <= rootString.size() ||
        candidateString.compare(0, rootString.size(), rootString) != 0)
        return false;

    resolved = canonicalCandidate.string();
    return true;
}

void ScriptLoader::updateScriptStatus(const std::string& absolutePath, bool loaded, const std::string& error)
{
    for (size_t i = 0; i < m_scripts.size(); ++i) {
        if (m_scripts[i].absolutePath == absolutePath) {
            m_scripts[i].loaded = loaded;
            m_scripts[i].lastError = error;
            break;
        }
    }
}

ScriptLoader::ScriptLoader() : m_loaded(false) {}
ScriptLoader::~ScriptLoader() {}

ScriptLoader& ScriptLoader::get()
{
    static ScriptLoader instance;
    return instance;
}

void ScriptLoader::discover()
{
    // Save existing running state
    std::unordered_map<std::string, std::pair<bool, std::string>> runningState;
    for (size_t i = 0; i < m_scripts.size(); ++i) {
        runningState[m_scripts[i].absolutePath] = std::make_pair(m_scripts[i].loaded, m_scripts[i].lastError);
    }

    m_scripts.clear();
    m_activeModNames.clear();

	// GameWorld Singleton (ou)
    if (!::ou) {
        logToFileWarn("ScriptLoader: GameWorld (ou) not yet available - skipping mod discovery");
        return;
    }

    lektor<ModInfo*>& mods = ::ou->activeMods;
    int n = (int)mods.size();
    if (n == 0) {
        logToFile("ScriptLoader: no active mods");
        return;
    }

    for (int i = 0; i < n; ++i) {
        ModInfo* mi = mods[i];
        if (!mi) continue;
        m_activeModNames.push_back(mi->name);

        if (mi->path.empty()) continue;

        fs::path modRoot(mi->path);
        fs::path scriptsDir = modRoot / "scripts";
        boost::system::error_code ec;
        if (!fs::exists(scriptsDir, ec) || !fs::is_directory(scriptsDir, ec)) continue;

        std::vector<std::string> found;
        fs::recursive_directory_iterator it(scriptsDir, ec);
        fs::recursive_directory_iterator end;
        for (; !ec && it != end; it.increment(ec)) {
            if (ec) break;
            if (!fs::is_regular_file(it->status())) continue;
            std::string p = it->path().string();
            if (!endsWithCaseInsensitive(p, ".lua")) continue;
            found.push_back(p);
        }

        std::sort(found.begin(), found.end());

        for (size_t k = 0; k < found.size(); ++k) {
            LoadedScript s;
            s.modName = mi->name;
            s.modPath = mi->path;
            s.absolutePath = found[k];

            if (s.absolutePath.size() > s.modPath.size() + 1
                && s.absolutePath.compare(0, s.modPath.size(), s.modPath) == 0) {
                s.relativePath = s.absolutePath.substr(s.modPath.size() + 1);
            } else {
                s.relativePath = s.absolutePath;
            }
            normalizePathSlashes(s.relativePath);
            s.chunkName = makeChunkName(s.modName, s.relativePath);

            // Restore previous running state if it existed
            auto stateIt = runningState.find(s.absolutePath);
            if (stateIt != runningState.end()) {
                s.loaded = stateIt->second.first;
                s.lastError = stateIt->second.second;
            } else {
                s.loaded = false;
            }

            m_scripts.push_back(s);
        }
    }

    std::string summary = "ScriptLoader: discovered " + std::to_string((long long)m_scripts.size())
              + " script(s) across "
              + std::to_string((long long)m_activeModNames.size()) + " active mod(s)";
    if (summary != m_lastDiscoveredSummary) {
        logToFile(summary);
        m_lastDiscoveredSummary = summary;
    }
}

bool ScriptLoader::runScriptSandboxed(lua_State* L, const std::string& absolutePath,
    const std::string& chunkName, std::string* outError, RunScriptStatus* outStatus)
{
    if (outStatus) *outStatus = RUN_SCRIPT_OK;
    int top = lua_gettop(L);

    fs::path path(absolutePath);
    fs::ifstream f(path, std::ios::binary | std::ios::ate);
    if (!f) {
        std::string errStr = "could not open " + absolutePath;
        logToFileError("ScriptLoader: " + errStr);
        if (outError) *outError = errStr;
        if (outStatus) *outStatus = RUN_SCRIPT_FILE_ERROR;
        updateScriptStatus(absolutePath, false, errStr);
        return false;
    }
    std::streamsize sz = f.tellg();
    f.seekg(0, std::ios::beg);
    std::string buf;
    if (sz > 0) {
        buf.resize(static_cast<size_t>(sz));
        if (!f.read(&buf[0], sz)) {
            std::string errStr = "failed to read " + absolutePath;
            logToFileError("ScriptLoader: " + errStr);
            if (outError) *outError = errStr;
            if (outStatus) *outStatus = RUN_SCRIPT_FILE_ERROR;
            lua_settop(L, top);
            updateScriptStatus(absolutePath, false, errStr);
            return false;
        }
    }

    int loadResult = luaL_loadbuffer(L, buf.data(), buf.size(), chunkName.c_str());
    if (loadResult != LUA_OK) {
        const char* err = lua_tostring(L, -1);
        std::string errStr = err ? err : "load error";
        logToFileError("ScriptLoader: load failed: " + chunkName + " : " + errStr);
        if (outError) *outError = errStr;
        if (outStatus)
            *outStatus = loadResult == LUA_ERRMEM ? RUN_SCRIPT_MEMORY_ERROR : RUN_SCRIPT_SYNTAX_ERROR;
        lua_settop(L, top);
        updateScriptStatus(absolutePath, false, errStr);
        return false;
    }

    createSandboxEnv(L);
#if LUA_VERSION_NUM >= 502
    if (lua_setupvalue(L, -2, 1) == 0) {
        lua_pop(L, 1);
    }
#else
    lua_setfenv(L, -2);
#endif

    std::string pcallErr;
    int pcallStatus = LUA_OK;
    if (!LuaState::pcallWithTraceback(L, 0, 0, &pcallErr, &pcallStatus)) {
        logToFileError("ScriptLoader: runtime error in " + chunkName + " : " + pcallErr);
        if (outError) *outError = pcallErr;
        if (outStatus)
            *outStatus = pcallStatus == LUA_ERRMEM ? RUN_SCRIPT_MEMORY_ERROR : RUN_SCRIPT_RUNTIME_ERROR;
        lua_settop(L, top);
        updateScriptStatus(absolutePath, false, pcallErr);
        return false;
    }

    lua_settop(L, top);
    updateScriptStatus(absolutePath, true);
    return true;
}

bool ScriptLoader::runScript(lua_State* L, LoadedScript& s)
{
    // Clean up any previously registered event handlers and MyGUI widgets from this script
    EventSystem::get().unregisterHandlersBySource(s.chunkName);
    MyGUIBinding::destroyWidgetsBySource(s.chunkName);

    bool res = runScriptSandboxed(L, s.absolutePath, s.chunkName, &s.lastError);
    s.loaded = res;
    if (res) {
        logToFile("ScriptLoader: loaded " + s.chunkName);
    }
    return res;
}

void ScriptLoader::loadAll(lua_State* L)
{
    if (!L) return;
    if (m_loaded) return;
    m_loaded = true;

    discover();
    for (size_t i = 0; i < m_scripts.size(); ++i) {
        if (isScriptStopped(m_scripts[i].absolutePath)) {
            logToFile("ScriptLoader: skipping auto-start of stopped script: " + m_scripts[i].chunkName);
            continue;
        }
        // Only auto-start scripts inside scripts/init/
        if (m_scripts[i].relativePath.size() >= 13 &&
            _strnicmp(m_scripts[i].relativePath.c_str(), "scripts/init/", 13) == 0) {
            runScript(L, m_scripts[i]);
        }
    }
}

void ScriptLoader::reloadAll(lua_State* L)
{
    if (!L) return;
    m_resolvedScriptPaths.clear();
    discover();
    for (size_t i = 0; i < m_scripts.size(); ++i) {
        m_scripts[i].loaded = false;
        m_scripts[i].lastError.clear();
        if (isScriptStopped(m_scripts[i].absolutePath)) {
            continue;
        }
        // Only auto-start scripts inside scripts/init/
        if (m_scripts[i].relativePath.size() >= 13 &&
            _strnicmp(m_scripts[i].relativePath.c_str(), "scripts/init/", 13) == 0) {
            runScript(L, m_scripts[i]);
        }
    }
    m_loaded = true;
}

// Discovered paths keep the mod path's spelling (often relative, such as
// "mods/Name\scripts\init\x.lua"), while resolveScriptPath returns an absolute
// path with forward slashes, so equal strings cannot be assumed for one file.
static bool isSameScriptFile(const std::string& discoveredPath, const std::string& requestedPath)
{
    if (discoveredPath == requestedPath) return true;
    boost::system::error_code ec;
    return fs::equivalent(fs::path(discoveredPath), fs::path(requestedPath), ec) && !ec;
}

bool ScriptLoader::reloadSingleScript(lua_State* L, const std::string& absolutePath)
{
    if (!L) return false;

    for (size_t i = 0; i < m_scripts.size(); ++i) {
        if (isSameScriptFile(m_scripts[i].absolutePath, absolutePath)) {
            // Stopped scripts are recorded under their discovered path.
            if (isScriptStopped(m_scripts[i].absolutePath)) {
                logToFile("ScriptLoader: skipping hot reload of stopped script: " + m_scripts[i].chunkName);
                return false;
            }
            logToFile("ScriptLoader: Hot-reloading script: " + m_scripts[i].chunkName);
            return runScript(L, m_scripts[i]);
        }
    }

    // New script file discovered
    discover();
    for (size_t i = 0; i < m_scripts.size(); ++i) {
        if (isSameScriptFile(m_scripts[i].absolutePath, absolutePath)) {
            logToFile("ScriptLoader: Hot-reloading newly discovered script: " + m_scripts[i].chunkName);
            return runScript(L, m_scripts[i]);
        }
    }

    logToFileDebug("ScriptLoader: no discovered script matches " + absolutePath);
    return false;
}

void ScriptLoader::reset()
{
    m_scripts.clear();
    m_activeModNames.clear();
    m_resolvedScriptPaths.clear();
    m_lastDiscoveredSummary.clear();
    m_loaded = false;
}

std::string ScriptLoader::resolveScriptPath(const std::string& filename)
{
    if (!::ou) return "";

    const auto& mods = ::ou->activeMods;
    auto cached = m_resolvedScriptPaths.find(filename);
    if (cached != m_resolvedScriptPaths.end())
    {
        for (int i = 0; i < static_cast<int>(mods.size()); ++i)
        {
            ModInfo* mod = mods[i];
            if (!mod || mod->path.empty()) continue;
            std::string revalidated;
            if (canonicalFileInside(fs::path(mod->path), fs::path(cached->second),
                    revalidated))
            {
                cached->second = revalidated;
                return revalidated;
            }
        }
        m_resolvedScriptPaths.erase(cached);
    }

    std::string normalized = filename;
    normalizePathSlashes(normalized);

    while (normalized.size() >= 2 && normalized[0] == '.' && normalized[1] == '/')
        normalized.erase(0, 2);
    if (normalized.empty()) return "";

    // Absolute paths are allowed only when their canonical target remains
    // inside one of the active mod roots.
    fs::path requestedPath(filename);
    if (requestedPath.is_absolute())
    {
        for (int i = 0; i < static_cast<int>(mods.size()); ++i)
        {
            ModInfo* mod = mods[i];
            if (!mod || mod->path.empty()) continue;
            std::string resolved;
            if (canonicalFileInside(fs::path(mod->path), requestedPath, resolved))
            {
                m_resolvedScriptPaths[filename] = resolved;
                return resolved;
            }
        }
        return "";
    }

    std::string withoutModsPrefix = normalized;
    bool hasModsPrefix = lowerPath(withoutModsPrefix).compare(0, 5, "mods/") == 0;
    if (hasModsPrefix)
        withoutModsPrefix.erase(0, 5);

    int qualifiedModIndex = -1;
    std::string qualifiedRelative;
    for (int i = 0; i < static_cast<int>(mods.size()); ++i)
    {
        ModInfo* mod = mods[i];
        if (!mod || mod->path.empty()) continue;

        std::string modName = mod->name;
        normalizePathSlashes(modName);
        std::string directoryName = fs::path(mod->path).filename().string();
        normalizePathSlashes(directoryName);

        std::string loweredRequest = lowerPath(withoutModsPrefix);
        std::string prefixes[2] = { lowerPath(modName) + "/", lowerPath(directoryName) + "/" };
        std::string originals[2] = { modName, directoryName };
        for (int prefixIndex = 0; prefixIndex < 2; ++prefixIndex)
        {
            if (loweredRequest.compare(0, prefixes[prefixIndex].size(),
                    prefixes[prefixIndex]) != 0)
                continue;

            std::string remainder = withoutModsPrefix.substr(originals[prefixIndex].size() + 1);
            if (!hasModsPrefix && lowerPath(remainder).compare(0, 8, "scripts/") != 0)
                continue;

            qualifiedModIndex = i;
            qualifiedRelative = remainder;
            break;
        }
        if (qualifiedModIndex >= 0)
            break;
    }

    if (hasModsPrefix && qualifiedModIndex < 0)
        return "";

    for (int i = 0; i < static_cast<int>(mods.size()); ++i)
    {
        if (qualifiedModIndex >= 0 && i != qualifiedModIndex)
            continue;

        ModInfo* mi = mods[i];
        if (!mi || mi->path.empty()) continue;

        fs::path modRoot(mi->path);
        std::string relative = qualifiedModIndex >= 0 ? qualifiedRelative : withoutModsPrefix;

        std::string resolved;
        if (canonicalFileInside(modRoot, modRoot / fs::path(relative), resolved))
        {
            m_resolvedScriptPaths[filename] = resolved;
            return resolved;
        }

        if (lowerPath(relative).compare(0, 8, "scripts/") != 0 &&
            canonicalFileInside(modRoot, modRoot / "scripts" / fs::path(relative), resolved))
        {
            m_resolvedScriptPaths[filename] = resolved;
            return resolved;
        }

        if (qualifiedModIndex >= 0)
            return "";
    }

    return "";
}

} // namespace KenshiLua
