#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ItemListWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ItemListWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int itemSelected(lua_State* L);
    static int _NV_itemSelected(lua_State* L);
};
}