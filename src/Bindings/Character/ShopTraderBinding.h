#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ShopTraderBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ShopTrader"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int getInventory(lua_State* L);
    static int _NV_getInventory(lua_State* L);
    static int takeMoney(lua_State* L);
    static int _NV_takeMoney(lua_State* L);
    static int getMoney(lua_State* L);
    static int _NV_getMoney(lua_State* L);
    static int getFloor(lua_State* L);
    static int _NV_getFloor(lua_State* L);
    static int getTrader(lua_State* L);
    static int isPhysical(lua_State* L);
    static int _NV_isPhysical(lua_State* L);
    static int setVisible(lua_State* L);
    static int _NV_setVisible(lua_State* L);
    static int createPhysical(lua_State* L);
    static int _NV_createPhysical(lua_State* L);
    static int destroyPhysical(lua_State* L);
    static int _NV_destroyPhysical(lua_State* L);
    static int updateInventory(lua_State* L);
};
}