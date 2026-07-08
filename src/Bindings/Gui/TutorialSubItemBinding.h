#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TutorialSubItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TutorialSubItem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int start(lua_State* L);
    static int _NV_start(lua_State* L);
    static int run(lua_State* L);
    static int _NV_run(lua_State* L);
    static int end(lua_State* L);
    static int _NV_end(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}