#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class ButtonBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.Button"; }
    static void registerBinding(lua_State* L);

    static MyGUI::Button* getButton(lua_State* L, int idx);

    static int setStateSelected(lua_State* L);
    static int getStateSelected(lua_State* L);
    static int setModeImage(lua_State* L);
    static int getModeImage(lua_State* L);
    static int setImageResource(lua_State* L);
};

} // namespace KenshiLua
