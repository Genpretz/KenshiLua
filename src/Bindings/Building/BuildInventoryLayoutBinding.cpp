#include "pch.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"

#include <kenshi/Building/ProductionBuilding.h>
#include "BuildInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/MyGuiBinding.h"
#include "Bindings/Gui/InventoryGUIBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/Gui/InventorySectionGUIBinding.h"
#include "Bindings/Util/StdMapBinding.h"
#include <MyGUI.h>

namespace KenshiLua
{

typedef std::map<std::string, InventorySectionGUI*, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, InventorySectionGUI*>, Ogre::GeneralAllocPolicy > > SectionsMap;

static BuildInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<BuildInventoryLayout>(L, idx, BuildInventoryLayoutBinding::getMetatableName());
}

// --- Getters for BuildInventoryLayout ---
static int BuildInventoryLayout_get_input1NameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::TextBox>(L, instance->input1NameText, MyGuiBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input2NameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::TextBox>(L, instance->input2NameText, MyGuiBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input1StatusText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::TextBox>(L, instance->input1StatusText, MyGuiBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input2StatusText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::TextBox>(L, instance->input2StatusText, MyGuiBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input1ItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::ImageBox>(L, instance->input1ItemIcon, MyGuiBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input2ItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::ImageBox>(L, instance->input2ItemIcon, MyGuiBinding::getMetatableName());
}

static int BuildInventoryLayout_get_outputNameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::TextBox>(L, instance->outputNameText, MyGuiBinding::getMetatableName());
}

static int BuildInventoryLayout_get_outputItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::ImageBox>(L, instance->outputItemIcon, MyGuiBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input1Panel(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::Widget>(L, instance->input1Panel, MyGuiBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input2Panel(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::Widget>(L, instance->input2Panel, MyGuiBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input1Progress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::ProgressBar>(L, instance->input1Progress, MyGuiBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input2Progress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::ProgressBar>(L, instance->input2Progress, MyGuiBinding::getMetatableName());
}

static int BuildInventoryLayout_get_outputProgress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::ProgressBar>(L, instance->outputProgress, MyGuiBinding::getMetatableName());
}

static int BuildInventoryLayout_get_inputs(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushinteger(L, instance->inputs);
    return 1;
}

static int BuildInventoryLayout_get_outputs(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushinteger(L, instance->outputs);
    return 1;
}

static int BuildInventoryLayout_get_input1Item(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<Item>(L, instance->input1Item, ItemBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input2Item(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<Item>(L, instance->input2Item, ItemBinding::getMetatableName());
}

static int BuildInventoryLayout_get_outputItem(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<Item>(L, instance->outputItem, ItemBinding::getMetatableName());
}

// --- Setters for BuildInventoryLayout ---
static int BuildInventoryLayout_set_input1NameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input1NameText = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input2NameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input2NameText = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input1StatusText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input1StatusText = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input2StatusText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input2StatusText = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input1ItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input1ItemIcon = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ImageBox>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input2ItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input2ItemIcon = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ImageBox>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_outputNameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->outputNameText = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_outputItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->outputItemIcon = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ImageBox>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input1Panel(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input1Panel = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input2Panel(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input2Panel = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input1Progress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input1Progress = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ProgressBar>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input2Progress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input2Progress = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ProgressBar>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_outputProgress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->outputProgress = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ProgressBar>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_inputs(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->inputs = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int BuildInventoryLayout_set_outputs(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->outputs = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int BuildInventoryLayout_set_input1Item(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input1Item = lua_isnoneornil(L, 2) ? nullptr : checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input2Item(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input2Item = lua_isnoneornil(L, 2) ? nullptr : checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_outputItem(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->outputItem = lua_isnoneornil(L, 2) ? nullptr : checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    return 0;
}

int BuildInventoryLayoutBinding::_CONSTRUCTOR(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");

    std::string title = luaL_checkstring(L, 2);
    int ins = (int)luaL_checkinteger(L, 3);
    int outs = (int)luaL_checkinteger(L, 4);
    bool hasQueue = lua_toboolean(L, 5) != 0;
    BuildInventoryLayout* result = instance->_CONSTRUCTOR(title, ins, outs, hasQueue);
    return pushObject<BuildInventoryLayout>(L, result, BuildInventoryLayoutBinding::getMetatableName());
}

int BuildInventoryLayoutBinding::setupSections(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");

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

int BuildInventoryLayoutBinding::_NV_setupSections(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");

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

int BuildInventoryLayoutBinding::setInput(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");

    int inputIndex = (int)luaL_checkinteger(L, 2);
    std::string name = luaL_checkstring(L, 3);
    std::string status = luaL_checkstring(L, 4);
    instance->setInput(inputIndex, name, status);
    return 0;
}

int BuildInventoryLayoutBinding::setOutput(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");

    std::string name = luaL_checkstring(L, 2);
    instance->setOutput(name);
    return 0;
}

int BuildInventoryLayoutBinding::setInputProgress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");

    int inputIdx = (int)luaL_checkinteger(L, 2);
    float progress = (float)luaL_checknumber(L, 3);
    instance->setInputProgress(inputIdx, progress);
    return 0;
}

int BuildInventoryLayoutBinding::setInputEnabled(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");

    int inputIdx = (int)luaL_checkinteger(L, 2);
    bool value = lua_toboolean(L, 3) != 0;
    instance->setInputEnabled(inputIdx, value);
    return 0;
}

int BuildInventoryLayoutBinding::setOutputProgress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");

    float progress = (float)luaL_checknumber(L, 2);
    instance->setOutputProgress(progress);
    return 0;
}

int BuildInventoryLayoutBinding::setInputItem(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");

    int inputIdx = (int)luaL_checkinteger(L, 2);
    Item* item = lua_isnoneornil(L, 3) ? nullptr : checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    bool visible = lua_toboolean(L, 4) != 0;
    instance->setInputItem(inputIdx, item, visible);
    return 0;
}

int BuildInventoryLayoutBinding::setOutputItem(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");

    Item* item = lua_isnoneornil(L, 2) ? nullptr : checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool visible = lua_toboolean(L, 3) != 0;
    instance->setOutputItem(item, visible);
    return 0;
}

int BuildInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int BuildInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BuildInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BuildInventoryLayout object");
    return 1;
}

void BuildInventoryLayoutBinding::registerBinding(lua_State* L)
{
    StdMapBinding<std::string, InventorySectionGUI*>::registerBinding(L, "std::map<std::string, InventorySectionGUI*>", nullptr, InventorySectionGUIBinding::getMetatableName());

    static const luaL_Reg meta[] = {
        { "__gc",       BuildInventoryLayoutBinding::gc },
        { "__tostring", BuildInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", BuildInventoryLayoutBinding::_CONSTRUCTOR },
        { "setupSections", BuildInventoryLayoutBinding::setupSections },
        { "_NV_setupSections", BuildInventoryLayoutBinding::_NV_setupSections },
        { "setInput", BuildInventoryLayoutBinding::setInput },
        { "setOutput", BuildInventoryLayoutBinding::setOutput },
        { "setInputProgress", BuildInventoryLayoutBinding::setInputProgress },
        { "setInputEnabled", BuildInventoryLayoutBinding::setInputEnabled },
        { "setOutputProgress", BuildInventoryLayoutBinding::setOutputProgress },
        { "setInputItem", BuildInventoryLayoutBinding::setInputItem },
        { "setOutputItem", BuildInventoryLayoutBinding::setOutputItem },
        { "_DESTRUCTOR", BuildInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        BuildInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BuildInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, BuildInventoryLayout_get_input1NameText);
    lua_setfield(L, -2, "input1NameText");
    lua_pushcfunction(L, BuildInventoryLayout_get_input2NameText);
    lua_setfield(L, -2, "input2NameText");
    lua_pushcfunction(L, BuildInventoryLayout_get_input1StatusText);
    lua_setfield(L, -2, "input1StatusText");
    lua_pushcfunction(L, BuildInventoryLayout_get_input2StatusText);
    lua_setfield(L, -2, "input2StatusText");
    lua_pushcfunction(L, BuildInventoryLayout_get_input1ItemIcon);
    lua_setfield(L, -2, "input1ItemIcon");
    lua_pushcfunction(L, BuildInventoryLayout_get_input2ItemIcon);
    lua_setfield(L, -2, "input2ItemIcon");
    lua_pushcfunction(L, BuildInventoryLayout_get_outputNameText);
    lua_setfield(L, -2, "outputNameText");
    lua_pushcfunction(L, BuildInventoryLayout_get_outputItemIcon);
    lua_setfield(L, -2, "outputItemIcon");
    lua_pushcfunction(L, BuildInventoryLayout_get_input1Panel);
    lua_setfield(L, -2, "input1Panel");
    lua_pushcfunction(L, BuildInventoryLayout_get_input2Panel);
    lua_setfield(L, -2, "input2Panel");
    lua_pushcfunction(L, BuildInventoryLayout_get_input1Progress);
    lua_setfield(L, -2, "input1Progress");
    lua_pushcfunction(L, BuildInventoryLayout_get_input2Progress);
    lua_setfield(L, -2, "input2Progress");
    lua_pushcfunction(L, BuildInventoryLayout_get_outputProgress);
    lua_setfield(L, -2, "outputProgress");
    lua_pushcfunction(L, BuildInventoryLayout_get_inputs);
    lua_setfield(L, -2, "inputs");
    lua_pushcfunction(L, BuildInventoryLayout_get_outputs);
    lua_setfield(L, -2, "outputs");
    lua_pushcfunction(L, BuildInventoryLayout_get_input1Item);
    lua_setfield(L, -2, "input1Item");
    lua_pushcfunction(L, BuildInventoryLayout_get_input2Item);
    lua_setfield(L, -2, "input2Item");
    lua_pushcfunction(L, BuildInventoryLayout_get_outputItem);
    lua_setfield(L, -2, "outputItem");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, BuildInventoryLayout_set_input1NameText);
    lua_setfield(L, -2, "input1NameText");
    lua_pushcfunction(L, BuildInventoryLayout_set_input2NameText);
    lua_setfield(L, -2, "input2NameText");
    lua_pushcfunction(L, BuildInventoryLayout_set_input1StatusText);
    lua_setfield(L, -2, "input1StatusText");
    lua_pushcfunction(L, BuildInventoryLayout_set_input2StatusText);
    lua_setfield(L, -2, "input2StatusText");
    lua_pushcfunction(L, BuildInventoryLayout_set_input1ItemIcon);
    lua_setfield(L, -2, "input1ItemIcon");
    lua_pushcfunction(L, BuildInventoryLayout_set_input2ItemIcon);
    lua_setfield(L, -2, "input2ItemIcon");
    lua_pushcfunction(L, BuildInventoryLayout_set_outputNameText);
    lua_setfield(L, -2, "outputNameText");
    lua_pushcfunction(L, BuildInventoryLayout_set_outputItemIcon);
    lua_setfield(L, -2, "outputItemIcon");
    lua_pushcfunction(L, BuildInventoryLayout_set_input1Panel);
    lua_setfield(L, -2, "input1Panel");
    lua_pushcfunction(L, BuildInventoryLayout_set_input2Panel);
    lua_setfield(L, -2, "input2Panel");
    lua_pushcfunction(L, BuildInventoryLayout_set_input1Progress);
    lua_setfield(L, -2, "input1Progress");
    lua_pushcfunction(L, BuildInventoryLayout_set_input2Progress);
    lua_setfield(L, -2, "input2Progress");
    lua_pushcfunction(L, BuildInventoryLayout_set_outputProgress);
    lua_setfield(L, -2, "outputProgress");
    lua_pushcfunction(L, BuildInventoryLayout_set_inputs);
    lua_setfield(L, -2, "inputs");
    lua_pushcfunction(L, BuildInventoryLayout_set_outputs);
    lua_setfield(L, -2, "outputs");
    lua_pushcfunction(L, BuildInventoryLayout_set_input1Item);
    lua_setfield(L, -2, "input1Item");
    lua_pushcfunction(L, BuildInventoryLayout_set_input2Item);
    lua_setfield(L, -2, "input2Item");
    lua_pushcfunction(L, BuildInventoryLayout_set_outputItem);
    lua_setfield(L, -2, "outputItem");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua