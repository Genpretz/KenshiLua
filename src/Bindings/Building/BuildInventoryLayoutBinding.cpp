#include "pch.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"

#include <kenshi/Building/ProductionBuilding.h>
#include "BuildInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
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
    return pushObject<MyGUI::TextBox>(L, instance->input1NameText, MyGUIBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input2NameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::TextBox>(L, instance->input2NameText, MyGUIBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input1StatusText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::TextBox>(L, instance->input1StatusText, MyGUIBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input2StatusText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::TextBox>(L, instance->input2StatusText, MyGUIBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input1ItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::ImageBox>(L, instance->input1ItemIcon, MyGUIBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input2ItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::ImageBox>(L, instance->input2ItemIcon, MyGUIBinding::getMetatableName());
}

static int BuildInventoryLayout_get_outputNameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::TextBox>(L, instance->outputNameText, MyGUIBinding::getMetatableName());
}

static int BuildInventoryLayout_get_outputItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::ImageBox>(L, instance->outputItemIcon, MyGUIBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input1Panel(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::Widget>(L, instance->input1Panel, MyGUIBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input2Panel(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::Widget>(L, instance->input2Panel, MyGUIBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input1Progress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::ProgressBar>(L, instance->input1Progress, MyGUIBinding::getMetatableName());
}

static int BuildInventoryLayout_get_input2Progress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::ProgressBar>(L, instance->input2Progress, MyGUIBinding::getMetatableName());
}

static int BuildInventoryLayout_get_outputProgress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return pushObject<MyGUI::ProgressBar>(L, instance->outputProgress, MyGUIBinding::getMetatableName());
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
    instance->input1NameText = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input2NameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input2NameText = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input1StatusText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input1StatusText = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input2StatusText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input2StatusText = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input1ItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input1ItemIcon = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ImageBox>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input2ItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input2ItemIcon = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ImageBox>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_outputNameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->outputNameText = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_outputItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->outputItemIcon = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ImageBox>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input1Panel(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input1Panel = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input2Panel(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input2Panel = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input1Progress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input1Progress = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ProgressBar>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_input2Progress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->input2Progress = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ProgressBar>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int BuildInventoryLayout_set_outputProgress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    instance->outputProgress = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ProgressBar>(L, 2, MyGUIBinding::getMetatableName());
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
        { "setupSections", BuildInventoryLayoutBinding::setupSections },
        { "_NV_setupSections", BuildInventoryLayoutBinding::_NV_setupSections },
        { "setInput", BuildInventoryLayoutBinding::setInput },
        { "setOutput", BuildInventoryLayoutBinding::setOutput },
        { "setInputProgress", BuildInventoryLayoutBinding::setInputProgress },
        { "setInputEnabled", BuildInventoryLayoutBinding::setInputEnabled },
        { "setOutputProgress", BuildInventoryLayoutBinding::setOutputProgress },
        { "setInputItem", BuildInventoryLayoutBinding::setInputItem },
        { "setOutputItem", BuildInventoryLayoutBinding::setOutputItem },
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
    registerGetter(L, "input1NameText", BuildInventoryLayout_get_input1NameText);
    registerGetter(L, "input2NameText", BuildInventoryLayout_get_input2NameText);
    registerGetter(L, "input1StatusText", BuildInventoryLayout_get_input1StatusText);
    registerGetter(L, "input2StatusText", BuildInventoryLayout_get_input2StatusText);
    registerGetter(L, "input1ItemIcon", BuildInventoryLayout_get_input1ItemIcon);
    registerGetter(L, "input2ItemIcon", BuildInventoryLayout_get_input2ItemIcon);
    registerGetter(L, "outputNameText", BuildInventoryLayout_get_outputNameText);
    registerGetter(L, "outputItemIcon", BuildInventoryLayout_get_outputItemIcon);
    registerGetter(L, "input1Panel", BuildInventoryLayout_get_input1Panel);
    registerGetter(L, "input2Panel", BuildInventoryLayout_get_input2Panel);
    registerGetter(L, "input1Progress", BuildInventoryLayout_get_input1Progress);
    registerGetter(L, "input2Progress", BuildInventoryLayout_get_input2Progress);
    registerGetter(L, "outputProgress", BuildInventoryLayout_get_outputProgress);
    registerGetter(L, "inputs", BuildInventoryLayout_get_inputs);
    registerGetter(L, "outputs", BuildInventoryLayout_get_outputs);
    registerGetter(L, "input1Item", BuildInventoryLayout_get_input1Item);
    registerGetter(L, "input2Item", BuildInventoryLayout_get_input2Item);
    registerGetter(L, "outputItem", BuildInventoryLayout_get_outputItem);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "input1NameText", BuildInventoryLayout_set_input1NameText);
    registerSetter(L, "input2NameText", BuildInventoryLayout_set_input2NameText);
    registerSetter(L, "input1StatusText", BuildInventoryLayout_set_input1StatusText);
    registerSetter(L, "input2StatusText", BuildInventoryLayout_set_input2StatusText);
    registerSetter(L, "input1ItemIcon", BuildInventoryLayout_set_input1ItemIcon);
    registerSetter(L, "input2ItemIcon", BuildInventoryLayout_set_input2ItemIcon);
    registerSetter(L, "outputNameText", BuildInventoryLayout_set_outputNameText);
    registerSetter(L, "outputItemIcon", BuildInventoryLayout_set_outputItemIcon);
    registerSetter(L, "input1Panel", BuildInventoryLayout_set_input1Panel);
    registerSetter(L, "input2Panel", BuildInventoryLayout_set_input2Panel);
    registerSetter(L, "input1Progress", BuildInventoryLayout_set_input1Progress);
    registerSetter(L, "input2Progress", BuildInventoryLayout_set_input2Progress);
    registerSetter(L, "outputProgress", BuildInventoryLayout_set_outputProgress);
    registerSetter(L, "inputs", BuildInventoryLayout_set_inputs);
    registerSetter(L, "outputs", BuildInventoryLayout_set_outputs);
    registerSetter(L, "input1Item", BuildInventoryLayout_set_input1Item);
    registerSetter(L, "input2Item", BuildInventoryLayout_set_input2Item);
    registerSetter(L, "outputItem", BuildInventoryLayout_set_outputItem);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua