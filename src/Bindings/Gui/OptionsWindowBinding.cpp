#include "pch.h"
#include "Bindings/Gui/DataPanelLine_KeyConfigBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

#include <kenshi/gui/OptionsWindow.h>
#include "OptionsWindowBinding.h"
#include "GUIWindowBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static OptionsWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<OptionsWindow>(L, idx, OptionsWindowBinding::getMetatableName());
}

// --- Getters for OptionsWindow ---
static int OptionsWindow_get_invertX(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    lua_pushboolean(L, instance->invertX ? 1 : 0);
    return 1;
}

static int OptionsWindow_get_invertY(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    lua_pushboolean(L, instance->invertY ? 1 : 0);
    return 1;
}

static int OptionsWindow_get_resolutionIndex(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    lua_pushinteger(L, instance->resolutionIndex);
    return 1;
}

static int OptionsWindow_get_keyConfig(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    return pushObject<DataPanelLine_KeyConfig>(L, instance->keyConfig, DataPanelLine_KeyConfigBinding::getMetatableName());
}

static int OptionsWindow_get_keysDatapanel(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->keysDatapanel, DatapanelGUIBinding::getMetatableName());
}

static int OptionsWindow_get_tabs(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->tabs);
    return 1;
}

static int OptionsWindow_get_created(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    lua_pushboolean(L, instance->created ? 1 : 0);
    return 1;
}

static int OptionsWindow_get_tooltip(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->tooltip);
    return 1;
}

static int OptionsWindow_get_previewFontSize(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    lua_pushboolean(L, instance->previewFontSize ? 1 : 0);
    return 1;
}

// --- Setters for OptionsWindow ---
static int OptionsWindow_set_invertX(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    instance->invertX = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsWindow_set_invertY(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    instance->invertY = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsWindow_set_resolutionIndex(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    instance->resolutionIndex = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int OptionsWindow_set_created(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    instance->created = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsWindow_set_previewFontSize(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    instance->previewFontSize = lua_toboolean(L, 2) != 0;
    return 0;
}

int OptionsWindowBinding::_NV_show(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->_NV_show(value);
    return 0;
}

int OptionsWindowBinding::hide(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    instance->hide();
    return 0;
}

int OptionsWindowBinding::toggle(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    instance->toggle();
    return 0;
}

int OptionsWindowBinding::isVisible(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    bool result = instance->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OptionsWindowBinding::waitingForKey(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    bool result = instance->waitingForKey();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OptionsWindowBinding::update(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    instance->update();
    return 0;
}

int OptionsWindowBinding::_NV_update(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    instance->_NV_update();
    return 0;
}

int OptionsWindowBinding::_CONSTRUCTOR(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    OptionsWindow* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int OptionsWindowBinding::_DESTRUCTOR(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int OptionsWindowBinding::saveOptions(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    instance->saveOptions();
    return 0;
}

int OptionsWindowBinding::create(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    instance->create();
    return 0;
}

int OptionsWindowBinding::updateResolutions(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    instance->updateResolutions();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 19: OptionsWindow* getSingleton(...) - static method
  line 20: void show(...) - overloaded method
  line 22: void show(...) - overloaded method
  line 27: void setKey(...) - non-string reference arg
  line 35: void saveLocationChanged(...) - unsupported arg type
  line 36: void changeFontSize(...) - unsupported arg type
  line 37: void changeVolume(...) - unsupported arg type
  line 38: void toggleNames(...) - unsupported arg type
  line 39: void resetTutorials(...) - unsupported arg type
  line 40: void toggleTutorials(...) - unsupported arg type
  line 41: void changeDistances(...) - unsupported arg type
  line 42: void toggleCompositor(...) - unsupported arg type
  line 43: void resetAllKeys(...) - unsupported arg type
  line 47: void closeButton(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 50: resolutions (lektor<std::string >) - unsupported type
*/

int OptionsWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int OptionsWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.OptionsWindow object");
    return 1;
}

void OptionsWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       OptionsWindowBinding::gc },
        { "__tostring", OptionsWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_NV_show", OptionsWindowBinding::_NV_show },
        { "hide", OptionsWindowBinding::hide },
        { "toggle", OptionsWindowBinding::toggle },
        { "isVisible", OptionsWindowBinding::isVisible },
        { "waitingForKey", OptionsWindowBinding::waitingForKey },
        { "update", OptionsWindowBinding::update },
        { "_NV_update", OptionsWindowBinding::_NV_update },
        { "_CONSTRUCTOR", OptionsWindowBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", OptionsWindowBinding::_DESTRUCTOR },
        { "saveOptions", OptionsWindowBinding::saveOptions },
        { "create", OptionsWindowBinding::create },
        { "updateResolutions", OptionsWindowBinding::updateResolutions },
        { 0, 0 }
    };

    registerClass(
        L, 
        OptionsWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, OptionsWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, OptionsWindow_get_invertX);
    lua_setfield(L, -2, "invertX");
    lua_pushcfunction(L, OptionsWindow_get_invertY);
    lua_setfield(L, -2, "invertY");
    lua_pushcfunction(L, OptionsWindow_get_resolutionIndex);
    lua_setfield(L, -2, "resolutionIndex");
    lua_pushcfunction(L, OptionsWindow_get_keyConfig);
    lua_setfield(L, -2, "keyConfig");
    lua_pushcfunction(L, OptionsWindow_get_keysDatapanel);
    lua_setfield(L, -2, "keysDatapanel");
    lua_pushcfunction(L, OptionsWindow_get_tabs);
    lua_setfield(L, -2, "tabs");
    lua_pushcfunction(L, OptionsWindow_get_created);
    lua_setfield(L, -2, "created");
    lua_pushcfunction(L, OptionsWindow_get_tooltip);
    lua_setfield(L, -2, "tooltip");
    lua_pushcfunction(L, OptionsWindow_get_previewFontSize);
    lua_setfield(L, -2, "previewFontSize");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, OptionsWindow_set_invertX);
    lua_setfield(L, -2, "invertX");
    lua_pushcfunction(L, OptionsWindow_set_invertY);
    lua_setfield(L, -2, "invertY");
    lua_pushcfunction(L, OptionsWindow_set_resolutionIndex);
    lua_setfield(L, -2, "resolutionIndex");
    lua_pushcfunction(L, OptionsWindow_set_created);
    lua_setfield(L, -2, "created");
    lua_pushcfunction(L, OptionsWindow_set_previewFontSize);
    lua_setfield(L, -2, "previewFontSize");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GUIWindow
    // setMetatableParent(L, OptionsWindowBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
