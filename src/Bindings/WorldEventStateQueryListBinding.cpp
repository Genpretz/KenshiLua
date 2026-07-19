#include "pch.h"
#include "kenshi\WorldEventStateQuery.h"
#include "WorldEventStateQueryListBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static WorldEventStateQueryList* getB(lua_State* L, int idx)
{
    return checkObject<WorldEventStateQueryList>(L, idx, WorldEventStateQueryListBinding::getMetatableName());
}

// --- Getters for WorldEventStateQueryList ---
static int WorldEventStateQueryList_get_statesList(lua_State* L)
{
    WorldEventStateQueryList* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQueryList is nil");
    // TODO: Unsupported type for statesList (ogre_unordered_map<WorldEventStateQuery*, bool>::type)
    return luaL_error(L, "Unsupported property 'statesList' (type: ogre_unordered_map<WorldEventStateQuery*, bool>::type)");
}

// --- Setters for WorldEventStateQueryList ---
static int WorldEventStateQueryList_set_statesList(lua_State* L)
{
    WorldEventStateQueryList* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQueryList is nil");
    return luaL_error(L, "Read-only or unsupported setter type for statesList");
}

int WorldEventStateQueryListBinding::reset(lua_State* L)
{
    WorldEventStateQueryList* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQueryList is nil");

    b->reset();
    return 0;
}

int WorldEventStateQueryListBinding::isTrue(lua_State* L)
{
    WorldEventStateQueryList* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQueryList is nil");

    bool result = b->isTrue();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WorldEventStateQueryListBinding::_DESTRUCTOR(lua_State* L)
{
    WorldEventStateQueryList* b = getB(L, 1);
    if (!b) return luaL_error(L, "WorldEventStateQueryList is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 47: bool setupFrom(...) - unsupported arg type
  line 53: WorldEventStateQueryList* _CONSTRUCTOR(...) - unsupported return type
*/

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

void WorldEventStateQueryListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WorldEventStateQueryListBinding::gc },
        { "__tostring", WorldEventStateQueryListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "reset", WorldEventStateQueryListBinding::reset },
        { "isTrue", WorldEventStateQueryListBinding::isTrue },
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
    lua_pushcfunction(L, WorldEventStateQueryList_get_statesList);
    lua_setfield(L, -2, "statesList");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, WorldEventStateQueryList_set_statesList);
    lua_setfield(L, -2, "statesList");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
