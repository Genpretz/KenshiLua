#include "pch.h"
#include "kenshi\saveinfo.h"
#include "GameplayOptionsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static GameplayOptions* getInstance(lua_State* L, int idx)
{
    return checkObject<GameplayOptions>(L, idx, GameplayOptionsBinding::getMetatableName());
}

// --- Getters for GameplayOptions ---
static int GameplayOptions_get_deathFrequency(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    lua_pushnumber(L, instance->deathFrequency);
    return 1;
}

static int GameplayOptions_get_easyProspecting(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    lua_pushboolean(L, instance->easyProspecting ? 1 : 0);
    return 1;
}

static int GameplayOptions_get_globalDamageMultiplier(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    lua_pushnumber(L, instance->globalDamageMultiplier);
    return 1;
}

static int GameplayOptions_get_buildingSpeed(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    lua_pushnumber(L, instance->buildingSpeed);
    return 1;
}

static int GameplayOptions_get_numNestsMult(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    lua_pushnumber(L, instance->numNestsMult);
    return 1;
}

static int GameplayOptions_get_researchSpeed(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    lua_pushnumber(L, instance->researchSpeed);
    return 1;
}

static int GameplayOptions_get_productionSpeed(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    lua_pushnumber(L, instance->productionSpeed);
    return 1;
}

static int GameplayOptions_get_hungerTime(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    lua_pushnumber(L, instance->hungerTime);
    return 1;
}

static int GameplayOptions_get_banditsLootPlayer(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    lua_pushboolean(L, instance->banditsLootPlayer ? 1 : 0);
    return 1;
}

static int GameplayOptions_get_animalsEat(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    lua_pushboolean(L, instance->animalsEat ? 1 : 0);
    return 1;
}

static int GameplayOptions_get_difficultHealing(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    lua_pushboolean(L, instance->difficultHealing ? 1 : 0);
    return 1;
}

// --- Setters for GameplayOptions ---
static int GameplayOptions_set_deathFrequency(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    instance->deathFrequency = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameplayOptions_set_easyProspecting(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    instance->easyProspecting = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameplayOptions_set_globalDamageMultiplier(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    instance->globalDamageMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameplayOptions_set_buildingSpeed(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    instance->buildingSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameplayOptions_set_numNestsMult(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    instance->numNestsMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameplayOptions_set_researchSpeed(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    instance->researchSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameplayOptions_set_productionSpeed(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    instance->productionSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameplayOptions_set_hungerTime(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    instance->hungerTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameplayOptions_set_banditsLootPlayer(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    instance->banditsLootPlayer = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameplayOptions_set_animalsEat(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    instance->animalsEat = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameplayOptions_set_difficultHealing(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");
    instance->difficultHealing = lua_toboolean(L, 2) != 0;
    return 0;
}

int GameplayOptionsBinding::_CONSTRUCTOR(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");

    GameplayOptions* result = instance->_CONSTRUCTOR();
    return pushObject<GameplayOptions>(L, result, GameplayOptionsBinding::getMetatableName());
}

int GameplayOptionsBinding::reset(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");

    instance->reset();
    return 0;
}

int GameplayOptionsBinding::getStarvationTimeInHours(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");

    float result = instance->getStarvationTimeInHours();
    lua_pushnumber(L, result);
    return 1;
}

int GameplayOptionsBinding::save(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->save(data);
    return 0;
}

int GameplayOptionsBinding::load(lua_State* L)
{
    GameplayOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameplayOptions is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->load(data);
    return 0;
}

int GameplayOptionsBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GameplayOptionsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GameplayOptions object");
    return 1;
}

void GameplayOptionsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameplayOptionsBinding::gc },
        { "__tostring", GameplayOptionsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", GameplayOptionsBinding::_CONSTRUCTOR },
        { "reset", GameplayOptionsBinding::reset },
        { "getStarvationTimeInHours", GameplayOptionsBinding::getStarvationTimeInHours },
        { "save", GameplayOptionsBinding::save },
        { "load", GameplayOptionsBinding::load },
        { 0, 0 }
    };

    registerClass(
        L, 
        GameplayOptionsBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GameplayOptionsBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "deathFrequency", GameplayOptions_get_deathFrequency);
    registerGetter(L, "easyProspecting", GameplayOptions_get_easyProspecting);
    registerGetter(L, "globalDamageMultiplier", GameplayOptions_get_globalDamageMultiplier);
    registerGetter(L, "buildingSpeed", GameplayOptions_get_buildingSpeed);
    registerGetter(L, "numNestsMult", GameplayOptions_get_numNestsMult);
    registerGetter(L, "researchSpeed", GameplayOptions_get_researchSpeed);
    registerGetter(L, "productionSpeed", GameplayOptions_get_productionSpeed);
    registerGetter(L, "hungerTime", GameplayOptions_get_hungerTime);
    registerGetter(L, "banditsLootPlayer", GameplayOptions_get_banditsLootPlayer);
    registerGetter(L, "animalsEat", GameplayOptions_get_animalsEat);
    registerGetter(L, "difficultHealing", GameplayOptions_get_difficultHealing);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "deathFrequency", GameplayOptions_set_deathFrequency);
    registerSetter(L, "easyProspecting", GameplayOptions_set_easyProspecting);
    registerSetter(L, "globalDamageMultiplier", GameplayOptions_set_globalDamageMultiplier);
    registerSetter(L, "buildingSpeed", GameplayOptions_set_buildingSpeed);
    registerSetter(L, "numNestsMult", GameplayOptions_set_numNestsMult);
    registerSetter(L, "researchSpeed", GameplayOptions_set_researchSpeed);
    registerSetter(L, "productionSpeed", GameplayOptions_set_productionSpeed);
    registerSetter(L, "hungerTime", GameplayOptions_set_hungerTime);
    registerSetter(L, "banditsLootPlayer", GameplayOptions_set_banditsLootPlayer);
    registerSetter(L, "animalsEat", GameplayOptions_set_animalsEat);
    registerSetter(L, "difficultHealing", GameplayOptions_set_difficultHealing);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua