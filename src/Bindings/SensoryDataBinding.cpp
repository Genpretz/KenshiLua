#include "pch.h"
#include "kenshi\SensoryData.h"
#include "SensoryDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/SeenSomeoneBinding.h"
#include "Bindings/SenseItrBinding.h"
#include "Bindings/VisibleObjectInfoBinding.h"
#include "Bindings/SpottingPeopleMgrBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Templates/LektorBinding.h"
#include "Bindings/Templates/OgreUnorderedBinding.h"

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
    lua_pushlightuserdata(L, &b->seen);
    return 1;
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
    lua_pushlightuserdata(L, &b->threats);
    return 1;
}

static int SensoryData_get_flockingList(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushlightuserdata(L, &b->flockingList);
    return 1;
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
    lua_pushlightuserdata(L, &b->hearTestTimers);
    return 1;
}

static int SensoryData_get_killList(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lua_pushlightuserdata(L, &b->killList);
    return 1;
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
    lua_pushlightuserdata(L, &b->assessList);
    return 1;
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
    return pushObject<SensoryData::SpottingPeopleMgr>(L, &b->spottedSneakingPeople, SpottingPeopleMgrBinding::getMetatableName());
}

static int SensoryData_get_spottedSuspiciousPeople(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return pushObject<SensoryData::SpottingPeopleMgr>(L, &b->spottedSuspiciousPeople, SpottingPeopleMgrBinding::getMetatableName());
}

static int SensoryData_get_progressBar(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    if (b->progressBar) lua_pushlightuserdata(L, b->progressBar);
    else lua_pushnil(L);
    return 1;
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
    return handBinding::push(L, b->spottedGuyIndexForProgressBar);
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
    return luaL_error(L, "seen is a read-only property");
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
    return luaL_error(L, "threats is a read-only property");
}

static int SensoryData_set_flockingList(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "flockingList is a read-only property");
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
    return luaL_error(L, "hearTestTimers is a read-only property");
}

static int SensoryData_set_killList(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "killList is a read-only property");
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
    return luaL_error(L, "assessList is a read-only property");
}

static int SensoryData_set_me(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int SensoryData_set_spottedSneakingPeople(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "spottedSneakingPeople is a read-only property");
}

static int SensoryData_set_spottedSuspiciousPeople(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "spottedSuspiciousPeople is a read-only property");
}

static int SensoryData_set_progressBar(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    b->progressBar = (FloatingProgressBar*)lua_touserdata(L, 2);
    return 0;
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
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->spottedGuyIndexForProgressBar = *val;
    return 0;
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
  line 107: SensoryData* _CONSTRUCTOR(...) - constructor
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - SensoryData_get_flockingList: Ogre::vector<VisibleObjectInfo>::type
  - SensoryData_get_hearTestTimers: std::map<hand, float...>
  - SensoryData_get_progressBar / SensoryData_set_progressBar: FloatingProgressBar*
  - SensoryData_getStateBroadcast / SensoryData_getStateBroadcastOf: StateBroadcastData*
  - SensoryData__shareSensesCheck: lektor<RootObject*>* (arg 3)
  - SensoryData_getGUIData: DatapanelGUI* (arg 2)
*/

static int SensoryData_getIterator(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    unsigned int tagsAny = (unsigned int)luaL_checkinteger(L, 2);
    unsigned int tagsNOT = (unsigned int)luaL_checkinteger(L, 3);
    SenseItr res = b->getIterator(tagsAny, tagsNOT);
    SenseItr* copy = new SenseItr(res);
    return pushObject<SenseItr>(L, copy, SenseItrBinding::getMetatableName());
}

static int SensoryData_canISeeThisGuy(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool res = b->canISeeThisGuy(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int SensoryData_canIHearThisGuy(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool res = b->canIHearThisGuy(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int SensoryData_amIAwareOfThisGuy(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool needToSeeOrHear = lua_toboolean(L, 3) != 0;
    bool res = b->amIAwareOfThisGuy(who, needToSeeOrHear);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int SensoryData_getLastKnownPositionOf(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Ogre::Vector3 res = b->getLastKnownPositionOf(who);
    pushVector3(L, res);
    return 1;
}

static int SensoryData_getDataFor(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    SeenSomeone* res = b->getDataFor(who);
    return pushObject<SeenSomeone>(L, res, SeenSomeoneBinding::getMetatableName());
}

static int SensoryData_notifyCriminalThreat(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->notifyCriminalThreat(*h);
    return 0;
}

static int SensoryData_getFactionRelation(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    RootObjectBase* c = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    float res = b->getFactionRelation(c);
    lua_pushnumber(L, res);
    return 1;
}

static int SensoryData_getStateBroadcast(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    StateBroadcastData* res = b->getStateBroadcast();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}

static int SensoryData_getStateBroadcastOf(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    hand* who = checkObject<hand>(L, 2, handBinding::getMetatableName());
    StateBroadcastData* res = b->getStateBroadcastOf(*who);
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}

static int SensoryData__shareSensesCheck(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* leader = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lektor<RootObject*>* list = (lektor<RootObject*>*)lua_touserdata(L, 3);
    if (!list) return luaL_error(L, "Invalid lektor<RootObject*> userdata");
    float time = (float)luaL_checknumber(L, 4);
    bool res = b->_shareSensesCheck(leader, *list, time);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int SensoryData_getGUIData(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    DatapanelGUI* panel = (DatapanelGUI*)lua_touserdata(L, 2);
    int cat = (int)luaL_checkinteger(L, 3);
    b->getGUIData(panel, cat);
    return 0;
}

static int SensoryData__calculateFOVScore(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float res = b->_calculateFOVScore(who);
    lua_pushnumber(L, res);
    return 1;
}

static int SensoryData__traceLineOfSightCheck(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool res = b->_traceLineOfSightCheck(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int SensoryData_noticeThisPerson(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool alarmed = lua_toboolean(L, 3) != 0;
    b->noticeThisPerson(c, alarmed);
    return 0;
}

static int SensoryData_add(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool see = lua_toboolean(L, 3) != 0;
    bool hear = lua_toboolean(L, 4) != 0;
    SeenSomeone* res = b->add(c, see, hear);
    return pushObject<SeenSomeone>(L, res, SeenSomeoneBinding::getMetatableName());
}

static int SensoryData_remove(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    b->remove(c);
    return 0;
}

static int SensoryData_decay(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    b->decay(c);
    return 0;
}

static int SensoryData_canSee(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    SeenSomeone* sees = checkObject<SeenSomeone>(L, 3, SeenSomeoneBinding::getMetatableName());
    bool res = b->canSee(c, sees);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int SensoryData_canHear(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    SeenSomeone* see = checkObject<SeenSomeone>(L, 3, SeenSomeoneBinding::getMetatableName());
    bool res = b->canHear(c, see);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int SensoryData_disguiseMods(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float FOV = (float)luaL_checknumber(L, 3);
    bool res = b->disguiseMods(c, FOV);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int SensoryData_assessCrimes(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    b->assessCrimes(c);
    return 0;
}

static int SensoryData_assessKidnapping(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    b->assessKidnapping(c);
    return 0;
}

static int SensoryData_assessNeutral(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool inDepth = lua_toboolean(L, 3) != 0;
    b->assessNeutral(who, inDepth);
    return 0;
}

static int SensoryData_setupMyProgressBar(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    hand* who = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->setupMyProgressBar(*who);
    return 0;
}

static int SensoryData_canISeeThisGuyDoinSneakingOrSomething(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float FOVScore = (float)luaL_checknumber(L, 3);
    SensoryData::SpottingPeopleMgr* memory = checkObject<SensoryData::SpottingPeopleMgr>(L, 4, SpottingPeopleMgrBinding::getMetatableName());
    float spotTimeMinFOV = (float)luaL_checknumber(L, 5);
    float spotTimeMaxFOV = (float)luaL_checknumber(L, 6);
    YesNoMaybe res = b->canISeeThisGuyDoinSneakingOrSomething(who, FOVScore, memory, spotTimeMinFOV, spotTimeMaxFOV);
    lua_pushinteger(L, (lua_Integer)res.key);
    return 1;
}

static int SensoryData_isIntruder_Base(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool res = b->isIntruder_Base(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int SensoryData_isIntruder_Building(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool res = b->isIntruder_Building(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int SensoryData_isInMyPrivate_Building(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool res = b->isInMyPrivate_Building(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int SensoryData_isEscapee(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool res = b->isEscapee(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int SensoryData_reassessAll(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    lektor<RootObject*>* newTargets = (lektor<RootObject*>*)lua_touserdata(L, 2);
    if (!newTargets) return luaL_error(L, "Invalid lektor<RootObject*> userdata");
    float time = (float)luaL_checknumber(L, 3);
    b->reassessAll(*newTargets, time);
    return 0;
}

static int SensoryData_reassess(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    SeenSomeone* sees = checkObject<SeenSomeone>(L, 3, SeenSomeoneBinding::getMetatableName());
    float time = (float)luaL_checknumber(L, 4);
    SeenSomeone* res = b->reassess(c, sees, time);
    return pushObject<SeenSomeone>(L, res, SeenSomeoneBinding::getMetatableName());
}

static int SensoryData_addToThreatsAndFlockingList(lua_State* L)
{
    SensoryData* b = getB(L, 1);
    if (!b) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    b->addToThreatsAndFlockingList(c);
    return 0;
}

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
        { "getIterator", SensoryData_getIterator },
        { "canISeeThisGuy", SensoryData_canISeeThisGuy },
        { "canIHearThisGuy", SensoryData_canIHearThisGuy },
        { "amIAwareOfThisGuy", SensoryData_amIAwareOfThisGuy },
        { "getLastKnownPositionOf", SensoryData_getLastKnownPositionOf },
        { "getDataFor", SensoryData_getDataFor },
        { "notifyCriminalThreat", SensoryData_notifyCriminalThreat },
        { "getFactionRelation", SensoryData_getFactionRelation },
        { "getStateBroadcast", SensoryData_getStateBroadcast },
        { "getStateBroadcastOf", SensoryData_getStateBroadcastOf },
        { "_shareSensesCheck", SensoryData__shareSensesCheck },
        { "getGUIData", SensoryData_getGUIData },
        { "_calculateFOVScore", SensoryData__calculateFOVScore },
        { "_traceLineOfSightCheck", SensoryData__traceLineOfSightCheck },
        { "noticeThisPerson", SensoryData_noticeThisPerson },
        { "add", SensoryData_add },
        { "remove", SensoryData_remove },
        { "decay", SensoryData_decay },
        { "canSee", SensoryData_canSee },
        { "canHear", SensoryData_canHear },
        { "disguiseMods", SensoryData_disguiseMods },
        { "assessCrimes", SensoryData_assessCrimes },
        { "assessKidnapping", SensoryData_assessKidnapping },
        { "assessNeutral", SensoryData_assessNeutral },
        { "setupMyProgressBar", SensoryData_setupMyProgressBar },
        { "canISeeThisGuyDoinSneakingOrSomething", SensoryData_canISeeThisGuyDoinSneakingOrSomething },
        { "isIntruder_Base", SensoryData_isIntruder_Base },
        { "isIntruder_Building", SensoryData_isIntruder_Building },
        { "isInMyPrivate_Building", SensoryData_isInMyPrivate_Building },
        { "isEscapee", SensoryData_isEscapee },
        { "reassessAll", SensoryData_reassessAll },
        { "reassess", SensoryData_reassess },
        { "addToThreatsAndFlockingList", SensoryData_addToThreatsAndFlockingList },
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
