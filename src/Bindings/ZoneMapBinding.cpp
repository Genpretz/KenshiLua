#include "pch.h"
#include "kenshi\ZoneManager.h"
#include "ZoneMapBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Util/iVector2Binding.h"
#include <kenshi/ZoneManager.h>

namespace KenshiLua
{

static ZoneMap* getInstance(lua_State* L, int idx)
{
    return checkObject<ZoneMap>(L, idx, ZoneMapBinding::getMetatableName());
}

// --- Getters for ZoneMap ---
static int ZoneMap_get_mapContent(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    lua_pushlightuserdata(L, (void*)instance->mapContent);
    return 1;
}

static int ZoneMap_get_mapFeatures(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    lua_pushlightuserdata(L, (void*)instance->mapFeatures);
    return 1;
}

static int ZoneMap_get_zoneSmell(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    lua_pushlightuserdata(L, (void*)instance->zoneSmell);
    return 1;
}

static int ZoneMap_get_coordinates(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    return pushObject<iVector2>(L, &instance->coordinates, iVector2Binding::getMetatableName());
}

static int ZoneMap_get_island(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    lua_pushinteger(L, instance->island);
    return 1;
}

static int ZoneMap_get_hasFile(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    lua_pushboolean(L, instance->hasFile ? 1 : 0);
    return 1;
}

static int ZoneMap_get_terrainCollision(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    lua_pushlightuserdata(L, (void*)instance->terrainCollision);
    return 1;
}

static int ZoneMap_get_activatedCountdown(lua_State* L) { return 0; }

static int ZoneMap_get__generateNavMeshesFlag(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    lua_pushboolean(L, instance->_generateNavMeshesFlag ? 1 : 0);
    return 1;
}

static int ZoneMap_get_center(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    pushVector3(L, instance->center);
    return 1;
}

static int ZoneMap_get_loadCount(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    lua_pushinteger(L, instance->loadCount);
    return 1;
}

static int ZoneMap_get_neighbors(lua_State* L) { return 0; }

static int ZoneMap_get_neighborsDiagonal(lua_State* L) { return 0; }

static int ZoneMap_get_AABB(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    pushVector4(L, instance->AABB);
    return 1;
}

// --- Setters for ZoneMap ---
static int ZoneMap_set_AABB(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    readVector4(L, 2, instance->AABB);
    return 0;
}

static int ZoneMap_set_coordinates(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    instance->coordinates = *checkObject<iVector2>(L, 2, iVector2Binding::getMetatableName());
    return 0;
}

static int ZoneMap_set_island(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    instance->island = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ZoneMap_set_hasFile(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    instance->hasFile = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ZoneMap_set_activatedCountdown(lua_State* L) { return 0; }

static int ZoneMap_set__generateNavMeshesFlag(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    instance->_generateNavMeshesFlag = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ZoneMap_set_center(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    readVector3(L, 2, instance->center);
    return 0;
}

static int ZoneMap_set_loadCount(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");
    instance->loadCount = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ZoneMap_set_neighbors(lua_State* L) { return 0; }

static int ZoneMap_set_neighborsDiagonal(lua_State* L) { return 0; }

int ZoneMapBinding::isInIsland(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    ZoneMap* other = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    bool result = instance->isInIsland(other);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapBinding::initialise(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    instance->initialise();
    return 0;
}

int ZoneMapBinding::threadedUpdate(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    instance->threadedUpdate();
    return 0;
}

int ZoneMapBinding::update(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    bool result = instance->update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapBinding::selectBiomes(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    int result = instance->selectBiomes();
    lua_pushinteger(L, result);
    return 1;
}

int ZoneMapBinding::getBiomeCount(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    int result = instance->getBiomeCount();
    lua_pushinteger(L, result);
    return 1;
}

int ZoneMapBinding::getBiomeData(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    int i = (int)luaL_checkinteger(L, 2);
    GameData* result = instance->getBiomeData(i);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int ZoneMapBinding::getOverlay(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    ZoneMapOverlay* result = instance->getOverlay();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ZoneMapBinding::getAreaSector(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    AreaSector* result = instance->getAreaSector();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ZoneMapBinding::getTerrainHeight(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    float _x = (float)luaL_checknumber(L, 2);
    float _y = (float)luaL_checknumber(L, 3);
    float result = instance->getTerrainHeight(_x, _y);
    lua_pushnumber(L, result);
    return 1;
}

int ZoneMapBinding::getTerrainHeightWithNormal(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    float _x = (float)luaL_checknumber(L, 2);
    float _y = (float)luaL_checknumber(L, 3);
    Ogre::Vector3 normal;
    readVector3(L, 4, normal);
    float result = instance->getTerrainHeightWithNormal(_x, _y, normal);
    lua_pushnumber(L, result);
    return 1;
}

int ZoneMapBinding::getTerrainSlope(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    float _x = (float)luaL_checknumber(L, 2);
    float _y = (float)luaL_checknumber(L, 3);
    float result = instance->getTerrainSlope(_x, _y);
    lua_pushnumber(L, result);
    return 1;
}

int ZoneMapBinding::isWithinBoundsMinusUnloadedEdges(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    float borderThickness = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 v;
    readVector3(L, 3, v);
    bool result = instance->isWithinBoundsMinusUnloadedEdges(borderThickness, v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapBinding::getCornerPos(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    Ogre::Vector3 result = instance->getCornerPos();
    pushVector3(L, result);
    return 1;
}

int ZoneMapBinding::getTerrainSector(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    bool force = lua_toboolean(L, 2) != 0;
    TerrainSector* result = instance->getTerrainSector(force);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ZoneMapBinding::isActive(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    bool result = instance->isActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapBinding::getDeactivationCountdown(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    float result = instance->getDeactivationCountdown();
    lua_pushnumber(L, result);
    return 1;
}

int ZoneMapBinding::isLoadedBT(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    bool result = instance->isLoadedBT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapBinding::isBeingLoadedBT(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    bool result = instance->isBeingLoadedBT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapBinding::isLoadedMT(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    bool result = instance->isLoadedMT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapBinding::isBeingLoadedMT(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    bool result = instance->isBeingLoadedMT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapBinding::isANeighbour(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    ZoneMap* who = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    bool result = instance->isANeighbour(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapBinding::isTerrainCollisionLoaded(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    bool result = instance->isTerrainCollisionLoaded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapBinding::_makeSureTerrainHeightmapLoaded(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    instance->_makeSureTerrainHeightmapLoaded();
    return 0;
}

int ZoneMapBinding::_dactivateMT(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    bool saveZoneState = lua_toboolean(L, 2) != 0;
    instance->_dactivateMT(saveZoneState);
    return 0;
}

int ZoneMapBinding::generateNavMeshes(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    bool result = instance->generateNavMeshes();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapBinding::updateBuildingUsageNodes(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    instance->updateBuildingUsageNodes();
    return 0;
}

int ZoneMapBinding::getBounds(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    pushVector4(L, instance->getBounds());
    return 1;
}

int ZoneMapBinding::getBoundsMinusUnloadedEdges(lua_State* L)
{
    ZoneMap* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMap is nil");

    float borderThickness = (float)luaL_checknumber(L, 2);
    pushVector4(L, instance->getBoundsMinusUnloadedEdges(borderThickness));
    return 1;
}

/*
Skipped methods needing manual binding:
  line 206: void init(...) - non-string reference arg
  line 207: void getActiveZoneIsland(...) - unsupported arg type
  line 221: const Ogre::Aabb& getBoundingBox(...) - reference return type
  line 225: const Ogre::Vector3& getCenterPos(...) - reference return type
  line 229: bool isActivationType(...) - unsupported arg type
  line 235: void getActiveNeighbours4(...) - unsupported arg type
  line 236: void getActiveNeighbours8(...) - unsupported arg type
  line 239: void getMaterialValues(...) - static method
  line 240: Ogre::SharedPtr<Ogre::Material> getTerrainMaterial_DX11(...) - static method
  line 241: std::string getBiomeTextureArrayData(...) - static method
  line 242: Ogre::SharedPtr<Ogre::Texture> createTextureArray(...) - static method
  line 243: Ogre::SharedPtr<Ogre::Material> materialCallback(...) - static method
  line 244: void destroyMaterialCallback(...) - static method
  line 262: bool _activate(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - ZoneMap_get_mapContent: ZoneMapContent* (unbound pointer)
  - ZoneMap_get_mapFeatures: MapFeatureList* (unbound pointer)
  - ZoneMap_get_zoneSmell: ZoneSmell* (unbound pointer)
  - ZoneMap_get_terrainCollision: TerrainSector* (unbound pointer)
  - ZoneMapBinding::getOverlay: ZoneMapOverlay* (unbound pointer)
  - ZoneMapBinding::getAreaSector: AreaSector* (unbound pointer)
  - ZoneMapBinding::getTerrainSector: TerrainSector* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 252: zoneIncomingMessagesT (BackThreadMessagesToMainT<ZONE_MESSAGE>) - unsupported type
  line 266: stateT (MainthreadStateReaderT<ZoneMap::StateT>) - unsupported type
  line 270: bounds (Ogre::Aabb) - unsupported type
  line 273: biomes (lektor<GameData*>) - unsupported type
*/

int ZoneMapBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ZoneMapBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ZoneMap object");
    return 1;
}

void ZoneMapBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ZoneMapBinding::gc },
        { "__tostring", ZoneMapBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isInIsland", ZoneMapBinding::isInIsland },
        { "initialise", ZoneMapBinding::initialise },
        { "threadedUpdate", ZoneMapBinding::threadedUpdate },
        { "update", ZoneMapBinding::update },
        { "selectBiomes", ZoneMapBinding::selectBiomes },
        { "getBiomeCount", ZoneMapBinding::getBiomeCount },
        { "getBiomeData", ZoneMapBinding::getBiomeData },
        { "getOverlay", ZoneMapBinding::getOverlay },
        { "getAreaSector", ZoneMapBinding::getAreaSector },
        { "getTerrainHeight", ZoneMapBinding::getTerrainHeight },
        { "getTerrainHeightWithNormal", ZoneMapBinding::getTerrainHeightWithNormal },
        { "getTerrainSlope", ZoneMapBinding::getTerrainSlope },
        { "isWithinBoundsMinusUnloadedEdges", ZoneMapBinding::isWithinBoundsMinusUnloadedEdges },
        { "getCornerPos", ZoneMapBinding::getCornerPos },
        { "getTerrainSector", ZoneMapBinding::getTerrainSector },
        { "isActive", ZoneMapBinding::isActive },
        { "getDeactivationCountdown", ZoneMapBinding::getDeactivationCountdown },
        { "isLoadedBT", ZoneMapBinding::isLoadedBT },
        { "isBeingLoadedBT", ZoneMapBinding::isBeingLoadedBT },
        { "isLoadedMT", ZoneMapBinding::isLoadedMT },
        { "isBeingLoadedMT", ZoneMapBinding::isBeingLoadedMT },
        { "isANeighbour", ZoneMapBinding::isANeighbour },
        { "isTerrainCollisionLoaded", ZoneMapBinding::isTerrainCollisionLoaded },
        { "_makeSureTerrainHeightmapLoaded", ZoneMapBinding::_makeSureTerrainHeightmapLoaded },
        { "_dactivateMT", ZoneMapBinding::_dactivateMT },
        { "generateNavMeshes", ZoneMapBinding::generateNavMeshes },
        { "updateBuildingUsageNodes", ZoneMapBinding::updateBuildingUsageNodes },
        { "getBounds", ZoneMapBinding::getBounds },
        { "getBoundsMinusUnloadedEdges", ZoneMapBinding::getBoundsMinusUnloadedEdges },
        { 0, 0 }
    };

    registerClass(
        L, 
        ZoneMapBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ZoneMapBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "mapContent", ZoneMap_get_mapContent);
    registerGetter(L, "mapFeatures", ZoneMap_get_mapFeatures);
    registerGetter(L, "zoneSmell", ZoneMap_get_zoneSmell);
    registerGetter(L, "coordinates", ZoneMap_get_coordinates);
    registerGetter(L, "island", ZoneMap_get_island);
    registerGetter(L, "hasFile", ZoneMap_get_hasFile);
    registerGetter(L, "terrainCollision", ZoneMap_get_terrainCollision);
    registerGetter(L, "activatedCountdown", ZoneMap_get_activatedCountdown);
    registerGetter(L, "_generateNavMeshesFlag", ZoneMap_get__generateNavMeshesFlag);
    registerGetter(L, "center", ZoneMap_get_center);
    registerGetter(L, "loadCount", ZoneMap_get_loadCount);
    registerGetter(L, "neighbors", ZoneMap_get_neighbors);
    registerGetter(L, "neighborsDiagonal", ZoneMap_get_neighborsDiagonal);
    registerGetter(L, "AABB", ZoneMap_get_AABB);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "coordinates", ZoneMap_set_coordinates);
    registerSetter(L, "island", ZoneMap_set_island);
    registerSetter(L, "hasFile", ZoneMap_set_hasFile);
    registerSetter(L, "activatedCountdown", ZoneMap_set_activatedCountdown);
    registerSetter(L, "_generateNavMeshesFlag", ZoneMap_set__generateNavMeshesFlag);
    registerSetter(L, "center", ZoneMap_set_center);
    registerSetter(L, "loadCount", ZoneMap_set_loadCount);
    registerSetter(L, "neighbors", ZoneMap_set_neighbors);
    registerSetter(L, "neighborsDiagonal", ZoneMap_set_neighborsDiagonal);
    registerSetter(L, "AABB", ZoneMap_set_AABB);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, ZoneMapBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua