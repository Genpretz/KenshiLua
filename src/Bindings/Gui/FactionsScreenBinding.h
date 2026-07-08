#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FactionsScreenBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FactionsScreen"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int getVisible(lua_State* L);
    static int clear(lua_State* L);
    static int update(lua_State* L);
    static int refresh(lua_State* L);
    static int updateInfo(lua_State* L);
};
}