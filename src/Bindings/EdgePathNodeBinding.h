#pragma once
#include "kenshi/HavokCharacter.h"

namespace KenshiLua
{
class EdgePathNodeBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.EdgePathNode"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
