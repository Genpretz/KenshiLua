#pragma once
#include "kenshi/Town.h"

namespace KenshiLua
{
class Town_NestSpotBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Town_NestSpot"; }
    static void registerBinding(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
