#include "pch.h"
#include "kenshi/Weather.h"
#include "WeatherBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Weather/SeasonBinding.h"

namespace KenshiLua
{

static_assert(offsetof(Weather, windSpeedMin) == 0x30, "Weather::windSpeedMin offset does not match the game");
static_assert(offsetof(Weather, season) == 0xA8, "Weather::season offset does not match the game");

static Weather* getInstance(lua_State* L, int idx)
{
    return checkObject<Weather>(L, idx, WeatherBinding::getMetatableName());
}

// --- Getters for Weather ---
static int Weather_get_affectCharactersType(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushinteger(L, (lua_Integer)instance->affectCharactersType);
    return 1;
}

static int Weather_get_affectCharactersStrength(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->affectCharactersStrength);
    return 1;
}

static int Weather_get_weatherData(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    return pushObject<GameData>(L, instance->weatherData, GameDataBinding::getMetatableName());
}

static int Weather_get_windSpeedMin(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->windSpeedMin);
    return 1;
}

static int Weather_get_windSpeedMax(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->windSpeedMax);
    return 1;
}

static int Weather_get_windUpdateTime(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushinteger(L, instance->windUpdateTime);
    return 1;
}

static int Weather_get_windUpdateLimit(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushinteger(L, instance->windUpdateLimit);
    return 1;
}

static int Weather_get_fogEnabled(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushboolean(L, instance->fogEnabled ? 1 : 0);
    return 1;
}

static int Weather_get_fogDistanceMin(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->fogDistanceMin);
    return 1;
}

static int Weather_get_fogDistanceMax(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->fogDistanceMax);
    return 1;
}

static int Weather_get_fogWindSpeedMin(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->fogWindSpeedMin);
    return 1;
}

static int Weather_get_fogWindSpeedMax(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->fogWindSpeedMax);
    return 1;
}

static int Weather_get_fogColor(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    pushColourValue(L, instance->fogColor);
    return 1;
}

static int Weather_get_cloudsDensity(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->cloudsDensity);
    return 1;
}

static int Weather_get_cloudsColor(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    pushColourValue(L, instance->cloudsColor);
    return 1;
}

static int Weather_get_probabilityOccurrence(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->probabilityOccurrence);
    return 1;
}

static int Weather_get_conditionStart(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->conditionStart);
    return 1;
}

static int Weather_get_conditionEnd(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->conditionEnd);
    return 1;
}

static int Weather_get_durationMin(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushinteger(L, instance->durationMin);
    return 1;
}

static int Weather_get_durationMax(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushinteger(L, instance->durationMax);
    return 1;
}

static int Weather_get_rainSound(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->rainSound);
    return 1;
}

static int Weather_get_windSound(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->windSound);
    return 1;
}

static int Weather_get_wetness(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->wetness);
    return 1;
}

static int Weather_get_dust(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->dust);
    return 1;
}

static int Weather_get_dustInside(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->dustInside);
    return 1;
}

static int Weather_get_dustSticky(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->dustSticky);
    return 1;
}

static int Weather_get_heatHaze(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    lua_pushnumber(L, instance->heatHaze);
    return 1;
}

static int Weather_get_season(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    return pushObject<Season>(L, instance->season, SeasonBinding::getMetatableName());
}

// --- Setters for Weather ---
static int Weather_set_affectCharactersType(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->affectCharactersType = (WeatherAffecting)luaL_checkinteger(L, 2);
    return 0;
}

static int Weather_set_affectCharactersStrength(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->affectCharactersStrength = (float)luaL_checknumber(L, 2);
    return 0;
}

// getName reads weatherData's name without a null check.
static int Weather_set_weatherData(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->weatherData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int Weather_set_windSpeedMin(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->windSpeedMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_windSpeedMax(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->windSpeedMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_windUpdateTime(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->windUpdateTime = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Weather_set_windUpdateLimit(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->windUpdateLimit = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Weather_set_fogEnabled(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->fogEnabled = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Weather_set_fogDistanceMin(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->fogDistanceMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_fogDistanceMax(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->fogDistanceMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_fogWindSpeedMin(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->fogWindSpeedMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_fogWindSpeedMax(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->fogWindSpeedMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_fogColor(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    if (!readColourValue(L, 2, instance->fogColor)) return luaL_argerror(L, 2, "ColourValue table expected");
    return 0;
}

static int Weather_set_cloudsDensity(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->cloudsDensity = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_cloudsColor(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    if (!readColourValue(L, 2, instance->cloudsColor)) return luaL_argerror(L, 2, "ColourValue table expected");
    return 0;
}

static int Weather_set_probabilityOccurrence(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->probabilityOccurrence = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_conditionStart(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->conditionStart = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_conditionEnd(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->conditionEnd = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_durationMin(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->durationMin = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Weather_set_durationMax(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->durationMax = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Weather_set_rainSound(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->rainSound = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_windSound(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->windSound = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_wetness(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->wetness = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_dust(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->dust = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_dustInside(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->dustInside = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_dustSticky(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->dustSticky = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weather_set_heatHaze(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->heatHaze = (float)luaL_checknumber(L, 2);
    return 0;
}

// Weathers are created for and deleted by their season.
static int Weather_set_season(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");
    instance->season = checkObject<Season>(L, 2, SeasonBinding::getMetatableName());
    return 0;
}

int WeatherBinding::getName(lua_State* L)
{
    Weather* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weather is nil");

    lua_pushstring(L, instance->getName().c_str());
    return 1;
}

/*
Skipped methods needing manual binding:
  line 153: Weather(GameData* data, Season* season, ...) - constructor; Season creates its weathers
  line 155: ~Weather() - destructor; ~Season deletes its weathers

Skipped properties needing manual binding:
  line 161: effects (std::vector<std::pair<GameData*, TripleInt>, Ogre::STLAllocator<...> >) - no container binding for this vector
*/

int WeatherBinding::gc(lua_State* L)
{
    // Borrowed from the owning Season
    return 0;
}

int WeatherBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Weather object");
    return 1;
}

void WeatherBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WeatherBinding::gc },
        { "__tostring", WeatherBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getName", WeatherBinding::getName },
        { 0, 0 }
    };

    registerClass(
        L,
        WeatherBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, WeatherBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "affectCharactersType", Weather_get_affectCharactersType);
    registerGetter(L, "affectCharactersStrength", Weather_get_affectCharactersStrength);
    registerGetter(L, "weatherData", Weather_get_weatherData);
    registerGetter(L, "windSpeedMin", Weather_get_windSpeedMin);
    registerGetter(L, "windSpeedMax", Weather_get_windSpeedMax);
    registerGetter(L, "windUpdateTime", Weather_get_windUpdateTime);
    registerGetter(L, "windUpdateLimit", Weather_get_windUpdateLimit);
    registerGetter(L, "fogEnabled", Weather_get_fogEnabled);
    registerGetter(L, "fogDistanceMin", Weather_get_fogDistanceMin);
    registerGetter(L, "fogDistanceMax", Weather_get_fogDistanceMax);
    registerGetter(L, "fogWindSpeedMin", Weather_get_fogWindSpeedMin);
    registerGetter(L, "fogWindSpeedMax", Weather_get_fogWindSpeedMax);
    registerGetter(L, "fogColor", Weather_get_fogColor);
    registerGetter(L, "cloudsDensity", Weather_get_cloudsDensity);
    registerGetter(L, "cloudsColor", Weather_get_cloudsColor);
    registerGetter(L, "probabilityOccurrence", Weather_get_probabilityOccurrence);
    registerGetter(L, "conditionStart", Weather_get_conditionStart);
    registerGetter(L, "conditionEnd", Weather_get_conditionEnd);
    registerGetter(L, "durationMin", Weather_get_durationMin);
    registerGetter(L, "durationMax", Weather_get_durationMax);
    registerGetter(L, "rainSound", Weather_get_rainSound);
    registerGetter(L, "windSound", Weather_get_windSound);
    registerGetter(L, "wetness", Weather_get_wetness);
    registerGetter(L, "dust", Weather_get_dust);
    registerGetter(L, "dustInside", Weather_get_dustInside);
    registerGetter(L, "dustSticky", Weather_get_dustSticky);
    registerGetter(L, "heatHaze", Weather_get_heatHaze);
    registerGetter(L, "season", Weather_get_season);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "affectCharactersType", Weather_set_affectCharactersType);
    registerSetter(L, "affectCharactersStrength", Weather_set_affectCharactersStrength);
    registerSetter(L, "weatherData", Weather_set_weatherData);
    registerSetter(L, "windSpeedMin", Weather_set_windSpeedMin);
    registerSetter(L, "windSpeedMax", Weather_set_windSpeedMax);
    registerSetter(L, "windUpdateTime", Weather_set_windUpdateTime);
    registerSetter(L, "windUpdateLimit", Weather_set_windUpdateLimit);
    registerSetter(L, "fogEnabled", Weather_set_fogEnabled);
    registerSetter(L, "fogDistanceMin", Weather_set_fogDistanceMin);
    registerSetter(L, "fogDistanceMax", Weather_set_fogDistanceMax);
    registerSetter(L, "fogWindSpeedMin", Weather_set_fogWindSpeedMin);
    registerSetter(L, "fogWindSpeedMax", Weather_set_fogWindSpeedMax);
    registerSetter(L, "fogColor", Weather_set_fogColor);
    registerSetter(L, "cloudsDensity", Weather_set_cloudsDensity);
    registerSetter(L, "cloudsColor", Weather_set_cloudsColor);
    registerSetter(L, "probabilityOccurrence", Weather_set_probabilityOccurrence);
    registerSetter(L, "conditionStart", Weather_set_conditionStart);
    registerSetter(L, "conditionEnd", Weather_set_conditionEnd);
    registerSetter(L, "durationMin", Weather_set_durationMin);
    registerSetter(L, "durationMax", Weather_set_durationMax);
    registerSetter(L, "rainSound", Weather_set_rainSound);
    registerSetter(L, "windSound", Weather_set_windSound);
    registerSetter(L, "wetness", Weather_set_wetness);
    registerSetter(L, "dust", Weather_set_dust);
    registerSetter(L, "dustInside", Weather_set_dustInside);
    registerSetter(L, "dustSticky", Weather_set_dustSticky);
    registerSetter(L, "heatHaze", Weather_set_heatHaze);
    registerSetter(L, "season", Weather_set_season);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
