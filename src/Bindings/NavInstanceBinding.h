#pragma once
#include "kenshi/NavInstance.h"

namespace KenshiLua
{
class NavInstanceBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.NavInstance"; }
    static void registerBinding(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
