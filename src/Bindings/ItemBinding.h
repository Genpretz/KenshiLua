#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Item"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isGear(lua_State* L);
    static int _NV_isGear(lua_State* L);
    static int getClassType(lua_State* L);
    static int _NV_getClassType(lua_State* L);
    static int resetAfterCopy(lua_State* L);
    static int _NV_resetAfterCopy(lua_State* L);
    static int deactivate(lua_State* L);
    static int _NV_deactivate(lua_State* L);
    static int setPositionRotation(lua_State* L);
    static int _NV_setPositionRotation(lua_State* L);
    static int isCrossbow(lua_State* L);
    static int _NV_isCrossbow(lua_State* L);
    static int isArmour(lua_State* L);
    static int _NV_isArmour(lua_State* L);
    static int isWeapon(lua_State* L);
    static int _NV_isWeapon(lua_State* L);
    static int isLockedArmour(lua_State* L);
    static int _NV_isLockedArmour(lua_State* L);
    static int isAFactionUniform(lua_State* L);
    static int _NV_isAFactionUniform(lua_State* L);
    static int isPhysical(lua_State* L);
    static int _NV_isPhysical(lua_State* L);
    static int setVisible(lua_State* L);
    static int _NV_setVisible(lua_State* L);
    static int getVisible(lua_State* L);
    static int _NV_getVisible(lua_State* L);
    static int getModelName(lua_State* L);
    static int _NV_getModelName(lua_State* L);
    static int getInventory(lua_State* L);
    static int _NV_getInventory(lua_State* L);
    static int hasIngredients(lua_State* L);
    static int _NV_hasIngredients(lua_State* L);
    static int isGoodFood(lua_State* L);
    static int _NV_isGoodFood(lua_State* L);
    static int getCraftTime(lua_State* L);
    static int _NV_getCraftTime(lua_State* L);
    static int getCraftMaterialMult(lua_State* L);
    static int _NV_getCraftMaterialMult(lua_State* L);
    static int getLevel(lua_State* L);
    static int _NV_getLevel(lua_State* L);
    static int destroyItemEntityCallback_Equipping(lua_State* L);
    static int _NV_destroyItemEntityCallback_Equipping(lua_State* L);
    static int isPersistant(lua_State* L);
    static int persistantOwnerExists(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int createPhysical(lua_State* L);
    static int _NV_createPhysical(lua_State* L);
    static int destroyPhysical(lua_State* L);
    static int _NV_destroyPhysical(lua_State* L);
    static int loadUnloadCheck(lua_State* L);
    static int _NV_loadUnloadCheck(lua_State* L);
	static int getInventoryWeAreIn(lua_State* L);
	static int setInventoryWeAreIn(lua_State* L);
	static int _NV_setInventoryWeAreIn(lua_State* L);

    static int isFood(lua_State* L);
    static int activate(lua_State* L);
    static int _NV_activate(lua_State* L);
    static int getEntity(lua_State* L);
    static int _NV_getEntity(lua_State* L);
    static int getTimeout(lua_State* L);
    static int _NV_getTimeout(lua_State* L);
    static int _serialise(lua_State* L);
    static int _NV__serialise(lua_State* L);
    static int _loadFromSerialise(lua_State* L);
    static int _NV__loadFromSerialise(lua_State* L);
    static int serialise(lua_State* L);
    static int _NV_serialise(lua_State* L);
    static int loadFromSerialise(lua_State* L);
    static int _NV_loadFromSerialise(lua_State* L);
    static int serialiseInInventory(lua_State* L);
    static int _NV_serialiseInInventory(lua_State* L);
    static int loadFromSerialiseInInventory(lua_State* L);
    static int _NV_loadFromSerialiseInInventory(lua_State* L);
    static int createItemEntityCallback_Equipping(lua_State* L);
    static int _NV_createItemEntityCallback_Equipping(lua_State* L);
    static int notifyTheftFrom(lua_State* L);
    static int _NV_notifyTheftFrom(lua_State* L);
    static int findProperOwner(lua_State* L);
    static int setPersistant(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int itemEntityCreated(lua_State* L);
    static int _NV_itemEntityCreated(lua_State* L);
};
}
