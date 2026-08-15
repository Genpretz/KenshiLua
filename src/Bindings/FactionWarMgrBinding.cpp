#include "pch.h"
#include "kenshi\FactionWarMgr.h"
#include "FactionWarMgrBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/FitnessSelectorBinding.h"
#include "Bindings/CampaignTriggerDataBinding.h"
#include "Bindings/Util/LektorBinding.h"

namespace KenshiLua
{

static FactionWarMgr* getInstance(lua_State* L, int idx)
{
    return checkObject<FactionWarMgr>(L, idx, FactionWarMgrBinding::getMetatableName());
}

// --- Getters for FactionWarMgr ---
static int FactionWarMgr_get_me(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    return pushObject<Faction>(L, instance->me, FactionBinding::getMetatableName());
}

static int FactionWarMgr_get_lastID(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    lua_pushinteger(L, instance->lastID);
    return 1;
}

static int FactionWarMgr_get_nextUpdateTime(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    return pushObject<TimeOfDay>(L, &instance->nextUpdateTime, TimeOfDayBinding::getMetatableName());
}

static int FactionWarMgr_get_myTowns(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    return pushObject<lektor<TownBase*>>(L, &instance->myTowns, LektorPtrBinding<TownBase*>::metaName);
}

static int FactionWarMgr_get_hiredForces(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    return pushObject<lektor<hand>>(L, &instance->hiredForces, LektorValueReadOnlyBinding<hand>::metaName);
}

static int FactionWarMgr_get_activeCampaigns(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    lua_pushlightuserdata(L, (void*)&instance->activeCampaigns);
    return 1;
}

static int FactionWarMgr_get_biomeTerritories(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    lua_pushlightuserdata(L, (void*)&instance->biomeTerritories);
    return 1;
}

static int FactionWarMgr_get_biomeNoGoZones(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    lua_pushlightuserdata(L, (void*)&instance->biomeNoGoZones);
    return 1;
}

static int FactionWarMgr_get_campaignRequests(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    lua_pushlightuserdata(L, (void*)&instance->campaignRequests);
    return 1;
}

static int FactionWarMgr_get_possibleCampaigns(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    lua_pushlightuserdata(L, (void*)&instance->possibleCampaigns);
    return 1;
}

static int FactionWarMgr_get_forces(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    lua_pushlightuserdata(L, (void*)&instance->forces);
    return 1;
}

// --- Setters for FactionWarMgr ---
static int FactionWarMgr_set_me(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int FactionWarMgr_set_lastID(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    instance->lastID = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int FactionWarMgr_set_nextUpdateTime(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    instance->nextUpdateTime = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int FactionWarMgr_set_myTowns(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    lektor<TownBase*>* val = LektorPtrBinding<TownBase*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<TownBase*>");
    instance->myTowns = *val;
    return 0;
}

static int FactionWarMgr_set_hiredForces(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    lektor<hand>* val = checkObject<lektor<hand>>(L, 2, LektorValueReadOnlyBinding<hand>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<hand>");
    instance->hiredForces = *val;
    return 0;
}

static int FactionWarMgr_set_activeCampaigns(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    lektor<CampaignInstance*>* val = (lektor<CampaignInstance*>*)lua_touserdata(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<CampaignInstance*> lightuserdata");
    instance->activeCampaigns = *val;
    return 0;
}

static int FactionWarMgr_set_biomeTerritories(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    lektor<AreaBiomeGroup*>* val = (lektor<AreaBiomeGroup*>*)lua_touserdata(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<AreaBiomeGroup*> lightuserdata");
    instance->biomeTerritories = *val;
    return 0;
}

static int FactionWarMgr_set_biomeNoGoZones(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    lektor<AreaBiomeGroup*>* val = (lektor<AreaBiomeGroup*>*)lua_touserdata(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<AreaBiomeGroup*> lightuserdata");
    instance->biomeNoGoZones = *val;
    return 0;
}

static int FactionWarMgr_set_campaignRequests(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    lektor<FactionWarMgr::CampaignRequest*>* val = (lektor<FactionWarMgr::CampaignRequest*>*)lua_touserdata(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<CampaignRequest*> lightuserdata");
    instance->campaignRequests = *val;
    return 0;
}

static int FactionWarMgr_set_possibleCampaigns(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    lektor<CampaignData*>* val = (lektor<CampaignData*>*)lua_touserdata(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<CampaignData*> lightuserdata");
    instance->possibleCampaigns = *val;
    return 0;
}

static int FactionWarMgr_set_forces(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");
    typedef std::map<Platoon*, CampaignInstance*, std::less<Platoon*>, Ogre::STLAllocator<std::pair<Platoon* const, CampaignInstance*>, Ogre::GeneralAllocPolicy > > MapType;
    MapType* val = (MapType*)lua_touserdata(L, 2);
    if (!val) return luaL_error(L, "Expected map lightuserdata");
    instance->forces = *val;
    return 0;
}

int FactionWarMgrBinding::reset(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    instance->reset();
    return 0;
}

int FactionWarMgrBinding::save(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    GameData* s = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->save(s);
    return 0;
}

int FactionWarMgrBinding::load(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    GameData* s = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->load(s);
    return 0;
}

int FactionWarMgrBinding::removePlatoon(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    Platoon* p = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->removePlatoon(p);
    return 0;
}

int FactionWarMgrBinding::addPlatoon(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    Platoon* p = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->addPlatoon(p);
    return 0;
}

int FactionWarMgrBinding::getGUIData(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int cat = (int)luaL_checkinteger(L, 3);
    bool playeronly = lua_toboolean(L, 4) != 0;
    instance->getGUIData(panel, cat, playeronly);
    return 0;
}

int FactionWarMgrBinding::areAnyHostileCampaignsRunning(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    bool playeronly = lua_toboolean(L, 2) != 0;
    bool result = instance->areAnyHostileCampaignsRunning(playeronly);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionWarMgrBinding::endCampaign(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    CampaignInstance* c = (CampaignInstance*)lua_touserdata(L, 2);
    instance->endCampaign(c);
    return 0;
}

int FactionWarMgrBinding::getAllTheForces(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    RootObjectBase* target = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    CampaignInstance* c = (CampaignInstance*)lua_touserdata(L, 3);
    instance->getAllTheForces(target, c);
    return 0;
}

int FactionWarMgrBinding::_generateForcesForTown(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    TownBase* t = checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    CampaignInstance* c = (CampaignInstance*)lua_touserdata(L, 3);
    instance->_generateForcesForTown(t, c);
    return 0;
}

int FactionWarMgrBinding::canGenerateThisManyForces(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    int num = (int)luaL_checkinteger(L, 2);
    bool result = instance->canGenerateThisManyForces(num);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionWarMgrBinding::periodicUpdate(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    instance->periodicUpdate();
    return 0;
}

int FactionWarMgrBinding::debugButton(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    instance->debugButton();
    return 0;
}

int FactionWarMgrBinding::triggerCampaign(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    int top = lua_gettop(L);
    if (top == 4)
    {
        RootObjectBase* targetTown = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
        CampaignData* data = (CampaignData*)lua_touserdata(L, 3);
        TownBase* home = checkObject<TownBase>(L, 4, TownBaseBinding::getMetatableName());
        CampaignInstance* result = instance->triggerCampaign(targetTown, data, home);
        lua_pushlightuserdata(L, (void*)result);
        return 1;
    }
    else if (top == 8)
    {
        RootObjectBase* targetTown = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
        GameData* _data = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
        float minTime = (float)luaL_checknumber(L, 4);
        float maxTime = (float)luaL_checknumber(L, 5);
        TownBase* hometown = checkObject<TownBase>(L, 6, TownBaseBinding::getMetatableName());
        bool forceDuplicate = lua_toboolean(L, 7) != 0;
        Faction* triggeringFaction = checkObject<Faction>(L, 8, FactionBinding::getMetatableName());
        instance->triggerCampaign(targetTown, _data, minTime, maxTime, hometown, forceDuplicate, triggeringFaction);
        return 0;
    }
    else if (top == 6)
    {
        FitnessSelector<CampaignTriggerData*>* randomTriggers = FitnessSelectorBinding<CampaignTriggerData*>::get(L, 2);
        if (!randomTriggers) return luaL_error(L, "Expected FitnessSelector<CampaignTriggerData*>");
        RootObjectBase* targetTown = checkObject<RootObjectBase>(L, 3, RootObjectBaseBinding::getMetatableName());
        TownBase* hometown = checkObject<TownBase>(L, 4, TownBaseBinding::getMetatableName());
        bool forceDuplicate = lua_toboolean(L, 5) != 0;
        Faction* triggeringFaction = checkObject<Faction>(L, 6, FactionBinding::getMetatableName());
        instance->triggerCampaign(*randomTriggers, targetTown, hometown, forceDuplicate, triggeringFaction);
        return 0;
    }
    return luaL_error(L, "Invalid number of arguments for triggerCampaign");
}

int FactionWarMgrBinding::getCurrentCampaign(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    CampaignInstance* result = instance->getCurrentCampaign(who);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int FactionWarMgrBinding::getAITarget(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    hand result = instance->getAITarget(who);
    return HandBinding::push(L, result);
}

int FactionWarMgrBinding::getMyUnloadedAI(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    UnloadedPlatoonJob result = instance->getMyUnloadedAI(who);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int FactionWarMgrBinding::isBiomeHomeTerritory(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    AreaBiomeGroup* area = (AreaBiomeGroup*)lua_touserdata(L, 2);
    bool result = instance->isBiomeHomeTerritory(area);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionWarMgrBinding::getNearestTown(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    TownBase* result = instance->getNearestTown(p);
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int FactionWarMgrBinding::getTownsInBiome(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    lektor<TownBase*>* out = LektorPtrBinding<TownBase*>::get(L, 2);
    if (!out) return luaL_error(L, "out is nil");
    AreaBiomeGroup* b = (AreaBiomeGroup*)lua_touserdata(L, 3);
    instance->getTownsInBiome(*out, b);
    return 0;
}

int FactionWarMgrBinding::getMyTownsWithEnoughFreePopulation(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    lektor<TownBase*>* out = LektorPtrBinding<TownBase*>::get(L, 2);
    if (!out) return luaL_error(L, "out is nil");
    int popNeeded = (int)luaL_checkinteger(L, 3);
    instance->getMyTownsWithEnoughFreePopulation(*out, popNeeded);
    return 0;
}

int FactionWarMgrBinding::getActiveCampaign(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    int uniqueID = (int)luaL_checkinteger(L, 2);
    CampaignInstance* result = instance->getActiveCampaign(uniqueID);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int FactionWarMgrBinding::setup(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    instance->setup();
    return 0;
}

int FactionWarMgrBinding::_createCampaignData(lua_State* L)
{
    FactionWarMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionWarMgr is nil");

    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    CampaignData* result = instance->_createCampaignData(dat);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - FactionWarMgr_get_activeCampaigns / FactionWarMgr_set_activeCampaigns: lektor<CampaignInstance*> (unbound pointer type)
  - FactionWarMgr_get_biomeTerritories / FactionWarMgr_set_biomeTerritories: lektor<AreaBiomeGroup*> (unbound pointer type)
  - FactionWarMgr_get_biomeNoGoZones / FactionWarMgr_set_biomeNoGoZones: lektor<AreaBiomeGroup*> (unbound pointer type)
  - FactionWarMgr_get_campaignRequests / FactionWarMgr_set_campaignRequests: lektor<FactionWarMgr::CampaignRequest*> (unbound pointer type)
  - FactionWarMgr_get_possibleCampaigns / FactionWarMgr_set_possibleCampaigns: lektor<CampaignData*> (unbound pointer type)
  - FactionWarMgr_get_forces / FactionWarMgr_set_forces: std::map<Platoon*, CampaignInstance*> (unbound map type)
*/

int FactionWarMgrBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FactionWarMgrBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FactionWarMgr object");
    return 1;
}

void FactionWarMgrBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FactionWarMgrBinding::gc },
        { "__tostring", FactionWarMgrBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "reset", FactionWarMgrBinding::reset },
        { "save", FactionWarMgrBinding::save },
        { "load", FactionWarMgrBinding::load },
        { "removePlatoon", FactionWarMgrBinding::removePlatoon },
        { "addPlatoon", FactionWarMgrBinding::addPlatoon },
        { "getGUIData", FactionWarMgrBinding::getGUIData },
        { "areAnyHostileCampaignsRunning", FactionWarMgrBinding::areAnyHostileCampaignsRunning },
        { "endCampaign", FactionWarMgrBinding::endCampaign },
        { "getAllTheForces", FactionWarMgrBinding::getAllTheForces },
        { "_generateForcesForTown", FactionWarMgrBinding::_generateForcesForTown },
        { "canGenerateThisManyForces", FactionWarMgrBinding::canGenerateThisManyForces },
        { "periodicUpdate", FactionWarMgrBinding::periodicUpdate },
        { "debugButton", FactionWarMgrBinding::debugButton },
        { "triggerCampaign", FactionWarMgrBinding::triggerCampaign },
        { "getCurrentCampaign", FactionWarMgrBinding::getCurrentCampaign },
        { "getAITarget", FactionWarMgrBinding::getAITarget },
        { "getMyUnloadedAI", FactionWarMgrBinding::getMyUnloadedAI },
        { "isBiomeHomeTerritory", FactionWarMgrBinding::isBiomeHomeTerritory },
        { "getNearestTown", FactionWarMgrBinding::getNearestTown },
        { "getTownsInBiome", FactionWarMgrBinding::getTownsInBiome },
        { "getMyTownsWithEnoughFreePopulation", FactionWarMgrBinding::getMyTownsWithEnoughFreePopulation },
        { "getActiveCampaign", FactionWarMgrBinding::getActiveCampaign },
        { "setup", FactionWarMgrBinding::setup },
        { "_createCampaignData", FactionWarMgrBinding::_createCampaignData },
        { 0, 0 }
    };

    registerClass(
        L, 
        FactionWarMgrBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FactionWarMgrBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, FactionWarMgr_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, FactionWarMgr_get_lastID);
    lua_setfield(L, -2, "lastID");
    lua_pushcfunction(L, FactionWarMgr_get_nextUpdateTime);
    lua_setfield(L, -2, "nextUpdateTime");
    lua_pushcfunction(L, FactionWarMgr_get_myTowns);
    lua_setfield(L, -2, "myTowns");
    lua_pushcfunction(L, FactionWarMgr_get_hiredForces);
    lua_setfield(L, -2, "hiredForces");
    lua_pushcfunction(L, FactionWarMgr_get_activeCampaigns);
    lua_setfield(L, -2, "activeCampaigns");
    lua_pushcfunction(L, FactionWarMgr_get_biomeTerritories);
    lua_setfield(L, -2, "biomeTerritories");
    lua_pushcfunction(L, FactionWarMgr_get_biomeNoGoZones);
    lua_setfield(L, -2, "biomeNoGoZones");
    lua_pushcfunction(L, FactionWarMgr_get_campaignRequests);
    lua_setfield(L, -2, "campaignRequests");
    lua_pushcfunction(L, FactionWarMgr_get_possibleCampaigns);
    lua_setfield(L, -2, "possibleCampaigns");
    lua_pushcfunction(L, FactionWarMgr_get_forces);
    lua_setfield(L, -2, "forces");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FactionWarMgr_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, FactionWarMgr_set_lastID);
    lua_setfield(L, -2, "lastID");
    lua_pushcfunction(L, FactionWarMgr_set_nextUpdateTime);
    lua_setfield(L, -2, "nextUpdateTime");
    lua_pushcfunction(L, FactionWarMgr_set_myTowns);
    lua_setfield(L, -2, "myTowns");
    lua_pushcfunction(L, FactionWarMgr_set_hiredForces);
    lua_setfield(L, -2, "hiredForces");
    lua_pushcfunction(L, FactionWarMgr_set_activeCampaigns);
    lua_setfield(L, -2, "activeCampaigns");
    lua_pushcfunction(L, FactionWarMgr_set_biomeTerritories);
    lua_setfield(L, -2, "biomeTerritories");
    lua_pushcfunction(L, FactionWarMgr_set_biomeNoGoZones);
    lua_setfield(L, -2, "biomeNoGoZones");
    lua_pushcfunction(L, FactionWarMgr_set_campaignRequests);
    lua_setfield(L, -2, "campaignRequests");
    lua_pushcfunction(L, FactionWarMgr_set_possibleCampaigns);
    lua_setfield(L, -2, "possibleCampaigns");
    lua_pushcfunction(L, FactionWarMgr_set_forces);
    lua_setfield(L, -2, "forces");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua