#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ContextMenuGUIBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ContextMenuGUI"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int getMainWidget(lua_State* L);
    static int getVisible(lua_State* L);
    static int setVisible(lua_State* L);
};
}