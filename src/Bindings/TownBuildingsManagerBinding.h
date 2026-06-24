#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TownBuildingsManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TownBuildingsManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int clear(lua_State* L);
    static int setAllVisible(lua_State* L);
    static int resetAllVisible(lua_State* L);
    static int setSignsVisible(lua_State* L);
};
}