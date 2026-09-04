#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class InputManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.InputManager"; }
    static void registerBinding(lua_State* L);

    static int getInstance(lua_State* L);
    static int injectMouseMove(lua_State* L);
    static int injectMousePress(lua_State* L);
    static int injectMouseRelease(lua_State* L);
    static int injectKeyPress(lua_State* L);
    static int injectKeyRelease(lua_State* L);
    static int isControlPressed(lua_State* L);
    static int isShiftPressed(lua_State* L);
    static int isFocusMouse(lua_State* L);
    static int isFocusKey(lua_State* L);
    static int isCaptureMouse(lua_State* L);
    static int setKeyFocusWidget(lua_State* L);
    static int resetKeyFocusWidget(lua_State* L);
    static int getMouseFocusWidget(lua_State* L);
    static int getKeyFocusWidget(lua_State* L);
    static int getMousePosition(lua_State* L);
    static int addWidgetModal(lua_State* L);
    static int removeWidgetModal(lua_State* L);
    static int isModalAny(lua_State* L);
    static int resetMouseCaptureWidget(lua_State* L);
};

} // namespace KenshiLua
