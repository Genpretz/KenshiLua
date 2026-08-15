#include "pch.h"
#include "kenshi\Faction.h"
#include "FactionBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/FactionLeaderBinding.h"
#include "Bindings/FactionRelationsBinding.h"
#include "Bindings/FactionUniqueSquadManagerBinding.h"
#include "Bindings/FactionWarMgrBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/OwnershipsBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/PlayerInterfaceBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/TradeCultureBinding.h"
#include "Bindings/FitnessSelectorBinding.h"
#include "Bindings/BuildingSwapsBinding.h"
#include "Bindings/Faction_CharacteristicsDataBinding.h"
#include "Bindings/Util/LektorBinding.h"

namespace KenshiLua
{

static Faction* getInstance(lua_State* L, int idx)
{
    return checkObject<Faction>(L, idx, FactionBinding::getMetatableName());
}

// --- Getters for Faction ---
static int Faction_get__antiSlavery(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushboolean(L, instance->_antiSlavery ? 1 : 0);
    return 1;
}

static int Faction_get_characteristicsData(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<Faction::CharacteristicsData>(L, &instance->characteristicsData, Faction_CharacteristicsDataBinding::getMetatableName());
}

static int Faction_get_fundamentalNPCType(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushinteger(L, (lua_Integer)instance->fundamentalNPCType);
    return 1;
}

static int Faction_get_ranks(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<lektor<std::string>>(L, &instance->ranks, LektorStringBinding<std::string>::metaName);
}

static int Faction_get_allowSlavesWeapons(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushboolean(L, instance->allowSlavesWeapons ? 1 : 0);
    return 1;
}

static int Faction_get_myLawEnforcementFaction(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<Faction>(L, instance->myLawEnforcementFaction, FactionBinding::getMetatableName());
}

static int Faction_get_isALawEnforcementFaction(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushboolean(L, instance->isALawEnforcementFaction ? 1 : 0);
    return 1;
}

static int Faction_get_factionLeader(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<FactionLeader>(L, &instance->factionLeader, FactionLeaderBinding::getMetatableName());
}

static int Faction_get_diplomatMgr(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<FactionUniqueSquadManager>(L, instance->diplomatMgr, FactionUniqueSquadManagerBinding::getMetatableName());
}

static int Faction_get_relations(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<FactionRelations>(L, instance->relations, FactionRelationsBinding::getMetatableName());
}

static int Faction_get_factionOwnerships(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<Ownerships>(L, instance->factionOwnerships, OwnershipsBinding::getMetatableName());
}

static int Faction_get_warMgr(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<FactionWarMgr>(L, instance->warMgr, FactionWarMgrBinding::getMetatableName());
}

static int Faction_get_tradeCulture(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<TradeCulture>(L, &instance->tradeCulture, TradeCultureBinding::getMetatableName());
}

static int Faction_get_raceSelector(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<FitnessSelector<GameData*>>(L, &instance->raceSelector, FitnessSelectorBinding<GameData*>::metaName);
}

static int Faction_get_name(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int Faction_get_notARealFaction(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushboolean(L, instance->notARealFaction ? 1 : 0);
    return 1;
}

static int Faction_get_roadPreference(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushnumber(L, instance->roadPreference);
    return 1;
}

static int Faction_get_platoonKillList(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<lektor<Platoon*>>(L, &instance->platoonKillList, LektorPtrBinding<Platoon*>::metaName);
}

static int Faction_get_platoonRemoveList(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<lektor<Platoon*>>(L, &instance->platoonRemoveList, LektorPtrBinding<Platoon*>::metaName);
}

static int Faction_get_activePlatoons(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<lektor<Platoon*>>(L, &instance->activePlatoons, LektorPtrBinding<Platoon*>::metaName);
}

static int Faction_get_unloadedPlatoons(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<lektor<Platoon*>>(L, &instance->unloadedPlatoons, LektorPtrBinding<Platoon*>::metaName);
}

static int Faction_get_periodicUpdateCounter_active(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushinteger(L, instance->periodicUpdateCounter_active);
    return 1;
}

static int Faction_get_periodicUpdateCounter_unloaded(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushinteger(L, instance->periodicUpdateCounter_unloaded);
    return 1;
}

static int Faction_get_data(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<GameData>(L, instance->data, GameDataBinding::getMetatableName());
}

static int Faction_get_isAI(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushlightuserdata(L, (void*)instance->isAI);
    return 1;
}

static int Faction_get_isPlayer(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<PlayerInterface>(L, instance->isPlayer, PlayerInterfaceBinding::getMetatableName());
}

static int Faction_get_spawnTimeStamp(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushinteger(L, instance->spawnTimeStamp);
    return 1;
}

static int Faction_get_diplomatTimeStamp(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushinteger(L, instance->diplomatTimeStamp);
    return 1;
}

static int Faction_get_platoonIDs(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushinteger(L, instance->platoonIDs);
    return 1;
}

static int Faction_get_p_TIME(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushnumber(L, instance->p_TIME);
    return 1;
}

static int Faction_get_platoonPeriodicUpdateIndex(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lua_pushinteger(L, instance->platoonPeriodicUpdateIndex);
    return 1;
}

static int Faction_get_buildingSwaps(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    return pushObject<lektor<Faction::BuildingSwaps>>(L, &instance->buildingSwaps, LektorValueBinding<Faction::BuildingSwaps>::metaName);
}

// --- Setters for Faction ---
static int Faction_set__antiSlavery(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->_antiSlavery = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Faction_set_characteristicsData(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    Faction::CharacteristicsData* val = checkObject<Faction::CharacteristicsData>(L, 2, Faction_CharacteristicsDataBinding::getMetatableName());
    if (!val) return luaL_error(L, "Faction::set_characteristicsData: expected Faction_CharacteristicsData for argument 2");
    instance->characteristicsData = *val;
    return 0;
}

static int Faction_set_fundamentalNPCType(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->fundamentalNPCType = (CharacterTypeEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int Faction_set_ranks(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lektor<std::string>* val = LektorStringBinding<std::string>::get(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<string> object");
    instance->ranks = *val;
    return 0;
}

static int Faction_set_allowSlavesWeapons(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->allowSlavesWeapons = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Faction_set_myLawEnforcementFaction(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->myLawEnforcementFaction = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int Faction_set_isALawEnforcementFaction(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->isALawEnforcementFaction = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Faction_set_factionLeader(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->factionLeader = *checkObject<FactionLeader>(L, 2, FactionLeaderBinding::getMetatableName());
    return 0;
}

static int Faction_set_diplomatMgr(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->diplomatMgr = lua_isnoneornil(L, 2) ? nullptr : checkObject<FactionUniqueSquadManager>(L, 2, FactionUniqueSquadManagerBinding::getMetatableName());
    return 0;
}

static int Faction_set_relations(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->relations = lua_isnoneornil(L, 2) ? nullptr : checkObject<FactionRelations>(L, 2, FactionRelationsBinding::getMetatableName());
    return 0;
}

static int Faction_set_factionOwnerships(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->factionOwnerships = lua_isnoneornil(L, 2) ? nullptr : checkObject<Ownerships>(L, 2, OwnershipsBinding::getMetatableName());
    return 0;
}

static int Faction_set_warMgr(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->warMgr = lua_isnoneornil(L, 2) ? nullptr : checkObject<FactionWarMgr>(L, 2, FactionWarMgrBinding::getMetatableName());
    return 0;
}

static int Faction_set_tradeCulture(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->tradeCulture = *checkObject<TradeCulture>(L, 2, TradeCultureBinding::getMetatableName());
    return 0;
}

static int Faction_set_raceSelector(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    FitnessSelector<GameData*>* val = FitnessSelectorBinding<GameData*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected FitnessSelector<GameData*>");
    instance->raceSelector = *val;
    return 0;
}


static int Faction_set_name(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

static int Faction_set_notARealFaction(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->notARealFaction = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Faction_set_roadPreference(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->roadPreference = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Faction_set_platoonKillList(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lektor<Platoon*>* val = LektorPtrBinding<Platoon*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<Platoon*>");
    instance->platoonKillList = *val;
    return 0;
}

static int Faction_set_platoonRemoveList(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lektor<Platoon*>* val = LektorPtrBinding<Platoon*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<Platoon*>");
    instance->platoonRemoveList = *val;
    return 0;
}

static int Faction_set_activePlatoons(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lektor<Platoon*>* val = LektorPtrBinding<Platoon*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<Platoon*>");
    instance->activePlatoons = *val;
    return 0;
}

static int Faction_set_unloadedPlatoons(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lektor<Platoon*>* val = LektorPtrBinding<Platoon*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<Platoon*>");
    instance->unloadedPlatoons = *val;
    return 0;
}

static int Faction_set_periodicUpdateCounter_active(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->periodicUpdateCounter_active = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Faction_set_periodicUpdateCounter_unloaded(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->periodicUpdateCounter_unloaded = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Faction_set_data(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int Faction_set_isAI(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->isAI = (AIPlayer*)lua_touserdata(L, 2);
    return 0;
}

static int Faction_set_isPlayer(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->isPlayer = lua_isnoneornil(L, 2) ? nullptr : checkObject<PlayerInterface>(L, 2, PlayerInterfaceBinding::getMetatableName());
    return 0;
}

static int Faction_set_spawnTimeStamp(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->spawnTimeStamp = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Faction_set_diplomatTimeStamp(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->diplomatTimeStamp = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Faction_set_platoonIDs(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->platoonIDs = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Faction_set_p_TIME(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->p_TIME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Faction_set_platoonPeriodicUpdateIndex(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    instance->platoonPeriodicUpdateIndex = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Faction_set_buildingSwaps(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");
    lektor<Faction::BuildingSwaps>* val = LektorValueBinding<Faction::BuildingSwaps>::get(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<BuildingSwaps>");
    instance->buildingSwaps = *val;
    return 0;
}

int FactionBinding::_CONSTRUCTOR(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    const std::string _name = luaL_checkstring(L, 2);
    Faction* result = instance->_CONSTRUCTOR(_name);
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int FactionBinding::_DESTRUCTOR(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int FactionBinding::getProsperityMultiplier(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    float result = instance->getProsperityMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int FactionBinding::clearAndDestroy(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    instance->clearAndDestroy();
    return 0;
}

int FactionBinding::setup(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameData* _data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->setup(_data);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::setup2(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    bool result = instance->setup2();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::setup3(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    instance->setup3();
    return 0;
}

int FactionBinding::getNewPlatoonID(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    std::string result = instance->getNewPlatoonID();
    lua_pushstring(L, result.c_str());
    return 1;
}

int FactionBinding::resetPlatoonID(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    instance->resetPlatoonID();
    return 0;
}

int FactionBinding::createNewEmptyUnloadedPlatoon(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameData* squadTemplate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    GameDataContainer* forcecharacterDatas = checkObject<GameDataContainer>(L, 4, GameDataContainerBinding::getMetatableName());
    bool persistent = lua_toboolean(L, 5) != 0;
    Platoon* result = instance->createNewEmptyUnloadedPlatoon(squadTemplate, pos, forcecharacterDatas, persistent);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int FactionBinding::createNewEmptyActivePlatoon(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameData* squadTemplate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool permanent = lua_toboolean(L, 3) != 0;
    Ogre::Vector3 p;
    readVector3(L, 4, p);
    Platoon* result = instance->createNewEmptyActivePlatoon(squadTemplate, permanent, p);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int FactionBinding::createPlatoonUnloaded(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameData* platoonstate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameDataContainer* charactersState = checkObject<GameDataContainer>(L, 3, GameDataContainerBinding::getMetatableName());
    GameData* squadTemplate = checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 5, pos);
    bool persistent = lua_toboolean(L, 6) != 0;
    instance->createPlatoonUnloaded(platoonstate, charactersState, squadTemplate, pos, persistent);
    return 0;
}

int FactionBinding::createPlatoonAuto(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameData* platoonstate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* squadTemplate = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 4, pos);
    instance->createPlatoonAuto(platoonstate, squadTemplate, pos);
    return 0;
}

int FactionBinding::createPlatoonsAuto(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    lektor<GameData*>* platoons = LektorPtrBinding<GameData*>::get(L, 2);
    if (!platoons) return luaL_error(L, "platoons is nil");
    instance->createPlatoonsAuto(*platoons);
    return 0;
}

int FactionBinding::createReplacementPlatoonForPlayerWhenSavegameIsCorrupt(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    const std::string src = luaL_checkstring(L, 2);
    instance->createReplacementPlatoonForPlayerWhenSavegameIsCorrupt(src);
    return 0;
}

int FactionBinding::restorePlatoon(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    Platoon* p = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->restorePlatoon(p);
    return 0;
}

int FactionBinding::resetSquadPositions(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    Ogre::Vector3 target;
    readVector3(L, 2, target);
    bool result = instance->resetSquadPositions(target);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::countPopulation(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    TownBase* t = checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    int result = instance->countPopulation(t);
    lua_pushinteger(L, result);
    return 1;
}

int FactionBinding::countNumSquads(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameData* squadTemplate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    TownBase* squadHome = checkObject<TownBase>(L, 3, TownBaseBinding::getMetatableName());
    int result = instance->countNumSquads(squadTemplate, squadHome);
    lua_pushinteger(L, result);
    return 1;
}

int FactionBinding::destroyPlatoon(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    Platoon* platoon = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->destroyPlatoon(platoon);
    return 0;
}

int FactionBinding::removePlatoon(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    Platoon* platoon = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->removePlatoon(platoon);
    return 0;
}

int FactionBinding::getRandomLockLevel(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameData* objData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int result = instance->getRandomLockLevel(objData);
    lua_pushinteger(L, result);
    return 1;
}

int FactionBinding::getData(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameData* result = instance->getData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int FactionBinding::getGUIData(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(panel, category);
    return 0;
}

int FactionBinding::getDefaultDivision(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameData* result = instance->getDefaultDivision();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int FactionBinding::getFactionColorScheme(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameData* result = instance->getFactionColorScheme();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int FactionBinding::loadState(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameDataContainer* saveSource = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* gamestate_faction = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->loadState(saveSource, gamestate_faction);
    return 0;
}

int FactionBinding::saveState(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    bool leveleditor = lua_toboolean(L, 3) != 0;
    GameData* result = instance->saveState(container, leveleditor);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int FactionBinding::_activateUnloadedPlatoons(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    instance->_activateUnloadedPlatoons();
    return 0;
}

int FactionBinding::getCharactersInArea(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "out is nil");
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    float radius = (float)luaL_checknumber(L, 4);
    bool standingOnly = lua_toboolean(L, 5) != 0;
    instance->getCharactersInArea(*out, pos, radius, standingOnly);
    return 0;
}

int FactionBinding::_NV_getCharactersInArea(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "out is nil");
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    float radius = (float)luaL_checknumber(L, 4);
    bool standingOnly = lua_toboolean(L, 5) != 0;
    instance->_NV_getCharactersInArea(*out, pos, radius, standingOnly);
    return 0;
}

int FactionBinding::getSelectedObjects(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "out is nil");
    itemType type = (itemType)luaL_checkinteger(L, 3);
    bool selectedOnly = lua_toboolean(L, 4) != 0;
    instance->getSelectedObjects(*out, type, selectedOnly);
    return 0;
}

int FactionBinding::_NV_getSelectedObjects(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "out is nil");
    itemType type = (itemType)luaL_checkinteger(L, 3);
    bool selectedOnly = lua_toboolean(L, 4) != 0;
    instance->_NV_getSelectedObjects(*out, type, selectedOnly);
    return 0;
}

int FactionBinding::removeObject(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->removeObject(c);
    return 0;
}

int FactionBinding::_NV_removeObject(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->_NV_removeObject(c);
    return 0;
}

int FactionBinding::destroyObject(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->destroyObject(c);
    return 0;
}

int FactionBinding::_NV_destroyObject(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->_NV_destroyObject(c);
    return 0;
}

int FactionBinding::processKillList(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    instance->processKillList();
    return 0;
}

int FactionBinding::_NV_processKillList(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    instance->_NV_processKillList();
    return 0;
}

int FactionBinding::addActiveObject(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    ActivePlatoon* p = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    bool result = instance->addActiveObject(c, p);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::_NV_addActiveObject(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    ActivePlatoon* p = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    bool result = instance->_NV_addActiveObject(c, p);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::choosePlatoon(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    ActivePlatoon* result = instance->choosePlatoon();
    return pushObject<ActivePlatoon>(L, result, ActivePlatoonBinding::getMetatableName());
}

int FactionBinding::getActivePlatoons(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    const lektor<Platoon*>* result = instance->getActivePlatoons();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<lektor<Platoon*>>(L, const_cast<lektor<Platoon*>*>(result), LektorPtrBinding<Platoon*>::metaName);
}

int FactionBinding::getUnloadedPlatoons(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    const lektor<Platoon*>* result = instance->getUnloadedPlatoons();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<lektor<Platoon*>>(L, const_cast<lektor<Platoon*>*>(result), LektorPtrBinding<Platoon*>::metaName);
}

int FactionBinding::getFactionSize(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    int result = instance->getFactionSize();
    lua_pushinteger(L, result);
    return 1;
}

int FactionBinding::update(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->update(time);
    return 0;
}

int FactionBinding::periodicUpdateThreaded(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    bool result = instance->periodicUpdateThreaded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::periodicUpdateMT(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    bool result = instance->periodicUpdateMT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::isThePlayer(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    bool result = instance->isThePlayer();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::isNotARealFaction(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    bool result = instance->isNotARealFaction();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::getName(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    const std::string& result = instance->getName();
    lua_pushlstring(L, result.c_str(), result.length());
    return 1;
}

int FactionBinding::getNumPlatoons(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameData* squadTemplate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool tempsOnly = lua_toboolean(L, 3) != 0;
    TownBase* hometown = checkObject<TownBase>(L, 4, TownBaseBinding::getMetatableName());
    int result = instance->getNumPlatoons(squadTemplate, tempsOnly, hometown);
    lua_pushinteger(L, result);
    return 1;
}

int FactionBinding::getSquadThatOwns(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    Building* what = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    Platoon* result = instance->getSquadThatOwns(what);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int FactionBinding::getAllSquadsThatOwn(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    lektor<Platoon*>* out = LektorPtrBinding<Platoon*>::get(L, 2);
    if (!out) return luaL_error(L, "out is nil");
    Building* what = checkObject<Building>(L, 3, BuildingBinding::getMetatableName());
    instance->getAllSquadsThatOwn(*out, what);
    return 0;
}

int FactionBinding::getAllActiveSquads(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    const lektor<Platoon*>* result = instance->getAllActiveSquads();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int FactionBinding::getRoadPreference(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    float result = instance->getRoadPreference();
    lua_pushnumber(L, result);
    return 1;
}

int FactionBinding::isAntiSlavery(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    bool result = instance->isAntiSlavery();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::getLawEnforcementFaction(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    Faction* result = instance->getLawEnforcementFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int FactionBinding::chooseARace(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameData* character = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* squadTemplate = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* result = instance->chooseARace(character, squadTemplate);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int FactionBinding::setName(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    const std::string _name = luaL_checkstring(L, 2);
    instance->setName(_name);
    return 0;
}

int FactionBinding::getBuildingReplacement(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    GameData* building = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* result = instance->getBuildingReplacement(building);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int FactionBinding::_switchToUnloadedPlatoon(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    ActivePlatoon* platoon = checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
    instance->_switchToUnloadedPlatoon(platoon);
    return 0;
}

int FactionBinding::_newPlatoon(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    GameData* squadTemplate = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* platoonState = checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 5, pos);
    bool persistent = lua_toboolean(L, 6) != 0;
    Platoon* result = instance->_newPlatoon(f, squadTemplate, platoonState, pos, persistent);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int FactionBinding::_addActivePlatoonToList(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    Platoon* platoon = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->_addActivePlatoonToList(platoon);
    return 0;
}

int FactionBinding::addPlatoon(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    Platoon* platoon = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->addPlatoon(platoon);
    return 0;
}

int FactionBinding::changePlatoonIndex(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    Platoon* platoon = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    int index = (int)luaL_checkinteger(L, 3);
    instance->changePlatoonIndex(platoon, index);
    return 0;
}

int FactionBinding::deactivatePlatoon(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    Platoon* p = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->deactivatePlatoon(p);
    return 0;
}

int FactionBinding::activatePlatoon(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    Platoon* p = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->activatePlatoon(p);
    return 0;
}

int FactionBinding::updateUnloadedPlatoons(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->updateUnloadedPlatoons(time);
    return 0;
}

int FactionBinding::updateActivePlatoons(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->updateActivePlatoons(time);
    return 0;
}

int FactionBinding::spawnSquadMissionsUpdate(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    instance->spawnSquadMissionsUpdate();
    return 0;
}

int FactionBinding::_spawnASquad(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    const std::string listname = luaL_checkstring(L, 2);
    float sizeMultiplier = (float)luaL_checknumber(L, 3);
    bool result = instance->_spawnASquad(listname, sizeMultiplier);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::getFundamentalNPCType(lua_State* L)
{
    Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Faction is nil");

    CharacterTypeEnum result = instance->getFundamentalNPCType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - Faction_get_warMgr / Faction_set_warMgr: FactionWarMgr* (unbound pointer)
  - Faction_get_isAI / Faction_set_isAI: AIPlayer* (unbound pointer)
  - Faction_get_characteristicsData / Faction_set_characteristicsData: Faction::CharacteristicsData (unbound struct)
*/

int FactionBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FactionBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Faction object");
    return 1;
}

void FactionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FactionBinding::gc },
        { "__tostring", FactionBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", FactionBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", FactionBinding::_DESTRUCTOR },
        { "getProsperityMultiplier", FactionBinding::getProsperityMultiplier },
        { "clearAndDestroy", FactionBinding::clearAndDestroy },
        { "setup", FactionBinding::setup },
        { "setup2", FactionBinding::setup2 },
        { "setup3", FactionBinding::setup3 },
        { "getNewPlatoonID", FactionBinding::getNewPlatoonID },
        { "resetPlatoonID", FactionBinding::resetPlatoonID },
        { "createNewEmptyUnloadedPlatoon", FactionBinding::createNewEmptyUnloadedPlatoon },
        { "createNewEmptyActivePlatoon", FactionBinding::createNewEmptyActivePlatoon },
        { "createPlatoonUnloaded", FactionBinding::createPlatoonUnloaded },
        { "createPlatoonAuto", FactionBinding::createPlatoonAuto },
        { "createReplacementPlatoonForPlayerWhenSavegameIsCorrupt", FactionBinding::createReplacementPlatoonForPlayerWhenSavegameIsCorrupt },
        { "restorePlatoon", FactionBinding::restorePlatoon },
        { "resetSquadPositions", FactionBinding::resetSquadPositions },
        { "countPopulation", FactionBinding::countPopulation },
        { "countNumSquads", FactionBinding::countNumSquads },
        { "destroyPlatoon", FactionBinding::destroyPlatoon },
        { "removePlatoon", FactionBinding::removePlatoon },
        { "getRandomLockLevel", FactionBinding::getRandomLockLevel },
        { "getData", FactionBinding::getData },
        { "getGUIData", FactionBinding::getGUIData },
        { "getDefaultDivision", FactionBinding::getDefaultDivision },
        { "getFactionColorScheme", FactionBinding::getFactionColorScheme },
        { "loadState", FactionBinding::loadState },
        { "saveState", FactionBinding::saveState },
        { "_activateUnloadedPlatoons", FactionBinding::_activateUnloadedPlatoons },
        { "getCharactersInArea", FactionBinding::getCharactersInArea },
        { "_NV_getCharactersInArea", FactionBinding::_NV_getCharactersInArea },
        { "getSelectedObjects", FactionBinding::getSelectedObjects },
        { "_NV_getSelectedObjects", FactionBinding::_NV_getSelectedObjects },
        { "removeObject", FactionBinding::removeObject },
        { "_NV_removeObject", FactionBinding::_NV_removeObject },
        { "destroyObject", FactionBinding::destroyObject },
        { "_NV_destroyObject", FactionBinding::_NV_destroyObject },
        { "processKillList", FactionBinding::processKillList },
        { "_NV_processKillList", FactionBinding::_NV_processKillList },
        { "addActiveObject", FactionBinding::addActiveObject },
        { "_NV_addActiveObject", FactionBinding::_NV_addActiveObject },
        { "choosePlatoon", FactionBinding::choosePlatoon },
        { "getActivePlatoons", FactionBinding::getActivePlatoons },
        { "getUnloadedPlatoons", FactionBinding::getUnloadedPlatoons },
        { "getFactionSize", FactionBinding::getFactionSize },
        { "update", FactionBinding::update },
        { "periodicUpdateThreaded", FactionBinding::periodicUpdateThreaded },
        { "periodicUpdateMT", FactionBinding::periodicUpdateMT },
        { "isThePlayer", FactionBinding::isThePlayer },
        { "isNotARealFaction", FactionBinding::isNotARealFaction },
        { "getName", FactionBinding::getName },
        { "getNumPlatoons", FactionBinding::getNumPlatoons },
        { "getSquadThatOwns", FactionBinding::getSquadThatOwns },
        { "getAllActiveSquads", FactionBinding::getAllActiveSquads },
        { "getRoadPreference", FactionBinding::getRoadPreference },
        { "isAntiSlavery", FactionBinding::isAntiSlavery },
        { "getLawEnforcementFaction", FactionBinding::getLawEnforcementFaction },
        { "chooseARace", FactionBinding::chooseARace },
        { "setName", FactionBinding::setName },
        { "getBuildingReplacement", FactionBinding::getBuildingReplacement },
        { "_switchToUnloadedPlatoon", FactionBinding::_switchToUnloadedPlatoon },
        { "_newPlatoon", FactionBinding::_newPlatoon },
        { "_addActivePlatoonToList", FactionBinding::_addActivePlatoonToList },
        { "addPlatoon", FactionBinding::addPlatoon },
        { "changePlatoonIndex", FactionBinding::changePlatoonIndex },
        { "deactivatePlatoon", FactionBinding::deactivatePlatoon },
        { "activatePlatoon", FactionBinding::activatePlatoon },
        { "updateUnloadedPlatoons", FactionBinding::updateUnloadedPlatoons },
        { "updateActivePlatoons", FactionBinding::updateActivePlatoons },
        { "spawnSquadMissionsUpdate", FactionBinding::spawnSquadMissionsUpdate },
        { "_spawnASquad", FactionBinding::_spawnASquad },
        { "getFundamentalNPCType", FactionBinding::getFundamentalNPCType },
        { 0, 0 }
    };

    registerClass(
        L, 
        FactionBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FactionBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "_antiSlavery", Faction_get__antiSlavery);
    registerGetter(L, "characteristicsData", Faction_get_characteristicsData);
    registerGetter(L, "ranks", Faction_get_ranks);
    registerGetter(L, "allowSlavesWeapons", Faction_get_allowSlavesWeapons);
    registerGetter(L,"fundamentalNPCType", Faction_get_fundamentalNPCType);
    registerGetter(L, "myLawEnforcementFaction", Faction_get_myLawEnforcementFaction);
    registerGetter(L, "isALawEnforcementFaction", Faction_get_isALawEnforcementFaction);
    registerGetter(L, "factionLeader", Faction_get_factionLeader);
    registerGetter(L, "diplomatMgr", Faction_get_diplomatMgr);
    registerGetter(L, "relations", Faction_get_relations);
    registerGetter(L, "factionOwnerships", Faction_get_factionOwnerships);
    registerGetter(L, "warMgr", Faction_get_warMgr);
    registerGetter(L, "tradeCulture", Faction_get_tradeCulture);
    registerGetter(L, "raceSelector", Faction_get_raceSelector);
    registerGetter(L, "name", Faction_get_name);
    registerGetter(L, "notARealFaction", Faction_get_notARealFaction);
    registerGetter(L, "roadPreference", Faction_get_roadPreference);
    registerGetter(L, "platoonKillList", Faction_get_platoonKillList);
    registerGetter(L, "platoonRemoveList", Faction_get_platoonRemoveList);
    registerGetter(L, "activePlatoons", Faction_get_activePlatoons);
    registerGetter(L, "unloadedPlatoons", Faction_get_unloadedPlatoons);
    registerGetter(L, "periodicUpdateCounter_active", Faction_get_periodicUpdateCounter_active);
    registerGetter(L, "periodicUpdateCounter_unloaded", Faction_get_periodicUpdateCounter_unloaded);
    registerGetter(L, "data", Faction_get_data);
    registerGetter(L, "isAI", Faction_get_isAI);
    registerGetter(L, "isPlayer", Faction_get_isPlayer);
    registerGetter(L, "spawnTimeStamp", Faction_get_spawnTimeStamp);
    registerGetter(L, "diplomatTimeStamp", Faction_get_diplomatTimeStamp);
    registerGetter(L, "platoonIDs", Faction_get_platoonIDs);
    registerGetter(L, "p_TIME", Faction_get_p_TIME);
    registerGetter(L, "platoonPeriodicUpdateIndex", Faction_get_platoonPeriodicUpdateIndex);
    registerGetter(L, "buildingSwaps", Faction_get_buildingSwaps);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "_antiSlavery", Faction_set__antiSlavery);
    registerSetter(L, "characteristicsData", Faction_set_characteristicsData);
    registerSetter(L, "ranks", Faction_set_ranks);
    registerSetter(L, "allowSlavesWeapons", Faction_set_allowSlavesWeapons);
    registerSetter(L,"fundamentalNPCType", Faction_set_fundamentalNPCType);
    registerSetter(L, "myLawEnforcementFaction", Faction_set_myLawEnforcementFaction);
    registerSetter(L, "isALawEnforcementFaction", Faction_set_isALawEnforcementFaction);
    registerSetter(L, "factionLeader", Faction_set_factionLeader);
    registerSetter(L, "diplomatMgr", Faction_set_diplomatMgr);
    registerSetter(L, "relations", Faction_set_relations);
    registerSetter(L, "factionOwnerships", Faction_set_factionOwnerships);
    registerSetter(L, "warMgr", Faction_set_warMgr);
    registerSetter(L, "tradeCulture", Faction_set_tradeCulture);
    registerSetter(L, "raceSelector", Faction_set_raceSelector);
    registerSetter(L, "name", Faction_set_name);
    registerSetter(L, "notARealFaction", Faction_set_notARealFaction);
    registerSetter(L, "roadPreference", Faction_set_roadPreference);
    registerSetter(L, "platoonKillList", Faction_set_platoonKillList);
    registerSetter(L, "platoonRemoveList", Faction_set_platoonRemoveList);
    registerSetter(L, "activePlatoons", Faction_set_activePlatoons);
    registerSetter(L, "unloadedPlatoons", Faction_set_unloadedPlatoons);
    registerSetter(L, "periodicUpdateCounter_active", Faction_set_periodicUpdateCounter_active);
    registerSetter(L, "periodicUpdateCounter_unloaded", Faction_set_periodicUpdateCounter_unloaded);
    registerSetter(L, "data", Faction_set_data);
    registerSetter(L, "isAI", Faction_set_isAI);
    registerSetter(L, "isPlayer", Faction_set_isPlayer);
    registerSetter(L, "spawnTimeStamp", Faction_set_spawnTimeStamp);
    registerSetter(L, "diplomatTimeStamp", Faction_set_diplomatTimeStamp);
    registerSetter(L, "platoonIDs", Faction_set_platoonIDs);
    registerSetter(L, "p_TIME", Faction_set_p_TIME);
    registerSetter(L, "platoonPeriodicUpdateIndex", Faction_set_platoonPeriodicUpdateIndex);
    registerSetter(L, "buildingSwaps", Faction_set_buildingSwaps);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, FactionBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua