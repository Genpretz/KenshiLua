#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class ClipboardManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.ClipboardManager"; }
    static void registerBinding(lua_State* L);

    static int getInstance(lua_State* L);
    static int setClipboardData(lua_State* L);
    static int clearClipboardData(lua_State* L);
    static int getClipboardData(lua_State* L);
    static int setText(lua_State* L);
    static int getText(lua_State* L);
};

} // namespace KenshiLua
