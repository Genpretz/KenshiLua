#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TownListWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TownListWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int formatItem(lua_State* L);
    static int _NV_formatItem(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}