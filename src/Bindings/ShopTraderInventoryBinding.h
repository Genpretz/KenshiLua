#pragma once

#include "kenshi/ShopTrader.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ShopTraderInventoryBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ShopTraderInventory"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int updateInventory(lua_State* L);
    static int _NV_updateInventory(lua_State* L);
    static int dropItem(lua_State* L);
    static int _NV_dropItem(lua_State* L);
    static int refreshGui(lua_State* L);
    static int _NV_refreshGui(lua_State* L);
    static int initialiseNewSection(lua_State* L);
    static int _NV_initialiseNewSection(lua_State* L);
    static int _addItem(lua_State* L);
    static int _NV__addItem(lua_State* L);
    static int _addItemToInventories(lua_State* L);
    static int _removeItemFromInventories(lua_State* L);
    static int _sectionAddItemCallback(lua_State* L);
    static int _NV__sectionAddItemCallback(lua_State* L);
    static int _sectionUpdateItemCallback(lua_State* L);
    static int _NV__sectionUpdateItemCallback(lua_State* L);
    static int _sectionRemoveItemCallback(lua_State* L);
    static int _NV__sectionRemoveItemCallback(lua_State* L);
};
}

