#include "pch.h"
#include "Bindings/TradeCultureBinding.h"

#include "kenshi\Faction.h"
#include "FactionBinding.h"
#include "kenshi/Platoon.h"
#include "OwnershipsBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "kenshi/PlayerInterface.h"
#include "PlayerInterfaceBinding.h"
#include "GameDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/OwnershipsBinding.h"
#include "Bindings/PlayerInterfaceBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/Templates/LektorBinding.h"
#include "Bindings/FactionRelationsBinding.h"
#include "Bindings/TradeCultureBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/RootObjectBinding.h"

namespace KenshiLua
{

static Faction* getB(lua_State* L, int idx)
{
    return checkObject<Faction>(L, idx, FactionBinding::getMetatableName());
}

// --- Getters for Faction ---
static int Faction_get__antiSlavery(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lua_pushboolean(L, b->_antiSlavery ? 1 : 0);
    return 1;
}

static int Faction_get_characteristicsData(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for characteristicsData (Faction::CharacteristicsData)
    return luaL_error(L, "Unsupported property 'characteristicsData' (type: Faction::CharacteristicsData)");
}

static int Faction_get_ranks(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return pushObject<lektor<std::string>>(L, &b->ranks, LektorStringBinding<std::string>::metaName);
}

static int Faction_get_allowSlavesWeapons(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lua_pushboolean(L, b->allowSlavesWeapons ? 1 : 0);
    return 1;
}

static int Faction_get_fundamentalNPCType(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lua_pushinteger(L, (lua_Integer)b->fundamentalNPCType);
    return 1;
}

static int Faction_get_myLawEnforcementFaction(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return pushObject<Faction>(L, b->myLawEnforcementFaction, FactionBinding::getMetatableName());
}

static int Faction_get_isALawEnforcementFaction(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lua_pushboolean(L, b->isALawEnforcementFaction ? 1 : 0);
    return 1;
}

static int Faction_get_factionLeader(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for factionLeader (FactionLeader)
    return luaL_error(L, "Unsupported property 'factionLeader' (type: FactionLeader)");
}

static int Faction_get_diplomatMgr(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for diplomatMgr (FactionUniqueSquadManager*)
    return luaL_error(L, "Unsupported property 'diplomatMgr' (type: FactionUniqueSquadManager*)");
}

static int Faction_get_relations(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return pushObject<FactionRelations>(L, b->relations, FactionRelationsBinding::getMetatableName());
}

static int Faction_get_factionOwnerships(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return pushObject<Ownerships>(L, b->factionOwnerships, OwnershipsBinding::getMetatableName());
}

static int Faction_get_warMgr(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for warMgr (FactionWarMgr*)
    return luaL_error(L, "Unsupported property 'warMgr' (type: FactionWarMgr*)");
}

static int Faction_get_tradeCulture(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return pushObject<TradeCulture>(L, &b->tradeCulture, TradeCultureBinding::getMetatableName());
}

static int Faction_get_raceSelector(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for raceSelector (FitnessSelector<GameData*>)
    return luaL_error(L, "Unsupported property 'raceSelector' (type: FitnessSelector<GameData*>)");
}

static int Faction_get_name(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lua_pushstring(L, b->name.c_str());
    return 1;
}

static int Faction_get_notARealFaction(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lua_pushboolean(L, b->notARealFaction ? 1 : 0);
    return 1;
}

static int Faction_get_roadPreference(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lua_pushnumber(L, b->roadPreference);
    return 1;
}

static int Faction_get_platoonKillList(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return pushObject<lektor<Platoon*>>(L, &b->platoonKillList, LektorPtrBinding<Platoon*>::metaName);
}

static int Faction_get_platoonRemoveList(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return pushObject<lektor<Platoon*>>(L, &b->platoonRemoveList, LektorPtrBinding<Platoon*>::metaName);
}

static int Faction_get_activePlatoons(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return pushObject<lektor<Platoon*>>(L, &b->activePlatoons, LektorPtrBinding<Platoon*>::metaName);
}

static int Faction_get_unloadedPlatoons(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return pushObject<lektor<Platoon*>>(L, &b->unloadedPlatoons, LektorPtrBinding<Platoon*>::metaName);
}

static int Faction_get_periodicUpdateCounter_active(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lua_pushinteger(L, b->periodicUpdateCounter_active);
    return 1;
}

static int Faction_get_periodicUpdateCounter_unloaded(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lua_pushinteger(L, b->periodicUpdateCounter_unloaded);
    return 1;
}

static int Faction_get_data(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return pushObject<GameData>(L, b->data, GameDataBinding::getMetatableName());
}

static int Faction_get_isAI(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for isAI (AIPlayer*)
    return luaL_error(L, "Unsupported property 'isAI' (type: AIPlayer*)");
}

static int Faction_get_isPlayer(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return pushObject<PlayerInterface>(L, b->isPlayer, PlayerInterfaceBinding::getMetatableName());
}

static int Faction_get_spawnTimeStamp(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lua_pushinteger(L, b->spawnTimeStamp);
    return 1;
}

static int Faction_get_diplomatTimeStamp(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lua_pushinteger(L, b->diplomatTimeStamp);
    return 1;
}

static int Faction_get_platoonIDs(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lua_pushinteger(L, b->platoonIDs);
    return 1;
}

static int Faction_get_p_TIME(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lua_pushnumber(L, b->p_TIME);
    return 1;
}

static int Faction_get_platoonPeriodicUpdateIndex(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lua_pushinteger(L, b->platoonPeriodicUpdateIndex);
    return 1;
}

static int Faction_get_buildingSwaps(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for buildingSwaps (lektor<Faction::BuildingSwaps>)
    return luaL_error(L, "Unsupported property 'buildingSwaps' (type: lektor<Faction::BuildingSwaps>)");
}

// --- Setters for Faction ---
static int Faction_set__antiSlavery(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->_antiSlavery = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Faction_set_characteristicsData(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for characteristicsData");
}

static int Faction_set_ranks(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for ranks");
}

static int Faction_set_allowSlavesWeapons(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->allowSlavesWeapons = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Faction_set_fundamentalNPCType(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->fundamentalNPCType = (CharacterTypeEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int Faction_set_myLawEnforcementFaction(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for myLawEnforcementFaction");
}

static int Faction_set_isALawEnforcementFaction(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->isALawEnforcementFaction = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Faction_set_factionLeader(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for factionLeader");
}

static int Faction_set_diplomatMgr(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for diplomatMgr");
}

static int Faction_set_relations(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->relations = lua_isnoneornil(L, 2) ? nullptr : checkObject<FactionRelations>(L, 2, FactionRelationsBinding::getMetatableName());
    return 0;
}

static int Faction_set_factionOwnerships(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for factionOwnerships");
}

static int Faction_set_warMgr(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for warMgr");
}

static int Faction_set_tradeCulture(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    TradeCulture* tc = checkObject<TradeCulture>(L, 2, TradeCultureBinding::getMetatableName());
    if (tc) b->tradeCulture = *tc;
    return 0;
}

static int Faction_set_raceSelector(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for raceSelector");
}

static int Faction_set_name(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->name = luaL_checkstring(L, 2);
    return 0;
}

static int Faction_set_notARealFaction(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->notARealFaction = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Faction_set_roadPreference(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->roadPreference = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Faction_set_platoonKillList(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for platoonKillList");
}

static int Faction_set_platoonRemoveList(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for platoonRemoveList");
}

static int Faction_set_activePlatoons(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for activePlatoons");
}

static int Faction_set_unloadedPlatoons(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for unloadedPlatoons");
}

static int Faction_set_periodicUpdateCounter_active(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->periodicUpdateCounter_active = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Faction_set_periodicUpdateCounter_unloaded(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->periodicUpdateCounter_unloaded = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Faction_set_data(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for data");
}

static int Faction_set_isAI(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isAI");
}

static int Faction_set_isPlayer(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isPlayer");
}

static int Faction_set_spawnTimeStamp(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->spawnTimeStamp = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Faction_set_diplomatTimeStamp(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->diplomatTimeStamp = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Faction_set_platoonIDs(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->platoonIDs = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Faction_set_p_TIME(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->p_TIME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Faction_set_platoonPeriodicUpdateIndex(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    b->platoonPeriodicUpdateIndex = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Faction_set_buildingSwaps(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for buildingSwaps");
}

// --- Methods for Faction ---
int FactionBinding::_CONSTRUCTOR(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    std::string _name = luaL_checkstring(L, 2);
    Faction* result = b->_CONSTRUCTOR(_name);
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int FactionBinding::_DESTRUCTOR(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    b->_DESTRUCTOR();
    return 0;
}

int FactionBinding::getProsperityMultiplier(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    float result = b->getProsperityMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int FactionBinding::clearAndDestroy(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    b->clearAndDestroy();
    return 0;
}

int FactionBinding::setup2(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    bool result = b->setup2();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::setup3(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    b->setup3();
    return 0;
}

int FactionBinding::getNewPlatoonID(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    std::string result = b->getNewPlatoonID();
    lua_pushstring(L, result.c_str());
    return 1;
}

int FactionBinding::resetPlatoonID(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    b->resetPlatoonID();
    return 0;
}

int FactionBinding::createReplacementPlatoonForPlayerWhenSavegameIsCorrupt(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    std::string src = luaL_checkstring(L, 2);
    b->createReplacementPlatoonForPlayerWhenSavegameIsCorrupt(src);
    return 0;
}

int FactionBinding::resetSquadPositions(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    Ogre::Vector3 target;
    readVector3(L, 2, target);
    bool result = b->resetSquadPositions(target);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::getData(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    GameData* result = b->getData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int FactionBinding::getDefaultDivision(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    GameData* result = b->getDefaultDivision();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int FactionBinding::getFactionColorScheme(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    GameData* result = b->getFactionColorScheme();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int FactionBinding::_activateUnloadedPlatoons(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    b->_activateUnloadedPlatoons();
    return 0;
}

int FactionBinding::processKillList(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    b->processKillList();
    return 0;
}

int FactionBinding::_NV_processKillList(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    b->_NV_processKillList();
    return 0;
}

int FactionBinding::getFactionSize(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    int result = b->getFactionSize();
    lua_pushinteger(L, result);
    return 1;
}

int FactionBinding::update(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->update(time);
    return 0;
}

int FactionBinding::periodicUpdateThreaded(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    bool result = b->periodicUpdateThreaded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::periodicUpdateMT(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    bool result = b->periodicUpdateMT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::isThePlayer(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    bool result = b->isThePlayer();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::isNotARealFaction(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    bool result = b->isNotARealFaction();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::getRoadPreference(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    float result = b->getRoadPreference();
    lua_pushnumber(L, result);
    return 1;
}

int FactionBinding::isAntiSlavery(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    bool result = b->isAntiSlavery();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::getLawEnforcementFaction(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    Faction* result = b->getLawEnforcementFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int FactionBinding::setName(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    std::string _name = luaL_checkstring(L, 2);
    b->setName(_name);
    return 0;
}

int FactionBinding::updateUnloadedPlatoons(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->updateUnloadedPlatoons(time);
    return 0;
}

int FactionBinding::updateActivePlatoons(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->updateActivePlatoons(time);
    return 0;
}

int FactionBinding::spawnSquadMissionsUpdate(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    b->spawnSquadMissionsUpdate();
    return 0;
}

int FactionBinding::_spawnASquad(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");

    std::string listname = luaL_checkstring(L, 2);
    float sizeMultiplier = (float)luaL_checknumber(L, 3);
    bool result = b->_spawnASquad(listname, sizeMultiplier);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::getFundamentalNPCType(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    CharacterTypeEnum result = b->getFundamentalNPCType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int FactionBinding::setup(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = b->setup(data);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::createNewEmptyUnloadedPlatoon(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    GameData* squadTemplate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    GameDataContainer* forcecharacterDatas = (GameDataContainer*)lua_touserdata(L, 4);
    bool persistent = lua_toboolean(L, 5) != 0;
    
    Platoon* result = b->createNewEmptyUnloadedPlatoon(squadTemplate, pos, forcecharacterDatas, persistent);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int FactionBinding::createNewEmptyActivePlatoon(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    GameData* squadTemplate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool permanent = lua_toboolean(L, 3) != 0;
    Ogre::Vector3 p;
    readVector3(L, 4, p);
    
    Platoon* result = b->createNewEmptyActivePlatoon(squadTemplate, permanent, p);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int FactionBinding::createPlatoonUnloaded(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    GameData* platoonstate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameDataContainer* charactersState = (GameDataContainer*)lua_touserdata(L, 3);
    GameData* squadTemplate = checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 5, pos);
    bool persistent = lua_toboolean(L, 6) != 0;
    
    b->createPlatoonUnloaded(platoonstate, charactersState, squadTemplate, pos, persistent);
    return 0;
}

int FactionBinding::createPlatoonAuto(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    GameData* platoonstate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* squadTemplate = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 4, pos);
    
    b->createPlatoonAuto(platoonstate, squadTemplate, pos);
    return 0;
}

int FactionBinding::createPlatoonsAuto(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lektor<GameData*>* platoons = LektorPtrBinding<GameData*>::get(L, 2);
    if (!platoons) return luaL_error(L, "platoons is nil");
    b->createPlatoonsAuto(*platoons);
    return 0;
}

int FactionBinding::restorePlatoon(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    Platoon* p = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    b->restorePlatoon(p);
    return 0;
}

int FactionBinding::countPopulation(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    TownBase* t = checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    int result = b->countPopulation(t);
    lua_pushinteger(L, result);
    return 1;
}

int FactionBinding::countNumSquads(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    GameData* squadTemplate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    TownBase* squadHome = checkObject<TownBase>(L, 3, TownBaseBinding::getMetatableName());
    int result = b->countNumSquads(squadTemplate, squadHome);
    lua_pushinteger(L, result);
    return 1;
}

int FactionBinding::destroyPlatoon(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    Platoon* platoon = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    b->destroyPlatoon(platoon);
    return 0;
}

int FactionBinding::removePlatoon(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    Platoon* platoon = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    b->removePlatoon(platoon);
    return 0;
}

int FactionBinding::getRandomLockLevel(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    GameData* objData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int result = b->getRandomLockLevel(objData);
    lua_pushinteger(L, result);
    return 1;
}

int FactionBinding::getGUIData(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    b->getGUIData(panel, category);
    return 0;
}

int FactionBinding::loadState(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    GameDataContainer* saveSource = (GameDataContainer*)lua_touserdata(L, 2);
    GameData* gamestate_faction = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    b->loadState(saveSource, gamestate_faction);
    return 0;
}

int FactionBinding::saveState(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    GameDataContainer* container = (GameDataContainer*)lua_touserdata(L, 2);
    bool leveleditor = lua_toboolean(L, 3) != 0;
    GameData* result = b->saveState(container, leveleditor);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int FactionBinding::getCharactersInArea(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "out is nil");
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    float radius = (float)luaL_checknumber(L, 4);
    bool standingOnly = lua_toboolean(L, 5) != 0;
    b->getCharactersInArea(*out, pos, radius, standingOnly);
    return 0;
}

int FactionBinding::_NV_getCharactersInArea(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "out is nil");
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    float radius = (float)luaL_checknumber(L, 4);
    bool standingOnly = lua_toboolean(L, 5) != 0;
    b->_NV_getCharactersInArea(*out, pos, radius, standingOnly);
    return 0;
}

int FactionBinding::getSelectedObjects(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "out is nil");
    itemType type = (itemType)luaL_checkinteger(L, 3);
    bool selectedOnly = lua_toboolean(L, 4) != 0;
    b->getSelectedObjects(*out, type, selectedOnly);
    return 0;
}

int FactionBinding::_NV_getSelectedObjects(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "out is nil");
    itemType type = (itemType)luaL_checkinteger(L, 3);
    bool selectedOnly = lua_toboolean(L, 4) != 0;
    b->_NV_getSelectedObjects(*out, type, selectedOnly);
    return 0;
}

int FactionBinding::removeObject(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    b->removeObject(c);
    return 0;
}

int FactionBinding::_NV_removeObject(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    b->_NV_removeObject(c);
    return 0;
}

int FactionBinding::destroyObject(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    b->destroyObject(c);
    return 0;
}

int FactionBinding::_NV_destroyObject(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    b->_NV_destroyObject(c);
    return 0;
}

int FactionBinding::addActiveObject(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    ActivePlatoon* p = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    bool result = b->addActiveObject(c, p);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::_NV_addActiveObject(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    ActivePlatoon* p = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    bool result = b->_NV_addActiveObject(c, p);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionBinding::choosePlatoon(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    ActivePlatoon* result = b->choosePlatoon();
    return pushObject<ActivePlatoon>(L, result, ActivePlatoonBinding::getMetatableName());
}

int FactionBinding::getName(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    const std::string& result = b->getName();
    lua_pushlstring(L, result.c_str(), result.length());
    return 1;
}

int FactionBinding::getNumPlatoons(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    GameData* squadTemplate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool tempsOnly = lua_toboolean(L, 3) != 0;
    TownBase* hometown = checkObject<TownBase>(L, 4, TownBaseBinding::getMetatableName());
    int result = b->getNumPlatoons(squadTemplate, tempsOnly, hometown);
    lua_pushinteger(L, result);
    return 1;
}

int FactionBinding::getAllSquadsThatOwn(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    lektor<Platoon*>* out = LektorPtrBinding<Platoon*>::get(L, 2);
    if (!out) return luaL_error(L, "out is nil");
    Building* what = checkObject<Building>(L, 3, BuildingBinding::getMetatableName());
    b->getAllSquadsThatOwn(*out, what);
    return 0;
}

int FactionBinding::chooseARace(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    GameData* character = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* squadTemplate = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* result = b->chooseARace(character, squadTemplate);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int FactionBinding::getBuildingReplacement(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    GameData* building = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* result = b->getBuildingReplacement(building);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int FactionBinding::_switchToUnloadedPlatoon(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    ActivePlatoon* platoon = checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
    b->_switchToUnloadedPlatoon(platoon);
    return 0;
}

int FactionBinding::_newPlatoon(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    GameData* squadTemplate = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* platoonState = checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 5, pos);
    bool persistent = lua_toboolean(L, 6) != 0;
    
    Platoon* result = b->_newPlatoon(f, squadTemplate, platoonState, pos, persistent);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int FactionBinding::_addActivePlatoonToList(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    Platoon* platoon = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    b->_addActivePlatoonToList(platoon);
    return 0;
}

int FactionBinding::addPlatoon(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    Platoon* platoon = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    b->addPlatoon(platoon);
    return 0;
}

int FactionBinding::changePlatoonIndex(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    Platoon* platoon = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    int index = (int)luaL_checkinteger(L, 3);
    b->changePlatoonIndex(platoon, index);
    return 0;
}

int FactionBinding::deactivatePlatoon(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    Platoon* p = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    b->deactivatePlatoon(p);
    return 0;
}

int FactionBinding::activatePlatoon(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    Platoon* p = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    b->activatePlatoon(p);
    return 0;
}
static int Faction_getSquadThatOwns(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    Building* what = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    Platoon* result = b->getSquadThatOwns(what);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

static int Faction_getActivePlatoons_method(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    const lektor<Platoon*>* result = b->getActivePlatoons();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<lektor<Platoon*>>(L, const_cast<lektor<Platoon*>*>(result), LektorPtrBinding<Platoon*>::metaName);
}

static int Faction_getUnloadedPlatoons_method(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    const lektor<Platoon*>* result = b->getUnloadedPlatoons();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<lektor<Platoon*>>(L, const_cast<lektor<Platoon*>*>(result), LektorPtrBinding<Platoon*>::metaName);
}

static int Faction_getAllActiveSquads(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    const lektor<Platoon*>* result = b->getAllActiveSquads();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<lektor<Platoon*>>(L, const_cast<lektor<Platoon*>*>(result), LektorPtrBinding<Platoon*>::metaName);
}

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
        { "setup2", FactionBinding::setup2 },
        { "setup3", FactionBinding::setup3 },
        { "getNewPlatoonID", FactionBinding::getNewPlatoonID },
        { "resetPlatoonID", FactionBinding::resetPlatoonID },
        { "createReplacementPlatoonForPlayerWhenSavegameIsCorrupt", FactionBinding::createReplacementPlatoonForPlayerWhenSavegameIsCorrupt },
        { "resetSquadPositions", FactionBinding::resetSquadPositions },
        { "getData", FactionBinding::getData },
        { "getDefaultDivision", FactionBinding::getDefaultDivision },
        { "getFactionColorScheme", FactionBinding::getFactionColorScheme },
        { "_activateUnloadedPlatoons", FactionBinding::_activateUnloadedPlatoons },
        { "processKillList", FactionBinding::processKillList },
        { "_NV_processKillList", FactionBinding::_NV_processKillList },
        { "getFactionSize", FactionBinding::getFactionSize },
        { "update", FactionBinding::update },
        { "periodicUpdateThreaded", FactionBinding::periodicUpdateThreaded },
        { "periodicUpdateMT", FactionBinding::periodicUpdateMT },
        { "isThePlayer", FactionBinding::isThePlayer },
        { "isNotARealFaction", FactionBinding::isNotARealFaction },
        { "getRoadPreference", FactionBinding::getRoadPreference },
        { "isAntiSlavery", FactionBinding::isAntiSlavery },
        { "getLawEnforcementFaction", FactionBinding::getLawEnforcementFaction },
        { "setName", FactionBinding::setName },
        { "updateUnloadedPlatoons", FactionBinding::updateUnloadedPlatoons },
        { "updateActivePlatoons", FactionBinding::updateActivePlatoons },
        { "spawnSquadMissionsUpdate", FactionBinding::spawnSquadMissionsUpdate },
        { "_spawnASquad", FactionBinding::_spawnASquad },
        { "getSquadThatOwns", Faction_getSquadThatOwns },
        { "getActivePlatoons", Faction_getActivePlatoons_method },
        { "getUnloadedPlatoons", Faction_getUnloadedPlatoons_method },
        { "getAllActiveSquads", Faction_getAllActiveSquads },

        { "getFundamentalNPCType", FactionBinding::getFundamentalNPCType },
        { "setup", FactionBinding::setup },
        { "createNewEmptyUnloadedPlatoon", FactionBinding::createNewEmptyUnloadedPlatoon },
        { "createNewEmptyActivePlatoon", FactionBinding::createNewEmptyActivePlatoon },
        { "createPlatoonUnloaded", FactionBinding::createPlatoonUnloaded },
        { "createPlatoonAuto", FactionBinding::createPlatoonAuto },
        { "createPlatoonsAuto", FactionBinding::createPlatoonsAuto },
        { "restorePlatoon", FactionBinding::restorePlatoon },
        { "countPopulation", FactionBinding::countPopulation },
        { "countNumSquads", FactionBinding::countNumSquads },
        { "destroyPlatoon", FactionBinding::destroyPlatoon },
        { "removePlatoon", FactionBinding::removePlatoon },
        { "getRandomLockLevel", FactionBinding::getRandomLockLevel },
        { "getGUIData", FactionBinding::getGUIData },
        { "loadState", FactionBinding::loadState },
        { "saveState", FactionBinding::saveState },
        { "getCharactersInArea", FactionBinding::getCharactersInArea },
        { "_NV_getCharactersInArea", FactionBinding::_NV_getCharactersInArea },
        { "getSelectedObjects", FactionBinding::getSelectedObjects },
        { "_NV_getSelectedObjects", FactionBinding::_NV_getSelectedObjects },
        { "removeObject", FactionBinding::removeObject },
        { "_NV_removeObject", FactionBinding::_NV_removeObject },
        { "destroyObject", FactionBinding::destroyObject },
        { "_NV_destroyObject", FactionBinding::_NV_destroyObject },
        { "addActiveObject", FactionBinding::addActiveObject },
        { "_NV_addActiveObject", FactionBinding::_NV_addActiveObject },
        { "choosePlatoon", FactionBinding::choosePlatoon },
        { "getName", FactionBinding::getName },
        { "getNumPlatoons", FactionBinding::getNumPlatoons },
        { "getAllSquadsThatOwn", FactionBinding::getAllSquadsThatOwn },
        { "chooseARace", FactionBinding::chooseARace },
        { "getBuildingReplacement", FactionBinding::getBuildingReplacement },
        { "_switchToUnloadedPlatoon", FactionBinding::_switchToUnloadedPlatoon },
        { "_newPlatoon", FactionBinding::_newPlatoon },
        { "_addActivePlatoonToList", FactionBinding::_addActivePlatoonToList },
        { "addPlatoon", FactionBinding::addPlatoon },
        { "changePlatoonIndex", FactionBinding::changePlatoonIndex },
        { "deactivatePlatoon", FactionBinding::deactivatePlatoon },
        { "activatePlatoon", FactionBinding::activatePlatoon },
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
    lua_pushcfunction(L, Faction_get__antiSlavery);
    lua_setfield(L, -2, "_antiSlavery");
    lua_pushcfunction(L, Faction_get_characteristicsData);
    lua_setfield(L, -2, "characteristicsData");
    lua_pushcfunction(L, Faction_get_ranks);
    lua_setfield(L, -2, "ranks");
    lua_pushcfunction(L, Faction_get_allowSlavesWeapons);
    lua_setfield(L, -2, "allowSlavesWeapons");
    lua_pushcfunction(L, Faction_get_fundamentalNPCType);
    lua_setfield(L, -2, "fundamentalNPCType");
    lua_pushcfunction(L, Faction_get_myLawEnforcementFaction);
    lua_setfield(L, -2, "myLawEnforcementFaction");
    lua_pushcfunction(L, Faction_get_isALawEnforcementFaction);
    lua_setfield(L, -2, "isALawEnforcementFaction");
    lua_pushcfunction(L, Faction_get_factionLeader);
    lua_setfield(L, -2, "factionLeader");
    lua_pushcfunction(L, Faction_get_diplomatMgr);
    lua_setfield(L, -2, "diplomatMgr");
    lua_pushcfunction(L, Faction_get_relations);
    lua_setfield(L, -2, "relations");
    lua_pushcfunction(L, Faction_get_factionOwnerships);
    lua_setfield(L, -2, "factionOwnerships");
    lua_pushcfunction(L, Faction_get_warMgr);
    lua_setfield(L, -2, "warMgr");
    lua_pushcfunction(L, Faction_get_tradeCulture);
    lua_setfield(L, -2, "tradeCulture");
    lua_pushcfunction(L, Faction_get_raceSelector);
    lua_setfield(L, -2, "raceSelector");
    lua_pushcfunction(L, Faction_get_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, Faction_get_notARealFaction);
    lua_setfield(L, -2, "notARealFaction");
    lua_pushcfunction(L, Faction_get_roadPreference);
    lua_setfield(L, -2, "roadPreference");
    lua_pushcfunction(L, Faction_get_platoonKillList);
    lua_setfield(L, -2, "platoonKillList");
    lua_pushcfunction(L, Faction_get_platoonRemoveList);
    lua_setfield(L, -2, "platoonRemoveList");
    lua_pushcfunction(L, Faction_get_activePlatoons);
    lua_setfield(L, -2, "activePlatoons");
    lua_pushcfunction(L, Faction_get_unloadedPlatoons);
    lua_setfield(L, -2, "unloadedPlatoons");
    lua_pushcfunction(L, Faction_get_periodicUpdateCounter_active);
    lua_setfield(L, -2, "periodicUpdateCounter_active");
    lua_pushcfunction(L, Faction_get_periodicUpdateCounter_unloaded);
    lua_setfield(L, -2, "periodicUpdateCounter_unloaded");
    lua_pushcfunction(L, Faction_get_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, Faction_get_isAI);
    lua_setfield(L, -2, "isAI");
    lua_pushcfunction(L, Faction_get_isPlayer);
    lua_setfield(L, -2, "isPlayer");
    lua_pushcfunction(L, Faction_get_spawnTimeStamp);
    lua_setfield(L, -2, "spawnTimeStamp");
    lua_pushcfunction(L, Faction_get_diplomatTimeStamp);
    lua_setfield(L, -2, "diplomatTimeStamp");
    lua_pushcfunction(L, Faction_get_platoonIDs);
    lua_setfield(L, -2, "platoonIDs");
    lua_pushcfunction(L, Faction_get_p_TIME);
    lua_setfield(L, -2, "p_TIME");
    lua_pushcfunction(L, Faction_get_platoonPeriodicUpdateIndex);
    lua_setfield(L, -2, "platoonPeriodicUpdateIndex");
    lua_pushcfunction(L, Faction_get_buildingSwaps);
    lua_setfield(L, -2, "buildingSwaps");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Faction_set__antiSlavery);
    lua_setfield(L, -2, "_antiSlavery");
    lua_pushcfunction(L, Faction_set_characteristicsData);
    lua_setfield(L, -2, "characteristicsData");
    lua_pushcfunction(L, Faction_set_ranks);
    lua_setfield(L, -2, "ranks");
    lua_pushcfunction(L, Faction_set_allowSlavesWeapons);
    lua_setfield(L, -2, "allowSlavesWeapons");
    lua_pushcfunction(L, Faction_set_fundamentalNPCType);
    lua_setfield(L, -2, "fundamentalNPCType");
    lua_pushcfunction(L, Faction_set_myLawEnforcementFaction);
    lua_setfield(L, -2, "myLawEnforcementFaction");
    lua_pushcfunction(L, Faction_set_isALawEnforcementFaction);
    lua_setfield(L, -2, "isALawEnforcementFaction");
    lua_pushcfunction(L, Faction_set_factionLeader);
    lua_setfield(L, -2, "factionLeader");
    lua_pushcfunction(L, Faction_set_diplomatMgr);
    lua_setfield(L, -2, "diplomatMgr");
    lua_pushcfunction(L, Faction_set_relations);
    lua_setfield(L, -2, "relations");
    lua_pushcfunction(L, Faction_set_factionOwnerships);
    lua_setfield(L, -2, "factionOwnerships");
    lua_pushcfunction(L, Faction_set_warMgr);
    lua_setfield(L, -2, "warMgr");
    lua_pushcfunction(L, Faction_set_tradeCulture);
    lua_setfield(L, -2, "tradeCulture");
    lua_pushcfunction(L, Faction_set_raceSelector);
    lua_setfield(L, -2, "raceSelector");
    lua_pushcfunction(L, Faction_set_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, Faction_set_notARealFaction);
    lua_setfield(L, -2, "notARealFaction");
    lua_pushcfunction(L, Faction_set_roadPreference);
    lua_setfield(L, -2, "roadPreference");
    lua_pushcfunction(L, Faction_set_platoonKillList);
    lua_setfield(L, -2, "platoonKillList");
    lua_pushcfunction(L, Faction_set_platoonRemoveList);
    lua_setfield(L, -2, "platoonRemoveList");
    lua_pushcfunction(L, Faction_set_activePlatoons);
    lua_setfield(L, -2, "activePlatoons");
    lua_pushcfunction(L, Faction_set_unloadedPlatoons);
    lua_setfield(L, -2, "unloadedPlatoons");
    lua_pushcfunction(L, Faction_set_periodicUpdateCounter_active);
    lua_setfield(L, -2, "periodicUpdateCounter_active");
    lua_pushcfunction(L, Faction_set_periodicUpdateCounter_unloaded);
    lua_setfield(L, -2, "periodicUpdateCounter_unloaded");
    lua_pushcfunction(L, Faction_set_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, Faction_set_isAI);
    lua_setfield(L, -2, "isAI");
    lua_pushcfunction(L, Faction_set_isPlayer);
    lua_setfield(L, -2, "isPlayer");
    lua_pushcfunction(L, Faction_set_spawnTimeStamp);
    lua_setfield(L, -2, "spawnTimeStamp");
    lua_pushcfunction(L, Faction_set_diplomatTimeStamp);
    lua_setfield(L, -2, "diplomatTimeStamp");
    lua_pushcfunction(L, Faction_set_platoonIDs);
    lua_setfield(L, -2, "platoonIDs");
    lua_pushcfunction(L, Faction_set_p_TIME);
    lua_setfield(L, -2, "p_TIME");
    lua_pushcfunction(L, Faction_set_platoonPeriodicUpdateIndex);
    lua_setfield(L, -2, "platoonPeriodicUpdateIndex");
    lua_pushcfunction(L, Faction_set_buildingSwaps);
    lua_setfield(L, -2, "buildingSwaps");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
