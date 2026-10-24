#pragma once

#include "kenshi/Weather.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class WeatherInstanceBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.WeatherInstance"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getTime(lua_State* L);
    static int getTimeNormalized(lua_State* L);
    static int getWeatherBiome(lua_State* L);
    static int getWeather(lua_State* L);
    static int update(lua_State* L);
    static int getHasEnded(lua_State* L);
    static int getFogVisible(lua_State* L);
    static int getFogDistance(lua_State* L);
    static int getFogColour(lua_State* L);
    static int getFogEnabled(lua_State* L);
    static int getGlobalEffectsStrength(lua_State* L);
    static int getWindSpeed(lua_State* L);
    static int getWindDirection(lua_State* L);
    static int getWindForce(lua_State* L);
    static int getWetness(lua_State* L);
    static int getWeatherStrength(lua_State* L);
    static int save(lua_State* L);
    static int load(lua_State* L);
    static int setupWeather(lua_State* L);
};
}
