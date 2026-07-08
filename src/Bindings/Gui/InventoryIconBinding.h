#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class InventoryIconBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.InventoryIcon"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int update(lua_State* L);
    static int getWidget(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}