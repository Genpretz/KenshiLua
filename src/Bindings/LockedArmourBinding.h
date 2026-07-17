#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class LockedArmourBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.LockedArmour"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int isArmour(lua_State* L);
    static int _NV_isArmour(lua_State* L);
    static int isLockedArmour(lua_State* L);
    static int _NV_isLockedArmour(lua_State* L);
};
}