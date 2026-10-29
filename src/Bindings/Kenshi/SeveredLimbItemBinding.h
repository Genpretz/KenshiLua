#pragma once
#include "kenshi/Item.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SeveredLimbItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SeveredLimbItem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setupFromCharacter(lua_State* L);
    static int _serialise(lua_State* L);
    static int _NV__serialise(lua_State* L);
    static int _loadFromSerialise(lua_State* L);
    static int _NV__loadFromSerialise(lua_State* L);
    static int getTimeout(lua_State* L);
    static int _NV_getTimeout(lua_State* L);
    static int destroyPhysical(lua_State* L);
    static int _NV_destroyPhysical(lua_State* L);
};
}
