#include "pch.h"
#include "kenshi\gui\DataPanelLine.h"
#include "DataPanelLine_KeyConfigBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

namespace KenshiLua
{

static DataPanelLine_KeyConfig* getInstance(lua_State* L, int idx)
{
    return checkObject<DataPanelLine_KeyConfig>(L, idx, DataPanelLine_KeyConfigBinding::getMetatableName());
}

// --- Getters for DataPanelLine_KeyConfig ---
static int DataPanelLine_KeyConfig_get_btn0(lua_State* L)
{
    DataPanelLine_KeyConfig* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_KeyConfig is nil");
    lua_pushlightuserdata(L, (void*)instance->btn0);
    return 1;
}

static int DataPanelLine_KeyConfig_get_btn1(lua_State* L)
{
    DataPanelLine_KeyConfig* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_KeyConfig is nil");
    lua_pushlightuserdata(L, (void*)instance->btn1);
    return 1;
}

static int DataPanelLine_KeyConfig_get_command(lua_State* L)
{
    DataPanelLine_KeyConfig* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_KeyConfig is nil");
    lua_pushstring(L, instance->command.c_str());
    return 1;
}

// --- Setters for DataPanelLine_KeyConfig ---
static int DataPanelLine_KeyConfig_set_command(lua_State* L)
{
    DataPanelLine_KeyConfig* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_KeyConfig is nil");
    instance->command = luaL_checkstring(L, 2);
    return 0;
}

int DataPanelLine_KeyConfigBinding::_CONSTRUCTOR(lua_State* L)
{
    DataPanelLine_KeyConfig* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_KeyConfig is nil");

    const std::string cmd = luaL_checkstring(L, 2);
    const std::string text = luaL_checkstring(L, 3);
    int cat = (int)luaL_checkinteger(L, 4);
    DataPanelLine_KeyConfig* result = instance->_CONSTRUCTOR(cmd, text, cat);
    return pushObject<DataPanelLine_KeyConfig>(L, result, DataPanelLine_KeyConfigBinding::getMetatableName());
}

int DataPanelLine_KeyConfigBinding::oldKey(lua_State* L)
{
    DataPanelLine_KeyConfig* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_KeyConfig is nil");

    int result = instance->oldKey();
    lua_pushinteger(L, result);
    return 1;
}

int DataPanelLine_KeyConfigBinding::setKey(lua_State* L)
{
    DataPanelLine_KeyConfig* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_KeyConfig is nil");

    const std::string s = luaL_checkstring(L, 2);
    instance->setKey(s);
    return 0;
}

int DataPanelLine_KeyConfigBinding::eraseKey(lua_State* L)
{
    DataPanelLine_KeyConfig* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_KeyConfig is nil");

    const std::string key = luaL_checkstring(L, 2);
    instance->eraseKey(key);
    return 0;
}

int DataPanelLine_KeyConfigBinding::refresh(lua_State* L)
{
    DataPanelLine_KeyConfig* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_KeyConfig is nil");

    instance->refresh();
    return 0;
}

int DataPanelLine_KeyConfigBinding::_NV_refresh(lua_State* L)
{
    DataPanelLine_KeyConfig* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_KeyConfig is nil");

    instance->_NV_refresh();
    return 0;
}

int DataPanelLine_KeyConfigBinding::cancel(lua_State* L)
{
    DataPanelLine_KeyConfig* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_KeyConfig is nil");

    instance->cancel();
    return 0;
}

int DataPanelLine_KeyConfigBinding::createMe(lua_State* L)
{
    DataPanelLine_KeyConfig* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_KeyConfig is nil");

    DatapanelGUI* p = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    float vpos = (float)luaL_checknumber(L, 3);
    bool lastLine = lua_toboolean(L, 4) != 0;
    instance->createMe(p, vpos, lastLine);
    return 0;
}

int DataPanelLine_KeyConfigBinding::_NV_createMe(lua_State* L)
{
    DataPanelLine_KeyConfig* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_KeyConfig is nil");

    DatapanelGUI* p = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    float vpos = (float)luaL_checknumber(L, 3);
    bool lastLine = lua_toboolean(L, 4) != 0;
    instance->_NV_createMe(p, vpos, lastLine);
    return 0;
}

int DataPanelLine_KeyConfigBinding::_DESTRUCTOR(lua_State* L)
{
    DataPanelLine_KeyConfig* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_KeyConfig is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 359: const std::string& getCommand(...) - reference return type
  line 368: void clickButton(...) - unsupported arg type
*/

int DataPanelLine_KeyConfigBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DataPanelLine_KeyConfigBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DataPanelLine_KeyConfig object");
    return 1;
}

void DataPanelLine_KeyConfigBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DataPanelLine_KeyConfigBinding::gc },
        { "__tostring", DataPanelLine_KeyConfigBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", DataPanelLine_KeyConfigBinding::_CONSTRUCTOR },
        { "oldKey", DataPanelLine_KeyConfigBinding::oldKey },
        { "setKey", DataPanelLine_KeyConfigBinding::setKey },
        { "eraseKey", DataPanelLine_KeyConfigBinding::eraseKey },
        { "refresh", DataPanelLine_KeyConfigBinding::refresh },
        { "_NV_refresh", DataPanelLine_KeyConfigBinding::_NV_refresh },
        { "cancel", DataPanelLine_KeyConfigBinding::cancel },
        { "createMe", DataPanelLine_KeyConfigBinding::createMe },
        { "_NV_createMe", DataPanelLine_KeyConfigBinding::_NV_createMe },
        { "_DESTRUCTOR", DataPanelLine_KeyConfigBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        DataPanelLine_KeyConfigBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DataPanelLine_KeyConfigBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "btn0", DataPanelLine_KeyConfig_get_btn0);
    registerGetter(L, "btn1", DataPanelLine_KeyConfig_get_btn1);
    registerGetter(L, "command", DataPanelLine_KeyConfig_get_command);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "command", DataPanelLine_KeyConfig_set_command);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to DataPanelLine
    setMetatableParent(L, DataPanelLine_KeyConfigBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua