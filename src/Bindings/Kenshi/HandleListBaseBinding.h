#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class HandleListBaseBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.HandleListBase"; }
    static void registerBinding(lua_State* L);

    static int clearToZero(lua_State* L);
    static int _NV_clearToZero(lua_State* L);
    static int get(lua_State* L);
    static int _NV_get(lua_State* L);
    static int isUnloadedNotDead(lua_State* L);
    static int _NV_isUnloadedNotDead(lua_State* L);
    static int addExisting(lua_State* L);
    static int _NV_addExisting(lua_State* L);
    static int setUnloaded(lua_State* L);
    static int _NV_setUnloaded(lua_State* L);
    static int destroy(lua_State* L);
    static int _NV_destroy(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

