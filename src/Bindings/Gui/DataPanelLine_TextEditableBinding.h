#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DataPanelLine_TextEditableBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DataPanelLine_TextEditable"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getEditBox(lua_State* L);
    static int getNameBox(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}