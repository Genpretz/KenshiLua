#include "pch.h"
#include "kenshi\ZoneManager.h"
#include "ZoneManagerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/AABB2DBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/OwnershipsBinding.h"
#include "Bindings/ParticlePoolBinding.h"
#include "Bindings/TownBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/ZoneManagerInterfaceTBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "Bindings/ZoneSpacialGridBinding.h"
#include "Bindings/Util/iVector2Binding.h"
#include "Bindings/Util/HandBinding.h"
#include <kenshi/ZoneManager.h>

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

static int ZoneManager_get_characterGrid(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    return pushObject<ZoneSpacialGrid>(L, &instance->characterGrid, ZoneSpacialGridBinding::getMetatableName());
}

static int ZoneManager_get_buildingGrid(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    return pushObject<ZoneSpacialGrid>(L, &instance->buildingGrid, ZoneSpacialGridBinding::getMetatableName());
}

static int ZoneManager_get_itemGrid(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    return pushObject<ZoneSpacialGrid>(L, &instance->itemGrid, ZoneSpacialGridBinding::getMetatableName());
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

static int ZoneManager_get_distantTownCentre(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    return pushObject<iVector2>(L, &instance->distantTownCentre, iVector2Binding::getMetatableName());
}

static int ZoneManager_get_centralZone(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    return pushObject<ZoneMap>(L, instance->centralZone, ZoneMapBinding::getMetatableName());
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

static int ZoneManager_get_groundEffectsPool(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    return pushObject<ParticlePool>(L, &instance->groundEffectsPool, ParticlePoolBinding::getMetatableName());
}

// --- Setters for ZoneManager ---
static int ZoneManager_set_justLoadedAGame(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    instance->justLoadedAGame = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ZoneManager_set_characterGrid(lua_State* L) { return luaL_error(L, "ZoneSpacialGrid property is read-only"); }

static int ZoneManager_set_buildingGrid(lua_State* L) { return luaL_error(L, "ZoneSpacialGrid property is read-only"); }

static int ZoneManager_set_itemGrid(lua_State* L) { return luaL_error(L, "ZoneSpacialGrid property is read-only"); }

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

static int ZoneManager_set_distantTownCentre(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    instance->distantTownCentre = *checkObject<iVector2>(L, 2, iVector2Binding::getMetatableName());
    return 0;
}

static int ZoneManager_set_centralZone(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    instance->centralZone = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    return 0;
}

static int ZoneManager_set_loadingPhase(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    instance->loadingPhase = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ZoneManager_set_groundEffectsPool(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");
    instance->groundEffectsPool = *checkObject<ParticlePool>(L, 2, ParticlePoolBinding::getMetatableName());
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

int ZoneManagerBinding::findShop(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Town* t = checkObject<Town>(L, 2, TownBinding::getMetatableName());
    ItemFunction selling = (ItemFunction)luaL_checkinteger(L, 3);
    Building* result = instance->findShop(t, selling);
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int ZoneManagerBinding::findAnyShop(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Town* t = checkObject<Town>(L, 2, TownBinding::getMetatableName());
    Building* result = instance->findAnyShop(t);
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
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

int ZoneManagerBinding::getCurrentMapSector(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    iVector2 result = instance->getCurrentMapSector();
    return pushValue<iVector2>(L, result, iVector2Binding::getMetatableName());
}

int ZoneManagerBinding::getCurrentZoneMap(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    ZoneMap* result = instance->getCurrentZoneMap();
    return pushObject<ZoneMap>(L, result, ZoneMapBinding::getMetatableName());
}

int ZoneManagerBinding::getSubMapSector(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    float X = (float)luaL_checknumber(L, 2);
    float Z = (float)luaL_checknumber(L, 3);
    iVector2 result = instance->getSubMapSector(X, Z);
    return pushValue<iVector2>(L, result, iVector2Binding::getMetatableName());
}

int ZoneManagerBinding::getZoneMapFromResolutionCoord(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    float X = (float)luaL_checknumber(L, 2);
    float Z = (float)luaL_checknumber(L, 3);
    iVector2 result = instance->getZoneMapFromResolutionCoord(X, Z);
    return pushValue<iVector2>(L, result, iVector2Binding::getMetatableName());
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

int ZoneManagerBinding::deactivateZoneMap(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    ZoneMap* map = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    bool saveZoneState = lua_toboolean(L, 3) != 0;
    instance->deactivateZoneMap(map, saveZoneState);
    return 0;
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

int ZoneManagerBinding::addGroundEffect(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    GameData* effectData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    instance->addGroundEffect(effectData, position);
    return 0;
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

    const std::string path = luaL_checkstring(L, 2);
    const std::string modName = luaL_checkstring(L, 3);
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

int ZoneManagerBinding::checkForRepopulateTown(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Town* t = checkObject<Town>(L, 2, TownBinding::getMetatableName());
    bool result = instance->checkForRepopulateTown(t);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneManagerBinding::getCentralZone(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    ZoneMap* result = instance->getCentralZone();
    return pushObject<ZoneMap>(L, result, ZoneMapBinding::getMetatableName());
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

int ZoneManagerBinding::getGroundSound(lua_State* L)
{
    if (ZoneManager* instance = testObject<ZoneManager>(L, 1, ZoneManagerBinding::getMetatableName()))
    {
        if (lua_isnumber(L, 2))
        {
            GroundType type = (GroundType)luaL_checkinteger(L, 2);
            bool barefoot = lua_toboolean(L, 3) != 0;
            const char* result = ZoneManager::getGroundSound(type, barefoot);
            lua_pushstring(L, result ? result : "");
            return 1;
        }
        else
        {
            Ogre::Vector3 pos;
            readVector3(L, 2, pos);
            const char* result = instance->getGroundSound(pos);
            lua_pushstring(L, result ? result : "");
            return 1;
        }
    }
    else
    {
        GroundType type = (GroundType)luaL_checkinteger(L, 1);
        bool barefoot = lua_toboolean(L, 2) != 0;
        const char* result = ZoneManager::getGroundSound(type, barefoot);
        lua_pushstring(L, result ? result : "");
        return 1;
    }
}

int ZoneManagerBinding::activateZoneMap(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    if (ZoneMap* map = testObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName()))
    {
        iVector2* center = checkObject<iVector2>(L, 3, iVector2Binding::getMetatableName());
        if (!center) return luaL_error(L, "Argument 3 to activateZoneMap must be an iVector2");
        int range = (int)luaL_checkinteger(L, 4);
        ZoneActivationType type = (ZoneActivationType)luaL_checkinteger(L, 5);
        float deactivationTimer = (float)luaL_checknumber(L, 6);
        bool result = instance->activateZoneMap(map, *center, range, type, deactivationTimer);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
    else
    {
        iVector2* co = checkObject<iVector2>(L, 2, iVector2Binding::getMetatableName());
        if (!co) return luaL_error(L, "Argument 2 to activateZoneMap must be ZoneMap or iVector2");
        int range = (int)luaL_checkinteger(L, 3);
        ZoneActivationType playerActivated = (ZoneActivationType)luaL_checkinteger(L, 4);
        bool backThread = lua_toboolean(L, 5) != 0;
        bool result = instance->activateZoneMap(*co, range, playerActivated, backThread);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
}

int ZoneManagerBinding::findBuilding(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    TownBase* t = checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    Faction* f = lua_isnoneornil(L, 3) ? nullptr : checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    bool forSaleOnly = lua_toboolean(L, 4) != 0;
    BuildingFunction fun = (BuildingFunction)luaL_checkinteger(L, 5);
    Ownerships* own = lua_isnoneornil(L, 6) ? nullptr : checkObject<Ownerships>(L, 6, OwnershipsBinding::getMetatableName());

    Building* result = instance->findBuilding(t, f, forSaleOnly, fun, own);
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int ZoneManagerBinding::getAllActiveZones(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    lektor<ZoneMap*> out;
    instance->getAllActiveZones(out);
    lua_newtable(L);
    for (size_t i = 0; i < out.size(); ++i)
    {
        pushObject<ZoneMap>(L, out[i], ZoneMapBinding::getMetatableName());
        lua_rawseti(L, -2, (int)(i + 1));
    }
    return 1;
}

int ZoneManagerBinding::getAllActiveIslandNumbers(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    ogre_unordered_set<int>::type out;
    instance->getAllActiveIslandNumbers(out);
    lua_newtable(L);
    int idx = 1;
    for (ogre_unordered_set<int>::type::const_iterator it = out.begin(); it != out.end(); ++it)
    {
        lua_pushinteger(L, *it);
        lua_rawseti(L, -2, idx++);
    }
    return 1;
}

int ZoneManagerBinding::getZonesTouchingTown(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Town* town = checkObject<Town>(L, 2, TownBinding::getMetatableName());
    if (!town) return luaL_error(L, "Argument 2 to getZonesTouchingTown must be a Town");

    lektor<ZoneMap*> out;
    instance->getZonesTouchingTown(out, town);
    lua_newtable(L);
    for (size_t i = 0; i < out.size(); ++i)
    {
        pushObject<ZoneMap>(L, out[i], ZoneMapBinding::getMetatableName());
        lua_rawseti(L, -2, (int)(i + 1));
    }
    return 1;
}

int ZoneManagerBinding::findOverlappingActiveZones(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    float radius = (float)luaL_checknumber(L, 3);

    lektor<ZoneMap*> out;
    instance->findOverlappingActiveZones(out, pos, radius);
    lua_newtable(L);
    for (size_t i = 0; i < out.size(); ++i)
    {
        pushObject<ZoneMap>(L, out[i], ZoneMapBinding::getMetatableName());
        lua_rawseti(L, -2, (int)(i + 1));
    }
    return 1;
}

int ZoneManagerBinding::getBuildingsThatLinkTo(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    GameData* buildingType = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (!buildingType) return luaL_error(L, "Argument 2 to getBuildingsThatLinkTo must be a GameData");

    lektor<Building*> out;
    instance->getBuildingsThatLinkTo(out, buildingType);
    lua_newtable(L);
    for (size_t i = 0; i < out.size(); ++i)
    {
        pushObject<Building>(L, out[i], BuildingBinding::getMetatableName());
        lua_rawseti(L, -2, (int)(i + 1));
    }
    return 1;
}

int ZoneManagerBinding::findAllBuildings(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    TownBase* t = checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    Faction* f = lua_isnoneornil(L, 3) ? nullptr : checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    bool forSaleOnly = lua_toboolean(L, 4) != 0;
    unsigned int fun = (unsigned int)luaL_checkinteger(L, 5);
    Ownerships* ownership = lua_isnoneornil(L, 6) ? nullptr : checkObject<Ownerships>(L, 6, OwnershipsBinding::getMetatableName());

    lektor<Building*> out;
    instance->findAllBuildings(out, t, f, forSaleOnly, fun, ownership);
    lua_newtable(L);
    for (size_t i = 0; i < out.size(); ++i)
    {
        pushObject<Building>(L, out[i], BuildingBinding::getMetatableName());
        lua_rawseti(L, -2, (int)(i + 1));
    }
    return 1;
}

int ZoneManagerBinding::getResource(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    MiningResource resource = (MiningResource)luaL_checkinteger(L, 2);
    AreaBiomeGroup* biome = (AreaBiomeGroup*)lua_touserdata(L, 3);
    Ogre::Vector3 pos;
    readVector3(L, 4, pos);

    float result = instance->getResource(resource, biome, pos);
    lua_pushnumber(L, result);
    return 1;
}

int ZoneManagerBinding::getResourceBase(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    MiningResource resource = (MiningResource)luaL_checkinteger(L, 2);
    AreaBiomeGroup* biome = (AreaBiomeGroup*)lua_touserdata(L, 3);
    Ogre::Vector3 pos;
    readVector3(L, 4, pos);

    float result = instance->getResourceBase(resource, biome, pos);
    lua_pushnumber(L, result);
    return 1;
}

int ZoneManagerBinding::getGroundEffect(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);

    GameData* effectData = nullptr;
    float minSpeed = 0.0f;
    float probability = 0.0f;

    bool result = instance->getGroundEffect(pos, effectData, minSpeed, probability);
    lua_pushboolean(L, result ? 1 : 0);
    pushObject<GameData>(L, effectData, GameDataBinding::getMetatableName());
    lua_pushnumber(L, minSpeed);
    lua_pushnumber(L, probability);
    return 4;
}

/*
Skipped methods needing manual binding:
  line 333: void getAllActiveZonesT(...) - unsupported arg type
  line 334: void _NV_getAllActiveZonesT(...) - unsupported arg type
  line 351: void levelEditorGetAllSelectedObjects(...) - unsupported arg type
  line 368: const lektor<MapFeatureList*>& getLoadedFeatureLists(...) - reference return type
  line 369: ZoneMapOverlay* getOverlay(...) - non-string reference arg
  line 400: void getIsland(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - ZoneManager_get_biomeMap: BiomeMap* (unbound pointer)
  - ZoneManagerBinding::getBiomeMap: const BiomeMap* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 425: processingNewActiveZones (ogre_unordered_set<ZoneMap*>::type) - unsupported type
  line 426: activeZones (ogre_unordered_set<ZoneMap*>::type) - unsupported type
  line 427: updatedTownOverrides (ogre_unordered_set<Town*>::type) - unsupported type
  line 429: loadedFeatureLists (lektor<MapFeatureList*>) - unsupported type
  line 431: distantTownList (std::set<Town*, std::less<Town*>, Ogre::STLAllocator<Town*, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 440: overlays (ogre_unordered_map<iVector2, ZoneMapOverlay*>::type) - unsupported type
  line 442: groundTypes (ogre_unordered_map<int, unsigned char*>::type) - unsupported type
  line 443: groundEffects (ogre_unordered_map<int, ZoneManager::BiomeGroundEffects>::type) - unsupported type
*/

int ZoneManagerBinding::getMapSector(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    if (lua_gettop(L) >= 3 || lua_isnumber(L, 2))
    {
        float x = (float)luaL_checknumber(L, 2);
        float z = (float)luaL_checknumber(L, 3);
        iVector2 result = instance->getMapSector(x, z);
        return pushValue<iVector2>(L, result, iVector2Binding::getMetatableName());
    }
    else
    {
        Ogre::Vector3 v;
        readVector3(L, 2, v);
        iVector2 result = instance->getMapSector(v);
        return pushValue<iVector2>(L, result, iVector2Binding::getMetatableName());
    }
}

int ZoneManagerBinding::getZoneBoundsT(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    if (lua_istable(L, 2))
    {
        Ogre::Vector3 pos;
        readVector3(L, 2, pos);
        AABB2D result = instance->getZoneBoundsT(pos);
        return pushValue<AABB2D>(L, result, AABB2DBinding::getMetatableName());
    }
    else if (lua_isuserdata(L, 2))
    {
        iVector2* coord = (iVector2*)luaL_testudata(L, 2, iVector2Binding::getMetatableName());
        if (coord)
        {
            AABB2D result = instance->getZoneBoundsT(*coord);
            return pushValue<AABB2D>(L, result, AABB2DBinding::getMetatableName());
        }
        Ogre::Vector3 pos;
        readVector3(L, 2, pos);
        AABB2D result = instance->getZoneBoundsT(pos);
        return pushValue<AABB2D>(L, result, AABB2DBinding::getMetatableName());
    }
    return luaL_error(L, "Argument 2 to getZoneBoundsT must be Vector3 or iVector2");
}

int ZoneManagerBinding::_NV_getZoneBoundsT(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    if (lua_istable(L, 2))
    {
        Ogre::Vector3 pos;
        readVector3(L, 2, pos);
        AABB2D result = instance->_NV_getZoneBoundsT(pos);
        return pushValue<AABB2D>(L, result, AABB2DBinding::getMetatableName());
    }
    else if (lua_isuserdata(L, 2))
    {
        iVector2* coord = (iVector2*)luaL_testudata(L, 2, iVector2Binding::getMetatableName());
        if (coord)
        {
            AABB2D result = instance->_NV_getZoneBoundsT(*coord);
            return pushValue<AABB2D>(L, result, AABB2DBinding::getMetatableName());
        }
        Ogre::Vector3 pos;
        readVector3(L, 2, pos);
        AABB2D result = instance->_NV_getZoneBoundsT(pos);
        return pushValue<AABB2D>(L, result, AABB2DBinding::getMetatableName());
    }
    return luaL_error(L, "Argument 2 to _NV_getZoneBoundsT must be Vector3 or iVector2");
}

int ZoneManagerBinding::getZoneMapSectorBounds(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    iVector2* sector = checkObject<iVector2>(L, 2, iVector2Binding::getMetatableName());
    if (!sector) return luaL_error(L, "Argument 2 to getZoneMapSectorBounds must be iVector2");

    Ogre::Vector4 result = instance->getZoneMapSectorBounds(*sector);
    pushVector4(L, result);
    return 1;
}

int ZoneManagerBinding::getZoneMap(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    ZoneMap* result = nullptr;
    Ogre::Vector3 v;
    if (lua_gettop(L) >= 3 && lua_isnumber(L, 2) && lua_isnumber(L, 3))
    {
        int x = (int)luaL_checkinteger(L, 2);
        int y = (int)luaL_checkinteger(L, 3);
        result = instance->getZoneMap(x, y);
    }
    else if (iVector2* iv = testObject<iVector2>(L, 2, iVector2Binding::getMetatableName()))
    {
        result = instance->getZoneMap(*iv);
    }
    else if (readVector3(L, 2, v))
    {
        result = instance->getZoneMap(v);
    }
    else
    {
        return luaL_error(L, "getZoneMap expected (int, int), (iVector2), or (Vector3)");
    }
    return pushObject<ZoneMap>(L, result, ZoneMapBinding::getMetatableName());
}

int ZoneManagerBinding::getZoneMapFromBuildingHandle(lua_State* L)
{
    ZoneManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManager is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 to getZoneMapFromBuildingHandle must be a hand");

    ZoneMap* result = instance->getZoneMapFromBuildingHandle(*h);
    return pushObject<ZoneMap>(L, result, ZoneMapBinding::getMetatableName());
}

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
        { "isZoneLoadedT", ZoneManagerBinding::isZoneLoadedT },
        { "_NV_isZoneLoadedT", ZoneManagerBinding::_NV_isZoneLoadedT },
        { "isZoneBeingLoadedT", ZoneManagerBinding::isZoneBeingLoadedT },
        { "_NV_isZoneBeingLoadedT", ZoneManagerBinding::_NV_isZoneBeingLoadedT },
        { "getNumActiveZones", ZoneManagerBinding::getNumActiveZones },
        { "findShop", ZoneManagerBinding::findShop },
        { "findAnyShop", ZoneManagerBinding::findAnyShop },
        { "setup", ZoneManagerBinding::setup },
        { "updateMainThread", ZoneManagerBinding::updateMainThread },
        { "updateRendertimeThread", ZoneManagerBinding::updateRendertimeThread },
        { "updateGPUSafeThread", ZoneManagerBinding::updateGPUSafeThread },
        { "spawnChecksUpdateThreaded", ZoneManagerBinding::spawnChecksUpdateThreaded },
        { "levelEditorDeleteAllSelectedObjects", ZoneManagerBinding::levelEditorDeleteAllSelectedObjects },
        { "getCurrentMapSector", ZoneManagerBinding::getCurrentMapSector },
        { "getCurrentZoneMap", ZoneManagerBinding::getCurrentZoneMap },
        { "getSubMapSector", ZoneManagerBinding::getSubMapSector },
        { "getZoneMapFromResolutionCoord", ZoneManagerBinding::getZoneMapFromResolutionCoord },
        { "playerActivate", ZoneManagerBinding::playerActivate },
        { "deactivateZoneMap", ZoneManagerBinding::deactivateZoneMap },
        { "getBiome", ZoneManagerBinding::getBiome },
        { "getBiomeCode", ZoneManagerBinding::getBiomeCode },
        { "getBiomeMap", ZoneManagerBinding::getBiomeMap },
        { "getGroundTypeIndex", ZoneManagerBinding::getGroundTypeIndex },
        { "getGroundType", ZoneManagerBinding::getGroundType },
        { "addGroundEffect", ZoneManagerBinding::addGroundEffect },
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
        { "checkForRepopulateTown", ZoneManagerBinding::checkForRepopulateTown },
        { "getCentralZone", ZoneManagerBinding::getCentralZone },
        { "isLoading", ZoneManagerBinding::isLoading },
        { "_calculateIslands", ZoneManagerBinding::_calculateIslands },
        { "loadFeatures", ZoneManagerBinding::loadFeatures },
        { "loadDistantTowns", ZoneManagerBinding::loadDistantTowns },
        { "processLoading", ZoneManagerBinding::processLoading },
        { "loadPhase1", ZoneManagerBinding::loadPhase1 },
        { "loadPhase2", ZoneManagerBinding::loadPhase2 },
        { "loadPhase3", ZoneManagerBinding::loadPhase3 },
        { "getMapSector", ZoneManagerBinding::getMapSector },
        { "getZoneBoundsT", ZoneManagerBinding::getZoneBoundsT },
        { "_NV_getZoneBoundsT", ZoneManagerBinding::_NV_getZoneBoundsT },
        { "getZoneMapSectorBounds", ZoneManagerBinding::getZoneMapSectorBounds },
        { "getZoneMap", ZoneManagerBinding::getZoneMap },
        { "getZoneMapFromBuildingHandle", ZoneManagerBinding::getZoneMapFromBuildingHandle },
        { "getGroundSound", ZoneManagerBinding::getGroundSound },
        { "activateZoneMap", ZoneManagerBinding::activateZoneMap },
        { "findBuilding", ZoneManagerBinding::findBuilding },
        { "getAllActiveZones", ZoneManagerBinding::getAllActiveZones },
        { "getAllActiveIslandNumbers", ZoneManagerBinding::getAllActiveIslandNumbers },
        { "getZonesTouchingTown", ZoneManagerBinding::getZonesTouchingTown },
        { "findOverlappingActiveZones", ZoneManagerBinding::findOverlappingActiveZones },
        { "getBuildingsThatLinkTo", ZoneManagerBinding::getBuildingsThatLinkTo },
        { "findAllBuildings", ZoneManagerBinding::findAllBuildings },
        { "getResource", ZoneManagerBinding::getResource },
        { "getResourceBase", ZoneManagerBinding::getResourceBase },
        { "getGroundEffect", ZoneManagerBinding::getGroundEffect },
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
    registerGetter(L, "justLoadedAGame", ZoneManager_get_justLoadedAGame);
    registerGetter(L, "characterGrid", ZoneManager_get_characterGrid);
    registerGetter(L, "buildingGrid", ZoneManager_get_buildingGrid);
    registerGetter(L, "itemGrid", ZoneManager_get_itemGrid);
    registerGetter(L, "_needCalculateIslands", ZoneManager_get__needCalculateIslands);
    registerGetter(L, "spawnUpdateTimerMT", ZoneManager_get_spawnUpdateTimerMT);
    registerGetter(L, "spawnUpdateTimerTT", ZoneManager_get_spawnUpdateTimerTT);
    registerGetter(L, "distantTownCentre", ZoneManager_get_distantTownCentre);
    registerGetter(L, "centralZone", ZoneManager_get_centralZone);
    registerGetter(L, "loadingPhase", ZoneManager_get_loadingPhase);
    registerGetter(L, "biomeMap", ZoneManager_get_biomeMap);
    registerGetter(L, "groundEffectsPool", ZoneManager_get_groundEffectsPool);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "justLoadedAGame", ZoneManager_set_justLoadedAGame);
    registerSetter(L, "characterGrid", ZoneManager_set_characterGrid);
    registerSetter(L, "buildingGrid", ZoneManager_set_buildingGrid);
    registerSetter(L, "itemGrid", ZoneManager_set_itemGrid);
    registerSetter(L, "_needCalculateIslands", ZoneManager_set__needCalculateIslands);
    registerSetter(L, "spawnUpdateTimerMT", ZoneManager_set_spawnUpdateTimerMT);
    registerSetter(L, "spawnUpdateTimerTT", ZoneManager_set_spawnUpdateTimerTT);
    registerSetter(L, "distantTownCentre", ZoneManager_set_distantTownCentre);
    registerSetter(L, "centralZone", ZoneManager_set_centralZone);
    registerSetter(L, "loadingPhase", ZoneManager_set_loadingPhase);
    registerSetter(L, "groundEffectsPool", ZoneManager_set_groundEffectsPool);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ZoneManagerInterfaceT
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ZoneManagerBinding::getMetatableName(), ZoneManagerInterfaceTBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    lua_getglobal(L, "ZoneManager");
    if (!lua_istable(L, -1))
    {
        lua_pop(L, 1);
        lua_newtable(L);
    }
    registerStaticMethod(L, "getGroundSound", ZoneManagerBinding::getGroundSound);
    lua_setglobal(L, "ZoneManager");
}

} // namespace KenshiLua
