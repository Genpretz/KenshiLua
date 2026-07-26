#pragma once
#include <kenshi/ZoneManager.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef ::MainthreadStateReaderT<ZoneMap::ZONE_MESSAGE> MainthreadStateReaderT;

class MainthreadStateReaderTBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MainthreadStateReaderT"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int updateBackDataCheck(lua_State* L);
    static int _NV_updateBackDataCheck(lua_State* L);
    static int getMainData(lua_State* L);
    static int getBackData(lua_State* L);
};
}
