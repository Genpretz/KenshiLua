#pragma once
#include "kenshi/Animation/RagdollAnimation.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RagdollAnimationBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RagdollAnimation"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isAnimating(lua_State* L);
    static int update(lua_State* L);
    static int setTargetAnimation(lua_State* L);
    static int getTargetAnimation(lua_State* L);
    static int getAnimationTime(lua_State* L);
};
}
