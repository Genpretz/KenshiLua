#pragma once
#include <kenshi/RaceData.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef RaceLimiter::Limiter Limiter;

class LimiterBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Limiter"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int _NV_canEquip(lua_State* L);
    static int canEquip(lua_State* L);
};
}
