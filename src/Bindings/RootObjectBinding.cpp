#include "pch.h"
#include "kenshi\RootObject.h"
#include "RootObjectBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/CombatTechniqueDataBinding.h"
#include "Bindings/DamagesBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/InstanceIDBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/RaceDataBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/RootObjectContainerBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/StringPairBinding.h"
#include "InventoryBinding.h"
#include "RaceDataBinding.h"
#include "RootObjectContainerBinding.h"
#include "kenshi/Character.h"
#include "kenshi/CombatTechniqueData.h"
#include "kenshi/Damages.h"
#include "kenshi/InstanceID.h"
#include "kenshi/Inventory.h"
#include "kenshi/RaceData.h"
#include "kenshi/ZoneManager.h"
#include "kenshi/gui/InventoryGUI.h"

namespace KenshiLua
{

static RootObject* getInstance(lua_State* L, int idx)
{
    return checkObject<RootObject>(L, idx, RootObjectBinding::getMetatableName());
}

// --- Getters for RootObject ---
static int RootObject_get_container(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    return pushObject<RootObjectContainer>(L, instance->container, RootObjectContainerBinding::getMetatableName());
}

static int RootObject_get_isInsideBuilding(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    return handBinding::push(L, instance->isInsideBuilding);
}

static int RootObject_get_isInsideTownWalls(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    lua_pushinteger(L, instance->isInsideTownWalls);
    return 1;
}

static int RootObject_get_floorNum(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    lua_pushinteger(L, instance->floorNum);
    return 1;
}

static int RootObject_get_spacialKey(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    lua_pushinteger(L, instance->spacialKey);
    return 1;
}

static int RootObject_get_outdoorDelayNotification_timer(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    lua_pushinteger(L, instance->outdoorDelayNotification_timer);
    return 1;
}

static int RootObject_get_rot(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    pushQuaternion(L, instance->rot);
    return 1;
}

// --- Setters for RootObject ---
static int RootObject_set_container(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    instance->container = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObjectContainer>(L, 2, RootObjectContainerBinding::getMetatableName());
    return 0;
}

static int RootObject_set_isInsideBuilding(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    instance->isInsideBuilding = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int RootObject_set_isInsideTownWalls(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    instance->isInsideTownWalls = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int RootObject_set_floorNum(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    instance->floorNum = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int RootObject_set_spacialKey(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    instance->spacialKey = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int RootObject_set_outdoorDelayNotification_timer(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    instance->outdoorDelayNotification_timer = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int RootObject_set_rot(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    readQuaternion(L, 2, instance->rot);
    return 0;
}

int RootObjectBinding::_CONSTRUCTOR(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Faction* ownr = checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    hand _h = *checkObject<hand>(L, 4, handBinding::getMetatableName());
    RootObject* result = instance->_CONSTRUCTOR(d, ownr, _h);
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int RootObjectBinding::_DESTRUCTOR(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int RootObjectBinding::needsSaving(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    const std::string s = luaL_checkstring(L, 2);
    bool result = instance->needsSaving(s);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_needsSaving(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    const std::string s = luaL_checkstring(L, 2);
    bool result = instance->_NV_needsSaving(s);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::getInstanceID(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    InstanceID* result = instance->getInstanceID();
    return pushObject<InstanceID>(L, result, InstanceIDBinding::getMetatableName());
}

int RootObjectBinding::_NV_getInstanceID(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    InstanceID* result = instance->_NV_getInstanceID();
    return pushObject<InstanceID>(L, result, InstanceIDBinding::getMetatableName());
}

int RootObjectBinding::getOrientation(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    Ogre::Quaternion result = instance->getOrientation();
    pushQuaternion(L, result);
    return 1;
}

int RootObjectBinding::_NV_getOrientation(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    Ogre::Quaternion result = instance->_NV_getOrientation();
    pushQuaternion(L, result);
    return 1;
}

int RootObjectBinding::getZoneMapLocation(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    ZoneMap* result = instance->getZoneMapLocation();
    return pushObject<ZoneMap>(L, result, ZoneMapBinding::getMetatableName());
}

int RootObjectBinding::_NV_getZoneMapLocation(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    ZoneMap* result = instance->_NV_getZoneMapLocation();
    return pushObject<ZoneMap>(L, result, ZoneMapBinding::getMetatableName());
}

int RootObjectBinding::getRace(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    RaceData* result = instance->getRace();
    return pushObject<RaceData>(L, result, RaceDataBinding::getMetatableName());
}

int RootObjectBinding::_NV_getRace(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    RaceData* result = instance->_NV_getRace();
    return pushObject<RaceData>(L, result, RaceDataBinding::getMetatableName());
}

int RootObjectBinding::threadedUpdate(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->threadedUpdate();
    return 0;
}

int RootObjectBinding::_NV_threadedUpdate(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->_NV_threadedUpdate();
    return 0;
}

int RootObjectBinding::update(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->update();
    return 0;
}

int RootObjectBinding::_NV_update(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->_NV_update();
    return 0;
}

int RootObjectBinding::periodicUpdate(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->periodicUpdate();
    return 0;
}

int RootObjectBinding::_NV_periodicUpdate(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->_NV_periodicUpdate();
    return 0;
}

int RootObjectBinding::isPhysical(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    bool result = instance->isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::setVisible(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    bool _a1 = lua_toboolean(L, 2) != 0;
    instance->setVisible(_a1);
    return 0;
}

int RootObjectBinding::getVisible(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_getVisible(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    bool result = instance->_NV_getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::isDisabled(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    bool result = instance->isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_isDisabled(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    bool result = instance->_NV_isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::setFaction(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* a = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    instance->setFaction(p, a);
    return 0;
}

int RootObjectBinding::_NV_setFaction(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* a = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    instance->_NV_setFaction(p, a);
    return 0;
}

int RootObjectBinding::amInsideTownWalls(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    int result = instance->amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBinding::_NV_amInsideTownWalls(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    int result = instance->_NV_amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBinding::setInsideTownWalls(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    int s = (int)luaL_checkinteger(L, 2);
    instance->setInsideTownWalls(s);
    return 0;
}

int RootObjectBinding::_NV_setInsideTownWalls(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    int s = (int)luaL_checkinteger(L, 2);
    instance->_NV_setInsideTownWalls(s);
    return 0;
}

int RootObjectBinding::getFloor(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    int result = instance->getFloor();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBinding::_NV_getFloor(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    int result = instance->_NV_getFloor();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBinding::setFloor(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    int f = (int)luaL_checkinteger(L, 2);
    instance->setFloor(f);
    return 0;
}

int RootObjectBinding::_NV_setFloor(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    int f = (int)luaL_checkinteger(L, 2);
    instance->_NV_setFloor(f);
    return 0;
}

int RootObjectBinding::select(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->select();
    return 0;
}

int RootObjectBinding::_NV_select(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->_NV_select();
    return 0;
}

int RootObjectBinding::unselect(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->unselect();
    return 0;
}

int RootObjectBinding::_NV_unselect(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->_NV_unselect();
    return 0;
}

int RootObjectBinding::getGUIData(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    DatapanelGUI* _a1 = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(_a1, category);
    return 0;
}

int RootObjectBinding::_NV_getGUIData(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    DatapanelGUI* _a1 = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIData(_a1, category);
    return 0;
}

int RootObjectBinding::setStandingOrder(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    MessageForB::StandingOrder _a1 = (MessageForB::StandingOrder)luaL_checkinteger(L, 2);
    instance->setStandingOrder(_a1);
    return 0;
}

int RootObjectBinding::_NV_setStandingOrder(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    MessageForB::StandingOrder _a1 = (MessageForB::StandingOrder)luaL_checkinteger(L, 2);
    instance->_NV_setStandingOrder(_a1);
    return 0;
}

int RootObjectBinding::getInventory(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    Inventory* result = instance->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int RootObjectBinding::_NV_getInventory(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    Inventory* result = instance->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int RootObjectBinding::giveItem(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool dropOnFail = lua_toboolean(L, 3) != 0;
    bool destroyOnFail = lua_toboolean(L, 4) != 0;
    bool result = instance->giveItem(item, dropOnFail, destroyOnFail);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_giveItem(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool dropOnFail = lua_toboolean(L, 3) != 0;
    bool destroyOnFail = lua_toboolean(L, 4) != 0;
    bool result = instance->_NV_giveItem(item, dropOnFail, destroyOnFail);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::hasRoomForItem(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->hasRoomForItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_hasRoomForItem(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->_NV_hasRoomForItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::hasItem(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->hasItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_hasItem(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->_NV_hasItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::createInventoryLayout(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    InventoryLayout* result = instance->createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

int RootObjectBinding::_NV_createInventoryLayout(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    InventoryLayout* result = instance->_NV_createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

int RootObjectBinding::ImStealingDoYouNotice(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    RootObject* thief = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->ImStealingDoYouNotice(thief);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_ImStealingDoYouNotice(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    RootObject* thief = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->_NV_ImStealingDoYouNotice(thief);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::stolenGoodsDetectionCheck(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    RootObject* thief = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    bool result = instance->stolenGoodsDetectionCheck(item, thief);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_stolenGoodsDetectionCheck(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    RootObject* thief = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    bool result = instance->_NV_stolenGoodsDetectionCheck(item, thief);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::equipItem(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    const std::string _a1 = luaL_checkstring(L, 2);
    Item* _a2 = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->equipItem(_a1, _a2);
    return 0;
}

int RootObjectBinding::_NV_equipItem(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    const std::string _a1 = luaL_checkstring(L, 2);
    Item* _a2 = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->_NV_equipItem(_a1, _a2);
    return 0;
}

int RootObjectBinding::unequipItem(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    const std::string _a1 = luaL_checkstring(L, 2);
    Item* _a2 = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->unequipItem(_a1, _a2);
    return 0;
}

int RootObjectBinding::_NV_unequipItem(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    const std::string _a1 = luaL_checkstring(L, 2);
    Item* _a2 = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->_NV_unequipItem(_a1, _a2);
    return 0;
}

int RootObjectBinding::dropItem(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    RootObject* _a1 = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->dropItem(_a1);
    return 0;
}

int RootObjectBinding::_NV_dropItem(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    RootObject* _a1 = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->_NV_dropItem(_a1);
    return 0;
}

int RootObjectBinding::takeMoney(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    int _a1 = (int)luaL_checkinteger(L, 2);
    bool result = instance->takeMoney(_a1);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_takeMoney(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    int _a1 = (int)luaL_checkinteger(L, 2);
    bool result = instance->_NV_takeMoney(_a1);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::getMoney(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    int result = instance->getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBinding::_NV_getMoney(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    int result = instance->_NV_getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBinding::say(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    const std::string _a1 = luaL_checkstring(L, 2);
    instance->say(_a1);
    return 0;
}

int RootObjectBinding::_NV_say(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    const std::string _a1 = luaL_checkstring(L, 2);
    instance->_NV_say(_a1);
    return 0;
}

int RootObjectBinding::notifyOutdoors(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->notifyOutdoors();
    return 0;
}

int RootObjectBinding::_NV_notifyOutdoors(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->_NV_notifyOutdoors();
    return 0;
}

int RootObjectBinding::isOnARoof(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    bool result = instance->isOnARoof();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::_NV_isOnARoof(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    bool result = instance->_NV_isOnARoof();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::getIntendedAggression(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    float result = instance->getIntendedAggression();
    lua_pushnumber(L, result);
    return 1;
}

int RootObjectBinding::_NV_getIntendedAggression(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    float result = instance->_NV_getIntendedAggression();
    lua_pushnumber(L, result);
    return 1;
}

int RootObjectBinding::getPlatoonAI(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    PlatoonAI* result = instance->getPlatoonAI();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int RootObjectBinding::_NV_getPlatoonAI(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    PlatoonAI* result = instance->_NV_getPlatoonAI();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int RootObjectBinding::createPhysical(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    bool result = instance->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBinding::destroyPhysical(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->destroyPhysical();
    return 0;
}

int RootObjectBinding::notifyEffect(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    EffectType::Enum type = (EffectType::Enum)luaL_checkinteger(L, 2);
    WeatherAffecting what = (WeatherAffecting)luaL_checkinteger(L, 3);
    float strength = (float)luaL_checknumber(L, 4);
    instance->notifyEffect(type, what, strength);
    return 0;
}

int RootObjectBinding::_NV_notifyEffect(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    EffectType::Enum type = (EffectType::Enum)luaL_checkinteger(L, 2);
    WeatherAffecting what = (WeatherAffecting)luaL_checkinteger(L, 3);
    float strength = (float)luaL_checknumber(L, 4);
    instance->_NV_notifyEffect(type, what, strength);
    return 0;
}

int RootObjectBinding::loadUnloadCheck(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->loadUnloadCheck();
    return 0;
}

int RootObjectBinding::_NV_loadUnloadCheck(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");

    instance->_NV_loadUnloadCheck();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 32: const std::string& getLayoutInstanceID(...) - reference return type
  line 33: const std::string& _NV_getLayoutInstanceID(...) - reference return type
  line 47: const Ogre::Aabb& getAABB(...) - reference return type
  line 48: const Ogre::Aabb& _NV_getAABB(...) - reference return type
  line 71: void getGUIDataCategories(...) - unsupported arg type
  line 72: void _NV_getGUIDataCategories(...) - unsupported arg type
  line 75: void getOrders(...) - unsupported arg type
  line 76: void _NV_getOrders(...) - unsupported arg type
  line 103: void notifyIndoors(...) - non-string reference arg
  line 104: void _NV_notifyIndoors(...) - non-string reference arg
  line 107: const hand& isIndoors(...) - reference return type
  line 108: const hand& _NV_isIndoors(...) - reference return type
  line 113: HitMaterialType hitByMeleeAttack(...) - non-string reference arg
  line 114: HitMaterialType _NV_hitByMeleeAttack(...) - non-string reference arg
  line 119: void setIsInsideBuilding(...) - non-string reference arg
  line 120: void _NV_setIsInsideBuilding(...) - non-string reference arg
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - RootObjectBinding::getPlatoonAI: PlatoonAI* (unbound pointer)
  - RootObjectBinding::_NV_getPlatoonAI: PlatoonAI* (unbound pointer)
*/

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



int RootObjectBinding::_NV_getAABB(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    const Ogre::Aabb& res = instance->_NV_getAABB();
    lua_pushlightuserdata(L, (void*)&res);
    return 1;
}


int RootObjectBinding::_NV_getGUIDataCategories(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    lektor<StringPair>* out = LektorValueBinding<StringPair>::get(L, 2);
    if (!out) return luaL_error(L, "lektor<StringPair> is nil or invalid");
    instance->_NV_getGUIDataCategories(*out);
    return 0;
}


int RootObjectBinding::_NV_getLayoutInstanceID(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    const std::string& res = instance->_NV_getLayoutInstanceID();
    lua_pushstring(L, res.c_str());
    return 1;
}


int RootObjectBinding::_NV_getOrders(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    lektor<std::string>* out = LektorStringBinding<std::string>::get(L, 2);
    if (!out) return luaL_error(L, "lektor<string> is nil or invalid");
    instance->_NV_getOrders(*out);
    return 0;
}


int RootObjectBinding::_NV_hitByMeleeAttack(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
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
    HitMaterialType res = instance->_NV_hitByMeleeAttack(dir, *damage, who, attack, comboID);
    lua_pushinteger(L, (lua_Integer)res);
    return 1;
}


int RootObjectBinding::_NV_isIndoors(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    const hand& result = instance->_NV_isIndoors();
    handBinding::push(L, result);
    return 1;
}


int RootObjectBinding::_NV_notifyIndoors(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    hand* in = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->_NV_notifyIndoors(*in);
    return 0;
}


int RootObjectBinding::_NV_setIsInsideBuilding(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->_NV_setIsInsideBuilding(*h);
    return 0;
}


int RootObjectBinding::getAABB(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    const Ogre::Aabb& res = instance->getAABB();
    lua_pushlightuserdata(L, (void*)&res);
    return 1;
}


int RootObjectBinding::getGUIDataCategories(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    lektor<StringPair>* out = LektorValueBinding<StringPair>::get(L, 2);
    if (!out) return luaL_error(L, "lektor<StringPair> is nil or invalid");
    instance->getGUIDataCategories(*out);
    return 0;
}


int RootObjectBinding::getLayoutInstanceID(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    const std::string& res = instance->getLayoutInstanceID();
    lua_pushstring(L, res.c_str());
    return 1;
}


int RootObjectBinding::getOrders(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    lektor<std::string>* out = LektorStringBinding<std::string>::get(L, 2);
    if (!out) return luaL_error(L, "lektor<string> is nil or invalid");
    instance->getOrders(*out);
    return 0;
}


int RootObjectBinding::hitByMeleeAttack(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
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
    HitMaterialType res = instance->hitByMeleeAttack(dir, *damage, who, attack, comboID);
    lua_pushinteger(L, (lua_Integer)res);
    return 1;
}


int RootObjectBinding::isIndoors(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    const hand& result = instance->isIndoors();
    handBinding::push(L, result);
    return 1;
}


int RootObjectBinding::notifyIndoors(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    hand* in = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->notifyIndoors(*in);
    return 0;
}


int RootObjectBinding::setIsInsideBuilding(lua_State* L)
{
    RootObject* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObject is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->setIsInsideBuilding(*h);
    return 0;
}


void RootObjectBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RootObjectBinding::gc },
        { "__tostring", RootObjectBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", RootObjectBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", RootObjectBinding::_DESTRUCTOR },
        { "needsSaving", RootObjectBinding::needsSaving },
        { "_NV_needsSaving", RootObjectBinding::_NV_needsSaving },
        { "getInstanceID", RootObjectBinding::getInstanceID },
        { "_NV_getInstanceID", RootObjectBinding::_NV_getInstanceID },
        { "getOrientation", RootObjectBinding::getOrientation },
        { "_NV_getOrientation", RootObjectBinding::_NV_getOrientation },
        { "getZoneMapLocation", RootObjectBinding::getZoneMapLocation },
        { "_NV_getZoneMapLocation", RootObjectBinding::_NV_getZoneMapLocation },
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
        { "setFaction", RootObjectBinding::setFaction },
        { "_NV_setFaction", RootObjectBinding::_NV_setFaction },
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
        { "getGUIData", RootObjectBinding::getGUIData },
        { "_NV_getGUIData", RootObjectBinding::_NV_getGUIData },
        { "setStandingOrder", RootObjectBinding::setStandingOrder },
        { "_NV_setStandingOrder", RootObjectBinding::_NV_setStandingOrder },
        { "getInventory", RootObjectBinding::getInventory },
        { "_NV_getInventory", RootObjectBinding::_NV_getInventory },
        { "giveItem", RootObjectBinding::giveItem },
        { "_NV_giveItem", RootObjectBinding::_NV_giveItem },
        { "hasRoomForItem", RootObjectBinding::hasRoomForItem },
        { "_NV_hasRoomForItem", RootObjectBinding::_NV_hasRoomForItem },
        { "hasItem", RootObjectBinding::hasItem },
        { "_NV_hasItem", RootObjectBinding::_NV_hasItem },
        { "createInventoryLayout", RootObjectBinding::createInventoryLayout },
        { "_NV_createInventoryLayout", RootObjectBinding::_NV_createInventoryLayout },
        { "ImStealingDoYouNotice", RootObjectBinding::ImStealingDoYouNotice },
        { "_NV_ImStealingDoYouNotice", RootObjectBinding::_NV_ImStealingDoYouNotice },
        { "stolenGoodsDetectionCheck", RootObjectBinding::stolenGoodsDetectionCheck },
        { "_NV_stolenGoodsDetectionCheck", RootObjectBinding::_NV_stolenGoodsDetectionCheck },
        { "equipItem", RootObjectBinding::equipItem },
        { "_NV_equipItem", RootObjectBinding::_NV_equipItem },
        { "unequipItem", RootObjectBinding::unequipItem },
        { "_NV_unequipItem", RootObjectBinding::_NV_unequipItem },
        { "dropItem", RootObjectBinding::dropItem },
        { "_NV_dropItem", RootObjectBinding::_NV_dropItem },
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
        { "getPlatoonAI", RootObjectBinding::getPlatoonAI },
        { "_NV_getPlatoonAI", RootObjectBinding::_NV_getPlatoonAI },
        { "createPhysical", RootObjectBinding::createPhysical },
        { "destroyPhysical", RootObjectBinding::destroyPhysical },
        { "notifyEffect", RootObjectBinding::notifyEffect },
        { "_NV_notifyEffect", RootObjectBinding::_NV_notifyEffect },
        { "loadUnloadCheck", RootObjectBinding::loadUnloadCheck },
        { "_NV_loadUnloadCheck", RootObjectBinding::_NV_loadUnloadCheck },
                { "isIndoors", RootObjectBinding::isIndoors },
        { "_NV_isIndoors", RootObjectBinding::_NV_isIndoors },
        { "setIsInsideBuilding", RootObjectBinding::setIsInsideBuilding },
        { "_NV_setIsInsideBuilding", RootObjectBinding::_NV_setIsInsideBuilding },
        { "getLayoutInstanceID", RootObjectBinding::getLayoutInstanceID },
        { "_NV_getLayoutInstanceID", RootObjectBinding::_NV_getLayoutInstanceID },
        { "getAABB", RootObjectBinding::getAABB },
        { "_NV_getAABB", RootObjectBinding::_NV_getAABB },
        { "getGUIDataCategories", RootObjectBinding::getGUIDataCategories },
        { "_NV_getGUIDataCategories", RootObjectBinding::_NV_getGUIDataCategories },
        { "getOrders", RootObjectBinding::getOrders },
        { "_NV_getOrders", RootObjectBinding::_NV_getOrders },
        { "notifyIndoors", RootObjectBinding::notifyIndoors },
        { "_NV_notifyIndoors", RootObjectBinding::_NV_notifyIndoors },
        { "hitByMeleeAttack", RootObjectBinding::hitByMeleeAttack },
        { "_NV_hitByMeleeAttack", RootObjectBinding::_NV_hitByMeleeAttack },
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
    registerGetter(L, "container", RootObject_get_container);
    registerGetter(L, "isInsideBuilding", RootObject_get_isInsideBuilding);
    registerGetter(L, "isInsideTownWalls", RootObject_get_isInsideTownWalls);
    registerGetter(L, "floorNum", RootObject_get_floorNum);
    registerGetter(L, "spacialKey", RootObject_get_spacialKey);
    registerGetter(L, "outdoorDelayNotification_timer", RootObject_get_outdoorDelayNotification_timer);
    registerGetter(L, "rot", RootObject_get_rot);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "container", RootObject_set_container);
    registerSetter(L, "isInsideBuilding", RootObject_set_isInsideBuilding);
    registerSetter(L, "isInsideTownWalls", RootObject_set_isInsideTownWalls);
    registerSetter(L, "floorNum", RootObject_set_floorNum);
    registerSetter(L, "spacialKey", RootObject_set_spacialKey);
    registerSetter(L, "outdoorDelayNotification_timer", RootObject_set_outdoorDelayNotification_timer);
    registerSetter(L, "rot", RootObject_set_rot);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to RootObjectBase
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, RootObjectBinding::getMetatableName(), RootObjectBaseBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua