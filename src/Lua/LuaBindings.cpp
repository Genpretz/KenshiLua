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

#include <string>
#include <cstdio>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

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

    lua_setglobal(L, "KenshiLua");
}

static std::string formatLuaArgs(lua_State* L)
{
    int n = lua_gettop(L);
    std::string msg;
    for (int i = 1; i <= n; i++) {
        if (i > 1) msg += " ";
        switch (lua_type(L, i)) {
        case LUA_TSTRING: msg += lua_tostring(L, i); break;
        case LUA_TNUMBER:
            if (lua_isinteger(L, i)) {
                char buf[32]; _snprintf(buf, sizeof(buf), "%lld", (long long)lua_tointeger(L, i));
                msg += buf;
            } else {
                char buf[64]; _snprintf(buf, sizeof(buf), "%.14g", lua_tonumber(L, i));
                msg += buf;
            }
            break;
        case LUA_TBOOLEAN: msg += lua_toboolean(L, i) ? "true" : "false"; break;
        case LUA_TNIL: msg += "nil"; break;
        default:
            char buf[64]; _snprintf(buf, sizeof(buf), "%s:%p", lua_typename(L, lua_type(L, i)), lua_topointer(L, i));
            msg += buf;
            break;
        }
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
    int n = lua_gettop(L);
    std::string msg = "Lua Error: ";
    for (int i = 1; i <= n; i++) {
        if (i > 1) msg += " ";
        switch (lua_type(L, i)) {
        case LUA_TSTRING: msg += lua_tostring(L, i); break;
        default:
            {
                char buf[64]; _snprintf(buf, sizeof(buf), "%s:%p", lua_typename(L, lua_type(L, i)), lua_topointer(L, i));
                msg += buf;
            }
            break;
        }
    }
    logToFile(LogLevel_Error, msg);
    lua_settop(L, 0);
    lua_pushlstring(L, msg.c_str(), msg.size());
    return lua_error(L);
}

int luaKenshiVersion(lua_State* L) { lua_pushstring(L, "KenshiLua 0.2.5"); return 1; }

} // namespace KenshiLua
