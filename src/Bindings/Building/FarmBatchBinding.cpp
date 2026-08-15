#include "pch.h"
#include "Bindings/Building/FarmBatchBinding.h"
#include "Bindings/Building/FarmBuildingBinding.h"
#include "Bindings/FarmBuilding_PlantSourceBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static FarmBuilding::FarmBatch* getInstance(lua_State* L, int idx)
{
    return checkObject<FarmBuilding::FarmBatch>(L, idx, FarmBatchBinding::getMetatableName());
}

// --- Getters for FarmBatch ---
static int FarmBatch_get_plantSource(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    return pushObject<lektor<FarmBuilding::PlantSource*>>(L, &instance->plantSource, LektorPtrBinding<FarmBuilding::PlantSource*>::metaName);
}

static int FarmBatch_get_plantGroups(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    return pushObject<lektor<int>>(L, &instance->plantGroups, "lektor<int>");
}

static int FarmBatch_get_geometry(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    if (instance->geometry.get()) {
        lua_pushlightuserdata(L, (void*)instance->geometry.get());
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int FarmBatch_get_height(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    lua_pushnumber(L, instance->height);
    return 1;
}

static int FarmBatch_get_size(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    lua_pushinteger(L, instance->size);
    return 1;
}

static int FarmBatch_get_meshesLoaded(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    lua_pushinteger(L, instance->meshesLoaded);
    return 1;
}

static int FarmBatch_get_farms(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    return pushObject<lektor<FarmBuilding*>>(L, &instance->farms, LektorPtrBinding<FarmBuilding*>::metaName);
}

// --- Setters for FarmBatch ---
static int FarmBatch_set_plantSource(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    lektor<FarmBuilding::PlantSource*>* val = LektorPtrBinding<FarmBuilding::PlantSource*>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'plantSource' must be lektor<FarmBuilding::PlantSource*>");
    instance->plantSource = *val;
    return 0;
}

static int FarmBatch_set_plantGroups(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    lektor<int>* val = LektorIntBinding<int>::get(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<int>");
    instance->plantGroups = *val;
    return 0;
}

static int FarmBatch_set_geometry(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    return luaL_error(L, "Property '%s' is read-only or does not exist", lua_tostring(L, 2));
}

static int FarmBatch_set_height(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    instance->height = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBatch_set_size(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    instance->size = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int FarmBatch_set_meshesLoaded(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    instance->meshesLoaded = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int FarmBatch_set_farms(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    lektor<FarmBuilding*>* val = LektorPtrBinding<FarmBuilding*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<FarmBuilding*>");
    instance->farms = *val;
    return 0;
}

int FarmBatchBinding::load(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");

    instance->load();
    return 0;
}

int FarmBatchBinding::meshLoaded(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");

    Ogre::SharedPtr<Ogre::Resource>* res = (Ogre::SharedPtr<Ogre::Resource>*)lua_touserdata(L, 2);
    void* entityData = lua_touserdata(L, 3);
    if (res) {
        instance->meshLoaded(*res, entityData);
    }
    return 0;
}

int FarmBatchBinding::createGeometry(lua_State* L)
{
    FarmBuilding::FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");

    instance->createGeometry();
    return 0;
}

// --- Methods for FarmBatch
/*
LIGHTUSERDATA DEPENDENCIES:
  - FarmBatch_get_geometry / FarmBatch_set_geometry: Ogre::SharedPtr<Ogre::Mesh> (unbound pointer/smart-pointer type)
  - FarmBatchBinding::meshLoaded: Ogre::SharedPtr<Ogre::Resource> and void* entityData (unbound Ogre resource / raw pointer)
*/

int FarmBatchBinding::gc(lua_State* L)
{
    return 0;
}

int FarmBatchBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FarmBatch object");
    return 1;
}

void FarmBatchBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FarmBatchBinding::gc },
        { "__tostring", FarmBatchBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "load", FarmBatchBinding::load },
        { "meshLoaded", FarmBatchBinding::meshLoaded },
        { "createGeometry", FarmBatchBinding::createGeometry },
        { 0, 0 }
    };

    registerClass(
        L, 
        FarmBatchBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FarmBatchBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, FarmBatch_get_plantSource);
    lua_setfield(L, -2, "plantSource");
    lua_pushcfunction(L, FarmBatch_get_plantGroups);
    lua_setfield(L, -2, "plantGroups");
    lua_pushcfunction(L, FarmBatch_get_geometry);
    lua_setfield(L, -2, "geometry");
    lua_pushcfunction(L, FarmBatch_get_height);
    lua_setfield(L, -2, "height");
    lua_pushcfunction(L, FarmBatch_get_size);
    lua_setfield(L, -2, "size");
    lua_pushcfunction(L, FarmBatch_get_meshesLoaded);
    lua_setfield(L, -2, "meshesLoaded");
    lua_pushcfunction(L, FarmBatch_get_farms);
    lua_setfield(L, -2, "farms");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FarmBatch_set_plantSource);
    lua_setfield(L, -2, "plantSource");
    lua_pushcfunction(L, FarmBatch_set_plantGroups);
    lua_setfield(L, -2, "plantGroups");
    lua_pushcfunction(L, FarmBatch_set_geometry);
    lua_setfield(L, -2, "geometry");
    lua_pushcfunction(L, FarmBatch_set_height);
    lua_setfield(L, -2, "height");
    lua_pushcfunction(L, FarmBatch_set_size);
    lua_setfield(L, -2, "size");
    lua_pushcfunction(L, FarmBatch_set_meshesLoaded);
    lua_setfield(L, -2, "meshesLoaded");
    lua_pushcfunction(L, FarmBatch_set_farms);
    lua_setfield(L, -2, "farms");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
