#include "pch.h"
#include "kenshi\RootObjectFactory.h"
#include "RootObjectContainerBinding.h"
#include "CreatelistItemBinding.h"
//#include "BuildingBinding.h"
#include "FactionBinding.h"
#include "GameDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static RootObjectFactory::CreatelistItem* getB(lua_State* L, int idx)
{
    return checkObject<RootObjectFactory::CreatelistItem>(L, idx, CreatelistItemBinding::getMetatableName());
}

// --- Getters for CreatelistItem ---
static int CreatelistItem_get_container(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    return pushObject<RootObjectContainer>(L, b->container, RootObjectContainerBinding::getMetatableName());
}

static int CreatelistItem_get_homeBuilding(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    return pushObject<Building>(L, b->homeBuilding, "KenshiLua.Building");
}

static int CreatelistItem_get_faction(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    return pushObject<Faction>(L, b->faction, FactionBinding::getMetatableName());
}

static int CreatelistItem_get_data(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    return pushObject<GameData>(L, b->data, GameDataBinding::getMetatableName());
}

static int CreatelistItem_get_position(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    pushVector3(L, b->position);
    return 1;
}

static int CreatelistItem_get_isFromActiveLevelMod(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    lua_pushboolean(L, b->isFromActiveLevelMod ? 1 : 0);
    return 1;
}

static int CreatelistItem_get_rotation(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    pushQuaternion(L, b->rotation);
    return 1;
}

static int CreatelistItem_get_callbackObject(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    // TODO: Unsupported type for callbackObject (FactoryCallbackInterface*)
    lua_pushnil(L);
    return 1;
}

static int CreatelistItem_get_saveState(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    // TODO: Unsupported type for saveState (GameSaveState*)
    lua_pushnil(L);
    return 1;
}

static int CreatelistItem_get_age(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    lua_pushnumber(L, b->age);
    return 1;
}

// --- Setters for CreatelistItem ---
static int CreatelistItem_set_container(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for container");
}

static int CreatelistItem_set_homeBuilding(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for homeBuilding");
}

static int CreatelistItem_set_faction(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for faction");
}

static int CreatelistItem_set_data(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for data");
}

static int CreatelistItem_set_position(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    readVector3(L, 2, b->position);
    return 0;
}

static int CreatelistItem_set_isFromActiveLevelMod(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    b->isFromActiveLevelMod = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CreatelistItem_set_rotation(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    readQuaternion(L, 2, b->rotation);
    return 0;
}

static int CreatelistItem_set_callbackObject(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for callbackObject");
}

static int CreatelistItem_set_saveState(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for saveState");
}

static int CreatelistItem_set_age(lua_State* L)
{
    RootObjectFactory::CreatelistItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "CreatelistItem is nil");
    b->age = (float)luaL_checknumber(L, 2);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 58: RootObjectFactory::CreatelistItem* _CONSTRUCTOR(...) - unsupported return type
*/

int CreatelistItemBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CreatelistItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CreatelistItem object");
    return 1;
}

void CreatelistItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CreatelistItemBinding::gc },
        { "__tostring", CreatelistItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        CreatelistItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CreatelistItemBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CreatelistItem_get_container);
    lua_setfield(L, -2, "container");
    lua_pushcfunction(L, CreatelistItem_get_homeBuilding);
    lua_setfield(L, -2, "homeBuilding");
    lua_pushcfunction(L, CreatelistItem_get_faction);
    lua_setfield(L, -2, "faction");
    lua_pushcfunction(L, CreatelistItem_get_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, CreatelistItem_get_position);
    lua_setfield(L, -2, "position");
    lua_pushcfunction(L, CreatelistItem_get_isFromActiveLevelMod);
    lua_setfield(L, -2, "isFromActiveLevelMod");
    lua_pushcfunction(L, CreatelistItem_get_rotation);
    lua_setfield(L, -2, "rotation");
    lua_pushcfunction(L, CreatelistItem_get_callbackObject);
    lua_setfield(L, -2, "callbackObject");
    lua_pushcfunction(L, CreatelistItem_get_saveState);
    lua_setfield(L, -2, "saveState");
    lua_pushcfunction(L, CreatelistItem_get_age);
    lua_setfield(L, -2, "age");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CreatelistItem_set_container);
    lua_setfield(L, -2, "container");
    lua_pushcfunction(L, CreatelistItem_set_homeBuilding);
    lua_setfield(L, -2, "homeBuilding");
    lua_pushcfunction(L, CreatelistItem_set_faction);
    lua_setfield(L, -2, "faction");
    lua_pushcfunction(L, CreatelistItem_set_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, CreatelistItem_set_position);
    lua_setfield(L, -2, "position");
    lua_pushcfunction(L, CreatelistItem_set_isFromActiveLevelMod);
    lua_setfield(L, -2, "isFromActiveLevelMod");
    lua_pushcfunction(L, CreatelistItem_set_rotation);
    lua_setfield(L, -2, "rotation");
    lua_pushcfunction(L, CreatelistItem_set_callbackObject);
    lua_setfield(L, -2, "callbackObject");
    lua_pushcfunction(L, CreatelistItem_set_saveState);
    lua_setfield(L, -2, "saveState");
    lua_pushcfunction(L, CreatelistItem_set_age);
    lua_setfield(L, -2, "age");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua