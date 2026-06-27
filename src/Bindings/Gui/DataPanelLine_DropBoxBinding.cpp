#include "pch.h"
#include <kenshi/gui/DataPanelLine.h>
#include "DataPanelLine_DropBoxBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"

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
static int DataPanelLine_DropBox_set_listBox(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");
    return luaL_error(L, "Read-only or unsupported setter type for listBox");
}

static int DataPanelLine_DropBox_set_listWidth(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");
    instance->listWidth = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_DropBox_set_valPtr(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");
    return luaL_error(L, "Read-only or unsupported setter type for valPtr");
}

static int DataPanelLine_DropBox_set_hasGoBox(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");
    instance->hasGoBox = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DataPanelLine_DropBox_set_goBox(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");
    return luaL_error(L, "Read-only or unsupported setter type for goBox");
}

int DataPanelLine_DropBoxBinding::addAValue(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");

    std::string key = luaL_checkstring(L, 2);
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

int DataPanelLine_DropBoxBinding::_DESTRUCTOR(lua_State* L)
{
    DataPanelLine_DropBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_DropBox is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 329: void createMe(...) - unsupported arg type
  line 330: void _NV_createMe(...) - unsupported arg type
  line 331: void updateValuePtr(...) - unsupported arg type
  line 332: void _NV_updateValuePtr(...) - unsupported arg type
  line 337: DataPanelLine_DropBox* _CONSTRUCTOR(...) - pointer arg
  line 343: void selectionChange(...) - unsupported arg type
  line 344: void goPressed(...) - unsupported arg type
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
        { "refresh", DataPanelLine_DropBoxBinding::refresh },
        { "_NV_refresh", DataPanelLine_DropBoxBinding::_NV_refresh },
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
    lua_pushcfunction(L, DataPanelLine_DropBox_get_listBox);
    lua_setfield(L, -2, "listBox");
    lua_pushcfunction(L, DataPanelLine_DropBox_get_listWidth);
    lua_setfield(L, -2, "listWidth");
    lua_pushcfunction(L, DataPanelLine_DropBox_get_valPtr);
    lua_setfield(L, -2, "valPtr");
    lua_pushcfunction(L, DataPanelLine_DropBox_get_hasGoBox);
    lua_setfield(L, -2, "hasGoBox");
    lua_pushcfunction(L, DataPanelLine_DropBox_get_goBox);
    lua_setfield(L, -2, "goBox");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DataPanelLine_DropBox_set_listBox);
    lua_setfield(L, -2, "listBox");
    lua_pushcfunction(L, DataPanelLine_DropBox_set_listWidth);
    lua_setfield(L, -2, "listWidth");
    lua_pushcfunction(L, DataPanelLine_DropBox_set_valPtr);
    lua_setfield(L, -2, "valPtr");
    lua_pushcfunction(L, DataPanelLine_DropBox_set_hasGoBox);
    lua_setfield(L, -2, "hasGoBox");
    lua_pushcfunction(L, DataPanelLine_DropBox_set_goBox);
    lua_setfield(L, -2, "goBox");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to DataPanelLine
    setMetatableParent(L, DataPanelLine_DropBoxBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua