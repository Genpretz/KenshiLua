#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FurnaceInventoryLayoutBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FurnaceInventoryLayout"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
};
}