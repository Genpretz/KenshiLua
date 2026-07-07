#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class InventoryBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Inventory"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int clearAll(lua_State* L);
    static int notifyModified(lua_State* L);
    static int initialiseNewSection(lua_State* L);
    static int _NV_initialiseNewSection(lua_State* L);
    static int removeAllSections(lua_State* L);
    static int getSection(lua_State* L);
    static int getSectionOfType(lua_State* L);
    static int resizeSection(lua_State* L);
    static int getCallbackCharacter(lua_State* L);
    static int hasItemType(lua_State* L);
    static int hasStolenItems(lua_State* L);
    static int getSecondaryWeapon(lua_State* L);
    static int getPrimaryWeapon(lua_State* L);
    static int hasItemFunction(lua_State* L);
    static int getBestItemWithFunction(lua_State* L);
    static int hasWeaponEquipped(lua_State* L);
    static int isAContainer(lua_State* L);
    static int getOwner(lua_State* L);
    static int isEmpty(lua_State* L);
    static int recalculateTotalWeight(lua_State* L);
    static int getTotalWeight(lua_State* L);
    static int getMoney(lua_State* L);
    static int takeMoney(lua_State* L);
    static int isVisible(lua_State* L);
    static int refreshGui(lua_State* L);
    static int _NV_refreshGui(lua_State* L);
    static int autoArrange(lua_State* L);
    static int getCallbackObject(lua_State* L);

    static int getHandle(lua_State* L);
    static int addItem(lua_State* L);
    static int _NV_addItem(lua_State* L);
    static int tryAddItem(lua_State* L);
    static int _NV_tryAddItem(lua_State* L);
    static int removeItemDontDestroy_returnsItem(lua_State* L);
    static int _NV_removeItemDontDestroy_returnsItem(lua_State* L);
    static int removeItemAutoDestroy(lua_State* L);
    static int _NV_removeItemAutoDestroy(lua_State* L);
    static int dropItem(lua_State* L);
    static int _NV_dropItem(lua_State* L);
    static int getItem(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int serialise(lua_State* L);
    static int loadFrom(lua_State* L);
    static int fillFromVendorList(lua_State* L);
    static int getAllSectionsOfType(lua_State* L);
    static int getAllSections(lua_State* L);
    static int getExcessLoot(lua_State* L);
    static int getResourceItems(lua_State* L);
    static int getNumItems(lua_State* L);
    static int hasRoomForItem(lua_State* L);
    static int _NV_hasRoomForItem(lua_State* L);
    static int transferMouseItem(lua_State* L);
    static int hasItem(lua_State* L);
    static int countItems(lua_State* L);
    static int getAllStolenItems(lua_State* L);
    static int getAllItemsOfType(lua_State* L);
    static int getEquippedWeapons(lua_State* L);
    static int getEquippedArmour(lua_State* L);
    static int takeOneItemOnly(lua_State* L);
    static int deathCheck(lua_State* L);
    static int takeItem_EntireStack(lua_State* L);
    static int getAllItemsWithFunction(lua_State* L);
    static int getBestItemWithLowestCharges(lua_State* L);
    static int getBestFoodItem(lua_State* L);
    static int getNumFoodItems(lua_State* L);
    static int _getBestFoodItem(lua_State* L);
    static int _getNumFoodItems(lua_State* L);
    static int equipItem(lua_State* L);
    static int buyItem(lua_State* L);
    static int getInventoryGUI(lua_State* L);
    static int _sectionAddItemCallback(lua_State* L);
    static int _NV__sectionAddItemCallback(lua_State* L);
    static int _sectionUpdateItemCallback(lua_State* L);
    static int _NV__sectionUpdateItemCallback(lua_State* L);
    static int _sectionRemoveItemCallback(lua_State* L);
    static int _NV__sectionRemoveItemCallback(lua_State* L);
    static int _addToList(lua_State* L);
    static int _NV__addToList(lua_State* L);
    static int _removeFromList(lua_State* L);
    static int _NV__removeFromList(lua_State* L);
    static int getAllItems(lua_State* L);
};
}