#pragma once
#include "kenshi/combat/CombatState.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AttackStateBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AttackState"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int validate(lua_State* L);
    static int _NV_validate(lua_State* L);
    static int initialiseAttack(lua_State* L);
    static int initialise(lua_State* L);
    static int _NV_initialise(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int end(lua_State* L);
    static int _NV_end(lua_State* L);
};
}
