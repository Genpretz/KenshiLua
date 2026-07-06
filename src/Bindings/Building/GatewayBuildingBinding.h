#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GatewayBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GatewayBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int reAnnounceGateToPathfinder(lua_State* L);
    static int postCreationPathfinderSetupStuff(lua_State* L);
    static int _NV_postCreationPathfinderSetupStuff(lua_State* L);
    static int getPositionForWaypoint(lua_State* L);
    static int _NV_getPositionForWaypoint(lua_State* L);
    static int getUseableStuff(lua_State* L);
    static int _NV_getUseableStuff(lua_State* L);
    static int isGate(lua_State* L);
    static int _NV_isGate(lua_State* L);
    static int isForSale(lua_State* L);
    static int _NV_isForSale(lua_State* L);
    static int setup(lua_State* L);
    static int _NV_setup(lua_State* L);
    static int getGateCodeAt(lua_State* L);
    static int getOutsideGateCode(lua_State* L);
    static int separatesAreas(lua_State* L);
};
}