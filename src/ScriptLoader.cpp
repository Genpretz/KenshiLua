#include "pch.h"
#include "ScriptLoader.h"
#include "Logger.h"

#include <kenshi/Globals.h>
#include <kenshi/GameWorld.h>
#include <kenshi/ModInfo.h>
#include <kenshi/util/lektor.h>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/system/error_code.hpp>

#include <algorithm>
#include <cstring>

#include <lua.hpp>
#include "Lua/LuaState.h"

namespace KenshiLua
{

namespace fs = boost::filesystem;

static bool endsWithCaseInsensitive(const std::string& s, const std::string& suffix)
{
    if (s.size() < suffix.size()) return false;
    for (size_t i = 0; i < suffix.size(); ++i) {
        char a = s[s.size() - suffix.size() + i];
        char b = suffix[i];
        if (a >= 'A' && a <= 'Z') a = (char)(a + ('a' - 'A'));
        if (b >= 'A' && b <= 'Z') b = (char)(b + ('a' - 'A'));
        if (a != b) return false;
    }
    return true;
}

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
    lua_pushglobaltable(L);
    lua_setfield(L, -2, "__index");
    lua_setmetatable(L, -2);
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "_ENV");
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

    if (!::ou) {
        logToFile("ScriptLoader: GameWorld (ou) not yet available - skipping mod discovery");
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
            for (size_t j = 0; j < s.relativePath.size(); ++j) {
                if (s.relativePath[j] == '\\') s.relativePath[j] = '/';
            }
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

    logToFile("ScriptLoader: discovered " + std::to_string((long long)m_scripts.size())
              + " script(s) across "
              + std::to_string((long long)m_activeModNames.size()) + " active mod(s)");
}

bool ScriptLoader::runScriptSandboxed(lua_State* L, const std::string& absolutePath, const std::string& chunkName, std::string* outError)
{
    int top = lua_gettop(L);

    fs::path path(absolutePath);
    fs::ifstream f(path, std::ios::binary | std::ios::ate);
    if (!f) {
        std::string errStr = "could not open " + absolutePath;
        logToFile("ScriptLoader: " + errStr);
        if (outError) *outError = errStr;
        for (size_t i = 0; i < m_scripts.size(); ++i) {
            if (m_scripts[i].absolutePath == absolutePath) {
                m_scripts[i].loaded = false;
                m_scripts[i].lastError = errStr;
                break;
            }
        }
        return false;
    }
    std::streamsize sz = f.tellg();
    f.seekg(0, std::ios::beg);
    std::string buf;
    if (sz > 0) {
        buf.resize(static_cast<size_t>(sz));
        if (!f.read(&buf[0], sz)) {
            std::string errStr = "failed to read " + absolutePath;
            logToFile("ScriptLoader: " + errStr);
            if (outError) *outError = errStr;
            lua_settop(L, top);
            for (size_t i = 0; i < m_scripts.size(); ++i) {
                if (m_scripts[i].absolutePath == absolutePath) {
                    m_scripts[i].loaded = false;
                    m_scripts[i].lastError = errStr;
                    break;
                }
            }
            return false;
        }
    }

    int loadResult = luaL_loadbuffer(L, buf.data(), buf.size(), chunkName.c_str());
    if (loadResult != LUA_OK) {
        const char* err = lua_tostring(L, -1);
        std::string errStr = err ? err : "load error";
        logToFile("ScriptLoader: load failed: " + chunkName + " : " + errStr);
        if (outError) *outError = errStr;
        lua_settop(L, top);
        for (size_t i = 0; i < m_scripts.size(); ++i) {
            if (m_scripts[i].absolutePath == absolutePath) {
                m_scripts[i].loaded = false;
                m_scripts[i].lastError = errStr;
                break;
            }
        }
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
    if (!LuaState::pcallWithTraceback(L, 0, 0, &pcallErr)) {
        logToFile("ScriptLoader: runtime error in " + chunkName + " : " + pcallErr);
        if (outError) *outError = pcallErr;
        lua_settop(L, top);
        for (size_t i = 0; i < m_scripts.size(); ++i) {
            if (m_scripts[i].absolutePath == absolutePath) {
                m_scripts[i].loaded = false;
                m_scripts[i].lastError = pcallErr;
                break;
            }
        }
        return false;
    }

    lua_settop(L, top);
    for (size_t i = 0; i < m_scripts.size(); ++i) {
        if (m_scripts[i].absolutePath == absolutePath) {
            m_scripts[i].loaded = true;
            m_scripts[i].lastError.clear();
            break;
        }
    }
    return true;
}

bool ScriptLoader::runScript(lua_State* L, LoadedScript& s)
{
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

void ScriptLoader::reset()
{
    m_scripts.clear();
    m_activeModNames.clear();
    m_resolvedScriptPaths.clear();
    m_loaded = false;
}

std::string ScriptLoader::resolveScriptPath(const std::string& filename)
{
    auto it = m_resolvedScriptPaths.find(filename);
    if (it != m_resolvedScriptPaths.end())
    {
        return it->second;
    }

    if (!::ou) return "";

    std::string normFilename = filename;
    for (size_t i = 0; i < normFilename.size(); ++i)
    {
        if (normFilename[i] == '\\') normFilename[i] = '/';
    }

    if (normFilename.size() >= 2 && normFilename[0] == '.' && normFilename[1] == '/')
    {
        normFilename = normFilename.substr(2);
    }

    // Direct check relative to game CWD
    fs::path directP(normFilename);
    boost::system::error_code ec;
    if (fs::exists(directP, ec) && fs::is_regular_file(directP, ec))
    {
        std::string absPath = fs::absolute(directP).string();
        m_resolvedScriptPaths[filename] = absPath;
        return absPath;
    }

    std::string suffix = normFilename;
    size_t modsPos = normFilename.find("mods/");
    if (modsPos != std::string::npos)
    {
        size_t nextSlash = normFilename.find('/', modsPos + 5);
        if (nextSlash != std::string::npos)
        {
            suffix = normFilename.substr(nextSlash + 1);
        }
    }

    const auto& mods = ::ou->activeMods;
    for (int i = 0; i < static_cast<int>(mods.size()); ++i)
    {
        ModInfo* mi = mods[i];
        if (!mi || mi->path.empty()) continue;

        fs::path modRoot(mi->path);
        
        // 1. Check direct path under modRoot
        fs::path targetPathDirect = modRoot / suffix;
        if (fs::exists(targetPathDirect, ec) && fs::is_regular_file(targetPathDirect, ec))
        {
            std::string pathStr = fs::absolute(targetPathDirect).string();
            m_resolvedScriptPaths[filename] = pathStr;
            return pathStr;
        }

        // 2. Check direct path under modRoot/scripts
        fs::path scriptsDir = modRoot / "scripts";
        fs::path targetPathScripts = scriptsDir / suffix;
        if (fs::exists(targetPathScripts, ec) && fs::is_regular_file(targetPathScripts, ec))
        {
            std::string pathStr = fs::absolute(targetPathScripts).string();
            m_resolvedScriptPaths[filename] = pathStr;
            return pathStr;
        }

        // 3. Fallback: recursively scan only modRoot/scripts
        if (fs::exists(scriptsDir, ec) && fs::is_directory(scriptsDir, ec))
        {
            fs::recursive_directory_iterator rit(scriptsDir, ec);
            fs::recursive_directory_iterator end;
            for (; !ec && rit != end; rit.increment(ec))
            {
                if (ec) break;
                if (!fs::is_regular_file(rit->status())) continue;

                std::string p = rit->path().string();
                std::string normP = p;
                for (size_t j = 0; j < normP.size(); ++j)
                {
                    if (normP[j] == '\\') normP[j] = '/';
                }

                std::string matchSuffix = "/" + suffix;
                if (normP.size() >= matchSuffix.size() && normP.compare(normP.size() - matchSuffix.size(), matchSuffix.size(), matchSuffix) == 0)
                {
                    std::string absFoundPath = fs::absolute(rit->path()).string();
                    m_resolvedScriptPaths[filename] = absFoundPath;
                    return absFoundPath;
                }
            }
        }
    }

    return "";
}

} // namespace KenshiLua
