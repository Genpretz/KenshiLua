#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class WindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.Window"; }
    static void registerBinding(lua_State* L);

    static MyGUI::Window* getWindow(lua_State* L, int idx);

    static int setVisibleSmooth(lua_State* L);
    static int destroySmooth(lua_State* L);
    static int setAutoAlpha(lua_State* L);
    static int getAutoAlpha(lua_State* L);
    static int setSnap(lua_State* L);
    static int getSnap(lua_State* L);
    static int setMovable(lua_State* L);
    static int getMovable(lua_State* L);
    static int setMinSize(lua_State* L);
    static int getMinSize(lua_State* L);
    static int setMaxSize(lua_State* L);
    static int getMaxSize(lua_State* L);
    static int getActionScale(lua_State* L);
    static int getCaptionWidget(lua_State* L);
};

} // namespace KenshiLua
