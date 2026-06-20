#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FarmBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FarmBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int createPhysical(lua_State* L);
    static int _NV_createPhysical(lua_State* L);
    static int destroyPhysical(lua_State* L);
    static int _NV_destroyPhysical(lua_State* L);
    static int setVisible(lua_State* L);
    static int _NV_setVisible(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int needsUpdate(lua_State* L);
    static int _NV_needsUpdate(lua_State* L);
    static int isAnyInputsEmpty(lua_State* L);
    static int _NV_isAnyInputsEmpty(lua_State* L);
    static int isProductionFull(lua_State* L);
    static int _NV_isProductionFull(lua_State* L);
    static int howMuchPowerDoYouWantForSortingFunction(lua_State* L);
    static int _NV_howMuchPowerDoYouWantForSortingFunction(lua_State* L);
    static int setupMiningResourceLevel(lua_State* L);
    static int _NV_setupMiningResourceLevel(lua_State* L);
    static int destroyAPlant(lua_State* L);
    static int timeSkip(lua_State* L);
    static int _updateInputs(lua_State* L);
    static int isCropsEdible(lua_State* L);
    static int eat(lua_State* L);
    static int dontNeedWorkRightNow(lua_State* L);
    static int _NV_dontNeedWorkRightNow(lua_State* L);
    static int setupMaterial(lua_State* L);
    static int updateMaterial(lua_State* L);
    static int resetFarm(lua_State* L);
};
}