#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CharacterStatsWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CharacterStatsWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int clear(lua_State* L);
    static int _NV_clear(lua_State* L);
    static int create(lua_State* L);
    static int _NV_create(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int show(lua_State* L);
    static int _NV_show(lua_State* L);
    static int isVisible(lua_State* L);
    static int _NV_isVisible(lua_State* L);
    static int setAutoUpdateMode(lua_State* L);
    static int setupStats(lua_State* L);
    static int updateStats(lua_State* L);
    static int clearDesctiption(lua_State* L);
    static int sumStats(lua_State* L);
    static int getStatsPanel(lua_State* L);
};
}