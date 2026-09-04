#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class ScrollBarBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.ScrollBar"; }
    static void registerBinding(lua_State* L);

    static MyGUI::ScrollBar* getScrollBar(lua_State* L, int idx);

    static int setScrollRange(lua_State* L);
    static int getScrollRange(lua_State* L);
    static int setScrollPosition(lua_State* L);
    static int getScrollPosition(lua_State* L);
    static int setScrollPage(lua_State* L);
    static int getScrollPage(lua_State* L);
    static int setScrollViewPage(lua_State* L);
    static int getScrollViewPage(lua_State* L);
    static int setScrollWheelPage(lua_State* L);
    static int getScrollWheelPage(lua_State* L);
    static int setVerticalAlignment(lua_State* L);
    static int getVerticalAlignment(lua_State* L);
    static int setTrackSize(lua_State* L);
    static int getTrackSize(lua_State* L);
    static int setMinTrackSize(lua_State* L);
    static int getMinTrackSize(lua_State* L);
    static int getLineSize(lua_State* L);
    static int setMoveToClick(lua_State* L);
    static int getMoveToClick(lua_State* L);
    static int setRepeatEnabled(lua_State* L);
    static int getRepeatEnabled(lua_State* L);
};

} // namespace KenshiLua
