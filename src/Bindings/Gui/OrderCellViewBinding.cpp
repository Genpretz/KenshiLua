#include "pch.h"
#include "kenshi\gui\OrdersPanel.h"
#include "OrderCellViewBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/OrderDataBinding.h"

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
    return pushObject<OrderData>(L, instance->data, OrderDataBinding::getMetatableName());
}

// --- Setters for OrderCellView ---
static int OrderCellView_set_data(lua_State* L)
{
    OrderCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderCellView is nil");
    instance->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<OrderData>(L, 2, OrderDataBinding::getMetatableName());
    return 0;
}

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
  line 23: OrderCellView* _CONSTRUCTOR(...) - unsupported arg type
  line 26: void update(...) - unsupported arg type
  line 27: void getCellDimension(...) - static method
  line 31: void onRemove(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - OrderCellView_get_orderText: MyGUI::TextBox* (unbound pointer)
  - OrderCellView_get_removeButton: MyGUI::Button* (unbound pointer)
  - OrderCellViewBinding::getWidget: MyGUI::Widget* (unbound pointer)
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
    registerGetter(L, "orderText", OrderCellView_get_orderText);
    registerGetter(L, "removeButton", OrderCellView_get_removeButton);
    registerGetter(L, "data", OrderCellView_get_data);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "data", OrderCellView_set_data);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseCellView<OrderData*>
    // setMetatableParent(L, OrderCellViewBinding::getMetatableName(), wraps::BaseCellView<OrderData*>Binding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua