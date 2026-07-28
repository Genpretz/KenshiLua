#include "pch.h"
#include "kenshi\faction.h"
#include "BuildingSwapsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Bindings/FitnessSelectorBinding.h"

namespace KenshiLua
{

typedef Faction::BuildingSwaps BuildingSwaps;

static BuildingSwaps* getInstance(lua_State* L, int idx)
{
    return checkObject<BuildingSwaps>(L, idx, BuildingSwapsBinding::getMetatableName());
}

// --- Getters for BuildingSwaps ---
static int BuildingSwaps_get_toReplace(lua_State* L)
{
    Faction::BuildingSwaps* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingSwaps is nil");
    return pushObject<ogre_unordered_set<GameData*>::type>(L, &instance->toReplace, OgreUnorderedSetBinding<GameData*>::metaName);
}

static int BuildingSwaps_get_replaceWith(lua_State* L)
{
    Faction::BuildingSwaps* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingSwaps is nil");
    return pushObject<FitnessSelector<GameData*>>(L, &instance->replaceWith, FitnessSelectorBinding<GameData*>::metaName);
}

// --- Setters for BuildingSwaps ---
static int BuildingSwaps_set_toReplace(lua_State* L)
{
    Faction::BuildingSwaps* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingSwaps is nil");
    ogre_unordered_set<GameData*>::type* val = OgreUnorderedSetBinding<GameData*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected ogre_unordered_set<GameData*>");
    instance->toReplace = *val;
    return 0;
}

static int BuildingSwaps_set_replaceWith(lua_State* L)
{
    Faction::BuildingSwaps* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingSwaps is nil");
    FitnessSelector<GameData*>* val = FitnessSelectorBinding<GameData*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected FitnessSelector_GameData");
    instance->replaceWith = *val;
    return 0;
}

int BuildingSwapsBinding::hasReplacement(lua_State* L)
{
    BuildingSwaps* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingSwaps is nil");

    GameData* building = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->hasReplacement(building);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildingSwapsBinding::getReplacement(lua_State* L)
{
    BuildingSwaps* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingSwaps is nil");

    GameData* building = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());

    return pushObject<GameData>(
        L,
        instance->getReplacement(building),
        GameDataBinding::getMetatableName());
}

int BuildingSwapsBinding::_DESTRUCTOR(lua_State* L)
{
    BuildingSwaps* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingSwaps is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int BuildingSwapsBinding::_CONSTRUCTOR(lua_State* L)
{
    Faction::BuildingSwaps* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingSwaps is nil");

    if (lua_gettop(L) >= 2 && !lua_isnil(L, 2))
    {
        GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
        if (!data) return luaL_error(L, "Expected GameData object for constructor");
        Faction::BuildingSwaps* result = instance->_CONSTRUCTOR(data);
        return pushObject<Faction::BuildingSwaps>(L, result, BuildingSwapsBinding::getMetatableName());
    }
    else
    {
        Faction::BuildingSwaps* result = instance->_CONSTRUCTOR();
        return pushObject<Faction::BuildingSwaps>(L, result, BuildingSwapsBinding::getMetatableName());
    }
}

/*
Skipped methods needing manual binding:
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
        { "hasReplacement", BuildingSwapsBinding::hasReplacement },
        { "getReplacement", BuildingSwapsBinding::getReplacement },
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
    registerGetter(L, "toReplace", BuildingSwaps_get_toReplace);
    registerGetter(L, "replaceWith", BuildingSwaps_get_replaceWith);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "toReplace", BuildingSwaps_set_toReplace);
    registerSetter(L, "replaceWith", BuildingSwaps_set_replaceWith);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua