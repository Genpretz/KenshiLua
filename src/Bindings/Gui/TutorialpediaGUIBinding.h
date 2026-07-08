#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TutorialpediaGUIBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TutorialpediaGUI"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int show(lua_State* L);
    static int _NV_show(lua_State* L);
    static int clear(lua_State* L);
    static int _NV_clear(lua_State* L);
    static int isVisible(lua_State* L);
    static int _NV_isVisible(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int setup(lua_State* L);
    static int updateCurrentItem(lua_State* L);
};
}