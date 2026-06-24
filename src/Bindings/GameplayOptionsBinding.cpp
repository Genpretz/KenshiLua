#include "pch.h"
#include "kenshi\GameplayOptions.h"
#include "GameplayOptionsBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static GameplayOptions* getB(lua_State* L, int idx)
{
    return checkObject<GameplayOptions>(L, idx, GameplayOptionsBinding::getMetatableName());
}

// --- Getters for GameplayOptions ---
static int GameplayOptions_get_deathFrequency(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    lua_pushnumber(L, b->deathFrequency);
    return 1;
}

static int GameplayOptions_get_easyProspecting(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    lua_pushboolean(L, b->easyProspecting ? 1 : 0);
    return 1;
}

static int GameplayOptions_get_globalDamageMultiplier(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    lua_pushnumber(L, b->globalDamageMultiplier);
    return 1;
}

static int GameplayOptions_get_buildingSpeed(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    lua_pushnumber(L, b->buildingSpeed);
    return 1;
}

static int GameplayOptions_get_numNestsMult(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    lua_pushnumber(L, b->numNestsMult);
    return 1;
}

static int GameplayOptions_get_researchSpeed(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    lua_pushnumber(L, b->researchSpeed);
    return 1;
}

static int GameplayOptions_get_productionSpeed(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    lua_pushnumber(L, b->productionSpeed);
    return 1;
}

static int GameplayOptions_get_hungerTime(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    lua_pushnumber(L, b->hungerTime);
    return 1;
}

static int GameplayOptions_get_banditsLootPlayer(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    lua_pushboolean(L, b->banditsLootPlayer ? 1 : 0);
    return 1;
}

static int GameplayOptions_get_animalsEat(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    lua_pushboolean(L, b->animalsEat ? 1 : 0);
    return 1;
}

static int GameplayOptions_get_difficultHealing(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    lua_pushboolean(L, b->difficultHealing ? 1 : 0);
    return 1;
}

// --- Setters for GameplayOptions ---
static int GameplayOptions_set_deathFrequency(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    b->deathFrequency = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameplayOptions_set_easyProspecting(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    b->easyProspecting = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameplayOptions_set_globalDamageMultiplier(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    b->globalDamageMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameplayOptions_set_buildingSpeed(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    b->buildingSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameplayOptions_set_numNestsMult(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    b->numNestsMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameplayOptions_set_researchSpeed(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    b->researchSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameplayOptions_set_productionSpeed(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    b->productionSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameplayOptions_set_hungerTime(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    b->hungerTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GameplayOptions_set_banditsLootPlayer(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    b->banditsLootPlayer = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameplayOptions_set_animalsEat(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    b->animalsEat = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameplayOptions_set_difficultHealing(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");
    b->difficultHealing = lua_toboolean(L, 2) != 0;
    return 0;
}

int GameplayOptionsBinding::reset(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");

    b->reset();
    return 0;
}

int GameplayOptionsBinding::getStarvationTimeInHours(lua_State* L)
{
    GameplayOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameplayOptions is nil");

    float result = b->getStarvationTimeInHours();
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 9: GameplayOptions* _CONSTRUCTOR(...) - unsupported return type
  line 23: void save(...) - unsupported arg type
  line 24: void load(...) - unsupported arg type
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