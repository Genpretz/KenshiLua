#include "pch.h"
#include "kenshi\Platoon.h"
#include "ActivePlatoonBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/DataObjectContainerBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/FactoryCallbackInterfaceBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/PlayerInterfaceBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/RootObjectContainerBinding.h"
#include "Bindings/TaskerBinding.h"
#include "Bindings/Util/YesNoMaybeBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "FactoryCallbackInterfaceBinding.h"
#include "PlayerInterfaceBinding.h"
#include "RootObjectBinding.h"
#include "TaskerBinding.h"
#include "Util/LektorBinding.h"
#include "kenshi/PlayerInterface.h"

namespace KenshiLua
{

static ActivePlatoon* getInstance(lua_State* L, int idx)
{
    return checkObject<ActivePlatoon>(L, idx, ActivePlatoonBinding::getMetatableName());
}

// --- Getters for ActivePlatoon ---
static int ActivePlatoon_get__groupSense(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    lua_pushlightuserdata(L, (void*)instance->_groupSense);
    return 1;
}

static int ActivePlatoon_get_isAnimalsOnly(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    lua_pushboolean(L, instance->isAnimalsOnly ? 1 : 0);
    return 1;
}

static int ActivePlatoon_get_me(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    return pushObject<Platoon>(L, instance->me, PlatoonBinding::getMetatableName());
}

static int ActivePlatoon_get_characterHandles(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    lua_pushlightuserdata(L, (void*)instance->characterHandles);
    return 1;
}

static int ActivePlatoon_get_p_TIME(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    lua_pushnumber(L, instance->p_TIME);
    return 1;
}

static int ActivePlatoon_get_lastActiveZone(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    return pushObject<ZoneMap>(L, instance->lastActiveZone, ZoneMapBinding::getMetatableName());
}

static int ActivePlatoon_get__myMemory(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    lua_pushlightuserdata(L, (void*)instance->_myMemory);
    return 1;
}

static int ActivePlatoon_get_squadleader(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    return pushObject<Character>(L, instance->squadleader, CharacterBinding::getMetatableName());
}

static int ActivePlatoon_get_backupLeader(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    return pushObject<Character>(L, instance->backupLeader, CharacterBinding::getMetatableName());
}

static int ActivePlatoon_get_deactivationTimer(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    lua_pushnumber(L, instance->deactivationTimer);
    return 1;
}

static int ActivePlatoon_get_workingPos(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    pushVector3(L, instance->workingPos);
    return 1;
}

static int ActivePlatoon_get_currentGoal(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    return pushObject<Tasker>(L, instance->currentGoal, TaskerBinding::getMetatableName());
}

static int ActivePlatoon_get_positionMoved(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    pushVector3(L, instance->positionMoved);
    return 1;
}

static int ActivePlatoon_get_teleportTo(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    pushVector3(L, instance->teleportTo);
    return 1;
}

static int ActivePlatoon_get_teleportMessage(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    lua_pushboolean(L, instance->teleportMessage ? 1 : 0);
    return 1;
}

static int ActivePlatoon_get_isPlayer(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    return pushObject<PlayerInterface>(L, instance->isPlayer, PlayerInterfaceBinding::getMetatableName());
}

static int ActivePlatoon_get_isPhysical(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    lua_pushboolean(L, instance->isPhysical ? 1 : 0);
    return 1;
}

// --- Setters for ActivePlatoon ---
static int ActivePlatoon_set_isAnimalsOnly(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    instance->isAnimalsOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ActivePlatoon_set_me(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    return 0;
}

static int ActivePlatoon_set_p_TIME(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    instance->p_TIME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ActivePlatoon_set_lastActiveZone(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    instance->lastActiveZone = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    return 0;
}

static int ActivePlatoon_set_squadleader(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    instance->squadleader = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int ActivePlatoon_set_backupLeader(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    instance->backupLeader = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int ActivePlatoon_set_deactivationTimer(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    instance->deactivationTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ActivePlatoon_set_workingPos(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    readVector3(L, 2, instance->workingPos);
    return 0;
}

static int ActivePlatoon_set_currentGoal(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    instance->currentGoal = lua_isnoneornil(L, 2) ? nullptr : checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    return 0;
}

static int ActivePlatoon_set_positionMoved(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    readVector3(L, 2, instance->positionMoved);
    return 0;
}

static int ActivePlatoon_set_teleportTo(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    readVector3(L, 2, instance->teleportTo);
    return 0;
}

static int ActivePlatoon_set_teleportMessage(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    instance->teleportMessage = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ActivePlatoon_set_isPlayer(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    instance->isPlayer = lua_isnoneornil(L, 2) ? nullptr : checkObject<PlayerInterface>(L, 2, PlayerInterfaceBinding::getMetatableName());
    return 0;
}

static int ActivePlatoon_set_isPhysical(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    instance->isPhysical = lua_toboolean(L, 2) != 0;
    return 0;
}

int ActivePlatoonBinding::_recalculateIsIntact(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool result = instance->_recalculateIsIntact();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::isAnyoneCaptured(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool result = instance->isAnyoneCaptured();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::_DESTRUCTOR(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ActivePlatoonBinding::getGroupSense(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    GroupSense* result = instance->getGroupSense();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ActivePlatoonBinding::getMemory(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    CharacterMemory* result = instance->getMemory();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ActivePlatoonBinding::removeObject(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->removeObject(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::_NV_removeObject(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->_NV_removeObject(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::addActiveObject(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->addActiveObject(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::_NV_addActiveObject(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->_NV_addActiveObject(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::addCharacterAt(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    int index = (int)luaL_checkinteger(L, 3);
    instance->addCharacterAt(c, index);
    return 0;
}

int ActivePlatoonBinding::swapCharacters(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    int indexA = (int)luaL_checkinteger(L, 2);
    int indexB = (int)luaL_checkinteger(L, 3);
    instance->swapCharacters(indexA, indexB);
    return 0;
}

int ActivePlatoonBinding::emptySquadCheck(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    instance->emptySquadCheck();
    return 0;
}

int ActivePlatoonBinding::clearAllTheUniqueNPCStates(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    instance->clearAllTheUniqueNPCStates();
    return 0;
}

int ActivePlatoonBinding::isIntact(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool result = instance->isIntact();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::getSquadLeader_theRealOne(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    Character* result = instance->getSquadLeader_theRealOne();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int ActivePlatoonBinding::getNearestActiveCharacter(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    int floor = (int)luaL_checkinteger(L, 3);
    Character* result = instance->getNearestActiveCharacter(p, floor);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int ActivePlatoonBinding::getSquadLeader(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    Character* result = instance->getSquadLeader();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int ActivePlatoonBinding::getSquadSize(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    int result = instance->getSquadSize();
    lua_pushinteger(L, result);
    return 1;
}

int ActivePlatoonBinding::setSquadLeader(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->setSquadLeader(who);
    return 0;
}

int ActivePlatoonBinding::update(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool result = instance->update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::_NV_update(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool result = instance->_NV_update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::refreshInventory(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool firstTime = lua_toboolean(L, 2) != 0;
    instance->refreshInventory(firstTime);
    return 0;
}

int ActivePlatoonBinding::_forceRefreshInventory(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    instance->_forceRefreshInventory();
    return 0;
}

int ActivePlatoonBinding::periodicUpdate(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool result = instance->periodicUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::_NV_periodicUpdate(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool result = instance->_NV_periodicUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::serialiseEverythingToDisk(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool levelEditor = lua_toboolean(L, 2) != 0;
    instance->serialiseEverythingToDisk(levelEditor);
    return 0;
}

int ActivePlatoonBinding::isWholeSquadDown(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    int minusThis = (int)luaL_checkinteger(L, 2);
    bool result = instance->isWholeSquadDown(minusThis);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::setDataFilename(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    const std::string f = luaL_checkstring(L, 2);
    instance->setDataFilename(f);
    return 0;
}

int ActivePlatoonBinding::setupLeaderDialogues(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    instance->setupLeaderDialogues();
    return 0;
}

int ActivePlatoonBinding::isLoaded(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool result = instance->isLoaded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::teleport(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    instance->teleport(pos);
    return 0;
}

int ActivePlatoonBinding::setName(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    const std::string name = luaL_checkstring(L, 2);
    instance->setName(name);
    return 0;
}

int ActivePlatoonBinding::getIsTrader(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool result = instance->getIsTrader();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::getHasVendorList(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool result = instance->getHasVendorList();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::getHasSpecialItemsList(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool result = instance->getHasSpecialItemsList();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::setupTraderBuildings(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    instance->setupTraderBuildings();
    return 0;
}

int ActivePlatoonBinding::putTheSpecialCharactersInNewSquads_captured(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    instance->putTheSpecialCharactersInNewSquads_captured();
    return 0;
}

int ActivePlatoonBinding::checkForCharactersBeingCarried(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool result = instance->checkForCharactersBeingCarried();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::restoreSquad(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    instance->restoreSquad();
    return 0;
}

int ActivePlatoonBinding::_CONSTRUCTOR(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    Platoon* my = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    DataObjectContainer* doc = checkObject<DataObjectContainer>(L, 3, DataObjectContainerBinding::getMetatableName());
    Faction* f = checkObject<Faction>(L, 4, FactionBinding::getMetatableName());
    GameData* d = checkObject<GameData>(L, 5, GameDataBinding::getMetatableName());
    Tasker* _currentGoal = checkObject<Tasker>(L, 6, TaskerBinding::getMetatableName());
    Ogre::Vector3 _posOffset;
    readVector3(L, 7, _posOffset);
    ActivePlatoon* result = instance->_CONSTRUCTOR(my, doc, f, d, _currentGoal, _posOffset);
    return pushObject<ActivePlatoon>(L, result, ActivePlatoonBinding::getMetatableName());
}

int ActivePlatoonBinding::unloadCheck(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool result = instance->unloadCheck();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::setupCheck(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    YesNoMaybe result = instance->setupCheck();
    return pushObject<YesNoMaybe>(L, &result, YesNoMaybeBinding::getMetatableName());
}

int ActivePlatoonBinding::destroyCharacters(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool justUnload = lua_toboolean(L, 2) != 0;
    instance->destroyCharacters(justUnload);
    return 0;
}

int ActivePlatoonBinding::serialiseCharacterData(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    instance->serialiseCharacterData();
    return 0;
}

int ActivePlatoonBinding::saveToDisk(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    bool levelEditor = lua_toboolean(L, 2) != 0;
    const std::string force = luaL_checkstring(L, 3);
    instance->saveToDisk(levelEditor, force);
    return 0;
}

int ActivePlatoonBinding::loadCharacters(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    Ogre::Vector3 _a1;
    readVector3(L, 2, _a1);
    FactoryCallbackInterface* _a2 = checkObject<FactoryCallbackInterface>(L, 3, FactoryCallbackInterfaceBinding::getMetatableName());
    instance->loadCharacters(_a1, _a2);
    return 0;
}

int ActivePlatoonBinding::_NV_loadCharacters(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    Ogre::Vector3 _a1;
    readVector3(L, 2, _a1);
    FactoryCallbackInterface* _a2 = checkObject<FactoryCallbackInterface>(L, 3, FactoryCallbackInterfaceBinding::getMetatableName());
    instance->_NV_loadCharacters(_a1, _a2);
    return 0;
}

int ActivePlatoonBinding::calculateCurrentPos(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    Ogre::Vector3 result = instance->calculateCurrentPos();
    pushVector3(L, result);
    return 1;
}

int ActivePlatoonBinding::_checkForUniqueCharactersOnUnload(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    instance->_checkForUniqueCharactersOnUnload();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 207: bool loadFromDisk(...) - unsupported arg type
  line 208: bool _NV_loadFromDisk(...) - unsupported arg type
  line 226: void getCharactersInArea(...) - unsupported arg type
  line 245: const std::string& getName(...) - reference return type
  line 268: void loadInstance(...) - non-string reference arg
  line 269: void _NV_loadInstance(...) - non-string reference arg
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - ActivePlatoon_get__groupSense: GroupSense* (unbound pointer)
  - ActivePlatoon_get_characterHandles: HandleList* (unbound pointer)
  - ActivePlatoon_get__myMemory: CharacterMemory* (unbound pointer)
  - ActivePlatoonBinding::getGroupSense: GroupSense* (unbound pointer)
  - ActivePlatoonBinding::getMemory: CharacterMemory* (unbound pointer)
*/

int ActivePlatoonBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ActivePlatoonBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ActivePlatoon object");
    return 1;
}



static int ActivePlatoon__NV_addActiveObject(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->_NV_addActiveObject(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}


static int ActivePlatoon__NV_loadCharacters(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);

    FactoryCallbackInterface* callback = nullptr;
    if (!lua_isnil(L, 3)) {
        callback = checkObject<FactoryCallbackInterface>(L, 3, FactoryCallbackInterfaceBinding::getMetatableName());
    }

    instance->_NV_loadCharacters(pos, callback);
    return 0;
}


static int ActivePlatoon__NV_loadFromDisk(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    bool force = lua_toboolean(L, 2) != 0;
    Serialisable* extra = nullptr;
    if (!lua_isnil(L, 3)) {
        extra = (Serialisable*)lua_touserdata(L, 3);
        if (!extra) return luaL_error(L, "Argument 3 must be lightuserdata (Serialisable*) or nil");
    }
    bool result = instance->_NV_loadFromDisk(force, extra);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}


static int ActivePlatoon__NV_loadInstance(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());

    bool skipSaveState = lua_toboolean(L, 3) != 0;

    Ogre::Vector3 pos;
    readVector3(L, 4, pos);

    Ogre::Quaternion rot;
    readQuaternion(L, 5, rot);

    FactoryCallbackInterface* callback = nullptr;
    if (!lua_isnil(L, 6)) {
        callback = checkObject<FactoryCallbackInterface>(L, 6, FactoryCallbackInterfaceBinding::getMetatableName());
    }

    Ogre::Vector3 positionMoved;
    readVector3(L, 7, positionMoved);

    instance->_NV_loadInstance(*state, skipSaveState, pos, rot, callback, positionMoved);
    return 0;
}


static int ActivePlatoon__NV_removeObject(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->_NV_removeObject(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}


static int ActivePlatoon_addActiveObject(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->addActiveObject(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}


static int ActivePlatoon_addCharacterAt(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    int index = (int)luaL_checkinteger(L, 3);
    instance->addCharacterAt(c, index);
    return 0;
}


static int ActivePlatoon_getCharactersInArea(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 must be a lektor<RootObject*>");

    Ogre::Vector3 pos;
    readVector3(L, 3, pos);

    float radius = (float)luaL_checknumber(L, 4);
    bool standingOnly = lua_toboolean(L, 5) != 0;

    instance->getCharactersInArea(*out, pos, radius, standingOnly);
    return 0;
}


static int ActivePlatoon_getGroupSense(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    GroupSense* gs = instance->getGroupSense();
    if (gs) {
        lua_pushlightuserdata(L, (void*)gs);
    } else {
        lua_pushnil(L);
    }
    return 1;
}


static int ActivePlatoon_getMemory(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    CharacterMemory* cm = instance->getMemory();
    if (cm) {
        lua_pushlightuserdata(L, (void*)cm);
    } else {
        lua_pushnil(L);
    }
    return 1;
}


static int ActivePlatoon_getName(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    const std::string& result = instance->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}


static int ActivePlatoon_loadCharacters(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);

    FactoryCallbackInterface* callback = nullptr;
    if (!lua_isnil(L, 3)) {
        callback = checkObject<FactoryCallbackInterface>(L, 3, FactoryCallbackInterfaceBinding::getMetatableName());
    }

    instance->loadCharacters(pos, callback);
    return 0;
}


static int ActivePlatoon_loadFromDisk(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    bool force = lua_toboolean(L, 2) != 0;
    Serialisable* extra = nullptr;
    if (!lua_isnil(L, 3)) {
        extra = (Serialisable*)lua_touserdata(L, 3);
        if (!extra) return luaL_error(L, "Argument 3 must be lightuserdata (Serialisable*) or nil");
    }
    bool result = instance->loadFromDisk(force, extra);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}


static int ActivePlatoon_loadInstance(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());

    bool skipSaveState = lua_toboolean(L, 3) != 0;

    Ogre::Vector3 pos;
    readVector3(L, 4, pos);

    Ogre::Quaternion rot;
    readQuaternion(L, 5, rot);

    FactoryCallbackInterface* callback = nullptr;
    if (!lua_isnil(L, 6)) {
        callback = checkObject<FactoryCallbackInterface>(L, 6, FactoryCallbackInterfaceBinding::getMetatableName());
    }

    Ogre::Vector3 positionMoved;
    readVector3(L, 7, positionMoved);

    instance->loadInstance(*state, skipSaveState, pos, rot, callback, positionMoved);
    return 0;
}


static int ActivePlatoon_removeObject(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->removeObject(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}


static int ActivePlatoon_setSquadLeader(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->setSquadLeader(who);
    return 0;
}


static int ActivePlatoon_set__groupSense(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _groupSense");
}


static int ActivePlatoon_set__myMemory(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _myMemory");
}


static int ActivePlatoon_set_characterHandles(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for characterHandles");
}


static int ActivePlatoon_setupCheck(lua_State* L)
{
    ActivePlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActivePlatoon is nil");
    YesNoMaybe result = instance->setupCheck();
    lua_pushinteger(L, static_cast<int>(result.key));
    return 1;
}


void ActivePlatoonBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ActivePlatoonBinding::gc },
        { "__tostring", ActivePlatoonBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_recalculateIsIntact", ActivePlatoonBinding::_recalculateIsIntact },
        { "isAnyoneCaptured", ActivePlatoonBinding::isAnyoneCaptured },
        { "_DESTRUCTOR", ActivePlatoonBinding::_DESTRUCTOR },
        { "getGroupSense", ActivePlatoonBinding::getGroupSense },
        { "getMemory", ActivePlatoonBinding::getMemory },
        { "removeObject", ActivePlatoonBinding::removeObject },
        { "_NV_removeObject", ActivePlatoonBinding::_NV_removeObject },
        { "addActiveObject", ActivePlatoonBinding::addActiveObject },
        { "_NV_addActiveObject", ActivePlatoonBinding::_NV_addActiveObject },
        { "addCharacterAt", ActivePlatoonBinding::addCharacterAt },
        { "swapCharacters", ActivePlatoonBinding::swapCharacters },
        { "emptySquadCheck", ActivePlatoonBinding::emptySquadCheck },
        { "clearAllTheUniqueNPCStates", ActivePlatoonBinding::clearAllTheUniqueNPCStates },
        { "isIntact", ActivePlatoonBinding::isIntact },
        { "getSquadLeader_theRealOne", ActivePlatoonBinding::getSquadLeader_theRealOne },
        { "getNearestActiveCharacter", ActivePlatoonBinding::getNearestActiveCharacter },
        { "getSquadLeader", ActivePlatoonBinding::getSquadLeader },
        { "getSquadSize", ActivePlatoonBinding::getSquadSize },
        { "setSquadLeader", ActivePlatoonBinding::setSquadLeader },
        { "update", ActivePlatoonBinding::update },
        { "_NV_update", ActivePlatoonBinding::_NV_update },
        { "refreshInventory", ActivePlatoonBinding::refreshInventory },
        { "_forceRefreshInventory", ActivePlatoonBinding::_forceRefreshInventory },
        { "periodicUpdate", ActivePlatoonBinding::periodicUpdate },
        { "_NV_periodicUpdate", ActivePlatoonBinding::_NV_periodicUpdate },
        { "serialiseEverythingToDisk", ActivePlatoonBinding::serialiseEverythingToDisk },
        { "isWholeSquadDown", ActivePlatoonBinding::isWholeSquadDown },
        { "setDataFilename", ActivePlatoonBinding::setDataFilename },
        { "setupLeaderDialogues", ActivePlatoonBinding::setupLeaderDialogues },
        { "isLoaded", ActivePlatoonBinding::isLoaded },
        { "teleport", ActivePlatoonBinding::teleport },
        { "setName", ActivePlatoonBinding::setName },
        { "getIsTrader", ActivePlatoonBinding::getIsTrader },
        { "getHasVendorList", ActivePlatoonBinding::getHasVendorList },
        { "getHasSpecialItemsList", ActivePlatoonBinding::getHasSpecialItemsList },
        { "setupTraderBuildings", ActivePlatoonBinding::setupTraderBuildings },
        { "putTheSpecialCharactersInNewSquads_captured", ActivePlatoonBinding::putTheSpecialCharactersInNewSquads_captured },
        { "checkForCharactersBeingCarried", ActivePlatoonBinding::checkForCharactersBeingCarried },
        { "restoreSquad", ActivePlatoonBinding::restoreSquad },
        { "_CONSTRUCTOR", ActivePlatoonBinding::_CONSTRUCTOR },
        { "unloadCheck", ActivePlatoonBinding::unloadCheck },
        { "setupCheck", ActivePlatoonBinding::setupCheck },
        { "destroyCharacters", ActivePlatoonBinding::destroyCharacters },
        { "serialiseCharacterData", ActivePlatoonBinding::serialiseCharacterData },
        { "saveToDisk", ActivePlatoonBinding::saveToDisk },
        { "loadCharacters", ActivePlatoonBinding::loadCharacters },
        { "_NV_loadCharacters", ActivePlatoonBinding::_NV_loadCharacters },
        { "calculateCurrentPos", ActivePlatoonBinding::calculateCurrentPos },
        { "_checkForUniqueCharactersOnUnload", ActivePlatoonBinding::_checkForUniqueCharactersOnUnload },
                { "getName", ActivePlatoon_getName },
        { "loadFromDisk", ActivePlatoon_loadFromDisk },
        { "_NV_loadFromDisk", ActivePlatoon__NV_loadFromDisk },
        { "getCharactersInArea", ActivePlatoon_getCharactersInArea },
        { "loadInstance", ActivePlatoon_loadInstance },
        { "_NV_loadInstance", ActivePlatoon__NV_loadInstance },
        { 0, 0 }
    };

    registerClass(
        L, 
        ActivePlatoonBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ActivePlatoonBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "_groupSense", ActivePlatoon_get__groupSense);
    registerGetter(L, "isAnimalsOnly", ActivePlatoon_get_isAnimalsOnly);
    registerGetter(L, "me", ActivePlatoon_get_me);
    registerGetter(L, "characterHandles", ActivePlatoon_get_characterHandles);
    registerGetter(L, "p_TIME", ActivePlatoon_get_p_TIME);
    registerGetter(L, "lastActiveZone", ActivePlatoon_get_lastActiveZone);
    registerGetter(L, "_myMemory", ActivePlatoon_get__myMemory);
    registerGetter(L, "squadleader", ActivePlatoon_get_squadleader);
    registerGetter(L, "backupLeader", ActivePlatoon_get_backupLeader);
    registerGetter(L, "deactivationTimer", ActivePlatoon_get_deactivationTimer);
    registerGetter(L, "workingPos", ActivePlatoon_get_workingPos);
    registerGetter(L, "currentGoal", ActivePlatoon_get_currentGoal);
    registerGetter(L, "positionMoved", ActivePlatoon_get_positionMoved);
    registerGetter(L, "teleportTo", ActivePlatoon_get_teleportTo);
    registerGetter(L, "teleportMessage", ActivePlatoon_get_teleportMessage);
    registerGetter(L, "isPlayer", ActivePlatoon_get_isPlayer);
    registerGetter(L, "isPhysical", ActivePlatoon_get_isPhysical);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "isAnimalsOnly", ActivePlatoon_set_isAnimalsOnly);
    registerSetter(L, "me", ActivePlatoon_set_me);
    registerSetter(L, "p_TIME", ActivePlatoon_set_p_TIME);
    registerSetter(L, "lastActiveZone", ActivePlatoon_set_lastActiveZone);
    registerSetter(L, "squadleader", ActivePlatoon_set_squadleader);
    registerSetter(L, "backupLeader", ActivePlatoon_set_backupLeader);
    registerSetter(L, "deactivationTimer", ActivePlatoon_set_deactivationTimer);
    registerSetter(L, "workingPos", ActivePlatoon_set_workingPos);
    registerSetter(L, "currentGoal", ActivePlatoon_set_currentGoal);
    registerSetter(L, "positionMoved", ActivePlatoon_set_positionMoved);
    registerSetter(L, "teleportTo", ActivePlatoon_set_teleportTo);
    registerSetter(L, "teleportMessage", ActivePlatoon_set_teleportMessage);
    registerSetter(L, "isPlayer", ActivePlatoon_set_isPlayer);
    registerSetter(L, "isPhysical", ActivePlatoon_set_isPhysical);
    registerSetter(L, "_groupSense", ActivePlatoon_set__groupSense);
    registerSetter(L, "_myMemory", ActivePlatoon_set__myMemory);
    registerSetter(L, "characterHandles", ActivePlatoon_set_characterHandles);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to RootObjectContainer
    setMetatableParent(L, ActivePlatoonBinding::getMetatableName(), RootObjectContainerBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua