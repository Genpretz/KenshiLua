#pragma once

#include "kenshi/gui/MyGUI_ListScrollBar.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ListScrollBarBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ListScrollBar"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setEnabled(lua_State* L);
    static int initialiseOverride(lua_State* L);
    static int shutdownOverride(lua_State* L);
};
}