#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GearBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Gear"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isGear(lua_State* L);
    static int _NV_isGear(lua_State* L);
    static int getLevel01(lua_State* L);
    static int _NV_getLevel01(lua_State* L);
    static int getLevel(lua_State* L);
    static int _NV_getLevel(lua_State* L);
    static int isAFactionUniform(lua_State* L);
    static int _NV_isAFactionUniform(lua_State* L);
    static int isPlayerCrafted(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
	static int setInventoryWeAreIn(lua_State* L);
	static int _NV_setInventoryWeAreIn(lua_State* L);
};
}