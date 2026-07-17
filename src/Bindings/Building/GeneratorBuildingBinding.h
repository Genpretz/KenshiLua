#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GeneratorBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GeneratorBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getPowerOutput(lua_State* L);
    static int _NV_getPowerOutput(lua_State* L);
    static int getFuelConsumptionRate(lua_State* L);
    static int _NV_getFuelConsumptionRate(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}