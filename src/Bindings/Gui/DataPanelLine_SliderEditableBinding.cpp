#include "pch.h"
#include <kenshi/gui/DataPanelLine.h>
#include "DataPanelLine_SliderEditableBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"

namespace KenshiLua
{

static DataPanelLine_SliderEditable* getInstance(lua_State* L, int idx)
{
    return checkObject<DataPanelLine_SliderEditable>(L, idx, DataPanelLine_SliderEditableBinding::getMetatableName());
}

// --- Getters for DataPanelLine_SliderEditable ---
static int DataPanelLine_SliderEditable_get_width(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    lua_pushnumber(L, instance->width);
    return 1;
}

static int DataPanelLine_SliderEditable_get_showName(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    lua_pushboolean(L, instance->showName ? 1 : 0);
    return 1;
}

static int DataPanelLine_SliderEditable_get_min(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    lua_pushnumber(L, instance->min);
    return 1;
}

static int DataPanelLine_SliderEditable_get_max(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    lua_pushnumber(L, instance->max);
    return 1;
}

static int DataPanelLine_SliderEditable_get_valuePtr(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    lua_pushlightuserdata(L, (void*)instance->valuePtr);
    return 1;
}

static int DataPanelLine_SliderEditable_get_scale(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    lua_pushnumber(L, instance->scale);
    return 1;
}

static int DataPanelLine_SliderEditable_get_nameText(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    lua_pushlightuserdata(L, (void*)instance->nameText);
    return 1;
}

static int DataPanelLine_SliderEditable_get_valueEditBox(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    lua_pushlightuserdata(L, (void*)instance->valueEditBox);
    return 1;
}

static int DataPanelLine_SliderEditable_get_sliderBar(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    lua_pushlightuserdata(L, (void*)instance->sliderBar);
    return 1;
}

// --- Setters for DataPanelLine_SliderEditable ---
static int DataPanelLine_SliderEditable_set_width(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    instance->width = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_SliderEditable_set_showName(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    instance->showName = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DataPanelLine_SliderEditable_set_min(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    instance->min = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_SliderEditable_set_max(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    instance->max = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_SliderEditable_set_valuePtr(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    return luaL_error(L, "Read-only or unsupported setter type for valuePtr");
}

static int DataPanelLine_SliderEditable_set_scale(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    instance->scale = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_SliderEditable_set_nameText(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    return luaL_error(L, "Read-only or unsupported setter type for nameText");
}

static int DataPanelLine_SliderEditable_set_valueEditBox(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    return luaL_error(L, "Read-only or unsupported setter type for valueEditBox");
}

static int DataPanelLine_SliderEditable_set_sliderBar(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");
    return luaL_error(L, "Read-only or unsupported setter type for sliderBar");
}

int DataPanelLine_SliderEditableBinding::getSlider(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");

    MyGUI::ScrollBar* result = instance->getSlider();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DataPanelLine_SliderEditableBinding::getEditBox(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");

    MyGUI::EditBox* result = instance->getEditBox();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DataPanelLine_SliderEditableBinding::setValue(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");

    float v = (float)luaL_checknumber(L, 2);
    instance->setValue(v);
    return 0;
}

int DataPanelLine_SliderEditableBinding::refresh(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");

    instance->refresh();
    return 0;
}

int DataPanelLine_SliderEditableBinding::_NV_refresh(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");

    instance->_NV_refresh();
    return 0;
}

int DataPanelLine_SliderEditableBinding::setPrecision(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");

    int dp = (int)luaL_checkinteger(L, 2);
    instance->setPrecision(dp);
    return 0;
}

int DataPanelLine_SliderEditableBinding::_DESTRUCTOR(lua_State* L)
{
    DataPanelLine_SliderEditable* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_SliderEditable is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 163: void setEditableValuePtr(...) - pointer arg
  line 167: void updateValuePtr(...) - unsupported arg type
  line 168: void _NV_updateValuePtr(...) - unsupported arg type
  line 175: DataPanelLine_SliderEditable* _CONSTRUCTOR(...) - pointer arg
  line 176: void createMe(...) - unsupported arg type
  line 177: void _NV_createMe(...) - unsupported arg type
  line 178: void editCallback(...) - unsupported arg type
  line 179: void sliderCallback(...) - unsupported arg type
*/

int DataPanelLine_SliderEditableBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DataPanelLine_SliderEditableBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DataPanelLine_SliderEditable object");
    return 1;
}

void DataPanelLine_SliderEditableBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DataPanelLine_SliderEditableBinding::gc },
        { "__tostring", DataPanelLine_SliderEditableBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getSlider", DataPanelLine_SliderEditableBinding::getSlider },
        { "getEditBox", DataPanelLine_SliderEditableBinding::getEditBox },
        { "setValue", DataPanelLine_SliderEditableBinding::setValue },
        { "refresh", DataPanelLine_SliderEditableBinding::refresh },
        { "_NV_refresh", DataPanelLine_SliderEditableBinding::_NV_refresh },
        { "setPrecision", DataPanelLine_SliderEditableBinding::setPrecision },
        { "_DESTRUCTOR", DataPanelLine_SliderEditableBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        DataPanelLine_SliderEditableBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DataPanelLine_SliderEditableBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DataPanelLine_SliderEditable_get_width);
    lua_setfield(L, -2, "width");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_get_showName);
    lua_setfield(L, -2, "showName");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_get_min);
    lua_setfield(L, -2, "min");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_get_max);
    lua_setfield(L, -2, "max");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_get_valuePtr);
    lua_setfield(L, -2, "valuePtr");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_get_scale);
    lua_setfield(L, -2, "scale");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_get_nameText);
    lua_setfield(L, -2, "nameText");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_get_valueEditBox);
    lua_setfield(L, -2, "valueEditBox");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_get_sliderBar);
    lua_setfield(L, -2, "sliderBar");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DataPanelLine_SliderEditable_set_width);
    lua_setfield(L, -2, "width");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_set_showName);
    lua_setfield(L, -2, "showName");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_set_min);
    lua_setfield(L, -2, "min");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_set_max);
    lua_setfield(L, -2, "max");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_set_valuePtr);
    lua_setfield(L, -2, "valuePtr");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_set_scale);
    lua_setfield(L, -2, "scale");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_set_nameText);
    lua_setfield(L, -2, "nameText");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_set_valueEditBox);
    lua_setfield(L, -2, "valueEditBox");
    lua_pushcfunction(L, DataPanelLine_SliderEditable_set_sliderBar);
    lua_setfield(L, -2, "sliderBar");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to DataPanelLine
    setMetatableParent(L, DataPanelLine_SliderEditableBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua