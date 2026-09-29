#include "pch.h"
#include "kenshi\gui\InventoryGUI.h"
#include "BackpackInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Gui/GenericFixedInventoryLayoutBinding.h"
#include "Bindings/Kenshi/InventoryBinding.h"
#include "Bindings/Kenshi/Gui/InventoryGUIBinding.h"
#include "Bindings/Kenshi/Gui/InventorySectionGUIBinding.h"
#include "Bindings/Kenshi/Util/StdMapBinding.h"

namespace KenshiLua
{

static BackpackInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<BackpackInventoryLayout>(L, idx, BackpackInventoryLayoutBinding::getMetatableName());
}

// --- Getters for BackpackInventoryLayout ---
// --- Setters for BackpackInventoryLayout ---

typedef StdMapBinding<std::string, InventorySectionGUI*> InventorySectionsMapBinding;

int BackpackInventoryLayoutBinding::setupSections(lua_State* L)
{
    BackpackInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BackpackInventoryLayout is nil");

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
  line 17: void _NV_setupSections(...) - unexported in KenshiLib.lib
*/

int BackpackInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BackpackInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BackpackInventoryLayout object");
    return 1;
}

void BackpackInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BackpackInventoryLayoutBinding::gc },
        { "__tostring", BackpackInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setupSections", BackpackInventoryLayoutBinding::setupSections },
        { 0, 0 }
    };

    InventorySectionsMapBinding::registerBinding(L, "std::map<std::string, InventorySectionGUI*>", nullptr, InventorySectionGUIBinding::getMetatableName());

    registerClass(
        L, 
        BackpackInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BackpackInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GenericFixedInventoryLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, BackpackInventoryLayoutBinding::getMetatableName(), GenericFixedInventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua