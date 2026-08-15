#include "pch.h"
#include "kenshi\CharacterAnimal.h"
#include "CharacterAnimalBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataCopyStandaloneBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
#include "Bindings/WeaponBinding.h"
#include "ItemBinding.h"
#include "WeaponBinding.h"
#include "kenshi/Item.h"

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
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushboolean(L, instance->weaponIsTechnicallyEquipped ? 1 : 0);
    return 1;
}

static int CharacterAnimal_get_HPMultiplier(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, instance->HPMultiplier);
    return 1;
}

static int CharacterAnimal_get_itemInMouthTimeStamp(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    return pushObject<TimeOfDay>(L, &instance->itemInMouthTimeStamp, TimeOfDayBinding::getMetatableName());
}

static int CharacterAnimal_get_smellThresholdBlood(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, instance->smellThresholdBlood);
    return 1;
}

static int CharacterAnimal_get_smellThresholdEggs(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, instance->smellThresholdEggs);
    return 1;
}

static int CharacterAnimal_get_ageSizeMin(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, instance->ageSizeMin);
    return 1;
}

static int CharacterAnimal_get_ageSizeMax(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, instance->ageSizeMax);
    return 1;
}

static int CharacterAnimal_get_lifespanInDays(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, instance->lifespanInDays);
    return 1;
}

static int CharacterAnimal_get_lastUpdatedAge(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, instance->lastUpdatedAge);
    return 1;
}

static int CharacterAnimal_get_age(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, instance->age);
    return 1;
}

static int CharacterAnimal_get_weaponInHands(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    return pushObject<Weapon>(L, instance->weaponInHands, WeaponBinding::getMetatableName());
}

static int CharacterAnimal_get_audioTimeStamp(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, instance->audioTimeStamp);
    return 1;
}

// --- Setters for CharacterAnimal ---
static int CharacterAnimal_set_weaponIsTechnicallyEquipped(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    instance->weaponIsTechnicallyEquipped = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharacterAnimal_set_HPMultiplier(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    instance->HPMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_itemInMouthTimeStamp(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    instance->itemInMouthTimeStamp = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int CharacterAnimal_set_smellThresholdBlood(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    instance->smellThresholdBlood = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_smellThresholdEggs(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    instance->smellThresholdEggs = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_ageSizeMin(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    instance->ageSizeMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_ageSizeMax(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    instance->ageSizeMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_lifespanInDays(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    instance->lifespanInDays = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_lastUpdatedAge(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    instance->lastUpdatedAge = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_age(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    instance->age = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_weaponInHands(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    instance->weaponInHands = lua_isnoneornil(L, 2) ? nullptr : checkObject<Weapon>(L, 2, WeaponBinding::getMetatableName());
    return 0;
}

static int CharacterAnimal_set_audioTimeStamp(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");
    instance->audioTimeStamp = (float)luaL_checknumber(L, 2);
    return 0;
}

int CharacterAnimalBinding::isAnimal(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    CharacterAnimal* result = instance->isAnimal();
    return pushObject<CharacterAnimal>(L, result, CharacterAnimalBinding::getMetatableName());
}

int CharacterAnimalBinding::_NV_isAnimal(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    CharacterAnimal* result = instance->_NV_isAnimal();
    return pushObject<CharacterAnimal>(L, result, CharacterAnimalBinding::getMetatableName());
}

int CharacterAnimalBinding::createAnimationClass(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    instance->createAnimationClass();
    return 0;
}

int CharacterAnimalBinding::_NV_createAnimationClass(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    instance->_NV_createAnimationClass();
    return 0;
}

int CharacterAnimalBinding::drawWeapon(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    Item* _a1 = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    std::string lastSlot = luaL_checkstring(L, 3);
    bool result = instance->drawWeapon(_a1, lastSlot);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::_NV_drawWeapon(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    Item* _a1 = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    std::string lastSlot = luaL_checkstring(L, 3);
    bool result = instance->_NV_drawWeapon(_a1, lastSlot);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::sheatheWeapon(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    instance->sheatheWeapon();
    return 0;
}

int CharacterAnimalBinding::_NV_sheatheWeapon(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    instance->_NV_sheatheWeapon();
    return 0;
}

int CharacterAnimalBinding::getCurrentWeapon(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    Weapon* result = instance->getCurrentWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterAnimalBinding::_NV_getCurrentWeapon(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    Weapon* result = instance->_NV_getCurrentWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterAnimalBinding::getThePreferredWeapon(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    Weapon* result = instance->getThePreferredWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterAnimalBinding::_NV_getThePreferredWeapon(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    Weapon* result = instance->_NV_getThePreferredWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterAnimalBinding::createInventoryLayout(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    InventoryLayout* result = instance->createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

int CharacterAnimalBinding::_NV_createInventoryLayout(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    InventoryLayout* result = instance->_NV_createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

int CharacterAnimalBinding::giveBirth(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    GameDataCopyStandalone* appearance = checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    Ogre::Quaternion rotation;
    readQuaternion(L, 4, rotation);
    GameSaveState* state = checkObject<GameSaveState>(L, 5, GameSaveStateBinding::getMetatableName());
    ActivePlatoon* tempplatoonptr = checkObject<ActivePlatoon>(L, 6, ActivePlatoonBinding::getMetatableName());
    Faction* _faction = checkObject<Faction>(L, 7, FactionBinding::getMetatableName());
    bool result = instance->giveBirth(appearance, position, rotation, state, tempplatoonptr, _faction);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::_NV_giveBirth(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    GameDataCopyStandalone* appearance = checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    Ogre::Quaternion rotation;
    readQuaternion(L, 4, rotation);
    GameSaveState* state = checkObject<GameSaveState>(L, 5, GameSaveStateBinding::getMetatableName());
    ActivePlatoon* tempplatoonptr = checkObject<ActivePlatoon>(L, 6, ActivePlatoonBinding::getMetatableName());
    Faction* _faction = checkObject<Faction>(L, 7, FactionBinding::getMetatableName());
    bool result = instance->_NV_giveBirth(appearance, position, rotation, state, tempplatoonptr, _faction);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::setupInventorySections(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool result = instance->setupInventorySections(state);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::_NV_setupInventorySections(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool result = instance->_NV_setupInventorySections(state);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::setupAudio(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    instance->setupAudio();
    return 0;
}

int CharacterAnimalBinding::_NV_setupAudio(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    instance->_NV_setupAudio();
    return 0;
}

int CharacterAnimalBinding::periodicUpdate(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    instance->periodicUpdate();
    return 0;
}

int CharacterAnimalBinding::_NV_periodicUpdate(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    instance->_NV_periodicUpdate();
    return 0;
}

int CharacterAnimalBinding::setAge(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    float zeroToOne = (float)luaL_checknumber(L, 2);
    instance->setAge(zeroToOne);
    return 0;
}

int CharacterAnimalBinding::_NV_setAge(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    float zeroToOne = (float)luaL_checknumber(L, 2);
    instance->_NV_setAge(zeroToOne);
    return 0;
}

int CharacterAnimalBinding::getAge(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    float result = instance->getAge();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getAge(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    float result = instance->_NV_getAge();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::getAgeInverse(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    float result = instance->getAgeInverse();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getAgeInverse(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    float result = instance->_NV_getAgeInverse();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::getAge0to1(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    float result = instance->getAge0to1();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getAge0to1(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    float result = instance->_NV_getAge0to1();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::getDefaultTaskRepertoireEnum(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    unsigned int result = instance->getDefaultTaskRepertoireEnum();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getDefaultTaskRepertoireEnum(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    unsigned int result = instance->_NV_getDefaultTaskRepertoireEnum();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterAnimalBinding::canGoIndoors(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    Building* b = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    bool result = instance->canGoIndoors(b);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::_NV_canGoIndoors(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    Building* b = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    bool result = instance->_NV_canGoIndoors(b);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::getSmellHuntingThresholdBlood(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    float result = instance->getSmellHuntingThresholdBlood();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getSmellHuntingThresholdBlood(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    float result = instance->_NV_getSmellHuntingThresholdBlood();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::getSmellHuntingThresholdEggs(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    float result = instance->getSmellHuntingThresholdEggs();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getSmellHuntingThresholdEggs(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    float result = instance->_NV_getSmellHuntingThresholdEggs();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::getHPMultiplier(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    float result = instance->getHPMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getHPMultiplier(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    float result = instance->_NV_getHPMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::foodUpdate(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    instance->foodUpdate();
    return 0;
}

int CharacterAnimalBinding::_NV_foodUpdate(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    instance->_NV_foodUpdate();
    return 0;
}

int CharacterAnimalBinding::pickupItemInMouth(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = instance->pickupItemInMouth(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::dropItemInMouth(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    bool result = instance->dropItemInMouth();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::getItemInMouth(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    Item* result = instance->getItemInMouth();
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int CharacterAnimalBinding::eatItemInMouth(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    instance->eatItemInMouth();
    return 0;
}

int CharacterAnimalBinding::init(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    instance->init();
    return 0;
}

int CharacterAnimalBinding::_NV_init(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    instance->_NV_init();
    return 0;
}

int CharacterAnimalBinding::dropItem(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

    RootObject* itembase = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->dropItem(itembase);
    return 0;
}

int CharacterAnimalBinding::_NV_dropItem(lua_State* L)
{
    CharacterAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterAnimal is nil");

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
        { "createAnimationClass", CharacterAnimalBinding::createAnimationClass },
        { "_NV_createAnimationClass", CharacterAnimalBinding::_NV_createAnimationClass },
        { "drawWeapon", CharacterAnimalBinding::drawWeapon },
        { "_NV_drawWeapon", CharacterAnimalBinding::_NV_drawWeapon },
        { "sheatheWeapon", CharacterAnimalBinding::sheatheWeapon },
        { "_NV_sheatheWeapon", CharacterAnimalBinding::_NV_sheatheWeapon },
        { "getCurrentWeapon", CharacterAnimalBinding::getCurrentWeapon },
        { "_NV_getCurrentWeapon", CharacterAnimalBinding::_NV_getCurrentWeapon },
        { "getThePreferredWeapon", CharacterAnimalBinding::getThePreferredWeapon },
        { "_NV_getThePreferredWeapon", CharacterAnimalBinding::_NV_getThePreferredWeapon },
        { "createInventoryLayout", CharacterAnimalBinding::createInventoryLayout },
        { "_NV_createInventoryLayout", CharacterAnimalBinding::_NV_createInventoryLayout },
        { "giveBirth", CharacterAnimalBinding::giveBirth },
        { "_NV_giveBirth", CharacterAnimalBinding::_NV_giveBirth },
        { "setupInventorySections", CharacterAnimalBinding::setupInventorySections },
        { "_NV_setupInventorySections", CharacterAnimalBinding::_NV_setupInventorySections },
        { "setupAudio", CharacterAnimalBinding::setupAudio },
        { "_NV_setupAudio", CharacterAnimalBinding::_NV_setupAudio },
        { "periodicUpdate", CharacterAnimalBinding::periodicUpdate },
        { "_NV_periodicUpdate", CharacterAnimalBinding::_NV_periodicUpdate },
        { "setAge", CharacterAnimalBinding::setAge },
        { "_NV_setAge", CharacterAnimalBinding::_NV_setAge },
        { "getAge", CharacterAnimalBinding::getAge },
        { "_NV_getAge", CharacterAnimalBinding::_NV_getAge },
        { "getAgeInverse", CharacterAnimalBinding::getAgeInverse },
        { "_NV_getAgeInverse", CharacterAnimalBinding::_NV_getAgeInverse },
        { "getAge0to1", CharacterAnimalBinding::getAge0to1 },
        { "_NV_getAge0to1", CharacterAnimalBinding::_NV_getAge0to1 },
        { "getDefaultTaskRepertoireEnum", CharacterAnimalBinding::getDefaultTaskRepertoireEnum },
        { "_NV_getDefaultTaskRepertoireEnum", CharacterAnimalBinding::_NV_getDefaultTaskRepertoireEnum },
        { "canGoIndoors", CharacterAnimalBinding::canGoIndoors },
        { "_NV_canGoIndoors", CharacterAnimalBinding::_NV_canGoIndoors },
        { "getSmellHuntingThresholdBlood", CharacterAnimalBinding::getSmellHuntingThresholdBlood },
        { "_NV_getSmellHuntingThresholdBlood", CharacterAnimalBinding::_NV_getSmellHuntingThresholdBlood },
        { "getSmellHuntingThresholdEggs", CharacterAnimalBinding::getSmellHuntingThresholdEggs },
        { "_NV_getSmellHuntingThresholdEggs", CharacterAnimalBinding::_NV_getSmellHuntingThresholdEggs },
        { "getHPMultiplier", CharacterAnimalBinding::getHPMultiplier },
        { "_NV_getHPMultiplier", CharacterAnimalBinding::_NV_getHPMultiplier },
        { "foodUpdate", CharacterAnimalBinding::foodUpdate },
        { "_NV_foodUpdate", CharacterAnimalBinding::_NV_foodUpdate },
        { "pickupItemInMouth", CharacterAnimalBinding::pickupItemInMouth },
        { "dropItemInMouth", CharacterAnimalBinding::dropItemInMouth },
        { "getItemInMouth", CharacterAnimalBinding::getItemInMouth },
        { "eatItemInMouth", CharacterAnimalBinding::eatItemInMouth },
        { "init", CharacterAnimalBinding::init },
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

    // Wire up inheritance to Character
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, CharacterAnimalBinding::getMetatableName(), CharacterBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua