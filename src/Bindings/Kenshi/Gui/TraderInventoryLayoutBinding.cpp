#include "pch.h"
#include "kenshi\gui\InventoryTraderGUI.h"
#include "TraderInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/InventoryBinding.h"
#include "Bindings/Kenshi/Gui/InventoryGUIBinding.h"
#include "Bindings/Kenshi/Gui/InventoryLayoutBinding.h"
#include "Bindings/Kenshi/Gui/InventorySectionGUIBinding.h"
#include "Bindings/Kenshi/Util/StdMapBinding.h"
#include "Bindings/MyGUI/MyGUIBinding.h" 

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
typedef StdMapBinding<std::string, InventorySectionGUI*> InventorySectionsMapBinding;

int TraderInventoryLayoutBinding::setupSections(lua_State* L)
{
    TraderInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TraderInventoryLayout is nil");

    InventoryGUI* gui = checkObject<InventoryGUI>(L, 2, InventoryGUIBinding::getMetatableName());
    if (!gui) return luaL_error(L, "Argument 2 to setupSections must be InventoryGUI");
    auto* sections = InventorySectionsMapBinding::get(L, 3);
    if (!sections) return luaL_error(L, "Argument 3 to setupSections must be std::map<std::string, InventorySectionGUI*>");
    Inventory* inv = checkObject<Inventory>(L, 4, InventoryBinding::getMetatableName());
    if (!inv) return luaL_error(L, "Argument 4 to setupSections must be Inventory");

    instance->setupSections(gui, *sections, inv);
    return 0;
}


/*
Skipped methods needing manual binding:
  line 13: void _NV_setupSections(...) - unexported in KenshiLib.lib
  line 14: void resize(...) - unexported in KenshiLib.lib (MASM identifier length limit)
*/

int TraderInventoryLayoutBinding::notifyMouseWheel(lua_State* L)
{
    TraderInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TraderInventoryLayout is nil");

    MyGUI::Widget* widget = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    int rel = (int)luaL_checkinteger(L, 3);
    instance->notifyMouseWheel(widget, rel);
    return 0;
}


/*
LIGHTUSERDATA DEPENDENCIES:
  - TraderInventoryLayout_get_scrollBackpack: MyGUI::ScrollView* (unbound pointer)
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
        { "setupSections", TraderInventoryLayoutBinding::setupSections },
        { "notifyMouseWheel", TraderInventoryLayoutBinding::notifyMouseWheel },
        { 0, 0 }
    };

    InventorySectionsMapBinding::registerBinding(L, "std::map<std::string, InventorySectionGUI*>", nullptr, InventorySectionGUIBinding::getMetatableName());

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
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, TraderInventoryLayoutBinding::getMetatableName(), InventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua