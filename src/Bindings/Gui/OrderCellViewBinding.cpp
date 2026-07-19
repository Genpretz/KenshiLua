#include "pch.h"
#include <kenshi/gui/OrdersPanel.h>
#include "OrderCellViewBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static OrderCellView* getInstance(lua_State* L, int idx)
{
    return checkObject<OrderCellView>(L, idx, OrderCellViewBinding::getMetatableName());
}

// --- Getters for OrderCellView ---
static int OrderCellView_get_orderText(lua_State* L)
{
    OrderCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderCellView is nil");
    lua_pushlightuserdata(L, (void*)instance->orderText);
    return 1;
}

static int OrderCellView_get_removeButton(lua_State* L)
{
    OrderCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderCellView is nil");
    lua_pushlightuserdata(L, (void*)instance->removeButton);
    return 1;
}

static int OrderCellView_get_data(lua_State* L)
{
    OrderCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderCellView is nil");
    lua_pushlightuserdata(L, (void*)instance->data);
    return 1;
}

// --- Setters for OrderCellView ---
int OrderCellViewBinding::_DESTRUCTOR(lua_State* L)
{
    OrderCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderCellView is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int OrderCellViewBinding::getWidget(lua_State* L)
{
    OrderCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderCellView is nil");

    MyGUI::Widget* result = instance->getWidget();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int OrderCellViewBinding::resize(lua_State* L)
{
    OrderCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderCellView is nil");

    instance->resize();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 21: OrderCellView* _CONSTRUCTOR(...) - unsupported arg type
  line 24: void update(...) - unsupported arg type
  line 25: void getCellDimension(...) - static method
  line 29: void onRemove(...) - unsupported arg type
*/

int OrderCellViewBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int OrderCellViewBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.OrderCellView object");
    return 1;
}

void OrderCellViewBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       OrderCellViewBinding::gc },
        { "__tostring", OrderCellViewBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", OrderCellViewBinding::_DESTRUCTOR },
        { "getWidget", OrderCellViewBinding::getWidget },
        { "resize", OrderCellViewBinding::resize },
        { 0, 0 }
    };

    registerClass(
        L, 
        OrderCellViewBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, OrderCellViewBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, OrderCellView_get_orderText);
    lua_setfield(L, -2, "orderText");
    lua_pushcfunction(L, OrderCellView_get_removeButton);
    lua_setfield(L, -2, "removeButton");
    lua_pushcfunction(L, OrderCellView_get_data);
    lua_setfield(L, -2, "data");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseCellView<OrderData*>
    // setMetatableParent(L, OrderCellViewBinding::getMetatableName(), wraps::BaseCellView<OrderData*>Binding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua