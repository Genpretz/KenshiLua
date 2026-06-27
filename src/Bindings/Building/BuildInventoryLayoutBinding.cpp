#include "pch.h"
#include <kenshi/Building/ProductionBuilding.h>
#include "BuildInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ItemBinding.h"

namespace KenshiLua
{

static BuildInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<BuildInventoryLayout>(L, idx, BuildInventoryLayoutBinding::getMetatableName());
}

// --- Getters for BuildInventoryLayout ---
static int BuildInventoryLayout_get_input1NameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->input1NameText);
    return 1;
}

static int BuildInventoryLayout_get_input2NameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->input2NameText);
    return 1;
}

static int BuildInventoryLayout_get_input1StatusText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->input1StatusText);
    return 1;
}

static int BuildInventoryLayout_get_input2StatusText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->input2StatusText);
    return 1;
}

static int BuildInventoryLayout_get_input1ItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->input1ItemIcon);
    return 1;
}

static int BuildInventoryLayout_get_input2ItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->input2ItemIcon);
    return 1;
}

static int BuildInventoryLayout_get_outputNameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->outputNameText);
    return 1;
}

static int BuildInventoryLayout_get_outputItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->outputItemIcon);
    return 1;
}

static int BuildInventoryLayout_get_input1Panel(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->input1Panel);
    return 1;
}

static int BuildInventoryLayout_get_input2Panel(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->input2Panel);
    return 1;
}

static int BuildInventoryLayout_get_input1Progress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->input1Progress);
    return 1;
}

static int BuildInventoryLayout_get_input2Progress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->input2Progress);
    return 1;
}

static int BuildInventoryLayout_get_outputProgress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->outputProgress);
    return 1;
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
    return luaL_error(L, "Read-only or unsupported setter type for input1NameText");
}

static int BuildInventoryLayout_set_input2NameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for input2NameText");
}

static int BuildInventoryLayout_set_input1StatusText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for input1StatusText");
}

static int BuildInventoryLayout_set_input2StatusText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for input2StatusText");
}

static int BuildInventoryLayout_set_input1ItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for input1ItemIcon");
}

static int BuildInventoryLayout_set_input2ItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for input2ItemIcon");
}

static int BuildInventoryLayout_set_outputNameText(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for outputNameText");
}

static int BuildInventoryLayout_set_outputItemIcon(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for outputItemIcon");
}

static int BuildInventoryLayout_set_input1Panel(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for input1Panel");
}

static int BuildInventoryLayout_set_input2Panel(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for input2Panel");
}

static int BuildInventoryLayout_set_input1Progress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for input1Progress");
}

static int BuildInventoryLayout_set_input2Progress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for input2Progress");
}

static int BuildInventoryLayout_set_outputProgress(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for outputProgress");
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
    return luaL_error(L, "Read-only or unsupported setter type for input1Item");
}

static int BuildInventoryLayout_set_input2Item(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for input2Item");
}

static int BuildInventoryLayout_set_outputItem(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for outputItem");
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

int BuildInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    BuildInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildInventoryLayout is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 12: void setupSections(...) - unsupported arg type
  line 13: void _NV_setupSections(...) - unsupported arg type
  line 19: void setInputItem(...) - unsupported arg type
  line 20: void setOutputItem(...) - unsupported arg type
*/

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
    static const luaL_Reg meta[] = {
        { "__gc",       BuildInventoryLayoutBinding::gc },
        { "__tostring", BuildInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", BuildInventoryLayoutBinding::_CONSTRUCTOR },
        { "setInput", BuildInventoryLayoutBinding::setInput },
        { "setOutput", BuildInventoryLayoutBinding::setOutput },
        { "setInputProgress", BuildInventoryLayoutBinding::setInputProgress },
        { "setInputEnabled", BuildInventoryLayoutBinding::setInputEnabled },
        { "setOutputProgress", BuildInventoryLayoutBinding::setOutputProgress },
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

    // Wire up inheritance to InventoryLayout
    // // setMetatableParent(L, BuildInventoryLayoutBinding::getMetatableName(), InventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua