#include "pch.h"
#include "kenshi\Building\Building.h"
#include "BuildingBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/TownBinding.h"

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
    // TODO: Unsupported type for residentSquad (hand)
    lua_pushnil(L);
    return 1;
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
    // TODO: Unsupported type for instanceID (InstanceID)
    lua_pushnil(L);
    return 1;
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
    // TODO: Unsupported type for _buildState (ConstructionState)
    lua_pushnil(L);
    return 1;
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

static int Building_get_doors(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for doors (lektor<Building*>)
    lua_pushnil(L);
    return 1;
}

static int Building_get__town(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for _town (hand)
    lua_pushnil(L);
    return 1;
}

static int Building_get_myInterior(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for myInterior (BuildingInterior*)
    lua_pushnil(L);
    return 1;
}

static int Building_get_buildingsManager(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for buildingsManager (TownBuildingsManager*)
    lua_pushnil(L);
    return 1;
}

static int Building_get_rootNode(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for rootNode (Ogre::SceneNode*)
    lua_pushnil(L);
    return 1;
}

static int Building_get_audioObject(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for audioObject (unsigned __int64)
    lua_pushnil(L);
    return 1;
}

static int Building_get_soundEmitter(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for soundEmitter (SoundEmitter*)
    lua_pushnil(L);
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

static int Building_get_physical(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for physical (PhysicsCollection*)
    lua_pushnil(L);
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

static int Building_get_isFurnitureOf(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for isFurnitureOf (Layout*)
    lua_pushnil(L);
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

static int Building_get_effects(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for effects (lektor<std::pair<PhysicalEntity*, Effect*> >)
    lua_pushnil(L);
    return 1;
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

static int Building_get_AABB(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for AABB (Ogre::Aabb)
    lua_pushnil(L);
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

static int Building_get_usageNodesIds(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for usageNodesIds (std::set<std::string, std::less<std::string >, Ogre::STLAllocator<std::string, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
    return 1;
}

static int Building_get_usageNodes(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for usageNodes (lektor<UsageNode*>)
    lua_pushnil(L);
    return 1;
}

static int Building_get_badNodes(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for badNodes (ogre_unordered_map<int, float>::type)
    lua_pushnil(L);
    return 1;
}

static int Building_get_triggerVolume(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for triggerVolume (SimplePhysXEntity*)
    lua_pushnil(L);
    return 1;
}

static int Building_get_activeEffects(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    // TODO: Unsupported type for activeEffects (lektor<std::pair<char, float> >)
    lua_pushnil(L);
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
    return luaL_error(L, "Read-only or unsupported setter type for residentSquad");
}

static int Building_set_residentSquadTemplate(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for residentSquadTemplate");
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
    return luaL_error(L, "Read-only or unsupported setter type for instanceID");
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
    return luaL_error(L, "Read-only or unsupported setter type for _buildState");
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

static int Building_set_doors(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for doors");
}

static int Building_set__town(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _town");
}

static int Building_set_myInterior(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for myInterior");
}

static int Building_set_buildingsManager(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for buildingsManager");
}

static int Building_set_rootNode(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for rootNode");
}

static int Building_set_audioObject(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for audioObject");
}

static int Building_set_soundEmitter(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for soundEmitter");
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

static int Building_set_physical(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for physical");
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

static int Building_set_isFurnitureOf(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isFurnitureOf");
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
    return luaL_error(L, "Read-only or unsupported setter type for baseMaterial");
}

static int Building_set_effects(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for effects");
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

static int Building_set_AABB(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for AABB");
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

static int Building_set_usageNodesIds(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for usageNodesIds");
}

static int Building_set_usageNodes(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for usageNodes");
}

static int Building_set_badNodes(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for badNodes");
}

static int Building_set_triggerVolume(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for triggerVolume");
}

static int Building_set_activeEffects(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");
    return luaL_error(L, "Read-only or unsupported setter type for activeEffects");
}

int BuildingBinding::getScale(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    float result = instance->getScale();
    lua_pushnumber(L, result);
    return 1;
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

    std::string mod = luaL_checkstring(L, 2);
    bool result = instance->needsSaving(mod);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_needsSaving(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    std::string mod = luaL_checkstring(L, 2);
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

int BuildingBinding::calculateLeftPost(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    Ogre::Vector3 result = instance->calculateLeftPost();
    pushVector3(L, result);
    return 1;
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

    std::string nodeId = luaL_checkstring(L, 2);
    instance->addUsageNode(nodeId);
    return 0;
}

int BuildingBinding::removeUsageNode(lua_State* L)
{
    Building* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Building is nil");

    std::string nodeId = luaL_checkstring(L, 2);
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
  line 143: ConstructionState* getBuildState(...) - unsupported return type
  line 144: ConstructionState* _NV_getBuildState(...) - unsupported return type
  line 145: ConstructionState* getBuildState_ActualNonShared(...) - unsupported return type
  line 161: void upgrade(...) - unsupported arg type
  line 162: void _NV_upgrade(...) - unsupported arg type
  line 163: void downgrade(...) - unsupported arg type
  line 164: void _NV_downgrade(...) - unsupported arg type
  line 171: void buyMeAsk(...) - unsupported arg type
  line 172: void _NV_buyMeAsk(...) - unsupported arg type
  line 179: void togglePublic(...) - unsupported arg type
  line 180: void _NV_togglePublic(...) - unsupported arg type
  line 181: void dismantleButton(...) - unsupported arg type
  line 182: void _NV_dismantleButton(...) - unsupported arg type
  line 183: void pauseButton(...) - unsupported arg type
  line 184: void _NV_pauseButton(...) - unsupported arg type
  line 192: WallBuilding* isAWall(...) - unsupported return type
  line 193: WallBuilding* _NV_isAWall(...) - unsupported return type
  line 200: void setResidentSquad(...) - unsupported arg type
  line 208: void addAnInternalBuilding(...) - unsupported arg type
  line 209: void removeAnInternalBuilding(...) - unsupported arg type
  line 211: void addAnInternalItem(...) - unsupported arg type
  line 212: void removeAnInternalItem(...) - unsupported arg type
  line 214: int getMountedBuildings(...) - unsupported arg type
  line 216: void setHandle(...) - unsupported arg type
  line 217: void _NV_setHandle(...) - unsupported arg type
  line 225: StorageBuilding* getFunctionStuff(...) - unsupported return type
  line 226: StorageBuilding* _NV_getFunctionStuff(...) - unsupported return type
  line 227: UseableStuff* getUseableStuff(...) - unsupported return type
  line 228: UseableStuff* _NV_getUseableStuff(...) - unsupported return type
  line 258: InstanceID* getInstanceID(...) - unsupported return type
  line 259: InstanceID* _NV_getInstanceID(...) - unsupported return type
  line 260: const std::string& getLayoutInstanceID(...) - reference return type
  line 261: const std::string& _NV_getLayoutInstanceID(...) - reference return type
  line 268: Building* _CONSTRUCTOR(...) - unsupported arg type
  line 290: void _saveBuildingState(...) - unsupported arg type
  line 291: void _NV__saveBuildingState(...) - unsupported arg type
  line 292: void _loadBuildingState(...) - unsupported arg type
  line 293: void _NV__loadBuildingState(...) - unsupported arg type
  line 294: void getGUIName(...) - unsupported arg type
  line 295: void _NV_getGUIName(...) - unsupported arg type
  line 296: void getGUIState(...) - unsupported arg type
  line 297: void _NV_getGUIState(...) - unsupported arg type
  line 298: void getGUICondition(...) - unsupported arg type
  line 299: void _NV_getGUICondition(...) - unsupported arg type
  line 300: void getGUIUpgrade(...) - unsupported arg type
  line 301: void _NV_getGUIUpgrade(...) - unsupported arg type
  line 302: void getGUIDestroyButton(...) - unsupported arg type
  line 303: void _NV_getGUIDestroyButton(...) - unsupported arg type
  line 305: void findAllFurnitureWithFunction(...) - unsupported arg type
  line 306: ProductionBuilding* getProductionBuilding(...) - unsupported return type
  line 307: ProductionBuilding* _NV_getProductionBuilding(...) - unsupported return type
  line 314: DoorStuff* doorStuff(...) - unsupported return type
  line 315: DoorStuff* _NV_doorStuff(...) - unsupported return type
  line 319: GatewayBuilding* isGate(...) - unsupported return type
  line 320: GatewayBuilding* _NV_isGate(...) - unsupported return type
  line 321: DoorStuff* getDoor(...) - unsupported return type
  line 322: DoorStuff* _NV_getDoor(...) - unsupported return type
  line 323: Layout* getParentLayout(...) - unsupported return type
  line 343: GameSaveState serialise(...) - unsupported return type
  line 344: GameSaveState _NV_serialise(...) - unsupported return type
  line 345: void loadFromSerialise(...) - unsupported arg type
  line 346: void _NV_loadFromSerialise(...) - unsupported arg type
  line 347: void loadFromSerialise_TheDoors(...) - unsupported arg type
  line 348: void _NV_loadFromSerialise_TheDoors(...) - unsupported arg type
  line 349: void getGUIData(...) - unsupported arg type
  line 350: void _NV_getGUIData(...) - unsupported arg type
  line 355: DoorLock* getDoorLock(...) - unsupported return type
  line 356: DoorLock* _NV_getDoorLock(...) - unsupported return type
  line 365: const Ogre::Aabb& getAABB(...) - overloaded method
  line 366: const Ogre::Aabb& _NV_getAABB(...) - overloaded method
  line 367: Ogre::Aabb getAABB(...) - overloaded method
  line 368: Ogre::Aabb _NV_getAABB(...) - overloaded method
  line 369: void setAABB(...) - unsupported arg type
  line 370: void _changeTown(...) - unsupported arg type
  line 372: hand getTownHandle(...) - unsupported return type
  line 382: unsigned __int64 getAudioObject(...) - unsupported return type
  line 386: const hand& isIndoors(...) - reference return type
  line 387: const hand& _NV_isIndoors(...) - reference return type
  line 388: const hand& isIndoors_notDestroyed(...) - reference return type
  line 389: const hand& _NV_isIndoors_notDestroyed(...) - reference return type
  line 390: const hand& getMountedBuilding(...) - reference return type
  line 391: const hand& _NV_getMountedBuilding(...) - reference return type
  line 392: int getLights(...) - unsupported arg type
  line 398: void setFaction(...) - unsupported arg type
  line 399: void _NV_setFaction(...) - unsupported arg type
  line 401: void setupLevelData(...) - unsupported arg type
  line 405: Ogre::SceneNode* getRootNode(...) - unsupported return type
  line 406: ZoneMap* getZoneMapLocation(...) - unsupported return type
  line 407: ZoneMap* _NV_getZoneMapLocation(...) - unsupported return type
  line 456: Ogre::SharedPtr<Ogre::Material> getBuildingPartMaterial(...) - static method
  line 457: void setBuildingPartMaterial(...) - static method
  line 458: void restoreMaterialToPhysical(...) - unsupported arg type
  line 462: void updateWorldAABB(...) - unsupported arg type
  line 467: GameData* selectPartMaterial(...) - unsupported arg type
  line 468: Ogre::SharedPtr<Ogre::Material> getPartMaterial(...) - unsupported return type
  line 469: void selectParts(...) - static method
  line 470: void loadParts(...) - unsupported arg type
  line 471: PhysicalEntity* loadPartEntity(...) - unsupported return type
  line 472: Ogre::MovableObject* loadEntity(...) - unsupported return type
  line 473: void loadEntityCallback(...) - unsupported arg type
  line 474: void loadInstances(...) - unsupported arg type
  line 476: PhysicalEntity* findPhysicalEntity(...) - unsupported return type
  line 477: PhysicalEntity* findPhysicalEntityInCollection(...) - static method
  line 478: bool buildingContainsEntity(...) - static method
  line 479: std::string getEntityMaterialName(...) - static method
  line 482: void setPartVisible(...) - unsupported arg type
  line 483: void _NV_setPartVisible(...) - unsupported arg type
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
        { "canUpgrade", BuildingBinding::canUpgrade },
        { "_NV_canUpgrade", BuildingBinding::_NV_canUpgrade },
        { "canDowngrade", BuildingBinding::canDowngrade },
        { "_NV_canDowngrade", BuildingBinding::_NV_canDowngrade },
        { "canDismantle", BuildingBinding::canDismantle },
        { "_NV_canDismantle", BuildingBinding::_NV_canDismantle },
        { "buyMeCallback", BuildingBinding::buyMeCallback },
        { "_NV_buyMeCallback", BuildingBinding::_NV_buyMeCallback },
        { "calculateSaleValue", BuildingBinding::calculateSaleValue },
        { "loadNodes", BuildingBinding::loadNodes },
        { "isPublic", BuildingBinding::isPublic },
        { "_NV_isPublic", BuildingBinding::_NV_isPublic },
        { "confirmDismantle", BuildingBinding::confirmDismantle },
        { "_NV_confirmDismantle", BuildingBinding::_NV_confirmDismantle },
        { "isAShop", BuildingBinding::isAShop },
        { "_NV_isAShop", BuildingBinding::_NV_isAShop },
        { "isForSale", BuildingBinding::isForSale },
        { "_NV_isForSale", BuildingBinding::_NV_isForSale },
        { "isAWallRamp", BuildingBinding::isAWallRamp },
        { "_NV_isAWallRamp", BuildingBinding::_NV_isAWallRamp },
        { "hasInterior", BuildingBinding::hasInterior },
        { "affectsNavmesh", BuildingBinding::affectsNavmesh },
        { "getResidentSquadLeader", BuildingBinding::getResidentSquadLeader },
        { "setDesignation", BuildingBinding::setDesignation },
        { "getWallEndPosition", BuildingBinding::getWallEndPosition },
        { "setupMiningResourceLevel", BuildingBinding::setupMiningResourceLevel },
        { "_NV_setupMiningResourceLevel", BuildingBinding::_NV_setupMiningResourceLevel },
        { "getMiningResourceLevel", BuildingBinding::getMiningResourceLevel },
        { "_NV_getMiningResourceLevel", BuildingBinding::_NV_getMiningResourceLevel },
        { "getNumInternalBuildings", BuildingBinding::getNumInternalBuildings },
        { "moveMountedBuildings", BuildingBinding::moveMountedBuildings },
        { "reCheckInsideOutsideFortificationStatus", BuildingBinding::reCheckInsideOutsideFortificationStatus },
        { "setInsideTownWalls", BuildingBinding::setInsideTownWalls },
        { "_NV_setInsideTownWalls", BuildingBinding::_NV_setInsideTownWalls },
        { "postCreationPathfinderSetupStuff", BuildingBinding::postCreationPathfinderSetupStuff },
        { "_NV_postCreationPathfinderSetupStuff", BuildingBinding::_NV_postCreationPathfinderSetupStuff },
        { "getSpecialFunction", BuildingBinding::getSpecialFunction },
        { "_NV_getSpecialFunction", BuildingBinding::_NV_getSpecialFunction },
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
        { "getProductionMultForGUI", BuildingBinding::getProductionMultForGUI },
        { "_NV_getProductionMultForGUI", BuildingBinding::_NV_getProductionMultForGUI },
        { "getProductionMult", BuildingBinding::getProductionMult },
        { "_NV_getProductionMult", BuildingBinding::_NV_getProductionMult },
        { "isThePlayer", BuildingBinding::isThePlayer },
        { "doorParentBuilding", BuildingBinding::doorParentBuilding },
        { "_NV_doorParentBuilding", BuildingBinding::_NV_doorParentBuilding },
        { "isDoor", BuildingBinding::isDoor },
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
        { "setVisible", BuildingBinding::setVisible },
        { "_NV_setVisible", BuildingBinding::_NV_setVisible },
        { "getVisible", BuildingBinding::getVisible },
        { "_NV_getVisible", BuildingBinding::_NV_getVisible },
        { "hasDoorLock", BuildingBinding::hasDoorLock },
        { "_NV_hasDoorLock", BuildingBinding::_NV_hasDoorLock },
        { "getMouseCursor", BuildingBinding::getMouseCursor },
        { "_NV_getMouseCursor", BuildingBinding::_NV_getMouseCursor },
        { "getDefaultTask", BuildingBinding::getDefaultTask },
        { "_NV_getDefaultTask", BuildingBinding::_NV_getDefaultTask },
        { "getInventory", BuildingBinding::getInventory },
        { "_NV_getInventory", BuildingBinding::_NV_getInventory },
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
        { "calculateLeftPost", BuildingBinding::calculateLeftPost },
        { "getLinkLength", BuildingBinding::getLinkLength },
        { "_NV_getLinkLength", BuildingBinding::_NV_getLinkLength },
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
    lua_pushcfunction(L, Building_get_doors);
    lua_setfield(L, -2, "doors");
    lua_pushcfunction(L, Building_get__town);
    lua_setfield(L, -2, "_town");
    lua_pushcfunction(L, Building_get_myInterior);
    lua_setfield(L, -2, "myInterior");
    lua_pushcfunction(L, Building_get_buildingsManager);
    lua_setfield(L, -2, "buildingsManager");
    lua_pushcfunction(L, Building_get_rootNode);
    lua_setfield(L, -2, "rootNode");
    lua_pushcfunction(L, Building_get_audioObject);
    lua_setfield(L, -2, "audioObject");
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
    lua_pushcfunction(L, Building_get_effects);
    lua_setfield(L, -2, "effects");
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
    lua_pushcfunction(L, Building_get_AABB);
    lua_setfield(L, -2, "AABB");
    lua_pushcfunction(L, Building_get_isRedDebugTextureMode);
    lua_setfield(L, -2, "isRedDebugTextureMode");
    lua_pushcfunction(L, Building_get_materialName);
    lua_setfield(L, -2, "materialName");
    lua_pushcfunction(L, Building_get_usageNodesIds);
    lua_setfield(L, -2, "usageNodesIds");
    lua_pushcfunction(L, Building_get_usageNodes);
    lua_setfield(L, -2, "usageNodes");
    lua_pushcfunction(L, Building_get_badNodes);
    lua_setfield(L, -2, "badNodes");
    lua_pushcfunction(L, Building_get_triggerVolume);
    lua_setfield(L, -2, "triggerVolume");
    lua_pushcfunction(L, Building_get_activeEffects);
    lua_setfield(L, -2, "activeEffects");
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
    lua_pushcfunction(L, Building_set_doors);
    lua_setfield(L, -2, "doors");
    lua_pushcfunction(L, Building_set__town);
    lua_setfield(L, -2, "_town");
    lua_pushcfunction(L, Building_set_myInterior);
    lua_setfield(L, -2, "myInterior");
    lua_pushcfunction(L, Building_set_buildingsManager);
    lua_setfield(L, -2, "buildingsManager");
    lua_pushcfunction(L, Building_set_rootNode);
    lua_setfield(L, -2, "rootNode");
    lua_pushcfunction(L, Building_set_audioObject);
    lua_setfield(L, -2, "audioObject");
    lua_pushcfunction(L, Building_set_soundEmitter);
    lua_setfield(L, -2, "soundEmitter");
    lua_pushcfunction(L, Building_set_hasAudio);
    lua_setfield(L, -2, "hasAudio");
    lua_pushcfunction(L, Building_set_interiorGround);
    lua_setfield(L, -2, "interiorGround");
    lua_pushcfunction(L, Building_set_exteriorGround);
    lua_setfield(L, -2, "exteriorGround");
    lua_pushcfunction(L, Building_set_physical);
    lua_setfield(L, -2, "physical");
    lua_pushcfunction(L, Building_set_entitiesToLoad);
    lua_setfield(L, -2, "entitiesToLoad");
    lua_pushcfunction(L, Building_set_entitiesLoaded);
    lua_setfield(L, -2, "entitiesLoaded");
    lua_pushcfunction(L, Building_set_isFurnitureOf);
    lua_setfield(L, -2, "isFurnitureOf");
    lua_pushcfunction(L, Building_set_isOutsideFurniture);
    lua_setfield(L, -2, "isOutsideFurniture");
    lua_pushcfunction(L, Building_set_isNestItem);
    lua_setfield(L, -2, "isNestItem");
    lua_pushcfunction(L, Building_set_baseMaterial);
    lua_setfield(L, -2, "baseMaterial");
    lua_pushcfunction(L, Building_set_effects);
    lua_setfield(L, -2, "effects");
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
    lua_pushcfunction(L, Building_set_AABB);
    lua_setfield(L, -2, "AABB");
    lua_pushcfunction(L, Building_set_isRedDebugTextureMode);
    lua_setfield(L, -2, "isRedDebugTextureMode");
    lua_pushcfunction(L, Building_set_materialName);
    lua_setfield(L, -2, "materialName");
    lua_pushcfunction(L, Building_set_usageNodesIds);
    lua_setfield(L, -2, "usageNodesIds");
    lua_pushcfunction(L, Building_set_usageNodes);
    lua_setfield(L, -2, "usageNodes");
    lua_pushcfunction(L, Building_set_badNodes);
    lua_setfield(L, -2, "badNodes");
    lua_pushcfunction(L, Building_set_triggerVolume);
    lua_setfield(L, -2, "triggerVolume");
    lua_pushcfunction(L, Building_set_activeEffects);
    lua_setfield(L, -2, "activeEffects");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to RootObject
    setMetatableParent(L, BuildingBinding::getMetatableName(), RootObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}
}