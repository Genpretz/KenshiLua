#pragma once
#include "kenshi/SharedKing.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SharedKingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SharedKing"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isLevelEditMode(lua_State* L);
};
}
