#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RootObjectBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RootObject"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int needsSaving(lua_State* L);
    static int _NV_needsSaving(lua_State* L);
    static int getOrientation(lua_State* L);
    static int _NV_getOrientation(lua_State* L);
    static int getRace(lua_State* L);
    static int _NV_getRace(lua_State* L);
    static int threadedUpdate(lua_State* L);
    static int _NV_threadedUpdate(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int isPhysical(lua_State* L);
    static int setVisible(lua_State* L);
    static int getVisible(lua_State* L);
    static int _NV_getVisible(lua_State* L);
    static int isDisabled(lua_State* L);
    static int _NV_isDisabled(lua_State* L);
    static int amInsideTownWalls(lua_State* L);
    static int _NV_amInsideTownWalls(lua_State* L);
    static int setInsideTownWalls(lua_State* L);
    static int _NV_setInsideTownWalls(lua_State* L);
    static int getFloor(lua_State* L);
    static int _NV_getFloor(lua_State* L);
    static int setFloor(lua_State* L);
    static int _NV_setFloor(lua_State* L);
    static int select(lua_State* L);
    static int _NV_select(lua_State* L);
    static int unselect(lua_State* L);
    static int _NV_unselect(lua_State* L);
    static int setStandingOrder(lua_State* L);
    static int _NV_setStandingOrder(lua_State* L);
    static int getInventory(lua_State* L);
    static int _NV_getInventory(lua_State* L);
    static int takeMoney(lua_State* L);
    static int _NV_takeMoney(lua_State* L);
    static int getMoney(lua_State* L);
    static int _NV_getMoney(lua_State* L);
    static int say(lua_State* L);
    static int _NV_say(lua_State* L);
    static int notifyOutdoors(lua_State* L);
    static int _NV_notifyOutdoors(lua_State* L);
    static int isOnARoof(lua_State* L);
    static int _NV_isOnARoof(lua_State* L);
    static int getIntendedAggression(lua_State* L);
    static int _NV_getIntendedAggression(lua_State* L);
    static int createPhysical(lua_State* L);
    static int destroyPhysical(lua_State* L);
    static int notifyEffect(lua_State* L);
    static int _NV_notifyEffect(lua_State* L);
    static int loadUnloadCheck(lua_State* L);
    static int _NV_loadUnloadCheck(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int getInstanceID(lua_State* L);
    static int _NV_getInstanceID(lua_State* L);
    static int getLayoutInstanceID(lua_State* L);
    static int _NV_getLayoutInstanceID(lua_State* L);
    static int getZoneMapLocation(lua_State* L);
    static int _NV_getZoneMapLocation(lua_State* L);
    static int getAABB(lua_State* L);
    static int _NV_getAABB(lua_State* L);
    static int getGUIData(lua_State* L);
    static int _NV_getGUIData(lua_State* L);
    static int getGUIDataCategories(lua_State* L);
    static int _NV_getGUIDataCategories(lua_State* L);
    static int getOrders(lua_State* L);
    static int _NV_getOrders(lua_State* L);
    static int hasRoomForItem(lua_State* L);
    static int _NV_hasRoomForItem(lua_State* L);
    static int createInventoryLayout(lua_State* L);
    static int _NV_createInventoryLayout(lua_State* L);
    static int ImStealingDoYouNotice(lua_State* L);
    static int _NV_ImStealingDoYouNotice(lua_State* L);
    static int stolenGoodsDetectionCheck(lua_State* L);
    static int _NV_stolenGoodsDetectionCheck(lua_State* L);
    static int notifyIndoors(lua_State* L);
    static int _NV_notifyIndoors(lua_State* L);
    static int hitByMeleeAttack(lua_State* L);
    static int _NV_hitByMeleeAttack(lua_State* L);
    static int getPlatoonAI(lua_State* L);
    static int _NV_getPlatoonAI(lua_State* L);

    static int setFaction(lua_State* L);
    static int _NV_setFaction(lua_State* L);
    static int giveItem(lua_State* L);
    static int _NV_giveItem(lua_State* L);
    static int hasItem(lua_State* L);
    static int _NV_hasItem(lua_State* L);
    static int equipItem(lua_State* L);
    static int _NV_equipItem(lua_State* L);
    static int unequipItem(lua_State* L);
    static int _NV_unequipItem(lua_State* L);
    static int dropItem(lua_State* L);
    static int _NV_dropItem(lua_State* L);
    static int isIndoors(lua_State* L);
    static int _NV_isIndoors(lua_State* L);
    static int setIsInsideBuilding(lua_State* L);
    static int _NV_setIsInsideBuilding(lua_State* L);
};
}
