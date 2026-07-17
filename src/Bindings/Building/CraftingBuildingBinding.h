#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CraftingBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CraftingBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int createInventoryLayout(lua_State* L);
    static int _NV_createInventoryLayout(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int givePower(lua_State* L);
    static int _NV_givePower(lua_State* L);
    static int hasCraftingQueued(lua_State* L);
    static int _NV_hasCraftingQueued(lua_State* L);
    static int isProductionFull(lua_State* L);
    static int _NV_isProductionFull(lua_State* L);
    static int getProductionItemData(lua_State* L);
    static int _NV_getProductionItemData(lua_State* L);
    static int getCurrentProductionQuantity(lua_State* L);
    static int _NV_getCurrentProductionQuantity(lua_State* L);
    static int isAnyInputsInvalidType(lua_State* L);
    static int _NV_isAnyInputsInvalidType(lua_State* L);
    static int notifyCraftFailiure(lua_State* L);
    static int _removeCraft(lua_State* L);
    static int getCraft(lua_State* L);
    static int destroyProductionItem(lua_State* L);
    static int getCriticalSuccessWeapon(lua_State* L);
    static int setupFromData(lua_State* L);
    static int _NV_setupFromData(lua_State* L);
    static int updateOutput(lua_State* L);
    static int _NV_updateOutput(lua_State* L);
    static int updateInventoryWindow(lua_State* L);
    static int _NV_updateInventoryWindow(lua_State* L);
};
}