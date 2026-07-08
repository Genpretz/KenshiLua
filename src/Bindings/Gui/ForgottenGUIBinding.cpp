#include "pch.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Gui/DialogueWindowBinding.h"

#include <kenshi/gui/ForgottenGUI.h>
#include "ForgottenGUIBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ForgottenGUI* getInstance(lua_State* L, int idx)
{
    return checkObject<ForgottenGUI>(L, idx, ForgottenGUIBinding::getMetatableName());
}

// --- Getters for ForgottenGUI ---
static int ForgottenGUI_get_hasMouse(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushboolean(L, instance->hasMouse ? 1 : 0);
    return 1;
}

static int ForgottenGUI_get_mainbar(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->mainbar);
    return 1;
}

static int ForgottenGUI_get_tooltip(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->tooltip);
    return 1;
}

static int ForgottenGUI_get_dialogue(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return pushObject<DialogueWindow>(L, instance->dialogue, DialogueWindowBinding::getMetatableName());
}

static int ForgottenGUI_get_tutorial(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->tutorial);
    return 1;
}

static int ForgottenGUI_get_tutorialpedia(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->tutorialpedia);
    return 1;
}

static int ForgottenGUI_get_currentCursor(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentCursor);
    return 1;
}

static int ForgottenGUI_get_manager(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->manager);
    return 1;
}

static int ForgottenGUI_get_guiPlatform(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->guiPlatform);
    return 1;
}

static int ForgottenGUI_get__closeTradeWindowMsg(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushboolean(L, instance->_closeTradeWindowMsg ? 1 : 0);
    return 1;
}

static int ForgottenGUI_get_characterEditor(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->characterEditor);
    return 1;
}


static int ForgottenGUI_get_cursorPanel(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return pushObject<DatapanelGUI>(L, instance->cursorPanel, DatapanelGUIBinding::getMetatableName());
}

static int ForgottenGUI_get_cursorAction(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushboolean(L, instance->cursorAction ? 1 : 0);
    return 1;
}

static int ForgottenGUI_get_visible(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushboolean(L, instance->visible ? 1 : 0);
    return 1;
}

static int ForgottenGUI_get_created(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushboolean(L, instance->created ? 1 : 0);
    return 1;
}

// --- Setters for ForgottenGUI ---
static int ForgottenGUI_set_hasMouse(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->hasMouse = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ForgottenGUI_set_currentCursor(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->currentCursor = (CursorType)luaL_checkinteger(L, 2);
    return 0;
}

static int ForgottenGUI_set__closeTradeWindowMsg(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->_closeTradeWindowMsg = lua_toboolean(L, 2) != 0;
    return 0;
}


static int ForgottenGUI_set_cursorAction(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->cursorAction = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ForgottenGUI_set_visible(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->visible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ForgottenGUI_set_created(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->created = lua_toboolean(L, 2) != 0;
    return 0;
}

int ForgottenGUIBinding::_CONSTRUCTOR(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    ForgottenGUI* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ForgottenGUIBinding::_DESTRUCTOR(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ForgottenGUIBinding::clearGUI(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->clearGUI();
    return 0;
}

int ForgottenGUIBinding::shutDown(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->shutDown();
    return 0;
}

int ForgottenGUIBinding::restart(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->restart();
    return 0;
}

int ForgottenGUIBinding::setupGuiScaling(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->setupGuiScaling();
    return 0;
}

int ForgottenGUIBinding::init(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->init();
    return 0;
}

int ForgottenGUIBinding::getTopOfScreenMessagePosition(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    float result = instance->getTopOfScreenMessagePosition();
    lua_pushnumber(L, result);
    return 1;
}

int ForgottenGUIBinding::showLoadingMessage(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->showLoadingMessage(on);
    return 0;
}

int ForgottenGUIBinding::isLoadingMessageVisible(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool result = instance->isLoadingMessageVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ForgottenGUIBinding::showPauseMessage(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->showPauseMessage(on);
    return 0;
}

int ForgottenGUIBinding::isLoading(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool result = instance->isLoading();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ForgottenGUIBinding::setLoading(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setLoading(value);
    return 0;
}

int ForgottenGUIBinding::isPaused(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool result = instance->isPaused();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ForgottenGUIBinding::inDialogue(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool result = instance->inDialogue();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ForgottenGUIBinding::hideMessageBox(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool enter = lua_toboolean(L, 2) != 0;
    bool result = instance->hideMessageBox(enter);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ForgottenGUIBinding::hasModalMessage(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool result = instance->hasModalMessage();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ForgottenGUIBinding::showMainbar(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->showMainbar(on);
    return 0;
}

int ForgottenGUIBinding::updateBountyPanelVisibility(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->updateBountyPanelVisibility();
    return 0;
}

int ForgottenGUIBinding::getInDialogue(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool result = instance->getInDialogue();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ForgottenGUIBinding::getToolTip(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    ToolTip* result = instance->getToolTip();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ForgottenGUIBinding::isVisible(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool result = instance->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ForgottenGUIBinding::toggle(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->toggle();
    return 0;
}

int ForgottenGUIBinding::showNames(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->showNames(on);
    return 0;
}

int ForgottenGUIBinding::showPrintOutput(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool v = lua_toboolean(L, 2) != 0;
    instance->showPrintOutput(v);
    return 0;
}

int ForgottenGUIBinding::closeCharacterEditor(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->closeCharacterEditor();
    return 0;
}

int ForgottenGUIBinding::isCharacterEditorMode(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool result = instance->isCharacterEditorMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ForgottenGUIBinding::closeAllCharacterStatsWindows(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->closeAllCharacterStatsWindows();
    return 0;
}

int ForgottenGUIBinding::isStatsWindowOpen(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool result = instance->isStatsWindowOpen();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ForgottenGUIBinding::characterStatsWindowVisible(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool result = instance->characterStatsWindowVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ForgottenGUIBinding::selectedObjectsChanged(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->selectedObjectsChanged();
    return 0;
}

int ForgottenGUIBinding::updateToOrdersPanel(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->updateToOrdersPanel();
    return 0;
}

int ForgottenGUIBinding::update(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->update();
    return 0;
}

int ForgottenGUIBinding::closeTradeWindow(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->closeTradeWindow();
    return 0;
}

int ForgottenGUIBinding::closeInventoryBuilding(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->closeInventoryBuilding();
    return 0;
}

int ForgottenGUIBinding::closeAllInventories(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->closeAllInventories();
    return 0;
}

int ForgottenGUIBinding::closeAllWindows(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->closeAllWindows();
    return 0;
}

int ForgottenGUIBinding::getNumOpenInventoryWindows(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    int result = instance->getNumOpenInventoryWindows();
    lua_pushinteger(L, result);
    return 1;
}

int ForgottenGUIBinding::getInventoryWindowWithMouse(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    InventoryGUI* result = instance->getInventoryWindowWithMouse();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ForgottenGUIBinding::isAnyInventoryWindowOpen(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool result = instance->isAnyInventoryWindowOpen();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ForgottenGUIBinding::toggleHelpWindow(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    instance->toggleHelpWindow();
    return 0;
}

int ForgottenGUIBinding::setMouseCursorVisible(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setMouseCursorVisible(visible);
    return 0;
}

int ForgottenGUIBinding::getGuiManager(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    MyGUI::Gui* result = instance->getGuiManager();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ForgottenGUIBinding::createPanel(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    std::string name = luaL_checkstring(L, 2);
    float top = (float)luaL_checknumber(L, 3);
    float left = (float)luaL_checknumber(L, 4);
    float width = (float)luaL_checknumber(L, 5);
    float height = (float)luaL_checknumber(L, 6);
    std::string layer = luaL_checkstring(L, 7);
    std::string skin = luaL_checkstring(L, 8);
    MyGUI::Window* result = instance->createPanel(name, top, left, width, height, layer, skin);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ForgottenGUIBinding::createPanelAbs(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    std::string name = luaL_checkstring(L, 2);
    float top = (float)luaL_checknumber(L, 3);
    float left = (float)luaL_checknumber(L, 4);
    float width = (float)luaL_checknumber(L, 5);
    float height = (float)luaL_checknumber(L, 6);
    std::string layer = luaL_checkstring(L, 7);
    std::string skin = luaL_checkstring(L, 8);
    MyGUI::Window* result = instance->createPanelAbs(name, top, left, width, height, layer, skin);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ForgottenGUIBinding::createTabPanel(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    std::string name = luaL_checkstring(L, 2);
    float top = (float)luaL_checknumber(L, 3);
    float left = (float)luaL_checknumber(L, 4);
    float width = (float)luaL_checknumber(L, 5);
    float height = (float)luaL_checknumber(L, 6);
    std::string layer = luaL_checkstring(L, 7);
    std::string skin = luaL_checkstring(L, 8);
    MyGUI::TabControl* result = instance->createTabPanel(name, top, left, width, height, layer, skin);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ForgottenGUIBinding::createFloatingImage(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    std::string image = luaL_checkstring(L, 2);
    float top = (float)luaL_checknumber(L, 3);
    float left = (float)luaL_checknumber(L, 4);
    float width = (float)luaL_checknumber(L, 5);
    float height = (float)luaL_checknumber(L, 6);
    std::string layer = luaL_checkstring(L, 7);
    MyGUI::Window* result = instance->createFloatingImage(image, top, left, width, height, layer);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ForgottenGUIBinding::createFloatingImageAbs(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    std::string image = luaL_checkstring(L, 2);
    float top = (float)luaL_checknumber(L, 3);
    float left = (float)luaL_checknumber(L, 4);
    float width = (float)luaL_checknumber(L, 5);
    float height = (float)luaL_checknumber(L, 6);
    std::string layer = luaL_checkstring(L, 7);
    MyGUI::Window* result = instance->createFloatingImageAbs(image, top, left, width, height, layer);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ForgottenGUIBinding::createFloatingProgressBar(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    FloatingProgressBar* result = instance->createFloatingProgressBar();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ForgottenGUIBinding::createScreenLabelD(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    std::string text = luaL_checkstring(L, 2);
    float time = (float)luaL_checknumber(L, 3);
    ScreenLabelDebug* result = instance->createScreenLabelD(text, time);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 54: void changeFontSize(...) - static method
  line 65: void destroy(...) - overloaded method
  line 66: void destroy(...) - overloaded method
  line 67: void destroy(...) - overloaded method
  line 68: DatapanelGUI* createDatapanel(...) - overloaded method
  line 69: DatapanelGUI* createDatapanel(...) - overloaded method
  line 70: MyGUI::Window* messageBox(...) - unsupported arg type
  line 82: void showCharacterEditor(...) - unsupported arg type
  line 85: void showCharacterStatsWindow(...) - unsupported arg type
  line 86: void closeCharacterStatsWindow(...) - unsupported arg type
  line 89: void toggleStatsWindow(...) - unsupported arg type
  line 90: void toggleCharacterStatsWindowPermanent(...) - unsupported arg type
  line 94: void notifyTownDeleted(...) - unsupported arg type
  line 96: void showTradeWindow(...) - unsupported arg type
  line 98: InventoryGUI* showInventory(...) - unsupported arg type
  line 99: InventoryGUI* showTraderInventory(...) - unsupported arg type
  line 100: InventoryGUI* showInventoryBuilding(...) - unsupported arg type
  line 101: InventoryGUI* showInventoryNPC(...) - unsupported arg type
  line 102: void closeInventory(...) - unsupported arg type
  line 106: InventoryGUI* getInventoryWindow(...) - unsupported arg type
  line 107: InventoryGUI* toggleInventory(...) - unsupported arg type
  line 110: bool hasInventoryWindowOpen(...) - unsupported arg type
  line 112: void toggleInventoryWindowPermanent(...) - unsupported arg type
  line 114: const hand& getSelectedObject(...) - reference return type
  line 115: const hand& getSelectedPlayerCharacter(...) - reference return type
  line 116: void addWindowToUpdateList(...) - unsupported arg type
  line 117: void removeWindowFromUpdateList(...) - unsupported arg type
  line 118: void addScreenLabel(...) - unsupported arg type
  line 119: void addDatapanelToUpdateList(...) - unsupported arg type
  line 120: void removeDatapanelFromUpdateList(...) - unsupported arg type
  line 121: void destroyWidget(...) - unsupported arg type
  line 122: void destroyWidgets(...) - overloaded method
  line 123: void destroyWidgets(...) - overloaded method
  line 124: bool widgetHasMouse(...) - unsupported arg type
  line 132: void setup(...) - unsupported arg type
  line 133: void changeMouseCursor(...) - overloaded method
  line 134: void changeMouseCursor(...) - overloaded method
  line 141: void _showTradeWindow(...) - unsupported arg type
  line 142: void setInventoryPosition(...) - unsupported arg type
  line 143: InventoryGUI* createInventoryWindow(...) - overloaded method
  line 144: InventoryGUI* createInventoryWindow(...) - overloaded method
  line 145: void inventoriesSelectedObjectUpdate(...) - unsupported arg type
  line 174: void keepWindownOnScreen(...) - unsupported arg type
  line 175: const std::string& getDataLineColor(...) - reference return type
  line 179: MyGUI::ImageBox* createImage(...) - unsupported arg type
  line 180: MyGUI::ImageBox* createImageAbs(...) - unsupported arg type
  line 181: MyGUI::ImageBox* createRotatableImageAbs(...) - unsupported arg type
  line 183: MyGUI::Button* createButtonAbs(...) - unsupported arg type
  line 184: MyGUI::Button* createButton(...) - unsupported arg type
  line 185: MyGUI::ComboBox* createDropBox(...) - unsupported arg type
  line 186: MyGUI::ComboBox* createDropBoxAbs(...) - unsupported arg type
  line 187: MyGUI::ProgressBar* createProgressBar(...) - unsupported arg type
  line 188: MyGUI::ProgressBar* createProgressBarAbs(...) - unsupported arg type
  line 189: MyGUI::Window* createFloatingLabel(...) - unsupported arg type
  line 190: MyGUI::EditBox* createLabel(...) - overloaded method
  line 191: MyGUI::TextBox* createLabel(...) - overloaded method
  line 192: MyGUI::TextBox* createLabelAbs(...) - overloaded method
  line 193: MyGUI::EditBox* createLabelAbs(...) - overloaded method
  line 194: MyGUI::EditBox* createValueEdit(...) - unsupported arg type
  line 195: MyGUI::EditBox* createEditBox(...) - overloaded method
  line 196: MyGUI::EditBox* createEditBox(...) - overloaded method
  line 197: MyGUI::EditBox* createEditBoxAbs(...) - overloaded method
  line 198: MyGUI::EditBox* createEditBoxAbs(...) - overloaded method
  line 199: MyGUI::ScrollBar* createScrollBarAbs(...) - unsupported arg type
  line 200: MyGUI::Button* createCheckbox(...) - unsupported arg type
  line 201: MyGUI::EditBox* createValueEditTransparent(...) - unsupported arg type
  line 202: MyGUI::ListBox* createListbox(...) - unsupported arg type
  line 206: ScreenLabel* createScreenLabel(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 138: Scale (Ogre::Vector2) - unsupported type
  line 146: _showTradeWindowMsg (TradeWindowType) - unsupported type
  line 148: tradeA (hand) - unsupported type
  line 149: tradeB (hand) - unsupported type
  line 150: inventoryWindowsOpen (ogre_unordered_map<hand, InventoryGUI*>::type) - unsupported type
  line 151: inventoryWindowBuilding (hand) - unsupported type
  line 152: inventoryWindowCharacter (hand) - unsupported type
  line 153: inventoryWindowTrader (hand) - unsupported type
  line 154: inventoryWindowNPC (hand) - unsupported type
  line 155: inventoryWindowsPermanent (ogre_unordered_set<hand>::type) - unsupported type
  line 156: inventoryWindowsKillList (Ogre::vector<InventoryGUI*>::type) - unsupported type
  line 158: characterStatsWindows (Ogre::vector<CharacterStatsWindow*>::type) - unsupported type
  line 159: characterStatsWindowsKillList (Ogre::vector<CharacterStatsWindow*>::type) - unsupported type
  line 160: guiWindows (lektor<GUIWindow*>) - unsupported type
  line 161: guiDatapanels (lektor<DatapanelGUI*>) - unsupported type
  line 163: guiScreenLabels (lektor<ScreenLabelInterface*>) - unsupported type
  line 164: guiScreenLabelsToAdd (lektor<ScreenLabelInterface*>) - unsupported type
  line 165: guiScreenLabelsToRemove (lektor<ScreenLabelInterface*>) - unsupported type
  line 166: selectedObject (hand) - unsupported type
  line 167: selectedPlayerCharacter (hand) - unsupported type
  line 170: cursorActionPlayer (hand) - unsupported type
  line 171: cursorActionTarget (hand) - unsupported type
*/

int ForgottenGUIBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ForgottenGUIBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ForgottenGUI object");
    return 1;
}

void ForgottenGUIBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ForgottenGUIBinding::gc },
        { "__tostring", ForgottenGUIBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ForgottenGUIBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ForgottenGUIBinding::_DESTRUCTOR },
        { "clearGUI", ForgottenGUIBinding::clearGUI },
        { "shutDown", ForgottenGUIBinding::shutDown },
        { "restart", ForgottenGUIBinding::restart },
        { "setupGuiScaling", ForgottenGUIBinding::setupGuiScaling },
        { "init", ForgottenGUIBinding::init },
        { "getTopOfScreenMessagePosition", ForgottenGUIBinding::getTopOfScreenMessagePosition },
        { "showLoadingMessage", ForgottenGUIBinding::showLoadingMessage },
        { "isLoadingMessageVisible", ForgottenGUIBinding::isLoadingMessageVisible },
        { "showPauseMessage", ForgottenGUIBinding::showPauseMessage },
        { "isLoading", ForgottenGUIBinding::isLoading },
        { "setLoading", ForgottenGUIBinding::setLoading },
        { "isPaused", ForgottenGUIBinding::isPaused },
        { "inDialogue", ForgottenGUIBinding::inDialogue },
        { "hideMessageBox", ForgottenGUIBinding::hideMessageBox },
        { "hasModalMessage", ForgottenGUIBinding::hasModalMessage },
        { "showMainbar", ForgottenGUIBinding::showMainbar },
        { "updateBountyPanelVisibility", ForgottenGUIBinding::updateBountyPanelVisibility },
        { "getInDialogue", ForgottenGUIBinding::getInDialogue },
        { "getToolTip", ForgottenGUIBinding::getToolTip },
        { "isVisible", ForgottenGUIBinding::isVisible },
        { "toggle", ForgottenGUIBinding::toggle },
        { "showNames", ForgottenGUIBinding::showNames },
        { "showPrintOutput", ForgottenGUIBinding::showPrintOutput },
        { "closeCharacterEditor", ForgottenGUIBinding::closeCharacterEditor },
        { "isCharacterEditorMode", ForgottenGUIBinding::isCharacterEditorMode },
        { "closeAllCharacterStatsWindows", ForgottenGUIBinding::closeAllCharacterStatsWindows },
        { "isStatsWindowOpen", ForgottenGUIBinding::isStatsWindowOpen },
        { "characterStatsWindowVisible", ForgottenGUIBinding::characterStatsWindowVisible },
        { "selectedObjectsChanged", ForgottenGUIBinding::selectedObjectsChanged },
        { "updateToOrdersPanel", ForgottenGUIBinding::updateToOrdersPanel },
        { "update", ForgottenGUIBinding::update },
        { "closeTradeWindow", ForgottenGUIBinding::closeTradeWindow },
        { "closeInventoryBuilding", ForgottenGUIBinding::closeInventoryBuilding },
        { "closeAllInventories", ForgottenGUIBinding::closeAllInventories },
        { "closeAllWindows", ForgottenGUIBinding::closeAllWindows },
        { "getNumOpenInventoryWindows", ForgottenGUIBinding::getNumOpenInventoryWindows },
        { "getInventoryWindowWithMouse", ForgottenGUIBinding::getInventoryWindowWithMouse },
        { "isAnyInventoryWindowOpen", ForgottenGUIBinding::isAnyInventoryWindowOpen },
        { "toggleHelpWindow", ForgottenGUIBinding::toggleHelpWindow },
        { "setMouseCursorVisible", ForgottenGUIBinding::setMouseCursorVisible },
        { "getGuiManager", ForgottenGUIBinding::getGuiManager },
        { "createPanel", ForgottenGUIBinding::createPanel },
        { "createPanelAbs", ForgottenGUIBinding::createPanelAbs },
        { "createTabPanel", ForgottenGUIBinding::createTabPanel },
        { "createFloatingImage", ForgottenGUIBinding::createFloatingImage },
        { "createFloatingImageAbs", ForgottenGUIBinding::createFloatingImageAbs },
        { "createFloatingProgressBar", ForgottenGUIBinding::createFloatingProgressBar },
        { "createScreenLabelD", ForgottenGUIBinding::createScreenLabelD },
        { 0, 0 }
    };

    registerClass(
        L, 
        ForgottenGUIBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ForgottenGUIBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ForgottenGUI_get_hasMouse);
    lua_setfield(L, -2, "hasMouse");
    lua_pushcfunction(L, ForgottenGUI_get_mainbar);
    lua_setfield(L, -2, "mainbar");
    lua_pushcfunction(L, ForgottenGUI_get_tooltip);
    lua_setfield(L, -2, "tooltip");
    lua_pushcfunction(L, ForgottenGUI_get_dialogue);
    lua_setfield(L, -2, "dialogue");
    lua_pushcfunction(L, ForgottenGUI_get_tutorial);
    lua_setfield(L, -2, "tutorial");
    lua_pushcfunction(L, ForgottenGUI_get_tutorialpedia);
    lua_setfield(L, -2, "tutorialpedia");
    lua_pushcfunction(L, ForgottenGUI_get_currentCursor);
    lua_setfield(L, -2, "currentCursor");
    lua_pushcfunction(L, ForgottenGUI_get_manager);
    lua_setfield(L, -2, "manager");
    lua_pushcfunction(L, ForgottenGUI_get_guiPlatform);
    lua_setfield(L, -2, "guiPlatform");
    lua_pushcfunction(L, ForgottenGUI_get__closeTradeWindowMsg);
    lua_setfield(L, -2, "_closeTradeWindowMsg");
    lua_pushcfunction(L, ForgottenGUI_get_characterEditor);
    lua_setfield(L, -2, "characterEditor");
    lua_pushcfunction(L, ForgottenGUI_get_cursorPanel);
    lua_setfield(L, -2, "cursorPanel");
    lua_pushcfunction(L, ForgottenGUI_get_cursorAction);
    lua_setfield(L, -2, "cursorAction");
    lua_pushcfunction(L, ForgottenGUI_get_visible);
    lua_setfield(L, -2, "visible");
    lua_pushcfunction(L, ForgottenGUI_get_created);
    lua_setfield(L, -2, "created");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ForgottenGUI_set_hasMouse);
    lua_setfield(L, -2, "hasMouse");
    lua_pushcfunction(L, ForgottenGUI_set_currentCursor);
    lua_setfield(L, -2, "currentCursor");
    lua_pushcfunction(L, ForgottenGUI_set__closeTradeWindowMsg);
    lua_setfield(L, -2, "_closeTradeWindowMsg");
    lua_pushcfunction(L, ForgottenGUI_set_cursorAction);
    lua_setfield(L, -2, "cursorAction");
    lua_pushcfunction(L, ForgottenGUI_set_visible);
    lua_setfield(L, -2, "visible");
    lua_pushcfunction(L, ForgottenGUI_set_created);
    lua_setfield(L, -2, "created");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // // // // // // // // // setMetatableParent(L, ForgottenGUIBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua