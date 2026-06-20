#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

class InventoryItemBase;
class Item;

namespace KenshiLua
{

class InventoryItemBaseBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.InventoryItemBase"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    // Polymorphic helpers
    static int pushInventoryItemBase(lua_State* L, InventoryItemBase* item);
    static InventoryItemBase* getItem(lua_State* L, int idx);
    static InventoryItemBase* checkItem(lua_State* L, int idx);

    // Methods
    static int resetCharges(lua_State* L);
    static int addQuantity(lua_State* L);
    static int subtractQuantity(lua_State* L);
    static int getItemWeight(lua_State* L);
    static int getItemWeightSingle(lua_State* L);
    static int getValueSingle(lua_State* L);
    static int getValueAll(lua_State* L);
    static int getQuantity(lua_State* L);
    static int getQuality(lua_State* L);
    static int isResearchArtifact(lua_State* L);
    static int onGround(lua_State* L);
    static int isStolen(lua_State* L);
    static int getLevel(lua_State* L);
    static int getInventory(lua_State* L);
    static int getMaxAffordable(lua_State* L);
    static int getItemType(lua_State* L);
    static int getAvgPrice(lua_State* L);
    static int isStackable(lua_State* L);
    static int canStackWith(lua_State* L);
    static int getProperOwner(lua_State* L);
    static int setProperOwner(lua_State* L);
};

class ItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Item"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    // Polymorphic helpers
    static int pushItem(lua_State* L, Item* item);
    static Item* getItem(lua_State* L, int idx);
    static Item* checkItem(lua_State* L, int idx);

    // Reads
    static int getName(lua_State* L);
    static int getPosition(lua_State* L);
    static int getClassType(lua_State* L);
    static int getVisible(lua_State* L);
    static int getInventory(lua_State* L);
    static int getLevel(lua_State* L);
    static int getModelName(lua_State* L);
    static int isPersistant(lua_State* L);
    static int isValid(lua_State* L);

    // Writes
    static int setVisible(lua_State* L);
    static int setPositionRotation(lua_State* L);
    static int setInventoryWeAreIn(lua_State* L);
    static int setPersistant(lua_State* L);
    static int stolenGoodsDetectionCheck(lua_State* L);
};

} // namespace KenshiLua

