#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class ProgressBarBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.ProgressBar"; }
    static void registerBinding(lua_State* L);

    static MyGUI::ProgressBar* getProgressBar(lua_State* L, int idx);

    static int setProgressRange(lua_State* L);
    static int getProgressRange(lua_State* L);
    static int setProgressPosition(lua_State* L);
    static int getProgressPosition(lua_State* L);
    static int setProgressAutoTrack(lua_State* L);
    static int getProgressAutoTrack(lua_State* L);
    static int setFlowDirection(lua_State* L);
    static int getFlowDirection(lua_State* L);
};

} // namespace KenshiLua
