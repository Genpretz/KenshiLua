#include "pch.h"
#include "CampaignInstanceBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/AI/TargetInfoBinding.h"
#include "Bindings/Kenshi/CampaignDataBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/PlatoonBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/Util/TimeOfDayBinding.h"

namespace KenshiLua
{

// Field accessors index engine-owned instances; offsets checked against the constructor (RVA 0x9D2FC0).
static_assert(offsetof(CampaignInstance, uniqueID) == 0x8, "CampaignInstance::uniqueID offset does not match the game");
static_assert(offsetof(CampaignInstance, me) == 0x70, "CampaignInstance::me offset does not match the game");
static_assert(offsetof(CampaignInstance, currentPhase) == 0xC0, "CampaignInstance::currentPhase offset does not match the game");
static_assert(offsetof(CampaignInstance, membersInOrder) == 0xC8, "CampaignInstance::membersInOrder offset does not match the game");

static CampaignInstance* getInstance(lua_State* L, int idx)
{
    return checkObject<CampaignInstance>(L, idx, CampaignInstanceBinding::getMetatableName());
}

// --- Getters for CampaignInstance ---
static int CampaignInstance_get_uniqueID(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    lua_pushinteger(L, instance->uniqueID);
    return 1;
}

static int CampaignInstance_get_myData(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    return pushObject<CampaignData>(L, instance->myData, CampaignDataBinding::getMetatableName());
}

static int CampaignInstance_get_phaseChangeTime(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    return pushObject<TimeOfDay>(L, &instance->phaseChangeTime, TimeOfDayBinding::getMetatableName());
}

static int CampaignInstance_get_timeWithNoEnemies(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    return pushObject<TimeOfDay>(L, &instance->timeWithNoEnemies, TimeOfDayBinding::getMetatableName());
}

static int CampaignInstance_get_travelSpeedUnloaded(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    lua_pushinteger(L, (lua_Integer)instance->travelSpeedUnloaded);
    return 1;
}

static int CampaignInstance_get_travelSpeedLoaded(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    lua_pushinteger(L, (lua_Integer)instance->travelSpeedLoaded);
    return 1;
}

static int CampaignInstance_get_manPowerMin(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    lua_pushinteger(L, instance->manPowerMin);
    return 1;
}

static int CampaignInstance_get_manPowerMax(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    lua_pushinteger(L, instance->manPowerMax);
    return 1;
}

static int CampaignInstance_get_manPowerLastCount(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    lua_pushinteger(L, instance->manPowerLastCount);
    return 1;
}

static int CampaignInstance_get_reachedDestination(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    lua_pushboolean(L, instance->reachedDestination ? 1 : 0);
    return 1;
}

static int CampaignInstance_get_hasTriggeredSomething(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    lua_pushboolean(L, instance->hasTriggeredSomething ? 1 : 0);
    return 1;
}

static int CampaignInstance_get__target(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    return pushObject<TargetInfo>(L, &instance->_target, TargetInfoBinding::getMetatableName());
}

static int CampaignInstance_get_me(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    return pushObject<Faction>(L, instance->me, FactionBinding::getMetatableName());
}

static int CampaignInstance_get_enemy(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    return pushObject<Faction>(L, instance->enemy, FactionBinding::getMetatableName());
}

static int CampaignInstance_get_leader(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    return HandBinding::push(L, instance->leader);
}

static int CampaignInstance_get_homeTown(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    return HandBinding::push(L, instance->homeTown);
}

static int CampaignInstance_get_currentPhase(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentPhase);
    return 1;
}

static int CampaignInstance_get_canTalkToBeforeArrival(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    lua_pushboolean(L, instance->canTalkToBeforeArrival ? 1 : 0);
    return 1;
}

static int CampaignInstance_get_membersInOrder(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    return pushObject<lektor<hand> >(L, &instance->membersInOrder, LektorValueReadOnlyBinding<hand>::metaName);
}

// --- Setters for CampaignInstance ---
static int CampaignInstance_set_uniqueID(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->uniqueID = (int)luaL_checkinteger(L, 2);
    return 0;
}

// The constructor and isEnemy dereference myData without a null check.
static int CampaignInstance_set_myData(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->myData = checkObject<CampaignData>(L, 2, CampaignDataBinding::getMetatableName());
    return 0;
}

static int CampaignInstance_set_phaseChangeTime(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->phaseChangeTime = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int CampaignInstance_set_timeWithNoEnemies(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->timeWithNoEnemies = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int CampaignInstance_set_travelSpeedUnloaded(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->travelSpeedUnloaded = (MoveSpeed)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignInstance_set_travelSpeedLoaded(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->travelSpeedLoaded = (MoveSpeed)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignInstance_set_manPowerMin(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->manPowerMin = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignInstance_set_manPowerMax(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->manPowerMax = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignInstance_set_manPowerLastCount(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->manPowerLastCount = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignInstance_set_reachedDestination(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->reachedDestination = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CampaignInstance_set_hasTriggeredSomething(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->hasTriggeredSomething = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CampaignInstance_set__target(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->_target = *checkObject<TargetInfo>(L, 2, TargetInfoBinding::getMetatableName());
    return 0;
}

// lossEvent reads me->warManager without a null check.
static int CampaignInstance_set_me(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->me = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

// FactionWarMgr::triggerCampaign reads enemy without a null check.
static int CampaignInstance_set_enemy(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->enemy = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int CampaignInstance_set_leader(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->leader = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int CampaignInstance_set_homeTown(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->homeTown = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int CampaignInstance_set_currentPhase(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->currentPhase = (Phase)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignInstance_set_canTalkToBeforeArrival(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");
    instance->canTalkToBeforeArrival = lua_toboolean(L, 2) != 0;
    return 0;
}

int CampaignInstanceBinding::getData(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    CampaignData* result = instance->getData();
    return pushObject<CampaignData>(L, result, CampaignDataBinding::getMetatableName());
}

int CampaignInstanceBinding::changePhase(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Phase p = (Phase)luaL_checkinteger(L, 2);
    instance->changePhase(p);
    return 0;
}

int CampaignInstanceBinding::saveState(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    GameData* s = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int id = (int)luaL_checkinteger(L, 3);
    instance->saveState(s, id);
    return 0;
}

int CampaignInstanceBinding::loadState(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    GameData* s = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int id = (int)luaL_checkinteger(L, 3);
    instance->loadState(s, id);
    return 0;
}

int CampaignInstanceBinding::markOnMap(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    instance->markOnMap();
    return 0;
}

int CampaignInstanceBinding::_NV_markOnMap(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    instance->_NV_markOnMap();
    return 0;
}

int CampaignInstanceBinding::getDialogData(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    EventTriggerEnum ev = (EventTriggerEnum)luaL_checkinteger(L, 2);
    GameData* result = instance->getDialogData(ev);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CampaignInstanceBinding::hasSufficientManpower(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    bool result = instance->hasSufficientManpower();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CampaignInstanceBinding::victoryEvent(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    instance->victoryEvent();
    return 0;
}

int CampaignInstanceBinding::_NV_victoryEvent(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    instance->_NV_victoryEvent();
    return 0;
}

int CampaignInstanceBinding::lossEvent(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    instance->lossEvent();
    return 0;
}

int CampaignInstanceBinding::_NV_lossEvent(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    instance->_NV_lossEvent();
    return 0;
}

int CampaignInstanceBinding::setLeader(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->setLeader(*h);
    return 0;
}

int CampaignInstanceBinding::_NV_setLeader(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->_NV_setLeader(*h);
    return 0;
}

int CampaignInstanceBinding::getLeader(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Character* result = instance->getLeader();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int CampaignInstanceBinding::_NV_getLeader(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Character* result = instance->_NV_getLeader();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int CampaignInstanceBinding::getLeaderPlatoon(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* result = instance->getLeaderPlatoon();
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int CampaignInstanceBinding::_NV_getLeaderPlatoon(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* result = instance->_NV_getLeaderPlatoon();
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

// isEnemy calls who->getFaction() through the vtable, so who cannot be nil.
int CampaignInstanceBinding::isEnemy(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->isEnemy(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CampaignInstanceBinding::_NV_isEnemy(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->_NV_isEnemy(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CampaignInstanceBinding::getName(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    std::string result = instance->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int CampaignInstanceBinding::_NV_getName(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    std::string result = instance->_NV_getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int CampaignInstanceBinding::setup(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    bool result = instance->setup();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CampaignInstanceBinding::_NV_setup(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    bool result = instance->_NV_setup();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CampaignInstanceBinding::periodicUpdate(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    instance->periodicUpdate();
    return 0;
}

int CampaignInstanceBinding::_NV_periodicUpdate(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    instance->_NV_periodicUpdate();
    return 0;
}

int CampaignInstanceBinding::isEverybodyIdle(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    bool result = instance->isEverybodyIdle();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CampaignInstanceBinding::_NV_isEverybodyIdle(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    bool result = instance->_NV_isEverybodyIdle();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CampaignInstanceBinding::getUnloadedPlatoonBehavior(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    UnloadedPlatoonJob result = instance->getUnloadedPlatoonBehavior(who);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CampaignInstanceBinding::_NV_getUnloadedPlatoonBehavior(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    UnloadedPlatoonJob result = instance->_NV_getUnloadedPlatoonBehavior(who);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CampaignInstanceBinding::getAIPackage(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    GameData* result = instance->getAIPackage(who);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CampaignInstanceBinding::_NV_getAIPackage(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    GameData* result = instance->_NV_getAIPackage(who);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CampaignInstanceBinding::addToCampaign(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    bool forceLeader = lua_toboolean(L, 3) != 0;
    instance->addToCampaign(who, forceLeader);
    return 0;
}

int CampaignInstanceBinding::_NV_addToCampaign(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    bool forceLeader = lua_toboolean(L, 3) != 0;
    instance->_NV_addToCampaign(who, forceLeader);
    return 0;
}

int CampaignInstanceBinding::areForcesAllTogether(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    bool result = instance->areForcesAllTogether();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CampaignInstanceBinding::_NV_areForcesAllTogether(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    bool result = instance->_NV_areForcesAllTogether();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CampaignInstanceBinding::removeFromCampaign(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->removeFromCampaign(who);
    return 0;
}

int CampaignInstanceBinding::_NV_removeFromCampaign(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->_NV_removeFromCampaign(who);
    return 0;
}

int CampaignInstanceBinding::getAITarget(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    TargetInfo result = instance->getAITarget(who);
    return pushValue<TargetInfo>(L, result, TargetInfoBinding::getMetatableName());
}

int CampaignInstanceBinding::_NV_getAITarget(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    TargetInfo result = instance->_NV_getAITarget(who);
    return pushValue<TargetInfo>(L, result, TargetInfoBinding::getMetatableName());
}

int CampaignInstanceBinding::getMoveSpeedUnloaded(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    MoveSpeed result = instance->getMoveSpeedUnloaded();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CampaignInstanceBinding::_NV_getMoveSpeedUnloaded(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    MoveSpeed result = instance->_NV_getMoveSpeedUnloaded();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CampaignInstanceBinding::getMoveSpeedLoaded(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    MoveSpeed result = instance->getMoveSpeedLoaded();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CampaignInstanceBinding::_NV_getMoveSpeedLoaded(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    MoveSpeed result = instance->_NV_getMoveSpeedLoaded();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CampaignInstanceBinding::getTargetTown(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    hand result = instance->getTargetTown();
    return HandBinding::push(L, result);
}

int CampaignInstanceBinding::_NV_getTargetTown(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    hand result = instance->_NV_getTargetTown();
    return HandBinding::push(L, result);
}

// Pure virtual in CampaignInstance; dispatched to the subclass through the vtable (slot 0xA8).
int CampaignInstanceBinding::getFormationPosition(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    Ogre::Vector3 result = instance->getFormationPosition(who);
    pushVector3(L, result);
    return 1;
}

int CampaignInstanceBinding::getDestination(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    Ogre::Vector3 result = instance->getDestination(who);
    pushVector3(L, result);
    return 1;
}

int CampaignInstanceBinding::_NV_getDestination(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    Ogre::Vector3 result = instance->_NV_getDestination(who);
    pushVector3(L, result);
    return 1;
}

// Pure virtual in CampaignInstance; dispatched to the subclass through the vtable (slot 0xB8).
int CampaignInstanceBinding::isSuccessful(lua_State* L)
{
    CampaignInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignInstance is nil");

    bool result = instance->isSuccessful();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 122: CampaignInstance(...) - FactionWarMgr creates campaigns through CampaignData::createCampaign
  line 123: _CONSTRUCTOR(...) - see above
  line 124: ~CampaignInstance() - FactionWarMgr::endCampaign destroys campaigns
  line 125: _DESTRUCTOR() - see above
Read-only properties:
  membersInOrder (lektor<hand>) - KenshiLib's lektor has no deep copy, so assignment would alias the engine's buffer
*/

int CampaignInstanceBinding::gc(lua_State* L)
{
    // Borrowed from the owning FactionWarMgr
    return 0;
}

int CampaignInstanceBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CampaignInstance object");
    return 1;
}

void CampaignInstanceBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CampaignInstanceBinding::gc },
        { "__tostring", CampaignInstanceBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getData", CampaignInstanceBinding::getData },
        { "changePhase", CampaignInstanceBinding::changePhase },
        { "saveState", CampaignInstanceBinding::saveState },
        { "loadState", CampaignInstanceBinding::loadState },
        { "markOnMap", CampaignInstanceBinding::markOnMap },
        { "_NV_markOnMap", CampaignInstanceBinding::_NV_markOnMap },
        { "getDialogData", CampaignInstanceBinding::getDialogData },
        { "hasSufficientManpower", CampaignInstanceBinding::hasSufficientManpower },
        { "victoryEvent", CampaignInstanceBinding::victoryEvent },
        { "_NV_victoryEvent", CampaignInstanceBinding::_NV_victoryEvent },
        { "lossEvent", CampaignInstanceBinding::lossEvent },
        { "_NV_lossEvent", CampaignInstanceBinding::_NV_lossEvent },
        { "setLeader", CampaignInstanceBinding::setLeader },
        { "_NV_setLeader", CampaignInstanceBinding::_NV_setLeader },
        { "getLeader", CampaignInstanceBinding::getLeader },
        { "_NV_getLeader", CampaignInstanceBinding::_NV_getLeader },
        { "getLeaderPlatoon", CampaignInstanceBinding::getLeaderPlatoon },
        { "_NV_getLeaderPlatoon", CampaignInstanceBinding::_NV_getLeaderPlatoon },
        { "isEnemy", CampaignInstanceBinding::isEnemy },
        { "_NV_isEnemy", CampaignInstanceBinding::_NV_isEnemy },
        { "getName", CampaignInstanceBinding::getName },
        { "_NV_getName", CampaignInstanceBinding::_NV_getName },
        { "setup", CampaignInstanceBinding::setup },
        { "_NV_setup", CampaignInstanceBinding::_NV_setup },
        { "periodicUpdate", CampaignInstanceBinding::periodicUpdate },
        { "_NV_periodicUpdate", CampaignInstanceBinding::_NV_periodicUpdate },
        { "isEverybodyIdle", CampaignInstanceBinding::isEverybodyIdle },
        { "_NV_isEverybodyIdle", CampaignInstanceBinding::_NV_isEverybodyIdle },
        { "getUnloadedPlatoonBehavior", CampaignInstanceBinding::getUnloadedPlatoonBehavior },
        { "_NV_getUnloadedPlatoonBehavior", CampaignInstanceBinding::_NV_getUnloadedPlatoonBehavior },
        { "getAIPackage", CampaignInstanceBinding::getAIPackage },
        { "_NV_getAIPackage", CampaignInstanceBinding::_NV_getAIPackage },
        { "addToCampaign", CampaignInstanceBinding::addToCampaign },
        { "_NV_addToCampaign", CampaignInstanceBinding::_NV_addToCampaign },
        { "areForcesAllTogether", CampaignInstanceBinding::areForcesAllTogether },
        { "_NV_areForcesAllTogether", CampaignInstanceBinding::_NV_areForcesAllTogether },
        { "removeFromCampaign", CampaignInstanceBinding::removeFromCampaign },
        { "_NV_removeFromCampaign", CampaignInstanceBinding::_NV_removeFromCampaign },
        { "getAITarget", CampaignInstanceBinding::getAITarget },
        { "_NV_getAITarget", CampaignInstanceBinding::_NV_getAITarget },
        { "getMoveSpeedUnloaded", CampaignInstanceBinding::getMoveSpeedUnloaded },
        { "_NV_getMoveSpeedUnloaded", CampaignInstanceBinding::_NV_getMoveSpeedUnloaded },
        { "getMoveSpeedLoaded", CampaignInstanceBinding::getMoveSpeedLoaded },
        { "_NV_getMoveSpeedLoaded", CampaignInstanceBinding::_NV_getMoveSpeedLoaded },
        { "getTargetTown", CampaignInstanceBinding::getTargetTown },
        { "_NV_getTargetTown", CampaignInstanceBinding::_NV_getTargetTown },
        { "getFormationPosition", CampaignInstanceBinding::getFormationPosition },
        { "getDestination", CampaignInstanceBinding::getDestination },
        { "_NV_getDestination", CampaignInstanceBinding::_NV_getDestination },
        { "isSuccessful", CampaignInstanceBinding::isSuccessful },
        { 0, 0 }
    };

    registerClass(
        L,
        CampaignInstanceBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CampaignInstanceBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "uniqueID", CampaignInstance_get_uniqueID);
    registerGetter(L, "myData", CampaignInstance_get_myData);
    registerGetter(L, "phaseChangeTime", CampaignInstance_get_phaseChangeTime);
    registerGetter(L, "timeWithNoEnemies", CampaignInstance_get_timeWithNoEnemies);
    registerGetter(L, "travelSpeedUnloaded", CampaignInstance_get_travelSpeedUnloaded);
    registerGetter(L, "travelSpeedLoaded", CampaignInstance_get_travelSpeedLoaded);
    registerGetter(L, "manPowerMin", CampaignInstance_get_manPowerMin);
    registerGetter(L, "manPowerMax", CampaignInstance_get_manPowerMax);
    registerGetter(L, "manPowerLastCount", CampaignInstance_get_manPowerLastCount);
    registerGetter(L, "reachedDestination", CampaignInstance_get_reachedDestination);
    registerGetter(L, "hasTriggeredSomething", CampaignInstance_get_hasTriggeredSomething);
    registerGetter(L, "_target", CampaignInstance_get__target);
    registerGetter(L, "me", CampaignInstance_get_me);
    registerGetter(L, "enemy", CampaignInstance_get_enemy);
    registerGetter(L, "leader", CampaignInstance_get_leader);
    registerGetter(L, "homeTown", CampaignInstance_get_homeTown);
    registerGetter(L, "currentPhase", CampaignInstance_get_currentPhase);
    registerGetter(L, "canTalkToBeforeArrival", CampaignInstance_get_canTalkToBeforeArrival);
    registerGetter(L, "membersInOrder", CampaignInstance_get_membersInOrder);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "uniqueID", CampaignInstance_set_uniqueID);
    registerSetter(L, "myData", CampaignInstance_set_myData);
    registerSetter(L, "phaseChangeTime", CampaignInstance_set_phaseChangeTime);
    registerSetter(L, "timeWithNoEnemies", CampaignInstance_set_timeWithNoEnemies);
    registerSetter(L, "travelSpeedUnloaded", CampaignInstance_set_travelSpeedUnloaded);
    registerSetter(L, "travelSpeedLoaded", CampaignInstance_set_travelSpeedLoaded);
    registerSetter(L, "manPowerMin", CampaignInstance_set_manPowerMin);
    registerSetter(L, "manPowerMax", CampaignInstance_set_manPowerMax);
    registerSetter(L, "manPowerLastCount", CampaignInstance_set_manPowerLastCount);
    registerSetter(L, "reachedDestination", CampaignInstance_set_reachedDestination);
    registerSetter(L, "hasTriggeredSomething", CampaignInstance_set_hasTriggeredSomething);
    registerSetter(L, "_target", CampaignInstance_set__target);
    registerSetter(L, "me", CampaignInstance_set_me);
    registerSetter(L, "enemy", CampaignInstance_set_enemy);
    registerSetter(L, "leader", CampaignInstance_set_leader);
    registerSetter(L, "homeTown", CampaignInstance_set_homeTown);
    registerSetter(L, "currentPhase", CampaignInstance_set_currentPhase);
    registerSetter(L, "canTalkToBeforeArrival", CampaignInstance_set_canTalkToBeforeArrival);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
