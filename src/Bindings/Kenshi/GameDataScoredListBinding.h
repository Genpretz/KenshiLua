#pragma once
#include "kenshi/Campaign.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GameDataScoredListBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GameDataScoredList"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setupFromData(lua_State* L);
};
}
