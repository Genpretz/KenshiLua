#include "pch.h"
#include "kenshi\gui\OptionsWindow.h"
#include "OptionsWindowBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/Gui/DataPanelLine_KeyConfigBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Gui/GUIWindowBinding.h"
#include "Bindings/Gui/ToolTipBinding.h"
#include "Bindings/Util/LektorBinding.h"

namespace KenshiLua
{

static OptionsWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<OptionsWindow>(L, idx, OptionsWindowBinding::getMetatableName());
}

// --- Getters for OptionsWindow ---
static int OptionsWindow_get_resolutions(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    return pushObject<lektor<std::string>>(L, &instance->resolutions, LektorStringBinding<std::string>::metaName);
}

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
    return pushObject<ToolTip>(L, instance->tooltip, ToolTipBinding::getMetatableName());
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

static int OptionsWindow_set_keyConfig(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    instance->keyConfig = lua_isnoneornil(L, 2) ? nullptr : checkObject<DataPanelLine_KeyConfig>(L, 2, DataPanelLine_KeyConfigBinding::getMetatableName());
    return 0;
}

static int OptionsWindow_set_keysDatapanel(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    instance->keysDatapanel = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int OptionsWindow_set_created(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    instance->created = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsWindow_set_tooltip(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");
    instance->tooltip = lua_isnoneornil(L, 2) ? nullptr : checkObject<ToolTip>(L, 2, ToolTipBinding::getMetatableName());
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

int OptionsWindowBinding::saveLocationChanged(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->saveLocationChanged(line);
    return 0;
}

int OptionsWindowBinding::changeFontSize(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->changeFontSize(line);
    return 0;
}

int OptionsWindowBinding::changeVolume(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->changeVolume(line);
    return 0;
}

int OptionsWindowBinding::toggleNames(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->toggleNames(line);
    return 0;
}

int OptionsWindowBinding::resetTutorials(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->resetTutorials(_a1);
    return 0;
}

int OptionsWindowBinding::toggleTutorials(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->toggleTutorials(_a1);
    return 0;
}

int OptionsWindowBinding::changeDistances(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->changeDistances(_a1);
    return 0;
}

int OptionsWindowBinding::toggleCompositor(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    DataPanelLine* l = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->toggleCompositor(l);
    return 0;
}

int OptionsWindowBinding::resetAllKeys(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->resetAllKeys(_a1);
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

int OptionsWindowBinding::show(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    if (lua_gettop(L) >= 2)
    {
        bool value = lua_toboolean(L, 2) != 0;
        instance->show(value);
    }
    else
    {
        instance->show();
    }
    return 0;
}

int OptionsWindowBinding::setKey(lua_State* L)
{
    OptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsWindow is nil");

    OIS::KeyCode code = (OIS::KeyCode)luaL_checkinteger(L, 2);
    instance->setKey(code);
    return 0;
}

int OptionsWindowBinding::getSingleton(lua_State* L)
{
    OptionsWindow* result = OptionsWindow::getSingleton();
    return pushObject<OptionsWindow>(L, result, OptionsWindowBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 47: void closeButton(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - OptionsWindow_get_tabs: MyGUI::TabControl* (unbound pointer)
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
        { "show", OptionsWindowBinding::show },
        { "_NV_show", OptionsWindowBinding::_NV_show },
        { "hide", OptionsWindowBinding::hide },
        { "toggle", OptionsWindowBinding::toggle },
        { "isVisible", OptionsWindowBinding::isVisible },
        { "waitingForKey", OptionsWindowBinding::waitingForKey },
        { "setKey", OptionsWindowBinding::setKey },
        { "update", OptionsWindowBinding::update },
        { "_NV_update", OptionsWindowBinding::_NV_update },
        { "saveLocationChanged", OptionsWindowBinding::saveLocationChanged },
        { "changeFontSize", OptionsWindowBinding::changeFontSize },
        { "changeVolume", OptionsWindowBinding::changeVolume },
        { "toggleNames", OptionsWindowBinding::toggleNames },
        { "resetTutorials", OptionsWindowBinding::resetTutorials },
        { "toggleTutorials", OptionsWindowBinding::toggleTutorials },
        { "changeDistances", OptionsWindowBinding::changeDistances },
        { "toggleCompositor", OptionsWindowBinding::toggleCompositor },
        { "resetAllKeys", OptionsWindowBinding::resetAllKeys },
        { "saveOptions", OptionsWindowBinding::saveOptions },
        { "create", OptionsWindowBinding::create },
        { "updateResolutions", OptionsWindowBinding::updateResolutions },
        { "getSingleton", OptionsWindowBinding::getSingleton },
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
    registerGetter(L, "resolutions", OptionsWindow_get_resolutions);
    registerGetter(L, "invertX", OptionsWindow_get_invertX);
    registerGetter(L, "invertY", OptionsWindow_get_invertY);
    registerGetter(L, "resolutionIndex", OptionsWindow_get_resolutionIndex);
    registerGetter(L, "keyConfig", OptionsWindow_get_keyConfig);
    registerGetter(L, "keysDatapanel", OptionsWindow_get_keysDatapanel);
    registerGetter(L, "tabs", OptionsWindow_get_tabs);
    registerGetter(L, "created", OptionsWindow_get_created);
    registerGetter(L, "tooltip", OptionsWindow_get_tooltip);
    registerGetter(L, "previewFontSize", OptionsWindow_get_previewFontSize);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "invertX", OptionsWindow_set_invertX);
    registerSetter(L, "invertY", OptionsWindow_set_invertY);
    registerSetter(L, "resolutionIndex", OptionsWindow_set_resolutionIndex);
    registerSetter(L, "keyConfig", OptionsWindow_set_keyConfig);
    registerSetter(L, "keysDatapanel", OptionsWindow_set_keysDatapanel);
    registerSetter(L, "created", OptionsWindow_set_created);
    registerSetter(L, "tooltip", OptionsWindow_set_tooltip);
    registerSetter(L, "previewFontSize", OptionsWindow_set_previewFontSize);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "getSingleton", OptionsWindowBinding::getSingleton);
    lua_setglobal(L, "OptionsWindow");
}

} // namespace KenshiLua