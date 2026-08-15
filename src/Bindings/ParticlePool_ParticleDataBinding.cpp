#include "pch.h"
#include "Bindings/ParticlePool_ParticleDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include <kenshi/ZoneManager.h>

namespace KenshiLua
{

static ParticlePool::ParticleData* getInstance(lua_State* L, int idx)
{
    return checkObject<ParticlePool::ParticleData>(L, idx, ParticlePool_ParticleDataBinding::getMetatableName());
}

static int ParticleData_get_particle(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ParticlePool::ParticleData is nil");
    if (inst->particle) lua_pushlightuserdata(L, (void*)inst->particle);
    else lua_pushnil(L);
    return 1;
}

static int ParticleData_get_effectData(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ParticlePool::ParticleData is nil");
    return pushObject<GameData>(L, inst->effectData, GameDataBinding::getMetatableName());
}

static int ParticleData_get_node(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ParticlePool::ParticleData is nil");
    if (inst->node) lua_pushlightuserdata(L, (void*)inst->node);
    else lua_pushnil(L);
    return 1;
}

static int ParticleData_set_particle(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ParticlePool::ParticleData is nil");
    inst->particle = (ParticleSystemHandler*)lua_touserdata(L, 2);
    return 0;
}

static int ParticleData_set_effectData(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ParticlePool::ParticleData is nil");
    inst->effectData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int ParticleData_set_node(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ParticlePool::ParticleData is nil");
    inst->node = (Ogre::SceneNode*)lua_touserdata(L, 2);
    return 0;
}

int ParticlePool_ParticleDataBinding::gc(lua_State* L)
{
    return 0;
}

int ParticlePool_ParticleDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ParticlePool_ParticleData object");
    return 1;
}

int ParticlePool_ParticleDataBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void ParticlePool_ParticleDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "particle", ParticleData_get_particle);
    registerGetter(L, "effectData", ParticleData_get_effectData);
    registerGetter(L, "node", ParticleData_get_node);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "particle", ParticleData_set_particle);
    registerSetter(L, "effectData", ParticleData_set_effectData);
    registerSetter(L, "node", ParticleData_set_node);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
