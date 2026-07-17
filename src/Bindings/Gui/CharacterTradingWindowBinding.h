#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CharacterTradingWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CharacterTradingWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int show(lua_State* L);
    static int _NV_show(lua_State* L);
    static int isVisible(lua_State* L);
    static int _NV_isVisible(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int close(lua_State* L);
    static int _NV_close(lua_State* L);
    static int updateSelected(lua_State* L);
};
}