#include "pch.h"
#include "kenshi\CharacterAnimal.h"
#include "AnimalInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/InventoryBinding.h"
#include "Bindings/Kenshi/Gui/InventoryGUIBinding.h"
#include "Bindings/Kenshi/Gui/InventoryLayoutBinding.h"
#include "Bindings/Kenshi/Gui/InventorySectionGUIBinding.h"
#include "Bindings/Kenshi/Util/StdMapBinding.h"

namespace KenshiLua
{

static AnimalInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimalInventoryLayout>(L, idx, AnimalInventoryLayoutBinding::getMetatableName());
}

// --- Getters for AnimalInventoryLayout ---
// --- Setters for AnimalInventoryLayout ---

typedef StdMapBinding<std::string, InventorySectionGUI*> InventorySectionsMapBinding;

int AnimalInventoryLayoutBinding::setupSections(lua_State* L)
{
    AnimalInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimalInventoryLayout is nil");

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

int AnimalInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int AnimalInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimalInventoryLayout object");
    return 1;
}

void AnimalInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimalInventoryLayoutBinding::gc },
        { "__tostring", AnimalInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setupSections", AnimalInventoryLayoutBinding::setupSections },
        { 0, 0 }
    };

    InventorySectionsMapBinding::registerBinding(L, "std::map<std::string, InventorySectionGUI*>", nullptr, InventorySectionGUIBinding::getMetatableName());

    registerClass(
        L, 
        AnimalInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimalInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to InventoryLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, AnimalInventoryLayoutBinding::getMetatableName(), InventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua