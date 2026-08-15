#include "pch.h"
#include "kenshi\ShopTrader.h"
#include "kenshi\GameSaveState.h"
#include "ShopTraderBinding.h"
#include "CharacterBinding.h"
#include "InventoryBinding.h"
#include "ItemBinding.h"
#include "TownBaseBinding.h"
#include "RootObjectBinding.h"
#include "GameDataContainerBinding.h"
#include "GameDataBinding.h"
#include "GameSaveStateBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ShopTrader* getInstance(lua_State* L, int idx)
{
    return checkObject<ShopTrader>(L, idx, ShopTraderBinding::getMetatableName());
}

// --- Getters for ShopTrader ---
static int ShopTrader_get_trader(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    return pushObject<Character>(L, instance->trader, CharacterBinding::getMetatableName());
}

static int ShopTrader_get_inventory(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    return pushObject<Inventory>(L, instance->inventory, InventoryBinding::getMetatableName());
}

// --- Setters for ShopTrader ---
static int ShopTrader_set_trader(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    instance->trader = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int ShopTrader_set_inventory(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    instance->inventory = lua_isnoneornil(L, 2) ? nullptr : checkObject<Inventory>(L, 2, InventoryBinding::getMetatableName());
    return 0;
}

int ShopTraderBinding::getInventory(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    Inventory* result = instance->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int ShopTraderBinding::_NV_getInventory(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    Inventory* result = instance->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int ShopTraderBinding::takeMoney(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    int money = (int)luaL_checkinteger(L, 2);
    bool result = instance->takeMoney(money);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderBinding::_NV_takeMoney(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    int money = (int)luaL_checkinteger(L, 2);
    bool result = instance->_NV_takeMoney(money);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderBinding::getMoney(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    int result = instance->getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int ShopTraderBinding::_NV_getMoney(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    int result = instance->_NV_getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int ShopTraderBinding::getOrientation(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    Ogre::Quaternion result = instance->getOrientation();
    pushQuaternion(L, result);
    return 1;
}

int ShopTraderBinding::_NV_getOrientation(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    Ogre::Quaternion result = instance->_NV_getOrientation();
    pushQuaternion(L, result);
    return 1;
}

int ShopTraderBinding::getPosition(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    Ogre::Vector3 result = instance->getPosition();
    pushVector3(L, result);
    return 1;
}

int ShopTraderBinding::_NV_getPosition(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    Ogre::Vector3 result = instance->_NV_getPosition();
    pushVector3(L, result);
    return 1;
}

int ShopTraderBinding::getFloor(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    int result = instance->getFloor();
    lua_pushinteger(L, result);
    return 1;
}

int ShopTraderBinding::_NV_getFloor(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    int result = instance->_NV_getFloor();
    lua_pushinteger(L, result);
    return 1;
}

int ShopTraderBinding::getCurrentTownLocation(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    TownBase* result = instance->getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int ShopTraderBinding::_NV_getCurrentTownLocation(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    TownBase* result = instance->_NV_getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int ShopTraderBinding::getDataType(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    itemType result = instance->getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ShopTraderBinding::_NV_getDataType(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    itemType result = instance->_NV_getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ShopTraderBinding::getTrader(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    Character* result = instance->getTrader();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int ShopTraderBinding::isPhysical(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    bool result = instance->isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderBinding::_NV_isPhysical(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    bool result = instance->_NV_isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderBinding::setVisible(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setVisible(on);
    return 0;
}

int ShopTraderBinding::_NV_setVisible(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(on);
    return 0;
}

int ShopTraderBinding::createPhysical(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    bool result = instance->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderBinding::_NV_createPhysical(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    bool result = instance->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderBinding::destroyPhysical(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    instance->destroyPhysical();
    return 0;
}

int ShopTraderBinding::_NV_destroyPhysical(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    instance->_NV_destroyPhysical();
    return 0;
}

int ShopTraderBinding::updateInventory(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");

    instance->updateInventory();
    return 0;
}

int ShopTraderBinding::equipItem(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    std::string sectionName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->equipItem(sectionName, item);
    return 0;
}

int ShopTraderBinding::_NV_equipItem(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    std::string sectionName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->_NV_equipItem(sectionName, item);
    return 0;
}

int ShopTraderBinding::unequipItem(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    std::string sectionName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->unequipItem(sectionName, item);
    return 0;
}

int ShopTraderBinding::_NV_unequipItem(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    std::string sectionName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->_NV_unequipItem(sectionName, item);
    return 0;
}

int ShopTraderBinding::getGUIData(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(datapanel, category);
    return 0;
}

int ShopTraderBinding::_NV_getGUIData(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIData(datapanel, category);
    return 0;
}

int ShopTraderBinding::isIndoors(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    return HandBinding::push(L, instance->isIndoors());
}

int ShopTraderBinding::_NV_isIndoors(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    return HandBinding::push(L, instance->_NV_isIndoors());
}

int ShopTraderBinding::serialise(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offsetPosToSubtract = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState result = instance->serialise(container, refList, offsetPosToSubtract);
    return pushValue<GameSaveState>(L, result, GameSaveStateBinding::getMetatableName());
}

int ShopTraderBinding::_NV_serialise(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offsetPosToSubtract = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState result = instance->_NV_serialise(container, refList, offsetPosToSubtract);
    return pushValue<GameSaveState>(L, result, GameSaveStateBinding::getMetatableName());
}

int ShopTraderBinding::loadFromSerialise(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(state);
    return 0;
}

int ShopTraderBinding::_NV_loadFromSerialise(lua_State* L)
{
    ShopTrader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTrader is nil");
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(state);
    return 0;
}

int ShopTraderBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ShopTraderBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ShopTrader object");
    return 1;
}

void ShopTraderBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ShopTraderBinding::gc },
        { "__tostring", ShopTraderBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getGUIData", ShopTraderBinding::getGUIData },
        { "_NV_getGUIData", ShopTraderBinding::_NV_getGUIData },
        { "getInventory", ShopTraderBinding::getInventory },
        { "_NV_getInventory", ShopTraderBinding::_NV_getInventory },
        { "takeMoney", ShopTraderBinding::takeMoney },
        { "_NV_takeMoney", ShopTraderBinding::_NV_takeMoney },
        { "getMoney", ShopTraderBinding::getMoney },
        { "_NV_getMoney", ShopTraderBinding::_NV_getMoney },
        { "getOrientation", ShopTraderBinding::getOrientation },
        { "_NV_getOrientation", ShopTraderBinding::_NV_getOrientation },
        { "getPosition", ShopTraderBinding::getPosition },
        { "_NV_getPosition", ShopTraderBinding::_NV_getPosition },
        { "isIndoors", ShopTraderBinding::isIndoors },
        { "_NV_isIndoors", ShopTraderBinding::_NV_isIndoors },
        { "getFloor", ShopTraderBinding::getFloor },
        { "_NV_getFloor", ShopTraderBinding::_NV_getFloor },
        { "getCurrentTownLocation", ShopTraderBinding::getCurrentTownLocation },
        { "_NV_getCurrentTownLocation", ShopTraderBinding::_NV_getCurrentTownLocation },
        { "getDataType", ShopTraderBinding::getDataType },
        { "_NV_getDataType", ShopTraderBinding::_NV_getDataType },
        { "serialise", ShopTraderBinding::serialise },
        { "_NV_serialise", ShopTraderBinding::_NV_serialise },
        { "loadFromSerialise", ShopTraderBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", ShopTraderBinding::_NV_loadFromSerialise },
        { "getTrader", ShopTraderBinding::getTrader },
        { "isPhysical", ShopTraderBinding::isPhysical },
        { "_NV_isPhysical", ShopTraderBinding::_NV_isPhysical },
        { "setVisible", ShopTraderBinding::setVisible },
        { "_NV_setVisible", ShopTraderBinding::_NV_setVisible },
        { "createPhysical", ShopTraderBinding::createPhysical },
        { "_NV_createPhysical", ShopTraderBinding::_NV_createPhysical },
        { "destroyPhysical", ShopTraderBinding::destroyPhysical },
        { "_NV_destroyPhysical", ShopTraderBinding::_NV_destroyPhysical },
        { "updateInventory", ShopTraderBinding::updateInventory },
        { "equipItem", ShopTraderBinding::equipItem },
        { "_NV_equipItem", ShopTraderBinding::_NV_equipItem },
        { "unequipItem", ShopTraderBinding::unequipItem },
        { "_NV_unequipItem", ShopTraderBinding::_NV_unequipItem },
        { 0, 0 }
    };

    registerClass(
        L, 
        ShopTraderBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ShopTraderBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ShopTrader_get_trader);
    lua_setfield(L, -2, "trader");
    lua_pushcfunction(L, ShopTrader_get_inventory);
    lua_setfield(L, -2, "inventory");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ShopTrader_set_trader);
    lua_setfield(L, -2, "trader");
    lua_pushcfunction(L, ShopTrader_set_inventory);
    lua_setfield(L, -2, "inventory");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to RootObject
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ShopTraderBinding::getMetatableName(), RootObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
