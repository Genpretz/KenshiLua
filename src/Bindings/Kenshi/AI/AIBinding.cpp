#include "pch.h"
#include "AIBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/AI/BlackboardBinding.h"
#include "Bindings/Kenshi/Building/BuildingBinding.h"
#include "Bindings/Kenshi/Building/StorageBuildingBinding.h"
#include "Bindings/Kenshi/Building/UseableStuffBinding.h"
#include "Bindings/Kenshi/CharBodyBinding.h"
#include "Bindings/Kenshi/CharStatsBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/InventoryBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/Kenshi/MedicalSystemBinding.h"
#include "Bindings/Kenshi/PlatoonBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/RootObjectBaseBinding.h"
#include "Bindings/Kenshi/SensoryDataBinding.h"
#include "Bindings/Kenshi/StateBroadcastDataBinding.h"
#include "Bindings/Kenshi/TaskStateDataBinding.h"
#include "Bindings/Kenshi/TownBaseBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

// Field accessors index engine-owned AI objects; these catch SensoryData and AIResultsCacher size drift.
static_assert(offsetof(AI, taskRepertoireFlags) == 0x200, "AI::taskRepertoireFlags offset does not match the game");
static_assert(offsetof(AI, taskRepertoire) == 0x2A8, "AI::taskRepertoire offset does not match the game");
static_assert(offsetof(AI, me) == 0x2F8, "AI::me offset does not match the game");

static AI* getInstance(lua_State* L, int idx)
{
    return checkObject<AI>(L, idx, AIBinding::getMetatableName());
}

// --- Getters for AI ---
static int AI_get_meiDistance(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    lua_pushnumber(L, instance->meiDistance);
    return 1;
}

static int AI_get_meiDistanceTolerance(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    lua_pushnumber(L, instance->meiDistanceTolerance);
    return 1;
}

static int AI_get_platoon(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    return pushObject<Platoon>(L, instance->platoon, PlatoonBinding::getMetatableName());
}

static int AI_get_state(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    return pushObject<StateBroadcastData>(L, instance->state, StateBroadcastDataBinding::getMetatableName());
}

static int AI_get_sensoryData(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    return pushObject<SensoryData>(L, &instance->sensoryData, SensoryDataBinding::getMetatableName());
}

static int AI_get_taskRepertoireFlags(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    lua_pushinteger(L, (lua_Integer)instance->taskRepertoireFlags);
    return 1;
}

static int AI_get_ordersAggression(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    lua_pushinteger(L, (lua_Integer)instance->ordersAggression);
    return 1;
}

static int AI_get_ordersMovement(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    lua_pushinteger(L, (lua_Integer)instance->ordersMovement);
    return 1;
}

static int AI_get_centerOfMovement(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    pushVector3(L, instance->centerOfMovement);
    return 1;
}

static int AI_get_centerOfMovementTarget(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    return HandBinding::push(L, instance->centerOfMovementTarget);
}

static int AI_get_slaveStateTimeStamp(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    lua_pushnumber(L, instance->slaveStateTimeStamp);
    return 1;
}

static int AI_get_me(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int AI_get_body(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    return pushObject<CharBody>(L, instance->body, CharBodyBinding::getMetatableName());
}

static int AI_get_inventory(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    return pushObject<Inventory>(L, instance->inventory, InventoryBinding::getMetatableName());
}

static int AI_get_stats(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    return pushObject<CharStats>(L, instance->stats, CharStatsBinding::getMetatableName());
}

static int AI_get_medical(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    return pushObject<MedicalSystem>(L, instance->medical, MedicalSystemBinding::getMetatableName());
}

// --- Setters for AI ---
// platoon, state, me, body, inventory, stats, and medical are owner pointers assigned by the
// AI constructor and AI::create, so their setters reject nil. For example,
// findResourceStorageBulidingFor dereferences me without a null check.
static int AI_set_meiDistance(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    instance->meiDistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AI_set_meiDistanceTolerance(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    instance->meiDistanceTolerance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AI_set_platoon(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    instance->platoon = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    return 0;
}

static int AI_set_state(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    instance->state = checkObject<StateBroadcastData>(L, 2, StateBroadcastDataBinding::getMetatableName());
    return 0;
}

static int AI_set_taskRepertoireFlags(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    instance->taskRepertoireFlags = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int AI_set_ordersAggression(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    instance->ordersAggression = (AI::AIAggressionOrders)luaL_checkinteger(L, 2);
    return 0;
}

static int AI_set_ordersMovement(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    instance->ordersMovement = (AI::AIManuverabilityOrders)luaL_checkinteger(L, 2);
    return 0;
}

static int AI_set_centerOfMovement(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    Ogre::Vector3 v;
    if (!readVector3(L, 2, v)) return luaL_argerror(L, 2, "Vector3 table expected");
    instance->centerOfMovement = v;
    return 0;
}

static int AI_set_centerOfMovementTarget(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    instance->centerOfMovementTarget = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int AI_set_slaveStateTimeStamp(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    instance->slaveStateTimeStamp = (double)luaL_checknumber(L, 2);
    return 0;
}

static int AI_set_me(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    instance->me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int AI_set_body(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    instance->body = checkObject<CharBody>(L, 2, CharBodyBinding::getMetatableName());
    return 0;
}

static int AI_set_inventory(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    instance->inventory = checkObject<Inventory>(L, 2, InventoryBinding::getMetatableName());
    return 0;
}

static int AI_set_stats(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    instance->stats = checkObject<CharStats>(L, 2, CharStatsBinding::getMetatableName());
    return 0;
}

static int AI_set_medical(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");
    instance->medical = checkObject<MedicalSystem>(L, 2, MedicalSystemBinding::getMetatableName());
    return 0;
}

// Methods with a hand& out parameter take no Lua argument for it and return it after their result.
int AIBinding::_createTradingInfo(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    instance->_createTradingInfo();
    return 0;
}

int AIBinding::isWithinChoppingRange(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    RootObjectBase* subj = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    bool isMoving = lua_toboolean(L, 3) != 0;
    bool result = instance->isWithinChoppingRange(subj, isMoving);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::setTaskRepertoireFlag(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    unsigned int flag = (unsigned int)luaL_checkinteger(L, 2);
    instance->setTaskRepertoireFlag(flag);
    return 0;
}

int AIBinding::clearTaskRepertoireFlag(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    unsigned int flag = (unsigned int)luaL_checkinteger(L, 2);
    instance->clearTaskRepertoireFlag(flag);
    return 0;
}

int AIBinding::forceOrderInsert(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    instance->forceOrderInsert(t);
    return 0;
}

int AIBinding::stateIsTrue(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    TaskStateData* state = checkObject<TaskStateData>(L, 2, TaskStateDataBinding::getMetatableName());
    hand* h = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 4, v)) return luaL_argerror(L, 4, "Vector3 table expected");
    bool result = instance->stateIsTrue(*state, *h, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::_NV_stateIsTrue(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    TaskStateData* state = checkObject<TaskStateData>(L, 2, TaskStateDataBinding::getMetatableName());
    hand* h = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 4, v)) return luaL_argerror(L, 4, "Vector3 table expected");
    bool result = instance->_NV_stateIsTrue(*state, *h, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::addAIGoalsFrom(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    std::string goallistname = luaL_checkstring(L, 3);
    instance->addAIGoalsFrom(data, goallistname);
    return 0;
}

int AIBinding::isWithinGivenRange(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    float _range = (float)luaL_checknumber(L, 4);
    bool result = instance->isWithinGivenRange(*subject, loc, _range);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::getSensoryData(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    SensoryData* result = instance->getSensoryData();
    return pushObject<SensoryData>(L, result, SensoryDataBinding::getMetatableName());
}

int AIBinding::getStateBroadcast(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    StateBroadcastData* result = instance->getStateBroadcast();
    return pushObject<StateBroadcastData>(L, result, StateBroadcastDataBinding::getMetatableName());
}

int AIBinding::_notifyTaskComplete(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    instance->_notifyTaskComplete();
    return 0;
}

int AIBinding::getDestinationTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    TownBase* result = instance->getDestinationTown();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int AIBinding::setPlatoon(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Platoon* p = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->setPlatoon(p);
    return 0;
}

int AIBinding::getPlatoon(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Platoon* result = instance->getPlatoon();
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int AIBinding::getFaction(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Faction* result = instance->getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int AIBinding::_NV_getFaction(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Faction* result = instance->_NV_getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int AIBinding::getBlackboard(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Blackboard* result = instance->getBlackboard();
    return pushObject<Blackboard>(L, result, BlackboardBinding::getMetatableName());
}

int AIBinding::getHandle(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand result = instance->getHandle();
    return HandBinding::push(L, result);
}

int AIBinding::create(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    CharBody* b = checkObject<CharBody>(L, 2, CharBodyBinding::getMetatableName());
    Inventory* inv = checkObject<Inventory>(L, 3, InventoryBinding::getMetatableName());
    CharStats* st = checkObject<CharStats>(L, 4, CharStatsBinding::getMetatableName());
    MedicalSystem* med = checkObject<MedicalSystem>(L, 5, MedicalSystemBinding::getMetatableName());
    Platoon* p = checkObject<Platoon>(L, 6, PlatoonBinding::getMetatableName());
    instance->create(b, inv, st, med, p);
    return 0;
}

int AIBinding::update4Frame(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    float frametime = (float)luaL_checknumber(L, 2);
    instance->update4Frame(frametime);
    return 0;
}

int AIBinding::_NV_update4Frame(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    float frametime = (float)luaL_checknumber(L, 2);
    instance->_NV_update4Frame(frametime);
    return 0;
}

int AIBinding::periodicUpdate(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    float frametime = (float)luaL_checknumber(L, 2);
    instance->periodicUpdate(frametime);
    return 0;
}

int AIBinding::_NV_periodicUpdate(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    float frametime = (float)luaL_checknumber(L, 2);
    instance->_NV_periodicUpdate(frametime);
    return 0;
}

int AIBinding::periodicUpdate_KOed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    float frametime = (float)luaL_checknumber(L, 2);
    instance->periodicUpdate_KOed(frametime);
    return 0;
}

int AIBinding::sendMessage(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    CharacterMessage message = (CharacterMessage)luaL_checkinteger(L, 2);
    hand* sender = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    hand* subject = checkObject<hand>(L, 4, HandBinding::getMetatableName());
    instance->sendMessage(message, *sender, *subject);
    return 0;
}

int AIBinding::underMeleeAttack(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Character* attacker = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool so = lua_toboolean(L, 3) != 0;
    bool doAwarenessCheck = lua_toboolean(L, 4) != 0;
    instance->underMeleeAttack(attacker, so, doAwarenessCheck);
    return 0;
}

int AIBinding::underRangedAttack(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Character* attacker = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool so = lua_toboolean(L, 3) != 0;
    instance->underRangedAttack(attacker, so);
    return 0;
}

int AIBinding::isTargetOutsideTheGates(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    RootObject* target = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->isTargetOutsideTheGates(target);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::amILockedWithinTownWalls(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    bool result = instance->amILockedWithinTownWalls();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

// Overloads: isEnemy(hand subject, Vector3) and isEnemy(RootObjectBase c).
int AIBinding::isEnemy(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = testObject<hand>(L, 2, HandBinding::getMetatableName());
    if (subject)
    {
        Ogre::Vector3 v;
        if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
        bool result = instance->isEnemy(*subject, v);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    RootObjectBase* c = testObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    if (!c) return luaL_argerror(L, 2, "KenshiLua.hand or KenshiLua.RootObjectBase expected");
    bool result = instance->isEnemy(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::load(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->load(d);
    return 0;
}

int AIBinding::save(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->save(d);
    return 0;
}

int AIBinding::getPosWithinChoppingRange(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    RootObjectBase* subj = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    Ogre::Vector3 clickPos;
    if (!readVector3(L, 3, clickPos)) return luaL_argerror(L, 3, "Vector3 table expected");
    Ogre::Vector3 result = instance->getPosWithinChoppingRange(subj, clickPos);
    pushVector3(L, result);
    return 1;
}

int AIBinding::setAggressionLevel(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    AI::AIAggressionOrders agg = (AI::AIAggressionOrders)luaL_checkinteger(L, 2);
    instance->setAggressionLevel(agg);
    return 0;
}

int AIBinding::setManuveringFreedomLevel(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    AI::AIManuverabilityOrders agg = (AI::AIManuverabilityOrders)luaL_checkinteger(L, 2);
    instance->setManuveringFreedomLevel(agg);
    return 0;
}

int AIBinding::setCenterOfMovement(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Ogre::Vector3 wher;
    if (!readVector3(L, 2, wher)) return luaL_argerror(L, 2, "Vector3 table expected");
    instance->setCenterOfMovement(wher);
    return 0;
}

int AIBinding::setCenterOfMovementTarget(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* wher = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->setCenterOfMovementTarget(*wher);
    return 0;
}

int AIBinding::getCombatTarget(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand result = instance->getCombatTarget();
    return HandBinding::push(L, result);
}

int AIBinding::_NV_getCombatTarget(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand result = instance->_NV_getCombatTarget();
    return HandBinding::push(L, result);
}

int AIBinding::updateStateBroadcast(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->updateStateBroadcast(time);
    return 0;
}

int AIBinding::_NV_updateStateBroadcast(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->_NV_updateStateBroadcast(time);
    return 0;
}

int AIBinding::buySomething(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Building* shop = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    bool result = instance->buySomething(shop);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::IDontWantToLeaveTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    bool result = instance->IDontWantToLeaveTown();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::getPosition(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Ogre::Vector3 result = instance->getPosition();
    pushVector3(L, result);
    return 1;
}

int AIBinding::_NV_getPosition(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Ogre::Vector3 result = instance->_NV_getPosition();
    pushVector3(L, result);
    return 1;
}

int AIBinding::amMoving(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    bool result = instance->amMoving();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::_NV_amMoving(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    bool result = instance->_NV_amMoving();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::periodicUpdateStateBroadcast(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->periodicUpdateStateBroadcast(time);
    return 0;
}

int AIBinding::_NV_periodicUpdateStateBroadcast(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->_NV_periodicUpdateStateBroadcast(time);
    return 0;
}

int AIBinding::getCharacter(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Character* result = instance->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int AIBinding::getAllMyPermajobMachines(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    ogre_unordered_set<UseableStuff*>::type out;
    instance->getAllMyPermajobMachines(out);
    lua_newtable(L);
    int idx = 1;
    for (ogre_unordered_set<UseableStuff*>::type::const_iterator it = out.begin(); it != out.end(); ++it)
    {
        pushObject<UseableStuff>(L, *it, UseableStuffBinding::getMetatableName());
        lua_rawseti(L, -2, idx++);
    }
    return 1;
}

int AIBinding::hasPermajob(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    bool result = instance->hasPermajob(t);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::noneState(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->noneState(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::_NV_noneState(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->_NV_noneState(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isAtLocation(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isAtLocation(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::_NV_isAtLocation(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->_NV_isAtLocation(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isLocationAccessible(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isLocationAccessible(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

// Overloads: isDestinationAccessible(RootObject target, bool outsideBuilding) and
// isDestinationAccessible(hand subject, Vector3 v).
int AIBinding::isDestinationAccessible(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = testObject<hand>(L, 2, HandBinding::getMetatableName());
    if (subject)
    {
        Ogre::Vector3 v;
        if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
        bool result = instance->isDestinationAccessible(*subject, v);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    RootObject* target = testObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    if (!target) return luaL_argerror(L, 2, "KenshiLua.hand or KenshiLua.RootObject expected");
    bool outsideBuilding = lua_toboolean(L, 3) != 0;
    bool result = instance->isDestinationAccessible(target, outsideBuilding);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isDestinationAccessibleAnimal(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isDestinationAccessibleAnimal(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isAtDoorOf(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isAtDoorOf(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isAtDoorOf_Inside(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isAtDoorOf_Inside(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isAtDoorOf_Outside(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isAtDoorOf_Outside(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isAtDoorOfCurrentLocation(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isAtDoorOfCurrentLocation(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isBuildingComplete(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isBuildingComplete(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isSubjectInInventory(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isSubjectInInventory(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isNoEnemiesInVicinity(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isNoEnemiesInVicinity(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isTargetDown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isTargetDown(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::targetIsConscious(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->targetIsConscious(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isLeaderDown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isLeaderDown(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isTargetEnemy(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isTargetEnemy(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::crowdLimit8(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->crowdLimit8(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::hasWeapon(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->hasWeapon(*_a1, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::hasWeaponEquipped(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->hasWeaponEquipped(*_a1, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::hasCrossbowEquipped(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->hasCrossbowEquipped(*_a1, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::hasAnythingEquipped(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->hasAnythingEquipped(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isAlliesFighting(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isAlliesFighting(*_a1, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isSquadmatesFighting(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isSquadmatesFighting(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::iAmBeingMeleeAttacked_immediate(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->iAmBeingMeleeAttacked_immediate(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::iAmBeingMeleeAttacked_general(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->iAmBeingMeleeAttacked_general(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isAggressionTowards(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isAggressionTowards(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isAggressionTowardsMe(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isAggressionTowardsMe(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isGeneralAggressionLevel(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isGeneralAggressionLevel(*_a1, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isItemLootable(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isItemLootable(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::amIdle(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->amIdle(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::needsFirstAid(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->needsFirstAid(*_subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::myLegsAreMessedUpButCouldBeFixed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->myLegsAreMessedUpButCouldBeFixed(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::haveFirstAidKit(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->haveFirstAidKit(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::needsFirstAid_robot(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->needsFirstAid_robot(*_subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::haveFirstAidKit_robot(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->haveFirstAidKit_robot(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::needsSplint(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->needsSplint(*_subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::hasSplintKit(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->hasSplintKit(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::hasTools(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->hasTools(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isCrouching(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isCrouching(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isCrouchingOrLying(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isCrouchingOrLying(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isLyingProne(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isLyingProne(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isMovementAllowed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 location;
    if (!readVector3(L, 3, location)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isMovementAllowed(*subject, location);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isAtHome(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isAtHome(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isAtHomeTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isAtHomeTown(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::targetStandingStill(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->targetStandingStill(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::hasOneWorkingArm(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->hasOneWorkingArm(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::hasTwoWorkingArms(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->hasTwoWorkingArms(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isReadyForAction(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isReadyForAction(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::iAmDown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->iAmDown(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::iAmProne(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->iAmProne(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::canGetUp(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->canGetUp(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::scoreCanGetUp(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreCanGetUp(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::isCarryingSomething(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isCarryingSomething(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isCarriedDudeInBed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isCarriedDudeInBed(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isCarriedDudeDead(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isCarriedDudeDead(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isCarryingTarget(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isCarryingTarget(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::final_gotAKidnapVictim(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->final_gotAKidnapVictim(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::final_foundAndPutInCage(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->final_foundAndPutInCage(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::targetIsArrested(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->targetIsArrested(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::alarmsInTheVicinity(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->alarmsInTheVicinity(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::intruderIsOutside(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->intruderIsOutside(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::intruderIsOutsideGates(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->intruderIsOutsideGates(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::amSwimming(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->amSwimming(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isTargetSwimming(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isTargetSwimming(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isBeingCarried(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isBeingCarried(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::hasBuildingMaterials(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->hasBuildingMaterials(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::buildingHasBuildingMaterials(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->buildingHasBuildingMaterials(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isDoorBroken(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isDoorBroken(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isDoorOpen(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isDoorOpen(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isDoorOpenHere(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isDoorOpenHere(*_a1, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::iAmInsideTargetBuilding(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->iAmInsideTargetBuilding(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::farmHasFood(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->farmHasFood(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::amHungry(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->amHungry(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::iHaveSufficientLockSkill(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->iHaveSufficientLockSkill(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::iHaveSufficientLockSkillForShackles(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->iHaveSufficientLockSkillForShackles(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::scoreIAmInsideTargetBuilding(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreIAmInsideTargetBuilding(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreIAmOutsideTargetBuilding(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreIAmOutsideTargetBuilding(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::machineHasEmptyInputs(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->machineHasEmptyInputs(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isMachineOutputFull(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isMachineOutputFull(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::machineHasFullInputs(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->machineHasFullInputs(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isMachineOutputEmpty(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isMachineOutputEmpty(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::haveSomeResourcesFrom(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->haveSomeResourcesFrom(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::haveSomeResourcesFromThisMachineButWantThemGoneIfPossible(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->haveSomeResourcesFromThisMachineButWantThemGoneIfPossible(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::haveSomeResourcesFor(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->haveSomeResourcesFor(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isMachineJammed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isMachineJammed(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isAnyMachineJammed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isAnyMachineJammed(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isMachineInputInvalid(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isMachineInputInvalid(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::gotInventoryRoomForResources(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->gotInventoryRoomForResources(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isRouteTraceBlocked(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isRouteTraceBlocked(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isDoorLocked(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isDoorLocked(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isDoorLockedHere(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isDoorLockedHere(*_a1, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isDoorLockedAndMeInside(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isDoorLockedAndMeInside(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isDoorLockedAndMeOutside(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isDoorLockedAndMeOutside(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isObjectMine(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isObjectMine(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isBuildingDamaged(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isBuildingDamaged(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isBuildingDestroyed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isBuildingDestroyed(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isFullyRested(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isFullyRested(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::machineHasFreeOperatorSlot(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->machineHasFreeOperatorSlot(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isDialogDelivered(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isDialogDelivered(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isMessageDelivered(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isMessageDelivered(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isEnemyForceDefeated(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isEnemyForceDefeated(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isInBed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isInBed(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isCarryingArmOK(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isCarryingArmOK(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isAtAShop(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isAtAShop(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::boughtShitComplete(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->boughtShitComplete(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isInsideTargetBuilding(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* what = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isInsideTargetBuilding(*what, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::allDoorsLocked(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->allDoorsLocked(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

// Overloads: destinationNotBlockedByFortifications(RootObject target) and
// destinationNotBlockedByFortifications(hand subject, Vector3 v).
int AIBinding::destinationNotBlockedByFortifications(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = testObject<hand>(L, 2, HandBinding::getMetatableName());
    if (subject)
    {
        Ogre::Vector3 v;
        if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
        bool result = instance->destinationNotBlockedByFortifications(*subject, v);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    RootObject* target = testObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    if (!target) return luaL_argerror(L, 2, "KenshiLua.hand or KenshiLua.RootObject expected");
    bool result = instance->destinationNotBlockedByFortifications(target);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::atLocationGate(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->atLocationGate(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isAlly(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isAlly(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::buildingHasPower(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->buildingHasPower(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::hasDestinationTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->hasDestinationTown(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isCarryingHealthyTarget(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isCarryingHealthyTarget(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::atDestinationTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->atDestinationTown(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::atPackageTarget(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->atPackageTarget(*subject, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::atATown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->atATown(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::targetAtATown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->targetAtATown(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isTiredFromTravel(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isTiredFromTravel(*subject, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::scoreGetNextDestinationTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreGetNextDestinationTown(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreWantsToGetUp_toFeet(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreWantsToGetUp_toFeet(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreWantsToGetUp_stayLow(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreWantsToGetUp_stayLow(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::isNearTo(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isNearTo(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isWithin50Meters(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isWithin50Meters(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isWithin10Meters(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isWithin10Meters(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isWithinMyBowRange(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isWithinMyBowRange(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isTargetRestrainedOrKO(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isTargetRestrainedOrKO(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isOccupantAlive(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isOccupantAlive(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::cagesAreAllFull(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->cagesAreAllFull(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::iAmImprisoned(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->iAmImprisoned(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::targetIsImprisoned(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->targetIsImprisoned(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::targetIsMySlave(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->targetIsMySlave(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::iveDitchedAllMyResources(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->iveDitchedAllMyResources(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::targetHasBeenLootedOfResources(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->targetHasBeenLootedOfResources(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::targetHasBeenLooted(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->targetHasBeenLooted(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::usingTurret_Any(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->usingTurret_Any(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::usingTurret_Target(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->usingTurret_Target(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::strangersAreInMyBuilding(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->strangersAreInMyBuilding(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::strangersAreInMyBuilding_andPrivate(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->strangersAreInMyBuilding_andPrivate(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::buildingIsPublic(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->buildingIsPublic(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::targetIsUnarmed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->targetIsUnarmed(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::_targetLooksLikeASlave(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->_targetLooksLikeASlave(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::carryingExcessLoot(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->carryingExcessLoot(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isWorking(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isWorking(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::gotAFoodItem(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->gotAFoodItem(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::iHaveSomeSlaves(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->iHaveSomeSlaves(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::getALootableResourceItemFromTargetThatWeHaveStorageFor(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Item* result = instance->getALootableResourceItemFromTargetThatWeHaveStorageFor(target);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int AIBinding::targetLooksLikeASlave(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->targetLooksLikeASlave(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::slaveIsEscaping(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->slaveIsEscaping(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::slaveIsFollowingOrders(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->slaveIsFollowingOrders(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isRunningAway(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    RootObject* from = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    bool result = instance->isRunningAway(who, from);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isWearingShackles(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isWearingShackles(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isWearingShackles_locked(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isWearingShackles_locked(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isTargetEscapee(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 loc;
    if (!readVector3(L, 3, loc)) return luaL_argerror(L, 3, "Vector3 table expected");
    bool result = instance->isTargetEscapee(*subject, loc);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

// Overloads: isTargetInRangeForOrders(Vector3 location) and isTargetInRangeForOrders(RootObject who).
int AIBinding::isTargetInRangeForOrders(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    if (lua_istable(L, 2))
    {
        Ogre::Vector3 location;
        readVector3(L, 2, location);
        bool result = instance->isTargetInRangeForOrders(location);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    RootObject* who = testObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    if (!who) return luaL_argerror(L, 2, "Vector3 table or KenshiLua.RootObject expected");
    bool result = instance->isTargetInRangeForOrders(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::isTargetInRangeForHOLDMode_hostiles(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->isTargetInRangeForHOLDMode_hostiles(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::getMaxTargetRangeForOrdersSq(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    float result = instance->getMaxTargetRangeForOrdersSq();
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::targetMyself(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* oldSubject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->targetMyself(*oldSubject, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findWeapon(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* oldSubject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findWeapon(*oldSubject, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findSomebodyToLoot(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findSomebodyToLoot(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findAttackerOf(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _of = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findAttackerOf(*_of, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findAggressiveFellows(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findAggressiveFellows(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::wantGuardAggressionNeutralTargetCheck(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->wantGuardAggressionNeutralTargetCheck(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::findBounty(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findBounty(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findKOIntruder(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findKOIntruder(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findKOIntruder_town(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findKOIntruder_town(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findTurretToUse(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findTurretToUse(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findTurretToUseOnMyBuilding(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findTurretToUseOnMyBuilding(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findMeleeOpponentForTerritorialAggression(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* oldSubject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findMeleeOpponentForTerritorialAggression(*oldSubject, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findMeleeOpponentForFightingSlave(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* oldSubject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findMeleeOpponentForFightingSlave(*oldSubject, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findMeleeOpponentForTerritorialAggressionWithNeutrals(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* oldSubject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findMeleeOpponentForTerritorialAggressionWithNeutrals(*oldSubject, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findMeleeOpponent(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* oldSubject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findMeleeOpponent(*oldSubject, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findMeleeOpponentNearMyTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* oldSubject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findMeleeOpponentNearMyTown(*oldSubject, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findMeleeOpponentFromSquad(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findMeleeOpponentFromSquad(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::shouldIFreeMySlaveBuddies(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Character* slave = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->shouldIFreeMySlaveBuddies(slave);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::findAllyInNeed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findAllyInNeed(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findAllyInNeed_stayInTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findAllyInNeed_stayInTown(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findSquadmateInNeed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findSquadmateInNeed(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findHome(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand _out;
    float result = instance->findHome(*_a1, _out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, _out);
    return 2;
}

int AIBinding::findShopkeeperNode(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findShopkeeperNode(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findDefensiveNode(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findDefensiveNode(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findGuardNodeForBuilding_inOrOut(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findGuardNodeForBuilding_inOrOut(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findGuardNodeForBuilding_indoorOnly(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findGuardNodeForBuilding_indoorOnly(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findGuardNodeForBuilding_nearestPlayer(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    bool indoorsOnly = lua_toboolean(L, 2) != 0;
    hand out;
    float result = instance->findGuardNodeForBuilding_nearestPlayer(out, indoorsOnly);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findGuardNodeForTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findGuardNodeForTown(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findGeneralNode(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findGeneralNode(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findGoodRecruitNode(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findGoodRecruitNode(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findPublicGeneralNodeInTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findPublicGeneralNodeInTown(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findWoundedAllies(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findWoundedAllies(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findSplintableAllies(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findSplintableAllies(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findWoundedAllies_Robots(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findWoundedAllies_Robots(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::_findWoundedAllies(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    bool robots = lua_toboolean(L, 2) != 0;
    hand out;
    float result = instance->_findWoundedAllies(out, robots);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findPrisonerFreeToGo(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findPrisonerFreeToGo(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findPrisonerToLiberate(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findPrisonerToLiberate(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findPrisonerWithContraband(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findPrisonerWithContraband(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::getCurrentBuilding(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->getCurrentBuilding(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::getDestinationBuilding(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->getDestinationBuilding(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findJammedMachine(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findJammedMachine(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findResourceSourceForMe(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findResourceSourceForMe(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findResourceDestinationForMe(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findResourceDestinationForMe(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findResourceDestinationFor(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* forwhat = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool includeMyInventoryContents = lua_toboolean(L, 3) != 0;
    hand out;
    bool result = instance->findResourceDestinationFor(*forwhat, out, includeMyInventoryContents);
    lua_pushboolean(L, result ? 1 : 0);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findResourceDestinationForMyLoot(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findResourceDestinationForMyLoot(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findMineToWorkAt(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findMineToWorkAt(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findMineToWorkAt_pretend(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findMineToWorkAt_pretend(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findSomethingToDoInHome(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findSomethingToDoInHome(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findSomethingToDo_lazy(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findSomethingToDo_lazy(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findThrone(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findThrone(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findBuildingMaterials(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findBuildingMaterials(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findTalkTarget(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findTalkTarget(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findDisabledAlly(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findDisabledAlly(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findDisabledDude(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    unsigned int flagsAny = (unsigned int)luaL_checkinteger(L, 2);
    unsigned int flagsNot = (unsigned int)luaL_checkinteger(L, 3);
    bool includeBeds = lua_toboolean(L, 4) != 0;
    hand result = instance->findDisabledDude(flagsAny, flagsNot, includeBeds);
    return HandBinding::push(L, result);
}

int AIBinding::findDisabledNonAlly(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findDisabledNonAlly(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findSomeoneWhoWouldMakeAGoodSlave(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findSomeoneWhoWouldMakeAGoodSlave(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findBadSlaves(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findBadSlaves(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findNewSlaveOrPrisonerToProcess(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findNewSlaveOrPrisonerToProcess(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findRandomOneOfMySlaves(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findRandomOneOfMySlaves(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findConsciousSlaveInTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findConsciousSlaveInTown(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findConsciousSlaveInTownForShipping(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findConsciousSlaveInTownForShipping(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findConsciousSlaveInTown_unholy(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findConsciousSlaveInTown_unholy(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findKOedSlaveOfMine(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findKOedSlaveOfMine(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findCorpse_onGround(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findCorpse_onGround(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findCorpse_onGround_detail(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    bool carriableOnly = lua_toboolean(L, 4) != 0;
    bool edibleOnly = lua_toboolean(L, 5) != 0;
    hand out;
    float result = instance->findCorpse_onGround_detail(*in, out, justAsking, carriableOnly, edibleOnly);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findCorpse_includingCages(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findCorpse_includingCages(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findDeadOrKOBody_onGround(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findDeadOrKOBody_onGround(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findCrops(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findCrops(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findOwnedFreeBed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findOwnedFreeBed(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findOwnedFreeCage(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findOwnedFreeCage(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findSlaveBuyer(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findSlaveBuyer(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findEmptyCageBelongingToMaster(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findEmptyCageBelongingToMaster(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findOwnedFullCage_MarkForDeath(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findOwnedFullCage_MarkForDeath(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findCorpseDisposal(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findCorpseDisposal(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findShop(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findShop(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findPackageTarget(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findPackageTarget(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::getDestinationGate(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->getDestinationGate(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::getBuildingToSmash(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->getBuildingToSmash(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findSomethingToBuild(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findSomethingToBuild(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findNearestHomeBase(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findNearestHomeBase(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findNextTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findNextTown(*_a1, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findSomethingToLootFoodFrom(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findSomethingToLootFoodFrom(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findFoodOnGround(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* oldSubject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findFoodOnGround(*oldSubject, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findLimbOnGround(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* oldSubject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findLimbOnGround(*oldSubject, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::targetMyLeader(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* oldSubject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->targetMyLeader(*oldSubject, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::targetMySlavemaster(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* oldSubject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->targetMySlavemaster(*oldSubject, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::targetMyLeader_theRealOne(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* oldSubject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->targetMyLeader_theRealOne(*oldSubject, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findUnlockedDoorHere(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findUnlockedDoorHere(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findLockedOrClosedDoorHere(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findLockedOrClosedDoorHere(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findStrangersInMyBuilding(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findStrangersInMyBuilding(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findUnlockedCage(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findUnlockedCage(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findRandomBuildingInTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findRandomBuildingInTown(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findFogmanWorshipTarget(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool _a3 = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findFogmanWorshipTarget(*in, out, _a3);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findAnimalsToLoot(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findAnimalsToLoot(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findAllyAnimalWithFoodInMouth(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool justAsking = lua_toboolean(L, 3) != 0;
    hand out;
    float result = instance->findAllyAnimalWithFoodInMouth(*in, out, justAsking);
    lua_pushnumber(L, result);
    HandBinding::push(L, out);
    return 2;
}

int AIBinding::findBodyWithResourceToLoot(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    GameData* resourceNeeded = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool animalsOnly = lua_toboolean(L, 3) != 0;
    Character* result = instance->findBodyWithResourceToLoot(resourceNeeded, animalsOnly);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int AIBinding::_findOwnedCageThing(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    bool wantEmpty = lua_toboolean(L, 2) != 0;
    BuildingFunction whatType = (BuildingFunction)luaL_checkinteger(L, 3);
    UseableStuff* result = instance->_findOwnedCageThing(wantEmpty, whatType);
    return pushObject<UseableStuff>(L, result, UseableStuffBinding::getMetatableName());
}

int AIBinding::findNode(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    NodeType t = (NodeType)luaL_checkinteger(L, 2);
    bool forHomeBuildingOnly = lua_toboolean(L, 3) != 0;
    bool indoorsOnly = lua_toboolean(L, 4) != 0;
    hand result = instance->findNode(t, forHomeBuildingOnly, indoorsOnly);
    return HandBinding::push(L, result);
}

int AIBinding::itemOnGroundStealingCheckIsSafe(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = instance->itemOnGroundStealingCheckIsSafe(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::findSomeoneToLoot(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    bool wantAWeapon = lua_toboolean(L, 2) != 0;
    Character* result = instance->findSomeoneToLoot(wantAWeapon);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int AIBinding::getAllLocalMachines(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    unsigned int buildingFunctions = (unsigned int)luaL_checkinteger(L, 2);
    lektor<Building*> out;
    instance->getAllLocalMachines(out, buildingFunctions);
    lua_newtable(L);
    for (uint32_t i = 0; i < out.size(); ++i)
    {
        pushObject<Building>(L, out[i], BuildingBinding::getMetatableName());
        lua_rawseti(L, -2, (int)(i + 1));
    }
    return 1;
}

int AIBinding::findResourceStorageBulidingFor(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    GameData* needed = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    // The engine null-checks skip before comparing candidates against it.
    StorageBuilding* skip = lua_isnoneornil(L, 3) ? nullptr : checkObject<StorageBuilding>(L, 3, StorageBuildingBinding::getMetatableName());
    StorageBuilding* result = instance->findResourceStorageBulidingFor(needed, skip);
    return pushObject<StorageBuilding>(L, result, StorageBuildingBinding::getMetatableName());
}

int AIBinding::rateWeapon(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    float result = instance->rateWeapon(item);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_rateWeapon(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    float result = instance->_NV_rateWeapon(item);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::canUseWeapon(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = instance->canUseWeapon(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::_NV_canUseWeapon(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = instance->_NV_canUseWeapon(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AIBinding::scoreTargetRange(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    float range = (float)luaL_checknumber(L, 2);
    float result = instance->scoreTargetRange(range);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreDistanceTo(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    RootObject* target = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool holdPositionMode = lua_toboolean(L, 3) != 0;
    float result = instance->scoreDistanceTo(target, holdPositionMode);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreSplint(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreSplint(*_subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreFirstAid(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreFirstAid(*_subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreFixMyLegs(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreFixMyLegs(*_subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreFirstAidRobot(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreFirstAidRobot(*_subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scorePutCarriedDudeDown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scorePutCarriedDudeDown(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreJobMedic(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreJobMedic(*_subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scorePutCarriedDudeInBed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scorePutCarriedDudeInBed(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scorePutCarriedDudeInCage(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scorePutCarriedDudeInCage(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreCarryingIntruder(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreCarryingIntruder(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreFindAndRescue(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreFindAndRescue(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreFindAndRescueIfTheresBeds(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreFindAndRescueIfTheresBeds(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreRescueLeader(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreRescueLeader(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreFindAndKidnap(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreFindAndKidnap(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreKidnapperCageJob(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreKidnapperCageJob(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreShopping(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreShopping(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreProtectAllies(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreProtectAllies(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreProtectAllies(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreProtectAllies(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreStayClose(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 p;
    if (!readVector3(L, 3, p)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreStayClose(*subject, p);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreStayClose(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 p;
    if (!readVector3(L, 3, p)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreStayClose(*subject, p);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreStayCloseIsh(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 p;
    if (!readVector3(L, 3, p)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreStayCloseIsh(*subject, p);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreStayCloseIsh(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 p;
    if (!readVector3(L, 3, p)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreStayCloseIsh(*subject, p);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scorePutDudeInCage(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* who = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    float result = instance->scorePutDudeInCage(*who);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreUnderAttack(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreUnderAttack(*in, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreUnderAttack(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreUnderAttack(*in, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreEmptyMachine(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreEmptyMachine(*in, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreEmptyMachine(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* in = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreEmptyMachine(*in, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreNone(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreNone(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreNone(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreNone(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreCannibalKill(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreCannibalKill(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreCannibalKill(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreCannibalKill(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreAutoMachinery(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreAutoMachinery(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreAutoMachinery(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreAutoMachinery(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreCollectOutputResource(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreCollectOutputResource(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreCollectOutputResource(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreCollectOutputResource(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreCollectOutputResourceForBuildMats(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreCollectOutputResourceForBuildMats(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreCollectOutputResourceForBuildMats(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreCollectOutputResourceForBuildMats(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreGetFood_inHomeTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreGetFood_inHomeTown(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreGetFood_inHomeTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreGetFood_inHomeTown(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreFindFoodOnGround(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreFindFoodOnGround(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreFindFoodOnGround(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreFindFoodOnGround(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreGetFood_inHomeTown_andFeedAnimals(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreGetFood_inHomeTown_andFeedAnimals(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreGetFood_inHomeTown_andFeedAnimals(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreGetFood_inHomeTown_andFeedAnimals(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreUnlockDoorHere(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreUnlockDoorHere(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreUnlockDoorHere(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreUnlockDoorHere(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreGetOutOfBed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreGetOutOfBed(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreGetOutOfBed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreGetOutOfBed(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreGetOutOfBedOnceFullyHealed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreGetOutOfBedOnceFullyHealed(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreGetOutOfBedOnceFullyHealed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreGetOutOfBedOnceFullyHealed(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreGoToBed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreGoToBed(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreGoToBed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreGoToBed(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreHomeIsNotLockedUp(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreHomeIsNotLockedUp(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreHomeIsNotLockedUp(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreHomeIsNotLockedUp(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreDontLeaveTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreDontLeaveTown(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreDontLeaveTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreDontLeaveTown(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreFoundCages(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreFoundCages(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreFoundCages(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreFoundCages(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreHasWorkingArm(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreHasWorkingArm(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreHasWorkingArm(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreHasWorkingArm(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreUseTurret(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreUseTurret(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreUseTurret(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreUseTurret(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreAggressiveAction(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreAggressiveAction(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreAggressiveAction(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreAggressiveAction(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreBashGate(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreBashGate(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreBashGate(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreBashGate(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreNPCEscapeCageOpportunity(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreNPCEscapeCageOpportunity(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreNPCEscapeCageOpportunity(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreNPCEscapeCageOpportunity(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::score01(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->score01(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_score01(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_score01(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::score025(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->score025(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_score025(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_score025(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::score05(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->score05(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_score05(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_score05(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::score08(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->score08(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_score08(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_score08(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::score10(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->score10(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_score10(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_score10(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreCanSeeTarget(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreCanSeeTarget(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreCanSeeTarget(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreCanSeeTarget(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::score12(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->score12(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_score12(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_score12(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::score15(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->score15(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_score15(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_score15(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::score20(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->score20(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_score20(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_score20(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreRandomFluff(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreRandomFluff(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreRandomFluff(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreRandomFluff(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreHuntingBlood(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreHuntingBlood(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreHuntingBlood(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreHuntingBlood(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreHuntingEggs(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreHuntingEggs(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreHuntingEggs(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreHuntingEggs(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreTargetInDanger(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreTargetInDanger(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreTargetInDanger(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreTargetInDanger(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreAttackEnemies(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreAttackEnemies(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreAttackEnemies(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreAttackEnemies(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreMeleeAttack(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreMeleeAttack(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreMeleeAttack(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreMeleeAttack(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreRangedAttack(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreRangedAttack(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreRangedAttack(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreRangedAttack(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreRunAway(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreRunAway(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreRunAway(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreRunAway(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreRetreat(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreRetreat(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreRetreat(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreRetreat(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreMove(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreMove(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreMove(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreMove(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreDontWantToBeUnarmed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreDontWantToBeUnarmed(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreDontWantToBeUnarmed(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreDontWantToBeUnarmed(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreLiftObject(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreLiftObject(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreLiftObject(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreLiftObject(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreLiftIntruder(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreLiftIntruder(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreLiftIntruder(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreLiftIntruder(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreChainNewSlave(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreChainNewSlave(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreChainNewSlave(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreChainNewSlave(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreNotDown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreNotDown(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreNotDown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreNotDown(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreNoMoreThan4Slaves(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreNoMoreThan4Slaves(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreNoMoreThan4Slaves(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreNoMoreThan4Slaves(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreSlaveExportTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreSlaveExportTown(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreSlaveExportTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreSlaveExportTown(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreHasSomeSlaves(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreHasSomeSlaves(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreHasSomeSlaves(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreHasSomeSlaves(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreHasSomeSlavesAndAtImportTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreHasSomeSlavesAndAtImportTown(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreHasSomeSlavesAndAtImportTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreHasSomeSlavesAndAtImportTown(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreAmTheRealLeader(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreAmTheRealLeader(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreAmTheRealLeader(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 3, v)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreAmTheRealLeader(*subject, v);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreAtAttackableTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreAtAttackableTown(*_a1, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreAtAttackableTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* _a1 = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreAtAttackableTown(*_a1, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreDogPlaying(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreDogPlaying(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreDogPlaying(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreDogPlaying(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreDogPlayingChase(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreDogPlayingChase(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreDogPlayingChase(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreDogPlayingChase(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreHomeIsPrivate(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreHomeIsPrivate(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreHomeIsPrivate(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreHomeIsPrivate(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreNotKOOrPlayingDead(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreNotKOOrPlayingDead(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreNotKOOrPlayingDead(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreNotKOOrPlayingDead(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::scoreTargetInMyTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->scoreTargetInMyTown(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

int AIBinding::_NV_scoreTargetInMyTown(lua_State* L)
{
    AI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI is nil");

    hand* subject = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 _a2;
    if (!readVector3(L, 3, _a2)) return luaL_argerror(L, 3, "Vector3 table expected");
    float result = instance->_NV_scoreTargetInMyTown(*subject, _a2);
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped fields:
  line 107: stateFuncs - static StateFunctionList of member-function pointers
  line 114: taskSystemAI - AITaskSytem* (unbound pointer)
  line 115: sensoryData setter - embedded SensoryData; KenshiLib exports no SensoryData::operator=
  line 144: resultsCache - AI::AIResultsCacher (unbound type)
  line 147: taskRepertoire - TaskRepertoire* (unbound pointer)
  line 198: tradingInfo - TradingInfo* (unbound pointer)

Skipped methods needing manual binding:
  line 145: setFunc - static; takes a bool (AI::*)(const hand&, const Ogre::Vector3&) member-function pointer
  line 146: _setupGOAPFuncs - static engine initialization of AI::stateFuncs
  line 157: getTaskSystem - AITaskSytem* (unbound pointer)
  line 183: AI - engine-owned; created by Character
  line 184: _CONSTRUCTOR - engine-owned; created by Character
  line 185: ~AI - engine-owned; destroyed by Character
  line 186: _DESTRUCTOR - engine-owned; destroyed by Character
  line 204: chooseBestAttackTarget - RootObject** and float& out-parameters plus a lektor<Character*>& input built by the engine
  line 233: getMyMissionTarget - TargetInfo return (unbound type)
*/

int AIBinding::gc(lua_State* L)
{
    // Borrowed from the owning Character
    return 0;
}

int AIBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AI object");
    return 1;
}

void AIBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AIBinding::gc },
        { "__tostring", AIBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_createTradingInfo", AIBinding::_createTradingInfo },
        { "isWithinChoppingRange", AIBinding::isWithinChoppingRange },
        { "setTaskRepertoireFlag", AIBinding::setTaskRepertoireFlag },
        { "clearTaskRepertoireFlag", AIBinding::clearTaskRepertoireFlag },
        { "forceOrderInsert", AIBinding::forceOrderInsert },
        { "stateIsTrue", AIBinding::stateIsTrue },
        { "_NV_stateIsTrue", AIBinding::_NV_stateIsTrue },
        { "addAIGoalsFrom", AIBinding::addAIGoalsFrom },
        { "isWithinGivenRange", AIBinding::isWithinGivenRange },
        { "getSensoryData", AIBinding::getSensoryData },
        { "getStateBroadcast", AIBinding::getStateBroadcast },
        { "_notifyTaskComplete", AIBinding::_notifyTaskComplete },
        { "getDestinationTown", AIBinding::getDestinationTown },
        { "setPlatoon", AIBinding::setPlatoon },
        { "getPlatoon", AIBinding::getPlatoon },
        { "getFaction", AIBinding::getFaction },
        { "_NV_getFaction", AIBinding::_NV_getFaction },
        { "getBlackboard", AIBinding::getBlackboard },
        { "getHandle", AIBinding::getHandle },
        { "create", AIBinding::create },
        { "update4Frame", AIBinding::update4Frame },
        { "_NV_update4Frame", AIBinding::_NV_update4Frame },
        { "periodicUpdate", AIBinding::periodicUpdate },
        { "_NV_periodicUpdate", AIBinding::_NV_periodicUpdate },
        { "periodicUpdate_KOed", AIBinding::periodicUpdate_KOed },
        { "sendMessage", AIBinding::sendMessage },
        { "underMeleeAttack", AIBinding::underMeleeAttack },
        { "underRangedAttack", AIBinding::underRangedAttack },
        { "isTargetOutsideTheGates", AIBinding::isTargetOutsideTheGates },
        { "amILockedWithinTownWalls", AIBinding::amILockedWithinTownWalls },
        { "isEnemy", AIBinding::isEnemy },
        { "load", AIBinding::load },
        { "save", AIBinding::save },
        { "getPosWithinChoppingRange", AIBinding::getPosWithinChoppingRange },
        { "setAggressionLevel", AIBinding::setAggressionLevel },
        { "setManuveringFreedomLevel", AIBinding::setManuveringFreedomLevel },
        { "setCenterOfMovement", AIBinding::setCenterOfMovement },
        { "setCenterOfMovementTarget", AIBinding::setCenterOfMovementTarget },
        { "getCombatTarget", AIBinding::getCombatTarget },
        { "_NV_getCombatTarget", AIBinding::_NV_getCombatTarget },
        { "updateStateBroadcast", AIBinding::updateStateBroadcast },
        { "_NV_updateStateBroadcast", AIBinding::_NV_updateStateBroadcast },
        { "buySomething", AIBinding::buySomething },
        { "IDontWantToLeaveTown", AIBinding::IDontWantToLeaveTown },
        { "getPosition", AIBinding::getPosition },
        { "_NV_getPosition", AIBinding::_NV_getPosition },
        { "amMoving", AIBinding::amMoving },
        { "_NV_amMoving", AIBinding::_NV_amMoving },
        { "periodicUpdateStateBroadcast", AIBinding::periodicUpdateStateBroadcast },
        { "_NV_periodicUpdateStateBroadcast", AIBinding::_NV_periodicUpdateStateBroadcast },
        { "getCharacter", AIBinding::getCharacter },
        { "getAllMyPermajobMachines", AIBinding::getAllMyPermajobMachines },
        { "hasPermajob", AIBinding::hasPermajob },
        { "noneState", AIBinding::noneState },
        { "_NV_noneState", AIBinding::_NV_noneState },
        { "isAtLocation", AIBinding::isAtLocation },
        { "_NV_isAtLocation", AIBinding::_NV_isAtLocation },
        { "isLocationAccessible", AIBinding::isLocationAccessible },
        { "isDestinationAccessible", AIBinding::isDestinationAccessible },
        { "isDestinationAccessibleAnimal", AIBinding::isDestinationAccessibleAnimal },
        { "isAtDoorOf", AIBinding::isAtDoorOf },
        { "isAtDoorOf_Inside", AIBinding::isAtDoorOf_Inside },
        { "isAtDoorOf_Outside", AIBinding::isAtDoorOf_Outside },
        { "isAtDoorOfCurrentLocation", AIBinding::isAtDoorOfCurrentLocation },
        { "isBuildingComplete", AIBinding::isBuildingComplete },
        { "isSubjectInInventory", AIBinding::isSubjectInInventory },
        { "isNoEnemiesInVicinity", AIBinding::isNoEnemiesInVicinity },
        { "isTargetDown", AIBinding::isTargetDown },
        { "targetIsConscious", AIBinding::targetIsConscious },
        { "isLeaderDown", AIBinding::isLeaderDown },
        { "isTargetEnemy", AIBinding::isTargetEnemy },
        { "crowdLimit8", AIBinding::crowdLimit8 },
        { "hasWeapon", AIBinding::hasWeapon },
        { "hasWeaponEquipped", AIBinding::hasWeaponEquipped },
        { "hasCrossbowEquipped", AIBinding::hasCrossbowEquipped },
        { "hasAnythingEquipped", AIBinding::hasAnythingEquipped },
        { "isAlliesFighting", AIBinding::isAlliesFighting },
        { "isSquadmatesFighting", AIBinding::isSquadmatesFighting },
        { "iAmBeingMeleeAttacked_immediate", AIBinding::iAmBeingMeleeAttacked_immediate },
        { "iAmBeingMeleeAttacked_general", AIBinding::iAmBeingMeleeAttacked_general },
        { "isAggressionTowards", AIBinding::isAggressionTowards },
        { "isAggressionTowardsMe", AIBinding::isAggressionTowardsMe },
        { "isGeneralAggressionLevel", AIBinding::isGeneralAggressionLevel },
        { "isItemLootable", AIBinding::isItemLootable },
        { "amIdle", AIBinding::amIdle },
        { "needsFirstAid", AIBinding::needsFirstAid },
        { "myLegsAreMessedUpButCouldBeFixed", AIBinding::myLegsAreMessedUpButCouldBeFixed },
        { "haveFirstAidKit", AIBinding::haveFirstAidKit },
        { "needsFirstAid_robot", AIBinding::needsFirstAid_robot },
        { "haveFirstAidKit_robot", AIBinding::haveFirstAidKit_robot },
        { "needsSplint", AIBinding::needsSplint },
        { "hasSplintKit", AIBinding::hasSplintKit },
        { "hasTools", AIBinding::hasTools },
        { "isCrouching", AIBinding::isCrouching },
        { "isCrouchingOrLying", AIBinding::isCrouchingOrLying },
        { "isLyingProne", AIBinding::isLyingProne },
        { "isMovementAllowed", AIBinding::isMovementAllowed },
        { "isAtHome", AIBinding::isAtHome },
        { "isAtHomeTown", AIBinding::isAtHomeTown },
        { "targetStandingStill", AIBinding::targetStandingStill },
        { "hasOneWorkingArm", AIBinding::hasOneWorkingArm },
        { "hasTwoWorkingArms", AIBinding::hasTwoWorkingArms },
        { "isReadyForAction", AIBinding::isReadyForAction },
        { "iAmDown", AIBinding::iAmDown },
        { "iAmProne", AIBinding::iAmProne },
        { "canGetUp", AIBinding::canGetUp },
        { "scoreCanGetUp", AIBinding::scoreCanGetUp },
        { "isCarryingSomething", AIBinding::isCarryingSomething },
        { "isCarriedDudeInBed", AIBinding::isCarriedDudeInBed },
        { "isCarriedDudeDead", AIBinding::isCarriedDudeDead },
        { "isCarryingTarget", AIBinding::isCarryingTarget },
        { "final_gotAKidnapVictim", AIBinding::final_gotAKidnapVictim },
        { "final_foundAndPutInCage", AIBinding::final_foundAndPutInCage },
        { "targetIsArrested", AIBinding::targetIsArrested },
        { "alarmsInTheVicinity", AIBinding::alarmsInTheVicinity },
        { "intruderIsOutside", AIBinding::intruderIsOutside },
        { "intruderIsOutsideGates", AIBinding::intruderIsOutsideGates },
        { "amSwimming", AIBinding::amSwimming },
        { "isTargetSwimming", AIBinding::isTargetSwimming },
        { "isBeingCarried", AIBinding::isBeingCarried },
        { "hasBuildingMaterials", AIBinding::hasBuildingMaterials },
        { "buildingHasBuildingMaterials", AIBinding::buildingHasBuildingMaterials },
        { "isDoorBroken", AIBinding::isDoorBroken },
        { "isDoorOpen", AIBinding::isDoorOpen },
        { "isDoorOpenHere", AIBinding::isDoorOpenHere },
        { "iAmInsideTargetBuilding", AIBinding::iAmInsideTargetBuilding },
        { "farmHasFood", AIBinding::farmHasFood },
        { "amHungry", AIBinding::amHungry },
        { "iHaveSufficientLockSkill", AIBinding::iHaveSufficientLockSkill },
        { "iHaveSufficientLockSkillForShackles", AIBinding::iHaveSufficientLockSkillForShackles },
        { "scoreIAmInsideTargetBuilding", AIBinding::scoreIAmInsideTargetBuilding },
        { "scoreIAmOutsideTargetBuilding", AIBinding::scoreIAmOutsideTargetBuilding },
        { "machineHasEmptyInputs", AIBinding::machineHasEmptyInputs },
        { "isMachineOutputFull", AIBinding::isMachineOutputFull },
        { "machineHasFullInputs", AIBinding::machineHasFullInputs },
        { "isMachineOutputEmpty", AIBinding::isMachineOutputEmpty },
        { "haveSomeResourcesFrom", AIBinding::haveSomeResourcesFrom },
        { "haveSomeResourcesFromThisMachineButWantThemGoneIfPossible", AIBinding::haveSomeResourcesFromThisMachineButWantThemGoneIfPossible },
        { "haveSomeResourcesFor", AIBinding::haveSomeResourcesFor },
        { "isMachineJammed", AIBinding::isMachineJammed },
        { "isAnyMachineJammed", AIBinding::isAnyMachineJammed },
        { "isMachineInputInvalid", AIBinding::isMachineInputInvalid },
        { "gotInventoryRoomForResources", AIBinding::gotInventoryRoomForResources },
        { "isRouteTraceBlocked", AIBinding::isRouteTraceBlocked },
        { "isDoorLocked", AIBinding::isDoorLocked },
        { "isDoorLockedHere", AIBinding::isDoorLockedHere },
        { "isDoorLockedAndMeInside", AIBinding::isDoorLockedAndMeInside },
        { "isDoorLockedAndMeOutside", AIBinding::isDoorLockedAndMeOutside },
        { "isObjectMine", AIBinding::isObjectMine },
        { "isBuildingDamaged", AIBinding::isBuildingDamaged },
        { "isBuildingDestroyed", AIBinding::isBuildingDestroyed },
        { "isFullyRested", AIBinding::isFullyRested },
        { "machineHasFreeOperatorSlot", AIBinding::machineHasFreeOperatorSlot },
        { "isDialogDelivered", AIBinding::isDialogDelivered },
        { "isMessageDelivered", AIBinding::isMessageDelivered },
        { "isEnemyForceDefeated", AIBinding::isEnemyForceDefeated },
        { "isInBed", AIBinding::isInBed },
        { "isCarryingArmOK", AIBinding::isCarryingArmOK },
        { "isAtAShop", AIBinding::isAtAShop },
        { "boughtShitComplete", AIBinding::boughtShitComplete },
        { "isInsideTargetBuilding", AIBinding::isInsideTargetBuilding },
        { "allDoorsLocked", AIBinding::allDoorsLocked },
        { "destinationNotBlockedByFortifications", AIBinding::destinationNotBlockedByFortifications },
        { "atLocationGate", AIBinding::atLocationGate },
        { "isAlly", AIBinding::isAlly },
        { "buildingHasPower", AIBinding::buildingHasPower },
        { "hasDestinationTown", AIBinding::hasDestinationTown },
        { "isCarryingHealthyTarget", AIBinding::isCarryingHealthyTarget },
        { "atDestinationTown", AIBinding::atDestinationTown },
        { "atPackageTarget", AIBinding::atPackageTarget },
        { "atATown", AIBinding::atATown },
        { "targetAtATown", AIBinding::targetAtATown },
        { "isTiredFromTravel", AIBinding::isTiredFromTravel },
        { "scoreGetNextDestinationTown", AIBinding::scoreGetNextDestinationTown },
        { "scoreWantsToGetUp_toFeet", AIBinding::scoreWantsToGetUp_toFeet },
        { "scoreWantsToGetUp_stayLow", AIBinding::scoreWantsToGetUp_stayLow },
        { "isNearTo", AIBinding::isNearTo },
        { "isWithin50Meters", AIBinding::isWithin50Meters },
        { "isWithin10Meters", AIBinding::isWithin10Meters },
        { "isWithinMyBowRange", AIBinding::isWithinMyBowRange },
        { "isTargetRestrainedOrKO", AIBinding::isTargetRestrainedOrKO },
        { "isOccupantAlive", AIBinding::isOccupantAlive },
        { "cagesAreAllFull", AIBinding::cagesAreAllFull },
        { "iAmImprisoned", AIBinding::iAmImprisoned },
        { "targetIsImprisoned", AIBinding::targetIsImprisoned },
        { "targetIsMySlave", AIBinding::targetIsMySlave },
        { "iveDitchedAllMyResources", AIBinding::iveDitchedAllMyResources },
        { "targetHasBeenLootedOfResources", AIBinding::targetHasBeenLootedOfResources },
        { "targetHasBeenLooted", AIBinding::targetHasBeenLooted },
        { "usingTurret_Any", AIBinding::usingTurret_Any },
        { "usingTurret_Target", AIBinding::usingTurret_Target },
        { "strangersAreInMyBuilding", AIBinding::strangersAreInMyBuilding },
        { "strangersAreInMyBuilding_andPrivate", AIBinding::strangersAreInMyBuilding_andPrivate },
        { "buildingIsPublic", AIBinding::buildingIsPublic },
        { "targetIsUnarmed", AIBinding::targetIsUnarmed },
        { "_targetLooksLikeASlave", AIBinding::_targetLooksLikeASlave },
        { "carryingExcessLoot", AIBinding::carryingExcessLoot },
        { "isWorking", AIBinding::isWorking },
        { "gotAFoodItem", AIBinding::gotAFoodItem },
        { "iHaveSomeSlaves", AIBinding::iHaveSomeSlaves },
        { "getALootableResourceItemFromTargetThatWeHaveStorageFor", AIBinding::getALootableResourceItemFromTargetThatWeHaveStorageFor },
        { "targetLooksLikeASlave", AIBinding::targetLooksLikeASlave },
        { "slaveIsEscaping", AIBinding::slaveIsEscaping },
        { "slaveIsFollowingOrders", AIBinding::slaveIsFollowingOrders },
        { "isRunningAway", AIBinding::isRunningAway },
        { "isWearingShackles", AIBinding::isWearingShackles },
        { "isWearingShackles_locked", AIBinding::isWearingShackles_locked },
        { "isTargetEscapee", AIBinding::isTargetEscapee },
        { "isTargetInRangeForOrders", AIBinding::isTargetInRangeForOrders },
        { "isTargetInRangeForHOLDMode_hostiles", AIBinding::isTargetInRangeForHOLDMode_hostiles },
        { "getMaxTargetRangeForOrdersSq", AIBinding::getMaxTargetRangeForOrdersSq },
        { "targetMyself", AIBinding::targetMyself },
        { "findWeapon", AIBinding::findWeapon },
        { "findSomebodyToLoot", AIBinding::findSomebodyToLoot },
        { "findAttackerOf", AIBinding::findAttackerOf },
        { "findAggressiveFellows", AIBinding::findAggressiveFellows },
        { "wantGuardAggressionNeutralTargetCheck", AIBinding::wantGuardAggressionNeutralTargetCheck },
        { "findBounty", AIBinding::findBounty },
        { "findKOIntruder", AIBinding::findKOIntruder },
        { "findKOIntruder_town", AIBinding::findKOIntruder_town },
        { "findTurretToUse", AIBinding::findTurretToUse },
        { "findTurretToUseOnMyBuilding", AIBinding::findTurretToUseOnMyBuilding },
        { "findMeleeOpponentForTerritorialAggression", AIBinding::findMeleeOpponentForTerritorialAggression },
        { "findMeleeOpponentForFightingSlave", AIBinding::findMeleeOpponentForFightingSlave },
        { "findMeleeOpponentForTerritorialAggressionWithNeutrals", AIBinding::findMeleeOpponentForTerritorialAggressionWithNeutrals },
        { "findMeleeOpponent", AIBinding::findMeleeOpponent },
        { "findMeleeOpponentNearMyTown", AIBinding::findMeleeOpponentNearMyTown },
        { "findMeleeOpponentFromSquad", AIBinding::findMeleeOpponentFromSquad },
        { "shouldIFreeMySlaveBuddies", AIBinding::shouldIFreeMySlaveBuddies },
        { "findAllyInNeed", AIBinding::findAllyInNeed },
        { "findAllyInNeed_stayInTown", AIBinding::findAllyInNeed_stayInTown },
        { "findSquadmateInNeed", AIBinding::findSquadmateInNeed },
        { "findHome", AIBinding::findHome },
        { "findShopkeeperNode", AIBinding::findShopkeeperNode },
        { "findDefensiveNode", AIBinding::findDefensiveNode },
        { "findGuardNodeForBuilding_inOrOut", AIBinding::findGuardNodeForBuilding_inOrOut },
        { "findGuardNodeForBuilding_indoorOnly", AIBinding::findGuardNodeForBuilding_indoorOnly },
        { "findGuardNodeForBuilding_nearestPlayer", AIBinding::findGuardNodeForBuilding_nearestPlayer },
        { "findGuardNodeForTown", AIBinding::findGuardNodeForTown },
        { "findGeneralNode", AIBinding::findGeneralNode },
        { "findGoodRecruitNode", AIBinding::findGoodRecruitNode },
        { "findPublicGeneralNodeInTown", AIBinding::findPublicGeneralNodeInTown },
        { "findWoundedAllies", AIBinding::findWoundedAllies },
        { "findSplintableAllies", AIBinding::findSplintableAllies },
        { "findWoundedAllies_Robots", AIBinding::findWoundedAllies_Robots },
        { "_findWoundedAllies", AIBinding::_findWoundedAllies },
        { "findPrisonerFreeToGo", AIBinding::findPrisonerFreeToGo },
        { "findPrisonerToLiberate", AIBinding::findPrisonerToLiberate },
        { "findPrisonerWithContraband", AIBinding::findPrisonerWithContraband },
        { "getCurrentBuilding", AIBinding::getCurrentBuilding },
        { "getDestinationBuilding", AIBinding::getDestinationBuilding },
        { "findJammedMachine", AIBinding::findJammedMachine },
        { "findResourceSourceForMe", AIBinding::findResourceSourceForMe },
        { "findResourceDestinationForMe", AIBinding::findResourceDestinationForMe },
        { "findResourceDestinationFor", AIBinding::findResourceDestinationFor },
        { "findResourceDestinationForMyLoot", AIBinding::findResourceDestinationForMyLoot },
        { "findMineToWorkAt", AIBinding::findMineToWorkAt },
        { "findMineToWorkAt_pretend", AIBinding::findMineToWorkAt_pretend },
        { "findSomethingToDoInHome", AIBinding::findSomethingToDoInHome },
        { "findSomethingToDo_lazy", AIBinding::findSomethingToDo_lazy },
        { "findThrone", AIBinding::findThrone },
        { "findBuildingMaterials", AIBinding::findBuildingMaterials },
        { "findTalkTarget", AIBinding::findTalkTarget },
        { "findDisabledAlly", AIBinding::findDisabledAlly },
        { "findDisabledDude", AIBinding::findDisabledDude },
        { "findDisabledNonAlly", AIBinding::findDisabledNonAlly },
        { "findSomeoneWhoWouldMakeAGoodSlave", AIBinding::findSomeoneWhoWouldMakeAGoodSlave },
        { "findBadSlaves", AIBinding::findBadSlaves },
        { "findNewSlaveOrPrisonerToProcess", AIBinding::findNewSlaveOrPrisonerToProcess },
        { "findRandomOneOfMySlaves", AIBinding::findRandomOneOfMySlaves },
        { "findConsciousSlaveInTown", AIBinding::findConsciousSlaveInTown },
        { "findConsciousSlaveInTownForShipping", AIBinding::findConsciousSlaveInTownForShipping },
        { "findConsciousSlaveInTown_unholy", AIBinding::findConsciousSlaveInTown_unholy },
        { "findKOedSlaveOfMine", AIBinding::findKOedSlaveOfMine },
        { "findCorpse_onGround", AIBinding::findCorpse_onGround },
        { "findCorpse_onGround_detail", AIBinding::findCorpse_onGround_detail },
        { "findCorpse_includingCages", AIBinding::findCorpse_includingCages },
        { "findDeadOrKOBody_onGround", AIBinding::findDeadOrKOBody_onGround },
        { "findCrops", AIBinding::findCrops },
        { "findOwnedFreeBed", AIBinding::findOwnedFreeBed },
        { "findOwnedFreeCage", AIBinding::findOwnedFreeCage },
        { "findSlaveBuyer", AIBinding::findSlaveBuyer },
        { "findEmptyCageBelongingToMaster", AIBinding::findEmptyCageBelongingToMaster },
        { "findOwnedFullCage_MarkForDeath", AIBinding::findOwnedFullCage_MarkForDeath },
        { "findCorpseDisposal", AIBinding::findCorpseDisposal },
        { "findShop", AIBinding::findShop },
        { "findPackageTarget", AIBinding::findPackageTarget },
        { "getDestinationGate", AIBinding::getDestinationGate },
        { "getBuildingToSmash", AIBinding::getBuildingToSmash },
        { "findSomethingToBuild", AIBinding::findSomethingToBuild },
        { "findNearestHomeBase", AIBinding::findNearestHomeBase },
        { "findNextTown", AIBinding::findNextTown },
        { "findSomethingToLootFoodFrom", AIBinding::findSomethingToLootFoodFrom },
        { "findFoodOnGround", AIBinding::findFoodOnGround },
        { "findLimbOnGround", AIBinding::findLimbOnGround },
        { "targetMyLeader", AIBinding::targetMyLeader },
        { "targetMySlavemaster", AIBinding::targetMySlavemaster },
        { "targetMyLeader_theRealOne", AIBinding::targetMyLeader_theRealOne },
        { "findUnlockedDoorHere", AIBinding::findUnlockedDoorHere },
        { "findLockedOrClosedDoorHere", AIBinding::findLockedOrClosedDoorHere },
        { "findStrangersInMyBuilding", AIBinding::findStrangersInMyBuilding },
        { "findUnlockedCage", AIBinding::findUnlockedCage },
        { "findRandomBuildingInTown", AIBinding::findRandomBuildingInTown },
        { "findFogmanWorshipTarget", AIBinding::findFogmanWorshipTarget },
        { "findAnimalsToLoot", AIBinding::findAnimalsToLoot },
        { "findAllyAnimalWithFoodInMouth", AIBinding::findAllyAnimalWithFoodInMouth },
        { "findBodyWithResourceToLoot", AIBinding::findBodyWithResourceToLoot },
        { "_findOwnedCageThing", AIBinding::_findOwnedCageThing },
        { "findNode", AIBinding::findNode },
        { "itemOnGroundStealingCheckIsSafe", AIBinding::itemOnGroundStealingCheckIsSafe },
        { "findSomeoneToLoot", AIBinding::findSomeoneToLoot },
        { "getAllLocalMachines", AIBinding::getAllLocalMachines },
        { "findResourceStorageBulidingFor", AIBinding::findResourceStorageBulidingFor },
        { "rateWeapon", AIBinding::rateWeapon },
        { "_NV_rateWeapon", AIBinding::_NV_rateWeapon },
        { "canUseWeapon", AIBinding::canUseWeapon },
        { "_NV_canUseWeapon", AIBinding::_NV_canUseWeapon },
        { "scoreTargetRange", AIBinding::scoreTargetRange },
        { "scoreDistanceTo", AIBinding::scoreDistanceTo },
        { "scoreSplint", AIBinding::scoreSplint },
        { "scoreFirstAid", AIBinding::scoreFirstAid },
        { "scoreFixMyLegs", AIBinding::scoreFixMyLegs },
        { "scoreFirstAidRobot", AIBinding::scoreFirstAidRobot },
        { "scorePutCarriedDudeDown", AIBinding::scorePutCarriedDudeDown },
        { "scoreJobMedic", AIBinding::scoreJobMedic },
        { "scorePutCarriedDudeInBed", AIBinding::scorePutCarriedDudeInBed },
        { "scorePutCarriedDudeInCage", AIBinding::scorePutCarriedDudeInCage },
        { "scoreCarryingIntruder", AIBinding::scoreCarryingIntruder },
        { "scoreFindAndRescue", AIBinding::scoreFindAndRescue },
        { "scoreFindAndRescueIfTheresBeds", AIBinding::scoreFindAndRescueIfTheresBeds },
        { "scoreRescueLeader", AIBinding::scoreRescueLeader },
        { "scoreFindAndKidnap", AIBinding::scoreFindAndKidnap },
        { "scoreKidnapperCageJob", AIBinding::scoreKidnapperCageJob },
        { "scoreShopping", AIBinding::scoreShopping },
        { "scoreProtectAllies", AIBinding::scoreProtectAllies },
        { "_NV_scoreProtectAllies", AIBinding::_NV_scoreProtectAllies },
        { "scoreStayClose", AIBinding::scoreStayClose },
        { "_NV_scoreStayClose", AIBinding::_NV_scoreStayClose },
        { "scoreStayCloseIsh", AIBinding::scoreStayCloseIsh },
        { "_NV_scoreStayCloseIsh", AIBinding::_NV_scoreStayCloseIsh },
        { "scorePutDudeInCage", AIBinding::scorePutDudeInCage },
        { "scoreUnderAttack", AIBinding::scoreUnderAttack },
        { "_NV_scoreUnderAttack", AIBinding::_NV_scoreUnderAttack },
        { "scoreEmptyMachine", AIBinding::scoreEmptyMachine },
        { "_NV_scoreEmptyMachine", AIBinding::_NV_scoreEmptyMachine },
        { "scoreNone", AIBinding::scoreNone },
        { "_NV_scoreNone", AIBinding::_NV_scoreNone },
        { "scoreCannibalKill", AIBinding::scoreCannibalKill },
        { "_NV_scoreCannibalKill", AIBinding::_NV_scoreCannibalKill },
        { "scoreAutoMachinery", AIBinding::scoreAutoMachinery },
        { "_NV_scoreAutoMachinery", AIBinding::_NV_scoreAutoMachinery },
        { "scoreCollectOutputResource", AIBinding::scoreCollectOutputResource },
        { "_NV_scoreCollectOutputResource", AIBinding::_NV_scoreCollectOutputResource },
        { "scoreCollectOutputResourceForBuildMats", AIBinding::scoreCollectOutputResourceForBuildMats },
        { "_NV_scoreCollectOutputResourceForBuildMats", AIBinding::_NV_scoreCollectOutputResourceForBuildMats },
        { "scoreGetFood_inHomeTown", AIBinding::scoreGetFood_inHomeTown },
        { "_NV_scoreGetFood_inHomeTown", AIBinding::_NV_scoreGetFood_inHomeTown },
        { "scoreFindFoodOnGround", AIBinding::scoreFindFoodOnGround },
        { "_NV_scoreFindFoodOnGround", AIBinding::_NV_scoreFindFoodOnGround },
        { "scoreGetFood_inHomeTown_andFeedAnimals", AIBinding::scoreGetFood_inHomeTown_andFeedAnimals },
        { "_NV_scoreGetFood_inHomeTown_andFeedAnimals", AIBinding::_NV_scoreGetFood_inHomeTown_andFeedAnimals },
        { "scoreUnlockDoorHere", AIBinding::scoreUnlockDoorHere },
        { "_NV_scoreUnlockDoorHere", AIBinding::_NV_scoreUnlockDoorHere },
        { "scoreGetOutOfBed", AIBinding::scoreGetOutOfBed },
        { "_NV_scoreGetOutOfBed", AIBinding::_NV_scoreGetOutOfBed },
        { "scoreGetOutOfBedOnceFullyHealed", AIBinding::scoreGetOutOfBedOnceFullyHealed },
        { "_NV_scoreGetOutOfBedOnceFullyHealed", AIBinding::_NV_scoreGetOutOfBedOnceFullyHealed },
        { "scoreGoToBed", AIBinding::scoreGoToBed },
        { "_NV_scoreGoToBed", AIBinding::_NV_scoreGoToBed },
        { "scoreHomeIsNotLockedUp", AIBinding::scoreHomeIsNotLockedUp },
        { "_NV_scoreHomeIsNotLockedUp", AIBinding::_NV_scoreHomeIsNotLockedUp },
        { "scoreDontLeaveTown", AIBinding::scoreDontLeaveTown },
        { "_NV_scoreDontLeaveTown", AIBinding::_NV_scoreDontLeaveTown },
        { "scoreFoundCages", AIBinding::scoreFoundCages },
        { "_NV_scoreFoundCages", AIBinding::_NV_scoreFoundCages },
        { "scoreHasWorkingArm", AIBinding::scoreHasWorkingArm },
        { "_NV_scoreHasWorkingArm", AIBinding::_NV_scoreHasWorkingArm },
        { "scoreUseTurret", AIBinding::scoreUseTurret },
        { "_NV_scoreUseTurret", AIBinding::_NV_scoreUseTurret },
        { "scoreAggressiveAction", AIBinding::scoreAggressiveAction },
        { "_NV_scoreAggressiveAction", AIBinding::_NV_scoreAggressiveAction },
        { "scoreBashGate", AIBinding::scoreBashGate },
        { "_NV_scoreBashGate", AIBinding::_NV_scoreBashGate },
        { "scoreNPCEscapeCageOpportunity", AIBinding::scoreNPCEscapeCageOpportunity },
        { "_NV_scoreNPCEscapeCageOpportunity", AIBinding::_NV_scoreNPCEscapeCageOpportunity },
        { "score01", AIBinding::score01 },
        { "_NV_score01", AIBinding::_NV_score01 },
        { "score025", AIBinding::score025 },
        { "_NV_score025", AIBinding::_NV_score025 },
        { "score05", AIBinding::score05 },
        { "_NV_score05", AIBinding::_NV_score05 },
        { "score08", AIBinding::score08 },
        { "_NV_score08", AIBinding::_NV_score08 },
        { "score10", AIBinding::score10 },
        { "_NV_score10", AIBinding::_NV_score10 },
        { "scoreCanSeeTarget", AIBinding::scoreCanSeeTarget },
        { "_NV_scoreCanSeeTarget", AIBinding::_NV_scoreCanSeeTarget },
        { "score12", AIBinding::score12 },
        { "_NV_score12", AIBinding::_NV_score12 },
        { "score15", AIBinding::score15 },
        { "_NV_score15", AIBinding::_NV_score15 },
        { "score20", AIBinding::score20 },
        { "_NV_score20", AIBinding::_NV_score20 },
        { "scoreRandomFluff", AIBinding::scoreRandomFluff },
        { "_NV_scoreRandomFluff", AIBinding::_NV_scoreRandomFluff },
        { "scoreHuntingBlood", AIBinding::scoreHuntingBlood },
        { "_NV_scoreHuntingBlood", AIBinding::_NV_scoreHuntingBlood },
        { "scoreHuntingEggs", AIBinding::scoreHuntingEggs },
        { "_NV_scoreHuntingEggs", AIBinding::_NV_scoreHuntingEggs },
        { "scoreTargetInDanger", AIBinding::scoreTargetInDanger },
        { "_NV_scoreTargetInDanger", AIBinding::_NV_scoreTargetInDanger },
        { "scoreAttackEnemies", AIBinding::scoreAttackEnemies },
        { "_NV_scoreAttackEnemies", AIBinding::_NV_scoreAttackEnemies },
        { "scoreMeleeAttack", AIBinding::scoreMeleeAttack },
        { "_NV_scoreMeleeAttack", AIBinding::_NV_scoreMeleeAttack },
        { "scoreRangedAttack", AIBinding::scoreRangedAttack },
        { "_NV_scoreRangedAttack", AIBinding::_NV_scoreRangedAttack },
        { "scoreRunAway", AIBinding::scoreRunAway },
        { "_NV_scoreRunAway", AIBinding::_NV_scoreRunAway },
        { "scoreRetreat", AIBinding::scoreRetreat },
        { "_NV_scoreRetreat", AIBinding::_NV_scoreRetreat },
        { "scoreMove", AIBinding::scoreMove },
        { "_NV_scoreMove", AIBinding::_NV_scoreMove },
        { "scoreDontWantToBeUnarmed", AIBinding::scoreDontWantToBeUnarmed },
        { "_NV_scoreDontWantToBeUnarmed", AIBinding::_NV_scoreDontWantToBeUnarmed },
        { "scoreLiftObject", AIBinding::scoreLiftObject },
        { "_NV_scoreLiftObject", AIBinding::_NV_scoreLiftObject },
        { "scoreLiftIntruder", AIBinding::scoreLiftIntruder },
        { "_NV_scoreLiftIntruder", AIBinding::_NV_scoreLiftIntruder },
        { "scoreChainNewSlave", AIBinding::scoreChainNewSlave },
        { "_NV_scoreChainNewSlave", AIBinding::_NV_scoreChainNewSlave },
        { "scoreNotDown", AIBinding::scoreNotDown },
        { "_NV_scoreNotDown", AIBinding::_NV_scoreNotDown },
        { "scoreNoMoreThan4Slaves", AIBinding::scoreNoMoreThan4Slaves },
        { "_NV_scoreNoMoreThan4Slaves", AIBinding::_NV_scoreNoMoreThan4Slaves },
        { "scoreSlaveExportTown", AIBinding::scoreSlaveExportTown },
        { "_NV_scoreSlaveExportTown", AIBinding::_NV_scoreSlaveExportTown },
        { "scoreHasSomeSlaves", AIBinding::scoreHasSomeSlaves },
        { "_NV_scoreHasSomeSlaves", AIBinding::_NV_scoreHasSomeSlaves },
        { "scoreHasSomeSlavesAndAtImportTown", AIBinding::scoreHasSomeSlavesAndAtImportTown },
        { "_NV_scoreHasSomeSlavesAndAtImportTown", AIBinding::_NV_scoreHasSomeSlavesAndAtImportTown },
        { "scoreAmTheRealLeader", AIBinding::scoreAmTheRealLeader },
        { "_NV_scoreAmTheRealLeader", AIBinding::_NV_scoreAmTheRealLeader },
        { "scoreAtAttackableTown", AIBinding::scoreAtAttackableTown },
        { "_NV_scoreAtAttackableTown", AIBinding::_NV_scoreAtAttackableTown },
        { "scoreDogPlaying", AIBinding::scoreDogPlaying },
        { "_NV_scoreDogPlaying", AIBinding::_NV_scoreDogPlaying },
        { "scoreDogPlayingChase", AIBinding::scoreDogPlayingChase },
        { "_NV_scoreDogPlayingChase", AIBinding::_NV_scoreDogPlayingChase },
        { "scoreHomeIsPrivate", AIBinding::scoreHomeIsPrivate },
        { "_NV_scoreHomeIsPrivate", AIBinding::_NV_scoreHomeIsPrivate },
        { "scoreNotKOOrPlayingDead", AIBinding::scoreNotKOOrPlayingDead },
        { "_NV_scoreNotKOOrPlayingDead", AIBinding::_NV_scoreNotKOOrPlayingDead },
        { "scoreTargetInMyTown", AIBinding::scoreTargetInMyTown },
        { "_NV_scoreTargetInMyTown", AIBinding::_NV_scoreTargetInMyTown },
        { 0, 0 }
    };

    registerClass(
        L,
        AIBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AIBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "meiDistance", AI_get_meiDistance);
    registerGetter(L, "meiDistanceTolerance", AI_get_meiDistanceTolerance);
    registerGetter(L, "platoon", AI_get_platoon);
    registerGetter(L, "state", AI_get_state);
    registerGetter(L, "sensoryData", AI_get_sensoryData);
    registerGetter(L, "taskRepertoireFlags", AI_get_taskRepertoireFlags);
    registerGetter(L, "ordersAggression", AI_get_ordersAggression);
    registerGetter(L, "ordersMovement", AI_get_ordersMovement);
    registerGetter(L, "centerOfMovement", AI_get_centerOfMovement);
    registerGetter(L, "centerOfMovementTarget", AI_get_centerOfMovementTarget);
    registerGetter(L, "slaveStateTimeStamp", AI_get_slaveStateTimeStamp);
    registerGetter(L, "me", AI_get_me);
    registerGetter(L, "body", AI_get_body);
    registerGetter(L, "inventory", AI_get_inventory);
    registerGetter(L, "stats", AI_get_stats);
    registerGetter(L, "medical", AI_get_medical);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "meiDistance", AI_set_meiDistance);
    registerSetter(L, "meiDistanceTolerance", AI_set_meiDistanceTolerance);
    registerSetter(L, "platoon", AI_set_platoon);
    registerSetter(L, "state", AI_set_state);
    registerSetter(L, "taskRepertoireFlags", AI_set_taskRepertoireFlags);
    registerSetter(L, "ordersAggression", AI_set_ordersAggression);
    registerSetter(L, "ordersMovement", AI_set_ordersMovement);
    registerSetter(L, "centerOfMovement", AI_set_centerOfMovement);
    registerSetter(L, "centerOfMovementTarget", AI_set_centerOfMovementTarget);
    registerSetter(L, "slaveStateTimeStamp", AI_set_slaveStateTimeStamp);
    registerSetter(L, "me", AI_set_me);
    registerSetter(L, "body", AI_set_body);
    registerSetter(L, "inventory", AI_set_inventory);
    registerSetter(L, "stats", AI_set_stats);
    registerSetter(L, "medical", AI_set_medical);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
