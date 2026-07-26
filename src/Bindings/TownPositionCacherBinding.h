#pragma once
#include <kenshi/Town.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef TownBase::TownPositionCacher TownPositionCacher;

class TownPositionCacherBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TownPositionCacher"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int stampUpdate(lua_State* L);
    static int needsUpdate(lua_State* L);
};
}
