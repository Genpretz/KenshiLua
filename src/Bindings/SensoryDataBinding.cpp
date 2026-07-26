#include "pch.h"
#include "kenshi\SensoryData.h"
#include "SensoryDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Gui/FloatingProgressBarBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/SeenSomeoneBinding.h"
#include "Bindings/SenseItrBinding.h"
#include "Bindings/Util/YesNoMaybeBinding.h"
#include "Bindings/SpottingPeopleMgrBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Bindings/VisibleObjectInfoBinding.h"

namespace KenshiLua
{

static SensoryData* getInstance(lua_State* L, int idx)
{
    return checkObject<SensoryData>(L, idx, SensoryDataBinding::getMetatableName());
}

// --- Getters for SensoryData ---
static int SensoryData_get_nearestEnemy(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushnumber(L, instance->nearestEnemy);
    return 1;
}

static int SensoryData_get_numUnconsciousAllies(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushinteger(L, instance->numUnconsciousAllies);
    return 1;
}

static int SensoryData_get_numConsciousAllies(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushinteger(L, instance->numConsciousAllies);
    return 1;
}

static int SensoryData_get_totalThreatLevelPersonal(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushnumber(L, instance->totalThreatLevelPersonal);
    return 1;
}

static int SensoryData_get_totalThreatLevelAllies(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushnumber(L, instance->totalThreatLevelAllies);
    return 1;
}

static int SensoryData_get_totalIntendedThreatLevelGeneral(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushnumber(L, instance->totalIntendedThreatLevelGeneral);
    return 1;
}

static int SensoryData_get_numEnemies(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushinteger(L, instance->numEnemies);
    return 1;
}

static int SensoryData_get_numNeutrals(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushinteger(L, instance->numNeutrals);
    return 1;
}

static int SensoryData_get_lastThreat(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushnumber(L, instance->lastThreat);
    return 1;
}

static int SensoryData_get_currentAssessIndex(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushinteger(L, instance->currentAssessIndex);
    return 1;
}

static int SensoryData_get_currentAssessList(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushinteger(L, instance->currentAssessList);
    return 1;
}

static int SensoryData_get_me(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int SensoryData_get_spottedSneakingPeople(lua_State* L) { return pushObject<SensoryData::SpottingPeopleMgr>(L, &getInstance(L, 1)->spottedSneakingPeople, SpottingPeopleMgrBinding::getMetatableName()); }

static int SensoryData_get_spottedSuspiciousPeople(lua_State* L) { return pushObject<SensoryData::SpottingPeopleMgr>(L, &getInstance(L, 1)->spottedSuspiciousPeople, SpottingPeopleMgrBinding::getMetatableName()); }

static int SensoryData_get_progressBar(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    return pushObject<FloatingProgressBar>(L, instance->progressBar, FloatingProgressBarBinding::getMetatableName());
}

static int SensoryData_get_progressBarStillNeeded(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushinteger(L, instance->progressBarStillNeeded);
    return 1;
}

static int SensoryData_get_spottedGuyIndexForProgressBar(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    return handBinding::push(L, instance->spottedGuyIndexForProgressBar);
}

static int SensoryData_get_amSharingThisFrame(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushboolean(L, instance->amSharingThisFrame ? 1 : 0);
    return 1;
}

// --- Setters for SensoryData ---
static int SensoryData_set_nearestEnemy(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->nearestEnemy = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SensoryData_set_numUnconsciousAllies(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->numUnconsciousAllies = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SensoryData_set_numConsciousAllies(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->numConsciousAllies = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SensoryData_set_totalThreatLevelPersonal(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->totalThreatLevelPersonal = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SensoryData_set_totalThreatLevelAllies(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->totalThreatLevelAllies = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SensoryData_set_totalIntendedThreatLevelGeneral(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->totalIntendedThreatLevelGeneral = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SensoryData_set_numEnemies(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->numEnemies = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SensoryData_set_numNeutrals(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->numNeutrals = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SensoryData_set_lastThreat(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->lastThreat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SensoryData_set_currentAssessIndex(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->currentAssessIndex = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SensoryData_set_currentAssessList(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->currentAssessList = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SensoryData_set_me(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int SensoryData_set_spottedSneakingPeople(lua_State* L) { return 0; }

static int SensoryData_set_spottedSuspiciousPeople(lua_State* L) { return 0; }

static int SensoryData_set_progressBar(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->progressBar = lua_isnoneornil(L, 2) ? nullptr : checkObject<FloatingProgressBar>(L, 2, FloatingProgressBarBinding::getMetatableName());
    return 0;
}

static int SensoryData_set_progressBarStillNeeded(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->progressBarStillNeeded = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SensoryData_set_spottedGuyIndexForProgressBar(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->spottedGuyIndexForProgressBar = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int SensoryData_set_amSharingThisFrame(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    instance->amSharingThisFrame = lua_toboolean(L, 2) != 0;
    return 0;
}

int SensoryDataBinding::_CONSTRUCTOR(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* _me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    SensoryData* result = instance->_CONSTRUCTOR(_me);
    return pushObject<SensoryData>(L, result, SensoryDataBinding::getMetatableName());
}

int SensoryDataBinding::_DESTRUCTOR(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int SensoryDataBinding::periodicUpdate(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->periodicUpdate(time);
    return 0;
}

int SensoryDataBinding::periodicUpdate_KOed(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    instance->periodicUpdate_KOed();
    return 0;
}

int SensoryDataBinding::getVisionRange(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    bool inTown = lua_toboolean(L, 2) != 0;
    float result = instance->getVisionRange(inTown);
    lua_pushnumber(L, result);
    return 1;
}

int SensoryDataBinding::update(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    instance->update(frameTime);
    return 0;
}

int SensoryDataBinding::notifyKO(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    instance->notifyKO();
    return 0;
}

int SensoryDataBinding::getIterator(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    unsigned int tagsAny = (unsigned int)luaL_checkinteger(L, 2);
    unsigned int tagsNOT = (unsigned int)luaL_checkinteger(L, 3);
    SenseItr result = instance->getIterator(tagsAny, tagsNOT);
    return pushObject<SenseItr>(L, &result, SenseItrBinding::getMetatableName());
}

int SensoryDataBinding::getNearestEnemyDistanceSq(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    float result = instance->getNearestEnemyDistanceSq();
    lua_pushnumber(L, result);
    return 1;
}

int SensoryDataBinding::canISeeThisGuy(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->canISeeThisGuy(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SensoryDataBinding::canIHearThisGuy(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->canIHearThisGuy(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SensoryDataBinding::amIAwareOfThisGuy(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool needToSeeOrHear = lua_toboolean(L, 3) != 0;
    bool result = instance->amIAwareOfThisGuy(who, needToSeeOrHear);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SensoryDataBinding::getLastKnownPositionOf(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Ogre::Vector3 result = instance->getLastKnownPositionOf(who);
    pushVector3(L, result);
    return 1;
}

int SensoryDataBinding::getDataFor(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    SeenSomeone* result = instance->getDataFor(who);
    return pushObject<SeenSomeone>(L, result, SeenSomeoneBinding::getMetatableName());
}

int SensoryDataBinding::getFactionRelation(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    RootObjectBase* c = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    float result = instance->getFactionRelation(c);
    lua_pushnumber(L, result);
    return 1;
}

int SensoryDataBinding::getStateBroadcast(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    StateBroadcastData* result = instance->getStateBroadcast();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int SensoryDataBinding::getGUIData(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int cat = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(panel, cat);
    return 0;
}

int SensoryDataBinding::_calculateFOVScore(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float result = instance->_calculateFOVScore(who);
    lua_pushnumber(L, result);
    return 1;
}

int SensoryDataBinding::_traceLineOfSightCheck(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->_traceLineOfSightCheck(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SensoryDataBinding::getCharacter(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* result = instance->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int SensoryDataBinding::dialogAssessmentUpdate(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    bool inDepth = lua_toboolean(L, 3) != 0;
    instance->dialogAssessmentUpdate(frameTime, inDepth);
    return 0;
}

int SensoryDataBinding::noticeThisPerson(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool alarmed = lua_toboolean(L, 3) != 0;
    instance->noticeThisPerson(c, alarmed);
    return 0;
}

int SensoryDataBinding::add(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool see = lua_toboolean(L, 3) != 0;
    bool hear = lua_toboolean(L, 4) != 0;
    SeenSomeone* result = instance->add(c, see, hear);
    return pushObject<SeenSomeone>(L, result, SeenSomeoneBinding::getMetatableName());
}

int SensoryDataBinding::remove(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->remove(c);
    return 0;
}

int SensoryDataBinding::decay(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->decay(c);
    return 0;
}

int SensoryDataBinding::canSee(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    SeenSomeone* sees = checkObject<SeenSomeone>(L, 3, SeenSomeoneBinding::getMetatableName());
    bool result = instance->canSee(c, sees);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SensoryDataBinding::canHear(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    SeenSomeone* see = checkObject<SeenSomeone>(L, 3, SeenSomeoneBinding::getMetatableName());
    bool result = instance->canHear(c, see);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SensoryDataBinding::disguiseMods(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float FOV = (float)luaL_checknumber(L, 3);
    bool result = instance->disguiseMods(c, FOV);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SensoryDataBinding::assessCrimes(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->assessCrimes(c);
    return 0;
}

int SensoryDataBinding::assessKidnapping(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->assessKidnapping(c);
    return 0;
}

int SensoryDataBinding::processKillList(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    instance->processKillList();
    return 0;
}

int SensoryDataBinding::assessNeutral(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool inDepth = lua_toboolean(L, 3) != 0;
    instance->assessNeutral(who, inDepth);
    return 0;
}

int SensoryDataBinding::updateMyProgressBar(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    float progress = (float)luaL_checknumber(L, 2);
    const std::string text = luaL_checkstring(L, 3);
    instance->updateMyProgressBar(progress, text);
    return 0;
}

int SensoryDataBinding::canISeeThisGuyDoinSneakingOrSomething(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float FOVScore = (float)luaL_checknumber(L, 3);
    SensoryData::SpottingPeopleMgr* memory = lua_isnoneornil(L, 4) ? nullptr : checkObject<SensoryData::SpottingPeopleMgr>(L, 4, SpottingPeopleMgrBinding::getMetatableName());
    float spotTimeMinFOV = (float)luaL_checknumber(L, 5);
    float spotTimeMaxFOV = (float)luaL_checknumber(L, 6);
    YesNoMaybe result = instance->canISeeThisGuyDoinSneakingOrSomething(who, FOVScore, memory, spotTimeMinFOV, spotTimeMaxFOV);
    return pushObject<YesNoMaybe>(L, &result, YesNoMaybeBinding::getMetatableName());
}

int SensoryDataBinding::isIntruder_Base(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->isIntruder_Base(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SensoryDataBinding::isIntruder_Building(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->isIntruder_Building(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SensoryDataBinding::isInMyPrivate_Building(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->isInMyPrivate_Building(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SensoryDataBinding::isEscapee(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->isEscapee(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SensoryDataBinding::reassess(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    SeenSomeone* sees = checkObject<SeenSomeone>(L, 3, SeenSomeoneBinding::getMetatableName());
    float time = (float)luaL_checknumber(L, 4);
    SeenSomeone* result = instance->reassess(c, sees, time);
    return pushObject<SeenSomeone>(L, result, SeenSomeoneBinding::getMetatableName());
}

int SensoryDataBinding::addToThreatsAndFlockingList(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->addToThreatsAndFlockingList(c);
    return 0;
}

int SensoryDataBinding::buildingSpotterUpdate(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");

    instance->buildingSpotterUpdate();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 126: void notifyCriminalThreat(...) - non-string reference arg
  line 131: StateBroadcastData* getStateBroadcastOf(...) - non-string reference arg
  line 139: bool _shareSensesCheck(...) - unsupported arg type
  line 193: void setupMyProgressBar(...) - non-string reference arg
  line 201: void reassessAll(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - SensoryDataBinding::getStateBroadcast: StateBroadcastData* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 115: seen (ogre_unordered_map<hand, SeenSomeone*>::type) - unsupported type
  line 127: threats (lektor<hand>) - unsupported type
  line 128: flockingList (Ogre::vector<VisibleObjectInfo>::type) - unsupported type
  line 154: hearTestTimers (std::map<hand, float, std::less<hand>, std::allocator<std::pair<hand const, float> > >) - unsupported type
  line 156: killList (ogre_unordered_set<hand>::type) - unsupported type
  line 160: assessList (ogre_unordered_set<hand>::type) - unsupported type
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



static int SensoryData__calculateFOVScore(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float res = instance->_calculateFOVScore(who);
    lua_pushnumber(L, res);
    return 1;
}


static int SensoryData__shareSensesCheck(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* leader = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lektor<RootObject*>* list = (lektor<RootObject*>*)lua_touserdata(L, 3);
    if (!list) return luaL_error(L, "Invalid lektor<RootObject*> userdata");
    float time = (float)luaL_checknumber(L, 4);
    bool res = instance->_shareSensesCheck(leader, *list, time);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


static int SensoryData__traceLineOfSightCheck(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool res = instance->_traceLineOfSightCheck(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


static int SensoryData_add(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool see = lua_toboolean(L, 3) != 0;
    bool hear = lua_toboolean(L, 4) != 0;
    SeenSomeone* res = instance->add(c, see, hear);
    return pushObject<SeenSomeone>(L, res, SeenSomeoneBinding::getMetatableName());
}


static int SensoryData_addToThreatsAndFlockingList(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->addToThreatsAndFlockingList(c);
    return 0;
}


static int SensoryData_amIAwareOfThisGuy(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool needToSeeOrHear = lua_toboolean(L, 3) != 0;
    bool res = instance->amIAwareOfThisGuy(who, needToSeeOrHear);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


static int SensoryData_assessCrimes(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->assessCrimes(c);
    return 0;
}


static int SensoryData_assessKidnapping(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->assessKidnapping(c);
    return 0;
}


static int SensoryData_assessNeutral(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool inDepth = lua_toboolean(L, 3) != 0;
    instance->assessNeutral(who, inDepth);
    return 0;
}


static int SensoryData_canHear(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    SeenSomeone* see = checkObject<SeenSomeone>(L, 3, SeenSomeoneBinding::getMetatableName());
    bool res = instance->canHear(c, see);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


static int SensoryData_canIHearThisGuy(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool res = instance->canIHearThisGuy(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


static int SensoryData_canISeeThisGuy(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool res = instance->canISeeThisGuy(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


static int SensoryData_canISeeThisGuyDoinSneakingOrSomething(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float FOVScore = (float)luaL_checknumber(L, 3);
    SensoryData::SpottingPeopleMgr* memory = checkObject<SensoryData::SpottingPeopleMgr>(L, 4, SpottingPeopleMgrBinding::getMetatableName());
    float spotTimeMinFOV = (float)luaL_checknumber(L, 5);
    float spotTimeMaxFOV = (float)luaL_checknumber(L, 6);
    YesNoMaybe res = instance->canISeeThisGuyDoinSneakingOrSomething(who, FOVScore, memory, spotTimeMinFOV, spotTimeMaxFOV);
    lua_pushinteger(L, (lua_Integer)res.key);
    return 1;
}


static int SensoryData_canSee(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    SeenSomeone* sees = checkObject<SeenSomeone>(L, 3, SeenSomeoneBinding::getMetatableName());
    bool res = instance->canSee(c, sees);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


static int SensoryData_decay(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->decay(c);
    return 0;
}


static int SensoryData_disguiseMods(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float FOV = (float)luaL_checknumber(L, 3);
    bool res = instance->disguiseMods(c, FOV);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


static int SensoryData_getDataFor(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    SeenSomeone* res = instance->getDataFor(who);
    return pushObject<SeenSomeone>(L, res, SeenSomeoneBinding::getMetatableName());
}


static int SensoryData_getFactionRelation(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    RootObjectBase* c = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    float res = instance->getFactionRelation(c);
    lua_pushnumber(L, res);
    return 1;
}


static int SensoryData_getGUIData(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    DatapanelGUI* panel = (DatapanelGUI*)lua_touserdata(L, 2);
    int cat = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(panel, cat);
    return 0;
}


static int SensoryData_getIterator(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    unsigned int tagsAny = (unsigned int)luaL_checkinteger(L, 2);
    unsigned int tagsNOT = (unsigned int)luaL_checkinteger(L, 3);
    SenseItr res = instance->getIterator(tagsAny, tagsNOT);
    SenseItr* copy = new SenseItr(res);
    return pushObject<SenseItr>(L, copy, SenseItrBinding::getMetatableName());
}


static int SensoryData_getLastKnownPositionOf(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Ogre::Vector3 res = instance->getLastKnownPositionOf(who);
    pushVector3(L, res);
    return 1;
}


static int SensoryData_getStateBroadcast(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    StateBroadcastData* res = instance->getStateBroadcast();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}


static int SensoryData_getStateBroadcastOf(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    hand* who = checkObject<hand>(L, 2, handBinding::getMetatableName());
    StateBroadcastData* res = instance->getStateBroadcastOf(*who);
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}


static int SensoryData_get_assessList(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushlightuserdata(L, &instance->assessList);
    return 1;
}


static int SensoryData_get_flockingList(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushlightuserdata(L, &instance->flockingList);
    return 1;
}


static int SensoryData_get_hearTestTimers(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushlightuserdata(L, &instance->hearTestTimers);
    return 1;
}


static int SensoryData_get_killList(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushlightuserdata(L, &instance->killList);
    return 1;
}


static int SensoryData_get_seen(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushlightuserdata(L, &instance->seen);
    return 1;
}


static int SensoryData_get_threats(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lua_pushlightuserdata(L, &instance->threats);
    return 1;
}


static int SensoryData_isEscapee(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool res = instance->isEscapee(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


static int SensoryData_isInMyPrivate_Building(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool res = instance->isInMyPrivate_Building(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


static int SensoryData_isIntruder_Base(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool res = instance->isIntruder_Base(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


static int SensoryData_isIntruder_Building(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool res = instance->isIntruder_Building(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


static int SensoryData_noticeThisPerson(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool alarmed = lua_toboolean(L, 3) != 0;
    instance->noticeThisPerson(c, alarmed);
    return 0;
}


static int SensoryData_notifyCriminalThreat(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->notifyCriminalThreat(*h);
    return 0;
}


static int SensoryData_reassess(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    SeenSomeone* sees = checkObject<SeenSomeone>(L, 3, SeenSomeoneBinding::getMetatableName());
    float time = (float)luaL_checknumber(L, 4);
    SeenSomeone* res = instance->reassess(c, sees, time);
    return pushObject<SeenSomeone>(L, res, SeenSomeoneBinding::getMetatableName());
}


static int SensoryData_reassessAll(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    lektor<RootObject*>* newTargets = (lektor<RootObject*>*)lua_touserdata(L, 2);
    if (!newTargets) return luaL_error(L, "Invalid lektor<RootObject*> userdata");
    float time = (float)luaL_checknumber(L, 3);
    instance->reassessAll(*newTargets, time);
    return 0;
}


static int SensoryData_remove(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->remove(c);
    return 0;
}


static int SensoryData_set_assessList(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "assessList is a read-only property");
}


static int SensoryData_set_flockingList(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "flockingList is a read-only property");
}


static int SensoryData_set_hearTestTimers(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "hearTestTimers is a read-only property");
}


static int SensoryData_set_killList(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "killList is a read-only property");
}


static int SensoryData_set_seen(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "seen is a read-only property");
}


static int SensoryData_set_threats(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    return luaL_error(L, "threats is a read-only property");
}


static int SensoryData_setupMyProgressBar(lua_State* L)
{
    SensoryData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SensoryData is nil");
    hand* who = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->setupMyProgressBar(*who);
    return 0;
}


void SensoryDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SensoryDataBinding::gc },
        { "__tostring", SensoryDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", SensoryDataBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", SensoryDataBinding::_DESTRUCTOR },
        { "periodicUpdate", SensoryDataBinding::periodicUpdate },
        { "periodicUpdate_KOed", SensoryDataBinding::periodicUpdate_KOed },
        { "getVisionRange", SensoryDataBinding::getVisionRange },
        { "update", SensoryDataBinding::update },
        { "notifyKO", SensoryDataBinding::notifyKO },
        { "getIterator", SensoryDataBinding::getIterator },
        { "getNearestEnemyDistanceSq", SensoryDataBinding::getNearestEnemyDistanceSq },
        { "canISeeThisGuy", SensoryDataBinding::canISeeThisGuy },
        { "canIHearThisGuy", SensoryDataBinding::canIHearThisGuy },
        { "amIAwareOfThisGuy", SensoryDataBinding::amIAwareOfThisGuy },
        { "getLastKnownPositionOf", SensoryDataBinding::getLastKnownPositionOf },
        { "getDataFor", SensoryDataBinding::getDataFor },
        { "getFactionRelation", SensoryDataBinding::getFactionRelation },
        { "getStateBroadcast", SensoryDataBinding::getStateBroadcast },
        { "getGUIData", SensoryDataBinding::getGUIData },
        { "_calculateFOVScore", SensoryDataBinding::_calculateFOVScore },
        { "_traceLineOfSightCheck", SensoryDataBinding::_traceLineOfSightCheck },
        { "getCharacter", SensoryDataBinding::getCharacter },
        { "dialogAssessmentUpdate", SensoryDataBinding::dialogAssessmentUpdate },
        { "noticeThisPerson", SensoryDataBinding::noticeThisPerson },
        { "add", SensoryDataBinding::add },
        { "remove", SensoryDataBinding::remove },
        { "decay", SensoryDataBinding::decay },
        { "canSee", SensoryDataBinding::canSee },
        { "canHear", SensoryDataBinding::canHear },
        { "disguiseMods", SensoryDataBinding::disguiseMods },
        { "assessCrimes", SensoryDataBinding::assessCrimes },
        { "assessKidnapping", SensoryDataBinding::assessKidnapping },
        { "processKillList", SensoryDataBinding::processKillList },
        { "assessNeutral", SensoryDataBinding::assessNeutral },
        { "updateMyProgressBar", SensoryDataBinding::updateMyProgressBar },
        { "canISeeThisGuyDoinSneakingOrSomething", SensoryDataBinding::canISeeThisGuyDoinSneakingOrSomething },
        { "isIntruder_Base", SensoryDataBinding::isIntruder_Base },
        { "isIntruder_Building", SensoryDataBinding::isIntruder_Building },
        { "isInMyPrivate_Building", SensoryDataBinding::isInMyPrivate_Building },
        { "isEscapee", SensoryDataBinding::isEscapee },
        { "reassess", SensoryDataBinding::reassess },
        { "addToThreatsAndFlockingList", SensoryDataBinding::addToThreatsAndFlockingList },
        { "buildingSpotterUpdate", SensoryDataBinding::buildingSpotterUpdate },
                { "notifyCriminalThreat", SensoryData_notifyCriminalThreat },
        { "getStateBroadcastOf", SensoryData_getStateBroadcastOf },
        { "_shareSensesCheck", SensoryData__shareSensesCheck },
        { "setupMyProgressBar", SensoryData_setupMyProgressBar },
        { "reassessAll", SensoryData_reassessAll },
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
    registerGetter(L, "nearestEnemy", SensoryData_get_nearestEnemy);
    registerGetter(L, "numUnconsciousAllies", SensoryData_get_numUnconsciousAllies);
    registerGetter(L, "numConsciousAllies", SensoryData_get_numConsciousAllies);
    registerGetter(L, "totalThreatLevelPersonal", SensoryData_get_totalThreatLevelPersonal);
    registerGetter(L, "totalThreatLevelAllies", SensoryData_get_totalThreatLevelAllies);
    registerGetter(L, "totalIntendedThreatLevelGeneral", SensoryData_get_totalIntendedThreatLevelGeneral);
    registerGetter(L, "numEnemies", SensoryData_get_numEnemies);
    registerGetter(L, "numNeutrals", SensoryData_get_numNeutrals);
    registerGetter(L, "lastThreat", SensoryData_get_lastThreat);
    registerGetter(L, "currentAssessIndex", SensoryData_get_currentAssessIndex);
    registerGetter(L, "currentAssessList", SensoryData_get_currentAssessList);
    registerGetter(L, "me", SensoryData_get_me);
    registerGetter(L, "spottedSneakingPeople", SensoryData_get_spottedSneakingPeople);
    registerGetter(L, "spottedSuspiciousPeople", SensoryData_get_spottedSuspiciousPeople);
    registerGetter(L, "progressBar", SensoryData_get_progressBar);
    registerGetter(L, "progressBarStillNeeded", SensoryData_get_progressBarStillNeeded);
    registerGetter(L, "spottedGuyIndexForProgressBar", SensoryData_get_spottedGuyIndexForProgressBar);
    registerGetter(L, "amSharingThisFrame", SensoryData_get_amSharingThisFrame);
        registerGetter(L, "assessList", SensoryData_get_assessList);
        registerGetter(L, "flockingList", SensoryData_get_flockingList);
        registerGetter(L, "hearTestTimers", SensoryData_get_hearTestTimers);
        registerGetter(L, "killList", SensoryData_get_killList);
        registerGetter(L, "seen", SensoryData_get_seen);
        registerGetter(L, "threats", SensoryData_get_threats);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "nearestEnemy", SensoryData_set_nearestEnemy);
    registerSetter(L, "numUnconsciousAllies", SensoryData_set_numUnconsciousAllies);
    registerSetter(L, "numConsciousAllies", SensoryData_set_numConsciousAllies);
    registerSetter(L, "totalThreatLevelPersonal", SensoryData_set_totalThreatLevelPersonal);
    registerSetter(L, "totalThreatLevelAllies", SensoryData_set_totalThreatLevelAllies);
    registerSetter(L, "totalIntendedThreatLevelGeneral", SensoryData_set_totalIntendedThreatLevelGeneral);
    registerSetter(L, "numEnemies", SensoryData_set_numEnemies);
    registerSetter(L, "numNeutrals", SensoryData_set_numNeutrals);
    registerSetter(L, "lastThreat", SensoryData_set_lastThreat);
    registerSetter(L, "currentAssessIndex", SensoryData_set_currentAssessIndex);
    registerSetter(L, "currentAssessList", SensoryData_set_currentAssessList);
    registerSetter(L, "me", SensoryData_set_me);
    registerSetter(L, "spottedSneakingPeople", SensoryData_set_spottedSneakingPeople);
    registerSetter(L, "spottedSuspiciousPeople", SensoryData_set_spottedSuspiciousPeople);
    registerSetter(L, "progressBar", SensoryData_set_progressBar);
    registerSetter(L, "progressBarStillNeeded", SensoryData_set_progressBarStillNeeded);
    registerSetter(L, "spottedGuyIndexForProgressBar", SensoryData_set_spottedGuyIndexForProgressBar);
    registerSetter(L, "amSharingThisFrame", SensoryData_set_amSharingThisFrame);
        registerSetter(L, "assessList", SensoryData_set_assessList);
        registerSetter(L, "flockingList", SensoryData_set_flockingList);
        registerSetter(L, "hearTestTimers", SensoryData_set_hearTestTimers);
        registerSetter(L, "killList", SensoryData_set_killList);
        registerSetter(L, "seen", SensoryData_set_seen);
        registerSetter(L, "threats", SensoryData_set_threats);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua