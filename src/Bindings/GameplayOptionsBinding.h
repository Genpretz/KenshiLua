#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GameplayOptionsBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GameplayOptions"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int reset(lua_State* L);
    static int getStarvationTimeInHours(lua_State* L);
};
}