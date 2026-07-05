#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class BountyBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Bounty"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int addCrime(lua_State* L);
    static int hasCrime(lua_State* L);
};
}