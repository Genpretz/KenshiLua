#include "pch.h"
#include "kenshi\gui\DataPanelLine.h"
#include "DataPanelLine_TextBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

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

static int DataPanelLine_Text_get_wordWrap(lua_State* L)
{
    DataPanelLine_Text* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Text is nil");
    lua_pushboolean(L, instance->wordWrap ? 1 : 0);
    return 1;
}

// --- Setters for DataPanelLine_Text ---
static int DataPanelLine_Text_set_wordWrap(lua_State* L)
{
    DataPanelLine_Text* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Text is nil");
    instance->wordWrap = lua_toboolean(L, 2) != 0;
    return 0;
}

int DataPanelLine_TextBinding::createMe(lua_State* L)
{
    DataPanelLine_Text* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Text is nil");

    DatapanelGUI* parent = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    float top = (float)luaL_checknumber(L, 3);
    bool lastLine = lua_toboolean(L, 4) != 0;
    instance->createMe(parent, top, lastLine);
    return 0;
}

int DataPanelLine_TextBinding::_NV_createMe(lua_State* L)
{
    DataPanelLine_Text* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Text is nil");

    DatapanelGUI* parent = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    float top = (float)luaL_checknumber(L, 3);
    bool lastLine = lua_toboolean(L, 4) != 0;
    instance->_NV_createMe(parent, top, lastLine);
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
  line 203: DataPanelLine_Text* _CONSTRUCTOR(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 207: textAlign (MyGUI::Align) - unsupported type
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
        { "createMe", DataPanelLine_TextBinding::createMe },
        { "_NV_createMe", DataPanelLine_TextBinding::_NV_createMe },
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
    registerGetter(L, "editBox", DataPanelLine_Text_get_editBox);
    registerGetter(L, "wordWrap", DataPanelLine_Text_get_wordWrap);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "wordWrap", DataPanelLine_Text_set_wordWrap);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to DataPanelLine
    setMetatableParent(L, DataPanelLine_TextBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua