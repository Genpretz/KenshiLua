#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GenericFixedInventoryLayoutBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GenericFixedInventoryLayout"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int setSize(lua_State* L);
    static int _NV_setSize(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}