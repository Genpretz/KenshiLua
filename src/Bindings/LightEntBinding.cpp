#include "pch.h"
#include <kenshi/PhysicsCollection.h>
#include "LightEntBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

typedef PhysicsCollection::LightEnt LightEnt;

static LightEnt* getInstance(lua_State* L, int idx)
{
    return checkObject<LightEnt>(L, idx, LightEntBinding::getMetatableName());
}

// --- Getters for LightEnt ---
static int LightEnt_get_light(lua_State* L)
{
    LightEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightEnt is nil");
    lua_pushlightuserdata(L, (void*)instance->light);
    return 1;
}

static int LightEnt_get_brightness(lua_State* L)
{
    LightEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightEnt is nil");
    lua_pushnumber(L, instance->brightness);
    return 1;
}

static int LightEnt_get_range(lua_State* L)
{
    LightEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightEnt is nil");
    lua_pushnumber(L, instance->range);
    return 1;
}

// --- Setters for LightEnt ---
static int LightEnt_set_brightness(lua_State* L)
{
    LightEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightEnt is nil");
    instance->brightness = (float)luaL_checknumber(L, 2);
    return 0;
}

static int LightEnt_set_range(lua_State* L)
{
    LightEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightEnt is nil");
    instance->range = (float)luaL_checknumber(L, 2);
    return 0;
}

int LightEntBinding::setEnergyLevel(lua_State* L)
{
    LightEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightEnt is nil");

    float level = (float)luaL_checknumber(L, 2);
    instance->setEnergyLevel(level);
    return 0;
}

int LightEntBinding::setFloor(lua_State* L)
{
    LightEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightEnt is nil");

    int floor = (int)luaL_checkinteger(L, 2);
    instance->setFloor(floor);
    return 0;
}


/*
LIGHTUSERDATA DEPENDENCIES:
  - LightEnt_get_light: Ogre::Light* (unbound pointer)
*/

int LightEntBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int LightEntBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.LightEnt object");
    return 1;
}

void LightEntBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LightEntBinding::gc },
        { "__tostring", LightEntBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setEnergyLevel", LightEntBinding::setEnergyLevel },
        { "setFloor", LightEntBinding::setFloor },
        { 0, 0 }
    };

    registerClass(
        L, 
        LightEntBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, LightEntBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "light", LightEnt_get_light);
    registerGetter(L, "brightness", LightEnt_get_brightness);
    registerGetter(L, "range", LightEnt_get_range);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "brightness", LightEnt_set_brightness);
    registerSetter(L, "range", LightEnt_set_range);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua