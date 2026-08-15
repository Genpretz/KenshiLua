#include "pch.h"
#include "kenshi\gui\TransformWindow.h"
#include "TransformWindowBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/Gui/DataPanelLine_ButtonBinding.h"
#include "Bindings/Gui/DataPanelLine_TextEditableBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/InstanceIDBinding.h"
#include "Bindings/ZoneMapBinding.h"

namespace KenshiLua
{

static TransformWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<TransformWindow>(L, idx, TransformWindowBinding::getMetatableName());
}

// --- Getters for TransformWindow ---
static int TransformWindow_get_window(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->window, DatapanelGUIBinding::getMetatableName());
}

static int TransformWindow_get_windowXValue(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    return pushObject<DataPanelLine_TextEditable>(L, instance->windowXValue, DataPanelLine_TextEditableBinding::getMetatableName());
}

static int TransformWindow_get_windowYValue(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    return pushObject<DataPanelLine_TextEditable>(L, instance->windowYValue, DataPanelLine_TextEditableBinding::getMetatableName());
}

static int TransformWindow_get_windowZValue(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    return pushObject<DataPanelLine_TextEditable>(L, instance->windowZValue, DataPanelLine_TextEditableBinding::getMetatableName());
}

static int TransformWindow_get_modeButton(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    return pushObject<DataPanelLine_Button>(L, instance->modeButton, DataPanelLine_ButtonBinding::getMetatableName());
}

static int TransformWindow_get_axisButton(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    return pushObject<DataPanelLine_Button>(L, instance->axisButton, DataPanelLine_ButtonBinding::getMetatableName());
}

static int TransformWindow_get_revertButton(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    return pushObject<DataPanelLine_Button>(L, instance->revertButton, DataPanelLine_ButtonBinding::getMetatableName());
}

static int TransformWindow_get_node(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->node);
    return 1;
}

static int TransformWindow_get_parentNode(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->parentNode);
    return 1;
}

static int TransformWindow_get_gizmo(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->gizmo);
    return 1;
}

static int TransformWindow_get_mode(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    lua_pushinteger(L, instance->mode);
    return 1;
}

static int TransformWindow_get_coordinateSystem(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    lua_pushinteger(L, instance->coordinateSystem);
    return 1;
}

static int TransformWindow_get_hasScale(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    lua_pushboolean(L, instance->hasScale ? 1 : 0);
    return 1;
}

static int TransformWindow_get_lastZone(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    return pushObject<ZoneMap>(L, instance->lastZone, ZoneMapBinding::getMetatableName());
}

static int TransformWindow_get_currentZone(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    return pushObject<ZoneMap>(L, instance->currentZone, ZoneMapBinding::getMetatableName());
}

static int TransformWindow_get_currentInstance(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    return pushObject<InstanceID>(L, const_cast<InstanceID*>(instance->currentInstance), InstanceIDBinding::getMetatableName());
}

static int TransformWindow_get_changed(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    lua_pushboolean(L, instance->changed ? 1 : 0);
    return 1;
}

static int TransformWindow_get_editChanged(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    lua_pushboolean(L, instance->editChanged ? 1 : 0);
    return 1;
}

static int TransformWindow_get_lastMouse(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    pushVector2(L, instance->lastMouse);
    return 1;
}

// --- Setters for TransformWindow ---
static int TransformWindow_set_window(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->window = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int TransformWindow_set_windowXValue(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->windowXValue = lua_isnoneornil(L, 2) ? nullptr : checkObject<DataPanelLine_TextEditable>(L, 2, DataPanelLine_TextEditableBinding::getMetatableName());
    return 0;
}

static int TransformWindow_set_windowYValue(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->windowYValue = lua_isnoneornil(L, 2) ? nullptr : checkObject<DataPanelLine_TextEditable>(L, 2, DataPanelLine_TextEditableBinding::getMetatableName());
    return 0;
}

static int TransformWindow_set_windowZValue(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->windowZValue = lua_isnoneornil(L, 2) ? nullptr : checkObject<DataPanelLine_TextEditable>(L, 2, DataPanelLine_TextEditableBinding::getMetatableName());
    return 0;
}

static int TransformWindow_set_modeButton(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->modeButton = lua_isnoneornil(L, 2) ? nullptr : checkObject<DataPanelLine_Button>(L, 2, DataPanelLine_ButtonBinding::getMetatableName());
    return 0;
}

static int TransformWindow_set_axisButton(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->axisButton = lua_isnoneornil(L, 2) ? nullptr : checkObject<DataPanelLine_Button>(L, 2, DataPanelLine_ButtonBinding::getMetatableName());
    return 0;
}

static int TransformWindow_set_revertButton(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->revertButton = lua_isnoneornil(L, 2) ? nullptr : checkObject<DataPanelLine_Button>(L, 2, DataPanelLine_ButtonBinding::getMetatableName());
    return 0;
}

static int TransformWindow_set_mode(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->mode = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int TransformWindow_set_coordinateSystem(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->coordinateSystem = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int TransformWindow_set_hasScale(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->hasScale = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TransformWindow_set_lastZone(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->lastZone = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    return 0;
}

static int TransformWindow_set_currentZone(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->currentZone = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    return 0;
}

static int TransformWindow_set_currentInstance(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->currentInstance = lua_isnoneornil(L, 2) ? nullptr : checkObject<InstanceID>(L, 2, InstanceIDBinding::getMetatableName());
    return 0;
}

static int TransformWindow_set_changed(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->changed = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TransformWindow_set_editChanged(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->editChanged = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TransformWindow_set_lastMouse(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    readVector2(L, 2, instance->lastMouse);
    return 0;
}

int TransformWindowBinding::setCaption(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    const std::string s = luaL_checkstring(L, 2);
    instance->setCaption(s);
    return 0;
}

int TransformWindowBinding::updateState(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    const InstanceID* id = checkObject<InstanceID>(L, 2, InstanceIDBinding::getMetatableName());
    instance->updateState(id);
    return 0;
}

int TransformWindowBinding::close(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    instance->close();
    return 0;
}

int TransformWindowBinding::refresh(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    instance->refresh();
    return 0;
}

int TransformWindowBinding::updateGizmo(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    bool result = instance->updateGizmo();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TransformWindowBinding::isActive(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    bool result = instance->isActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TransformWindowBinding::isVisible(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    bool result = instance->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TransformWindowBinding::hasChanged(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    bool result = instance->hasChanged();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TransformWindowBinding::clearChangedFlag(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    instance->clearChangedFlag();
    return 0;
}

int TransformWindowBinding::getMode(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    int result = instance->getMode();
    lua_pushinteger(L, result);
    return 1;
}

int TransformWindowBinding::setMode(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    int m = (int)luaL_checkinteger(L, 2);
    bool result = instance->setMode(m);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TransformWindowBinding::getLastZone(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    ZoneMap* result = instance->getLastZone();
    return pushObject<ZoneMap>(L, result, ZoneMapBinding::getMetatableName());
}

int TransformWindowBinding::getZone(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    ZoneMap* result = instance->getZone();
    return pushObject<ZoneMap>(L, result, ZoneMapBinding::getMetatableName());
}

int TransformWindowBinding::changeMode(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->changeMode(line);
    return 0;
}

int TransformWindowBinding::changeCoord(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->changeCoord(line);
    return 0;
}

int TransformWindowBinding::changeValue(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->changeValue(line);
    return 0;
}

int TransformWindowBinding::reset(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->reset(_a1);
    return 0;
}

int TransformWindowBinding::revert(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->revert(_a1);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 24: void show(...) - unsupported arg type
  line 42: void confirmValue(...) - unsupported arg type
  line 45: void hide(...) - unsupported arg type
*/

static int TransformWindow_set_node(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->node = (Ogre::SceneNode*)lua_touserdata(L, 2);
    return 0;
}

static int TransformWindow_set_parentNode(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->parentNode = (Ogre::SceneNode*)lua_touserdata(L, 2);
    return 0;
}

static int TransformWindow_set_gizmo(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    instance->gizmo = (Gizmo*)lua_touserdata(L, 2);
    return 0;
}

int TransformWindowBinding::getSingleton(lua_State* L)
{
    TransformWindow* result = TransformWindow::getSingleton();
    return pushObject<TransformWindow>(L, result, TransformWindowBinding::getMetatableName());
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - TransformWindow_get_node: Ogre::SceneNode* (unbound pointer)
  - TransformWindow_get_parentNode: Ogre::SceneNode* (unbound pointer)
  - TransformWindow_get_gizmo: Gizmo* (unbound pointer)
*/

int TransformWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TransformWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TransformWindow object");
    return 1;
}

void TransformWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TransformWindowBinding::gc },
        { "__tostring", TransformWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setCaption", TransformWindowBinding::setCaption },
        { "updateState", TransformWindowBinding::updateState },
        { "close", TransformWindowBinding::close },
        { "refresh", TransformWindowBinding::refresh },
        { "updateGizmo", TransformWindowBinding::updateGizmo },
        { "isActive", TransformWindowBinding::isActive },
        { "isVisible", TransformWindowBinding::isVisible },
        { "hasChanged", TransformWindowBinding::hasChanged },
        { "clearChangedFlag", TransformWindowBinding::clearChangedFlag },
        { "getMode", TransformWindowBinding::getMode },
        { "setMode", TransformWindowBinding::setMode },
        { "getLastZone", TransformWindowBinding::getLastZone },
        { "getZone", TransformWindowBinding::getZone },
        { "changeMode", TransformWindowBinding::changeMode },
        { "changeCoord", TransformWindowBinding::changeCoord },
        { "changeValue", TransformWindowBinding::changeValue },
        { "reset", TransformWindowBinding::reset },
        { "revert", TransformWindowBinding::revert },
        { "getSingleton", TransformWindowBinding::getSingleton },
        { 0, 0 }
    };

    registerClass(
        L, 
        TransformWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TransformWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "window", TransformWindow_get_window);
    registerGetter(L, "windowXValue", TransformWindow_get_windowXValue);
    registerGetter(L, "windowYValue", TransformWindow_get_windowYValue);
    registerGetter(L, "windowZValue", TransformWindow_get_windowZValue);
    registerGetter(L, "modeButton", TransformWindow_get_modeButton);
    registerGetter(L, "axisButton", TransformWindow_get_axisButton);
    registerGetter(L, "revertButton", TransformWindow_get_revertButton);
    registerGetter(L, "node", TransformWindow_get_node);
    registerGetter(L, "parentNode", TransformWindow_get_parentNode);
    registerGetter(L, "gizmo", TransformWindow_get_gizmo);
    registerGetter(L, "mode", TransformWindow_get_mode);
    registerGetter(L, "coordinateSystem", TransformWindow_get_coordinateSystem);
    registerGetter(L, "hasScale", TransformWindow_get_hasScale);
    registerGetter(L, "lastZone", TransformWindow_get_lastZone);
    registerGetter(L, "currentZone", TransformWindow_get_currentZone);
    registerGetter(L, "currentInstance", TransformWindow_get_currentInstance);
    registerGetter(L, "changed", TransformWindow_get_changed);
    registerGetter(L, "editChanged", TransformWindow_get_editChanged);
    registerGetter(L, "lastMouse", TransformWindow_get_lastMouse);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "window", TransformWindow_set_window);
    registerSetter(L, "windowXValue", TransformWindow_set_windowXValue);
    registerSetter(L, "windowYValue", TransformWindow_set_windowYValue);
    registerSetter(L, "windowZValue", TransformWindow_set_windowZValue);
    registerSetter(L, "modeButton", TransformWindow_set_modeButton);
    registerSetter(L, "axisButton", TransformWindow_set_axisButton);
    registerSetter(L, "revertButton", TransformWindow_set_revertButton);
    registerSetter(L, "node", TransformWindow_set_node);
    registerSetter(L, "parentNode", TransformWindow_set_parentNode);
    registerSetter(L, "gizmo", TransformWindow_set_gizmo);
    registerSetter(L, "mode", TransformWindow_set_mode);
    registerSetter(L, "coordinateSystem", TransformWindow_set_coordinateSystem);
    registerSetter(L, "hasScale", TransformWindow_set_hasScale);
    registerSetter(L, "lastZone", TransformWindow_set_lastZone);
    registerSetter(L, "currentZone", TransformWindow_set_currentZone);
    registerSetter(L, "currentInstance", TransformWindow_set_currentInstance);
    registerSetter(L, "changed", TransformWindow_set_changed);
    registerSetter(L, "editChanged", TransformWindow_set_editChanged);
    registerSetter(L, "lastMouse", TransformWindow_set_lastMouse);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "getSingleton", TransformWindowBinding::getSingleton);
    lua_setglobal(L, "TransformWindow");
}

} // namespace KenshiLua