#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SplashScreenBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SplashScreen"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int update(lua_State* L);
    static int getState(lua_State* L);
    static int getEnded(lua_State* L);
    static int skip(lua_State* L);
    static int addLogo(lua_State* L);
};
}