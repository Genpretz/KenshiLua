#include "pch.h"
#include "kenshi\CharacterAnimal.h"
#include "CharacterAnimalBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/ActivePlatoonBinding.h"
#include "Bindings/Kenshi/Building/BuildingBinding.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/GameDataCopyStandaloneBinding.h"
#include "Bindings/Kenshi/GameSaveStateBinding.h"
#include "Bindings/Kenshi/Gui/InventoryLayoutBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/Util/TimeOfDayBinding.h"
#include "Bindings/Kenshi/WeaponBinding.h"
#include <kenshi/Item.h>

namespace KenshiLua
{

static CharacterAnimal* getInstance(lua_State* L, int idx)
{
    return checkObject<CharacterAnimal>(L, idx, CharacterAnimalBinding::getMetatableName());
}

// --- Getters for CharacterAnimal ---
static int CharacterAnimal_get_weaponIsTechnicallyEquipped(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    lua_pushboolean(L, instance->weaponIsTechnicallyEquipped ? 1 : 0);
    return 1;
}

static int CharacterAnimal_get_HPMultiplier(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    lua_pushnumber(L, instance->HPMultiplier);
    return 1;
}

static int CharacterAnimal_get_itemInMouthTimeStamp(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    return pushObject<TimeOfDay>(L, &instance->itemInMouthTimeStamp, TimeOfDayBinding::getMetatableName());
}

static int CharacterAnimal_get_smellThresholdBlood(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    lua_pushnumber(L, instance->smellThresholdBlood);
    return 1;
}

static int CharacterAnimal_get_smellThresholdEggs(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    lua_pushnumber(L, instance->smellThresholdEggs);
    return 1;
}

static int CharacterAnimal_get_ageSizeMin(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    lua_pushnumber(L, instance->ageSizeMin);
    return 1;
}

static int CharacterAnimal_get_ageSizeMax(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    lua_pushnumber(L, instance->ageSizeMax);
    return 1;
}

static int CharacterAnimal_get_lifespanInDays(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    lua_pushnumber(L, instance->lifespanInDays);
    return 1;
}

static int CharacterAnimal_get_lastUpdatedAge(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    lua_pushnumber(L, instance->lastUpdatedAge);
    return 1;
}

static int CharacterAnimal_get_age(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    lua_pushnumber(L, instance->age);
    return 1;
}

static int CharacterAnimal_get_weaponInHands(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    return pushObject<Weapon>(L, instance->weaponInHands, WeaponBinding::getMetatableName());
}

static int CharacterAnimal_get_audioTimeStamp(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    lua_pushnumber(L, instance->audioTimeStamp);
    return 1;
}

// --- Setters for CharacterAnimal ---
static int CharacterAnimal_set_weaponIsTechnicallyEquipped(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->weaponIsTechnicallyEquipped = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharacterAnimal_set_HPMultiplier(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->HPMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_itemInMouthTimeStamp(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->itemInMouthTimeStamp = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int CharacterAnimal_set_smellThresholdBlood(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->smellThresholdBlood = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_smellThresholdEggs(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->smellThresholdEggs = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_ageSizeMin(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->ageSizeMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_ageSizeMax(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->ageSizeMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_lifespanInDays(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->lifespanInDays = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_lastUpdatedAge(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->lastUpdatedAge = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_age(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->age = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_weaponInHands(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->weaponInHands = lua_isnoneornil(L, 2) ? nullptr : checkObject<Weapon>(L, 2, WeaponBinding::getMetatableName());
    return 0;
}

static int CharacterAnimal_set_audioTimeStamp(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->audioTimeStamp = (float)luaL_checknumber(L, 2);
    return 0;
}

int CharacterAnimalBinding::isAnimal(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    CharacterAnimal* result = instance->isAnimal();
    return pushObject<CharacterAnimal>(L, result, CharacterAnimalBinding::getMetatableName());
}

int CharacterAnimalBinding::_NV_isAnimal(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    CharacterAnimal* result = instance->_NV_isAnimal();
    return pushObject<CharacterAnimal>(L, result, CharacterAnimalBinding::getMetatableName());
}

int CharacterAnimalBinding::_NV_createAnimationClass(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->_NV_createAnimationClass();
    return 0;
}

int CharacterAnimalBinding::_NV_drawWeapon(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    Item* _a1 = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    const char* lastSlot = luaL_checkstring(L, 3);
    bool result = instance->_NV_drawWeapon(_a1, lastSlot);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::_NV_sheatheWeapon(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->_NV_sheatheWeapon();
    return 0;
}

int CharacterAnimalBinding::_NV_getCurrentWeapon(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    Weapon* result = instance->_NV_getCurrentWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterAnimalBinding::_NV_getThePreferredWeapon(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    Weapon* result = instance->_NV_getThePreferredWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterAnimalBinding::_NV_createInventoryLayout(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    InventoryLayout* result = instance->_NV_createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

int CharacterAnimalBinding::_NV_giveBirth(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    GameDataCopyStandalone* appearance = checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    Ogre::Vector3 position;
    checkVector3(L, 3, position);
    Ogre::Quaternion rotation;
    checkQuaternion(L, 4, rotation);
    GameSaveState* state = checkObject<GameSaveState>(L, 5, GameSaveStateBinding::getMetatableName());
    ActivePlatoon* tempplatoonptr = checkObject<ActivePlatoon>(L, 6, ActivePlatoonBinding::getMetatableName());
    Faction* _faction = checkObject<Faction>(L, 7, FactionBinding::getMetatableName());
    bool result = instance->_NV_giveBirth(appearance, position, rotation, state, tempplatoonptr, _faction);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::_NV_setupInventorySections(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool result = instance->_NV_setupInventorySections(state);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::_NV_setupAudio(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->_NV_setupAudio();
    return 0;
}

int CharacterAnimalBinding::_NV_periodicUpdate(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->_NV_periodicUpdate();
    return 0;
}

int CharacterAnimalBinding::_NV_setAge(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    float zeroToOne = (float)luaL_checknumber(L, 2);
    instance->_NV_setAge(zeroToOne);
    return 0;
}

int CharacterAnimalBinding::_NV_getAge(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    float result = instance->_NV_getAge();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getAgeInverse(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    float result = instance->_NV_getAgeInverse();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getAge0to1(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    float result = instance->_NV_getAge0to1();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getDefaultTaskRepertoireEnum(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    unsigned int result = instance->_NV_getDefaultTaskRepertoireEnum();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_canGoIndoors(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    Building* b = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    bool result = instance->_NV_canGoIndoors(b);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::getSmellHuntingThresholdBlood(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    float result = instance->getSmellHuntingThresholdBlood();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getSmellHuntingThresholdBlood(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    float result = instance->_NV_getSmellHuntingThresholdBlood();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::getSmellHuntingThresholdEggs(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    float result = instance->getSmellHuntingThresholdEggs();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getSmellHuntingThresholdEggs(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    float result = instance->_NV_getSmellHuntingThresholdEggs();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getHPMultiplier(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    float result = instance->_NV_getHPMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_foodUpdate(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->_NV_foodUpdate();
    return 0;
}

int CharacterAnimalBinding::pickupItemInMouth(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = instance->pickupItemInMouth(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::dropItemInMouth(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    bool result = instance->dropItemInMouth();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::getItemInMouth(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    Item* result = instance->getItemInMouth();
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int CharacterAnimalBinding::eatItemInMouth(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->eatItemInMouth();
    return 0;
}

int CharacterAnimalBinding::_NV_init(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    instance->_NV_init();
    return 0;
}

int CharacterAnimalBinding::dropItem(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    RootObject* itembase = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->dropItem(itembase);
    return 0;
}

int CharacterAnimalBinding::_NV_dropItem(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    RootObject* itembase = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->_NV_dropItem(itembase);
    return 0;
}

int CharacterAnimalBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CharacterAnimalBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CharacterAnimal object");
    return 1;
}

void CharacterAnimalBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CharacterAnimalBinding::gc },
        { "__tostring", CharacterAnimalBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isAnimal", CharacterAnimalBinding::isAnimal },
        { "_NV_isAnimal", CharacterAnimalBinding::_NV_isAnimal },
        { "_NV_createAnimationClass", CharacterAnimalBinding::_NV_createAnimationClass },
        { "_NV_drawWeapon", CharacterAnimalBinding::_NV_drawWeapon },
        { "_NV_sheatheWeapon", CharacterAnimalBinding::_NV_sheatheWeapon },
        { "_NV_getCurrentWeapon", CharacterAnimalBinding::_NV_getCurrentWeapon },
        { "_NV_getThePreferredWeapon", CharacterAnimalBinding::_NV_getThePreferredWeapon },
        { "_NV_createInventoryLayout", CharacterAnimalBinding::_NV_createInventoryLayout },
        { "_NV_giveBirth", CharacterAnimalBinding::_NV_giveBirth },
        { "_NV_setupInventorySections", CharacterAnimalBinding::_NV_setupInventorySections },
        { "_NV_setupAudio", CharacterAnimalBinding::_NV_setupAudio },
        { "_NV_periodicUpdate", CharacterAnimalBinding::_NV_periodicUpdate },
        { "_NV_setAge", CharacterAnimalBinding::_NV_setAge },
        { "_NV_getAge", CharacterAnimalBinding::_NV_getAge },
        { "_NV_getAgeInverse", CharacterAnimalBinding::_NV_getAgeInverse },
        { "_NV_getAge0to1", CharacterAnimalBinding::_NV_getAge0to1 },
        { "_NV_getDefaultTaskRepertoireEnum", CharacterAnimalBinding::_NV_getDefaultTaskRepertoireEnum },
        { "_NV_canGoIndoors", CharacterAnimalBinding::_NV_canGoIndoors },
        { "getSmellHuntingThresholdBlood", CharacterAnimalBinding::getSmellHuntingThresholdBlood },
        { "_NV_getSmellHuntingThresholdBlood", CharacterAnimalBinding::_NV_getSmellHuntingThresholdBlood },
        { "getSmellHuntingThresholdEggs", CharacterAnimalBinding::getSmellHuntingThresholdEggs },
        { "_NV_getSmellHuntingThresholdEggs", CharacterAnimalBinding::_NV_getSmellHuntingThresholdEggs },
        { "_NV_getHPMultiplier", CharacterAnimalBinding::_NV_getHPMultiplier },
        { "_NV_foodUpdate", CharacterAnimalBinding::_NV_foodUpdate },
        { "pickupItemInMouth", CharacterAnimalBinding::pickupItemInMouth },
        { "dropItemInMouth", CharacterAnimalBinding::dropItemInMouth },
        { "getItemInMouth", CharacterAnimalBinding::getItemInMouth },
        { "eatItemInMouth", CharacterAnimalBinding::eatItemInMouth },
        { "_NV_init", CharacterAnimalBinding::_NV_init },
        { "dropItem", CharacterAnimalBinding::dropItem },
        { "_NV_dropItem", CharacterAnimalBinding::_NV_dropItem },
        { 0, 0 }
    };

    registerClass(
        L, 
        CharacterAnimalBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CharacterAnimalBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "weaponIsTechnicallyEquipped", CharacterAnimal_get_weaponIsTechnicallyEquipped);
    registerGetter(L, "HPMultiplier", CharacterAnimal_get_HPMultiplier);
    registerGetter(L, "itemInMouthTimeStamp", CharacterAnimal_get_itemInMouthTimeStamp);
    registerGetter(L, "smellThresholdBlood", CharacterAnimal_get_smellThresholdBlood);
    registerGetter(L, "smellThresholdEggs", CharacterAnimal_get_smellThresholdEggs);
    registerGetter(L, "ageSizeMin", CharacterAnimal_get_ageSizeMin);
    registerGetter(L, "ageSizeMax", CharacterAnimal_get_ageSizeMax);
    registerGetter(L, "lifespanInDays", CharacterAnimal_get_lifespanInDays);
    registerGetter(L, "lastUpdatedAge", CharacterAnimal_get_lastUpdatedAge);
    registerGetter(L, "age", CharacterAnimal_get_age);
    registerGetter(L, "weaponInHands", CharacterAnimal_get_weaponInHands);
    registerGetter(L, "audioTimeStamp", CharacterAnimal_get_audioTimeStamp);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "weaponIsTechnicallyEquipped", CharacterAnimal_set_weaponIsTechnicallyEquipped);
    registerSetter(L, "HPMultiplier", CharacterAnimal_set_HPMultiplier);
    registerSetter(L, "itemInMouthTimeStamp", CharacterAnimal_set_itemInMouthTimeStamp);
    registerSetter(L, "smellThresholdBlood", CharacterAnimal_set_smellThresholdBlood);
    registerSetter(L, "smellThresholdEggs", CharacterAnimal_set_smellThresholdEggs);
    registerSetter(L, "ageSizeMin", CharacterAnimal_set_ageSizeMin);
    registerSetter(L, "ageSizeMax", CharacterAnimal_set_ageSizeMax);
    registerSetter(L, "lifespanInDays", CharacterAnimal_set_lifespanInDays);
    registerSetter(L, "lastUpdatedAge", CharacterAnimal_set_lastUpdatedAge);
    registerSetter(L, "age", CharacterAnimal_set_age);
    registerSetter(L, "weaponInHands", CharacterAnimal_set_weaponInHands);
    registerSetter(L, "audioTimeStamp", CharacterAnimal_set_audioTimeStamp);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
