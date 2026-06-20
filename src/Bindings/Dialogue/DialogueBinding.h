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
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int setupWordSwaps(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int getCharacter(lua_State* L);
    static int setInDialog(lua_State* L);
    static int clearDialogues(lua_State* L);
    static int clearAnnouncements(lua_State* L);
    static int needsDialogAssessmentUpdate(lua_State* L);
    static int willTalkToEnemies(lua_State* L);
    static int conversationHasEnded(lua_State* L);
    static int conversationHasEndedPrettyMuch(lua_State* L);
    static int update(lua_State* L);
    static int endDialogue(lua_State* L);
    static int hasDialogue_Fast(lua_State* L);
    static int hasDialogue_Accurate(lua_State* L);
    static int _endPlayerConversation(lua_State* L);
    static int listPlayerReplies(lua_State* L);
    static int _updateTextPos(lua_State* L);
    static int clearSpeechBox(lua_State* L);
    static int clearRespones(lua_State* L);
    static int clearResponesGUI(lua_State* L);
    static int setResponesGUI(lua_State* L);
    static int setConversationReplyGUI(lua_State* L);

    // Merged from old Bindings/System/DialogueBinding.h
    static int getConversationTarget(lua_State* L);
    static int hasDialogueEvent(lua_State* L);
    static int sendEvent(lua_State* L);
    static int sendEventOverride(lua_State* L);
    static int isValid(lua_State* L);
};

}