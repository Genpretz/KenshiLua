#include "pch.h"
#include "kenshi\GameWorld.h"
#include "GameWorldBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionManagerBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataManagerBinding.h"
#include "Bindings/ModInfoBinding.h"
#include "Bindings/NavMeshBinding.h"
#include "Bindings/PhysicsInterfaceBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/PlayerInterfaceBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/RootObjectFactoryBinding.h"
#include "Bindings/SimpleTimeStamperBinding.h"
#include "Bindings/SysMessageBinding.h"
#include "Bindings/ThreadWannabeBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
#include "Bindings/TownBuildingsManagerBinding.h"
#include "Bindings/ZoneManagerBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Bindings/Util/StdMapBinding.h"
#include "Bindings/Util/StdDequeBinding.h"

namespace KenshiLua
{
typedef StdDequePtrBinding<RootObject*, Ogre::STLAllocator<RootObject*, Ogre::GeneralAllocPolicy>> KillListPhase2DequeBinding;
typedef StdDequePtrBinding<NestBatcher*, Ogre::STLAllocator<NestBatcher*, Ogre::GeneralAllocPolicy>> NestBatcherKillListDequeBinding;


static GameWorld* getInstance(lua_State* L, int idx)
{
    return checkObject<GameWorld>(L, idx, GameWorldBinding::getMetatableName());
}

// --- Getters for GameWorld ---
static int GameWorld_get_tempSpawnsDisableTimer(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushnumber(L, instance->tempSpawnsDisableTimer);
    return 1;
}

static int GameWorld_get_initialized(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushboolean(L, instance->initialized ? 1 : 0);
    return 1;
}

static int GameWorld_get_render(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushlightuserdata(L, (void*)instance->render);
    return 1;
}

static int GameWorld_get_physics(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<PhysicsInterface>(L, instance->physics, PhysicsInterfaceBinding::getMetatableName());
}

static int GameWorld_get_gamedata(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<GameDataManager>(L, &instance->gamedata, GameDataManagerBinding::getMetatableName());
}

static int GameWorld_get_leveldata(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<GameDataManager>(L, &instance->leveldata, GameDataManagerBinding::getMetatableName());
}

static int GameWorld_get_savedata(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<GameDataManager>(L, &instance->savedata, GameDataManagerBinding::getMetatableName());
}

static int GameWorld_get_theFactory(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<RootObjectFactory>(L, instance->theFactory, RootObjectFactoryBinding::getMetatableName());
}

static int GameWorld_get_factionMgr(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<FactionManager>(L, instance->factionMgr, FactionManagerBinding::getMetatableName());
}

static int GameWorld_get_navmesh(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<NavMesh>(L, instance->navmesh, NavMeshBinding::getMetatableName());
}

static int GameWorld_get_nodeList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushlightuserdata(L, (void*)instance->nodeList);
    return 1;
}

static int GameWorld_get_guiDisplayObject(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return HandBinding::push(L, instance->guiDisplayObject);
}

static int GameWorld_get_messageRoller(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushlightuserdata(L, (void*)instance->messageRoller);
    return 1;
}

static int GameWorld_get_ogreLogger(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushlightuserdata(L, (void*)instance->ogreLogger);
    return 1;
}

static int GameWorld_get_steamEnabled(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushboolean(L, instance->steamEnabled ? 1 : 0);
    return 1;
}

static int GameWorld_get_player(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<PlayerInterface>(L, instance->player, PlayerInterfaceBinding::getMetatableName());
}

static int GameWorld_get_frameSpeedMult(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushnumber(L, instance->frameSpeedMult);
    return 1;
}

static int GameWorld_get_deathParadeWasMeddledWith(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushboolean(L, instance->deathParadeWasMeddledWith ? 1 : 0);
    return 1;
}

static int GameWorld_get_charUpdateListMain_inUse(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushboolean(L, instance->charUpdateListMain_inUse ? 1 : 0);
    return 1;
}

static int GameWorld_get__AINonRenderThread(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushlightuserdata(L, (void*)instance->_AINonRenderThread);
    return 1;
}

static int GameWorld_get_timeStamper(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<SimpleTimeStamper>(L, &instance->timeStamper, SimpleTimeStamperBinding::getMetatableName());
}

static int GameWorld_get_zoneMgr(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<ZoneManager>(L, instance->zoneMgr, ZoneManagerBinding::getMetatableName());
}

static int GameWorld_get_debugFlag(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushboolean(L, instance->debugFlag ? 1 : 0);
    return 1;
}

static int GameWorld_get_paused(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushboolean(L, instance->paused ? 1 : 0);
    return 1;
}

static int GameWorld_get_gameResetting(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushboolean(L, instance->gameResetting ? 1 : 0);
    return 1;
}

static int GameWorld_get_audioThread(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    lua_pushlightuserdata(L, (void*)instance->audioThread);
    return 1;
}

// --- Setters for GameWorld ---
static int GameWorld_set_tempSpawnsDisableTimer(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->tempSpawnsDisableTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameWorld_set_initialized(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->initialized = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameWorld_set_physics(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->physics = lua_isnoneornil(L, 2) ? nullptr : checkObject<PhysicsInterface>(L, 2, PhysicsInterfaceBinding::getMetatableName());
    return 0;
}

static int GameWorld_set_gamedata(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->gamedata = *checkObject<GameDataManager>(L, 2, GameDataManagerBinding::getMetatableName());
    return 0;
}

static int GameWorld_set_leveldata(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->leveldata = *checkObject<GameDataManager>(L, 2, GameDataManagerBinding::getMetatableName());
    return 0;
}

static int GameWorld_set_savedata(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->savedata = *checkObject<GameDataManager>(L, 2, GameDataManagerBinding::getMetatableName());
    return 0;
}

static int GameWorld_set_theFactory(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->theFactory = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObjectFactory>(L, 2, RootObjectFactoryBinding::getMetatableName());
    return 0;
}

static int GameWorld_set_factionMgr(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->factionMgr = lua_isnoneornil(L, 2) ? nullptr : checkObject<FactionManager>(L, 2, FactionManagerBinding::getMetatableName());
    return 0;
}

static int GameWorld_set_navmesh(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->navmesh = lua_isnoneornil(L, 2) ? nullptr : checkObject<NavMesh>(L, 2, NavMeshBinding::getMetatableName());
    return 0;
}

static int GameWorld_set_guiDisplayObject(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->guiDisplayObject = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int GameWorld_set_steamEnabled(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->steamEnabled = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameWorld_set_player(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->player = lua_isnoneornil(L, 2) ? nullptr : checkObject<PlayerInterface>(L, 2, PlayerInterfaceBinding::getMetatableName());
    return 0;
}

static int GameWorld_set_frameSpeedMult(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->frameSpeedMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameWorld_set_deathParadeWasMeddledWith(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->deathParadeWasMeddledWith = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameWorld_set_charUpdateListMain_inUse(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->charUpdateListMain_inUse = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameWorld_set_timeStamper(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->timeStamper = *checkObject<SimpleTimeStamper>(L, 2, SimpleTimeStamperBinding::getMetatableName());
    return 0;
}

static int GameWorld_set_zoneMgr(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->zoneMgr = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneManager>(L, 2, ZoneManagerBinding::getMetatableName());
    return 0;
}

static int GameWorld_set_debugFlag(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->debugFlag = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameWorld_set_paused(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->paused = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameWorld_set_gameResetting(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->gameResetting = lua_toboolean(L, 2) != 0;
    return 0;
}

int GameWorldBinding::justLoadFactionRelations(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    GameDataManager* datasrc = checkObject<GameDataManager>(L, 2, GameDataManagerBinding::getMetatableName());
    instance->justLoadFactionRelations(datasrc);
    return 0;
}

int GameWorldBinding::startUpThreads(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    bool result = instance->startUpThreads();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::_CONSTRUCTOR(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    GameWorld* result = instance->_CONSTRUCTOR();
    return pushObject<GameWorld>(L, result, GameWorldBinding::getMetatableName());
}

int GameWorldBinding::_DESTRUCTOR(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int GameWorldBinding::resetGame(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->resetGame();
    return 0;
}

int GameWorldBinding::_clearAndDestroyGameWorldStuff(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->_clearAndDestroyGameWorldStuff();
    return 0;
}

int GameWorldBinding::initialisation(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    bool result = instance->initialisation();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::initialisationGameData(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    bool result = instance->initialisationGameData();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::dailyUpdates(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->dailyUpdates();
    return 0;
}

int GameWorldBinding::initialiseNewGameWorld(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    GameDataManager* datasrc = checkObject<GameDataManager>(L, 2, GameDataManagerBinding::getMetatableName());
    instance->initialiseNewGameWorld(datasrc);
    return 0;
}

int GameWorldBinding::errorToLogReleaseMode(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    const std::string msg = luaL_checkstring(L, 2);
    instance->errorToLogReleaseMode(msg);
    return 0;
}

int GameWorldBinding::errorD(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    const std::string msg = luaL_checkstring(L, 2);
    instance->errorD(msg);
    return 0;
}

int GameWorldBinding::logToSave(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    const std::string msg = luaL_checkstring(L, 2);
    instance->logToSave(msg);
    return 0;
}

int GameWorldBinding::log(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    const std::string line = luaL_checkstring(L, 2);
    instance->log(line);
    return 0;
}

int GameWorldBinding::getIsInKillList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->getIsInKillList(obj);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::flushKillList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->flushKillList();
    return 0;
}

int GameWorldBinding::allThreadQueuesAreClear(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    bool result = instance->allThreadQueuesAreClear();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::initBaseMods(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->initBaseMods();
    return 0;
}

int GameWorldBinding::initModsList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->initModsList();
    return 0;
}

int GameWorldBinding::getModIndex(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    const std::string modName = luaL_checkstring(L, 2);
    int result = instance->getModIndex(modName);
    lua_pushinteger(L, result);
    return 1;
}

int GameWorldBinding::buildingIntersectionTestCapsule(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    float radius = (float)luaL_checknumber(L, 3);
    float length = (float)luaL_checknumber(L, 4);
    RootObject* skip = checkObject<RootObject>(L, 5, RootObjectBinding::getMetatableName());
    bool result = instance->buildingIntersectionTestCapsule(pos, radius, length, skip);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::getLightLevel(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    int floor = (int)luaL_checkinteger(L, 3);
    bool inside = lua_toboolean(L, 4) != 0;
    float result = instance->getLightLevel(position, floor, inside);
    lua_pushnumber(L, result);
    return 1;
}

int GameWorldBinding::populateMapArea_nonPermanent(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    ZoneMap* map = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    int howMany = (int)luaL_checkinteger(L, 3);
    bool rePopulationMode = lua_toboolean(L, 4) != 0;
    instance->populateMapArea_nonPermanent(map, howMany, rePopulationMode);
    return 0;
}

int GameWorldBinding::findValidSpawnPos(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Ogre::Vector3 centerArea;
    readVector3(L, 3, centerArea);
    bool result = instance->findValidSpawnPos(pos, centerArea);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::togglePause(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->togglePause(on);
    return 0;
}

int GameWorldBinding::getFrameSpeedMultiplier(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    float result = instance->getFrameSpeedMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int GameWorldBinding::setFrameSpeedMultiplier(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    float m = (float)luaL_checknumber(L, 2);
    instance->setFrameSpeedMultiplier(m);
    return 0;
}

int GameWorldBinding::setGameSpeed(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    float speed = (float)luaL_checknumber(L, 2);
    bool click = lua_toboolean(L, 3) != 0;
    instance->setGameSpeed(speed, click);
    return 0;
}

int GameWorldBinding::userPause(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    bool p = lua_toboolean(L, 2) != 0;
    instance->userPause(p);
    return 0;
}

int GameWorldBinding::isPaused(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    bool result = instance->isPaused();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::getCameraCenter(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    const Ogre::Vector3 result = instance->getCameraCenter();
    pushVector3(L, result);
    return 1;
}

int GameWorldBinding::getCameraPos(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    const Ogre::Vector3 result = instance->getCameraPos();
    pushVector3(L, result);
    return 1;
}

int GameWorldBinding::fixNaNPosition(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    bool result = instance->fixNaNPosition(pos);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::getWindSpeed(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    float result = instance->getWindSpeed(pos);
    lua_pushnumber(L, result);
    return 1;
}

int GameWorldBinding::isLoadingFromASaveGame(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    bool result = instance->isLoadingFromASaveGame();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::addToUpdateListMain(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->addToUpdateListMain(character);
    return 0;
}

int GameWorldBinding::removeFromUpdateListMain(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->removeFromUpdateListMain(character);
    return 0;
}

int GameWorldBinding::addToDeathParade(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->addToDeathParade(who);
    return 0;
}

int GameWorldBinding::removeFromDeathParade(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->removeFromDeathParade(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::removeFromDeathParadeByPlatoon(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    Platoon* p = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->removeFromDeathParadeByPlatoon(p);
    return 0;
}

int GameWorldBinding::hideContextMenu(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->hideContextMenu();
    return 0;
}

int GameWorldBinding::showPlayerAMessage_withLog(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    const std::string message = luaL_checkstring(L, 2);
    bool queued = lua_toboolean(L, 3) != 0;
    instance->showPlayerAMessage_withLog(message, queued);
    return 0;
}

int GameWorldBinding::showPlayerAMessage(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    const std::string message = luaL_checkstring(L, 2);
    bool queued = lua_toboolean(L, 3) != 0;
    instance->showPlayerAMessage(message, queued);
    return 0;
}

int GameWorldBinding::showPlayerAMessageD(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    const std::string message = luaL_checkstring(L, 2);
    bool queued = lua_toboolean(L, 3) != 0;
    instance->showPlayerAMessageD(message, queued);
    return 0;
}

int GameWorldBinding::playNotification(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    const char* sound = luaL_checkstring(L, 2);
    instance->playNotification(sound);
    return 0;
}

int GameWorldBinding::mainLoop_GPUSensitiveStuff(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->mainLoop_GPUSensitiveStuff(time);
    return 0;
}

int GameWorldBinding::_NV_mainLoop_GPUSensitiveStuff(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->_NV_mainLoop_GPUSensitiveStuff(time);
    return 0;
}

int GameWorldBinding::clearPortaitsUpdate(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->clearPortaitsUpdate();
    return 0;
}

int GameWorldBinding::processSysMessages(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->processSysMessages();
    return 0;
}

int GameWorldBinding::destroyDeathParade(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->destroyDeathParade();
    return 0;
}

int GameWorldBinding::processKeys(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->processKeys();
    return 0;
}

int GameWorldBinding::processThreadMessages(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->processThreadMessages();
    return 0;
}

int GameWorldBinding::charsUpdate(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->charsUpdate();
    return 0;
}

int GameWorldBinding::charsUpdateUT(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->charsUpdateUT();
    return 0;
}

int GameWorldBinding::charsUpdatePaused(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->charsUpdatePaused();
    return 0;
}

int GameWorldBinding::charsUpdateDeathParade(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->charsUpdateDeathParade();
    return 0;
}

int GameWorldBinding::threadSafeRagdollUpdates(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->threadSafeRagdollUpdates();
    return 0;
}

int GameWorldBinding::AINonRenderThread(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    ThreadWannabe* result = instance->AINonRenderThread();
    return pushObject<ThreadWannabe>(L, result, ThreadWannabeBinding::getMetatableName());
}

int GameWorldBinding::processAttachmentsKillList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->processAttachmentsKillList();
    return 0;
}

int GameWorldBinding::processKillList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    bool forceImmediate = lua_toboolean(L, 2) != 0;
    instance->processKillList(forceImmediate);
    return 0;
}

int GameWorldBinding::processUpdateRemovalList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->processUpdateRemovalList();
    return 0;
}

int GameWorldBinding::loadAllPlatoons(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->loadAllPlatoons();
    return 0;
}

int GameWorldBinding::reCalculateFortificationInsideOutsideStateForAllCharacters(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    instance->reCalculateFortificationInsideOutsideStateForAllCharacters();
    return 0;
}

int GameWorldBinding::getTimeStamp(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    double result = instance->getTimeStamp();
    lua_pushnumber(L, result);
    return 1;
}

int GameWorldBinding::getTimeFromStamp_inGameHours(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    double stamp = (double)luaL_checknumber(L, 2);
    float result = instance->getTimeFromStamp_inGameHours(stamp);
    lua_pushnumber(L, result);
    return 1;
}

int GameWorldBinding::getTimeStamp_inGameHours(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    TimeOfDay result = instance->getTimeStamp_inGameHours();
    return pushValue<TimeOfDay>(L, result, TimeOfDayBinding::getMetatableName());
}

int GameWorldBinding::getLengthOfHourInRealSeconds(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    float result = instance->getLengthOfHourInRealSeconds();
    lua_pushnumber(L, result);
    return 1;
}

int GameWorldBinding::logDebug(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    std::string line = luaL_checkstring(L, 2);
    if (lua_gettop(L) >= 3)
    {
        std::string logname = luaL_checkstring(L, 3);
        instance->logDebug(line, logname);
    }
    else
    {
        instance->logDebug(line);
    }
    return 0;
}

int GameWorldBinding::getTimeFromStamp(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    if (lua_isnumber(L, 2))
    {
        double stamp = (double)luaL_checknumber(L, 2);
        float result = instance->getTimeFromStamp(stamp);
        lua_pushnumber(L, result);
        return 1;
    }
    else
    {
        TimeOfDay* stamp = checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
        TimeOfDay result = instance->getTimeFromStamp(*stamp);
        return pushValue<TimeOfDay>(L, result, TimeOfDayBinding::getMetatableName());
    }
}

int GameWorldBinding::dynamicDestroyBuilding(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->dynamicDestroyBuilding(*h);
    return 0;
}

int GameWorldBinding::getFromDeathParade(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Character* result = instance->getFromDeathParade(*h);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int GameWorldBinding::addPortraitUpdate(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->addPortraitUpdate(*h);
    return 0;
}

int GameWorldBinding::removePortaitUpdate(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->removePortaitUpdate(*h);
    return 0;
}

int GameWorldBinding::start(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    RendererT* rend = (RendererT*)lua_touserdata(L, 2);
    bool result = instance->start(rend);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::destroy(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    if (lua_isnoneornil(L, 2))
        return luaL_error(L, "Argument 2 to destroy cannot be nil");

    if (RootObject* obj = testObject<RootObject>(L, 2, RootObjectBinding::getMetatableName()))
    {
        bool justUnloaded = lua_isboolean(L, 3) ? (lua_toboolean(L, 3) != 0) : false;
        const char* debugInfo = lua_isstring(L, 4) ? lua_tostring(L, 4) : nullptr;
        bool res = instance->destroy(obj, justUnloaded, debugInfo);
        lua_pushboolean(L, res ? 1 : 0);
        return 1;
    }
    else if (TownBuildingsManager* b = testObject<TownBuildingsManager>(L, 2, TownBuildingsManagerBinding::getMetatableName()))
    {
        instance->destroy(b);
        return 0;
    }
    else if (GameData* d = testObject<GameData>(L, 2, GameDataBinding::getMetatableName()))
    {
        instance->destroy(d);
        return 0;
    }
    else if (lua_isuserdata(L, 2))
    {
        void* ptr = lua_touserdata(L, 2);
        instance->destroy((Ogre::MovableObject*)ptr);
        return 0;
    }

    return luaL_error(L, "Argument 2 to destroy must be RootObject, TownBuildingsManager, GameData, or lightuserdata pointer");
}

int GameWorldBinding::getModsListFromConfig(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    static lektor<ModInfo*> list;
    list = instance->getModsListFromConfig();
    return pushObject<lektor<ModInfo*>>(L, &list, "lektor<ModInfo*>");
}

int GameWorldBinding::getAllModsList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    const lektor<ModInfo*>& mods = instance->getAllModsList();
    return pushObject<lektor<ModInfo*>>(L, (lektor<ModInfo*>*)&mods, "lektor<ModInfo*>");
}

int GameWorldBinding::getModLeveldataFolder(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    const std::string modName = luaL_checkstring(L, 2);
    const std::string& res = instance->getModLeveldataFolder(modName);
    lua_pushstring(L, res.c_str());
    return 1;
}

int GameWorldBinding::getObjectsWithinSphere(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    lektor<RootObject*>* results = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!results) return luaL_error(L, "Argument 2 to getObjectsWithinSphere must be lektor<RootObject*>");

    Ogre::Vector3 spherePos;
    readVector3(L, 3, spherePos);
    float radius = (float)luaL_checknumber(L, 4);
    itemType type = (itemType)luaL_checkinteger(L, 5);
    int maxNumber = (int)luaL_checkinteger(L, 6);
    RootObject* skip = lua_isnoneornil(L, 7) ? nullptr : checkObject<RootObject>(L, 7, RootObjectBinding::getMetatableName());

    instance->getObjectsWithinSphere(*results, spherePos, radius, type, maxNumber, skip);
    return 0;
}

int GameWorldBinding::getCharactersWithinSphere(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    lektor<RootObject*>* results = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!results) return luaL_error(L, "Argument 2 to getCharactersWithinSphere must be lektor<RootObject*>");

    Ogre::Vector3 spherePos;
    readVector3(L, 3, spherePos);
    float farRadius = (float)luaL_checknumber(L, 4);
    float nearRadius = (float)luaL_checknumber(L, 5);
    float always = (float)luaL_checknumber(L, 6);
    int maxFar = (int)luaL_checkinteger(L, 7);
    int maxNear = (int)luaL_checkinteger(L, 8);
    RootObject* skip = lua_isnoneornil(L, 9) ? nullptr : checkObject<RootObject>(L, 9, RootObjectBinding::getMetatableName());

    instance->getCharactersWithinSphere(*results, spherePos, farRadius, nearRadius, always, maxFar, maxNear, skip);
    return 0;
}

int GameWorldBinding::getObjectsWithinBox(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    lektor<RootObject*>* results = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!results) return luaL_error(L, "Argument 2 to getObjectsWithinBox must be lektor<RootObject*>");

    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    Ogre::Vector3 size;
    readVector3(L, 4, size);
    Ogre::Quaternion rot;
    readQuaternion(L, 5, rot);
    itemType type = (itemType)luaL_checkinteger(L, 6);
    int maxNumber = (int)luaL_checkinteger(L, 7);
    RootObject* skip = lua_isnoneornil(L, 8) ? nullptr : checkObject<RootObject>(L, 8, RootObjectBinding::getMetatableName());

    instance->getObjectsWithinBox(*results, pos, size, rot, type, maxNumber, skip);
    return 0;
}

int GameWorldBinding::getCharacterUpdateList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    const ogre_unordered_set<Character*>::type& list = instance->getCharacterUpdateList();
    return pushObject<ogre_unordered_set<Character*>::type>(L, (ogre_unordered_set<Character*>::type*)&list, "ogre_unordered_set<Character*>");
}

int GameWorldBinding::sysMessage(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    GameWorld::SysMessage* m = checkObject<GameWorld::SysMessage>(L, 2, SysMessageBinding::getMetatableName());
    instance->sysMessage(*m);
    return 0;
}

int GameWorldBinding::sysMessageUrgent(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    GameWorld::SysMessage* m = checkObject<GameWorld::SysMessage>(L, 2, SysMessageBinding::getMetatableName());
    instance->sysMessageUrgent(*m);
    return 0;
}

int GameWorldBinding::sysMessage_noDuplicates(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    GameWorld::SysMessage* m = checkObject<GameWorld::SysMessage>(L, 2, SysMessageBinding::getMetatableName());
    instance->sysMessage_noDuplicates(*m);
    return 0;
}

int GameWorldBinding::getCollisionGroupType(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    itemType type = (itemType)luaL_checkinteger(L, 2);
    NxShapesType shapeType = NX_ALL_SHAPES;
    unsigned int group = 0;
    instance->getCollisionGroupType(type, shapeType, group);
    lua_pushinteger(L, (lua_Integer)shapeType);
    lua_pushinteger(L, (lua_Integer)group);
    return 2;
}

typedef StdMapBinding<std::string, ModInfo> AvailableModsMapBinding;

static int GameWorld_get_baseMods(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<lektor<ModInfo>>(L, &instance->baseMods, "lektor<ModInfo>");
}

static int GameWorld_set_baseMods(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    auto* val = LektorValueReadOnlyBinding<ModInfo>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set baseMods must be lektor<ModInfo>");
    instance->baseMods = *val;
    return 0;
}

static int GameWorld_get_baseModsNames(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<lektor<std::string>>(L, &instance->baseModsNames, "lektor<std::string>");
}

static int GameWorld_set_baseModsNames(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    auto* val = LektorStringBinding<std::string>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set baseModsNames must be lektor<std::string>");
    instance->baseModsNames = *val;
    return 0;
}

static int GameWorld_get_activeMods(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<lektor<ModInfo*>>(L, &instance->activeMods, "lektor<ModInfo*>");
}

static int GameWorld_set_activeMods(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    auto* val = LektorPtrBinding<ModInfo*>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set activeMods must be lektor<ModInfo*>");
    instance->activeMods = *val;
    return 0;
}

static int GameWorld_get_availableModsByName(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<AvailableModsMapBinding::MapType>(L, &instance->availableModsByName, "std::map<std::string, ModInfo>");
}

static int GameWorld_set_availableModsByName(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    auto* val = AvailableModsMapBinding::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set availableModsByName must be std::map<std::string, ModInfo>");
    instance->availableModsByName = *val;
    return 0;
}

static int GameWorld_get_availabelModsOrderedList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<lektor<ModInfo*>>(L, &instance->availabelModsOrderedList, "lektor<ModInfo*>");
}

static int GameWorld_set_availabelModsOrderedList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    auto* val = LektorPtrBinding<ModInfo*>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set availabelModsOrderedList must be lektor<ModInfo*>");
    instance->availabelModsOrderedList = *val;
    return 0;
}

static int GameWorld_get_updatePortraitsMap(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<ogre_unordered_map<hand, float>::type>(L, &instance->updatePortraitsMap, "ogre_unordered_map<hand, float>");
}

static int GameWorld_set_updatePortraitsMap(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    auto* val = checkObject<ogre_unordered_map<hand, float>::type>(L, 2, "ogre_unordered_map<hand, float>");
    if (!val) return luaL_error(L, "Argument 2 to set updatePortraitsMap must be ogre_unordered_map<hand, float>");
    instance->updatePortraitsMap = *val;
    return 0;
}

static int GameWorld_get_dynamicDestroyBuildingsList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<lektor<hand>>(L, &instance->dynamicDestroyBuildingsList, "lektor<hand>");
}

static int GameWorld_set_dynamicDestroyBuildingsList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    auto* val = checkObject<lektor<hand>>(L, 2, "lektor<hand>");
    if (!val) return luaL_error(L, "Argument 2 to set dynamicDestroyBuildingsList must be lektor<hand>");
    instance->dynamicDestroyBuildingsList = *val;
    return 0;
}

static int GameWorld_get_destroyListTBM(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<ogre_unordered_set<TownBuildingsManager*>::type>(L, &instance->destroyListTBM, "ogre_unordered_set<TownBuildingsManager*>");
}

static int GameWorld_set_destroyListTBM(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    auto* val = checkObject<ogre_unordered_set<TownBuildingsManager*>::type>(L, 2, "ogre_unordered_set<TownBuildingsManager*>");
    if (!val) return luaL_error(L, "Argument 2 to set destroyListTBM must be ogre_unordered_set<TownBuildingsManager*>");
    instance->destroyListTBM = *val;
    return 0;
}

static int GameWorld_get_killListPhase0(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<ogre_unordered_set<RootObject*>::type>(L, &instance->killListPhase0, "ogre_unordered_set<RootObject*>");
}

static int GameWorld_set_killListPhase0(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    auto* val = checkObject<ogre_unordered_set<RootObject*>::type>(L, 2, "ogre_unordered_set<RootObject*>");
    if (!val) return luaL_error(L, "Argument 2 to set killListPhase0 must be ogre_unordered_set<RootObject*>");
    instance->killListPhase0 = *val;
    return 0;
}

static int GameWorld_get_killListPhase1(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<ogre_unordered_map<RootObject*, float>::type>(L, &instance->killListPhase1, "ogre_unordered_map<RootObject*, float>");
}

static int GameWorld_set_killListPhase1(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    auto* val = checkObject<ogre_unordered_map<RootObject*, float>::type>(L, 2, "ogre_unordered_map<RootObject*, float>");
    if (!val) return luaL_error(L, "Argument 2 to set killListPhase1 must be ogre_unordered_map<RootObject*, float>");
    instance->killListPhase1 = *val;
    return 0;
}

static int GameWorld_get_killListPhase2(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<KillListPhase2DequeBinding::DequeType>(L, &instance->killListPhase2, "std::deque<RootObject*>");
}

static int GameWorld_set_killListPhase2(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    if (lua_isnoneornil(L, 2))
    {
        instance->killListPhase2.clear();
        return 0;
    }
    auto* src = KillListPhase2DequeBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set killListPhase2 must be std::deque<RootObject*>");
    instance->killListPhase2 = *src;
    return 0;
}

static int GameWorld_get_nestBatcherKillList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<NestBatcherKillListDequeBinding::DequeType>(L, &instance->nestBatcherKillList, "std::deque<NestBatcher*>");
}

static int GameWorld_set_nestBatcherKillList(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    if (lua_isnoneornil(L, 2))
    {
        instance->nestBatcherKillList.clear();
        return 0;
    }
    auto* src = NestBatcherKillListDequeBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set nestBatcherKillList must be std::deque<NestBatcher*>");
    instance->nestBatcherKillList = *src;
    return 0;
}


static int GameWorld_get_mainUpdateListRemovalQueue(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<lektor<Character*>>(L, &instance->mainUpdateListRemovalQueue, "lektor<Character*>");
}

static int GameWorld_set_mainUpdateListRemovalQueue(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    auto* val = LektorPtrBinding<Character*>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set mainUpdateListRemovalQueue must be lektor<Character*>");
    instance->mainUpdateListRemovalQueue = *val;
    return 0;
}

static int GameWorld_get_charactersWithLights(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<ogre_unordered_set<Character*>::type>(L, &instance->charactersWithLights, "ogre_unordered_set<Character*>");
}

static int GameWorld_set_charactersWithLights(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    auto* val = checkObject<ogre_unordered_set<Character*>::type>(L, 2, "ogre_unordered_set<Character*>");
    if (val) instance->charactersWithLights = *val;
    return 0;
}

static int GameWorld_get_deathParade(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<ogre_unordered_map<hand, Character*>::type>(L, &instance->deathParade, "ogre_unordered_map<hand, Character*>");
}

static int GameWorld_set_deathParade(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    auto* val = checkObject<ogre_unordered_map<hand, Character*>::type>(L, 2, "ogre_unordered_map<hand, Character*>");
    if (val) instance->deathParade = *val;
    return 0;
}

static int GameWorld_get_charUpdateListMain(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    return pushObject<ogre_unordered_set<Character*>::type>(L, &instance->charUpdateListMain, "ogre_unordered_set<Character*>");
}

static int GameWorld_set_charUpdateListMain(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    auto* val = checkObject<ogre_unordered_set<Character*>::type>(L, 2, "ogre_unordered_set<Character*>");
    if (val) instance->charUpdateListMain = *val;
    return 0;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - GameWorld_get_render: RendererT* (unbound pointer type RendererT)
  - GameWorld_get_nodeList: NodeList* (unbound pointer type NodeList)
  - GameWorld_get_messageRoller: MessageRoller* (unbound pointer type MessageRoller)
  - GameWorld_get_ogreLogger: Ogre::Log* (unbound pointer type Ogre::Log)
  - GameWorld_get__AINonRenderThread: RenderTimeBackthread* (unbound pointer type RenderTimeBackthread)
  - GameWorld_get_audioThread: AudioSystemGlobal* (unbound pointer type AudioSystemGlobal)
  - GameWorldBinding::start: RendererT* parameter (unbound pointer type RendererT, lightuserdata parameter)
  - GameWorldBinding::destroy: MovableObject*, AttachedEntity*, NestBatcher* overloads (unbound pointer types, lightuserdata fallbacks)

SKIPPED PROPERTIES / CONTAINERS NEEDING MANUAL BINDING OR UNBOUND TYPES:
  - sysMessageList (std::list<GameWorld::SysMessage>) - unsupported container type std::list
  - destroyListAE (ogre_unordered_set<AttachedEntity*>::type) - unbound element type AttachedEntity*
  - destroyListOE (ogre_unordered_set<Ogre::MovableObject*>::type) - unbound element type Ogre::MovableObject*
*/

int GameWorldBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GameWorldBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GameWorld object");
    return 1;
}

void GameWorldBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameWorldBinding::gc },
        { "__tostring", GameWorldBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "justLoadFactionRelations", GameWorldBinding::justLoadFactionRelations },
        { "startUpThreads", GameWorldBinding::startUpThreads },
        { "start", GameWorldBinding::start },
        { "destroy", GameWorldBinding::destroy },
        { "_CONSTRUCTOR", GameWorldBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", GameWorldBinding::_DESTRUCTOR },
        { "resetGame", GameWorldBinding::resetGame },
        { "_clearAndDestroyGameWorldStuff", GameWorldBinding::_clearAndDestroyGameWorldStuff },
        { "initialisation", GameWorldBinding::initialisation },
        { "initialisationGameData", GameWorldBinding::initialisationGameData },
        { "dailyUpdates", GameWorldBinding::dailyUpdates },
        { "initialiseNewGameWorld", GameWorldBinding::initialiseNewGameWorld },
        { "errorToLogReleaseMode", GameWorldBinding::errorToLogReleaseMode },
        { "errorD", GameWorldBinding::errorD },
        { "logToSave", GameWorldBinding::logToSave },
        { "log", GameWorldBinding::log },
        { "logDebug", GameWorldBinding::logDebug },
        { "dynamicDestroyBuilding", GameWorldBinding::dynamicDestroyBuilding },
        { "getFromDeathParade", GameWorldBinding::getFromDeathParade },
        { "addPortraitUpdate", GameWorldBinding::addPortraitUpdate },
        { "removePortaitUpdate", GameWorldBinding::removePortaitUpdate },
        { "getModsListFromConfig", GameWorldBinding::getModsListFromConfig },
        { "getAllModsList", GameWorldBinding::getAllModsList },
        { "getModLeveldataFolder", GameWorldBinding::getModLeveldataFolder },
        { "getObjectsWithinSphere", GameWorldBinding::getObjectsWithinSphere },
        { "getCharactersWithinSphere", GameWorldBinding::getCharactersWithinSphere },
        { "getObjectsWithinBox", GameWorldBinding::getObjectsWithinBox },
        { "getCharacterUpdateList", GameWorldBinding::getCharacterUpdateList },
        { "sysMessage", GameWorldBinding::sysMessage },
        { "sysMessageUrgent", GameWorldBinding::sysMessageUrgent },
        { "sysMessage_noDuplicates", GameWorldBinding::sysMessage_noDuplicates },
        { "getCollisionGroupType", GameWorldBinding::getCollisionGroupType },
        { "getTimeFromStamp", GameWorldBinding::getTimeFromStamp },
        { "getIsInKillList", GameWorldBinding::getIsInKillList },
        { "flushKillList", GameWorldBinding::flushKillList },
        { "allThreadQueuesAreClear", GameWorldBinding::allThreadQueuesAreClear },
        { "initBaseMods", GameWorldBinding::initBaseMods },
        { "initModsList", GameWorldBinding::initModsList },
        { "getModIndex", GameWorldBinding::getModIndex },
        { "buildingIntersectionTestCapsule", GameWorldBinding::buildingIntersectionTestCapsule },
        { "getLightLevel", GameWorldBinding::getLightLevel },
        { "populateMapArea_nonPermanent", GameWorldBinding::populateMapArea_nonPermanent },
        { "findValidSpawnPos", GameWorldBinding::findValidSpawnPos },
        { "togglePause", GameWorldBinding::togglePause },
        { "getFrameSpeedMultiplier", GameWorldBinding::getFrameSpeedMultiplier },
        { "setFrameSpeedMultiplier", GameWorldBinding::setFrameSpeedMultiplier },
        { "setGameSpeed", GameWorldBinding::setGameSpeed },
        { "userPause", GameWorldBinding::userPause },
        { "isPaused", GameWorldBinding::isPaused },
        { "getCameraCenter", GameWorldBinding::getCameraCenter },
        { "getCameraPos", GameWorldBinding::getCameraPos },
        { "fixNaNPosition", GameWorldBinding::fixNaNPosition },
        { "getWindSpeed", GameWorldBinding::getWindSpeed },
        { "isLoadingFromASaveGame", GameWorldBinding::isLoadingFromASaveGame },
        { "addToUpdateListMain", GameWorldBinding::addToUpdateListMain },
        { "removeFromUpdateListMain", GameWorldBinding::removeFromUpdateListMain },
        { "addToDeathParade", GameWorldBinding::addToDeathParade },
        { "removeFromDeathParade", GameWorldBinding::removeFromDeathParade },
        { "removeFromDeathParadeByPlatoon", GameWorldBinding::removeFromDeathParadeByPlatoon },
        { "hideContextMenu", GameWorldBinding::hideContextMenu },
        { "showPlayerAMessage_withLog", GameWorldBinding::showPlayerAMessage_withLog },
        { "showPlayerAMessage", GameWorldBinding::showPlayerAMessage },
        { "showPlayerAMessageD", GameWorldBinding::showPlayerAMessageD },
        { "playNotification", GameWorldBinding::playNotification },
        { "mainLoop_GPUSensitiveStuff", GameWorldBinding::mainLoop_GPUSensitiveStuff },
        { "_NV_mainLoop_GPUSensitiveStuff", GameWorldBinding::_NV_mainLoop_GPUSensitiveStuff },
        { "clearPortaitsUpdate", GameWorldBinding::clearPortaitsUpdate },
        { "processSysMessages", GameWorldBinding::processSysMessages },
        { "destroyDeathParade", GameWorldBinding::destroyDeathParade },
        { "processKeys", GameWorldBinding::processKeys },
        { "processThreadMessages", GameWorldBinding::processThreadMessages },
        { "charsUpdate", GameWorldBinding::charsUpdate },
        { "charsUpdateUT", GameWorldBinding::charsUpdateUT },
        { "charsUpdatePaused", GameWorldBinding::charsUpdatePaused },
        { "charsUpdateDeathParade", GameWorldBinding::charsUpdateDeathParade },
        { "threadSafeRagdollUpdates", GameWorldBinding::threadSafeRagdollUpdates },
        { "AINonRenderThread", GameWorldBinding::AINonRenderThread },
        { "processAttachmentsKillList", GameWorldBinding::processAttachmentsKillList },
        { "processKillList", GameWorldBinding::processKillList },
        { "processUpdateRemovalList", GameWorldBinding::processUpdateRemovalList },
        { "loadAllPlatoons", GameWorldBinding::loadAllPlatoons },
        { "reCalculateFortificationInsideOutsideStateForAllCharacters", GameWorldBinding::reCalculateFortificationInsideOutsideStateForAllCharacters },
        { "getTimeStamp", GameWorldBinding::getTimeStamp },
        { "getTimeFromStamp_inGameHours", GameWorldBinding::getTimeFromStamp_inGameHours },
        { "getTimeStamp_inGameHours", GameWorldBinding::getTimeStamp_inGameHours },
        { "getLengthOfHourInRealSeconds", GameWorldBinding::getLengthOfHourInRealSeconds },
        { 0, 0 }
    };

    registerClass(
        L, 
        GameWorldBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GameWorldBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "tempSpawnsDisableTimer", GameWorld_get_tempSpawnsDisableTimer);
    registerGetter(L, "initialized", GameWorld_get_initialized);
    registerGetter(L, "render", GameWorld_get_render);
    registerGetter(L, "physics", GameWorld_get_physics);
    registerGetter(L, "gamedata", GameWorld_get_gamedata);
    registerGetter(L, "leveldata", GameWorld_get_leveldata);
    registerGetter(L, "savedata", GameWorld_get_savedata);
    registerGetter(L, "theFactory", GameWorld_get_theFactory);
    registerGetter(L, "factionMgr", GameWorld_get_factionMgr);
    registerGetter(L, "navmesh", GameWorld_get_navmesh);
    registerGetter(L, "nodeList", GameWorld_get_nodeList);
    registerGetter(L, "guiDisplayObject", GameWorld_get_guiDisplayObject);
    registerGetter(L, "messageRoller", GameWorld_get_messageRoller);
    registerGetter(L, "ogreLogger", GameWorld_get_ogreLogger);
    registerGetter(L, "steamEnabled", GameWorld_get_steamEnabled);
    registerGetter(L, "baseMods", GameWorld_get_baseMods);
    registerGetter(L, "baseModsNames", GameWorld_get_baseModsNames);
    registerGetter(L, "activeMods", GameWorld_get_activeMods);
    registerGetter(L, "availableModsByName", GameWorld_get_availableModsByName);
    registerGetter(L, "availabelModsOrderedList", GameWorld_get_availabelModsOrderedList);
    registerGetter(L, "player", GameWorld_get_player);
    registerGetter(L, "frameSpeedMult", GameWorld_get_frameSpeedMult);
    registerGetter(L, "deathParadeWasMeddledWith", GameWorld_get_deathParadeWasMeddledWith);
    registerGetter(L, "charUpdateListMain_inUse", GameWorld_get_charUpdateListMain_inUse);
    registerGetter(L, "_AINonRenderThread", GameWorld_get__AINonRenderThread);
    registerGetter(L, "timeStamper", GameWorld_get_timeStamper);
    registerGetter(L, "zoneMgr", GameWorld_get_zoneMgr);
    registerGetter(L, "debugFlag", GameWorld_get_debugFlag);
    registerGetter(L, "paused", GameWorld_get_paused);
    registerGetter(L, "gameResetting", GameWorld_get_gameResetting);
    registerGetter(L, "audioThread", GameWorld_get_audioThread);
    registerGetter(L, "charactersWithLights", GameWorld_get_charactersWithLights);
    registerGetter(L, "updatePortraitsMap", GameWorld_get_updatePortraitsMap);
    registerGetter(L, "dynamicDestroyBuildingsList", GameWorld_get_dynamicDestroyBuildingsList);
    registerGetter(L, "destroyListTBM", GameWorld_get_destroyListTBM);
    registerGetter(L, "deathParade", GameWorld_get_deathParade);
    registerGetter(L, "charUpdateListMain", GameWorld_get_charUpdateListMain);
    registerGetter(L, "killListPhase0", GameWorld_get_killListPhase0);
    registerGetter(L, "killListPhase1", GameWorld_get_killListPhase1);
    registerGetter(L, "killListPhase2", GameWorld_get_killListPhase2);
    registerGetter(L, "nestBatcherKillList", GameWorld_get_nestBatcherKillList);
    registerGetter(L, "mainUpdateListRemovalQueue", GameWorld_get_mainUpdateListRemovalQueue);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "tempSpawnsDisableTimer", GameWorld_set_tempSpawnsDisableTimer);
    registerSetter(L, "initialized", GameWorld_set_initialized);
    registerSetter(L, "physics", GameWorld_set_physics);
    registerSetter(L, "gamedata", GameWorld_set_gamedata);
    registerSetter(L, "leveldata", GameWorld_set_leveldata);
    registerSetter(L, "savedata", GameWorld_set_savedata);
    registerSetter(L, "theFactory", GameWorld_set_theFactory);
    registerSetter(L, "factionMgr", GameWorld_set_factionMgr);
    registerSetter(L, "navmesh", GameWorld_set_navmesh);
    registerSetter(L, "guiDisplayObject", GameWorld_set_guiDisplayObject);
    registerSetter(L, "steamEnabled", GameWorld_set_steamEnabled);
    registerSetter(L, "baseMods", GameWorld_set_baseMods);
    registerSetter(L, "baseModsNames", GameWorld_set_baseModsNames);
    registerSetter(L, "activeMods", GameWorld_set_activeMods);
    registerSetter(L, "availableModsByName", GameWorld_set_availableModsByName);
    registerSetter(L, "availabelModsOrderedList", GameWorld_set_availabelModsOrderedList);
    registerSetter(L, "player", GameWorld_set_player);
    registerSetter(L, "frameSpeedMult", GameWorld_set_frameSpeedMult);
    registerSetter(L, "deathParadeWasMeddledWith", GameWorld_set_deathParadeWasMeddledWith);
    registerSetter(L, "charUpdateListMain_inUse", GameWorld_set_charUpdateListMain_inUse);
    registerSetter(L, "timeStamper", GameWorld_set_timeStamper);
    registerSetter(L, "zoneMgr", GameWorld_set_zoneMgr);
    registerSetter(L, "debugFlag", GameWorld_set_debugFlag);
    registerSetter(L, "paused", GameWorld_set_paused);
    registerSetter(L, "gameResetting", GameWorld_set_gameResetting);
    registerSetter(L, "charactersWithLights", GameWorld_set_charactersWithLights);
    registerSetter(L, "updatePortraitsMap", GameWorld_set_updatePortraitsMap);
    registerSetter(L, "dynamicDestroyBuildingsList", GameWorld_set_dynamicDestroyBuildingsList);
    registerSetter(L, "destroyListTBM", GameWorld_set_destroyListTBM);
    registerSetter(L, "deathParade", GameWorld_set_deathParade);
    registerSetter(L, "charUpdateListMain", GameWorld_set_charUpdateListMain);
    registerSetter(L, "killListPhase0", GameWorld_set_killListPhase0);
    registerSetter(L, "killListPhase1", GameWorld_set_killListPhase1);
    registerSetter(L, "killListPhase2", GameWorld_set_killListPhase2);
    registerSetter(L, "nestBatcherKillList", GameWorld_set_nestBatcherKillList);
    registerSetter(L, "mainUpdateListRemovalQueue", GameWorld_set_mainUpdateListRemovalQueue);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    LektorValueReadOnlyBinding<ModInfo>::registerBinding(L, "lektor<ModInfo>", ModInfoBinding::getMetatableName());
    LektorStringBinding<std::string>::registerBinding(L, "lektor<std::string>");
    LektorPtrBinding<ModInfo*>::registerBinding(L, "lektor<ModInfo*>", ModInfoBinding::getMetatableName());
    AvailableModsMapBinding::registerBinding(L, "std::map<std::string, ModInfo>", nullptr, ModInfoBinding::getMetatableName());
    OgreUnorderedSetBinding<Character*>::registerBinding(L, "ogre_unordered_set<Character*>", CharacterBinding::getMetatableName());
    OgreUnorderedMapBinding<hand, float>::registerBinding(L, "ogre_unordered_map<hand, float>", HandBinding::getMetatableName(), nullptr);
    LektorValueReadOnlyBinding<hand>::registerBinding(L, "lektor<hand>", HandBinding::getMetatableName());
    OgreUnorderedSetBinding<TownBuildingsManager*>::registerBinding(L, "ogre_unordered_set<TownBuildingsManager*>", TownBuildingsManagerBinding::getMetatableName());
    OgreUnorderedMapBinding<hand, Character*>::registerBinding(L, "ogre_unordered_map<hand, Character*>", HandBinding::getMetatableName(), CharacterBinding::getMetatableName());
    OgreUnorderedSetBinding<Character*>::registerBinding(L, "ogre_unordered_set<Character*>", CharacterBinding::getMetatableName());
    OgreUnorderedSetBinding<RootObject*>::registerBinding(L, "ogre_unordered_set<RootObject*>", RootObjectBinding::getMetatableName());
    OgreUnorderedMapBinding<RootObject*, float>::registerBinding(L, "ogre_unordered_map<RootObject*, float>", RootObjectBinding::getMetatableName(), nullptr);
    KillListPhase2DequeBinding::registerBinding(L, "std::deque<RootObject*>", RootObjectBinding::getMetatableName());
    NestBatcherKillListDequeBinding::registerBinding(L, "std::deque<NestBatcher*>", nullptr);
    LektorPtrBinding<Character*>::registerBinding(L, "lektor<Character*>", CharacterBinding::getMetatableName());

/*
LIGHTUSERDATA DEPENDENCIES:
  - GameWorld_get_render / GameWorld_set_render: (unbound pointer)
  - GameWorld_get_nodeList / GameWorld_set_nodeList: DataObjectContainer* (unbound pointer)
  - GameWorld_get_messageRoller / GameWorld_set_messageRoller: DatapanelGUI* (unbound pointer)
  - GameWorld_get_ogreLogger / GameWorld_set_ogreLogger: Ogre::Log* (unbound pointer)
  - GameWorld_get__AINonRenderThread / GameWorld_set__AINonRenderThread: ThreadClass* (unbound pointer)
  - GameWorld_get_audioThread / GameWorld_set_audioThread: ThreadClass* (unbound pointer)
*/

    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, GameWorldBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua