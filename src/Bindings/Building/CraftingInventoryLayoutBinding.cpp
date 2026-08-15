#include "pch.h"
class CraftingItem {};
#include <kenshi/Building/CraftingBuilding.h>
#include "CraftingInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildInventoryLayoutBinding.h"
#include "Bindings/Gui/InventoryGUIBinding.h"
#include "Bindings/Gui/InventorySectionGUIBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/MyGuiBinding.h"
#include "Bindings/Util/StdMapBinding.h"
#include <MyGUI.h>

namespace KenshiLua
{

typedef std::map<std::string, InventorySectionGUI*, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, InventorySectionGUI*>, Ogre::GeneralAllocPolicy > > SectionsMap;

static CraftingInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<CraftingInventoryLayout>(L, idx, CraftingInventoryLayoutBinding::getMetatableName());
}

// --- Getters for CraftingInventoryLayout ---
static int CraftingInventoryLayout_get_queueBtn(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");
    return pushObject<MyGUI::Widget>(L, instance->queueBtn, MyGuiBinding::getMetatableName());
}

static int CraftingInventoryLayout_get_craftingName(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");
    return pushObject<MyGUI::Widget>(L, instance->craftingName, MyGuiBinding::getMetatableName());
}

static int CraftingInventoryLayout_get_outputType(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");
    lua_pushinteger(L, (lua_Integer)instance->outputType);
    return 1;
}

// --- Setters for CraftingInventoryLayout ---
static int CraftingInventoryLayout_set_queueBtn(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");
    instance->queueBtn = lua_isnoneornil(L, 2) ? nullptr : (MyGUI::Button*)checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int CraftingInventoryLayout_set_craftingName(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");
    instance->craftingName = lua_isnoneornil(L, 2) ? nullptr : (MyGUI::TextBox*)checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int CraftingInventoryLayout_set_outputType(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");
    instance->outputType = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

int CraftingInventoryLayoutBinding::setupSections(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");

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

int CraftingInventoryLayoutBinding::_NV_setupSections(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");

    InventoryGUI* inventoryGUI = testObject<InventoryGUI>(L, 2, InventoryGUIBinding::getMetatableName());
    if (!inventoryGUI) inventoryGUI = (InventoryGUI*)lua_touserdata(L, 2);

    SectionsMap* sections = testObject<SectionsMap>(L, 3, "std::map<std::string, InventorySectionGUI*>");
    if (!sections) sections = (SectionsMap*)lua_touserdata(L, 3);
    if (!sections) return luaL_error(L, "Argument 3 to _NV_setupSections must be a valid std::map<std::string, InventorySectionGUI*> or lightuserdata");

    Inventory* inventory = testObject<Inventory>(L, 4, InventoryBinding::getMetatableName());
    if (!inventory) inventory = (Inventory*)lua_touserdata(L, 4);

    instance->setupSections(inventoryGUI, *sections, inventory);
    return 0;
}

int CraftingInventoryLayoutBinding::refresh(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");

    instance->refresh();
    return 0;
}

int CraftingInventoryLayoutBinding::setOutputType(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");

    itemType type = (itemType)luaL_checkinteger(L, 2);
    instance->setOutputType(type);
    return 0;
}

int CraftingInventoryLayoutBinding::setCraftingName(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");

    std::string name = luaL_checkstring(L, 2);
    instance->setCraftingName(name);
    return 0;
}

int CraftingInventoryLayoutBinding::getQueueButton(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");

    MyGUI::Button* result = instance->getQueueButton();
    return pushObject<MyGUI::Widget>(L, result, MyGuiBinding::getMetatableName());
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - CraftingInventoryLayout_get_queueBtn / CraftingInventoryLayout_set_queueBtn: MyGUI::Button* (unbound pointer)
  - CraftingInventoryLayout_get_craftingName / CraftingInventoryLayout_set_craftingName: MyGUI::TextBox* (unbound pointer)
  - CraftingInventoryLayoutBinding::getQueueButton: MyGUI::Button* (unbound pointer)
*/

int CraftingInventoryLayoutBinding::gc(lua_State* L)
{
    return 0;
}

int CraftingInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CraftingInventoryLayout object");
    return 1;
}

void CraftingInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CraftingInventoryLayoutBinding::gc },
        { "__tostring", CraftingInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setupSections", CraftingInventoryLayoutBinding::setupSections },
        { "_NV_setupSections", CraftingInventoryLayoutBinding::_NV_setupSections },
        { "refresh", CraftingInventoryLayoutBinding::refresh },
        { "setOutputType", CraftingInventoryLayoutBinding::setOutputType },
        { "setCraftingName", CraftingInventoryLayoutBinding::setCraftingName },
        { "getQueueButton", CraftingInventoryLayoutBinding::getQueueButton },
        { 0, 0 }
    };

    registerClass(
        L, 
        CraftingInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CraftingInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CraftingInventoryLayout_get_queueBtn);
    lua_setfield(L, -2, "queueBtn");
    lua_pushcfunction(L, CraftingInventoryLayout_get_craftingName);
    lua_setfield(L, -2, "craftingName");
    lua_pushcfunction(L, CraftingInventoryLayout_get_outputType);
    lua_setfield(L, -2, "outputType");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CraftingInventoryLayout_set_queueBtn);
    lua_setfield(L, -2, "queueBtn");
    lua_pushcfunction(L, CraftingInventoryLayout_set_craftingName);
    lua_setfield(L, -2, "craftingName");
    lua_pushcfunction(L, CraftingInventoryLayout_set_outputType);
    lua_setfield(L, -2, "outputType");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua

