#pragma once

#include "kenshi/PhysicsCollection.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class WeatherRegionBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.WeatherRegion"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int reset(lua_State* L);
    static int getWeatherInstance(lua_State* L);
    static int setCurrentSeason(lua_State* L);
    static int getNewWeatherStrength(lua_State* L);
    static int update(lua_State* L);
    static int updateBT(lua_State* L);
    static int addListener(lua_State* L);
    static int removeListener(lua_State* L);
    static int addGlobalEffect(lua_State* L);
    static int getNewSeason(lua_State* L);
    static int weatherChanged(lua_State* L);
    static int updateWeatherEffects(lua_State* L);
    static int save(lua_State* L);
    static int load(lua_State* L);
};
}