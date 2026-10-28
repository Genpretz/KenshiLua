#include "pch.h"
#include "kenshi/SharedKing.h"
#include "SharedKingBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/ZoneManagerInterfaceTBinding.h"

namespace KenshiLua
{

static_assert(offsetof(SharedKing, areasList) == 0x0, "SharedKing::areasList offset mismatch");
static_assert(offsetof(SharedKing, townList) == 0x8, "SharedKing::townList offset mismatch");
static_assert(offsetof(SharedKing, zoneMgr) == 0x10, "SharedKing::zoneMgr offset mismatch");

static SharedKing* getInstance(lua_State* L, int idx)
{
    return checkObject<SharedKing>(L, idx, SharedKingBinding::getMetatableName());
}

static int SharedKing_get_areasList(lua_State* L)
{
    SharedKing* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SharedKing is nil");
    lua_pushlightuserdata(L, (void*)instance->areasList);
    return 1;
}

static int SharedKing_get_townList(lua_State* L)
{
    SharedKing* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SharedKing is nil");
    lua_pushlightuserdata(L, (void*)instance->townList);
    return 1;
}

static int SharedKing_get_zoneMgr(lua_State* L)
{
    SharedKing* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SharedKing is nil");
    if (!instance->zoneMgr) { lua_pushnil(L); return 1; }
    return pushObject<ZoneManagerInterfaceT>(L, instance->zoneMgr, ZoneManagerInterfaceTBinding::getMetatableName());
}

static int SharedKing_set_zoneMgr(lua_State* L)
{
    SharedKing* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SharedKing is nil");
    instance->zoneMgr = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneManagerInterfaceT>(L, 2, ZoneManagerInterfaceTBinding::getMetatableName());
    return 0;
}

int SharedKingBinding::isLevelEditMode(lua_State* L)
{
    SharedKing* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SharedKing is nil");

    bool result = instance->isLevelEditMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SharedKingBinding::gc(lua_State* L)
{
    return 0;
}

int SharedKingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SharedKing object");
    return 1;
}

void SharedKingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SharedKingBinding::gc },
        { "__tostring", SharedKingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isLevelEditMode", SharedKingBinding::isLevelEditMode },
        { 0, 0 }
    };

    registerClass(
        L,
        SharedKingBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SharedKingBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "areasList", SharedKing_get_areasList);
    registerGetter(L, "townList", SharedKing_get_townList);
    registerGetter(L, "zoneMgr", SharedKing_get_zoneMgr);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "zoneMgr", SharedKing_set_zoneMgr);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
