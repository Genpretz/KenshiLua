#include "pch.h"
#include "kenshi\Character.h"
#include "AttachedArrowManagerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Character::AttachedArrowManager* getB(lua_State* L, int idx)
{
    return checkObject<Character::AttachedArrowManager>(L, idx, AttachedArrowManagerBinding::getMetatableName());
}

// --- Getters for AttachedArrowManager ---
static int AttachedArrowManager_get_ents(lua_State* L)
{
    Character::AttachedArrowManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "AttachedArrowManager is nil");
    // TODO: Unsupported type for ents (lektor<Ogre::Entity*>)
    return luaL_error(L, "Unsupported property 'ents' (type: lektor<Ogre::Entity*>)");
}

static int AttachedArrowManager_get_index(lua_State* L)
{
    Character::AttachedArrowManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "AttachedArrowManager is nil");
    lua_pushinteger(L, b->index);
    return 1;
}

// --- Setters for AttachedArrowManager ---
static int AttachedArrowManager_set_ents(lua_State* L)
{
    Character::AttachedArrowManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "AttachedArrowManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for ents");
}

static int AttachedArrowManager_set_index(lua_State* L)
{
    Character::AttachedArrowManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "AttachedArrowManager is nil");
    b->index = (int)luaL_checkinteger(L, 2);
    return 0;
}

// --- Methods for AttachedArrowManager ---
int AttachedArrowManagerBinding::_DESTRUCTOR(lua_State* L)
{
    Character::AttachedArrowManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "AttachedArrowManager is nil");

    b->_DESTRUCTOR();
    return 0;
}

int AttachedArrowManagerBinding::clearAll(lua_State* L)
{
    Character::AttachedArrowManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "AttachedArrowManager is nil");

    b->clearAll();
    return 0;
}

int AttachedArrowManagerBinding::updateStart(lua_State* L)
{
    Character::AttachedArrowManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "AttachedArrowManager is nil");

    b->updateStart();
    return 0;
}

int AttachedArrowManagerBinding::addArrow(lua_State* L)
{
    Character::AttachedArrowManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "AttachedArrowManager is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Ogre::Vector3 targ;
    readVector3(L, 3, targ);
    int color = (int)luaL_checkinteger(L, 4);
    b->addArrow(pos, targ, color);
    return 0;
}

int AttachedArrowManagerBinding::updateEnd(lua_State* L)
{
    Character::AttachedArrowManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "AttachedArrowManager is nil");

    b->updateEnd();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 343: AttachedArrowManager* _CONSTRUCTOR(...) - unsupported return type
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
    lua_pushcfunction(L, AttachedArrowManager_get_ents);
    lua_setfield(L, -2, "ents");
    lua_pushcfunction(L, AttachedArrowManager_get_index);
    lua_setfield(L, -2, "index");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, AttachedArrowManager_set_ents);
    lua_setfield(L, -2, "ents");
    lua_pushcfunction(L, AttachedArrowManager_set_index);
    lua_setfield(L, -2, "index");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua