#pragma once

#include "kenshi/gui/ForgottenGUI.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ProgressBarWidgetBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ProgressBarWidget"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int setVisible(lua_State* L);
    static int setProgress(lua_State* L);
    static int setPosition(lua_State* L);
    static int setCaption(lua_State* L);
};
}