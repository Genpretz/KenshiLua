#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class InventorySectionBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.InventorySection"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int notifyModified(lua_State* L);
    static int getItemAt(lua_State* L);
    static int hasItemType(lua_State* L);
    static int autoArrange(lua_State* L);
    static int _NV_autoArrange(lua_State* L);
    static int getNumItems(lua_State* L);
    static int isEmpty(lua_State* L);
    static int clearAllItems(lua_State* L);
    static int getLimitedSlot(lua_State* L);
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
}