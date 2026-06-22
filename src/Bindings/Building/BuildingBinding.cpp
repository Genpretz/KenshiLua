#include "pch.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Building/ConstructionStateBinding.h"
#include "Bindings/Building/ProductionBuildingBinding.h"
#include "Bindings/Building/StorageBuildingBinding.h"
#include "Bindings/Equipment/InventoryBinding.h"
#include "Bindings/Character/CharacterBinding.h"
#include "Bindings/Core/EnumBinding.h"
#include "Bindings/World/FactionBinding.h"
#include "Bindings/Core/GameDataBinding.h"
#include "Bindings/World/TownBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/Building.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static Building* getB(lua_State* L, int idx)
{
    return checkObject<Building>(L, idx, BuildingBinding::getMetatableName());
}

int BuildingBinding::gc(lua_State* L) { return noopGc(L); }

int BuildingBinding::tostring(lua_State* L)
{
    Building* b = getB(L, 1);
    return genericTostringPtr(L, "%s",b);
}

int BuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, BuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    Building* b = getB(L, 1);
    if (!b) { lua_pushnil(L); return 1; }

    if (strcmp(key, "isFoliage") == 0) { lua_pushboolean(L, b->isFoliage ? 1 : 0); return 1; }
    if (strcmp(key, "hasTerrainInside") == 0) { lua_pushboolean(L, b->hasTerrainInside ? 1 : 0); return 1; }
    if (strcmp(key, "isCavernous") == 0) { lua_pushboolean(L, b->isCavernous ? 1 : 0); return 1; }
    if (strcmp(key, "enforceCeiling") == 0) { lua_pushboolean(L, b->enforceCeiling ? 1 : 0); return 1; }
    if (strcmp(key, "designation") == 0) { lua_pushinteger(L, (lua_Integer)b->designation); return 1; }
    if (strcmp(key, "publicDaytime") == 0) { lua_pushboolean(L, b->publicDaytime ? 1 : 0); return 1; }
    // TODO hand residentSquad; unsupported __index type from header line 198
    if (strcmp(key, "residentSquadTemplate") == 0) { return pushObject<GameData>(L, b->residentSquadTemplate, GameDataBinding::getMetatableName()); }
    if (strcmp(key, "isAnInteriorObject") == 0) { lua_pushboolean(L, b->isAnInteriorObject ? 1 : 0); return 1; }
    // TODO InstanceID instanceID; unsupported __index type from header line 254
    if (strcmp(key, "layoutInstanceID") == 0) { lua_pushstring(L, b->layoutInstanceID.c_str()); return 1; }
    if (strcmp(key, "specialFunction") == 0) { lua_pushinteger(L, (lua_Integer)b->specialFunction); return 1; }
    // TODO ConstructionState _buildState; unsupported __index type from header line 264
    if (strcmp(key, "classType") == 0) { lua_pushinteger(L, (lua_Integer)b->classType); return 1; }
    if (strcmp(key, "updateNavmesh") == 0) { lua_pushboolean(L, b->updateNavmesh ? 1 : 0); return 1; }
    if (strcmp(key, "visible") == 0) { lua_pushboolean(L, b->visible ? 1 : 0); return 1; }
    if (strcmp(key, "interiorVisibility") == 0) { lua_pushboolean(L, b->interiorVisibility ? 1 : 0); return 1; }
    if (strcmp(key, "justBeenUpgradedFlag") == 0) { lua_pushboolean(L, b->justBeenUpgradedFlag ? 1 : 0); return 1; }
    if (strcmp(key, "imADoor") == 0) { lua_pushboolean(L, b->imADoor ? 1 : 0); return 1; }
    if (strcmp(key, "destroyed") == 0) { lua_pushboolean(L, b->destroyed ? 1 : 0); return 1; }
    if (strcmp(key, "productionMult") == 0) { lua_pushnumber(L, b->productionMult); return 1; }
    if (strcmp(key, "productionMult_baseData") == 0) { lua_pushnumber(L, b->productionMult_baseData); return 1; }
    if (strcmp(key, "hasMovingParts") == 0) { lua_pushboolean(L, b->hasMovingParts ? 1 : 0); return 1; }
    if (strcmp(key, "saveVersion") == 0) { lua_pushinteger(L, b->saveVersion); return 1; }

    // TODO lektor<Building*> doors; unsupported __index type from header line 313
    if (strcmp(key, "doors") == 0) {
        lua_createtable(L, b->doors.size(), 0);
        for (uint32_t i = 0; i < b->doors.size(); ++i) {
            pushObject<Building>(L, b->doors[i], BuildingBinding::getMetatableName());
            lua_rawseti(L, -2, i + 1);
        }
        return 1;
    }

    // TODO hand _town; unsupported __index type from header line 371
    // TODO BuildingInterior* myInterior; unsupported __index type from header line 404
    // TODO TownBuildingsManager* buildingsManager; unsupported __index type from header line 410
    // TODO Ogre::SceneNode* rootNode; unsupported __index type from header line 411
    // TODO unsigned __int64 audioObject; unsupported __index type from header line 417
    // TODO SoundEmitter* soundEmitter; unsupported __index type from header line 418
    if (strcmp(key, "hasAudio") == 0) { lua_pushboolean(L, b->hasAudio ? 1 : 0); return 1; }
    if (strcmp(key, "interiorGround") == 0) { lua_pushinteger(L, (lua_Integer)b->interiorGround); return 1; }
    if (strcmp(key, "exteriorGround") == 0) { lua_pushinteger(L, (lua_Integer)b->exteriorGround); return 1; }
    // TODO PhysicsCollection* physical; unsupported __index type from header line 422
    if (strcmp(key, "entitiesToLoad") == 0) { lua_pushinteger(L, b->entitiesToLoad); return 1; }
    if (strcmp(key, "entitiesLoaded") == 0) { lua_pushboolean(L, b->entitiesLoaded ? 1 : 0); return 1; }

    // TODO Layout* isFurnitureOf; unsupported __index type from header line 425
    if (strcmp(key, "isFurnitureOf") == 0) {
            if (b->isFurnitureOf) lua_pushlightuserdata(L, (void*)b->isFurnitureOf);
            else                 lua_pushnil(L);
            return 1;
    }
    
    if (strcmp(key, "isOutsideFurniture") == 0) { lua_pushboolean(L, b->isOutsideFurniture ? 1 : 0); return 1; }
    if (strcmp(key, "isNestItem") == 0) { lua_pushboolean(L, b->isNestItem ? 1 : 0); return 1; }
    if (strcmp(key, "baseMaterial") == 0) { return pushObject<GameData>(L, b->baseMaterial, GameDataBinding::getMetatableName()); }
    // TODO lektor<std::pair<PhysicalEntity*, Effect*> > effects; unsupported __index type from header line 429
    if (strcmp(key, "effectsVisible") == 0) { lua_pushboolean(L, b->effectsVisible ? 1 : 0); return 1; }
    if (strcmp(key, "effectsActive") == 0) { lua_pushboolean(L, b->effectsActive ? 1 : 0); return 1; }
    if (strcmp(key, "lightsVisible") == 0) { lua_pushboolean(L, b->lightsVisible ? 1 : 0); return 1; }
    // TODO Ogre::Vector3 positionMarker; unsupported __index type from header line 459
    if (strcmp(key, "heightAboveGround") == 0) { lua_pushnumber(L, b->heightAboveGround); return 1; }
    // TODO Ogre::Aabb AABB; unsupported __index type from header line 464
    if (strcmp(key, "isRedDebugTextureMode") == 0) { lua_pushboolean(L, b->isRedDebugTextureMode ? 1 : 0); return 1; }
    if (strcmp(key, "materialName") == 0) { lua_pushstring(L, b->materialName.c_str()); return 1; }
    // TODO std::set<std::string, std::less<std::string >, Ogre::STLAllocator<std::string, Ogre::GeneralAllocPolicy > > usageNodesIds; unsupported __index type from header line 484
    // TODO lektor<UsageNode*> usageNodes; unsupported __index type from header line 485
    // TODO ogre_unordered_map<int, float>::type badNodes; unsupported __index type from header line 486
    // TODO SimplePhysXEntity* triggerVolume; unsupported __index type from header line 488
    // TODO lektor<std::pair<char, float> > activeEffects; unsupported __index type from header line 489

    lua_pushnil(L);
    return 1;
}

int BuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    if (strcmp(key, "isFoliage") == 0) { b->isFoliage = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "hasTerrainInside") == 0) { b->hasTerrainInside = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "isCavernous") == 0) { b->isCavernous = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "enforceCeiling") == 0) { b->enforceCeiling = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "designation") == 0) { b->designation = (BuildingDesignation)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "publicDaytime") == 0) { b->publicDaytime = lua_toboolean(L, 3) != 0; return 0; }
    // TODO hand residentSquad; unsupported __newindex type from header line 198
    // TODO GameData* residentSquadTemplate; unsupported __newindex type from header line 199
    if (strcmp(key, "isAnInteriorObject") == 0) { b->isAnInteriorObject = lua_toboolean(L, 3) != 0; return 0; }
    // TODO InstanceID instanceID; unsupported __newindex type from header line 254
    if (strcmp(key, "layoutInstanceID") == 0) { b->layoutInstanceID = luaL_checkstring(L, 3); return 0; }
    if (strcmp(key, "specialFunction") == 0) { b->specialFunction = (BuildingFunction)luaL_checkinteger(L, 3); return 0; }
    // TODO ConstructionState _buildState; unsupported __newindex type from header line 264
    if (strcmp(key, "classType") == 0) { b->classType = (BuildingClassType)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "updateNavmesh") == 0) { b->updateNavmesh = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "visible") == 0) { b->visible = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "interiorVisibility") == 0) { b->interiorVisibility = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "justBeenUpgradedFlag") == 0) { b->justBeenUpgradedFlag = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "imADoor") == 0) { b->imADoor = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "destroyed") == 0) { b->destroyed = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "productionMult") == 0) { b->productionMult = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "productionMult_baseData") == 0) { b->productionMult_baseData = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "hasMovingParts") == 0) { b->hasMovingParts = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "saveVersion") == 0) { b->saveVersion = (int)luaL_checkinteger(L, 3); return 0; }
    // TODO lektor<Building*> doors; unsupported __newindex type from header line 313
    // TODO hand _town; unsupported __newindex type from header line 371
    // TODO BuildingInterior* myInterior; unsupported __newindex type from header line 404
    // TODO TownBuildingsManager* buildingsManager; unsupported __newindex type from header line 410
    // TODO Ogre::SceneNode* rootNode; unsupported __newindex type from header line 411
    // TODO unsigned __int64 audioObject; unsupported __newindex type from header line 417
    // TODO SoundEmitter* soundEmitter; unsupported __newindex type from header line 418
    if (strcmp(key, "hasAudio") == 0) { b->hasAudio = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "interiorGround") == 0) { b->interiorGround = (GroundType)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "exteriorGround") == 0) { b->exteriorGround = (GroundType)luaL_checkinteger(L, 3); return 0; }
    // TODO PhysicsCollection* physical; unsupported __newindex type from header line 422
    if (strcmp(key, "entitiesToLoad") == 0) { b->entitiesToLoad = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "entitiesLoaded") == 0) { b->entitiesLoaded = lua_toboolean(L, 3) != 0; return 0; }
    // TODO Layout* isFurnitureOf; unsupported __newindex type from header line 425
    if (strcmp(key, "isOutsideFurniture") == 0) { b->isOutsideFurniture = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "isNestItem") == 0) { b->isNestItem = lua_toboolean(L, 3) != 0; return 0; }
    // TODO GameData* baseMaterial; unsupported __newindex type from header line 428
    // TODO lektor<std::pair<PhysicalEntity*, Effect*> > effects; unsupported __newindex type from header line 429
    if (strcmp(key, "effectsVisible") == 0) { b->effectsVisible = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "effectsActive") == 0) { b->effectsActive = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "lightsVisible") == 0) { b->lightsVisible = lua_toboolean(L, 3) != 0; return 0; }
    // TODO Ogre::Vector3 positionMarker; unsupported __newindex type from header line 459
    if (strcmp(key, "heightAboveGround") == 0) { b->heightAboveGround = (float)luaL_checknumber(L, 3); return 0; }
    // TODO Ogre::Aabb AABB; unsupported __newindex type from header line 464
    if (strcmp(key, "isRedDebugTextureMode") == 0) { b->isRedDebugTextureMode = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "materialName") == 0) { b->materialName = luaL_checkstring(L, 3); return 0; }
    // TODO std::set<std::string, std::less<std::string >, Ogre::STLAllocator<std::string, Ogre::GeneralAllocPolicy > > usageNodesIds; unsupported __newindex type from header line 484
    // TODO lektor<UsageNode*> usageNodes; unsupported __newindex type from header line 485
    // TODO ogre_unordered_map<int, float>::type badNodes; unsupported __newindex type from header line 486
    // TODO SimplePhysXEntity* triggerVolume; unsupported __newindex type from header line 488
    // TODO lektor<std::pair<char, float> > activeEffects; unsupported __newindex type from header line 489

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int BuildingBinding::getName(lua_State* L)
{
    Building* b = getB(L, 1);
    if (b) lua_pushstring(L, b->getName().c_str()); else lua_pushnil(L);
    return 1;
}

// int BuildingBinding::getConstructionProgress(lua_State* L)
// {
//     Building* b = getB(L, 1);
//     if (!b) { lua_pushnil(L); return 1; }
//     Building::ConstructionState* s = b->getBuildState();
//     if (s) lua_pushnumber(L, s->constructionProgress);
//     else   lua_pushnumber(L, 0);
//     return 1;
// }

int BuildingBinding::getScale(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->getScale();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::getBuildState(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    Building::ConstructionState* result = b->getBuildState();
    return pushObject<Building::ConstructionState>(L, result, ConstructionStateBinding::getMetatableName());
}

// int BuildingBinding::getBuildState(lua_State* L)
// {
//     Building* b = getB(L, 1);
//     if (!b) { lua_pushnil(L); return 1; }
//     Building::ConstructionState* state = b->getBuildState();
//     if (!state) { lua_pushnil(L); return 1; }
//     lua_createtable(L, 0, 6);
//     lua_pushboolean(L, state->isComplete ? 1 : 0);     lua_setfield(L, -2, "isComplete");
//     lua_pushboolean(L, state->isPaused ? 1 : 0);       lua_setfield(L, -2, "isPaused");
//     lua_pushboolean(L, state->isDismantled ? 1 : 0);   lua_setfield(L, -2, "isDismantled");
//     lua_pushnumber(L,  state->constructionProgress);   lua_setfield(L, -2, "constructionProgress");
//     lua_pushnumber(L,  state->getHealthBarProgress()); lua_setfield(L, -2, "healthBarProgress");
//     lua_pushnumber(L,  state->getConstructionMaterialProgress()); lua_setfield(L, -2, "materialProgress");
//     return 1;
// }

int BuildingBinding::_NV_getBuildState(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    Building::ConstructionState* result = b->_NV_getBuildState();
    return pushObject<Building::ConstructionState>(L, result, ConstructionStateBinding::getMetatableName());
}

int BuildingBinding::getBuildState_ActualNonShared(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    Building::ConstructionState* result = b->getBuildState_ActualNonShared();
    return pushObject<Building::ConstructionState>(L, result, ConstructionStateBinding::getMetatableName());
}

int BuildingBinding::select(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->select();
    return 0;
}

int BuildingBinding::_NV_select(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_NV_select();
    return 0;
}

int BuildingBinding::getBuildingDesignation(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    BuildingDesignation result = b->getBuildingDesignation();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::addConstructionProgress(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float amount = (float)luaL_checknumber(L, 2);
    b->addConstructionProgress(amount);
    return 0;
}

int BuildingBinding::_NV_addConstructionProgress(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float amount = (float)luaL_checknumber(L, 2);
    b->_NV_addConstructionProgress(amount);
    return 0;
}

int BuildingBinding::setConstructionProgress(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float amount = (float)luaL_checknumber(L, 2);
    b->setConstructionProgress(amount);
    return 0;
}

int BuildingBinding::_NV_setConstructionProgress(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float amount = (float)luaL_checknumber(L, 2);
    b->_NV_setConstructionProgress(amount);
    return 0;
}

int BuildingBinding::notifyConstructionComplete(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->notifyConstructionComplete();
    return 0;
}

int BuildingBinding::_NV_notifyConstructionComplete(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_NV_notifyConstructionComplete();
    return 0;
}

int BuildingBinding::addDismantleProgress(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = b->addDismantleProgress(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_addDismantleProgress(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = b->_NV_addDismantleProgress(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::notifyConstructionDismantling(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->notifyConstructionDismantling();
    return 0;
}

int BuildingBinding::_NV_notifyConstructionDismantling(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_NV_notifyConstructionDismantling();
    return 0;
}

int BuildingBinding::dropMats(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->dropMats();
    return 0;
}

int BuildingBinding::canUpgrade(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    GameData* result = b->canUpgrade();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int BuildingBinding::_NV_canUpgrade(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    GameData* result = b->_NV_canUpgrade();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int BuildingBinding::canDowngrade(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    GameData* result = b->canDowngrade();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int BuildingBinding::_NV_canDowngrade(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    GameData* result = b->_NV_canDowngrade();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int BuildingBinding::canDismantle(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->canDismantle();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_canDismantle(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_canDismantle();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::buyMeCallback(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    int result = (int)luaL_checkinteger(L, 2);
    b->buyMeCallback(result);
    return 0;
}

int BuildingBinding::_NV_buyMeCallback(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    int result = (int)luaL_checkinteger(L, 2);
    b->_NV_buyMeCallback(result);
    return 0;
}

int BuildingBinding::calculateSaleValue(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    int result = b->calculateSaleValue();
    lua_pushinteger(L, result);
    return 1;
}

int BuildingBinding::loadNodes(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->loadNodes();
    return 0;
}

int BuildingBinding::isPublic(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isPublic(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::confirmDismantle(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    int r = (int)luaL_checkinteger(L, 2);
    b->confirmDismantle(r);
    return 0;
}

int BuildingBinding::_NV_confirmDismantle(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    int r = (int)luaL_checkinteger(L, 2);
    b->_NV_confirmDismantle(r);
    return 0;
}

int BuildingBinding::isAShop(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isAShop();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isAShop(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_isAShop();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isForSale(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isForSale(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isAWallRamp(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isAWallRamp();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isAWallRamp(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_isAWallRamp();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::hasInterior(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->hasInterior();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::affectsNavmesh(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->affectsNavmesh();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::getResidentSquadLeader(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    Character* result = b->getResidentSquadLeader();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int BuildingBinding::setDesignation(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    BuildingDesignation d = (BuildingDesignation)luaL_checkinteger(L, 2);
    b->setDesignation(d);
    return 0;
}

int BuildingBinding::setupMiningResourceLevel(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->setupMiningResourceLevel();
    return 0;
}

int BuildingBinding::_NV_setupMiningResourceLevel(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_NV_setupMiningResourceLevel();
    return 0;
}

int BuildingBinding::getMiningResourceLevel(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->getMiningResourceLevel();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_getMiningResourceLevel(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->_NV_getMiningResourceLevel();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::getNumInternalBuildings(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    int result = b->getNumInternalBuildings();
    lua_pushinteger(L, result);
    return 1;
}

int BuildingBinding::moveMountedBuildings(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->moveMountedBuildings();
    return 0;
}

int BuildingBinding::reCheckInsideOutsideFortificationStatus(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->reCheckInsideOutsideFortificationStatus();
    return 0;
}

int BuildingBinding::setInsideTownWalls(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    int code = (int)luaL_checkinteger(L, 2);
    b->setInsideTownWalls(code);
    return 0;
}

int BuildingBinding::_NV_setInsideTownWalls(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    int code = (int)luaL_checkinteger(L, 2);
    b->_NV_setInsideTownWalls(code);
    return 0;
}

int BuildingBinding::postCreationPathfinderSetupStuff(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->postCreationPathfinderSetupStuff();
    return 0;
}

int BuildingBinding::_NV_postCreationPathfinderSetupStuff(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_NV_postCreationPathfinderSetupStuff();
    return 0;
}

int BuildingBinding::getSpecialFunction(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    BuildingFunction result = b->getSpecialFunction();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::_NV_getSpecialFunction(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    BuildingFunction result = b->_NV_getSpecialFunction();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::getFunctionStuff(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    StorageBuilding* result = b->getFunctionStuff();
    return pushObject<StorageBuilding>(L, result, StorageBuildingBinding::getMetatableName());
}

int BuildingBinding::_NV_getFunctionStuff(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    StorageBuilding* result = b->_NV_getFunctionStuff();
    return pushObject<StorageBuilding>(L, result, StorageBuildingBinding::getMetatableName());
}

int BuildingBinding::isBroken(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isBroken();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isBroken(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_isBroken();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::setBroken(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool _a1 = lua_toboolean(L, 2) != 0;
    b->setBroken(_a1);
    return 0;
}

int BuildingBinding::_NV_setBroken(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool _a1 = lua_toboolean(L, 2) != 0;
    b->_NV_setBroken(_a1);
    return 0;
}

int BuildingBinding::switchPowerOn(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->switchPowerOn(on);
    return 0;
}

int BuildingBinding::_NV_switchPowerOn(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->_NV_switchPowerOn(on);
    return 0;
}

int BuildingBinding::isPowerOn(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isPowerOn();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isPowerOn(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_isPowerOn();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isDamaged(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isDamaged();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isDamaged(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_isDamaged();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isDestroyed(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isDestroyed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isDestroyed(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_isDestroyed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isSign(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isSign();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isSign(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_isSign();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::setDestroyed(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool d = lua_toboolean(L, 2) != 0;
    b->setDestroyed(d);
    return 0;
}

int BuildingBinding::_NV_setDestroyed(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool d = lua_toboolean(L, 2) != 0;
    b->_NV_setDestroyed(d);
    return 0;
}

int BuildingBinding::canBeDestroyed(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->canBeDestroyed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_canBeDestroyed(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_canBeDestroyed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::setNestTag(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->setNestTag();
    return 0;
}

int BuildingBinding::getReachRange(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_getReachRange(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->_NV_getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::getBuildingClass(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    BuildingClassType result = b->getBuildingClass();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::_NV_getBuildingClass(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    BuildingClassType result = b->_NV_getBuildingClass();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::needsSaving(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    std::string mod = luaL_checkstring(L, 2);
    bool result = b->needsSaving(mod);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_needsSaving(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    std::string mod = luaL_checkstring(L, 2);
    bool result = b->_NV_needsSaving(mod);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::notifyChange(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->notifyChange();
    return 0;
}

int BuildingBinding::setToDefaultFactionDivision(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->setToDefaultFactionDivision();
    return 0;
}

int BuildingBinding::getOutputBasedRotationSpeedMult(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->getOutputBasedRotationSpeedMult();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_getOutputBasedRotationSpeedMult(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->_NV_getOutputBasedRotationSpeedMult();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::calculateEfficiencyMult(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->calculateEfficiencyMult();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_calculateEfficiencyMult(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->_NV_calculateEfficiencyMult();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::getSoundIntensity(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->getSoundIntensity();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_getSoundIntensity(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->_NV_getSoundIntensity();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::loadUnloadCheck(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->loadUnloadCheck();
    return 0;
}

int BuildingBinding::_NV_loadUnloadCheck(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_NV_loadUnloadCheck();
    return 0;
}

int BuildingBinding::_DESTRUCTOR(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_DESTRUCTOR();
    return 0;
}

int BuildingBinding::getProductionBuilding(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    ProductionBuilding* result = b->getProductionBuilding();
    return pushObject<ProductionBuilding>(L, result, ProductionBuildingBinding::getMetatableName());
}

int BuildingBinding::_NV_getProductionBuilding(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    ProductionBuilding* result = b->_NV_getProductionBuilding();
    return pushObject<ProductionBuilding>(L, result, ProductionBuildingBinding::getMetatableName());
}

int BuildingBinding::getProductionMultForGUI(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->getProductionMultForGUI();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_getProductionMultForGUI(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->_NV_getProductionMultForGUI();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::getProductionMult(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->getProductionMult();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_getProductionMult(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->_NV_getProductionMult();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::isThePlayer(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isThePlayer();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::doorParentBuilding(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    Building* result = b->doorParentBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int BuildingBinding::_NV_doorParentBuilding(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    Building* result = b->_NV_doorParentBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int BuildingBinding::isDoor(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isDoor();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isFurniture(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isFurniture();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isFurnitureOrDoor(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isFurnitureOrDoor();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::getIsOutsideFurniture(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->getIsOutsideFurniture();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::setIsOutsideFurniture(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool value = lua_toboolean(L, 2) != 0;
    b->setIsOutsideFurniture(value);
    return 0;
}

int BuildingBinding::getCurrentTownLocation(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    TownBase* result = b->getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int BuildingBinding::_NV_getCurrentTownLocation(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    TownBase* result = b->_NV_getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int BuildingBinding::furnitureParentBuilding(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    Building* result = b->furnitureParentBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int BuildingBinding::hasAnOpenDoor(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->hasAnOpenDoor();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::allowAnimals(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->allowAnimals();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::update(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->update();
    return 0;
}

int BuildingBinding::_NV_update(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_NV_update();
    return 0;
}

int BuildingBinding::threadedUpdate(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->threadedUpdate();
    return 0;
}

int BuildingBinding::_NV_threadedUpdate(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_NV_threadedUpdate();
    return 0;
}

int BuildingBinding::needsUpdate(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_needsUpdate(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isPhysical(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isPhysical(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::checkLoadedProperly(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->checkLoadedProperly();
    return 0;
}

int BuildingBinding::_NV_checkLoadedProperly(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_NV_checkLoadedProperly();
    return 0;
}

int BuildingBinding::setVisible(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->setVisible(on);
    return 0;
}

int BuildingBinding::_NV_setVisible(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->_NV_setVisible(on);
    return 0;
}

int BuildingBinding::getVisible(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_getVisible(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::hasDoorLock(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->hasDoorLock();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_hasDoorLock(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_hasDoorLock();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::getInventory(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    Inventory* result = b->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int BuildingBinding::_NV_getInventory(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    Inventory* result = b->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int BuildingBinding::getTown(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    TownBase* result = b->getTown();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int BuildingBinding::getRealTown(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    Town* result = b->getRealTown();
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int BuildingBinding::createPhysical(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_createPhysical(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::destroyPhysical(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->destroyPhysical();
    return 0;
}

int BuildingBinding::_NV_destroyPhysical(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_NV_destroyPhysical();
    return 0;
}

int BuildingBinding::destroyDoors(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->destroyDoors();
    return 0;
}

int BuildingBinding::createTriggerHull(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->createTriggerHull();
    return 0;
}

int BuildingBinding::destroyAudioObject(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->destroyAudioObject();
    return 0;
}

int BuildingBinding::getGroundType(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool inside = lua_toboolean(L, 2) != 0;
    GroundType result = b->getGroundType(inside);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildingBinding::isCeilingMounted(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isCeilingMounted();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isCeilingMounted(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_isCeilingMounted();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::setFloorVisibility(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    int floor = (int)luaL_checkinteger(L, 2);
    bool vis = lua_toboolean(L, 3) != 0;
    b->setFloorVisibility(floor, vis);
    return 0;
}

int BuildingBinding::getNumFloors(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    int result = b->getNumFloors();
    lua_pushinteger(L, result);
    return 1;
}

int BuildingBinding::buildingComplete_RestoreMaterial(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->buildingComplete_RestoreMaterial();
    return 0;
}

int BuildingBinding::loadInteriorPhysical(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->loadInteriorPhysical(on);
    return 0;
}

int BuildingBinding::loadInteriorGraphics(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->loadInteriorGraphics(on);
    return 0;
}

int BuildingBinding::getLinkLength(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->getLinkLength();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::_NV_getLinkLength(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    float result = b->_NV_getLinkLength();
    lua_pushnumber(L, result);
    return 1;
}

int BuildingBinding::clearTownBuildingsManagerPtr(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->clearTownBuildingsManagerPtr();
    return 0;
}

int BuildingBinding::_NV_clearTownBuildingsManagerPtr(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_NV_clearTownBuildingsManagerPtr();
    return 0;
}

int BuildingBinding::setup(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->setup();
    return 0;
}

int BuildingBinding::_NV_setup(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_NV_setup();
    return 0;
}

int BuildingBinding::setupFromData(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->setupFromData();
    return 0;
}

int BuildingBinding::_NV_setupFromData(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_NV_setupFromData();
    return 0;
}

int BuildingBinding::setupAudio(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->setupAudio();
    return 0;
}

int BuildingBinding::switchLights(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->switchLights(on);
    return 0;
}

int BuildingBinding::_NV_switchLights(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->_NV_switchLights(on);
    return 0;
}

int BuildingBinding::switchEffects(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->switchEffects(on);
    return 0;
}

int BuildingBinding::_NV_switchEffects(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->_NV_switchEffects(on);
    return 0;
}

int BuildingBinding::hasAnyGoodPositionMarkersLeft(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->hasAnyGoodPositionMarkersLeft();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::isCreated(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->isCreated();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::_NV_isCreated(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    bool result = b->_NV_isCreated();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingBinding::updateUsageNodes(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->updateUsageNodes();
    return 0;
}

int BuildingBinding::forceValidUsageNodesValidation(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->forceValidUsageNodesValidation();
    return 0;
}

int BuildingBinding::addUsageNode(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    std::string nodeId = luaL_checkstring(L, 2);
    b->addUsageNode(nodeId);
    return 0;
}

int BuildingBinding::removeUsageNode(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    std::string nodeId = luaL_checkstring(L, 2);
    b->removeUsageNode(nodeId);
    return 0;
}

int BuildingBinding::clearUsageNodes(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->clearUsageNodes();
    return 0;
}

int BuildingBinding::updatePhysicalWithProgress(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->updatePhysicalWithProgress();
    return 0;
}

int BuildingBinding::recalculateWorldAABB(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->recalculateWorldAABB();
    return 0;
}

int BuildingBinding::getSeed(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    unsigned int result = b->getSeed();
    lua_pushinteger(L, result);
    return 1;
}

int BuildingBinding::onBuildingLoaded(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->onBuildingLoaded();
    return 0;
}

int BuildingBinding::_NV_onBuildingLoaded(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->_NV_onBuildingLoaded();
    return 0;
}

int BuildingBinding::updateBadNodes(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    b->updateBadNodes();
    return 0;
}

// line 359: CursorType getMouseCursor(...) - unsupported return type
int BuildingBinding::getMouseCursor(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    CursorType result = b->getMouseCursor();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

// line 360: CursorType _NV_getMouseCursor(...) - unsupported return type
int BuildingBinding::_NV_getMouseCursor(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    CursorType result = b->_NV_getMouseCursor();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

// line 361: TaskType getDefaultTask(...) - unsupported return type
int BuildingBinding::getDefaultTask(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    TaskType result = b->getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

// line 362: TaskType _NV_getDefaultTask(...) - unsupported return type
int BuildingBinding::_NV_getDefaultTask(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    TaskType result = b->_NV_getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

// line 203: Ogre::Vector3 getWallEndPosition(...) - unsupported return type
int BuildingBinding::getWallEndPosition(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    Ogre::Vector3 result = b->getWallEndPosition();
    pushVector3(L, result);
    return 1;
}

// line 400: Ogre::Vector3 calculateLeftPost(...)
int BuildingBinding::calculateLeftPost(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) return luaL_error(L, "Building is nil");

    Ogre::Vector3 result = b->calculateLeftPost();
    pushVector3(L, result);
    return 1;
}

// line 439: Ogre::Vector3 getPositionMarker(...) - unsupported return type
int BuildingBinding::getPosition(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) { lua_pushnil(L); return 1; }
    Ogre::Vector3 p = b->getPosition();
    pushVector3(L, p);
    return 1;
}

// line 440: Ogre::Vector3 _NV_getPositionMarker(...) - unsupported return type
int BuildingBinding::_NV_getPositionMarker(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) { lua_pushnil(L); return 1; }

    Ogre::Vector3 p = b->getPosition();
    Ogre::Vector3 result = b->_NV_getPositionMarker(p);
    pushVector3(L, result);
    return 1;
}

// line 441: Ogre::Vector3 getDirectionMarker(...) - unsupported return type
int BuildingBinding::getDirectionMarker(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) { lua_pushnil(L); return 1; }

    Ogre::Vector3 p = b->getPosition();
    Ogre::Vector3 result = b->getDirectionMarker(p);
    pushVector3(L, result);
    return 1;
}

// line 442: Ogre::Vector3 _NV_getDirectionMarker(...) - unsupported return type
int BuildingBinding::_NV_getDirectionMarker(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) { lua_pushnil(L); return 1; }

    Ogre::Vector3 p = b->getPosition();
    Ogre::Vector3 result = b->_NV_getDirectionMarker(p);
    pushVector3(L, result);
    return 1;
}

// line 443: Ogre::Quaternion getDirectionMarkerQuat(...) - unsupported return type
int BuildingBinding::getDirectionMarkerQuat(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) { lua_pushnil(L); return 1; }

    Ogre::Vector3 p = b->getPosition();
    Ogre::Quaternion result = b->getDirectionMarkerQuat(p);
    pushQuaternion(L, result);
    return 1;
}

// line 444: Ogre::Quaternion _NV_getDirectionMarkerQuat(...) - unsupported return type
int BuildingBinding::_NV_getDirectionMarkerQuat(lua_State* L)
{
    Building* b = getB(L, 1);
    if (!b) { lua_pushnil(L); return 1; }

    Ogre::Vector3 p = b->getPosition();
    Ogre::Quaternion result = b->_NV_getDirectionMarkerQuat(p);
    pushQuaternion(L, result);
    return 1;
}


/*
Skipped methods needing manual binding:
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
  line 203: Ogre::Vector3 getWallEndPosition(...) - unsupported return type
  line 208: void addAnInternalBuilding(...) - unsupported arg type
  line 209: void removeAnInternalBuilding(...) - unsupported arg type
  line 211: void addAnInternalItem(...) - unsupported arg type
  line 212: void removeAnInternalItem(...) - unsupported arg type
  line 214: int getMountedBuildings(...) - unsupported arg type
  line 216: void setHandle(...) - unsupported arg type
  line 217: void _NV_setHandle(...) - unsupported arg type
  line 227: UseableStuff* getUseableStuff(...) - unsupported return type
  line 228: UseableStuff* _NV_getUseableStuff(...) - unsupported return type
  line 251: bool hasShopCountersSelling(...) - unsupported arg type
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
  line 438: void notifyBadPositionMarker(...) - unsupported arg type
  line 453: void notifyEffect(...) - unsupported arg type
  line 454: void _NV_notifyEffect(...) - unsupported arg type
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

void BuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildingBinding::gc },
        { "__tostring", BuildingBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getName", BuildingBinding::getName },
        { "getPosition", BuildingBinding::getPosition },
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
        { "getFunctionStuff", BuildingBinding::getFunctionStuff },
        { "_NV_getFunctionStuff", BuildingBinding::_NV_getFunctionStuff },
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
        { "getProductionBuilding", BuildingBinding::getProductionBuilding },
        { "_NV_getProductionBuilding", BuildingBinding::_NV_getProductionBuilding },
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
        { "isCreated", BuildingBinding::isCreated },
        { "_NV_isCreated", BuildingBinding::_NV_isCreated },
        { "updateUsageNodes", BuildingBinding::updateUsageNodes },
        { "forceValidUsageNodesValidation", BuildingBinding::forceValidUsageNodesValidation },
        { "addUsageNode", BuildingBinding::addUsageNode },
        { "removeUsageNode", BuildingBinding::removeUsageNode },
        { "clearUsageNodes", BuildingBinding::clearUsageNodes },
        { "updatePhysicalWithProgress", BuildingBinding::updatePhysicalWithProgress },
        { "recalculateWorldAABB", BuildingBinding::recalculateWorldAABB },
        { "getSeed", BuildingBinding::getSeed },
        { "onBuildingLoaded", BuildingBinding::onBuildingLoaded },
        { "_NV_onBuildingLoaded", BuildingBinding::_NV_onBuildingLoaded },
        { "updateBadNodes", BuildingBinding::updateBadNodes },
        { "getMouseCursor", BuildingBinding::getMouseCursor },
        { "_NV_getMouseCursor", BuildingBinding::_NV_getMouseCursor },
        { "getDefaultTask", BuildingBinding::getDefaultTask },
        { "_NV_getDefaultTask", BuildingBinding::_NV_getDefaultTask },
        { "getWallEndPosition", BuildingBinding::getWallEndPosition },
        { "calculateLeftPost", BuildingBinding::calculateLeftPost },
        { "getPosition", BuildingBinding::getPosition },
        { "_NV_getPositionMarker", BuildingBinding::_NV_getPositionMarker },
        { "getDirectionMarker", BuildingBinding::getDirectionMarker },
        { "_NV_getDirectionMarker", BuildingBinding::_NV_getDirectionMarker },
        { "getDirectionMarkerQuat", BuildingBinding::getDirectionMarkerQuat },
        { "_NV_getDirectionMarkerQuat", BuildingBinding::_NV_getDirectionMarkerQuat },
        { 0, 0 }
    };
    registerClass(L, BuildingBinding::getMetatableName(), meta, methods, BuildingBinding::index, BuildingBinding::newindex);
}

} // namespace KenshiLua