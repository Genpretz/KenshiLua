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
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int reAnnounceGateToPathfinder(lua_State* L);
    static int postCreationPathfinderSetupStuff(lua_State* L);
    static int _NV_postCreationPathfinderSetupStuff(lua_State* L);
    static int isForSale(lua_State* L);
    static int _NV_isForSale(lua_State* L);
    static int setup(lua_State* L);
    static int _NV_setup(lua_State* L);
    static int getOutsideGateCode(lua_State* L);
    static int separatesAreas(lua_State* L);
};
}