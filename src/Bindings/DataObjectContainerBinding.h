#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DataObjectContainerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DataObjectContainer"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int getType(lua_State* L);
    static int destroyObjectDatas(lua_State* L);
};
}
