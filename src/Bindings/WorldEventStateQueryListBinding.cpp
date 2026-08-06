#include "pch.h"
#include "kenshi\WorldEventStateQuery.h"
#include "WorldEventStateQueryListBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/WorldEventStateQueryBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"

namespace KenshiLua
{

static WorldEventStateQueryList* getInstance(lua_State* L, int idx)
{
    return checkObject<WorldEventStateQueryList>(L, idx, WorldEventStateQueryListBinding::getMetatableName());
}

// --- Getters for WorldEventStateQueryList ---
// --- Setters for WorldEventStateQueryList ---
int WorldEventStateQueryListBinding::setupFrom(lua_State* L)
{
    WorldEventStateQueryList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQueryList is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string listname = luaL_checkstring(L, 3);
    bool result = instance->setupFrom(d, listname);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WorldEventStateQueryListBinding::reset(lua_State* L)
{
    WorldEventStateQueryList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQueryList is nil");

    instance->reset();
    return 0;
}

int WorldEventStateQueryListBinding::isTrue(lua_State* L)
{
    WorldEventStateQueryList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQueryList is nil");

    bool result = instance->isTrue();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WorldEventStateQueryListBinding::_CONSTRUCTOR(lua_State* L)
{
    WorldEventStateQueryList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQueryList is nil");

    WorldEventStateQueryList* result = instance->_CONSTRUCTOR();
    return pushObject<WorldEventStateQueryList>(L, result, WorldEventStateQueryListBinding::getMetatableName());
}

int WorldEventStateQueryListBinding::_DESTRUCTOR(lua_State* L)
{
    WorldEventStateQueryList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQueryList is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int WorldEventStateQueryListBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int WorldEventStateQueryListBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.WorldEventStateQueryList object");
    return 1;
}

static int WorldEventStateQueryList_get_statesList(lua_State* L)
{
    WorldEventStateQueryList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQueryList is nil");
    return pushObject<ogre_unordered_map<WorldEventStateQuery*, bool>::type>(
        L, &instance->statesList, OgreUnorderedMapBinding<WorldEventStateQuery*, bool>::getMetatableName());
}

static int WorldEventStateQueryList_set_statesList(lua_State* L)
{
    WorldEventStateQueryList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WorldEventStateQueryList is nil");
    ogre_unordered_map<WorldEventStateQuery*, bool>::type* val = 
        OgreUnorderedMapBinding<WorldEventStateQuery*, bool>::get(L, 2);
    if (!val) return luaL_error(L, "Expected ogre_unordered_map<WorldEventStateQuery*, bool>");
    instance->statesList = *val;
    return 0;
}


void WorldEventStateQueryListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WorldEventStateQueryListBinding::gc },
        { "__tostring", WorldEventStateQueryListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setupFrom", WorldEventStateQueryListBinding::setupFrom },
        { "reset", WorldEventStateQueryListBinding::reset },
        { "isTrue", WorldEventStateQueryListBinding::isTrue },
        { "_CONSTRUCTOR", WorldEventStateQueryListBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", WorldEventStateQueryListBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        WorldEventStateQueryListBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, WorldEventStateQueryListBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
        registerGetter(L, "statesList", WorldEventStateQueryList_get_statesList);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
        registerSetter(L, "statesList", WorldEventStateQueryList_set_statesList);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua