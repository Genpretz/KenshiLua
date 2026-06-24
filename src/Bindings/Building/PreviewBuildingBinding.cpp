#include "pch.h"
#include <kenshi/Building/Building.h>
#include "PreviewBuildingBinding.h"
#include "BuildingBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static PreviewBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<PreviewBuilding>(L, idx, PreviewBuildingBinding::getMetatableName());
}

// --- Getters for PreviewBuilding ---
static int PreviewBuilding_get_parentNode(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    // TODO: Unsupported type for parentNode (Ogre::SceneNode*)
    lua_pushnil(L);
    return 1;
}

static int PreviewBuilding_get_entitiesList(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    // TODO: Unsupported type for entitiesList (Ogre::vector<Ogre::Entity*>::type)
    lua_pushnil(L);
    return 1;
}

static int PreviewBuilding_get_footprints(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    // TODO: Unsupported type for footprints (lektor<Footprint>)
    lua_pushnil(L);
    return 1;
}

static int PreviewBuilding_get_isCurrentlySnapped(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->isCurrentlySnapped ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_snappedTo(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return pushObject<Building>(L, instance->snappedTo, BuildingBinding::getMetatableName());
}

static int PreviewBuilding_get_usageNodes(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    // TODO: Unsupported type for usageNodes (lektor<FootprintNode>)
    lua_pushnil(L);
    return 1;
}

static int PreviewBuilding_get_prospectingInformation(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    // TODO: Unsupported type for prospectingInformation (DatapanelGUI*)
    lua_pushnil(L);
    return 1;
}

static int PreviewBuilding_get_prospectResource(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushinteger(L, (lua_Integer)instance->prospectResource);
    return 1;
}

static int PreviewBuilding_get_roofOnly(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->roofOnly ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_spaceAbove(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushnumber(L, instance->spaceAbove);
    return 1;
}

static int PreviewBuilding_get_spaceBelow(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushnumber(L, instance->spaceBelow);
    return 1;
}

static int PreviewBuilding_get_collisionOK(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->collisionOK ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_charactersOK(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->charactersOK ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_floorOk(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->floorOk ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_indoorsOK(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->indoorsOK ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_slopeOK(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->slopeOK ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_nodesOk(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->nodesOk ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_blockedBuildings(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->blockedBuildings ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_validGround(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->validGround ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_inTown(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return pushObject<Town>(L, instance->inTown, TownBinding::getMetatableName());
}

static int PreviewBuilding_get_floorNum(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushinteger(L, instance->floorNum);
    return 1;
}

static int PreviewBuilding_get_isOutside(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->isOutside ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_matchSlope(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->matchSlope ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_nodeResults(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    // TODO: Unsupported type for nodeResults (lektor<PlacementResult>)
    lua_pushnil(L);
    return 1;
}

static int PreviewBuilding_get_justBeenBuilt(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return pushObject<Building>(L, instance->justBeenBuilt, BuildingBinding::getMetatableName());
}

static int PreviewBuilding_get_yaw(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushnumber(L, instance->yaw);
    return 1;
}

static int PreviewBuilding_get_centreOffset(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    pushVector3(L, instance->centreOffset);
    return 1;
}

static int PreviewBuilding_get_isFurnitureOf(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return pushObject<Building>(L, instance->isFurnitureOf, BuildingBinding::getMetatableName());
}

static int PreviewBuilding_get_isIndoors(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return pushObject<Building>(L, instance->isIndoors, BuildingBinding::getMetatableName());
}

static int PreviewBuilding_get_AABB(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    // TODO: Unsupported type for AABB (Ogre::Aabb)
    lua_pushnil(L);
    return 1;
}

static int PreviewBuilding_get_buildDataPtr(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return pushObject<GameData>(L, instance->buildDataPtr, GameDataBinding::getMetatableName());
}

static int PreviewBuilding_get_farmData(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return pushObject<GameData>(L, instance->farmData, GameDataBinding::getMetatableName());
}

static int PreviewBuilding_get_prospectingOK(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->prospectingOK ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_furniture(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->furniture ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_exteriorFurniture(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushboolean(L, instance->exteriorFurniture ? 1 : 0);
    return 1;
}

static int PreviewBuilding_get_pos(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    pushVector3(L, instance->pos);
    return 1;
}

static int PreviewBuilding_get_rot(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    pushQuaternion(L, instance->rot);
    return 1;
}

static int PreviewBuilding_get_positionHitGroup(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    lua_pushinteger(L, instance->positionHitGroup);
    return 1;
}

// --- Setters for PreviewBuilding ---
static int PreviewBuilding_set_parentNode(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for parentNode");
}

static int PreviewBuilding_set_entitiesList(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for entitiesList");
}

static int PreviewBuilding_set_footprints(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for footprints");
}

static int PreviewBuilding_set_isCurrentlySnapped(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->isCurrentlySnapped = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_snappedTo(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for snappedTo");
}

static int PreviewBuilding_set_usageNodes(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for usageNodes");
}

static int PreviewBuilding_set_prospectingInformation(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for prospectingInformation");
}

static int PreviewBuilding_set_prospectResource(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->prospectResource = (MiningResource)luaL_checkinteger(L, 2);
    return 0;
}

static int PreviewBuilding_set_roofOnly(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->roofOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_spaceAbove(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->spaceAbove = (float)luaL_checknumber(L, 2);
    return 0;
}

static int PreviewBuilding_set_spaceBelow(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->spaceBelow = (float)luaL_checknumber(L, 2);
    return 0;
}

static int PreviewBuilding_set_collisionOK(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->collisionOK = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_charactersOK(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->charactersOK = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_floorOk(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->floorOk = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_indoorsOK(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->indoorsOK = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_slopeOK(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->slopeOK = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_nodesOk(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->nodesOk = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_blockedBuildings(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->blockedBuildings = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_validGround(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->validGround = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_inTown(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for inTown");
}

static int PreviewBuilding_set_floorNum(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->floorNum = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int PreviewBuilding_set_isOutside(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->isOutside = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_matchSlope(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->matchSlope = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_nodeResults(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for nodeResults");
}

static int PreviewBuilding_set_justBeenBuilt(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for justBeenBuilt");
}

static int PreviewBuilding_set_yaw(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->yaw = (float)luaL_checknumber(L, 2);
    return 0;
}

static int PreviewBuilding_set_centreOffset(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    readVector3(L, 2, instance->centreOffset);
    return 0;
}

static int PreviewBuilding_set_isFurnitureOf(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isFurnitureOf");
}

static int PreviewBuilding_set_isIndoors(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isIndoors");
}

static int PreviewBuilding_set_AABB(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for AABB");
}

static int PreviewBuilding_set_buildDataPtr(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for buildDataPtr");
}

static int PreviewBuilding_set_farmData(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for farmData");
}

static int PreviewBuilding_set_prospectingOK(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->prospectingOK = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_furniture(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->furniture = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_exteriorFurniture(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->exteriorFurniture = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PreviewBuilding_set_pos(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    readVector3(L, 2, instance->pos);
    return 0;
}

static int PreviewBuilding_set_rot(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    readQuaternion(L, 2, instance->rot);
    return 0;
}

static int PreviewBuilding_set_positionHitGroup(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");
    instance->positionHitGroup = (int)luaL_checkinteger(L, 2);
    return 0;
}

int PreviewBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int PreviewBuildingBinding::type(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    PreviewBuilding::PreviewBuildingClassType result = instance->type();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int PreviewBuildingBinding::_NV_type(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    PreviewBuilding::PreviewBuildingClassType result = instance->_NV_type();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int PreviewBuildingBinding::checkProspectingIsNotZero(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->checkProspectingIsNotZero();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_checkProspectingIsNotZero(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_checkProspectingIsNotZero();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::isASnapToBuilding(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->isASnapToBuilding();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_isASnapToBuilding(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_isASnapToBuilding();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::isACeilingBuilding(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->isACeilingBuilding();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_isACeilingBuilding(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_isACeilingBuilding();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::snappingOk(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->snappingOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_snappingOk(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_snappingOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::isInteriorBuilding(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->isInteriorBuilding();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_isInteriorBuilding(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_isInteriorBuilding();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::isCurrent(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->isCurrent();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::setup(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->setup();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_setup(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_setup();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_destroyEnts(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    instance->_destroyEnts();
    return 0;
}

int PreviewBuildingBinding::_NV__destroyEnts(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    instance->_NV__destroyEnts();
    return 0;
}

int PreviewBuildingBinding::update(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    instance->update();
    return 0;
}

int PreviewBuildingBinding::_NV_update(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    instance->_NV_update();
    return 0;
}

int PreviewBuildingBinding::figureOutWhichTown(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    instance->figureOutWhichTown();
    return 0;
}

int PreviewBuildingBinding::setVisualPosition(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    instance->setVisualPosition(position);
    return 0;
}

int PreviewBuildingBinding::_NV_setVisualPosition(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    instance->_NV_setVisualPosition(position);
    return 0;
}

int PreviewBuildingBinding::yawBy(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    float pan = (float)luaL_checknumber(L, 2);
    instance->yawBy(pan);
    return 0;
}

int PreviewBuildingBinding::yawSet(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    float pan = (float)luaL_checknumber(L, 2);
    instance->yawSet(pan);
    return 0;
}

int PreviewBuildingBinding::rotateBy(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Quaternion by;
    readQuaternion(L, 2, by);
    instance->rotateBy(by);
    return 0;
}

int PreviewBuildingBinding::tilt(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    float pan = (float)luaL_checknumber(L, 2);
    instance->tilt(pan);
    return 0;
}

int PreviewBuildingBinding::roll(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    float pan = (float)luaL_checknumber(L, 2);
    instance->roll(pan);
    return 0;
}

int PreviewBuildingBinding::setRotation(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Quaternion r;
    readQuaternion(L, 2, r);
    instance->setRotation(r);
    return 0;
}

int PreviewBuildingBinding::allFootprintsWantBelowGround(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->allFootprintsWantBelowGround();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::allFootprintsWantAboveGround(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->allFootprintsWantAboveGround();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::updateFootprintHeights(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->updateFootprintHeights();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::isCollisionOK(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->isCollisionOK();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_isCollisionOK(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_isCollisionOK();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::isFloorOk(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->isFloorOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_isFloorOk(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_isFloorOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::isIndoorsOk(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->isIndoorsOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_isIndoorsOk(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_isIndoorsOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::isNodesOk(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->isNodesOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_isNodesOk(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_isNodesOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::isBlockingBuildingsNodes(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->isBlockingBuildingsNodes();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_isBlockingBuildingsNodes(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_isBlockingBuildingsNodes();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::isGoodAboveAndBelow(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->isGoodAboveAndBelow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_isGoodAboveAndBelow(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_isGoodAboveAndBelow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::isOnValidGround(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->isOnValidGround();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_isOnValidGround(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_isOnValidGround();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::isLinked(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->isLinked();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_isLinked(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_isLinked();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::moveHeightOffset(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    float h = (float)luaL_checknumber(L, 2);
    instance->moveHeightOffset(h);
    return 0;
}

int PreviewBuildingBinding::resetHeightOffset(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    instance->resetHeightOffset();
    return 0;
}

int PreviewBuildingBinding::getFootprintShift(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    float result = instance->getFootprintShift();
    lua_pushnumber(L, result);
    return 1;
}

int PreviewBuildingBinding::setOrientation(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Quaternion q;
    readQuaternion(L, 2, q);
    instance->setOrientation(q);
    return 0;
}

int PreviewBuildingBinding::getPosition(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    const Ogre::Vector3 result = instance->getPosition();
    pushVector3(L, result);
    return 1;
}

int PreviewBuildingBinding::getFloor(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    int result = instance->getFloor();
    lua_pushinteger(L, result);
    return 1;
}

int PreviewBuildingBinding::setStartPosition(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    instance->setStartPosition(p);
    return 0;
}

int PreviewBuildingBinding::_NV_setStartPosition(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    instance->_NV_setStartPosition(p);
    return 0;
}

int PreviewBuildingBinding::setEndPosition(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    instance->setEndPosition(position);
    return 0;
}

int PreviewBuildingBinding::_NV_setEndPosition(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    instance->_NV_setEndPosition(position);
    return 0;
}

int PreviewBuildingBinding::getEndPos(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Vector3 result = instance->getEndPos();
    pushVector3(L, result);
    return 1;
}

int PreviewBuildingBinding::_NV_getEndPos(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Vector3 result = instance->_NV_getEndPos();
    pushVector3(L, result);
    return 1;
}

int PreviewBuildingBinding::placeFinalPreviewBuilding(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    instance->placeFinalPreviewBuilding();
    return 0;
}

int PreviewBuildingBinding::_NV_placeFinalPreviewBuilding(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    instance->_NV_placeFinalPreviewBuilding();
    return 0;
}

int PreviewBuildingBinding::insideBuilding(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Building* result = instance->insideBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int PreviewBuildingBinding::placementVerification(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->placementVerification();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_placementVerification(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_placementVerification();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::getGameData(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    GameData* result = instance->getGameData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int PreviewBuildingBinding::noAltitude(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->noAltitude();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_noAltitude(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_noAltitude();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::noPathfindingNeeded(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->noPathfindingNeeded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::_NV_noPathfindingNeeded(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->_NV_noPathfindingNeeded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::placePreview(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    Ogre::Quaternion rotation;
    readQuaternion(L, 3, rotation);
    int floorNumber = (int)luaL_checkinteger(L, 4);
    instance->placePreview(position, rotation, floorNumber);
    return 0;
}

int PreviewBuildingBinding::_NV_placePreview(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    Ogre::Quaternion rotation;
    readQuaternion(L, 3, rotation);
    int floorNumber = (int)luaL_checkinteger(L, 4);
    instance->_NV_placePreview(position, rotation, floorNumber);
    return 0;
}

int PreviewBuildingBinding::resetUseageNodes(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    instance->resetUseageNodes();
    return 0;
}

int PreviewBuildingBinding::calculateRotationsAndStuff(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    instance->calculateRotationsAndStuff(position);
    return 0;
}

int PreviewBuildingBinding::_NV_calculateRotationsAndStuff(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    instance->_NV_calculateRotationsAndStuff(position);
    return 0;
}

int PreviewBuildingBinding::placementVerification_recurse(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    bool result = instance->placementVerification_recurse();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PreviewBuildingBinding::getTerrainHeightAtCenter(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    float result = instance->getTerrainHeightAtCenter();
    lua_pushnumber(L, result);
    return 1;
}

int PreviewBuildingBinding::_NV_getTerrainHeightAtCenter(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    float result = instance->_NV_getTerrainHeightAtCenter();
    lua_pushnumber(L, result);
    return 1;
}

int PreviewBuildingBinding::recalculateWorldAABB(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    instance->recalculateWorldAABB();
    return 0;
}

int PreviewBuildingBinding::validateUsageNodes(lua_State* L)
{
    PreviewBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PreviewBuilding is nil");

    instance->validateUsageNodes();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 600: const std::string& getPlacementResultMaterialName(...) - static method
  line 603: PreviewBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 625: void buildingPlacementUpdate(...) - unsupported arg type
  line 626: void _NV_buildingPlacementUpdate(...) - unsupported arg type
  line 659: const Ogre::Quaternion& getOrientation(...) - reference return type
  line 662: const Ogre::Vector3& getCentreOffset(...) - reference return type
  line 670: void clearPointersTo(...) - unsupported arg type
  line 671: void _NV_clearPointersTo(...) - unsupported arg type
  line 677: const Ogre::Aabb& getWorldAABB(...) - reference return type
  line 678: bool isNoCollideWithThisBuilding(...) - overloaded method
  line 679: bool _NV_isNoCollideWithThisBuilding(...) - overloaded method
  line 680: bool isNoCollideWithThisBuilding(...) - overloaded method
  line 681: bool _NV_isNoCollideWithThisBuilding(...) - overloaded method
*/

int PreviewBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int PreviewBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.PreviewBuilding object");
    return 1;
}

void PreviewBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PreviewBuildingBinding::gc },
        { "__tostring", PreviewBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", PreviewBuildingBinding::_DESTRUCTOR },
        { "type", PreviewBuildingBinding::type },
        { "_NV_type", PreviewBuildingBinding::_NV_type },
        { "checkProspectingIsNotZero", PreviewBuildingBinding::checkProspectingIsNotZero },
        { "_NV_checkProspectingIsNotZero", PreviewBuildingBinding::_NV_checkProspectingIsNotZero },
        { "isASnapToBuilding", PreviewBuildingBinding::isASnapToBuilding },
        { "_NV_isASnapToBuilding", PreviewBuildingBinding::_NV_isASnapToBuilding },
        { "isACeilingBuilding", PreviewBuildingBinding::isACeilingBuilding },
        { "_NV_isACeilingBuilding", PreviewBuildingBinding::_NV_isACeilingBuilding },
        { "snappingOk", PreviewBuildingBinding::snappingOk },
        { "_NV_snappingOk", PreviewBuildingBinding::_NV_snappingOk },
        { "isInteriorBuilding", PreviewBuildingBinding::isInteriorBuilding },
        { "_NV_isInteriorBuilding", PreviewBuildingBinding::_NV_isInteriorBuilding },
        { "isCurrent", PreviewBuildingBinding::isCurrent },
        { "setup", PreviewBuildingBinding::setup },
        { "_NV_setup", PreviewBuildingBinding::_NV_setup },
        { "_destroyEnts", PreviewBuildingBinding::_destroyEnts },
        { "_NV__destroyEnts", PreviewBuildingBinding::_NV__destroyEnts },
        { "update", PreviewBuildingBinding::update },
        { "_NV_update", PreviewBuildingBinding::_NV_update },
        { "figureOutWhichTown", PreviewBuildingBinding::figureOutWhichTown },
        { "setVisualPosition", PreviewBuildingBinding::setVisualPosition },
        { "_NV_setVisualPosition", PreviewBuildingBinding::_NV_setVisualPosition },
        { "yawBy", PreviewBuildingBinding::yawBy },
        { "yawSet", PreviewBuildingBinding::yawSet },
        { "rotateBy", PreviewBuildingBinding::rotateBy },
        { "tilt", PreviewBuildingBinding::tilt },
        { "roll", PreviewBuildingBinding::roll },
        { "setRotation", PreviewBuildingBinding::setRotation },
        { "allFootprintsWantBelowGround", PreviewBuildingBinding::allFootprintsWantBelowGround },
        { "allFootprintsWantAboveGround", PreviewBuildingBinding::allFootprintsWantAboveGround },
        { "updateFootprintHeights", PreviewBuildingBinding::updateFootprintHeights },
        { "isCollisionOK", PreviewBuildingBinding::isCollisionOK },
        { "_NV_isCollisionOK", PreviewBuildingBinding::_NV_isCollisionOK },
        { "isFloorOk", PreviewBuildingBinding::isFloorOk },
        { "_NV_isFloorOk", PreviewBuildingBinding::_NV_isFloorOk },
        { "isIndoorsOk", PreviewBuildingBinding::isIndoorsOk },
        { "_NV_isIndoorsOk", PreviewBuildingBinding::_NV_isIndoorsOk },
        { "isNodesOk", PreviewBuildingBinding::isNodesOk },
        { "_NV_isNodesOk", PreviewBuildingBinding::_NV_isNodesOk },
        { "isBlockingBuildingsNodes", PreviewBuildingBinding::isBlockingBuildingsNodes },
        { "_NV_isBlockingBuildingsNodes", PreviewBuildingBinding::_NV_isBlockingBuildingsNodes },
        { "isGoodAboveAndBelow", PreviewBuildingBinding::isGoodAboveAndBelow },
        { "_NV_isGoodAboveAndBelow", PreviewBuildingBinding::_NV_isGoodAboveAndBelow },
        { "isOnValidGround", PreviewBuildingBinding::isOnValidGround },
        { "_NV_isOnValidGround", PreviewBuildingBinding::_NV_isOnValidGround },
        { "isLinked", PreviewBuildingBinding::isLinked },
        { "_NV_isLinked", PreviewBuildingBinding::_NV_isLinked },
        { "moveHeightOffset", PreviewBuildingBinding::moveHeightOffset },
        { "resetHeightOffset", PreviewBuildingBinding::resetHeightOffset },
        { "getFootprintShift", PreviewBuildingBinding::getFootprintShift },
        { "setOrientation", PreviewBuildingBinding::setOrientation },
        { "getPosition", PreviewBuildingBinding::getPosition },
        { "getFloor", PreviewBuildingBinding::getFloor },
        { "setStartPosition", PreviewBuildingBinding::setStartPosition },
        { "_NV_setStartPosition", PreviewBuildingBinding::_NV_setStartPosition },
        { "setEndPosition", PreviewBuildingBinding::setEndPosition },
        { "_NV_setEndPosition", PreviewBuildingBinding::_NV_setEndPosition },
        { "getEndPos", PreviewBuildingBinding::getEndPos },
        { "_NV_getEndPos", PreviewBuildingBinding::_NV_getEndPos },
        { "placeFinalPreviewBuilding", PreviewBuildingBinding::placeFinalPreviewBuilding },
        { "_NV_placeFinalPreviewBuilding", PreviewBuildingBinding::_NV_placeFinalPreviewBuilding },
        { "insideBuilding", PreviewBuildingBinding::insideBuilding },
        { "placementVerification", PreviewBuildingBinding::placementVerification },
        { "_NV_placementVerification", PreviewBuildingBinding::_NV_placementVerification },
        { "getGameData", PreviewBuildingBinding::getGameData },
        { "noAltitude", PreviewBuildingBinding::noAltitude },
        { "_NV_noAltitude", PreviewBuildingBinding::_NV_noAltitude },
        { "noPathfindingNeeded", PreviewBuildingBinding::noPathfindingNeeded },
        { "_NV_noPathfindingNeeded", PreviewBuildingBinding::_NV_noPathfindingNeeded },
        { "placePreview", PreviewBuildingBinding::placePreview },
        { "_NV_placePreview", PreviewBuildingBinding::_NV_placePreview },
        { "resetUseageNodes", PreviewBuildingBinding::resetUseageNodes },
        { "calculateRotationsAndStuff", PreviewBuildingBinding::calculateRotationsAndStuff },
        { "_NV_calculateRotationsAndStuff", PreviewBuildingBinding::_NV_calculateRotationsAndStuff },
        { "placementVerification_recurse", PreviewBuildingBinding::placementVerification_recurse },
        { "getTerrainHeightAtCenter", PreviewBuildingBinding::getTerrainHeightAtCenter },
        { "_NV_getTerrainHeightAtCenter", PreviewBuildingBinding::_NV_getTerrainHeightAtCenter },
        { "recalculateWorldAABB", PreviewBuildingBinding::recalculateWorldAABB },
        { "validateUsageNodes", PreviewBuildingBinding::validateUsageNodes },
        { 0, 0 }
    };

    registerClass(
        L, 
        PreviewBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, PreviewBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, PreviewBuilding_get_parentNode);
    lua_setfield(L, -2, "parentNode");
    lua_pushcfunction(L, PreviewBuilding_get_entitiesList);
    lua_setfield(L, -2, "entitiesList");
    lua_pushcfunction(L, PreviewBuilding_get_footprints);
    lua_setfield(L, -2, "footprints");
    lua_pushcfunction(L, PreviewBuilding_get_isCurrentlySnapped);
    lua_setfield(L, -2, "isCurrentlySnapped");
    lua_pushcfunction(L, PreviewBuilding_get_snappedTo);
    lua_setfield(L, -2, "snappedTo");
    lua_pushcfunction(L, PreviewBuilding_get_usageNodes);
    lua_setfield(L, -2, "usageNodes");
    lua_pushcfunction(L, PreviewBuilding_get_prospectingInformation);
    lua_setfield(L, -2, "prospectingInformation");
    lua_pushcfunction(L, PreviewBuilding_get_prospectResource);
    lua_setfield(L, -2, "prospectResource");
    lua_pushcfunction(L, PreviewBuilding_get_roofOnly);
    lua_setfield(L, -2, "roofOnly");
    lua_pushcfunction(L, PreviewBuilding_get_spaceAbove);
    lua_setfield(L, -2, "spaceAbove");
    lua_pushcfunction(L, PreviewBuilding_get_spaceBelow);
    lua_setfield(L, -2, "spaceBelow");
    lua_pushcfunction(L, PreviewBuilding_get_collisionOK);
    lua_setfield(L, -2, "collisionOK");
    lua_pushcfunction(L, PreviewBuilding_get_charactersOK);
    lua_setfield(L, -2, "charactersOK");
    lua_pushcfunction(L, PreviewBuilding_get_floorOk);
    lua_setfield(L, -2, "floorOk");
    lua_pushcfunction(L, PreviewBuilding_get_indoorsOK);
    lua_setfield(L, -2, "indoorsOK");
    lua_pushcfunction(L, PreviewBuilding_get_slopeOK);
    lua_setfield(L, -2, "slopeOK");
    lua_pushcfunction(L, PreviewBuilding_get_nodesOk);
    lua_setfield(L, -2, "nodesOk");
    lua_pushcfunction(L, PreviewBuilding_get_blockedBuildings);
    lua_setfield(L, -2, "blockedBuildings");
    lua_pushcfunction(L, PreviewBuilding_get_validGround);
    lua_setfield(L, -2, "validGround");
    lua_pushcfunction(L, PreviewBuilding_get_inTown);
    lua_setfield(L, -2, "inTown");
    lua_pushcfunction(L, PreviewBuilding_get_floorNum);
    lua_setfield(L, -2, "floorNum");
    lua_pushcfunction(L, PreviewBuilding_get_isOutside);
    lua_setfield(L, -2, "isOutside");
    lua_pushcfunction(L, PreviewBuilding_get_matchSlope);
    lua_setfield(L, -2, "matchSlope");
    lua_pushcfunction(L, PreviewBuilding_get_nodeResults);
    lua_setfield(L, -2, "nodeResults");
    lua_pushcfunction(L, PreviewBuilding_get_justBeenBuilt);
    lua_setfield(L, -2, "justBeenBuilt");
    lua_pushcfunction(L, PreviewBuilding_get_yaw);
    lua_setfield(L, -2, "yaw");
    lua_pushcfunction(L, PreviewBuilding_get_centreOffset);
    lua_setfield(L, -2, "centreOffset");
    lua_pushcfunction(L, PreviewBuilding_get_isFurnitureOf);
    lua_setfield(L, -2, "isFurnitureOf");
    lua_pushcfunction(L, PreviewBuilding_get_isIndoors);
    lua_setfield(L, -2, "isIndoors");
    lua_pushcfunction(L, PreviewBuilding_get_AABB);
    lua_setfield(L, -2, "AABB");
    lua_pushcfunction(L, PreviewBuilding_get_buildDataPtr);
    lua_setfield(L, -2, "buildDataPtr");
    lua_pushcfunction(L, PreviewBuilding_get_farmData);
    lua_setfield(L, -2, "farmData");
    lua_pushcfunction(L, PreviewBuilding_get_prospectingOK);
    lua_setfield(L, -2, "prospectingOK");
    lua_pushcfunction(L, PreviewBuilding_get_furniture);
    lua_setfield(L, -2, "furniture");
    lua_pushcfunction(L, PreviewBuilding_get_exteriorFurniture);
    lua_setfield(L, -2, "exteriorFurniture");
    lua_pushcfunction(L, PreviewBuilding_get_pos);
    lua_setfield(L, -2, "pos");
    lua_pushcfunction(L, PreviewBuilding_get_rot);
    lua_setfield(L, -2, "rot");
    lua_pushcfunction(L, PreviewBuilding_get_positionHitGroup);
    lua_setfield(L, -2, "positionHitGroup");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, PreviewBuilding_set_parentNode);
    lua_setfield(L, -2, "parentNode");
    lua_pushcfunction(L, PreviewBuilding_set_entitiesList);
    lua_setfield(L, -2, "entitiesList");
    lua_pushcfunction(L, PreviewBuilding_set_footprints);
    lua_setfield(L, -2, "footprints");
    lua_pushcfunction(L, PreviewBuilding_set_isCurrentlySnapped);
    lua_setfield(L, -2, "isCurrentlySnapped");
    lua_pushcfunction(L, PreviewBuilding_set_snappedTo);
    lua_setfield(L, -2, "snappedTo");
    lua_pushcfunction(L, PreviewBuilding_set_usageNodes);
    lua_setfield(L, -2, "usageNodes");
    lua_pushcfunction(L, PreviewBuilding_set_prospectingInformation);
    lua_setfield(L, -2, "prospectingInformation");
    lua_pushcfunction(L, PreviewBuilding_set_prospectResource);
    lua_setfield(L, -2, "prospectResource");
    lua_pushcfunction(L, PreviewBuilding_set_roofOnly);
    lua_setfield(L, -2, "roofOnly");
    lua_pushcfunction(L, PreviewBuilding_set_spaceAbove);
    lua_setfield(L, -2, "spaceAbove");
    lua_pushcfunction(L, PreviewBuilding_set_spaceBelow);
    lua_setfield(L, -2, "spaceBelow");
    lua_pushcfunction(L, PreviewBuilding_set_collisionOK);
    lua_setfield(L, -2, "collisionOK");
    lua_pushcfunction(L, PreviewBuilding_set_charactersOK);
    lua_setfield(L, -2, "charactersOK");
    lua_pushcfunction(L, PreviewBuilding_set_floorOk);
    lua_setfield(L, -2, "floorOk");
    lua_pushcfunction(L, PreviewBuilding_set_indoorsOK);
    lua_setfield(L, -2, "indoorsOK");
    lua_pushcfunction(L, PreviewBuilding_set_slopeOK);
    lua_setfield(L, -2, "slopeOK");
    lua_pushcfunction(L, PreviewBuilding_set_nodesOk);
    lua_setfield(L, -2, "nodesOk");
    lua_pushcfunction(L, PreviewBuilding_set_blockedBuildings);
    lua_setfield(L, -2, "blockedBuildings");
    lua_pushcfunction(L, PreviewBuilding_set_validGround);
    lua_setfield(L, -2, "validGround");
    lua_pushcfunction(L, PreviewBuilding_set_inTown);
    lua_setfield(L, -2, "inTown");
    lua_pushcfunction(L, PreviewBuilding_set_floorNum);
    lua_setfield(L, -2, "floorNum");
    lua_pushcfunction(L, PreviewBuilding_set_isOutside);
    lua_setfield(L, -2, "isOutside");
    lua_pushcfunction(L, PreviewBuilding_set_matchSlope);
    lua_setfield(L, -2, "matchSlope");
    lua_pushcfunction(L, PreviewBuilding_set_nodeResults);
    lua_setfield(L, -2, "nodeResults");
    lua_pushcfunction(L, PreviewBuilding_set_justBeenBuilt);
    lua_setfield(L, -2, "justBeenBuilt");
    lua_pushcfunction(L, PreviewBuilding_set_yaw);
    lua_setfield(L, -2, "yaw");
    lua_pushcfunction(L, PreviewBuilding_set_centreOffset);
    lua_setfield(L, -2, "centreOffset");
    lua_pushcfunction(L, PreviewBuilding_set_isFurnitureOf);
    lua_setfield(L, -2, "isFurnitureOf");
    lua_pushcfunction(L, PreviewBuilding_set_isIndoors);
    lua_setfield(L, -2, "isIndoors");
    lua_pushcfunction(L, PreviewBuilding_set_AABB);
    lua_setfield(L, -2, "AABB");
    lua_pushcfunction(L, PreviewBuilding_set_buildDataPtr);
    lua_setfield(L, -2, "buildDataPtr");
    lua_pushcfunction(L, PreviewBuilding_set_farmData);
    lua_setfield(L, -2, "farmData");
    lua_pushcfunction(L, PreviewBuilding_set_prospectingOK);
    lua_setfield(L, -2, "prospectingOK");
    lua_pushcfunction(L, PreviewBuilding_set_furniture);
    lua_setfield(L, -2, "furniture");
    lua_pushcfunction(L, PreviewBuilding_set_exteriorFurniture);
    lua_setfield(L, -2, "exteriorFurniture");
    lua_pushcfunction(L, PreviewBuilding_set_pos);
    lua_setfield(L, -2, "pos");
    lua_pushcfunction(L, PreviewBuilding_set_rot);
    lua_setfield(L, -2, "rot");
    lua_pushcfunction(L, PreviewBuilding_set_positionHitGroup);
    lua_setfield(L, -2, "positionHitGroup");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setPlayableParent(L, PreviewBuildingBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}
}