#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class HandleListBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.HandleList"; }
    static void registerBinding(lua_State* L);

    static int add(lua_State* L);
    static int _NV_add(lua_State* L);
    static int get(lua_State* L);
    static int _NV_get(lua_State* L);
    static int addExisting(lua_State* L);
    static int _NV_addExisting(lua_State* L);
    static int addExistingAndForceContainer(lua_State* L);
    static int _NV_addExistingAndForceContainer(lua_State* L);
    static int destroy(lua_State* L);
    static int _NV_destroy(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

