#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ProductionBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ProductionBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int needsUpdate(lua_State* L);
    static int _NV_needsUpdate(lua_State* L);
    static int getProductionMult(lua_State* L);
    static int _NV_getProductionMult(lua_State* L);
    static int getProductionMultForGUI(lua_State* L);
    static int _NV_getProductionMultForGUI(lua_State* L);
    static int setupMiningResourceLevel(lua_State* L);
    static int _NV_setupMiningResourceLevel(lua_State* L);
    static int getMiningResourceLevel(lua_State* L);
    static int _NV_getMiningResourceLevel(lua_State* L);
    static int isAnyInputsEmpty(lua_State* L);
    static int _NV_isAnyInputsEmpty(lua_State* L);
    static int isAnyInputsInvalidType(lua_State* L);
    static int _NV_isAnyInputsInvalidType(lua_State* L);
    static int isAnyInputsFull(lua_State* L);
    static int _NV_isAnyInputsFull(lua_State* L);
    static int isProductionFull(lua_State* L);
    static int _NV_isProductionFull(lua_State* L);
    static int isProductionEmpty(lua_State* L);
    static int _NV_isProductionEmpty(lua_State* L);
    static int getOutputBasedRotationSpeedMult(lua_State* L);
    static int _NV_getOutputBasedRotationSpeedMult(lua_State* L);
    static int getOutput(lua_State* L);
    static int getNumConsumtionItems(lua_State* L);
    static int _NV_getNumConsumtionItems(lua_State* L);
    static int getConsumtionItems(lua_State* L);
    static int _NV_getConsumtionItems(lua_State* L);
    static int setupFromData(lua_State* L);
    static int _NV_setupFromData(lua_State* L);
    static int updateInventoryWindow(lua_State* L);
    static int _NV_updateInventoryWindow(lua_State* L);
    static int updateInputs(lua_State* L);
    static int _NV_updateInputs(lua_State* L);
    static int updateOutput(lua_State* L);
    static int _NV_updateOutput(lua_State* L);
};
}