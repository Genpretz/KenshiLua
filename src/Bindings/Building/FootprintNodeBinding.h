#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FootprintNodeBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FootprintNode"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int updateBox(lua_State* L);
    static int _NV_updateBox(lua_State* L);
    static int setEnabled(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}