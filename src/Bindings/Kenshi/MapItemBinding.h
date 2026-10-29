#pragma once
#include "kenshi/Item.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class MapItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MapItem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getItemWeight(lua_State* L);
    static int _NV_getItemWeight(lua_State* L);
    static int getValueSingle(lua_State* L);
    static int _NV_getValueSingle(lua_State* L);
    static int selectTowns(lua_State* L);
    static int consume(lua_State* L);
    static int getTownsDiscovered(lua_State* L);
    static int _loadFromSerialise(lua_State* L);
    static int _NV__loadFromSerialise(lua_State* L);
    static int _serialise(lua_State* L);
    static int _NV__serialise(lua_State* L);
};
}
