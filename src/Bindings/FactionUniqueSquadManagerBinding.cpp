#include "pch.h"
#include "kenshi\FactionUniqueSquadManager.h"
#include "FactionUniqueSquadManagerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/ProsperityManagerBinding.h"
#include "Bindings/TownBinding.h"

namespace KenshiLua
{

static FactionUniqueSquadManager* getInstance(lua_State* L, int idx)
{
    return checkObject<FactionUniqueSquadManager>(L, idx, FactionUniqueSquadManagerBinding::getMetatableName());
}

// --- Getters for FactionUniqueSquadManager ---
static int FactionUniqueSquadManager_get_prosperityMgr(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");
    return pushObject<ProsperityManager>(L, &instance->prosperityMgr, ProsperityManagerBinding::getMetatableName());
}

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
static int FactionUniqueSquadManager_set_prosperityMgr(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");
    instance->prosperityMgr = *checkObject<ProsperityManager>(L, 2, ProsperityManagerBinding::getMetatableName());
    return 0;
}

static int FactionUniqueSquadManager_set_me(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int FactionUniqueSquadManager_set_squadListData(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");
    instance->squadListData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int FactionUniqueSquadManager_set_homeTown(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");
    instance->homeTown = lua_isnoneornil(L, 2) ? nullptr : checkObject<Town>(L, 2, TownBinding::getMetatableName());
    return 0;
}

int FactionUniqueSquadManagerBinding::_CONSTRUCTOR(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");

    FactionUniqueSquadManager* result = instance->_CONSTRUCTOR();
    return pushObject<FactionUniqueSquadManager>(L, result, FactionUniqueSquadManagerBinding::getMetatableName());
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

int FactionUniqueSquadManagerBinding::initialiseNew(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");

    Faction* faction = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    GameData* mdat = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    Town* t = checkObject<Town>(L, 4, TownBinding::getMetatableName());
    instance->initialiseNew(faction, mdat, t);
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

int FactionUniqueSquadManagerBinding::serialise(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->serialise(state);
    return 0;
}

int FactionUniqueSquadManagerBinding::load(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool import = lua_toboolean(L, 3) != 0;
    instance->load(state, import);
    return 0;
}

int FactionUniqueSquadManagerBinding::getGUIData(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int cat = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(panel, cat);
    return 0;
}

int FactionUniqueSquadManagerBinding::getExistingSquadsFor(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");

    GameData* squad = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    FactionUniqueSquadManager::UniqueSpawnData* result = instance->getExistingSquadsFor(squad);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int FactionUniqueSquadManagerBinding::spawnNewUniqueSquad(lua_State* L)
{
    FactionUniqueSquadManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionUniqueSquadManager is nil");

    GameData* squadtemplate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    UniquePlatoon* result = instance->spawnNewUniqueSquad(squadtemplate);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 45: void endOfUniqueSquad(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
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
        { "initialiseNew", FactionUniqueSquadManagerBinding::initialiseNew },
        { "chooseRandomSquadToSpawn", FactionUniqueSquadManagerBinding::chooseRandomSquadToSpawn },
        { "periodicUpdate", FactionUniqueSquadManagerBinding::periodicUpdate },
        { "serialise", FactionUniqueSquadManagerBinding::serialise },
        { "load", FactionUniqueSquadManagerBinding::load },
        { "getGUIData", FactionUniqueSquadManagerBinding::getGUIData },
        { "getExistingSquadsFor", FactionUniqueSquadManagerBinding::getExistingSquadsFor },
        { "spawnNewUniqueSquad", FactionUniqueSquadManagerBinding::spawnNewUniqueSquad },
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
    lua_pushcfunction(L, FactionUniqueSquadManager_get_prosperityMgr);
    lua_setfield(L, -2, "prosperityMgr");
    lua_pushcfunction(L, FactionUniqueSquadManager_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, FactionUniqueSquadManager_get_squadListData);
    lua_setfield(L, -2, "squadListData");
    lua_pushcfunction(L, FactionUniqueSquadManager_get_homeTown);
    lua_setfield(L, -2, "homeTown");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FactionUniqueSquadManager_set_prosperityMgr);
    lua_setfield(L, -2, "prosperityMgr");
    lua_pushcfunction(L, FactionUniqueSquadManager_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, FactionUniqueSquadManager_set_squadListData);
    lua_setfield(L, -2, "squadListData");
    lua_pushcfunction(L, FactionUniqueSquadManager_set_homeTown);
    lua_setfield(L, -2, "homeTown");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua