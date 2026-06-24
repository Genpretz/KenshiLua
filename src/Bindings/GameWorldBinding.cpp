#include "pch.h"
#include "kenshi\GameWorld.h"
#include "GameWorldBinding.h"
#include "kenshi/PlayerInterface.h"
#include "PlayerInterfaceBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static GameWorld* getB(lua_State* L, int idx)
{
    return checkObject<GameWorld>(L, idx, GameWorldBinding::getMetatableName());
}

// --- Getters for GameWorld ---
static int GameWorld_get_tempSpawnsDisableTimer(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    lua_pushnumber(L, b->tempSpawnsDisableTimer);
    return 1;
}

static int GameWorld_get_initialized(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    lua_pushboolean(L, b->initialized ? 1 : 0);
    return 1;
}

static int GameWorld_get_render(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for render (RendererT*)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_physics(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for physics (PhysicsInterface*)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_gamedata(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for gamedata (GameDataManager)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_leveldata(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for leveldata (GameDataManager)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_savedata(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for savedata (GameDataManager)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_theFactory(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for theFactory (RootObjectFactory*)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_factionMgr(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for factionMgr (FactionManager*)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_navmesh(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for navmesh (NavMesh*)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_nodeList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for nodeList (NodeList*)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_guiDisplayObject(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for guiDisplayObject (hand)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_messageRoller(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for messageRoller (MessageRoller*)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_ogreLogger(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for ogreLogger (Ogre::Log*)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_steamEnabled(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    lua_pushboolean(L, b->steamEnabled ? 1 : 0);
    return 1;
}

static int GameWorld_get_baseMods(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for baseMods (lektor<ModInfo>)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_baseModsNames(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for baseModsNames (lektor<std::string >)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_activeMods(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for activeMods (lektor<ModInfo*>)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_availableModsByName(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for availableModsByName (std::map<std::string, ModInfo, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, ModInfo>, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_availabelModsOrderedList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for availabelModsOrderedList (lektor<ModInfo*>)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_player(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return pushObject<PlayerInterface>(L, b->player, PlayerInterfaceBinding::getMetatableName());
}

static int GameWorld_get_charactersWithLights(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for charactersWithLights (ogre_unordered_set<Character*>::type)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_sysMessageList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for sysMessageList (std::list<GameWorld::SysMessage, Ogre::STLAllocator<GameWorld::SysMessage, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_updatePortraitsMap(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for updatePortraitsMap (ogre_unordered_map<hand, float>::type)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_dynamicDestroyBuildingsList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for dynamicDestroyBuildingsList (lektor<hand>)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_destroyListAE(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for destroyListAE (ogre_unordered_set<AttachedEntity*>::type)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_destroyListOE(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for destroyListOE (ogre_unordered_set<Ogre::MovableObject*>::type)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_destroyListTBM(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for destroyListTBM (ogre_unordered_set<TownBuildingsManager*>::type)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_frameSpeedMult(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    lua_pushnumber(L, b->frameSpeedMult);
    return 1;
}

static int GameWorld_get_deathParade(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for deathParade (ogre_unordered_map<hand, Character*>::type)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_deathParadeWasMeddledWith(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    lua_pushboolean(L, b->deathParadeWasMeddledWith ? 1 : 0);
    return 1;
}

static int GameWorld_get_charUpdateListMain_inUse(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    lua_pushboolean(L, b->charUpdateListMain_inUse ? 1 : 0);
    return 1;
}

static int GameWorld_get_charUpdateListMain(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for charUpdateListMain (ogre_unordered_set<Character*>::type)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get__AINonRenderThread(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for _AINonRenderThread (RenderTimeBackthread*)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_nestBatcherKillList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for nestBatcherKillList (std::deque<NestBatcher*, Ogre::STLAllocator<NestBatcher*, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_killListPhase0(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for killListPhase0 (ogre_unordered_set<RootObject*>::type)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_killListPhase1(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for killListPhase1 (ogre_unordered_map<RootObject*, float>::type)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_killListPhase2(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for killListPhase2 (std::deque<RootObject*, Ogre::STLAllocator<RootObject*, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_mainUpdateListRemovalQueue(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for mainUpdateListRemovalQueue (lektor<Character*>)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_timeStamper(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for timeStamper (SimpleTimeStamper)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_zoneMgr(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for zoneMgr (ZoneManager*)
    lua_pushnil(L);
    return 1;
}

static int GameWorld_get_debugFlag(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    lua_pushboolean(L, b->debugFlag ? 1 : 0);
    return 1;
}

static int GameWorld_get_paused(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    lua_pushboolean(L, b->paused ? 1 : 0);
    return 1;
}

static int GameWorld_get_gameResetting(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    lua_pushboolean(L, b->gameResetting ? 1 : 0);
    return 1;
}

static int GameWorld_get_audioThread(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    // TODO: Unsupported type for audioThread (AudioSystemGlobal*)
    lua_pushnil(L);
    return 1;
}

// --- Setters for GameWorld ---
static int GameWorld_set_tempSpawnsDisableTimer(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    b->tempSpawnsDisableTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameWorld_set_initialized(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    b->initialized = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameWorld_set_render(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for render");
}

static int GameWorld_set_physics(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for physics");
}

static int GameWorld_set_gamedata(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for gamedata");
}

static int GameWorld_set_leveldata(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for leveldata");
}

static int GameWorld_set_savedata(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for savedata");
}

static int GameWorld_set_theFactory(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for theFactory");
}

static int GameWorld_set_factionMgr(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for factionMgr");
}

static int GameWorld_set_navmesh(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for navmesh");
}

static int GameWorld_set_nodeList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for nodeList");
}

static int GameWorld_set_guiDisplayObject(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for guiDisplayObject");
}

static int GameWorld_set_messageRoller(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for messageRoller");
}

static int GameWorld_set_ogreLogger(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for ogreLogger");
}

static int GameWorld_set_steamEnabled(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    b->steamEnabled = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameWorld_set_baseMods(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for baseMods");
}

static int GameWorld_set_baseModsNames(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for baseModsNames");
}

static int GameWorld_set_activeMods(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for activeMods");
}

static int GameWorld_set_availableModsByName(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for availableModsByName");
}

static int GameWorld_set_availabelModsOrderedList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for availabelModsOrderedList");
}

static int GameWorld_set_player(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for player");
}

static int GameWorld_set_charactersWithLights(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for charactersWithLights");
}

static int GameWorld_set_sysMessageList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for sysMessageList");
}

static int GameWorld_set_updatePortraitsMap(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for updatePortraitsMap");
}

static int GameWorld_set_dynamicDestroyBuildingsList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for dynamicDestroyBuildingsList");
}

static int GameWorld_set_destroyListAE(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for destroyListAE");
}

static int GameWorld_set_destroyListOE(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for destroyListOE");
}

static int GameWorld_set_destroyListTBM(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for destroyListTBM");
}

static int GameWorld_set_frameSpeedMult(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    b->frameSpeedMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameWorld_set_deathParade(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for deathParade");
}

static int GameWorld_set_deathParadeWasMeddledWith(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    b->deathParadeWasMeddledWith = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameWorld_set_charUpdateListMain_inUse(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    b->charUpdateListMain_inUse = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameWorld_set_charUpdateListMain(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for charUpdateListMain");
}

static int GameWorld_set__AINonRenderThread(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _AINonRenderThread");
}

static int GameWorld_set_nestBatcherKillList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for nestBatcherKillList");
}

static int GameWorld_set_killListPhase0(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for killListPhase0");
}

static int GameWorld_set_killListPhase1(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for killListPhase1");
}

static int GameWorld_set_killListPhase2(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for killListPhase2");
}

static int GameWorld_set_mainUpdateListRemovalQueue(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for mainUpdateListRemovalQueue");
}

static int GameWorld_set_timeStamper(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for timeStamper");
}

static int GameWorld_set_zoneMgr(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for zoneMgr");
}

static int GameWorld_set_debugFlag(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    b->debugFlag = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameWorld_set_paused(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    b->paused = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameWorld_set_gameResetting(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    b->gameResetting = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameWorld_set_audioThread(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");
    return luaL_error(L, "Read-only or unsupported setter type for audioThread");
}

int GameWorldBinding::startUpThreads(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    bool result = b->startUpThreads();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::_CONSTRUCTOR(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    GameWorld* result = b->_CONSTRUCTOR();
    return pushObject<GameWorld>(L, result, GameWorldBinding::getMetatableName());
}

int GameWorldBinding::_DESTRUCTOR(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->_DESTRUCTOR();
    return 0;
}

int GameWorldBinding::resetGame(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->resetGame();
    return 0;
}

int GameWorldBinding::_clearAndDestroyGameWorldStuff(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->_clearAndDestroyGameWorldStuff();
    return 0;
}

int GameWorldBinding::initialisation(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    bool result = b->initialisation();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::initialisationGameData(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    bool result = b->initialisationGameData();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::dailyUpdates(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->dailyUpdates();
    return 0;
}

int GameWorldBinding::errorToLogReleaseMode(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    std::string msg = luaL_checkstring(L, 2);
    b->errorToLogReleaseMode(msg);
    return 0;
}

int GameWorldBinding::errorD(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    std::string msg = luaL_checkstring(L, 2);
    b->errorD(msg);
    return 0;
}

int GameWorldBinding::logToSave(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    std::string msg = luaL_checkstring(L, 2);
    b->logToSave(msg);
    return 0;
}

int GameWorldBinding::log(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    std::string line = luaL_checkstring(L, 2);
    b->log(line);
    return 0;
}

int GameWorldBinding::flushKillList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->flushKillList();
    return 0;
}

int GameWorldBinding::allThreadQueuesAreClear(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    bool result = b->allThreadQueuesAreClear();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::initBaseMods(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->initBaseMods();
    return 0;
}

int GameWorldBinding::initModsList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->initModsList();
    return 0;
}

int GameWorldBinding::getModIndex(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    std::string modName = luaL_checkstring(L, 2);
    int result = b->getModIndex(modName);
    lua_pushinteger(L, result);
    return 1;
}

int GameWorldBinding::getLightLevel(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    int floor = (int)luaL_checkinteger(L, 3);
    bool inside = lua_toboolean(L, 4) != 0;
    float result = b->getLightLevel(position, floor, inside);
    lua_pushnumber(L, result);
    return 1;
}

int GameWorldBinding::findValidSpawnPos(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Ogre::Vector3 centerArea;
    readVector3(L, 3, centerArea);
    bool result = b->findValidSpawnPos(pos, centerArea);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::togglePause(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->togglePause(on);
    return 0;
}

int GameWorldBinding::getFrameSpeedMultiplier(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    float result = b->getFrameSpeedMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int GameWorldBinding::setFrameSpeedMultiplier(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    float m = (float)luaL_checknumber(L, 2);
    b->setFrameSpeedMultiplier(m);
    return 0;
}

int GameWorldBinding::setGameSpeed(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    float speed = (float)luaL_checknumber(L, 2);
    bool click = lua_toboolean(L, 3) != 0;
    b->setGameSpeed(speed, click);
    return 0;
}

int GameWorldBinding::userPause(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    bool p = lua_toboolean(L, 2) != 0;
    b->userPause(p);
    return 0;
}

int GameWorldBinding::isPaused(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    bool result = b->isPaused();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::getCameraCenter(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    Ogre::Vector3 result = b->getCameraCenter();
    pushVector3(L, result);
    return 1;
}

int GameWorldBinding::getCameraPos(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    Ogre::Vector3 result = b->getCameraPos();
    pushVector3(L, result);
    return 1;
}

int GameWorldBinding::fixNaNPosition(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    bool result = b->fixNaNPosition(pos);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::getWindSpeed(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    float result = b->getWindSpeed(pos);
    lua_pushnumber(L, result);
    return 1;
}

int GameWorldBinding::isLoadingFromASaveGame(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    bool result = b->isLoadingFromASaveGame();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameWorldBinding::hideContextMenu(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->hideContextMenu();
    return 0;
}

int GameWorldBinding::showPlayerAMessage_withLog(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    std::string message = luaL_checkstring(L, 2);
    bool queued = lua_toboolean(L, 3) != 0;
    b->showPlayerAMessage_withLog(message, queued);
    return 0;
}

int GameWorldBinding::showPlayerAMessage(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    std::string message = luaL_checkstring(L, 2);
    bool queued = lua_toboolean(L, 3) != 0;
    b->showPlayerAMessage(message, queued);
    return 0;
}

int GameWorldBinding::showPlayerAMessageD(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    std::string message = luaL_checkstring(L, 2);
    bool queued = lua_toboolean(L, 3) != 0;
    b->showPlayerAMessageD(message, queued);
    return 0;
}

int GameWorldBinding::mainLoop_GPUSensitiveStuff(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->mainLoop_GPUSensitiveStuff(time);
    return 0;
}

int GameWorldBinding::_NV_mainLoop_GPUSensitiveStuff(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->_NV_mainLoop_GPUSensitiveStuff(time);
    return 0;
}

int GameWorldBinding::clearPortaitsUpdate(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->clearPortaitsUpdate();
    return 0;
}

int GameWorldBinding::processSysMessages(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->processSysMessages();
    return 0;
}

int GameWorldBinding::destroyDeathParade(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->destroyDeathParade();
    return 0;
}

int GameWorldBinding::processKeys(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->processKeys();
    return 0;
}

int GameWorldBinding::processThreadMessages(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->processThreadMessages();
    return 0;
}

int GameWorldBinding::charsUpdate(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->charsUpdate();
    return 0;
}

int GameWorldBinding::charsUpdateUT(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->charsUpdateUT();
    return 0;
}

int GameWorldBinding::charsUpdatePaused(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->charsUpdatePaused();
    return 0;
}

int GameWorldBinding::charsUpdateDeathParade(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->charsUpdateDeathParade();
    return 0;
}

int GameWorldBinding::threadSafeRagdollUpdates(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->threadSafeRagdollUpdates();
    return 0;
}

int GameWorldBinding::processAttachmentsKillList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->processAttachmentsKillList();
    return 0;
}

int GameWorldBinding::processKillList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    bool forceImmediate = lua_toboolean(L, 2) != 0;
    b->processKillList(forceImmediate);
    return 0;
}

int GameWorldBinding::processUpdateRemovalList(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->processUpdateRemovalList();
    return 0;
}

int GameWorldBinding::loadAllPlatoons(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->loadAllPlatoons();
    return 0;
}

int GameWorldBinding::reCalculateFortificationInsideOutsideStateForAllCharacters(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    b->reCalculateFortificationInsideOutsideStateForAllCharacters();
    return 0;
}

int GameWorldBinding::getTimeStamp(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    double result = b->getTimeStamp();
    lua_pushnumber(L, result);
    return 1;
}

int GameWorldBinding::getTimeFromStamp_inGameHours(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    double stamp = (double)luaL_checknumber(L, 2);
    float result = b->getTimeFromStamp_inGameHours(stamp);
    lua_pushnumber(L, result);
    return 1;
}

int GameWorldBinding::getLengthOfHourInRealSeconds(lua_State* L)
{
    GameWorld* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameWorld is nil");

    float result = b->getLengthOfHourInRealSeconds();
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
  line 124: void populateMapArea_nonPermanent(...) - unsupported arg type
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
        { "getLightLevel", GameWorldBinding::getLightLevel },
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
    lua_pushcfunction(L, GameWorld_get_tempSpawnsDisableTimer);
    lua_setfield(L, -2, "tempSpawnsDisableTimer");
    lua_pushcfunction(L, GameWorld_get_initialized);
    lua_setfield(L, -2, "initialized");
    lua_pushcfunction(L, GameWorld_get_render);
    lua_setfield(L, -2, "render");
    lua_pushcfunction(L, GameWorld_get_physics);
    lua_setfield(L, -2, "physics");
    lua_pushcfunction(L, GameWorld_get_gamedata);
    lua_setfield(L, -2, "gamedata");
    lua_pushcfunction(L, GameWorld_get_leveldata);
    lua_setfield(L, -2, "leveldata");
    lua_pushcfunction(L, GameWorld_get_savedata);
    lua_setfield(L, -2, "savedata");
    lua_pushcfunction(L, GameWorld_get_theFactory);
    lua_setfield(L, -2, "theFactory");
    lua_pushcfunction(L, GameWorld_get_factionMgr);
    lua_setfield(L, -2, "factionMgr");
    lua_pushcfunction(L, GameWorld_get_navmesh);
    lua_setfield(L, -2, "navmesh");
    lua_pushcfunction(L, GameWorld_get_nodeList);
    lua_setfield(L, -2, "nodeList");
    lua_pushcfunction(L, GameWorld_get_guiDisplayObject);
    lua_setfield(L, -2, "guiDisplayObject");
    lua_pushcfunction(L, GameWorld_get_messageRoller);
    lua_setfield(L, -2, "messageRoller");
    lua_pushcfunction(L, GameWorld_get_ogreLogger);
    lua_setfield(L, -2, "ogreLogger");
    lua_pushcfunction(L, GameWorld_get_steamEnabled);
    lua_setfield(L, -2, "steamEnabled");
    lua_pushcfunction(L, GameWorld_get_baseMods);
    lua_setfield(L, -2, "baseMods");
    lua_pushcfunction(L, GameWorld_get_baseModsNames);
    lua_setfield(L, -2, "baseModsNames");
    lua_pushcfunction(L, GameWorld_get_activeMods);
    lua_setfield(L, -2, "activeMods");
    lua_pushcfunction(L, GameWorld_get_availableModsByName);
    lua_setfield(L, -2, "availableModsByName");
    lua_pushcfunction(L, GameWorld_get_availabelModsOrderedList);
    lua_setfield(L, -2, "availabelModsOrderedList");
    lua_pushcfunction(L, GameWorld_get_player);
    lua_setfield(L, -2, "player");
    lua_pushcfunction(L, GameWorld_get_charactersWithLights);
    lua_setfield(L, -2, "charactersWithLights");
    lua_pushcfunction(L, GameWorld_get_sysMessageList);
    lua_setfield(L, -2, "sysMessageList");
    lua_pushcfunction(L, GameWorld_get_updatePortraitsMap);
    lua_setfield(L, -2, "updatePortraitsMap");
    lua_pushcfunction(L, GameWorld_get_dynamicDestroyBuildingsList);
    lua_setfield(L, -2, "dynamicDestroyBuildingsList");
    lua_pushcfunction(L, GameWorld_get_destroyListAE);
    lua_setfield(L, -2, "destroyListAE");
    lua_pushcfunction(L, GameWorld_get_destroyListOE);
    lua_setfield(L, -2, "destroyListOE");
    lua_pushcfunction(L, GameWorld_get_destroyListTBM);
    lua_setfield(L, -2, "destroyListTBM");
    lua_pushcfunction(L, GameWorld_get_frameSpeedMult);
    lua_setfield(L, -2, "frameSpeedMult");
    lua_pushcfunction(L, GameWorld_get_deathParade);
    lua_setfield(L, -2, "deathParade");
    lua_pushcfunction(L, GameWorld_get_deathParadeWasMeddledWith);
    lua_setfield(L, -2, "deathParadeWasMeddledWith");
    lua_pushcfunction(L, GameWorld_get_charUpdateListMain_inUse);
    lua_setfield(L, -2, "charUpdateListMain_inUse");
    lua_pushcfunction(L, GameWorld_get_charUpdateListMain);
    lua_setfield(L, -2, "charUpdateListMain");
    lua_pushcfunction(L, GameWorld_get__AINonRenderThread);
    lua_setfield(L, -2, "_AINonRenderThread");
    lua_pushcfunction(L, GameWorld_get_nestBatcherKillList);
    lua_setfield(L, -2, "nestBatcherKillList");
    lua_pushcfunction(L, GameWorld_get_killListPhase0);
    lua_setfield(L, -2, "killListPhase0");
    lua_pushcfunction(L, GameWorld_get_killListPhase1);
    lua_setfield(L, -2, "killListPhase1");
    lua_pushcfunction(L, GameWorld_get_killListPhase2);
    lua_setfield(L, -2, "killListPhase2");
    lua_pushcfunction(L, GameWorld_get_mainUpdateListRemovalQueue);
    lua_setfield(L, -2, "mainUpdateListRemovalQueue");
    lua_pushcfunction(L, GameWorld_get_timeStamper);
    lua_setfield(L, -2, "timeStamper");
    lua_pushcfunction(L, GameWorld_get_zoneMgr);
    lua_setfield(L, -2, "zoneMgr");
    lua_pushcfunction(L, GameWorld_get_debugFlag);
    lua_setfield(L, -2, "debugFlag");
    lua_pushcfunction(L, GameWorld_get_paused);
    lua_setfield(L, -2, "paused");
    lua_pushcfunction(L, GameWorld_get_gameResetting);
    lua_setfield(L, -2, "gameResetting");
    lua_pushcfunction(L, GameWorld_get_audioThread);
    lua_setfield(L, -2, "audioThread");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, GameWorld_set_tempSpawnsDisableTimer);
    lua_setfield(L, -2, "tempSpawnsDisableTimer");
    lua_pushcfunction(L, GameWorld_set_initialized);
    lua_setfield(L, -2, "initialized");
    lua_pushcfunction(L, GameWorld_set_render);
    lua_setfield(L, -2, "render");
    lua_pushcfunction(L, GameWorld_set_physics);
    lua_setfield(L, -2, "physics");
    lua_pushcfunction(L, GameWorld_set_gamedata);
    lua_setfield(L, -2, "gamedata");
    lua_pushcfunction(L, GameWorld_set_leveldata);
    lua_setfield(L, -2, "leveldata");
    lua_pushcfunction(L, GameWorld_set_savedata);
    lua_setfield(L, -2, "savedata");
    lua_pushcfunction(L, GameWorld_set_theFactory);
    lua_setfield(L, -2, "theFactory");
    lua_pushcfunction(L, GameWorld_set_factionMgr);
    lua_setfield(L, -2, "factionMgr");
    lua_pushcfunction(L, GameWorld_set_navmesh);
    lua_setfield(L, -2, "navmesh");
    lua_pushcfunction(L, GameWorld_set_nodeList);
    lua_setfield(L, -2, "nodeList");
    lua_pushcfunction(L, GameWorld_set_guiDisplayObject);
    lua_setfield(L, -2, "guiDisplayObject");
    lua_pushcfunction(L, GameWorld_set_messageRoller);
    lua_setfield(L, -2, "messageRoller");
    lua_pushcfunction(L, GameWorld_set_ogreLogger);
    lua_setfield(L, -2, "ogreLogger");
    lua_pushcfunction(L, GameWorld_set_steamEnabled);
    lua_setfield(L, -2, "steamEnabled");
    lua_pushcfunction(L, GameWorld_set_baseMods);
    lua_setfield(L, -2, "baseMods");
    lua_pushcfunction(L, GameWorld_set_baseModsNames);
    lua_setfield(L, -2, "baseModsNames");
    lua_pushcfunction(L, GameWorld_set_activeMods);
    lua_setfield(L, -2, "activeMods");
    lua_pushcfunction(L, GameWorld_set_availableModsByName);
    lua_setfield(L, -2, "availableModsByName");
    lua_pushcfunction(L, GameWorld_set_availabelModsOrderedList);
    lua_setfield(L, -2, "availabelModsOrderedList");
    lua_pushcfunction(L, GameWorld_set_player);
    lua_setfield(L, -2, "player");
    lua_pushcfunction(L, GameWorld_set_charactersWithLights);
    lua_setfield(L, -2, "charactersWithLights");
    lua_pushcfunction(L, GameWorld_set_sysMessageList);
    lua_setfield(L, -2, "sysMessageList");
    lua_pushcfunction(L, GameWorld_set_updatePortraitsMap);
    lua_setfield(L, -2, "updatePortraitsMap");
    lua_pushcfunction(L, GameWorld_set_dynamicDestroyBuildingsList);
    lua_setfield(L, -2, "dynamicDestroyBuildingsList");
    lua_pushcfunction(L, GameWorld_set_destroyListAE);
    lua_setfield(L, -2, "destroyListAE");
    lua_pushcfunction(L, GameWorld_set_destroyListOE);
    lua_setfield(L, -2, "destroyListOE");
    lua_pushcfunction(L, GameWorld_set_destroyListTBM);
    lua_setfield(L, -2, "destroyListTBM");
    lua_pushcfunction(L, GameWorld_set_frameSpeedMult);
    lua_setfield(L, -2, "frameSpeedMult");
    lua_pushcfunction(L, GameWorld_set_deathParade);
    lua_setfield(L, -2, "deathParade");
    lua_pushcfunction(L, GameWorld_set_deathParadeWasMeddledWith);
    lua_setfield(L, -2, "deathParadeWasMeddledWith");
    lua_pushcfunction(L, GameWorld_set_charUpdateListMain_inUse);
    lua_setfield(L, -2, "charUpdateListMain_inUse");
    lua_pushcfunction(L, GameWorld_set_charUpdateListMain);
    lua_setfield(L, -2, "charUpdateListMain");
    lua_pushcfunction(L, GameWorld_set__AINonRenderThread);
    lua_setfield(L, -2, "_AINonRenderThread");
    lua_pushcfunction(L, GameWorld_set_nestBatcherKillList);
    lua_setfield(L, -2, "nestBatcherKillList");
    lua_pushcfunction(L, GameWorld_set_killListPhase0);
    lua_setfield(L, -2, "killListPhase0");
    lua_pushcfunction(L, GameWorld_set_killListPhase1);
    lua_setfield(L, -2, "killListPhase1");
    lua_pushcfunction(L, GameWorld_set_killListPhase2);
    lua_setfield(L, -2, "killListPhase2");
    lua_pushcfunction(L, GameWorld_set_mainUpdateListRemovalQueue);
    lua_setfield(L, -2, "mainUpdateListRemovalQueue");
    lua_pushcfunction(L, GameWorld_set_timeStamper);
    lua_setfield(L, -2, "timeStamper");
    lua_pushcfunction(L, GameWorld_set_zoneMgr);
    lua_setfield(L, -2, "zoneMgr");
    lua_pushcfunction(L, GameWorld_set_debugFlag);
    lua_setfield(L, -2, "debugFlag");
    lua_pushcfunction(L, GameWorld_set_paused);
    lua_setfield(L, -2, "paused");
    lua_pushcfunction(L, GameWorld_set_gameResetting);
    lua_setfield(L, -2, "gameResetting");
    lua_pushcfunction(L, GameWorld_set_audioThread);
    lua_setfield(L, -2, "audioThread");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua