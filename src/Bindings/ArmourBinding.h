#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ArmourBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Armour"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getClassType(lua_State* L);
    static int _NV_getClassType(lua_State* L);
    static int isArmour(lua_State* L);
    static int _NV_isArmour(lua_State* L);
    static int getItemWeight(lua_State* L);
    static int _NV_getItemWeight(lua_State* L);
    static int getValueSingle(lua_State* L);
    static int _NV_getValueSingle(lua_State* L);
    static int hasArmourCoverage(lua_State* L);
    static int getCraftTime(lua_State* L);
    static int _NV_getCraftTime(lua_State* L);
    static int getWeatherProtection_simple(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int didIHitFlesh(lua_State* L);
    static int getArmourCraftingMaterialConsumptionRate(lua_State* L);
};
}