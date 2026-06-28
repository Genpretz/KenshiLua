#include "pch.h"
#include <kenshi/gui/DataPanelLine.h>
#include "DataPanelLine_ButtonBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/HandBinding.h"

namespace KenshiLua
{

static DataPanelLine_Button* getInstance(lua_State* L, int idx)
{
    return checkObject<DataPanelLine_Button>(L, idx, DataPanelLine_ButtonBinding::getMetatableName());
}

// --- Getters for DataPanelLine_Button ---
static int DataPanelLine_Button_get_userData(lua_State* L)
{
    DataPanelLine_Button* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Button is nil");
    return handBinding::push(L, instance->userData);
}

static int DataPanelLine_Button_get_button(lua_State* L)
{
    DataPanelLine_Button* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Button is nil");
    lua_pushlightuserdata(L, (void*)instance->button);
    return 1;
}

static int DataPanelLine_Button_get_buttonWidth(lua_State* L)
{
    DataPanelLine_Button* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Button is nil");
    lua_pushnumber(L, instance->buttonWidth);
    return 1;
}

static int DataPanelLine_Button_get_buttonHeight(lua_State* L)
{
    DataPanelLine_Button* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Button is nil");
    lua_pushnumber(L, instance->buttonHeight);
    return 1;
}

static int DataPanelLine_Button_get_buttonSkin(lua_State* L)
{
    DataPanelLine_Button* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Button is nil");
    lua_pushstring(L, instance->buttonSkin.c_str());
    return 1;
}

// --- Setters for DataPanelLine_Button ---
static int DataPanelLine_Button_set_userData(lua_State* L)
{
    DataPanelLine_Button* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Button is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->userData = *val;
    return 0;
}

static int DataPanelLine_Button_set_button(lua_State* L)
{
    DataPanelLine_Button* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Button is nil");
    return luaL_error(L, "Read-only or unsupported setter type for button");
}

static int DataPanelLine_Button_set_buttonWidth(lua_State* L)
{
    DataPanelLine_Button* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Button is nil");
    instance->buttonWidth = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_Button_set_buttonHeight(lua_State* L)
{
    DataPanelLine_Button* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Button is nil");
    instance->buttonHeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_Button_set_buttonSkin(lua_State* L)
{
    DataPanelLine_Button* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Button is nil");
    instance->buttonSkin = luaL_checkstring(L, 2);
    return 0;
}

int DataPanelLine_ButtonBinding::_CONSTRUCTOR(lua_State* L)
{
    DataPanelLine_Button* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Button is nil");

    std::string a = luaL_checkstring(L, 2);
    std::string b = luaL_checkstring(L, 3);
    int cat = (int)luaL_checkinteger(L, 4);
    float w = (float)luaL_checknumber(L, 5);
    std::string skin = luaL_checkstring(L, 6);
    DataPanelLine_Button* result = instance->_CONSTRUCTOR(a, b, cat, w, skin);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DataPanelLine_ButtonBinding::_DESTRUCTOR(lua_State* L)
{
    DataPanelLine_Button* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Button is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 139: void pressCallback(...) - unsupported arg type
  line 140: hand getUserData(...) - unsupported return type
  line 141: hand _NV_getUserData(...) - unsupported return type
  line 147: void createMe(...) - unsupported arg type
  line 148: void _NV_createMe(...) - unsupported arg type
  line 149: void setToolTipMainBar(...) - overloaded method
  line 150: void _NV_setToolTipMainBar(...) - overloaded method
  line 151: void setToolTipMainBar(...) - overloaded method
  line 152: void _NV_setToolTipMainBar(...) - overloaded method
*/

int DataPanelLine_ButtonBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DataPanelLine_ButtonBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DataPanelLine_Button object");
    return 1;
}

void DataPanelLine_ButtonBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DataPanelLine_ButtonBinding::gc },
        { "__tostring", DataPanelLine_ButtonBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", DataPanelLine_ButtonBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", DataPanelLine_ButtonBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        DataPanelLine_ButtonBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DataPanelLine_ButtonBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DataPanelLine_Button_get_userData);
    lua_setfield(L, -2, "userData");
    lua_pushcfunction(L, DataPanelLine_Button_get_button);
    lua_setfield(L, -2, "button");
    lua_pushcfunction(L, DataPanelLine_Button_get_buttonWidth);
    lua_setfield(L, -2, "buttonWidth");
    lua_pushcfunction(L, DataPanelLine_Button_get_buttonHeight);
    lua_setfield(L, -2, "buttonHeight");
    lua_pushcfunction(L, DataPanelLine_Button_get_buttonSkin);
    lua_setfield(L, -2, "buttonSkin");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DataPanelLine_Button_set_userData);
    lua_setfield(L, -2, "userData");
    lua_pushcfunction(L, DataPanelLine_Button_set_button);
    lua_setfield(L, -2, "button");
    lua_pushcfunction(L, DataPanelLine_Button_set_buttonWidth);
    lua_setfield(L, -2, "buttonWidth");
    lua_pushcfunction(L, DataPanelLine_Button_set_buttonHeight);
    lua_setfield(L, -2, "buttonHeight");
    lua_pushcfunction(L, DataPanelLine_Button_set_buttonSkin);
    lua_setfield(L, -2, "buttonSkin");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to DataPanelLine
    setMetatableParent(L, DataPanelLine_ButtonBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua