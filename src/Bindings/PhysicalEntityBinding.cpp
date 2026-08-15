#include "pch.h"
#include "kenshi\physicscollection.h"
#include "PhysicalEntityBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static PhysicalEntity* getInstance(lua_State* L, int idx)
{
    return checkObject<PhysicalEntity>(L, idx, PhysicalEntityBinding::getMetatableName());
}

// --- Getters for PhysicalEntity ---
static int PhysicalEntity_get_ent(lua_State* L)
{
    PhysicalEntity* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicalEntity is nil");
    lua_pushlightuserdata(L, (void*)instance->ent);
    return 1;
}

static int PhysicalEntity_get_parent(lua_State* L)
{
    PhysicalEntity* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicalEntity is nil");
    lua_pushlightuserdata(L, (void*)instance->parent);
    return 1;
}

static int PhysicalEntity_get_floorNumber(lua_State* L)
{
    PhysicalEntity* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicalEntity is nil");
    lua_pushinteger(L, instance->floorNumber);
    return 1;
}

static int PhysicalEntity_get_mat(lua_State* L)
{
    PhysicalEntity* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicalEntity is nil");
    return pushObject<GameData>(L, instance->mat, GameDataBinding::getMetatableName());
}

static int PhysicalEntity_get_partData(lua_State* L)
{
    PhysicalEntity* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicalEntity is nil");
    return pushObject<GameData>(L, instance->partData, GameDataBinding::getMetatableName());
}

static int PhysicalEntity_get_instanced(lua_State* L)
{
    PhysicalEntity* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicalEntity is nil");
    lua_pushboolean(L, instance->instanced ? 1 : 0);
    return 1;
}

static int PhysicalEntity_get_isShell(lua_State* L)
{
    PhysicalEntity* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicalEntity is nil");
    lua_pushboolean(L, instance->isShell ? 1 : 0);
    return 1;
}

static int PhysicalEntity_get_isEmissive(lua_State* L)
{
    PhysicalEntity* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicalEntity is nil");
    lua_pushboolean(L, instance->isEmissive ? 1 : 0);
    return 1;
}

// --- Setters for PhysicalEntity ---
static int PhysicalEntity_set_floorNumber(lua_State* L)
{
    PhysicalEntity* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicalEntity is nil");
    instance->floorNumber = (char)luaL_checkinteger(L, 2);
    return 0;
}

static int PhysicalEntity_set_mat(lua_State* L)
{
    PhysicalEntity* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicalEntity is nil");
    instance->mat = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int PhysicalEntity_set_partData(lua_State* L)
{
    PhysicalEntity* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicalEntity is nil");
    instance->partData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int PhysicalEntity_set_instanced(lua_State* L)
{
    PhysicalEntity* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicalEntity is nil");
    instance->instanced = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PhysicalEntity_set_isShell(lua_State* L)
{
    PhysicalEntity* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicalEntity is nil");
    instance->isShell = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PhysicalEntity_set_isEmissive(lua_State* L)
{
    PhysicalEntity* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicalEntity is nil");
    instance->isEmissive = lua_toboolean(L, 2) != 0;
    return 0;
}


/*
LIGHTUSERDATA DEPENDENCIES:
  - PhysicalEntity_get_ent: Ogre::MovableObject* (unbound pointer)
  - PhysicalEntity_get_parent: PhysicalEntity* (unbound pointer)
*/

int PhysicalEntityBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int PhysicalEntityBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.PhysicalEntity object");
    return 1;
}

void PhysicalEntityBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PhysicalEntityBinding::gc },
        { "__tostring", PhysicalEntityBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        PhysicalEntityBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, PhysicalEntityBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "ent", PhysicalEntity_get_ent);
    registerGetter(L, "parent", PhysicalEntity_get_parent);
    registerGetter(L, "floorNumber", PhysicalEntity_get_floorNumber);
    registerGetter(L, "mat", PhysicalEntity_get_mat);
    registerGetter(L, "partData", PhysicalEntity_get_partData);
    registerGetter(L, "instanced", PhysicalEntity_get_instanced);
    registerGetter(L, "isShell", PhysicalEntity_get_isShell);
    registerGetter(L, "isEmissive", PhysicalEntity_get_isEmissive);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "floorNumber", PhysicalEntity_set_floorNumber);
    registerSetter(L, "mat", PhysicalEntity_set_mat);
    registerSetter(L, "partData", PhysicalEntity_set_partData);
    registerSetter(L, "instanced", PhysicalEntity_set_instanced);
    registerSetter(L, "isShell", PhysicalEntity_set_isShell);
    registerSetter(L, "isEmissive", PhysicalEntity_set_isEmissive);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, PhysicalEntityBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua