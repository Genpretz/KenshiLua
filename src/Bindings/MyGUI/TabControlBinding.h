#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class TabControlBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.TabControl"; }
    static void registerBinding(lua_State* L);

    static MyGUI::TabControl* getTabControl(lua_State* L, int idx);

    static int getItemCount(lua_State* L);
    static int insertItemAt(lua_State* L);
    static int addItem(lua_State* L);
    static int removeItemAt(lua_State* L);
    static int removeAllItems(lua_State* L);
    static int getItemNameAt(lua_State* L);
    static int setItemNameAt(lua_State* L);
    static int getIndexSelected(lua_State* L);
    static int setIndexSelected(lua_State* L);
    static int clearIndexSelected(lua_State* L);
    static int getItemAt(lua_State* L);
    static int getItemSelected(lua_State* L);
    static int setButtonWidthAt(lua_State* L);
    static int getButtonWidthAt(lua_State* L);
    static int setButtonDefaultWidth(lua_State* L);
    static int getButtonDefaultWidth(lua_State* L);
    static int setButtonAutoWidth(lua_State* L);
    static int getButtonAutoWidth(lua_State* L);
    static int setSmoothShow(lua_State* L);
    static int getSmoothShow(lua_State* L);
};

} // namespace KenshiLua
