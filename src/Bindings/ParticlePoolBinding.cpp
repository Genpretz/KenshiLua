#include "pch.h"
#include <kenshi/ZoneManager.h>
#include "ParticlePoolBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ParticlePool* getInstance(lua_State* L, int idx)
{
    return checkObject<ParticlePool>(L, idx, ParticlePoolBinding::getMetatableName());
}

// --- Getters for ParticlePool ---
static int ParticlePool_get_limit(lua_State* L)
{
    ParticlePool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ParticlePool is nil");
    lua_pushinteger(L, instance->limit);
    return 1;
}

static int ParticlePool_get_lastIndex(lua_State* L)
{
    ParticlePool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ParticlePool is nil");
    lua_pushinteger(L, instance->lastIndex);
    return 1;
}

static int ParticlePool_get_particles(lua_State* L)
{
    ParticlePool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ParticlePool is nil");
    lua_pushlightuserdata(L, (void*)instance->particles);
    return 1;
}

static int ParticlePool_get_maxTTL(lua_State* L)
{
    ParticlePool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ParticlePool is nil");
    lua_pushnumber(L, instance->maxTTL);
    return 1;
}

// --- Setters for ParticlePool ---
static int ParticlePool_set_limit(lua_State* L)
{
    ParticlePool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ParticlePool is nil");
    instance->limit = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int ParticlePool_set_lastIndex(lua_State* L)
{
    ParticlePool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ParticlePool is nil");
    instance->lastIndex = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int ParticlePool_set_maxTTL(lua_State* L)
{
    ParticlePool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ParticlePool is nil");
    instance->maxTTL = (float)luaL_checknumber(L, 2);
    return 0;
}

int ParticlePoolBinding::_CONSTRUCTOR(lua_State* L)
{
    ParticlePool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ParticlePool is nil");

    int limit = (int)luaL_checkinteger(L, 2);
    float ttl = (float)luaL_checknumber(L, 3);
    ParticlePool* result = instance->_CONSTRUCTOR(limit, ttl);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ParticlePoolBinding::_DESTRUCTOR(lua_State* L)
{
    ParticlePool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ParticlePool is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ParticlePoolBinding::init(lua_State* L)
{
    ParticlePool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ParticlePool is nil");

    instance->init();
    return 0;
}

int ParticlePoolBinding::destroy(lua_State* L)
{
    ParticlePool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ParticlePool is nil");

    instance->destroy();
    return 0;
}

int ParticlePoolBinding::getSize(lua_State* L)
{
    ParticlePool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ParticlePool is nil");

    int result = instance->getSize();
    lua_pushinteger(L, result);
    return 1;
}

int ParticlePoolBinding::update(lua_State* L)
{
    ParticlePool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ParticlePool is nil");

    instance->update();
    return 0;
}

int ParticlePoolBinding::shiftParticles(lua_State* L)
{
    ParticlePool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ParticlePool is nil");

    Ogre::Vector3 shift;
    readVector3(L, 2, shift);
    instance->shiftParticles(shift);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 304: bool addParticle(...) - unsupported arg type
*/

int ParticlePoolBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ParticlePoolBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ParticlePool object");
    return 1;
}

void ParticlePoolBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ParticlePoolBinding::gc },
        { "__tostring", ParticlePoolBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ParticlePoolBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ParticlePoolBinding::_DESTRUCTOR },
        { "init", ParticlePoolBinding::init },
        { "destroy", ParticlePoolBinding::destroy },
        { "getSize", ParticlePoolBinding::getSize },
        { "update", ParticlePoolBinding::update },
        { "shiftParticles", ParticlePoolBinding::shiftParticles },
        { 0, 0 }
    };

    registerClass(
        L, 
        ParticlePoolBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ParticlePoolBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ParticlePool_get_limit);
    lua_setfield(L, -2, "limit");
    lua_pushcfunction(L, ParticlePool_get_lastIndex);
    lua_setfield(L, -2, "lastIndex");
    lua_pushcfunction(L, ParticlePool_get_particles);
    lua_setfield(L, -2, "particles");
    lua_pushcfunction(L, ParticlePool_get_maxTTL);
    lua_setfield(L, -2, "maxTTL");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ParticlePool_set_limit);
    lua_setfield(L, -2, "limit");
    lua_pushcfunction(L, ParticlePool_set_lastIndex);
    lua_setfield(L, -2, "lastIndex");
    lua_pushcfunction(L, ParticlePool_set_maxTTL);
    lua_setfield(L, -2, "maxTTL");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, ParticlePoolBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
