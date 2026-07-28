#include "pch.h"
#include "kenshi\gui\Tooltip.h"
#include "ToolTipInventoryBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/ToolTipBinding.h"

namespace KenshiLua
{

static ToolTipInventory* getInstance(lua_State* L, int idx)
{
    return checkObject<ToolTipInventory>(L, idx, ToolTipInventoryBinding::getMetatableName());
}

// --- Getters for ToolTipInventory ---
static int ToolTipInventory_get_compareTooltip(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    return pushObject<ToolTipInventory>(L, instance->compareTooltip, ToolTipInventoryBinding::getMetatableName());
}

// --- Setters for ToolTipInventory ---
static int ToolTipInventory_set_compareTooltip(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    instance->compareTooltip = lua_isnoneornil(L, 2) ? nullptr : checkObject<ToolTipInventory>(L, 2, ToolTipInventoryBinding::getMetatableName());
    return 0;
}

int ToolTipInventoryBinding::_CONSTRUCTOR(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");

    ToolTipInventory* result = instance->_CONSTRUCTOR();
    return pushObject<ToolTipInventory>(L, result, ToolTipInventoryBinding::getMetatableName());
}

int ToolTipInventoryBinding::_DESTRUCTOR(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ToolTipInventoryBinding::update(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");

    instance->update();
    return 0;
}

int ToolTipInventoryBinding::_NV_update(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");

    instance->_NV_update();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 162: void _setup(...) - unsupported arg type
  line 163: void _NV__setup(...) - unsupported arg type
  line 164: void setup(...) - unsupported arg type
  line 165: void _NV_setup(...) - unsupported arg type
  line 166: void show(...) - unsupported arg type
  line 167: void _NV_show(...) - unsupported arg type
  line 170: void setContent(...) - unsupported arg type
  line 171: void _NV_setContent(...) - unsupported arg type
  line 172: void clearData(...) - unsupported arg type
  line 173: void _NV_clearData(...) - unsupported arg type
  line 174: void mouseMoved(...) - unsupported arg type
  line 175: void setPosition(...) - unsupported arg type
  line 176: void _NV_setPosition(...) - unsupported arg type
*/

int ToolTipInventoryBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ToolTipInventoryBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ToolTipInventory object");
    return 1;
}

void ToolTipInventoryBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ToolTipInventoryBinding::gc },
        { "__tostring", ToolTipInventoryBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ToolTipInventoryBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ToolTipInventoryBinding::_DESTRUCTOR },
        { "update", ToolTipInventoryBinding::update },
        { "_NV_update", ToolTipInventoryBinding::_NV_update },
        { 0, 0 }
    };

    registerClass(
        L, 
        ToolTipInventoryBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ToolTipInventoryBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "compareTooltip", ToolTipInventory_get_compareTooltip);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "compareTooltip", ToolTipInventory_set_compareTooltip);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ToolTip
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ToolTipInventoryBinding::getMetatableName(), ToolTipBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua