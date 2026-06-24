#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CrossbowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Crossbow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isCrossbow(lua_State* L);
    static int _NV_isCrossbow(lua_State* L);
    static int getClassType(lua_State* L);
    static int _NV_getClassType(lua_State* L);
    static int getCraftMaterialMult(lua_State* L);
    static int _NV_getCraftMaterialMult(lua_State* L);
    static int getCraftTime(lua_State* L);
    static int _NV_getCraftTime(lua_State* L);
    static int getRangeInUnits(lua_State* L);
    static int getEquipPositionOffset(lua_State* L);
    static int destroyItemEntityCallback_Equipping(lua_State* L);
    static int _NV_destroyItemEntityCallback_Equipping(lua_State* L);
    static int setVisible(lua_State* L);
    static int _NV_setVisible(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}