#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class GuiBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.Gui"; }
    static void registerBinding(lua_State* L);

    static int getInstance(lua_State* L);
    static int createWidget(lua_State* L);
    static int createWidgetReal(lua_State* L);
    static int findWidget(lua_State* L);
    static int findWidgetT(lua_State* L);
    static int destroyWidget(lua_State* L);
    static int destroyWidgets(lua_State* L);
    static int hidePointer(lua_State* L);
    static int showPointer(lua_State* L);
    static int isPointerVisible(lua_State* L);
};

} // namespace KenshiLua
