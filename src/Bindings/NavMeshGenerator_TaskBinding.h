#pragma once
#include "kenshi/NavMeshGenerator.h"

namespace KenshiLua
{
class NavMeshGenerator_TaskBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.NavMeshGenerator_Task"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
