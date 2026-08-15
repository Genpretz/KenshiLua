#include "pch.h"
#include "Bindings/SaveInfoBinding.h"
#include "Lua/BindingHelpers.h"

#include "Bindings/GameplayOptionsBinding.h"

namespace KenshiLua
{

static SaveInfo* getInstance(lua_State* L, int idx)
{
    return checkObject<SaveInfo>(L, idx, SaveInfoBinding::getMetatableName());
}

// --- Getters for SaveInfo ---
static int SaveInfo_get_version(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    lua_pushstring(L, inst->version.c_str());

    return 1;
}

static int SaveInfo_get_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    lua_pushstring(L, inst->name.c_str());

    return 1;
}

static int SaveInfo_get_area(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    lua_pushstring(L, inst->area.c_str());

    return 1;
}

static int SaveInfo_get_time(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    lua_pushnumber(L, (lua_Number)inst->time);

    return 1;
}

static int SaveInfo_get_faction(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    lua_pushstring(L, inst->faction.c_str());

    return 1;
}

static int SaveInfo_get_money(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    lua_pushinteger(L, inst->money);
    return 1;
}

static int SaveInfo_get_size(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    lua_pushinteger(L, inst->size);
    return 1;
}

static int SaveInfo_get_days(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    lua_pushinteger(L, inst->days);
    return 1;
}

static int SaveInfo_get_location(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    lua_pushstring(L, inst->location.c_str());

    return 1;
}

static int SaveInfo_get_advanced(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    return pushObject<GameplayOptions>(L, &inst->advanced, GameplayOptionsBinding::getMetatableName());
}

// --- Setters for SaveInfo ---
static int SaveInfo_set_version(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    inst->version = luaL_checkstring(L, 2);
    return 0;
}

static int SaveInfo_set_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    inst->name = luaL_checkstring(L, 2);
    return 0;
}

static int SaveInfo_set_area(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    inst->area = luaL_checkstring(L, 2);
    return 0;
}

static int SaveInfo_set_time(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    inst->time = (__int64)luaL_checknumber(L, 2);
    return 0;
}

static int SaveInfo_set_faction(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    inst->faction = luaL_checkstring(L, 2);
    return 0;
}

static int SaveInfo_set_money(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    inst->money = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SaveInfo_set_size(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    inst->size = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SaveInfo_set_days(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    inst->days = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SaveInfo_set_location(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    inst->location = luaL_checkstring(L, 2);
    return 0;
}

static int SaveInfo_set_advanced(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveInfo is nil");
    GameplayOptions* val = checkObject<GameplayOptions>(L, 2, GameplayOptionsBinding::getMetatableName());

    if (val) inst->advanced = *val;
    return 0;
}

int SaveInfoBinding::gc(lua_State* L)
{
    return 0;
}

int SaveInfoBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SaveInfo object");
    return 1;
}

int SaveInfoBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->version == b->version && a->name == b->name && a->area == b->area && a->time == b->time && a->faction == b->faction && a->money == b->money && a->size == b->size && a->days == b->days && a->location == b->location && &a->advanced == &b->advanced)) ? 1 : 0);
    return 1;
}

void SaveInfoBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "version", SaveInfo_get_version);
    registerGetter(L, "name", SaveInfo_get_name);
    registerGetter(L, "area", SaveInfo_get_area);
    registerGetter(L, "time", SaveInfo_get_time);
    registerGetter(L, "faction", SaveInfo_get_faction);
    registerGetter(L, "money", SaveInfo_get_money);
    registerGetter(L, "size", SaveInfo_get_size);
    registerGetter(L, "days", SaveInfo_get_days);
    registerGetter(L, "location", SaveInfo_get_location);
    registerGetter(L, "advanced", SaveInfo_get_advanced);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "version", SaveInfo_set_version);
    registerSetter(L, "name", SaveInfo_set_name);
    registerSetter(L, "area", SaveInfo_set_area);
    registerSetter(L, "time", SaveInfo_set_time);
    registerSetter(L, "faction", SaveInfo_set_faction);
    registerSetter(L, "money", SaveInfo_set_money);
    registerSetter(L, "size", SaveInfo_set_size);
    registerSetter(L, "days", SaveInfo_set_days);
    registerSetter(L, "location", SaveInfo_set_location);
    registerSetter(L, "advanced", SaveInfo_set_advanced);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
