#pragma once

#include "kenshi/Animation/AnimationClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class AnimationRequirementBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AnimationRequirement"; }
    static void registerBinding(lua_State* L);

    static int isUpperBodyOnlyAction(lua_State* L);
    static int hasAction(lua_State* L);
    static int clearAction(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

