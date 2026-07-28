#include "pch.h"
#include <kenshi/PhysicsCollection.h>
#include "StaticEntBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

typedef PhysicsCollection::StaticEnt StaticEnt;

static StaticEnt* getInstance(lua_State* L, int idx)
{
    return checkObject<StaticEnt>(L, idx, StaticEntBinding::getMetatableName());
}

// --- Getters for StaticEnt ---
// --- Setters for StaticEnt ---
int StaticEntBinding::update(lua_State* L)
{
    StaticEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StaticEnt is nil");

    float spd = (float)luaL_checknumber(L, 2);
    instance->update(spd);
    return 0;
}

int StaticEntBinding::_NV_update(lua_State* L)
{
    StaticEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StaticEnt is nil");

    float spd = (float)luaL_checknumber(L, 2);
    instance->_NV_update(spd);
    return 0;
}

int StaticEntBinding::updateAim(lua_State* L)
{
    StaticEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StaticEnt is nil");

    float rotSpeed = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 target;
    readVector3(L, 3, target);
    float result = instance->updateAim(rotSpeed, target);
    lua_pushnumber(L, result);
    return 1;
}

int StaticEntBinding::_NV_updateAim(lua_State* L)
{
    StaticEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StaticEnt is nil");

    float rotSpeed = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 target;
    readVector3(L, 3, target);
    float result = instance->_NV_updateAim(rotSpeed, target);
    lua_pushnumber(L, result);
    return 1;
}

int StaticEntBinding::isRotatingEnt(lua_State* L)
{
    StaticEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StaticEnt is nil");

    bool result = instance->isRotatingEnt();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StaticEntBinding::_NV_isRotatingEnt(lua_State* L)
{
    StaticEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StaticEnt is nil");

    bool result = instance->_NV_isRotatingEnt();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StaticEntBinding::_DESTRUCTOR(lua_State* L)
{
    StaticEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StaticEnt is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 118: StaticEnt* _CONSTRUCTOR(...) - unsupported arg type
*/

int StaticEntBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int StaticEntBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.StaticEnt object");
    return 1;
}

void StaticEntBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       StaticEntBinding::gc },
        { "__tostring", StaticEntBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", StaticEntBinding::update },
        { "_NV_update", StaticEntBinding::_NV_update },
        { "updateAim", StaticEntBinding::updateAim },
        { "_NV_updateAim", StaticEntBinding::_NV_updateAim },
        { "isRotatingEnt", StaticEntBinding::isRotatingEnt },
        { "_NV_isRotatingEnt", StaticEntBinding::_NV_isRotatingEnt },
        { "_DESTRUCTOR", StaticEntBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        StaticEntBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, StaticEntBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to PhysicalEntity
    // setMetatableParent(L, StaticEntBinding::getMetatableName(), PhysicalEntityBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua