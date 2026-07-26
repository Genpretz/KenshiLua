#include "pch.h"
#include "kenshi\Item.h"
#include "ItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ArmourBinding.h"
#include "Bindings/CrossbowBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/GearBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/InventoryItemBaseBinding.h"
#include "Bindings/LockedArmourBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
#include "Bindings/WeaponBinding.h"
#include "Bindings/Util/YesNoMaybeBinding.h"
#include "ArmourBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "CrossbowBinding.h"
#include "GearBinding.h"
#include "InventoryBinding.h"
#include "LockedArmourBinding.h"
#include "WeaponBinding.h"
#include "kenshi/GameSaveState.h"
#include "kenshi/Gear.h"
#include "kenshi/Inventory.h"

namespace KenshiLua
{

static Item* getInstance(lua_State* L, int idx)
{
    return checkObject<Item>(L, idx, ItemBinding::getMetatableName());
}

// --- Getters for Item ---
static int Item_get_physicalShouldExist(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    lua_pushboolean(L, instance->physicalShouldExist ? 1 : 0);
    return 1;
}

static int Item_get_existAsBareWeapon(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    lua_pushboolean(L, instance->existAsBareWeapon ? 1 : 0);
    return 1;
}

static int Item_get_persistant(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    return handBinding::push(L, instance->persistant);
}

static int Item_get_visible(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    lua_pushboolean(L, instance->visible ? 1 : 0);
    return 1;
}

static int Item_get_physical(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    lua_pushlightuserdata(L, (void*)instance->physical);
    return 1;
}

static int Item_get__isPhysical(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    lua_pushboolean(L, instance->_isPhysical ? 1 : 0);
    return 1;
}

static int Item_get_physicalEntity(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    lua_pushlightuserdata(L, (void*)instance->physicalEntity);
    return 1;
}

static int Item_get_creatingPhysical(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    lua_pushboolean(L, instance->creatingPhysical ? 1 : 0);
    return 1;
}

static int Item_get_fixedPhysicalPosition(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    lua_pushboolean(L, instance->fixedPhysicalPosition ? 1 : 0);
    return 1;
}

static int Item_get_useDynamicPhysics(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    lua_pushboolean(L, instance->useDynamicPhysics ? 1 : 0);
    return 1;
}

static int Item_get_loadingEntity(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    lua_pushlightuserdata(L, (void*)instance->loadingEntity);
    return 1;
}

// --- Setters for Item ---
static int Item_set_physicalShouldExist(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    instance->physicalShouldExist = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Item_set_existAsBareWeapon(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    instance->existAsBareWeapon = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Item_set_persistant(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    instance->persistant = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int Item_set_visible(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    instance->visible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Item_set__isPhysical(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    instance->_isPhysical = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Item_set_creatingPhysical(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    instance->creatingPhysical = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Item_set_fixedPhysicalPosition(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    instance->fixedPhysicalPosition = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Item_set_useDynamicPhysics(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    instance->useDynamicPhysics = lua_toboolean(L, 2) != 0;
    return 0;
}

int ItemBinding::isGear(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Gear* result = instance->isGear();
    return pushObject<Gear>(L, result, GearBinding::getMetatableName());
}

int ItemBinding::_NV_isGear(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Gear* result = instance->_NV_isGear();
    return pushObject<Gear>(L, result, GearBinding::getMetatableName());
}

int ItemBinding::getClassType(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    itemType result = instance->getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ItemBinding::_NV_getClassType(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    itemType result = instance->_NV_getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ItemBinding::resetAfterCopy(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    instance->resetAfterCopy();
    return 0;
}

int ItemBinding::_NV_resetAfterCopy(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    instance->_NV_resetAfterCopy();
    return 0;
}

int ItemBinding::deactivate(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    instance->deactivate();
    return 0;
}

int ItemBinding::_NV_deactivate(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    instance->_NV_deactivate();
    return 0;
}

int ItemBinding::setPositionRotation(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    Ogre::Quaternion rotation;
    readQuaternion(L, 3, rotation);
    bool fixedPosition = lua_toboolean(L, 4) != 0;
    instance->setPositionRotation(position, rotation, fixedPosition);
    return 0;
}

int ItemBinding::_NV_setPositionRotation(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    Ogre::Quaternion rotation;
    readQuaternion(L, 3, rotation);
    bool fixedPosition = lua_toboolean(L, 4) != 0;
    instance->_NV_setPositionRotation(position, rotation, fixedPosition);
    return 0;
}

int ItemBinding::isCrossbow(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Crossbow* result = instance->isCrossbow();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int ItemBinding::_NV_isCrossbow(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Crossbow* result = instance->_NV_isCrossbow();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int ItemBinding::isArmour(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Armour* result = instance->isArmour();
    return pushObject<Armour>(L, result, ArmourBinding::getMetatableName());
}

int ItemBinding::_NV_isArmour(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Armour* result = instance->_NV_isArmour();
    return pushObject<Armour>(L, result, ArmourBinding::getMetatableName());
}

int ItemBinding::isWeapon(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Weapon* result = instance->isWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int ItemBinding::_NV_isWeapon(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Weapon* result = instance->_NV_isWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int ItemBinding::isLockedArmour(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    LockedArmour* result = instance->isLockedArmour();
    return pushObject<LockedArmour>(L, result, LockedArmourBinding::getMetatableName());
}

int ItemBinding::_NV_isLockedArmour(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    LockedArmour* result = instance->_NV_isLockedArmour();
    return pushObject<LockedArmour>(L, result, LockedArmourBinding::getMetatableName());
}

int ItemBinding::isAFactionUniform(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Faction* result = instance->isAFactionUniform();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int ItemBinding::_NV_isAFactionUniform(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Faction* result = instance->_NV_isAFactionUniform();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int ItemBinding::isPhysical(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    bool result = instance->isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::_NV_isPhysical(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    bool result = instance->_NV_isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::setVisible(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setVisible(on);
    return 0;
}

int ItemBinding::_NV_setVisible(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(on);
    return 0;
}

int ItemBinding::getVisible(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::_NV_getVisible(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    bool result = instance->_NV_getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::getModelName(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    std::string result = instance->getModelName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int ItemBinding::_NV_getModelName(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    std::string result = instance->_NV_getModelName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int ItemBinding::getInventory(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Inventory* result = instance->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int ItemBinding::_NV_getInventory(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Inventory* result = instance->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int ItemBinding::hasIngredients(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    bool result = instance->hasIngredients();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::_NV_hasIngredients(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    bool result = instance->_NV_hasIngredients();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::isGoodFood(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    bool result = instance->isGoodFood();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::_NV_isGoodFood(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    bool result = instance->_NV_isGoodFood();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::getEntity(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Ogre::Entity* result = instance->getEntity();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ItemBinding::_NV_getEntity(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    Ogre::Entity* result = instance->_NV_getEntity();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ItemBinding::getTimeout(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    TimeOfDay result = instance->getTimeout();
    return pushObject<TimeOfDay>(L, &result, TimeOfDayBinding::getMetatableName());
}

int ItemBinding::_NV_getTimeout(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    TimeOfDay result = instance->_NV_getTimeout();
    return pushObject<TimeOfDay>(L, &result, TimeOfDayBinding::getMetatableName());
}

int ItemBinding::_serialise(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    GameData* result = instance->_serialise(container, type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int ItemBinding::_NV__serialise(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    GameData* result = instance->_NV__serialise(container, type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int ItemBinding::_loadFromSerialise(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_loadFromSerialise(container, state);
    return 0;
}

int ItemBinding::_NV__loadFromSerialise(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_NV__loadFromSerialise(container, state);
    return 0;
}

int ItemBinding::loadFromSerialise(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    GameSaveState* saveState = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(saveState);
    return 0;
}

int ItemBinding::_NV_loadFromSerialise(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    GameSaveState* saveState = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(saveState);
    return 0;
}

int ItemBinding::serialiseInInventory(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* result = instance->serialiseInInventory(container, refList);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int ItemBinding::_NV_serialiseInInventory(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* result = instance->_NV_serialiseInInventory(container, refList);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int ItemBinding::loadFromSerialiseInInventory(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->loadFromSerialiseInInventory(container, state);
    return 0;
}

int ItemBinding::_NV_loadFromSerialiseInInventory(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_NV_loadFromSerialiseInInventory(container, state);
    return 0;
}

int ItemBinding::getCraftTime(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    float result = instance->getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int ItemBinding::_NV_getCraftTime(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    float result = instance->_NV_getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int ItemBinding::getCraftMaterialMult(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    float result = instance->getCraftMaterialMult();
    lua_pushnumber(L, result);
    return 1;
}

int ItemBinding::_NV_getCraftMaterialMult(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    float result = instance->_NV_getCraftMaterialMult();
    lua_pushnumber(L, result);
    return 1;
}

int ItemBinding::getLevel(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    int result = instance->getLevel();
    lua_pushinteger(L, result);
    return 1;
}

int ItemBinding::_NV_getLevel(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    int result = instance->_NV_getLevel();
    lua_pushinteger(L, result);
    return 1;
}

int ItemBinding::destroyItemEntityCallback_Equipping(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    instance->destroyItemEntityCallback_Equipping();
    return 0;
}

int ItemBinding::_NV_destroyItemEntityCallback_Equipping(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    instance->_NV_destroyItemEntityCallback_Equipping();
    return 0;
}

int ItemBinding::isPersistant(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    bool result = instance->isPersistant();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::persistantOwnerExists(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    bool result = instance->persistantOwnerExists();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::_CONSTRUCTOR(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    GameData* baseData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* companyData = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* _materialData = checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
    hand _handle = *checkObject<hand>(L, 5, handBinding::getMetatableName());
    Item* result = instance->_CONSTRUCTOR(baseData, companyData, _materialData, _handle);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int ItemBinding::_DESTRUCTOR(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ItemBinding::createPhysical(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    bool result = instance->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::_NV_createPhysical(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    bool result = instance->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::destroyPhysical(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    instance->destroyPhysical();
    return 0;
}

int ItemBinding::_NV_destroyPhysical(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    instance->_NV_destroyPhysical();
    return 0;
}

int ItemBinding::loadUnloadCheck(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    instance->loadUnloadCheck();
    return 0;
}

int ItemBinding::_NV_loadUnloadCheck(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");

    instance->_NV_loadUnloadCheck();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 112: bool isFood(...) - static method
  line 119: void activate(...) - overloaded method
  line 120: void _NV_activate(...) - overloaded method
  line 121: void activate(...) - overloaded method
  line 122: void _NV_activate(...) - overloaded method
  line 159: GameSaveState serialise(...) - unsupported arg type
  line 160: GameSaveState _NV_serialise(...) - unsupported arg type
  line 174: void createItemEntityCallback_Equipping(...) - unsupported arg type
  line 175: void _NV_createItemEntityCallback_Equipping(...) - unsupported arg type
  line 178: void notifyTheftFrom(...) - overloaded method
  line 179: void _NV_notifyTheftFrom(...) - overloaded method
  line 180: void notifyTheftFrom(...) - overloaded method
  line 181: void _NV_notifyTheftFrom(...) - overloaded method
  line 182: const hand& findProperOwner(...) - static method
  line 183: const hand& findProperOwner(...) - static method
  line 184: void setInventoryWeAreIn(...) - non-string reference arg
  line 185: void _NV_setInventoryWeAreIn(...) - non-string reference arg
  line 186: const hand& getInventoryWeAreIn(...) - reference return type
  line 188: void setPersistant(...) - overloaded method
  line 189: void setPersistant(...) - overloaded method
  line 202: void createItemEntityCallback(...) - unsupported arg type
  line 203: void itemEntityCreated(...) - unsupported arg type
  line 204: void _NV_itemEntityCreated(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - Item_get_physical: SimplePhysXEntity* (unbound pointer)
  - Item_get_physicalEntity: Ogre::Entity* (unbound pointer)
  - Item_get_loadingEntity: Ogre::Entity* (unbound pointer)
  - ItemBinding::getEntity: Ogre::Entity* (unbound pointer)
  - ItemBinding::_NV_getEntity: Ogre::Entity* (unbound pointer)
*/

int ItemBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Item object");
    return 1;
}



static int Item_set_loadingEntity(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    instance->loadingEntity = (Ogre::Entity*)lua_touserdata(L, 2);
    return 0;
}


static int Item_set_physical(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    instance->physical = (SimplePhysXEntity*)lua_touserdata(L, 2);
    return 0;
}


static int Item_set_physicalEntity(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    instance->physicalEntity = (Ogre::Entity*)lua_touserdata(L, 2);
    return 0;
}


int ItemBinding::_NV_activate(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    int numArgs = lua_gettop(L);
    if (numArgs <= 3) {
        bool createPhysical = lua_toboolean(L, 2) != 0;
        YesNoMaybe bareWeapon = (YesNoMaybe)(int)luaL_checkinteger(L, 3);
        instance->_NV_activate(createPhysical, bareWeapon);
    } else {
        bool createPhysical = lua_toboolean(L, 2) != 0;
        Ogre::Vector3 position;
        readVector3(L, 3, position);
        Ogre::Quaternion rotation;
        readQuaternion(L, 4, rotation);
        bool fixedPosition = lua_toboolean(L, 5) != 0;
        YesNoMaybe bareWeapon = (YesNoMaybe)(int)luaL_checkinteger(L, 6);
        bool dynamicPhysics = lua_toboolean(L, 7) != 0;
        instance->_NV_activate(createPhysical, position, rotation, fixedPosition, bareWeapon, dynamicPhysics);
    }
    return 0;
}


int ItemBinding::_NV_createItemEntityCallback_Equipping(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    Ogre::Entity* ent = (Ogre::Entity*)lua_touserdata(L, 2);
    Ogre::SceneNode* node = (Ogre::SceneNode*)lua_touserdata(L, 3);
    instance->_NV_createItemEntityCallback_Equipping(ent, node);
    return 0;
}


int ItemBinding::_NV_itemEntityCreated(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    Ogre::Entity* ent = (Ogre::Entity*)lua_touserdata(L, 2);
    instance->_NV_itemEntityCreated(ent);
    return 0;
}


int ItemBinding::_NV_notifyTheftFrom(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    if (testObject<hand>(L, 2, handBinding::getMetatableName()) != nullptr)
    {
        hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
        instance->_NV_notifyTheftFrom(*h);
        return 0;
    }
    else
    {
        RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
        instance->_NV_notifyTheftFrom(obj);
        return 0;
    }
}


int ItemBinding::_NV_serialise(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    GameDataContainer* c = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* r = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offset = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState res = instance->_NV_serialise(c, r, offset);
    return pushObject<GameSaveState>(L, new GameSaveState(res), GameSaveStateBinding::getMetatableName());
}


int ItemBinding::_NV_setInventoryWeAreIn(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->_NV_setInventoryWeAreIn(*h);
    return 0;
}


int ItemBinding::activate(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    int numArgs = lua_gettop(L);
    if (numArgs <= 3) {
        bool createPhysical = lua_toboolean(L, 2) != 0;
        YesNoMaybe bareWeapon = (YesNoMaybe)(int)luaL_checkinteger(L, 3);
        instance->activate(createPhysical, bareWeapon);
    } else {
        bool createPhysical = lua_toboolean(L, 2) != 0;
        Ogre::Vector3 position;
        readVector3(L, 3, position);
        Ogre::Quaternion rotation;
        readQuaternion(L, 4, rotation);
        bool fixedPosition = lua_toboolean(L, 5) != 0;
        YesNoMaybe bareWeapon = (YesNoMaybe)(int)luaL_checkinteger(L, 6);
        bool dynamicPhysics = lua_toboolean(L, 7) != 0;
        instance->activate(createPhysical, position, rotation, fixedPosition, bareWeapon, dynamicPhysics);
    }
    return 0;
}


int ItemBinding::createItemEntityCallback_Equipping(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    Ogre::Entity* ent = (Ogre::Entity*)lua_touserdata(L, 2);
    Ogre::SceneNode* node = (Ogre::SceneNode*)lua_touserdata(L, 3);
    instance->createItemEntityCallback_Equipping(ent, node);
    return 0;
}


int ItemBinding::findProperOwner(lua_State* L)
{
    if (testObject<hand>(L, 1, handBinding::getMetatableName()) != nullptr)
    {
        hand* h = checkObject<hand>(L, 1, handBinding::getMetatableName());
        hand res = Item::findProperOwner(*h);
        return pushObject<hand>(L, new hand(res), handBinding::getMetatableName());
    }
    else
    {
        RootObject* obj = checkObject<RootObject>(L, 1, RootObjectBinding::getMetatableName());
        hand res = Item::findProperOwner(obj);
        return pushObject<hand>(L, new hand(res), handBinding::getMetatableName());
    }
}


int ItemBinding::getInventoryWeAreIn(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    const hand& result = instance->getInventoryWeAreIn();
    handBinding::push(L, result);
    return 1;
}


int ItemBinding::isFood(lua_State* L)
{
    GameData* gd = checkObject<GameData>(L, 1, GameDataBinding::getMetatableName());
    bool res = Item::isFood(gd);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


int ItemBinding::itemEntityCreated(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    Ogre::Entity* ent = (Ogre::Entity*)lua_touserdata(L, 2);
    instance->itemEntityCreated(ent);
    return 0;
}


int ItemBinding::notifyTheftFrom(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    if (testObject<hand>(L, 2, handBinding::getMetatableName()) != nullptr)
    {
        hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
        instance->notifyTheftFrom(*h);
        return 0;
    }
    else
    {
        RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
        instance->notifyTheftFrom(obj);
        return 0;
    }
}


int ItemBinding::serialise(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    GameDataContainer* c = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* r = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offset = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState res = instance->serialise(c, r, offset);
    return pushObject<GameSaveState>(L, new GameSaveState(res), GameSaveStateBinding::getMetatableName());
}


int ItemBinding::setInventoryWeAreIn(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->setInventoryWeAreIn(*h);
    return 0;
}


int ItemBinding::setPersistant(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    if (testObject<hand>(L, 2, handBinding::getMetatableName()) != nullptr)
    {
        hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
        instance->setPersistant(*h);
    }
    else
    {
        bool p = lua_toboolean(L, 2) != 0;
        instance->setPersistant(p);
    }
    return 0;
}


void ItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ItemBinding::gc },
        { "__tostring", ItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isGear", ItemBinding::isGear },
        { "_NV_isGear", ItemBinding::_NV_isGear },
        { "getClassType", ItemBinding::getClassType },
        { "_NV_getClassType", ItemBinding::_NV_getClassType },
        { "resetAfterCopy", ItemBinding::resetAfterCopy },
        { "_NV_resetAfterCopy", ItemBinding::_NV_resetAfterCopy },
        { "deactivate", ItemBinding::deactivate },
        { "_NV_deactivate", ItemBinding::_NV_deactivate },
        { "setPositionRotation", ItemBinding::setPositionRotation },
        { "_NV_setPositionRotation", ItemBinding::_NV_setPositionRotation },
        { "isCrossbow", ItemBinding::isCrossbow },
        { "_NV_isCrossbow", ItemBinding::_NV_isCrossbow },
        { "isArmour", ItemBinding::isArmour },
        { "_NV_isArmour", ItemBinding::_NV_isArmour },
        { "isWeapon", ItemBinding::isWeapon },
        { "_NV_isWeapon", ItemBinding::_NV_isWeapon },
        { "isLockedArmour", ItemBinding::isLockedArmour },
        { "_NV_isLockedArmour", ItemBinding::_NV_isLockedArmour },
        { "isAFactionUniform", ItemBinding::isAFactionUniform },
        { "_NV_isAFactionUniform", ItemBinding::_NV_isAFactionUniform },
        { "isPhysical", ItemBinding::isPhysical },
        { "_NV_isPhysical", ItemBinding::_NV_isPhysical },
        { "setVisible", ItemBinding::setVisible },
        { "_NV_setVisible", ItemBinding::_NV_setVisible },
        { "getVisible", ItemBinding::getVisible },
        { "_NV_getVisible", ItemBinding::_NV_getVisible },
        { "getModelName", ItemBinding::getModelName },
        { "_NV_getModelName", ItemBinding::_NV_getModelName },
        { "getInventory", ItemBinding::getInventory },
        { "_NV_getInventory", ItemBinding::_NV_getInventory },
        { "hasIngredients", ItemBinding::hasIngredients },
        { "_NV_hasIngredients", ItemBinding::_NV_hasIngredients },
        { "isGoodFood", ItemBinding::isGoodFood },
        { "_NV_isGoodFood", ItemBinding::_NV_isGoodFood },
        { "getEntity", ItemBinding::getEntity },
        { "_NV_getEntity", ItemBinding::_NV_getEntity },
        { "getTimeout", ItemBinding::getTimeout },
        { "_NV_getTimeout", ItemBinding::_NV_getTimeout },
        { "_serialise", ItemBinding::_serialise },
        { "_NV__serialise", ItemBinding::_NV__serialise },
        { "_loadFromSerialise", ItemBinding::_loadFromSerialise },
        { "_NV__loadFromSerialise", ItemBinding::_NV__loadFromSerialise },
        { "loadFromSerialise", ItemBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", ItemBinding::_NV_loadFromSerialise },
        { "serialiseInInventory", ItemBinding::serialiseInInventory },
        { "_NV_serialiseInInventory", ItemBinding::_NV_serialiseInInventory },
        { "loadFromSerialiseInInventory", ItemBinding::loadFromSerialiseInInventory },
        { "_NV_loadFromSerialiseInInventory", ItemBinding::_NV_loadFromSerialiseInInventory },
        { "getCraftTime", ItemBinding::getCraftTime },
        { "_NV_getCraftTime", ItemBinding::_NV_getCraftTime },
        { "getCraftMaterialMult", ItemBinding::getCraftMaterialMult },
        { "_NV_getCraftMaterialMult", ItemBinding::_NV_getCraftMaterialMult },
        { "getLevel", ItemBinding::getLevel },
        { "_NV_getLevel", ItemBinding::_NV_getLevel },
        { "destroyItemEntityCallback_Equipping", ItemBinding::destroyItemEntityCallback_Equipping },
        { "_NV_destroyItemEntityCallback_Equipping", ItemBinding::_NV_destroyItemEntityCallback_Equipping },
        { "isPersistant", ItemBinding::isPersistant },
        { "persistantOwnerExists", ItemBinding::persistantOwnerExists },
        { "_CONSTRUCTOR", ItemBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ItemBinding::_DESTRUCTOR },
        { "createPhysical", ItemBinding::createPhysical },
        { "_NV_createPhysical", ItemBinding::_NV_createPhysical },
        { "destroyPhysical", ItemBinding::destroyPhysical },
        { "_NV_destroyPhysical", ItemBinding::_NV_destroyPhysical },
        { "loadUnloadCheck", ItemBinding::loadUnloadCheck },
        { "_NV_loadUnloadCheck", ItemBinding::_NV_loadUnloadCheck },
                { "getInventoryWeAreIn", ItemBinding::getInventoryWeAreIn },
        { "setInventoryWeAreIn", ItemBinding::setInventoryWeAreIn },
        { "_NV_setInventoryWeAreIn", ItemBinding::_NV_setInventoryWeAreIn },
        { "isFood", ItemBinding::isFood },
        { "activate", ItemBinding::activate },
        { "_NV_activate", ItemBinding::_NV_activate },
        { "serialise", ItemBinding::serialise },
        { "_NV_serialise", ItemBinding::_NV_serialise },
        { "createItemEntityCallback_Equipping", ItemBinding::createItemEntityCallback_Equipping },
        { "_NV_createItemEntityCallback_Equipping", ItemBinding::_NV_createItemEntityCallback_Equipping },
        { "notifyTheftFrom", ItemBinding::notifyTheftFrom },
        { "_NV_notifyTheftFrom", ItemBinding::_NV_notifyTheftFrom },
        { "findProperOwner", ItemBinding::findProperOwner },
        { "setPersistant", ItemBinding::setPersistant },
        { "itemEntityCreated", ItemBinding::itemEntityCreated },
        { "_NV_itemEntityCreated", ItemBinding::_NV_itemEntityCreated },
        { 0, 0 }
    };

    registerClass(
        L, 
        ItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ItemBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "physicalShouldExist", Item_get_physicalShouldExist);
    registerGetter(L, "existAsBareWeapon", Item_get_existAsBareWeapon);
    registerGetter(L, "persistant", Item_get_persistant);
    registerGetter(L, "visible", Item_get_visible);
    registerGetter(L, "physical", Item_get_physical);
    registerGetter(L, "_isPhysical", Item_get__isPhysical);
    registerGetter(L, "physicalEntity", Item_get_physicalEntity);
    registerGetter(L, "creatingPhysical", Item_get_creatingPhysical);
    registerGetter(L, "fixedPhysicalPosition", Item_get_fixedPhysicalPosition);
    registerGetter(L, "useDynamicPhysics", Item_get_useDynamicPhysics);
    registerGetter(L, "loadingEntity", Item_get_loadingEntity);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "physicalShouldExist", Item_set_physicalShouldExist);
    registerSetter(L, "existAsBareWeapon", Item_set_existAsBareWeapon);
    registerSetter(L, "persistant", Item_set_persistant);
    registerSetter(L, "visible", Item_set_visible);
    registerSetter(L, "_isPhysical", Item_set__isPhysical);
    registerSetter(L, "creatingPhysical", Item_set_creatingPhysical);
    registerSetter(L, "fixedPhysicalPosition", Item_set_fixedPhysicalPosition);
    registerSetter(L, "useDynamicPhysics", Item_set_useDynamicPhysics);
    registerSetter(L, "loadingEntity", Item_set_loadingEntity);
    registerSetter(L, "physicalEntity", Item_set_physicalEntity);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to InventoryItemBase
    setMetatableParent(L, ItemBinding::getMetatableName(), InventoryItemBaseBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua