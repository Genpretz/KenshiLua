#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GameDataEditorWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GameDataEditorWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int _NV_show(lua_State* L);
    static int initDataValues(lua_State* L);
};
}