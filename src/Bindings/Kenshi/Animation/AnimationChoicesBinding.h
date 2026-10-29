#pragma once

#include "kenshi/Animation/AnimationClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class AnimationChoicesBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AnimationChoices"; }
    static void registerBinding(lua_State* L);

    static int normaliseWeights(lua_State* L);
    static int calculateSpeedOfMoveAnims(lua_State* L);
    static int chooseHighestScore(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

