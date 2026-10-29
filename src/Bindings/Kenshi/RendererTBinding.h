#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class RendererTBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RendererT"; }
    static void registerBinding(lua_State* L);

    static int update(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

