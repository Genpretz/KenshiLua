#include "pch.h"
#include "Bindings/ZoneManager_BiomeGroundEffectsBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/ZoneManager.h>

namespace KenshiLua
{

static ZoneManager::BiomeGroundEffects* getInstance(lua_State* L, int idx)
{
    return checkObject<ZoneManager::BiomeGroundEffects>(L, idx, ZoneManager_BiomeGroundEffectsBinding::getMetatableName());
}

// --- Getters for BiomeGroundEffects ---
static int BiomeGroundEffects_get_effectDatas(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneManager::BiomeGroundEffects is nil");
    
    if (lua_gettop(L) >= 2 && lua_isnumber(L, 2))
    {
        int idx = (int)luaL_checkinteger(L, 2);
        if (idx >= 1 && idx <= 5) idx -= 1;
        if (idx < 0 || idx >= 5) return luaL_error(L, "Index out of bounds (1-5)");
        return pushObject<GameData>(L, inst->effectDatas[idx], GameDataBinding::getMetatableName());
    }

    lua_newtable(L);
    for (int i = 0; i < 5; ++i)
    {
        pushObject<GameData>(L, inst->effectDatas[i], GameDataBinding::getMetatableName());
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int BiomeGroundEffects_get_minSpeeds(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneManager::BiomeGroundEffects is nil");

    if (lua_gettop(L) >= 2 && lua_isnumber(L, 2))
    {
        int idx = (int)luaL_checkinteger(L, 2);
        if (idx >= 1 && idx <= 5) idx -= 1;
        if (idx < 0 || idx >= 5) return luaL_error(L, "Index out of bounds (1-5)");
        lua_pushnumber(L, inst->minSpeeds[idx]);
        return 1;
    }

    lua_newtable(L);
    for (int i = 0; i < 5; ++i)
    {
        lua_pushnumber(L, inst->minSpeeds[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int BiomeGroundEffects_get_probabilities(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneManager::BiomeGroundEffects is nil");

    if (lua_gettop(L) >= 2 && lua_isnumber(L, 2))
    {
        int idx = (int)luaL_checkinteger(L, 2);
        if (idx >= 1 && idx <= 5) idx -= 1;
        if (idx < 0 || idx >= 5) return luaL_error(L, "Index out of bounds (1-5)");
        lua_pushnumber(L, inst->probabilities[idx]);
        return 1;
    }

    lua_newtable(L);
    for (int i = 0; i < 5; ++i)
    {
        lua_pushnumber(L, inst->probabilities[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

// --- Setters for BiomeGroundEffects ---
static int BiomeGroundEffects_set_effectDatas(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneManager::BiomeGroundEffects is nil");

    if (lua_gettop(L) >= 3 && lua_isnumber(L, 2))
    {
        int idx = (int)luaL_checkinteger(L, 2);
        if (idx >= 1 && idx <= 5) idx -= 1;
        if (idx < 0 || idx >= 5) return luaL_error(L, "Index out of bounds (1-5)");
        inst->effectDatas[idx] = lua_isnoneornil(L, 3) ? nullptr : checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
        return 0;
    }

    if (lua_istable(L, 2))
    {
        for (int i = 0; i < 5; ++i)
        {
            lua_rawgeti(L, 2, i + 1);
            inst->effectDatas[i] = lua_isnoneornil(L, -1) ? nullptr : checkObject<GameData>(L, -1, GameDataBinding::getMetatableName());
            lua_pop(L, 1);
        }
        return 0;
    }

    return luaL_error(L, "Expected table of GameData or index and GameData value");
}

static int BiomeGroundEffects_set_minSpeeds(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneManager::BiomeGroundEffects is nil");

    if (lua_gettop(L) >= 3 && lua_isnumber(L, 2))
    {
        int idx = (int)luaL_checkinteger(L, 2);
        if (idx >= 1 && idx <= 5) idx -= 1;
        if (idx < 0 || idx >= 5) return luaL_error(L, "Index out of bounds (1-5)");
        inst->minSpeeds[idx] = (float)luaL_checknumber(L, 3);
        return 0;
    }

    if (lua_istable(L, 2))
    {
        for (int i = 0; i < 5; ++i)
        {
            lua_rawgeti(L, 2, i + 1);
            if (lua_isnumber(L, -1)) inst->minSpeeds[i] = (float)lua_tonumber(L, -1);
            lua_pop(L, 1);
        }
        return 0;
    }

    return luaL_error(L, "Expected table of numbers or index and number value");
}

static int BiomeGroundEffects_set_probabilities(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneManager::BiomeGroundEffects is nil");

    if (lua_gettop(L) >= 3 && lua_isnumber(L, 2))
    {
        int idx = (int)luaL_checkinteger(L, 2);
        if (idx >= 1 && idx <= 5) idx -= 1;
        if (idx < 0 || idx >= 5) return luaL_error(L, "Index out of bounds (1-5)");
        inst->probabilities[idx] = (float)luaL_checknumber(L, 3);
        return 0;
    }

    if (lua_istable(L, 2))
    {
        for (int i = 0; i < 5; ++i)
        {
            lua_rawgeti(L, 2, i + 1);
            if (lua_isnumber(L, -1)) inst->probabilities[i] = (float)lua_tonumber(L, -1);
            lua_pop(L, 1);
        }
        return 0;
    }

    return luaL_error(L, "Expected table of numbers or index and number value");
}

int ZoneManager_BiomeGroundEffectsBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (ZoneManager::BiomeGroundEffects*)::operator new(sizeof(ZoneManager::BiomeGroundEffects));
    ::new ((void*)obj) ZoneManager::BiomeGroundEffects();
    return pushObject<ZoneManager::BiomeGroundEffects>(L, obj, getMetatableName());
}

int ZoneManager_BiomeGroundEffectsBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneManager::BiomeGroundEffects is nil");
    inst->~BiomeGroundEffects();
    return 0;
}

int ZoneManager_BiomeGroundEffectsBinding::gc(lua_State* L)
{
    return 0;
}

int ZoneManager_BiomeGroundEffectsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ZoneManager_BiomeGroundEffects object");
    return 1;
}

int ZoneManager_BiomeGroundEffectsBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void ZoneManager_BiomeGroundEffectsBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "effectDatas", BiomeGroundEffects_get_effectDatas);
    registerGetter(L, "minSpeeds", BiomeGroundEffects_get_minSpeeds);
    registerGetter(L, "probabilities", BiomeGroundEffects_get_probabilities);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "effectDatas", BiomeGroundEffects_set_effectDatas);
    registerSetter(L, "minSpeeds", BiomeGroundEffects_set_minSpeeds);
    registerSetter(L, "probabilities", BiomeGroundEffects_set_probabilities);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
