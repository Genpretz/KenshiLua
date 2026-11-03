#include "pch.h"
#include "kenshi/combat/CombatState.h"
#include "WaitingStateAIBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(WaitingStateAI, circlingDirection) == 0x18, "WaitingStateAI::circlingDirection offset mismatch");

static WaitingStateAI* getInstance(lua_State* L, int idx)
{
    return checkObject<WaitingStateAI>(L, idx, WaitingStateAIBinding::getMetatableName());
}

static int WaitingStateAI_get_circlingDirection(lua_State* L)
{
    WaitingStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WaitingStateAI is nil");
    lua_pushnumber(L, instance->circlingDirection);
    return 1;
}

static int WaitingStateAI_set_circlingDirection(lua_State* L)
{
    WaitingStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WaitingStateAI is nil");
    instance->circlingDirection = (float)luaL_checknumber(L, 2);
    return 0;
}

int WaitingStateAIBinding::validate(lua_State* L)
{
    WaitingStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WaitingStateAI is nil");

    bool result = instance->validate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WaitingStateAIBinding::_NV_validate(lua_State* L)
{
    WaitingStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WaitingStateAI is nil");

    bool result = instance->_NV_validate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WaitingStateAIBinding::initialise(lua_State* L)
{
    WaitingStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WaitingStateAI is nil");

    bool result = instance->initialise();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WaitingStateAIBinding::_NV_initialise(lua_State* L)
{
    WaitingStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WaitingStateAI is nil");

    bool result = instance->_NV_initialise();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WaitingStateAIBinding::update(lua_State* L)
{
    WaitingStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WaitingStateAI is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->update(time);
    return 0;
}

int WaitingStateAIBinding::_NV_update(lua_State* L)
{
    WaitingStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WaitingStateAI is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->_NV_update(time);
    return 0;
}

int WaitingStateAIBinding::end(lua_State* L)
{
    WaitingStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WaitingStateAI is nil");

    instance->end();
    return 0;
}

int WaitingStateAIBinding::_NV_end(lua_State* L)
{
    WaitingStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WaitingStateAI is nil");

    instance->_NV_end();
    return 0;
}

int WaitingStateAIBinding::gc(lua_State* L)
{
    return 0;
}

int WaitingStateAIBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.WaitingStateAI object");
    return 1;
}

void WaitingStateAIBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WaitingStateAIBinding::gc },
        { "__tostring", WaitingStateAIBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "validate",           WaitingStateAIBinding::validate },
        { "_NV_validate",       WaitingStateAIBinding::_NV_validate },
        { "initialise",         WaitingStateAIBinding::initialise },
        { "_NV_initialise",     WaitingStateAIBinding::_NV_initialise },
        { "update",             WaitingStateAIBinding::update },
        { "_NV_update",         WaitingStateAIBinding::_NV_update },
        { "end",                WaitingStateAIBinding::end },
        { "_NV_end",            WaitingStateAIBinding::_NV_end },
        { 0, 0 }
    };

    registerClass(
        L,
        WaitingStateAIBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, WaitingStateAIBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "circlingDirection", WaitingStateAI_get_circlingDirection);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "circlingDirection", WaitingStateAI_set_circlingDirection);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);
}

} // namespace KenshiLua
