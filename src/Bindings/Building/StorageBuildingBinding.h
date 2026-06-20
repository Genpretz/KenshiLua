#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class StorageBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.StorageBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int getProductionItemData(lua_State* L);
    static int _NV_getProductionItemData(lua_State* L);
    static int getProductionItem(lua_State* L);
    static int getCurrentProductionQuantity(lua_State* L);
    static int _NV_getCurrentProductionQuantity(lua_State* L);
    static int isAnyInputsEmpty(lua_State* L);
    static int _NV_isAnyInputsEmpty(lua_State* L);
    static int isAnyInputsFull(lua_State* L);
    static int _NV_isAnyInputsFull(lua_State* L);
    static int isProductionFull(lua_State* L);
    static int _NV_isProductionFull(lua_State* L);
    static int isProductionEmpty(lua_State* L);
    static int _NV_isProductionEmpty(lua_State* L);
    static int getNumConsumtionItems(lua_State* L);
    static int _NV_getNumConsumtionItems(lua_State* L);
    static int getConsumtionItems(lua_State* L);
    static int _NV_getConsumtionItems(lua_State* L);
    static int limitedByType(lua_State* L);
    static int updateInventoryWindow(lua_State* L);
    static int _NV_updateInventoryWindow(lua_State* L);
};
}