#include "pch.h"
#include <kenshi/gui/DataPanelLine.h>
#include "DataPanelLine_SliderBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"

namespace KenshiLua
{

static DataPanelLine_Slider* getInstance(lua_State* L, int idx)
{
    return checkObject<DataPanelLine_Slider>(L, idx, DataPanelLine_SliderBinding::getMetatableName());
}

// --- Getters for DataPanelLine_Slider ---
static int DataPanelLine_Slider_get_scale(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");
    lua_pushnumber(L, instance->scale);
    return 1;
}

static int DataPanelLine_Slider_get_min(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");
    lua_pushnumber(L, instance->min);
    return 1;
}

static int DataPanelLine_Slider_get_max(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");
    lua_pushnumber(L, instance->max);
    return 1;
}

static int DataPanelLine_Slider_get_valuePtr(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");
    lua_pushlightuserdata(L, (void*)instance->valuePtr);
    return 1;
}

static int DataPanelLine_Slider_get_slider(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");
    lua_pushlightuserdata(L, (void*)instance->slider);
    return 1;
}

// --- Setters for DataPanelLine_Slider ---
static int DataPanelLine_Slider_set_scale(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");
    instance->scale = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_Slider_set_min(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");
    instance->min = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_Slider_set_max(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");
    instance->max = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_Slider_set_valuePtr(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");
    return luaL_error(L, "Read-only or unsupported setter type for valuePtr");
}

static int DataPanelLine_Slider_set_slider(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");
    return luaL_error(L, "Read-only or unsupported setter type for slider");
}

int DataPanelLine_SliderBinding::_CONSTRUCTOR(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");

    std::string key = luaL_checkstring(L, 2);
    std::string text = luaL_checkstring(L, 3);
    float min = (float)luaL_checknumber(L, 4);
    float max = (float)luaL_checknumber(L, 5);
    int category = (int)luaL_checkinteger(L, 6);
    float scale = (float)luaL_checknumber(L, 7);
    DataPanelLine_Slider* result = instance->_CONSTRUCTOR(key, text, min, max, category, scale);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DataPanelLine_SliderBinding::setValue(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");

    float value = (float)luaL_checknumber(L, 2);
    instance->setValue(value);
    return 0;
}

int DataPanelLine_SliderBinding::getValue(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");

    float result = instance->getValue();
    lua_pushnumber(L, result);
    return 1;
}

int DataPanelLine_SliderBinding::refresh(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");

    instance->refresh();
    return 0;
}

int DataPanelLine_SliderBinding::_NV_refresh(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");

    instance->_NV_refresh();
    return 0;
}

int DataPanelLine_SliderBinding::_DESTRUCTOR(lua_State* L)
{
    DataPanelLine_Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Slider is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 251: void sliderValueChanged(...) - unsupported arg type
  line 257: void updateValuePtr(...) - unsupported arg type
  line 258: void _NV_updateValuePtr(...) - unsupported arg type
  line 263: void createMe(...) - unsupported arg type
  line 264: void _NV_createMe(...) - unsupported arg type
*/

int DataPanelLine_SliderBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DataPanelLine_SliderBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DataPanelLine_Slider object");
    return 1;
}

void DataPanelLine_SliderBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DataPanelLine_SliderBinding::gc },
        { "__tostring", DataPanelLine_SliderBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", DataPanelLine_SliderBinding::_CONSTRUCTOR },
        { "setValue", DataPanelLine_SliderBinding::setValue },
        { "getValue", DataPanelLine_SliderBinding::getValue },
        { "refresh", DataPanelLine_SliderBinding::refresh },
        { "_NV_refresh", DataPanelLine_SliderBinding::_NV_refresh },
        { "_DESTRUCTOR", DataPanelLine_SliderBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        DataPanelLine_SliderBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DataPanelLine_SliderBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DataPanelLine_Slider_get_scale);
    lua_setfield(L, -2, "scale");
    lua_pushcfunction(L, DataPanelLine_Slider_get_min);
    lua_setfield(L, -2, "min");
    lua_pushcfunction(L, DataPanelLine_Slider_get_max);
    lua_setfield(L, -2, "max");
    lua_pushcfunction(L, DataPanelLine_Slider_get_valuePtr);
    lua_setfield(L, -2, "valuePtr");
    lua_pushcfunction(L, DataPanelLine_Slider_get_slider);
    lua_setfield(L, -2, "slider");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DataPanelLine_Slider_set_scale);
    lua_setfield(L, -2, "scale");
    lua_pushcfunction(L, DataPanelLine_Slider_set_min);
    lua_setfield(L, -2, "min");
    lua_pushcfunction(L, DataPanelLine_Slider_set_max);
    lua_setfield(L, -2, "max");
    lua_pushcfunction(L, DataPanelLine_Slider_set_valuePtr);
    lua_setfield(L, -2, "valuePtr");
    lua_pushcfunction(L, DataPanelLine_Slider_set_slider);
    lua_setfield(L, -2, "slider");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to DataPanelLine
    // setMetatableParent(L, DataPanelLine_SliderBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
