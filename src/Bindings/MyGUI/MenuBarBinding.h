#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class MenuBarBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.MenuBar"; }
    static void registerBinding(lua_State* L);

    static MyGUI::MenuBar* getMenuBar(lua_State* L, int idx);
};

} // namespace KenshiLua
