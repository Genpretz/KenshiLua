#include "pch.h"
#include "Bindings/FarmBuilding_SubPlantBinding.h"
#include "Bindings/FarmBuilding_PlantSourceBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/Building/FarmBuilding.h>

namespace KenshiLua
{

static FarmBuilding::SubPlant* getInstance(lua_State* L, int idx)
{
    return checkObject<FarmBuilding::SubPlant>(L, idx, FarmBuilding_SubPlantBinding::getMetatableName());
}

static int SubPlant_get_scale(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::SubPlant is nil");
    lua_pushnumber(L, inst->scale);
    return 1;
}

static int SubPlant_get_offset(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::SubPlant is nil");
    lua_pushnumber(L, inst->offset);
    return 1;
}

static int SubPlant_get_rv(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::SubPlant is nil");
    lua_pushnumber(L, inst->rv);
    return 1;
}

static int SubPlant_get_data(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::SubPlant is nil");
    return pushObject<FarmBuilding::PlantSource>(L, inst->data, FarmBuilding_PlantSourceBinding::getMetatableName());
}

static int SubPlant_get_index(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::SubPlant is nil");
    lua_pushinteger(L, inst->index);
    return 1;
}

static int SubPlant_set_scale(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::SubPlant is nil");
    inst->scale = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SubPlant_set_offset(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::SubPlant is nil");
    inst->offset = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SubPlant_set_rv(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::SubPlant is nil");
    inst->rv = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SubPlant_set_data(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::SubPlant is nil");
    inst->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<FarmBuilding::PlantSource>(L, 2, FarmBuilding_PlantSourceBinding::getMetatableName());
    return 0;
}

static int SubPlant_set_index(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::SubPlant is nil");
    inst->index = (int)luaL_checkinteger(L, 2);
    return 0;
}

int FarmBuilding_SubPlantBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (FarmBuilding::SubPlant*)::operator new(sizeof(FarmBuilding::SubPlant));
    ::new ((void*)obj) FarmBuilding::SubPlant();
    return pushObject<FarmBuilding::SubPlant>(L, obj, getMetatableName());
}

int FarmBuilding_SubPlantBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::SubPlant is nil");
    inst->~SubPlant();
    return 0;
}

int FarmBuilding_SubPlantBinding::gc(lua_State* L)
{
    return 0;
}

int FarmBuilding_SubPlantBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FarmBuilding_SubPlant object");
    return 1;
}

int FarmBuilding_SubPlantBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void FarmBuilding_SubPlantBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", _CONSTRUCTOR },
        { "_DESTRUCTOR",  _DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "scale", SubPlant_get_scale);
    registerGetter(L, "offset", SubPlant_get_offset);
    registerGetter(L, "rv", SubPlant_get_rv);
    registerGetter(L, "data", SubPlant_get_data);
    registerGetter(L, "index", SubPlant_get_index);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "scale", SubPlant_set_scale);
    registerSetter(L, "offset", SubPlant_set_offset);
    registerSetter(L, "rv", SubPlant_set_rv);
    registerSetter(L, "data", SubPlant_set_data);
    registerSetter(L, "index", SubPlant_set_index);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
