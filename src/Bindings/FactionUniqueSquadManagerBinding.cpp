#include "pch.h"
#include "kenshi\FactionUniqueSquadManager.h"
#include "FactionUniqueSquadManagerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static FactionUniqueSquadManager* getInstance(lua_State* L, int idx)
{
    return checkObject<FactionUniqueSquadManager>(L, idx, FactionUniqueSquadManagerBinding::getMetatableName());
}

// --- Getters for FactionUniqueSquadManager ---
static int FactionUniqueSquadManager_get_me(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");
    return pushObject<Faction>(L, instance->me, FactionBinding::getMetatableName());
}

static int FactionUniqueSquadManager_get_squadListData(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");
    return pushObject<GameData>(L, instance->squadListData, GameDataBinding::getMetatableName());
}

static int FactionUniqueSquadManager_get_homeTown(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");
    return pushObject<Town>(L, instance->homeTown, TownBinding::getMetatableName());
}

// --- Setters for FactionUniqueSquadManager ---
int FactionUniqueSquadManagerBinding::_CONSTRUCTOR(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");

    FactionUniqueSquadManager* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int FactionUniqueSquadManagerBinding::_DESTRUCTOR(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int FactionUniqueSquadManagerBinding::clearAndReset(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");

    instance->clearAndReset();
    return 0;
}

int FactionUniqueSquadManagerBinding::chooseRandomSquadToSpawn(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");

    float time = (float)luaL_checknumber(L, 2);
    GameData* result = instance->chooseRandomSquadToSpawn(time);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int FactionUniqueSquadManagerBinding::periodicUpdate(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->periodicUpdate(time);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 39: void initialiseNew(...) - unsupported arg type
  line 42: void serialise(...) - unsupported arg type
  line 43: void load(...) - unsupported arg type
  line 44: void getGUIData(...) - unsupported arg type
  line 45: void endOfUniqueSquad(...) - unsupported arg type
  line 67: FactionUniqueSquadManager::UniqueSpawnData* getExistingSquadsFor(...) - unsupported arg type
  line 68: UniquePlatoon* spawnNewUniqueSquad(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 46: prosperityMgr (ProsperityManager) - unsupported type
  line 66: squads (lektor<FactionUniqueSquadManager::UniqueSpawnData*>) - unsupported type
*/

int FactionUniqueSquadManagerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FactionUniqueSquadManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FactionUniqueSquadManager object");
    return 1;
}

void FactionUniqueSquadManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FactionUniqueSquadManagerBinding::gc },
        { "__tostring", FactionUniqueSquadManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", FactionUniqueSquadManagerBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", FactionUniqueSquadManagerBinding::_DESTRUCTOR },
        { "clearAndReset", FactionUniqueSquadManagerBinding::clearAndReset },
        { "chooseRandomSquadToSpawn", FactionUniqueSquadManagerBinding::chooseRandomSquadToSpawn },
        { "periodicUpdate", FactionUniqueSquadManagerBinding::periodicUpdate },
        { 0, 0 }
    };

    registerClass(
        L, 
        FactionUniqueSquadManagerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FactionUniqueSquadManagerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, FactionUniqueSquadManager_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, FactionUniqueSquadManager_get_squadListData);
    lua_setfield(L, -2, "squadListData");
    lua_pushcfunction(L, FactionUniqueSquadManager_get_homeTown);
    lua_setfield(L, -2, "homeTown");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
