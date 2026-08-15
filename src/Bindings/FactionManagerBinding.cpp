#include "pch.h"
#include "kenshi\faction.h"
#include "FactionManagerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/Util/LektorBinding.h"

namespace KenshiLua
{

static FactionManager* getInstance(lua_State* L, int idx)
{
    return checkObject<FactionManager>(L, idx, FactionManagerBinding::getMetatableName());
}

// --- Getters for FactionManager ---
// static int FactionManager_get_addListMuto(lua_State* L)
// {
//     FactionManager* instance = getInstance(L, 1);
//     if (!instance) return luaL_error(L, "FactionManager is nil");
//     lua_pushinteger(L, (lua_Integer)instance->addListMuto);
//     return 1;
// }

static int FactionManager_get_participants(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");
    return pushObject<lektor<Faction*>>(L, &instance->participants, LektorPtrBinding<Faction*>::metaName);
}

static int FactionManager_get_toAddList(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");
    return pushObject<lektor<Platoon*>>(L, &instance->toAddList, LektorPtrBinding<Platoon*>::metaName);
}


// --- Setters for FactionManager ---
// static int FactionManager_set_addListMuto(lua_State* L)
// {
//     FactionManager* instance = getInstance(L, 1);
//     if (!instance) return luaL_error(L, "FactionManager is nil");
//     instance->addListMuto = (boost::shared_mutex)luaL_checkinteger(L, 2);
//     return 0;
// }

static int FactionManager_set_participants(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");
    lektor<Faction*>* val = LektorPtrBinding<Faction*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<Faction*>");
    instance->participants = *val;
    return 0;
}

static int FactionManager_set_toAddList(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");
    lektor<Platoon*>* val = LektorPtrBinding<Platoon*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<Platoon*>");
    instance->toAddList = *val;
    return 0;
}

int FactionManagerBinding::saveGameState(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    instance->saveGameState(container);
    return 0;
}

int FactionManagerBinding::savePlayerGameState(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    instance->savePlayerGameState(container);
    return 0;
}

int FactionManagerBinding::clearAndDestroy(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    instance->clearAndDestroy();
    return 0;
}

int FactionManagerBinding::activateUnloadedPlatoons(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    instance->activateUnloadedPlatoons();
    return 0;
}

int FactionManagerBinding::getOrCreateFaction(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    if (lua_isstring(L, 2))
    {
        std::string id = luaL_checkstring(L, 2);
        std::string name = luaL_checkstring(L, 3);
        Faction* result = instance->getOrCreateFaction(id, name);
        return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
    }
    else
    {
        GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
        Faction* result = instance->getOrCreateFaction(data);
        return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
    }
}

int FactionManagerBinding::getFactionByName(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    const std::string name = luaL_checkstring(L, 2);
    Faction* result = instance->getFactionByName(name);
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int FactionManagerBinding::getFactionByStringID(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    const std::string sid = luaL_checkstring(L, 2);
    Faction* result = instance->getFactionByStringID(sid);
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int FactionManagerBinding::getEmptyFaction(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    Faction* result = instance->getEmptyFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int FactionManagerBinding::setupAndLinkAllFactions(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    instance->setupAndLinkAllFactions();
    return 0;
}

int FactionManagerBinding::getFactionBySquad(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    GameData* squadtemplate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Faction* result = instance->getFactionBySquad(squadtemplate);
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int FactionManagerBinding::getCampaignGUIInfos(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    DatapanelGUI* pan = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int cat = (int)luaL_checkinteger(L, 3);
    bool playeronly = lua_toboolean(L, 4) != 0;
    instance->getCampaignGUIInfos(pan, cat, playeronly);
    return 0;
}

int FactionManagerBinding::areAnyHostileCampaignsRunning(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    bool result = instance->areAnyHostileCampaignsRunning();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionManagerBinding::getNumTempPlatoons(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    int result = instance->getNumTempPlatoons();
    lua_pushinteger(L, result);
    return 1;
}

int FactionManagerBinding::updateMT(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->updateMT(time);
    return 0;
}

int FactionManagerBinding::updateThreaded(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->updateThreaded(time);
    return 0;
}

int FactionManagerBinding::_showDebugPlatoonMarkers(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_showDebugPlatoonMarkers(on);
    return 0;
}

int FactionManagerBinding::getAllFactions(lua_State* L)
{
    FactionManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionManager is nil");

    const lektor<Faction*>* result = instance->getAllFactions();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - FactionManagerBinding::getAllFactions: const lektor<Faction*>* (unbound pointer)
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
        { "saveGameState", FactionManagerBinding::saveGameState },
        { "savePlayerGameState", FactionManagerBinding::savePlayerGameState },
        { "clearAndDestroy", FactionManagerBinding::clearAndDestroy },
        { "activateUnloadedPlatoons", FactionManagerBinding::activateUnloadedPlatoons },
        { "getOrCreateFaction", FactionManagerBinding::getOrCreateFaction },
        { "getFactionByName", FactionManagerBinding::getFactionByName },
        { "getFactionByStringID", FactionManagerBinding::getFactionByStringID },
        { "getEmptyFaction", FactionManagerBinding::getEmptyFaction },
        { "setupAndLinkAllFactions", FactionManagerBinding::setupAndLinkAllFactions },
        { "getFactionBySquad", FactionManagerBinding::getFactionBySquad },
        { "getCampaignGUIInfos", FactionManagerBinding::getCampaignGUIInfos },
        { "areAnyHostileCampaignsRunning", FactionManagerBinding::areAnyHostileCampaignsRunning },
        { "getNumTempPlatoons", FactionManagerBinding::getNumTempPlatoons },
        { "updateMT", FactionManagerBinding::updateMT },
        { "updateThreaded", FactionManagerBinding::updateThreaded },
        { "_showDebugPlatoonMarkers", FactionManagerBinding::_showDebugPlatoonMarkers },
        { "getAllFactions", FactionManagerBinding::getAllFactions },
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
    //registerGetter(L, "addListMuto", FactionManager_get_addListMuto);
    registerGetter(L, "participants", FactionManager_get_participants);
    registerGetter(L, "toAddList", FactionManager_get_toAddList);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    //registerSetter(L, "addListMuto", FactionManager_set_addListMuto);
    registerSetter(L, "participants", FactionManager_set_participants);
    registerSetter(L, "toAddList", FactionManager_set_toAddList);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, FactionManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua