#include "pch.h"
#include <kenshi/gui/OrdersPanel.h>
#include "OrdersItemBoxBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static OrdersItemBox* getInstance(lua_State* L, int idx)
{
    return checkObject<OrdersItemBox>(L, idx, OrdersItemBoxBinding::getMetatableName());
}

// --- Getters for OrdersItemBox ---
// --- Setters for OrdersItemBox ---
int OrdersItemBoxBinding::_DESTRUCTOR(lua_State* L)
{
    OrdersItemBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersItemBox is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 65: OrdersItemBox* _CONSTRUCTOR(...) - unsupported arg type
*/

int OrdersItemBoxBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int OrdersItemBoxBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.OrdersItemBox object");
    return 1;
}

void OrdersItemBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       OrdersItemBoxBinding::gc },
        { "__tostring", OrdersItemBoxBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", OrdersItemBoxBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        OrdersItemBoxBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, OrdersItemBoxBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseItemBox<OrderCellView>
    // // // // setMetatableParent(L, OrdersItemBoxBinding::getMetatableName(), wraps::BaseItemBox<OrderCellView>Binding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua