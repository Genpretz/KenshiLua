#pragma once

#include <string>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class LuaState;
extern LuaState* g_luaState;

class LuaState
{
public:
    LuaState();
    ~LuaState();

    LuaState(const LuaState&);
    LuaState& operator=(const LuaState&);

    lua_State* getState() { return m_L; }

    bool initialize();
    void close();

    bool isValid() const { return m_L != NULL; }

    /// Lua panic handler installed via lua_atpanic.
    static int panicHandler(lua_State* L);

    /// Traceback message handler suitable for use as the msgh argument to lua_pcall.
    /// Appends file:line + stack traceback info to the error string on top of the stack.
    static int genericTraceback(lua_State* L);

    /// Safe lua_pcall wrapper that installs genericTraceback as the message handler.
    /// Returns true on LUA_OK. On error, pops the error value and writes it to
    /// *outError if non-null, then returns false.
    static bool pcallWithTraceback(lua_State* L, int nargs, int nresults, std::string* outError = NULL);

private:
    lua_State* m_L;
};

} // namespace KenshiLua