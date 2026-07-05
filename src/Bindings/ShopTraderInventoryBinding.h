#pragma once

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

    static int _DESTRUCTOR(lua_State* L);
    static int updateInventory(lua_State* L);
    static int _NV_updateInventory(lua_State* L);
    static int refreshGui(lua_State* L);
    static int _NV_refreshGui(lua_State* L);
    static int initialiseNewSection(lua_State* L);
    static int _NV_initialiseNewSection(lua_State* L);
};
}