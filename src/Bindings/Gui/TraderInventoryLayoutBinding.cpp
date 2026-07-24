#include "pch.h"
#include "kenshi\gui\InventoryTraderGUI.h"
#include "TraderInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/Gui/InventoryGUIBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"

namespace KenshiLua
{

static TraderInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<TraderInventoryLayout>(L, idx, TraderInventoryLayoutBinding::getMetatableName());
}

// --- Getters for TraderInventoryLayout ---
static int TraderInventoryLayout_get_scrollBackpack(lua_State* L)
{
    TraderInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TraderInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->scrollBackpack);
    return 1;
}

// --- Setters for TraderInventoryLayout ---
int TraderInventoryLayoutBinding::_CONSTRUCTOR(lua_State* L)
{
    TraderInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TraderInventoryLayout is nil");

    TraderInventoryLayout* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TraderInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    TraderInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TraderInventoryLayout is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 12: void setupSections(...) - unsupported arg type
  line 13: void _NV_setupSections(...) - unsupported arg type
  line 14: void resize(...) - unsupported arg type
  line 15: void notifyMouseWheel(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - TraderInventoryLayout_get_scrollBackpack: MyGUI::ScrollView* (unbound pointer)
  - TraderInventoryLayoutBinding::_CONSTRUCTOR: TraderInventoryLayout* (unbound pointer)
*/

int TraderInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TraderInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TraderInventoryLayout object");
    return 1;
}

void TraderInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TraderInventoryLayoutBinding::gc },
        { "__tostring", TraderInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", TraderInventoryLayoutBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", TraderInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        TraderInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TraderInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "scrollBackpack", TraderInventoryLayout_get_scrollBackpack);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to InventoryLayout
    // setMetatableParent(L, TraderInventoryLayoutBinding::getMetatableName(), InventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua