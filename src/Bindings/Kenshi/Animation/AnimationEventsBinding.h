#pragma once

#include "kenshi/Animation/AnimationClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class AnimationEventsBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AnimationEvents"; }
    static void registerBinding(lua_State* L);

    static int setInitialFrame(lua_State* L);
    static int update(lua_State* L);
    static int addEvent(lua_State* L);
    static int size(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

