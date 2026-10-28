#include "pch.h"
#include "kenshi/Item.h"
#include "MapItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/GameDataContainerBinding.h"

namespace KenshiLua
{

static_assert(offsetof(MapItem, value) == 0x1E8, "MapItem::value offset mismatch");
static_assert(offsetof(MapItem, townsDiscoveredCount) == 0x1EC, "MapItem::townsDiscoveredCount offset mismatch");

static MapItem* getInstance(lua_State* L, int idx)
{
    return checkObject<MapItem>(L, idx, MapItemBinding::getMetatableName());
}

static int MapItem_get_value(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    lua_pushinteger(L, instance->value);
    return 1;
}

static int MapItem_set_value(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    instance->value = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int MapItem_get_townsDiscoveredCount(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    lua_pushinteger(L, instance->townsDiscoveredCount);
    return 1;
}

static int MapItem_set_townsDiscoveredCount(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    instance->townsDiscoveredCount = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

int MapItemBinding::getItemWeight(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    lua_pushnumber(L, (lua_Number)instance->getItemWeight());
    return 1;
}

int MapItemBinding::_NV_getItemWeight(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    lua_pushnumber(L, (lua_Number)instance->_NV_getItemWeight());
    return 1;
}

int MapItemBinding::getValueSingle(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    bool isPlayer = lua_toboolean(L, 2) != 0;
    lua_pushinteger(L, (lua_Integer)instance->getValueSingle(isPlayer));
    return 1;
}

int MapItemBinding::_NV_getValueSingle(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    bool isPlayer = lua_toboolean(L, 2) != 0;
    lua_pushinteger(L, (lua_Integer)instance->_NV_getValueSingle(isPlayer));
    return 1;
}

int MapItemBinding::selectTowns(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    int res = instance->selectTowns();
    lua_pushinteger(L, res);
    return 1;
}

int MapItemBinding::consume(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    bool res = instance->consume();
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int MapItemBinding::getTownsDiscovered(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    int res = instance->getTownsDiscovered();
    lua_pushinteger(L, res);
    return 1;
}

int MapItemBinding::_loadFromSerialise(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_loadFromSerialise(container, state);
    return 0;
}

int MapItemBinding::_NV__loadFromSerialise(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_NV__loadFromSerialise(container, state);
    return 0;
}

int MapItemBinding::_serialise(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType typ = (itemType)luaL_checkinteger(L, 3);
    GameData* res = instance->_serialise(container, typ);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}

int MapItemBinding::_NV__serialise(lua_State* L)
{
    MapItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapItem is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType typ = (itemType)luaL_checkinteger(L, 3);
    GameData* res = instance->_NV__serialise(container, typ);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}

int MapItemBinding::gc(lua_State* L)
{
    return 0;
}

int MapItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MapItem object");
    return 1;
}

void MapItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MapItemBinding::gc },
        { "__tostring", MapItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getItemWeight", MapItemBinding::getItemWeight },
        { "_NV_getItemWeight", MapItemBinding::_NV_getItemWeight },
        { "getValueSingle", MapItemBinding::getValueSingle },
        { "_NV_getValueSingle", MapItemBinding::_NV_getValueSingle },
        { "selectTowns", MapItemBinding::selectTowns },
        { "consume", MapItemBinding::consume },
        { "getTownsDiscovered", MapItemBinding::getTownsDiscovered },
        { "_loadFromSerialise", MapItemBinding::_loadFromSerialise },
        { "_NV__loadFromSerialise", MapItemBinding::_NV__loadFromSerialise },
        { "_serialise", MapItemBinding::_serialise },
        { "_NV__serialise", MapItemBinding::_NV__serialise },
        { 0, 0 }
    };

    registerClass(
        L, 
        MapItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MapItemBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "value", MapItem_get_value);
    registerGetter(L, "townsDiscoveredCount", MapItem_get_townsDiscoveredCount);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "value", MapItem_set_value);
    registerSetter(L, "townsDiscoveredCount", MapItem_set_townsDiscoveredCount);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
