#include "pch.h"
#include "kenshi\PlayerInterface.h"
#include "AIOptionsBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static PlayerInterface::AIOptions* getB(lua_State* L, int idx)
{
    return checkObject<PlayerInterface::AIOptions>(L, idx, AIOptionsBinding::getMetatableName());
}

// --- Getters for AIOptions ---
static int AIOptions_get_healAllies(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, b->healAllies ? 1 : 0);
    return 1;
}

static int AIOptions_get_helpAllies(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, b->helpAllies ? 1 : 0);
    return 1;
}

static int AIOptions_get_rescueAllies(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, b->rescueAllies ? 1 : 0);
    return 1;
}

static int AIOptions_get_stayInBase(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, b->stayInBase ? 1 : 0);
    return 1;
}

static int AIOptions_get_feedAnimals(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, b->feedAnimals ? 1 : 0);
    return 1;
}

static int AIOptions_get_shareFood(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, b->shareFood ? 1 : 0);
    return 1;
}

static int AIOptions_get_autoSleep(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, b->autoSleep ? 1 : 0);
    return 1;
}

static int AIOptions_get_autoDitchItems(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, b->autoDitchItems ? 1 : 0);
    return 1;
}

static int AIOptions_get_autoSit(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, b->autoSit ? 1 : 0);
    return 1;
}

static int AIOptions_get_ejectEnemies(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, b->ejectEnemies ? 1 : 0);
    return 1;
}

static int AIOptions_get_shootFirst(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, b->shootFirst ? 1 : 0);
    return 1;
}

// --- Setters for AIOptions ---
static int AIOptions_set_healAllies(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    b->healAllies = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_helpAllies(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    b->helpAllies = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_rescueAllies(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    b->rescueAllies = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_stayInBase(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    b->stayInBase = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_feedAnimals(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    b->feedAnimals = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_shareFood(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    b->shareFood = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_autoSleep(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    b->autoSleep = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_autoDitchItems(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    b->autoDitchItems = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_autoSit(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    b->autoSit = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_ejectEnemies(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    b->ejectEnemies = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_shootFirst(lua_State* L)
{
    PlayerInterface::AIOptions* b = getB(L, 1);
    if (!b) return luaL_error(L, "AIOptions is nil");
    b->shootFirst = lua_toboolean(L, 2) != 0;
    return 0;
}

/*
Skipped methods needing manual binding:
  line 197: AIOptions* _CONSTRUCTOR(...) - unsupported return type
  line 198: void load(...) - unsupported arg type
  line 199: void save(...) - unsupported arg type
*/

int AIOptionsBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int AIOptionsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AIOptions object");
    return 1;
}

void AIOptionsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AIOptionsBinding::gc },
        { "__tostring", AIOptionsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        AIOptionsBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AIOptionsBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, AIOptions_get_healAllies);
    lua_setfield(L, -2, "healAllies");
    lua_pushcfunction(L, AIOptions_get_helpAllies);
    lua_setfield(L, -2, "helpAllies");
    lua_pushcfunction(L, AIOptions_get_rescueAllies);
    lua_setfield(L, -2, "rescueAllies");
    lua_pushcfunction(L, AIOptions_get_stayInBase);
    lua_setfield(L, -2, "stayInBase");
    lua_pushcfunction(L, AIOptions_get_feedAnimals);
    lua_setfield(L, -2, "feedAnimals");
    lua_pushcfunction(L, AIOptions_get_shareFood);
    lua_setfield(L, -2, "shareFood");
    lua_pushcfunction(L, AIOptions_get_autoSleep);
    lua_setfield(L, -2, "autoSleep");
    lua_pushcfunction(L, AIOptions_get_autoDitchItems);
    lua_setfield(L, -2, "autoDitchItems");
    lua_pushcfunction(L, AIOptions_get_autoSit);
    lua_setfield(L, -2, "autoSit");
    lua_pushcfunction(L, AIOptions_get_ejectEnemies);
    lua_setfield(L, -2, "ejectEnemies");
    lua_pushcfunction(L, AIOptions_get_shootFirst);
    lua_setfield(L, -2, "shootFirst");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, AIOptions_set_healAllies);
    lua_setfield(L, -2, "healAllies");
    lua_pushcfunction(L, AIOptions_set_helpAllies);
    lua_setfield(L, -2, "helpAllies");
    lua_pushcfunction(L, AIOptions_set_rescueAllies);
    lua_setfield(L, -2, "rescueAllies");
    lua_pushcfunction(L, AIOptions_set_stayInBase);
    lua_setfield(L, -2, "stayInBase");
    lua_pushcfunction(L, AIOptions_set_feedAnimals);
    lua_setfield(L, -2, "feedAnimals");
    lua_pushcfunction(L, AIOptions_set_shareFood);
    lua_setfield(L, -2, "shareFood");
    lua_pushcfunction(L, AIOptions_set_autoSleep);
    lua_setfield(L, -2, "autoSleep");
    lua_pushcfunction(L, AIOptions_set_autoDitchItems);
    lua_setfield(L, -2, "autoDitchItems");
    lua_pushcfunction(L, AIOptions_set_autoSit);
    lua_setfield(L, -2, "autoSit");
    lua_pushcfunction(L, AIOptions_set_ejectEnemies);
    lua_setfield(L, -2, "ejectEnemies");
    lua_pushcfunction(L, AIOptions_set_shootFirst);
    lua_setfield(L, -2, "shootFirst");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua