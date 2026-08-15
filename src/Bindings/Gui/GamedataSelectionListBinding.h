#pragma once

#include "kenshi/gui/GameDataEditorWindow.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GamedataSelectionListBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GamedataSelectionList"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int deselectItem(lua_State* L);
    static int selectItem(lua_State* L);
    static int getSelectedItem(lua_State* L);
    static int itemSelected(lua_State* L);
    static int formatItem(lua_State* L);
    static int _NV_formatItem(lua_State* L);
    static int listItemSelected(lua_State* L);
    static int changeFilter(lua_State* L);
};
}
