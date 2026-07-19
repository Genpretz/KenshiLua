#include "pch.h"
#include <kenshi/gui/DataPanelLine.h>
#include "DataPanelLine_ProgressBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"

namespace KenshiLua
{

static DataPanelLine_Progress* getInstance(lua_State* L, int idx)
{
    return checkObject<DataPanelLine_Progress>(L, idx, DataPanelLine_ProgressBinding::getMetatableName());
}

// --- Getters for DataPanelLine_Progress ---
static int DataPanelLine_Progress_get_textBox(lua_State* L)
{
    DataPanelLine_Progress* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Progress is nil");
    lua_pushlightuserdata(L, (void*)instance->textBox);
    return 1;
}

static int DataPanelLine_Progress_get_progress(lua_State* L)
{
    DataPanelLine_Progress* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Progress is nil");
    lua_pushlightuserdata(L, (void*)instance->progress);
    return 1;
}

static int DataPanelLine_Progress_get_progressText(lua_State* L)
{
    DataPanelLine_Progress* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Progress is nil");
    lua_pushlightuserdata(L, (void*)instance->progressText);
    return 1;
}

static int DataPanelLine_Progress_get_showKey(lua_State* L)
{
    DataPanelLine_Progress* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Progress is nil");
    lua_pushboolean(L, instance->showKey ? 1 : 0);
    return 1;
}

// --- Setters for DataPanelLine_Progress ---
static int DataPanelLine_Progress_set_textBox(lua_State* L)
{
    DataPanelLine_Progress* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Progress is nil");
    return luaL_error(L, "Read-only or unsupported setter type for textBox");
}

static int DataPanelLine_Progress_set_progress(lua_State* L)
{
    DataPanelLine_Progress* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Progress is nil");
    return luaL_error(L, "Read-only or unsupported setter type for progress");
}

static int DataPanelLine_Progress_set_progressText(lua_State* L)
{
    DataPanelLine_Progress* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Progress is nil");
    return luaL_error(L, "Read-only or unsupported setter type for progressText");
}

static int DataPanelLine_Progress_set_showKey(lua_State* L)
{
    DataPanelLine_Progress* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Progress is nil");
    instance->showKey = lua_toboolean(L, 2) != 0;
    return 0;
}

int DataPanelLine_ProgressBinding::setProgress(lua_State* L)
{
    DataPanelLine_Progress* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Progress is nil");

    float value = (float)luaL_checknumber(L, 2);
    std::string text = luaL_checkstring(L, 3);
    instance->setProgress(value, text);
    return 0;
}

int DataPanelLine_ProgressBinding::_CONSTRUCTOR(lua_State* L)
{
    DataPanelLine_Progress* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Progress is nil");

    std::string key = luaL_checkstring(L, 2);
    int category = (int)luaL_checkinteger(L, 3);
    bool showKey = lua_toboolean(L, 4) != 0;
    DataPanelLine_Progress* result = instance->_CONSTRUCTOR(key, category, showKey);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DataPanelLine_ProgressBinding::_DESTRUCTOR(lua_State* L)
{
    DataPanelLine_Progress* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Progress is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 279: void createMe(...) - unsupported arg type
  line 280: void _NV_createMe(...) - unsupported arg type
*/

int DataPanelLine_ProgressBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DataPanelLine_ProgressBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DataPanelLine_Progress object");
    return 1;
}

void DataPanelLine_ProgressBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DataPanelLine_ProgressBinding::gc },
        { "__tostring", DataPanelLine_ProgressBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setProgress", DataPanelLine_ProgressBinding::setProgress },
        { "_CONSTRUCTOR", DataPanelLine_ProgressBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", DataPanelLine_ProgressBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        DataPanelLine_ProgressBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DataPanelLine_ProgressBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DataPanelLine_Progress_get_textBox);
    lua_setfield(L, -2, "textBox");
    lua_pushcfunction(L, DataPanelLine_Progress_get_progress);
    lua_setfield(L, -2, "progress");
    lua_pushcfunction(L, DataPanelLine_Progress_get_progressText);
    lua_setfield(L, -2, "progressText");
    lua_pushcfunction(L, DataPanelLine_Progress_get_showKey);
    lua_setfield(L, -2, "showKey");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DataPanelLine_Progress_set_textBox);
    lua_setfield(L, -2, "textBox");
    lua_pushcfunction(L, DataPanelLine_Progress_set_progress);
    lua_setfield(L, -2, "progress");
    lua_pushcfunction(L, DataPanelLine_Progress_set_progressText);
    lua_setfield(L, -2, "progressText");
    lua_pushcfunction(L, DataPanelLine_Progress_set_showKey);
    lua_setfield(L, -2, "showKey");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to DataPanelLine
    // setMetatableParent(L, DataPanelLine_ProgressBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
