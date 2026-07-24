#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class NewGameWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.NewGameWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int setVisible(lua_State* L);
    static int getVisible(lua_State* L);
    static int setRealPosition(lua_State* L);
    static int setPosition(lua_State* L);
    static int _NV_setPosition(lua_State* L);
    static int show(lua_State* L);
    static int _NV_show(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int loadData(lua_State* L);
    static int updateCurrentData(lua_State* L);
};
}