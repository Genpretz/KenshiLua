#include "pch.h"
#include <kenshi\Character.h>
#include "Bindings\CharacterBinding.h"
#include "Bindings\AttachedArrowManagerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
static Character::AttachedArrowManager* getInstance(lua_State* L, int idx)
{
    return checkObject<Character::AttachedArrowManager>(L, idx, AttachedArrowManagerBinding::getMetatableName());
}

// --- Getters for AttachedArrowManager ---
static int AttachedArrowManager_get_index(lua_State* L)
{
    Character::AttachedArrowManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttachedArrowManager is nil");
    lua_pushinteger(L, instance->index);
    return 1;
}

// --- Setters for AttachedArrowManager ---
static int AttachedArrowManager_set_index(lua_State* L)
{
    Character::AttachedArrowManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttachedArrowManager is nil");
    instance->index = (int)luaL_checkinteger(L, 2);
    return 0;
}

int AttachedArrowManagerBinding::_DESTRUCTOR(lua_State* L)
{
    Character::AttachedArrowManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttachedArrowManager is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int AttachedArrowManagerBinding::clearAll(lua_State* L)
{
    Character::AttachedArrowManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttachedArrowManager is nil");

    instance->clearAll();
    return 0;
}

int AttachedArrowManagerBinding::updateStart(lua_State* L)
{
    Character::AttachedArrowManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttachedArrowManager is nil");

    instance->updateStart();
    return 0;
}

int AttachedArrowManagerBinding::addArrow(lua_State* L)
{
    Character::AttachedArrowManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttachedArrowManager is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Ogre::Vector3 targ;
    readVector3(L, 3, targ);
    int color = (int)luaL_checkinteger(L, 4);
    instance->addArrow(pos, targ, color);
    return 0;
}

int AttachedArrowManagerBinding::updateEnd(lua_State* L)
{
    Character::AttachedArrowManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttachedArrowManager is nil");

    instance->updateEnd();
    return 0;
}

int AttachedArrowManagerBinding::_CONSTRUCTOR(lua_State* L)
{
    Character::AttachedArrowManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttachedArrowManager is nil");

    Character::AttachedArrowManager* result = instance->_CONSTRUCTOR();
    return pushObject<Character::AttachedArrowManager>(L, result, AttachedArrowManagerBinding::getMetatableName());
}

/*
Skipped properties needing manual binding:
  line 339: ents (lektor<Ogre::Entity*>) - unsupported type
*/

int AttachedArrowManagerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int AttachedArrowManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AttachedArrowManager object");
    return 1;
}

void AttachedArrowManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AttachedArrowManagerBinding::gc },
        { "__tostring", AttachedArrowManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", AttachedArrowManagerBinding::_DESTRUCTOR },
        { "clearAll", AttachedArrowManagerBinding::clearAll },
        { "updateStart", AttachedArrowManagerBinding::updateStart },
        { "addArrow", AttachedArrowManagerBinding::addArrow },
        { "updateEnd", AttachedArrowManagerBinding::updateEnd },
        { "_CONSTRUCTOR", AttachedArrowManagerBinding::_CONSTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        AttachedArrowManagerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AttachedArrowManagerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, AttachedArrowManager_get_index);
    lua_setfield(L, -2, "index");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, AttachedArrowManager_set_index);
    lua_setfield(L, -2, "index");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua