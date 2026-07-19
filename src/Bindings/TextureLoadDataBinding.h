#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TextureLoadDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TextureLoadData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int loadImage(lua_State* L);
    static int _NV_loadImage(lua_State* L);
};
}
