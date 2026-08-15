#pragma once

#include "kenshi/RaceData.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RaceLimiterBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RaceLimiter"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int addLimit(lua_State* L);
    static int getSingleton(lua_State* L);
    static int canEquip(lua_State* L);
    static int _NV_canEquip(lua_State* L);
};
}