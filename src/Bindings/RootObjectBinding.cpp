#include "pch.h"
#include "kenshi\RootObject.h"
#include "RootObjectBinding.h"
#include "RootObjectContainerBinding.h"
#include "kenshi/Inventory.h"
#include "InventoryBinding.h"
#include "kenshi/RaceData.h"
#include "RaceDataBinding.h"
#include "Lua/BindingHelpers.h"

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
    // TODO: Unsupported type for isInsideBuilding (hand)
    lua_pushnil(L);
    return 1;
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
    return luaL_error(L, "Read-only or unsupported setter type for isInsideBuilding");
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

/*
Skipped methods needing manual binding:
  line 25: RootObject* _CONSTRUCTOR(...) - unsupported arg type
  line 30: InstanceID* getInstanceID(...) - unsupported return type
  line 31: InstanceID* _NV_getInstanceID(...) - unsupported return type
  line 32: const std::string& getLayoutInstanceID(...) - reference return type
  line 33: const std::string& _NV_getLayoutInstanceID(...) - reference return type
  line 36: ZoneMap* getZoneMapLocation(...) - unsupported return type
  line 37: ZoneMap* _NV_getZoneMapLocation(...) - unsupported return type
  line 47: const Ogre::Aabb& getAABB(...) - reference return type
  line 48: const Ogre::Aabb& _NV_getAABB(...) - reference return type
  line 55: void setFaction(...) - unsupported arg type
  line 56: void _NV_setFaction(...) - unsupported arg type
  line 69: void getGUIData(...) - unsupported arg type
  line 70: void _NV_getGUIData(...) - unsupported arg type
  line 71: void getGUIDataCategories(...) - unsupported arg type
  line 72: void _NV_getGUIDataCategories(...) - unsupported arg type
  line 75: void getOrders(...) - unsupported arg type
  line 76: void _NV_getOrders(...) - unsupported arg type
  line 79: bool giveItem(...) - unsupported arg type
  line 80: bool _NV_giveItem(...) - unsupported arg type
  line 81: bool hasRoomForItem(...) - unsupported arg type
  line 82: bool _NV_hasRoomForItem(...) - unsupported arg type
  line 83: bool hasItem(...) - unsupported arg type
  line 84: bool _NV_hasItem(...) - unsupported arg type
  line 85: InventoryLayout* createInventoryLayout(...) - unsupported return type
  line 86: InventoryLayout* _NV_createInventoryLayout(...) - unsupported return type
  line 87: bool ImStealingDoYouNotice(...) - unsupported arg type
  line 88: bool _NV_ImStealingDoYouNotice(...) - unsupported arg type
  line 89: bool stolenGoodsDetectionCheck(...) - unsupported arg type
  line 90: bool _NV_stolenGoodsDetectionCheck(...) - unsupported arg type
  line 91: void equipItem(...) - unsupported arg type
  line 92: void _NV_equipItem(...) - unsupported arg type
  line 93: void unequipItem(...) - unsupported arg type
  line 94: void _NV_unequipItem(...) - unsupported arg type
  line 95: void dropItem(...) - unsupported arg type
  line 96: void _NV_dropItem(...) - unsupported arg type
  line 103: void notifyIndoors(...) - unsupported arg type
  line 104: void _NV_notifyIndoors(...) - unsupported arg type
  line 107: const hand& isIndoors(...) - reference return type
  line 108: const hand& _NV_isIndoors(...) - reference return type
  line 113: HitMaterialType hitByMeleeAttack(...) - unsupported arg type
  line 114: HitMaterialType _NV_hitByMeleeAttack(...) - unsupported arg type
  line 115: PlatoonAI* getPlatoonAI(...) - unsupported return type
  line 116: PlatoonAI* _NV_getPlatoonAI(...) - unsupported return type
  line 119: void setIsInsideBuilding(...) - unsupported arg type
  line 120: void _NV_setIsInsideBuilding(...) - unsupported arg type
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

void RootObjectBinding::registerBinding(lua_State* L)
{
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
}

} // namespace KenshiLua