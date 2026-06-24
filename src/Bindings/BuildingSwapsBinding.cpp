#include "pch.h"
#include "kenshi\Faction.h"
#include "BuildingSwapsBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Faction::BuildingSwaps* getB(lua_State* L, int idx)
{
    return checkObject<Faction::BuildingSwaps>(L, idx, BuildingSwapsBinding::getMetatableName());
}

// --- Getters for BuildingSwaps ---
static int BuildingSwaps_get_toReplace(lua_State* L)
{
    Faction::BuildingSwaps* b = getB(L, 1);
    if (!b) return luaL_error(L, "BuildingSwaps is nil");
    // TODO: Unsupported type for toReplace (ogre_unordered_set<GameData*>::type)
    lua_pushnil(L);
    return 1;
}

static int BuildingSwaps_get_replaceWith(lua_State* L)
{
    Faction::BuildingSwaps* b = getB(L, 1);
    if (!b) return luaL_error(L, "BuildingSwaps is nil");
    // TODO: Unsupported type for replaceWith (FitnessSelector<GameData*>)
    lua_pushnil(L);
    return 1;
}

// --- Setters for BuildingSwaps ---
static int BuildingSwaps_set_toReplace(lua_State* L)
{
    Faction::BuildingSwaps* b = getB(L, 1);
    if (!b) return luaL_error(L, "BuildingSwaps is nil");
    return luaL_error(L, "Read-only or unsupported setter type for toReplace");
}

static int BuildingSwaps_set_replaceWith(lua_State* L)
{
    Faction::BuildingSwaps* b = getB(L, 1);
    if (!b) return luaL_error(L, "BuildingSwaps is nil");
    return luaL_error(L, "Read-only or unsupported setter type for replaceWith");
}

int BuildingSwapsBinding::_DESTRUCTOR(lua_State* L)
{
    Faction::BuildingSwaps* b = getB(L, 1);
    if (!b) return luaL_error(L, "BuildingSwaps is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 38: Faction::BuildingSwaps* _CONSTRUCTOR(...) - overloaded method
  line 40: Faction::BuildingSwaps* _CONSTRUCTOR(...) - overloaded method
  line 41: bool hasReplacement(...) - unsupported arg type
  line 42: GameData* getReplacement(...) - unsupported arg type
  line 47: Faction::BuildingSwaps& operator=(...) - operator
*/

int BuildingSwapsBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BuildingSwapsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BuildingSwaps object");
    return 1;
}

void BuildingSwapsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildingSwapsBinding::gc },
        { "__tostring", BuildingSwapsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", BuildingSwapsBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        BuildingSwapsBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BuildingSwapsBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, BuildingSwaps_get_toReplace);
    lua_setfield(L, -2, "toReplace");
    lua_pushcfunction(L, BuildingSwaps_get_replaceWith);
    lua_setfield(L, -2, "replaceWith");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, BuildingSwaps_set_toReplace);
    lua_setfield(L, -2, "toReplace");
    lua_pushcfunction(L, BuildingSwaps_set_replaceWith);
    lua_setfield(L, -2, "replaceWith");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua