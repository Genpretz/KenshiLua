#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DialogueBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Dialogue"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getWordSwap(lua_State* L);
    static int setupWordSwaps(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int getGUIData(lua_State* L);
    static int create(lua_State* L);
    static int getHandle(lua_State* L);
    static int getCharacter(lua_State* L);
    static int setLineLocked(lua_State* L);
    static int isLocked(lua_State* L);
    static int setInDialog(lua_State* L);
    static int clearDialogues(lua_State* L);
    static int clearAnnouncements(lua_State* L);
    static int needsDialogAssessmentUpdate(lua_State* L);
    static int addDialoguePackage(lua_State* L);
    static int addConversation(lua_State* L);
    static int clearConversationList(lua_State* L);
    static int willTalkToEnemies(lua_State* L);
    static int sendEventOverride(lua_State* L);
    static int sendEvent(lua_State* L);
    static int stopEvent(lua_State* L);
    static int runCustomDialog(lua_State* L);
    static int scoreCustomDialog(lua_State* L);
    static int conversationHasEnded(lua_State* L);
    static int getConversationTarget(lua_State* L);
    static int changeConversationTarget(lua_State* L);
    static int conversationHasEndedPrettyMuch(lua_State* L);
    static int makeAnnouncement(lua_State* L);
    static int update(lua_State* L);
    static int endDialogue(lua_State* L);
    static int notifyUnderAttack(lua_State* L);
    static int hasDialogue_Fast(lua_State* L);
    static int hasDialogue_Accurate(lua_State* L);
    static int hasDialogueEvent(lua_State* L);
    static int dialogDelivered(lua_State* L);
    static int _checkCondition(lua_State* L);
    static int dontLetTargetBeMe(lua_State* L);
    static int hasThisChanceLine(lua_State* L);
    static int _chooseDialog(lua_State* L);
    static int triggerNextLine(lua_State* L);
    static int targetInTalkingRange(lua_State* L);
    static int save(lua_State* L);
    static int load(lua_State* L);
    static int getSpeaker(lua_State* L);
    static int isCurrentConversationRunning(lua_State* L);
    static int findInterjectionCharacter(lua_State* L);
    static int isKOExempt(lua_State* L);
    static int _endPlayerConversation(lua_State* L);
    static int startPlayerConversation(lua_State* L);
    static int startConversation(lua_State* L);
    static int getConversationList(lua_State* L);
    static int _doActions(lua_State* L);
    static int sayLine(lua_State* L);
    static int listPlayerReplies(lua_State* L);
    static int isLastLine(lua_State* L);
    static int setSpeaker(lua_State* L);
    static int _updateTextPos(lua_State* L);
    static int clearSpeechBox(lua_State* L);
    static int clearRespones(lua_State* L);
    static int clearResponesGUI(lua_State* L);
    static int setResponesGUI(lua_State* L);
    static int setConversationReplyGUI(lua_State* L);
    static int say(lua_State* L);
    static int replyClicked(lua_State* L);
    static int isAtTownOf(lua_State* L);
    static int resolveOverlappedSpeechBubbles(lua_State* L);
};
}