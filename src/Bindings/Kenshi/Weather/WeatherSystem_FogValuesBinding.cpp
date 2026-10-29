#include "pch.h"
#include "kenshi/Weather.h"
#include "WeatherSystem_FogValuesBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(sizeof(WeatherSystem::FogValues) == 0x18, "WeatherSystem::FogValues size does not match the game");

static WeatherSystem::FogValues* getInstance(lua_State* L, int idx)
{
    return checkObject<WeatherSystem::FogValues>(L, idx, WeatherSystem_FogValuesBinding::getMetatableName());
}

// --- Getters for WeatherSystem::FogValues ---
static int FogValues_get_alpha(lua_State* L)
{
    WeatherSystem::FogValues* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_FogValues is nil");
    lua_pushnumber(L, instance->alpha);
    return 1;
}

static int FogValues_get_distance(lua_State* L)
{
    WeatherSystem::FogValues* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_FogValues is nil");
    lua_pushnumber(L, instance->distance);
    return 1;
}

static int FogValues_get_colour(lua_State* L)
{
    WeatherSystem::FogValues* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_FogValues is nil");
    pushColourValue(L, instance->colour);
    return 1;
}

// --- Setters for WeatherSystem::FogValues ---
static int FogValues_set_alpha(lua_State* L)
{
    WeatherSystem::FogValues* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_FogValues is nil");
    instance->alpha = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FogValues_set_distance(lua_State* L)
{
    WeatherSystem::FogValues* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_FogValues is nil");
    instance->distance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FogValues_set_colour(lua_State* L)
{
    WeatherSystem::FogValues* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem_FogValues is nil");
    if (!readColourValue(L, 2, instance->colour)) return luaL_argerror(L, 2, "ColourValue table expected");
    return 0;
}

/*
Skipped methods needing manual binding:
  line 221: FogValues() - constructor; values come from WeatherSystem and ZoneFog
  line 226: lerp(...) - static member of a nested type; KenshiLua has no class-table convention for nested-type statics
*/

int WeatherSystem_FogValuesBinding::gc(lua_State* L)
{
    // Borrowed from WeatherSystem or ZoneFog; copies from getCurrentValues use the owned metatable's __gc
    return 0;
}

int WeatherSystem_FogValuesBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.WeatherSystem_FogValues object");
    return 1;
}

void WeatherSystem_FogValuesBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WeatherSystem_FogValuesBinding::gc },
        { "__tostring", WeatherSystem_FogValuesBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L,
        WeatherSystem_FogValuesBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, WeatherSystem_FogValuesBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "alpha", FogValues_get_alpha);
    registerGetter(L, "distance", FogValues_get_distance);
    registerGetter(L, "colour", FogValues_get_colour);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "alpha", FogValues_set_alpha);
    registerSetter(L, "distance", FogValues_set_distance);
    registerSetter(L, "colour", FogValues_set_colour);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
