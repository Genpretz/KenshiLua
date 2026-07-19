#include "pch.h"
#include "kenshi\Item.h"
#include "ItemBinding.h"
#include "kenshi/Gear.h"
#include "GearBinding.h"
#include "CrossbowBinding.h"
#include "ArmourBinding.h"
#include "WeaponBinding.h"
#include "LockedArmourBinding.h"
#include "kenshi/Inventory.h"
#include "InventoryBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ArmourBinding.h"
#include "Bindings/CrossbowBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GearBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/LockedArmourBinding.h"
#include "Bindings/WeaponBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "kenshi/GameSaveState.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Templates/LektorBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"

namespace KenshiLua
{

static Item* getB(lua_State* L, int idx)
{
    return checkObject<Item>(L, idx, ItemBinding::getMetatableName());
}

// --- Getters for Item ---
static int Item_get_physicalShouldExist(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    lua_pushboolean(L, b->physicalShouldExist ? 1 : 0);
    return 1;
}

static int Item_get_existAsBareWeapon(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    lua_pushboolean(L, b->existAsBareWeapon ? 1 : 0);
    return 1;
}

static int Item_get_persistant(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    return handBinding::push(L, b->persistant);
}

static int Item_get_visible(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    lua_pushboolean(L, b->visible ? 1 : 0);
    return 1;
}

static int Item_get_physical(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    lua_pushlightuserdata(L, (void*)b->physical);
    return 1;
}

static int Item_get__isPhysical(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    lua_pushboolean(L, b->_isPhysical ? 1 : 0);
    return 1;
}

static int Item_get_physicalEntity(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    lua_pushlightuserdata(L, (void*)b->physicalEntity);
    return 1;
}

static int Item_get_creatingPhysical(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    lua_pushboolean(L, b->creatingPhysical ? 1 : 0);
    return 1;
}

static int Item_get_fixedPhysicalPosition(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    lua_pushboolean(L, b->fixedPhysicalPosition ? 1 : 0);
    return 1;
}

static int Item_get_useDynamicPhysics(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    lua_pushboolean(L, b->useDynamicPhysics ? 1 : 0);
    return 1;
}

static int Item_get_loadingEntity(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    lua_pushlightuserdata(L, (void*)b->loadingEntity);
    return 1;
}

// --- Setters for Item ---
static int Item_set_physicalShouldExist(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    b->physicalShouldExist = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Item_set_existAsBareWeapon(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    b->existAsBareWeapon = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Item_set_persistant(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->persistant = *val;
    return 0;
}

static int Item_set_visible(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    b->visible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Item_set_physical(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    b->physical = (SimplePhysXEntity*)lua_touserdata(L, 2);
    return 0;
}

static int Item_set__isPhysical(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    b->_isPhysical = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Item_set_physicalEntity(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    b->physicalEntity = (Ogre::Entity*)lua_touserdata(L, 2);
    return 0;
}

static int Item_set_creatingPhysical(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    b->creatingPhysical = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Item_set_fixedPhysicalPosition(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    b->fixedPhysicalPosition = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Item_set_useDynamicPhysics(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    b->useDynamicPhysics = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Item_set_loadingEntity(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    b->loadingEntity = (Ogre::Entity*)lua_touserdata(L, 2);
    return 0;
}

int ItemBinding::isGear(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    Gear* result = b->isGear();
    return pushObject<Gear>(L, result, GearBinding::getMetatableName());
}

int ItemBinding::_NV_isGear(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    Gear* result = b->_NV_isGear();
    return pushObject<Gear>(L, result, GearBinding::getMetatableName());
}

int ItemBinding::getClassType(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    itemType result = b->getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ItemBinding::_NV_getClassType(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    itemType result = b->_NV_getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ItemBinding::resetAfterCopy(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    b->resetAfterCopy();
    return 0;
}

int ItemBinding::_NV_resetAfterCopy(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    b->_NV_resetAfterCopy();
    return 0;
}

int ItemBinding::deactivate(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    b->deactivate();
    return 0;
}

int ItemBinding::_NV_deactivate(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    b->_NV_deactivate();
    return 0;
}

int ItemBinding::setPositionRotation(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    Ogre::Quaternion rotation;
    readQuaternion(L, 3, rotation);
    bool fixedPosition = lua_toboolean(L, 4) != 0;
    b->setPositionRotation(position, rotation, fixedPosition);
    return 0;
}

int ItemBinding::_NV_setPositionRotation(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    Ogre::Quaternion rotation;
    readQuaternion(L, 3, rotation);
    bool fixedPosition = lua_toboolean(L, 4) != 0;
    b->_NV_setPositionRotation(position, rotation, fixedPosition);
    return 0;
}

int ItemBinding::isCrossbow(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    Crossbow* result = b->isCrossbow();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int ItemBinding::_NV_isCrossbow(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    Crossbow* result = b->_NV_isCrossbow();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int ItemBinding::isArmour(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    Armour* result = b->isArmour();
    return pushObject<Armour>(L, result, ArmourBinding::getMetatableName());
}

int ItemBinding::_NV_isArmour(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    Armour* result = b->_NV_isArmour();
    return pushObject<Armour>(L, result, ArmourBinding::getMetatableName());
}

int ItemBinding::isWeapon(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    Weapon* result = b->isWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int ItemBinding::_NV_isWeapon(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    Weapon* result = b->_NV_isWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int ItemBinding::isLockedArmour(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    LockedArmour* result = b->isLockedArmour();
    return pushObject<LockedArmour>(L, result, LockedArmourBinding::getMetatableName());
}

int ItemBinding::_NV_isLockedArmour(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    LockedArmour* result = b->_NV_isLockedArmour();
    return pushObject<LockedArmour>(L, result, LockedArmourBinding::getMetatableName());
}

int ItemBinding::isAFactionUniform(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    Faction* result = b->isAFactionUniform();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int ItemBinding::_NV_isAFactionUniform(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    Faction* result = b->_NV_isAFactionUniform();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int ItemBinding::isPhysical(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    bool result = b->isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::_NV_isPhysical(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    bool result = b->_NV_isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::setVisible(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->setVisible(on);
    return 0;
}

int ItemBinding::_NV_setVisible(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->_NV_setVisible(on);
    return 0;
}

int ItemBinding::getVisible(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    bool result = b->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::_NV_getVisible(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    bool result = b->_NV_getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::getModelName(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    std::string result = b->getModelName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int ItemBinding::_NV_getModelName(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    std::string result = b->_NV_getModelName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int ItemBinding::getInventory(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    Inventory* result = b->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int ItemBinding::_NV_getInventory(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    Inventory* result = b->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int ItemBinding::hasIngredients(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    bool result = b->hasIngredients();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::_NV_hasIngredients(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    bool result = b->_NV_hasIngredients();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::isGoodFood(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    bool result = b->isGoodFood();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::_NV_isGoodFood(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    bool result = b->_NV_isGoodFood();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::getCraftTime(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    float result = b->getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int ItemBinding::_NV_getCraftTime(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    float result = b->_NV_getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int ItemBinding::getCraftMaterialMult(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    float result = b->getCraftMaterialMult();
    lua_pushnumber(L, result);
    return 1;
}

int ItemBinding::_NV_getCraftMaterialMult(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    float result = b->_NV_getCraftMaterialMult();
    lua_pushnumber(L, result);
    return 1;
}

int ItemBinding::getLevel(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    int result = b->getLevel();
    lua_pushinteger(L, result);
    return 1;
}

int ItemBinding::_NV_getLevel(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    int result = b->_NV_getLevel();
    lua_pushinteger(L, result);
    return 1;
}

int ItemBinding::destroyItemEntityCallback_Equipping(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    b->destroyItemEntityCallback_Equipping();
    return 0;
}

int ItemBinding::_NV_destroyItemEntityCallback_Equipping(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    b->_NV_destroyItemEntityCallback_Equipping();
    return 0;
}

int ItemBinding::isPersistant(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    bool result = b->isPersistant();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::persistantOwnerExists(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    bool result = b->persistantOwnerExists();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::_DESTRUCTOR(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    b->_DESTRUCTOR();
    return 0;
}

int ItemBinding::createPhysical(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    bool result = b->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::_NV_createPhysical(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    bool result = b->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ItemBinding::destroyPhysical(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    b->destroyPhysical();
    return 0;
}

int ItemBinding::_NV_destroyPhysical(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    b->_NV_destroyPhysical();
    return 0;
}

int ItemBinding::loadUnloadCheck(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    b->loadUnloadCheck();
    return 0;
}

int ItemBinding::_NV_loadUnloadCheck(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");

    b->_NV_loadUnloadCheck();
    return 0;
}


int ItemBinding::getInventoryWeAreIn(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    const hand& result = b->getInventoryWeAreIn();
    handBinding::push(L, result);
    return 1;
}

int ItemBinding::setInventoryWeAreIn(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->setInventoryWeAreIn(*h);
    return 0;
}

int ItemBinding::_NV_setInventoryWeAreIn(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->_NV_setInventoryWeAreIn(*h);
    return 0;
}

int ItemBinding::isFood(lua_State* L)
{
    GameData* gd = checkObject<GameData>(L, 1, GameDataBinding::getMetatableName());
    bool res = Item::isFood(gd);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int ItemBinding::activate(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    int numArgs = lua_gettop(L);
    if (numArgs <= 3) {
        bool createPhysical = lua_toboolean(L, 2) != 0;
        YesNoMaybe bareWeapon = (YesNoMaybe)luaL_checkinteger(L, 3);
        b->activate(createPhysical, bareWeapon);
    } else {
        bool createPhysical = lua_toboolean(L, 2) != 0;
        Ogre::Vector3 position;
        readVector3(L, 3, position);
        Ogre::Quaternion rotation;
        readQuaternion(L, 4, rotation);
        bool fixedPosition = lua_toboolean(L, 5) != 0;
        YesNoMaybe bareWeapon = (YesNoMaybe)luaL_checkinteger(L, 6);
        bool dynamicPhysics = lua_toboolean(L, 7) != 0;
        b->activate(createPhysical, position, rotation, fixedPosition, bareWeapon, dynamicPhysics);
    }
    return 0;
}

int ItemBinding::_NV_activate(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    int numArgs = lua_gettop(L);
    if (numArgs <= 3) {
        bool createPhysical = lua_toboolean(L, 2) != 0;
        YesNoMaybe bareWeapon = (YesNoMaybe)luaL_checkinteger(L, 3);
        b->_NV_activate(createPhysical, bareWeapon);
    } else {
        bool createPhysical = lua_toboolean(L, 2) != 0;
        Ogre::Vector3 position;
        readVector3(L, 3, position);
        Ogre::Quaternion rotation;
        readQuaternion(L, 4, rotation);
        bool fixedPosition = lua_toboolean(L, 5) != 0;
        YesNoMaybe bareWeapon = (YesNoMaybe)luaL_checkinteger(L, 6);
        bool dynamicPhysics = lua_toboolean(L, 7) != 0;
        b->_NV_activate(createPhysical, position, rotation, fixedPosition, bareWeapon, dynamicPhysics);
    }
    return 0;
}

int ItemBinding::getEntity(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    lua_pushlightuserdata(L, (void*)b->getEntity());
    return 1;
}

int ItemBinding::_NV_getEntity(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    lua_pushlightuserdata(L, (void*)b->_NV_getEntity());
    return 1;
}

int ItemBinding::getTimeout(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    TimeOfDay res = b->getTimeout();
    return pushObject<TimeOfDay>(L, new TimeOfDay(res), TimeOfDayBinding::getMetatableName());
}

int ItemBinding::_NV_getTimeout(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    TimeOfDay res = b->_NV_getTimeout();
    return pushObject<TimeOfDay>(L, new TimeOfDay(res), TimeOfDayBinding::getMetatableName());
}

int ItemBinding::_serialise(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    GameDataContainer* c = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    GameData* res = b->_serialise(c, type);
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}

int ItemBinding::_NV__serialise(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    GameDataContainer* c = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    GameData* res = b->_NV__serialise(c, type);
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}

int ItemBinding::_loadFromSerialise(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    b->_loadFromSerialise(container, state);
    return 0;
}

int ItemBinding::_NV__loadFromSerialise(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    b->_NV__loadFromSerialise(container, state);
    return 0;
}

int ItemBinding::serialise(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    GameDataContainer* c = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* r = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offset = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState res = b->serialise(c, r, offset);
    return pushObject<GameSaveState>(L, new GameSaveState(res), GameSaveStateBinding::getMetatableName());
}

int ItemBinding::_NV_serialise(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    GameDataContainer* c = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* r = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offset = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState res = b->_NV_serialise(c, r, offset);
    return pushObject<GameSaveState>(L, new GameSaveState(res), GameSaveStateBinding::getMetatableName());
}

int ItemBinding::loadFromSerialise(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    b->loadFromSerialise(state);
    return 0;
}

int ItemBinding::_NV_loadFromSerialise(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    b->_NV_loadFromSerialise(state);
    return 0;
}

int ItemBinding::serialiseInInventory(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    GameDataContainer* c = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* r = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* res = b->serialiseInInventory(c, r);
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}

int ItemBinding::_NV_serialiseInInventory(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    GameDataContainer* c = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* r = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* res = b->_NV_serialiseInInventory(c, r);
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}

int ItemBinding::loadFromSerialiseInInventory(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    b->loadFromSerialiseInInventory(container, state);
    return 0;
}

int ItemBinding::_NV_loadFromSerialiseInInventory(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    b->_NV_loadFromSerialiseInInventory(container, state);
    return 0;
}

int ItemBinding::createItemEntityCallback_Equipping(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    Ogre::Entity* ent = (Ogre::Entity*)lua_touserdata(L, 2);
    Ogre::SceneNode* node = (Ogre::SceneNode*)lua_touserdata(L, 3);
    b->createItemEntityCallback_Equipping(ent, node);
    return 0;
}

int ItemBinding::_NV_createItemEntityCallback_Equipping(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    Ogre::Entity* ent = (Ogre::Entity*)lua_touserdata(L, 2);
    Ogre::SceneNode* node = (Ogre::SceneNode*)lua_touserdata(L, 3);
    b->_NV_createItemEntityCallback_Equipping(ent, node);
    return 0;
}

int ItemBinding::notifyTheftFrom(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    if (testObject<hand>(L, 2, handBinding::getMetatableName()) != nullptr)
    {
        hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
        b->notifyTheftFrom(*h);
        return 0;
    }
    else
    {
        RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
        b->notifyTheftFrom(obj);
        return 0;
    }
}

int ItemBinding::_NV_notifyTheftFrom(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    if (testObject<hand>(L, 2, handBinding::getMetatableName()) != nullptr)
    {
        hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
        b->_NV_notifyTheftFrom(*h);
        return 0;
    }
    else
    {
        RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
        b->_NV_notifyTheftFrom(obj);
        return 0;
    }
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

int ItemBinding::setPersistant(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    if (testObject<hand>(L, 2, handBinding::getMetatableName()) != nullptr)
    {
        hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
        b->setPersistant(*h);
    }
    else
    {
        bool p = lua_toboolean(L, 2) != 0;
        b->setPersistant(p);
    }
    return 0;
}

int ItemBinding::_CONSTRUCTOR(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    GameData* baseData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* companyData = lua_isnoneornil(L, 3) ? nullptr : checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* materialData = lua_isnoneornil(L, 4) ? nullptr : checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
    hand* _handle = checkObject<hand>(L, 5, handBinding::getMetatableName());
    Item* res = b->_CONSTRUCTOR(baseData, companyData, materialData, *_handle);
    return pushObject<Item>(L, res, ItemBinding::getMetatableName());
}

int ItemBinding::itemEntityCreated(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    Ogre::Entity* ent = (Ogre::Entity*)lua_touserdata(L, 2);
    b->itemEntityCreated(ent);
    return 0;
}

int ItemBinding::_NV_itemEntityCreated(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    Ogre::Entity* ent = (Ogre::Entity*)lua_touserdata(L, 2);
    b->_NV_itemEntityCreated(ent);
    return 0;
}

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
        { "getEntity", ItemBinding::getEntity },
        { "_NV_getEntity", ItemBinding::_NV_getEntity },
        { "getTimeout", ItemBinding::getTimeout },
        { "_NV_getTimeout", ItemBinding::_NV_getTimeout },
        { "_serialise", ItemBinding::_serialise },
        { "_NV__serialise", ItemBinding::_NV__serialise },
        { "_loadFromSerialise", ItemBinding::_loadFromSerialise },
        { "_NV__loadFromSerialise", ItemBinding::_NV__loadFromSerialise },
        { "serialise", ItemBinding::serialise },
        { "_NV_serialise", ItemBinding::_NV_serialise },
        { "loadFromSerialise", ItemBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", ItemBinding::_NV_loadFromSerialise },
        { "serialiseInInventory", ItemBinding::serialiseInInventory },
        { "_NV_serialiseInInventory", ItemBinding::_NV_serialiseInInventory },
        { "loadFromSerialiseInInventory", ItemBinding::loadFromSerialiseInInventory },
        { "_NV_loadFromSerialiseInInventory", ItemBinding::_NV_loadFromSerialiseInInventory },
        { "createItemEntityCallback_Equipping", ItemBinding::createItemEntityCallback_Equipping },
        { "_NV_createItemEntityCallback_Equipping", ItemBinding::_NV_createItemEntityCallback_Equipping },
        { "notifyTheftFrom", ItemBinding::notifyTheftFrom },
        { "_NV_notifyTheftFrom", ItemBinding::_NV_notifyTheftFrom },
        { "findProperOwner", ItemBinding::findProperOwner },
        { "setPersistant", ItemBinding::setPersistant },
        { "_CONSTRUCTOR", ItemBinding::_CONSTRUCTOR },
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
    lua_pushcfunction(L, Item_get_physicalShouldExist);
    lua_setfield(L, -2, "physicalShouldExist");
    lua_pushcfunction(L, Item_get_existAsBareWeapon);
    lua_setfield(L, -2, "existAsBareWeapon");
    lua_pushcfunction(L, Item_get_persistant);
    lua_setfield(L, -2, "persistant");
    lua_pushcfunction(L, Item_get_visible);
    lua_setfield(L, -2, "visible");
    lua_pushcfunction(L, Item_get_physical);
    lua_setfield(L, -2, "physical");
    lua_pushcfunction(L, Item_get__isPhysical);
    lua_setfield(L, -2, "_isPhysical");
    lua_pushcfunction(L, Item_get_physicalEntity);
    lua_setfield(L, -2, "physicalEntity");
    lua_pushcfunction(L, Item_get_creatingPhysical);
    lua_setfield(L, -2, "creatingPhysical");
    lua_pushcfunction(L, Item_get_fixedPhysicalPosition);
    lua_setfield(L, -2, "fixedPhysicalPosition");
    lua_pushcfunction(L, Item_get_useDynamicPhysics);
    lua_setfield(L, -2, "useDynamicPhysics");
    lua_pushcfunction(L, Item_get_loadingEntity);
    lua_setfield(L, -2, "loadingEntity");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Item_set_physicalShouldExist);
    lua_setfield(L, -2, "physicalShouldExist");
    lua_pushcfunction(L, Item_set_existAsBareWeapon);
    lua_setfield(L, -2, "existAsBareWeapon");
    lua_pushcfunction(L, Item_set_persistant);
    lua_setfield(L, -2, "persistant");
    lua_pushcfunction(L, Item_set_visible);
    lua_setfield(L, -2, "visible");
    lua_pushcfunction(L, Item_set_physical);
    lua_setfield(L, -2, "physical");
    lua_pushcfunction(L, Item_set__isPhysical);
    lua_setfield(L, -2, "_isPhysical");
    lua_pushcfunction(L, Item_set_physicalEntity);
    lua_setfield(L, -2, "physicalEntity");
    lua_pushcfunction(L, Item_set_creatingPhysical);
    lua_setfield(L, -2, "creatingPhysical");
    lua_pushcfunction(L, Item_set_fixedPhysicalPosition);
    lua_setfield(L, -2, "fixedPhysicalPosition");
    lua_pushcfunction(L, Item_set_useDynamicPhysics);
    lua_setfield(L, -2, "useDynamicPhysics");
    lua_pushcfunction(L, Item_set_loadingEntity);
    lua_setfield(L, -2, "loadingEntity");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
