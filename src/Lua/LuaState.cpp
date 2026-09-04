#include "pch.h"
#include "Lua/LuaState.h"
#include "Lua/BindingHelpers.h"
#include "Util/PathUtils.h"

#include <cstdlib>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
LuaState* g_luaState = 0;

LuaState* LuaState::getActive()
{
    return g_luaState;
}

lua_State* LuaState::getActiveState()
{
    return (g_luaState && g_luaState->isValid()) ? g_luaState->getState() : nullptr;
}

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

    luaL_dostring(m_L,
        "local ok, tn = pcall(require, 'table.new') "
        "if ok then table.new = tn end "
        "local ok2, tc = pcall(require, 'table.clear') "
        "if ok2 then table.clear = tc end");

    std::string dllDir = getDllDirectory();
    normalizePathSlashes(dllDir);
    std::string pathScript =
        "local p = package.path\n"
        "package.path = p .. ';./KenshiLua/lib/?.lua;./KenshiLua/lib/?/init.lua;./lib/?.lua;./lib/?/init.lua;"
        + dllDir + "/../lib/?.lua;" + dllDir + "/../lib/?/init.lua'\n";
    luaL_dostring(m_L, pathScript.c_str());

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
    if (lua_gettop(L) > 0) {
        size_t len = 0;
        const char* s = lua_tolstring(L, -1, &len);
        if (!s) {
            s = luaL_tolstring(L, -1, &len);
            if (s && len > 0) {
                msg += ": ";
                msg.append(s, len);
                lua_pop(L, 1); // pop luaL_tolstring result
            }
        } else if (len > 0) {
            msg += ": ";
            msg.append(s, len);
        }
    }

    // Capture full Lua stack traceback
    luaL_traceback(L, L, msg.c_str(), 0);
    const char* fullTrace = lua_tostring(L, -1);
    if (fullTrace) {
        logToFileError(fullTrace);
    } else {
        logToFileError(msg);
    }
    lua_pop(L, 1); // pop traceback string

    return LUA_ERRERR;
}

int LuaState::genericTraceback(lua_State* L)
{
    const char* msg = lua_tostring(L, 1);
    if (!msg && !lua_isnoneornil(L, 1)) {
        luaL_tolstring(L, 1, NULL);
        msg = lua_tostring(L, -1);
    }
    luaL_traceback(L, L, msg, 1);
    return 1;
}

bool LuaState::pcallWithTraceback(lua_State* L, int nargs, int nresults, std::string* outError)
{
    // Insert traceback handler below the function + args already on the stack.
    int funcIndex = lua_gettop(L) - nargs;
    if (funcIndex < 1) {
        funcIndex = 1;
    }
    lua_pushcfunction(L, genericTraceback);
    lua_insert(L, funcIndex);

    int status = lua_pcall(L, nargs, nresults, funcIndex);

    if (status != LUA_OK) {
        if (outError) {
            if (lua_gettop(L) > 0 && !lua_isnil(L, -1)) {
                size_t len = 0;
                const char* err = lua_tolstring(L, -1, &len);
                if (!err) {
                    err = luaL_tolstring(L, -1, &len);
                    if (err) {
                        *outError = std::string(err, len);
                        lua_pop(L, 1); // pop luaL_tolstring result
                    }
                } else {
                    *outError = std::string(err, len);
                }
            }
            if (outError->empty()) {
                switch (status) {
                case LUA_ERRRUN:
                    *outError = "Lua runtime error";
                    break;
                case LUA_ERRSYNTAX:
                    *outError = "Lua syntax error";
                    break;
                case LUA_ERRMEM:
                    *outError = "Lua memory allocation error (out of memory in GC space)";
                    break;
                case LUA_ERRERR:
                    *outError = "Lua error in error handling";
                    break;
                default:
                    *outError = "Lua error (status " + std::to_string((long long)status) + ")";
                    break;
                }
            }
        }
        lua_remove(L, funcIndex); // remove traceback handler
        if (lua_gettop(L) > 0) {
            lua_pop(L, 1); // pop error message
        }
        return false;
    }

    lua_remove(L, funcIndex); // remove traceback handler
    return true;
}

} // namespace KenshiLua
