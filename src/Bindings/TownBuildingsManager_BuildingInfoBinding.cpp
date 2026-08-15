#include "pch.h"
#include "Bindings/TownBuildingsManager_BuildingInfoBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TownBuildingsManager::BuildingInfo* getInstance(lua_State* L, int idx)
{
    return checkObject<TownBuildingsManager::BuildingInfo>(L, idx, TownBuildingsManager_BuildingInfoBinding::getMetatableName());
}

// --- Getters for BuildingInfo ---
static int BuildingInfo_get_visibleFloor(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBuildingsManager::BuildingInfo is nil");
    lua_pushinteger(L, inst->visibleFloor);
    return 1;
}

// --- Setters for BuildingInfo ---
static int BuildingInfo_set_visibleFloor(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBuildingsManager::BuildingInfo is nil");
    inst->visibleFloor = (unsigned char)luaL_checkinteger(L, 2);
    return 0;
}

int TownBuildingsManager_BuildingInfoBinding::gc(lua_State* L)
{
    return 0;
}

int TownBuildingsManager_BuildingInfoBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TownBuildingsManager_BuildingInfo object");
    return 1;
}

int TownBuildingsManager_BuildingInfoBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->visibleFloor == b->visibleFloor)) ? 1 : 0);
    return 1;
}

void TownBuildingsManager_BuildingInfoBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "visibleFloor", BuildingInfo_get_visibleFloor);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "visibleFloor", BuildingInfo_set_visibleFloor);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
