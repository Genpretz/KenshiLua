#include "pch.h"
#include "Bindings/TaskerBinding.h"

#include <kenshi/gui/OrdersPanel.h>
#include "OrderDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static OrderData* getInstance(lua_State* L, int idx)
{
    return checkObject<OrderData>(L, idx, OrderDataBinding::getMetatableName());
}

// --- Getters for OrderData ---
static int OrderData_get_task(lua_State* L)
{
    OrderData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderData is nil");
    return pushObject<Tasker>(L, const_cast<Tasker*>(instance->task), TaskerBinding::getMetatableName());
}

static int OrderData_get_index(lua_State* L)
{
    OrderData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderData is nil");
    lua_pushinteger(L, instance->index);
    return 1;
}

static int OrderData_get_text(lua_State* L)
{
    OrderData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderData is nil");
    lua_pushstring(L, instance->text.c_str());
    return 1;
}

static int OrderData_get_enabled(lua_State* L)
{
    OrderData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderData is nil");
    lua_pushboolean(L, instance->enabled ? 1 : 0);
    return 1;
}

// --- Setters for OrderData ---
static int OrderData_set_index(lua_State* L)
{
    OrderData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderData is nil");
    instance->index = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int OrderData_set_text(lua_State* L)
{
    OrderData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderData is nil");
    instance->text = luaL_checkstring(L, 2);
    return 0;
}

static int OrderData_set_enabled(lua_State* L)
{
    OrderData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderData is nil");
    instance->enabled = lua_toboolean(L, 2) != 0;
    return 0;
}

int OrderDataBinding::_CONSTRUCTOR(lua_State* L)
{
    OrderData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderData is nil");

    OrderData* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int OrderDataBinding::updateText(lua_State* L)
{
    OrderData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderData is nil");

    instance->updateText();
    return 0;
}

int OrderDataBinding::_DESTRUCTOR(lua_State* L)
{
    OrderData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrderData is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 46: void set(...) - unsupported arg type
  line 54: OrderData& operator=(...) - operator
*/

int OrderDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int OrderDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.OrderData object");
    return 1;
}

void OrderDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       OrderDataBinding::gc },
        { "__tostring", OrderDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", OrderDataBinding::_CONSTRUCTOR },
        { "updateText", OrderDataBinding::updateText },
        { "_DESTRUCTOR", OrderDataBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        OrderDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, OrderDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, OrderData_get_task);
    lua_setfield(L, -2, "task");
    lua_pushcfunction(L, OrderData_get_index);
    lua_setfield(L, -2, "index");
    lua_pushcfunction(L, OrderData_get_text);
    lua_setfield(L, -2, "text");
    lua_pushcfunction(L, OrderData_get_enabled);
    lua_setfield(L, -2, "enabled");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, OrderData_set_index);
    lua_setfield(L, -2, "index");
    lua_pushcfunction(L, OrderData_set_text);
    lua_setfield(L, -2, "text");
    lua_pushcfunction(L, OrderData_set_enabled);
    lua_setfield(L, -2, "enabled");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, OrderDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua