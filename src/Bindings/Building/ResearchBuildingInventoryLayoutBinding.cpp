#include "pch.h"
#include <kenshi/Building/ResearchBuilding.h>
#include "ResearchBuildingInventoryLayoutBinding.h"
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

static ResearchBuildingInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<ResearchBuildingInventoryLayout>(L, idx, ResearchBuildingInventoryLayoutBinding::getMetatableName());
}

// --- Getters for ResearchBuildingInventoryLayout ---
static int ResearchBuildingInventoryLayout_get_researchButton(lua_State* L)
{
    ResearchBuildingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuildingInventoryLayout is nil");
    return pushObject<MyGUI::Widget>(L, instance->researchButton, MyGuiBinding::getMetatableName());
}

// --- Setters for ResearchBuildingInventoryLayout ---
static int ResearchBuildingInventoryLayout_set_researchButton(lua_State* L)
{
    ResearchBuildingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuildingInventoryLayout is nil");
    instance->researchButton = lua_isnoneornil(L, 2) ? nullptr : (MyGUI::Button*)checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

int ResearchBuildingInventoryLayoutBinding::getResearchButton(lua_State* L)
{
    ResearchBuildingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuildingInventoryLayout is nil");

    MyGUI::Widget* result = instance->getResearchButton();
    return pushObject<MyGUI::Widget>(L, result, MyGuiBinding::getMetatableName());
}

int ResearchBuildingInventoryLayoutBinding::setupSections(lua_State* L)
{
    ResearchBuildingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuildingInventoryLayout is nil");

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

int ResearchBuildingInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ResearchBuildingInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ResearchBuildingInventoryLayout object");
    return 1;
}

void ResearchBuildingInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ResearchBuildingInventoryLayoutBinding::gc },
        { "__tostring", ResearchBuildingInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getResearchButton", ResearchBuildingInventoryLayoutBinding::getResearchButton },
        { "setupSections", ResearchBuildingInventoryLayoutBinding::setupSections },
        { 0, 0 }
    };

    registerClass(
        L, 
        ResearchBuildingInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ResearchBuildingInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ResearchBuildingInventoryLayout_get_researchButton);
    lua_setfield(L, -2, "researchButton");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ResearchBuildingInventoryLayout_set_researchButton);
    lua_setfield(L, -2, "researchButton");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GenericInventoryLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ResearchBuildingInventoryLayoutBinding::getMetatableName(), GenericInventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack

    StdMapBinding<std::string, InventorySectionGUI*>::registerBinding(L, "std::map<std::string, InventorySectionGUI*>", nullptr, InventorySectionGUIBinding::getMetatableName());
}

} // namespace KenshiLua
