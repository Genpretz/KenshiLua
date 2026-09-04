#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class ListBoxBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.ListBox"; }
    static void registerBinding(lua_State* L);

    static MyGUI::ListBox* getListBox(lua_State* L, int idx);

    static int getItemCount(lua_State* L);
    static int insertItemAt(lua_State* L);
    static int addItem(lua_State* L);
    static int removeItemAt(lua_State* L);
    static int removeAllItems(lua_State* L);
    static int swapItemsAt(lua_State* L);
    static int setItemNameAt(lua_State* L);
    static int getItemNameAt(lua_State* L);
    static int getIndexSelected(lua_State* L);
    static int setIndexSelected(lua_State* L);
    static int clearIndexSelected(lua_State* L);
    static int findItemIndexWith(lua_State* L);
    static int beginToItemAt(lua_State* L);
    static int beginToItemFirst(lua_State* L);
    static int beginToItemLast(lua_State* L);
    static int beginToItemSelected(lua_State* L);
    static int isItemVisibleAt(lua_State* L);
    static int isItemSelectedVisible(lua_State* L);
    static int setScrollVisible(lua_State* L);
    static int setScrollPosition(lua_State* L);
    static int getOptimalHeight(lua_State* L);
    static int getWidgetByIndex(lua_State* L);
};

} // namespace KenshiLua
