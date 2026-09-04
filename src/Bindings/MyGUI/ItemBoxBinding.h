#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class ItemBoxBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.ItemBox"; }
    static void registerBinding(lua_State* L);

    static MyGUI::ItemBox* getItemBox(lua_State* L, int idx);

    static int getItemCount(lua_State* L);
    static int insertItemAt(lua_State* L);
    static int addItem(lua_State* L);
    static int removeItemAt(lua_State* L);
    static int removeAllItems(lua_State* L);
    static int getIndexSelected(lua_State* L);
    static int setIndexSelected(lua_State* L);
    static int clearIndexSelected(lua_State* L);
    static int redrawItemAt(lua_State* L);
    static int redrawAllItems(lua_State* L);
    static int resetDrag(lua_State* L);
    static int getWidgetDrag(lua_State* L);
    static int getWidgetByIndex(lua_State* L);
    static int getIndexByWidget(lua_State* L);
};

} // namespace KenshiLua
