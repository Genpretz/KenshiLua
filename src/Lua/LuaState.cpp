#include "pch.h"
#include "Lua/LuaState.h"
#include <cstdlib>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
LuaState* g_luaState = 0;

static void* defaultAlloc(void* ud, void* ptr, size_t osize, size_t nsize)
{
    (void)ud;
    (void)osize;
    if (nsize == 0) {
        free(ptr);
        return 0;
    }
    void* newptr = realloc(ptr, nsize);
    return newptr;
}

LuaState::LuaState()
    : m_L(0)
{
}

LuaState::~LuaState()
{
    close();
}

LuaState::LuaState(const LuaState&)
    : m_L(0)
{
}

LuaState& LuaState::operator=(const LuaState&)
{
    return *this;
}

bool LuaState::initialize()
{
    if (m_L) {
        return true;
    }

    m_L = lua_newstate(defaultAlloc, NULL);

    if (!m_L) {
        return false;
    }

    lua_atpanic(m_L, panicHandler);

    luaL_openlibs(m_L);

    return true;
}

void LuaState::close()
{
    if (m_L) {
        lua_close(m_L);
        m_L = 0;
    }
}

int LuaState::panicHandler(lua_State* L)
{
    std::string msg = "PANIC: unprotected error in Lua";
    if (lua_gettop(L) > 0 && lua_isstring(L, -1)) {
        size_t len = 0;
        const char* s = lua_tolstring(L, -1, &len);
        if (s && len > 0) {
            msg += ": ";
            msg.append(s, len);
        }
    }
    return LUA_ERRERR;
}

int LuaState::genericTraceback(lua_State* L)
{
    lua_Debug ar;
    if (!lua_getstack(L, 1, &ar)) {
        return 1;
    }
    if (!lua_getinfo(L, "Snl", &ar)) {
        return 1;
    }

    lua_pushstring(L, "\nstack traceback:\n");
    if (ar.currentline > 0) {
        char buf[256];
        _snprintf(buf, sizeof(buf), "\t%s:%d: ", ar.short_src, ar.currentline);
        lua_pushstring(L, buf);
    } else {
        lua_pushstring(L, "\tunknown: ");
    }
    lua_concat(L, 3);

    return 1;
}

bool LuaState::pcallWithTraceback(lua_State* L, int nargs, int nresults, std::string* outError)
{
    // Insert traceback handler below the function + args already on the stack.
    int funcIndex = lua_gettop(L) - nargs;
    lua_pushcfunction(L, genericTraceback);
    lua_insert(L, funcIndex);

    int status = lua_pcall(L, nargs, nresults, funcIndex);
    lua_remove(L, funcIndex); // remove traceback handler

    if (status != LUA_OK) {
        if (outError) {
            const char* err = lua_tostring(L, -1);
            *outError = err ? err : "unknown Lua error";
        }
        lua_pop(L, 1); // pop error message
        return false;
    }
    return true;
}

} // namespace KenshiLua