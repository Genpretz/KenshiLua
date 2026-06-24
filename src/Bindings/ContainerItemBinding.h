#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ContainerItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ContainerItem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int getClassType(lua_State* L);
    static int _NV_getClassType(lua_State* L);
    static int takeMoney(lua_State* L);
    static int _NV_takeMoney(lua_State* L);
    static int getMoney(lua_State* L);
    static int _NV_getMoney(lua_State* L);
    static int doubleCheckHandle(lua_State* L);
    static int getPosition(lua_State* L);
    static int _NV_getPosition(lua_State* L);
    static int getInventory(lua_State* L);
    static int _NV_getInventory(lua_State* L);
};
}