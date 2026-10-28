#include "pch.h"
#include "kenshi/Item.h"
#include "MoneyItemBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MoneyItem* getInstance(lua_State* L, int idx)
{
    return checkObject<MoneyItem>(L, idx, MoneyItemBinding::getMetatableName());
}

int MoneyItemBinding::getValueSingle(lua_State* L)
{
    MoneyItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MoneyItem is nil");
    bool isPlayer = lua_toboolean(L, 2) != 0;
    lua_pushinteger(L, (lua_Integer)instance->getValueSingle(isPlayer));
    return 1;
}

int MoneyItemBinding::_NV_getValueSingle(lua_State* L)
{
    MoneyItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MoneyItem is nil");
    bool isPlayer = lua_toboolean(L, 2) != 0;
    lua_pushinteger(L, (lua_Integer)instance->_NV_getValueSingle(isPlayer));
    return 1;
}

int MoneyItemBinding::consume(lua_State* L)
{
    MoneyItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MoneyItem is nil");
    bool res = instance->consume();
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int MoneyItemBinding::gc(lua_State* L)
{
    return 0;
}

int MoneyItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MoneyItem object");
    return 1;
}

void MoneyItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MoneyItemBinding::gc },
        { "__tostring", MoneyItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getValueSingle", MoneyItemBinding::getValueSingle },
        { "_NV_getValueSingle", MoneyItemBinding::_NV_getValueSingle },
        { "consume", MoneyItemBinding::consume },
        { 0, 0 }
    };

    registerClass(
        L, 
        MoneyItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MoneyItemBinding::getMetatableName());
    lua_newtable(L);
    lua_setfield(L, -2, "__getters");
    lua_newtable(L);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);
}

} // namespace KenshiLua
