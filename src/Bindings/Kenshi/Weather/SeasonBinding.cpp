#include "pch.h"
#include "kenshi/Weather.h"
#include "SeasonBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Weather/WeatherRegionBinding.h"
#include "Bindings/Kenshi/Weather/WeatherBinding.h"

namespace KenshiLua
{

static_assert(offsetof(Season, hasConditionalWeather) == 0x20, "Season::hasConditionalWeather offset does not match the game");
static_assert(offsetof(Season, seasonData) == 0x40, "Season::seasonData offset does not match the game");

static Season* getInstance(lua_State* L, int idx)
{
    return checkObject<Season>(L, idx, SeasonBinding::getMetatableName());
}

// --- Getters for Season ---
static int Season_get_regionWeather(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    return pushObject<WeatherRegion>(L, instance->regionWeather, WeatherRegionBinding::getMetatableName());
}

// ~Season deletes these weathers, so the list is returned as a table and cannot be edited.
static int Season_get_weathers(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    lua_createtable(L, (int)instance->weathers.count, 0);
    for (uint32_t i = 0; i < instance->weathers.count; ++i)
    {
        pushObject<Weather>(L, instance->weathers.stuff[i], WeatherBinding::getMetatableName());
        lua_rawseti(L, -2, (int)i + 1);
    }
    return 1;
}

static int Season_get_hasConditionalWeather(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    lua_pushboolean(L, instance->hasConditionalWeather ? 1 : 0);
    return 1;
}

static int Season_get_durationInDays(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    lua_pushinteger(L, instance->durationInDays);
    return 1;
}

static int Season_get_weatherStrengthMin(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    lua_pushnumber(L, instance->weatherStrengthMin);
    return 1;
}

static int Season_get_weatherStrengthMax(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    lua_pushnumber(L, instance->weatherStrengthMax);
    return 1;
}

static int Season_get_sunlightColor(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    pushColourValue(L, instance->sunlightColor);
    return 1;
}

static int Season_get_seasonData(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    return pushObject<GameData>(L, instance->seasonData, GameDataBinding::getMetatableName());
}

// --- Setters for Season ---
// getNewWeather sets up regionWeather's instance without a null check.
static int Season_set_regionWeather(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    instance->regionWeather = checkObject<WeatherRegion>(L, 2, WeatherRegionBinding::getMetatableName());
    return 0;
}

static int Season_set_hasConditionalWeather(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    instance->hasConditionalWeather = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Season_set_durationInDays(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    instance->durationInDays = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Season_set_weatherStrengthMin(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    instance->weatherStrengthMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Season_set_weatherStrengthMax(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    instance->weatherStrengthMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Season_set_sunlightColor(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    if (!readColourValue(L, 2, instance->sunlightColor)) return luaL_argerror(L, 2, "ColourValue table expected");
    return 0;
}

// getName returns an empty name for null seasonData.
static int Season_set_seasonData(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");
    instance->seasonData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

int SeasonBinding::getName(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");

    lua_pushstring(L, instance->getName().c_str());
    return 1;
}

int SeasonBinding::getNewWeather(lua_State* L)
{
    Season* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Season is nil");

    // With no weathers this sets up a null Weather, which setupWeather dereferences.
    if (instance->weathers.count == 0) return luaL_error(L, "Season:getNewWeather: the season has no weathers");
    if (!instance->regionWeather || !instance->regionWeather->weatherInstance)
        return luaL_error(L, "Season:getNewWeather: the season's region has no WeatherInstance");

    instance->getNewWeather();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 129: Season(WeatherRegion* region, GameData* seasonData, int duration) - constructor; WeatherRegion creates its seasons
  line 131: ~Season() - destructor; ~WeatherRegion deletes its seasons
*/

int SeasonBinding::gc(lua_State* L)
{
    // Borrowed from the owning WeatherRegion
    return 0;
}

int SeasonBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Season object");
    return 1;
}

void SeasonBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SeasonBinding::gc },
        { "__tostring", SeasonBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getName", SeasonBinding::getName },
        { "getNewWeather", SeasonBinding::getNewWeather },
        { 0, 0 }
    };

    registerClass(
        L,
        SeasonBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SeasonBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "regionWeather", Season_get_regionWeather);
    registerGetter(L, "weathers", Season_get_weathers);
    registerGetter(L, "hasConditionalWeather", Season_get_hasConditionalWeather);
    registerGetter(L, "durationInDays", Season_get_durationInDays);
    registerGetter(L, "weatherStrengthMin", Season_get_weatherStrengthMin);
    registerGetter(L, "weatherStrengthMax", Season_get_weatherStrengthMax);
    registerGetter(L, "sunlightColor", Season_get_sunlightColor);
    registerGetter(L, "seasonData", Season_get_seasonData);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "regionWeather", Season_set_regionWeather);
    registerSetter(L, "hasConditionalWeather", Season_set_hasConditionalWeather);
    registerSetter(L, "durationInDays", Season_set_durationInDays);
    registerSetter(L, "weatherStrengthMin", Season_set_weatherStrengthMin);
    registerSetter(L, "weatherStrengthMax", Season_set_weatherStrengthMax);
    registerSetter(L, "sunlightColor", Season_set_sunlightColor);
    registerSetter(L, "seasonData", Season_set_seasonData);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
