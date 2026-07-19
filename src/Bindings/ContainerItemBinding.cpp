#include "pch.h"
#include "kenshi\Item.h"
#include "ContainerItemBinding.h"
#include "RootObjectBinding.h"
#include "kenshi/Inventory.h"
#include "InventoryBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/RootObjectBinding.h"

namespace KenshiLua
{

static ContainerItem* getB(lua_State* L, int idx)
{
    return checkObject<ContainerItem>(L, idx, ContainerItemBinding::getMetatableName());
}

// --- Getters for ContainerItem ---
static int ContainerItem_get_callbackOwner(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    return pushObject<RootObject>(L, b->callbackOwner, RootObjectBinding::getMetatableName());
}

static int ContainerItem_get_athleticsMult(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    lua_pushnumber(L, b->athleticsMult);
    return 1;
}

static int ContainerItem_get_weightMult(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    lua_pushnumber(L, b->weightMult);
    return 1;
}

static int ContainerItem_get_combatSpeedMult(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    lua_pushnumber(L, b->combatSpeedMult);
    return 1;
}

static int ContainerItem_get_combatSkillBonus(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    lua_pushinteger(L, b->combatSkillBonus);
    return 1;
}

static int ContainerItem_get_stealthMult(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    lua_pushnumber(L, b->stealthMult);
    return 1;
}

static int ContainerItem_get_racesExclude(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    // TODO: Unsupported type for racesExclude (ogre_unordered_set<GameData*>::type)
    return luaL_error(L, "Unsupported property 'racesExclude' (type: ogre_unordered_set<GameData*>::type)");
}

static int ContainerItem_get_inventory(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    return pushObject<Inventory>(L, b->inventory, InventoryBinding::getMetatableName());
}

// --- Setters for ContainerItem ---
static int ContainerItem_set_callbackOwner(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for callbackOwner");
}

static int ContainerItem_set_athleticsMult(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    b->athleticsMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ContainerItem_set_weightMult(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    b->weightMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ContainerItem_set_combatSpeedMult(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    b->combatSpeedMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ContainerItem_set_combatSkillBonus(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    b->combatSkillBonus = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ContainerItem_set_stealthMult(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    b->stealthMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ContainerItem_set_racesExclude(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for racesExclude");
}

static int ContainerItem_set_inventory(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for inventory");
}

// --- Methods for ContainerItem ---
int ContainerItemBinding::_DESTRUCTOR(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");

    b->_DESTRUCTOR();
    return 0;
}

int ContainerItemBinding::getClassType(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");

    itemType result = b->getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ContainerItemBinding::_NV_getClassType(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");

    itemType result = b->_NV_getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ContainerItemBinding::takeMoney(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");

    int n = (int)luaL_checkinteger(L, 2);
    bool result = b->takeMoney(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ContainerItemBinding::_NV_takeMoney(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");

    int n = (int)luaL_checkinteger(L, 2);
    bool result = b->_NV_takeMoney(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ContainerItemBinding::getMoney(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");

    int result = b->getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int ContainerItemBinding::_NV_getMoney(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");

    int result = b->_NV_getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int ContainerItemBinding::doubleCheckHandle(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");

    b->doubleCheckHandle();
    return 0;
}

int ContainerItemBinding::getPosition(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");

    Ogre::Vector3 result = b->getPosition();
    pushVector3(L, result);
    return 1;
}

int ContainerItemBinding::_NV_getPosition(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");

    Ogre::Vector3 result = b->_NV_getPosition();
    pushVector3(L, result);
    return 1;
}

int ContainerItemBinding::getInventory(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");

    Inventory* result = b->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int ContainerItemBinding::_NV_getInventory(lua_State* L)
{
    ContainerItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContainerItem is nil");

    Inventory* result = b->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 268: bool canEquip(...) - unsupported arg type
  line 269: bool _NV_canEquip(...) - unsupported arg type
  line 270: void equipItem(...) - unsupported arg type
  line 271: void _NV_equipItem(...) - unsupported arg type
  line 272: void unequipItem(...) - unsupported arg type
  line 273: void _NV_unequipItem(...) - unsupported arg type
  line 274: void dropItem(...) - unsupported arg type
  line 275: void _NV_dropItem(...) - unsupported arg type
  line 285: InventoryLayout* createInventoryLayout(...) - unsupported return type
  line 286: InventoryLayout* _NV_createInventoryLayout(...) - unsupported return type
  line 287: void getTooltipData1(...) - unsupported arg type
  line 288: void _NV_getTooltipData1(...) - unsupported arg type
  line 289: void getTooltipData2(...) - unsupported arg type
  line 290: void _NV_getTooltipData2(...) - unsupported arg type
  line 291: GameData* _serialise(...) - unsupported arg type
  line 292: GameData* _NV__serialise(...) - unsupported arg type
  line 293: void _loadFromSerialise(...) - unsupported arg type
  line 294: void _NV__loadFromSerialise(...) - unsupported arg type
  line 295: GameSaveState serialise(...) - unsupported return type
  line 296: GameSaveState _NV_serialise(...) - unsupported return type
  line 297: void loadFromSerialise(...) - unsupported arg type
  line 298: void _NV_loadFromSerialise(...) - unsupported arg type
  line 299: void setProperOwner(...) - unsupported arg type
  line 300: void _NV_setProperOwner(...) - unsupported arg type
  line 310: ContainerItem* _CONSTRUCTOR(...) - unsupported arg type
*/

int ContainerItemBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ContainerItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ContainerItem object");
    return 1;
}

void ContainerItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ContainerItemBinding::gc },
        { "__tostring", ContainerItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ContainerItemBinding::_DESTRUCTOR },
        { "getClassType", ContainerItemBinding::getClassType },
        { "_NV_getClassType", ContainerItemBinding::_NV_getClassType },
        { "takeMoney", ContainerItemBinding::takeMoney },
        { "_NV_takeMoney", ContainerItemBinding::_NV_takeMoney },
        { "getMoney", ContainerItemBinding::getMoney },
        { "_NV_getMoney", ContainerItemBinding::_NV_getMoney },
        { "doubleCheckHandle", ContainerItemBinding::doubleCheckHandle },
        { "getPosition", ContainerItemBinding::getPosition },
        { "_NV_getPosition", ContainerItemBinding::_NV_getPosition },
        { "getInventory", ContainerItemBinding::getInventory },
        { "_NV_getInventory", ContainerItemBinding::_NV_getInventory },
        { 0, 0 }
    };

    registerClass(
        L, 
        ContainerItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ContainerItemBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ContainerItem_get_callbackOwner);
    lua_setfield(L, -2, "callbackOwner");
    lua_pushcfunction(L, ContainerItem_get_athleticsMult);
    lua_setfield(L, -2, "athleticsMult");
    lua_pushcfunction(L, ContainerItem_get_weightMult);
    lua_setfield(L, -2, "weightMult");
    lua_pushcfunction(L, ContainerItem_get_combatSpeedMult);
    lua_setfield(L, -2, "combatSpeedMult");
    lua_pushcfunction(L, ContainerItem_get_combatSkillBonus);
    lua_setfield(L, -2, "combatSkillBonus");
    lua_pushcfunction(L, ContainerItem_get_stealthMult);
    lua_setfield(L, -2, "stealthMult");
    lua_pushcfunction(L, ContainerItem_get_racesExclude);
    lua_setfield(L, -2, "racesExclude");
    lua_pushcfunction(L, ContainerItem_get_inventory);
    lua_setfield(L, -2, "inventory");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ContainerItem_set_callbackOwner);
    lua_setfield(L, -2, "callbackOwner");
    lua_pushcfunction(L, ContainerItem_set_athleticsMult);
    lua_setfield(L, -2, "athleticsMult");
    lua_pushcfunction(L, ContainerItem_set_weightMult);
    lua_setfield(L, -2, "weightMult");
    lua_pushcfunction(L, ContainerItem_set_combatSpeedMult);
    lua_setfield(L, -2, "combatSpeedMult");
    lua_pushcfunction(L, ContainerItem_set_combatSkillBonus);
    lua_setfield(L, -2, "combatSkillBonus");
    lua_pushcfunction(L, ContainerItem_set_stealthMult);
    lua_setfield(L, -2, "stealthMult");
    lua_pushcfunction(L, ContainerItem_set_racesExclude);
    lua_setfield(L, -2, "racesExclude");
    lua_pushcfunction(L, ContainerItem_set_inventory);
    lua_setfield(L, -2, "inventory");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
