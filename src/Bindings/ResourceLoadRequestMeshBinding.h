#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ResourceLoadRequestMeshBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ResourceLoadRequestMesh"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int finish(lua_State* L);
};
}
