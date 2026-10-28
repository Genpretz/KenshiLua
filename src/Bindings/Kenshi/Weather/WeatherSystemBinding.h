#pragma once

#include "kenshi/Weather.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class WeatherSystemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.WeatherSystem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getInstanceMethod(lua_State* L);
    static int reset(lua_State* L);
    static int updateMT(lua_State* L);
    static int updateBT(lua_State* L);
    static int updateUT(lua_State* L);
    static int addWeatherListener(lua_State* L);
    static int removeWeatherListener(lua_State* L);
    static int getPositionGlobalEffects(lua_State* L);
    static int addWeatherEffect(lua_State* L);
    static int removeWeatherEffect(lua_State* L);
    static int setDustShaderValue(lua_State* L);
};
}
