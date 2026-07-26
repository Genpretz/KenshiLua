#pragma once
#include <kenshi/Town.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef TownBase::DelayedSpawnMsg DelayedSpawnMsg;

class DelayedSpawnMsgBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DelayedSpawnMsg"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
};
}
