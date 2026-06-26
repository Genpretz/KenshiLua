#include "pch.h"
#include "Lua/LuaUtils.h"
#include "Lua/Logger.h"

#include <string>
#include <cstdarg>
#include <cstdio>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
namespace LuaUtils
{

// ---------------------------------------------------------------------------
// luaToString - produce a human-readable representation of one stack slot.
// Leverages Lua 5.5's improved number conversion for better performance.
// ---------------------------------------------------------------------------
std::string luaToString(lua_State* L, int idx)
{
    switch (lua_type(L, idx)) {
    case LUA_TNIL:
        return "nil";
    case LUA_TBOOLEAN:
        return lua_toboolean(L, idx) ? "true" : "false";
    case LUA_TNUMBER: {
        // Use Lua 5.5's optimized number-to-string conversion
        // This leverages the VM's native formatting which is faster and more accurate
        lua_pushvalue(L, idx);
        size_t len;
        const char* str = lua_tolstring(L, -1, &len);
        std::string result(str, len);
        lua_pop(L, 1);
        return result;
    }
    case LUA_TSTRING: {
        size_t len = 0;
        const char* s = lua_tolstring(L, idx, &len);
        return s ? std::string(s, len) : std::string();
    }
    case LUA_TTABLE:
    case LUA_TFUNCTION:
    case LUA_TUSERDATA:
    case LUA_TLIGHTUSERDATA:
    case LUA_TTHREAD: {
        // %p formats the pointer correctly - the previous implementation
        // treated lua_topointer's return as a C string, which is undefined
        // behaviour and would crash or corrupt memory.
        char buf[64];
        _snprintf(buf, sizeof(buf), "%s:%p",
                  lua_typename(L, lua_type(L, idx)),
                  lua_topointer(L, idx));
        return std::string(buf);
    }
    default:
        return std::string(lua_typename(L, lua_type(L, idx)));
    }
}

// ---------------------------------------------------------------------------
// luaLog - concatenate every argument tab-separated and write to the log.
// ---------------------------------------------------------------------------
int luaLog(lua_State* L)
{
    int n = lua_gettop(L);
    std::string msg;
    for (int i = 1; i <= n; i++) {
        if (i > 1) msg += "\t";
        msg += luaToString(L, i);
    }
    logToFile(msg);
    return 0;
}

// ---------------------------------------------------------------------------
// luaError - assemble an error message from args, log it, then raise.
// ---------------------------------------------------------------------------
int luaError(lua_State* L)
{
    int n = lua_gettop(L);
    std::string msg;
    for (int i = 1; i <= n; i++) {
        if (i > 1) msg += " ";
        msg += luaToString(L, i);
    }
    logToFile("Lua error: " + msg);
    lua_settop(L, 0);
    lua_pushlstring(L, msg.c_str(), msg.size());
    return lua_error(L);
}

// ---------------------------------------------------------------------------
// luaPrint - alias for luaLog so scripts can use the standard print().
// ---------------------------------------------------------------------------
int luaPrint(lua_State* L)
{
    return luaLog(L);
}

// ---------------------------------------------------------------------------
// registerBasicBindings - hooks up `log` and `print` to our logger.
// ---------------------------------------------------------------------------
void registerBasicBindings(lua_State* L)
{
    lua_pushcfunction(L, luaLog);
    lua_setglobal(L, "log");

    lua_pushcfunction(L, luaPrint);
    lua_setglobal(L, "print");
}

// ---------------------------------------------------------------------------
// luaRequireSafe - sandbox shim that rejects all module loads.  Used when
// running untrusted scripts; not registered by default.
// ---------------------------------------------------------------------------
int luaRequireSafe(lua_State* L)
{
    const char* modname = luaL_checkstring(L, 1);
    lua_pushnil(L);
    lua_pushfstring(L, "module '%s' not allowed in sandbox", modname);
    return 2;
}

// ---------------------------------------------------------------------------
// executeChunk - run a previously-loaded chunk by registry ref.  Returns
// false (and leaves the error on the stack) on failure.
// ---------------------------------------------------------------------------
bool executeChunk(lua_State* L, int ref)
{
    lua_rawgeti(L, LUA_REGISTRYINDEX, ref);
    if (!lua_isfunction(L, -1)) {
        lua_pop(L, 1);
        return false;
    }
    return lua_pcall(L, 0, 0, 0) == LUA_OK;
}

} // namespace LuaUtils
} // namespace KenshiLua
