#include "pch.h"
#include "Bindings/Dialogue/DialogueBinding.h"
#include "Bindings/Character/CharacterBinding.h"
#include "Bindings/Character/CharStatsBinding.h"
#include "Bindings/Utility/HandBinding.h"
#include "Bindings/Dialogue/RepetitionCounterBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Core/EnumBinding.h"

#include <kenshi/Dialogue.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static Dialogue* getS(lua_State* L, int idx)
{
    return checkObject<Dialogue>(L, idx, DialogueBinding::getMetatableName());
}

int DialogueBinding::gc(lua_State* L) { return noopGc(L); }

int DialogueBinding::tostring(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int DialogueBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, DialogueBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    Dialogue* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "repCounter") == 0) { return pushObject<Dialogue::RepetitionCounter>(L, &s->repCounter, RepetitionCounterBinding::getMetatableName()); }
    if (strcmp(key, "_needsDynamicAssessments") == 0) { lua_pushboolean(L, s->_needsDynamicAssessments ? 1 : 0); return 1; }
    // TODO std::map<DialogLineData*, bool, std::less<DialogLineData*>, Ogre::STLAllocator<std::pair<DialogLineData*const, bool>, Ogre::GeneralAllocPolicy > > locked; unsupported __index type from header line 314
    if (strcmp(key, "sayMsg") == 0) { lua_pushstring(L, s->sayMsg.c_str()); return 1; }
    // TODO Ogre::vector<Dialogue::DT_MSG>::type threadMessages; unsupported __index type from header line 327
    // TODO std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::GeneralAllocPolicy > > pacakgesIHave; unsupported __index type from header line 343
    // TODO DialogLineData* playerInterruptionDialog; unsupported __index type from header line 349
    // TODO std::map<EventTriggerEnum, float, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, float>, Ogre::GeneralAllocPolicy > > eventRepeatTimers; unsupported __index type from header line 384
    // TODO std::map<EventTriggerEnum, hand, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, hand>, Ogre::GeneralAllocPolicy > > eventDeliveredStates; unsupported __index type from header line 385
    // TODO std::map<DialogLineData*, bool, std::less<DialogLineData*>, Ogre::STLAllocator<std::pair<DialogLineData*const, bool>, Ogre::GeneralAllocPolicy > > _hasChanceLines; unsupported __index type from header line 388
    if (strcmp(key, "_hasEnded") == 0) { lua_pushboolean(L, s->_hasEnded ? 1 : 0); return 1; }
    if (strcmp(key, "shouting") == 0) { lua_pushboolean(L, s->shouting ? 1 : 0); return 1; }
    if (strcmp(key, "staysOnScreen") == 0) { lua_pushboolean(L, s->staysOnScreen ? 1 : 0); return 1; }
    if (strcmp(key, "me") == 0 || strcmp(key, "character") == 0) { return pushObject<Character>(L, s->me, CharacterBinding::getMetatableName()); }
    if (strcmp(key, "conversationTarget") == 0) { return HandBinding::pushHand(L, s->conversationTarget); }
    if (strcmp(key, "stats") == 0) { return pushObject<CharStats>(L, s->stats, CharStatsBinding::getMetatableName()); }
    // TODO CharMovement* movement; unsupported __index type from header line 398
    // TODO EventTriggerEnum currentConversationType; unsupported __index type from header line 399
    // TODO DialogLineData* currentConversation; unsupported __index type from header line 400
    // TODO DialogLineData* currentLine; unsupported __index type from header line 401
    // TODO std::map<EventTriggerEnum, DialogChoiceList*, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, DialogChoiceList*>, Ogre::GeneralAllocPolicy > > conversationsMain; unsupported __index type from header line 403
    // TODO hand interjector1; unsupported __index type from header line 409
    // TODO hand interjector2; unsupported __index type from header line 410
    // TODO hand interjector3; unsupported __index type from header line 411
    // TODO DialogueSpeechBubble* speechBubblePanel; unsupported __index type from header line 418
    if (strcmp(key, "speechTextTimer") == 0) { lua_pushnumber(L, s->speechTextTimer); return 1; }
    if (strcmp(key, "speechTextTimer_forced") == 0) { lua_pushnumber(L, s->speechTextTimer_forced); return 1; }
    // TODO Ogre::vector<std::string>::type replyIds; unsupported __index type from header line 421
    // TODO Ogre::vector<std::string>::type responses; unsupported __index type from header line 422
    if (strcmp(key, "npcReplyText") == 0) { lua_pushstring(L, s->npcReplyText.c_str()); return 1; }
    // TODO hand conversationMaster; unsupported __index type from header line 424
    // TODO hand waitingForReplyFrom; unsupported __index type from header line 425
 
    lua_pushnil(L);
    return 1;
}
 
int DialogueBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");
 
    if (strcmp(key, "repCounter") == 0) {
        Dialogue::RepetitionCounter* other = checkObject<Dialogue::RepetitionCounter>(L, 3, RepetitionCounterBinding::getMetatableName());
        if (other) s->repCounter = *other;
        return 0;
    }
    if (strcmp(key, "_needsDynamicAssessments") == 0) { s->_needsDynamicAssessments = lua_toboolean(L, 3) != 0; return 0; }
    // TODO std::map<DialogLineData*, bool, std::less<DialogLineData*>, Ogre::STLAllocator<std::pair<DialogLineData*const, bool>, Ogre::GeneralAllocPolicy > > locked; unsupported __newindex type from header line 314
    if (strcmp(key, "sayMsg") == 0) { s->sayMsg = luaL_checkstring(L, 3); return 0; }
    // TODO Ogre::vector<Dialogue::DT_MSG>::type threadMessages; unsupported __newindex type from header line 327
    // TODO std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::GeneralAllocPolicy > > pacakgesIHave; unsupported __newindex type from header line 343
    // TODO DialogLineData* playerInterruptionDialog; unsupported __newindex type from header line 349
    // TODO std::map<EventTriggerEnum, float, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, float>, Ogre::GeneralAllocPolicy > > eventRepeatTimers; unsupported __newindex type from header line 384
    // TODO std::map<EventTriggerEnum, hand, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, hand>, Ogre::GeneralAllocPolicy > > eventDeliveredStates; unsupported __newindex type from header line 385
    // TODO std::map<DialogLineData*, bool, std::less<DialogLineData*>, Ogre::STLAllocator<std::pair<DialogLineData*const, bool>, Ogre::GeneralAllocPolicy > > _hasChanceLines; unsupported __newindex type from header line 388
    if (strcmp(key, "_hasEnded") == 0) { s->_hasEnded = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "shouting") == 0) { s->shouting = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "staysOnScreen") == 0) { s->staysOnScreen = lua_toboolean(L, 3) != 0; return 0; }
    // TODO Character* me; unsupported __newindex type from header line 395
    // TODO hand conversationTarget; unsupported __newindex type from header line 396
    // TODO CharStats* stats; unsupported __newindex type from header line 397
    // TODO CharMovement* movement; unsupported __newindex type from header line 398
    // TODO EventTriggerEnum currentConversationType; unsupported __newindex type from header line 399
    // TODO DialogLineData* currentConversation; unsupported __newindex type from header line 400
    // TODO DialogLineData* currentLine; unsupported __newindex type from header line 401
    // TODO std::map<EventTriggerEnum, DialogChoiceList*, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, DialogChoiceList*>, Ogre::GeneralAllocPolicy > > conversationsMain; unsupported __newindex type from header line 403
    // TODO hand interjector1; unsupported __newindex type from header line 409
    // TODO hand interjector2; unsupported __newindex type from header line 410
    // TODO hand interjector3; unsupported __newindex type from header line 411
    // TODO DialogueSpeechBubble* speechBubblePanel; unsupported __newindex type from header line 418
    if (strcmp(key, "speechTextTimer") == 0) { s->speechTextTimer = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "speechTextTimer_forced") == 0) { s->speechTextTimer_forced = (float)luaL_checknumber(L, 3); return 0; }
    // TODO Ogre::vector<std::string>::type replyIds; unsupported __newindex type from header line 421
    // TODO Ogre::vector<std::string>::type responses; unsupported __newindex type from header line 422
    if (strcmp(key, "npcReplyText") == 0) { s->npcReplyText = luaL_checkstring(L, 3); return 0; }
    // TODO hand conversationMaster; unsupported __newindex type from header line 424
    // TODO hand waitingForReplyFrom; unsupported __newindex type from header line 425

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int DialogueBinding::setupWordSwaps(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    s->setupWordSwaps();
    return 0;
}

int DialogueBinding::_CONSTRUCTOR(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    Dialogue* result = s->_CONSTRUCTOR();
    return pushObject<Dialogue>(L, result, DialogueBinding::getMetatableName());
}

int DialogueBinding::_DESTRUCTOR(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    s->_DESTRUCTOR();
    return 0;
}

int DialogueBinding::getCharacter(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    Character* result = s->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int DialogueBinding::setInDialog(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->setInDialog(on);
    return 0;
}

int DialogueBinding::clearDialogues(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    s->clearDialogues();
    return 0;
}

int DialogueBinding::clearAnnouncements(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    s->clearAnnouncements();
    return 0;
}

int DialogueBinding::needsDialogAssessmentUpdate(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    bool result = s->needsDialogAssessmentUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::willTalkToEnemies(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    bool result = s->willTalkToEnemies();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::conversationHasEnded(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    bool result = s->conversationHasEnded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::conversationHasEndedPrettyMuch(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    bool result = s->conversationHasEndedPrettyMuch();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::update(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    s->update(frameTime);
    return 0;
}

int DialogueBinding::endDialogue(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    bool definitelyTheEnd = lua_toboolean(L, 2) != 0;
    s->endDialogue(definitelyTheEnd);
    return 0;
}

int DialogueBinding::hasDialogue_Fast(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    bool result = s->hasDialogue_Fast();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::hasDialogue_Accurate(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    bool result = s->hasDialogue_Accurate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueBinding::_endPlayerConversation(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    bool finished = lua_toboolean(L, 2) != 0;
    s->_endPlayerConversation(finished);
    return 0;
}

int DialogueBinding::listPlayerReplies(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    s->listPlayerReplies();
    return 0;
}

int DialogueBinding::_updateTextPos(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    s->_updateTextPos();
    return 0;
}

int DialogueBinding::clearSpeechBox(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    s->clearSpeechBox();
    return 0;
}

int DialogueBinding::clearRespones(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    s->clearRespones();
    return 0;
}

int DialogueBinding::clearResponesGUI(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    s->clearResponesGUI();
    return 0;
}

int DialogueBinding::setResponesGUI(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    s->setResponesGUI();
    return 0;
}

int DialogueBinding::setConversationReplyGUI(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");

    s->setConversationReplyGUI();
    return 0;
}

int DialogueBinding::getConversationTarget(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }
    hand h = s->conversationTarget;
    if (!h.isValid()) { lua_pushnil(L); return 1; }
    return pushObject<Character>(L, h.getCharacter(), CharacterBinding::getMetatableName());
}

int DialogueBinding::hasDialogueEvent(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) { lua_pushboolean(L, 0); return 1; }
    int ev = (int)luaL_checkinteger(L, 2);
    lua_pushboolean(L, s->hasDialogueEvent((EventTriggerEnum)ev) ? 1 : 0);
    return 1;
}

int DialogueBinding::sendEvent(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");
    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    if (!target) return luaL_error(L, "Target Character expected");
    int ev = (int)luaL_checkinteger(L, 3);
    lua_pushboolean(L, s->sendEvent(target, (EventTriggerEnum)ev) ? 1 : 0);
    return 1;
}

int DialogueBinding::sendEventOverride(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    if (!s) return luaL_error(L, "Dialogue is nil");
    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    if (!target) return luaL_error(L, "Target Character expected");
    int ev = (int)luaL_checkinteger(L, 3);
    bool force = lua_toboolean(L, 4) != 0;
    lua_pushboolean(L, s->sendEventOverride(target, (EventTriggerEnum)ev, force) ? 1 : 0);
    return 1;
}

int DialogueBinding::isValid(lua_State* L)
{
    Dialogue* s = getS(L, 1);
    lua_pushboolean(L, s && s->me ? 1 : 0);
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
        { "setInDialog", DialogueBinding::setInDialog },
        { "clearDialogues", DialogueBinding::clearDialogues },
        { "clearAnnouncements", DialogueBinding::clearAnnouncements },
        { "needsDialogAssessmentUpdate", DialogueBinding::needsDialogAssessmentUpdate },
        { "willTalkToEnemies", DialogueBinding::willTalkToEnemies },
        { "conversationHasEnded", DialogueBinding::conversationHasEnded },
        { "conversationHasEndedPrettyMuch", DialogueBinding::conversationHasEndedPrettyMuch },
        { "update", DialogueBinding::update },
        { "endDialogue", DialogueBinding::endDialogue },
        { "hasDialogue_Fast", DialogueBinding::hasDialogue_Fast },
        { "hasDialogue_Accurate", DialogueBinding::hasDialogue_Accurate },
        { "_endPlayerConversation", DialogueBinding::_endPlayerConversation },
        { "listPlayerReplies", DialogueBinding::listPlayerReplies },
        { "_updateTextPos", DialogueBinding::_updateTextPos },
        { "clearSpeechBox", DialogueBinding::clearSpeechBox },
        { "clearRespones", DialogueBinding::clearRespones },
        { "clearResponesGUI", DialogueBinding::clearResponesGUI },
        { "setResponesGUI", DialogueBinding::setResponesGUI },
        { "setConversationReplyGUI", DialogueBinding::setConversationReplyGUI },
        { "getConversationTarget", DialogueBinding::getConversationTarget },
        { "hasDialogueEvent",     DialogueBinding::hasDialogueEvent },
        { "sendEvent",            DialogueBinding::sendEvent },
        { "sendEventOverride",    DialogueBinding::sendEventOverride },
        { "isValid",              DialogueBinding::isValid },
        { 0, 0 }
    };
    registerClass(L, DialogueBinding::getMetatableName(), meta, methods, DialogueBinding::index, DialogueBinding::newindex);
}

} // namespace KenshiLua
