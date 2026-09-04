#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class ScrollViewBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.ScrollView"; }
    static void registerBinding(lua_State* L);

    static MyGUI::ScrollView* getScrollView(lua_State* L, int idx);

    static int setVisibleHScroll(lua_State* L);
    static int isVisibleHScroll(lua_State* L);
    static int setVisibleVScroll(lua_State* L);
    static int isVisibleVScroll(lua_State* L);
    static int setCanvasAlign(lua_State* L);
    static int getCanvasAlign(lua_State* L);
    static int setCanvasSize(lua_State* L);
    static int getCanvasSize(lua_State* L);
    static int setViewOffset(lua_State* L);
    static int getViewOffset(lua_State* L);
    static int getViewCoord(lua_State* L);
};

} // namespace KenshiLua
