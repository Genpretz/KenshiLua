#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class Array2dBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Array2d"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int resize(lua_State* L);
    static int setToZeros(lua_State* L);
};
}