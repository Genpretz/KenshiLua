#pragma once

#include <string>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    // Restores a Lua global to its previous value when this object leaves scope.
    class ScopedLuaGlobal
    {
    public:
        ScopedLuaGlobal(lua_State* state, const char* name)
            : m_state(state), m_name(name), m_previousValue(LUA_NOREF)
        {
            lua_getglobal(m_state, m_name.c_str());
            m_previousValue = luaL_ref(m_state, LUA_REGISTRYINDEX);
        }

        ~ScopedLuaGlobal()
        {
            if (m_previousValue == LUA_REFNIL)
                lua_pushnil(m_state);
            else
                lua_rawgeti(m_state, LUA_REGISTRYINDEX, m_previousValue);

            lua_setglobal(m_state, m_name.c_str());

            if (m_previousValue != LUA_REFNIL && m_previousValue != LUA_NOREF)
                luaL_unref(m_state, LUA_REGISTRYINDEX, m_previousValue);
        }

    private:
        ScopedLuaGlobal(const ScopedLuaGlobal&);
        ScopedLuaGlobal& operator=(const ScopedLuaGlobal&);

        lua_State* m_state;
        std::string m_name;
        int m_previousValue;
    };
}
