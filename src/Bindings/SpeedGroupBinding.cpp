#include "pch.h"
#include "kenshi\CharMovement.h"
#include "SpeedGroupBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"

namespace KenshiLua
{

static SpeedGroup* getInstance(lua_State* L, int idx)
{
    return checkObject<SpeedGroup>(L, idx, SpeedGroupBinding::getMetatableName());
}

// --- Getters for SpeedGroup ---
static int SpeedGroup_get_position(lua_State* L)
{
    SpeedGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpeedGroup is nil");
    pushVector3(L, instance->position);
    return 1;
}

static int SpeedGroup_get_direction(lua_State* L)
{
    SpeedGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpeedGroup is nil");
    pushVector3(L, instance->direction);
    return 1;
}

static int SpeedGroup_get_speed(lua_State* L)
{
    SpeedGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpeedGroup is nil");
    lua_pushnumber(L, instance->speed);
    return 1;
}

static int SpeedGroup_get_last(lua_State* L)
{
    SpeedGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpeedGroup is nil");
    lua_pushinteger(L, instance->last);
    return 1;
}

// --- Setters for SpeedGroup ---
static int SpeedGroup_set_position(lua_State* L)
{
    SpeedGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpeedGroup is nil");
    readVector3(L, 2, instance->position);
    return 0;
}

static int SpeedGroup_set_direction(lua_State* L)
{
    SpeedGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpeedGroup is nil");
    readVector3(L, 2, instance->direction);
    return 0;
}

static int SpeedGroup_set_speed(lua_State* L)
{
    SpeedGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpeedGroup is nil");
    instance->speed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SpeedGroup_set_last(lua_State* L)
{
    SpeedGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpeedGroup is nil");
    instance->last = (unsigned long)luaL_checkinteger(L, 2);
    return 0;
}

int SpeedGroupBinding::_CONSTRUCTOR(lua_State* L)
{
    SpeedGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpeedGroup is nil");

    SpeedGroup* result = instance->_CONSTRUCTOR();
    return pushObject<SpeedGroup>(L, result, SpeedGroupBinding::getMetatableName());
}

int SpeedGroupBinding::getSpeed(lua_State* L)
{
    SpeedGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpeedGroup is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float result = instance->getSpeed(who);
    lua_pushnumber(L, result);
    return 1;
}

int SpeedGroupBinding::_DESTRUCTOR(lua_State* L)
{
    SpeedGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpeedGroup is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 68: void insert(...) - non-string reference arg
  line 69: void erase(...) - non-string reference arg
*/

/*
Skipped properties needing manual binding:
  line 71: members (ogre_unordered_set<hand>::type) - unsupported type
*/

int SpeedGroupBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SpeedGroupBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SpeedGroup object");
    return 1;
}

void SpeedGroupBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SpeedGroupBinding::gc },
        { "__tostring", SpeedGroupBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", SpeedGroupBinding::_CONSTRUCTOR },
        { "getSpeed", SpeedGroupBinding::getSpeed },
        { "_DESTRUCTOR", SpeedGroupBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        SpeedGroupBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SpeedGroupBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "position", SpeedGroup_get_position);
    registerGetter(L, "direction", SpeedGroup_get_direction);
    registerGetter(L, "speed", SpeedGroup_get_speed);
    registerGetter(L, "last", SpeedGroup_get_last);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "position", SpeedGroup_set_position);
    registerSetter(L, "direction", SpeedGroup_set_direction);
    registerSetter(L, "speed", SpeedGroup_set_speed);
    registerSetter(L, "last", SpeedGroup_set_last);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua