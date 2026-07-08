#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class OptionsWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.OptionsWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _NV_show(lua_State* L);
    static int hide(lua_State* L);
    static int toggle(lua_State* L);
    static int isVisible(lua_State* L);
    static int waitingForKey(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int saveOptions(lua_State* L);
    static int create(lua_State* L);
    static int updateResolutions(lua_State* L);
};
}