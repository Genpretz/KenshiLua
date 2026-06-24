#include "pch.h"
#include "kenshi\Faction.h"
#include "FactionBinding.h"
#include "kenshi/Platoon.h"
#include "OwnershipsBinding.h"
#include "kenshi/PlayerInterface.h"
#include "PlayerInterfaceBinding.h"
#include "GameDataBinding.h"
#include "Lua/BindingHelpers.h"

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
    lua_pushnil(L);
    return 1;
}

static int Faction_get_ranks(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for ranks (lektor<std::string >)
    lua_pushnil(L);
    return 1;
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
    // TODO: Unsupported type for fundamentalNPCType (CharacterTypeEnum)
    lua_pushnil(L);
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
    lua_pushnil(L);
    return 1;
}

static int Faction_get_diplomatMgr(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for diplomatMgr (FactionUniqueSquadManager*)
    lua_pushnil(L);
    return 1;
}

static int Faction_get_relations(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for relations (FactionRelations*)
    lua_pushnil(L);
    return 1;
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
    lua_pushnil(L);
    return 1;
}

static int Faction_get_tradeCulture(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for tradeCulture (TradeCulture)
    lua_pushnil(L);
    return 1;
}

static int Faction_get_raceSelector(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for raceSelector (FitnessSelector<GameData*>)
    lua_pushnil(L);
    return 1;
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
    // TODO: Unsupported type for platoonKillList (lektor<Platoon*>)
    lua_pushnil(L);
    return 1;
}

static int Faction_get_platoonRemoveList(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for platoonRemoveList (lektor<Platoon*>)
    lua_pushnil(L);
    return 1;
}

static int Faction_get_activePlatoons(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for activePlatoons (lektor<Platoon*>)
    lua_pushnil(L);
    return 1;
}

static int Faction_get_unloadedPlatoons(lua_State* L)
{
    Faction* b = getB(L, 1);
    if (!b) return luaL_error(L, "Faction is nil");
    // TODO: Unsupported type for unloadedPlatoons (lektor<Platoon*>)
    lua_pushnil(L);
    return 1;
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
    lua_pushnil(L);
    return 1;
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
    lua_pushnil(L);
    return 1;
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
    return luaL_error(L, "Read-only or unsupported setter type for fundamentalNPCType");
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
    return luaL_error(L, "Read-only or unsupported setter type for relations");
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
    return luaL_error(L, "Read-only or unsupported setter type for tradeCulture");
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

/*
Skipped methods needing manual binding:
  line 65: CharacterTypeEnum getFundamentalNPCType(...) - unsupported return type
  line 68: bool setup(...) - unsupported arg type
  line 73: Platoon* createNewEmptyUnloadedPlatoon(...) - unsupported arg type
  line 74: Platoon* createNewEmptyActivePlatoon(...) - unsupported arg type
  line 75: void createPlatoonUnloaded(...) - unsupported arg type
  line 76: void createPlatoonAuto(...) - unsupported arg type
  line 77: void createPlatoonsAuto(...) - unsupported arg type
  line 79: void restorePlatoon(...) - unsupported arg type
  line 81: int countPopulation(...) - unsupported arg type
  line 82: int countNumSquads(...) - unsupported arg type
  line 83: void destroyPlatoon(...) - unsupported arg type
  line 84: void removePlatoon(...) - unsupported arg type
  line 85: int getRandomLockLevel(...) - unsupported arg type
  line 87: void getGUIData(...) - unsupported arg type
  line 90: void loadState(...) - unsupported arg type
  line 91: GameData* saveState(...) - unsupported arg type
  line 93: void getCharactersInArea(...) - unsupported arg type
  line 94: void _NV_getCharactersInArea(...) - unsupported arg type
  line 95: void getSelectedObjects(...) - unsupported arg type
  line 96: void _NV_getSelectedObjects(...) - unsupported arg type
  line 97: void removeObject(...) - unsupported arg type
  line 98: void _NV_removeObject(...) - unsupported arg type
  line 99: void destroyObject(...) - unsupported arg type
  line 100: void _NV_destroyObject(...) - unsupported arg type
  line 103: bool addActiveObject(...) - unsupported arg type
  line 104: bool _NV_addActiveObject(...) - unsupported arg type
  line 105: ActivePlatoon* choosePlatoon(...) - unsupported return type
  line 106: const lektor<Platoon*>* getActivePlatoons(...) - unsupported return type
  line 107: const lektor<Platoon*>* getUnloadedPlatoons(...) - unsupported return type
  line 115: const std::string& getName(...) - reference return type
  line 117: int getNumPlatoons(...) - unsupported arg type
  line 118: Platoon* getSquadThatOwns(...) - unsupported arg type
  line 119: void getAllSquadsThatOwn(...) - unsupported arg type
  line 120: const lektor<Platoon*>* getAllActiveSquads(...) - unsupported return type
  line 130: GameData* chooseARace(...) - unsupported arg type
  line 132: GameData* getBuildingReplacement(...) - unsupported arg type
  line 135: void _switchToUnloadedPlatoon(...) - unsupported arg type
  line 137: Platoon* _newPlatoon(...) - unsupported arg type
  line 138: void _addActivePlatoonToList(...) - unsupported arg type
  line 139: void addPlatoon(...) - unsupported arg type
  line 140: void changePlatoonIndex(...) - unsupported arg type
  line 141: void deactivatePlatoon(...) - unsupported arg type
  line 142: void activatePlatoon(...) - unsupported arg type
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