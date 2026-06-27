#include "pch.h"
#include "ModLoader.h"
#include "Lua/Logger.h"

#include <kenshi/Globals.h>
#include <kenshi/GameWorld.h>
#include <kenshi/ModInfo.h>
#include <kenshi/util/lektor.h>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/system/error_code.hpp>

#include <algorithm>
#include <cstring>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

namespace fs = boost::filesystem;

// -----------------------------------------------------------------------------
// Small helpers
// -----------------------------------------------------------------------------

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

// Build the chunk name we feed to luaL_loadbuffer.  Prefixing with '@' makes
// Lua treat the rest as a filename in stack traces.
static std::string makeChunkName(const std::string& modName, const std::string& relPath)
{
    std::string out = "@";
    out += modName;
    out += "/";
    out += relPath;
    // Lua truncates chunknames to LUA_IDSIZE (usually 60) in traceback output,
    // which is fine. It'll keep the right-most useful part.
    return out;
}

// -----------------------------------------------------------------------------
// Per-script sandbox setup
//
// We use a *shared* lua_State (the global one) but give every script its own
// _ENV table so its locals/file-locals can't collide with another mod's.  The
// sandbox table's __index falls back to the real global table so scripts can
// still read `ou`, `player`, `key`, `log`, etc.  Writes go into the
// sandbox table by default - to deliberately expose a global to other scripts,
// a mod can write to `_G.foo = ...`.
// -----------------------------------------------------------------------------

static void createSandboxEnv(lua_State* L)
{
    // Stack after this function: [sandboxTable]
    lua_newtable(L);              // sandbox

    // Provide _G as a fallback for read-through.
    lua_newtable(L);              // sandbox, meta
    lua_pushglobaltable(L);       // sandbox, meta, _G
    lua_setfield(L, -2, "__index");
    lua_setmetatable(L, -2);

    // Self-reference so scripts can `_ENV._something = ...` explicitly.
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "_ENV");
}

// -----------------------------------------------------------------------------
// ModLoader
// -----------------------------------------------------------------------------

ModLoader::ModLoader() : m_loaded(false) {}
ModLoader::~ModLoader() {}

ModLoader& ModLoader::get()
{
    static ModLoader instance;
    return instance;
}

void ModLoader::discover()
{
    m_scripts.clear();
    m_activeModNames.clear();

    if (!::ou) {
        logToFile("ModLoader: GameWorld (ou) not yet available - skipping mod discovery");
        return;
    }

    lektor<ModInfo*>& mods = ::ou->activeMods;
    int n = (int)mods.size();
    if (n == 0) {
        logToFile("ModLoader: no active mods");
        return;
    }

    for (int i = 0; i < n; ++i) {
        ModInfo* mi = mods[i];
        if (!mi) continue;
        m_activeModNames.push_back(mi->name);

        if (mi->path.empty()) continue;

        fs::path modRoot(mi->path);
        fs::path initDir = modRoot / "scripts" / "init";
        boost::system::error_code ec;
        if (!fs::exists(initDir, ec) || !fs::is_directory(initDir, ec)) continue;

        // Recursive walk under modRoot/scripts/init for startup scripts
        std::vector<std::string> found;
        fs::recursive_directory_iterator it(initDir, ec);
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

            // Build relative path manually (boost::filesystem::relative is
            // 1.60-conditional; do it ourselves to be safe).
            if (s.absolutePath.size() > s.modPath.size() + 1
                && s.absolutePath.compare(0, s.modPath.size(), s.modPath) == 0) {
                s.relativePath = s.absolutePath.substr(s.modPath.size() + 1);
            } else {
                s.relativePath = s.absolutePath;
            }
            // Normalize slashes for nicer chunk names.
            for (size_t j = 0; j < s.relativePath.size(); ++j) {
                if (s.relativePath[j] == '\\') s.relativePath[j] = '/';
            }
            s.chunkName = makeChunkName(s.modName, s.relativePath);
            s.loaded = false;
            m_scripts.push_back(s);
        }
    }

    logToFile("ModLoader: discovered " + std::to_string((long long)m_scripts.size())
              + " script(s) across "
              + std::to_string((long long)m_activeModNames.size()) + " active mod(s)");
}

bool ModLoader::runScript(lua_State* L, LoadedScript& s)
{
    int top = lua_gettop(L);

    // Read the file ourselves (avoids luaL_loadfile's BOM-only handling
    // quirks across encodings).  Use boost::filesystem::ifstream.
    fs::path path(s.absolutePath);
    fs::ifstream f(path, std::ios::binary | std::ios::ate);
    if (!f) {
        s.lastError = "could not open " + s.absolutePath;
        logToFile("ModLoader: " + s.lastError);
        lua_settop(L, top);
        return false;
    }
    std::streamsize sz = f.tellg();
    f.seekg(0, std::ios::beg);
    std::string buf;
    if (sz > 0) {
        buf.resize(static_cast<size_t>(sz));
        if (!f.read(&buf[0], sz)) {
            s.lastError = "failed to read " + s.absolutePath;
            logToFile("ModLoader: " + s.lastError);
            lua_settop(L, top);
            return false;
        }
    }

    int loadResult = luaL_loadbuffer(L, buf.data(), buf.size(), s.chunkName.c_str());
    if (loadResult != LUA_OK) {
        const char* err = lua_tostring(L, -1);
        s.lastError = err ? err : "load error";
        logToFile("ModLoader: load failed: " + s.chunkName + " : " + s.lastError);
        lua_settop(L, top);
        return false;
    }

    // Install a per-script sandbox environment.
#if LUA_VERSION_NUM >= 502
    createSandboxEnv(L);                            // top: chunk, env
    if (lua_setupvalue(L, -2, 1) == 0) {            // top: chunk  (no upvalue#1?!)
        // No upvalues to set - chunk just uses real globals.  Drop the env.
        lua_pop(L, 1);
    }
#else
    createSandboxEnv(L);                            // top: chunk, env
    lua_setfenv(L, -2);                             // top: chunk
#endif

    if (lua_pcall(L, 0, 0, 0) != LUA_OK) {
        const char* err = lua_tostring(L, -1);
        s.lastError = err ? err : "runtime error";
        logToFile("ModLoader: runtime error in " + s.chunkName + " : " + s.lastError);
        lua_settop(L, top);
        return false;
    }

    s.loaded = true;
    s.lastError.clear();
    logToFile("ModLoader: loaded " + s.chunkName);
    lua_settop(L, top);
    return true;
}

void ModLoader::loadAll(lua_State* L)
{
    if (!L) return;
    if (m_loaded) return;
    m_loaded = true;

    discover();
    for (size_t i = 0; i < m_scripts.size(); ++i) {
        runScript(L, m_scripts[i]);
    }
}

void ModLoader::reloadAll(lua_State* L)
{
    if (!L) return;
    m_resolvedScriptPaths.clear();
    discover();
    for (size_t i = 0; i < m_scripts.size(); ++i) {
        m_scripts[i].loaded = false;
        m_scripts[i].lastError.clear();
        runScript(L, m_scripts[i]);
    }
    m_loaded = true;
}

std::string ModLoader::resolveScriptPath(const std::string& filename)
{
    auto it = m_resolvedScriptPaths.find(filename);
    if (it != m_resolvedScriptPaths.end())
    {
        return it->second;
    }

    if (!::ou) return "";

    // Normalize filename slashes to forward slashes for matching
    std::string normFilename = filename;
    for (size_t i = 0; i < normFilename.size(); ++i)
    {
        if (normFilename[i] == '\\') normFilename[i] = '/';
    }

    const auto& mods = ::ou->activeMods;
    for (int i = 0; i < static_cast<int>(mods.size()); ++i)
    {
        ModInfo* mi = mods[i];
        if (!mi || mi->path.empty()) continue;

        fs::path modRoot(mi->path);
        boost::system::error_code ec;
        if (!fs::exists(modRoot, ec) || !fs::is_directory(modRoot, ec)) continue;

        // Direct check (in case the filename is relative to the mod root, e.g. "scripts/go_prone.lua")
        fs::path directPath = modRoot / normFilename;
        if (fs::exists(directPath, ec) && fs::is_regular_file(directPath, ec))
        {
            std::string pathStr = directPath.string();
            m_resolvedScriptPaths[filename] = pathStr;
            return pathStr;
        }

        // Recursive fallback scan inside the mod directory
        fs::recursive_directory_iterator rit(modRoot, ec);
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

            // If the path ends with "/" + normFilename, we found it
            std::string suffix = "/" + normFilename;
            if (normP.size() >= suffix.size() && normP.compare(normP.size() - suffix.size(), suffix.size(), suffix) == 0)
            {
                m_resolvedScriptPaths[filename] = p;
                return p;
            }
        }
    }

    return "";
}

} // namespace KenshiLua
