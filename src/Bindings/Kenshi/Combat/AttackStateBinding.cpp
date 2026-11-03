#include "pch.h"
#include "kenshi/combat/CombatState.h"
#include "AttackStateBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/CharacterBinding.h"

namespace KenshiLua
{

static_assert(offsetof(AttackState, techniqueIntegrityCheckTimer) == 0x18, "AttackState::techniqueIntegrityCheckTimer offset mismatch");

static AttackState* getInstance(lua_State* L, int idx)
{
    return checkObject<AttackState>(L, idx, AttackStateBinding::getMetatableName());
}

static int AttackState_get_techniqueIntegrityCheckTimer(lua_State* L)
{
    AttackState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackState is nil");
    lua_pushnumber(L, instance->techniqueIntegrityCheckTimer);
    return 1;
}

static int AttackState_set_techniqueIntegrityCheckTimer(lua_State* L)
{
    AttackState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackState is nil");
    instance->techniqueIntegrityCheckTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

int AttackStateBinding::validate(lua_State* L)
{
    AttackState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackState is nil");

    bool result = instance->validate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AttackStateBinding::_NV_validate(lua_State* L)
{
    AttackState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackState is nil");

    bool result = instance->_NV_validate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AttackStateBinding::initialiseAttack(lua_State* L)
{
    AttackState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackState is nil");

    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->initialiseAttack(target);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AttackStateBinding::initialise(lua_State* L)
{
    AttackState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackState is nil");

    bool result = instance->initialise();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AttackStateBinding::_NV_initialise(lua_State* L)
{
    AttackState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackState is nil");

    bool result = instance->_NV_initialise();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AttackStateBinding::update(lua_State* L)
{
    AttackState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackState is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->update(time);
    return 0;
}

int AttackStateBinding::_NV_update(lua_State* L)
{
    AttackState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackState is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->_NV_update(time);
    return 0;
}

int AttackStateBinding::end(lua_State* L)
{
    AttackState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackState is nil");

    instance->end();
    return 0;
}

int AttackStateBinding::_NV_end(lua_State* L)
{
    AttackState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackState is nil");

    instance->_NV_end();
    return 0;
}

int AttackStateBinding::gc(lua_State* L)
{
    return 0;
}

int AttackStateBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AttackState object");
    return 1;
}

void AttackStateBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AttackStateBinding::gc },
        { "__tostring", AttackStateBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "validate",           AttackStateBinding::validate },
        { "_NV_validate",       AttackStateBinding::_NV_validate },
        { "initialiseAttack",   AttackStateBinding::initialiseAttack },
        { "initialise",         AttackStateBinding::initialise },
        { "_NV_initialise",     AttackStateBinding::_NV_initialise },
        { "update",             AttackStateBinding::update },
        { "_NV_update",         AttackStateBinding::_NV_update },
        { "end",                AttackStateBinding::end },
        { "_NV_end",            AttackStateBinding::_NV_end },
        { 0, 0 }
    };

    registerClass(
        L,
        AttackStateBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AttackStateBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "techniqueIntegrityCheckTimer", AttackState_get_techniqueIntegrityCheckTimer);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "techniqueIntegrityCheckTimer", AttackState_set_techniqueIntegrityCheckTimer);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);
}

} // namespace KenshiLua
