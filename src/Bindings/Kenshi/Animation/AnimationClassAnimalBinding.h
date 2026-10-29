#pragma once
#include "kenshi/Animation/AnimationClassAnimal.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AnimationClassAnimalBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AnimationClassAnimal"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isHuman(lua_State* L);
    static int _NV_isHuman(lua_State* L);
};
}
