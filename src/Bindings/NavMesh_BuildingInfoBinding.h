#pragma once
#include "pch.h"
#include "kenshi/NavMesh.h"

namespace KenshiLua
{
class NavMesh_BuildingInfoBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.NavMesh_BuildingInfo"; }
    static void registerBinding(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
