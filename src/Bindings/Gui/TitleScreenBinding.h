#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TitleScreenBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TitleScreen"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int clear(lua_State* L);
    static int _NV_clear(lua_State* L);
    static int show(lua_State* L);
    static int _NV_show(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int closeTheOtherBits(lua_State* L);
    static int setCreditsVisible(lua_State* L);
};
}