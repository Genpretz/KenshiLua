#include "pch.h"
#include <kenshi/gui/DatapanelGUI.h>
#include "DatapanelGUIBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/Gui/GUIWindowBinding.h"

namespace KenshiLua
{

static DatapanelGUI* getInstance(lua_State* L, int idx)
{
    return checkObject<DatapanelGUI>(L, idx, DatapanelGUIBinding::getMetatableName());
}

// --- Getters for DatapanelGUI ---
static int DatapanelGUI_get_tabEvent(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    // TODO: Unsupported type for tabEvent (MyGUI::delegates::CMultiDelegate2<DatapanelGUI*, int>)
    lua_pushnil(L);
    return 1;
}

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

static int DatapanelGUI_get_content(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    // TODO: Unsupported type for content (std::map<int, std::map<std::string, DataPanelLine*, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, DataPanelLine*>, Ogre::GeneralAllocPolicy > >, std::less<int>, Ogre::STLAllocator<std::pair<int const, std::map<std::string, DataPanelLine*, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, DataPanelLine*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
    return 1;
}

static int DatapanelGUI_get_bottomLine(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    // TODO: Unsupported type for bottomLine (std::map<int, DataPanelLine*, std::less<int>, Ogre::STLAllocator<std::pair<int const, DataPanelLine*>, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
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

static int DatapanelGUI_get_tabs(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    // TODO: Unsupported type for tabs (lektor<MyGUI::Button*>)
    lua_pushnil(L);
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
static int DatapanelGUI_set_tabEvent(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    return luaL_error(L, "Read-only or unsupported setter type for tabEvent");
}

static int DatapanelGUI_set_frequentUpdatesWanted(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->frequentUpdatesWanted = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DatapanelGUI_set_scrollWin(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    return luaL_error(L, "Read-only or unsupported setter type for scrollWin");
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

static int DatapanelGUI_set_content(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    return luaL_error(L, "Read-only or unsupported setter type for content");
}

static int DatapanelGUI_set_bottomLine(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    return luaL_error(L, "Read-only or unsupported setter type for bottomLine");
}

static int DatapanelGUI_set_currentCategory(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    instance->currentCategory = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DatapanelGUI_set_mouseOverEvent(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    return luaL_error(L, "Read-only or unsupported setter type for mouseOverEvent");
}

static int DatapanelGUI_set_mouseOverEventDatas(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    return luaL_error(L, "Read-only or unsupported setter type for mouseOverEventDatas");
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

static int DatapanelGUI_set_tabWin(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    return luaL_error(L, "Read-only or unsupported setter type for tabWin");
}

static int DatapanelGUI_set_tabs(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    return luaL_error(L, "Read-only or unsupported setter type for tabs");
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

static int DatapanelGUI_set_scrollView(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");
    return luaL_error(L, "Read-only or unsupported setter type for scrollView");
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

    std::string name = luaL_checkstring(L, 2);
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
    std::string name = luaL_checkstring(L, 3);
    std::string icon = luaL_checkstring(L, 4);
    instance->addTab(id, name, icon);
    return 0;
}

int DatapanelGUIBinding::_NV_addTab(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int id = (int)luaL_checkinteger(L, 2);
    std::string name = luaL_checkstring(L, 3);
    std::string icon = luaL_checkstring(L, 4);
    instance->_NV_addTab(id, name, icon);
    return 0;
}

int DatapanelGUIBinding::setTabName(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int id = (int)luaL_checkinteger(L, 2);
    std::string name = luaL_checkstring(L, 3);
    instance->setTabName(id, name);
    return 0;
}

int DatapanelGUIBinding::_NV_setTabName(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int id = (int)luaL_checkinteger(L, 2);
    std::string name = luaL_checkstring(L, 3);
    instance->_NV_setTabName(id, name);
    return 0;
}

int DatapanelGUIBinding::setCaption(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    std::string s = luaL_checkstring(L, 2);
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

    std::string s1 = luaL_checkstring(L, 2);
    std::string s2 = luaL_checkstring(L, 3);
    int category = (int)luaL_checkinteger(L, 4);
    DataPanelLine* result = instance->setLineStatInfo(s1, s2, category);
    return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
}

int DatapanelGUIBinding::setLineFaction(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    std::string s1 = luaL_checkstring(L, 2);
    std::string s2 = luaL_checkstring(L, 3);
    int category = (int)luaL_checkinteger(L, 4);
    float v1 = (float)luaL_checknumber(L, 5);
    float v2 = (float)luaL_checknumber(L, 6);
    DataPanelLine_Faction* result = instance->setLineFaction(s1, s2, category, v1, v2);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DatapanelGUIBinding::setLineTextButton(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    std::string text = luaL_checkstring(L, 2);
    std::string caption = luaL_checkstring(L, 3);
    int category = (int)luaL_checkinteger(L, 4);
    float buttonWidth = (float)luaL_checknumber(L, 5);
    std::string skin = luaL_checkstring(L, 6);
    DataPanelLine_Button* result = instance->setLineTextButton(text, caption, category, buttonWidth, skin);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DatapanelGUIBinding::setLineButton(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    std::string key = luaL_checkstring(L, 2);
    std::string caption = luaL_checkstring(L, 3);
    int category = (int)luaL_checkinteger(L, 4);
    DataPanelLine_Button* result = instance->setLineButton(key, caption, category);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DatapanelGUIBinding::setLineToggleButton(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    std::string key = luaL_checkstring(L, 2);
    std::string caption = luaL_checkstring(L, 3);
    int category = (int)luaL_checkinteger(L, 4);
    DataPanelLine_Button* result = instance->setLineToggleButton(key, caption, category);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DatapanelGUIBinding::setLineProgress(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    std::string key = luaL_checkstring(L, 2);
    int category = (int)luaL_checkinteger(L, 3);
    float progressValue = (float)luaL_checknumber(L, 4);
    std::string progressText = luaL_checkstring(L, 5);
    bool showKey = lua_toboolean(L, 6) != 0;
    DataPanelLine_Progress* result = instance->setLineProgress(key, category, progressValue, progressText, showKey);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DatapanelGUIBinding::removeLine(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    std::string s1 = luaL_checkstring(L, 2);
    int category = (int)luaL_checkinteger(L, 3);
    instance->removeLine(s1, category);
    return 0;
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
    std::string image = luaL_checkstring(L, 3);
    instance->setCategoryIcon(cat, image);
    return 0;
}

int DatapanelGUIBinding::_NV_setCategoryIcon(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    int cat = (int)luaL_checkinteger(L, 2);
    std::string image = luaL_checkstring(L, 3);
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

    std::string key = luaL_checkstring(L, 2);
    int cat = (int)luaL_checkinteger(L, 3);
    DataPanelLine* result = instance->getLine(key, cat);
    return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
}

int DatapanelGUIBinding::_NV_getLine(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    std::string key = luaL_checkstring(L, 2);
    int cat = (int)luaL_checkinteger(L, 3);
    DataPanelLine* result = instance->_NV_getLine(key, cat);
    return pushObject<DataPanelLine>(L, result, DataPanelLineBinding::getMetatableName());
}

int DatapanelGUIBinding::lineExists(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    std::string key = luaL_checkstring(L, 2);
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

int DatapanelGUIBinding::_DESTRUCTOR(lua_State* L)
{
    DatapanelGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DatapanelGUI is nil");

    instance->_DESTRUCTOR();
    return 0;
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
    std::string name = luaL_checkstring(L, 3);
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

/*
Skipped methods needing manual binding:
  line 57: void setTabEnabled(...) - non-string reference arg
  line 58: void _NV_setTabEnabled(...) - non-string reference arg
  line 62: void setCloseCallback(...) - unsupported arg type
  line 69: DataPanelLine* setLine(...) - overloaded method
  line 70: DataPanelLine* setLine(...) - overloaded method
  line 71: DataPanelLine* setLine(...) - overloaded method
  line 72: DataPanelLine* setLine(...) - overloaded method
  line 73: DataPanelLine* setLine(...) - overloaded method
  line 76: DataPanelLine_Research* setLineResearch(...) - overloaded method
  line 77: DataPanelLine_Research* setLineResearch(...) - overloaded method
  line 81: DataPanelLine_SliderEditable* setLineSliderEditable(...) - pointer arg
  line 82: DataPanelLine_Text* setLineText(...) - unsupported arg type
  line 83: DataPanelLine_TextEditable* setLineTextEditable(...) - unsupported arg type
  line 84: DataPanelLine_Slider* setLineSlider(...) - pointer arg
  line 87: DataPanelLine_CheckBox* setLineCheckbox(...) - pointer arg
  line 88: DataPanelLine_DropBox* setLineDropBox(...) - pointer arg
  line 90: void setLines(...) - unsupported arg type
  line 97: void addCustomLine(...) - unsupported arg type
  line 98: void autoChangeSelectedObject(...) - unsupported arg type
  line 99: void _NV_autoChangeSelectedObject(...) - unsupported arg type
  line 100: hand getObject(...) - unsupported return type
  line 101: hand _NV_getObject(...) - unsupported return type
  line 102: void setObject(...) - unsupported arg type
  line 103: void _NV_setObject(...) - unsupported arg type
  line 106: void setMouseOverCallback(...) - unsupported arg type
  line 107: void _NV_setMouseOverCallback(...) - unsupported arg type
  line 113: void tabButton(...) - unsupported arg type
  line 121: DatapanelGUI* _CONSTRUCTOR(...) - overloaded method
  line 123: DatapanelGUI* _CONSTRUCTOR(...) - overloaded method
  line 129: DataPanelLine* createLine(...) - unsupported arg type
  line 131: void closeButtonCallback(...) - unsupported arg type
  line 132: void mouseOverCallback(...) - unsupported arg type
  line 133: void notifyMouseWheel(...) - unsupported arg type
  line 134: MyGUI::types::TCoord<int> getCoords(...) - unsupported return type
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
        { "setLineProgress", DatapanelGUIBinding::setLineProgress },
        { "removeLine", DatapanelGUIBinding::removeLine },
        { "addSpace", DatapanelGUIBinding::addSpace },
        { "setCategoryIcon", DatapanelGUIBinding::setCategoryIcon },
        { "_NV_setCategoryIcon", DatapanelGUIBinding::_NV_setCategoryIcon },
        { "changeCategory", DatapanelGUIBinding::changeCategory },
        { "_NV_changeCategory", DatapanelGUIBinding::_NV_changeCategory },
        { "getCurrentCategory", DatapanelGUIBinding::getCurrentCategory },
        { "_NV_getCurrentCategory", DatapanelGUIBinding::_NV_getCurrentCategory },
        { "setLineSpacing", DatapanelGUIBinding::setLineSpacing },
        { "_NV_setLineSpacing", DatapanelGUIBinding::_NV_setLineSpacing },
        { "getLine", DatapanelGUIBinding::getLine },
        { "_NV_getLine", DatapanelGUIBinding::_NV_getLine },
        { "lineExists", DatapanelGUIBinding::lineExists },
        { "getContentHeight", DatapanelGUIBinding::getContentHeight },
        { "getNumLines", DatapanelGUIBinding::getNumLines },
        { "getLineByNum", DatapanelGUIBinding::getLineByNum },
        { "_DESTRUCTOR", DatapanelGUIBinding::_DESTRUCTOR },
        { "getNextVerticalPos", DatapanelGUIBinding::getNextVerticalPos },
        { "dataExists", DatapanelGUIBinding::dataExists },
        { "clearCategoryTabs", DatapanelGUIBinding::clearCategoryTabs },
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
    lua_pushcfunction(L, DatapanelGUI_get_tabEvent);
    lua_setfield(L, -2, "tabEvent");
    lua_pushcfunction(L, DatapanelGUI_get_frequentUpdatesWanted);
    lua_setfield(L, -2, "frequentUpdatesWanted");
    lua_pushcfunction(L, DatapanelGUI_get_scrollWin);
    lua_setfield(L, -2, "scrollWin");
    lua_pushcfunction(L, DatapanelGUI_get_premadeParentWindow);
    lua_setfield(L, -2, "premadeParentWindow");
    lua_pushcfunction(L, DatapanelGUI_get_scrolling);
    lua_setfield(L, -2, "scrolling");
    lua_pushcfunction(L, DatapanelGUI_get_isWindow);
    lua_setfield(L, -2, "isWindow");
    lua_pushcfunction(L, DatapanelGUI_get_content);
    lua_setfield(L, -2, "content");
    lua_pushcfunction(L, DatapanelGUI_get_bottomLine);
    lua_setfield(L, -2, "bottomLine");
    lua_pushcfunction(L, DatapanelGUI_get_currentCategory);
    lua_setfield(L, -2, "currentCategory");
    lua_pushcfunction(L, DatapanelGUI_get_mouseOverEvent);
    lua_setfield(L, -2, "mouseOverEvent");
    lua_pushcfunction(L, DatapanelGUI_get_mouseOverEventDatas);
    lua_setfield(L, -2, "mouseOverEventDatas");
    lua_pushcfunction(L, DatapanelGUI_get_automaticRefresh);
    lua_setfield(L, -2, "automaticRefresh");
    lua_pushcfunction(L, DatapanelGUI_get_automaticTarget);
    lua_setfield(L, -2, "automaticTarget");
    lua_pushcfunction(L, DatapanelGUI_get_tabWin);
    lua_setfield(L, -2, "tabWin");
    lua_pushcfunction(L, DatapanelGUI_get_tabs);
    lua_setfield(L, -2, "tabs");
    lua_pushcfunction(L, DatapanelGUI_get_panelName);
    lua_setfield(L, -2, "panelName");
    lua_pushcfunction(L, DatapanelGUI_get_x);
    lua_setfield(L, -2, "x");
    lua_pushcfunction(L, DatapanelGUI_get_y);
    lua_setfield(L, -2, "y");
    lua_pushcfunction(L, DatapanelGUI_get_w);
    lua_setfield(L, -2, "w");
    lua_pushcfunction(L, DatapanelGUI_get_h);
    lua_setfield(L, -2, "h");
    lua_pushcfunction(L, DatapanelGUI_get_DATALINESPACING);
    lua_setfield(L, -2, "DATALINESPACING");
    lua_pushcfunction(L, DatapanelGUI_get_DATALINETHICKNESS);
    lua_setfield(L, -2, "DATALINETHICKNESS");
    lua_pushcfunction(L, DatapanelGUI_get_basicSpacing);
    lua_setfield(L, -2, "basicSpacing");
    lua_pushcfunction(L, DatapanelGUI_get_layer);
    lua_setfield(L, -2, "layer");
    lua_pushcfunction(L, DatapanelGUI_get_scrollView);
    lua_setfield(L, -2, "scrollView");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DatapanelGUI_set_tabEvent);
    lua_setfield(L, -2, "tabEvent");
    lua_pushcfunction(L, DatapanelGUI_set_frequentUpdatesWanted);
    lua_setfield(L, -2, "frequentUpdatesWanted");
    lua_pushcfunction(L, DatapanelGUI_set_scrollWin);
    lua_setfield(L, -2, "scrollWin");
    lua_pushcfunction(L, DatapanelGUI_set_premadeParentWindow);
    lua_setfield(L, -2, "premadeParentWindow");
    lua_pushcfunction(L, DatapanelGUI_set_scrolling);
    lua_setfield(L, -2, "scrolling");
    lua_pushcfunction(L, DatapanelGUI_set_isWindow);
    lua_setfield(L, -2, "isWindow");
    lua_pushcfunction(L, DatapanelGUI_set_content);
    lua_setfield(L, -2, "content");
    lua_pushcfunction(L, DatapanelGUI_set_bottomLine);
    lua_setfield(L, -2, "bottomLine");
    lua_pushcfunction(L, DatapanelGUI_set_currentCategory);
    lua_setfield(L, -2, "currentCategory");
    lua_pushcfunction(L, DatapanelGUI_set_mouseOverEvent);
    lua_setfield(L, -2, "mouseOverEvent");
    lua_pushcfunction(L, DatapanelGUI_set_mouseOverEventDatas);
    lua_setfield(L, -2, "mouseOverEventDatas");
    lua_pushcfunction(L, DatapanelGUI_set_automaticRefresh);
    lua_setfield(L, -2, "automaticRefresh");
    lua_pushcfunction(L, DatapanelGUI_set_automaticTarget);
    lua_setfield(L, -2, "automaticTarget");
    lua_pushcfunction(L, DatapanelGUI_set_tabWin);
    lua_setfield(L, -2, "tabWin");
    lua_pushcfunction(L, DatapanelGUI_set_tabs);
    lua_setfield(L, -2, "tabs");
    lua_pushcfunction(L, DatapanelGUI_set_panelName);
    lua_setfield(L, -2, "panelName");
    lua_pushcfunction(L, DatapanelGUI_set_x);
    lua_setfield(L, -2, "x");
    lua_pushcfunction(L, DatapanelGUI_set_y);
    lua_setfield(L, -2, "y");
    lua_pushcfunction(L, DatapanelGUI_set_w);
    lua_setfield(L, -2, "w");
    lua_pushcfunction(L, DatapanelGUI_set_h);
    lua_setfield(L, -2, "h");
    lua_pushcfunction(L, DatapanelGUI_set_DATALINESPACING);
    lua_setfield(L, -2, "DATALINESPACING");
    lua_pushcfunction(L, DatapanelGUI_set_DATALINETHICKNESS);
    lua_setfield(L, -2, "DATALINETHICKNESS");
    lua_pushcfunction(L, DatapanelGUI_set_basicSpacing);
    lua_setfield(L, -2, "basicSpacing");
    lua_pushcfunction(L, DatapanelGUI_set_layer);
    lua_setfield(L, -2, "layer");
    lua_pushcfunction(L, DatapanelGUI_set_scrollView);
    lua_setfield(L, -2, "scrollView");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GUIWindow
    setMetatableParent(L, DatapanelGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua