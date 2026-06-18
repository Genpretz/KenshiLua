#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AnimalInventoryLayoutBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AnimalInventoryLayout"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
};

class CharacterAnimalBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CharacterAnimal"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int createAnimationClass(lua_State* L);
    static int _NV_createAnimationClass(lua_State* L);
    static int sheatheWeapon(lua_State* L);
    static int _NV_sheatheWeapon(lua_State* L);
    static int setupAudio(lua_State* L);
    static int _NV_setupAudio(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int setAge(lua_State* L);
    static int _NV_setAge(lua_State* L);
    static int getAge(lua_State* L);
    static int _NV_getAge(lua_State* L);
    static int getAgeInverse(lua_State* L);
    static int _NV_getAgeInverse(lua_State* L);
    static int getAge0to1(lua_State* L);
    static int _NV_getAge0to1(lua_State* L);
    static int getDefaultTaskRepertoireEnum(lua_State* L);
    static int _NV_getDefaultTaskRepertoireEnum(lua_State* L);
    static int getSmellHuntingThresholdBlood(lua_State* L);
    static int _NV_getSmellHuntingThresholdBlood(lua_State* L);
    static int getSmellHuntingThresholdEggs(lua_State* L);
    static int _NV_getSmellHuntingThresholdEggs(lua_State* L);
    static int getHPMultiplier(lua_State* L);
    static int _NV_getHPMultiplier(lua_State* L);
    static int foodUpdate(lua_State* L);
    static int _NV_foodUpdate(lua_State* L);
    static int dropItemInMouth(lua_State* L);
    static int eatItemInMouth(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int init(lua_State* L);
    static int _NV_init(lua_State* L);
};
}
