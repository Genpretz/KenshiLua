#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class MultiListBoxBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.MultiListBox"; }
    static void registerBinding(lua_State* L);

    static MyGUI::MultiListBox* getMultiListBox(lua_State* L, int idx);

    static int getColumnCount(lua_State* L);
    static int insertColumnAt(lua_State* L);
    static int addColumn(lua_State* L);
    static int removeColumnAt(lua_State* L);
    static int removeAllColumns(lua_State* L);
    static int setColumnNameAt(lua_State* L);
    static int setColumnWidthAt(lua_State* L);
    static int getColumnNameAt(lua_State* L);
    static int getColumnWidthAt(lua_State* L);
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
    static int setSubItemNameAt(lua_State* L);
    static int getSubItemNameAt(lua_State* L);
    static int findSubItemWith(lua_State* L);
};

} // namespace KenshiLua
