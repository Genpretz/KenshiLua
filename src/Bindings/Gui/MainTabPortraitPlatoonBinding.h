#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class MainTabPortraitPlatoonBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MainTabPortraitPlatoon"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int detach(lua_State* L);
    static int setFlash(lua_State* L);
    static int update(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}