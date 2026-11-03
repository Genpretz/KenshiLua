#include "pch.h"
#include "kenshi/combat/CombatState.h"
#include "CircleStateAIBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(CircleStateAI, circlingDirection) == 0x18, "CircleStateAI::circlingDirection offset mismatch");

static CircleStateAI* getInstance(lua_State* L, int idx)
{
    return checkObject<CircleStateAI>(L, idx, CircleStateAIBinding::getMetatableName());
}

static int CircleStateAI_get_circlingDirection(lua_State* L)
{
    CircleStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CircleStateAI is nil");
    lua_pushnumber(L, instance->circlingDirection);
    return 1;
}

static int CircleStateAI_set_circlingDirection(lua_State* L)
{
    CircleStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CircleStateAI is nil");
    instance->circlingDirection = (float)luaL_checknumber(L, 2);
    return 0;
}

int CircleStateAIBinding::amOverCrowded(lua_State* L)
{
    CircleStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CircleStateAI is nil");

    bool result = instance->amOverCrowded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CircleStateAIBinding::validate(lua_State* L)
{
    CircleStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CircleStateAI is nil");

    bool result = instance->validate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CircleStateAIBinding::_NV_validate(lua_State* L)
{
    CircleStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CircleStateAI is nil");

    bool result = instance->_NV_validate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CircleStateAIBinding::initialise(lua_State* L)
{
    CircleStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CircleStateAI is nil");

    bool result = instance->initialise();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CircleStateAIBinding::_NV_initialise(lua_State* L)
{
    CircleStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CircleStateAI is nil");

    bool result = instance->_NV_initialise();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CircleStateAIBinding::update(lua_State* L)
{
    CircleStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CircleStateAI is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->update(time);
    return 0;
}

int CircleStateAIBinding::_NV_update(lua_State* L)
{
    CircleStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CircleStateAI is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->_NV_update(time);
    return 0;
}

int CircleStateAIBinding::end(lua_State* L)
{
    CircleStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CircleStateAI is nil");

    instance->end();
    return 0;
}

int CircleStateAIBinding::_NV_end(lua_State* L)
{
    CircleStateAI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CircleStateAI is nil");

    instance->_NV_end();
    return 0;
}

int CircleStateAIBinding::gc(lua_State* L)
{
    return 0;
}

int CircleStateAIBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CircleStateAI object");
    return 1;
}

void CircleStateAIBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CircleStateAIBinding::gc },
        { "__tostring", CircleStateAIBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "amOverCrowded",      CircleStateAIBinding::amOverCrowded },
        { "validate",           CircleStateAIBinding::validate },
        { "_NV_validate",       CircleStateAIBinding::_NV_validate },
        { "initialise",         CircleStateAIBinding::initialise },
        { "_NV_initialise",     CircleStateAIBinding::_NV_initialise },
        { "update",             CircleStateAIBinding::update },
        { "_NV_update",         CircleStateAIBinding::_NV_update },
        { "end",                CircleStateAIBinding::end },
        { "_NV_end",            CircleStateAIBinding::_NV_end },
        { 0, 0 }
    };

    registerClass(
        L,
        CircleStateAIBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CircleStateAIBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "circlingDirection", CircleStateAI_get_circlingDirection);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "circlingDirection", CircleStateAI_set_circlingDirection);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);
}

} // namespace KenshiLua
