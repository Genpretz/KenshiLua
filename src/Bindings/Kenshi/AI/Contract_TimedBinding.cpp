#include "pch.h"
// Tasker.h must come before AI.h; see TaskDataBinding.cpp.
#include "kenshi/Tasker.h"
// Contract.h includes AIPackage.h, which defines BlackboardSignalFunctions again, so never include Blackboard.h here.
#include "kenshi/AI/Contract.h"
#include "Contract_TimedBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(sizeof(Contract_Timed) == 0xB0, "Contract_Timed size does not match the game");

static Contract_Timed* getInstance(lua_State* L, int idx)
{
    return checkObject<Contract_Timed>(L, idx, Contract_TimedBinding::getMetatableName());
}

int Contract_TimedBinding::signalStart(lua_State* L)
{
    Contract_Timed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_Timed is nil");

    bool result = instance->signalStart();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_TimedBinding::_NV_signalStart(lua_State* L)
{
    Contract_Timed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_Timed is nil");

    bool result = instance->_NV_signalStart();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_TimedBinding::signalEnd(lua_State* L)
{
    Contract_Timed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_Timed is nil");

    bool result = instance->signalEnd();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_TimedBinding::_NV_signalEnd(lua_State* L)
{
    Contract_Timed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_Timed is nil");

    bool result = instance->_NV_signalEnd();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 14-17: Contract_Timed(), _CONSTRUCTOR, ~Contract_Timed, _DESTRUCTOR - packages are created by Blackboard::createNewPackage and deleted by Blackboard
*/

int Contract_TimedBinding::gc(lua_State* L)
{
    // Borrowed from the owning Blackboard
    return 0;
}

int Contract_TimedBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Contract_Timed object");
    return 1;
}

void Contract_TimedBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       Contract_TimedBinding::gc },
        { "__tostring", Contract_TimedBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "signalStart", Contract_TimedBinding::signalStart },
        { "_NV_signalStart", Contract_TimedBinding::_NV_signalStart },
        { "signalEnd", Contract_TimedBinding::signalEnd },
        { "_NV_signalEnd", Contract_TimedBinding::_NV_signalEnd },
        { 0, 0 }
    };

    registerClass(
        L,
        Contract_TimedBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, Contract_TimedBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
