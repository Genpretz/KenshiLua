#pragma once

extern "C" {
#include <lua.h>
}

class Dialogue;

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

    static int getCharacter(lua_State* L);
    static int getConversationTarget(lua_State* L);
    static int hasDialogueEvent(lua_State* L);
    static int willTalkToEnemies(lua_State* L);
    static int conversationHasEnded(lua_State* L);
    static int sendEvent(lua_State* L);
    static int sendEventOverride(lua_State* L);
    static int endDialogue(lua_State* L);
    static int isValid(lua_State* L);
};

void registerEventBinding(lua_State* L);

} // namespace KenshiLua