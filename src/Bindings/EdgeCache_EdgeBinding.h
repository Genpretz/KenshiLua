#pragma once
#include "kenshi/HavokCharacter.h"

namespace KenshiLua
{
class EdgeCache_EdgeBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.EdgeCache_Edge"; }
    static void registerBinding(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
