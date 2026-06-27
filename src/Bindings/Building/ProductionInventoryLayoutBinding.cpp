#include "pch.h"
#include <kenshi/Building/ProductionBuilding.h>
#include "ProductionInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildInventoryLayoutBinding.h"

namespace KenshiLua
{

static ProductionInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<ProductionInventoryLayout>(L, idx, ProductionInventoryLayoutBinding::getMetatableName());
}

// --- Getters for ProductionInventoryLayout ---
// --- Setters for ProductionInventoryLayout ---
int ProductionInventoryLayoutBinding::_CONSTRUCTOR(lua_State* L)
{
    ProductionInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionInventoryLayout is nil");

    std::string title = luaL_checkstring(L, 2);
    int ins = (int)luaL_checkinteger(L, 3);
    int outs = (int)luaL_checkinteger(L, 4);
    ProductionInventoryLayout* result = instance->_CONSTRUCTOR(title, ins, outs);
    return pushObject<ProductionInventoryLayout>(L, result, ProductionInventoryLayoutBinding::getMetatableName());
}

int ProductionInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    ProductionInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionInventoryLayout is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ProductionInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ProductionInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ProductionInventoryLayout object");
    return 1;
}

void ProductionInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ProductionInventoryLayoutBinding::gc },
        { "__tostring", ProductionInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ProductionInventoryLayoutBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ProductionInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        ProductionInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ProductionInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to BuildInventoryLayout
    setMetatableParent(L, ProductionInventoryLayoutBinding::getMetatableName(), BuildInventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua