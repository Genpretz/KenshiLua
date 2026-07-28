#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class LightEntBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.LightEnt"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int setEnergyLevel(lua_State* L);
    static int setFloor(lua_State* L);
};
}