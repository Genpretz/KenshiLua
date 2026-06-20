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
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int isKeyState(lua_State* L);
    static int isBound(lua_State* L);
    static int sendEvent(lua_State* L);
    static int bind(lua_State* L);
    static int unbind(lua_State* L);
    static int unbindAll(lua_State* L);
    static int getMousePos(lua_State* L);
    static int getMousePosAbs(lua_State* L);
    static int getMouseWheel(lua_State* L);
    static int getModifiers(lua_State* L);
};
}
