#include "pch.h"
#include "kenshi\Item.h"
#include "ContainerItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/RaceLimiterBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "InventoryBinding.h"
#include "RootObjectBinding.h"
#include "kenshi/Inventory.h"

namespace KenshiLua
{

static ContainerItem* getInstance(lua_State* L, int idx)
{
    return checkObject<ContainerItem>(L, idx, ContainerItemBinding::getMetatableName());
}

// --- Getters for ContainerItem ---
static int ContainerItem_get_callbackOwner(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    return pushObject<RootObject>(L, instance->callbackOwner, RootObjectBinding::getMetatableName());
}

static int ContainerItem_get_athleticsMult(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    lua_pushnumber(L, instance->athleticsMult);
    return 1;
}

static int ContainerItem_get_weightMult(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    lua_pushnumber(L, instance->weightMult);
    return 1;
}

static int ContainerItem_get_combatSpeedMult(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    lua_pushnumber(L, instance->combatSpeedMult);
    return 1;
}

static int ContainerItem_get_combatSkillBonus(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    lua_pushinteger(L, instance->combatSkillBonus);
    return 1;
}

static int ContainerItem_get_stealthMult(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    lua_pushnumber(L, instance->stealthMult);
    return 1;
}

static int ContainerItem_get_inventory(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    return pushObject<Inventory>(L, instance->inventory, InventoryBinding::getMetatableName());
}

// --- Setters for ContainerItem ---
static int ContainerItem_set_callbackOwner(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    instance->callbackOwner = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    return 0;
}

static int ContainerItem_set_athleticsMult(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    instance->athleticsMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ContainerItem_set_weightMult(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    instance->weightMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ContainerItem_set_combatSpeedMult(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    instance->combatSpeedMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ContainerItem_set_combatSkillBonus(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    instance->combatSkillBonus = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ContainerItem_set_stealthMult(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    instance->stealthMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ContainerItem_set_inventory(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    instance->inventory = lua_isnoneornil(L, 2) ? nullptr : checkObject<Inventory>(L, 2, InventoryBinding::getMetatableName());
    return 0;
}

int ContainerItemBinding::_DESTRUCTOR(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ContainerItemBinding::getClassType(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    itemType result = instance->getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ContainerItemBinding::_NV_getClassType(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    itemType result = instance->_NV_getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ContainerItemBinding::canEquip(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    GameData* race = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->canEquip(race);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ContainerItemBinding::_NV_canEquip(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    GameData* race = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->_NV_canEquip(race);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ContainerItemBinding::equipItem(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    const std::string what = luaL_checkstring(L, 2);
    Item* who = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->equipItem(what, who);
    return 0;
}

int ContainerItemBinding::_NV_equipItem(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    const std::string what = luaL_checkstring(L, 2);
    Item* who = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->_NV_equipItem(what, who);
    return 0;
}

int ContainerItemBinding::unequipItem(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    const std::string what = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->unequipItem(what, item);
    return 0;
}

int ContainerItemBinding::_NV_unequipItem(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    const std::string what = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->_NV_unequipItem(what, item);
    return 0;
}

int ContainerItemBinding::dropItem(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    RootObject* what = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->dropItem(what);
    return 0;
}

int ContainerItemBinding::_NV_dropItem(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    RootObject* what = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->_NV_dropItem(what);
    return 0;
}

int ContainerItemBinding::takeMoney(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    int n = (int)luaL_checkinteger(L, 2);
    bool result = instance->takeMoney(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ContainerItemBinding::_NV_takeMoney(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    int n = (int)luaL_checkinteger(L, 2);
    bool result = instance->_NV_takeMoney(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ContainerItemBinding::getMoney(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    int result = instance->getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int ContainerItemBinding::_NV_getMoney(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    int result = instance->_NV_getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int ContainerItemBinding::doubleCheckHandle(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    instance->doubleCheckHandle();
    return 0;
}

int ContainerItemBinding::getPosition(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    Ogre::Vector3 result = instance->getPosition();
    pushVector3(L, result);
    return 1;
}

int ContainerItemBinding::_NV_getPosition(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    Ogre::Vector3 result = instance->_NV_getPosition();
    pushVector3(L, result);
    return 1;
}

int ContainerItemBinding::getInventory(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    Inventory* result = instance->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int ContainerItemBinding::_NV_getInventory(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    Inventory* result = instance->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int ContainerItemBinding::createInventoryLayout(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    InventoryLayout* result = instance->createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

int ContainerItemBinding::_NV_createInventoryLayout(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    InventoryLayout* result = instance->_NV_createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

int ContainerItemBinding::_serialise(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    GameData* result = instance->_serialise(container, type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int ContainerItemBinding::_NV__serialise(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    GameData* result = instance->_NV__serialise(container, type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int ContainerItemBinding::_loadFromSerialise(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_loadFromSerialise(container, state);
    return 0;
}

int ContainerItemBinding::_NV__loadFromSerialise(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_NV__loadFromSerialise(container, state);
    return 0;
}

int ContainerItemBinding::loadFromSerialise(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(state);
    return 0;
}

int ContainerItemBinding::_NV_loadFromSerialise(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(state);
    return 0;
}

int ContainerItemBinding::_CONSTRUCTOR(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");

    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* mat = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    hand _handle = *checkObject<hand>(L, 4, handBinding::getMetatableName());
    ContainerItem* result = instance->_CONSTRUCTOR(dat, mat, _handle);
    return pushObject<ContainerItem>(L, result, ContainerItemBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 287: void getTooltipData1(...) - unsupported arg type
  line 288: void _NV_getTooltipData1(...) - unsupported arg type
  line 289: void getTooltipData2(...) - unsupported arg type
  line 290: void _NV_getTooltipData2(...) - unsupported arg type
  line 295: GameSaveState serialise(...) - unsupported arg type
  line 296: GameSaveState _NV_serialise(...) - unsupported arg type
  line 299: void setProperOwner(...) - non-string reference arg
  line 300: void _NV_setProperOwner(...) - non-string reference arg
*/

/*
Skipped properties needing manual binding:
  line 307: racesExclude (ogre_unordered_set<GameData*>::type) - unsupported type
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



static int ContainerItem_get_racesExclude(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    // TODO: Unsupported type for racesExclude (ogre_unordered_set<GameData*>::type)
    return luaL_error(L, "Unsupported property 'racesExclude' (type: ogre_unordered_set<GameData*>::type)");
}


static int ContainerItem_set_racesExclude(lua_State* L)
{
    ContainerItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContainerItem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for racesExclude");
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
        { "canEquip", ContainerItemBinding::canEquip },
        { "_NV_canEquip", ContainerItemBinding::_NV_canEquip },
        { "equipItem", ContainerItemBinding::equipItem },
        { "_NV_equipItem", ContainerItemBinding::_NV_equipItem },
        { "unequipItem", ContainerItemBinding::unequipItem },
        { "_NV_unequipItem", ContainerItemBinding::_NV_unequipItem },
        { "dropItem", ContainerItemBinding::dropItem },
        { "_NV_dropItem", ContainerItemBinding::_NV_dropItem },
        { "takeMoney", ContainerItemBinding::takeMoney },
        { "_NV_takeMoney", ContainerItemBinding::_NV_takeMoney },
        { "getMoney", ContainerItemBinding::getMoney },
        { "_NV_getMoney", ContainerItemBinding::_NV_getMoney },
        { "doubleCheckHandle", ContainerItemBinding::doubleCheckHandle },
        { "getPosition", ContainerItemBinding::getPosition },
        { "_NV_getPosition", ContainerItemBinding::_NV_getPosition },
        { "getInventory", ContainerItemBinding::getInventory },
        { "_NV_getInventory", ContainerItemBinding::_NV_getInventory },
        { "createInventoryLayout", ContainerItemBinding::createInventoryLayout },
        { "_NV_createInventoryLayout", ContainerItemBinding::_NV_createInventoryLayout },
        { "_serialise", ContainerItemBinding::_serialise },
        { "_NV__serialise", ContainerItemBinding::_NV__serialise },
        { "_loadFromSerialise", ContainerItemBinding::_loadFromSerialise },
        { "_NV__loadFromSerialise", ContainerItemBinding::_NV__loadFromSerialise },
        { "loadFromSerialise", ContainerItemBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", ContainerItemBinding::_NV_loadFromSerialise },
        { "_CONSTRUCTOR", ContainerItemBinding::_CONSTRUCTOR },
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
    registerGetter(L, "callbackOwner", ContainerItem_get_callbackOwner);
    registerGetter(L, "athleticsMult", ContainerItem_get_athleticsMult);
    registerGetter(L, "weightMult", ContainerItem_get_weightMult);
    registerGetter(L, "combatSpeedMult", ContainerItem_get_combatSpeedMult);
    registerGetter(L, "combatSkillBonus", ContainerItem_get_combatSkillBonus);
    registerGetter(L, "stealthMult", ContainerItem_get_stealthMult);
    registerGetter(L, "inventory", ContainerItem_get_inventory);
    registerGetter(L, "racesExclude", ContainerItem_get_racesExclude);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "callbackOwner", ContainerItem_set_callbackOwner);
    registerSetter(L, "athleticsMult", ContainerItem_set_athleticsMult);
    registerSetter(L, "weightMult", ContainerItem_set_weightMult);
    registerSetter(L, "combatSpeedMult", ContainerItem_set_combatSpeedMult);
    registerSetter(L, "combatSkillBonus", ContainerItem_set_combatSkillBonus);
    registerSetter(L, "stealthMult", ContainerItem_set_stealthMult);
    registerSetter(L, "inventory", ContainerItem_set_inventory);
    registerSetter(L, "racesExclude", ContainerItem_set_racesExclude);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Item
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ContainerItemBinding::getMetatableName(), ItemBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua