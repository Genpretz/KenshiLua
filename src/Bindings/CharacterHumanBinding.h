#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CharacterHumanBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CharacterHuman"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int sheatheWeapon(lua_State* L);
    static int _NV_sheatheWeapon(lua_State* L);
    static int getCurrentWeapon(lua_State* L);
    static int _NV_getCurrentWeapon(lua_State* L);
    static int getThePreferredWeapon(lua_State* L);
    static int _NV_getThePreferredWeapon(lua_State* L);
    static int getRangedWeapon(lua_State* L);
    static int _NV_getRangedWeapon(lua_State* L);
    static int validateInventorySections(lua_State* L);
    static int _NV_validateInventorySections(lua_State* L);
    static int setupAudio(lua_State* L);
    static int _NV_setupAudio(lua_State* L);
    static int shaveHead(lua_State* L);
    static int isHeadShaven(lua_State* L);
    static int _NV_isHeadShaven(lua_State* L);
    static int createAnimationClass(lua_State* L);
    static int _NV_createAnimationClass(lua_State* L);
    static int dropWeaponInHands(lua_State* L);
    static int dropWeaponInHandsFake(lua_State* L);
    static int weatherUpdate(lua_State* L);
    static int _NV_weatherUpdate(lua_State* L);
    static int leaveSheathEquipped(lua_State* L);
    static int postRagdollCallback(lua_State* L);
    static int _NV_postRagdollCallback(lua_State* L);
    static int reCalculateNaturalWeapon(lua_State* L);
    static int _NV_reCalculateNaturalWeapon(lua_State* L);
};
}
