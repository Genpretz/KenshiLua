#include "pch.h"
#include "Bindings/AppearanceManager_DataRangeBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static AppearanceManager::DataRange* getInstance(lua_State* L, int idx)
{
    return checkObject<AppearanceManager::DataRange>(L, idx, AppearanceManager_DataRangeBinding::getMetatableName());
}

// --- Methods ---
int AppearanceManager_DataRangeBinding::clamp(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRange is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    inst->clamp(data);
    return 0;
}

// --- Getters for DataRange ---
static int DataRange_get_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRange is nil");
    lua_pushlstring(L, inst->name.c_str(), inst->name.size());
    return 1;
}

static int DataRange_get_max(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRange is nil");
    lua_pushinteger(L, inst->max);
    return 1;
}

static int DataRange_get_min(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRange is nil");
    lua_pushinteger(L, inst->min);
    return 1;
}

static int DataRange_get_mid(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRange is nil");
    lua_pushinteger(L, inst->mid);
    return 1;
}

static int DataRange_get_random_group(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRange is nil");
    lua_pushinteger(L, inst->random_group);
    return 1;
}

static int DataRange_get_random_variation(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRange is nil");
    lua_pushinteger(L, inst->random_variation);
    return 1;
}

// --- Setters for DataRange ---
static int DataRange_set_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRange is nil");
    inst->name = luaL_checkstring(L, 2);
    return 0;
}

static int DataRange_set_max(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRange is nil");
    inst->max = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int DataRange_set_min(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRange is nil");
    inst->min = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int DataRange_set_mid(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRange is nil");
    inst->mid = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int DataRange_set_random_group(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRange is nil");
    inst->random_group = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int DataRange_set_random_variation(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRange is nil");
    inst->random_variation = (short)luaL_checkinteger(L, 2);
    return 0;
}

int AppearanceManager_DataRangeBinding::gc(lua_State* L)
{
    return 0;
}

int AppearanceManager_DataRangeBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AppearanceManager_DataRange object");
    return 1;
}

int AppearanceManager_DataRangeBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void AppearanceManager_DataRangeBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       AppearanceManager_DataRangeBinding::operator_eq },
        { "__gc",       AppearanceManager_DataRangeBinding::gc },
        { "__tostring", AppearanceManager_DataRangeBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "clamp",      AppearanceManager_DataRangeBinding::clamp },
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "name", DataRange_get_name);
    registerGetter(L, "max", DataRange_get_max);
    registerGetter(L, "min", DataRange_get_min);
    registerGetter(L, "mid", DataRange_get_mid);
    registerGetter(L, "random_group", DataRange_get_random_group);
    registerGetter(L, "random_variation", DataRange_get_random_variation);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "name", DataRange_set_name);
    registerSetter(L, "max", DataRange_set_max);
    registerSetter(L, "min", DataRange_set_min);
    registerSetter(L, "mid", DataRange_set_mid);
    registerSetter(L, "random_group", DataRange_set_random_group);
    registerSetter(L, "random_variation", DataRange_set_random_variation);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
