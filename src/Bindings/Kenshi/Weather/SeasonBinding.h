#pragma once

#include "kenshi/Weather.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SeasonBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Season"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getName(lua_State* L);
    static int getNewWeather(lua_State* L);
};
}
