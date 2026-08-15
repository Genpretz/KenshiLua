#pragma once

#include "kenshi/Dialogue.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DialogueSpeechBubbleBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DialogueSpeechBubble"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setPosition(lua_State* L);
    static int getRect(lua_State* L);
    static int setText(lua_State* L);
    static int setAlpha(lua_State* L);
    static int reset(lua_State* L);
    static int getAlpha(lua_State* L);
};
}