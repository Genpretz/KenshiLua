#include "pch.h"
#include "Research_BuildingUpgradesBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(Research::BuildingUpgrades, productionMult) == 0x0, "Research::BuildingUpgrades::productionMult offset mismatch");
static_assert(offsetof(Research::BuildingUpgrades, powerBoost) == 0x4, "Research::BuildingUpgrades::powerBoost offset mismatch");
static_assert(offsetof(Research::BuildingUpgrades, powerCapacity) == 0x8, "Research::BuildingUpgrades::powerCapacity offset mismatch");

static Research::BuildingUpgrades* getInstance(lua_State* L, int idx)
{
    return checkObject<Research::BuildingUpgrades>(L, idx, Research_BuildingUpgradesBinding::getMetatableName());
}

static int BuildingUpgrades_get_productionMult(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Research::BuildingUpgrades is nil");
    lua_pushnumber(L, inst->productionMult);
    return 1;
}

static int BuildingUpgrades_set_productionMult(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Research::BuildingUpgrades is nil");
    inst->productionMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int BuildingUpgrades_get_powerBoost(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Research::BuildingUpgrades is nil");
    lua_pushnumber(L, inst->powerBoost);
    return 1;
}

static int BuildingUpgrades_set_powerBoost(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Research::BuildingUpgrades is nil");
    inst->powerBoost = (float)luaL_checknumber(L, 2);
    return 0;
}

static int BuildingUpgrades_get_powerCapacity(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Research::BuildingUpgrades is nil");
    lua_pushnumber(L, inst->powerCapacity);
    return 1;
}

static int BuildingUpgrades_set_powerCapacity(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Research::BuildingUpgrades is nil");
    inst->powerCapacity = (float)luaL_checknumber(L, 2);
    return 0;
}

int Research_BuildingUpgradesBinding::gc(lua_State* L)
{
    return 0;
}

int Research_BuildingUpgradesBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Research_BuildingUpgrades object");
    return 1;
}

int Research_BuildingUpgradesBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, a == b);
    return 1;
}

void Research_BuildingUpgradesBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       Research_BuildingUpgradesBinding::gc },
        { "__tostring", Research_BuildingUpgradesBinding::tostring },
        { "__eq",       Research_BuildingUpgradesBinding::operator_eq },
        { 0, 0 }
    };

    registerClass(
        L,
        Research_BuildingUpgradesBinding::getMetatableName(),
        meta,
        nullptr,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, Research_BuildingUpgradesBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "productionMult", BuildingUpgrades_get_productionMult);
    registerGetter(L, "powerBoost", BuildingUpgrades_get_powerBoost);
    registerGetter(L, "powerCapacity", BuildingUpgrades_get_powerCapacity);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "productionMult", BuildingUpgrades_set_productionMult);
    registerSetter(L, "powerBoost", BuildingUpgrades_set_powerBoost);
    registerSetter(L, "powerCapacity", BuildingUpgrades_set_powerCapacity);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
