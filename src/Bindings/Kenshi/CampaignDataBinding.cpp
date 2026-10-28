#include "pch.h"
#include "CampaignDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/CampaignTriggerDataBinding.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/FitnessSelectorBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/RootObjectBaseBinding.h"
#include "Bindings/Kenshi/TownBaseBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/Util/TimeOfDayBinding.h"
#include "Bindings/Kenshi/WorldEventStateQueryListBinding.h"

namespace KenshiLua
{

// Field accessors index engine-owned data; offsets checked against the constructor (RVA 0x9C7420).
static_assert(offsetof(CampaignData, me) == 0x8, "CampaignData::me offset does not match the game");
static_assert(offsetof(CampaignData, specificTargetCharacter) == 0x70, "CampaignData::specificTargetCharacter offset does not match the game");
static_assert(offsetof(CampaignData, campaignType) == 0x104, "CampaignData::campaignType offset does not match the game");
static_assert(offsetof(CampaignData, data) == 0x138, "CampaignData::data offset does not match the game");
static_assert(offsetof(CampaignData, victoryTriggers) == 0x1F0, "CampaignData::victoryTriggers offset does not match the game");
// FactionWarMgr::_createCampaignData allocates 0x250 bytes for each CampaignData.
static_assert(sizeof(CampaignData) == 0x250, "CampaignData size does not match the game");

static CampaignData* getInstance(lua_State* L, int idx)
{
    return checkObject<CampaignData>(L, idx, CampaignDataBinding::getMetatableName());
}

// --- Getters for CampaignData ---
static int CampaignData_get_me(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    return pushObject<Faction>(L, instance->me, FactionBinding::getMetatableName());
}

static int CampaignData_get_targetCharacters(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    lua_pushboolean(L, instance->targetCharacters ? 1 : 0);
    return 1;
}

static int CampaignData_get_triggersRandomly_territorial(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    lua_pushboolean(L, instance->triggersRandomly_territorial ? 1 : 0);
    return 1;
}

static int CampaignData_get__isHostile(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    lua_pushboolean(L, instance->_isHostile ? 1 : 0);
    return 1;
}

static int CampaignData_get_triggerTargetTechLevel(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    lua_pushinteger(L, instance->triggerTargetTechLevel);
    return 1;
}

static int CampaignData_get_triggerTargetPopulation(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    lua_pushinteger(L, instance->triggerTargetPopulation);
    return 1;
}

static int CampaignData_get_triggerChancePerDay01(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    lua_pushnumber(L, instance->triggerChancePerDay01);
    return 1;
}

static int CampaignData_get_triggerTimeMin(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    lua_pushinteger(L, instance->triggerTimeMin);
    return 1;
}

static int CampaignData_get_triggerTimeMax(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    lua_pushinteger(L, instance->triggerTimeMax);
    return 1;
}

static int CampaignData_get_triggerRangeNear(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    lua_pushnumber(L, instance->triggerRangeNear);
    return 1;
}

static int CampaignData_get_triggerRangeFurthest(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    lua_pushnumber(L, instance->triggerRangeFurthest);
    return 1;
}

static int CampaignData_get_worldStateRequirements(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    return pushObject<WorldEventStateQueryList>(L, &instance->worldStateRequirements, WorldEventStateQueryListBinding::getMetatableName());
}

static int CampaignData_get_specificTargetCharacter(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    return pushObject<lektor<GameData*> >(L, &instance->specificTargetCharacter, LektorPtrBinding<GameData*>::metaName);
}

static int CampaignData_get_specificLeaderCharacter(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    return pushObject<lektor<GameData*> >(L, &instance->specificLeaderCharacter, LektorPtrBinding<GameData*>::metaName);
}

// GameDataScoredList adds no members to its FitnessSelector<GameData*> base (both 0x60 bytes).
static int CampaignData_get_spawns(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    FitnessSelector<GameData*>* spawns = &instance->spawns;
    return pushObject<FitnessSelector<GameData*> >(L, spawns, FitnessSelectorBinding<GameData*>::metaName);
}

static int CampaignData_get_repeatLimit(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    lua_pushnumber(L, instance->repeatLimit);
    return 1;
}

static int CampaignData_get_campaignType(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    lua_pushinteger(L, (lua_Integer)instance->campaignType);
    return 1;
}

static int CampaignData_get_lastTerritorialTrigger(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    return pushObject<TimeOfDay>(L, &instance->lastTerritorialTrigger, TimeOfDayBinding::getMetatableName());
}

static int CampaignData_get_hasAssaultPhase(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    lua_pushboolean(L, instance->hasAssaultPhase ? 1 : 0);
    return 1;
}

static int CampaignData_get_factionOverride(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    return pushObject<Faction>(L, instance->factionOverride, FactionBinding::getMetatableName());
}

static int CampaignData_get_allyTriggers(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    return pushObject<lektor<GameData*> >(L, &instance->allyTriggers, LektorPtrBinding<GameData*>::metaName);
}

static int CampaignData_get_data(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    return pushObject<GameData>(L, instance->data, GameDataBinding::getMetatableName());
}

static int CampaignData_get_lossTriggers(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    return pushObject<FitnessSelector<CampaignTriggerData*> >(L, &instance->lossTriggers, FitnessSelectorBinding<CampaignTriggerData*>::metaName);
}

static int CampaignData_get_victoryTriggers(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    return pushObject<FitnessSelector<CampaignTriggerData*> >(L, &instance->victoryTriggers, FitnessSelectorBinding<CampaignTriggerData*>::metaName);
}

// --- Setters for CampaignData ---
// chooseTarget and territorialTriggerScore read me->warManager without a null check.
static int CampaignData_set_me(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->me = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int CampaignData_set_targetCharacters(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->targetCharacters = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CampaignData_set_triggersRandomly_territorial(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->triggersRandomly_territorial = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CampaignData_set__isHostile(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->_isHostile = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CampaignData_set_triggerTargetTechLevel(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->triggerTargetTechLevel = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignData_set_triggerTargetPopulation(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->triggerTargetPopulation = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignData_set_triggerChancePerDay01(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->triggerChancePerDay01 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CampaignData_set_triggerTimeMin(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->triggerTimeMin = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignData_set_triggerTimeMax(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->triggerTimeMax = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignData_set_triggerRangeNear(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->triggerRangeNear = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CampaignData_set_triggerRangeFurthest(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->triggerRangeFurthest = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CampaignData_set_repeatLimit(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->repeatLimit = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CampaignData_set_campaignType(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->campaignType = (WarCampaignEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignData_set_lastTerritorialTrigger(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->lastTerritorialTrigger = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int CampaignData_set_hasAssaultPhase(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->hasAssaultPhase = lua_toboolean(L, 2) != 0;
    return 0;
}

// The constructor leaves factionOverride null unless the data names one.
static int CampaignData_set_factionOverride(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->factionOverride = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

// chooseTarget and the CampaignInstance constructor read data without a null check.
static int CampaignData_set_data(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");
    instance->data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

int CampaignDataBinding::_setupPackages(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const char* listname = luaL_checkstring(L, 3);
    Phase state = (Phase)luaL_checkinteger(L, 4);
    instance->_setupPackages(d, listname, state);
    return 0;
}

int CampaignDataBinding::_addDataFrom(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_addDataFrom(d);
    return 0;
}

int CampaignDataBinding::reset(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    instance->reset();
    return 0;
}

int CampaignDataBinding::key(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    WarCampaignEnum result = instance->key();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CampaignDataBinding::isHostile(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    bool result = instance->isHostile();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CampaignDataBinding::getDisplayName(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    std::string result = instance->getDisplayName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int CampaignDataBinding::isTriggersRandomly(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    bool result = instance->isTriggersRandomly();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

// The homeTownOut out-parameter is returned after the result. Some paths leave it unwritten.
int CampaignDataBinding::chooseTarget(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    Faction* enemy = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    TownBase* homeTownOut = nullptr;
    RootObjectBase* result = instance->chooseTarget(enemy, &homeTownOut);
    pushObject<RootObjectBase>(L, result, RootObjectBaseBinding::getMetatableName());
    pushObject<TownBase>(L, homeTownOut, TownBaseBinding::getMetatableName());
    return 2;
}

int CampaignDataBinding::_NV_chooseTarget(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    Faction* enemy = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    TownBase* homeTownOut = nullptr;
    RootObjectBase* result = instance->_NV_chooseTarget(enemy, &homeTownOut);
    pushObject<RootObjectBase>(L, result, RootObjectBaseBinding::getMetatableName());
    pushObject<TownBase>(L, homeTownOut, TownBaseBinding::getMetatableName());
    return 2;
}

int CampaignDataBinding::territorialTriggerScore(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    Faction* enemy = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    RootObjectBase* target = checkObject<RootObjectBase>(L, 3, RootObjectBaseBinding::getMetatableName());
    float result = instance->territorialTriggerScore(enemy, target);
    lua_pushnumber(L, result);
    return 1;
}

int CampaignDataBinding::_NV_territorialTriggerScore(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    Faction* enemy = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    RootObjectBase* target = checkObject<RootObjectBase>(L, 3, RootObjectBaseBinding::getMetatableName());
    float result = instance->_NV_territorialTriggerScore(enemy, target);
    lua_pushnumber(L, result);
    return 1;
}

int CampaignDataBinding::canStart(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    bool result = instance->canStart();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CampaignDataBinding::_NV_canStart(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    bool result = instance->_NV_canStart();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CampaignDataBinding::numForcesNeeded(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    int result = instance->numForcesNeeded();
    lua_pushinteger(L, result);
    return 1;
}

int CampaignDataBinding::ignoresMults(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    bool result = instance->ignoresMults();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CampaignDataBinding::canUseThisSquad(lua_State* L)
{
    CampaignData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignData is nil");

    GameData* squadTemplate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->canUseThisSquad(squadTemplate);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 68: CampaignData(...) - FactionWarMgr owns campaign data (see FactionWarMgr._createCampaignData)
  line 69: _CONSTRUCTOR(...) - see above
  line 70: ~CampaignData() - see above
  line 71: _DESTRUCTOR() - see above
  line 104: createCampaign(...) - pure virtual factory; the new CampaignInstance is unowned until FactionWarMgr registers it, so use FactionWarMgr.triggerCampaign
Skipped properties needing manual binding:
  line 108: aiPackagesLeader (std::map<Phase, GameData*>) - no container binding for this map
  line 109: aiPackages (std::map<Phase, GameData*>) - no container binding for this map
Read-only properties:
  worldStateRequirements, spawns, lossTriggers, victoryTriggers - container assignment not verified against the engine
  specificTargetCharacter, specificLeaderCharacter, allyTriggers (lektor<GameData*>) - KenshiLib's lektor has no deep copy, so assignment would alias the engine's buffer
*/

int CampaignDataBinding::gc(lua_State* L)
{
    // Borrowed from the owning FactionWarMgr
    return 0;
}

int CampaignDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CampaignData object");
    return 1;
}

void CampaignDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CampaignDataBinding::gc },
        { "__tostring", CampaignDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_setupPackages", CampaignDataBinding::_setupPackages },
        { "_addDataFrom", CampaignDataBinding::_addDataFrom },
        { "reset", CampaignDataBinding::reset },
        { "key", CampaignDataBinding::key },
        { "isHostile", CampaignDataBinding::isHostile },
        { "getDisplayName", CampaignDataBinding::getDisplayName },
        { "isTriggersRandomly", CampaignDataBinding::isTriggersRandomly },
        { "chooseTarget", CampaignDataBinding::chooseTarget },
        { "_NV_chooseTarget", CampaignDataBinding::_NV_chooseTarget },
        { "territorialTriggerScore", CampaignDataBinding::territorialTriggerScore },
        { "_NV_territorialTriggerScore", CampaignDataBinding::_NV_territorialTriggerScore },
        { "canStart", CampaignDataBinding::canStart },
        { "_NV_canStart", CampaignDataBinding::_NV_canStart },
        { "numForcesNeeded", CampaignDataBinding::numForcesNeeded },
        { "ignoresMults", CampaignDataBinding::ignoresMults },
        { "canUseThisSquad", CampaignDataBinding::canUseThisSquad },
        { 0, 0 }
    };

    registerClass(
        L,
        CampaignDataBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CampaignDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "me", CampaignData_get_me);
    registerGetter(L, "targetCharacters", CampaignData_get_targetCharacters);
    registerGetter(L, "triggersRandomly_territorial", CampaignData_get_triggersRandomly_territorial);
    registerGetter(L, "_isHostile", CampaignData_get__isHostile);
    registerGetter(L, "triggerTargetTechLevel", CampaignData_get_triggerTargetTechLevel);
    registerGetter(L, "triggerTargetPopulation", CampaignData_get_triggerTargetPopulation);
    registerGetter(L, "triggerChancePerDay01", CampaignData_get_triggerChancePerDay01);
    registerGetter(L, "triggerTimeMin", CampaignData_get_triggerTimeMin);
    registerGetter(L, "triggerTimeMax", CampaignData_get_triggerTimeMax);
    registerGetter(L, "triggerRangeNear", CampaignData_get_triggerRangeNear);
    registerGetter(L, "triggerRangeFurthest", CampaignData_get_triggerRangeFurthest);
    registerGetter(L, "worldStateRequirements", CampaignData_get_worldStateRequirements);
    registerGetter(L, "specificTargetCharacter", CampaignData_get_specificTargetCharacter);
    registerGetter(L, "specificLeaderCharacter", CampaignData_get_specificLeaderCharacter);
    registerGetter(L, "spawns", CampaignData_get_spawns);
    registerGetter(L, "repeatLimit", CampaignData_get_repeatLimit);
    registerGetter(L, "campaignType", CampaignData_get_campaignType);
    registerGetter(L, "lastTerritorialTrigger", CampaignData_get_lastTerritorialTrigger);
    registerGetter(L, "hasAssaultPhase", CampaignData_get_hasAssaultPhase);
    registerGetter(L, "factionOverride", CampaignData_get_factionOverride);
    registerGetter(L, "allyTriggers", CampaignData_get_allyTriggers);
    registerGetter(L, "data", CampaignData_get_data);
    registerGetter(L, "lossTriggers", CampaignData_get_lossTriggers);
    registerGetter(L, "victoryTriggers", CampaignData_get_victoryTriggers);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "me", CampaignData_set_me);
    registerSetter(L, "targetCharacters", CampaignData_set_targetCharacters);
    registerSetter(L, "triggersRandomly_territorial", CampaignData_set_triggersRandomly_territorial);
    registerSetter(L, "_isHostile", CampaignData_set__isHostile);
    registerSetter(L, "triggerTargetTechLevel", CampaignData_set_triggerTargetTechLevel);
    registerSetter(L, "triggerTargetPopulation", CampaignData_set_triggerTargetPopulation);
    registerSetter(L, "triggerChancePerDay01", CampaignData_set_triggerChancePerDay01);
    registerSetter(L, "triggerTimeMin", CampaignData_set_triggerTimeMin);
    registerSetter(L, "triggerTimeMax", CampaignData_set_triggerTimeMax);
    registerSetter(L, "triggerRangeNear", CampaignData_set_triggerRangeNear);
    registerSetter(L, "triggerRangeFurthest", CampaignData_set_triggerRangeFurthest);
    registerSetter(L, "repeatLimit", CampaignData_set_repeatLimit);
    registerSetter(L, "campaignType", CampaignData_set_campaignType);
    registerSetter(L, "lastTerritorialTrigger", CampaignData_set_lastTerritorialTrigger);
    registerSetter(L, "hasAssaultPhase", CampaignData_set_hasAssaultPhase);
    registerSetter(L, "factionOverride", CampaignData_set_factionOverride);
    registerSetter(L, "data", CampaignData_set_data);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
