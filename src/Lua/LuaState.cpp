#include "pch.h"
#include "Lua/LuaState.h"
#include <cstdarg>
#include <cstdio>
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

static std::string formatLuaError(const char* msg, lua_State* L)
{
    std::string result = msg;

    if (lua_gettop(L) > 0 && lua_isstring(L, -1)) {
        size_t len = 0;
        const char* s = lua_tolstring(L, -1, &len);
        if (s && len > 0) {
            if (!result.empty()) {
                result += ": ";
            }
            result += s;
        }
    }

    lua_Debug ar;
    if (lua_getstack(L, 1, &ar) && lua_getinfo(L, "Sl", &ar)) {
        char buf[256];
        _snprintf(buf, sizeof(buf), " (%s:%d)", ar.short_src, ar.currentline);
        result += buf;
    }

    return result;
}

LuaState::LuaState()
    : m_L(0)
    , m_lastError(LUA_OK)
{
}

LuaState::~LuaState()
{
    close();
}

LuaState::LuaState(const LuaState&)
    : m_L(0)
    , m_lastError(LUA_OK)
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
        m_lastError = LUA_ERRMEM;
        m_errorMessage = "Failed to create Lua state";
        return false;
    }

    lua_atpanic(m_L, panicHandler);

    luaL_openlibs(m_L);

    m_lastError = LUA_OK;
    m_errorMessage.clear();
    return true;
}

void LuaState::close()
{
    if (m_L) {
        lua_close(m_L);
        m_L = 0;
    }
}

bool LuaState::loadScript(const char* script, size_t len, const char* chunkname)
{
    if (!m_L) {
        m_lastError = LUA_ERRERR;
        m_errorMessage = "Lua state not initialized";
        return false;
    }

    int base = lua_gettop(m_L);
    lua_pushcfunction(m_L, genericTraceback);
    int tracebackIndex = lua_gettop(m_L);

    m_lastError = luaL_loadbuffer(m_L, script, len, chunkname ? chunkname : "=(load)");

    if (m_lastError != LUA_OK) {
        m_errorMessage = formatLuaError("Lua error", m_L);
        lua_settop(m_L, base);
        return false;
    }

    m_lastError = lua_pcall(m_L, 0, 0, tracebackIndex);

    if (m_lastError != LUA_OK) {
        m_errorMessage = formatLuaError("Lua error", m_L);
        lua_settop(m_L, base);
        return false;
    }

    lua_settop(m_L, base);
    return true;
}

bool LuaState::loadScriptFile(const char* filepath)
{
    if (!m_L) {
        m_lastError = LUA_ERRERR;
        m_errorMessage = "Lua state not initialized";
        return false;
    }

    int base = lua_gettop(m_L);
    lua_pushcfunction(m_L, genericTraceback);
    int tracebackIndex = lua_gettop(m_L);

    m_lastError = luaL_loadfile(m_L, filepath);

    if (m_lastError != LUA_OK) {
        m_errorMessage = formatLuaError("Lua error", m_L);
        lua_settop(m_L, base);
        return false;
    }

    m_lastError = lua_pcall(m_L, 0, 0, tracebackIndex);

    if (m_lastError != LUA_OK) {
        m_errorMessage = formatLuaError("Lua error", m_L);
        lua_settop(m_L, base);
        return false;
    }

    lua_settop(m_L, base);
    return true;
}

bool LuaState::executeString(const char* str)
{
    if (!m_L) {
        m_lastError = LUA_ERRERR;
        m_errorMessage = "Lua state not initialized";
        return false;
    }

    int base = lua_gettop(m_L);
    lua_pushcfunction(m_L, genericTraceback);
    int tracebackIndex = lua_gettop(m_L);

    m_lastError = luaL_dostring(m_L, str);

    if (m_lastError != LUA_OK) {
        m_errorMessage = formatLuaError("Lua error", m_L);
        lua_settop(m_L, base);
        return false;
    }

    lua_settop(m_L, base);
    return true;
}

bool LuaState::executeFile(const char* filepath)
{
    if (!m_L) {
        m_lastError = LUA_ERRERR;
        m_errorMessage = "Lua state not initialized";
        return false;
    }

    int base = lua_gettop(m_L);
    lua_pushcfunction(m_L, genericTraceback);
    int tracebackIndex = lua_gettop(m_L);

    m_lastError = luaL_dofile(m_L, filepath);

    if (m_lastError != LUA_OK) {
        m_errorMessage = formatLuaError("Lua error", m_L);
        lua_settop(m_L, base);
        return false;
    }

    lua_settop(m_L, base);
    return true;
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

} // namespace KenshiLua