#pragma once

#include "kenshi/Animation/AnimationClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class AnimationClassBase_SingleAnimationBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AnimationClassBase.SingleAnimation"; }
    static void registerBinding(lua_State* L);

    static int getAnimTime(lua_State* L);
    static int hasSound(lua_State* L);
    static int _disable(lua_State* L);
    static int disable(lua_State* L);
    static int notStartedYet(lua_State* L);
    static int isACombatAnimation(lua_State* L);
    static int isABlockAnimation(lua_State* L);
    static int initialiseMainState(lua_State* L);
    static int fade(lua_State* L);
    static int update(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

