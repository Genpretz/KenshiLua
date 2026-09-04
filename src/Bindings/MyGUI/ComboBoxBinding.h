#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class ComboBoxBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.ComboBox"; }
    static void registerBinding(lua_State* L);

    static MyGUI::ComboBox* getComboBox(lua_State* L, int idx);

    static int getItemCount(lua_State* L);
    static int insertItemAt(lua_State* L);
    static int addItem(lua_State* L);
    static int removeItemAt(lua_State* L);
    static int removeAllItems(lua_State* L);
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
    static int setComboModeDrop(lua_State* L);
    static int getComboModeDrop(lua_State* L);
    static int setSmoothShow(lua_State* L);
    static int getSmoothShow(lua_State* L);
    static int setMaxListLength(lua_State* L);
    static int getMaxListLength(lua_State* L);
    static int setFlowDirection(lua_State* L);
    static int getFlowDirection(lua_State* L);
};

} // namespace KenshiLua
