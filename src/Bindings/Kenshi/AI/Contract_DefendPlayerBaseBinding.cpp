#include "pch.h"
// Tasker.h must come before AI.h; see TaskDataBinding.cpp.
#include "kenshi/Tasker.h"
// Contract.h includes AIPackage.h, which defines BlackboardSignalFunctions again, so never include Blackboard.h here.
#include "kenshi/AI/Contract.h"
#include "Contract_DefendPlayerBaseBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/AI/TargetInfoBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"

namespace KenshiLua
{

static_assert(sizeof(Contract_DefendPlayerBase) == 0xB0, "Contract_DefendPlayerBase size does not match the game");

static Contract_DefendPlayerBase* getInstance(lua_State* L, int idx)
{
    return checkObject<Contract_DefendPlayerBase>(L, idx, Contract_DefendPlayerBaseBinding::getMetatableName());
}

int Contract_DefendPlayerBaseBinding::getGUIData(lua_State* L)
{
    Contract_DefendPlayerBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_DefendPlayerBase is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    bool result = instance->getGUIData(panel);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_DefendPlayerBaseBinding::_NV_getGUIData(lua_State* L)
{
    Contract_DefendPlayerBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_DefendPlayerBase is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    bool result = instance->_NV_getGUIData(panel);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_DefendPlayerBaseBinding::getMyTarget(lua_State* L)
{
    Contract_DefendPlayerBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_DefendPlayerBase is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    TargetInfo result = instance->getMyTarget(me);
    return pushValue<TargetInfo>(L, result, TargetInfoBinding::getMetatableName());
}

int Contract_DefendPlayerBaseBinding::_NV_getMyTarget(lua_State* L)
{
    Contract_DefendPlayerBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_DefendPlayerBase is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    TargetInfo result = instance->_NV_getMyTarget(me);
    return pushValue<TargetInfo>(L, result, TargetInfoBinding::getMetatableName());
}

int Contract_DefendPlayerBaseBinding::getDesiredTravelSpeed(lua_State* L)
{
    Contract_DefendPlayerBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_DefendPlayerBase is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    MoveSpeed result = instance->getDesiredTravelSpeed(me);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int Contract_DefendPlayerBaseBinding::_NV_getDesiredTravelSpeed(lua_State* L)
{
    Contract_DefendPlayerBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_DefendPlayerBase is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    MoveSpeed result = instance->_NV_getDesiredTravelSpeed(me);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int Contract_DefendPlayerBaseBinding::activateAndSetup(lua_State* L)
{
    Contract_DefendPlayerBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_DefendPlayerBase is nil");

    instance->activateAndSetup();
    return 0;
}

int Contract_DefendPlayerBaseBinding::_NV_activateAndSetup(lua_State* L)
{
    Contract_DefendPlayerBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_DefendPlayerBase is nil");

    instance->_NV_activateAndSetup();
    return 0;
}

int Contract_DefendPlayerBaseBinding::periodicUpdate(lua_State* L)
{
    Contract_DefendPlayerBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_DefendPlayerBase is nil");

    instance->periodicUpdate();
    return 0;
}

int Contract_DefendPlayerBaseBinding::_NV_periodicUpdate(lua_State* L)
{
    Contract_DefendPlayerBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_DefendPlayerBase is nil");

    instance->_NV_periodicUpdate();
    return 0;
}

int Contract_DefendPlayerBaseBinding::assessNeutral(lua_State* L)
{
    Contract_DefendPlayerBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_DefendPlayerBase is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->assessNeutral(who);
    return 0;
}

int Contract_DefendPlayerBaseBinding::_NV_assessNeutral(lua_State* L)
{
    Contract_DefendPlayerBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_DefendPlayerBase is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->_NV_assessNeutral(who);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 118-121: Contract_DefendPlayerBase(), _CONSTRUCTOR, ~Contract_DefendPlayerBase, _DESTRUCTOR - packages are created by Blackboard::createNewPackage and deleted by Blackboard
*/

int Contract_DefendPlayerBaseBinding::gc(lua_State* L)
{
    // Borrowed from the owning Blackboard
    return 0;
}

int Contract_DefendPlayerBaseBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Contract_DefendPlayerBase object");
    return 1;
}

void Contract_DefendPlayerBaseBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       Contract_DefendPlayerBaseBinding::gc },
        { "__tostring", Contract_DefendPlayerBaseBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getGUIData", Contract_DefendPlayerBaseBinding::getGUIData },
        { "_NV_getGUIData", Contract_DefendPlayerBaseBinding::_NV_getGUIData },
        { "getMyTarget", Contract_DefendPlayerBaseBinding::getMyTarget },
        { "_NV_getMyTarget", Contract_DefendPlayerBaseBinding::_NV_getMyTarget },
        { "getDesiredTravelSpeed", Contract_DefendPlayerBaseBinding::getDesiredTravelSpeed },
        { "_NV_getDesiredTravelSpeed", Contract_DefendPlayerBaseBinding::_NV_getDesiredTravelSpeed },
        { "activateAndSetup", Contract_DefendPlayerBaseBinding::activateAndSetup },
        { "_NV_activateAndSetup", Contract_DefendPlayerBaseBinding::_NV_activateAndSetup },
        { "periodicUpdate", Contract_DefendPlayerBaseBinding::periodicUpdate },
        { "_NV_periodicUpdate", Contract_DefendPlayerBaseBinding::_NV_periodicUpdate },
        { "assessNeutral", Contract_DefendPlayerBaseBinding::assessNeutral },
        { "_NV_assessNeutral", Contract_DefendPlayerBaseBinding::_NV_assessNeutral },
        { 0, 0 }
    };

    registerClass(
        L,
        Contract_DefendPlayerBaseBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, Contract_DefendPlayerBaseBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
