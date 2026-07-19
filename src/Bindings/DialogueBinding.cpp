#include "pch.h"
#include "kenshi\Dialogue.h"
#include "DialogueBinding.h"
#include "kenshi/Character.h"
#include "CharacterBinding.h"
#include "kenshi/CharStats.h"
#include "CharStatsBinding.h"
#include "RepetitionCounterBinding.h"
#include "DialogChoiceListBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/DialogChoiceListBinding.h"
#include "Bindings/RepetitionCounterBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/DialogLineDataBinding.h"
#include "kenshi/util/hand.h"

typedef Dialogue::RepetitionCounter RepetitionCounter;

namespace KenshiLua
{

static Dialogue* getB(lua_State* L, int idx)
{
    return checkObject<Dialogue>(L, idx, DialogueBinding::getMetatableName());
}

// --- Getters for Dialogue ---
static int Dialogue_get_repCounter(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return pushObject<RepetitionCounter>(L, &b->repCounter, RepetitionCounterBinding::getMetatableName());
}

static int Dialogue_get__needsDynamicAssessments(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    lua_pushboolean(L, b->_needsDynamicAssessments ? 1 : 0);
    return 1;
}

static int Dialogue_get_locked(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    // TODO: Unsupported type for locked (std::map<DialogLineData*, bool, std::less<DialogLineData*>, Ogre::STLAllocator<std::pair<DialogLineData*const, bool>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'locked' (type: std::map<DialogLineData*, bool, std::less<DialogLineData*>, Ogre::STLAllocator<std::pair<DialogLineData*const, bool>, Ogre::GeneralAllocPolicy > >)");
}

static int Dialogue_get_sayMsg(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    lua_pushstring(L, b->sayMsg.c_str());
    return 1;
}

static int Dialogue_get_threadMessages(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    // TODO: Unsupported type for threadMessages (Ogre::vector<Dialogue::DT_MSG>::type)
    return luaL_error(L, "Unsupported property 'threadMessages' (type: Ogre::vector<Dialogue::DT_MSG>::type)");
}

static int Dialogue_get_pacakgesIHave(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    // TODO: Unsupported type for pacakgesIHave (std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'pacakgesIHave' (type: std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::GeneralAllocPolicy > >)");
}

static int Dialogue_get_playerInterruptionDialog(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    // TODO: Unsupported type for playerInterruptionDialog (DialogLineData*)
    return luaL_error(L, "Unsupported property 'playerInterruptionDialog' (type: DialogLineData*)");
}

static int Dialogue_get_eventRepeatTimers(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    // TODO: Unsupported type for eventRepeatTimers (std::map<EventTriggerEnum, float, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, float>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'eventRepeatTimers' (type: std::map<EventTriggerEnum, float, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, float>, Ogre::GeneralAllocPolicy > >)");
}

static int Dialogue_get_eventDeliveredStates(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    // TODO: Unsupported type for eventDeliveredStates (std::map<EventTriggerEnum, hand, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, hand>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'eventDeliveredStates' (type: std::map<EventTriggerEnum, hand, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, hand>, Ogre::GeneralAllocPolicy > >)");
}

static int Dialogue_get__hasChanceLines(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    // TODO: Unsupported type for _hasChanceLines (std::map<DialogLineData*, bool, std::less<DialogLineData*>, Ogre::STLAllocator<std::pair<DialogLineData*const, bool>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property '_hasChanceLines' (type: std::map<DialogLineData*, bool, std::less<DialogLineData*>, Ogre::STLAllocator<std::pair<DialogLineData*const, bool>, Ogre::GeneralAllocPolicy > >)");
}

static int Dialogue_get__hasEnded(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    lua_pushboolean(L, b->_hasEnded ? 1 : 0);
    return 1;
}

static int Dialogue_get_shouting(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    lua_pushboolean(L, b->shouting ? 1 : 0);
    return 1;
}

static int Dialogue_get_staysOnScreen(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    lua_pushboolean(L, b->staysOnScreen ? 1 : 0);
    return 1;
}

static int Dialogue_get_me(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return pushObject<Character>(L, b->me, CharacterBinding::getMetatableName());
}

static int Dialogue_get_conversationTarget(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return handBinding::push(L, b->conversationTarget);
}

static int Dialogue_get_stats(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return pushObject<CharStats>(L, b->stats, CharStatsBinding::getMetatableName());
}

static int Dialogue_get_movement(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    // TODO: Unsupported type for movement (CharMovement*)
    return luaL_error(L, "Unsupported property 'movement' (type: CharMovement*)");
}

static int Dialogue_get_currentConversationType(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    lua_pushinteger(L, (lua_Integer)b->currentConversationType);
    return 1;
}

static int Dialogue_get_currentConversation(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    // TODO: Unsupported type for currentConversation (DialogLineData*)
    return luaL_error(L, "Unsupported property 'currentConversation' (type: DialogLineData*)");
}

static int Dialogue_get_currentLine(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    // TODO: Unsupported type for currentLine (DialogLineData*)
    return luaL_error(L, "Unsupported property 'currentLine' (type: DialogLineData*)");
}

static int Dialogue_get_conversationsMain(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    // TODO: Unsupported type for conversationsMain (std::map<EventTriggerEnum, DialogChoiceList*, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, DialogChoiceList*>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'conversationsMain' (type: std::map<EventTriggerEnum, DialogChoiceList*, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, DialogChoiceList*>, Ogre::GeneralAllocPolicy > >)");
}

static int Dialogue_get_interjector1(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return handBinding::push(L, b->interjector1);
}

static int Dialogue_get_interjector2(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return handBinding::push(L, b->interjector2);
}

static int Dialogue_get_interjector3(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return handBinding::push(L, b->interjector3);
}

static int Dialogue_get_speechBubblePanel(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    // TODO: Unsupported type for speechBubblePanel (DialogueSpeechBubble*)
    return luaL_error(L, "Unsupported property 'speechBubblePanel' (type: DialogueSpeechBubble*)");
}

static int Dialogue_get_speechTextTimer(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    lua_pushnumber(L, b->speechTextTimer);
    return 1;
}

static int Dialogue_get_speechTextTimer_forced(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    lua_pushnumber(L, b->speechTextTimer_forced);
    return 1;
}

static int Dialogue_get_replyIds(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    // TODO: Unsupported type for replyIds (Ogre::vector<std::string>::type)
    return luaL_error(L, "Unsupported property 'replyIds' (type: Ogre::vector<std::string>::type)");
}

static int Dialogue_get_responses(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    // TODO: Unsupported type for responses (Ogre::vector<std::string>::type)
    return luaL_error(L, "Unsupported property 'responses' (type: Ogre::vector<std::string>::type)");
}

static int Dialogue_get_npcReplyText(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    lua_pushstring(L, b->npcReplyText.c_str());
    return 1;
}

static int Dialogue_get_conversationMaster(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return handBinding::push(L, b->conversationMaster);
}

static int Dialogue_get_waitingForReplyFrom(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return handBinding::push(L, b->waitingForReplyFrom);
}

// --- Setters for Dialogue ---
static int Dialogue_set_repCounter(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    RepetitionCounter* val = checkObject<RepetitionCounter>(L, 2, RepetitionCounterBinding::getMetatableName());
    if (!val) return luaL_error(L, "RepetitionCounter is nil");
    b->repCounter = *val;
    return 0;
}

static int Dialogue_set__needsDynamicAssessments(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    b->_needsDynamicAssessments = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Dialogue_set_locked(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for locked");
}

static int Dialogue_set_sayMsg(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    b->sayMsg = luaL_checkstring(L, 2);
    return 0;
}

static int Dialogue_set_threadMessages(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for threadMessages");
}

static int Dialogue_set_pacakgesIHave(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for pacakgesIHave");
}

static int Dialogue_set_playerInterruptionDialog(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for playerInterruptionDialog");
}

static int Dialogue_set_eventRepeatTimers(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for eventRepeatTimers");
}

static int Dialogue_set_eventDeliveredStates(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for eventDeliveredStates");
}

static int Dialogue_set__hasChanceLines(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _hasChanceLines");
}

static int Dialogue_set__hasEnded(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    b->_hasEnded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Dialogue_set_shouting(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    b->shouting = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Dialogue_set_staysOnScreen(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    b->staysOnScreen = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Dialogue_set_me(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for me");
}

static int Dialogue_set_conversationTarget(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (val) {
        b->conversationTarget = *val;
    }
    return 0;
}

static int Dialogue_set_stats(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for stats");
}

static int Dialogue_set_movement(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for movement");
}

static int Dialogue_set_currentConversationType(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    b->currentConversationType = (EventTriggerEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int Dialogue_set_currentConversation(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for currentConversation");
}

static int Dialogue_set_currentLine(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for currentLine");
}

static int Dialogue_set_conversationsMain(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for conversationsMain");
}

static int Dialogue_set_interjector1(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->interjector1 = *val;
    return 0;
}

static int Dialogue_set_interjector2(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->interjector2 = *val;
    return 0;
}

static int Dialogue_set_interjector3(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->interjector3 = *val;
    return 0;
}

static int Dialogue_set_speechBubblePanel(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for speechBubblePanel");
}

static int Dialogue_set_speechTextTimer(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    b->speechTextTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Dialogue_set_speechTextTimer_forced(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    b->speechTextTimer_forced = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Dialogue_set_replyIds(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for replyIds");
}

static int Dialogue_set_responses(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    return luaL_error(L, "Read-only or unsupported setter type for responses");
}

static int Dialogue_set_npcReplyText(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    b->npcReplyText = luaL_checkstring(L, 2);
    return 0;
}

static int Dialogue_set_conversationMaster(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->conversationMaster = *val;
    return 0;
}

static int Dialogue_set_waitingForReplyFrom(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->waitingForReplyFrom = *val;
    return 0;
}

int DialogueBinding::setupWordSwaps(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    b->setupWordSwaps();
    return 0;
}

int DialogueBinding::_CONSTRUCTOR(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    Dialogue* result = b->_CONSTRUCTOR();
    return pushObject<Dialogue>(L, result, DialogueBinding::getMetatableName());
}

int DialogueBinding::_DESTRUCTOR(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    b->_DESTRUCTOR();
    return 0;
}

int DialogueBinding::getCharacter(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    Character* result = b->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int DialogueBinding::getConversationTarget(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    hand result = b->getConversationTarget();
    return handBinding::push(L, result);
}

int DialogueBinding::setInDialog(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->setInDialog(on);
    return 0;
}

int DialogueBinding::clearDialogues(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    b->clearDialogues();
    return 0;
}

int DialogueBinding::clearAnnouncements(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    b->clearAnnouncements();
    return 0;
}

int DialogueBinding::needsDialogAssessmentUpdate(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    bool result = b->needsDialogAssessmentUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::clearConversationList(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    EventTriggerEnum t = (EventTriggerEnum)luaL_checkinteger(L, 2);
    b->clearConversationList(t);
    return 0;
}

int DialogueBinding::willTalkToEnemies(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    bool result = b->willTalkToEnemies();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::stopEvent(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    EventTriggerEnum what = (EventTriggerEnum)luaL_checkinteger(L, 2);
    b->stopEvent(what);
    return 0;
}

int DialogueBinding::conversationHasEnded(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    bool result = b->conversationHasEnded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::conversationHasEndedPrettyMuch(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    bool result = b->conversationHasEndedPrettyMuch();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::update(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    b->update(frameTime);
    return 0;
}

int DialogueBinding::endDialogue(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    bool definitelyTheEnd = lua_toboolean(L, 2) != 0;
    b->endDialogue(definitelyTheEnd);
    return 0;
}

int DialogueBinding::hasDialogue_Fast(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    bool result = b->hasDialogue_Fast();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::hasDialogue_Accurate(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    bool result = b->hasDialogue_Accurate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::hasDialogueEvent(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    EventTriggerEnum e = (EventTriggerEnum)luaL_checkinteger(L, 2);
    bool result = b->hasDialogueEvent(e);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::dialogDelivered(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    EventTriggerEnum e = (EventTriggerEnum)luaL_checkinteger(L, 2);
    bool result = b->dialogDelivered(e);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::isKOExempt(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    EventTriggerEnum what = (EventTriggerEnum)luaL_checkinteger(L, 2);
    bool result = b->isKOExempt(what);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::_endPlayerConversation(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    bool finished = lua_toboolean(L, 2) != 0;
    b->_endPlayerConversation(finished);
    return 0;
}

int DialogueBinding::getConversationList(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    EventTriggerEnum t = (EventTriggerEnum)luaL_checkinteger(L, 2);
    DialogChoiceList* result = b->getConversationList(t);
    return pushObject<DialogChoiceList>(L, result, DialogChoiceListBinding::getMetatableName());
}

int DialogueBinding::listPlayerReplies(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    b->listPlayerReplies();
    return 0;
}

int DialogueBinding::_updateTextPos(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    b->_updateTextPos();
    return 0;
}

int DialogueBinding::clearSpeechBox(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    b->clearSpeechBox();
    return 0;
}

int DialogueBinding::clearRespones(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    b->clearRespones();
    return 0;
}

int DialogueBinding::clearResponesGUI(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    b->clearResponesGUI();
    return 0;
}

int DialogueBinding::setResponesGUI(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");

    b->setResponesGUI();
    return 0;
}

int DialogueBinding::setConversationReplyGUI(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    b->setConversationReplyGUI();
    return 0;
}

static int Dialogue_getHandle(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    hand result = b->getHandle();
    handBinding::push(L, result);
    return 1;
}

static int Dialogue_getConversationTarget(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    hand result = b->getConversationTarget();
    handBinding::push(L, result);
    return 1;
}

static int Dialogue_getSpeaker(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    TalkerEnum who = (TalkerEnum)luaL_checkinteger(L, 2);
    DialogLineData* line = checkObject<DialogLineData>(L, 3, DialogLineDataBinding::getMetatableName());
    bool isForWordswaps = lua_toboolean(L, 4) != 0;
    Character* result = b->getSpeaker(who, line, isForWordswaps);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

static int Dialogue_findInterjectionCharacter(lua_State* L)
{
    Dialogue* b = getB(L, 1);
    if (!b) return luaL_error(L, "Dialogue is nil");
    DialogLineData* line = checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    Character* result = b->findInterjectionCharacter(line);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 310: std::string getWordSwap(...) - unsupported arg type
  line 312: void _insertWordSwapsRecurse(...) - non-string reference arg
  line 333: void insertWordSwaps(...) - non-string reference arg
  line 334: void getGUIData(...) - unsupported arg type
  line 335: void create(...) - unsupported arg type
  line 338: void setLineLocked(...) - unsupported arg type
  line 339: bool isLocked(...) - unsupported arg type
  line 345: void addDialoguePackage(...) - unsupported arg type
  line 346: void addConversation(...) - unsupported arg type
  line 350: bool sendEventOverride(...) - unsupported arg type
  line 351: bool sendEvent(...) - unsupported arg type
  line 353: bool runCustomDialog(...) - unsupported arg type
  line 354: int scoreCustomDialog(...) - unsupported arg type
  line 357: void changeConversationTarget(...) - unsupported arg type
  line 359: bool makeAnnouncement(...) - unsupported arg type
  line 362: void notifyUnderAttack(...) - unsupported arg type
  line 366: void say(...) - overloaded method
  line 367: void say(...) - overloaded method
  line 369: bool _checkCondition(...) - unsupported arg type
  line 370: void dontLetTargetBeMe(...) - unsupported arg type
  line 371: bool isAtTownOf(...) - unsupported arg type
  line 372: bool hasThisChanceLine(...) - unsupported arg type
  line 373: DialogLineData* _chooseDialog(...) - unsupported return type
  line 374: void triggerNextLine(...) - unsupported arg type
  line 375: bool targetInTalkingRange(...) - unsupported arg type
  line 376: void save(...) - unsupported arg type
  line 377: void load(...) - unsupported arg type
  line 378: void replyClicked(...) - overloaded method
  line 379: void replyClicked(...) - overloaded method
  line 381: bool isCurrentConversationRunning(...) - unsupported arg type
  line 382: void resolveOverlappedSpeechBubbles(...) - static method
  line 383: void _wordSwapCharacterName(...) - non-string reference arg
  line 390: bool startPlayerConversation(...) - unsupported arg type
  line 391: bool startConversation(...) - unsupported arg type
  line 404: void _doActions(...) - unsupported arg type
  line 405: bool sayLine(...) - unsupported arg type
  line 407: bool isLastLine(...) - unsupported arg type
  line 408: void setSpeaker(...) - unsupported arg type
*/

int DialogueBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DialogueBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Dialogue object");
    return 1;
}

void DialogueBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogueBinding::gc },
        { "__tostring", DialogueBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setupWordSwaps", DialogueBinding::setupWordSwaps },
        { "_CONSTRUCTOR", DialogueBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", DialogueBinding::_DESTRUCTOR },
        { "getCharacter", DialogueBinding::getCharacter },
        { "getConversationTarget", DialogueBinding::getConversationTarget },
        { "setInDialog", DialogueBinding::setInDialog },
        { "clearDialogues", DialogueBinding::clearDialogues },
        { "clearAnnouncements", DialogueBinding::clearAnnouncements },
        { "needsDialogAssessmentUpdate", DialogueBinding::needsDialogAssessmentUpdate },
        { "clearConversationList", DialogueBinding::clearConversationList },
        { "willTalkToEnemies", DialogueBinding::willTalkToEnemies },
        { "stopEvent", DialogueBinding::stopEvent },
        { "conversationHasEnded", DialogueBinding::conversationHasEnded },
        { "conversationHasEndedPrettyMuch", DialogueBinding::conversationHasEndedPrettyMuch },
        { "update", DialogueBinding::update },
        { "endDialogue", DialogueBinding::endDialogue },
        { "hasDialogue_Fast", DialogueBinding::hasDialogue_Fast },
        { "hasDialogue_Accurate", DialogueBinding::hasDialogue_Accurate },
        { "hasDialogueEvent", DialogueBinding::hasDialogueEvent },
        { "dialogDelivered", DialogueBinding::dialogDelivered },
        { "isKOExempt", DialogueBinding::isKOExempt },
        { "_endPlayerConversation", DialogueBinding::_endPlayerConversation },
        { "getConversationList", DialogueBinding::getConversationList },
        { "listPlayerReplies", DialogueBinding::listPlayerReplies },
        { "_updateTextPos", DialogueBinding::_updateTextPos },
        { "clearSpeechBox", DialogueBinding::clearSpeechBox },
        { "clearRespones", DialogueBinding::clearRespones },
        { "clearResponesGUI", DialogueBinding::clearResponesGUI },
        { "setResponesGUI", DialogueBinding::setResponesGUI },
        { "setConversationReplyGUI", DialogueBinding::setConversationReplyGUI },
        { "getHandle", Dialogue_getHandle },
        { "getConversationTarget", Dialogue_getConversationTarget },
        { "getSpeaker", Dialogue_getSpeaker },
        { "findInterjectionCharacter", Dialogue_findInterjectionCharacter },
        { 0, 0 }
    };

    registerClass(
        L, 
        DialogueBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DialogueBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, Dialogue_get_repCounter);
    lua_setfield(L, -2, "repCounter");
    lua_pushcfunction(L, Dialogue_get__needsDynamicAssessments);
    lua_setfield(L, -2, "_needsDynamicAssessments");
    lua_pushcfunction(L, Dialogue_get_locked);
    lua_setfield(L, -2, "locked");
    lua_pushcfunction(L, Dialogue_get_sayMsg);
    lua_setfield(L, -2, "sayMsg");
    lua_pushcfunction(L, Dialogue_get_threadMessages);
    lua_setfield(L, -2, "threadMessages");
    lua_pushcfunction(L, Dialogue_get_pacakgesIHave);
    lua_setfield(L, -2, "pacakgesIHave");
    lua_pushcfunction(L, Dialogue_get_playerInterruptionDialog);
    lua_setfield(L, -2, "playerInterruptionDialog");
    lua_pushcfunction(L, Dialogue_get_eventRepeatTimers);
    lua_setfield(L, -2, "eventRepeatTimers");
    lua_pushcfunction(L, Dialogue_get_eventDeliveredStates);
    lua_setfield(L, -2, "eventDeliveredStates");
    lua_pushcfunction(L, Dialogue_get__hasChanceLines);
    lua_setfield(L, -2, "_hasChanceLines");
    lua_pushcfunction(L, Dialogue_get__hasEnded);
    lua_setfield(L, -2, "_hasEnded");
    lua_pushcfunction(L, Dialogue_get_shouting);
    lua_setfield(L, -2, "shouting");
    lua_pushcfunction(L, Dialogue_get_staysOnScreen);
    lua_setfield(L, -2, "staysOnScreen");
    lua_pushcfunction(L, Dialogue_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, Dialogue_get_conversationTarget);
    lua_setfield(L, -2, "conversationTarget");
    lua_pushcfunction(L, Dialogue_get_stats);
    lua_setfield(L, -2, "stats");
    lua_pushcfunction(L, Dialogue_get_movement);
    lua_setfield(L, -2, "movement");
    lua_pushcfunction(L, Dialogue_get_currentConversationType);
    lua_setfield(L, -2, "currentConversationType");
    lua_pushcfunction(L, Dialogue_get_currentConversation);
    lua_setfield(L, -2, "currentConversation");
    lua_pushcfunction(L, Dialogue_get_currentLine);
    lua_setfield(L, -2, "currentLine");
    lua_pushcfunction(L, Dialogue_get_conversationsMain);
    lua_setfield(L, -2, "conversationsMain");
    lua_pushcfunction(L, Dialogue_get_interjector1);
    lua_setfield(L, -2, "interjector1");
    lua_pushcfunction(L, Dialogue_get_interjector2);
    lua_setfield(L, -2, "interjector2");
    lua_pushcfunction(L, Dialogue_get_interjector3);
    lua_setfield(L, -2, "interjector3");
    lua_pushcfunction(L, Dialogue_get_speechBubblePanel);
    lua_setfield(L, -2, "speechBubblePanel");
    lua_pushcfunction(L, Dialogue_get_speechTextTimer);
    lua_setfield(L, -2, "speechTextTimer");
    lua_pushcfunction(L, Dialogue_get_speechTextTimer_forced);
    lua_setfield(L, -2, "speechTextTimer_forced");
    lua_pushcfunction(L, Dialogue_get_replyIds);
    lua_setfield(L, -2, "replyIds");
    lua_pushcfunction(L, Dialogue_get_responses);
    lua_setfield(L, -2, "responses");
    lua_pushcfunction(L, Dialogue_get_npcReplyText);
    lua_setfield(L, -2, "npcReplyText");
    lua_pushcfunction(L, Dialogue_get_conversationMaster);
    lua_setfield(L, -2, "conversationMaster");
    lua_pushcfunction(L, Dialogue_get_waitingForReplyFrom);
    lua_setfield(L, -2, "waitingForReplyFrom");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Dialogue_set_repCounter);
    lua_setfield(L, -2, "repCounter");
    lua_pushcfunction(L, Dialogue_set__needsDynamicAssessments);
    lua_setfield(L, -2, "_needsDynamicAssessments");
    lua_pushcfunction(L, Dialogue_set_locked);
    lua_setfield(L, -2, "locked");
    lua_pushcfunction(L, Dialogue_set_sayMsg);
    lua_setfield(L, -2, "sayMsg");
    lua_pushcfunction(L, Dialogue_set_threadMessages);
    lua_setfield(L, -2, "threadMessages");
    lua_pushcfunction(L, Dialogue_set_pacakgesIHave);
    lua_setfield(L, -2, "pacakgesIHave");
    lua_pushcfunction(L, Dialogue_set_playerInterruptionDialog);
    lua_setfield(L, -2, "playerInterruptionDialog");
    lua_pushcfunction(L, Dialogue_set_eventRepeatTimers);
    lua_setfield(L, -2, "eventRepeatTimers");
    lua_pushcfunction(L, Dialogue_set_eventDeliveredStates);
    lua_setfield(L, -2, "eventDeliveredStates");
    lua_pushcfunction(L, Dialogue_set__hasChanceLines);
    lua_setfield(L, -2, "_hasChanceLines");
    lua_pushcfunction(L, Dialogue_set__hasEnded);
    lua_setfield(L, -2, "_hasEnded");
    lua_pushcfunction(L, Dialogue_set_shouting);
    lua_setfield(L, -2, "shouting");
    lua_pushcfunction(L, Dialogue_set_staysOnScreen);
    lua_setfield(L, -2, "staysOnScreen");
    lua_pushcfunction(L, Dialogue_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, Dialogue_set_conversationTarget);
    lua_setfield(L, -2, "conversationTarget");
    lua_pushcfunction(L, Dialogue_set_stats);
    lua_setfield(L, -2, "stats");
    lua_pushcfunction(L, Dialogue_set_movement);
    lua_setfield(L, -2, "movement");
    lua_pushcfunction(L, Dialogue_set_currentConversationType);
    lua_setfield(L, -2, "currentConversationType");
    lua_pushcfunction(L, Dialogue_set_currentConversation);
    lua_setfield(L, -2, "currentConversation");
    lua_pushcfunction(L, Dialogue_set_currentLine);
    lua_setfield(L, -2, "currentLine");
    lua_pushcfunction(L, Dialogue_set_conversationsMain);
    lua_setfield(L, -2, "conversationsMain");
    lua_pushcfunction(L, Dialogue_set_interjector1);
    lua_setfield(L, -2, "interjector1");
    lua_pushcfunction(L, Dialogue_set_interjector2);
    lua_setfield(L, -2, "interjector2");
    lua_pushcfunction(L, Dialogue_set_interjector3);
    lua_setfield(L, -2, "interjector3");
    lua_pushcfunction(L, Dialogue_set_speechBubblePanel);
    lua_setfield(L, -2, "speechBubblePanel");
    lua_pushcfunction(L, Dialogue_set_speechTextTimer);
    lua_setfield(L, -2, "speechTextTimer");
    lua_pushcfunction(L, Dialogue_set_speechTextTimer_forced);
    lua_setfield(L, -2, "speechTextTimer_forced");
    lua_pushcfunction(L, Dialogue_set_replyIds);
    lua_setfield(L, -2, "replyIds");
    lua_pushcfunction(L, Dialogue_set_responses);
    lua_setfield(L, -2, "responses");
    lua_pushcfunction(L, Dialogue_set_npcReplyText);
    lua_setfield(L, -2, "npcReplyText");
    lua_pushcfunction(L, Dialogue_set_conversationMaster);
    lua_setfield(L, -2, "conversationMaster");
    lua_pushcfunction(L, Dialogue_set_waitingForReplyFrom);
    lua_setfield(L, -2, "waitingForReplyFrom");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
