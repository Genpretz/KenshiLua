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
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ProductionInventoryLayoutBinding::getMetatableName(), BuildInventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
