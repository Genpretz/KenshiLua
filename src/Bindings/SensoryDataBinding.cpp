#include "pch.h"
#include "kenshi\SensoryData.h"
#include "SensoryDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"

namespace KenshiLua
{

static SensoryData* getB(lua_State* L, int idx)
{
    return checkObject<SensoryData>(L, idx, SensoryDataBinding::getMetatableName());
}

// --- Getters for SensoryData ---
static int SensoryData_get_nearestEnemy(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushnumber(L, b->nearestEnemy);
    return 1;
}

static int SensoryData_get_seen(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    // TODO: Unsupported type for seen (ogre_unordered_map<hand, SeenSomeone*>::type)
    return luaL_error(L, "Unsupported property 'seen' (type: ogre_unordered_map<hand, SeenSomeone*>::type)");
}

static int SensoryData_get_numUnconsciousAllies(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushinteger(L, b->numUnconsciousAllies);
    return 1;
}

static int SensoryData_get_numConsciousAllies(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushinteger(L, b->numConsciousAllies);
    return 1;
}

static int SensoryData_get_threats(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    // TODO: Unsupported type for threats (lektor<hand>)
    return luaL_error(L, "Unsupported property 'threats' (type: lektor<hand>)");
}

static int SensoryData_get_flockingList(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    // TODO: Unsupported type for flockingList (Ogre::vector<VisibleObjectInfo>::type)
    return luaL_error(L, "Unsupported property 'flockingList' (type: Ogre::vector<VisibleObjectInfo>::type)");
}

static int SensoryData_get_totalThreatLevelPersonal(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushnumber(L, b->totalThreatLevelPersonal);
    return 1;
}

static int SensoryData_get_totalThreatLevelAllies(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushnumber(L, b->totalThreatLevelAllies);
    return 1;
}

static int SensoryData_get_totalIntendedThreatLevelGeneral(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushnumber(L, b->totalIntendedThreatLevelGeneral);
    return 1;
}

static int SensoryData_get_numEnemies(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushinteger(L, b->numEnemies);
    return 1;
}

static int SensoryData_get_numNeutrals(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushinteger(L, b->numNeutrals);
    return 1;
}

static int SensoryData_get_lastThreat(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushnumber(L, b->lastThreat);
    return 1;
}

static int SensoryData_get_hearTestTimers(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    // TODO: Unsupported type for hearTestTimers (std::map<hand, float, std::less<hand>, std::allocator<std::pair<hand const, float> > >)
    return luaL_error(L, "Unsupported property 'hearTestTimers' (type: std::map<hand, float, std::less<hand>, std::allocator<std::pair<hand const, float> > >)");
}

static int SensoryData_get_killList(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    // TODO: Unsupported type for killList (ogre_unordered_set<hand>::type)
    return luaL_error(L, "Unsupported property 'killList' (type: ogre_unordered_set<hand>::type)");
}

static int SensoryData_get_currentAssessIndex(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushinteger(L, b->currentAssessIndex);
    return 1;
}

static int SensoryData_get_currentAssessList(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushinteger(L, b->currentAssessList);
    return 1;
}

static int SensoryData_get_assessList(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    // TODO: Unsupported type for assessList (ogre_unordered_set<hand>::type)
    return luaL_error(L, "Unsupported property 'assessList' (type: ogre_unordered_set<hand>::type)");
}

static int SensoryData_get_me(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return pushObject<Character>(L, b->me, CharacterBinding::getMetatableName());
}

static int SensoryData_get_spottedSneakingPeople(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    // TODO: Unsupported type for spottedSneakingPeople (SensoryData::SpottingPeopleMgr)
    return luaL_error(L, "Unsupported property 'spottedSneakingPeople' (type: SensoryData::SpottingPeopleMgr)");
}

static int SensoryData_get_spottedSuspiciousPeople(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    // TODO: Unsupported type for spottedSuspiciousPeople (SensoryData::SpottingPeopleMgr)
    return luaL_error(L, "Unsupported property 'spottedSuspiciousPeople' (type: SensoryData::SpottingPeopleMgr)");
}

static int SensoryData_get_progressBar(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    // TODO: Unsupported type for progressBar (FloatingProgressBar*)
    return luaL_error(L, "Unsupported property 'progressBar' (type: FloatingProgressBar*)");
}

static int SensoryData_get_progressBarStillNeeded(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushinteger(L, b->progressBarStillNeeded);
    return 1;
}

static int SensoryData_get_spottedGuyIndexForProgressBar(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    // TODO: Unsupported type for spottedGuyIndexForProgressBar (hand)
    return luaL_error(L, "Unsupported property 'spottedGuyIndexForProgressBar' (type: hand)");
}

static int SensoryData_get_amSharingThisFrame(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushboolean(L, b->amSharingThisFrame ? 1 : 0);
    return 1;
}

// --- Setters for SensoryData ---
static int SensoryData_set_nearestEnemy(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->nearestEnemy = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SensoryData_set_seen(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for seen");
}

static int SensoryData_set_numUnconsciousAllies(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->numUnconsciousAllies = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SensoryData_set_numConsciousAllies(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->numConsciousAllies = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SensoryData_set_threats(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for threats");
}

static int SensoryData_set_flockingList(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for flockingList");
}

static int SensoryData_set_totalThreatLevelPersonal(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->totalThreatLevelPersonal = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SensoryData_set_totalThreatLevelAllies(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->totalThreatLevelAllies = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SensoryData_set_totalIntendedThreatLevelGeneral(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->totalIntendedThreatLevelGeneral = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SensoryData_set_numEnemies(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->numEnemies = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SensoryData_set_numNeutrals(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->numNeutrals = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SensoryData_set_lastThreat(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->lastThreat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SensoryData_set_hearTestTimers(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for hearTestTimers");
}

static int SensoryData_set_killList(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for killList");
}

static int SensoryData_set_currentAssessIndex(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->currentAssessIndex = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SensoryData_set_currentAssessList(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->currentAssessList = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SensoryData_set_assessList(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for assessList");
}

static int SensoryData_set_me(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for me");
}

static int SensoryData_set_spottedSneakingPeople(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for spottedSneakingPeople");
}

static int SensoryData_set_spottedSuspiciousPeople(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for spottedSuspiciousPeople");
}

static int SensoryData_set_progressBar(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for progressBar");
}

static int SensoryData_set_progressBarStillNeeded(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->progressBarStillNeeded = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SensoryData_set_spottedGuyIndexForProgressBar(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for spottedGuyIndexForProgressBar");
}

static int SensoryData_set_amSharingThisFrame(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->amSharingThisFrame = lua_toboolean(L, 2) != 0;
    return 0;
}

int SensoryDataBinding::_DESTRUCTOR(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");

    b->_DESTRUCTOR();
    return 0;
}

int SensoryDataBinding::periodicUpdate(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->periodicUpdate(time);
    return 0;
}

int SensoryDataBinding::periodicUpdate_KOed(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");

    b->periodicUpdate_KOed();
    return 0;
}

int SensoryDataBinding::getVisionRange(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");

    bool inTown = lua_toboolean(L, 2) != 0;
    float result = b->getVisionRange(inTown);
    lua_pushnumber(L, result);
    return 1;
}

int SensoryDataBinding::update(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    b->update(frameTime);
    return 0;
}

int SensoryDataBinding::notifyKO(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");

    b->notifyKO();
    return 0;
}

int SensoryDataBinding::getNearestEnemyDistanceSq(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");

    float result = b->getNearestEnemyDistanceSq();
    lua_pushnumber(L, result);
    return 1;
}

int SensoryDataBinding::getCharacter(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");

    Character* result = b->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int SensoryDataBinding::dialogAssessmentUpdate(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    bool inDepth = lua_toboolean(L, 3) != 0;
    b->dialogAssessmentUpdate(frameTime, inDepth);
    return 0;
}

int SensoryDataBinding::processKillList(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");

    b->processKillList();
    return 0;
}

int SensoryDataBinding::updateMyProgressBar(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");

    float progress = (float)luaL_checknumber(L, 2);
    std::string text = luaL_checkstring(L, 3);
    b->updateMyProgressBar(progress, text);
    return 0;
}

int SensoryDataBinding::buildingSpotterUpdate(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");

    b->buildingSpotterUpdate();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 107: SensoryData* _CONSTRUCTOR(...) - unsupported return type
  line 116: SenseItr getIterator(...) - unsupported return type
  line 120: bool canISeeThisGuy(...) - unsupported arg type
  line 121: bool canIHearThisGuy(...) - unsupported arg type
  line 122: bool amIAwareOfThisGuy(...) - unsupported arg type
  line 123: Ogre::Vector3 getLastKnownPositionOf(...) - unsupported arg type
  line 124: SeenSomeone* getDataFor(...) - unsupported return type
  line 126: void notifyCriminalThreat(...) - unsupported arg type
  line 129: float getFactionRelation(...) - unsupported arg type
  line 130: StateBroadcastData* getStateBroadcast(...) - unsupported return type
  line 131: StateBroadcastData* getStateBroadcastOf(...) - unsupported return type
  line 139: bool _shareSensesCheck(...) - unsupported arg type
  line 140: void getGUIData(...) - unsupported arg type
  line 141: float _calculateFOVScore(...) - unsupported arg type
  line 142: bool _traceLineOfSightCheck(...) - unsupported arg type
  line 145: void noticeThisPerson(...) - unsupported arg type
  line 146: SeenSomeone* add(...) - unsupported return type
  line 147: void remove(...) - unsupported arg type
  line 148: void decay(...) - unsupported arg type
  line 149: bool canSee(...) - unsupported arg type
  line 150: bool canHear(...) - unsupported arg type
  line 151: bool disguiseMods(...) - unsupported arg type
  line 152: void assessCrimes(...) - unsupported arg type
  line 153: void assessKidnapping(...) - unsupported arg type
  line 157: void assessNeutral(...) - unsupported arg type
  line 193: void setupMyProgressBar(...) - unsupported arg type
  line 196: YesNoMaybe canISeeThisGuyDoinSneakingOrSomething(...) - unsupported return type
  line 197: bool isIntruder_Base(...) - unsupported arg type
  line 198: bool isIntruder_Building(...) - unsupported arg type
  line 199: bool isInMyPrivate_Building(...) - unsupported arg type
  line 200: bool isEscapee(...) - unsupported arg type
  line 201: void reassessAll(...) - unsupported arg type
  line 202: SeenSomeone* reassess(...) - unsupported return type
  line 203: void addToThreatsAndFlockingList(...) - unsupported arg type
*/

int SensoryDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SensoryDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SensoryData object");
    return 1;
}

void SensoryDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SensoryDataBinding::gc },
        { "__tostring", SensoryDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", SensoryDataBinding::_DESTRUCTOR },
        { "periodicUpdate", SensoryDataBinding::periodicUpdate },
        { "periodicUpdate_KOed", SensoryDataBinding::periodicUpdate_KOed },
        { "getVisionRange", SensoryDataBinding::getVisionRange },
        { "update", SensoryDataBinding::update },
        { "notifyKO", SensoryDataBinding::notifyKO },
        { "getNearestEnemyDistanceSq", SensoryDataBinding::getNearestEnemyDistanceSq },
        { "getCharacter", SensoryDataBinding::getCharacter },
        { "dialogAssessmentUpdate", SensoryDataBinding::dialogAssessmentUpdate },
        { "processKillList", SensoryDataBinding::processKillList },
        { "updateMyProgressBar", SensoryDataBinding::updateMyProgressBar },
        { "buildingSpotterUpdate", SensoryDataBinding::buildingSpotterUpdate },
        { 0, 0 }
    };

    registerClass(
        L, 
        SensoryDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SensoryDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, SensoryData_get_nearestEnemy);
    lua_setfield(L, -2, "nearestEnemy");
    lua_pushcfunction(L, SensoryData_get_seen);
    lua_setfield(L, -2, "seen");
    lua_pushcfunction(L, SensoryData_get_numUnconsciousAllies);
    lua_setfield(L, -2, "numUnconsciousAllies");
    lua_pushcfunction(L, SensoryData_get_numConsciousAllies);
    lua_setfield(L, -2, "numConsciousAllies");
    lua_pushcfunction(L, SensoryData_get_threats);
    lua_setfield(L, -2, "threats");
    lua_pushcfunction(L, SensoryData_get_flockingList);
    lua_setfield(L, -2, "flockingList");
    lua_pushcfunction(L, SensoryData_get_totalThreatLevelPersonal);
    lua_setfield(L, -2, "totalThreatLevelPersonal");
    lua_pushcfunction(L, SensoryData_get_totalThreatLevelAllies);
    lua_setfield(L, -2, "totalThreatLevelAllies");
    lua_pushcfunction(L, SensoryData_get_totalIntendedThreatLevelGeneral);
    lua_setfield(L, -2, "totalIntendedThreatLevelGeneral");
    lua_pushcfunction(L, SensoryData_get_numEnemies);
    lua_setfield(L, -2, "numEnemies");
    lua_pushcfunction(L, SensoryData_get_numNeutrals);
    lua_setfield(L, -2, "numNeutrals");
    lua_pushcfunction(L, SensoryData_get_lastThreat);
    lua_setfield(L, -2, "lastThreat");
    lua_pushcfunction(L, SensoryData_get_hearTestTimers);
    lua_setfield(L, -2, "hearTestTimers");
    lua_pushcfunction(L, SensoryData_get_killList);
    lua_setfield(L, -2, "killList");
    lua_pushcfunction(L, SensoryData_get_currentAssessIndex);
    lua_setfield(L, -2, "currentAssessIndex");
    lua_pushcfunction(L, SensoryData_get_currentAssessList);
    lua_setfield(L, -2, "currentAssessList");
    lua_pushcfunction(L, SensoryData_get_assessList);
    lua_setfield(L, -2, "assessList");
    lua_pushcfunction(L, SensoryData_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, SensoryData_get_spottedSneakingPeople);
    lua_setfield(L, -2, "spottedSneakingPeople");
    lua_pushcfunction(L, SensoryData_get_spottedSuspiciousPeople);
    lua_setfield(L, -2, "spottedSuspiciousPeople");
    lua_pushcfunction(L, SensoryData_get_progressBar);
    lua_setfield(L, -2, "progressBar");
    lua_pushcfunction(L, SensoryData_get_progressBarStillNeeded);
    lua_setfield(L, -2, "progressBarStillNeeded");
    lua_pushcfunction(L, SensoryData_get_spottedGuyIndexForProgressBar);
    lua_setfield(L, -2, "spottedGuyIndexForProgressBar");
    lua_pushcfunction(L, SensoryData_get_amSharingThisFrame);
    lua_setfield(L, -2, "amSharingThisFrame");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, SensoryData_set_nearestEnemy);
    lua_setfield(L, -2, "nearestEnemy");
    lua_pushcfunction(L, SensoryData_set_seen);
    lua_setfield(L, -2, "seen");
    lua_pushcfunction(L, SensoryData_set_numUnconsciousAllies);
    lua_setfield(L, -2, "numUnconsciousAllies");
    lua_pushcfunction(L, SensoryData_set_numConsciousAllies);
    lua_setfield(L, -2, "numConsciousAllies");
    lua_pushcfunction(L, SensoryData_set_threats);
    lua_setfield(L, -2, "threats");
    lua_pushcfunction(L, SensoryData_set_flockingList);
    lua_setfield(L, -2, "flockingList");
    lua_pushcfunction(L, SensoryData_set_totalThreatLevelPersonal);
    lua_setfield(L, -2, "totalThreatLevelPersonal");
    lua_pushcfunction(L, SensoryData_set_totalThreatLevelAllies);
    lua_setfield(L, -2, "totalThreatLevelAllies");
    lua_pushcfunction(L, SensoryData_set_totalIntendedThreatLevelGeneral);
    lua_setfield(L, -2, "totalIntendedThreatLevelGeneral");
    lua_pushcfunction(L, SensoryData_set_numEnemies);
    lua_setfield(L, -2, "numEnemies");
    lua_pushcfunction(L, SensoryData_set_numNeutrals);
    lua_setfield(L, -2, "numNeutrals");
    lua_pushcfunction(L, SensoryData_set_lastThreat);
    lua_setfield(L, -2, "lastThreat");
    lua_pushcfunction(L, SensoryData_set_hearTestTimers);
    lua_setfield(L, -2, "hearTestTimers");
    lua_pushcfunction(L, SensoryData_set_killList);
    lua_setfield(L, -2, "killList");
    lua_pushcfunction(L, SensoryData_set_currentAssessIndex);
    lua_setfield(L, -2, "currentAssessIndex");
    lua_pushcfunction(L, SensoryData_set_currentAssessList);
    lua_setfield(L, -2, "currentAssessList");
    lua_pushcfunction(L, SensoryData_set_assessList);
    lua_setfield(L, -2, "assessList");
    lua_pushcfunction(L, SensoryData_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, SensoryData_set_spottedSneakingPeople);
    lua_setfield(L, -2, "spottedSneakingPeople");
    lua_pushcfunction(L, SensoryData_set_spottedSuspiciousPeople);
    lua_setfield(L, -2, "spottedSuspiciousPeople");
    lua_pushcfunction(L, SensoryData_set_progressBar);
    lua_setfield(L, -2, "progressBar");
    lua_pushcfunction(L, SensoryData_set_progressBarStillNeeded);
    lua_setfield(L, -2, "progressBarStillNeeded");
    lua_pushcfunction(L, SensoryData_set_spottedGuyIndexForProgressBar);
    lua_setfield(L, -2, "spottedGuyIndexForProgressBar");
    lua_pushcfunction(L, SensoryData_set_amSharingThisFrame);
    lua_setfield(L, -2, "amSharingThisFrame");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua