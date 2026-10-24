#include "pch.h"
#include "kenshi/Weather.h"
#include "WeatherSystem_ZoneFogBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Weather/WeatherInstanceBinding.h"
#include "Bindings/Kenshi/Weather/WeatherSystem_FogValuesBinding.h"

namespace KenshiLua
{

// WeatherSystem::areaFog holds four of these, so indexing depends on the game's size.
static_assert(sizeof(WeatherSystem::ZoneFog) == 0x40, "WeatherSystem::ZoneFog size does not match the game");
static_assert(offsetof(WeatherSystem::ZoneFog, currFog) == 0x20, "WeatherSystem::ZoneFog::currFog offset does not match the game");

static WeatherSystem::ZoneFog* getInstance(lua_State* L, int idx)
{
    return checkObject<WeatherSystem::ZoneFog>(L, idx, WeatherSystem_ZoneFogBinding::getMetatableName());
}

// --- Getters for WeatherSystem::ZoneFog ---
static int ZoneFog_get_weatherInstance(lua_State* L)
{
    WeatherSystem::ZoneFog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_ZoneFog is nil");
    return pushObject<WeatherInstance>(L, instance->weatherInstance, WeatherInstanceBinding::getMetatableName());
}

static int ZoneFog_get_prevFog(lua_State* L)
{
    WeatherSystem::ZoneFog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_ZoneFog is nil");
    return pushObject<WeatherSystem::FogValues>(L, &instance->prevFog, WeatherSystem_FogValuesBinding::getMetatableName());
}

static int ZoneFog_get_currFog(lua_State* L)
{
    WeatherSystem::ZoneFog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_ZoneFog is nil");
    return pushObject<WeatherSystem::FogValues>(L, &instance->currFog, WeatherSystem_FogValuesBinding::getMetatableName());
}

static int ZoneFog_get_lastBlendValue(lua_State* L)
{
    WeatherSystem::ZoneFog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_ZoneFog is nil");
    lua_pushnumber(L, instance->lastBlendValue);
    return 1;
}

static int ZoneFog_get_blending(lua_State* L)
{
    WeatherSystem::ZoneFog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_ZoneFog is nil");
    lua_pushboolean(L, instance->blending ? 1 : 0);
    return 1;
}

// --- Setters for WeatherSystem::ZoneFog ---
// clear() stores null and update() skips a null instance, but update() reads the
// instance's Weather without a check, so an instance without one is rejected.
static int ZoneFog_set_weatherInstance(lua_State* L)
{
    WeatherSystem::ZoneFog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_ZoneFog is nil");
    if (lua_isnoneornil(L, 2))
    {
        instance->weatherInstance = nullptr;
        return 0;
    }
    WeatherInstance* weatherInstance = checkObject<WeatherInstance>(L, 2, WeatherInstanceBinding::getMetatableName());
    if (!weatherInstance->weather) return luaL_argerror(L, 2, "WeatherInstance has no Weather assigned yet");
    instance->weatherInstance = weatherInstance;
    return 0;
}

static int ZoneFog_set_prevFog(lua_State* L)
{
    WeatherSystem::ZoneFog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_ZoneFog is nil");
    instance->prevFog = *checkObject<WeatherSystem::FogValues>(L, 2, WeatherSystem_FogValuesBinding::getMetatableName());
    return 0;
}

static int ZoneFog_set_currFog(lua_State* L)
{
    WeatherSystem::ZoneFog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_ZoneFog is nil");
    instance->currFog = *checkObject<WeatherSystem::FogValues>(L, 2, WeatherSystem_FogValuesBinding::getMetatableName());
    return 0;
}

static int ZoneFog_set_lastBlendValue(lua_State* L)
{
    WeatherSystem::ZoneFog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_ZoneFog is nil");
    instance->lastBlendValue = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ZoneFog_set_blending(lua_State* L)
{
    WeatherSystem::ZoneFog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_ZoneFog is nil");
    instance->blending = lua_toboolean(L, 2) != 0;
    return 0;
}

int WeatherSystem_ZoneFogBinding::clear(lua_State* L)
{
    WeatherSystem::ZoneFog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_ZoneFog is nil");

    instance->clear();
    return 0;
}

int WeatherSystem_ZoneFogBinding::getCurrentValues(lua_State* L)
{
    WeatherSystem::ZoneFog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_ZoneFog is nil");

    WeatherSystem::FogValues result = instance->getCurrentValues();
    return pushValue<WeatherSystem::FogValues>(L, result, WeatherSystem_FogValuesBinding::getMetatableName());
}

int WeatherSystem_ZoneFogBinding::update(lua_State* L)
{
    WeatherSystem::ZoneFog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_ZoneFog is nil");
    if (instance->weatherInstance && !instance->weatherInstance->weather)
        return luaL_error(L, "WeatherSystem_ZoneFog:update: its WeatherInstance has no Weather assigned yet");

    instance->update();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 231: ZoneFog() - constructor; WeatherSystem owns its zone fogs
  line 234: set(AreaBiomeGroup* biome, const MainFog* fog) - AreaBiomeGroup and MainFog are unbound
*/

int WeatherSystem_ZoneFogBinding::gc(lua_State* L)
{
    // Borrowed from the WeatherSystem
    return 0;
}

int WeatherSystem_ZoneFogBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.WeatherSystem_ZoneFog object");
    return 1;
}

void WeatherSystem_ZoneFogBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WeatherSystem_ZoneFogBinding::gc },
        { "__tostring", WeatherSystem_ZoneFogBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "clear", WeatherSystem_ZoneFogBinding::clear },
        { "getCurrentValues", WeatherSystem_ZoneFogBinding::getCurrentValues },
        { "update", WeatherSystem_ZoneFogBinding::update },
        { 0, 0 }
    };

    registerClass(
        L,
        WeatherSystem_ZoneFogBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, WeatherSystem_ZoneFogBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "weatherInstance", ZoneFog_get_weatherInstance);
    registerGetter(L, "prevFog", ZoneFog_get_prevFog);
    registerGetter(L, "currFog", ZoneFog_get_currFog);
    registerGetter(L, "lastBlendValue", ZoneFog_get_lastBlendValue);
    registerGetter(L, "blending", ZoneFog_get_blending);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "weatherInstance", ZoneFog_set_weatherInstance);
    registerSetter(L, "prevFog", ZoneFog_set_prevFog);
    registerSetter(L, "currFog", ZoneFog_set_currFog);
    registerSetter(L, "lastBlendValue", ZoneFog_set_lastBlendValue);
    registerSetter(L, "blending", ZoneFog_set_blending);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
