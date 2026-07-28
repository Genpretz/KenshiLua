#include "pch.h"
#include <kenshi/FoliageSystem.h>
#include "EntDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

typedef FoliageSystem::EntData EntData;

static EntData* getInstance(lua_State* L, int idx)
{
    return checkObject<EntData>(L, idx, EntDataBinding::getMetatableName());
}

// --- Getters for EntData ---
static int EntData_get_data(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    return pushObject<GameData>(L, instance->data, GameDataBinding::getMetatableName());
}

static int EntData_get_maxSlope(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->maxSlope);
    return 1;
}

static int EntData_get_minSlope(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->minSlope);
    return 1;
}

static int EntData_get_chance(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->chance);
    return 1;
}

static int EntData_get_minAltitude(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->minAltitude);
    return 1;
}

static int EntData_get_maxAltitude(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->maxAltitude);
    return 1;
}

static int EntData_get_slopeAlign(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushboolean(L, instance->slopeAlign ? 1 : 0);
    return 1;
}

static int EntData_get_floating(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushboolean(L, instance->floating ? 1 : 0);
    return 1;
}

static int EntData_get_uniformScale(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushboolean(L, instance->uniformScale ? 1 : 0);
    return 1;
}

static int EntData_get_accurateTrace(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushboolean(L, instance->accurateTrace ? 1 : 0);
    return 1;
}

static int EntData_get_upright(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushboolean(L, instance->upright ? 1 : 0);
    return 1;
}

static int EntData_get_minV(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->minV);
    return 1;
}

static int EntData_get_maxV(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->maxV);
    return 1;
}

static int EntData_get_clustered(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushboolean(L, instance->clustered ? 1 : 0);
    return 1;
}

static int EntData_get_limitToGrassAreas(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushboolean(L, instance->limitToGrassAreas ? 1 : 0);
    return 1;
}

static int EntData_get_nonBatched(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushboolean(L, instance->nonBatched ? 1 : 0);
    return 1;
}

static int EntData_get_carveRadius(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->carveRadius);
    return 1;
}

static int EntData_get_grassSpot(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->grassSpot);
    return 1;
}

static int EntData_get_roadRadius(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->roadRadius);
    return 1;
}

static int EntData_get_clusterMin(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->clusterMin);
    return 1;
}

static int EntData_get_clusterMax(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->clusterMax);
    return 1;
}

static int EntData_get_clusterRadiusMin(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->clusterRadiusMin);
    return 1;
}

static int EntData_get_clusterRadiusMax(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->clusterRadiusMax);
    return 1;
}

static int EntData_get_viewDistance(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->viewDistance);
    return 1;
}

static int EntData_get_seedOffset(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushinteger(L, instance->seedOffset);
    return 1;
}

static int EntData_get_biomeSeparation(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushboolean(L, instance->biomeSeparation ? 1 : 0);
    return 1;
}

static int EntData_get_childClusterRadius(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushnumber(L, instance->childClusterRadius);
    return 1;
}

static int EntData_get_xmlFilename(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushstring(L, instance->xmlFilename.c_str());
    return 1;
}

static int EntData_get_entity1(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushlightuserdata(L, (void*)instance->entity1);
    return 1;
}

static int EntData_get_entity2(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushlightuserdata(L, (void*)instance->entity2);
    return 1;
}

static int EntData_get_entity1Loaded(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushboolean(L, instance->entity1Loaded ? 1 : 0);
    return 1;
}

static int EntData_get_entity2Loaded(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushboolean(L, instance->entity2Loaded ? 1 : 0);
    return 1;
}

static int EntData_get_position(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    pushVector3(L, instance->position);
    return 1;
}

static int EntData_get_type(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushinteger(L, (lua_Integer)instance->type);
    return 1;
}

static int EntData_get_referenceCount(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    lua_pushinteger(L, instance->referenceCount);
    return 1;
}

// --- Setters for EntData ---
static int EntData_set_data(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int EntData_set_maxSlope(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->maxSlope = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_minSlope(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->minSlope = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_chance(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->chance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_minAltitude(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->minAltitude = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_maxAltitude(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->maxAltitude = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_slopeAlign(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->slopeAlign = lua_toboolean(L, 2) != 0;
    return 0;
}

static int EntData_set_floating(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->floating = lua_toboolean(L, 2) != 0;
    return 0;
}

static int EntData_set_uniformScale(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->uniformScale = lua_toboolean(L, 2) != 0;
    return 0;
}

static int EntData_set_accurateTrace(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->accurateTrace = lua_toboolean(L, 2) != 0;
    return 0;
}

static int EntData_set_upright(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->upright = lua_toboolean(L, 2) != 0;
    return 0;
}

static int EntData_set_minV(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->minV = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_maxV(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->maxV = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_clustered(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->clustered = lua_toboolean(L, 2) != 0;
    return 0;
}

static int EntData_set_limitToGrassAreas(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->limitToGrassAreas = lua_toboolean(L, 2) != 0;
    return 0;
}

static int EntData_set_nonBatched(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->nonBatched = lua_toboolean(L, 2) != 0;
    return 0;
}

static int EntData_set_carveRadius(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->carveRadius = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_grassSpot(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->grassSpot = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_roadRadius(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->roadRadius = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_clusterMin(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->clusterMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_clusterMax(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->clusterMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_clusterRadiusMin(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->clusterRadiusMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_clusterRadiusMax(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->clusterRadiusMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_viewDistance(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->viewDistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_seedOffset(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->seedOffset = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int EntData_set_biomeSeparation(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->biomeSeparation = lua_toboolean(L, 2) != 0;
    return 0;
}

static int EntData_set_childClusterRadius(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->childClusterRadius = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EntData_set_xmlFilename(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->xmlFilename = luaL_checkstring(L, 2);
    return 0;
}

static int EntData_set_entity1Loaded(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->entity1Loaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int EntData_set_entity2Loaded(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->entity2Loaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int EntData_set_position(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    readVector3(L, 2, instance->position);
    return 0;
}

static int EntData_set_type(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->type = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int EntData_set_referenceCount(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");
    instance->referenceCount = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

int EntDataBinding::_CONSTRUCTOR(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");

    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool rld = lua_toboolean(L, 3) != 0;
    GameData* layer = checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
    EntData* result = instance->_CONSTRUCTOR(dat, rld, layer);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int EntDataBinding::_DESTRUCTOR(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int EntDataBinding::createEntity1(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");

    Ogre::Entity* result = instance->createEntity1();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int EntDataBinding::createEntity2(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");

    Ogre::Entity* result = instance->createEntity2();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int EntDataBinding::selectBiomeEntity(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    Ogre::Entity* result = instance->selectBiomeEntity(position);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int EntDataBinding::isLoaded(lua_State* L)
{
    EntData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "EntData is nil");

    bool result = instance->isLoaded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 38: void createEntity1Callback(...) - unsupported arg type
  line 40: void createEntity2Callback(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - EntData_get_entity1: Ogre::Entity* (unbound pointer)
  - EntData_get_entity2: Ogre::Entity* (unbound pointer)
  - EntDataBinding::_CONSTRUCTOR: EntData* (unbound pointer)
  - EntDataBinding::createEntity1: Ogre::Entity* (unbound pointer)
  - EntDataBinding::createEntity2: Ogre::Entity* (unbound pointer)
  - EntDataBinding::selectBiomeEntity: Ogre::Entity* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 54: scales (Ogre::Vector4) - unsupported type
  line 74: extraEntities (ogre_unordered_map<GameData*, Ogre::Entity*>::type) - unsupported type
  line 77: subEnts (lektor<FoliageSystem::EntData*>) - unsupported type
*/

int EntDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int EntDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.EntData object");
    return 1;
}

void EntDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       EntDataBinding::gc },
        { "__tostring", EntDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", EntDataBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", EntDataBinding::_DESTRUCTOR },
        { "createEntity1", EntDataBinding::createEntity1 },
        { "createEntity2", EntDataBinding::createEntity2 },
        { "selectBiomeEntity", EntDataBinding::selectBiomeEntity },
        { "isLoaded", EntDataBinding::isLoaded },
        { 0, 0 }
    };

    registerClass(
        L, 
        EntDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, EntDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "data", EntData_get_data);
    registerGetter(L, "maxSlope", EntData_get_maxSlope);
    registerGetter(L, "minSlope", EntData_get_minSlope);
    registerGetter(L, "chance", EntData_get_chance);
    registerGetter(L, "minAltitude", EntData_get_minAltitude);
    registerGetter(L, "maxAltitude", EntData_get_maxAltitude);
    registerGetter(L, "slopeAlign", EntData_get_slopeAlign);
    registerGetter(L, "floating", EntData_get_floating);
    registerGetter(L, "uniformScale", EntData_get_uniformScale);
    registerGetter(L, "accurateTrace", EntData_get_accurateTrace);
    registerGetter(L, "upright", EntData_get_upright);
    registerGetter(L, "minV", EntData_get_minV);
    registerGetter(L, "maxV", EntData_get_maxV);
    registerGetter(L, "clustered", EntData_get_clustered);
    registerGetter(L, "limitToGrassAreas", EntData_get_limitToGrassAreas);
    registerGetter(L, "nonBatched", EntData_get_nonBatched);
    registerGetter(L, "carveRadius", EntData_get_carveRadius);
    registerGetter(L, "grassSpot", EntData_get_grassSpot);
    registerGetter(L, "roadRadius", EntData_get_roadRadius);
    registerGetter(L, "clusterMin", EntData_get_clusterMin);
    registerGetter(L, "clusterMax", EntData_get_clusterMax);
    registerGetter(L, "clusterRadiusMin", EntData_get_clusterRadiusMin);
    registerGetter(L, "clusterRadiusMax", EntData_get_clusterRadiusMax);
    registerGetter(L, "viewDistance", EntData_get_viewDistance);
    registerGetter(L, "seedOffset", EntData_get_seedOffset);
    registerGetter(L, "biomeSeparation", EntData_get_biomeSeparation);
    registerGetter(L, "childClusterRadius", EntData_get_childClusterRadius);
    registerGetter(L, "xmlFilename", EntData_get_xmlFilename);
    registerGetter(L, "entity1", EntData_get_entity1);
    registerGetter(L, "entity2", EntData_get_entity2);
    registerGetter(L, "entity1Loaded", EntData_get_entity1Loaded);
    registerGetter(L, "entity2Loaded", EntData_get_entity2Loaded);
    registerGetter(L, "position", EntData_get_position);
    registerGetter(L, "type", EntData_get_type);
    registerGetter(L, "referenceCount", EntData_get_referenceCount);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "data", EntData_set_data);
    registerSetter(L, "maxSlope", EntData_set_maxSlope);
    registerSetter(L, "minSlope", EntData_set_minSlope);
    registerSetter(L, "chance", EntData_set_chance);
    registerSetter(L, "minAltitude", EntData_set_minAltitude);
    registerSetter(L, "maxAltitude", EntData_set_maxAltitude);
    registerSetter(L, "slopeAlign", EntData_set_slopeAlign);
    registerSetter(L, "floating", EntData_set_floating);
    registerSetter(L, "uniformScale", EntData_set_uniformScale);
    registerSetter(L, "accurateTrace", EntData_set_accurateTrace);
    registerSetter(L, "upright", EntData_set_upright);
    registerSetter(L, "minV", EntData_set_minV);
    registerSetter(L, "maxV", EntData_set_maxV);
    registerSetter(L, "clustered", EntData_set_clustered);
    registerSetter(L, "limitToGrassAreas", EntData_set_limitToGrassAreas);
    registerSetter(L, "nonBatched", EntData_set_nonBatched);
    registerSetter(L, "carveRadius", EntData_set_carveRadius);
    registerSetter(L, "grassSpot", EntData_set_grassSpot);
    registerSetter(L, "roadRadius", EntData_set_roadRadius);
    registerSetter(L, "clusterMin", EntData_set_clusterMin);
    registerSetter(L, "clusterMax", EntData_set_clusterMax);
    registerSetter(L, "clusterRadiusMin", EntData_set_clusterRadiusMin);
    registerSetter(L, "clusterRadiusMax", EntData_set_clusterRadiusMax);
    registerSetter(L, "viewDistance", EntData_set_viewDistance);
    registerSetter(L, "seedOffset", EntData_set_seedOffset);
    registerSetter(L, "biomeSeparation", EntData_set_biomeSeparation);
    registerSetter(L, "childClusterRadius", EntData_set_childClusterRadius);
    registerSetter(L, "xmlFilename", EntData_set_xmlFilename);
    registerSetter(L, "entity1Loaded", EntData_set_entity1Loaded);
    registerSetter(L, "entity2Loaded", EntData_set_entity2Loaded);
    registerSetter(L, "position", EntData_set_position);
    registerSetter(L, "type", EntData_set_type);
    registerSetter(L, "referenceCount", EntData_set_referenceCount);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, EntDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua