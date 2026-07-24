#include "pch.h"
#include "kenshi\gui\DataPanelLine.h"
#include "DataPanelLineBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Gui/ToolTipBinding.h"

namespace KenshiLua
{

static DataPanelLine* getInstance(lua_State* L, int idx)
{
    return checkObject<DataPanelLine>(L, idx, DataPanelLineBinding::getMetatableName());
}

// --- Getters for DataPanelLine ---
static int DataPanelLine_get_w1(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    lua_pushlightuserdata(L, (void*)instance->w1);
    return 1;
}

static int DataPanelLine_get_w2(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    lua_pushlightuserdata(L, (void*)instance->w2);
    return 1;
}

static int DataPanelLine_get_category(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    lua_pushinteger(L, instance->category);
    return 1;
}

static int DataPanelLine_get_keyValue(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    lua_pushstring(L, instance->keyValue.c_str());
    return 1;
}

static int DataPanelLine_get_s1(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    lua_pushstring(L, instance->s1.c_str());
    return 1;
}

static int DataPanelLine_get_s2(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    lua_pushstring(L, instance->s2.c_str());
    return 1;
}

static int DataPanelLine_get_lo(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    lua_pushinteger(L, instance->lo);
    return 1;
}

static int DataPanelLine_get_hi(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    lua_pushinteger(L, instance->hi);
    return 1;
}

static int DataPanelLine_get_skinW1(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    lua_pushstring(L, instance->skinW1.c_str());
    return 1;
}

static int DataPanelLine_get_skinW2(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    lua_pushstring(L, instance->skinW2.c_str());
    return 1;
}

static int DataPanelLine_get_classType(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    lua_pushinteger(L, (lua_Integer)instance->classType);
    return 1;
}

// --- Setters for DataPanelLine ---
static int DataPanelLine_set_category(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    instance->category = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DataPanelLine_set_keyValue(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    instance->keyValue = luaL_checkstring(L, 2);
    return 0;
}

static int DataPanelLine_set_s1(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    instance->s1 = luaL_checkstring(L, 2);
    return 0;
}

static int DataPanelLine_set_s2(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    instance->s2 = luaL_checkstring(L, 2);
    return 0;
}

static int DataPanelLine_set_lo(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    instance->lo = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DataPanelLine_set_hi(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    instance->hi = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DataPanelLine_set_skinW1(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    instance->skinW1 = luaL_checkstring(L, 2);
    return 0;
}

static int DataPanelLine_set_skinW2(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    instance->skinW2 = luaL_checkstring(L, 2);
    return 0;
}

static int DataPanelLine_set_classType(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");
    instance->classType = (DataPanelLine::LineType)luaL_checkinteger(L, 2);
    return 0;
}

int DataPanelLineBinding::_DESTRUCTOR(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int DataPanelLineBinding::setVisible(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setVisible(on);
    return 0;
}

int DataPanelLineBinding::_NV_setVisible(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(on);
    return 0;
}

int DataPanelLineBinding::setEnabled(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setEnabled(on);
    return 0;
}

int DataPanelLineBinding::_NV_setEnabled(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setEnabled(on);
    return 0;
}

int DataPanelLineBinding::refresh(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    instance->refresh();
    return 0;
}

int DataPanelLineBinding::_NV_refresh(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    instance->_NV_refresh();
    return 0;
}

int DataPanelLineBinding::createMe(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    DatapanelGUI* parent = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    float top = (float)luaL_checknumber(L, 3);
    bool lastLine = lua_toboolean(L, 4) != 0;
    instance->createMe(parent, top, lastLine);
    return 0;
}

int DataPanelLineBinding::_NV_createMe(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    DatapanelGUI* parent = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    float top = (float)luaL_checknumber(L, 3);
    bool lastLine = lua_toboolean(L, 4) != 0;
    instance->_NV_createMe(parent, top, lastLine);
    return 0;
}

int DataPanelLineBinding::resize(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    int width = (int)luaL_checkinteger(L, 2);
    int height = (int)luaL_checkinteger(L, 3);
    instance->resize(width, height);
    return 0;
}

int DataPanelLineBinding::_NV_resize(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    int width = (int)luaL_checkinteger(L, 2);
    int height = (int)luaL_checkinteger(L, 3);
    instance->_NV_resize(width, height);
    return 0;
}

int DataPanelLineBinding::getBottom(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    int result = instance->getBottom();
    lua_pushinteger(L, result);
    return 1;
}

int DataPanelLineBinding::_NV_getBottom(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    int result = instance->_NV_getBottom();
    lua_pushinteger(L, result);
    return 1;
}

int DataPanelLineBinding::getType(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    DataPanelLine::LineType result = instance->getType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int DataPanelLineBinding::getUserData(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    hand result = instance->getUserData();
    return handBinding::push(L, result);
}

int DataPanelLineBinding::_NV_getUserData(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    hand result = instance->_NV_getUserData();
    return handBinding::push(L, result);
}

int DataPanelLineBinding::getNumWidgets(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    int result = instance->getNumWidgets();
    lua_pushinteger(L, result);
    return 1;
}

int DataPanelLineBinding::getWidget(lua_State* L)
{
    DataPanelLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine is nil");

    int index = (int)luaL_checkinteger(L, 2);
    MyGUI::Widget* result = instance->getWidget(index);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 35: DataPanelLine* _CONSTRUCTOR(...) - overloaded method
  line 37: DataPanelLine* _CONSTRUCTOR(...) - overloaded method
  line 39: DataPanelLine* _CONSTRUCTOR(...) - overloaded method
  line 48: void updateValuePtr(...) - unsupported arg type
  line 49: void _NV_updateValuePtr(...) - unsupported arg type
  line 51: void setToolTip(...) - overloaded method
  line 52: void _NV_setToolTip(...) - overloaded method
  line 53: void setToolTip(...) - overloaded method
  line 54: void _NV_setToolTip(...) - overloaded method
  line 55: void setToolTipMainBar(...) - overloaded method
  line 56: void _NV_setToolTipMainBar(...) - overloaded method
  line 57: void setToolTipMainBar(...) - overloaded method
  line 58: void _NV_setToolTipMainBar(...) - overloaded method
*/

/*
Skipped properties needing manual binding:
  line 73: callback (MyGUI::delegates::CDelegate1<DataPanelLine*>) - unsupported type
  line 81: widgets (Ogre::vector<MyGUI::Widget*>::type) - unsupported type
*/

int DataPanelLineBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DataPanelLineBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DataPanelLine object");
    return 1;
}

void DataPanelLineBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DataPanelLineBinding::gc },
        { "__tostring", DataPanelLineBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", DataPanelLineBinding::_DESTRUCTOR },
        { "setVisible", DataPanelLineBinding::setVisible },
        { "_NV_setVisible", DataPanelLineBinding::_NV_setVisible },
        { "setEnabled", DataPanelLineBinding::setEnabled },
        { "_NV_setEnabled", DataPanelLineBinding::_NV_setEnabled },
        { "refresh", DataPanelLineBinding::refresh },
        { "_NV_refresh", DataPanelLineBinding::_NV_refresh },
        { "createMe", DataPanelLineBinding::createMe },
        { "_NV_createMe", DataPanelLineBinding::_NV_createMe },
        { "resize", DataPanelLineBinding::resize },
        { "_NV_resize", DataPanelLineBinding::_NV_resize },
        { "getBottom", DataPanelLineBinding::getBottom },
        { "_NV_getBottom", DataPanelLineBinding::_NV_getBottom },
        { "getType", DataPanelLineBinding::getType },
        { "getUserData", DataPanelLineBinding::getUserData },
        { "_NV_getUserData", DataPanelLineBinding::_NV_getUserData },
        { "getNumWidgets", DataPanelLineBinding::getNumWidgets },
        { "getWidget", DataPanelLineBinding::getWidget },
        { 0, 0 }
    };

    registerClass(
        L, 
        DataPanelLineBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DataPanelLineBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "w1", DataPanelLine_get_w1);
    registerGetter(L, "w2", DataPanelLine_get_w2);
    registerGetter(L, "category", DataPanelLine_get_category);
    registerGetter(L, "keyValue", DataPanelLine_get_keyValue);
    registerGetter(L, "s1", DataPanelLine_get_s1);
    registerGetter(L, "s2", DataPanelLine_get_s2);
    registerGetter(L, "lo", DataPanelLine_get_lo);
    registerGetter(L, "hi", DataPanelLine_get_hi);
    registerGetter(L, "skinW1", DataPanelLine_get_skinW1);
    registerGetter(L, "skinW2", DataPanelLine_get_skinW2);
    registerGetter(L, "classType", DataPanelLine_get_classType);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "category", DataPanelLine_set_category);
    registerSetter(L, "keyValue", DataPanelLine_set_keyValue);
    registerSetter(L, "s1", DataPanelLine_set_s1);
    registerSetter(L, "s2", DataPanelLine_set_s2);
    registerSetter(L, "lo", DataPanelLine_set_lo);
    registerSetter(L, "hi", DataPanelLine_set_hi);
    registerSetter(L, "skinW1", DataPanelLine_set_skinW1);
    registerSetter(L, "skinW2", DataPanelLine_set_skinW2);
    registerSetter(L, "classType", DataPanelLine_set_classType);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, DataPanelLineBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua