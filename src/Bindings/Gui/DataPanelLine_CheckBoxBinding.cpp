#include "pch.h"
#include <kenshi/gui/DataPanelLine.h>
#include "DataPanelLine_CheckBoxBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"

namespace KenshiLua
{

static DataPanelLine_CheckBox* getInstance(lua_State* L, int idx)
{
    return checkObject<DataPanelLine_CheckBox>(L, idx, DataPanelLine_CheckBoxBinding::getMetatableName());
}

// --- Getters for DataPanelLine_CheckBox ---
static int DataPanelLine_CheckBox_get_valuePtr(lua_State* L)
{
    DataPanelLine_CheckBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_CheckBox is nil");
    lua_pushlightuserdata(L, (void*)instance->valuePtr);
    return 1;
}

static int DataPanelLine_CheckBox_get_text(lua_State* L)
{
    DataPanelLine_CheckBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_CheckBox is nil");
    lua_pushlightuserdata(L, (void*)instance->text);
    return 1;
}

static int DataPanelLine_CheckBox_get_button(lua_State* L)
{
    DataPanelLine_CheckBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_CheckBox is nil");
    lua_pushlightuserdata(L, (void*)instance->button);
    return 1;
}

// --- Setters for DataPanelLine_CheckBox ---
static int DataPanelLine_CheckBox_set_valuePtr(lua_State* L)
{
    DataPanelLine_CheckBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_CheckBox is nil");
    return luaL_error(L, "Read-only or unsupported setter type for valuePtr");
}

static int DataPanelLine_CheckBox_set_text(lua_State* L)
{
    DataPanelLine_CheckBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_CheckBox is nil");
    return luaL_error(L, "Read-only or unsupported setter type for text");
}

static int DataPanelLine_CheckBox_set_button(lua_State* L)
{
    DataPanelLine_CheckBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_CheckBox is nil");
    return luaL_error(L, "Read-only or unsupported setter type for button");
}

int DataPanelLine_CheckBoxBinding::refresh(lua_State* L)
{
    DataPanelLine_CheckBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_CheckBox is nil");

    instance->refresh();
    return 0;
}

int DataPanelLine_CheckBoxBinding::_NV_refresh(lua_State* L)
{
    DataPanelLine_CheckBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_CheckBox is nil");

    instance->_NV_refresh();
    return 0;
}

int DataPanelLine_CheckBoxBinding::setValue(lua_State* L)
{
    DataPanelLine_CheckBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_CheckBox is nil");

    bool checked = lua_toboolean(L, 2) != 0;
    instance->setValue(checked);
    return 0;
}

int DataPanelLine_CheckBoxBinding::getTextBox(lua_State* L)
{
    DataPanelLine_CheckBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_CheckBox is nil");

    MyGUI::EditBox* result = instance->getTextBox();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DataPanelLine_CheckBoxBinding::getCheckBox(lua_State* L)
{
    DataPanelLine_CheckBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_CheckBox is nil");

    MyGUI::Button* result = instance->getCheckBox();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DataPanelLine_CheckBoxBinding::_DESTRUCTOR(lua_State* L)
{
    DataPanelLine_CheckBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_CheckBox is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 295: void updateValuePtr(...) - unsupported arg type
  line 296: void _NV_updateValuePtr(...) - unsupported arg type
  line 300: void setValuePtr(...) - pointer arg
  line 305: DataPanelLine_CheckBox* _CONSTRUCTOR(...) - pointer arg
  line 306: void notifyToggleCheck(...) - unsupported arg type
  line 307: void createMe(...) - unsupported arg type
  line 308: void _NV_createMe(...) - unsupported arg type
*/

int DataPanelLine_CheckBoxBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DataPanelLine_CheckBoxBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DataPanelLine_CheckBox object");
    return 1;
}

void DataPanelLine_CheckBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DataPanelLine_CheckBoxBinding::gc },
        { "__tostring", DataPanelLine_CheckBoxBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "refresh", DataPanelLine_CheckBoxBinding::refresh },
        { "_NV_refresh", DataPanelLine_CheckBoxBinding::_NV_refresh },
        { "setValue", DataPanelLine_CheckBoxBinding::setValue },
        { "getTextBox", DataPanelLine_CheckBoxBinding::getTextBox },
        { "getCheckBox", DataPanelLine_CheckBoxBinding::getCheckBox },
        { "_DESTRUCTOR", DataPanelLine_CheckBoxBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        DataPanelLine_CheckBoxBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DataPanelLine_CheckBoxBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DataPanelLine_CheckBox_get_valuePtr);
    lua_setfield(L, -2, "valuePtr");
    lua_pushcfunction(L, DataPanelLine_CheckBox_get_text);
    lua_setfield(L, -2, "text");
    lua_pushcfunction(L, DataPanelLine_CheckBox_get_button);
    lua_setfield(L, -2, "button");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DataPanelLine_CheckBox_set_valuePtr);
    lua_setfield(L, -2, "valuePtr");
    lua_pushcfunction(L, DataPanelLine_CheckBox_set_text);
    lua_setfield(L, -2, "text");
    lua_pushcfunction(L, DataPanelLine_CheckBox_set_button);
    lua_setfield(L, -2, "button");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to DataPanelLine
    setMetatableParent(L, DataPanelLine_CheckBoxBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua