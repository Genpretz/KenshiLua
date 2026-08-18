#include "pch.h"
#include "kenshi\gui\DatapanelGUI.h"
#include "DatapanelGUIBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/Gui/DataPanelLine_ButtonBinding.h"
#include "Bindings/Gui/DataPanelLine_CheckBoxBinding.h"
#include "Bindings/Gui/DataPanelLine_DropBoxBinding.h"
#include "Bindings/Gui/DataPanelLine_FactionBinding.h"
#include "Bindings/Gui/DataPanelLine_ProgressBinding.h"
#include "Bindings/Gui/DataPanelLine_ResearchBinding.h"
#include "Bindings/Gui/DataPanelLine_SliderBinding.h"
#include "Bindings/Gui/DataPanelLine_SliderEditableBinding.h"
#include "Bindings/Gui/DataPanelLine_TextBinding.h"
#include "Bindings/Gui/DataPanelLine_TextEditableBinding.h"
#include "Bindings/Gui/GUIWindowBinding.h"

namespace KenshiLua
{

static DatapanelGUI* getInstance(lua_State* L, int idx)
{
    return checkObject<DatapanelGUI>(L, idx, DatapanelGUIBinding::getMetatableName());
}

// --- Getters for DatapanelGUI ---
static int DatapanelGUI_get_frequentUpdatesWanted(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushboolean(L, instance->frequentUpdatesWanted ? 1 : 0);
    return 1;
}

static int DatapanelGUI_get_scrollWin(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->scrollWin);
    return 1;
}

static int DatapanelGUI_get_premadeParentWindow(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushboolean(L, instance->premadeParentWindow ? 1 : 0);
    return 1;
}

static int DatapanelGUI_get_scrolling(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushboolean(L, instance->scrolling ? 1 : 0);
    return 1;
}

static int DatapanelGUI_get_isWindow(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushboolean(L, instance->isWindow ? 1 : 0);
    return 1;
}

static int DatapanelGUI_get_currentCategory(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushinteger(L, instance->currentCategory);
    return 1;
}

static int DatapanelGUI_get_mouseOverEvent(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->mouseOverEvent);
    return 1;
}

static int DatapanelGUI_get_mouseOverEventDatas(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->mouseOverEventDatas);
    return 1;
}

static int DatapanelGUI_get_automaticRefresh(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushboolean(L, instance->automaticRefresh ? 1 : 0);
    return 1;
}

static int DatapanelGUI_get_automaticTarget(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushboolean(L, instance->automaticTarget ? 1 : 0);
    return 1;
}

static int DatapanelGUI_get_tabWin(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->tabWin);
    return 1;
}

static int DatapanelGUI_get_panelName(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushstring(L, instance->panelName.c_str());
    return 1;
}

static int DatapanelGUI_get_x(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushnumber(L, instance->x);
    return 1;
}

static int DatapanelGUI_get_y(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushnumber(L, instance->y);
    return 1;
}

static int DatapanelGUI_get_w(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushnumber(L, instance->w);
    return 1;
}

static int DatapanelGUI_get_h(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushnumber(L, instance->h);
    return 1;
}

static int DatapanelGUI_get_DATALINESPACING(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushnumber(L, instance->DATALINESPACING);
    return 1;
}

static int DatapanelGUI_get_DATALINETHICKNESS(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushnumber(L, instance->DATALINETHICKNESS);
    return 1;
}

static int DatapanelGUI_get_basicSpacing(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushboolean(L, instance->basicSpacing ? 1 : 0);
    return 1;
}

static int DatapanelGUI_get_layer(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushstring(L, instance->layer.c_str());
    return 1;
}

static int DatapanelGUI_get_scrollView(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->scrollView);
    return 1;
}

// --- Setters for DatapanelGUI ---
static int DatapanelGUI_set_frequentUpdatesWanted(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->frequentUpdatesWanted = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DatapanelGUI_set_premadeParentWindow(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->premadeParentWindow = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DatapanelGUI_set_scrolling(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->scrolling = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DatapanelGUI_set_isWindow(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->isWindow = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DatapanelGUI_set_currentCategory(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->currentCategory = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DatapanelGUI_set_automaticRefresh(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->automaticRefresh = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DatapanelGUI_set_automaticTarget(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->automaticTarget = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DatapanelGUI_set_panelName(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->panelName = luaL_checkstring(L, 2);
    return 0;
}

static int DatapanelGUI_set_x(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->x = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DatapanelGUI_set_y(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->y = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DatapanelGUI_set_w(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->w = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DatapanelGUI_set_h(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->h = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DatapanelGUI_set_DATALINESPACING(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->DATALINESPACING = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DatapanelGUI_set_DATALINETHICKNESS(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->DATALINETHICKNESS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DatapanelGUI_set_basicSpacing(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->basicSpacing = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DatapanelGUI_set_layer(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->layer = luaL_checkstring(L, 2);
    return 0;
}

int DatapanelGUIBinding::setFrequentUpdateMode(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    instance->setFrequentUpdateMode();
    return 0;
}

int DatapanelGUIBinding::setPositionReal(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    instance->setPositionReal(x, y);
    return 0;
}

int DatapanelGUIBinding::_NV_setPositionReal(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    instance->_NV_setPositionReal(x, y);
    return 0;
}

int DatapanelGUIBinding::setPosition(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    instance->setPosition(x, y);
    return 0;
}

int DatapanelGUIBinding::_NV_setPosition(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    instance->_NV_setPosition(x, y);
    return 0;
}

int DatapanelGUIBinding::resize(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int w = (int)luaL_checkinteger(L, 2);
    int h = (int)luaL_checkinteger(L, 3);
    instance->resize(w, h);
    return 0;
}

int DatapanelGUIBinding::_NV_resize(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int w = (int)luaL_checkinteger(L, 2);
    int h = (int)luaL_checkinteger(L, 3);
    instance->_NV_resize(w, h);
    return 0;
}

int DatapanelGUIBinding::clear(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    instance->clear();
    return 0;
}

int DatapanelGUIBinding::_NV_clear(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    instance->_NV_clear();
    return 0;
}

int DatapanelGUIBinding::clearPage(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int cat = (int)luaL_checkinteger(L, 2);
    instance->clearPage(cat);
    return 0;
}

int DatapanelGUIBinding::_NV_clearPage(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int cat = (int)luaL_checkinteger(L, 2);
    instance->_NV_clearPage(cat);
    return 0;
}

int DatapanelGUIBinding::hideAllWidgets(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    instance->hideAllWidgets();
    return 0;
}

int DatapanelGUIBinding::_NV_hideAllWidgets(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    instance->_NV_hideAllWidgets();
    return 0;
}

int DatapanelGUIBinding::create(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    instance->create();
    return 0;
}

int DatapanelGUIBinding::_NV_create(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    instance->_NV_create();
    return 0;
}

int DatapanelGUIBinding::show(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->show(on);
    return 0;
}

int DatapanelGUIBinding::_NV_show(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_show(on);
    return 0;
}

int DatapanelGUIBinding::show_NonSmooth(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->show_NonSmooth(on);
    return 0;
}

int DatapanelGUIBinding::update(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    instance->update();
    return 0;
}

int DatapanelGUIBinding::_NV_update(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    instance->_NV_update();
    return 0;
}

int DatapanelGUIBinding::setPanelName(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string name = luaL_checkstring(L, 2);
    instance->setPanelName(name);
    return 0;
}

int DatapanelGUIBinding::showTabs(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->showTabs(on);
    return 0;
}

int DatapanelGUIBinding::_NV_showTabs(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_showTabs(on);
    return 0;
}

int DatapanelGUIBinding::addTab(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int id = (int)luaL_checkinteger(L, 2);
    const std::string name = luaL_checkstring(L, 3);
    const std::string icon = luaL_checkstring(L, 4);
    instance->addTab(id, name, icon);
    return 0;
}

int DatapanelGUIBinding::_NV_addTab(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int id = (int)luaL_checkinteger(L, 2);
    const std::string name = luaL_checkstring(L, 3);
    const std::string icon = luaL_checkstring(L, 4);
    instance->_NV_addTab(id, name, icon);
    return 0;
}

int DatapanelGUIBinding::setTabName(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int id = (int)luaL_checkinteger(L, 2);
    const std::string name = luaL_checkstring(L, 3);
    instance->setTabName(id, name);
    return 0;
}

int DatapanelGUIBinding::_NV_setTabName(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int id = (int)luaL_checkinteger(L, 2);
    const std::string name = luaL_checkstring(L, 3);
    instance->_NV_setTabName(id, name);
    return 0;
}

int DatapanelGUIBinding::setCaption(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string s = luaL_checkstring(L, 2);
    instance->setCaption(s);
    return 0;
}

int DatapanelGUIBinding::setAutomaticRefresh(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setAutomaticRefresh(on);
    return 0;
}

int DatapanelGUIBinding::_NV_setAutomaticRefresh(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setAutomaticRefresh(on);
    return 0;
}

int DatapanelGUIBinding::setAutomaticTargeting(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setAutomaticTargeting(on);
    return 0;
}

int DatapanelGUIBinding::_NV_setAutomaticTargeting(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setAutomaticTargeting(on);
    return 0;
}

int DatapanelGUIBinding::_zeroLines(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int cat = (int)luaL_checkinteger(L, 2);
    DataPanelLine* result = instance->_zeroLines(cat);
    return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
}

int DatapanelGUIBinding::_NV__zeroLines(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int cat = (int)luaL_checkinteger(L, 2);
    DataPanelLine* result = instance->_NV__zeroLines(cat);
    return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
}

int DatapanelGUIBinding::setLineStatInfo(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string s1 = luaL_checkstring(L, 2);
    const std::string s2 = luaL_checkstring(L, 3);
    int category = (int)luaL_checkinteger(L, 4);
    DataPanelLine* result = instance->setLineStatInfo(s1, s2, category);
    return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
}

int DatapanelGUIBinding::setLineFaction(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string s1 = luaL_checkstring(L, 2);
    const std::string s2 = luaL_checkstring(L, 3);
    int category = (int)luaL_checkinteger(L, 4);
    float v1 = (float)luaL_checknumber(L, 5);
    float v2 = (float)luaL_checknumber(L, 6);
    DataPanelLine_Faction* result = instance->setLineFaction(s1, s2, category, v1, v2);
    return pushObject<DataPanelLine_Faction>(L, result, DataPanelLine_FactionBinding::getMetatableName());
}

int DatapanelGUIBinding::setLineTextButton(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string text = luaL_checkstring(L, 2);
    const std::string caption = luaL_checkstring(L, 3);
    int category = (int)luaL_checkinteger(L, 4);
    float buttonWidth = (float)luaL_checknumber(L, 5);
    const std::string skin = luaL_checkstring(L, 6);
    DataPanelLine_Button* result = instance->setLineTextButton(text, caption, category, buttonWidth, skin);
    return pushObject<DataPanelLine_Button>(L, result, DataPanelLine_ButtonBinding::getMetatableName());
}

int DatapanelGUIBinding::setLineButton(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string key = luaL_checkstring(L, 2);
    const std::string caption = luaL_checkstring(L, 3);
    int category = (int)luaL_checkinteger(L, 4);
    DataPanelLine_Button* result = instance->setLineButton(key, caption, category);
    return pushObject<DataPanelLine_Button>(L, result, DataPanelLine_ButtonBinding::getMetatableName());
}

int DatapanelGUIBinding::setLineToggleButton(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string key = luaL_checkstring(L, 2);
    const std::string caption = luaL_checkstring(L, 3);
    int category = (int)luaL_checkinteger(L, 4);
    DataPanelLine_Button* result = instance->setLineToggleButton(key, caption, category);
    return pushObject<DataPanelLine_Button>(L, result, DataPanelLine_ButtonBinding::getMetatableName());
}

int DatapanelGUIBinding::setLineSliderEditable(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string key = luaL_checkstring(L, 2);
    int category = (int)luaL_checkinteger(L, 3);
    bool showName = lua_toboolean(L, 4) != 0;
    float min = (float)luaL_checknumber(L, 5);
    float max = (float)luaL_checknumber(L, 6);
    float tempVal = (float)luaL_checknumber(L, 7);
    float* value = &tempVal;
    DataPanelLine_SliderEditable* result = instance->setLineSliderEditable(key, category, showName, min, max, value);
    return pushObject<DataPanelLine_SliderEditable>(L, result, DataPanelLine_SliderEditableBinding::getMetatableName());
}

int DatapanelGUIBinding::setLineSlider(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string key = luaL_checkstring(L, 2);
    const std::string caption = luaL_checkstring(L, 3);
    float min = (float)luaL_checknumber(L, 4);
    float max = (float)luaL_checknumber(L, 5);
    int category = (int)luaL_checkinteger(L, 6);
    float tempVal = (float)luaL_checknumber(L, 7);
    float* value = &tempVal;
    float scale = (float)luaL_checknumber(L, 8);
    DataPanelLine_Slider* result = instance->setLineSlider(key, caption, min, max, category, value, scale);
    return pushObject<DataPanelLine_Slider>(L, result, DataPanelLine_SliderBinding::getMetatableName());
}

int DatapanelGUIBinding::setLineProgress(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string key = luaL_checkstring(L, 2);
    int category = (int)luaL_checkinteger(L, 3);
    float progressValue = (float)luaL_checknumber(L, 4);
    const std::string progressText = luaL_checkstring(L, 5);
    bool showKey = lua_toboolean(L, 6) != 0;
    DataPanelLine_Progress* result = instance->setLineProgress(key, category, progressValue, progressText, showKey);
    return pushObject<DataPanelLine_Progress>(L, result, DataPanelLine_ProgressBinding::getMetatableName());
}

int DatapanelGUIBinding::removeLine(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string s1 = luaL_checkstring(L, 2);
    int category = (int)luaL_checkinteger(L, 3);
    instance->removeLine(s1, category);
    return 0;
}

int DatapanelGUIBinding::setLineCheckbox(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string s1 = luaL_checkstring(L, 2);
    bool tempBool = lua_toboolean(L, 3) != 0;
    bool* val = &tempBool;
    int category = (int)luaL_checkinteger(L, 4);
    DataPanelLine_CheckBox* result = instance->setLineCheckbox(s1, val, category);
    return pushObject<DataPanelLine_CheckBox>(L, result, DataPanelLine_CheckBoxBinding::getMetatableName());
}

int DatapanelGUIBinding::setLineDropBox(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string key = luaL_checkstring(L, 2);
    int category = (int)luaL_checkinteger(L, 3);
    int tempInt = (int)luaL_checkinteger(L, 4);
    int* valPtr = &tempInt;
    bool goBox = lua_toboolean(L, 5) != 0;
    float width = (float)luaL_checknumber(L, 6);
    DataPanelLine_DropBox* result = instance->setLineDropBox(key, category, valPtr, goBox, width);
    return pushObject<DataPanelLine_DropBox>(L, result, DataPanelLine_DropBoxBinding::getMetatableName());
}

int DatapanelGUIBinding::addSpace(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int category = (int)luaL_checkinteger(L, 2);
    float h = (float)luaL_checknumber(L, 3);
    instance->addSpace(category, h);
    return 0;
}

int DatapanelGUIBinding::setCategoryIcon(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int cat = (int)luaL_checkinteger(L, 2);
    const std::string image = luaL_checkstring(L, 3);
    instance->setCategoryIcon(cat, image);
    return 0;
}

int DatapanelGUIBinding::_NV_setCategoryIcon(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int cat = (int)luaL_checkinteger(L, 2);
    const std::string image = luaL_checkstring(L, 3);
    instance->_NV_setCategoryIcon(cat, image);
    return 0;
}

int DatapanelGUIBinding::changeCategory(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int cat = (int)luaL_checkinteger(L, 2);
    instance->changeCategory(cat);
    return 0;
}

int DatapanelGUIBinding::_NV_changeCategory(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int cat = (int)luaL_checkinteger(L, 2);
    instance->_NV_changeCategory(cat);
    return 0;
}

int DatapanelGUIBinding::getCurrentCategory(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int result = instance->getCurrentCategory();
    lua_pushinteger(L, result);
    return 1;
}

int DatapanelGUIBinding::_NV_getCurrentCategory(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int result = instance->_NV_getCurrentCategory();
    lua_pushinteger(L, result);
    return 1;
}

int DatapanelGUIBinding::addCustomLine(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->addCustomLine(line);
    return 0;
}

int DatapanelGUIBinding::getObject(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    hand result = instance->getObject();
    return HandBinding::push(L, result);
}

int DatapanelGUIBinding::_NV_getObject(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    hand result = instance->_NV_getObject();
    return HandBinding::push(L, result);
}

int DatapanelGUIBinding::setLineSpacing(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    float numLinesPerScreen = (float)luaL_checknumber(L, 2);
    instance->setLineSpacing(numLinesPerScreen);
    return 0;
}

int DatapanelGUIBinding::_NV_setLineSpacing(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    float numLinesPerScreen = (float)luaL_checknumber(L, 2);
    instance->_NV_setLineSpacing(numLinesPerScreen);
    return 0;
}

int DatapanelGUIBinding::getLine(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string key = luaL_checkstring(L, 2);
    int cat = (int)luaL_checkinteger(L, 3);
    DataPanelLine* result = instance->getLine(key, cat);
    return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
}

int DatapanelGUIBinding::_NV_getLine(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string key = luaL_checkstring(L, 2);
    int cat = (int)luaL_checkinteger(L, 3);
    DataPanelLine* result = instance->_NV_getLine(key, cat);
    return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
}

int DatapanelGUIBinding::lineExists(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    const std::string key = luaL_checkstring(L, 2);
    int cat = (int)luaL_checkinteger(L, 3);
    bool result = instance->lineExists(key, cat);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DatapanelGUIBinding::getContentHeight(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int cat = (int)luaL_checkinteger(L, 2);
    int result = instance->getContentHeight(cat);
    lua_pushinteger(L, result);
    return 1;
}

int DatapanelGUIBinding::getNumLines(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int cat = (int)luaL_checkinteger(L, 2);
    int result = instance->getNumLines(cat);
    lua_pushinteger(L, result);
    return 1;
}

int DatapanelGUIBinding::getLineByNum(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int cat = (int)luaL_checkinteger(L, 2);
    int i = (int)luaL_checkinteger(L, 3);
    DataPanelLine* result = instance->getLineByNum(cat, i);
    return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
}

int DatapanelGUIBinding::createLine(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    bool lastLine = lua_toboolean(L, 4) != 0;
    DataPanelLine* result = instance->createLine(line, category, lastLine);
    return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
}

int DatapanelGUIBinding::getNextVerticalPos(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int category = (int)luaL_checkinteger(L, 2);
    float result = instance->getNextVerticalPos(category);
    lua_pushnumber(L, result);
    return 1;
}

int DatapanelGUIBinding::dataExists(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int cat = (int)luaL_checkinteger(L, 2);
    const std::string name = luaL_checkstring(L, 3);
    bool result = instance->dataExists(cat, name);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DatapanelGUIBinding::clearCategoryTabs(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    instance->clearCategoryTabs();
    return 0;
}

int DatapanelGUIBinding::setLine(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int top = lua_gettop(L);
    if (top == 5)
    {
        // setLine(s1, s2, barValue, category)
        std::string s1 = luaL_checkstring(L, 2);
        std::string s2 = luaL_checkstring(L, 3);
        float barValue = (float)luaL_checknumber(L, 4);
        int category = (int)luaL_checkinteger(L, 5);
        DataPanelLine* result = instance->setLine(s1, s2, barValue, category);
        return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
    }
    else if (top == 6)
    {
        std::string s1 = luaL_checkstring(L, 2);
        std::string s2 = luaL_checkstring(L, 3);
        if (lua_isstring(L, 4) && lua_isstring(L, 5))
        {
            // setLine(s1, s2, skinA, skinB, category)
            std::string skinA = luaL_checkstring(L, 4);
            std::string skinB = luaL_checkstring(L, 5);
            int category = (int)luaL_checkinteger(L, 6);
            DataPanelLine* result = instance->setLine(s1, s2, skinA, skinB, category);
            return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
        }
        else
        {
            // setLine(s1, s2, category, last, keyVisible)
            int category = (int)luaL_checkinteger(L, 4);
            bool last = lua_toboolean(L, 5) != 0;
            bool keyVisible = lua_toboolean(L, 6) != 0;
            DataPanelLine* result = instance->setLine(s1, s2, category, last, keyVisible);
            return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
        }
    }
    else if (top >= 7)
    {
        std::string keyValue = luaL_checkstring(L, 2);
        std::string s1 = luaL_checkstring(L, 3);
        std::string s2 = luaL_checkstring(L, 4);
        if (lua_isstring(L, 5) && lua_isstring(L, 6))
        {
            // setLine(keyValue, s1, s2, skinA, skinB, category)
            std::string skinA = luaL_checkstring(L, 5);
            std::string skinB = luaL_checkstring(L, 6);
            int category = (int)luaL_checkinteger(L, 7);
            DataPanelLine* result = instance->setLine(keyValue, s1, s2, skinA, skinB, category);
            return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
        }
        else
        {
            // setLine(keyValue, s1, s2, category, last, keyVisible)
            int category = (int)luaL_checkinteger(L, 5);
            bool last = lua_toboolean(L, 6) != 0;
            bool keyVisible = lua_toboolean(L, 7) != 0;
            DataPanelLine* result = instance->setLine(keyValue, s1, s2, category, last, keyVisible);
            return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
        }
    }

    return luaL_error(L, "Invalid arguments for DatapanelGUI:setLine");
}

int DatapanelGUIBinding::setLineResearch(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int top = lua_gettop(L);
    if (top == 7)
    {
        // setLineResearch(s1, s2, category, v1, barColor, XButton)
        std::string s1 = luaL_checkstring(L, 2);
        std::string s2 = luaL_checkstring(L, 3);
        int category = (int)luaL_checkinteger(L, 4);
        float v1 = (float)luaL_checknumber(L, 5);
        std::string barColor = luaL_checkstring(L, 6);
        bool XButton = lua_toboolean(L, 7) != 0;
        DataPanelLine_Research* result = instance->setLineResearch(s1, s2, category, v1, barColor, XButton);
        return pushObject<DataPanelLine_Research>(L, result, DataPanelLine_ResearchBinding::getMetatableName());
    }
    else if (top >= 8)
    {
        // setLineResearch(key, s1, s2, category, v1, barColor, Xbutton)
        std::string key = luaL_checkstring(L, 2);
        std::string s1 = luaL_checkstring(L, 3);
        std::string s2 = luaL_checkstring(L, 4);
        int category = (int)luaL_checkinteger(L, 5);
        float v1 = (float)luaL_checknumber(L, 6);
        std::string barColor = luaL_checkstring(L, 7);
        bool Xbutton = lua_toboolean(L, 8) != 0;
        DataPanelLine_Research* result = instance->setLineResearch(key, s1, s2, category, v1, barColor, Xbutton);
        return pushObject<DataPanelLine_Research>(L, result, DataPanelLine_ResearchBinding::getMetatableName());
    }

    return luaL_error(L, "Invalid arguments for DatapanelGUI:setLineResearch");
}

/*
Skipped methods needing manual binding:
  line 57: void setTabEnabled(...) - non-string reference arg
  line 58: void _NV_setTabEnabled(...) - non-string reference arg
  line 62: void setCloseCallback(...) - unsupported arg type
  line 82: DataPanelLine_Text* setLineText(...) - unsupported arg type
  line 83: DataPanelLine_TextEditable* setLineTextEditable(...) - unsupported arg type
  line 90: void setLines(...) - unsupported arg type
  line 98: void autoChangeSelectedObject(...) - non-string reference arg
  line 99: void _NV_autoChangeSelectedObject(...) - non-string reference arg
  line 102: void setObject(...) - non-string reference arg
  line 103: void _NV_setObject(...) - non-string reference arg
  line 106: void setMouseOverCallback(...) - unsupported arg type
  line 107: void _NV_setMouseOverCallback(...) - unsupported arg type
  line 113: void tabButton(...) - unsupported arg type
  line 131: void closeButtonCallback(...) - unsupported arg type
  line 132: void mouseOverCallback(...) - unsupported arg type
  line 133: void notifyMouseWheel(...) - unsupported arg type
  line 134: MyGUI::types::TCoord<int> getCoords(...) - unsupported return type
*/

/*
Skipped properties needing manual binding:
  line 30: tabEvent (MyGUI::delegates::CMultiDelegate2<DatapanelGUI*, int>) - unsupported type
  line 135: content (std::map<int, std::map<std::string, DataPanelLine*, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, DataPanelLine*>, Ogre::GeneralAllocPolicy > >, std::less<int>, Ogre::STLAllocator<std::pair<int const, std::map<std::string, DataPanelLine*, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, DataPanelLine*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 136: bottomLine (std::map<int, DataPanelLine*, std::less<int>, Ogre::STLAllocator<std::pair<int const, DataPanelLine*>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 145: tabs (lektor<MyGUI::Button*>) - unsupported type
*/

int DatapanelGUIBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DatapanelGUIBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DatapanelGUI object");
    return 1;
}

void DatapanelGUIBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DatapanelGUIBinding::gc },
        { "__tostring", DatapanelGUIBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setFrequentUpdateMode", DatapanelGUIBinding::setFrequentUpdateMode },
        { "setPositionReal", DatapanelGUIBinding::setPositionReal },
        { "_NV_setPositionReal", DatapanelGUIBinding::_NV_setPositionReal },
        { "setPosition", DatapanelGUIBinding::setPosition },
        { "_NV_setPosition", DatapanelGUIBinding::_NV_setPosition },
        { "resize", DatapanelGUIBinding::resize },
        { "_NV_resize", DatapanelGUIBinding::_NV_resize },
        { "clear", DatapanelGUIBinding::clear },
        { "_NV_clear", DatapanelGUIBinding::_NV_clear },
        { "clearPage", DatapanelGUIBinding::clearPage },
        { "_NV_clearPage", DatapanelGUIBinding::_NV_clearPage },
        { "hideAllWidgets", DatapanelGUIBinding::hideAllWidgets },
        { "_NV_hideAllWidgets", DatapanelGUIBinding::_NV_hideAllWidgets },
        { "create", DatapanelGUIBinding::create },
        { "_NV_create", DatapanelGUIBinding::_NV_create },
        { "show", DatapanelGUIBinding::show },
        { "_NV_show", DatapanelGUIBinding::_NV_show },
        { "show_NonSmooth", DatapanelGUIBinding::show_NonSmooth },
        { "update", DatapanelGUIBinding::update },
        { "_NV_update", DatapanelGUIBinding::_NV_update },
        { "setPanelName", DatapanelGUIBinding::setPanelName },
        { "showTabs", DatapanelGUIBinding::showTabs },
        { "_NV_showTabs", DatapanelGUIBinding::_NV_showTabs },
        { "addTab", DatapanelGUIBinding::addTab },
        { "_NV_addTab", DatapanelGUIBinding::_NV_addTab },
        { "setTabName", DatapanelGUIBinding::setTabName },
        { "_NV_setTabName", DatapanelGUIBinding::_NV_setTabName },
        { "setCaption", DatapanelGUIBinding::setCaption },
        { "setAutomaticRefresh", DatapanelGUIBinding::setAutomaticRefresh },
        { "_NV_setAutomaticRefresh", DatapanelGUIBinding::_NV_setAutomaticRefresh },
        { "setAutomaticTargeting", DatapanelGUIBinding::setAutomaticTargeting },
        { "_NV_setAutomaticTargeting", DatapanelGUIBinding::_NV_setAutomaticTargeting },
        { "_zeroLines", DatapanelGUIBinding::_zeroLines },
        { "_NV__zeroLines", DatapanelGUIBinding::_NV__zeroLines },
        { "setLineStatInfo", DatapanelGUIBinding::setLineStatInfo },
        { "setLineFaction", DatapanelGUIBinding::setLineFaction },
        { "setLineTextButton", DatapanelGUIBinding::setLineTextButton },
        { "setLineButton", DatapanelGUIBinding::setLineButton },
        { "setLineToggleButton", DatapanelGUIBinding::setLineToggleButton },
        { "setLineSliderEditable", DatapanelGUIBinding::setLineSliderEditable },
        { "setLineSlider", DatapanelGUIBinding::setLineSlider },
        { "setLineProgress", DatapanelGUIBinding::setLineProgress },
        { "removeLine", DatapanelGUIBinding::removeLine },
        { "setLineCheckbox", DatapanelGUIBinding::setLineCheckbox },
        { "setLineDropBox", DatapanelGUIBinding::setLineDropBox },
        { "addSpace", DatapanelGUIBinding::addSpace },
        { "setCategoryIcon", DatapanelGUIBinding::setCategoryIcon },
        { "_NV_setCategoryIcon", DatapanelGUIBinding::_NV_setCategoryIcon },
        { "changeCategory", DatapanelGUIBinding::changeCategory },
        { "_NV_changeCategory", DatapanelGUIBinding::_NV_changeCategory },
        { "getCurrentCategory", DatapanelGUIBinding::getCurrentCategory },
        { "_NV_getCurrentCategory", DatapanelGUIBinding::_NV_getCurrentCategory },
        { "addCustomLine", DatapanelGUIBinding::addCustomLine },
        { "getObject", DatapanelGUIBinding::getObject },
        { "_NV_getObject", DatapanelGUIBinding::_NV_getObject },
        { "setLineSpacing", DatapanelGUIBinding::setLineSpacing },
        { "_NV_setLineSpacing", DatapanelGUIBinding::_NV_setLineSpacing },
        { "getLine", DatapanelGUIBinding::getLine },
        { "_NV_getLine", DatapanelGUIBinding::_NV_getLine },
        { "lineExists", DatapanelGUIBinding::lineExists },
        { "getContentHeight", DatapanelGUIBinding::getContentHeight },
        { "getNumLines", DatapanelGUIBinding::getNumLines },
        { "getLineByNum", DatapanelGUIBinding::getLineByNum },
        { "createLine", DatapanelGUIBinding::createLine },
        { "getNextVerticalPos", DatapanelGUIBinding::getNextVerticalPos },
        { "dataExists", DatapanelGUIBinding::dataExists },
        { "clearCategoryTabs", DatapanelGUIBinding::clearCategoryTabs },
        { "setLine", DatapanelGUIBinding::setLine },
        { "setLineResearch", DatapanelGUIBinding::setLineResearch },
        { 0, 0 }
    };

    registerClass(
        L, 
        DatapanelGUIBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DatapanelGUIBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "frequentUpdatesWanted", DatapanelGUI_get_frequentUpdatesWanted);
    registerGetter(L, "scrollWin", DatapanelGUI_get_scrollWin);
    registerGetter(L, "premadeParentWindow", DatapanelGUI_get_premadeParentWindow);
    registerGetter(L, "scrolling", DatapanelGUI_get_scrolling);
    registerGetter(L, "isWindow", DatapanelGUI_get_isWindow);
    registerGetter(L, "currentCategory", DatapanelGUI_get_currentCategory);
    registerGetter(L, "mouseOverEvent", DatapanelGUI_get_mouseOverEvent);
    registerGetter(L, "mouseOverEventDatas", DatapanelGUI_get_mouseOverEventDatas);
    registerGetter(L, "automaticRefresh", DatapanelGUI_get_automaticRefresh);
    registerGetter(L, "automaticTarget", DatapanelGUI_get_automaticTarget);
    registerGetter(L, "tabWin", DatapanelGUI_get_tabWin);
    registerGetter(L, "panelName", DatapanelGUI_get_panelName);
    registerGetter(L, "x", DatapanelGUI_get_x);
    registerGetter(L, "y", DatapanelGUI_get_y);
    registerGetter(L, "w", DatapanelGUI_get_w);
    registerGetter(L, "h", DatapanelGUI_get_h);
    registerGetter(L, "DATALINESPACING", DatapanelGUI_get_DATALINESPACING);
    registerGetter(L, "DATALINETHICKNESS", DatapanelGUI_get_DATALINETHICKNESS);
    registerGetter(L, "basicSpacing", DatapanelGUI_get_basicSpacing);
    registerGetter(L, "layer", DatapanelGUI_get_layer);
    registerGetter(L, "scrollView", DatapanelGUI_get_scrollView);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "frequentUpdatesWanted", DatapanelGUI_set_frequentUpdatesWanted);
    registerSetter(L, "premadeParentWindow", DatapanelGUI_set_premadeParentWindow);
    registerSetter(L, "scrolling", DatapanelGUI_set_scrolling);
    registerSetter(L, "isWindow", DatapanelGUI_set_isWindow);
    registerSetter(L, "currentCategory", DatapanelGUI_set_currentCategory);
    registerSetter(L, "automaticRefresh", DatapanelGUI_set_automaticRefresh);
    registerSetter(L, "automaticTarget", DatapanelGUI_set_automaticTarget);
    registerSetter(L, "panelName", DatapanelGUI_set_panelName);
    registerSetter(L, "x", DatapanelGUI_set_x);
    registerSetter(L, "y", DatapanelGUI_set_y);
    registerSetter(L, "w", DatapanelGUI_set_w);
    registerSetter(L, "h", DatapanelGUI_set_h);
    registerSetter(L, "DATALINESPACING", DatapanelGUI_set_DATALINESPACING);
    registerSetter(L, "DATALINETHICKNESS", DatapanelGUI_set_DATALINETHICKNESS);
    registerSetter(L, "basicSpacing", DatapanelGUI_set_basicSpacing);
    registerSetter(L, "layer", DatapanelGUI_set_layer);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GUIWindow
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, DatapanelGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua