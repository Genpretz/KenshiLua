#include "pch.h"
#include "kenshi\gameworld.h"
#include "GameWorldBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionManagerBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataManagerBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/PlayerInterfaceBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/RootObjectFactoryBinding.h"
#include "Bindings/SimpleTimeStamperBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
#include "Bindings/TownBuildingsManagerBinding.h"
#include "Bindings/ZoneManagerBinding.h"
#include "Bindings/ZoneMapBinding.h"

namespace KenshiLua
{

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
    lua_pushlightuserdata(L, (void*)instance->physics);
    return 1;
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
    lua_pushlightuserdata(L, (void*)instance->navmesh);
    return 1;
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
    return handBinding::push(L, instance->guiDisplayObject);
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

static int GameWorld_set_guiDisplayObject(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");
    instance->guiDisplayObject = *checkObject<hand>(L, 2, handBinding::getMetatableName());
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

// int GameWorldBinding::playNotification(lua_State* L)
// {
//     GameWorld* instance = getInstance(L, 1);
//     if (!instance) return luaL_error(L, "GameWorld is nil");

//     const char* sound = (char)luaL_checkinteger(L, 2);
//     instance->playNotification(sound);
//     return 0;
// }

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
    lua_pushlightuserdata(L, (void*)result);
    return 1;
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
    return pushObject<TimeOfDay>(L, &result, TimeOfDayBinding::getMetatableName());
}

int GameWorldBinding::getLengthOfHourInRealSeconds(lua_State* L)
{
    GameWorld* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameWorld is nil");

    float result = instance->getLengthOfHourInRealSeconds();
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 71: bool start(...) - unsupported arg type
  line 82: void logDebug(...) - overloaded method
  line 83: void logDebug(...) - overloaded method
  line 84: void destroy(...) - overloaded method
  line 85: void destroy(...) - overloaded method
  line 86: void destroy(...) - overloaded method
  line 87: void destroy(...) - overloaded method
  line 88: bool destroy(...) - overloaded method
  line 89: void destroy(...) - overloaded method
  line 92: void dynamicDestroyBuilding(...) - non-string reference arg
  line 115: lektor<ModInfo*> getModsListFromConfig(...) - unsupported return type
  line 116: const lektor<ModInfo*>& getAllModsList(...) - reference return type
  line 118: const std::string& getModLeveldataFolder(...) - reference return type
  line 119: void getObjectsWithinSphere(...) - unsupported arg type
  line 120: void getCharactersWithinSphere(...) - unsupported arg type
  line 121: void getObjectsWithinBox(...) - unsupported arg type
  line 140: const ogre_unordered_set<Character*>::type& getCharacterUpdateList(...) - reference return type
  line 144: Character* getFromDeathParade(...) - non-string reference arg
  line 192: void sysMessage(...) - non-string reference arg
  line 193: void sysMessageUrgent(...) - non-string reference arg
  line 194: void sysMessage_noDuplicates(...) - non-string reference arg
  line 198: void addPortraitUpdate(...) - non-string reference arg
  line 199: void removePortaitUpdate(...) - non-string reference arg
  line 202: void getCollisionGroupType(...) - unsupported arg type
  line 235: TimeOfDay getTimeFromStamp(...) - overloaded method
  line 236: float getTimeFromStamp(...) - overloaded method
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - GameWorld_get_render: RendererT* (unbound pointer)
  - GameWorld_get_physics: PhysicsInterface* (unbound pointer)
  - GameWorld_get_navmesh: NavMesh* (unbound pointer)
  - GameWorld_get_nodeList: NodeList* (unbound pointer)
  - GameWorld_get_messageRoller: MessageRoller* (unbound pointer)
  - GameWorld_get_ogreLogger: Ogre::Log* (unbound pointer)
  - GameWorld_get__AINonRenderThread: RenderTimeBackthread* (unbound pointer)
  - GameWorld_get_audioThread: AudioSystemGlobal* (unbound pointer)
  - GameWorldBinding::AINonRenderThread: ThreadWannabe* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 108: baseMods (lektor<ModInfo>) - unsupported type
  line 109: baseModsNames (lektor<std::string >) - unsupported type
  line 110: activeMods (lektor<ModInfo*>) - unsupported type
  line 111: availableModsByName (std::map<std::string, ModInfo, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, ModInfo>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 112: availabelModsOrderedList (lektor<ModInfo*>) - unsupported type
  line 153: charactersWithLights (ogre_unordered_set<Character*>::type) - unsupported type
  line 200: sysMessageList (std::list<GameWorld::SysMessage, Ogre::STLAllocator<GameWorld::SysMessage, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 203: updatePortraitsMap (ogre_unordered_map<hand, float>::type) - unsupported type
  line 204: dynamicDestroyBuildingsList (lektor<hand>) - unsupported type
  line 205: destroyListAE (ogre_unordered_set<AttachedEntity*>::type) - unsupported type
  line 206: destroyListOE (ogre_unordered_set<Ogre::MovableObject*>::type) - unsupported type
  line 207: destroyListTBM (ogre_unordered_set<TownBuildingsManager*>::type) - unsupported type
  line 210: deathParade (ogre_unordered_map<hand, Character*>::type) - unsupported type
  line 215: charUpdateListMain (ogre_unordered_set<Character*>::type) - unsupported type
  line 226: nestBatcherKillList (std::deque<NestBatcher*, Ogre::STLAllocator<NestBatcher*, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 227: killListPhase0 (ogre_unordered_set<RootObject*>::type) - unsupported type
  line 228: killListPhase1 (ogre_unordered_map<RootObject*, float>::type) - unsupported type
  line 229: killListPhase2 (std::deque<RootObject*, Ogre::STLAllocator<RootObject*, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 230: mainUpdateListRemovalQueue (lektor<Character*>) - unsupported type
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
        //{ "playNotification", GameWorldBinding::playNotification },
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
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "tempSpawnsDisableTimer", GameWorld_set_tempSpawnsDisableTimer);
    registerSetter(L, "initialized", GameWorld_set_initialized);
    registerSetter(L, "gamedata", GameWorld_set_gamedata);
    registerSetter(L, "leveldata", GameWorld_set_leveldata);
    registerSetter(L, "savedata", GameWorld_set_savedata);
    registerSetter(L, "theFactory", GameWorld_set_theFactory);
    registerSetter(L, "factionMgr", GameWorld_set_factionMgr);
    registerSetter(L, "guiDisplayObject", GameWorld_set_guiDisplayObject);
    registerSetter(L, "steamEnabled", GameWorld_set_steamEnabled);
    registerSetter(L, "player", GameWorld_set_player);
    registerSetter(L, "frameSpeedMult", GameWorld_set_frameSpeedMult);
    registerSetter(L, "deathParadeWasMeddledWith", GameWorld_set_deathParadeWasMeddledWith);
    registerSetter(L, "charUpdateListMain_inUse", GameWorld_set_charUpdateListMain_inUse);
    registerSetter(L, "timeStamper", GameWorld_set_timeStamper);
    registerSetter(L, "zoneMgr", GameWorld_set_zoneMgr);
    registerSetter(L, "debugFlag", GameWorld_set_debugFlag);
    registerSetter(L, "paused", GameWorld_set_paused);
    registerSetter(L, "gameResetting", GameWorld_set_gameResetting);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, GameWorldBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua