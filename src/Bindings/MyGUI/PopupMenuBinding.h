#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class PopupMenuBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.PopupMenu"; }
    static void registerBinding(lua_State* L);

    static MyGUI::PopupMenu* getPopupMenu(lua_State* L, int idx);
};

} // namespace KenshiLua
