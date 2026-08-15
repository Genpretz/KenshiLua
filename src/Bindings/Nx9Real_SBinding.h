#pragma once
#include "kenshi/PhysicsActual.h"

namespace KenshiLua
{
class Nx9Real_SBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Nx9Real_S"; }
    static void registerBinding(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
