#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DataPanelLine_KeyConfigBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DataPanelLine_KeyConfig"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int oldKey(lua_State* L);
    static int setKey(lua_State* L);
    static int eraseKey(lua_State* L);
    static int refresh(lua_State* L);
    static int _NV_refresh(lua_State* L);
    static int cancel(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}