#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class DDContainerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.DDContainer"; }
    static void registerBinding(lua_State* L);

    static MyGUI::DDContainer* getDDContainer(lua_State* L, int idx);

    static int setNeedDragDrop(lua_State* L);
    static int getNeedDragDrop(lua_State* L);
    static int resetDrag(lua_State* L);
};

} // namespace KenshiLua
