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
    static int getAvgPrice(lua_State* L);
    static int getValueSingle(lua_State* L);
    static int _NV_getValueSingle(lua_State* L);
    static int getValueAll(lua_State* L);
    static int _NV_getValueAll(lua_State* L);
    static int getMaxAffordableNum(lua_State* L);
    static int _NV_getMaxAffordableNum(lua_State* L);
    static int getInventory(lua_State* L);
    static int _NV_getInventory(lua_State* L);
    static int onGround(lua_State* L);
    static int isResearchArtifact(lua_State* L);
    static int getLevel(lua_State* L);
    static int _NV_getLevel(lua_State* L);
    static int getItemSound(lua_State* L);
    static int isStolen(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int merchantPriceMod(lua_State* L);
};
}
