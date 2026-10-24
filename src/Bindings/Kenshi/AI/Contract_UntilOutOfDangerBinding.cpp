#include "pch.h"
// Tasker.h must come before AI.h; see TaskDataBinding.cpp.
#include "kenshi/Tasker.h"
// Contract.h includes AIPackage.h, which defines BlackboardSignalFunctions again, so never include Blackboard.h here.
#include "kenshi/AI/Contract.h"
#include "Contract_UntilOutOfDangerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/CharacterBinding.h"

namespace KenshiLua
{

static_assert(sizeof(Contract_UntilOutOfDanger) == 0xB0, "Contract_UntilOutOfDanger size does not match the game");

static Contract_UntilOutOfDanger* getInstance(lua_State* L, int idx)
{
    return checkObject<Contract_UntilOutOfDanger>(L, idx, Contract_UntilOutOfDangerBinding::getMetatableName());
}

int Contract_UntilOutOfDangerBinding::activateAndSetup(lua_State* L)
{
    Contract_UntilOutOfDanger* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_UntilOutOfDanger is nil");

    instance->activateAndSetup();
    return 0;
}

int Contract_UntilOutOfDangerBinding::_NV_activateAndSetup(lua_State* L)
{
    Contract_UntilOutOfDanger* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_UntilOutOfDanger is nil");

    instance->_NV_activateAndSetup();
    return 0;
}

int Contract_UntilOutOfDangerBinding::periodicUpdate(lua_State* L)
{
    Contract_UntilOutOfDanger* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_UntilOutOfDanger is nil");

    instance->periodicUpdate();
    return 0;
}

int Contract_UntilOutOfDangerBinding::_NV_periodicUpdate(lua_State* L)
{
    Contract_UntilOutOfDanger* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_UntilOutOfDanger is nil");

    instance->_NV_periodicUpdate();
    return 0;
}

int Contract_UntilOutOfDangerBinding::getDesiredTravelSpeed(lua_State* L)
{
    Contract_UntilOutOfDanger* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_UntilOutOfDanger is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    MoveSpeed result = instance->getDesiredTravelSpeed(me);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int Contract_UntilOutOfDangerBinding::_NV_getDesiredTravelSpeed(lua_State* L)
{
    Contract_UntilOutOfDanger* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_UntilOutOfDanger is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    MoveSpeed result = instance->_NV_getDesiredTravelSpeed(me);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int Contract_UntilOutOfDangerBinding::signalEnd(lua_State* L)
{
    Contract_UntilOutOfDanger* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_UntilOutOfDanger is nil");

    bool result = instance->signalEnd();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_UntilOutOfDangerBinding::_NV_signalEnd(lua_State* L)
{
    Contract_UntilOutOfDanger* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_UntilOutOfDanger is nil");

    bool result = instance->_NV_signalEnd();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 36-39: Contract_UntilOutOfDanger(), _CONSTRUCTOR, ~Contract_UntilOutOfDanger, _DESTRUCTOR - packages are created by Blackboard::createNewPackage and deleted by Blackboard
*/

int Contract_UntilOutOfDangerBinding::gc(lua_State* L)
{
    // Borrowed from the owning Blackboard
    return 0;
}

int Contract_UntilOutOfDangerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Contract_UntilOutOfDanger object");
    return 1;
}

void Contract_UntilOutOfDangerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       Contract_UntilOutOfDangerBinding::gc },
        { "__tostring", Contract_UntilOutOfDangerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "activateAndSetup", Contract_UntilOutOfDangerBinding::activateAndSetup },
        { "_NV_activateAndSetup", Contract_UntilOutOfDangerBinding::_NV_activateAndSetup },
        { "periodicUpdate", Contract_UntilOutOfDangerBinding::periodicUpdate },
        { "_NV_periodicUpdate", Contract_UntilOutOfDangerBinding::_NV_periodicUpdate },
        { "getDesiredTravelSpeed", Contract_UntilOutOfDangerBinding::getDesiredTravelSpeed },
        { "_NV_getDesiredTravelSpeed", Contract_UntilOutOfDangerBinding::_NV_getDesiredTravelSpeed },
        { "signalEnd", Contract_UntilOutOfDangerBinding::signalEnd },
        { "_NV_signalEnd", Contract_UntilOutOfDangerBinding::_NV_signalEnd },
        { 0, 0 }
    };

    registerClass(
        L,
        Contract_UntilOutOfDangerBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, Contract_UntilOutOfDangerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
