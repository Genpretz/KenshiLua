#pragma once
#include "kenshi/Character.h"

namespace KenshiLua
{
class AkVectorBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AkVector"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
