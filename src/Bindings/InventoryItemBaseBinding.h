#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class InventoryItemBaseBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.InventoryItemBase"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int deactivate(lua_State* L);
    static int resetAfterCopy(lua_State* L);
    static int resetCharges(lua_State* L);
    static int getItemType(lua_State* L);
    static int getItemWeightSingle(lua_State* L);
    static int _NV_getItemWeightSingle(lua_State* L);
    static int getItemWeight(lua_State* L);
    static int _NV_getItemWeight(lua_State* L);
    static int _serialise(lua_State* L);
    static int _loadFromSerialise(lua_State* L);
    static int loadFromSerialise(lua_State* L);
    static int serialiseInInventory(lua_State* L);
    static int loadFromSerialiseInInventory(lua_State* L);
    static int getGUIData(lua_State* L);
    static int _NV_getGUIData(lua_State* L);
    static int getAvgPrice(lua_State* L);
    static int getValueSingle(lua_State* L);
    static int _NV_getValueSingle(lua_State* L);
    static int getValueAll(lua_State* L);
    static int _NV_getValueAll(lua_State* L);
    static int getMaxAffordableNum(lua_State* L);
    static int _NV_getMaxAffordableNum(lua_State* L);
    static int isStackable(lua_State* L);
    static int canStackWith(lua_State* L);
    static int getInventory(lua_State* L);
    static int _NV_getInventory(lua_State* L);
    static int isSameAs(lua_State* L);
    static int _NV_isSameAs(lua_State* L);
    static int onGround(lua_State* L);
    static int isResearchArtifact(lua_State* L);
    static int getLevel(lua_State* L);
    static int _NV_getLevel(lua_State* L);
    static int getItemSound(lua_State* L);
    static int isStolen(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int merchantPriceMod(lua_State* L);
    static int activate(lua_State* L);
    static int getStolenItemGUIInfo(lua_State* L);
    static int getBuyBackGUIInfo(lua_State* L);
    static int serialise(lua_State* L);
    static int getTooltipData1(lua_State* L);
    static int _NV_getTooltipData1(lua_State* L);
    static int getTooltipData2(lua_State* L);
    static int _NV_getTooltipData2(lua_State* L);
    static int addQuantity(lua_State* L);
    static int getProperOwner(lua_State* L);
    static int _NV_getProperOwner(lua_State* L);
    static int setProperOwner(lua_State* L);
    static int _NV_setProperOwner(lua_State* L);
    static int getTooltipTradeValue(lua_State* L);
};
}