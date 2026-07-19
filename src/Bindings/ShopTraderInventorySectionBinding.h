#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ShopTraderInventorySectionBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ShopTraderInventorySection"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int autoArrange(lua_State* L);
    static int _NV_autoArrange(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int addItem(lua_State* L);
    static int _NV_addItem(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
};
}
