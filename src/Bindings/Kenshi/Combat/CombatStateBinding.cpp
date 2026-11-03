#include "pch.h"
#include "kenshi/combat/CombatState.h"
#include "CombatStateBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Combat/CombatClassBinding.h"

namespace KenshiLua
{

static_assert(offsetof(CombatState, combat) == 0x8, "CombatState::combat offset mismatch");
static_assert(offsetof(CombatState, stateTimer) == 0x10, "CombatState::stateTimer offset mismatch");

static CombatState* getInstance(lua_State* L, int idx)
{
    return checkObject<CombatState>(L, idx, CombatStateBinding::getMetatableName());
}

static int CombatState_get_combat(lua_State* L)
{
    CombatState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatState is nil");
    if (!instance->combat) { lua_pushnil(L); return 1; }
    return pushObject<CombatClass>(L, instance->combat, CombatClassBinding::getMetatableName());
}

static int CombatState_set_combat(lua_State* L)
{
    CombatState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatState is nil");
    instance->combat = lua_isnoneornil(L, 2) ? nullptr : checkObject<CombatClass>(L, 2, CombatClassBinding::getMetatableName());
    return 0;
}

static int CombatState_get_stateTimer(lua_State* L)
{
    CombatState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatState is nil");
    lua_pushnumber(L, instance->stateTimer);
    return 1;
}

static int CombatState_set_stateTimer(lua_State* L)
{
    CombatState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatState is nil");
    instance->stateTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

int CombatStateBinding::validate(lua_State* L)
{
    CombatState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatState is nil");

    bool result = instance->validate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatStateBinding::initialise(lua_State* L)
{
    CombatState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatState is nil");

    bool result = instance->initialise();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatStateBinding::update(lua_State* L)
{
    CombatState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatState is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->update(time);
    return 0;
}

int CombatStateBinding::end(lua_State* L)
{
    CombatState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatState is nil");

    instance->end();
    return 0;
}

int CombatStateBinding::gc(lua_State* L)
{
    return 0;
}

int CombatStateBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CombatState object");
    return 1;
}

void CombatStateBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CombatStateBinding::gc },
        { "__tostring", CombatStateBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "validate",   CombatStateBinding::validate },
        { "initialise", CombatStateBinding::initialise },
        { "update",     CombatStateBinding::update },
        { "end",        CombatStateBinding::end },
        { 0, 0 }
    };

    registerClass(
        L,
        CombatStateBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CombatStateBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "combat", CombatState_get_combat);
    registerGetter(L, "stateTimer", CombatState_get_stateTimer);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "combat", CombatState_set_combat);
    registerSetter(L, "stateTimer", CombatState_set_stateTimer);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);
}

} // namespace KenshiLua
