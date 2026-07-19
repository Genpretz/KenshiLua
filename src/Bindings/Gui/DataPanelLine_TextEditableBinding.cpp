#include "pch.h"
#include <kenshi/gui/DataPanelLine.h>
#include "DataPanelLine_TextEditableBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"

namespace KenshiLua
{

static DataPanelLine_TextEditable* getInstance(lua_State* L, int idx)
{
    return checkObject<DataPanelLine_TextEditable>(L, idx, DataPanelLine_TextEditableBinding::getMetatableName());
}

// --- Getters for DataPanelLine_TextEditable ---
static int DataPanelLine_TextEditable_get_editBox(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");
    lua_pushlightuserdata(L, (void*)instance->editBox);
    return 1;
}

static int DataPanelLine_TextEditable_get_nameText(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");
    lua_pushlightuserdata(L, (void*)instance->nameText);
    return 1;
}

static int DataPanelLine_TextEditable_get_textAlign(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");
    // TODO: Unsupported type for textAlign (MyGUI::Align)
    return luaL_error(L, "Unsupported property 'textAlign' (type: MyGUI::Align)");
}

static int DataPanelLine_TextEditable_get_showKey(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");
    lua_pushboolean(L, instance->showKey ? 1 : 0);
    return 1;
}

static int DataPanelLine_TextEditable_get_multiLine(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");
    lua_pushboolean(L, instance->multiLine ? 1 : 0);
    return 1;
}

static int DataPanelLine_TextEditable_get_width(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");
    lua_pushnumber(L, instance->width);
    return 1;
}

// --- Setters for DataPanelLine_TextEditable ---
static int DataPanelLine_TextEditable_set_editBox(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");
    return luaL_error(L, "Read-only or unsupported setter type for editBox");
}

static int DataPanelLine_TextEditable_set_nameText(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");
    return luaL_error(L, "Read-only or unsupported setter type for nameText");
}

static int DataPanelLine_TextEditable_set_textAlign(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");
    return luaL_error(L, "Read-only or unsupported setter type for textAlign");
}

static int DataPanelLine_TextEditable_set_showKey(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");
    instance->showKey = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DataPanelLine_TextEditable_set_multiLine(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");
    instance->multiLine = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DataPanelLine_TextEditable_set_width(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");
    instance->width = (float)luaL_checknumber(L, 2);
    return 0;
}

int DataPanelLine_TextEditableBinding::getEditBox(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");

    MyGUI::EditBox* result = instance->getEditBox();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DataPanelLine_TextEditableBinding::getNameBox(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");

    MyGUI::EditBox* result = instance->getNameBox();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DataPanelLine_TextEditableBinding::_DESTRUCTOR(lua_State* L)
{
    DataPanelLine_TextEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_TextEditable is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 222: DataPanelLine_TextEditable* _CONSTRUCTOR(...) - unsupported arg type
  line 223: void createMe(...) - unsupported arg type
  line 224: void _NV_createMe(...) - unsupported arg type
  line 225: void textChanged(...) - unsupported arg type
*/

int DataPanelLine_TextEditableBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DataPanelLine_TextEditableBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DataPanelLine_TextEditable object");
    return 1;
}

void DataPanelLine_TextEditableBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DataPanelLine_TextEditableBinding::gc },
        { "__tostring", DataPanelLine_TextEditableBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getEditBox", DataPanelLine_TextEditableBinding::getEditBox },
        { "getNameBox", DataPanelLine_TextEditableBinding::getNameBox },
        { "_DESTRUCTOR", DataPanelLine_TextEditableBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        DataPanelLine_TextEditableBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DataPanelLine_TextEditableBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DataPanelLine_TextEditable_get_editBox);
    lua_setfield(L, -2, "editBox");
    lua_pushcfunction(L, DataPanelLine_TextEditable_get_nameText);
    lua_setfield(L, -2, "nameText");
    lua_pushcfunction(L, DataPanelLine_TextEditable_get_textAlign);
    lua_setfield(L, -2, "textAlign");
    lua_pushcfunction(L, DataPanelLine_TextEditable_get_showKey);
    lua_setfield(L, -2, "showKey");
    lua_pushcfunction(L, DataPanelLine_TextEditable_get_multiLine);
    lua_setfield(L, -2, "multiLine");
    lua_pushcfunction(L, DataPanelLine_TextEditable_get_width);
    lua_setfield(L, -2, "width");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DataPanelLine_TextEditable_set_editBox);
    lua_setfield(L, -2, "editBox");
    lua_pushcfunction(L, DataPanelLine_TextEditable_set_nameText);
    lua_setfield(L, -2, "nameText");
    lua_pushcfunction(L, DataPanelLine_TextEditable_set_textAlign);
    lua_setfield(L, -2, "textAlign");
    lua_pushcfunction(L, DataPanelLine_TextEditable_set_showKey);
    lua_setfield(L, -2, "showKey");
    lua_pushcfunction(L, DataPanelLine_TextEditable_set_multiLine);
    lua_setfield(L, -2, "multiLine");
    lua_pushcfunction(L, DataPanelLine_TextEditable_set_width);
    lua_setfield(L, -2, "width");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to DataPanelLine
    // setMetatableParent(L, DataPanelLine_TextEditableBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
