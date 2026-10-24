#include "pch.h"
// Tasker.h must come before AI.h; see TaskDataBinding.cpp.
#include "kenshi/Tasker.h"
#include "kenshi/AI/Blackboard.h"
#include "BlackboardBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/AI/AIPackageBinding.h"
#include "Bindings/Kenshi/Building/BuildingBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/OwnershipsBinding.h"
#include "Bindings/Kenshi/PlatoonBinding.h"
#include "Bindings/Kenshi/TaskerBinding.h"
#include "Bindings/Kenshi/TownBaseBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/Util/OgreUnorderedBinding.h"
#include "Bindings/Kenshi/Util/TimeOfDayBinding.h"
#include "Bindings/Kenshi/ZoneMapBinding.h"

namespace KenshiLua
{

static_assert(offsetof(Blackboard, currentPackage) == 0x48, "Blackboard::currentPackage offset does not match the game");
static_assert(offsetof(Blackboard, squad) == 0xA0, "Blackboard::squad offset does not match the game");
static_assert(offsetof(Blackboard, currentTownLocation) == 0x138, "Blackboard::currentTownLocation offset does not match the game");
static_assert(offsetof(Blackboard, contractJob) == 0x210, "Blackboard::contractJob offset does not match the game");
static_assert(offsetof(Blackboard, characterFormationPosition) == 0x268, "Blackboard::characterFormationPosition offset does not match the game");

// Hand values are copied through LuaCodec<hand>; a value metatable would push borrowed hands.
typedef OgreUnorderedMapBinding<TaskType, hand> TaskTypeHandMapBinding;
typedef OgreUnorderedMapBinding<hand, Ogre::Vector3> HandVector3MapBinding;

static Blackboard* getInstance(lua_State* L, int idx)
{
    return checkObject<Blackboard>(L, idx, BlackboardBinding::getMetatableName());
}

// --- Getters for Blackboard ---
static int Blackboard_get_currentPackage(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    return pushObject<AIPackage>(L, instance->currentPackage, AIPackageBinding::getMetatableName());
}

static int Blackboard_get_currentPackagePriorityLevel(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    lua_pushinteger(L, instance->currentPackagePriorityLevel);
    return 1;
}

static int Blackboard_get_replacementAIPackageSID(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    lua_pushstring(L, instance->replacementAIPackageSID.c_str());
    return 1;
}

static int Blackboard_get_cageMarkedForDeath(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    return HandBinding::push(L, instance->cageMarkedForDeath);
}

static int Blackboard_get_squad(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    return pushObject<Platoon>(L, instance->squad, PlatoonBinding::getMetatableName());
}

static int Blackboard_get_actionTargets(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    return pushObject<TaskTypeHandMapBinding::MapType>(L, &instance->actionTargets, TaskTypeHandMapBinding::getMetatableName());
}

static int Blackboard_get_homeIsLockedUp(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    lua_pushboolean(L, instance->homeIsLockedUp ? 1 : 0);
    return 1;
}

static int Blackboard_get_targetTown(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    return pushObject<TownBase>(L, instance->targetTown, TownBaseBinding::getMetatableName());
}

static int Blackboard_get_targetZoneHunting(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    return pushObject<ZoneMap>(L, instance->targetZoneHunting, ZoneMapBinding::getMetatableName());
}

static int Blackboard_get_missionData(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    return pushObject<GameData>(L, instance->missionData, GameDataBinding::getMetatableName());
}

static int Blackboard_get_moraleIsBroken(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    lua_pushboolean(L, instance->moraleIsBroken ? 1 : 0);
    return 1;
}

static int Blackboard_get__homeGateTarget(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    return HandBinding::push(L, instance->_homeGateTarget);
}

static int Blackboard_get__flagCleared(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    lua_pushboolean(L, instance->_flagCleared ? 1 : 0);
    return 1;
}

static int Blackboard_get_needsStateUpdate(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    lua_pushboolean(L, instance->needsStateUpdate ? 1 : 0);
    return 1;
}

static int Blackboard_get_currentTownLocation(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    return pushObject<TownBase>(L, instance->currentTownLocation, TownBaseBinding::getMetatableName());
}

static int Blackboard_get_townArrivalTime(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    return pushObject<TimeOfDay>(L, &instance->townArrivalTime, TimeOfDayBinding::getMetatableName());
}

static int Blackboard_get_HIGHEST_PRIORITY_LEVEL(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    lua_pushinteger(L, instance->HIGHEST_PRIORITY_LEVEL);
    return 1;
}

static int Blackboard_get_runningAwayMode(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    lua_pushboolean(L, instance->runningAwayMode ? 1 : 0);
    return 1;
}

static int Blackboard_get_characterCount(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    lua_pushinteger(L, instance->characterCount);
    return 1;
}

static int Blackboard_get_enemyCount(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    lua_pushinteger(L, instance->enemyCount);
    return 1;
}

static int Blackboard_get_contractJob(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    return pushObject<AIPackage>(L, instance->contractJob, AIPackageBinding::getMetatableName());
}

static int Blackboard_get_contractExpiryTime(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    return pushObject<TimeOfDay>(L, &instance->contractExpiryTime, TimeOfDayBinding::getMetatableName());
}

static int Blackboard_get_formationNeedUpdate(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    lua_pushboolean(L, instance->formationNeedUpdate ? 1 : 0);
    return 1;
}

static int Blackboard_get_characterFormationPosition(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    return pushObject<HandVector3MapBinding::MapType>(L, &instance->characterFormationPosition, HandVector3MapBinding::getMetatableName());
}

// --- Setters for Blackboard ---
// clearAllPackages and endContractJob reset currentPackage to null. Assigning a package
// owned by another Blackboard leaves this one pointing at memory that Blackboard may delete.
static int Blackboard_set_currentPackage(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->currentPackage = lua_isnoneornil(L, 2) ? nullptr : checkObject<AIPackage>(L, 2, AIPackageBinding::getMetatableName());
    return 0;
}

static int Blackboard_set_currentPackagePriorityLevel(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->currentPackagePriorityLevel = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Blackboard_set_replacementAIPackageSID(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->replacementAIPackageSID = luaL_checkstring(L, 2);
    return 0;
}

static int Blackboard_set_cageMarkedForDeath(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->cageMarkedForDeath = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

// Blackboard(Platoon*) sets squad; endContractJob calls Platoon::getSquadLeader(squad) without a null check.
static int Blackboard_set_squad(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->squad = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    return 0;
}

static int Blackboard_set_homeIsLockedUp(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->homeIsLockedUp = lua_toboolean(L, 2) != 0;
    return 0;
}

// The constructor leaves targetTown, targetZoneHunting, missionData, and currentTownLocation null.
static int Blackboard_set_targetTown(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->targetTown = lua_isnoneornil(L, 2) ? nullptr : checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    return 0;
}

static int Blackboard_set_targetZoneHunting(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->targetZoneHunting = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    return 0;
}

static int Blackboard_set_missionData(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->missionData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int Blackboard_set_moraleIsBroken(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->moraleIsBroken = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Blackboard_set__homeGateTarget(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->_homeGateTarget = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int Blackboard_set__flagCleared(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->_flagCleared = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Blackboard_set_needsStateUpdate(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->needsStateUpdate = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Blackboard_set_currentTownLocation(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->currentTownLocation = lua_isnoneornil(L, 2) ? nullptr : checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    return 0;
}

static int Blackboard_set_townArrivalTime(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->townArrivalTime = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int Blackboard_set_HIGHEST_PRIORITY_LEVEL(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->HIGHEST_PRIORITY_LEVEL = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Blackboard_set_runningAwayMode(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->runningAwayMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Blackboard_set_characterCount(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->characterCount = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Blackboard_set_enemyCount(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->enemyCount = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Blackboard_set_contractExpiryTime(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->contractExpiryTime = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int Blackboard_set_formationNeedUpdate(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");
    instance->formationNeedUpdate = lua_toboolean(L, 2) != 0;
    return 0;
}

int BlackboardBinding::createNewPackage(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    BlackboardSignalFunctions key = (BlackboardSignalFunctions)luaL_checkinteger(L, 2);
    GameData* data = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    int priority = (int)luaL_checkinteger(L, 4);
    hand* giver = checkObject<hand>(L, 5, HandBinding::getMetatableName());
    AIPackage* result = instance->createNewPackage(key, data, priority, *giver);
    return pushObject<AIPackage>(L, result, AIPackageBinding::getMetatableName());
}

int BlackboardBinding::_setContractJob(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    GameData* package = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int hours = (int)luaL_checkinteger(L, 3);
    hand* giver = checkObject<hand>(L, 4, HandBinding::getMetatableName());
    instance->_setContractJob(package, hours, *giver);
    return 0;
}

int BlackboardBinding::_addPackage(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    GameData* package = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int type = (int)luaL_checkinteger(L, 3);
    instance->_addPackage(package, type);
    return 0;
}

int BlackboardBinding::clearAllPackages(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    instance->clearAllPackages();
    return 0;
}

int BlackboardBinding::_activateCurrentPackage(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    AIPackage* package = checkObject<AIPackage>(L, 2, AIPackageBinding::getMetatableName());
    instance->_activateCurrentPackage(package);
    return 0;
}

int BlackboardBinding::_addFromData(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_addFromData(data);
    return 0;
}

int BlackboardBinding::getPackage(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    std::string sid = luaL_checkstring(L, 2);
    AIPackage* result = instance->getPackage(sid);
    return pushObject<AIPackage>(L, result, AIPackageBinding::getMetatableName());
}

int BlackboardBinding::getPackageList(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    int type = (int)luaL_checkinteger(L, 2);
    lektor<AIPackage*>* result = instance->getPackageList(type);
    return pushObject<lektor<AIPackage*> >(L, result, LektorPtrBinding<AIPackage*>::getMetatableName());
}

int BlackboardBinding::periodicPackageCheck(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    int type = (int)luaL_checkinteger(L, 2);
    float frameTime = (float)luaL_checknumber(L, 3);
    bool result = instance->periodicPackageCheck(type, frameTime);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BlackboardBinding::dialogEventsCheck(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    GameData* line = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    hand* target = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    instance->dialogEventsCheck(line, *target);
    return 0;
}

int BlackboardBinding::setContractJob(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    GameData* packageCollection = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    hand* giver = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    instance->setContractJob(packageCollection, *giver);
    return 0;
}

int BlackboardBinding::endContractJob(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    instance->endContractJob();
    return 0;
}

int BlackboardBinding::isMissionComplete(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    bool result = instance->isMissionComplete();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BlackboardBinding::isTargetMarkedForDeath(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    Building* cage = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    TownBase* t = checkObject<TownBase>(L, 3, TownBaseBinding::getMetatableName());
    bool result = instance->isTargetMarkedForDeath(cage, t);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BlackboardBinding::update(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    instance->update(frameTime);
    return 0;
}

int BlackboardBinding::periodicUpdate(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    instance->periodicUpdate(frameTime);
    return 0;
}

int BlackboardBinding::addPackages(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    GameData* packageCollection = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->addPackages(packageCollection);
    return 0;
}

int BlackboardBinding::addFallbackPackages(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    GameData* packageCollection_faction = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->addFallbackPackages(packageCollection_faction);
    return 0;
}

int BlackboardBinding::replaceAIPackage(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    GameData* package = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->replaceAIPackage(package);
    return 0;
}

int BlackboardBinding::getCurrentAIPackageName(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    std::string result = instance->getCurrentAIPackageName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int BlackboardBinding::getCurrentAIPackageGUIData(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int cat = (int)luaL_checkinteger(L, 3);
    instance->getCurrentAIPackageGUIData(panel, cat);
    return 0;
}

int BlackboardBinding::assessNeutral(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->assessNeutral(who);
    return 0;
}

int BlackboardBinding::assessEnemy(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->assessEnemy(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BlackboardBinding::getCurrentPackage(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    AIPackage* result = instance->getCurrentPackage();
    return pushObject<AIPackage>(L, result, AIPackageBinding::getMetatableName());
}

int BlackboardBinding::getFormationPositionOffset(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    const Ogre::Vector3& result = instance->getFormationPositionOffset(character);
    pushVector3(L, result);
    return 1;
}

int BlackboardBinding::nodifyFormationUpdate(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    instance->nodifyFormationUpdate();
    return 0;
}

int BlackboardBinding::getOwnerships(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    Ownerships* result = instance->getOwnerships();
    return pushObject<Ownerships>(L, result, OwnershipsBinding::getMetatableName());
}

int BlackboardBinding::notifyGoalStart(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    hand* me = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    instance->notifyGoalStart(t, *me);
    return 0;
}

int BlackboardBinding::notifyGoalEnd(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    hand* me = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->notifyGoalEnd(*me);
    return 0;
}

int BlackboardBinding::notifySubTarget(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    hand* me = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    hand* target = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    instance->notifySubTarget(*me, *target);
    return 0;
}

int BlackboardBinding::howManyGuysDoingThisGoal(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    hand* me = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    int result = instance->howManyGuysDoingThisGoal(t, *me);
    lua_pushinteger(L, result);
    return 1;
}

// (Tasker*, const hand& me, const hand& subtarget) or (const hand& me, const hand& subtarget)
int BlackboardBinding::howManyGuysWorkingOnThisSubTarget(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    Tasker* t = testObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    if (t)
    {
        hand* me = checkObject<hand>(L, 3, HandBinding::getMetatableName());
        hand* subtarget = checkObject<hand>(L, 4, HandBinding::getMetatableName());
        int result = instance->howManyGuysWorkingOnThisSubTarget(t, *me, *subtarget);
        lua_pushinteger(L, result);
        return 1;
    }

    hand* me = testObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!me) return luaL_argerror(L, 2, "KenshiLua.Tasker or KenshiLua.hand expected");
    hand* subtarget = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    int result = instance->howManyGuysWorkingOnThisSubTarget(*me, *subtarget);
    lua_pushinteger(L, result);
    return 1;
}

int BlackboardBinding::isMySubTarget(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    hand* me = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    hand* subtarget = checkObject<hand>(L, 4, HandBinding::getMetatableName());
    bool result = instance->isMySubTarget(t, *me, *subtarget);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

// subtarget is an out-parameter and is returned instead of passed.
int BlackboardBinding::getSubTarget(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    hand* me = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    hand subtarget;
    instance->getSubTarget(*me, subtarget);
    return HandBinding::push(L, subtarget);
}

int BlackboardBinding::addRequest(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    hand* from = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    hand* to = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    TaskType key = (TaskType)luaL_checkinteger(L, 4);
    hand* subject = checkObject<hand>(L, 5, HandBinding::getMetatableName());
    taskPriority pri = (taskPriority)luaL_checkinteger(L, 6);
    float weight = (float)luaL_checknumber(L, 7);
    instance->addRequest(*from, *to, key, *subject, pri, weight);
    return 0;
}

int BlackboardBinding::removeRequest(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    hand* from = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->removeRequest(*from);
    return 0;
}

int BlackboardBinding::notifyJobCompleted(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    TaskType key = (TaskType)luaL_checkinteger(L, 2);
    hand* subj = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    hand* me = checkObject<hand>(L, 4, HandBinding::getMetatableName());
    instance->notifyJobCompleted(key, *subj, *me);
    return 0;
}

int BlackboardBinding::addSquadJob(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    SquadMemberType type = (SquadMemberType)luaL_checkinteger(L, 2);
    TaskType key = (TaskType)luaL_checkinteger(L, 3);
    hand* subject = checkObject<hand>(L, 4, HandBinding::getMetatableName());
    taskPriority pri = (taskPriority)luaL_checkinteger(L, 5);
    float weight = (float)luaL_checknumber(L, 6);
    TaskTargetType targeting = (TaskTargetType)luaL_checkinteger(L, 7);
    TaskEndEvent ending = (TaskEndEvent)luaL_checkinteger(L, 8);
    int startTime = (int)luaL_checkinteger(L, 9);
    int endTime = (int)luaL_checkinteger(L, 10);
    instance->addSquadJob(type, key, *subject, pri, weight, targeting, ending, startTime, endTime);
    return 0;
}

int BlackboardBinding::getUnloadedPlatoonJob(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    UnloadedPlatoonJob result = instance->getUnloadedPlatoonJob();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BlackboardBinding::clearAllTheJobs(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    instance->clearAllTheJobs();
    return 0;
}

int BlackboardBinding::serialise(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->serialise(state);
    return 0;
}

int BlackboardBinding::load(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->load(state);
    return 0;
}

int BlackboardBinding::stateUpdate(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    instance->stateUpdate(frameTime);
    return 0;
}

int BlackboardBinding::notifyMissionTargetPathfindImpossible(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    Character* forWho = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    hand* target = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    instance->notifyMissionTargetPathfindImpossible(forWho, *target);
    return 0;
}

int BlackboardBinding::getMissionTown(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    bool getHometownAsFallback = lua_toboolean(L, 2) != 0;
    hand result = instance->getMissionTown(getHometownAsFallback);
    return HandBinding::push(L, result);
}

int BlackboardBinding::getMissionGiver(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    hand result = instance->getMissionGiver();
    return HandBinding::push(L, result);
}

int BlackboardBinding::getCurrentTownLocation(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    TownBase* result = instance->getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int BlackboardBinding::getTimeSpentInTown_inGameHours(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    float result = instance->getTimeSpentInTown_inGameHours();
    lua_pushnumber(L, result);
    return 1;
}

int BlackboardBinding::setMyHomeIsLocked(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setMyHomeIsLocked(on);
    return 0;
}

int BlackboardBinding::getMyHomeIsLocked(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    bool result = instance->getMyHomeIsLocked();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BlackboardBinding::getHomeGate(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    hand result = instance->getHomeGate();
    return HandBinding::push(L, result);
}

int BlackboardBinding::hasContractJob(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    bool result = instance->hasContractJob();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BlackboardBinding::getContractExpiryTime(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    TimeOfDay result = instance->getContractExpiryTime();
    return pushValue<TimeOfDay>(L, result, TimeOfDayBinding::getMetatableName());
}

int BlackboardBinding::contractJobNotifyBetrayal(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    Character* myWitness = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Character* betrayer = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    instance->contractJobNotifyBetrayal(myWitness, betrayer);
    return 0;
}

int BlackboardBinding::contractJobWasBetrayal(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    bool result = instance->contractJobWasBetrayal();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BlackboardBinding::showEndedMessage(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    instance->showEndedMessage();
    return 0;
}

int BlackboardBinding::_NV_showEndedMessage(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    instance->_NV_showEndedMessage();
    return 0;
}

int BlackboardBinding::_setupJobFromData(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    std::string listname = luaL_checkstring(L, 3);
    SquadMemberType listEnum = (SquadMemberType)luaL_checkinteger(L, 4);
    instance->_setupJobFromData(data, listname, listEnum);
    return 0;
}

int BlackboardBinding::countCharacters(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    instance->countCharacters();
    return 0;
}

int BlackboardBinding::runAwayCheck(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    instance->runAwayCheck();
    return 0;
}

int BlackboardBinding::runAway(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    instance->runAway();
    return 0;
}

int BlackboardBinding::buildFormation(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    instance->buildFormation();
    return 0;
}

// positions is an out-parameter and is returned as an array of Vector3 tables.
int BlackboardBinding::getGridPositions(lua_State* L)
{
    Blackboard* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard is nil");

    int gridWidth = (int)luaL_checkinteger(L, 2);
    int gridHeight = (int)luaL_checkinteger(L, 3);
    int size = (int)luaL_checkinteger(L, 4);
    float initialX = (float)luaL_checknumber(L, 5);
    float radius = (float)luaL_checknumber(L, 6);
    float spacingX = (float)luaL_checknumber(L, 7);
    float spacingZ = (float)luaL_checknumber(L, 8);
    Ogre::vector<Ogre::Vector3>::type positions;
    instance->getGridPositions(positions, gridWidth, gridHeight, size, initialX, radius, spacingX, spacingZ);
    lua_createtable(L, (int)positions.size(), 0);
    for (size_t i = 0; i < positions.size(); ++i)
    {
        pushVector3(L, positions[i]);
        lua_rawseti(L, -2, (int)(i + 1));
    }
    return 1;
}

/*
Skipped properties needing manual binding:
  line 60: packagesMain (ogre_unordered_map<int, lektor<AIPackage*>>::type) - no container binding; getPackageList(type) returns the same lists
  line 158: requests (ogre_unordered_map<hand, TaskRequest>::type) - TaskRequest is unbound
  line 159-163: leaderJobs, squadJobs, squadJobs2, signalJobs, slaveJobs (lektor<TaskRequest>) - TaskRequest is unbound
  line 180: currentTasks (ogre_unordered_map<hand, Blackboard::TaskInfo>::type) - Blackboard::TaskInfo is unbound
Read-only properties:
  contractJob - endContractJob and ~Blackboard delete it, so assigning another package would free it twice
  actionTargets, characterFormationPosition - containers are edited in place; whole-container assignment is not bound

Skipped methods needing manual binding:
  line 73: resetAllTheStaticData() - static engine reset of Blackboard's shared data
  line 81-84: Blackboard(Platoon*), _CONSTRUCTOR, ~Blackboard, _DESTRUCTOR - owned by Platoon (created in Platoon's constructor, deleted in ~Platoon)
  line 110: getRequests(...) - TaskRepertoire* (unbound pointer)
  line 114: getSquadJobs(...) - TaskRepertoire* (unbound pointer)
  line 126: getMissionTarget(...) - TargetInfo return (unbound type)
  line 149: _serialiseJobList(...) - lektor<TaskRequest> (TaskRequest is unbound)
  line 150: _loadJobList(...) - lektor<TaskRequest> (TaskRequest is unbound)
  line 166: getJobList(...) - lektor<TaskRequest>* return (TaskRequest is unbound)
*/

int BlackboardBinding::gc(lua_State* L)
{
    // Borrowed from the owning Platoon
    return 0;
}

int BlackboardBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Blackboard object");
    return 1;
}

void BlackboardBinding::registerBinding(lua_State* L)
{
    LektorPtrBinding<AIPackage*>::registerBinding(L, "lektor<AIPackage*>", AIPackageBinding::getMetatableName());
    TaskTypeHandMapBinding::registerBinding(L, "ogre_unordered_map<TaskType, hand>");
    HandVector3MapBinding::registerBinding(L, "ogre_unordered_map<hand, Vector3>", HandBinding::getMetatableName());

    static const luaL_Reg meta[] = {
        { "__gc",       BlackboardBinding::gc },
        { "__tostring", BlackboardBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "createNewPackage", BlackboardBinding::createNewPackage },
        { "_setContractJob", BlackboardBinding::_setContractJob },
        { "_addPackage", BlackboardBinding::_addPackage },
        { "clearAllPackages", BlackboardBinding::clearAllPackages },
        { "_activateCurrentPackage", BlackboardBinding::_activateCurrentPackage },
        { "_addFromData", BlackboardBinding::_addFromData },
        { "getPackage", BlackboardBinding::getPackage },
        { "getPackageList", BlackboardBinding::getPackageList },
        { "periodicPackageCheck", BlackboardBinding::periodicPackageCheck },
        { "dialogEventsCheck", BlackboardBinding::dialogEventsCheck },
        { "setContractJob", BlackboardBinding::setContractJob },
        { "endContractJob", BlackboardBinding::endContractJob },
        { "isMissionComplete", BlackboardBinding::isMissionComplete },
        { "isTargetMarkedForDeath", BlackboardBinding::isTargetMarkedForDeath },
        { "update", BlackboardBinding::update },
        { "periodicUpdate", BlackboardBinding::periodicUpdate },
        { "addPackages", BlackboardBinding::addPackages },
        { "addFallbackPackages", BlackboardBinding::addFallbackPackages },
        { "replaceAIPackage", BlackboardBinding::replaceAIPackage },
        { "getCurrentAIPackageName", BlackboardBinding::getCurrentAIPackageName },
        { "getCurrentAIPackageGUIData", BlackboardBinding::getCurrentAIPackageGUIData },
        { "assessNeutral", BlackboardBinding::assessNeutral },
        { "assessEnemy", BlackboardBinding::assessEnemy },
        { "getCurrentPackage", BlackboardBinding::getCurrentPackage },
        { "getFormationPositionOffset", BlackboardBinding::getFormationPositionOffset },
        { "nodifyFormationUpdate", BlackboardBinding::nodifyFormationUpdate },
        { "getOwnerships", BlackboardBinding::getOwnerships },
        { "notifyGoalStart", BlackboardBinding::notifyGoalStart },
        { "notifyGoalEnd", BlackboardBinding::notifyGoalEnd },
        { "notifySubTarget", BlackboardBinding::notifySubTarget },
        { "howManyGuysDoingThisGoal", BlackboardBinding::howManyGuysDoingThisGoal },
        { "howManyGuysWorkingOnThisSubTarget", BlackboardBinding::howManyGuysWorkingOnThisSubTarget },
        { "isMySubTarget", BlackboardBinding::isMySubTarget },
        { "getSubTarget", BlackboardBinding::getSubTarget },
        { "addRequest", BlackboardBinding::addRequest },
        { "removeRequest", BlackboardBinding::removeRequest },
        { "notifyJobCompleted", BlackboardBinding::notifyJobCompleted },
        { "addSquadJob", BlackboardBinding::addSquadJob },
        { "getUnloadedPlatoonJob", BlackboardBinding::getUnloadedPlatoonJob },
        { "clearAllTheJobs", BlackboardBinding::clearAllTheJobs },
        { "serialise", BlackboardBinding::serialise },
        { "load", BlackboardBinding::load },
        { "stateUpdate", BlackboardBinding::stateUpdate },
        { "notifyMissionTargetPathfindImpossible", BlackboardBinding::notifyMissionTargetPathfindImpossible },
        { "getMissionTown", BlackboardBinding::getMissionTown },
        { "getMissionGiver", BlackboardBinding::getMissionGiver },
        { "getCurrentTownLocation", BlackboardBinding::getCurrentTownLocation },
        { "getTimeSpentInTown_inGameHours", BlackboardBinding::getTimeSpentInTown_inGameHours },
        { "setMyHomeIsLocked", BlackboardBinding::setMyHomeIsLocked },
        { "getMyHomeIsLocked", BlackboardBinding::getMyHomeIsLocked },
        { "getHomeGate", BlackboardBinding::getHomeGate },
        { "hasContractJob", BlackboardBinding::hasContractJob },
        { "getContractExpiryTime", BlackboardBinding::getContractExpiryTime },
        { "contractJobNotifyBetrayal", BlackboardBinding::contractJobNotifyBetrayal },
        { "contractJobWasBetrayal", BlackboardBinding::contractJobWasBetrayal },
        { "showEndedMessage", BlackboardBinding::showEndedMessage },
        { "_NV_showEndedMessage", BlackboardBinding::_NV_showEndedMessage },
        { "_setupJobFromData", BlackboardBinding::_setupJobFromData },
        { "countCharacters", BlackboardBinding::countCharacters },
        { "runAwayCheck", BlackboardBinding::runAwayCheck },
        { "runAway", BlackboardBinding::runAway },
        { "buildFormation", BlackboardBinding::buildFormation },
        { "getGridPositions", BlackboardBinding::getGridPositions },
        { 0, 0 }
    };

    registerClass(
        L,
        BlackboardBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BlackboardBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "currentPackage", Blackboard_get_currentPackage);
    registerGetter(L, "currentPackagePriorityLevel", Blackboard_get_currentPackagePriorityLevel);
    registerGetter(L, "replacementAIPackageSID", Blackboard_get_replacementAIPackageSID);
    registerGetter(L, "cageMarkedForDeath", Blackboard_get_cageMarkedForDeath);
    registerGetter(L, "squad", Blackboard_get_squad);
    registerGetter(L, "actionTargets", Blackboard_get_actionTargets);
    registerGetter(L, "homeIsLockedUp", Blackboard_get_homeIsLockedUp);
    registerGetter(L, "targetTown", Blackboard_get_targetTown);
    registerGetter(L, "targetZoneHunting", Blackboard_get_targetZoneHunting);
    registerGetter(L, "missionData", Blackboard_get_missionData);
    registerGetter(L, "moraleIsBroken", Blackboard_get_moraleIsBroken);
    registerGetter(L, "_homeGateTarget", Blackboard_get__homeGateTarget);
    registerGetter(L, "_flagCleared", Blackboard_get__flagCleared);
    registerGetter(L, "needsStateUpdate", Blackboard_get_needsStateUpdate);
    registerGetter(L, "currentTownLocation", Blackboard_get_currentTownLocation);
    registerGetter(L, "townArrivalTime", Blackboard_get_townArrivalTime);
    registerGetter(L, "HIGHEST_PRIORITY_LEVEL", Blackboard_get_HIGHEST_PRIORITY_LEVEL);
    registerGetter(L, "runningAwayMode", Blackboard_get_runningAwayMode);
    registerGetter(L, "characterCount", Blackboard_get_characterCount);
    registerGetter(L, "enemyCount", Blackboard_get_enemyCount);
    registerGetter(L, "contractJob", Blackboard_get_contractJob);
    registerGetter(L, "contractExpiryTime", Blackboard_get_contractExpiryTime);
    registerGetter(L, "formationNeedUpdate", Blackboard_get_formationNeedUpdate);
    registerGetter(L, "characterFormationPosition", Blackboard_get_characterFormationPosition);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "currentPackage", Blackboard_set_currentPackage);
    registerSetter(L, "currentPackagePriorityLevel", Blackboard_set_currentPackagePriorityLevel);
    registerSetter(L, "replacementAIPackageSID", Blackboard_set_replacementAIPackageSID);
    registerSetter(L, "cageMarkedForDeath", Blackboard_set_cageMarkedForDeath);
    registerSetter(L, "squad", Blackboard_set_squad);
    registerSetter(L, "homeIsLockedUp", Blackboard_set_homeIsLockedUp);
    registerSetter(L, "targetTown", Blackboard_set_targetTown);
    registerSetter(L, "targetZoneHunting", Blackboard_set_targetZoneHunting);
    registerSetter(L, "missionData", Blackboard_set_missionData);
    registerSetter(L, "moraleIsBroken", Blackboard_set_moraleIsBroken);
    registerSetter(L, "_homeGateTarget", Blackboard_set__homeGateTarget);
    registerSetter(L, "_flagCleared", Blackboard_set__flagCleared);
    registerSetter(L, "needsStateUpdate", Blackboard_set_needsStateUpdate);
    registerSetter(L, "currentTownLocation", Blackboard_set_currentTownLocation);
    registerSetter(L, "townArrivalTime", Blackboard_set_townArrivalTime);
    registerSetter(L, "HIGHEST_PRIORITY_LEVEL", Blackboard_set_HIGHEST_PRIORITY_LEVEL);
    registerSetter(L, "runningAwayMode", Blackboard_set_runningAwayMode);
    registerSetter(L, "characterCount", Blackboard_set_characterCount);
    registerSetter(L, "enemyCount", Blackboard_set_enemyCount);
    registerSetter(L, "contractExpiryTime", Blackboard_set_contractExpiryTime);
    registerSetter(L, "formationNeedUpdate", Blackboard_set_formationNeedUpdate);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
