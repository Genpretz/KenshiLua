#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class BuildingSwapsBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BuildingSwaps"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int hasReplacement(lua_State* L);
    static int getReplacement(lua_State* L);
};
}
