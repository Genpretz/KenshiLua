#include "pch.h"
#include "kenshi/Item.h"
#include "NestItemBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static NestItem* getInstance(lua_State* L, int idx)
{
    return checkObject<NestItem>(L, idx, NestItemBinding::getMetatableName());
}

int NestItemBinding::getClassType(lua_State* L)
{
    NestItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NestItem is nil");
    lua_pushinteger(L, (lua_Integer)instance->getClassType());
    return 1;
}

int NestItemBinding::_NV_getClassType(lua_State* L)
{
    NestItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NestItem is nil");
    lua_pushinteger(L, (lua_Integer)instance->_NV_getClassType());
    return 1;
}

int NestItemBinding::getModelName(lua_State* L)
{
    NestItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NestItem is nil");
    std::string res = instance->getModelName();
    lua_pushstring(L, res.c_str());
    return 1;
}

int NestItemBinding::_NV_getModelName(lua_State* L)
{
    NestItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NestItem is nil");
    std::string res = instance->_NV_getModelName();
    lua_pushstring(L, res.c_str());
    return 1;
}

int NestItemBinding::gc(lua_State* L)
{
    return 0;
}

int NestItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NestItem object");
    return 1;
}

void NestItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       NestItemBinding::gc },
        { "__tostring", NestItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getClassType", NestItemBinding::getClassType },
        { "_NV_getClassType", NestItemBinding::_NV_getClassType },
        { "getModelName", NestItemBinding::getModelName },
        { "_NV_getModelName", NestItemBinding::_NV_getModelName },
        { 0, 0 }
    };

    registerClass(
        L, 
        NestItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, NestItemBinding::getMetatableName());
    lua_newtable(L);
    lua_setfield(L, -2, "__getters");
    lua_newtable(L);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);
}

} // namespace KenshiLua
