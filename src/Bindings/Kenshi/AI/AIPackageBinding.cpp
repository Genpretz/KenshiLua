#include "pch.h"
// Tasker.h must come before AI.h; see TaskDataBinding.cpp.
#include "kenshi/Tasker.h"
#include "kenshi/AI/AIPackage.h"
#include "AIPackageBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/AI/BlackboardBinding.h"
#include "Bindings/Kenshi/AI/TargetInfoBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/PlatoonBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

static_assert(offsetof(AIPackage, packageData) == 0x68, "AIPackage::packageData offset does not match the game");
static_assert(offsetof(AIPackage, blackboard) == 0x80, "AIPackage::blackboard offset does not match the game");
static_assert(offsetof(AIPackage, wasBetrayed) == 0xA8, "AIPackage::wasBetrayed offset does not match the game");

static AIPackage* getInstance(lua_State* L, int idx)
{
    return checkObject<AIPackage>(L, idx, AIPackageBinding::getMetatableName());
}

// --- Getters for AIPackage ---
static int AIPackage_get_missionTown(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    return HandBinding::push(L, instance->missionTown);
}

static int AIPackage_get_missionTarget(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    return HandBinding::push(L, instance->missionTarget);
}

static int AIPackage_get_missionEmployer(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    return HandBinding::push(L, instance->missionEmployer);
}

static int AIPackage_get_packageData(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    return pushObject<GameData>(L, instance->packageData, GameDataBinding::getMetatableName());
}

static int AIPackage_get_priorityLevel(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    lua_pushinteger(L, instance->priorityLevel);
    return 1;
}

static int AIPackage_get_key(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    lua_pushinteger(L, (lua_Integer)instance->key);
    return 1;
}

static int AIPackage_get_unloadedMode(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    lua_pushinteger(L, (lua_Integer)instance->unloadedMode);
    return 1;
}

static int AIPackage_get_blackboard(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    return pushObject<Blackboard>(L, instance->blackboard, BlackboardBinding::getMetatableName());
}

static int AIPackage_get_squad(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    return pushObject<Platoon>(L, instance->squad, PlatoonBinding::getMetatableName());
}

static int AIPackage_get_leadsToPackage(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    return pushObject<AIPackage>(L, instance->leadsToPackage, AIPackageBinding::getMetatableName());
}

static int AIPackage_get_endingDialogPassive(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    return pushObject<GameData>(L, instance->endingDialogPassive, GameDataBinding::getMetatableName());
}

static int AIPackage_get_endingDialogActive(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    return pushObject<GameData>(L, instance->endingDialogActive, GameDataBinding::getMetatableName());
}

static int AIPackage_get_wasBetrayed(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    lua_pushboolean(L, instance->wasBetrayed ? 1 : 0);
    return 1;
}

// --- Setters for AIPackage ---
static int AIPackage_set_missionTown(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    instance->missionTown = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int AIPackage_set_missionTarget(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    instance->missionTarget = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int AIPackage_set_missionEmployer(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    instance->missionEmployer = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

// Blackboard::createNewPackage sets packageData, blackboard, and squad on every live package;
// iAmActivePackage and getLeader dereference blackboard and squad without null checks.
static int AIPackage_set_packageData(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    instance->packageData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int AIPackage_set_priorityLevel(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    instance->priorityLevel = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int AIPackage_set_key(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    instance->key = (BlackboardSignalFunctions)luaL_checkinteger(L, 2);
    return 0;
}

static int AIPackage_set_unloadedMode(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    instance->unloadedMode = (UnloadedPlatoonJob)luaL_checkinteger(L, 2);
    return 0;
}

static int AIPackage_set_blackboard(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    instance->blackboard = checkObject<Blackboard>(L, 2, BlackboardBinding::getMetatableName());
    return 0;
}

static int AIPackage_set_squad(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    instance->squad = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    return 0;
}

// ~AIPackage does not delete leadsToPackage.
static int AIPackage_set_leadsToPackage(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    instance->leadsToPackage = lua_isnoneornil(L, 2) ? nullptr : checkObject<AIPackage>(L, 2, AIPackageBinding::getMetatableName());
    return 0;
}

// Blackboard::endContractJob checks endingDialogPassive for null.
static int AIPackage_set_endingDialogPassive(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    instance->endingDialogPassive = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int AIPackage_set_endingDialogActive(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    instance->endingDialogActive = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int AIPackage_set_wasBetrayed(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");
    instance->wasBetrayed = lua_toboolean(L, 2) != 0;
    return 0;
}

int AIPackageBinding::getMyTarget(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    TargetInfo result = instance->getMyTarget(me);
    return pushValue<TargetInfo>(L, result, TargetInfoBinding::getMetatableName());
}

int AIPackageBinding::_NV_getMyTarget(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    TargetInfo result = instance->_NV_getMyTarget(me);
    return pushValue<TargetInfo>(L, result, TargetInfoBinding::getMetatableName());
}

int AIPackageBinding::notifyMyTargetPathfindImpossible(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    hand* was = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    instance->notifyMyTargetPathfindImpossible(me, *was);
    return 0;
}

int AIPackageBinding::_NV_notifyMyTargetPathfindImpossible(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    hand* was = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    instance->_NV_notifyMyTargetPathfindImpossible(me, *was);
    return 0;
}

int AIPackageBinding::getDesiredTravelSpeed(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    MoveSpeed result = instance->getDesiredTravelSpeed(me);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int AIPackageBinding::_NV_getDesiredTravelSpeed(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    MoveSpeed result = instance->_NV_getDesiredTravelSpeed(me);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int AIPackageBinding::getLeader(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    Character* result = instance->getLeader();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int AIPackageBinding::save(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->save(state);
    return 0;
}

int AIPackageBinding::_NV_save(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_save(state);
    return 0;
}

int AIPackageBinding::load(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->load(state);
    return 0;
}

int AIPackageBinding::_NV_load(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_load(state);
    return 0;
}

int AIPackageBinding::activateAndSetup(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    instance->activateAndSetup();
    return 0;
}

int AIPackageBinding::_NV_activateAndSetup(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    instance->_NV_activateAndSetup();
    return 0;
}

int AIPackageBinding::endPackage(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    instance->endPackage();
    return 0;
}

int AIPackageBinding::_NV_endPackage(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    instance->_NV_endPackage();
    return 0;
}

int AIPackageBinding::notifyBetrayal(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    Character* myWitness = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Character* betrayer = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool result = instance->notifyBetrayal(myWitness, betrayer);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::_NV_notifyBetrayal(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    Character* myWitness = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Character* betrayer = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool result = instance->_NV_notifyBetrayal(myWitness, betrayer);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::periodicUpdate(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    instance->periodicUpdate();
    return 0;
}

int AIPackageBinding::_NV_periodicUpdate(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    instance->_NV_periodicUpdate();
    return 0;
}

int AIPackageBinding::assessNeutral(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->assessNeutral(who);
    return 0;
}

int AIPackageBinding::_NV_assessNeutral(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->_NV_assessNeutral(who);
    return 0;
}

int AIPackageBinding::assessEnemy(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->assessEnemy(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::_NV_assessEnemy(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->_NV_assessEnemy(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::signalStart(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    bool result = instance->signalStart();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::_NV_signalStart(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    bool result = instance->_NV_signalStart();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::signalEnd(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    bool result = instance->signalEnd();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::_NV_signalEnd(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    bool result = instance->_NV_signalEnd();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::iAmActivePackage(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    bool result = instance->iAmActivePackage();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::getGUIData(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    bool result = instance->getGUIData(panel);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::_NV_getGUIData(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    bool result = instance->_NV_getGUIData(panel);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::autoNotifyJobsPanel(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    bool result = instance->autoNotifyJobsPanel();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::_NV_autoNotifyJobsPanel(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    bool result = instance->_NV_autoNotifyJobsPanel();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::wantsRenewButton(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    bool result = instance->wantsRenewButton();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::_NV_wantsRenewButton(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    bool result = instance->_NV_wantsRenewButton();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::showManagementPanelCallback(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    instance->showManagementPanelCallback();
    return 0;
}

int AIPackageBinding::_NV_showManagementPanelCallback(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    instance->_NV_showManagementPanelCallback();
    return 0;
}

int AIPackageBinding::wasASuccess(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    bool result = instance->wasASuccess();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIPackageBinding::_NV_wasASuccess(lua_State* L)
{
    AIPackage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPackage is nil");

    bool result = instance->_NV_wasASuccess();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 55: AIPackage() - packages are created by Blackboard::createNewPackage and deleted by Blackboard
  line 56: _CONSTRUCTOR() - packages are created by Blackboard::createNewPackage and deleted by Blackboard
  line 57: ~AIPackage() - packages are deleted by Blackboard
  line 58: _DESTRUCTOR() - packages are deleted by Blackboard
*/

int AIPackageBinding::gc(lua_State* L)
{
    // Borrowed from the owning Blackboard
    return 0;
}

int AIPackageBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AIPackage object");
    return 1;
}

void AIPackageBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AIPackageBinding::gc },
        { "__tostring", AIPackageBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getMyTarget", AIPackageBinding::getMyTarget },
        { "_NV_getMyTarget", AIPackageBinding::_NV_getMyTarget },
        { "notifyMyTargetPathfindImpossible", AIPackageBinding::notifyMyTargetPathfindImpossible },
        { "_NV_notifyMyTargetPathfindImpossible", AIPackageBinding::_NV_notifyMyTargetPathfindImpossible },
        { "getDesiredTravelSpeed", AIPackageBinding::getDesiredTravelSpeed },
        { "_NV_getDesiredTravelSpeed", AIPackageBinding::_NV_getDesiredTravelSpeed },
        { "getLeader", AIPackageBinding::getLeader },
        { "save", AIPackageBinding::save },
        { "_NV_save", AIPackageBinding::_NV_save },
        { "load", AIPackageBinding::load },
        { "_NV_load", AIPackageBinding::_NV_load },
        { "activateAndSetup", AIPackageBinding::activateAndSetup },
        { "_NV_activateAndSetup", AIPackageBinding::_NV_activateAndSetup },
        { "endPackage", AIPackageBinding::endPackage },
        { "_NV_endPackage", AIPackageBinding::_NV_endPackage },
        { "notifyBetrayal", AIPackageBinding::notifyBetrayal },
        { "_NV_notifyBetrayal", AIPackageBinding::_NV_notifyBetrayal },
        { "periodicUpdate", AIPackageBinding::periodicUpdate },
        { "_NV_periodicUpdate", AIPackageBinding::_NV_periodicUpdate },
        { "assessNeutral", AIPackageBinding::assessNeutral },
        { "_NV_assessNeutral", AIPackageBinding::_NV_assessNeutral },
        { "assessEnemy", AIPackageBinding::assessEnemy },
        { "_NV_assessEnemy", AIPackageBinding::_NV_assessEnemy },
        { "signalStart", AIPackageBinding::signalStart },
        { "_NV_signalStart", AIPackageBinding::_NV_signalStart },
        { "signalEnd", AIPackageBinding::signalEnd },
        { "_NV_signalEnd", AIPackageBinding::_NV_signalEnd },
        { "iAmActivePackage", AIPackageBinding::iAmActivePackage },
        { "getGUIData", AIPackageBinding::getGUIData },
        { "_NV_getGUIData", AIPackageBinding::_NV_getGUIData },
        { "autoNotifyJobsPanel", AIPackageBinding::autoNotifyJobsPanel },
        { "_NV_autoNotifyJobsPanel", AIPackageBinding::_NV_autoNotifyJobsPanel },
        { "wantsRenewButton", AIPackageBinding::wantsRenewButton },
        { "_NV_wantsRenewButton", AIPackageBinding::_NV_wantsRenewButton },
        { "showManagementPanelCallback", AIPackageBinding::showManagementPanelCallback },
        { "_NV_showManagementPanelCallback", AIPackageBinding::_NV_showManagementPanelCallback },
        { "wasASuccess", AIPackageBinding::wasASuccess },
        { "_NV_wasASuccess", AIPackageBinding::_NV_wasASuccess },
        { 0, 0 }
    };

    registerClass(
        L,
        AIPackageBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AIPackageBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "missionTown", AIPackage_get_missionTown);
    registerGetter(L, "missionTarget", AIPackage_get_missionTarget);
    registerGetter(L, "missionEmployer", AIPackage_get_missionEmployer);
    registerGetter(L, "packageData", AIPackage_get_packageData);
    registerGetter(L, "priorityLevel", AIPackage_get_priorityLevel);
    registerGetter(L, "key", AIPackage_get_key);
    registerGetter(L, "unloadedMode", AIPackage_get_unloadedMode);
    registerGetter(L, "blackboard", AIPackage_get_blackboard);
    registerGetter(L, "squad", AIPackage_get_squad);
    registerGetter(L, "leadsToPackage", AIPackage_get_leadsToPackage);
    registerGetter(L, "endingDialogPassive", AIPackage_get_endingDialogPassive);
    registerGetter(L, "endingDialogActive", AIPackage_get_endingDialogActive);
    registerGetter(L, "wasBetrayed", AIPackage_get_wasBetrayed);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "missionTown", AIPackage_set_missionTown);
    registerSetter(L, "missionTarget", AIPackage_set_missionTarget);
    registerSetter(L, "missionEmployer", AIPackage_set_missionEmployer);
    registerSetter(L, "packageData", AIPackage_set_packageData);
    registerSetter(L, "priorityLevel", AIPackage_set_priorityLevel);
    registerSetter(L, "key", AIPackage_set_key);
    registerSetter(L, "unloadedMode", AIPackage_set_unloadedMode);
    registerSetter(L, "blackboard", AIPackage_set_blackboard);
    registerSetter(L, "squad", AIPackage_set_squad);
    registerSetter(L, "leadsToPackage", AIPackage_set_leadsToPackage);
    registerSetter(L, "endingDialogPassive", AIPackage_set_endingDialogPassive);
    registerSetter(L, "endingDialogActive", AIPackage_set_endingDialogActive);
    registerSetter(L, "wasBetrayed", AIPackage_set_wasBetrayed);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
