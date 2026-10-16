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

static std::unordered_map<std::string, std::string> s_activeModRootCache;

static bool canonicalDirectory(const fs::path& candidate, std::string& resolved)
{
    boost::system::error_code ec;
    if (!fs::exists(candidate, ec) || ec || !fs::is_directory(candidate, ec) || ec)
        return false;

    fs::path canonicalCandidate = fs::canonical(candidate, ec);
    if (ec) return false;

    resolved = canonicalCandidate.string();
    return true;
}

static bool getGameDirectory(fs::path& gameDirectory)
{
    char executablePath[MAX_PATH] = {0};
    DWORD length = GetModuleFileNameA(NULL, executablePath, MAX_PATH);
    if (length == 0 || length >= MAX_PATH)
        return false;

    gameDirectory = fs::path(std::string(executablePath, length)).parent_path();
    return !gameDirectory.empty();
}

static bool getSteamWorkshopRoot(const fs::path& gameDirectory,
    fs::path& workshopRoot)
{
    fs::path commonDirectory = gameDirectory.parent_path();
    fs::path steamAppsDirectory = commonDirectory.parent_path();
    if (_stricmp(commonDirectory.filename().string().c_str(), "common") != 0 ||
        _stricmp(steamAppsDirectory.filename().string().c_str(), "steamapps") != 0)
        return false;

    fs::path candidate = steamAppsDirectory / "workshop" / "content" / "233860";
    std::string resolved;
    if (!canonicalDirectory(candidate, resolved))
        return false;

    workshopRoot = fs::path(resolved);
    return true;
}

static void appendDescriptorName(std::vector<std::string>& names,
    const std::string& value)
{
    if (value.empty()) return;

    std::string filename = fs::path(value).filename().string();
    if (filename.empty()) return;

    for (size_t i = 0; i < names.size(); ++i) {
        if (_stricmp(names[i].c_str(), filename.c_str()) == 0)
            return;
    }
    names.push_back(filename);
}

static bool directoryContainsModDescriptor(const fs::path& directory,
    const ModInfo* mod)
{
    if (!mod) return false;

    std::vector<std::string> descriptorNames;
    appendDescriptorName(descriptorNames, mod->name);
    appendDescriptorName(descriptorNames, mod->file);

    boost::system::error_code ec;
    for (size_t i = 0; i < descriptorNames.size(); ++i) {
        fs::path descriptor = directory / descriptorNames[i];
        if (fs::exists(descriptor, ec) && !ec && fs::is_regular_file(descriptor, ec) && !ec)
            return true;
        ec.clear();
    }
    return false;
}

static bool findModDirectory(const fs::path& modsRoot, const ModInfo* mod,
    std::string& resolved)
{
    boost::system::error_code ec;
    if (!fs::exists(modsRoot, ec) || ec || !fs::is_directory(modsRoot, ec) || ec)
        return false;

    std::vector<fs::path> directCandidates;
    if (!mod->path.empty())
        directCandidates.push_back(modsRoot / fs::path(mod->path).filename());
    if (!mod->name.empty())
        directCandidates.push_back(modsRoot / fs::path(mod->name).stem());

    for (size_t i = 0; i < directCandidates.size(); ++i) {
        if (directoryContainsModDescriptor(directCandidates[i], mod) &&
            canonicalDirectory(directCandidates[i], resolved))
            return true;
    }

    fs::directory_iterator it(modsRoot, ec);
    fs::directory_iterator end;
    for (; !ec && it != end; it.increment(ec)) {
        if (ec || !fs::is_directory(it->status())) continue;
        if (directoryContainsModDescriptor(it->path(), mod) &&
            canonicalDirectory(it->path(), resolved))
            return true;
    }
    return false;
}

static bool resolveActiveModRoot(const ModInfo* mod, std::string& resolved)
{
    if (!mod) return false;

    std::string cacheKey = lowerPath(mod->name) + "|" + lowerPath(mod->path)
        + (mod->isWorkshop ? "|workshop" : "|local");
    std::unordered_map<std::string, std::string>::iterator cached =
        s_activeModRootCache.find(cacheKey);
    if (cached != s_activeModRootCache.end()) {
        if (canonicalDirectory(fs::path(cached->second), resolved)) {
            cached->second = resolved;
            return true;
        }
        s_activeModRootCache.erase(cached);
    }

    fs::path gameDirectory;
    bool hasGameDirectory = getGameDirectory(gameDirectory);
    fs::path workshopRoot;
    bool hasWorkshopRoot = hasGameDirectory &&
        getSteamWorkshopRoot(gameDirectory, workshopRoot);

    fs::path declaredPath(mod->path);
    if (declaredPath.is_absolute() && canonicalDirectory(declaredPath, resolved)) {
        s_activeModRootCache[cacheKey] = resolved;
        return true;
    }

    std::string loweredDeclaredPath = lowerPath(mod->path);
    bool declaredWorkshopPath = loweredDeclaredPath.find("workshop/content/233860/")
        != std::string::npos;
    bool trustRelativeDeclaredPath = !mod->isWorkshop || declaredWorkshopPath;

    if (trustRelativeDeclaredPath && hasGameDirectory && !declaredPath.empty()) {
        fs::path gameRelativePath = gameDirectory / declaredPath;
        if (canonicalDirectory(gameRelativePath, resolved)) {
            s_activeModRootCache[cacheKey] = resolved;
            return true;
        }
    }

    fs::path currentRelativePath = declaredPath;
    if (trustRelativeDeclaredPath && !declaredPath.empty() &&
        canonicalDirectory(currentRelativePath, resolved)) {
        s_activeModRootCache[cacheKey] = resolved;
        return true;
    }

    fs::path localModsRoot;
    if (hasGameDirectory)
        localModsRoot = gameDirectory / "mods";

    bool found = false;
    if (mod->isWorkshop) {
        found = hasWorkshopRoot && findModDirectory(workshopRoot, mod, resolved);
        if (!found && hasGameDirectory)
            found = findModDirectory(localModsRoot, mod, resolved);
    } else {
        found = hasGameDirectory && findModDirectory(localModsRoot, mod, resolved);
        if (!found && hasWorkshopRoot)
            found = findModDirectory(workshopRoot, mod, resolved);
    }

    if (!found)
        return false;

    s_activeModRootCache[cacheKey] = resolved;
    return true;
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

struct SandboxPathContext
{
    std::string scriptsDirectory;
};

static bool getSandboxPathContext(const std::string& absolutePath,
    SandboxPathContext& context)
{
    if (!::ou) return false;

    const lektor<ModInfo*>& mods = ::ou->activeMods;
    for (int i = 0; i < static_cast<int>(mods.size()); ++i) {
        ModInfo* mod = mods[i];
        if (!mod) continue;

        std::string modRoot;
        if (!resolveActiveModRoot(mod, modRoot)) continue;

        std::string resolvedScript;
        if (!canonicalFileInside(fs::path(modRoot), fs::path(absolutePath),
                resolvedScript))
            continue;

        context.scriptsDirectory = (fs::path(modRoot) / "scripts").string();
        return true;
    }

    return false;
}

static bool activeModNameMatches(const ModInfo* mod, const std::string& requestedName)
{
    if (!mod) return false;
    if (_stricmp(mod->name.c_str(), requestedName.c_str()) == 0)
        return true;

    std::string descriptorName = fs::path(mod->file).filename().string();
    if (!descriptorName.empty() &&
        _stricmp(descriptorName.c_str(), requestedName.c_str()) == 0)
        return true;

    if (!endsWithCaseInsensitive(mod->name, ".mod")) {
        std::string nameWithExtension = mod->name + ".mod";
        if (_stricmp(nameWithExtension.c_str(), requestedName.c_str()) == 0)
            return true;
    }
    return false;
}

static bool getActiveModScriptsDirectory(const std::string& modName,
    std::string& scriptsDirectory, std::string& error)
{
    if (!::ou) {
        error = "game world is not available";
        return false;
    }

    const lektor<ModInfo*>& mods = ::ou->activeMods;
    for (int i = 0; i < static_cast<int>(mods.size()); ++i) {
        ModInfo* mod = mods[i];
        if (!activeModNameMatches(mod, modName))
            continue;

        std::string modRoot;
        if (!resolveActiveModRoot(mod, modRoot)) {
            error = "could not locate active mod '" + modName
                + "' in the game mods directory or Steam Workshop";
            return false;
        }

        boost::system::error_code ec;
        fs::path scriptsRoot = fs::path(modRoot) / "scripts";
        if (!fs::exists(scriptsRoot, ec) || ec || !fs::is_directory(scriptsRoot, ec) || ec) {
            error = "active mod '" + modName + "' has no scripts directory";
            return false;
        }

        fs::path canonicalScripts = fs::canonical(scriptsRoot, ec);
        if (ec) {
            error = "could not resolve the scripts directory for active mod '" + modName + "'";
            return false;
        }

        scriptsDirectory = canonicalScripts.string();
        return true;
    }

    error = "required mod '" + modName + "' is not active";
    return false;
}

static bool resolveSandboxFile(const SandboxPathContext& context,
    const std::string& filename, std::string& resolved)
{
    fs::path requested(filename);
    if (requested.is_absolute()) {
        resolved = filename;
        return true;
    }

    const fs::path scriptsRoot(context.scriptsDirectory);
    return canonicalFileInside(scriptsRoot, scriptsRoot / requested, resolved);
}

static bool resolveSandboxModule(const SandboxPathContext& context,
    const std::string& moduleName, std::string& resolved)
{
    std::string modulePath = moduleName;
    std::replace(modulePath.begin(), modulePath.end(), '.', '/');

    const std::string filenames[] = {
        modulePath + ".lua",
        modulePath + "/init.lua"
    };
    for (size_t i = 0; i < sizeof(filenames) / sizeof(filenames[0]); ++i) {
        if (resolveSandboxFile(context, filenames[i], resolved))
            return true;
    }

    return false;
}

static SandboxPathContext getSandboxPathContextFromUpvalue(lua_State* L, int index)
{
    SandboxPathContext context;
    const char* scriptsDirectory = lua_tostring(L, lua_upvalueindex(index));
    if (scriptsDirectory) context.scriptsDirectory = scriptsDirectory;
    return context;
}

static std::string makeSandboxFileNotFoundError(const SandboxPathContext& context,
    const std::string& filename)
{
    return "cannot open mod script '" + filename + "': no file under "
        + context.scriptsDirectory;
}

static int sandboxLoadFile(lua_State* L)
{
    const char* filename = luaL_checkstring(L, 1);
    std::string requestedName(filename);
    SandboxPathContext context = getSandboxPathContextFromUpvalue(L, 1);
    std::string resolved;
    if (!resolveSandboxFile(context, requestedName, resolved)) {
        std::string error = makeSandboxFileNotFoundError(context, requestedName);
        lua_settop(L, 0);
        lua_pushnil(L);
        lua_pushlstring(L, error.c_str(), error.size());
        return 2;
    }

    lua_settop(L, 0);
    int status = luaL_loadfile(L, resolved.c_str());
    if (status != LUA_OK) {
        lua_pushnil(L);
        lua_insert(L, -2);
        return 2;
    }

    lua_pushvalue(L, lua_upvalueindex(2));
    lua_setfenv(L, -2);
    return 1;
}

static int sandboxDoFile(lua_State* L)
{
    const char* filename = luaL_checkstring(L, 1);
    std::string requestedName(filename);
    SandboxPathContext context = getSandboxPathContextFromUpvalue(L, 1);
    std::string resolved;
    if (!resolveSandboxFile(context, requestedName, resolved)) {
        std::string error = makeSandboxFileNotFoundError(context, requestedName);
        lua_settop(L, 0);
        lua_pushlstring(L, error.c_str(), error.size());
        return lua_error(L);
    }

    lua_settop(L, 0);
    int status = luaL_loadfile(L, resolved.c_str());
    if (status != LUA_OK)
        return lua_error(L);

    lua_pushvalue(L, lua_upvalueindex(2));
    lua_setfenv(L, -2);
    lua_call(L, 0, LUA_MULTRET);
    return lua_gettop(L);
}

static char s_loadingModuleMarker;

static int sandboxRequire(lua_State* L)
{
    const char* moduleName = luaL_checkstring(L, 1);

    // Mod-local modules use a cache owned by this script sandbox. This avoids
    // package.loaded collisions when two mods use the same internal name.
    lua_pushvalue(L, lua_upvalueindex(4));
    lua_getfield(L, -1, moduleName);
    if (lua_touserdata(L, -1) == &s_loadingModuleMarker)
        return luaL_error(L, "loop or previous error loading module '%s'", moduleName);
    if (lua_toboolean(L, -1))
        return 1;
    lua_pop(L, 2);

    SandboxPathContext context = getSandboxPathContextFromUpvalue(L, 2);
    std::string resolved;
    if (!resolveSandboxModule(context, moduleName, resolved)) {
        lua_pushvalue(L, lua_upvalueindex(1));
        lua_pushvalue(L, 1);
        lua_call(L, 1, 1);
        return 1;
    }

    lua_pushvalue(L, lua_upvalueindex(4));
    lua_pushlightuserdata(L, &s_loadingModuleMarker);
    lua_setfield(L, -2, moduleName);
    lua_pop(L, 1);

    int loadStatus = luaL_loadfile(L, resolved.c_str());
    if (loadStatus != LUA_OK) {
        const char* detail = lua_tostring(L, -1);
        std::string error = "error loading module '" + std::string(moduleName)
            + "' from file '" + resolved + "':\n\t" + (detail ? detail : "load error");
        lua_pop(L, 1);
        lua_pushvalue(L, lua_upvalueindex(4));
        lua_pushnil(L);
        lua_setfield(L, -2, moduleName);
        lua_pop(L, 1);
        return luaL_error(L, "%s", error.c_str());
    }

    lua_pushvalue(L, lua_upvalueindex(3));
    lua_setfenv(L, -2);
    lua_pushstring(L, moduleName);
    if (lua_pcall(L, 1, 1, 0) != LUA_OK) {
        lua_pushvalue(L, lua_upvalueindex(4));
        lua_pushnil(L);
        lua_setfield(L, -2, moduleName);
        lua_pop(L, 1);
        return lua_error(L);
    }

    if (lua_isnil(L, -1)) {
        lua_pop(L, 1);
        lua_pushboolean(L, 1);
    }

    lua_pushvalue(L, lua_upvalueindex(4));
    lua_pushvalue(L, -2);
    lua_setfield(L, -2, moduleName);
    lua_pop(L, 1);
    return 1;
}

static int createBaseSandboxEnv(lua_State* L)
{
    lua_newtable(L);
    int envIndex = lua_gettop(L);

    lua_newtable(L);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_setfield(L, -2, "__index");
    lua_setmetatable(L, envIndex);
    lua_pushvalue(L, envIndex);
    lua_setfield(L, envIndex, "_ENV");

    return envIndex;
}

static void installSandboxLoaders(lua_State* L, int envIndex,
    const std::string& scriptsDirectory)
{
    lua_pushlstring(L, scriptsDirectory.c_str(), scriptsDirectory.size());
    lua_pushvalue(L, envIndex);
    lua_pushcclosure(L, sandboxLoadFile, 2);
    lua_setfield(L, envIndex, "loadfile");

    lua_pushlstring(L, scriptsDirectory.c_str(), scriptsDirectory.size());
    lua_pushvalue(L, envIndex);
    lua_pushcclosure(L, sandboxDoFile, 2);
    lua_setfield(L, envIndex, "dofile");

    lua_getglobal(L, "require");
    lua_pushlstring(L, scriptsDirectory.c_str(), scriptsDirectory.size());
    lua_pushvalue(L, envIndex);
    lua_newtable(L);
    lua_pushcclosure(L, sandboxRequire, 4);
    lua_setfield(L, envIndex, "require");
}

static void createSandboxEnvForScriptsDirectory(lua_State* L,
    const std::string& scriptsDirectory)
{
    int envIndex = createBaseSandboxEnv(L);
    installSandboxLoaders(L, envIndex, scriptsDirectory);
}

static void createSandboxEnv(lua_State* L, const std::string& absolutePath)
{
    int envIndex = createBaseSandboxEnv(L);

    SandboxPathContext context;
    if (!getSandboxPathContext(absolutePath, context))
        return;

    installSandboxLoaders(L, envIndex, context.scriptsDirectory);
}

static char s_providerEnvironmentsRegistryKey;

static void pushProviderEnvironmentMap(lua_State* L)
{
    lua_pushlightuserdata(L, &s_providerEnvironmentsRegistryKey);
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L, -1))
        return;

    lua_pop(L, 1);
    lua_newtable(L);
    lua_pushlightuserdata(L, &s_providerEnvironmentsRegistryKey);
    lua_pushvalue(L, -2);
    lua_rawset(L, LUA_REGISTRYINDEX);
}

static void pushProviderEnvironment(lua_State* L, const std::string& scriptsDirectory)
{
    pushProviderEnvironmentMap(L);
    int mapIndex = lua_gettop(L);

    std::string key = lowerPath(scriptsDirectory);
    lua_getfield(L, mapIndex, key.c_str());
    if (lua_istable(L, -1)) {
        lua_remove(L, mapIndex);
        return;
    }

    lua_pop(L, 1);
    createSandboxEnvForScriptsDirectory(L, scriptsDirectory);
    lua_pushvalue(L, -1);
    lua_setfield(L, mapIndex, key.c_str());
    lua_remove(L, mapIndex);
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

void ScriptLoader::clearProviderEnvironments(lua_State* L)
{
    if (!L) return;
    lua_pushlightuserdata(L, &s_providerEnvironmentsRegistryKey);
    lua_pushnil(L);
    lua_rawset(L, LUA_REGISTRYINDEX);
}

int ScriptLoader::requireFromMod(lua_State* L, const std::string& modName,
    const std::string& moduleName)
{
    std::string scriptsDirectory;
    std::string error;
    if (!getActiveModScriptsDirectory(modName, scriptsDirectory, error))
        return luaL_error(L, "KenshiLua.requireFromMod: %s", error.c_str());

    SandboxPathContext context;
    context.scriptsDirectory = scriptsDirectory;
    std::string resolved;
    if (!resolveSandboxModule(context, moduleName, resolved)) {
        return luaL_error(L,
            "KenshiLua.requireFromMod: module '%s' was not found under active mod '%s' scripts directory",
            moduleName.c_str(), modName.c_str());
    }

    int base = lua_gettop(L);
    pushProviderEnvironment(L, scriptsDirectory);
    int envIndex = lua_gettop(L);
    lua_getfield(L, envIndex, "require");
    lua_pushlstring(L, moduleName.c_str(), moduleName.size());
    lua_call(L, 1, 1);
    lua_remove(L, envIndex);
    return lua_gettop(L) - base;
}

int ScriptLoader::dofileFromMod(lua_State* L, const std::string& modName,
    const std::string& filename)
{
    std::string scriptsDirectory;
    std::string error;
    if (!getActiveModScriptsDirectory(modName, scriptsDirectory, error))
        return luaL_error(L, "KenshiLua.dofileFromMod: %s", error.c_str());
    if (fs::path(filename).is_absolute())
        return luaL_error(L, "KenshiLua.dofileFromMod: filename must be relative to the target mod's scripts directory");

    SandboxPathContext context;
    context.scriptsDirectory = scriptsDirectory;
    std::string resolved;
    if (!resolveSandboxFile(context, filename, resolved)) {
        return luaL_error(L,
            "KenshiLua.dofileFromMod: file '%s' was not found under active mod '%s' scripts directory",
            filename.c_str(), modName.c_str());
    }

    int base = lua_gettop(L);
    pushProviderEnvironment(L, scriptsDirectory);
    int envIndex = lua_gettop(L);
    lua_getfield(L, envIndex, "dofile");
    lua_pushlstring(L, filename.c_str(), filename.size());
    lua_call(L, 1, LUA_MULTRET);
    int results = lua_gettop(L) - base - 1;
    lua_remove(L, envIndex);
    return results;
}

int ScriptLoader::loadfileFromMod(lua_State* L, const std::string& modName,
    const std::string& filename)
{
    std::string scriptsDirectory;
    std::string error;
    if (!getActiveModScriptsDirectory(modName, scriptsDirectory, error)) {
        lua_pushnil(L);
        std::string message = "KenshiLua.loadfileFromMod: " + error;
        lua_pushlstring(L, message.c_str(), message.size());
        return 2;
    }
    if (fs::path(filename).is_absolute()) {
        lua_pushnil(L);
        lua_pushliteral(L, "KenshiLua.loadfileFromMod: filename must be relative to the target mod's scripts directory");
        return 2;
    }

    SandboxPathContext context;
    context.scriptsDirectory = scriptsDirectory;
    std::string resolved;
    if (!resolveSandboxFile(context, filename, resolved)) {
        lua_pushnil(L);
        std::string message = "KenshiLua.loadfileFromMod: file '" + filename
            + "' was not found under active mod '" + modName + "' scripts directory";
        lua_pushlstring(L, message.c_str(), message.size());
        return 2;
    }

    int base = lua_gettop(L);
    pushProviderEnvironment(L, scriptsDirectory);
    int envIndex = lua_gettop(L);
    lua_getfield(L, envIndex, "loadfile");
    lua_pushlstring(L, filename.c_str(), filename.size());
    lua_call(L, 1, LUA_MULTRET);
    int results = lua_gettop(L) - base - 1;
    lua_remove(L, envIndex);
    return results;
}

void ScriptLoader::discover()
{
    s_activeModRootCache.clear();

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

        std::string resolvedModRoot;
        if (!resolveActiveModRoot(mi, resolvedModRoot)) {
            logToFileDebug("ScriptLoader: could not locate active mod root for " + mi->name);
            continue;
        }

        fs::path modRoot(resolvedModRoot);
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
            s.modPath = resolvedModRoot;
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

    createSandboxEnv(L, absolutePath);
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
    clearProviderEnvironments(L);
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
    clearProviderEnvironments(L);

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
    s_activeModRootCache.clear();
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
    std::vector<std::string> modRoots(mods.size());
    for (int i = 0; i < static_cast<int>(mods.size()); ++i) {
        ModInfo* mod = mods[i];
        if (mod)
            resolveActiveModRoot(mod, modRoots[i]);
    }

    auto cached = m_resolvedScriptPaths.find(filename);
    if (cached != m_resolvedScriptPaths.end())
    {
        for (int i = 0; i < static_cast<int>(mods.size()); ++i)
        {
            if (modRoots[i].empty()) continue;
            std::string revalidated;
            if (canonicalFileInside(fs::path(modRoots[i]), fs::path(cached->second),
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
            if (modRoots[i].empty()) continue;
            std::string resolved;
            if (canonicalFileInside(fs::path(modRoots[i]), requestedPath, resolved))
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
        if (!mod || modRoots[i].empty()) continue;

        std::string modName = mod->name;
        normalizePathSlashes(modName);
        std::string directoryName = fs::path(modRoots[i]).filename().string();
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
        if (!mi || modRoots[i].empty()) continue;

        fs::path modRoot(modRoots[i]);
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
