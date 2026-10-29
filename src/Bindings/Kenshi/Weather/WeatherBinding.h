#pragma once

#include "kenshi/Weather.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class WeatherBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Weather"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getName(lua_State* L);
};
}
