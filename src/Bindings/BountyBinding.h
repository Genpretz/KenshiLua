#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

class Bounty;

namespace KenshiLua
{

class BountyEnumBinding
{
public:
    static void registerCrimeEnum(lua_State* L);
};

class BountyBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Bounty"; }
    static void registerBinding(lua_State* L);

    static int pushBounty(lua_State* L, const Bounty& b);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    // Methods
    static int addCrime(lua_State* L);
    static int hasCrime(lua_State* L);
};

} // namespace KenshiLua
