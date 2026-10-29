#include "pch.h"
// Tasker.h must come before AI.h; see TaskDataBinding.cpp.
#include "kenshi/Tasker.h"
// Contract.h includes AIPackage.h, which defines BlackboardSignalFunctions again, so never include Blackboard.h here.
#include "kenshi/AI/Contract.h"
#include "Contract_UntilExSlaveBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/CharacterBinding.h"

namespace KenshiLua
{

static_assert(sizeof(Contract_UntilExSlave) == 0xB0, "Contract_UntilExSlave size does not match the game");

static Contract_UntilExSlave* getInstance(lua_State* L, int idx)
{
    return checkObject<Contract_UntilExSlave>(L, idx, Contract_UntilExSlaveBinding::getMetatableName());
}

int Contract_UntilExSlaveBinding::getDesiredTravelSpeed(lua_State* L)
{
    Contract_UntilExSlave* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_UntilExSlave is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    MoveSpeed result = instance->getDesiredTravelSpeed(me);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int Contract_UntilExSlaveBinding::_NV_getDesiredTravelSpeed(lua_State* L)
{
    Contract_UntilExSlave* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_UntilExSlave is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    MoveSpeed result = instance->_NV_getDesiredTravelSpeed(me);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int Contract_UntilExSlaveBinding::signalEnd(lua_State* L)
{
    Contract_UntilExSlave* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_UntilExSlave is nil");

    bool result = instance->signalEnd();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_UntilExSlaveBinding::_NV_signalEnd(lua_State* L)
{
    Contract_UntilExSlave* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_UntilExSlave is nil");

    bool result = instance->_NV_signalEnd();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 54-57: Contract_UntilExSlave(), _CONSTRUCTOR, ~Contract_UntilExSlave, _DESTRUCTOR - packages are created by Blackboard::createNewPackage and deleted by Blackboard
*/

int Contract_UntilExSlaveBinding::gc(lua_State* L)
{
    // Borrowed from the owning Blackboard
    return 0;
}

int Contract_UntilExSlaveBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Contract_UntilExSlave object");
    return 1;
}

void Contract_UntilExSlaveBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       Contract_UntilExSlaveBinding::gc },
        { "__tostring", Contract_UntilExSlaveBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getDesiredTravelSpeed", Contract_UntilExSlaveBinding::getDesiredTravelSpeed },
        { "_NV_getDesiredTravelSpeed", Contract_UntilExSlaveBinding::_NV_getDesiredTravelSpeed },
        { "signalEnd", Contract_UntilExSlaveBinding::signalEnd },
        { "_NV_signalEnd", Contract_UntilExSlaveBinding::_NV_signalEnd },
        { 0, 0 }
    };

    registerClass(
        L,
        Contract_UntilExSlaveBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, Contract_UntilExSlaveBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
