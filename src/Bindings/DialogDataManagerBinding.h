#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DialogDataManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DialogDataManager"; }
    static void registerBinding(lua_State* L);

    static int _createData(lua_State* L);
    static int initialise(lua_State* L);
    static int save(lua_State* L);
    static int load(lua_State* L);
    static int newGameReset(lua_State* L);
    static int getData(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}