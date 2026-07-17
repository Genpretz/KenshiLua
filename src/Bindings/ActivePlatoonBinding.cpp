#include "pch.h"
#include "kenshi\Platoon.h"
#include "ActivePlatoonBinding.h"
#include "kenshi/PlayerInterface.h"
#include "PlayerInterfaceBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/PlayerInterfaceBinding.h"
#include "TaskerBinding.h"
#include "RootObjectBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "FactoryCallbackInterfaceBinding.h"
#include "Templates/LektorBinding.h"

namespace KenshiLua
{

static ActivePlatoon* getB(lua_State* L, int idx)
{
    return checkObject<ActivePlatoon>(L, idx, ActivePlatoonBinding::getMetatableName());
}

// --- Getters for ActivePlatoon ---
static int ActivePlatoon_get__groupSense(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    // TODO: Unsupported type for _groupSense (GroupSense*)
    return luaL_error(L, "Unsupported property '_groupSense' (type: GroupSense*)");
}

static int ActivePlatoon_get_isAnimalsOnly(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    lua_pushboolean(L, b->isAnimalsOnly ? 1 : 0);
    return 1;
}

static int ActivePlatoon_get_me(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    return pushObject<Platoon>(L, b->me, PlatoonBinding::getMetatableName());
}

static int ActivePlatoon_get_characterHandles(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    // TODO: Unsupported type for characterHandles (HandleList*)
    return luaL_error(L, "Unsupported property 'characterHandles' (type: HandleList*)");
}

static int ActivePlatoon_get_p_TIME(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    lua_pushnumber(L, b->p_TIME);
    return 1;
}

static int ActivePlatoon_get_lastActiveZone(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    // TODO: Unsupported type for lastActiveZone (ZoneMap*)
    return luaL_error(L, "Unsupported property 'lastActiveZone' (type: ZoneMap*)");
}

static int ActivePlatoon_get__myMemory(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    // TODO: Unsupported type for _myMemory (CharacterMemory*)
    return luaL_error(L, "Unsupported property '_myMemory' (type: CharacterMemory*)");
}

static int ActivePlatoon_get_squadleader(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    return pushObject<Character>(L, b->squadleader, CharacterBinding::getMetatableName());
}

static int ActivePlatoon_get_backupLeader(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    return pushObject<Character>(L, b->backupLeader, CharacterBinding::getMetatableName());
}

static int ActivePlatoon_get_deactivationTimer(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    lua_pushnumber(L, b->deactivationTimer);
    return 1;
}

static int ActivePlatoon_get_workingPos(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    pushVector3(L, b->workingPos);
    return 1;
}

static int ActivePlatoon_get_currentGoal(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    return pushObject<Tasker>(L, b->currentGoal, TaskerBinding::getMetatableName());
}

static int ActivePlatoon_get_positionMoved(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    pushVector3(L, b->positionMoved);
    return 1;
}

static int ActivePlatoon_get_teleportTo(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    pushVector3(L, b->teleportTo);
    return 1;
}

static int ActivePlatoon_get_teleportMessage(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    lua_pushboolean(L, b->teleportMessage ? 1 : 0);
    return 1;
}

static int ActivePlatoon_get_isPlayer(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    return pushObject<PlayerInterface>(L, b->isPlayer, PlayerInterfaceBinding::getMetatableName());
}

static int ActivePlatoon_get_isPhysical(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    lua_pushboolean(L, b->isPhysical ? 1 : 0);
    return 1;
}

// --- Setters for ActivePlatoon ---
static int ActivePlatoon_set__groupSense(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _groupSense");
}

static int ActivePlatoon_set_isAnimalsOnly(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    b->isAnimalsOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ActivePlatoon_set_me(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for me");
}

static int ActivePlatoon_set_characterHandles(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for characterHandles");
}

static int ActivePlatoon_set_p_TIME(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    b->p_TIME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ActivePlatoon_set_lastActiveZone(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for lastActiveZone");
}

static int ActivePlatoon_set__myMemory(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _myMemory");
}

static int ActivePlatoon_set_squadleader(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for squadleader");
}

static int ActivePlatoon_set_backupLeader(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for backupLeader");
}

static int ActivePlatoon_set_deactivationTimer(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    b->deactivationTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ActivePlatoon_set_workingPos(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    readVector3(L, 2, b->workingPos);
    return 0;
}

static int ActivePlatoon_set_currentGoal(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    if (lua_isnil(L, 2)) {
        b->currentGoal = nullptr;
    } else {
        b->currentGoal = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    }
    return 0;
}

static int ActivePlatoon_set_positionMoved(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    readVector3(L, 2, b->positionMoved);
    return 0;
}

static int ActivePlatoon_set_teleportTo(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    readVector3(L, 2, b->teleportTo);
    return 0;
}

static int ActivePlatoon_set_teleportMessage(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    b->teleportMessage = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ActivePlatoon_set_isPlayer(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isPlayer");
}

static int ActivePlatoon_set_isPhysical(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    b->isPhysical = lua_toboolean(L, 2) != 0;
    return 0;
}

// --- Methods for ActivePlatoon ---
int ActivePlatoonBinding::_recalculateIsIntact(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool result = b->_recalculateIsIntact();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::isAnyoneCaptured(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool result = b->isAnyoneCaptured();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::_DESTRUCTOR(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    b->_DESTRUCTOR();
    return 0;
}

int ActivePlatoonBinding::swapCharacters(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    int indexA = (int)luaL_checkinteger(L, 2);
    int indexB = (int)luaL_checkinteger(L, 3);
    b->swapCharacters(indexA, indexB);
    return 0;
}

int ActivePlatoonBinding::emptySquadCheck(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    b->emptySquadCheck();
    return 0;
}

int ActivePlatoonBinding::clearAllTheUniqueNPCStates(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    b->clearAllTheUniqueNPCStates();
    return 0;
}

int ActivePlatoonBinding::isIntact(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool result = b->isIntact();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::getSquadLeader_theRealOne(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    Character* result = b->getSquadLeader_theRealOne();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int ActivePlatoonBinding::getNearestActiveCharacter(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    int floor = (int)luaL_checkinteger(L, 3);
    Character* result = b->getNearestActiveCharacter(p, floor);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int ActivePlatoonBinding::getSquadLeader(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    Character* result = b->getSquadLeader();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int ActivePlatoonBinding::getSquadSize(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    int result = b->getSquadSize();
    lua_pushinteger(L, result);
    return 1;
}

int ActivePlatoonBinding::update(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool result = b->update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::_NV_update(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool result = b->_NV_update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::refreshInventory(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool firstTime = lua_toboolean(L, 2) != 0;
    b->refreshInventory(firstTime);
    return 0;
}

int ActivePlatoonBinding::_forceRefreshInventory(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    b->_forceRefreshInventory();
    return 0;
}

int ActivePlatoonBinding::periodicUpdate(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool result = b->periodicUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::_NV_periodicUpdate(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool result = b->_NV_periodicUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::serialiseEverythingToDisk(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool levelEditor = lua_toboolean(L, 2) != 0;
    b->serialiseEverythingToDisk(levelEditor);
    return 0;
}

int ActivePlatoonBinding::isWholeSquadDown(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    int minusThis = (int)luaL_checkinteger(L, 2);
    bool result = b->isWholeSquadDown(minusThis);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::setDataFilename(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    std::string f = luaL_checkstring(L, 2);
    b->setDataFilename(f);
    return 0;
}

int ActivePlatoonBinding::setupLeaderDialogues(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    b->setupLeaderDialogues();
    return 0;
}

int ActivePlatoonBinding::isLoaded(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool result = b->isLoaded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::teleport(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    b->teleport(pos);
    return 0;
}

int ActivePlatoonBinding::setName(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    std::string name = luaL_checkstring(L, 2);
    b->setName(name);
    return 0;
}

int ActivePlatoonBinding::getIsTrader(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool result = b->getIsTrader();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::getHasVendorList(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool result = b->getHasVendorList();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::getHasSpecialItemsList(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool result = b->getHasSpecialItemsList();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::setupTraderBuildings(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    b->setupTraderBuildings();
    return 0;
}

int ActivePlatoonBinding::putTheSpecialCharactersInNewSquads_captured(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    b->putTheSpecialCharactersInNewSquads_captured();
    return 0;
}

int ActivePlatoonBinding::checkForCharactersBeingCarried(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool result = b->checkForCharactersBeingCarried();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::restoreSquad(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    b->restoreSquad();
    return 0;
}

int ActivePlatoonBinding::unloadCheck(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool result = b->unloadCheck();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ActivePlatoonBinding::destroyCharacters(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool justUnload = lua_toboolean(L, 2) != 0;
    b->destroyCharacters(justUnload);
    return 0;
}

int ActivePlatoonBinding::serialiseCharacterData(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    b->serialiseCharacterData();
    return 0;
}

int ActivePlatoonBinding::saveToDisk(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    bool levelEditor = lua_toboolean(L, 2) != 0;
    std::string force = luaL_checkstring(L, 3);
    b->saveToDisk(levelEditor, force);
    return 0;
}

int ActivePlatoonBinding::calculateCurrentPos(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    Ogre::Vector3 result = b->calculateCurrentPos();
    pushVector3(L, result);
    return 1;
}

int ActivePlatoonBinding::_checkForUniqueCharactersOnUnload(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    b->_checkForUniqueCharactersOnUnload();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 275: ActivePlatoon* _CONSTRUCTOR(...) - unsupported return type
*/
static int ActivePlatoon_removeObject(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = b->removeObject(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

static int ActivePlatoon__NV_removeObject(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = b->_NV_removeObject(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

static int ActivePlatoon_addActiveObject(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = b->addActiveObject(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

static int ActivePlatoon__NV_addActiveObject(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = b->_NV_addActiveObject(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

static int ActivePlatoon_addCharacterAt(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    int index = (int)luaL_checkinteger(L, 3);
    b->addCharacterAt(c, index);
    return 0;
}

static int ActivePlatoon_setSquadLeader(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    b->setSquadLeader(who);
    return 0;
}

static int ActivePlatoon_getName(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    const std::string& result = b->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

static int ActivePlatoon_loadFromDisk(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    bool force = lua_toboolean(L, 2) != 0;
    Serialisable* extra = nullptr;
    if (!lua_isnil(L, 3)) {
        extra = (Serialisable*)lua_touserdata(L, 3);
        if (!extra) return luaL_error(L, "Argument 3 must be lightuserdata (Serialisable*) or nil");
    }
    bool result = b->loadFromDisk(force, extra);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

static int ActivePlatoon__NV_loadFromDisk(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    bool force = lua_toboolean(L, 2) != 0;
    Serialisable* extra = nullptr;
    if (!lua_isnil(L, 3)) {
        extra = (Serialisable*)lua_touserdata(L, 3);
        if (!extra) return luaL_error(L, "Argument 3 must be lightuserdata (Serialisable*) or nil");
    }
    bool result = b->_NV_loadFromDisk(force, extra);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

static int ActivePlatoon_getGroupSense(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    GroupSense* gs = b->getGroupSense();
    if (gs) {
        lua_pushlightuserdata(L, (void*)gs);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int ActivePlatoon_getMemory(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    CharacterMemory* cm = b->getMemory();
    if (cm) {
        lua_pushlightuserdata(L, (void*)cm);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int ActivePlatoon_getCharactersInArea(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 must be a lektor<RootObject*>");

    Ogre::Vector3 pos;
    readVector3(L, 3, pos);

    float radius = (float)luaL_checknumber(L, 4);
    bool standingOnly = lua_toboolean(L, 5) != 0;

    b->getCharactersInArea(*out, pos, radius, standingOnly);
    return 0;
}

static int ActivePlatoon_setupCheck(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");
    YesNoMaybe result = b->setupCheck();
    lua_pushinteger(L, static_cast<int>(result.key));
    return 1;
}

static int ActivePlatoon_loadCharacters(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);

    FactoryCallbackInterface* callback = nullptr;
    if (!lua_isnil(L, 3)) {
        callback = checkObject<FactoryCallbackInterface>(L, 3, FactoryCallbackInterfaceBinding::getMetatableName());
    }

    b->loadCharacters(pos, callback);
    return 0;
}

static int ActivePlatoon__NV_loadCharacters(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);

    FactoryCallbackInterface* callback = nullptr;
    if (!lua_isnil(L, 3)) {
        callback = checkObject<FactoryCallbackInterface>(L, 3, FactoryCallbackInterfaceBinding::getMetatableName());
    }

    b->_NV_loadCharacters(pos, callback);
    return 0;
}

static int ActivePlatoon_loadInstance(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

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

    b->loadInstance(*state, skipSaveState, pos, rot, callback, positionMoved);
    return 0;
}

static int ActivePlatoon__NV_loadInstance(lua_State* L)
{
    ActivePlatoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "ActivePlatoon is nil");

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

    b->_NV_loadInstance(*state, skipSaveState, pos, rot, callback, positionMoved);
    return 0;
}



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
        { "swapCharacters", ActivePlatoonBinding::swapCharacters },
        { "emptySquadCheck", ActivePlatoonBinding::emptySquadCheck },
        { "clearAllTheUniqueNPCStates", ActivePlatoonBinding::clearAllTheUniqueNPCStates },
        { "isIntact", ActivePlatoonBinding::isIntact },
        { "getSquadLeader_theRealOne", ActivePlatoonBinding::getSquadLeader_theRealOne },
        { "getNearestActiveCharacter", ActivePlatoonBinding::getNearestActiveCharacter },
        { "getSquadLeader", ActivePlatoonBinding::getSquadLeader },
        { "getSquadSize", ActivePlatoonBinding::getSquadSize },
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
        { "unloadCheck", ActivePlatoonBinding::unloadCheck },
        { "destroyCharacters", ActivePlatoonBinding::destroyCharacters },
        { "serialiseCharacterData", ActivePlatoonBinding::serialiseCharacterData },
        { "saveToDisk", ActivePlatoonBinding::saveToDisk },
        { "calculateCurrentPos", ActivePlatoonBinding::calculateCurrentPos },
        { "_checkForUniqueCharactersOnUnload", ActivePlatoonBinding::_checkForUniqueCharactersOnUnload },
        { "removeObject", ActivePlatoon_removeObject },
        { "_NV_removeObject", ActivePlatoon__NV_removeObject },
        { "addActiveObject", ActivePlatoon_addActiveObject },
        { "_NV_addActiveObject", ActivePlatoon__NV_addActiveObject },
        { "addCharacterAt", ActivePlatoon_addCharacterAt },
        { "setSquadLeader", ActivePlatoon_setSquadLeader },
        { "getName", ActivePlatoon_getName },
        { "loadFromDisk", ActivePlatoon_loadFromDisk },
        { "_NV_loadFromDisk", ActivePlatoon__NV_loadFromDisk },
        { "getGroupSense", ActivePlatoon_getGroupSense },
        { "getMemory", ActivePlatoon_getMemory },
        { "getCharactersInArea", ActivePlatoon_getCharactersInArea },
        { "setupCheck", ActivePlatoon_setupCheck },
        { "loadCharacters", ActivePlatoon_loadCharacters },
        { "_NV_loadCharacters", ActivePlatoon__NV_loadCharacters },
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
    lua_pushcfunction(L, ActivePlatoon_get__groupSense);
    lua_setfield(L, -2, "_groupSense");
    lua_pushcfunction(L, ActivePlatoon_get_isAnimalsOnly);
    lua_setfield(L, -2, "isAnimalsOnly");
    lua_pushcfunction(L, ActivePlatoon_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, ActivePlatoon_get_characterHandles);
    lua_setfield(L, -2, "characterHandles");
    lua_pushcfunction(L, ActivePlatoon_get_p_TIME);
    lua_setfield(L, -2, "p_TIME");
    lua_pushcfunction(L, ActivePlatoon_get_lastActiveZone);
    lua_setfield(L, -2, "lastActiveZone");
    lua_pushcfunction(L, ActivePlatoon_get__myMemory);
    lua_setfield(L, -2, "_myMemory");
    lua_pushcfunction(L, ActivePlatoon_get_squadleader);
    lua_setfield(L, -2, "squadleader");
    lua_pushcfunction(L, ActivePlatoon_get_backupLeader);
    lua_setfield(L, -2, "backupLeader");
    lua_pushcfunction(L, ActivePlatoon_get_deactivationTimer);
    lua_setfield(L, -2, "deactivationTimer");
    lua_pushcfunction(L, ActivePlatoon_get_workingPos);
    lua_setfield(L, -2, "workingPos");
    lua_pushcfunction(L, ActivePlatoon_get_currentGoal);
    lua_setfield(L, -2, "currentGoal");
    lua_pushcfunction(L, ActivePlatoon_get_positionMoved);
    lua_setfield(L, -2, "positionMoved");
    lua_pushcfunction(L, ActivePlatoon_get_teleportTo);
    lua_setfield(L, -2, "teleportTo");
    lua_pushcfunction(L, ActivePlatoon_get_teleportMessage);
    lua_setfield(L, -2, "teleportMessage");
    lua_pushcfunction(L, ActivePlatoon_get_isPlayer);
    lua_setfield(L, -2, "isPlayer");
    lua_pushcfunction(L, ActivePlatoon_get_isPhysical);
    lua_setfield(L, -2, "isPhysical");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ActivePlatoon_set__groupSense);
    lua_setfield(L, -2, "_groupSense");
    lua_pushcfunction(L, ActivePlatoon_set_isAnimalsOnly);
    lua_setfield(L, -2, "isAnimalsOnly");
    lua_pushcfunction(L, ActivePlatoon_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, ActivePlatoon_set_characterHandles);
    lua_setfield(L, -2, "characterHandles");
    lua_pushcfunction(L, ActivePlatoon_set_p_TIME);
    lua_setfield(L, -2, "p_TIME");
    lua_pushcfunction(L, ActivePlatoon_set_lastActiveZone);
    lua_setfield(L, -2, "lastActiveZone");
    lua_pushcfunction(L, ActivePlatoon_set__myMemory);
    lua_setfield(L, -2, "_myMemory");
    lua_pushcfunction(L, ActivePlatoon_set_squadleader);
    lua_setfield(L, -2, "squadleader");
    lua_pushcfunction(L, ActivePlatoon_set_backupLeader);
    lua_setfield(L, -2, "backupLeader");
    lua_pushcfunction(L, ActivePlatoon_set_deactivationTimer);
    lua_setfield(L, -2, "deactivationTimer");
    lua_pushcfunction(L, ActivePlatoon_set_workingPos);
    lua_setfield(L, -2, "workingPos");
    lua_pushcfunction(L, ActivePlatoon_set_currentGoal);
    lua_setfield(L, -2, "currentGoal");
    lua_pushcfunction(L, ActivePlatoon_set_positionMoved);
    lua_setfield(L, -2, "positionMoved");
    lua_pushcfunction(L, ActivePlatoon_set_teleportTo);
    lua_setfield(L, -2, "teleportTo");
    lua_pushcfunction(L, ActivePlatoon_set_teleportMessage);
    lua_setfield(L, -2, "teleportMessage");
    lua_pushcfunction(L, ActivePlatoon_set_isPlayer);
    lua_setfield(L, -2, "isPlayer");
    lua_pushcfunction(L, ActivePlatoon_set_isPhysical);
    lua_setfield(L, -2, "isPhysical");
    lua_setfield(L, -2, "__setters"); // Bind to metatable
    
    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua