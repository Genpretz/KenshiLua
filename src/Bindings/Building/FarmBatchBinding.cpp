#include "pch.h"
#include <kenshi/Building/FarmBuilding.h>
#include "FarmBatchBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef FarmBuilding::FarmBatch FarmBatch;

static FarmBatch* getInstance(lua_State* L, int idx)
{
    return checkObject<FarmBatch>(L, idx, FarmBatchBinding::getMetatableName());
}

// --- Getters for FarmBatch ---
static int FarmBatch_get_plantSource(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    // TODO: Unsupported type for plantSource (lektor<FarmBuilding::PlantSource*>)
    lua_pushnil(L);
    return 1;
}

static int FarmBatch_get_plantGroups(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    // TODO: Unsupported type for plantGroups (lektor<int>)
    lua_pushnil(L);
    return 1;
}

static int FarmBatch_get_geometry(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    // TODO: Unsupported type for geometry (Ogre::SharedPtr<Ogre::Mesh>)
    lua_pushnil(L);
    return 1;
}

static int FarmBatch_get_height(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    lua_pushnumber(L, instance->height);
    return 1;
}

static int FarmBatch_get_size(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    lua_pushinteger(L, instance->size);
    return 1;
}

static int FarmBatch_get_meshesLoaded(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    lua_pushinteger(L, instance->meshesLoaded);
    return 1;
}

static int FarmBatch_get_farms(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    // TODO: Unsupported type for farms (lektor<FarmBuilding*>)
    lua_pushnil(L);
    return 1;
}

// --- Setters for FarmBatch ---
static int FarmBatch_set_plantSource(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    return luaL_error(L, "Read-only or unsupported setter type for plantSource");
}

static int FarmBatch_set_plantGroups(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    return luaL_error(L, "Read-only or unsupported setter type for plantGroups");
}

static int FarmBatch_set_geometry(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    return luaL_error(L, "Read-only or unsupported setter type for geometry");
}

static int FarmBatch_set_height(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    instance->height = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBatch_set_size(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    instance->size = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int FarmBatch_set_meshesLoaded(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    instance->meshesLoaded = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int FarmBatch_set_farms(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");
    return luaL_error(L, "Read-only or unsupported setter type for farms");
}

int FarmBatchBinding::load(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");

    instance->load();
    return 0;
}

int FarmBatchBinding::createGeometry(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");

    instance->createGeometry();
    return 0;
}

// --- Methods for FarmBatch
int FarmBatchBinding::_DESTRUCTOR(lua_State* L)
{
    FarmBatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBatch is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 102: FarmBatch* _CONSTRUCTOR(...) - unsupported arg type
  line 104: void meshLoaded(...) - unsupported arg type
*/

int FarmBatchBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
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
        { "createGeometry", FarmBatchBinding::createGeometry },
        { "_DESTRUCTOR", FarmBatchBinding::_DESTRUCTOR },
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