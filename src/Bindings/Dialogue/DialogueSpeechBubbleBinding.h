#pragma once

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
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int setText(lua_State* L);
    static int setAlpha(lua_State* L);
    static int reset(lua_State* L);
    static int getAlpha(lua_State* L);
};
}