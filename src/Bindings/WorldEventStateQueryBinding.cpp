#include "pch.h"
#include "WorldEventStateQueryBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"

namespace KenshiLua
{

static WorldEventStateQuery* getInstance(lua_State* L, int idx)
{
    return checkObject<WorldEventStateQuery>(L, idx, WorldEventStateQueryBinding::getMetatableName());
}

// --- Getters for WorldEventStateQuery ---
static int WorldEventStateQuery_get_playerInvolvement(lua_State* L)
{
    WorldEventStateQuery* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQuery is nil");
    lua_pushboolean(L, instance->playerInvolvement ? 1 : 0);
    return 1;
}

// --- Setters for WorldEventStateQuery ---
static int WorldEventStateQuery_set_playerInvolvement(lua_State* L)
{
    WorldEventStateQuery* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQuery is nil");
    instance->playerInvolvement = lua_toboolean(L, 2) != 0;
    return 0;
}

int WorldEventStateQueryBinding::_CONSTRUCTOR(lua_State* L)
{
    WorldEventStateQuery* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQuery is nil");

    WorldEventStateQuery* result = instance->_CONSTRUCTOR();
    return pushObject<WorldEventStateQuery>(L, result, WorldEventStateQueryBinding::getMetatableName());
}

int WorldEventStateQueryBinding::isTrue(lua_State* L)
{
    WorldEventStateQuery* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQuery is nil");

    bool result = instance->isTrue();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
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



static int WorldEventStateQuery_get_isAllyOf(lua_State* L)
{
    WorldEventStateQuery* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQuery is nil");
    return pushObject<ogre_unordered_map<Faction*, bool>::type>(
        L, &instance->isAllyOf, OgreUnorderedMapBinding<Faction*, bool>::getMetatableName());
}


static int WorldEventStateQuery_get_isEnemyOf(lua_State* L)
{
    WorldEventStateQuery* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQuery is nil");
    return pushObject<ogre_unordered_map<Faction*, bool>::type>(
        L, &instance->isEnemyOf, OgreUnorderedMapBinding<Faction*, bool>::getMetatableName());
}


static int WorldEventStateQuery_get_towns(lua_State* L)
{
    WorldEventStateQuery* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQuery is nil");
    return pushObject<ogre_unordered_map<GameData*, WorldStateEnum>::type>(
        L, &instance->towns, OgreUnorderedMapBinding<GameData*, WorldStateEnum>::getMetatableName());
}


static int WorldEventStateQuery_get_uniqueNPCsAre(lua_State* L)
{
    WorldEventStateQuery* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQuery is nil");
    return pushObject<ogre_unordered_map<GameData*, WorldStateEnum>::type>(
        L, &instance->uniqueNPCsAre, OgreUnorderedMapBinding<GameData*, WorldStateEnum>::getMetatableName());
}


static int WorldEventStateQuery_get_uniqueNPCsAreNot(lua_State* L)
{
    WorldEventStateQuery* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQuery is nil");
    return pushObject<ogre_unordered_map<GameData*, WorldStateEnum>::type>(
        L, &instance->uniqueNPCsAreNot, OgreUnorderedMapBinding<GameData*, WorldStateEnum>::getMetatableName());
}


static int WorldEventStateQuery_set_isAllyOf(lua_State* L)
{
    WorldEventStateQuery* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQuery is nil");
    ogre_unordered_map<Faction*, bool>::type* val = OgreUnorderedMapBinding<Faction*, bool>::get(L, 2);
    if (!val) return luaL_error(L, "Expected ogre_unordered_map<Faction*, bool>");
    instance->isAllyOf = *val;
    return 0;
}


static int WorldEventStateQuery_set_isEnemyOf(lua_State* L)
{
    WorldEventStateQuery* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQuery is nil");
    ogre_unordered_map<Faction*, bool>::type* val = OgreUnorderedMapBinding<Faction*, bool>::get(L, 2);
    if (!val) return luaL_error(L, "Expected ogre_unordered_map<Faction*, bool>");
    instance->isEnemyOf = *val;
    return 0;
}


static int WorldEventStateQuery_set_towns(lua_State* L)
{
    WorldEventStateQuery* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQuery is nil");
    ogre_unordered_map<GameData*, WorldStateEnum>::type* val = OgreUnorderedMapBinding<GameData*, WorldStateEnum>::get(L, 2);
    if (!val) return luaL_error(L, "Expected ogre_unordered_map<GameData*, WorldStateEnum>");
    instance->towns = *val;
    return 0;
}


static int WorldEventStateQuery_set_uniqueNPCsAre(lua_State* L)
{
    WorldEventStateQuery* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQuery is nil");
    ogre_unordered_map<GameData*, WorldStateEnum>::type* val = OgreUnorderedMapBinding<GameData*, WorldStateEnum>::get(L, 2);
    if (!val) return luaL_error(L, "Expected ogre_unordered_map<GameData*, WorldStateEnum>");
    instance->uniqueNPCsAre = *val;
    return 0;
}


static int WorldEventStateQuery_set_uniqueNPCsAreNot(lua_State* L)
{
    WorldEventStateQuery* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQuery is nil");
    ogre_unordered_map<GameData*, WorldStateEnum>::type* val = OgreUnorderedMapBinding<GameData*, WorldStateEnum>::get(L, 2);
    if (!val) return luaL_error(L, "Expected ogre_unordered_map<GameData*, WorldStateEnum>");
    instance->uniqueNPCsAreNot = *val;
    return 0;
}


void WorldEventStateQueryBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WorldEventStateQueryBinding::gc },
        { "__tostring", WorldEventStateQueryBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", WorldEventStateQueryBinding::_CONSTRUCTOR },
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
    registerGetter(L, "playerInvolvement", WorldEventStateQuery_get_playerInvolvement);
    registerGetter(L, "isAllyOf", WorldEventStateQuery_get_isAllyOf);
    registerGetter(L, "isEnemyOf", WorldEventStateQuery_get_isEnemyOf);
    registerGetter(L, "towns", WorldEventStateQuery_get_towns);
    registerGetter(L, "uniqueNPCsAre", WorldEventStateQuery_get_uniqueNPCsAre);
    registerGetter(L, "uniqueNPCsAreNot", WorldEventStateQuery_get_uniqueNPCsAreNot);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "playerInvolvement", WorldEventStateQuery_set_playerInvolvement);
    registerSetter(L, "isAllyOf", WorldEventStateQuery_set_isAllyOf);
    registerSetter(L, "isEnemyOf", WorldEventStateQuery_set_isEnemyOf);
    registerSetter(L, "towns", WorldEventStateQuery_set_towns);
    registerSetter(L, "uniqueNPCsAre", WorldEventStateQuery_set_uniqueNPCsAre);
    registerSetter(L, "uniqueNPCsAreNot", WorldEventStateQuery_set_uniqueNPCsAreNot);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua