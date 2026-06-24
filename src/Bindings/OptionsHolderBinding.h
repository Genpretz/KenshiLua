#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class OptionsHolderBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.OptionsHolder"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int enabledCivilians(lua_State* L);
    static int characterMultithreadingEnabled(lua_State* L);
    static int compositiorEnabled(lua_State* L);
    static int loadCompositorSettings(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}