#pragma once
#include "kenshi/Animation/AnimationClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AnimationClassBaseBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AnimationClassBase"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setVisible(lua_State* L);
    static int getVisible(lua_State* L);
    static int stopAllAnimation(lua_State* L);
    static int clearAllAnimationUT(lua_State* L);
    static int getBoneWorldOrientation(lua_State* L);
    static int getBoneWorldPosition(lua_State* L);
    static int getHasBone(lua_State* L);
    static int hasAnimation(lua_State* L);
    static int getSceneNodePosition(lua_State* L);
    static int getSceneNodeOrientation(lua_State* L);
    static int getBoneLocalOrientation(lua_State* L);
    static int getBoneLocalPosition(lua_State* L);
    static int getRootBoneWorldPosition(lua_State* L);
    static int getRootBoneLocalPosition(lua_State* L);
    static int getBoneInitialLocalPosition(lua_State* L);
    static int getBoneInitialLocalOrientation(lua_State* L);
    static int getBoneInitialWorldPosition(lua_State* L);
    static int getBoneInitialWorldOrientation(lua_State* L);
    static int resetOrientation(lua_State* L);
    static int getAnimationProgress(lua_State* L);
    static int getOrientation(lua_State* L);
    static int setVerticalPosition(lua_State* L);
    static int getAudioObject(lua_State* L);
    static int getCharacter(lua_State* L);
    static int _NV_getCharacter(lua_State* L);
    static int setMasterTimeSpeed(lua_State* L);
    static int getMasterTimeSpeed(lua_State* L);
    static int getMasterTime(lua_State* L);
    static int isVisibleEntity(lua_State* L);
    static int initBoneInitialWorldPositions(lua_State* L);
    static int isAnimationPlaying(lua_State* L);
    static int getTotalActionAnimationWeight(lua_State* L);
    static int stillPlayingAnActionOrSomething(lua_State* L);
};
}
