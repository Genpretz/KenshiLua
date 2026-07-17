#include "pch.h"
#include <kenshi/FactionLeader.h>
#include "FactionLeaderBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/FactionBinding.h"

namespace KenshiLua
{

static FactionLeader* getInstance(lua_State* L, int idx)
{
    return checkObject<FactionLeader>(L, idx, FactionLeaderBinding::getMetatableName());
}

// --- Getters for FactionLeader ---
static int FactionLeader_get_faction(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");
    return pushObject<Faction>(L, instance->faction, FactionBinding::getMetatableName());
}

static int FactionLeader_get_biomeTerritory(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");
    // TODO: Unsupported type for biomeTerritory (lektor<GameData*>)
    return luaL_error(L, "Unsupported property 'biomeTerritory' (type: lektor<GameData*>)");
}

static int FactionLeader_get_worstEnemy(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");
    return pushObject<Faction>(L, instance->worstEnemy, FactionBinding::getMetatableName());
}

// --- Setters for FactionLeader ---
static int FactionLeader_set_faction(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");
    return luaL_error(L, "Read-only or unsupported setter type for faction");
}

static int FactionLeader_set_biomeTerritory(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");
    return luaL_error(L, "Read-only or unsupported setter type for biomeTerritory");
}

static int FactionLeader_set_worstEnemy(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");
    return luaL_error(L, "Read-only or unsupported setter type for worstEnemy");
}

int FactionLeaderBinding::_DESTRUCTOR(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 16: FactionLeader* _CONSTRUCTOR(...) - unsupported arg type
  line 17: void setNewLeader(...) - unsupported arg type
  line 18: void getEnemyMissionTargetList(...) - unsupported arg type
  line 19: void getGUIData(...) - unsupported arg type
*/

int FactionLeaderBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FactionLeaderBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FactionLeader object");
    return 1;
}

void FactionLeaderBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FactionLeaderBinding::gc },
        { "__tostring", FactionLeaderBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", FactionLeaderBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        FactionLeaderBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FactionLeaderBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, FactionLeader_get_faction);
    lua_setfield(L, -2, "faction");
    lua_pushcfunction(L, FactionLeader_get_biomeTerritory);
    lua_setfield(L, -2, "biomeTerritory");
    lua_pushcfunction(L, FactionLeader_get_worstEnemy);
    lua_setfield(L, -2, "worstEnemy");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FactionLeader_set_faction);
    lua_setfield(L, -2, "faction");
    lua_pushcfunction(L, FactionLeader_set_biomeTerritory);
    lua_setfield(L, -2, "biomeTerritory");
    lua_pushcfunction(L, FactionLeader_set_worstEnemy);
    lua_setfield(L, -2, "worstEnemy");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua