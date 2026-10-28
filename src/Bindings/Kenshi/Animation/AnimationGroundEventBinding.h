#pragma once
#include "kenshi/Animation/AnimationEvent.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AnimationGroundEventBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AnimationGroundEvent"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int trigger(lua_State* L);
    static int _NV_trigger(lua_State* L);
    static int toString(lua_State* L);
    static int _NV_toString(lua_State* L);
};
}
