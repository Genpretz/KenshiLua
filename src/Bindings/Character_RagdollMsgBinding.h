#pragma once
#include "kenshi/Character.h"

namespace KenshiLua
{
class Character_RagdollMsgBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Character_RagdollMsg"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
}
