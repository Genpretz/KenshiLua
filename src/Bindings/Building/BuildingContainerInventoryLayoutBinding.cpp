#include "pch.h"
#include <kenshi/Building/StorageBuilding.h>
#include "BuildingContainerInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/GenericInventoryLayoutBinding.h"
#include "Bindings/Gui/InventoryGUIBinding.h"
#include "Bindings/Gui/InventorySectionGUIBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/MyGuiBinding.h"
#include "Bindings/Util/StdMapBinding.h"
#include <MyGUI.h>

namespace KenshiLua
{

typedef std::map<std::string, InventorySectionGUI*, std::less<std::string>, Ogre::STLAllocator<std::pair<std::string const, InventorySectionGUI*>, Ogre::GeneralAllocPolicy>> SectionsMap;

static BuildingContainerInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<BuildingContainerInventoryLayout>(L, idx, BuildingContainerInventoryLayoutBinding::getMetatableName());
}

// --- Getters for BuildingContainerInventoryLayout ---
static int BuildingContainerInventoryLayout_get_capacityText(lua_State* L)
{
    BuildingContainerInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingContainerInventoryLayout is nil");
    return pushObject<MyGUI::Widget>(L, instance->capacityText, MyGuiBinding::getMetatableName());
}

// --- Setters for BuildingContainerInventoryLayout ---
static int BuildingContainerInventoryLayout_set_capacityText(lua_State* L)
{
    BuildingContainerInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingContainerInventoryLayout is nil");
    instance->capacityText = lua_isnoneornil(L, 2) ? nullptr : (MyGUI::EditBox*)checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

int BuildingContainerInventoryLayoutBinding::setCapacity(lua_State* L)
{
    BuildingContainerInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingContainerInventoryLayout is nil");

    int value = (int)luaL_checkinteger(L, 2);
    bool full = lua_toboolean(L, 3) != 0;
    instance->setCapacity(value, full);
    return 0;
}

int BuildingContainerInventoryLayoutBinding::setupSections(lua_State* L)
{
    BuildingContainerInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingContainerInventoryLayout is nil");

    InventoryGUI* inventoryGUI = testObject<InventoryGUI>(L, 2, InventoryGUIBinding::getMetatableName());
    if (!inventoryGUI) inventoryGUI = (InventoryGUI*)lua_touserdata(L, 2);

    SectionsMap* sections = testObject<SectionsMap>(L, 3, "std::map<std::string, InventorySectionGUI*>");
    if (!sections) sections = (SectionsMap*)lua_touserdata(L, 3);
    if (!sections) return luaL_error(L, "Argument 3 to setupSections must be a valid std::map<std::string, InventorySectionGUI*> or lightuserdata");

    Inventory* inventory = testObject<Inventory>(L, 4, InventoryBinding::getMetatableName());
    if (!inventory) inventory = (Inventory*)lua_touserdata(L, 4);

    instance->setupSections(inventoryGUI, *sections, inventory);
    return 0;
}

int BuildingContainerInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BuildingContainerInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BuildingContainerInventoryLayout object");
    return 1;
}

void BuildingContainerInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildingContainerInventoryLayoutBinding::gc },
        { "__tostring", BuildingContainerInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setCapacity", BuildingContainerInventoryLayoutBinding::setCapacity },
        { "setupSections", BuildingContainerInventoryLayoutBinding::setupSections },
        { 0, 0 }
    };

    registerClass(
        L, 
        BuildingContainerInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BuildingContainerInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, BuildingContainerInventoryLayout_get_capacityText);
    lua_setfield(L, -2, "capacityText");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, BuildingContainerInventoryLayout_set_capacityText);
    lua_setfield(L, -2, "capacityText");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GenericInventoryLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, BuildingContainerInventoryLayoutBinding::getMetatableName(), GenericInventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack

    StdMapBinding<std::string, InventorySectionGUI*>::registerBinding(L, "std::map<std::string, InventorySectionGUI*>", nullptr, InventorySectionGUIBinding::getMetatableName());
}

} // namespace KenshiLua
