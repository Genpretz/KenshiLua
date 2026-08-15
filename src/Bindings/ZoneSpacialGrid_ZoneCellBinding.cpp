#include "pch.h"
#include "Bindings/ZoneSpacialGrid_ZoneCellBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/ZoneManager.h>

#include "Bindings/ZoneMapBinding.h"

namespace KenshiLua
{

static ZoneSpacialGrid::ZoneCell* getInstance(lua_State* L, int idx)
{
    return checkObject<ZoneSpacialGrid::ZoneCell>(L, idx, ZoneSpacialGrid_ZoneCellBinding::getMetatableName());
}

// --- Getters for ZoneCell ---
static int ZoneCell_get_zone(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSpacialGrid::ZoneCell is nil");
    return pushObject<ZoneMap>(L, inst->zone, ZoneMapBinding::getMetatableName());
}

static int ZoneCell_get_cells(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSpacialGrid::ZoneCell is nil");
    if (inst->cells) {

        lua_pushlightuserdata(L, (void*)inst->cells);

    } else {

        lua_pushnil(L);

    }

    return 1;
}

// --- Setters for ZoneCell ---
static int ZoneCell_set_zone(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSpacialGrid::ZoneCell is nil");
    inst->zone = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    return 0;
}

static int ZoneCell_set_cells(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSpacialGrid::ZoneCell is nil");
    inst->cells = (SpacialCell**)lua_touserdata(L, 2);
    return 0;
}

int ZoneSpacialGrid_ZoneCellBinding::gc(lua_State* L)
{
    return 0;
}

int ZoneSpacialGrid_ZoneCellBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ZoneSpacialGrid_ZoneCell object");
    return 1;
}

int ZoneSpacialGrid_ZoneCellBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->zone == b->zone && a->cells == b->cells)) ? 1 : 0);
    return 1;
}

void ZoneSpacialGrid_ZoneCellBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "zone", ZoneCell_get_zone);
    registerGetter(L, "cells", ZoneCell_get_cells);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "zone", ZoneCell_set_zone);
    registerSetter(L, "cells", ZoneCell_set_cells);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
