#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class LightBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.LightBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int createPhysical(lua_State* L);
    static int _NV_createPhysical(lua_State* L);
    static int getMouseCursor(lua_State* L);
    static int _NV_getMouseCursor(lua_State* L);
    static int needPowerRightNow(lua_State* L);
    static int _NV_needPowerRightNow(lua_State* L);
    static int getPositionMarker(lua_State* L);
    static int _NV_getPositionMarker(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}