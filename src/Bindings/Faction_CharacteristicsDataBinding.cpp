#include "pch.h"
#include "Bindings/Faction_CharacteristicsDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Faction::CharacteristicsData* getInstance(lua_State* L, int idx)
{
    return checkObject<Faction::CharacteristicsData>(L, idx, Faction_CharacteristicsDataBinding::getMetatableName());
}

// --- Getters for CharacteristicsData ---
static int CharacteristicsData_get_fleeRatio_squadSize(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Faction::CharacteristicsData is nil");
    lua_pushnumber(L, inst->fleeRatio_squadSize);
    return 1;
}

static int CharacteristicsData_get_fleeRatio_relativeEnemy(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Faction::CharacteristicsData is nil");
    lua_pushnumber(L, inst->fleeRatio_relativeEnemy);
    return 1;
}

// --- Setters for CharacteristicsData ---
static int CharacteristicsData_set_fleeRatio_squadSize(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Faction::CharacteristicsData is nil");
    inst->fleeRatio_squadSize = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacteristicsData_set_fleeRatio_relativeEnemy(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Faction::CharacteristicsData is nil");
    inst->fleeRatio_relativeEnemy = (float)luaL_checknumber(L, 2);
    return 0;
}

int Faction_CharacteristicsDataBinding::gc(lua_State* L)
{
    return 0;
}

int Faction_CharacteristicsDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Faction_CharacteristicsData object");
    return 1;
}

int Faction_CharacteristicsDataBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->fleeRatio_squadSize == b->fleeRatio_squadSize && a->fleeRatio_relativeEnemy == b->fleeRatio_relativeEnemy)) ? 1 : 0);
    return 1;
}

void Faction_CharacteristicsDataBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "fleeRatio_squadSize", CharacteristicsData_get_fleeRatio_squadSize);
    registerGetter(L, "fleeRatio_relativeEnemy", CharacteristicsData_get_fleeRatio_relativeEnemy);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "fleeRatio_squadSize", CharacteristicsData_set_fleeRatio_squadSize);
    registerSetter(L, "fleeRatio_relativeEnemy", CharacteristicsData_set_fleeRatio_relativeEnemy);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
