#include "pch.h"
#include "Bindings/Gui/DataPanelLine_ButtonBinding.h"
#include "Bindings/Gui/DataPanelLine_TextEditableBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

#include <kenshi/gui/TransformWindow.h>
#include "TransformWindowBinding.h"
#include "Lua/BindingHelpers.h"

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
    lua_pushlightuserdata(L, (void*)instance->lastZone);
    return 1;
}

static int TransformWindow_get_currentZone(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->currentZone);
    return 1;
}

static int TransformWindow_get_currentInstance(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->currentInstance);
    return 1;
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

// --- Setters for TransformWindow ---
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

int TransformWindowBinding::_CONSTRUCTOR(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    TransformWindow* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TransformWindowBinding::_DESTRUCTOR(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int TransformWindowBinding::setCaption(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    std::string s = luaL_checkstring(L, 2);
    instance->setCaption(s);
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
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TransformWindowBinding::getZone(lua_State* L)
{
    TransformWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TransformWindow is nil");

    ZoneMap* result = instance->getZone();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 19: TransformWindow* getSingleton(...) - static method
  line 24: void show(...) - unsupported arg type
  line 26: void updateState(...) - unsupported arg type
  line 39: void changeMode(...) - unsupported arg type
  line 40: void changeCoord(...) - unsupported arg type
  line 41: void changeValue(...) - unsupported arg type
  line 42: void confirmValue(...) - unsupported arg type
  line 43: void reset(...) - unsupported arg type
  line 44: void revert(...) - unsupported arg type
  line 45: void hide(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 65: lastMouse (Ogre::Vector2) - unsupported type
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
        { "_CONSTRUCTOR", TransformWindowBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", TransformWindowBinding::_DESTRUCTOR },
        { "setCaption", TransformWindowBinding::setCaption },
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
    lua_pushcfunction(L, TransformWindow_get_window);
    lua_setfield(L, -2, "window");
    lua_pushcfunction(L, TransformWindow_get_windowXValue);
    lua_setfield(L, -2, "windowXValue");
    lua_pushcfunction(L, TransformWindow_get_windowYValue);
    lua_setfield(L, -2, "windowYValue");
    lua_pushcfunction(L, TransformWindow_get_windowZValue);
    lua_setfield(L, -2, "windowZValue");
    lua_pushcfunction(L, TransformWindow_get_modeButton);
    lua_setfield(L, -2, "modeButton");
    lua_pushcfunction(L, TransformWindow_get_axisButton);
    lua_setfield(L, -2, "axisButton");
    lua_pushcfunction(L, TransformWindow_get_revertButton);
    lua_setfield(L, -2, "revertButton");
    lua_pushcfunction(L, TransformWindow_get_node);
    lua_setfield(L, -2, "node");
    lua_pushcfunction(L, TransformWindow_get_parentNode);
    lua_setfield(L, -2, "parentNode");
    lua_pushcfunction(L, TransformWindow_get_gizmo);
    lua_setfield(L, -2, "gizmo");
    lua_pushcfunction(L, TransformWindow_get_mode);
    lua_setfield(L, -2, "mode");
    lua_pushcfunction(L, TransformWindow_get_coordinateSystem);
    lua_setfield(L, -2, "coordinateSystem");
    lua_pushcfunction(L, TransformWindow_get_hasScale);
    lua_setfield(L, -2, "hasScale");
    lua_pushcfunction(L, TransformWindow_get_lastZone);
    lua_setfield(L, -2, "lastZone");
    lua_pushcfunction(L, TransformWindow_get_currentZone);
    lua_setfield(L, -2, "currentZone");
    lua_pushcfunction(L, TransformWindow_get_currentInstance);
    lua_setfield(L, -2, "currentInstance");
    lua_pushcfunction(L, TransformWindow_get_changed);
    lua_setfield(L, -2, "changed");
    lua_pushcfunction(L, TransformWindow_get_editChanged);
    lua_setfield(L, -2, "editChanged");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TransformWindow_set_mode);
    lua_setfield(L, -2, "mode");
    lua_pushcfunction(L, TransformWindow_set_coordinateSystem);
    lua_setfield(L, -2, "coordinateSystem");
    lua_pushcfunction(L, TransformWindow_set_hasScale);
    lua_setfield(L, -2, "hasScale");
    lua_pushcfunction(L, TransformWindow_set_changed);
    lua_setfield(L, -2, "changed");
    lua_pushcfunction(L, TransformWindow_set_editChanged);
    lua_setfield(L, -2, "editChanged");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // // // // // // // // // setMetatableParent(L, TransformWindowBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua