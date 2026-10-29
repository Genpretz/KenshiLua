#pragma once

#include "kenshi/Weather.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class WeatherSystem_ZoneFogBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.WeatherSystem_ZoneFog"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int clear(lua_State* L);
    static int getCurrentValues(lua_State* L);
    static int update(lua_State* L);
};
}
