#include "pch.h"
#include "kenshi/Dialogue.h"
#include "DialogueBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharMovementBinding.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/DialogChoiceListBinding.h"
#include "Bindings/DialogLineDataBinding.h"
#include "Bindings/DialogueSpeechBubbleBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/RepetitionCounterBinding.h"
#include "Bindings/Util/StdMapBinding.h"

namespace KenshiLua
{

typedef StdMapBinding<DialogLineData*, bool> DialogLineDataBoolMapBinding;
typedef StdMapBinding<EventTriggerEnum, float> EventRepeatTimersMapBinding;
typedef StdMapBinding<EventTriggerEnum, hand> EventDeliveredStatesMapBinding;
typedef StdMapBinding<EventTriggerEnum, DialogChoiceList*> ConversationsMainMapBinding;

static Dialogue* getInstance(lua_State* L, int idx)
{
    return checkObject<Dialogue>(L, idx, DialogueBinding::getMetatableName());
}

// --- Getters for Dialogue ---
static int Dialogue_get_repCounter(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return pushObject<Dialogue::RepetitionCounter>(L, &instance->repCounter, RepetitionCounterBinding::getMetatableName());
}

static int Dialogue_get__needsDynamicAssessments(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    lua_pushboolean(L, instance->_needsDynamicAssessments ? 1 : 0);
    return 1;
}

static int Dialogue_get_sayMsg(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    lua_pushstring(L, instance->sayMsg.c_str());
    return 1;
}

static int Dialogue_get_playerInterruptionDialog(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return pushObject<DialogLineData>(L, instance->playerInterruptionDialog, DialogLineDataBinding::getMetatableName());
}

static int Dialogue_get__hasEnded(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    lua_pushboolean(L, instance->_hasEnded ? 1 : 0);
    return 1;
}

static int Dialogue_get_shouting(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    lua_pushboolean(L, instance->shouting ? 1 : 0);
    return 1;
}

static int Dialogue_get_staysOnScreen(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    lua_pushboolean(L, instance->staysOnScreen ? 1 : 0);
    return 1;
}

static int Dialogue_get_me(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int Dialogue_get_conversationTarget(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return HandBinding::push(L, instance->conversationTarget);
}

static int Dialogue_get_stats(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return pushObject<CharStats>(L, instance->stats, CharStatsBinding::getMetatableName());
}

static int Dialogue_get_movement(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return pushObject<CharMovement>(L, instance->movement, CharMovementBinding::getMetatableName());
}

static int Dialogue_get_currentConversationType(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentConversationType);
    return 1;
}

static int Dialogue_get_currentConversation(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return pushObject<DialogLineData>(L, instance->currentConversation, DialogLineDataBinding::getMetatableName());
}

static int Dialogue_get_currentLine(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return pushObject<DialogLineData>(L, instance->currentLine, DialogLineDataBinding::getMetatableName());
}

static int Dialogue_get_interjector1(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return HandBinding::push(L, instance->interjector1);
}

static int Dialogue_get_interjector2(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return HandBinding::push(L, instance->interjector2);
}

static int Dialogue_get_interjector3(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return HandBinding::push(L, instance->interjector3);
}

static int Dialogue_get_speechBubblePanel(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return pushObject<DialogueSpeechBubble>(L, instance->speechBubblePanel, DialogueSpeechBubbleBinding::getMetatableName());
}

static int Dialogue_get_speechTextTimer(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    lua_pushnumber(L, instance->speechTextTimer);
    return 1;
}

static int Dialogue_get_speechTextTimer_forced(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    lua_pushnumber(L, instance->speechTextTimer_forced);
    return 1;
}

static int Dialogue_get_npcReplyText(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    lua_pushstring(L, instance->npcReplyText.c_str());
    return 1;
}

static int Dialogue_get_conversationMaster(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return HandBinding::push(L, instance->conversationMaster);
}

static int Dialogue_get_waitingForReplyFrom(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return HandBinding::push(L, instance->waitingForReplyFrom);
}

static int Dialogue_get_pacakgesIHave(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    lua_newtable(L);
    int i = 1;
    for (std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::GeneralAllocPolicy>>::const_iterator it = instance->pacakgesIHave.begin(); it != instance->pacakgesIHave.end(); ++it)
    {
        pushObject<GameData>(L, *it, GameDataBinding::getMetatableName());
        lua_rawseti(L, -2, i++);
    }
    return 1;
}

static int Dialogue_get_locked(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return pushObject<DialogLineDataBoolMapBinding::MapType>(L, &instance->locked, DialogLineDataBoolMapBinding::metaName);
}

static int Dialogue_get__hasChanceLines(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return pushObject<DialogLineDataBoolMapBinding::MapType>(L, &instance->_hasChanceLines, DialogLineDataBoolMapBinding::metaName);
}

static int Dialogue_get_eventRepeatTimers(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return pushObject<EventRepeatTimersMapBinding::MapType>(L, &instance->eventRepeatTimers, EventRepeatTimersMapBinding::metaName);
}

static int Dialogue_get_eventDeliveredStates(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return pushObject<EventDeliveredStatesMapBinding::MapType>(L, &instance->eventDeliveredStates, EventDeliveredStatesMapBinding::metaName);
}

static int Dialogue_get_conversationsMain(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    return pushObject<ConversationsMainMapBinding::MapType>(L, &instance->conversationsMain, ConversationsMainMapBinding::metaName);
}

static int Dialogue_get_threadMessages(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    lua_newtable(L);
    for (size_t i = 0; i < instance->threadMessages.size(); ++i)
    {
        lua_pushinteger(L, (lua_Integer)instance->threadMessages[i]);
        lua_rawseti(L, -2, (int)i + 1);
    }
    return 1;
}

static int Dialogue_get_replyIds(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    lua_newtable(L);
    for (size_t i = 0; i < instance->replyIds.size(); ++i)
    {
        lua_pushstring(L, instance->replyIds[i].c_str());
        lua_rawseti(L, -2, (int)i + 1);
    }
    return 1;
}

static int Dialogue_get_responses(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    lua_newtable(L);
    for (size_t i = 0; i < instance->responses.size(); ++i)
    {
        lua_pushstring(L, instance->responses[i].c_str());
        lua_rawseti(L, -2, (int)i + 1);
    }
    return 1;
}

// --- Setters for Dialogue ---
static int Dialogue_set_repCounter(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->repCounter = *checkObject<Dialogue::RepetitionCounter>(L, 2, RepetitionCounterBinding::getMetatableName());
    return 0;
}

static int Dialogue_set_pacakgesIHave(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->pacakgesIHave.clear();
    if (lua_istable(L, 2)) {
        int len = (int)lua_objlen(L, 2);
        for (int i = 1; i <= len; ++i) {
            lua_rawgeti(L, 2, i);
            GameData* gd = checkObject<GameData>(L, -1, GameDataBinding::getMetatableName());
            if (gd) instance->pacakgesIHave.insert(gd);
            lua_pop(L, 1);
        }
    }
    return 0;
}

static int Dialogue_set_locked(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    auto* val = DialogLineDataBoolMapBinding::get(L, 2);
    if (!val) return luaL_error(L, "Expected DialogLineDataBoolMap object");
    instance->locked = *val;
    return 0;
}

static int Dialogue_set__hasChanceLines(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    auto* val = DialogLineDataBoolMapBinding::get(L, 2);
    if (!val) return luaL_error(L, "Expected DialogLineDataBoolMap object");
    instance->_hasChanceLines = *val;
    return 0;
}

static int Dialogue_set_eventRepeatTimers(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    auto* val = EventRepeatTimersMapBinding::get(L, 2);
    if (!val) return luaL_error(L, "Expected EventRepeatTimersMap object");
    instance->eventRepeatTimers = *val;
    return 0;
}

static int Dialogue_set_eventDeliveredStates(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    auto* val = EventDeliveredStatesMapBinding::get(L, 2);
    if (!val) return luaL_error(L, "Expected EventDeliveredStatesMap object");
    instance->eventDeliveredStates = *val;
    return 0;
}

static int Dialogue_set_conversationsMain(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    auto* val = ConversationsMainMapBinding::get(L, 2);
    if (!val) return luaL_error(L, "Expected ConversationsMainMap object");
    instance->conversationsMain = *val;
    return 0;
}

static int Dialogue_set_threadMessages(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->threadMessages.clear();
    if (lua_istable(L, 2))
    {
        int len = (int)lua_objlen(L, 2);
        for (int i = 1; i <= len; ++i)
        {
            lua_rawgeti(L, 2, i);
            instance->threadMessages.push_back((Dialogue::DT_MSG)luaL_checkinteger(L, -1));
            lua_pop(L, 1);
        }
    }
    return 0;
}

static int Dialogue_set_replyIds(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->replyIds.clear();
    if (lua_istable(L, 2))
    {
        int len = (int)lua_objlen(L, 2);
        for (int i = 1; i <= len; ++i)
        {
            lua_rawgeti(L, 2, i);
            instance->replyIds.push_back(luaL_optstring(L, -1, ""));
            lua_pop(L, 1);
        }
    }
    return 0;
}

static int Dialogue_set_responses(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->responses.clear();
    if (lua_istable(L, 2))
    {
        int len = (int)lua_objlen(L, 2);
        for (int i = 1; i <= len; ++i)
        {
            lua_rawgeti(L, 2, i);
            instance->responses.push_back(luaL_optstring(L, -1, ""));
            lua_pop(L, 1);
        }
    }
    return 0;
}

static int Dialogue_set__needsDynamicAssessments(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->_needsDynamicAssessments = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Dialogue_set_sayMsg(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->sayMsg = luaL_checkstring(L, 2);
    return 0;
}

static int Dialogue_set_playerInterruptionDialog(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->playerInterruptionDialog = lua_isnoneornil(L, 2) ? nullptr : checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    return 0;
}

static int Dialogue_set__hasEnded(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->_hasEnded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Dialogue_set_shouting(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->shouting = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Dialogue_set_staysOnScreen(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->staysOnScreen = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Dialogue_set_me(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int Dialogue_set_conversationTarget(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->conversationTarget = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int Dialogue_set_stats(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->stats = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharStats>(L, 2, CharStatsBinding::getMetatableName());
    return 0;
}

static int Dialogue_set_movement(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->movement = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharMovement>(L, 2, CharMovementBinding::getMetatableName());
    return 0;
}

static int Dialogue_set_currentConversationType(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->currentConversationType = (EventTriggerEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int Dialogue_set_currentConversation(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->currentConversation = lua_isnoneornil(L, 2) ? nullptr : checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    return 0;
}

static int Dialogue_set_currentLine(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->currentLine = lua_isnoneornil(L, 2) ? nullptr : checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    return 0;
}

static int Dialogue_set_interjector1(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->interjector1 = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int Dialogue_set_interjector2(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->interjector2 = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int Dialogue_set_interjector3(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->interjector3 = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int Dialogue_set_speechBubblePanel(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->speechBubblePanel = lua_isnoneornil(L, 2) ? nullptr : checkObject<DialogueSpeechBubble>(L, 2, DialogueSpeechBubbleBinding::getMetatableName());
    return 0;
}

static int Dialogue_set_speechTextTimer(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->speechTextTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Dialogue_set_speechTextTimer_forced(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->speechTextTimer_forced = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Dialogue_set_npcReplyText(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->npcReplyText = luaL_checkstring(L, 2);
    return 0;
}

static int Dialogue_set_conversationMaster(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->conversationMaster = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int Dialogue_set_waitingForReplyFrom(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");
    instance->waitingForReplyFrom = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

int DialogueBinding::getWordSwap(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    const std::string key = luaL_checkstring(L, 2);
    Character* _target = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool _a3 = lua_toboolean(L, 4) != 0;
    DialogLineData* _line = checkObject<DialogLineData>(L, 5, DialogLineDataBinding::getMetatableName());
    std::string result = instance->getWordSwap(key, _target, _a3, _line);
    lua_pushstring(L, result.c_str());
    return 1;
}

int DialogueBinding::setupWordSwaps(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    instance->setupWordSwaps();
    return 0;
}

int DialogueBinding::_CONSTRUCTOR(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    Dialogue* result = instance->_CONSTRUCTOR();
    return pushObject<Dialogue>(L, result, DialogueBinding::getMetatableName());
}

int DialogueBinding::_DESTRUCTOR(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int DialogueBinding::getGUIData(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int cat = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(datapanel, cat);
    return 0;
}

int DialogueBinding::create(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    CharStats* s = checkObject<CharStats>(L, 3, CharStatsBinding::getMetatableName());
    CharMovement* m = checkObject<CharMovement>(L, 4, CharMovementBinding::getMetatableName());
    instance->create(c, s, m);
    return 0;
}

int DialogueBinding::getHandle(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    hand result = instance->getHandle();
    return HandBinding::push(L, result);
}

int DialogueBinding::getCharacter(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    Character* result = instance->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int DialogueBinding::setLineLocked(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    DialogLineData* line = checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    bool on = lua_toboolean(L, 3) != 0;
    instance->setLineLocked(line, on);
    return 0;
}

int DialogueBinding::isLocked(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    DialogLineData* line = checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    bool result = instance->isLocked(line);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::setInDialog(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setInDialog(on);
    return 0;
}

int DialogueBinding::clearDialogues(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    instance->clearDialogues();
    return 0;
}

int DialogueBinding::clearAnnouncements(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    instance->clearAnnouncements();
    return 0;
}

int DialogueBinding::needsDialogAssessmentUpdate(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    bool result = instance->needsDialogAssessmentUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::addDialoguePackage(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    GameData* _con = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->addDialoguePackage(_con);
    return 0;
}

int DialogueBinding::addConversation(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    GameData* _con = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    EventTriggerEnum t = (EventTriggerEnum)luaL_checkinteger(L, 3);
    instance->addConversation(_con, t);
    return 0;
}

int DialogueBinding::clearConversationList(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    EventTriggerEnum t = (EventTriggerEnum)luaL_checkinteger(L, 2);
    instance->clearConversationList(t);
    return 0;
}

int DialogueBinding::willTalkToEnemies(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    bool result = instance->willTalkToEnemies();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::sendEventOverride(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    EventTriggerEnum what = (EventTriggerEnum)luaL_checkinteger(L, 3);
    bool forceRepeat = lua_toboolean(L, 4) != 0;
    bool result = instance->sendEventOverride(who, what, forceRepeat);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::sendEvent(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    EventTriggerEnum what = (EventTriggerEnum)luaL_checkinteger(L, 3);
    bool result = instance->sendEvent(who, what);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::stopEvent(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    EventTriggerEnum what = (EventTriggerEnum)luaL_checkinteger(L, 2);
    instance->stopEvent(what);
    return 0;
}

int DialogueBinding::runCustomDialog(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    GameData* dialog = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->runCustomDialog(dialog);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::scoreCustomDialog(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    GameData* dialog = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int result = instance->scoreCustomDialog(dialog);
    lua_pushinteger(L, result);
    return 1;
}

int DialogueBinding::conversationHasEnded(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    bool result = instance->conversationHasEnded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::getConversationTarget(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    hand result = instance->getConversationTarget();
    return HandBinding::push(L, result);
}

int DialogueBinding::changeConversationTarget(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->changeConversationTarget(c);
    return 0;
}

int DialogueBinding::conversationHasEndedPrettyMuch(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    bool result = instance->conversationHasEndedPrettyMuch();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::makeAnnouncement(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->makeAnnouncement(dat);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::update(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    instance->update(frameTime);
    return 0;
}

int DialogueBinding::endDialogue(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    bool definitelyTheEnd = lua_toboolean(L, 2) != 0;
    instance->endDialogue(definitelyTheEnd);
    return 0;
}

int DialogueBinding::notifyUnderAttack(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    Character* attacker = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->notifyUnderAttack(attacker);
    return 0;
}

int DialogueBinding::hasDialogue_Fast(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    bool result = instance->hasDialogue_Fast();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::hasDialogue_Accurate(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    bool result = instance->hasDialogue_Accurate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::hasDialogueEvent(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    EventTriggerEnum e = (EventTriggerEnum)luaL_checkinteger(L, 2);
    bool result = instance->hasDialogueEvent(e);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::dialogDelivered(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    EventTriggerEnum e = (EventTriggerEnum)luaL_checkinteger(L, 2);
    bool result = instance->dialogDelivered(e);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::_checkCondition(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    DialogConditionEnum conditionName = (DialogConditionEnum)luaL_checkinteger(L, 2);
    ComparisonEnum compareBy = (ComparisonEnum)luaL_checkinteger(L, 3);
    int val = (int)luaL_checkinteger(L, 4);
    Character* target = checkObject<Character>(L, 5, CharacterBinding::getMetatableName());
    Character* actualConversationTarget = checkObject<Character>(L, 6, CharacterBinding::getMetatableName());
    bool result = instance->_checkCondition(conditionName, compareBy, val, target, actualConversationTarget);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::dontLetTargetBeMe(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    Character* targetObj = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Character* actualTarget = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    Character* tempTarget = targetObj;
    instance->dontLetTargetBeMe(&tempTarget, actualTarget);
    return 0;
}

int DialogueBinding::hasThisChanceLine(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    DialogLineData* line = checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    float chance = (float)luaL_checknumber(L, 3);
    bool result = instance->hasThisChanceLine(line, chance);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::_chooseDialog(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    DialogChoiceList* list = checkObject<DialogChoiceList>(L, 2, DialogChoiceListBinding::getMetatableName());
    Character* target = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool isWordswap = lua_toboolean(L, 4) != 0;
    DialogLineData* result = instance->_chooseDialog(list, target, isWordswap);
    return pushObject<DialogLineData>(L, result, DialogLineDataBinding::getMetatableName());
}

int DialogueBinding::triggerNextLine(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    DialogLineData* previousLine = checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    instance->triggerNextLine(previousLine);
    return 0;
}

int DialogueBinding::targetInTalkingRange(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float mult = (float)luaL_checknumber(L, 3);
    bool result = instance->targetInTalkingRange(target, mult);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::save(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    GameData* to = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->save(to);
    return 0;
}

int DialogueBinding::load(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    GameData* to = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->load(to);
    return 0;
}

int DialogueBinding::getSpeaker(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    TalkerEnum who = (TalkerEnum)luaL_checkinteger(L, 2);
    DialogLineData* line = checkObject<DialogLineData>(L, 3, DialogLineDataBinding::getMetatableName());
    bool isForWordswaps = lua_toboolean(L, 4) != 0;
    Character* result = instance->getSpeaker(who, line, isForWordswaps);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int DialogueBinding::isCurrentConversationRunning(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    DialogLineData* line = checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    bool result = instance->isCurrentConversationRunning(line);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::findInterjectionCharacter(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    DialogLineData* line = checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    Character* result = instance->findInterjectionCharacter(line);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int DialogueBinding::isKOExempt(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    EventTriggerEnum what = (EventTriggerEnum)luaL_checkinteger(L, 2);
    bool result = instance->isKOExempt(what);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::_endPlayerConversation(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    bool finished = lua_toboolean(L, 2) != 0;
    instance->_endPlayerConversation(finished);
    return 0;
}

int DialogueBinding::startPlayerConversation(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    DialogLineData* _talk = checkObject<DialogLineData>(L, 3, DialogLineDataBinding::getMetatableName());
    bool result = instance->startPlayerConversation(target, _talk);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::startConversation(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    DialogLineData* _talk = checkObject<DialogLineData>(L, 3, DialogLineDataBinding::getMetatableName());
    EventTriggerEnum ev = (EventTriggerEnum)luaL_checkinteger(L, 4);
    bool force = lua_toboolean(L, 5) != 0;
    bool result = instance->startConversation(target, _talk, ev, force);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::getConversationList(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    EventTriggerEnum t = (EventTriggerEnum)luaL_checkinteger(L, 2);
    DialogChoiceList* result = instance->getConversationList(t);
    return pushObject<DialogChoiceList>(L, result, DialogChoiceListBinding::getMetatableName());
}

int DialogueBinding::_doActions(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    DialogLineData* dialogLine = checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    instance->_doActions(dialogLine);
    return 0;
}

int DialogueBinding::sayLine(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    DialogLineData* line = checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    bool result = instance->sayLine(line);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::listPlayerReplies(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    instance->listPlayerReplies();
    return 0;
}

int DialogueBinding::isLastLine(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    DialogLineData* dialogLine = checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    bool result = instance->isLastLine(dialogLine);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::setSpeaker(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    TalkerEnum who = (TalkerEnum)luaL_checkinteger(L, 2);
    Character* c = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    instance->setSpeaker(who, c);
    return 0;
}

int DialogueBinding::_updateTextPos(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    instance->_updateTextPos();
    return 0;
}

int DialogueBinding::clearSpeechBox(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    instance->clearSpeechBox();
    return 0;
}

int DialogueBinding::clearRespones(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    instance->clearRespones();
    return 0;
}

int DialogueBinding::clearResponesGUI(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    instance->clearResponesGUI();
    return 0;
}

int DialogueBinding::setResponesGUI(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    instance->setResponesGUI();
    return 0;
}

int DialogueBinding::setConversationReplyGUI(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    instance->setConversationReplyGUI();
    return 0;
}

int DialogueBinding::say(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    if (lua_isstring(L, 2))
    {
        const std::string text = luaL_checkstring(L, 2);
        DialogLineData* line = checkObject<DialogLineData>(L, 3, DialogLineDataBinding::getMetatableName());
        instance->say(text, line);
    }
    else
    {
        DialogLineData* dialogLine = checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
        instance->say(dialogLine);
    }
    return 0;
}

int DialogueBinding::replyClicked(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    if (lua_isnumber(L, 2))
    {
        int index = (int)luaL_checkinteger(L, 2);
        instance->replyClicked(index);
    }
    else
    {
        const std::string index = luaL_checkstring(L, 2);
        instance->replyClicked(index);
    }
    return 0;
}

int DialogueBinding::isAtTownOf(lua_State* L)
{
    Dialogue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Dialogue is nil");

    std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy>> f;
    if (lua_istable(L, 2))
    {
        int len = (int)lua_objlen(L, 2);
        for (int i = 1; i <= len; ++i)
        {
            lua_rawgeti(L, 2, i);
            Faction* fac = checkObject<Faction>(L, -1, FactionBinding::getMetatableName());
            if (fac) f.insert(fac);
            lua_pop(L, 1);
        }
    }
    bool result = instance->isAtTownOf(f);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::resolveOverlappedSpeechBubbles(lua_State* L)
{
    Dialogue::resolveOverlappedSpeechBubbles();
    return 0;
}

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
        { "getWordSwap", DialogueBinding::getWordSwap },
        { "setupWordSwaps", DialogueBinding::setupWordSwaps },
        { "_CONSTRUCTOR", DialogueBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", DialogueBinding::_DESTRUCTOR },
        { "getGUIData", DialogueBinding::getGUIData },
        { "create", DialogueBinding::create },
        { "getHandle", DialogueBinding::getHandle },
        { "getCharacter", DialogueBinding::getCharacter },
        { "setLineLocked", DialogueBinding::setLineLocked },
        { "isLocked", DialogueBinding::isLocked },
        { "setInDialog", DialogueBinding::setInDialog },
        { "clearDialogues", DialogueBinding::clearDialogues },
        { "clearAnnouncements", DialogueBinding::clearAnnouncements },
        { "needsDialogAssessmentUpdate", DialogueBinding::needsDialogAssessmentUpdate },
        { "addDialoguePackage", DialogueBinding::addDialoguePackage },
        { "addConversation", DialogueBinding::addConversation },
        { "clearConversationList", DialogueBinding::clearConversationList },
        { "willTalkToEnemies", DialogueBinding::willTalkToEnemies },
        { "sendEventOverride", DialogueBinding::sendEventOverride },
        { "sendEvent", DialogueBinding::sendEvent },
        { "stopEvent", DialogueBinding::stopEvent },
        { "runCustomDialog", DialogueBinding::runCustomDialog },
        { "scoreCustomDialog", DialogueBinding::scoreCustomDialog },
        { "conversationHasEnded", DialogueBinding::conversationHasEnded },
        { "getConversationTarget", DialogueBinding::getConversationTarget },
        { "changeConversationTarget", DialogueBinding::changeConversationTarget },
        { "conversationHasEndedPrettyMuch", DialogueBinding::conversationHasEndedPrettyMuch },
        { "makeAnnouncement", DialogueBinding::makeAnnouncement },
        { "update", DialogueBinding::update },
        { "endDialogue", DialogueBinding::endDialogue },
        { "notifyUnderAttack", DialogueBinding::notifyUnderAttack },
        { "hasDialogue_Fast", DialogueBinding::hasDialogue_Fast },
        { "hasDialogue_Accurate", DialogueBinding::hasDialogue_Accurate },
        { "hasDialogueEvent", DialogueBinding::hasDialogueEvent },
        { "dialogDelivered", DialogueBinding::dialogDelivered },
        { "_checkCondition", DialogueBinding::_checkCondition },
        { "dontLetTargetBeMe", DialogueBinding::dontLetTargetBeMe },
        { "hasThisChanceLine", DialogueBinding::hasThisChanceLine },
        { "_chooseDialog", DialogueBinding::_chooseDialog },
        { "triggerNextLine", DialogueBinding::triggerNextLine },
        { "targetInTalkingRange", DialogueBinding::targetInTalkingRange },
        { "save", DialogueBinding::save },
        { "load", DialogueBinding::load },
        { "getSpeaker", DialogueBinding::getSpeaker },
        { "isCurrentConversationRunning", DialogueBinding::isCurrentConversationRunning },
        { "findInterjectionCharacter", DialogueBinding::findInterjectionCharacter },
        { "isKOExempt", DialogueBinding::isKOExempt },
        { "_endPlayerConversation", DialogueBinding::_endPlayerConversation },
        { "startPlayerConversation", DialogueBinding::startPlayerConversation },
        { "startConversation", DialogueBinding::startConversation },
        { "getConversationList", DialogueBinding::getConversationList },
        { "_doActions", DialogueBinding::_doActions },
        { "sayLine", DialogueBinding::sayLine },
        { "listPlayerReplies", DialogueBinding::listPlayerReplies },
        { "isLastLine", DialogueBinding::isLastLine },
        { "setSpeaker", DialogueBinding::setSpeaker },
        { "_updateTextPos", DialogueBinding::_updateTextPos },
        { "clearSpeechBox", DialogueBinding::clearSpeechBox },
        { "clearRespones", DialogueBinding::clearRespones },
        { "clearResponesGUI", DialogueBinding::clearResponesGUI },
        { "setResponesGUI", DialogueBinding::setResponesGUI },
        { "setConversationReplyGUI", DialogueBinding::setConversationReplyGUI },
        { "say", DialogueBinding::say },
        { "replyClicked", DialogueBinding::replyClicked },
        { "isAtTownOf", DialogueBinding::isAtTownOf },
        { "resolveOverlappedSpeechBubbles", DialogueBinding::resolveOverlappedSpeechBubbles },
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
    registerGetter(L, "repCounter", Dialogue_get_repCounter);
    registerGetter(L, "_needsDynamicAssessments", Dialogue_get__needsDynamicAssessments);
    registerGetter(L, "sayMsg", Dialogue_get_sayMsg);
    registerGetter(L, "playerInterruptionDialog", Dialogue_get_playerInterruptionDialog);
    registerGetter(L, "_hasEnded", Dialogue_get__hasEnded);
    registerGetter(L, "shouting", Dialogue_get_shouting);
    registerGetter(L, "staysOnScreen", Dialogue_get_staysOnScreen);
    registerGetter(L, "me", Dialogue_get_me);
    registerGetter(L, "conversationTarget", Dialogue_get_conversationTarget);
    registerGetter(L, "stats", Dialogue_get_stats);
    registerGetter(L, "movement", Dialogue_get_movement);
    registerGetter(L, "currentConversationType", Dialogue_get_currentConversationType);
    registerGetter(L, "currentConversation", Dialogue_get_currentConversation);
    registerGetter(L, "currentLine", Dialogue_get_currentLine);
    registerGetter(L, "interjector1", Dialogue_get_interjector1);
    registerGetter(L, "interjector2", Dialogue_get_interjector2);
    registerGetter(L, "interjector3", Dialogue_get_interjector3);
    registerGetter(L, "speechBubblePanel", Dialogue_get_speechBubblePanel);
    registerGetter(L, "speechTextTimer", Dialogue_get_speechTextTimer);
    registerGetter(L, "speechTextTimer_forced", Dialogue_get_speechTextTimer_forced);
    registerGetter(L, "npcReplyText", Dialogue_get_npcReplyText);
    registerGetter(L, "conversationMaster", Dialogue_get_conversationMaster);
    registerGetter(L, "waitingForReplyFrom", Dialogue_get_waitingForReplyFrom);
    registerGetter(L, "pacakgesIHave", Dialogue_get_pacakgesIHave);
    registerGetter(L, "locked", Dialogue_get_locked);
    registerGetter(L, "_hasChanceLines", Dialogue_get__hasChanceLines);
    registerGetter(L, "eventRepeatTimers", Dialogue_get_eventRepeatTimers);
    registerGetter(L, "eventDeliveredStates", Dialogue_get_eventDeliveredStates);
    registerGetter(L, "conversationsMain", Dialogue_get_conversationsMain);
    registerGetter(L, "threadMessages", Dialogue_get_threadMessages);
    registerGetter(L, "replyIds", Dialogue_get_replyIds);
    registerGetter(L, "responses", Dialogue_get_responses);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "repCounter", Dialogue_set_repCounter);
    registerSetter(L, "_needsDynamicAssessments", Dialogue_set__needsDynamicAssessments);
    registerSetter(L, "sayMsg", Dialogue_set_sayMsg);
    registerSetter(L, "playerInterruptionDialog", Dialogue_set_playerInterruptionDialog);
    registerSetter(L, "_hasEnded", Dialogue_set__hasEnded);
    registerSetter(L, "shouting", Dialogue_set_shouting);
    registerSetter(L, "staysOnScreen", Dialogue_set_staysOnScreen);
    registerSetter(L, "me", Dialogue_set_me);
    registerSetter(L, "conversationTarget", Dialogue_set_conversationTarget);
    registerSetter(L, "stats", Dialogue_set_stats);
    registerSetter(L, "movement", Dialogue_set_movement);
    registerSetter(L, "currentConversationType", Dialogue_set_currentConversationType);
    registerSetter(L, "currentConversation", Dialogue_set_currentConversation);
    registerSetter(L, "currentLine", Dialogue_set_currentLine);
    registerSetter(L, "interjector1", Dialogue_set_interjector1);
    registerSetter(L, "interjector2", Dialogue_set_interjector2);
    registerSetter(L, "interjector3", Dialogue_set_interjector3);
    registerSetter(L, "speechBubblePanel", Dialogue_set_speechBubblePanel);
    registerSetter(L, "speechTextTimer", Dialogue_set_speechTextTimer);
    registerSetter(L, "speechTextTimer_forced", Dialogue_set_speechTextTimer_forced);
    registerSetter(L, "npcReplyText", Dialogue_set_npcReplyText);
    registerSetter(L, "conversationMaster", Dialogue_set_conversationMaster);
    registerSetter(L, "waitingForReplyFrom", Dialogue_set_waitingForReplyFrom);
    registerSetter(L, "pacakgesIHave", Dialogue_set_pacakgesIHave);
    registerSetter(L, "locked", Dialogue_set_locked);
    registerSetter(L, "_hasChanceLines", Dialogue_set__hasChanceLines);
    registerSetter(L, "eventRepeatTimers", Dialogue_set_eventRepeatTimers);
    registerSetter(L, "eventDeliveredStates", Dialogue_set_eventDeliveredStates);
    registerSetter(L, "conversationsMain", Dialogue_set_conversationsMain);
    registerSetter(L, "threadMessages", Dialogue_set_threadMessages);
    registerSetter(L, "replyIds", Dialogue_set_replyIds);
    registerSetter(L, "responses", Dialogue_set_responses);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    DialogLineDataBoolMapBinding::registerBinding(L, "KenshiLua.DialogLineDataBoolMap", DialogLineDataBinding::getMetatableName(), nullptr);
    EventRepeatTimersMapBinding::registerBinding(L, "KenshiLua.EventRepeatTimersMap", nullptr, nullptr);
    EventDeliveredStatesMapBinding::registerBinding(L, "KenshiLua.EventDeliveredStatesMap", nullptr, HandBinding::getMetatableName());
    ConversationsMainMapBinding::registerBinding(L, "KenshiLua.ConversationsMainMap", nullptr, DialogChoiceListBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua