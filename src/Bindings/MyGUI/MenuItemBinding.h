#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class MenuItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.MenuItem"; }
    static void registerBinding(lua_State* L);

    static MyGUI::MenuItem* getMenuItem(lua_State* L, int idx);

    static int setItemName(lua_State* L);
    static int getItemName(lua_State* L);
    static int setItemId(lua_State* L);
    static int getItemId(lua_State* L);
    static int setItemType(lua_State* L);
    static int getItemType(lua_State* L);
    static int setItemData(lua_State* L);
    static int clearItemData(lua_State* L);
    static int getItemIndex(lua_State* L);
    static int createItemChild(lua_State* L);
    static int removeItemChild(lua_State* L);
    static int getItemChild(lua_State* L);
    static int setItemChildVisible(lua_State* L);
    static int setItemChecked(lua_State* L);
    static int getItemChecked(lua_State* L);
};

} // namespace KenshiLua
