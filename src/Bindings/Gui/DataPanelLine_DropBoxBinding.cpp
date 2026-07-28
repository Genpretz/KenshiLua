#include "pch.h"
#include "kenshi\gui\DataPanelLine.h"
#include "DataPanelLine_DropBoxBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

namespace KenshiLua
{

static DataPanelLine_DropBox* getInstance(lua_State* L, int idx)
{
    return checkObject<DataPanelLine_DropBox>(L, idx, DataPanelLine_DropBoxBinding::getMetatableName());
}

// --- Getters for DataPanelLine_DropBox ---
static int DataPanelLine_DropBox_get_listBox(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");
    lua_pushlightuserdata(L, (void*)instance->listBox);
    return 1;
}

static int DataPanelLine_DropBox_get_listWidth(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");
    lua_pushnumber(L, instance->listWidth);
    return 1;
}

static int DataPanelLine_DropBox_get_valPtr(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");
    lua_pushlightuserdata(L, (void*)instance->valPtr);
    return 1;
}

static int DataPanelLine_DropBox_get_hasGoBox(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");
    lua_pushboolean(L, instance->hasGoBox ? 1 : 0);
    return 1;
}

static int DataPanelLine_DropBox_get_goBox(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");
    lua_pushlightuserdata(L, (void*)instance->goBox);
    return 1;
}

// --- Setters for DataPanelLine_DropBox ---
static int DataPanelLine_DropBox_set_listWidth(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");
    instance->listWidth = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_DropBox_set_hasGoBox(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");
    instance->hasGoBox = lua_toboolean(L, 2) != 0;
    return 0;
}

int DataPanelLine_DropBoxBinding::addAValue(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");

    const std::string key = luaL_checkstring(L, 2);
    int val = (int)luaL_checkinteger(L, 3);
    instance->addAValue(key, val);
    return 0;
}

int DataPanelLine_DropBoxBinding::getSelectedValue(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");

    int result = instance->getSelectedValue();
    lua_pushinteger(L, result);
    return 1;
}

int DataPanelLine_DropBoxBinding::setSelectedValue(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");

    int val = (int)luaL_checkinteger(L, 2);
    instance->setSelectedValue(val);
    return 0;
}

int DataPanelLine_DropBoxBinding::getSelectedText(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");

    std::string result = instance->getSelectedText();
    lua_pushstring(L, result.c_str());
    return 1;
}

int DataPanelLine_DropBoxBinding::clearValues(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");

    instance->clearValues();
    return 0;
}

int DataPanelLine_DropBoxBinding::getComboBox(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");

    MyGUI::ComboBox* result = instance->getComboBox();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DataPanelLine_DropBoxBinding::createMe(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");

    DatapanelGUI* parent = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    float top = (float)luaL_checknumber(L, 3);
    bool lastLine = lua_toboolean(L, 4) != 0;
    instance->createMe(parent, top, lastLine);
    return 0;
}

int DataPanelLine_DropBoxBinding::_NV_createMe(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");

    DatapanelGUI* parent = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    float top = (float)luaL_checknumber(L, 3);
    bool lastLine = lua_toboolean(L, 4) != 0;
    instance->_NV_createMe(parent, top, lastLine);
    return 0;
}

int DataPanelLine_DropBoxBinding::refresh(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");

    instance->refresh();
    return 0;
}

int DataPanelLine_DropBoxBinding::_NV_refresh(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");

    instance->_NV_refresh();
    return 0;
}

int DataPanelLine_DropBoxBinding::_CONSTRUCTOR(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");

    const std::string text = luaL_checkstring(L, 2);
    int category = (int)luaL_checkinteger(L, 3);
    int valInt = (int)luaL_checkinteger(L, 4);
    int* valuePtr = &valInt;
    float width = (float)luaL_checknumber(L, 5);
    bool hasGobox = lua_toboolean(L, 6) != 0;
    DataPanelLine_DropBox* result = instance->_CONSTRUCTOR(text, category, valuePtr, width, hasGobox);
    return pushObject<DataPanelLine_DropBox>(L, result, DataPanelLine_DropBoxBinding::getMetatableName());
}

int DataPanelLine_DropBoxBinding::_DESTRUCTOR(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 332: void updateValuePtr(...) - unsupported arg type
  line 333: void _NV_updateValuePtr(...) - unsupported arg type
  line 344: void selectionChange(...) - unsupported arg type
  line 345: void goPressed(...) - unsupported arg type
*/

int DataPanelLine_DropBoxBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DataPanelLine_DropBoxBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DataPanelLine_DropBox object");
    return 1;
}

void DataPanelLine_DropBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DataPanelLine_DropBoxBinding::gc },
        { "__tostring", DataPanelLine_DropBoxBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "addAValue", DataPanelLine_DropBoxBinding::addAValue },
        { "getSelectedValue", DataPanelLine_DropBoxBinding::getSelectedValue },
        { "setSelectedValue", DataPanelLine_DropBoxBinding::setSelectedValue },
        { "getSelectedText", DataPanelLine_DropBoxBinding::getSelectedText },
        { "clearValues", DataPanelLine_DropBoxBinding::clearValues },
        { "getComboBox", DataPanelLine_DropBoxBinding::getComboBox },
        { "createMe", DataPanelLine_DropBoxBinding::createMe },
        { "_NV_createMe", DataPanelLine_DropBoxBinding::_NV_createMe },
        { "refresh", DataPanelLine_DropBoxBinding::refresh },
        { "_NV_refresh", DataPanelLine_DropBoxBinding::_NV_refresh },
        { "_CONSTRUCTOR", DataPanelLine_DropBoxBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", DataPanelLine_DropBoxBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        DataPanelLine_DropBoxBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DataPanelLine_DropBoxBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "listBox", DataPanelLine_DropBox_get_listBox);
    registerGetter(L, "listWidth", DataPanelLine_DropBox_get_listWidth);
    registerGetter(L, "valPtr", DataPanelLine_DropBox_get_valPtr);
    registerGetter(L, "hasGoBox", DataPanelLine_DropBox_get_hasGoBox);
    registerGetter(L, "goBox", DataPanelLine_DropBox_get_goBox);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "listWidth", DataPanelLine_DropBox_set_listWidth);
    registerSetter(L, "hasGoBox", DataPanelLine_DropBox_set_hasGoBox);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to DataPanelLine
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, DataPanelLine_DropBoxBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua