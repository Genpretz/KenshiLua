#pragma once
#include "kenshi/Animation/AnimationClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AnimationDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AnimationData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int checkWeaponArms(lua_State* L);
    static int checkModes(lua_State* L);
    static int scoreInjury(lua_State* L);
    static int scoreSpeed(lua_State* L);
    static int scoreCarryMode(lua_State* L);
    static int scoreWeaponType(lua_State* L);
};
}
