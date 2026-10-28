#pragma once

#include "kenshi/CharacterAnimal.h"

extern "C" {
#include <lua.h>
}

namespace KenshiLua
{
class CharacterAnimalBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CharacterAnimal"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isAnimal(lua_State* L);
    static int _NV_isAnimal(lua_State* L);
    static int _NV_createAnimationClass(lua_State* L);
    static int _NV_drawWeapon(lua_State* L);
    static int _NV_sheatheWeapon(lua_State* L);
    static int _NV_getCurrentWeapon(lua_State* L);
    static int _NV_getThePreferredWeapon(lua_State* L);
    static int _NV_createInventoryLayout(lua_State* L);
    static int _NV_giveBirth(lua_State* L);
    static int _NV_setupInventorySections(lua_State* L);
    static int _NV_setupAudio(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int _NV_setAge(lua_State* L);
    static int _NV_getAge(lua_State* L);
    static int _NV_getAgeInverse(lua_State* L);
    static int _NV_getAge0to1(lua_State* L);
    static int _NV_getDefaultTaskRepertoireEnum(lua_State* L);
    static int _NV_canGoIndoors(lua_State* L);
    static int getSmellHuntingThresholdBlood(lua_State* L);
    static int _NV_getSmellHuntingThresholdBlood(lua_State* L);
    static int getSmellHuntingThresholdEggs(lua_State* L);
    static int _NV_getSmellHuntingThresholdEggs(lua_State* L);
    static int _NV_getHPMultiplier(lua_State* L);
    static int _NV_foodUpdate(lua_State* L);
    static int pickupItemInMouth(lua_State* L);
    static int dropItemInMouth(lua_State* L);
    static int getItemInMouth(lua_State* L);
    static int eatItemInMouth(lua_State* L);
    static int _NV_init(lua_State* L);
    static int dropItem(lua_State* L);
    static int _NV_dropItem(lua_State* L);
};
}
