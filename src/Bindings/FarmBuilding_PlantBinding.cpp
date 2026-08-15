#include "pch.h"
#include "Bindings/FarmBuilding_PlantBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/LektorBinding.h"
#include <kenshi/Building/FarmBuilding.h>

namespace KenshiLua
{

static FarmBuilding::Plant* getInstance(lua_State* L, int idx)
{
    return checkObject<FarmBuilding::Plant>(L, idx, FarmBuilding_PlantBinding::getMetatableName());
}

static int Plant_get_age(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::Plant is nil");
    lua_pushnumber(L, inst->age);
    return 1;
}

static int Plant_get_position(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::Plant is nil");
    pushVector3(L, inst->position);
    return 1;
}

static int Plant_get_parts(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::Plant is nil");
    return pushObject<lektor<FarmBuilding::SubPlant>>(L, &inst->parts, "lektor<FarmBuilding::SubPlant>");
}

static int Plant_set_age(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::Plant is nil");
    inst->age = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Plant_set_position(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::Plant is nil");
    readVector3(L, 2, inst->position);
    return 0;
}

static int Plant_set_parts(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::Plant is nil");
    lektor<FarmBuilding::SubPlant>* val = checkObject<lektor<FarmBuilding::SubPlant>>(L, 2, "lektor<FarmBuilding::SubPlant>");
    if (val) inst->parts = *val;
    return 0;
}

int FarmBuilding_PlantBinding::gc(lua_State* L)
{
    return 0;
}

int FarmBuilding_PlantBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FarmBuilding_Plant object");
    return 1;
}

int FarmBuilding_PlantBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void FarmBuilding_PlantBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "age", Plant_get_age);
    registerGetter(L, "position", Plant_get_position);
    registerGetter(L, "parts", Plant_get_parts);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "age", Plant_set_age);
    registerSetter(L, "position", Plant_set_position);
    registerSetter(L, "parts", Plant_set_parts);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
