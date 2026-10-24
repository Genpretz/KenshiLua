#include "pch.h"
// Tasker.h must come before AI.h; see TaskDataBinding.cpp.
#include "kenshi/Tasker.h"
// Contract.h includes AIPackage.h, which defines BlackboardSignalFunctions again, so never include Blackboard.h here.
#include "kenshi/AI/Contract.h"
#include "Contract_HiredAllyBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"

namespace KenshiLua
{

static_assert(sizeof(Contract_HiredAlly) == 0xB0, "Contract_HiredAlly size does not match the game");

static Contract_HiredAlly* getInstance(lua_State* L, int idx)
{
    return checkObject<Contract_HiredAlly>(L, idx, Contract_HiredAllyBinding::getMetatableName());
}

int Contract_HiredAllyBinding::getDesiredTravelSpeed(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    MoveSpeed result = instance->getDesiredTravelSpeed(me);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int Contract_HiredAllyBinding::_NV_getDesiredTravelSpeed(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    MoveSpeed result = instance->_NV_getDesiredTravelSpeed(me);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int Contract_HiredAllyBinding::activateAndSetup(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    instance->activateAndSetup();
    return 0;
}

int Contract_HiredAllyBinding::_NV_activateAndSetup(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    instance->_NV_activateAndSetup();
    return 0;
}

int Contract_HiredAllyBinding::periodicUpdate(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    instance->periodicUpdate();
    return 0;
}

int Contract_HiredAllyBinding::_NV_periodicUpdate(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    instance->_NV_periodicUpdate();
    return 0;
}

int Contract_HiredAllyBinding::assessNeutral(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->assessNeutral(who);
    return 0;
}

int Contract_HiredAllyBinding::_NV_assessNeutral(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->_NV_assessNeutral(who);
    return 0;
}

int Contract_HiredAllyBinding::assessEnemy(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->assessEnemy(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_HiredAllyBinding::_NV_assessEnemy(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->_NV_assessEnemy(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_HiredAllyBinding::notifyBetrayal(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Character* betrayer = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool result = instance->notifyBetrayal(me, betrayer);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_HiredAllyBinding::_NV_notifyBetrayal(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Character* betrayer = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool result = instance->_NV_notifyBetrayal(me, betrayer);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_HiredAllyBinding::endPackage(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    instance->endPackage();
    return 0;
}

int Contract_HiredAllyBinding::_NV_endPackage(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    instance->_NV_endPackage();
    return 0;
}

int Contract_HiredAllyBinding::showEndedMessage(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    instance->showEndedMessage();
    return 0;
}

int Contract_HiredAllyBinding::_NV_showEndedMessage(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    instance->_NV_showEndedMessage();
    return 0;
}

int Contract_HiredAllyBinding::signalEnd(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    bool result = instance->signalEnd();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_HiredAllyBinding::_NV_signalEnd(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    bool result = instance->_NV_signalEnd();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_HiredAllyBinding::getGUIData(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    bool result = instance->getGUIData(panel);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_HiredAllyBinding::_NV_getGUIData(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    bool result = instance->_NV_getGUIData(panel);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_HiredAllyBinding::wantsRenewButton(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    bool result = instance->wantsRenewButton();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_HiredAllyBinding::_NV_wantsRenewButton(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    bool result = instance->_NV_wantsRenewButton();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Contract_HiredAllyBinding::showManagementPanelCallback(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    instance->showManagementPanelCallback();
    return 0;
}

int Contract_HiredAllyBinding::_NV_showManagementPanelCallback(lua_State* L)
{
    Contract_HiredAlly* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Contract_HiredAlly is nil");

    instance->_NV_showManagementPanelCallback();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 92-95: Contract_HiredAlly(), _CONSTRUCTOR, ~Contract_HiredAlly, _DESTRUCTOR - packages are created by Blackboard::createNewPackage and deleted by Blackboard
*/

int Contract_HiredAllyBinding::gc(lua_State* L)
{
    // Borrowed from the owning Blackboard
    return 0;
}

int Contract_HiredAllyBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Contract_HiredAlly object");
    return 1;
}

void Contract_HiredAllyBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       Contract_HiredAllyBinding::gc },
        { "__tostring", Contract_HiredAllyBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getDesiredTravelSpeed", Contract_HiredAllyBinding::getDesiredTravelSpeed },
        { "_NV_getDesiredTravelSpeed", Contract_HiredAllyBinding::_NV_getDesiredTravelSpeed },
        { "activateAndSetup", Contract_HiredAllyBinding::activateAndSetup },
        { "_NV_activateAndSetup", Contract_HiredAllyBinding::_NV_activateAndSetup },
        { "periodicUpdate", Contract_HiredAllyBinding::periodicUpdate },
        { "_NV_periodicUpdate", Contract_HiredAllyBinding::_NV_periodicUpdate },
        { "assessNeutral", Contract_HiredAllyBinding::assessNeutral },
        { "_NV_assessNeutral", Contract_HiredAllyBinding::_NV_assessNeutral },
        { "assessEnemy", Contract_HiredAllyBinding::assessEnemy },
        { "_NV_assessEnemy", Contract_HiredAllyBinding::_NV_assessEnemy },
        { "notifyBetrayal", Contract_HiredAllyBinding::notifyBetrayal },
        { "_NV_notifyBetrayal", Contract_HiredAllyBinding::_NV_notifyBetrayal },
        { "endPackage", Contract_HiredAllyBinding::endPackage },
        { "_NV_endPackage", Contract_HiredAllyBinding::_NV_endPackage },
        { "showEndedMessage", Contract_HiredAllyBinding::showEndedMessage },
        { "_NV_showEndedMessage", Contract_HiredAllyBinding::_NV_showEndedMessage },
        { "signalEnd", Contract_HiredAllyBinding::signalEnd },
        { "_NV_signalEnd", Contract_HiredAllyBinding::_NV_signalEnd },
        { "getGUIData", Contract_HiredAllyBinding::getGUIData },
        { "_NV_getGUIData", Contract_HiredAllyBinding::_NV_getGUIData },
        { "wantsRenewButton", Contract_HiredAllyBinding::wantsRenewButton },
        { "_NV_wantsRenewButton", Contract_HiredAllyBinding::_NV_wantsRenewButton },
        { "showManagementPanelCallback", Contract_HiredAllyBinding::showManagementPanelCallback },
        { "_NV_showManagementPanelCallback", Contract_HiredAllyBinding::_NV_showManagementPanelCallback },
        { 0, 0 }
    };

    registerClass(
        L,
        Contract_HiredAllyBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, Contract_HiredAllyBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
