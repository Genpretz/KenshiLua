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
        static int index(lua_State* L);
        static int newindex(lua_State* L);

        static int clearAll(lua_State* L);
        static int notifyModified(lua_State* L);
        static int removeAllSections(lua_State* L);
        static int hasStolenItems(lua_State* L);
        static int hasWeaponEquipped(lua_State* L);
        static int isAContainer(lua_State* L);
        static int isEmpty(lua_State* L);
        static int recalculateTotalWeight(lua_State* L);
        static int getTotalWeight(lua_State* L);
        static int getMoney(lua_State* L);
        static int takeMoney(lua_State* L);
        static int isVisible(lua_State* L);
        static int refreshGui(lua_State* L);
        static int _NV_refreshGui(lua_State* L);
        static int autoArrange(lua_State* L);

        static int _DESTRUCTOR(lua_State* L);
        static int getSection(lua_State* L);
        static int getCallbackCharacter(lua_State* L);
        static int hasItemType(lua_State* L);
        static int getSecondaryWeapon(lua_State* L);
        static int getPrimaryWeapon(lua_State* L);
        static int getOwner(lua_State* L);
        static int getCallbackObject(lua_State* L);
    };

    class InventorySectionBinding
    {
    public:
        static const char* getMetatableName() { return "KenshiLua.InventorySection"; }
        static void registerBinding(lua_State* L);

        static int gc(lua_State* L);
        static int tostring(lua_State* L);
        static int index(lua_State* L);
        static int newindex(lua_State* L);

        static int _DESTRUCTOR(lua_State* L);
        static int notifyModified(lua_State* L);
        static int getItemAt(lua_State* L);
        static int hasItemType(lua_State* L);
        static int autoArrange(lua_State* L);
        static int _NV_autoArrange(lua_State* L);
        static int getNumItems(lua_State* L);
        static int isEmpty(lua_State* L);
        static int clearAllItems(lua_State* L);
        static int applyStackingBonuses(lua_State* L);
        static int recalculateTotalWeight(lua_State* L);
        static int setWeightMultiplier(lua_State* L);
        static int setStackingBonus(lua_State* L);
        static int getMaxStack(lua_State* L);
        static int clearVeryLimitedSlot(lua_State* L);
        static int getEnabled(lua_State* L);
        static int setEnabled(lua_State* L);
        static int setItemsLimitCount(lua_State* L);
        static int getItemsLimitReached(lua_State* L);
        static int getInventory(lua_State* L);
        static int getFillPercentage(lua_State* L);
        static int getItem(lua_State* L);
        static int resize(lua_State* L);
    };

    class SectionItemBinding
    {
    public:
        static const char* getMetatableName() { return "KenshiLua.SectionItem"; }
        static void registerBinding(lua_State* L);

        static int gc(lua_State* L);
        static int tostring(lua_State* L);
        static int index(lua_State* L);
        static int newindex(lua_State* L);

    };

    class HasRoomCacheBinding
    {
    public:
        static const char* getMetatableName() { return "KenshiLua.HasRoomCache"; }
        static void registerBinding(lua_State* L);

        static int gc(lua_State* L);
        static int tostring(lua_State* L);
        static int index(lua_State* L);
        static int newindex(lua_State* L);

        static int modified(lua_State* L);
        static int _DESTRUCTOR(lua_State* L);
    };

}
