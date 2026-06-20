#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class WindGeneratorBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.WindGeneratorBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int getPowerOutput(lua_State* L);
    static int _NV_getPowerOutput(lua_State* L);
    static int getSoundIntensity(lua_State* L);
    static int _NV_getSoundIntensity(lua_State* L);
    static int isAnyInputsEmpty(lua_State* L);
    static int _NV_isAnyInputsEmpty(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}