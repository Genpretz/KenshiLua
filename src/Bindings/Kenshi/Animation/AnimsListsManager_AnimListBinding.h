#pragma once

#include "kenshi/Animation/AnimationClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class AnimsListsManager_AnimListBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AnimsListsManager.AnimList"; }
    static void registerBinding(lua_State* L);

    static int getStumbles(lua_State* L);
    static int getStrafe(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

