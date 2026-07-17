#include "pch.h"
<<<<<<< HEAD:src/Bindings/Core/RootObjectBinding.cpp
#include "Bindings/Core/RootObjectBinding.h"
#include "Bindings/Character/CharacterBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Equipment/ItemBinding.h"
#include "Bindings/World/TownBinding.h"
=======
#include "kenshi\RootObject.h"
#include "RootObjectBinding.h"
#include "RootObjectContainerBinding.h"
#include "kenshi/Inventory.h"
#include "InventoryBinding.h"
#include "kenshi/RaceData.h"
#include "RaceDataBinding.h"
>>>>>>> main:src/Bindings/RootObjectBinding.cpp
#include "Lua/BindingHelpers.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/RaceDataBinding.h"
#include "Bindings/RootObjectContainerBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "kenshi/InstanceID.h"
#include "kenshi/ZoneManager.h"
#include "kenshi/gui/InventoryGUI.h"
#include "kenshi/Damages.h"
#include "kenshi/CombatTechniqueData.h"
#include "kenshi/Character.h"
#include "Bindings/DamagesBinding.h"
#include "Bindings/CombatTechniqueDataBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Templates/LektorBinding.h"
#include "Bindings/Util/StringPairBinding.h"

namespace KenshiLua
{

static RootObject* getB(lua_State* L, int idx)
{
    return checkObject<RootObject>(L, idx, RootObjectBinding::getMetatableName());
}

// --- Getters for RootObject ---
static int RootObject_get_container(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    return pushObject<RootObjectContainer>(L, b->container, RootObjectContainerBinding::getMetatableName());
}

static int RootObject_get_isInsideBuilding(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    return handBinding::push(L, b->isInsideBuilding);
}

static int RootObject_get_isInsideTownWalls(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    lua_pushinteger(L, b->isInsideTownWalls);
    return 1;
}

static int RootObject_get_floorNum(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    lua_pushinteger(L, b->floorNum);
    return 1;
}

static int RootObject_get_spacialKey(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    lua_pushinteger(L, b->spacialKey);
    return 1;
}

static int RootObject_get_outdoorDelayNotification_timer(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    lua_pushinteger(L, b->outdoorDelayNotification_timer);
    return 1;
}

static int RootObject_get_rot(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    pushQuaternion(L, b->rot);
    return 1;
}

// --- Setters for RootObject ---
static int RootObject_set_container(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    return luaL_error(L, "Read-only or unsupported setter type for container");
}

static int RootObject_set_isInsideBuilding(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->isInsideBuilding = *val;
    return 0;
}

static int RootObject_set_isInsideTownWalls(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    b->isInsideTownWalls = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int RootObject_set_floorNum(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    b->floorNum = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int RootObject_set_spacialKey(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    b->spacialKey = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int RootObject_set_outdoorDelayNotification_timer(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    b->outdoorDelayNotification_timer = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int RootObject_set_rot(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    readQuaternion(L, 2, b->rot);
    return 0;
}

int RootObjectBinding::_DESTRUCTOR(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->_DESTRUCTOR();
    return 0;
}

int RootObjectBinding::needsSaving(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    std::string s = luaL_checkstring(L, 2);
    bool result = b->needsSaving(s);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_needsSaving(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    std::string s = luaL_checkstring(L, 2);
    bool result = b->_NV_needsSaving(s);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::getOrientation(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    Ogre::Quaternion result = b->getOrientation();
    pushQuaternion(L, result);
    return 1;
}

int RootObjectBinding::_NV_getOrientation(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    Ogre::Quaternion result = b->_NV_getOrientation();
    pushQuaternion(L, result);
    return 1;
}

int RootObjectBinding::getRace(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    RaceData* result = b->getRace();
    return pushObject<RaceData>(L, result, RaceDataBinding::getMetatableName());
}

int RootObjectBinding::_NV_getRace(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    RaceData* result = b->_NV_getRace();
    return pushObject<RaceData>(L, result, RaceDataBinding::getMetatableName());
}

int RootObjectBinding::threadedUpdate(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->threadedUpdate();
    return 0;
}

int RootObjectBinding::_NV_threadedUpdate(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->_NV_threadedUpdate();
    return 0;
}

int RootObjectBinding::update(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->update();
    return 0;
}

int RootObjectBinding::_NV_update(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->_NV_update();
    return 0;
}

int RootObjectBinding::periodicUpdate(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->periodicUpdate();
    return 0;
}

int RootObjectBinding::_NV_periodicUpdate(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->_NV_periodicUpdate();
    return 0;
}

int RootObjectBinding::isPhysical(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    bool result = b->isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::setVisible(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    bool _a1 = lua_toboolean(L, 2) != 0;
    b->setVisible(_a1);
    return 0;
}

int RootObjectBinding::getVisible(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    bool result = b->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_getVisible(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    bool result = b->_NV_getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::isDisabled(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    bool result = b->isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_isDisabled(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    bool result = b->_NV_isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::amInsideTownWalls(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    int result = b->amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBinding::_NV_amInsideTownWalls(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    int result = b->_NV_amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBinding::setInsideTownWalls(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    int s = (int)luaL_checkinteger(L, 2);
    b->setInsideTownWalls(s);
    return 0;
}

int RootObjectBinding::_NV_setInsideTownWalls(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    int s = (int)luaL_checkinteger(L, 2);
    b->_NV_setInsideTownWalls(s);
    return 0;
}

int RootObjectBinding::getFloor(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    int result = b->getFloor();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBinding::_NV_getFloor(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    int result = b->_NV_getFloor();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBinding::setFloor(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    int f = (int)luaL_checkinteger(L, 2);
    b->setFloor(f);
    return 0;
}

int RootObjectBinding::_NV_setFloor(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    int f = (int)luaL_checkinteger(L, 2);
    b->_NV_setFloor(f);
    return 0;
}

int RootObjectBinding::select(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->select();
    return 0;
}

int RootObjectBinding::_NV_select(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->_NV_select();
    return 0;
}

int RootObjectBinding::unselect(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->unselect();
    return 0;
}

int RootObjectBinding::_NV_unselect(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->_NV_unselect();
    return 0;
}

int RootObjectBinding::setStandingOrder(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    MessageForB::StandingOrder _a1 = (MessageForB::StandingOrder)luaL_checkinteger(L, 2);
    b->setStandingOrder(_a1);
    return 0;
}

int RootObjectBinding::_NV_setStandingOrder(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    MessageForB::StandingOrder _a1 = (MessageForB::StandingOrder)luaL_checkinteger(L, 2);
    b->_NV_setStandingOrder(_a1);
    return 0;
}

int RootObjectBinding::getInventory(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    Inventory* result = b->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int RootObjectBinding::_NV_getInventory(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    Inventory* result = b->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int RootObjectBinding::takeMoney(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    int _a1 = (int)luaL_checkinteger(L, 2);
    bool result = b->takeMoney(_a1);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_takeMoney(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    int _a1 = (int)luaL_checkinteger(L, 2);
    bool result = b->_NV_takeMoney(_a1);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::getMoney(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    int result = b->getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBinding::_NV_getMoney(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    int result = b->_NV_getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBinding::say(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    std::string _a1 = luaL_checkstring(L, 2);
    b->say(_a1);
    return 0;
}

int RootObjectBinding::_NV_say(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    std::string _a1 = luaL_checkstring(L, 2);
    b->_NV_say(_a1);
    return 0;
}

int RootObjectBinding::notifyOutdoors(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->notifyOutdoors();
    return 0;
}

int RootObjectBinding::_NV_notifyOutdoors(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->_NV_notifyOutdoors();
    return 0;
}

int RootObjectBinding::isOnARoof(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    bool result = b->isOnARoof();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_isOnARoof(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    bool result = b->_NV_isOnARoof();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::getIntendedAggression(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    float result = b->getIntendedAggression();
    lua_pushnumber(L, result);
    return 1;
}

int RootObjectBinding::_NV_getIntendedAggression(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    float result = b->_NV_getIntendedAggression();
    lua_pushnumber(L, result);
    return 1;
}

int RootObjectBinding::createPhysical(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    bool result = b->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::destroyPhysical(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->destroyPhysical();
    return 0;
}

int RootObjectBinding::notifyEffect(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    EffectType::Enum type = (EffectType::Enum)luaL_checkinteger(L, 2);
    WeatherAffecting what = (WeatherAffecting)luaL_checkinteger(L, 3);
    float strength = (float)luaL_checknumber(L, 4);
    b->notifyEffect(type, what, strength);
    return 0;
}

int RootObjectBinding::_NV_notifyEffect(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    EffectType::Enum type = (EffectType::Enum)luaL_checkinteger(L, 2);
    WeatherAffecting what = (WeatherAffecting)luaL_checkinteger(L, 3);
    float strength = (float)luaL_checknumber(L, 4);
    b->_NV_notifyEffect(type, what, strength);
    return 0;
}

int RootObjectBinding::loadUnloadCheck(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->loadUnloadCheck();
    return 0;
}

int RootObjectBinding::_NV_loadUnloadCheck(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");

    b->_NV_loadUnloadCheck();
    return 0;
}



int RootObjectBinding::setFaction(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* a = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        a = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    }
    b->setFaction(f, a);
    return 0;
}

int RootObjectBinding::_NV_setFaction(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* a = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        a = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    }
    b->_NV_setFaction(f, a);
    return 0;
}

int RootObjectBinding::giveItem(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool dropOnFail = lua_toboolean(L, 3) != 0;
    bool destroyOnFail = lua_toboolean(L, 4) != 0;
    bool result = b->giveItem(item, dropOnFail, destroyOnFail);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_giveItem(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool dropOnFail = lua_toboolean(L, 3) != 0;
    bool destroyOnFail = lua_toboolean(L, 4) != 0;
    bool result = b->_NV_giveItem(item, dropOnFail, destroyOnFail);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::hasItem(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = b->hasItem(data);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_hasItem(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = b->_NV_hasItem(data);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::equipItem(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    std::string slotName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    b->equipItem(slotName, item);
    return 0;
}

int RootObjectBinding::_NV_equipItem(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    std::string slotName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    b->_NV_equipItem(slotName, item);
    return 0;
}

int RootObjectBinding::unequipItem(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    std::string slotName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    b->unequipItem(slotName, item);
    return 0;
}

int RootObjectBinding::_NV_unequipItem(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    std::string slotName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    b->_NV_unequipItem(slotName, item);
    return 0;
}

int RootObjectBinding::dropItem(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    RootObject* item = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    b->dropItem(item);
    return 0;
}

int RootObjectBinding::_NV_dropItem(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    RootObject* item = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    b->_NV_dropItem(item);
    return 0;
}

int RootObjectBinding::isIndoors(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    const hand& result = b->isIndoors();
    handBinding::push(L, result);
    return 1;
}

int RootObjectBinding::_NV_isIndoors(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    const hand& result = b->_NV_isIndoors();
    handBinding::push(L, result);
    return 1;
}

int RootObjectBinding::setIsInsideBuilding(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->setIsInsideBuilding(*h);
    return 0;
}

int RootObjectBinding::_NV_setIsInsideBuilding(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->_NV_setIsInsideBuilding(*h);
    return 0;
}

int RootObjectBinding::_CONSTRUCTOR(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Faction* ownr = checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    hand* _h = checkObject<hand>(L, 4, handBinding::getMetatableName());
    RootObject* result = b->_CONSTRUCTOR(d, ownr, *_h);
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int RootObjectBinding::getInstanceID(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    InstanceID* res = b->getInstanceID();
    if (res) {
        lua_pushlightuserdata(L, (void*)res);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

int RootObjectBinding::_NV_getInstanceID(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    InstanceID* res = b->_NV_getInstanceID();
    if (res) {
        lua_pushlightuserdata(L, (void*)res);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

int RootObjectBinding::getLayoutInstanceID(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    const std::string& res = b->getLayoutInstanceID();
    lua_pushstring(L, res.c_str());
    return 1;
}

int RootObjectBinding::_NV_getLayoutInstanceID(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    const std::string& res = b->_NV_getLayoutInstanceID();
    lua_pushstring(L, res.c_str());
    return 1;
}

int RootObjectBinding::getZoneMapLocation(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    ZoneMap* res = b->getZoneMapLocation();
    if (res) {
        lua_pushlightuserdata(L, (void*)res);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

int RootObjectBinding::_NV_getZoneMapLocation(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    ZoneMap* res = b->_NV_getZoneMapLocation();
    if (res) {
        lua_pushlightuserdata(L, (void*)res);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

int RootObjectBinding::getAABB(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    const Ogre::Aabb& res = b->getAABB();
    lua_pushlightuserdata(L, (void*)&res);
    return 1;
}

int RootObjectBinding::_NV_getAABB(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    const Ogre::Aabb& res = b->_NV_getAABB();
    lua_pushlightuserdata(L, (void*)&res);
    return 1;
}

int RootObjectBinding::getGUIData(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    DatapanelGUI* gui = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    b->getGUIData(gui, category);
    return 0;
}

int RootObjectBinding::_NV_getGUIData(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    DatapanelGUI* gui = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    b->_NV_getGUIData(gui, category);
    return 0;
}

int RootObjectBinding::getGUIDataCategories(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    lektor<StringPair>* out = LektorValueBinding<StringPair>::get(L, 2);
    if (!out) return luaL_error(L, "lektor<StringPair> is nil or invalid");
    b->getGUIDataCategories(*out);
    return 0;
}

int RootObjectBinding::_NV_getGUIDataCategories(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    lektor<StringPair>* out = LektorValueBinding<StringPair>::get(L, 2);
    if (!out) return luaL_error(L, "lektor<StringPair> is nil or invalid");
    b->_NV_getGUIDataCategories(*out);
    return 0;
}

int RootObjectBinding::getOrders(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    lektor<std::string>* out = LektorStringBinding<std::string>::get(L, 2);
    if (!out) return luaL_error(L, "lektor<string> is nil or invalid");
    b->getOrders(*out);
    return 0;
}

int RootObjectBinding::_NV_getOrders(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    lektor<std::string>* out = LektorStringBinding<std::string>::get(L, 2);
    if (!out) return luaL_error(L, "lektor<string> is nil or invalid");
    b->_NV_getOrders(*out);
    return 0;
}

int RootObjectBinding::hasRoomForItem(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = b->hasRoomForItem(data);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_hasRoomForItem(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = b->_NV_hasRoomForItem(data);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::createInventoryLayout(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    InventoryLayout* res = b->createInventoryLayout();
    if (res) {
        lua_pushlightuserdata(L, (void*)res);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

int RootObjectBinding::_NV_createInventoryLayout(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    InventoryLayout* res = b->_NV_createInventoryLayout();
    if (res) {
        lua_pushlightuserdata(L, (void*)res);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

int RootObjectBinding::ImStealingDoYouNotice(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    RootObject* thief = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = b->ImStealingDoYouNotice(thief);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_ImStealingDoYouNotice(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    RootObject* thief = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = b->_NV_ImStealingDoYouNotice(thief);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::stolenGoodsDetectionCheck(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    RootObject* thief = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    bool result = b->stolenGoodsDetectionCheck(item, thief);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_stolenGoodsDetectionCheck(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    RootObject* thief = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    bool result = b->_NV_stolenGoodsDetectionCheck(item, thief);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::notifyIndoors(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    hand* in = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->notifyIndoors(*in);
    return 0;
}

int RootObjectBinding::_NV_notifyIndoors(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    hand* in = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->_NV_notifyIndoors(*in);
    return 0;
}

int RootObjectBinding::hitByMeleeAttack(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    CutDirection dir = (CutDirection)luaL_checkinteger(L, 2);
    Damages* damage = checkObject<Damages>(L, 3, DamagesBinding::getMetatableName());
    Character* who = nullptr;
    if (lua_gettop(L) >= 4 && !lua_isnil(L, 4)) {
        who = checkObject<Character>(L, 4, CharacterBinding::getMetatableName());
    }
    CombatTechniqueData* attack = nullptr;
    if (lua_gettop(L) >= 5 && !lua_isnil(L, 5)) {
        attack = checkObject<CombatTechniqueData>(L, 5, CombatTechniqueDataBinding::getMetatableName());
    }
    int comboID = (int)luaL_checkinteger(L, 6);
    HitMaterialType res = b->hitByMeleeAttack(dir, *damage, who, attack, comboID);
    lua_pushinteger(L, (lua_Integer)res);
    return 1;
}

int RootObjectBinding::_NV_hitByMeleeAttack(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    CutDirection dir = (CutDirection)luaL_checkinteger(L, 2);
    Damages* damage = checkObject<Damages>(L, 3, DamagesBinding::getMetatableName());
    Character* who = nullptr;
    if (lua_gettop(L) >= 4 && !lua_isnil(L, 4)) {
        who = checkObject<Character>(L, 4, CharacterBinding::getMetatableName());
    }
    CombatTechniqueData* attack = nullptr;
    if (lua_gettop(L) >= 5 && !lua_isnil(L, 5)) {
        attack = checkObject<CombatTechniqueData>(L, 5, CombatTechniqueDataBinding::getMetatableName());
    }
    int comboID = (int)luaL_checkinteger(L, 6);
    HitMaterialType res = b->_NV_hitByMeleeAttack(dir, *damage, who, attack, comboID);
    lua_pushinteger(L, (lua_Integer)res);
    return 1;
}

int RootObjectBinding::getPlatoonAI(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    PlatoonAI* res = b->getPlatoonAI();
    if (res) {
        lua_pushlightuserdata(L, (void*)res);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

int RootObjectBinding::_NV_getPlatoonAI(lua_State* L)
{
    RootObject* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObject is nil");
    PlatoonAI* res = b->_NV_getPlatoonAI();
    if (res) {
        lua_pushlightuserdata(L, (void*)res);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

int RootObjectBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int RootObjectBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RootObject object");
    return 1;
}

void RootObjectBinding::registerBinding(lua_State* L)
{
    LektorValueBinding<StringPair>::registerBinding(L, "lektor<StringPair>", StringPairBinding::getMetatableName());

    static const luaL_Reg meta[] = {
        { "__gc",       RootObjectBinding::gc },
        { "__tostring", RootObjectBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", RootObjectBinding::_DESTRUCTOR },
        { "needsSaving", RootObjectBinding::needsSaving },
        { "_NV_needsSaving", RootObjectBinding::_NV_needsSaving },
        { "getOrientation", RootObjectBinding::getOrientation },
        { "_NV_getOrientation", RootObjectBinding::_NV_getOrientation },
        { "getRace", RootObjectBinding::getRace },
        { "_NV_getRace", RootObjectBinding::_NV_getRace },
        { "threadedUpdate", RootObjectBinding::threadedUpdate },
        { "_NV_threadedUpdate", RootObjectBinding::_NV_threadedUpdate },
        { "update", RootObjectBinding::update },
        { "_NV_update", RootObjectBinding::_NV_update },
        { "periodicUpdate", RootObjectBinding::periodicUpdate },
        { "_NV_periodicUpdate", RootObjectBinding::_NV_periodicUpdate },
        { "isPhysical", RootObjectBinding::isPhysical },
        { "setVisible", RootObjectBinding::setVisible },
        { "getVisible", RootObjectBinding::getVisible },
        { "_NV_getVisible", RootObjectBinding::_NV_getVisible },
        { "isDisabled", RootObjectBinding::isDisabled },
        { "_NV_isDisabled", RootObjectBinding::_NV_isDisabled },
        { "amInsideTownWalls", RootObjectBinding::amInsideTownWalls },
        { "_NV_amInsideTownWalls", RootObjectBinding::_NV_amInsideTownWalls },
        { "setInsideTownWalls", RootObjectBinding::setInsideTownWalls },
        { "_NV_setInsideTownWalls", RootObjectBinding::_NV_setInsideTownWalls },
        { "getFloor", RootObjectBinding::getFloor },
        { "_NV_getFloor", RootObjectBinding::_NV_getFloor },
        { "setFloor", RootObjectBinding::setFloor },
        { "_NV_setFloor", RootObjectBinding::_NV_setFloor },
        { "select", RootObjectBinding::select },
        { "_NV_select", RootObjectBinding::_NV_select },
        { "unselect", RootObjectBinding::unselect },
        { "_NV_unselect", RootObjectBinding::_NV_unselect },
        { "setStandingOrder", RootObjectBinding::setStandingOrder },
        { "_NV_setStandingOrder", RootObjectBinding::_NV_setStandingOrder },
        { "getInventory", RootObjectBinding::getInventory },
        { "_NV_getInventory", RootObjectBinding::_NV_getInventory },
        { "takeMoney", RootObjectBinding::takeMoney },
        { "_NV_takeMoney", RootObjectBinding::_NV_takeMoney },
        { "getMoney", RootObjectBinding::getMoney },
        { "_NV_getMoney", RootObjectBinding::_NV_getMoney },
        { "say", RootObjectBinding::say },
        { "_NV_say", RootObjectBinding::_NV_say },
        { "notifyOutdoors", RootObjectBinding::notifyOutdoors },
        { "_NV_notifyOutdoors", RootObjectBinding::_NV_notifyOutdoors },
        { "isOnARoof", RootObjectBinding::isOnARoof },
        { "_NV_isOnARoof", RootObjectBinding::_NV_isOnARoof },
        { "getIntendedAggression", RootObjectBinding::getIntendedAggression },
        { "_NV_getIntendedAggression", RootObjectBinding::_NV_getIntendedAggression },
        { "createPhysical", RootObjectBinding::createPhysical },
        { "destroyPhysical", RootObjectBinding::destroyPhysical },
        { "notifyEffect", RootObjectBinding::notifyEffect },
        { "_NV_notifyEffect", RootObjectBinding::_NV_notifyEffect },
        { "loadUnloadCheck", RootObjectBinding::loadUnloadCheck },
        { "_NV_loadUnloadCheck", RootObjectBinding::_NV_loadUnloadCheck },
        { "setFaction", RootObjectBinding::setFaction },
        { "_NV_setFaction", RootObjectBinding::_NV_setFaction },
        { "giveItem", RootObjectBinding::giveItem },
        { "_NV_giveItem", RootObjectBinding::_NV_giveItem },
        { "hasItem", RootObjectBinding::hasItem },
        { "_NV_hasItem", RootObjectBinding::_NV_hasItem },
        { "equipItem", RootObjectBinding::equipItem },
        { "_NV_equipItem", RootObjectBinding::_NV_equipItem },
        { "unequipItem", RootObjectBinding::unequipItem },
        { "_NV_unequipItem", RootObjectBinding::_NV_unequipItem },
        { "dropItem", RootObjectBinding::dropItem },
        { "_NV_dropItem", RootObjectBinding::_NV_dropItem },
        { "isIndoors", RootObjectBinding::isIndoors },
        { "_NV_isIndoors", RootObjectBinding::_NV_isIndoors },
        { "setIsInsideBuilding", RootObjectBinding::setIsInsideBuilding },
        { "_NV_setIsInsideBuilding", RootObjectBinding::_NV_setIsInsideBuilding },
        { "_CONSTRUCTOR", RootObjectBinding::_CONSTRUCTOR },
        { "getInstanceID", RootObjectBinding::getInstanceID },
        { "_NV_getInstanceID", RootObjectBinding::_NV_getInstanceID },
        { "getLayoutInstanceID", RootObjectBinding::getLayoutInstanceID },
        { "_NV_getLayoutInstanceID", RootObjectBinding::_NV_getLayoutInstanceID },
        { "getZoneMapLocation", RootObjectBinding::getZoneMapLocation },
        { "_NV_getZoneMapLocation", RootObjectBinding::_NV_getZoneMapLocation },
        { "getAABB", RootObjectBinding::getAABB },
        { "_NV_getAABB", RootObjectBinding::_NV_getAABB },
        { "getGUIData", RootObjectBinding::getGUIData },
        { "_NV_getGUIData", RootObjectBinding::_NV_getGUIData },
        { "getGUIDataCategories", RootObjectBinding::getGUIDataCategories },
        { "_NV_getGUIDataCategories", RootObjectBinding::_NV_getGUIDataCategories },
        { "getOrders", RootObjectBinding::getOrders },
        { "_NV_getOrders", RootObjectBinding::_NV_getOrders },
        { "hasRoomForItem", RootObjectBinding::hasRoomForItem },
        { "_NV_hasRoomForItem", RootObjectBinding::_NV_hasRoomForItem },
        { "createInventoryLayout", RootObjectBinding::createInventoryLayout },
        { "_NV_createInventoryLayout", RootObjectBinding::_NV_createInventoryLayout },
        { "ImStealingDoYouNotice", RootObjectBinding::ImStealingDoYouNotice },
        { "_NV_ImStealingDoYouNotice", RootObjectBinding::_NV_ImStealingDoYouNotice },
        { "stolenGoodsDetectionCheck", RootObjectBinding::stolenGoodsDetectionCheck },
        { "_NV_stolenGoodsDetectionCheck", RootObjectBinding::_NV_stolenGoodsDetectionCheck },
        { "notifyIndoors", RootObjectBinding::notifyIndoors },
        { "_NV_notifyIndoors", RootObjectBinding::_NV_notifyIndoors },
        { "hitByMeleeAttack", RootObjectBinding::hitByMeleeAttack },
        { "_NV_hitByMeleeAttack", RootObjectBinding::_NV_hitByMeleeAttack },
        { "getPlatoonAI", RootObjectBinding::getPlatoonAI },
        { "_NV_getPlatoonAI", RootObjectBinding::_NV_getPlatoonAI },
        { 0, 0 }
    };

    registerClass(
        L, 
        RootObjectBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RootObjectBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, RootObject_get_container);
    lua_setfield(L, -2, "container");
    lua_pushcfunction(L, RootObject_get_isInsideBuilding);
    lua_setfield(L, -2, "isInsideBuilding");
    lua_pushcfunction(L, RootObject_get_isInsideTownWalls);
    lua_setfield(L, -2, "isInsideTownWalls");
    lua_pushcfunction(L, RootObject_get_floorNum);
    lua_setfield(L, -2, "floorNum");
    lua_pushcfunction(L, RootObject_get_spacialKey);
    lua_setfield(L, -2, "spacialKey");
    lua_pushcfunction(L, RootObject_get_outdoorDelayNotification_timer);
    lua_setfield(L, -2, "outdoorDelayNotification_timer");
    lua_pushcfunction(L, RootObject_get_rot);
    lua_setfield(L, -2, "rot");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, RootObject_set_container);
    lua_setfield(L, -2, "container");
    lua_pushcfunction(L, RootObject_set_isInsideBuilding);
    lua_setfield(L, -2, "isInsideBuilding");
    lua_pushcfunction(L, RootObject_set_isInsideTownWalls);
    lua_setfield(L, -2, "isInsideTownWalls");
    lua_pushcfunction(L, RootObject_set_floorNum);
    lua_setfield(L, -2, "floorNum");
    lua_pushcfunction(L, RootObject_set_spacialKey);
    lua_setfield(L, -2, "spacialKey");
    lua_pushcfunction(L, RootObject_set_outdoorDelayNotification_timer);
    lua_setfield(L, -2, "outdoorDelayNotification_timer");
    lua_pushcfunction(L, RootObject_set_rot);
    lua_setfield(L, -2, "rot");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    LektorPtrBinding<RootObject*>::registerBinding(L, "lektor<RootObject*>", RootObjectBinding::getMetatableName());
}

} // namespace KenshiLua