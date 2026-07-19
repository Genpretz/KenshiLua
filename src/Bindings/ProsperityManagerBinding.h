#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ProsperityManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ProsperityManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int getProsperityMultiplier(lua_State* L);
    static int update(lua_State* L);
};
}
