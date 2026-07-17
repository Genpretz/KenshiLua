#include "pch.h"
#include "kenshi\Building\Building.h"
#include "BuildingPlacementGroundTypeBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static BuildingPlacementGroundType* getInstance(lua_State* L, int idx)
{
    return checkObject<BuildingPlacementGroundType>(L, idx, BuildingPlacementGroundTypeBinding::getMetatableName());
}

// --- Getters for BuildingPlacementGroundType ---
// --- Setters for BuildingPlacementGroundType ---


int BuildingPlacementGroundTypeBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BuildingPlacementGroundTypeBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BuildingPlacementGroundType object");
    return 1;
}

void BuildingPlacementGroundTypeBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildingPlacementGroundTypeBinding::gc },
        { "__tostring", BuildingPlacementGroundTypeBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        BuildingPlacementGroundTypeBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BuildingPlacementGroundTypeBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}
}