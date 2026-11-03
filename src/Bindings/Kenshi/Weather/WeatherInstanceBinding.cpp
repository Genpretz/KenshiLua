#include "pch.h"
#include "kenshi/Weather.h"
#include "WeatherInstanceBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Weather/WeatherRegionBinding.h"
#include "Bindings/Kenshi/Weather/WeatherBinding.h"

namespace KenshiLua
{

static_assert(offsetof(WeatherInstance, weather) == 0x8, "WeatherInstance::weather offset does not match the game");
static_assert(offsetof(WeatherInstance, windDirection) == 0x1C, "WeatherInstance::windDirection offset does not match the game");
static_assert(offsetof(WeatherInstance, weatherTime) == 0x50, "WeatherInstance::weatherTime offset does not match the game");

static WeatherInstance* getInstance(lua_State* L, int idx)
{
    return checkObject<WeatherInstance>(L, idx, WeatherInstanceBinding::getMetatableName());
}

// The constructor leaves weather null until setupWeather or load assigns one, and
// getFog*, getWetness, and update read it without a null check.
static WeatherInstance* getInstanceWithWeather(lua_State* L, const char* method)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (instance && !instance->weather)
        luaL_error(L, "WeatherInstance:%s: no Weather assigned yet", method);
    return instance;
}

// --- Getters for WeatherInstance ---
static int WeatherInstance_get_regionWeather(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    return pushObject<WeatherRegion>(L, instance->regionWeather, WeatherRegionBinding::getMetatableName());
}

static int WeatherInstance_get_weather(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    return pushObject<Weather>(L, instance->weather, WeatherBinding::getMetatableName());
}

static int WeatherInstance_get_effectStrength(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    lua_pushnumber(L, instance->effectStrength);
    return 1;
}

static int WeatherInstance_get_strength(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    lua_pushnumber(L, instance->strength);
    return 1;
}

static int WeatherInstance_get_windSpeed(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    lua_pushnumber(L, instance->windSpeed);
    return 1;
}

static int WeatherInstance_get_windDirection(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    pushVector3(L, instance->windDirection);
    return 1;
}

static int WeatherInstance_get_windBuildUpEnded(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    lua_pushboolean(L, instance->windBuildUpEnded ? 1 : 0);
    return 1;
}

static int WeatherInstance_get_windBuildUpStart(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    lua_pushinteger(L, instance->windBuildUpStart);
    return 1;
}

static int WeatherInstance_get_windBuildUpEnd(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    lua_pushinteger(L, instance->windBuildUpEnd);
    return 1;
}

static int WeatherInstance_get_windBuildUpSpeedStart(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    lua_pushnumber(L, instance->windBuildUpSpeedStart);
    return 1;
}

static int WeatherInstance_get_windBuildUpSpeedEnd(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    lua_pushnumber(L, instance->windBuildUpSpeedEnd);
    return 1;
}

static int WeatherInstance_get_windBuildUpAngleStart(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    lua_pushnumber(L, instance->windBuildUpAngleStart);
    return 1;
}

static int WeatherInstance_get_windBuildUpAngleEnd(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    lua_pushnumber(L, instance->windBuildUpAngleEnd);
    return 1;
}

static int WeatherInstance_get_startTimeMinutes(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    lua_pushinteger(L, instance->startTimeMinutes);
    return 1;
}

static int WeatherInstance_get_endTimeMinutes(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    lua_pushinteger(L, instance->endTimeMinutes);
    return 1;
}

static int WeatherInstance_get_updateTimeWindMinutes(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    lua_pushinteger(L, instance->updateTimeWindMinutes);
    return 1;
}

static int WeatherInstance_get_weatherTime(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    lua_pushnumber(L, instance->weatherTime);
    return 1;
}

// --- Setters for WeatherInstance ---
// setupWeather asks regionWeather for a strength without a null check.
static int WeatherInstance_set_regionWeather(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->regionWeather = checkObject<WeatherRegion>(L, 2, WeatherRegionBinding::getMetatableName());
    return 0;
}

// WeatherSystem::updateMT reads the active instance's weather without a null check.
static int WeatherInstance_set_weather(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->weather = checkObject<Weather>(L, 2, WeatherBinding::getMetatableName());
    return 0;
}

static int WeatherInstance_set_effectStrength(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->effectStrength = (float)luaL_checknumber(L, 2);
    return 0;
}

static int WeatherInstance_set_strength(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->strength = (float)luaL_checknumber(L, 2);
    return 0;
}

static int WeatherInstance_set_windSpeed(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->windSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int WeatherInstance_set_windDirection(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    if (!readVector3(L, 2, instance->windDirection)) return luaL_argerror(L, 2, "Vector3 table expected");
    return 0;
}

static int WeatherInstance_set_windBuildUpEnded(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->windBuildUpEnded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int WeatherInstance_set_windBuildUpStart(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->windBuildUpStart = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int WeatherInstance_set_windBuildUpEnd(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->windBuildUpEnd = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int WeatherInstance_set_windBuildUpSpeedStart(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->windBuildUpSpeedStart = (float)luaL_checknumber(L, 2);
    return 0;
}

static int WeatherInstance_set_windBuildUpSpeedEnd(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->windBuildUpSpeedEnd = (float)luaL_checknumber(L, 2);
    return 0;
}

static int WeatherInstance_set_windBuildUpAngleStart(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->windBuildUpAngleStart = (float)luaL_checknumber(L, 2);
    return 0;
}

static int WeatherInstance_set_windBuildUpAngleEnd(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->windBuildUpAngleEnd = (float)luaL_checknumber(L, 2);
    return 0;
}

static int WeatherInstance_set_startTimeMinutes(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->startTimeMinutes = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int WeatherInstance_set_endTimeMinutes(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->endTimeMinutes = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int WeatherInstance_set_updateTimeWindMinutes(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->updateTimeWindMinutes = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int WeatherInstance_set_weatherTime(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");
    instance->weatherTime = (float)luaL_checknumber(L, 2);
    return 0;
}

int WeatherInstanceBinding::getTime(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    lua_pushnumber(L, instance->getTime());
    return 1;
}

int WeatherInstanceBinding::getTimeNormalized(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    lua_pushnumber(L, instance->getTimeNormalized());
    return 1;
}

int WeatherInstanceBinding::getWeatherBiome(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    WeatherRegion* result = instance->getWeatherBiome();
    return pushObject<WeatherRegion>(L, result, WeatherRegionBinding::getMetatableName());
}

int WeatherInstanceBinding::getWeather(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    Weather* result = instance->getWeather();
    return pushObject<Weather>(L, result, WeatherBinding::getMetatableName());
}

int WeatherInstanceBinding::update(lua_State* L)
{
    WeatherInstance* instance = getInstanceWithWeather(L, "update");
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    lua_pushboolean(L, instance->update() ? 1 : 0);
    return 1;
}

int WeatherInstanceBinding::getHasEnded(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    lua_pushboolean(L, instance->getHasEnded() ? 1 : 0);
    return 1;
}

int WeatherInstanceBinding::getFogVisible(lua_State* L)
{
    WeatherInstance* instance = getInstanceWithWeather(L, "getFogVisible");
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    lua_pushboolean(L, instance->getFogVisible() ? 1 : 0);
    return 1;
}

int WeatherInstanceBinding::getFogDistance(lua_State* L)
{
    WeatherInstance* instance = getInstanceWithWeather(L, "getFogDistance");
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    lua_pushnumber(L, instance->getFogDistance());
    return 1;
}

int WeatherInstanceBinding::getFogColour(lua_State* L)
{
    WeatherInstance* instance = getInstanceWithWeather(L, "getFogColour");
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    pushColourValue(L, instance->getFogColour());
    return 1;
}

int WeatherInstanceBinding::getFogEnabled(lua_State* L)
{
    WeatherInstance* instance = getInstanceWithWeather(L, "getFogEnabled");
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    lua_pushboolean(L, instance->getFogEnabled() ? 1 : 0);
    return 1;
}

int WeatherInstanceBinding::getGlobalEffectsStrength(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    lua_pushnumber(L, instance->getGlobalEffectsStrength());
    return 1;
}

int WeatherInstanceBinding::getWindSpeed(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    lua_pushnumber(L, instance->getWindSpeed());
    return 1;
}

int WeatherInstanceBinding::getWindDirection(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    pushVector3(L, instance->getWindDirection());
    return 1;
}

int WeatherInstanceBinding::getWindForce(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    Ogre::Vector3 result = instance->getWindForce();
    pushVector3(L, result);
    return 1;
}

int WeatherInstanceBinding::getWetness(lua_State* L)
{
    WeatherInstance* instance = getInstanceWithWeather(L, "getWetness");
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    lua_pushnumber(L, instance->getWetness());
    return 1;
}

int WeatherInstanceBinding::getWeatherStrength(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    lua_pushnumber(L, instance->getWeatherStrength());
    return 1;
}

int WeatherInstanceBinding::save(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    std::string key = luaL_checkstring(L, 3);
    instance->save(data, key);
    return 0;
}

int WeatherInstanceBinding::load(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Weather* newWeather = checkObject<Weather>(L, 3, WeatherBinding::getMetatableName());
    std::string key = luaL_checkstring(L, 4);
    instance->load(data, newWeather, key);
    return 0;
}

int WeatherInstanceBinding::setupWeather(lua_State* L)
{
    WeatherInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherInstance is nil");

    Weather* newWeather = checkObject<Weather>(L, 2, WeatherBinding::getMetatableName());
    instance->setupWeather(newWeather);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 18: WeatherInstance(WeatherRegion* region) - constructor; WeatherRegion creates its instance
  line 20: ~WeatherInstance() - destructor; ~WeatherRegion deletes its instance
*/

int WeatherInstanceBinding::gc(lua_State* L)
{
    // Borrowed from the owning WeatherRegion
    return 0;
}

int WeatherInstanceBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.WeatherInstance object");
    return 1;
}

void WeatherInstanceBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WeatherInstanceBinding::gc },
        { "__tostring", WeatherInstanceBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getTime", WeatherInstanceBinding::getTime },
        { "getTimeNormalized", WeatherInstanceBinding::getTimeNormalized },
        { "getWeatherBiome", WeatherInstanceBinding::getWeatherBiome },
        { "getWeather", WeatherInstanceBinding::getWeather },
        { "update", WeatherInstanceBinding::update },
        { "getHasEnded", WeatherInstanceBinding::getHasEnded },
        { "getFogVisible", WeatherInstanceBinding::getFogVisible },
        { "getFogDistance", WeatherInstanceBinding::getFogDistance },
        { "getFogColour", WeatherInstanceBinding::getFogColour },
        { "getFogEnabled", WeatherInstanceBinding::getFogEnabled },
        { "getGlobalEffectsStrength", WeatherInstanceBinding::getGlobalEffectsStrength },
        { "getWindSpeed", WeatherInstanceBinding::getWindSpeed },
        { "getWindDirection", WeatherInstanceBinding::getWindDirection },
        { "getWindForce", WeatherInstanceBinding::getWindForce },
        { "getWetness", WeatherInstanceBinding::getWetness },
        { "getWeatherStrength", WeatherInstanceBinding::getWeatherStrength },
        { "save", WeatherInstanceBinding::save },
        { "load", WeatherInstanceBinding::load },
        { "setupWeather", WeatherInstanceBinding::setupWeather },
        { 0, 0 }
    };

    registerClass(
        L,
        WeatherInstanceBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, WeatherInstanceBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "regionWeather", WeatherInstance_get_regionWeather);
    registerGetter(L, "weather", WeatherInstance_get_weather);
    registerGetter(L, "effectStrength", WeatherInstance_get_effectStrength);
    registerGetter(L, "strength", WeatherInstance_get_strength);
    registerGetter(L, "windSpeed", WeatherInstance_get_windSpeed);
    registerGetter(L, "windDirection", WeatherInstance_get_windDirection);
    registerGetter(L, "windBuildUpEnded", WeatherInstance_get_windBuildUpEnded);
    registerGetter(L, "windBuildUpStart", WeatherInstance_get_windBuildUpStart);
    registerGetter(L, "windBuildUpEnd", WeatherInstance_get_windBuildUpEnd);
    registerGetter(L, "windBuildUpSpeedStart", WeatherInstance_get_windBuildUpSpeedStart);
    registerGetter(L, "windBuildUpSpeedEnd", WeatherInstance_get_windBuildUpSpeedEnd);
    registerGetter(L, "windBuildUpAngleStart", WeatherInstance_get_windBuildUpAngleStart);
    registerGetter(L, "windBuildUpAngleEnd", WeatherInstance_get_windBuildUpAngleEnd);
    registerGetter(L, "startTimeMinutes", WeatherInstance_get_startTimeMinutes);
    registerGetter(L, "endTimeMinutes", WeatherInstance_get_endTimeMinutes);
    registerGetter(L, "updateTimeWindMinutes", WeatherInstance_get_updateTimeWindMinutes);
    registerGetter(L, "weatherTime", WeatherInstance_get_weatherTime);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "regionWeather", WeatherInstance_set_regionWeather);
    registerSetter(L, "weather", WeatherInstance_set_weather);
    registerSetter(L, "effectStrength", WeatherInstance_set_effectStrength);
    registerSetter(L, "strength", WeatherInstance_set_strength);
    registerSetter(L, "windSpeed", WeatherInstance_set_windSpeed);
    registerSetter(L, "windDirection", WeatherInstance_set_windDirection);
    registerSetter(L, "windBuildUpEnded", WeatherInstance_set_windBuildUpEnded);
    registerSetter(L, "windBuildUpStart", WeatherInstance_set_windBuildUpStart);
    registerSetter(L, "windBuildUpEnd", WeatherInstance_set_windBuildUpEnd);
    registerSetter(L, "windBuildUpSpeedStart", WeatherInstance_set_windBuildUpSpeedStart);
    registerSetter(L, "windBuildUpSpeedEnd", WeatherInstance_set_windBuildUpSpeedEnd);
    registerSetter(L, "windBuildUpAngleStart", WeatherInstance_set_windBuildUpAngleStart);
    registerSetter(L, "windBuildUpAngleEnd", WeatherInstance_set_windBuildUpAngleEnd);
    registerSetter(L, "startTimeMinutes", WeatherInstance_set_startTimeMinutes);
    registerSetter(L, "endTimeMinutes", WeatherInstance_set_endTimeMinutes);
    registerSetter(L, "updateTimeWindMinutes", WeatherInstance_set_updateTimeWindMinutes);
    registerSetter(L, "weatherTime", WeatherInstance_set_weatherTime);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
