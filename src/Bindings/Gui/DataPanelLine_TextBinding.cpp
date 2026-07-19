#include "pch.h"
#include <kenshi/gui/DataPanelLine.h>
#include "DataPanelLine_TextBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"

namespace KenshiLua
{

static DataPanelLine_Text* getInstance(lua_State* L, int idx)
{
    return checkObject<DataPanelLine_Text>(L, idx, DataPanelLine_TextBinding::getMetatableName());
}

// --- Getters for DataPanelLine_Text ---
static int DataPanelLine_Text_get_editBox(lua_State* L)
{
    DataPanelLine_Text* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Text is nil");
    lua_pushlightuserdata(L, (void*)instance->editBox);
    return 1;
}

static int DataPanelLine_Text_get_textAlign(lua_State* L)
{
    DataPanelLine_Text* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Text is nil");
    // TODO: Unsupported type for textAlign (MyGUI::Align)
    return luaL_error(L, "Unsupported property 'textAlign' (type: MyGUI::Align)");
}

static int DataPanelLine_Text_get_wordWrap(lua_State* L)
{
    DataPanelLine_Text* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Text is nil");
    lua_pushboolean(L, instance->wordWrap ? 1 : 0);
    return 1;
}

// --- Setters for DataPanelLine_Text ---
static int DataPanelLine_Text_set_editBox(lua_State* L)
{
    DataPanelLine_Text* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Text is nil");
    return luaL_error(L, "Read-only or unsupported setter type for editBox");
}

static int DataPanelLine_Text_set_textAlign(lua_State* L)
{
    DataPanelLine_Text* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Text is nil");
    return luaL_error(L, "Read-only or unsupported setter type for textAlign");
}

static int DataPanelLine_Text_set_wordWrap(lua_State* L)
{
    DataPanelLine_Text* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Text is nil");
    instance->wordWrap = lua_toboolean(L, 2) != 0;
    return 0;
}

int DataPanelLine_TextBinding::_DESTRUCTOR(lua_State* L)
{
    DataPanelLine_Text* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Text is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 202: DataPanelLine_Text* _CONSTRUCTOR(...) - unsupported arg type
  line 203: void createMe(...) - unsupported arg type
  line 204: void _NV_createMe(...) - unsupported arg type
*/

int DataPanelLine_TextBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DataPanelLine_TextBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DataPanelLine_Text object");
    return 1;
}

void DataPanelLine_TextBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DataPanelLine_TextBinding::gc },
        { "__tostring", DataPanelLine_TextBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", DataPanelLine_TextBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        DataPanelLine_TextBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DataPanelLine_TextBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DataPanelLine_Text_get_editBox);
    lua_setfield(L, -2, "editBox");
    lua_pushcfunction(L, DataPanelLine_Text_get_textAlign);
    lua_setfield(L, -2, "textAlign");
    lua_pushcfunction(L, DataPanelLine_Text_get_wordWrap);
    lua_setfield(L, -2, "wordWrap");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DataPanelLine_Text_set_editBox);
    lua_setfield(L, -2, "editBox");
    lua_pushcfunction(L, DataPanelLine_Text_set_textAlign);
    lua_setfield(L, -2, "textAlign");
    lua_pushcfunction(L, DataPanelLine_Text_set_wordWrap);
    lua_setfield(L, -2, "wordWrap");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to DataPanelLine
    // setMetatableParent(L, DataPanelLine_TextBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
