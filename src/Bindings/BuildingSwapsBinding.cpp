#include "pch.h"
#include "kenshi\Faction.h"
#include "BuildingSwapsBinding.h"
#include "GameDataBinding.h"
#include <kenshi/GameData.h>
#include "Bindings/Templates/OgreUnorderedBinding.h"
#include "Bindings/FitnessSelectorBinding.h"
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
    return pushObject<ogre_unordered_set<GameData*>::type>(L, &b->toReplace, OgreUnorderedSetBinding<GameData*>::metaName);
}

static int BuildingSwaps_get_replaceWith(lua_State* L)
{
    Faction::BuildingSwaps* b = getB(L, 1);
    if (!b) return luaL_error(L, "BuildingSwaps is nil");
    return pushObject<FitnessSelector<GameData*>>(L, &b->replaceWith, FitnessSelectorBinding<GameData*>::metaName);
}

// --- Setters for BuildingSwaps ---
static int BuildingSwaps_set_toReplace(lua_State* L)
{
    Faction::BuildingSwaps* b = getB(L, 1);
    if (!b) return luaL_error(L, "BuildingSwaps is nil");
    ogre_unordered_set<GameData*>::type* val = OgreUnorderedSetBinding<GameData*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected ogre_unordered_set<GameData*>");
    b->toReplace = *val;
    return 0;
}

static int BuildingSwaps_set_replaceWith(lua_State* L)
{
    Faction::BuildingSwaps* b = getB(L, 1);
    if (!b) return luaL_error(L, "BuildingSwaps is nil");
    FitnessSelector<GameData*>* val = FitnessSelectorBinding<GameData*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected FitnessSelector_GameData");
    b->replaceWith = *val;
    return 0;
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
  line 47: Faction::BuildingSwaps& operator=(...) - operator
*/

int BuildingSwapsBinding::_CONSTRUCTOR(lua_State* L)
{
    Faction::BuildingSwaps* b = getB(L, 1);
    if (!b) return luaL_error(L, "BuildingSwaps is nil");

    if (lua_gettop(L) >= 2 && !lua_isnil(L, 2))
    {
        GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
        if (!data) return luaL_error(L, "Expected GameData object for constructor");
        Faction::BuildingSwaps* result = b->_CONSTRUCTOR(data);
        return pushObject<Faction::BuildingSwaps>(L, result, BuildingSwapsBinding::getMetatableName());
    }
    else
    {
        Faction::BuildingSwaps* result = b->_CONSTRUCTOR();
        return pushObject<Faction::BuildingSwaps>(L, result, BuildingSwapsBinding::getMetatableName());
    }
}

int BuildingSwapsBinding::hasReplacement(lua_State* L)
{
    Faction::BuildingSwaps* b = getB(L, 1);
    if (!b) return luaL_error(L, "BuildingSwaps is nil");

    GameData* building = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (!building) return luaL_error(L, "Expected GameData object");

    bool result = b->hasReplacement(building);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingSwapsBinding::getReplacement(lua_State* L)
{
    Faction::BuildingSwaps* b = getB(L, 1);
    if (!b) return luaL_error(L, "BuildingSwaps is nil");

    GameData* building = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (!building) return luaL_error(L, "Expected GameData object");

    GameData* result = b->getReplacement(building);
    if (!result)
    {
        lua_pushnil(L);
    }
    else
    {
        pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
    }
    return 1;
}

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
        { "_CONSTRUCTOR", BuildingSwapsBinding::_CONSTRUCTOR },
        { "hasReplacement", BuildingSwapsBinding::hasReplacement },
        { "getReplacement", BuildingSwapsBinding::getReplacement },
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
