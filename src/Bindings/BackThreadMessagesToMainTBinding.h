#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

#include <kenshi/ZoneManager.h>
namespace KenshiLua
{
    typedef ::BackThreadMessagesToMainT<ZoneMap::ZONE_MESSAGE> BackThreadMessagesToMainT;
class BackThreadMessagesToMainTBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BackThreadMessagesToMainT"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int flush(lua_State* L);
    static int _NV_flush(lua_State* L);
};
}