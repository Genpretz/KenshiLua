#include "pch.h"
#include "kenshi\Faction.h"
#include "FactionManagerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static FactionManager* getB(lua_State* L, int idx)
{
    return checkObject<FactionManager>(L, idx, FactionManagerBinding::getMetatableName());
}

// --- Getters for FactionManager ---
static int FactionManager_get_participants(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");
    // TODO: Unsupported type for participants (lektor<Faction*>)
    lua_pushnil(L);
    return 1;
}

static int FactionManager_get_addListMuto(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");
    lua_pushnil(L);
    return 1;
}

static int FactionManager_get_toAddList(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");
    // TODO: Unsupported type for toAddList (lektor<Platoon*>)
    lua_pushnil(L);
    return 1;
}

// --- Setters for FactionManager ---
static int FactionManager_set_participants(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for participants");
}

static int FactionManager_set_addListMuto(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for addListMuto");
}

static int FactionManager_set_toAddList(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for toAddList");
}

int FactionManagerBinding::clearAndDestroy(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");

    b->clearAndDestroy();
    return 0;
}

int FactionManagerBinding::activateUnloadedPlatoons(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");

    b->activateUnloadedPlatoons();
    return 0;
}

int FactionManagerBinding::getFactionByName(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");

    std::string name = luaL_checkstring(L, 2);
    Faction* result = b->getFactionByName(name);
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int FactionManagerBinding::getFactionByStringID(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");

    std::string sid = luaL_checkstring(L, 2);
    Faction* result = b->getFactionByStringID(sid);
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int FactionManagerBinding::getEmptyFaction(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");

    Faction* result = b->getEmptyFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int FactionManagerBinding::setupAndLinkAllFactions(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");

    b->setupAndLinkAllFactions();
    return 0;
}

int FactionManagerBinding::areAnyHostileCampaignsRunning(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");

    bool result = b->areAnyHostileCampaignsRunning();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionManagerBinding::getNumTempPlatoons(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");

    int result = b->getNumTempPlatoons();
    lua_pushinteger(L, result);
    return 1;
}

int FactionManagerBinding::updateMT(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->updateMT(time);
    return 0;
}

int FactionManagerBinding::updateThreaded(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->updateThreaded(time);
    return 0;
}

int FactionManagerBinding::_showDebugPlatoonMarkers(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->_showDebugPlatoonMarkers(on);
    return 0;
}

int FactionManagerBinding::_DESTRUCTOR(lua_State* L)
{
    FactionManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "FactionManager is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 175: FactionManager* _CONSTRUCTOR(...) - unsupported return type
  line 176: void saveGameState(...) - unsupported arg type
  line 177: void savePlayerGameState(...) - unsupported arg type
  line 181: Faction* getOrCreateFaction(...) - overloaded method
  line 182: Faction* getOrCreateFaction(...) - overloaded method
  line 187: Faction* getFactionBySquad(...) - unsupported arg type
  line 188: void getCampaignGUIInfos(...) - unsupported arg type
  line 194: const lektor<Faction*>* getAllFactions(...) - unsupported return type
*/

int FactionManagerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FactionManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FactionManager object");
    return 1;
}

void FactionManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FactionManagerBinding::gc },
        { "__tostring", FactionManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "clearAndDestroy", FactionManagerBinding::clearAndDestroy },
        { "activateUnloadedPlatoons", FactionManagerBinding::activateUnloadedPlatoons },
        { "getFactionByName", FactionManagerBinding::getFactionByName },
        { "getFactionByStringID", FactionManagerBinding::getFactionByStringID },
        { "getEmptyFaction", FactionManagerBinding::getEmptyFaction },
        { "setupAndLinkAllFactions", FactionManagerBinding::setupAndLinkAllFactions },
        { "areAnyHostileCampaignsRunning", FactionManagerBinding::areAnyHostileCampaignsRunning },
        { "getNumTempPlatoons", FactionManagerBinding::getNumTempPlatoons },
        { "updateMT", FactionManagerBinding::updateMT },
        { "updateThreaded", FactionManagerBinding::updateThreaded },
        { "_showDebugPlatoonMarkers", FactionManagerBinding::_showDebugPlatoonMarkers },
        { "_DESTRUCTOR", FactionManagerBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        FactionManagerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FactionManagerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, FactionManager_get_participants);
    lua_setfield(L, -2, "participants");
    lua_pushcfunction(L, FactionManager_get_addListMuto);
    lua_setfield(L, -2, "addListMuto");
    lua_pushcfunction(L, FactionManager_get_toAddList);
    lua_setfield(L, -2, "toAddList");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FactionManager_set_participants);
    lua_setfield(L, -2, "participants");
    lua_pushcfunction(L, FactionManager_set_addListMuto);
    lua_setfield(L, -2, "addListMuto");
    lua_pushcfunction(L, FactionManager_set_toAddList);
    lua_setfield(L, -2, "toAddList");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua