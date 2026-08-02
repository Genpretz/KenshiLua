#include "pch.h"
#include "Lua/LuaBindings.h"
#include "Lua/LuaState.h"
#include "Lua/BindingHelpers.h"
#include "Benchmark.h"
#include "DialogueScriptBridge.h"
#include "EventSystem.h"
#include "Gui/GuiManager.h"
#include "Logger.h"
#include "ScriptLoader.h"
#include "FileWatcher.h"

#include <string>
#include <cstdio>
#include <map>
#include <sstream>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <luajit.h>
}

namespace KenshiLua
{

static int lua_enableHotReload(lua_State* L)
{
    FileWatcher::get().setEnabled(true);
    return 0;
}

static int lua_disableHotReload(lua_State* L)
{
    FileWatcher::get().setEnabled(false);
    return 0;
}

static int lua_isHotReloadEnabled(lua_State* L)
{
    lua_pushboolean(L, FileWatcher::get().isEnabled() ? 1 : 0);
    return 1;
}

static int lua_reloadScript(lua_State* L)
{
    if (lua_isstring(L, 1))
    {
        const char* path = lua_tostring(L, 1);
        std::string resolvedPath = ScriptLoader::get().resolveScriptPath(path);
        if (resolvedPath.empty()) resolvedPath = path;
        bool success = ScriptLoader::get().reloadSingleScript(L, resolvedPath);
        lua_pushboolean(L, success ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

static int lua_reloadMods(lua_State* L)
{
    ScriptLoader::get().reloadAll(L);
    lua_pushinteger(L, (lua_Integer)ScriptLoader::get().scripts().size());
    return 1;
}

static int lua_toggleGui(lua_State* L)
{
    GuiManager::get().toggle();
    return 0;
}

void installKenshiLuaTable(lua_State* L)
{
    // KenshiLua.* namespace for management helpers.
    lua_getglobal(L, "KenshiLua");
    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        lua_newtable(L);
    }

    lua_pushcfunction(L, lua_reloadMods);
    lua_setfield(L, -2, "reloadMods");

    lua_pushcfunction(L, lua_reloadScript);
    lua_setfield(L, -2, "reloadScript");

    lua_pushcfunction(L, lua_enableHotReload);
    lua_setfield(L, -2, "enableHotReload");

    lua_pushcfunction(L, lua_disableHotReload);
    lua_setfield(L, -2, "disableHotReload");

    lua_pushcfunction(L, lua_isHotReloadEnabled);
    lua_setfield(L, -2, "isHotReloadEnabled");

    lua_pushcfunction(L, lua_toggleGui);
    lua_setfield(L, -2, "toggleGui");

    // Aliases for the existing global event-handler functions.
    lua_pushcfunction(L, luaRegisterHandler);
    lua_setfield(L, -2, "registerHandler");

    lua_pushcfunction(L, luaUnregisterHandler);
    lua_setfield(L, -2, "unregisterHandler");

    // Version check helper.
    lua_pushcfunction(L, luaKenshiVersion);
    lua_setfield(L, -2, "version");

    lua_pushcfunction(L, luaKenshiRunBenchmark);
    lua_setfield(L, -2, "runBenchmark");

    lua_pushcfunction(L, luaCheckLuaScriptReferences);
    lua_setfield(L, -2, "checkLuaScriptReferences");

    lua_pushcfunction(L, luaKenshiLog);
    lua_setfield(L, -2, "log");

    lua_pushcfunction(L, luaKenshiLogDebug);
    lua_setfield(L, -2, "logDebug");

    lua_pushcfunction(L, luaKenshiLogWarn);
    lua_setfield(L, -2, "warn");
    lua_pushcfunction(L, luaKenshiLogWarn);
    lua_setfield(L, -2, "logWarn");

    lua_pushcfunction(L, luaKenshiLogError);
    lua_setfield(L, -2, "logError");

    lua_pushcfunction(L, luaKenshiError);
    lua_setfield(L, -2, "error");

    lua_pushcfunction(L, luaKenshiProfileStart);
    lua_setfield(L, -2, "profileStart");

    lua_pushcfunction(L, luaKenshiProfileStop);
    lua_setfield(L, -2, "profileStop");

    lua_pushcfunction(L, luaKenshiProfileDump);
    lua_setfield(L, -2, "profileDump");

    lua_setglobal(L, "KenshiLua");
}

static std::string formatLuaArgs(lua_State* L)
{
    int n = lua_gettop(L);
    std::string msg;
    for (int i = 1; i <= n; i++) {
        if (i > 1) msg += " ";
        size_t len = 0;
        const char* s = luaL_tolstring(L, i, &len);
        if (s) {
            msg.append(s, len);
        }
        lua_pop(L, 1);
    }
    return msg;
}

int luaKenshiLog(lua_State* L)
{
    logToFile(formatLuaArgs(L));
    return 0;
}

int luaKenshiLogDebug(lua_State* L)
{
    logToFileDebug(formatLuaArgs(L));
    return 0;
}

int luaKenshiLogWarn(lua_State* L)
{
    logToFile(LogLevel_Warn, formatLuaArgs(L));
    return 0;
}

int luaKenshiLogError(lua_State* L)
{
    logToFile(LogLevel_Error, formatLuaArgs(L));
    return 0;
}

int luaKenshiError(lua_State* L)
{
    std::string msg = "Lua Error: " + formatLuaArgs(L);
    logToFile(LogLevel_Error, msg);
    lua_settop(L, 0);
    lua_pushlstring(L, msg.c_str(), msg.size());
    return lua_error(L);
}

int luaKenshiVersion(lua_State* L) { lua_pushstring(L, "KenshiLua 0.2.7"); return 1; }

static std::map<std::string, int> g_profileSamples;
static int g_profileTotalSamples = 0;
static bool g_isProfiling = false;

static void profileCallback(void* data, lua_State* L, int samples, int vmstate)
{
    (void)data;
    (void)vmstate;
    size_t len = 0;
    const char* stackStr = luaJIT_profile_dumpstack(L, "f", 0, &len);
    if (stackStr && len > 0) {
        g_profileSamples[std::string(stackStr, len)] += samples;
    } else {
        g_profileSamples["[unknown]"] += samples;
    }
    g_profileTotalSamples += samples;
}

static std::string formatProfileReport()
{
    std::stringstream ss;
    ss << "=== LuaJIT Profile Report ===" << "\n";
    ss << "Total Samples: " << g_profileTotalSamples << "\n";
    if (g_profileTotalSamples == 0) {
        ss << "No samples recorded.\n";
        return ss.str();
    }
    for (std::map<std::string, int>::const_iterator it = g_profileSamples.begin(); it != g_profileSamples.end(); ++it) {
        double pct = (double)it->second * 100.0 / (double)g_profileTotalSamples;
        char buf[256];
        sprintf_s(buf, "  %6.2f%% (%d) : %s\n", pct, it->second, it->first.c_str());
        ss << buf;
    }
    ss << "=============================";
    return ss.str();
}

int luaKenshiProfileStart(lua_State* L)
{
    const char* mode = "fi1";
    if (lua_gettop(L) >= 1 && lua_isstring(L, 1)) {
        mode = lua_tostring(L, 1);
    }
    g_profileSamples.clear();
    g_profileTotalSamples = 0;
    g_isProfiling = true;

    luaJIT_profile_start(L, mode, profileCallback, NULL);
    logToFile("LuaJIT profiler started with mode: " + std::string(mode));
    return 0;
}

int luaKenshiProfileDump(lua_State* L)
{
    std::string report = formatProfileReport();
    lua_pushlstring(L, report.c_str(), report.size());
    return 1;
}

int luaKenshiProfileStop(lua_State* L)
{
    if (g_isProfiling) {
        luaJIT_profile_stop(L);
        g_isProfiling = false;
        logToFile("LuaJIT profiler stopped.");
    }
    std::string report = formatProfileReport();
    logToFile(report);
    lua_pushlstring(L, report.c_str(), report.size());
    return 1;
}

} // namespace KenshiLua
