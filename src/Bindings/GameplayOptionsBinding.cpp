#include "pch.h"
#include <kenshi/GameplayOptions.h>
#include "GameplayOptionsBinding.h"
#include "Lua/BindingHelpers.h"

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

/*
Skipped methods needing manual binding:
  line 25: void save(...) - unsupported arg type
  line 26: void load(...) - unsupported arg type
*/

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
    lua_pushcfunction(L, GameplayOptions_get_deathFrequency);
    lua_setfield(L, -2, "deathFrequency");
    lua_pushcfunction(L, GameplayOptions_get_easyProspecting);
    lua_setfield(L, -2, "easyProspecting");
    lua_pushcfunction(L, GameplayOptions_get_globalDamageMultiplier);
    lua_setfield(L, -2, "globalDamageMultiplier");
    lua_pushcfunction(L, GameplayOptions_get_buildingSpeed);
    lua_setfield(L, -2, "buildingSpeed");
    lua_pushcfunction(L, GameplayOptions_get_numNestsMult);
    lua_setfield(L, -2, "numNestsMult");
    lua_pushcfunction(L, GameplayOptions_get_researchSpeed);
    lua_setfield(L, -2, "researchSpeed");
    lua_pushcfunction(L, GameplayOptions_get_productionSpeed);
    lua_setfield(L, -2, "productionSpeed");
    lua_pushcfunction(L, GameplayOptions_get_hungerTime);
    lua_setfield(L, -2, "hungerTime");
    lua_pushcfunction(L, GameplayOptions_get_banditsLootPlayer);
    lua_setfield(L, -2, "banditsLootPlayer");
    lua_pushcfunction(L, GameplayOptions_get_animalsEat);
    lua_setfield(L, -2, "animalsEat");
    lua_pushcfunction(L, GameplayOptions_get_difficultHealing);
    lua_setfield(L, -2, "difficultHealing");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, GameplayOptions_set_deathFrequency);
    lua_setfield(L, -2, "deathFrequency");
    lua_pushcfunction(L, GameplayOptions_set_easyProspecting);
    lua_setfield(L, -2, "easyProspecting");
    lua_pushcfunction(L, GameplayOptions_set_globalDamageMultiplier);
    lua_setfield(L, -2, "globalDamageMultiplier");
    lua_pushcfunction(L, GameplayOptions_set_buildingSpeed);
    lua_setfield(L, -2, "buildingSpeed");
    lua_pushcfunction(L, GameplayOptions_set_numNestsMult);
    lua_setfield(L, -2, "numNestsMult");
    lua_pushcfunction(L, GameplayOptions_set_researchSpeed);
    lua_setfield(L, -2, "researchSpeed");
    lua_pushcfunction(L, GameplayOptions_set_productionSpeed);
    lua_setfield(L, -2, "productionSpeed");
    lua_pushcfunction(L, GameplayOptions_set_hungerTime);
    lua_setfield(L, -2, "hungerTime");
    lua_pushcfunction(L, GameplayOptions_set_banditsLootPlayer);
    lua_setfield(L, -2, "banditsLootPlayer");
    lua_pushcfunction(L, GameplayOptions_set_animalsEat);
    lua_setfield(L, -2, "animalsEat");
    lua_pushcfunction(L, GameplayOptions_set_difficultHealing);
    lua_setfield(L, -2, "difficultHealing");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
