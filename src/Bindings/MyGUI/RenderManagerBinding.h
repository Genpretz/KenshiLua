#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class RenderManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.RenderManager"; }
    static void registerBinding(lua_State* L);

    static int getInstance(lua_State* L);
    static int getViewSize(lua_State* L);
    static int getViewWidth(lua_State* L);
    static int getViewHeight(lua_State* L);
};

} // namespace KenshiLua
