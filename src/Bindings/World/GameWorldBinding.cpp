#include "pch.h"
#include "Bindings/World/GameWorldBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Globals.h>
#include <kenshi/GameWorld.h>

#include <ogre/OgreVector3.h>
#include "Bindings/Core/PlayerInterfaceBinding.h"
#include <kenshi/PlayerInterface.h>

namespace KenshiLua
{

static GameWorld* getG(lua_State* L, int idx)
{
    // Allow `GameWorld.method(...)` (no self) by falling back to the global
    // `ou` pointer when there's no userdata on the stack at idx.
    if (lua_isnoneornil(L, idx)) return ::ou;
    return checkObject<GameWorld>(L, idx, GameWorldBinding::getMetatableName());
}

int GameWorldBinding::gc(lua_State* L)       { return noopGc(L); }

int GameWorldBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, GameWorldBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    GameWorld* g = getG(L, 1);
    if(!g) { lua_pushnil(L); return 1; }

    if (strcmp(key, "tempSpawnsDisableTimer") == 0) { lua_pushnumber(L, g->tempSpawnsDisableTimer); return 1; }
    if (strcmp(key, "initialized") == 0) { lua_pushboolean(L, g->initialized ? 1 : 0); return 1; }
    // TODO RendererT* render; unsupported __index type from header line 95
    // TODO PhysicsInterface* physics; unsupported __index type from header line 96
    // TODO GameDataManager gamedata; unsupported __index type from header line 97
    // TODO GameDataManager leveldata; unsupported __index type from header line 98
    // TODO GameDataManager savedata; unsupported __index type from header line 99
    // TODO RootObjectFactory* theFactory; unsupported __index type from header line 100
    // TODO FactionManager* factionMgr; unsupported __index type from header line 101
    // TODO NavMesh* navmesh; unsupported __index type from header line 102
    // TODO NodeList* nodeList; unsupported __index type from header line 103
    // TODO hand guiDisplayObject; unsupported __index type from header line 104
    // TODO MessageRoller* messageRoller; unsupported __index type from header line 105
    // TODO Ogre::Log* ogreLogger; unsupported __index type from header line 106
    if (strcmp(key, "steamEnabled") == 0) { lua_pushboolean(L, g->steamEnabled ? 1 : 0); return 1; }
    // TODO lektor<ModInfo> baseMods; unsupported __index type from header line 108
    // TODO lektor<std::string > baseModsNames; unsupported __index type from header line 109
    // TODO lektor<ModInfo*> activeMods; unsupported __index type from header line 110
    // TODO std::map<std::string, ModInfo, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, ModInfo>, Ogre::GeneralAllocPolicy > > availableModsByName; unsupported __index type from header line 111
    // TODO lektor<ModInfo*> availabelModsOrderedList; unsupported __index type from header line 112
    if (strcmp(key, "player") == 0) { return pushObject<PlayerInterface>(L, g->player, PlayerInterfaceBinding::getMetatableName()); }
    // TODO ogre_unordered_set<Character*>::type charactersWithLights; unsupported __index type from header line 153
    // TODO std::list<GameWorld::SysMessage, Ogre::STLAllocator<GameWorld::SysMessage, Ogre::GeneralAllocPolicy > > sysMessageList; unsupported __index type from header line 200
    // TODO ogre_unordered_map<hand, float>::type updatePortraitsMap; unsupported __index type from header line 203
    // TODO lektor<hand> dynamicDestroyBuildingsList; unsupported __index type from header line 204
    // TODO ogre_unordered_set<AttachedEntity*>::type destroyListAE; unsupported __index type from header line 205
    // TODO ogre_unordered_set<Ogre::MovableObject*>::type destroyListOE; unsupported __index type from header line 206
    // TODO ogre_unordered_set<TownBuildingsManager*>::type destroyListTBM; unsupported __index type from header line 207
    if (strcmp(key, "frameSpeedMult") == 0) { lua_pushnumber(L, g->frameSpeedMult); return 1; }
    // TODO ogre_unordered_map<hand, Character*>::type deathParade; unsupported __index type from header line 210
    if (strcmp(key, "deathParadeWasMeddledWith") == 0) { lua_pushboolean(L, g->deathParadeWasMeddledWith ? 1 : 0); return 1; }
    if (strcmp(key, "charUpdateListMain_inUse") == 0) { lua_pushboolean(L, g->charUpdateListMain_inUse ? 1 : 0); return 1; }
    // TODO ogre_unordered_set<Character*>::type charUpdateListMain; unsupported __index type from header line 215
    // TODO RenderTimeBackthread* _AINonRenderThread; unsupported __index type from header line 221
    // TODO std::deque<NestBatcher*, Ogre::STLAllocator<NestBatcher*, Ogre::GeneralAllocPolicy > > nestBatcherKillList; unsupported __index type from header line 226
    // TODO ogre_unordered_set<RootObject*>::type killListPhase0; unsupported __index type from header line 227
    // TODO ogre_unordered_map<RootObject*, float>::type killListPhase1; unsupported __index type from header line 228
    // TODO std::deque<RootObject*, Ogre::STLAllocator<RootObject*, Ogre::GeneralAllocPolicy > > killListPhase2; unsupported __index type from header line 229
    // TODO lektor<Character*> mainUpdateListRemovalQueue; unsupported __index type from header line 230
    // TODO SimpleTimeStamper timeStamper; unsupported __index type from header line 233
    // TODO ZoneManager* zoneMgr; unsupported __index type from header line 240
    if (strcmp(key, "debugFlag") == 0) { lua_pushboolean(L, g->debugFlag ? 1 : 0); return 1; }
    if (strcmp(key, "paused") == 0) { lua_pushboolean(L, g->paused ? 1 : 0); return 1; }
    if (strcmp(key, "gameResetting") == 0) { lua_pushboolean(L, g->gameResetting ? 1 : 0); return 1; }
    // TODO AudioSystemGlobal* audioThread; unsupported __index type from header line 244

    lua_pushnil(L);
    return 1;
}

int GameWorldBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    if (strcmp(key, "tempSpawnsDisableTimer") == 0) { g->tempSpawnsDisableTimer = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "initialized") == 0) { g->initialized = lua_toboolean(L, 3) != 0; return 0; }
    // TODO RendererT* render; unsupported __newindex type from header line 95
    // TODO PhysicsInterface* physics; unsupported __newindex type from header line 96
    // TODO GameDataManager gamedata; unsupported __newindex type from header line 97
    // TODO GameDataManager leveldata; unsupported __newindex type from header line 98
    // TODO GameDataManager savedata; unsupported __newindex type from header line 99
    // TODO RootObjectFactory* theFactory; unsupported __newindex type from header line 100
    // TODO FactionManager* factionMgr; unsupported __newindex type from header line 101
    // TODO NavMesh* navmesh; unsupported __newindex type from header line 102
    // TODO NodeList* nodeList; unsupported __newindex type from header line 103
    // TODO hand guiDisplayObject; unsupported __newindex type from header line 104
    // TODO MessageRoller* messageRoller; unsupported __newindex type from header line 105
    // TODO Ogre::Log* ogreLogger; unsupported __newindex type from header line 106
    if (strcmp(key, "steamEnabled") == 0) { g->steamEnabled = lua_toboolean(L, 3) != 0; return 0; }
    // TODO lektor<ModInfo> baseMods; unsupported __newindex type from header line 108
    // TODO lektor<std::string > baseModsNames; unsupported __newindex type from header line 109
    // TODO lektor<ModInfo*> activeMods; unsupported __newindex type from header line 110
    // TODO std::map<std::string, ModInfo, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, ModInfo>, Ogre::GeneralAllocPolicy > > availableModsByName; unsupported __newindex type from header line 111
    // TODO lektor<ModInfo*> availabelModsOrderedList; unsupported __newindex type from header line 112
    // TODO PlayerInterface* player; unsupported __newindex type from header line 137
    // TODO ogre_unordered_set<Character*>::type charactersWithLights; unsupported __newindex type from header line 153
    // TODO std::list<GameWorld::SysMessage, Ogre::STLAllocator<GameWorld::SysMessage, Ogre::GeneralAllocPolicy > > sysMessageList; unsupported __newindex type from header line 200
    // TODO ogre_unordered_map<hand, float>::type updatePortraitsMap; unsupported __newindex type from header line 203
    // TODO lektor<hand> dynamicDestroyBuildingsList; unsupported __newindex type from header line 204
    // TODO ogre_unordered_set<AttachedEntity*>::type destroyListAE; unsupported __newindex type from header line 205
    // TODO ogre_unordered_set<Ogre::MovableObject*>::type destroyListOE; unsupported __newindex type from header line 206
    // TODO ogre_unordered_set<TownBuildingsManager*>::type destroyListTBM; unsupported __newindex type from header line 207
    if (strcmp(key, "frameSpeedMult") == 0) { g->frameSpeedMult = (float)luaL_checknumber(L, 3); return 0; }
    // TODO ogre_unordered_map<hand, Character*>::type deathParade; unsupported __newindex type from header line 210
    if (strcmp(key, "deathParadeWasMeddledWith") == 0) { g->deathParadeWasMeddledWith = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "charUpdateListMain_inUse") == 0) { g->charUpdateListMain_inUse = lua_toboolean(L, 3) != 0; return 0; }
    // TODO ogre_unordered_set<Character*>::type charUpdateListMain; unsupported __newindex type from header line 215
    // TODO RenderTimeBackthread* _AINonRenderThread; unsupported __newindex type from header line 221
    // TODO std::deque<NestBatcher*, Ogre::STLAllocator<NestBatcher*, Ogre::GeneralAllocPolicy > > nestBatcherKillList; unsupported __newindex type from header line 226
    // TODO ogre_unordered_set<RootObject*>::type killListPhase0; unsupported __newindex type from header line 227
    // TODO ogre_unordered_map<RootObject*, float>::type killListPhase1; unsupported __newindex type from header line 228
    // TODO std::deque<RootObject*, Ogre::STLAllocator<RootObject*, Ogre::GeneralAllocPolicy > > killListPhase2; unsupported __newindex type from header line 229
    // TODO lektor<Character*> mainUpdateListRemovalQueue; unsupported __newindex type from header line 230
    // TODO SimpleTimeStamper timeStamper; unsupported __newindex type from header line 233
    // TODO ZoneManager* zoneMgr; unsupported __newindex type from header line 240
    if (strcmp(key, "debugFlag") == 0) { g->debugFlag = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "paused") == 0) { g->paused = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "gameResetting") == 0) { g->gameResetting = lua_toboolean(L, 3) != 0; return 0; }
    // TODO AudioSystemGlobal* audioThread; unsupported __newindex type from header line 244

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int GameWorldBinding::tostring(lua_State* L) { lua_pushstring(L, "GameWorld"); return 1; }

int GameWorldBinding::getCameraCenter(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g) { lua_pushnil(L); return 1; }
    Ogre::Vector3 p = g->getCameraCenter();
    pushVector3(L, p);
    return 1;
}

int GameWorldBinding::getCameraPos(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g) { lua_pushnil(L); return 1; }
    Ogre::Vector3 p = g->getCameraPos();
    pushVector3(L, p);
    return 1;
}

int GameWorldBinding::getLightLevel(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g) { lua_pushnil(L); return 1; }
    Ogre::Vector3 pos(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 2, pos)) return luaL_error(L, "getLightLevel: expected {x,y,z}");
    int floor  = (int)luaL_optinteger(L, 3, 0);
    bool inside = lua_isnoneornil(L, 4) ? true : (lua_toboolean(L, 4) != 0);
    lua_pushnumber(L, g->getLightLevel(pos, floor, inside));
    return 1;
}

int GameWorldBinding::showMessage(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g) return luaL_error(L, "GameWorld is nil");
    const char* msg = luaL_checkstring(L, 2);
    bool queued = lua_isnoneornil(L, 3) ? true : (lua_toboolean(L, 3) != 0);
    g->showPlayerAMessage(msg, queued);
    return 0;
}

int GameWorldBinding::playSound(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g) return luaL_error(L, "GameWorld is nil");
    g->playNotification(luaL_checkstring(L, 2));
    return 0;
}

int GameWorldBinding::getPlayer(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g || !g->player) { lua_pushnil(L); return 1; }
    pushObject<PlayerInterface>(L, g->player, PlayerInterfaceBinding::getMetatableName());
    return 1;
}

int GameWorldBinding::startUpThreads(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    bool result = g->startUpThreads();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::_CONSTRUCTOR(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    GameWorld* result = g->_CONSTRUCTOR();
    return pushObject<GameWorld>(L, result, GameWorldBinding::getMetatableName());
}

int GameWorldBinding::_DESTRUCTOR(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->_DESTRUCTOR();
    return 0;
}

int GameWorldBinding::resetGame(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->resetGame();
    return 0;
}

int GameWorldBinding::_clearAndDestroyGameWorldStuff(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->_clearAndDestroyGameWorldStuff();
    return 0;
}

int GameWorldBinding::initialisation(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    bool result = g->initialisation();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::initialisationGameData(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    bool result = g->initialisationGameData();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::dailyUpdates(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->dailyUpdates();
    return 0;
}

int GameWorldBinding::errorToLogReleaseMode(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    std::string msg = luaL_checkstring(L, 2);
    g->errorToLogReleaseMode(msg);
    return 0;
}

int GameWorldBinding::errorD(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    std::string msg = luaL_checkstring(L, 2);
    g->errorD(msg);
    return 0;
}

int GameWorldBinding::logToSave(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    std::string msg = luaL_checkstring(L, 2);
    g->logToSave(msg);
    return 0;
}

int GameWorldBinding::log(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    std::string line = luaL_checkstring(L, 2);
    g->log(line);
    return 0;
}

int GameWorldBinding::flushKillList(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->flushKillList();
    return 0;
}

int GameWorldBinding::allThreadQueuesAreClear(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    bool result = g->allThreadQueuesAreClear();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::initBaseMods(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->initBaseMods();
    return 0;
}

int GameWorldBinding::initModsList(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->initModsList();
    return 0;
}

int GameWorldBinding::getModIndex(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    std::string modName = luaL_checkstring(L, 2);
    int result = g->getModIndex(modName);
    lua_pushinteger(L, result);
    return 1;
}

int GameWorldBinding::togglePause(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    bool on = lua_toboolean(L, 2) != 0;
    g->togglePause(on);
    return 0;
}

int GameWorldBinding::getFrameSpeedMultiplier(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    float result = g->getFrameSpeedMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int GameWorldBinding::setFrameSpeedMultiplier(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    float m = (float)luaL_checknumber(L, 2);
    g->setFrameSpeedMultiplier(m);
    return 0;
}

int GameWorldBinding::setGameSpeed(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    float speed = (float)luaL_checknumber(L, 2);
    bool click = lua_toboolean(L, 3) != 0;
    g->setGameSpeed(speed, click);
    return 0;
}

int GameWorldBinding::userPause(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    bool p = lua_toboolean(L, 2) != 0;
    g->userPause(p);
    return 0;
}

int GameWorldBinding::isPaused(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    bool result = g->isPaused();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::isLoadingFromASaveGame(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    bool result = g->isLoadingFromASaveGame();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::hideContextMenu(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->hideContextMenu();
    return 0;
}

int GameWorldBinding::showPlayerAMessage_withLog(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    std::string message = luaL_checkstring(L, 2);
    bool queued = lua_toboolean(L, 3) != 0;
    g->showPlayerAMessage_withLog(message, queued);
    return 0;
}

int GameWorldBinding::showPlayerAMessage(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    std::string message = luaL_checkstring(L, 2);
    bool queued = lua_toboolean(L, 3) != 0;
    g->showPlayerAMessage(message, queued);
    return 0;
}

int GameWorldBinding::showPlayerAMessageD(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    std::string message = luaL_checkstring(L, 2);
    bool queued = lua_toboolean(L, 3) != 0;
    g->showPlayerAMessageD(message, queued);
    return 0;
}

int GameWorldBinding::mainLoop_GPUSensitiveStuff(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    float time = (float)luaL_checknumber(L, 2);
    g->mainLoop_GPUSensitiveStuff(time);
    return 0;
}

int GameWorldBinding::_NV_mainLoop_GPUSensitiveStuff(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    float time = (float)luaL_checknumber(L, 2);
    g->_NV_mainLoop_GPUSensitiveStuff(time);
    return 0;
}

int GameWorldBinding::clearPortaitsUpdate(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->clearPortaitsUpdate();
    return 0;
}

int GameWorldBinding::processSysMessages(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->processSysMessages();
    return 0;
}

int GameWorldBinding::destroyDeathParade(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->destroyDeathParade();
    return 0;
}

int GameWorldBinding::processKeys(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->processKeys();
    return 0;
}

int GameWorldBinding::processThreadMessages(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->processThreadMessages();
    return 0;
}

int GameWorldBinding::charsUpdate(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->charsUpdate();
    return 0;
}

int GameWorldBinding::charsUpdateUT(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->charsUpdateUT();
    return 0;
}

int GameWorldBinding::charsUpdatePaused(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->charsUpdatePaused();
    return 0;
}

int GameWorldBinding::charsUpdateDeathParade(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->charsUpdateDeathParade();
    return 0;
}

int GameWorldBinding::threadSafeRagdollUpdates(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->threadSafeRagdollUpdates();
    return 0;
}

int GameWorldBinding::processAttachmentsKillList(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->processAttachmentsKillList();
    return 0;
}

int GameWorldBinding::processKillList(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    bool forceImmediate = lua_toboolean(L, 2) != 0;
    g->processKillList(forceImmediate);
    return 0;
}

int GameWorldBinding::processUpdateRemovalList(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->processUpdateRemovalList();
    return 0;
}

int GameWorldBinding::loadAllPlatoons(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->loadAllPlatoons();
    return 0;
}

int GameWorldBinding::reCalculateFortificationInsideOutsideStateForAllCharacters(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    g->reCalculateFortificationInsideOutsideStateForAllCharacters();
    return 0;
}

int GameWorldBinding::getTimeStamp(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    double result = g->getTimeStamp();
    lua_pushnumber(L, result);
    return 1;
}

int GameWorldBinding::getTimeFromStamp_inGameHours(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    double stamp = (double)luaL_checknumber(L, 2);
    float result = g->getTimeFromStamp_inGameHours(stamp);
    lua_pushnumber(L, result);
    return 1;
}

int GameWorldBinding::getLengthOfHourInRealSeconds(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if(!g) return luaL_error(L, "GameWorld is nil");

    float result = g->getLengthOfHourInRealSeconds();
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 64: void justLoadFactionRelations(...) - unsupported arg type
  line 71: bool start(...) - unsupported arg type
  line 77: void initialiseNewGameWorld(...) - unsupported arg type
  line 82: void logDebug(...) - overloaded method
  line 83: void logDebug(...) - overloaded method
  line 84: void destroy(...) - overloaded method
  line 85: void destroy(...) - overloaded method
  line 86: void destroy(...) - overloaded method
  line 87: void destroy(...) - overloaded method
  line 88: bool destroy(...) - overloaded method
  line 89: void destroy(...) - overloaded method
  line 90: bool getIsInKillList(...) - unsupported arg type
  line 92: void dynamicDestroyBuilding(...) - unsupported arg type
  line 115: lektor<ModInfo*> getModsListFromConfig(...) - unsupported return type
  line 116: const lektor<ModInfo*>& getAllModsList(...) - reference return type
  line 118: const std::string& getModLeveldataFolder(...) - reference return type
  line 119: void getObjectsWithinSphere(...) - unsupported arg type
  line 120: void getCharactersWithinSphere(...) - unsupported arg type
  line 121: void getObjectsWithinBox(...) - unsupported arg type
  line 122: bool buildingIntersectionTestCapsule(...) - unsupported arg type
  line 123: float getLightLevel(...) - unsupported arg type
  line 124: void populateMapArea_nonPermanent(...) - unsupported arg type
  line 125: bool findValidSpawnPos(...) - unsupported arg type
  line 132: const Ogre::Vector3 getCameraCenter(...) - unsupported return type
  line 133: const Ogre::Vector3 getCameraPos(...) - unsupported return type
  line 134: bool fixNaNPosition(...) - unsupported arg type
  line 135: float getWindSpeed(...) - unsupported arg type
  line 138: void addToUpdateListMain(...) - unsupported arg type
  line 139: void removeFromUpdateListMain(...) - unsupported arg type
  line 140: const ogre_unordered_set<Character*>::type& getCharacterUpdateList(...) - reference return type
  line 141: void addToDeathParade(...) - unsupported arg type
  line 142: bool removeFromDeathParade(...) - unsupported arg type
  line 143: void removeFromDeathParadeByPlatoon(...) - unsupported arg type
  line 144: Character* getFromDeathParade(...) - unsupported arg type
  line 151: void playNotification(...) - pointer arg
  line 192: void sysMessage(...) - non-string reference arg
  line 193: void sysMessageUrgent(...) - non-string reference arg
  line 194: void sysMessage_noDuplicates(...) - non-string reference arg
  line 198: void addPortraitUpdate(...) - unsupported arg type
  line 199: void removePortaitUpdate(...) - unsupported arg type
  line 202: void getCollisionGroupType(...) - unsupported arg type
  line 222: ThreadWannabe* AINonRenderThread(...) - unsupported return type
  line 235: TimeOfDay getTimeFromStamp(...) - overloaded method
  line 236: float getTimeFromStamp(...) - overloaded method
  line 238: TimeOfDay getTimeStamp_inGameHours(...) - unsupported return type
*/


void GameWorldBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameWorldBinding::gc },
        { "__tostring", GameWorldBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getCameraCenter",          GameWorldBinding::getCameraCenter },
        { "getCameraPos",             GameWorldBinding::getCameraPos },
        { "getLightLevel",            GameWorldBinding::getLightLevel },
        { "showMessage",              GameWorldBinding::showMessage },
        { "playSound",                GameWorldBinding::playSound },
        { "getPlayer",                GameWorldBinding::getPlayer },
        { "startUpThreads", GameWorldBinding::startUpThreads },
        { "_CONSTRUCTOR", GameWorldBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", GameWorldBinding::_DESTRUCTOR },
        { "resetGame", GameWorldBinding::resetGame },
        { "_clearAndDestroyGameWorldStuff", GameWorldBinding::_clearAndDestroyGameWorldStuff },
        { "initialisation", GameWorldBinding::initialisation },
        { "initialisationGameData", GameWorldBinding::initialisationGameData },
        { "dailyUpdates", GameWorldBinding::dailyUpdates },
        { "errorToLogReleaseMode", GameWorldBinding::errorToLogReleaseMode },
        { "errorD", GameWorldBinding::errorD },
        { "logToSave", GameWorldBinding::logToSave },
        { "log", GameWorldBinding::log },
        { "flushKillList", GameWorldBinding::flushKillList },
        { "allThreadQueuesAreClear", GameWorldBinding::allThreadQueuesAreClear },
        { "initBaseMods", GameWorldBinding::initBaseMods },
        { "initModsList", GameWorldBinding::initModsList },
        { "getModIndex", GameWorldBinding::getModIndex },
        { "togglePause", GameWorldBinding::togglePause },
        { "getFrameSpeedMultiplier", GameWorldBinding::getFrameSpeedMultiplier },
        { "setFrameSpeedMultiplier", GameWorldBinding::setFrameSpeedMultiplier },
        { "setGameSpeed", GameWorldBinding::setGameSpeed },
        { "userPause", GameWorldBinding::userPause },
        { "isPaused", GameWorldBinding::isPaused },
        { "isLoadingFromASaveGame", GameWorldBinding::isLoadingFromASaveGame },
        { "hideContextMenu", GameWorldBinding::hideContextMenu },
        { "showPlayerAMessage_withLog", GameWorldBinding::showPlayerAMessage_withLog },
        { "showPlayerAMessage", GameWorldBinding::showPlayerAMessage },
        { "showPlayerAMessageD", GameWorldBinding::showPlayerAMessageD },
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
        { "processAttachmentsKillList", GameWorldBinding::processAttachmentsKillList },
        { "processKillList", GameWorldBinding::processKillList },
        { "processUpdateRemovalList", GameWorldBinding::processUpdateRemovalList },
        { "loadAllPlatoons", GameWorldBinding::loadAllPlatoons },
        { "reCalculateFortificationInsideOutsideStateForAllCharacters", GameWorldBinding::reCalculateFortificationInsideOutsideStateForAllCharacters },
        { "getTimeStamp", GameWorldBinding::getTimeStamp },
        { "getTimeFromStamp_inGameHours", GameWorldBinding::getTimeFromStamp_inGameHours },
        { "getLengthOfHourInRealSeconds", GameWorldBinding::getLengthOfHourInRealSeconds },
        { 0, 0 }
    };
    registerClass(L, GameWorldBinding::getMetatableName(), meta, methods, GameWorldBinding::index, GameWorldBinding::newindex);
}

} // namespace KenshiLua