#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class LayoutManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.LayoutManager"; }
    static void registerBinding(lua_State* L);

    static int getInstance(lua_State* L);
    static int loadLayout(lua_State* L);
    static int unloadLayout(lua_State* L);
};

} // namespace KenshiLua
