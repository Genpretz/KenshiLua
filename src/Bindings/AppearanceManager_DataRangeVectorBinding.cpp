#include "pch.h"
#include "Bindings/AppearanceManager_DataRangeVectorBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static AppearanceManager::DataRangeVector* getInstance(lua_State* L, int idx)
{
    return checkObject<AppearanceManager::DataRangeVector>(L, idx, AppearanceManager_DataRangeVectorBinding::getMetatableName());
}

// --- Methods ---
int AppearanceManager_DataRangeVectorBinding::addValue(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    Ogre::Vector3 value;
    readVector3(L, 2, value);
    inst->addValue(value);
    return 0;
}

int AppearanceManager_DataRangeVectorBinding::getValue(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    int valueIndex = (int)luaL_checkinteger(L, 2);
    Ogre::Vector3 result = inst->getValue(valueIndex);
    pushVector3(L, result);
    return 1;
}

int AppearanceManager_DataRangeVectorBinding::getValueIndex(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    Ogre::Vector3 value;
    readVector3(L, 2, value);
    int result = inst->getValueIndex(value);
    lua_pushinteger(L, result);
    return 1;
}

int AppearanceManager_DataRangeVectorBinding::size(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    int result = inst->size();
    lua_pushinteger(L, result);
    return 1;
}

int AppearanceManager_DataRangeVectorBinding::clamp(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    inst->clamp(data);
    return 0;
}

// --- Getters for DataRangeVector ---
static int DataRangeVector_get_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    lua_pushlstring(L, inst->name.c_str(), inst->name.size());
    return 1;
}

static int DataRangeVector_get_max(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    lua_pushinteger(L, inst->max);
    return 1;
}

static int DataRangeVector_get_min(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    lua_pushinteger(L, inst->min);
    return 1;
}

static int DataRangeVector_get_mid(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    lua_pushinteger(L, inst->mid);
    return 1;
}

static int DataRangeVector_get_random_group(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    lua_pushinteger(L, inst->random_group);
    return 1;
}

static int DataRangeVector_get_random_variation(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    lua_pushinteger(L, inst->random_variation);
    return 1;
}

// --- Setters for DataRangeVector ---
static int DataRangeVector_set_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    inst->name = luaL_checkstring(L, 2);
    return 0;
}

static int DataRangeVector_set_max(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    inst->max = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int DataRangeVector_set_min(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    inst->min = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int DataRangeVector_set_mid(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    inst->mid = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int DataRangeVector_set_random_group(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    inst->random_group = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int DataRangeVector_set_random_variation(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataRangeVector is nil");
    inst->random_variation = (short)luaL_checkinteger(L, 2);
    return 0;
}

/*
Skipped properties needing manual binding:
  line 68: values (Ogre::FastArray<Ogre::Vector3>) - accessed via addValue/getValue/getValueIndex/size
*/

int AppearanceManager_DataRangeVectorBinding::gc(lua_State* L)
{
    return 0;
}

int AppearanceManager_DataRangeVectorBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AppearanceManager_DataRangeVector object");
    return 1;
}

int AppearanceManager_DataRangeVectorBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void AppearanceManager_DataRangeVectorBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       AppearanceManager_DataRangeVectorBinding::operator_eq },
        { "__gc",       AppearanceManager_DataRangeVectorBinding::gc },
        { "__tostring", AppearanceManager_DataRangeVectorBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "addValue",       AppearanceManager_DataRangeVectorBinding::addValue },
        { "getValue",       AppearanceManager_DataRangeVectorBinding::getValue },
        { "getValueIndex",  AppearanceManager_DataRangeVectorBinding::getValueIndex },
        { "size",           AppearanceManager_DataRangeVectorBinding::size },
        { "clamp",          AppearanceManager_DataRangeVectorBinding::clamp },
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "name", DataRangeVector_get_name);
    registerGetter(L, "max", DataRangeVector_get_max);
    registerGetter(L, "min", DataRangeVector_get_min);
    registerGetter(L, "mid", DataRangeVector_get_mid);
    registerGetter(L, "random_group", DataRangeVector_get_random_group);
    registerGetter(L, "random_variation", DataRangeVector_get_random_variation);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "name", DataRangeVector_set_name);
    registerSetter(L, "max", DataRangeVector_set_max);
    registerSetter(L, "min", DataRangeVector_set_min);
    registerSetter(L, "mid", DataRangeVector_set_mid);
    registerSetter(L, "random_group", DataRangeVector_set_random_group);
    registerSetter(L, "random_variation", DataRangeVector_set_random_variation);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
