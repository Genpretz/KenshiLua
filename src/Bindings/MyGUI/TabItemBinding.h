#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class TabItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.TabItem"; }
    static void registerBinding(lua_State* L);

    static MyGUI::TabItem* getTabItem(lua_State* L, int idx);

    static int setButtonWidth(lua_State* L);
};

} // namespace KenshiLua
