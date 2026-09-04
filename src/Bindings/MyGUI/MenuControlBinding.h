#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class MenuControlBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.MenuControl"; }
    static void registerBinding(lua_State* L);

    static MyGUI::MenuControl* getMenuControl(lua_State* L, int idx);

    static int getItemCount(lua_State* L);
    static int insertItemAt(lua_State* L);
    static int addItem(lua_State* L);
    static int removeItemAt(lua_State* L);
    static int removeAllItems(lua_State* L);
    static int getItemNameAt(lua_State* L);
    static int setItemNameAt(lua_State* L);
    static int getItemIdAt(lua_State* L);
    static int setItemIdAt(lua_State* L);
    static int getItemAt(lua_State* L);
    static int getItemById(lua_State* L);
    static int getItemIndex(lua_State* L);
    static int getItemIndexById(lua_State* L);
    static int findItemIndexWith(lua_State* L);
    static int setItemDataAt(lua_State* L);
    static int clearItemDataAt(lua_State* L);
    static int setItemTypeAt(lua_State* L);
    static int getItemTypeAt(lua_State* L);
    static int setItemChildVisibleAt(lua_State* L);
    static int createItemChildAt(lua_State* L);
    static int setPopupAccept(lua_State* L);
    static int getPopupAccept(lua_State* L);
    static int setVerticalAlignment(lua_State* L);
    static int getVerticalAlignment(lua_State* L);
};

} // namespace KenshiLua
