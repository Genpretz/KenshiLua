#include "pch.h"
#include "Bindings/AppearanceManager_DataRangePoseBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static AppearanceManager::DataRangePose* getInstance(lua_State* L, int idx)
{
    return checkObject<AppearanceManager::DataRangePose>(L, idx, AppearanceManager_DataRangePoseBinding::getMetatableName());
}

// --- Methods ---
int AppearanceManager_DataRangePoseBinding::clamp(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    inst->clamp(data);
    return 0;
}

// --- Getters for DataRangePose ---
static int DataRangePose_get_pose_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    lua_pushlstring(L, inst->pose_name.c_str(), inst->pose_name.size());
    return 1;
}

static int DataRangePose_get_pose_opposite_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    lua_pushlstring(L, inst->pose_opposite_name.c_str(), inst->pose_opposite_name.size());
    return 1;
}

static int DataRangePose_get_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    lua_pushlstring(L, inst->name.c_str(), inst->name.size());
    return 1;
}

static int DataRangePose_get_max(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    lua_pushinteger(L, inst->max);
    return 1;
}

static int DataRangePose_get_min(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    lua_pushinteger(L, inst->min);
    return 1;
}

static int DataRangePose_get_mid(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    lua_pushinteger(L, inst->mid);
    return 1;
}

static int DataRangePose_get_random_group(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    lua_pushinteger(L, inst->random_group);
    return 1;
}

static int DataRangePose_get_random_variation(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    lua_pushinteger(L, inst->random_variation);
    return 1;
}

// --- Setters for DataRangePose ---
static int DataRangePose_set_pose_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    inst->pose_name = luaL_checkstring(L, 2);
    return 0;
}

static int DataRangePose_set_pose_opposite_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    inst->pose_opposite_name = luaL_checkstring(L, 2);
    return 0;
}

static int DataRangePose_set_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    inst->name = luaL_checkstring(L, 2);
    return 0;
}

static int DataRangePose_set_max(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    inst->max = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int DataRangePose_set_min(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    inst->min = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int DataRangePose_set_mid(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    inst->mid = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int DataRangePose_set_random_group(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    inst->random_group = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int DataRangePose_set_random_variation(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangePose is nil");
    inst->random_variation = (short)luaL_checkinteger(L, 2);
    return 0;
}

int AppearanceManager_DataRangePoseBinding::gc(lua_State* L)
{
    return 0;
}

int AppearanceManager_DataRangePoseBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AppearanceManager_DataRangePose object");
    return 1;
}

int AppearanceManager_DataRangePoseBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void AppearanceManager_DataRangePoseBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       AppearanceManager_DataRangePoseBinding::operator_eq },
        { "__gc",       AppearanceManager_DataRangePoseBinding::gc },
        { "__tostring", AppearanceManager_DataRangePoseBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "clamp",      AppearanceManager_DataRangePoseBinding::clamp },
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "pose_name", DataRangePose_get_pose_name);
    registerGetter(L, "pose_opposite_name", DataRangePose_get_pose_opposite_name);
    registerGetter(L, "name", DataRangePose_get_name);
    registerGetter(L, "max", DataRangePose_get_max);
    registerGetter(L, "min", DataRangePose_get_min);
    registerGetter(L, "mid", DataRangePose_get_mid);
    registerGetter(L, "random_group", DataRangePose_get_random_group);
    registerGetter(L, "random_variation", DataRangePose_get_random_variation);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "pose_name", DataRangePose_set_pose_name);
    registerSetter(L, "pose_opposite_name", DataRangePose_set_pose_opposite_name);
    registerSetter(L, "name", DataRangePose_set_name);
    registerSetter(L, "max", DataRangePose_set_max);
    registerSetter(L, "min", DataRangePose_set_min);
    registerSetter(L, "mid", DataRangePose_set_mid);
    registerSetter(L, "random_group", DataRangePose_set_random_group);
    registerSetter(L, "random_variation", DataRangePose_set_random_variation);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
