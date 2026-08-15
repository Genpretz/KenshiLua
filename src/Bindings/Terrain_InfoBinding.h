#pragma once
#include "kenshi/Terrain.h"

namespace KenshiLua
{
class Terrain_InfoBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Terrain_Info"; }
    static void registerBinding(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
