#pragma once
#include "kenshi/Building/FarmBuilding.h"

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

    static int _CONSTRUCTOR(lua_State* L);
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
    static int operate(lua_State* L);
    static int _NV_operate(lua_State* L);
    static int isAnyInputsEmpty(lua_State* L);
    static int _NV_isAnyInputsEmpty(lua_State* L);
    static int isProductionFull(lua_State* L);
    static int _NV_isProductionFull(lua_State* L);
    static int howMuchPowerDoYouWantForSortingFunction(lua_State* L);
    static int _NV_howMuchPowerDoYouWantForSortingFunction(lua_State* L);
    static int setupMiningResourceLevel(lua_State* L);
    static int _NV_setupMiningResourceLevel(lua_State* L);
    static int getGUIData(lua_State* L);
    static int _NV_getGUIData(lua_State* L);
    static int getGUIEfficiency(lua_State* L);
    static int _NV_getGUIEfficiency(lua_State* L);
    static int getGUIWorkers(lua_State* L);
    static int _NV_getGUIWorkers(lua_State* L);
    static int getGUIState(lua_State* L);
    static int _NV_getGUIState(lua_State* L);
    static int destroyAPlant(lua_State* L);
    static int timeSkip(lua_State* L);
    static int _updateInputs(lua_State* L);
    static int upgrade(lua_State* L);
    static int _NV_upgrade(lua_State* L);
    static int downgrade(lua_State* L);
    static int _NV_downgrade(lua_State* L);
    static int getGUIFertility(lua_State* L);
    static int _NV_getGUIFertility(lua_State* L);
    static int isCropsEdible(lua_State* L);
    static int eat(lua_State* L);
    static int getYieldChancePerCrop(lua_State* L);
    static int getCropMult(lua_State* L);
    static int serialise(lua_State* L);
    static int _NV_serialise(lua_State* L);
    static int loadFromSerialise(lua_State* L);
    static int _NV_loadFromSerialise(lua_State* L);
    static int getDirectionMarker(lua_State* L);
    static int _NV_getDirectionMarker(lua_State* L);
    static int dontNeedWorkRightNow(lua_State* L);
    static int _NV_dontNeedWorkRightNow(lua_State* L);
    static int getFertilityMultiplier(lua_State* L);
    static int setupMaterial(lua_State* L);
    static int updateMaterial(lua_State* L);
    static int updatePlantInstance(lua_State* L);
    static int createPlants(lua_State* L);
    static int createClickHull(lua_State* L);
    static int createEntity(lua_State* L);
    static int resetFarm(lua_State* L);
};
}