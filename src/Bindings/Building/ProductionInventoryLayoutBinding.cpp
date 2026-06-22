#include "pch.h"
#include "Bindings/Building/ProductionInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/ProductionBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static ProductionInventoryLayout* getS(lua_State* L, int idx)
{
    return checkObject<ProductionInventoryLayout>(L, idx, ProductionInventoryLayoutBinding::getMetatableName());
}

int ProductionInventoryLayoutBinding::gc(lua_State* L) { return noopGc(L); }

int ProductionInventoryLayoutBinding::tostring(lua_State* L)
{
    ProductionInventoryLayout* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int ProductionInventoryLayoutBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, ProductionInventoryLayoutBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    ProductionInventoryLayout* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }


    lua_pushnil(L);
    return 1;
}

int ProductionInventoryLayoutBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    ProductionInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionInventoryLayout is nil");


    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int ProductionInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    ProductionInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionInventoryLayout is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 51: ProductionInventoryLayout* _CONSTRUCTOR(...) - unsupported return type
*/

void ProductionInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ProductionInventoryLayoutBinding::gc },
        { "__tostring", ProductionInventoryLayoutBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ProductionInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, ProductionInventoryLayoutBinding::getMetatableName(), meta, methods, ProductionInventoryLayoutBinding::index, ProductionInventoryLayoutBinding::newindex);
}

} // namespace KenshiLua