#include "pch.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/ZoneManagerInterfaceTBinding.h"

#include <kenshi/ZoneManager.h>
#include "ZoneManagerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ZoneManager* getInstance(lua_State* L, int idx)
{
    return checkObject<ZoneManager>(L, idx, ZoneManagerBinding::getMetatableName());
}

// --- Getters for ZoneManager ---
static int ZoneManager_get_justLoadedAGame(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    lua_pushboolean(L, instance->justLoadedAGame ? 1 : 0);
    return 1;
}

static int ZoneManager_get__needCalculateIslands(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    lua_pushboolean(L, instance->_needCalculateIslands ? 1 : 0);
    return 1;
}

static int ZoneManager_get_spawnUpdateTimerMT(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    lua_pushnumber(L, instance->spawnUpdateTimerMT);
    return 1;
}

static int ZoneManager_get_spawnUpdateTimerTT(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    lua_pushnumber(L, instance->spawnUpdateTimerTT);
    return 1;
}

static int ZoneManager_get_centralZone(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    lua_pushlightuserdata(L, (void*)instance->centralZone);
    return 1;
}

static int ZoneManager_get_loadingPhase(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    lua_pushinteger(L, instance->loadingPhase);
    return 1;
}

static int ZoneManager_get_biomeMap(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    lua_pushlightuserdata(L, (void*)instance->biomeMap);
    return 1;
}

// --- Setters for ZoneManager ---
static int ZoneManager_set_justLoadedAGame(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    instance->justLoadedAGame = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ZoneManager_set__needCalculateIslands(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    instance->_needCalculateIslands = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ZoneManager_set_spawnUpdateTimerMT(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    instance->spawnUpdateTimerMT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ZoneManager_set_spawnUpdateTimerTT(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    instance->spawnUpdateTimerTT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ZoneManager_set_loadingPhase(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    instance->loadingPhase = (int)luaL_checkinteger(L, 2);
    return 0;
}

int ZoneManagerBinding::_CONSTRUCTOR(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    ZoneManager* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ZoneManagerBinding::_DESTRUCTOR(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ZoneManagerBinding::isZoneLoadedT(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    bool result = instance->isZoneLoadedT(pos);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneManagerBinding::_NV_isZoneLoadedT(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    bool result = instance->_NV_isZoneLoadedT(pos);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneManagerBinding::isZoneBeingLoadedT(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    bool result = instance->isZoneBeingLoadedT(pos);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneManagerBinding::_NV_isZoneBeingLoadedT(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    bool result = instance->_NV_isZoneBeingLoadedT(pos);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneManagerBinding::getNumActiveZones(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    int result = instance->getNumActiveZones();
    lua_pushinteger(L, result);
    return 1;
}

int ZoneManagerBinding::setup(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->setup();
    return 0;
}

int ZoneManagerBinding::updateMainThread(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 camerapos;
    readVector3(L, 2, camerapos);
    instance->updateMainThread(camerapos);
    return 0;
}

int ZoneManagerBinding::updateRendertimeThread(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 camerapos;
    readVector3(L, 2, camerapos);
    instance->updateRendertimeThread(camerapos);
    return 0;
}

int ZoneManagerBinding::updateGPUSafeThread(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 camerapos;
    readVector3(L, 2, camerapos);
    instance->updateGPUSafeThread(camerapos);
    return 0;
}

int ZoneManagerBinding::spawnChecksUpdateThreaded(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    int island = (int)luaL_checkinteger(L, 2);
    instance->spawnChecksUpdateThreaded(island);
    return 0;
}

int ZoneManagerBinding::levelEditorDeleteAllSelectedObjects(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->levelEditorDeleteAllSelectedObjects();
    return 0;
}

int ZoneManagerBinding::getCurrentZoneMap(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    ZoneMap* result = instance->getCurrentZoneMap();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ZoneManagerBinding::playerActivate(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    bool result = instance->playerActivate(pos);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneManagerBinding::getBiome(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    GameData* result = instance->getBiome(position);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int ZoneManagerBinding::getBiomeCode(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    int result = instance->getBiomeCode(position);
    lua_pushinteger(L, result);
    return 1;
}

int ZoneManagerBinding::getBiomeMap(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    const BiomeMap* result = instance->getBiomeMap();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ZoneManagerBinding::getGroundTypeIndex(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    int result = instance->getGroundTypeIndex(pos);
    lua_pushinteger(L, result);
    return 1;
}

int ZoneManagerBinding::getGroundType(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    GroundType result = instance->getGroundType(pos);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ZoneManagerBinding::shiftGroundEffects(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 shift;
    readVector3(L, 2, shift);
    instance->shiftGroundEffects(shift);
    return 0;
}

int ZoneManagerBinding::checkZoneFiles(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    bool result = instance->checkZoneFiles();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneManagerBinding::resetStates(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->resetStates();
    return 0;
}

int ZoneManagerBinding::getResourceId(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    MiningResource resource = (MiningResource)luaL_checkinteger(L, 2);
    std::string result = instance->getResourceId(resource);
    lua_pushstring(L, result.c_str());
    return 1;
}

int ZoneManagerBinding::getResourceName(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    MiningResource resource = (MiningResource)luaL_checkinteger(L, 2);
    std::string result = instance->getResourceName(resource);
    lua_pushstring(L, result.c_str());
    return 1;
}

int ZoneManagerBinding::saveMapFeatures(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    bool result = instance->saveMapFeatures();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneManagerBinding::saveLevelData(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    std::string path = luaL_checkstring(L, 2);
    std::string modName = luaL_checkstring(L, 3);
    instance->saveLevelData(path, modName);
    return 0;
}

int ZoneManagerBinding::saveActiveZoneStates(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->saveActiveZoneStates();
    return 0;
}

int ZoneManagerBinding::resetGame(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->resetGame();
    return 0;
}

int ZoneManagerBinding::deactivateAllActiveZones(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->deactivateAllActiveZones();
    return 0;
}

int ZoneManagerBinding::activateAllActiveZones(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->activateAllActiveZones();
    return 0;
}

int ZoneManagerBinding::populateTownsForLevelEditor(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->populateTownsForLevelEditor();
    return 0;
}

int ZoneManagerBinding::calculateIslands(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->calculateIslands();
    return 0;
}

int ZoneManagerBinding::_reloadAllFoliage(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->_reloadAllFoliage();
    return 0;
}

int ZoneManagerBinding::_reloadGroundTextures(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->_reloadGroundTextures();
    return 0;
}

int ZoneManagerBinding::_unloadAllZones(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->_unloadAllZones();
    return 0;
}

int ZoneManagerBinding::getCentralZone(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    ZoneMap* result = instance->getCentralZone();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ZoneManagerBinding::isLoading(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    int result = instance->isLoading();
    lua_pushinteger(L, result);
    return 1;
}

int ZoneManagerBinding::_calculateIslands(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->_calculateIslands();
    return 0;
}

int ZoneManagerBinding::loadFeatures(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->loadFeatures();
    return 0;
}

int ZoneManagerBinding::loadDistantTowns(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->loadDistantTowns();
    return 0;
}

int ZoneManagerBinding::processLoading(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    bool result = instance->processLoading();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneManagerBinding::loadPhase1(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->loadPhase1();
    return 0;
}

int ZoneManagerBinding::loadPhase2(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->loadPhase2();
    return 0;
}

int ZoneManagerBinding::loadPhase3(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    instance->loadPhase3();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 329: AABB2D getZoneBoundsT(...) - overloaded method
  line 330: AABB2D _NV_getZoneBoundsT(...) - overloaded method
  line 331: AABB2D getZoneBoundsT(...) - overloaded method
  line 332: AABB2D _NV_getZoneBoundsT(...) - overloaded method
  line 333: void getAllActiveZonesT(...) - unsupported arg type
  line 334: void _NV_getAllActiveZonesT(...) - unsupported arg type
  line 335: void getAllActiveIslandNumbers(...) - unsupported arg type
  line 336: void getAllActiveZones(...) - unsupported arg type
  line 338: Building* findShop(...) - unsupported arg type
  line 339: Building* findAnyShop(...) - unsupported arg type
  line 340: void findBuilding(...) - overloaded method
  line 341: Building* findBuilding(...) - overloaded method
  line 342: void getBuildingsThatLinkTo(...) - unsupported arg type
  line 343: void findAllBuildings(...) - unsupported arg type
  line 344: void findOverlappingActiveZones(...) - unsupported arg type
  line 351: void levelEditorGetAllSelectedObjects(...) - unsupported arg type
  line 352: iVector2 getCurrentMapSector(...) - unsupported return type
  line 354: iVector2 getSubMapSector(...) - unsupported return type
  line 355: iVector2 getMapSector(...) - overloaded method
  line 356: iVector2 getMapSector(...) - overloaded method
  line 357: Ogre::Vector4 getZoneMapSectorBounds(...) - unsupported return type
  line 358: iVector2 getZoneMapFromResolutionCoord(...) - unsupported return type
  line 359: ZoneMap* getZoneMap(...) - overloaded method
  line 360: ZoneMap* getZoneMap(...) - overloaded method
  line 361: ZoneMap* getZoneMap(...) - overloaded method
  line 362: ZoneMap* getZoneMapFromBuildingHandle(...) - unsupported arg type
  line 364: bool activateZoneMap(...) - overloaded method
  line 365: bool activateZoneMap(...) - overloaded method
  line 366: void deactivateZoneMap(...) - unsupported arg type
  line 367: void getZonesTouchingTown(...) - unsupported arg type
  line 368: const lektor<MapFeatureList*>& getLoadedFeatureLists(...) - reference return type
  line 369: ZoneMapOverlay* getOverlay(...) - unsupported arg type
  line 375: const char* getGroundSound(...) - static method
  line 376: const char* getGroundSound(...) - overloaded method
  line 377: bool getGroundEffect(...) - unsupported arg type
  line 378: void addGroundEffect(...) - unsupported arg type
  line 388: float getResource(...) - unsupported arg type
  line 389: float getResourceBase(...) - unsupported arg type
  line 400: void getIsland(...) - unsupported arg type
  line 405: bool checkForRepopulateTown(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 409: characterGrid (ZoneSpacialGrid) - unsupported type
  line 410: buildingGrid (ZoneSpacialGrid) - unsupported type
  line 411: itemGrid (ZoneSpacialGrid) - unsupported type
  line 425: processingNewActiveZones (ogre_unordered_set<ZoneMap*>::type) - unsupported type
  line 426: activeZones (ogre_unordered_set<ZoneMap*>::type) - unsupported type
  line 427: updatedTownOverrides (ogre_unordered_set<Town*>::type) - unsupported type
  line 429: loadedFeatureLists (lektor<MapFeatureList*>) - unsupported type
  line 431: distantTownList (std::set<Town*, std::less<Town*>, Ogre::STLAllocator<Town*, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 432: distantTownCentre (iVector2) - unsupported type
  line 440: overlays (ogre_unordered_map<iVector2, ZoneMapOverlay*>::type) - unsupported type
  line 442: groundTypes (ogre_unordered_map<int, unsigned char*>::type) - unsupported type
  line 443: groundEffects (ogre_unordered_map<int, ZoneManager::BiomeGroundEffects>::type) - unsupported type
  line 444: groundEffectsPool (ParticlePool) - unsupported type
*/

int ZoneManagerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ZoneManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ZoneManager object");
    return 1;
}

void ZoneManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ZoneManagerBinding::gc },
        { "__tostring", ZoneManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ZoneManagerBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ZoneManagerBinding::_DESTRUCTOR },
        { "isZoneLoadedT", ZoneManagerBinding::isZoneLoadedT },
        { "_NV_isZoneLoadedT", ZoneManagerBinding::_NV_isZoneLoadedT },
        { "isZoneBeingLoadedT", ZoneManagerBinding::isZoneBeingLoadedT },
        { "_NV_isZoneBeingLoadedT", ZoneManagerBinding::_NV_isZoneBeingLoadedT },
        { "getNumActiveZones", ZoneManagerBinding::getNumActiveZones },
        { "setup", ZoneManagerBinding::setup },
        { "updateMainThread", ZoneManagerBinding::updateMainThread },
        { "updateRendertimeThread", ZoneManagerBinding::updateRendertimeThread },
        { "updateGPUSafeThread", ZoneManagerBinding::updateGPUSafeThread },
        { "spawnChecksUpdateThreaded", ZoneManagerBinding::spawnChecksUpdateThreaded },
        { "levelEditorDeleteAllSelectedObjects", ZoneManagerBinding::levelEditorDeleteAllSelectedObjects },
        { "getCurrentZoneMap", ZoneManagerBinding::getCurrentZoneMap },
        { "playerActivate", ZoneManagerBinding::playerActivate },
        { "getBiome", ZoneManagerBinding::getBiome },
        { "getBiomeCode", ZoneManagerBinding::getBiomeCode },
        { "getBiomeMap", ZoneManagerBinding::getBiomeMap },
        { "getGroundTypeIndex", ZoneManagerBinding::getGroundTypeIndex },
        { "getGroundType", ZoneManagerBinding::getGroundType },
        { "shiftGroundEffects", ZoneManagerBinding::shiftGroundEffects },
        { "checkZoneFiles", ZoneManagerBinding::checkZoneFiles },
        { "resetStates", ZoneManagerBinding::resetStates },
        { "getResourceId", ZoneManagerBinding::getResourceId },
        { "getResourceName", ZoneManagerBinding::getResourceName },
        { "saveMapFeatures", ZoneManagerBinding::saveMapFeatures },
        { "saveLevelData", ZoneManagerBinding::saveLevelData },
        { "saveActiveZoneStates", ZoneManagerBinding::saveActiveZoneStates },
        { "resetGame", ZoneManagerBinding::resetGame },
        { "deactivateAllActiveZones", ZoneManagerBinding::deactivateAllActiveZones },
        { "activateAllActiveZones", ZoneManagerBinding::activateAllActiveZones },
        { "populateTownsForLevelEditor", ZoneManagerBinding::populateTownsForLevelEditor },
        { "calculateIslands", ZoneManagerBinding::calculateIslands },
        { "_reloadAllFoliage", ZoneManagerBinding::_reloadAllFoliage },
        { "_reloadGroundTextures", ZoneManagerBinding::_reloadGroundTextures },
        { "_unloadAllZones", ZoneManagerBinding::_unloadAllZones },
        { "getCentralZone", ZoneManagerBinding::getCentralZone },
        { "isLoading", ZoneManagerBinding::isLoading },
        { "_calculateIslands", ZoneManagerBinding::_calculateIslands },
        { "loadFeatures", ZoneManagerBinding::loadFeatures },
        { "loadDistantTowns", ZoneManagerBinding::loadDistantTowns },
        { "processLoading", ZoneManagerBinding::processLoading },
        { "loadPhase1", ZoneManagerBinding::loadPhase1 },
        { "loadPhase2", ZoneManagerBinding::loadPhase2 },
        { "loadPhase3", ZoneManagerBinding::loadPhase3 },
        { 0, 0 }
    };

    registerClass(
        L, 
        ZoneManagerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ZoneManagerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ZoneManager_get_justLoadedAGame);
    lua_setfield(L, -2, "justLoadedAGame");
    lua_pushcfunction(L, ZoneManager_get__needCalculateIslands);
    lua_setfield(L, -2, "_needCalculateIslands");
    lua_pushcfunction(L, ZoneManager_get_spawnUpdateTimerMT);
    lua_setfield(L, -2, "spawnUpdateTimerMT");
    lua_pushcfunction(L, ZoneManager_get_spawnUpdateTimerTT);
    lua_setfield(L, -2, "spawnUpdateTimerTT");
    lua_pushcfunction(L, ZoneManager_get_centralZone);
    lua_setfield(L, -2, "centralZone");
    lua_pushcfunction(L, ZoneManager_get_loadingPhase);
    lua_setfield(L, -2, "loadingPhase");
    lua_pushcfunction(L, ZoneManager_get_biomeMap);
    lua_setfield(L, -2, "biomeMap");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ZoneManager_set_justLoadedAGame);
    lua_setfield(L, -2, "justLoadedAGame");
    lua_pushcfunction(L, ZoneManager_set__needCalculateIslands);
    lua_setfield(L, -2, "_needCalculateIslands");
    lua_pushcfunction(L, ZoneManager_set_spawnUpdateTimerMT);
    lua_setfield(L, -2, "spawnUpdateTimerMT");
    lua_pushcfunction(L, ZoneManager_set_spawnUpdateTimerTT);
    lua_setfield(L, -2, "spawnUpdateTimerTT");
    lua_pushcfunction(L, ZoneManager_set_loadingPhase);
    lua_setfield(L, -2, "loadingPhase");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ZoneManagerInterfaceT
    setMetatableParent(L, ZoneManagerBinding::getMetatableName(), ZoneManagerInterfaceTBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua