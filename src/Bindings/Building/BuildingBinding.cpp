#include "pch.h"
#include "kenshi\Building\Building.h"
#include "BuildingBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Building/ConstructionStateBinding.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Building/DoorStuffBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/Building/GatewayBuildingBinding.h"
#include "Bindings/InstanceIDBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/Building/ProductionBuildingBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Building/StorageBuildingBinding.h"
#include "Bindings/TownBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/TownBuildingsManagerBinding.h"
#include "Bindings/Building/UseableStuffBinding.h"
#include "Bindings/Building/WallBuildingBinding.h"
#include "Bindings/ZoneMapBinding.h"

namespace KenshiLua
{

static Building* getInstance(lua_State* L, int idx)
{
    return checkObject<Building>(L, idx, BuildingBinding::getMetatableName());
}

// --- Getters for Building ---
static int Building_get_isFoliage(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->isFoliage ? 1 : 0);
    return 1;
}

static int Building_get_hasTerrainInside(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->hasTerrainInside ? 1 : 0);
    return 1;
}

static int Building_get_isCavernous(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->isCavernous ? 1 : 0);
    return 1;
}

static int Building_get_enforceCeiling(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->enforceCeiling ? 1 : 0);
    return 1;
}

static int Building_get_designation(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushinteger(L, (lua_Integer)instance->designation);
    return 1;
}

static int Building_get_publicDaytime(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->publicDaytime ? 1 : 0);
    return 1;
}

static int Building_get_residentSquad(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return handBinding::push(L, instance->residentSquad);
}

static int Building_get_residentSquadTemplate(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return pushObject<GameData>(L, instance->residentSquadTemplate, GameDataBinding::getMetatableName());
}

static int Building_get_isAnInteriorObject(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->isAnInteriorObject ? 1 : 0);
    return 1;
}

static int Building_get_instanceID(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return pushObject<InstanceID>(L, &instance->instanceID, InstanceIDBinding::getMetatableName());
}

static int Building_get_layoutInstanceID(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushstring(L, instance->layoutInstanceID.c_str());
    return 1;
}

static int Building_get_specialFunction(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushinteger(L, (lua_Integer)instance->specialFunction);
    return 1;
}

static int Building_get__buildState(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return pushObject<Building::ConstructionState>(L, &instance->_buildState, ConstructionStateBinding::getMetatableName());
}

static int Building_get_classType(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushinteger(L, (lua_Integer)instance->classType);
    return 1;
}

static int Building_get_updateNavmesh(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->updateNavmesh ? 1 : 0);
    return 1;
}

static int Building_get_visible(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->visible ? 1 : 0);
    return 1;
}

static int Building_get_interiorVisibility(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->interiorVisibility ? 1 : 0);
    return 1;
}

static int Building_get_justBeenUpgradedFlag(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->justBeenUpgradedFlag ? 1 : 0);
    return 1;
}

static int Building_get_imADoor(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->imADoor ? 1 : 0);
    return 1;
}

static int Building_get_destroyed(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->destroyed ? 1 : 0);
    return 1;
}

static int Building_get_productionMult(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushnumber(L, instance->productionMult);
    return 1;
}

static int Building_get_productionMult_baseData(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushnumber(L, instance->productionMult_baseData);
    return 1;
}

static int Building_get_hasMovingParts(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->hasMovingParts ? 1 : 0);
    return 1;
}

static int Building_get_saveVersion(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushinteger(L, instance->saveVersion);
    return 1;
}

static int Building_get__town(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return handBinding::push(L, instance->_town);
}

// todo: implement a proper binding for Interior, instead of just returning a lightuserdata
static int Building_get_myInterior(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushlightuserdata(L, (void*)instance->myInterior);
    return 1;
}

static int Building_get_buildingsManager(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return pushObject<TownBuildingsManager>(L, instance->buildingsManager, TownBuildingsManagerBinding::getMetatableName());
}

// todo: implement a proper binding for rootNode, instead of just returning a lightuserdata
static int Building_get_rootNode(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushlightuserdata(L, (void*)instance->rootNode);
    return 1;
}

// todo: implement a proper binding for soundEmitter, instead of just returning a lightuserdata

static int Building_get_soundEmitter(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushlightuserdata(L, (void*)instance->soundEmitter);
    return 1;
}

static int Building_get_hasAudio(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->hasAudio ? 1 : 0);
    return 1;
}

static int Building_get_interiorGround(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushinteger(L, (lua_Integer)instance->interiorGround);
    return 1;
}

static int Building_get_exteriorGround(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushinteger(L, (lua_Integer)instance->exteriorGround);
    return 1;
}

// todo: implement a proper binding, instead of just returning a lightuserdata
static int Building_get_physical(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushlightuserdata(L, (void*)instance->physical);
    return 1;
}

static int Building_get_entitiesToLoad(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushinteger(L, instance->entitiesToLoad);
    return 1;
}

static int Building_get_entitiesLoaded(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->entitiesLoaded ? 1 : 0);
    return 1;
}

// todo: implement a proper binding, instead of just returning a lightuserdata
static int Building_get_isFurnitureOf(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushlightuserdata(L, (void*)instance->isFurnitureOf);
    return 1;
}

static int Building_get_isOutsideFurniture(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->isOutsideFurniture ? 1 : 0);
    return 1;
}

static int Building_get_isNestItem(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->isNestItem ? 1 : 0);
    return 1;
}

static int Building_get_baseMaterial(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return pushObject<GameData>(L, instance->baseMaterial, GameDataBinding::getMetatableName());
}

static int Building_get_effectsVisible(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->effectsVisible ? 1 : 0);
    return 1;
}

static int Building_get_effectsActive(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->effectsActive ? 1 : 0);
    return 1;
}

static int Building_get_lightsVisible(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->lightsVisible ? 1 : 0);
    return 1;
}

static int Building_get_positionMarker(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    pushVector3(L, instance->positionMarker);
    return 1;
}

static int Building_get_heightAboveGround(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushnumber(L, instance->heightAboveGround);
    return 1;
}

static int Building_get_isRedDebugTextureMode(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushboolean(L, instance->isRedDebugTextureMode ? 1 : 0);
    return 1;
}

static int Building_get_materialName(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushstring(L, instance->materialName.c_str());
    return 1;
}

// todo: implement a proper binding, instead of just returning a lightuserdata
static int Building_get_triggerVolume(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    lua_pushlightuserdata(L, (void*)instance->triggerVolume);
    return 1;
}

// --- Setters for Building ---
static int Building_set_isFoliage(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->isFoliage = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_hasTerrainInside(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->hasTerrainInside = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_isCavernous(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->isCavernous = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_enforceCeiling(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->enforceCeiling = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_designation(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->designation = (BuildingDesignation)luaL_checkinteger(L, 2);
    return 0;
}

static int Building_set_publicDaytime(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->publicDaytime = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_residentSquad(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->residentSquad = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int Building_set_residentSquadTemplate(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->residentSquadTemplate = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int Building_set_isAnInteriorObject(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->isAnInteriorObject = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_instanceID(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->instanceID = *checkObject<InstanceID>(L, 2, InstanceIDBinding::getMetatableName());
    return 0;
}

static int Building_set_layoutInstanceID(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->layoutInstanceID = luaL_checkstring(L, 2);
    return 0;
}

static int Building_set_specialFunction(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->specialFunction = (BuildingFunction)luaL_checkinteger(L, 2);
    return 0;
}

static int Building_set__buildState(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->_buildState = *checkObject<Building::ConstructionState>(L, 2, ConstructionStateBinding::getMetatableName());
    return 0;
}

static int Building_set_classType(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->classType = (BuildingClassType)luaL_checkinteger(L, 2);
    return 0;
}

static int Building_set_updateNavmesh(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->updateNavmesh = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_visible(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->visible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_interiorVisibility(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->interiorVisibility = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_justBeenUpgradedFlag(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->justBeenUpgradedFlag = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_imADoor(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->imADoor = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_destroyed(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->destroyed = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_productionMult(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->productionMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Building_set_productionMult_baseData(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->productionMult_baseData = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Building_set_hasMovingParts(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->hasMovingParts = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_saveVersion(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->saveVersion = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Building_set__town(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->_town = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int Building_set_buildingsManager(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->buildingsManager = lua_isnoneornil(L, 2) ? nullptr : checkObject<TownBuildingsManager>(L, 2, TownBuildingsManagerBinding::getMetatableName());
    return 0;
}

static int Building_set_hasAudio(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->hasAudio = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_interiorGround(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->interiorGround = (GroundType)luaL_checkinteger(L, 2);
    return 0;
}

static int Building_set_exteriorGround(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->exteriorGround = (GroundType)luaL_checkinteger(L, 2);
    return 0;
}

static int Building_set_entitiesToLoad(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->entitiesToLoad = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Building_set_entitiesLoaded(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->entitiesLoaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_isOutsideFurniture(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->isOutsideFurniture = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_isNestItem(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->isNestItem = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_baseMaterial(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->baseMaterial = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int Building_set_effectsVisible(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->effectsVisible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_effectsActive(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->effectsActive = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_lightsVisible(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->lightsVisible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_positionMarker(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    readVector3(L, 2, instance->positionMarker);
    return 0;
}

static int Building_set_heightAboveGround(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->heightAboveGround = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Building_set_isRedDebugTextureMode(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->isRedDebugTextureMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Building_set_materialName(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    instance->materialName = luaL_checkstring(L, 2);
    return 0;
}

int BuildingBinding::getScale(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->getScale();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::getBuildState(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Building::ConstructionState* result = instance->getBuildState();
    return pushObject<Building::ConstructionState>(L, result, ConstructionStateBinding::getMetatableName());
}

int BuildingBinding::_NV_getBuildState(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Building::ConstructionState* result = instance->_NV_getBuildState();
    return pushObject<Building::ConstructionState>(L, result, ConstructionStateBinding::getMetatableName());
}

int BuildingBinding::getBuildState_ActualNonShared(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Building::ConstructionState* result = instance->getBuildState_ActualNonShared();
    return pushObject<Building::ConstructionState>(L, result, ConstructionStateBinding::getMetatableName());
}

int BuildingBinding::select(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->select();
    return 0;
}

int BuildingBinding::_NV_select(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_NV_select();
    return 0;
}

int BuildingBinding::getBuildingDesignation(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    BuildingDesignation result = instance->getBuildingDesignation();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::addConstructionProgress(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->addConstructionProgress(amount);
    return 0;
}

int BuildingBinding::_NV_addConstructionProgress(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->_NV_addConstructionProgress(amount);
    return 0;
}

int BuildingBinding::setConstructionProgress(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->setConstructionProgress(amount);
    return 0;
}

int BuildingBinding::_NV_setConstructionProgress(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->_NV_setConstructionProgress(amount);
    return 0;
}

int BuildingBinding::notifyConstructionComplete(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->notifyConstructionComplete();
    return 0;
}

int BuildingBinding::_NV_notifyConstructionComplete(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_NV_notifyConstructionComplete();
    return 0;
}

int BuildingBinding::addDismantleProgress(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = instance->addDismantleProgress(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_addDismantleProgress(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = instance->_NV_addDismantleProgress(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::notifyConstructionDismantling(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->notifyConstructionDismantling();
    return 0;
}

int BuildingBinding::_NV_notifyConstructionDismantling(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_NV_notifyConstructionDismantling();
    return 0;
}

int BuildingBinding::dropMats(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->dropMats();
    return 0;
}

int BuildingBinding::upgrade(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->upgrade(_a1);
    return 0;
}

int BuildingBinding::_NV_upgrade(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->_NV_upgrade(_a1);
    return 0;
}

int BuildingBinding::downgrade(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->downgrade(_a1);
    return 0;
}

int BuildingBinding::_NV_downgrade(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->_NV_downgrade(_a1);
    return 0;
}

int BuildingBinding::canUpgrade(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GameData* result = instance->canUpgrade();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int BuildingBinding::_NV_canUpgrade(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GameData* result = instance->_NV_canUpgrade();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int BuildingBinding::canDowngrade(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GameData* result = instance->canDowngrade();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int BuildingBinding::_NV_canDowngrade(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GameData* result = instance->_NV_canDowngrade();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int BuildingBinding::canDismantle(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->canDismantle();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_canDismantle(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_canDismantle();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::buyMeAsk(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->buyMeAsk(_a1);
    return 0;
}

int BuildingBinding::_NV_buyMeAsk(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->_NV_buyMeAsk(_a1);
    return 0;
}

int BuildingBinding::buyMeCallback(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    int result = (int)luaL_checkinteger(L, 2);
    instance->buyMeCallback(result);
    return 0;
}

int BuildingBinding::_NV_buyMeCallback(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    int result = (int)luaL_checkinteger(L, 2);
    instance->_NV_buyMeCallback(result);
    return 0;
}

int BuildingBinding::calculateSaleValue(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    int result = instance->calculateSaleValue();
    lua_pushinteger(L, result);
    return 1;
}

int BuildingBinding::loadNodes(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->loadNodes();
    return 0;
}

int BuildingBinding::isPublic(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isPublic(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::togglePublic(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->togglePublic(_a1);
    return 0;
}

int BuildingBinding::_NV_togglePublic(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->_NV_togglePublic(_a1);
    return 0;
}

int BuildingBinding::dismantleButton(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->dismantleButton(_a1);
    return 0;
}

int BuildingBinding::_NV_dismantleButton(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->_NV_dismantleButton(_a1);
    return 0;
}

int BuildingBinding::pauseButton(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->pauseButton(_a1);
    return 0;
}

int BuildingBinding::_NV_pauseButton(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->_NV_pauseButton(_a1);
    return 0;
}

int BuildingBinding::confirmDismantle(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    int r = (int)luaL_checkinteger(L, 2);
    instance->confirmDismantle(r);
    return 0;
}

int BuildingBinding::_NV_confirmDismantle(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    int r = (int)luaL_checkinteger(L, 2);
    instance->_NV_confirmDismantle(r);
    return 0;
}

int BuildingBinding::isAShop(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isAShop();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isAShop(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_isAShop();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isForSale(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isForSale(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isAWall(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    WallBuilding* result = instance->isAWall();
    return pushObject<WallBuilding>(L, result, WallBuildingBinding::getMetatableName());
}

int BuildingBinding::_NV_isAWall(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    WallBuilding* result = instance->_NV_isAWall();
    return pushObject<WallBuilding>(L, result, WallBuildingBinding::getMetatableName());
}

int BuildingBinding::isAWallRamp(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isAWallRamp();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isAWallRamp(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_isAWallRamp();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::hasInterior(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->hasInterior();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::affectsNavmesh(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->affectsNavmesh();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::setResidentSquad(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->setResidentSquad(who);
    return 0;
}

int BuildingBinding::getResidentSquadLeader(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Character* result = instance->getResidentSquadLeader();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int BuildingBinding::setDesignation(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    BuildingDesignation d = (BuildingDesignation)luaL_checkinteger(L, 2);
    instance->setDesignation(d);
    return 0;
}

int BuildingBinding::getWallEndPosition(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Ogre::Vector3 result = instance->getWallEndPosition();
    pushVector3(L, result);
    return 1;
}

int BuildingBinding::setupMiningResourceLevel(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->setupMiningResourceLevel();
    return 0;
}

int BuildingBinding::_NV_setupMiningResourceLevel(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_NV_setupMiningResourceLevel();
    return 0;
}

int BuildingBinding::getMiningResourceLevel(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->getMiningResourceLevel();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_getMiningResourceLevel(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->_NV_getMiningResourceLevel();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::addAnInternalBuilding(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Building* b = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    instance->addAnInternalBuilding(b);
    return 0;
}

int BuildingBinding::getNumInternalBuildings(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    int result = instance->getNumInternalBuildings();
    lua_pushinteger(L, result);
    return 1;
}

int BuildingBinding::moveMountedBuildings(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->moveMountedBuildings();
    return 0;
}

int BuildingBinding::reCheckInsideOutsideFortificationStatus(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->reCheckInsideOutsideFortificationStatus();
    return 0;
}

int BuildingBinding::setInsideTownWalls(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    int code = (int)luaL_checkinteger(L, 2);
    instance->setInsideTownWalls(code);
    return 0;
}

int BuildingBinding::_NV_setInsideTownWalls(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    int code = (int)luaL_checkinteger(L, 2);
    instance->_NV_setInsideTownWalls(code);
    return 0;
}

int BuildingBinding::postCreationPathfinderSetupStuff(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->postCreationPathfinderSetupStuff();
    return 0;
}

int BuildingBinding::_NV_postCreationPathfinderSetupStuff(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_NV_postCreationPathfinderSetupStuff();
    return 0;
}

int BuildingBinding::getSpecialFunction(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    BuildingFunction result = instance->getSpecialFunction();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::_NV_getSpecialFunction(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    BuildingFunction result = instance->_NV_getSpecialFunction();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::getFunctionStuff(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    StorageBuilding* result = instance->getFunctionStuff();
    return pushObject<StorageBuilding>(L, result, StorageBuildingBinding::getMetatableName());
}

int BuildingBinding::_NV_getFunctionStuff(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    StorageBuilding* result = instance->_NV_getFunctionStuff();
    return pushObject<StorageBuilding>(L, result, StorageBuildingBinding::getMetatableName());
}

int BuildingBinding::getUseableStuff(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    UseableStuff* result = instance->getUseableStuff();
    return pushObject<UseableStuff>(L, result, UseableStuffBinding::getMetatableName());
}

int BuildingBinding::_NV_getUseableStuff(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    UseableStuff* result = instance->_NV_getUseableStuff();
    return pushObject<UseableStuff>(L, result, UseableStuffBinding::getMetatableName());
}

int BuildingBinding::isBroken(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isBroken();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isBroken(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_isBroken();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::setBroken(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool _a1 = lua_toboolean(L, 2) != 0;
    instance->setBroken(_a1);
    return 0;
}

int BuildingBinding::_NV_setBroken(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool _a1 = lua_toboolean(L, 2) != 0;
    instance->_NV_setBroken(_a1);
    return 0;
}

int BuildingBinding::switchPowerOn(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->switchPowerOn(on);
    return 0;
}

int BuildingBinding::_NV_switchPowerOn(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_switchPowerOn(on);
    return 0;
}

int BuildingBinding::isPowerOn(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isPowerOn();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isPowerOn(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_isPowerOn();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isDamaged(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isDamaged();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isDamaged(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_isDamaged();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isDestroyed(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isDestroyed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isDestroyed(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_isDestroyed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isSign(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isSign();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isSign(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_isSign();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::setDestroyed(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool d = lua_toboolean(L, 2) != 0;
    instance->setDestroyed(d);
    return 0;
}

int BuildingBinding::_NV_setDestroyed(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool d = lua_toboolean(L, 2) != 0;
    instance->_NV_setDestroyed(d);
    return 0;
}

int BuildingBinding::canBeDestroyed(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->canBeDestroyed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_canBeDestroyed(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_canBeDestroyed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::setNestTag(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->setNestTag();
    return 0;
}

int BuildingBinding::getReachRange(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_getReachRange(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->_NV_getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::hasShopCountersSelling(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    ItemFunction type = (ItemFunction)luaL_checkinteger(L, 2);
    bool result = instance->hasShopCountersSelling(type);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::getBuildingClass(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    BuildingClassType result = instance->getBuildingClass();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::_NV_getBuildingClass(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    BuildingClassType result = instance->_NV_getBuildingClass();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::needsSaving(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    const std::string mod = luaL_checkstring(L, 2);
    bool result = instance->needsSaving(mod);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_needsSaving(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    const std::string mod = luaL_checkstring(L, 2);
    bool result = instance->_NV_needsSaving(mod);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::notifyChange(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->notifyChange();
    return 0;
}

int BuildingBinding::getInstanceID(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    InstanceID* result = instance->getInstanceID();
    return pushObject<InstanceID>(L, result, InstanceIDBinding::getMetatableName());
}

int BuildingBinding::_NV_getInstanceID(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    InstanceID* result = instance->_NV_getInstanceID();
    return pushObject<InstanceID>(L, result, InstanceIDBinding::getMetatableName());
}

int BuildingBinding::setToDefaultFactionDivision(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->setToDefaultFactionDivision();
    return 0;
}

int BuildingBinding::getOutputBasedRotationSpeedMult(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->getOutputBasedRotationSpeedMult();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_getOutputBasedRotationSpeedMult(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->_NV_getOutputBasedRotationSpeedMult();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::calculateEfficiencyMult(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->calculateEfficiencyMult();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_calculateEfficiencyMult(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->_NV_calculateEfficiencyMult();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::getSoundIntensity(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->getSoundIntensity();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_getSoundIntensity(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->_NV_getSoundIntensity();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::loadUnloadCheck(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->loadUnloadCheck();
    return 0;
}

int BuildingBinding::_NV_loadUnloadCheck(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_NV_loadUnloadCheck();
    return 0;
}

int BuildingBinding::_DESTRUCTOR(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int BuildingBinding::_saveBuildingState(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string doorID = luaL_checkstring(L, 3);
    instance->_saveBuildingState(state, doorID);
    return 0;
}

int BuildingBinding::_NV__saveBuildingState(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string doorID = luaL_checkstring(L, 3);
    instance->_NV__saveBuildingState(state, doorID);
    return 0;
}

int BuildingBinding::_loadBuildingState(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string doorID = luaL_checkstring(L, 3);
    instance->_loadBuildingState(state, doorID);
    return 0;
}

int BuildingBinding::_NV__loadBuildingState(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string doorID = luaL_checkstring(L, 3);
    instance->_NV__loadBuildingState(state, doorID);
    return 0;
}

int BuildingBinding::getGUIName(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIName(datapanel, category);
    return 0;
}

int BuildingBinding::_NV_getGUIName(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIName(datapanel, category);
    return 0;
}

int BuildingBinding::getGUIState(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIState(datapanel, category);
    return 0;
}

int BuildingBinding::_NV_getGUIState(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIState(datapanel, category);
    return 0;
}

int BuildingBinding::getGUICondition(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUICondition(datapanel, category);
    return 0;
}

int BuildingBinding::_NV_getGUICondition(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUICondition(datapanel, category);
    return 0;
}

int BuildingBinding::getGUIUpgrade(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIUpgrade(datapanel, category);
    return 0;
}

int BuildingBinding::_NV_getGUIUpgrade(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIUpgrade(datapanel, category);
    return 0;
}

int BuildingBinding::getGUIDestroyButton(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIDestroyButton(datapanel, category);
    return 0;
}

int BuildingBinding::_NV_getGUIDestroyButton(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIDestroyButton(datapanel, category);
    return 0;
}

int BuildingBinding::getProductionBuilding(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    ProductionBuilding* result = instance->getProductionBuilding();
    return pushObject<ProductionBuilding>(L, result, ProductionBuildingBinding::getMetatableName());
}

int BuildingBinding::_NV_getProductionBuilding(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    ProductionBuilding* result = instance->_NV_getProductionBuilding();
    return pushObject<ProductionBuilding>(L, result, ProductionBuildingBinding::getMetatableName());
}

int BuildingBinding::getProductionMultForGUI(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->getProductionMultForGUI();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_getProductionMultForGUI(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->_NV_getProductionMultForGUI();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::getProductionMult(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->getProductionMult();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_getProductionMult(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->_NV_getProductionMult();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::isThePlayer(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isThePlayer();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::doorStuff(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DoorStuff* result = instance->doorStuff();
    return pushObject<DoorStuff>(L, result, DoorStuffBinding::getMetatableName());
}

int BuildingBinding::_NV_doorStuff(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DoorStuff* result = instance->_NV_doorStuff();
    return pushObject<DoorStuff>(L, result, DoorStuffBinding::getMetatableName());
}

int BuildingBinding::doorParentBuilding(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Building* result = instance->doorParentBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int BuildingBinding::_NV_doorParentBuilding(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Building* result = instance->_NV_doorParentBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int BuildingBinding::isDoor(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isDoor();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isGate(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GatewayBuilding* result = instance->isGate();
    return pushObject<GatewayBuilding>(L, result, GatewayBuildingBinding::getMetatableName());
}

int BuildingBinding::_NV_isGate(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GatewayBuilding* result = instance->_NV_isGate();
    return pushObject<GatewayBuilding>(L, result, GatewayBuildingBinding::getMetatableName());
}

int BuildingBinding::getDoor(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DoorStuff* result = instance->getDoor();
    return pushObject<DoorStuff>(L, result, DoorStuffBinding::getMetatableName());
}

int BuildingBinding::_NV_getDoor(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DoorStuff* result = instance->_NV_getDoor();
    return pushObject<DoorStuff>(L, result, DoorStuffBinding::getMetatableName());
}

int BuildingBinding::getParentLayout(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Layout* result = instance->getParentLayout();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int BuildingBinding::isFurniture(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isFurniture();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isFurnitureOrDoor(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isFurnitureOrDoor();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::getIsOutsideFurniture(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->getIsOutsideFurniture();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::setIsOutsideFurniture(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setIsOutsideFurniture(value);
    return 0;
}

int BuildingBinding::getCurrentTownLocation(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    TownBase* result = instance->getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int BuildingBinding::_NV_getCurrentTownLocation(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    TownBase* result = instance->_NV_getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int BuildingBinding::furnitureParentBuilding(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Building* result = instance->furnitureParentBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int BuildingBinding::hasAnOpenDoor(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->hasAnOpenDoor();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::allowAnimals(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->allowAnimals();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::update(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->update();
    return 0;
}

int BuildingBinding::_NV_update(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_NV_update();
    return 0;
}

int BuildingBinding::threadedUpdate(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->threadedUpdate();
    return 0;
}

int BuildingBinding::_NV_threadedUpdate(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_NV_threadedUpdate();
    return 0;
}

int BuildingBinding::needsUpdate(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_needsUpdate(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isPhysical(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isPhysical(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::checkLoadedProperly(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->checkLoadedProperly();
    return 0;
}

int BuildingBinding::_NV_checkLoadedProperly(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_NV_checkLoadedProperly();
    return 0;
}

int BuildingBinding::loadFromSerialise(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GameSaveState* savestate = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(savestate);
    return 0;
}

int BuildingBinding::_NV_loadFromSerialise(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GameSaveState* savestate = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(savestate);
    return 0;
}

int BuildingBinding::loadFromSerialise_TheDoors(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GameSaveState* savestate = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise_TheDoors(savestate);
    return 0;
}

int BuildingBinding::_NV_loadFromSerialise_TheDoors(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GameSaveState* savestate = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise_TheDoors(savestate);
    return 0;
}

int BuildingBinding::getGUIData(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(datapanel, category);
    return 0;
}

int BuildingBinding::_NV_getGUIData(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIData(datapanel, category);
    return 0;
}

int BuildingBinding::setVisible(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setVisible(on);
    return 0;
}

int BuildingBinding::_NV_setVisible(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(on);
    return 0;
}

int BuildingBinding::getVisible(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_getVisible(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

// todo: implement a proper binding, instead of just returning a lightuserdata
int BuildingBinding::getDoorLock(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DoorLock* result = instance->getDoorLock();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

// todo: implement a proper binding, instead of just returning a lightuserdata
int BuildingBinding::_NV_getDoorLock(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    DoorLock* result = instance->_NV_getDoorLock();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int BuildingBinding::hasDoorLock(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->hasDoorLock();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_hasDoorLock(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_hasDoorLock();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::getMouseCursor(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    CursorType result = instance->getMouseCursor();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::_NV_getMouseCursor(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    CursorType result = instance->_NV_getMouseCursor();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::getDefaultTask(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    TaskType result = instance->getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::_NV_getDefaultTask(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    TaskType result = instance->_NV_getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::getInventory(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Inventory* result = instance->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int BuildingBinding::_NV_getInventory(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Inventory* result = instance->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int BuildingBinding::_changeTown(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Town* t = checkObject<Town>(L, 2, TownBinding::getMetatableName());
    instance->_changeTown(t);
    return 0;
}

int BuildingBinding::getTownHandle(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    hand result = instance->getTownHandle();
    return handBinding::push(L, result);
}

int BuildingBinding::getTown(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    TownBase* result = instance->getTown();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int BuildingBinding::getRealTown(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Town* result = instance->getRealTown();
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int BuildingBinding::createPhysical(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_createPhysical(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::destroyPhysical(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->destroyPhysical();
    return 0;
}

int BuildingBinding::_NV_destroyPhysical(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_NV_destroyPhysical();
    return 0;
}

int BuildingBinding::destroyDoors(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->destroyDoors();
    return 0;
}

int BuildingBinding::createTriggerHull(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->createTriggerHull();
    return 0;
}

int BuildingBinding::destroyAudioObject(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->destroyAudioObject();
    return 0;
}

int BuildingBinding::getGroundType(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool inside = lua_toboolean(L, 2) != 0;
    GroundType result = instance->getGroundType(inside);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::isCeilingMounted(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isCeilingMounted();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isCeilingMounted(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_isCeilingMounted();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::setFloorVisibility(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    int floor = (int)luaL_checkinteger(L, 2);
    bool vis = lua_toboolean(L, 3) != 0;
    instance->setFloorVisibility(floor, vis);
    return 0;
}

int BuildingBinding::getNumFloors(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    int result = instance->getNumFloors();
    lua_pushinteger(L, result);
    return 1;
}

int BuildingBinding::buildingComplete_RestoreMaterial(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->buildingComplete_RestoreMaterial();
    return 0;
}

int BuildingBinding::loadInteriorPhysical(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->loadInteriorPhysical(on);
    return 0;
}

int BuildingBinding::loadInteriorGraphics(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->loadInteriorGraphics(on);
    return 0;
}

int BuildingBinding::setFaction(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* a = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    instance->setFaction(p, a);
    return 0;
}

int BuildingBinding::_NV_setFaction(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* a = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    instance->_NV_setFaction(p, a);
    return 0;
}

int BuildingBinding::calculateLeftPost(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Ogre::Vector3 result = instance->calculateLeftPost();
    pushVector3(L, result);
    return 1;
}

int BuildingBinding::setupLevelData(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    GameData* squad = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    const std::string interior = luaL_checkstring(L, 4);
    const std::string exterior = luaL_checkstring(L, 5);
    instance->setupLevelData(f, squad, interior, exterior);
    return 0;
}

int BuildingBinding::getLinkLength(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->getLinkLength();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_getLinkLength(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->_NV_getLinkLength();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::getRootNode(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Ogre::SceneNode* result = instance->getRootNode();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int BuildingBinding::getZoneMapLocation(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    ZoneMap* result = instance->getZoneMapLocation();
    return pushObject<ZoneMap>(L, result, ZoneMapBinding::getMetatableName());
}

int BuildingBinding::_NV_getZoneMapLocation(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    ZoneMap* result = instance->_NV_getZoneMapLocation();
    return pushObject<ZoneMap>(L, result, ZoneMapBinding::getMetatableName());
}

int BuildingBinding::clearTownBuildingsManagerPtr(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->clearTownBuildingsManagerPtr();
    return 0;
}

int BuildingBinding::_NV_clearTownBuildingsManagerPtr(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_NV_clearTownBuildingsManagerPtr();
    return 0;
}

int BuildingBinding::setup(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->setup();
    return 0;
}

int BuildingBinding::_NV_setup(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_NV_setup();
    return 0;
}

int BuildingBinding::setupFromData(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->setupFromData();
    return 0;
}

int BuildingBinding::_NV_setupFromData(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_NV_setupFromData();
    return 0;
}

int BuildingBinding::setupAudio(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->setupAudio();
    return 0;
}

int BuildingBinding::switchLights(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->switchLights(on);
    return 0;
}

int BuildingBinding::_NV_switchLights(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_switchLights(on);
    return 0;
}

int BuildingBinding::switchEffects(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->switchEffects(on);
    return 0;
}

int BuildingBinding::_NV_switchEffects(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_switchEffects(on);
    return 0;
}

int BuildingBinding::hasAnyGoodPositionMarkersLeft(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->hasAnyGoodPositionMarkersLeft();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::notifyBadPositionMarker(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Ogre::Vector3 what;
    readVector3(L, 2, what);
    instance->notifyBadPositionMarker(what);
    return 0;
}

int BuildingBinding::getPositionMarker(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Ogre::Vector3 currentPosition;
    readVector3(L, 2, currentPosition);
    Ogre::Vector3 result = instance->getPositionMarker(currentPosition);
    pushVector3(L, result);
    return 1;
}

int BuildingBinding::_NV_getPositionMarker(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Ogre::Vector3 currentPosition;
    readVector3(L, 2, currentPosition);
    Ogre::Vector3 result = instance->_NV_getPositionMarker(currentPosition);
    pushVector3(L, result);
    return 1;
}

int BuildingBinding::getDirectionMarker(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Ogre::Vector3 currentPosition;
    readVector3(L, 2, currentPosition);
    Ogre::Vector3 result = instance->getDirectionMarker(currentPosition);
    pushVector3(L, result);
    return 1;
}

int BuildingBinding::_NV_getDirectionMarker(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Ogre::Vector3 currentPosition;
    readVector3(L, 2, currentPosition);
    Ogre::Vector3 result = instance->_NV_getDirectionMarker(currentPosition);
    pushVector3(L, result);
    return 1;
}

int BuildingBinding::getDirectionMarkerQuat(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Ogre::Vector3 currentPosition;
    readVector3(L, 2, currentPosition);
    Ogre::Quaternion result = instance->getDirectionMarkerQuat(currentPosition);
    pushQuaternion(L, result);
    return 1;
}

int BuildingBinding::_NV_getDirectionMarkerQuat(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Ogre::Vector3 currentPosition;
    readVector3(L, 2, currentPosition);
    Ogre::Quaternion result = instance->_NV_getDirectionMarkerQuat(currentPosition);
    pushQuaternion(L, result);
    return 1;
}

int BuildingBinding::isCreated(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->isCreated();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isCreated(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    bool result = instance->_NV_isCreated();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::updateUsageNodes(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->updateUsageNodes();
    return 0;
}

int BuildingBinding::forceValidUsageNodesValidation(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->forceValidUsageNodesValidation();
    return 0;
}

int BuildingBinding::addUsageNode(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    const std::string nodeId = luaL_checkstring(L, 2);
    instance->addUsageNode(nodeId);
    return 0;
}

int BuildingBinding::removeUsageNode(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    const std::string nodeId = luaL_checkstring(L, 2);
    instance->removeUsageNode(nodeId);
    return 0;
}

int BuildingBinding::clearUsageNodes(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->clearUsageNodes();
    return 0;
}

int BuildingBinding::notifyEffect(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    EffectType::Enum type = (EffectType::Enum)luaL_checkinteger(L, 2);
    WeatherAffecting what = (WeatherAffecting)luaL_checkinteger(L, 3);
    float strength = (float)luaL_checknumber(L, 4);
    instance->notifyEffect(type, what, strength);
    return 0;
}

int BuildingBinding::_NV_notifyEffect(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    EffectType::Enum type = (EffectType::Enum)luaL_checkinteger(L, 2);
    WeatherAffecting what = (WeatherAffecting)luaL_checkinteger(L, 3);
    float strength = (float)luaL_checknumber(L, 4);
    instance->_NV_notifyEffect(type, what, strength);
    return 0;
}

int BuildingBinding::updatePhysicalWithProgress(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->updatePhysicalWithProgress();
    return 0;
}

int BuildingBinding::recalculateWorldAABB(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->recalculateWorldAABB();
    return 0;
}

int BuildingBinding::selectPartMaterial(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    GameData* partData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* result = instance->selectPartMaterial(partData);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int BuildingBinding::getSeed(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    unsigned int result = instance->getSeed();
    lua_pushinteger(L, result);
    return 1;
}

int BuildingBinding::onBuildingLoaded(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->onBuildingLoaded();
    return 0;
}

int BuildingBinding::_NV_onBuildingLoaded(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->_NV_onBuildingLoaded();
    return 0;
}

int BuildingBinding::updateBadNodes(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    instance->updateBadNodes();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 210: void removeAnInternalBuilding(...) - non-string reference arg
  line 212: void addAnInternalItem(...) - unsupported arg type
  line 213: void removeAnInternalItem(...) - unsupported arg type
  line 215: int getMountedBuildings(...) - unsupported arg type
  line 217: void setHandle(...) - non-string reference arg
  line 218: void _NV_setHandle(...) - non-string reference arg
  line 261: const std::string& getLayoutInstanceID(...) - reference return type
  line 262: const std::string& _NV_getLayoutInstanceID(...) - reference return type
  line 269: Building* _CONSTRUCTOR(...) - non-string reference arg
  line 306: void findAllFurnitureWithFunction(...) - unsupported arg type
  line 344: GameSaveState serialise(...) - unsupported arg type
  line 345: GameSaveState _NV_serialise(...) - unsupported arg type
  line 366: const Ogre::Aabb& getAABB(...) - overloaded method
  line 367: const Ogre::Aabb& _NV_getAABB(...) - overloaded method
  line 368: Ogre::Aabb getAABB(...) - overloaded method
  line 369: Ogre::Aabb _NV_getAABB(...) - overloaded method
  line 370: void setAABB(...) - unsupported arg type
  line 383: unsigned __int64 getAudioObject(...) - unsupported return type
  line 387: const hand& isIndoors(...) - reference return type
  line 388: const hand& _NV_isIndoors(...) - reference return type
  line 389: const hand& isIndoors_notDestroyed(...) - reference return type
  line 390: const hand& _NV_isIndoors_notDestroyed(...) - reference return type
  line 391: const hand& getMountedBuilding(...) - reference return type
  line 392: const hand& _NV_getMountedBuilding(...) - reference return type
  line 393: int getLights(...) - unsupported arg type
  line 457: Ogre::SharedPtr<Ogre::Material> getBuildingPartMaterial(...) - static method
  line 458: void setBuildingPartMaterial(...) - static method
  line 459: void restoreMaterialToPhysical(...) - unsupported arg type
  line 463: void updateWorldAABB(...) - unsupported arg type
  line 469: Ogre::SharedPtr<Ogre::Material> getPartMaterial(...) - unsupported return type
  line 470: void selectParts(...) - static method
  line 471: void loadParts(...) - unsupported arg type
  line 472: PhysicalEntity* loadPartEntity(...) - unsupported arg type
  line 473: Ogre::MovableObject* loadEntity(...) - unsupported arg type
  line 474: void loadEntityCallback(...) - unsupported arg type
  line 475: void loadInstances(...) - unsupported arg type
  line 477: PhysicalEntity* findPhysicalEntity(...) - unsupported arg type
  line 478: PhysicalEntity* findPhysicalEntityInCollection(...) - static method
  line 479: bool buildingContainsEntity(...) - static method
  line 480: std::string getEntityMaterialName(...) - static method
  line 483: void setPartVisible(...) - unsupported arg type
  line 484: void _NV_setPartVisible(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 314: doors (lektor<Building*>) - unsupported type
  line 418: audioObject (unsigned __int64) - unsupported type
  line 430: effects (lektor<std::pair<PhysicalEntity*, Effect*> >) - unsupported type
  line 465: AABB (Ogre::Aabb) - unsupported type
  line 485: usageNodesIds (std::set<std::string, std::less<std::string >, Ogre::STLAllocator<std::string, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 486: usageNodes (lektor<UsageNode*>) - unsupported type
  line 487: badNodes (ogre_unordered_map<int, float>::type) - unsupported type
  line 490: activeEffects (lektor<std::pair<char, float> >) - unsupported type
*/

int BuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Building object");
    return 1;
}

void BuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildingBinding::gc },
        { "__tostring", BuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getScale", BuildingBinding::getScale },
        { "getBuildState", BuildingBinding::getBuildState },
        { "_NV_getBuildState", BuildingBinding::_NV_getBuildState },
        { "getBuildState_ActualNonShared", BuildingBinding::getBuildState_ActualNonShared },
        { "select", BuildingBinding::select },
        { "_NV_select", BuildingBinding::_NV_select },
        { "getBuildingDesignation", BuildingBinding::getBuildingDesignation },
        { "addConstructionProgress", BuildingBinding::addConstructionProgress },
        { "_NV_addConstructionProgress", BuildingBinding::_NV_addConstructionProgress },
        { "setConstructionProgress", BuildingBinding::setConstructionProgress },
        { "_NV_setConstructionProgress", BuildingBinding::_NV_setConstructionProgress },
        { "notifyConstructionComplete", BuildingBinding::notifyConstructionComplete },
        { "_NV_notifyConstructionComplete", BuildingBinding::_NV_notifyConstructionComplete },
        { "addDismantleProgress", BuildingBinding::addDismantleProgress },
        { "_NV_addDismantleProgress", BuildingBinding::_NV_addDismantleProgress },
        { "notifyConstructionDismantling", BuildingBinding::notifyConstructionDismantling },
        { "_NV_notifyConstructionDismantling", BuildingBinding::_NV_notifyConstructionDismantling },
        { "dropMats", BuildingBinding::dropMats },
        { "upgrade", BuildingBinding::upgrade },
        { "_NV_upgrade", BuildingBinding::_NV_upgrade },
        { "downgrade", BuildingBinding::downgrade },
        { "_NV_downgrade", BuildingBinding::_NV_downgrade },
        { "canUpgrade", BuildingBinding::canUpgrade },
        { "_NV_canUpgrade", BuildingBinding::_NV_canUpgrade },
        { "canDowngrade", BuildingBinding::canDowngrade },
        { "_NV_canDowngrade", BuildingBinding::_NV_canDowngrade },
        { "canDismantle", BuildingBinding::canDismantle },
        { "_NV_canDismantle", BuildingBinding::_NV_canDismantle },
        { "buyMeAsk", BuildingBinding::buyMeAsk },
        { "_NV_buyMeAsk", BuildingBinding::_NV_buyMeAsk },
        { "buyMeCallback", BuildingBinding::buyMeCallback },
        { "_NV_buyMeCallback", BuildingBinding::_NV_buyMeCallback },
        { "calculateSaleValue", BuildingBinding::calculateSaleValue },
        { "loadNodes", BuildingBinding::loadNodes },
        { "isPublic", BuildingBinding::isPublic },
        { "_NV_isPublic", BuildingBinding::_NV_isPublic },
        { "togglePublic", BuildingBinding::togglePublic },
        { "_NV_togglePublic", BuildingBinding::_NV_togglePublic },
        { "dismantleButton", BuildingBinding::dismantleButton },
        { "_NV_dismantleButton", BuildingBinding::_NV_dismantleButton },
        { "pauseButton", BuildingBinding::pauseButton },
        { "_NV_pauseButton", BuildingBinding::_NV_pauseButton },
        { "confirmDismantle", BuildingBinding::confirmDismantle },
        { "_NV_confirmDismantle", BuildingBinding::_NV_confirmDismantle },
        { "isAShop", BuildingBinding::isAShop },
        { "_NV_isAShop", BuildingBinding::_NV_isAShop },
        { "isForSale", BuildingBinding::isForSale },
        { "_NV_isForSale", BuildingBinding::_NV_isForSale },
        { "isAWall", BuildingBinding::isAWall },
        { "_NV_isAWall", BuildingBinding::_NV_isAWall },
        { "isAWallRamp", BuildingBinding::isAWallRamp },
        { "_NV_isAWallRamp", BuildingBinding::_NV_isAWallRamp },
        { "hasInterior", BuildingBinding::hasInterior },
        { "affectsNavmesh", BuildingBinding::affectsNavmesh },
        { "setResidentSquad", BuildingBinding::setResidentSquad },
        { "getResidentSquadLeader", BuildingBinding::getResidentSquadLeader },
        { "setDesignation", BuildingBinding::setDesignation },
        { "getWallEndPosition", BuildingBinding::getWallEndPosition },
        { "setupMiningResourceLevel", BuildingBinding::setupMiningResourceLevel },
        { "_NV_setupMiningResourceLevel", BuildingBinding::_NV_setupMiningResourceLevel },
        { "getMiningResourceLevel", BuildingBinding::getMiningResourceLevel },
        { "_NV_getMiningResourceLevel", BuildingBinding::_NV_getMiningResourceLevel },
        { "addAnInternalBuilding", BuildingBinding::addAnInternalBuilding },
        { "getNumInternalBuildings", BuildingBinding::getNumInternalBuildings },
        { "moveMountedBuildings", BuildingBinding::moveMountedBuildings },
        { "reCheckInsideOutsideFortificationStatus", BuildingBinding::reCheckInsideOutsideFortificationStatus },
        { "setInsideTownWalls", BuildingBinding::setInsideTownWalls },
        { "_NV_setInsideTownWalls", BuildingBinding::_NV_setInsideTownWalls },
        { "postCreationPathfinderSetupStuff", BuildingBinding::postCreationPathfinderSetupStuff },
        { "_NV_postCreationPathfinderSetupStuff", BuildingBinding::_NV_postCreationPathfinderSetupStuff },
        { "getSpecialFunction", BuildingBinding::getSpecialFunction },
        { "_NV_getSpecialFunction", BuildingBinding::_NV_getSpecialFunction },
        { "getFunctionStuff", BuildingBinding::getFunctionStuff },
        { "_NV_getFunctionStuff", BuildingBinding::_NV_getFunctionStuff },
        { "getUseableStuff", BuildingBinding::getUseableStuff },
        { "_NV_getUseableStuff", BuildingBinding::_NV_getUseableStuff },
        { "isBroken", BuildingBinding::isBroken },
        { "_NV_isBroken", BuildingBinding::_NV_isBroken },
        { "setBroken", BuildingBinding::setBroken },
        { "_NV_setBroken", BuildingBinding::_NV_setBroken },
        { "switchPowerOn", BuildingBinding::switchPowerOn },
        { "_NV_switchPowerOn", BuildingBinding::_NV_switchPowerOn },
        { "isPowerOn", BuildingBinding::isPowerOn },
        { "_NV_isPowerOn", BuildingBinding::_NV_isPowerOn },
        { "isDamaged", BuildingBinding::isDamaged },
        { "_NV_isDamaged", BuildingBinding::_NV_isDamaged },
        { "isDestroyed", BuildingBinding::isDestroyed },
        { "_NV_isDestroyed", BuildingBinding::_NV_isDestroyed },
        { "isSign", BuildingBinding::isSign },
        { "_NV_isSign", BuildingBinding::_NV_isSign },
        { "setDestroyed", BuildingBinding::setDestroyed },
        { "_NV_setDestroyed", BuildingBinding::_NV_setDestroyed },
        { "canBeDestroyed", BuildingBinding::canBeDestroyed },
        { "_NV_canBeDestroyed", BuildingBinding::_NV_canBeDestroyed },
        { "setNestTag", BuildingBinding::setNestTag },
        { "getReachRange", BuildingBinding::getReachRange },
        { "_NV_getReachRange", BuildingBinding::_NV_getReachRange },
        { "hasShopCountersSelling", BuildingBinding::hasShopCountersSelling },
        { "getBuildingClass", BuildingBinding::getBuildingClass },
        { "_NV_getBuildingClass", BuildingBinding::_NV_getBuildingClass },
        { "needsSaving", BuildingBinding::needsSaving },
        { "_NV_needsSaving", BuildingBinding::_NV_needsSaving },
        { "notifyChange", BuildingBinding::notifyChange },
        { "getInstanceID", BuildingBinding::getInstanceID },
        { "_NV_getInstanceID", BuildingBinding::_NV_getInstanceID },
        { "setToDefaultFactionDivision", BuildingBinding::setToDefaultFactionDivision },
        { "getOutputBasedRotationSpeedMult", BuildingBinding::getOutputBasedRotationSpeedMult },
        { "_NV_getOutputBasedRotationSpeedMult", BuildingBinding::_NV_getOutputBasedRotationSpeedMult },
        { "calculateEfficiencyMult", BuildingBinding::calculateEfficiencyMult },
        { "_NV_calculateEfficiencyMult", BuildingBinding::_NV_calculateEfficiencyMult },
        { "getSoundIntensity", BuildingBinding::getSoundIntensity },
        { "_NV_getSoundIntensity", BuildingBinding::_NV_getSoundIntensity },
        { "loadUnloadCheck", BuildingBinding::loadUnloadCheck },
        { "_NV_loadUnloadCheck", BuildingBinding::_NV_loadUnloadCheck },
        { "_DESTRUCTOR", BuildingBinding::_DESTRUCTOR },
        { "_saveBuildingState", BuildingBinding::_saveBuildingState },
        { "_NV__saveBuildingState", BuildingBinding::_NV__saveBuildingState },
        { "_loadBuildingState", BuildingBinding::_loadBuildingState },
        { "_NV__loadBuildingState", BuildingBinding::_NV__loadBuildingState },
        { "getGUIName", BuildingBinding::getGUIName },
        { "_NV_getGUIName", BuildingBinding::_NV_getGUIName },
        { "getGUIState", BuildingBinding::getGUIState },
        { "_NV_getGUIState", BuildingBinding::_NV_getGUIState },
        { "getGUICondition", BuildingBinding::getGUICondition },
        { "_NV_getGUICondition", BuildingBinding::_NV_getGUICondition },
        { "getGUIUpgrade", BuildingBinding::getGUIUpgrade },
        { "_NV_getGUIUpgrade", BuildingBinding::_NV_getGUIUpgrade },
        { "getGUIDestroyButton", BuildingBinding::getGUIDestroyButton },
        { "_NV_getGUIDestroyButton", BuildingBinding::_NV_getGUIDestroyButton },
        { "getProductionBuilding", BuildingBinding::getProductionBuilding },
        { "_NV_getProductionBuilding", BuildingBinding::_NV_getProductionBuilding },
        { "getProductionMultForGUI", BuildingBinding::getProductionMultForGUI },
        { "_NV_getProductionMultForGUI", BuildingBinding::_NV_getProductionMultForGUI },
        { "getProductionMult", BuildingBinding::getProductionMult },
        { "_NV_getProductionMult", BuildingBinding::_NV_getProductionMult },
        { "isThePlayer", BuildingBinding::isThePlayer },
        { "doorStuff", BuildingBinding::doorStuff },
        { "_NV_doorStuff", BuildingBinding::_NV_doorStuff },
        { "doorParentBuilding", BuildingBinding::doorParentBuilding },
        { "_NV_doorParentBuilding", BuildingBinding::_NV_doorParentBuilding },
        { "isDoor", BuildingBinding::isDoor },
        { "isGate", BuildingBinding::isGate },
        { "_NV_isGate", BuildingBinding::_NV_isGate },
        { "getDoor", BuildingBinding::getDoor },
        { "_NV_getDoor", BuildingBinding::_NV_getDoor },
        { "getParentLayout", BuildingBinding::getParentLayout },
        { "isFurniture", BuildingBinding::isFurniture },
        { "isFurnitureOrDoor", BuildingBinding::isFurnitureOrDoor },
        { "getIsOutsideFurniture", BuildingBinding::getIsOutsideFurniture },
        { "setIsOutsideFurniture", BuildingBinding::setIsOutsideFurniture },
        { "getCurrentTownLocation", BuildingBinding::getCurrentTownLocation },
        { "_NV_getCurrentTownLocation", BuildingBinding::_NV_getCurrentTownLocation },
        { "furnitureParentBuilding", BuildingBinding::furnitureParentBuilding },
        { "hasAnOpenDoor", BuildingBinding::hasAnOpenDoor },
        { "allowAnimals", BuildingBinding::allowAnimals },
        { "update", BuildingBinding::update },
        { "_NV_update", BuildingBinding::_NV_update },
        { "threadedUpdate", BuildingBinding::threadedUpdate },
        { "_NV_threadedUpdate", BuildingBinding::_NV_threadedUpdate },
        { "needsUpdate", BuildingBinding::needsUpdate },
        { "_NV_needsUpdate", BuildingBinding::_NV_needsUpdate },
        { "isPhysical", BuildingBinding::isPhysical },
        { "_NV_isPhysical", BuildingBinding::_NV_isPhysical },
        { "checkLoadedProperly", BuildingBinding::checkLoadedProperly },
        { "_NV_checkLoadedProperly", BuildingBinding::_NV_checkLoadedProperly },
        { "loadFromSerialise", BuildingBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", BuildingBinding::_NV_loadFromSerialise },
        { "loadFromSerialise_TheDoors", BuildingBinding::loadFromSerialise_TheDoors },
        { "_NV_loadFromSerialise_TheDoors", BuildingBinding::_NV_loadFromSerialise_TheDoors },
        { "getGUIData", BuildingBinding::getGUIData },
        { "_NV_getGUIData", BuildingBinding::_NV_getGUIData },
        { "setVisible", BuildingBinding::setVisible },
        { "_NV_setVisible", BuildingBinding::_NV_setVisible },
        { "getVisible", BuildingBinding::getVisible },
        { "_NV_getVisible", BuildingBinding::_NV_getVisible },
        { "getDoorLock", BuildingBinding::getDoorLock },
        { "_NV_getDoorLock", BuildingBinding::_NV_getDoorLock },
        { "hasDoorLock", BuildingBinding::hasDoorLock },
        { "_NV_hasDoorLock", BuildingBinding::_NV_hasDoorLock },
        { "getMouseCursor", BuildingBinding::getMouseCursor },
        { "_NV_getMouseCursor", BuildingBinding::_NV_getMouseCursor },
        { "getDefaultTask", BuildingBinding::getDefaultTask },
        { "_NV_getDefaultTask", BuildingBinding::_NV_getDefaultTask },
        { "getInventory", BuildingBinding::getInventory },
        { "_NV_getInventory", BuildingBinding::_NV_getInventory },
        { "_changeTown", BuildingBinding::_changeTown },
        { "getTownHandle", BuildingBinding::getTownHandle },
        { "getTown", BuildingBinding::getTown },
        { "getRealTown", BuildingBinding::getRealTown },
        { "createPhysical", BuildingBinding::createPhysical },
        { "_NV_createPhysical", BuildingBinding::_NV_createPhysical },
        { "destroyPhysical", BuildingBinding::destroyPhysical },
        { "_NV_destroyPhysical", BuildingBinding::_NV_destroyPhysical },
        { "destroyDoors", BuildingBinding::destroyDoors },
        { "createTriggerHull", BuildingBinding::createTriggerHull },
        { "destroyAudioObject", BuildingBinding::destroyAudioObject },
        { "getGroundType", BuildingBinding::getGroundType },
        { "isCeilingMounted", BuildingBinding::isCeilingMounted },
        { "_NV_isCeilingMounted", BuildingBinding::_NV_isCeilingMounted },
        { "setFloorVisibility", BuildingBinding::setFloorVisibility },
        { "getNumFloors", BuildingBinding::getNumFloors },
        { "buildingComplete_RestoreMaterial", BuildingBinding::buildingComplete_RestoreMaterial },
        { "loadInteriorPhysical", BuildingBinding::loadInteriorPhysical },
        { "loadInteriorGraphics", BuildingBinding::loadInteriorGraphics },
        { "setFaction", BuildingBinding::setFaction },
        { "_NV_setFaction", BuildingBinding::_NV_setFaction },
        { "calculateLeftPost", BuildingBinding::calculateLeftPost },
        { "setupLevelData", BuildingBinding::setupLevelData },
        { "getLinkLength", BuildingBinding::getLinkLength },
        { "_NV_getLinkLength", BuildingBinding::_NV_getLinkLength },
        { "getRootNode", BuildingBinding::getRootNode },
        { "getZoneMapLocation", BuildingBinding::getZoneMapLocation },
        { "_NV_getZoneMapLocation", BuildingBinding::_NV_getZoneMapLocation },
        { "clearTownBuildingsManagerPtr", BuildingBinding::clearTownBuildingsManagerPtr },
        { "_NV_clearTownBuildingsManagerPtr", BuildingBinding::_NV_clearTownBuildingsManagerPtr },
        { "setup", BuildingBinding::setup },
        { "_NV_setup", BuildingBinding::_NV_setup },
        { "setupFromData", BuildingBinding::setupFromData },
        { "_NV_setupFromData", BuildingBinding::_NV_setupFromData },
        { "setupAudio", BuildingBinding::setupAudio },
        { "switchLights", BuildingBinding::switchLights },
        { "_NV_switchLights", BuildingBinding::_NV_switchLights },
        { "switchEffects", BuildingBinding::switchEffects },
        { "_NV_switchEffects", BuildingBinding::_NV_switchEffects },
        { "hasAnyGoodPositionMarkersLeft", BuildingBinding::hasAnyGoodPositionMarkersLeft },
        { "notifyBadPositionMarker", BuildingBinding::notifyBadPositionMarker },
        { "getPositionMarker", BuildingBinding::getPositionMarker },
        { "_NV_getPositionMarker", BuildingBinding::_NV_getPositionMarker },
        { "getDirectionMarker", BuildingBinding::getDirectionMarker },
        { "_NV_getDirectionMarker", BuildingBinding::_NV_getDirectionMarker },
        { "getDirectionMarkerQuat", BuildingBinding::getDirectionMarkerQuat },
        { "_NV_getDirectionMarkerQuat", BuildingBinding::_NV_getDirectionMarkerQuat },
        { "isCreated", BuildingBinding::isCreated },
        { "_NV_isCreated", BuildingBinding::_NV_isCreated },
        { "updateUsageNodes", BuildingBinding::updateUsageNodes },
        { "forceValidUsageNodesValidation", BuildingBinding::forceValidUsageNodesValidation },
        { "addUsageNode", BuildingBinding::addUsageNode },
        { "removeUsageNode", BuildingBinding::removeUsageNode },
        { "clearUsageNodes", BuildingBinding::clearUsageNodes },
        { "notifyEffect", BuildingBinding::notifyEffect },
        { "_NV_notifyEffect", BuildingBinding::_NV_notifyEffect },
        { "updatePhysicalWithProgress", BuildingBinding::updatePhysicalWithProgress },
        { "recalculateWorldAABB", BuildingBinding::recalculateWorldAABB },
        { "selectPartMaterial", BuildingBinding::selectPartMaterial },
        { "getSeed", BuildingBinding::getSeed },
        { "onBuildingLoaded", BuildingBinding::onBuildingLoaded },
        { "_NV_onBuildingLoaded", BuildingBinding::_NV_onBuildingLoaded },
        { "updateBadNodes", BuildingBinding::updateBadNodes },
        { 0, 0 }
    };

    registerClass(
        L, 
        BuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, Building_get_isFoliage);
    lua_setfield(L, -2, "isFoliage");
    lua_pushcfunction(L, Building_get_hasTerrainInside);
    lua_setfield(L, -2, "hasTerrainInside");
    lua_pushcfunction(L, Building_get_isCavernous);
    lua_setfield(L, -2, "isCavernous");
    lua_pushcfunction(L, Building_get_enforceCeiling);
    lua_setfield(L, -2, "enforceCeiling");
    lua_pushcfunction(L, Building_get_designation);
    lua_setfield(L, -2, "designation");
    lua_pushcfunction(L, Building_get_publicDaytime);
    lua_setfield(L, -2, "publicDaytime");
    lua_pushcfunction(L, Building_get_residentSquad);
    lua_setfield(L, -2, "residentSquad");
    lua_pushcfunction(L, Building_get_residentSquadTemplate);
    lua_setfield(L, -2, "residentSquadTemplate");
    lua_pushcfunction(L, Building_get_isAnInteriorObject);
    lua_setfield(L, -2, "isAnInteriorObject");
    lua_pushcfunction(L, Building_get_instanceID);
    lua_setfield(L, -2, "instanceID");
    lua_pushcfunction(L, Building_get_layoutInstanceID);
    lua_setfield(L, -2, "layoutInstanceID");
    lua_pushcfunction(L, Building_get_specialFunction);
    lua_setfield(L, -2, "specialFunction");
    lua_pushcfunction(L, Building_get__buildState);
    lua_setfield(L, -2, "_buildState");
    lua_pushcfunction(L, Building_get_classType);
    lua_setfield(L, -2, "classType");
    lua_pushcfunction(L, Building_get_updateNavmesh);
    lua_setfield(L, -2, "updateNavmesh");
    lua_pushcfunction(L, Building_get_visible);
    lua_setfield(L, -2, "visible");
    lua_pushcfunction(L, Building_get_interiorVisibility);
    lua_setfield(L, -2, "interiorVisibility");
    lua_pushcfunction(L, Building_get_justBeenUpgradedFlag);
    lua_setfield(L, -2, "justBeenUpgradedFlag");
    lua_pushcfunction(L, Building_get_imADoor);
    lua_setfield(L, -2, "imADoor");
    lua_pushcfunction(L, Building_get_destroyed);
    lua_setfield(L, -2, "destroyed");
    lua_pushcfunction(L, Building_get_productionMult);
    lua_setfield(L, -2, "productionMult");
    lua_pushcfunction(L, Building_get_productionMult_baseData);
    lua_setfield(L, -2, "productionMult_baseData");
    lua_pushcfunction(L, Building_get_hasMovingParts);
    lua_setfield(L, -2, "hasMovingParts");
    lua_pushcfunction(L, Building_get_saveVersion);
    lua_setfield(L, -2, "saveVersion");
    lua_pushcfunction(L, Building_get__town);
    lua_setfield(L, -2, "_town");
    lua_pushcfunction(L, Building_get_myInterior);
    lua_setfield(L, -2, "myInterior");
    lua_pushcfunction(L, Building_get_buildingsManager);
    lua_setfield(L, -2, "buildingsManager");
    lua_pushcfunction(L, Building_get_rootNode);
    lua_setfield(L, -2, "rootNode");
    lua_pushcfunction(L, Building_get_soundEmitter);
    lua_setfield(L, -2, "soundEmitter");
    lua_pushcfunction(L, Building_get_hasAudio);
    lua_setfield(L, -2, "hasAudio");
    lua_pushcfunction(L, Building_get_interiorGround);
    lua_setfield(L, -2, "interiorGround");
    lua_pushcfunction(L, Building_get_exteriorGround);
    lua_setfield(L, -2, "exteriorGround");
    lua_pushcfunction(L, Building_get_physical);
    lua_setfield(L, -2, "physical");
    lua_pushcfunction(L, Building_get_entitiesToLoad);
    lua_setfield(L, -2, "entitiesToLoad");
    lua_pushcfunction(L, Building_get_entitiesLoaded);
    lua_setfield(L, -2, "entitiesLoaded");
    lua_pushcfunction(L, Building_get_isFurnitureOf);
    lua_setfield(L, -2, "isFurnitureOf");
    lua_pushcfunction(L, Building_get_isOutsideFurniture);
    lua_setfield(L, -2, "isOutsideFurniture");
    lua_pushcfunction(L, Building_get_isNestItem);
    lua_setfield(L, -2, "isNestItem");
    lua_pushcfunction(L, Building_get_baseMaterial);
    lua_setfield(L, -2, "baseMaterial");
    lua_pushcfunction(L, Building_get_effectsVisible);
    lua_setfield(L, -2, "effectsVisible");
    lua_pushcfunction(L, Building_get_effectsActive);
    lua_setfield(L, -2, "effectsActive");
    lua_pushcfunction(L, Building_get_lightsVisible);
    lua_setfield(L, -2, "lightsVisible");
    lua_pushcfunction(L, Building_get_positionMarker);
    lua_setfield(L, -2, "positionMarker");
    lua_pushcfunction(L, Building_get_heightAboveGround);
    lua_setfield(L, -2, "heightAboveGround");
    lua_pushcfunction(L, Building_get_isRedDebugTextureMode);
    lua_setfield(L, -2, "isRedDebugTextureMode");
    lua_pushcfunction(L, Building_get_materialName);
    lua_setfield(L, -2, "materialName");
    lua_pushcfunction(L, Building_get_triggerVolume);
    lua_setfield(L, -2, "triggerVolume");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Building_set_isFoliage);
    lua_setfield(L, -2, "isFoliage");
    lua_pushcfunction(L, Building_set_hasTerrainInside);
    lua_setfield(L, -2, "hasTerrainInside");
    lua_pushcfunction(L, Building_set_isCavernous);
    lua_setfield(L, -2, "isCavernous");
    lua_pushcfunction(L, Building_set_enforceCeiling);
    lua_setfield(L, -2, "enforceCeiling");
    lua_pushcfunction(L, Building_set_designation);
    lua_setfield(L, -2, "designation");
    lua_pushcfunction(L, Building_set_publicDaytime);
    lua_setfield(L, -2, "publicDaytime");
    lua_pushcfunction(L, Building_set_residentSquad);
    lua_setfield(L, -2, "residentSquad");
    lua_pushcfunction(L, Building_set_residentSquadTemplate);
    lua_setfield(L, -2, "residentSquadTemplate");
    lua_pushcfunction(L, Building_set_isAnInteriorObject);
    lua_setfield(L, -2, "isAnInteriorObject");
    lua_pushcfunction(L, Building_set_instanceID);
    lua_setfield(L, -2, "instanceID");
    lua_pushcfunction(L, Building_set_layoutInstanceID);
    lua_setfield(L, -2, "layoutInstanceID");
    lua_pushcfunction(L, Building_set_specialFunction);
    lua_setfield(L, -2, "specialFunction");
    lua_pushcfunction(L, Building_set__buildState);
    lua_setfield(L, -2, "_buildState");
    lua_pushcfunction(L, Building_set_classType);
    lua_setfield(L, -2, "classType");
    lua_pushcfunction(L, Building_set_updateNavmesh);
    lua_setfield(L, -2, "updateNavmesh");
    lua_pushcfunction(L, Building_set_visible);
    lua_setfield(L, -2, "visible");
    lua_pushcfunction(L, Building_set_interiorVisibility);
    lua_setfield(L, -2, "interiorVisibility");
    lua_pushcfunction(L, Building_set_justBeenUpgradedFlag);
    lua_setfield(L, -2, "justBeenUpgradedFlag");
    lua_pushcfunction(L, Building_set_imADoor);
    lua_setfield(L, -2, "imADoor");
    lua_pushcfunction(L, Building_set_destroyed);
    lua_setfield(L, -2, "destroyed");
    lua_pushcfunction(L, Building_set_productionMult);
    lua_setfield(L, -2, "productionMult");
    lua_pushcfunction(L, Building_set_productionMult_baseData);
    lua_setfield(L, -2, "productionMult_baseData");
    lua_pushcfunction(L, Building_set_hasMovingParts);
    lua_setfield(L, -2, "hasMovingParts");
    lua_pushcfunction(L, Building_set_saveVersion);
    lua_setfield(L, -2, "saveVersion");
    lua_pushcfunction(L, Building_set__town);
    lua_setfield(L, -2, "_town");
    lua_pushcfunction(L, Building_set_buildingsManager);
    lua_setfield(L, -2, "buildingsManager");
    lua_pushcfunction(L, Building_set_hasAudio);
    lua_setfield(L, -2, "hasAudio");
    lua_pushcfunction(L, Building_set_interiorGround);
    lua_setfield(L, -2, "interiorGround");
    lua_pushcfunction(L, Building_set_exteriorGround);
    lua_setfield(L, -2, "exteriorGround");
    lua_pushcfunction(L, Building_set_entitiesToLoad);
    lua_setfield(L, -2, "entitiesToLoad");
    lua_pushcfunction(L, Building_set_entitiesLoaded);
    lua_setfield(L, -2, "entitiesLoaded");
    lua_pushcfunction(L, Building_set_isOutsideFurniture);
    lua_setfield(L, -2, "isOutsideFurniture");
    lua_pushcfunction(L, Building_set_isNestItem);
    lua_setfield(L, -2, "isNestItem");
    lua_pushcfunction(L, Building_set_baseMaterial);
    lua_setfield(L, -2, "baseMaterial");
    lua_pushcfunction(L, Building_set_effectsVisible);
    lua_setfield(L, -2, "effectsVisible");
    lua_pushcfunction(L, Building_set_effectsActive);
    lua_setfield(L, -2, "effectsActive");
    lua_pushcfunction(L, Building_set_lightsVisible);
    lua_setfield(L, -2, "lightsVisible");
    lua_pushcfunction(L, Building_set_positionMarker);
    lua_setfield(L, -2, "positionMarker");
    lua_pushcfunction(L, Building_set_heightAboveGround);
    lua_setfield(L, -2, "heightAboveGround");
    lua_pushcfunction(L, Building_set_isRedDebugTextureMode);
    lua_setfield(L, -2, "isRedDebugTextureMode");
    lua_pushcfunction(L, Building_set_materialName);
    lua_setfield(L, -2, "materialName");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to RootObject
    // setMetatableParent(L, BuildingBinding::getMetatableName(), RootObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua