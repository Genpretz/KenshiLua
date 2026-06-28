#include "pch.h"
#include "kenshi\WorldEventStateQuery.h"
#include "WorldEventStateQueryBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static WorldEventStateQuery* getB(lua_State* L, int idx)
{
    return checkObject<WorldEventStateQuery>(L, idx, WorldEventStateQueryBinding::getMetatableName());
}

// --- Getters for WorldEventStateQuery ---
static int WorldEventStateQuery_get_uniqueNPCsAre(lua_State* L)
{
    WorldEventStateQuery* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQuery is nil");
    // TODO: Unsupported type for uniqueNPCsAre (ogre_unordered_map<GameData*, WorldStateEnum>::type)
    return luaL_error(L, "Unsupported property 'uniqueNPCsAre' (type: ogre_unordered_map<GameData*, WorldStateEnum>::type)");
}

static int WorldEventStateQuery_get_uniqueNPCsAreNot(lua_State* L)
{
    WorldEventStateQuery* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQuery is nil");
    // TODO: Unsupported type for uniqueNPCsAreNot (ogre_unordered_map<GameData*, WorldStateEnum>::type)
    return luaL_error(L, "Unsupported property 'uniqueNPCsAreNot' (type: ogre_unordered_map<GameData*, WorldStateEnum>::type)");
}

static int WorldEventStateQuery_get_towns(lua_State* L)
{
    WorldEventStateQuery* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQuery is nil");
    // TODO: Unsupported type for towns (ogre_unordered_map<GameData*, WorldStateEnum>::type)
    return luaL_error(L, "Unsupported property 'towns' (type: ogre_unordered_map<GameData*, WorldStateEnum>::type)");
}

static int WorldEventStateQuery_get_isAllyOf(lua_State* L)
{
    WorldEventStateQuery* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQuery is nil");
    // TODO: Unsupported type for isAllyOf (ogre_unordered_map<Faction*, bool>::type)
    return luaL_error(L, "Unsupported property 'isAllyOf' (type: ogre_unordered_map<Faction*, bool>::type)");
}

static int WorldEventStateQuery_get_isEnemyOf(lua_State* L)
{
    WorldEventStateQuery* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQuery is nil");
    // TODO: Unsupported type for isEnemyOf (ogre_unordered_map<Faction*, bool>::type)
    return luaL_error(L, "Unsupported property 'isEnemyOf' (type: ogre_unordered_map<Faction*, bool>::type)");
}

static int WorldEventStateQuery_get_playerInvolvement(lua_State* L)
{
    WorldEventStateQuery* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQuery is nil");
    lua_pushboolean(L, b->playerInvolvement ? 1 : 0);
    return 1;
}

// --- Setters for WorldEventStateQuery ---
static int WorldEventStateQuery_set_uniqueNPCsAre(lua_State* L)
{
    WorldEventStateQuery* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQuery is nil");
    return luaL_error(L, "Read-only or unsupported setter type for uniqueNPCsAre");
}

static int WorldEventStateQuery_set_uniqueNPCsAreNot(lua_State* L)
{
    WorldEventStateQuery* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQuery is nil");
    return luaL_error(L, "Read-only or unsupported setter type for uniqueNPCsAreNot");
}

static int WorldEventStateQuery_set_towns(lua_State* L)
{
    WorldEventStateQuery* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQuery is nil");
    return luaL_error(L, "Read-only or unsupported setter type for towns");
}

static int WorldEventStateQuery_set_isAllyOf(lua_State* L)
{
    WorldEventStateQuery* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQuery is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isAllyOf");
}

static int WorldEventStateQuery_set_isEnemyOf(lua_State* L)
{
    WorldEventStateQuery* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQuery is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isEnemyOf");
}

static int WorldEventStateQuery_set_playerInvolvement(lua_State* L)
{
    WorldEventStateQuery* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQuery is nil");
    b->playerInvolvement = lua_toboolean(L, 2) != 0;
    return 0;
}

int WorldEventStateQueryBinding::isTrue(lua_State* L)
{
    WorldEventStateQuery* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQuery is nil");

    bool result = b->isTrue();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 29: WorldEventStateQuery* _CONSTRUCTOR(...) - unsupported return type
  line 36: WorldEventStateQuery* getFromData(...) - static method
  line 37: bool checkAllStatesInObject(...) - static method
*/

int WorldEventStateQueryBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int WorldEventStateQueryBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.WorldEventStateQuery object");
    return 1;
}

void WorldEventStateQueryBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WorldEventStateQueryBinding::gc },
        { "__tostring", WorldEventStateQueryBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isTrue", WorldEventStateQueryBinding::isTrue },
        { 0, 0 }
    };

    registerClass(
        L, 
        WorldEventStateQueryBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, WorldEventStateQueryBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, WorldEventStateQuery_get_uniqueNPCsAre);
    lua_setfield(L, -2, "uniqueNPCsAre");
    lua_pushcfunction(L, WorldEventStateQuery_get_uniqueNPCsAreNot);
    lua_setfield(L, -2, "uniqueNPCsAreNot");
    lua_pushcfunction(L, WorldEventStateQuery_get_towns);
    lua_setfield(L, -2, "towns");
    lua_pushcfunction(L, WorldEventStateQuery_get_isAllyOf);
    lua_setfield(L, -2, "isAllyOf");
    lua_pushcfunction(L, WorldEventStateQuery_get_isEnemyOf);
    lua_setfield(L, -2, "isEnemyOf");
    lua_pushcfunction(L, WorldEventStateQuery_get_playerInvolvement);
    lua_setfield(L, -2, "playerInvolvement");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, WorldEventStateQuery_set_uniqueNPCsAre);
    lua_setfield(L, -2, "uniqueNPCsAre");
    lua_pushcfunction(L, WorldEventStateQuery_set_uniqueNPCsAreNot);
    lua_setfield(L, -2, "uniqueNPCsAreNot");
    lua_pushcfunction(L, WorldEventStateQuery_set_towns);
    lua_setfield(L, -2, "towns");
    lua_pushcfunction(L, WorldEventStateQuery_set_isAllyOf);
    lua_setfield(L, -2, "isAllyOf");
    lua_pushcfunction(L, WorldEventStateQuery_set_isEnemyOf);
    lua_setfield(L, -2, "isEnemyOf");
    lua_pushcfunction(L, WorldEventStateQuery_set_playerInvolvement);
    lua_setfield(L, -2, "playerInvolvement");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua