#include "pch.h"
#include "Bindings/ShopTraderBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/InventoryBinding.h"

#include "Lua/BindingHelpers.h"

#include <kenshi/ShopTrader.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static ShopTrader* getS(lua_State* L, int idx)
{
    return checkObject<ShopTrader>(L, idx, ShopTraderBinding::getMetatableName());
}

int ShopTraderBinding::gc(lua_State* L) { return noopGc(L); }

int ShopTraderBinding::tostring(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int ShopTraderBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, ShopTraderBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    ShopTrader* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "trader") == 0) { return pushObject<Character>(L, s->trader, CharacterBinding::getMetatableName()); }
    if (strcmp(key, "inventory") == 0) { return pushObject<Inventory>(L, s->inventory, InventoryBinding::getMetatableName()); }

    lua_pushnil(L);
    return 1;
}

int ShopTraderBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    // TODO Character* trader; unsupported __newindex type from header line 53
    // TODO Inventory* inventory; unsupported __newindex type from header line 54

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int ShopTraderBinding::_DESTRUCTOR(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    s->_DESTRUCTOR();
    return 0;
}

int ShopTraderBinding::getInventory(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    Inventory* result = s->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int ShopTraderBinding::_NV_getInventory(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    Inventory* result = s->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int ShopTraderBinding::takeMoney(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    int money = (int)luaL_checkinteger(L, 2);
    bool result = s->takeMoney(money);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderBinding::_NV_takeMoney(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    int money = (int)luaL_checkinteger(L, 2);
    bool result = s->_NV_takeMoney(money);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderBinding::getMoney(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    int result = s->getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int ShopTraderBinding::_NV_getMoney(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    int result = s->_NV_getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int ShopTraderBinding::getFloor(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    int result = s->getFloor();
    lua_pushinteger(L, result);
    return 1;
}

int ShopTraderBinding::_NV_getFloor(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    int result = s->_NV_getFloor();
    lua_pushinteger(L, result);
    return 1;
}

int ShopTraderBinding::getTrader(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    Character* result = s->getTrader();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int ShopTraderBinding::isPhysical(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    bool result = s->isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderBinding::_NV_isPhysical(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    bool result = s->_NV_isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderBinding::setVisible(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->setVisible(on);
    return 0;
}

int ShopTraderBinding::_NV_setVisible(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->_NV_setVisible(on);
    return 0;
}

int ShopTraderBinding::createPhysical(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    bool result = s->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderBinding::_NV_createPhysical(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    bool result = s->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderBinding::destroyPhysical(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    s->destroyPhysical();
    return 0;
}

int ShopTraderBinding::_NV_destroyPhysical(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    s->_NV_destroyPhysical();
    return 0;
}

int ShopTraderBinding::updateInventory(lua_State* L)
{
    ShopTrader* s = getS(L, 1);
    if (!s) return luaL_error(L, "ShopTrader is nil");

    s->updateInventory();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 12: ShopTrader* _CONSTRUCTOR(...) - unsupported arg type
  line 15: void getGUIData(...) - unsupported arg type
  line 16: void _NV_getGUIData(...) - unsupported arg type
  line 17: void equipItem(...) - unsupported arg type
  line 18: void _NV_equipItem(...) - unsupported arg type
  line 19: void unequipItem(...) - unsupported arg type
  line 20: void _NV_unequipItem(...) - unsupported arg type
  line 27: Ogre::Quaternion getOrientation(...) - unsupported return type
  line 28: Ogre::Quaternion _NV_getOrientation(...) - unsupported return type
  line 29: Ogre::Vector3 getPosition(...) - unsupported return type
  line 30: Ogre::Vector3 _NV_getPosition(...) - unsupported return type
  line 31: const hand& isIndoors(...) - reference return type
  line 32: const hand& _NV_isIndoors(...) - reference return type
  line 35: TownBase* getCurrentTownLocation(...) - unsupported return type
  line 36: TownBase* _NV_getCurrentTownLocation(...) - unsupported return type
  line 37: itemType getDataType(...) - unsupported return type
  line 38: itemType _NV_getDataType(...) - unsupported return type
  line 39: GameSaveState serialise(...) - unsupported return type
  line 40: GameSaveState _NV_serialise(...) - unsupported return type
  line 41: void loadFromSerialise(...) - unsupported arg type
  line 42: void _NV_loadFromSerialise(...) - unsupported arg type
*/

void ShopTraderBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ShopTraderBinding::gc },
        { "__tostring", ShopTraderBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ShopTraderBinding::_DESTRUCTOR },
        { "getInventory", ShopTraderBinding::getInventory },
        { "_NV_getInventory", ShopTraderBinding::_NV_getInventory },
        { "takeMoney", ShopTraderBinding::takeMoney },
        { "_NV_takeMoney", ShopTraderBinding::_NV_takeMoney },
        { "getMoney", ShopTraderBinding::getMoney },
        { "_NV_getMoney", ShopTraderBinding::_NV_getMoney },
        { "getFloor", ShopTraderBinding::getFloor },
        { "_NV_getFloor", ShopTraderBinding::_NV_getFloor },
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
        { 0, 0 }
    };
    registerClass(L, ShopTraderBinding::getMetatableName(), meta, methods, ShopTraderBinding::index, ShopTraderBinding::newindex);
}

} // namespace KenshiLua