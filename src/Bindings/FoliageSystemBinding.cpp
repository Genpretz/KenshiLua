#include "pch.h"
#include <kenshi/FoliageSystem.h>
#include "FoliageSystemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/ZoneMapBinding.h"

namespace KenshiLua
{

static FoliageSystem* getInstance(lua_State* L, int idx)
{
    return checkObject<FoliageSystem>(L, idx, FoliageSystemBinding::getMetatableName());
}

// --- Getters for FoliageSystem ---
static int FoliageSystem_get_reloaded(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");
    lua_pushboolean(L, instance->reloaded ? 1 : 0);
    return 1;
}

static int FoliageSystem_get_generateOverlay(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");
    lua_pushboolean(L, instance->generateOverlay ? 1 : 0);
    return 1;
}

static int FoliageSystem_get_firstTimeLoad(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");
    lua_pushboolean(L, instance->firstTimeLoad ? 1 : 0);
    return 1;
}

static int FoliageSystem_get_collisionHash(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");
    lua_pushinteger(L, instance->collisionHash);
    return 1;
}

static int FoliageSystem_get_loadComplete(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");
    lua_pushboolean(L, instance->loadComplete ? 1 : 0);
    return 1;
}

static int FoliageSystem_get_zoneMap(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");
    return pushObject<ZoneMap>(L, instance->zoneMap, ZoneMapBinding::getMetatableName());
}

static int FoliageSystem_get_coverageMap(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");
    lua_pushlightuserdata(L, (void*)instance->coverageMap);
    return 1;
}

// --- Setters for FoliageSystem ---
static int FoliageSystem_set_reloaded(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");
    instance->reloaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int FoliageSystem_set_generateOverlay(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");
    instance->generateOverlay = lua_toboolean(L, 2) != 0;
    return 0;
}

static int FoliageSystem_set_firstTimeLoad(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");
    instance->firstTimeLoad = lua_toboolean(L, 2) != 0;
    return 0;
}

static int FoliageSystem_set_collisionHash(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");
    instance->collisionHash = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int FoliageSystem_set_loadComplete(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");
    instance->loadComplete = lua_toboolean(L, 2) != 0;
    return 0;
}

static int FoliageSystem_set_zoneMap(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");
    instance->zoneMap = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    return 0;
}

int FoliageSystemBinding::update(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");

    instance->update();
    return 0;
}

int FoliageSystemBinding::getCollisionHash(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");

    unsigned int result = instance->getCollisionHash();
    lua_pushinteger(L, result);
    return 1;
}

int FoliageSystemBinding::setupGrass(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");

    GameData* layerData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Forests::PagedGeometry* paged = (Forests::PagedGeometry*)lua_touserdata(L, 3);
    Forests::GrassLoader* grassLoader = (Forests::GrassLoader*)lua_touserdata(L, 4);
    int biomeCode = (int)luaL_checkinteger(L, 5);
    instance->setupGrass(layerData, paged, grassLoader, biomeCode);
    return 0;
}

int FoliageSystemBinding::setupFoliage(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");

    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Forests::PagedGeometry* paged = (Forests::PagedGeometry*)lua_touserdata(L, 3);
    Forests::TreeLoader3D* treeLoader = (Forests::TreeLoader3D*)lua_touserdata(L, 4);
    int biomeCode = (int)luaL_checkinteger(L, 5);
    instance->setupFoliage(dat, paged, treeLoader, biomeCode);
    return 0;
}

int FoliageSystemBinding::spawn(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");

    FoliageSystem::EntData* ent = (FoliageSystem::EntData*)lua_touserdata(L, 2);
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    Forests::TreeLoader3D* _treeLoader = (Forests::TreeLoader3D*)lua_touserdata(L, 4);
    bool result = instance->spawn(ent, position, _treeLoader);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FoliageSystemBinding::randomInt(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");

    int min = (int)luaL_checkinteger(L, 2);
    int max = (int)luaL_checkinteger(L, 3);
    int result = instance->randomInt(min, max);
    lua_pushinteger(L, result);
    return 1;
}

int FoliageSystemBinding::random(lua_State* L)
{
    FoliageSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FoliageSystem is nil");

    float min = (float)luaL_checknumber(L, 2);
    float max = (float)luaL_checknumber(L, 3);
    float result = instance->random(min, max);
    lua_pushnumber(L, result);
    return 1;
}

int FoliageSystemBinding::clearStaticData(lua_State* L)
{
    FoliageSystem::clearStaticData();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 91: int getNavmeshCarvers(...) - unsupported arg type
  line 112: void loadEnts(...) - unsupported arg type
  line 114: bool finalMakeEnt(...) - unsupported arg type
  line 115: void setupWind(...) - unsupported arg type
  line 120: int addGrassLayerToCoverageMap(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - FoliageSystem_get_coverageMap: RealWorldEditableImage* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 125: pageLayers (lektor<Forests::PagedGeometry*>) - unsupported type
  line 126: treeListsWithCarvers (lektor<Forests::TreeLoader3D*>) - unsupported type
  line 127: loadedEnts (ogre_unordered_set<FoliageSystem::EntData*>::type) - unsupported type
  line 131: usedEntsCount (ogre_unordered_map<GameData*, int>::type) - unsupported type
  line 132: collisionList (lektor<SimplePhysXEntity*>) - unsupported type
  line 133: soundEmitters (lektor<SoundEmitter*>) - unsupported type
  line 134: soundUpdate (lektor<SoundEmitter*>) - unsupported type
*/

int FoliageSystemBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FoliageSystemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FoliageSystem object");
    return 1;
}

void FoliageSystemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FoliageSystemBinding::gc },
        { "__tostring", FoliageSystemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", FoliageSystemBinding::update },
        { "getCollisionHash", FoliageSystemBinding::getCollisionHash },
        { "setupGrass", FoliageSystemBinding::setupGrass },
        { "setupFoliage", FoliageSystemBinding::setupFoliage },
        { "spawn", FoliageSystemBinding::spawn },
        { "randomInt", FoliageSystemBinding::randomInt },
        { "random", FoliageSystemBinding::random },
        { "clearStaticData", FoliageSystemBinding::clearStaticData },
        { 0, 0 }
    };

    registerClass(
        L, 
        FoliageSystemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FoliageSystemBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "reloaded", FoliageSystem_get_reloaded);
    registerGetter(L, "generateOverlay", FoliageSystem_get_generateOverlay);
    registerGetter(L, "firstTimeLoad", FoliageSystem_get_firstTimeLoad);
    registerGetter(L, "collisionHash", FoliageSystem_get_collisionHash);
    registerGetter(L, "loadComplete", FoliageSystem_get_loadComplete);
    registerGetter(L, "zoneMap", FoliageSystem_get_zoneMap);
    registerGetter(L, "coverageMap", FoliageSystem_get_coverageMap);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "reloaded", FoliageSystem_set_reloaded);
    registerSetter(L, "generateOverlay", FoliageSystem_set_generateOverlay);
    registerSetter(L, "firstTimeLoad", FoliageSystem_set_firstTimeLoad);
    registerSetter(L, "collisionHash", FoliageSystem_set_collisionHash);
    registerSetter(L, "loadComplete", FoliageSystem_set_loadComplete);
    registerSetter(L, "zoneMap", FoliageSystem_set_zoneMap);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, FoliageSystemBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    lua_getglobal(L, "FoliageSystem");
    if (!lua_istable(L, -1))
    {
        lua_pop(L, 1);
        lua_newtable(L);
    }
    registerStaticMethod(L, "clearStaticData", FoliageSystemBinding::clearStaticData);
    lua_setglobal(L, "FoliageSystem");
}

} // namespace KenshiLua