#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class InputHandlerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.InputHandler"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getKeyUTF8(lua_State* L);
    static int parseKey(lua_State* L);
    static int keyDownEvent(lua_State* L);
    static int keyUpEvent(lua_State* L);
    static int clearMessages(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int initialise(lua_State* L);
    static int bind(lua_State* L);
    static int unbindAll(lua_State* L);
    static int isKeyState(lua_State* L);
    static int getMode(lua_State* L);
    static int sendEvent(lua_State* L);
    static int loadConfig(lua_State* L);
    static int saveConfig(lua_State* L);
    static int keyString(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}