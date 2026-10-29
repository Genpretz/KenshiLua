#pragma once

#include "kenshi/Animation/AnimationClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class AnimationClassBase_AnimationLayerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AnimationClassBase.AnimationLayer"; }
    static void registerBinding(lua_State* L);

    static int addToRemoveList(lua_State* L);
    static int clearLists(lua_State* L);
    static int _clearListsSafe(lua_State* L);
    static int randomiseAnimationPosition(lua_State* L);
    static int isAnimationInRemoveList(lua_State* L);
    static int isAnimationInAddList(lua_State* L);
    static int isAnimationInAddList_Datname(lua_State* L);
    static int takeFromRemoveList(lua_State* L);
    static int takeFromAddList(lua_State* L);
    static int getTotalAnimationWeight(lua_State* L);
    static int getTotalActionAnimationWeight(lua_State* L);
    static int stillPlayingAnActionOrSomething(lua_State* L);
    static int getCurrentAnimationWeight(lua_State* L);
    static int updateAnimationSpeed(lua_State* L);
    static int removeAnimation(lua_State* L);
    static int update2frame(lua_State* L);
    static int moveAllToRemoveList(lua_State* L);
    static int endAllAnimations(lua_State* L);
    static int stopActionAnimations(lua_State* L);
    static int stopAllAnimation(lua_State* L);
    static int stopAllAnimationThatMovesFromOrigin(lua_State* L);
    static int clearAllAnimationUT(lua_State* L);
    static int getAnimTime(lua_State* L);
    static int usingRightArm(lua_State* L);
    static int usingLeftArm(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

