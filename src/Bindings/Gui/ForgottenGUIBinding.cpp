#include "pch.h"
#include "kenshi\gui\ForgottenGUI.h"
#include "ForgottenGUIBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/CharacterEditWindowBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Gui/DialogueWindowBinding.h"
#include "Bindings/Gui/FloatingProgressBarBinding.h"
#include "Bindings/Gui/GUIWindowBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/Gui/InventoryGUIBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"
#include "Bindings/Gui/MainBarGUIBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Gui/ToolTipBinding.h"
#include "Bindings/TownBinding.h"
#include "Bindings/Gui/TutorialGUIBinding.h"
#include "Bindings/Gui/TutorialpediaGUIBinding.h"
#include "Bindings/Gui/ScreenLabelInterfaceBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"

namespace KenshiLua
{

typedef OgreUnorderedMapBinding<hand, InventoryGUI*> ForgottenInventoryWindowsOpenMapBinding;
typedef OgreUnorderedSetBinding<hand> ForgottenInventoryWindowsPermanentSetBinding;

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
    return pushObject<MainBarGUI>(L, instance->mainbar, MainBarGUIBinding::getMetatableName());
}

static int ForgottenGUI_get_tooltip(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return pushObject<ToolTip>(L, instance->tooltip, ToolTipBinding::getMetatableName());
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
    return pushObject<TutorialGUI>(L, instance->tutorial, TutorialGUIBinding::getMetatableName());
}

static int ForgottenGUI_get_tutorialpedia(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return pushObject<TutorialpediaGUI>(L, instance->tutorialpedia, TutorialpediaGUIBinding::getMetatableName());
}

static int ForgottenGUI_get_currentCursor(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentCursor);
    return 1;
}

static int ForgottenGUI_get_Scale(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    pushVector2(L, instance->Scale);
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

static int ForgottenGUI_get_tradeA(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return HandBinding::push(L, instance->tradeA);
}

static int ForgottenGUI_get_tradeB(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return HandBinding::push(L, instance->tradeB);
}

static int ForgottenGUI_get_inventoryWindowBuilding(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return HandBinding::push(L, instance->inventoryWindowBuilding);
}

static int ForgottenGUI_get_inventoryWindowCharacter(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return HandBinding::push(L, instance->inventoryWindowCharacter);
}

static int ForgottenGUI_get_inventoryWindowTrader(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return HandBinding::push(L, instance->inventoryWindowTrader);
}

static int ForgottenGUI_get_inventoryWindowNPC(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return HandBinding::push(L, instance->inventoryWindowNPC);
}

static int ForgottenGUI_get_characterEditor(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return pushObject<CharacterEditWindow>(L, instance->characterEditor, CharacterEditWindowBinding::getMetatableName());
}

static int ForgottenGUI_get_guiScreenLabelsMutex(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    lua_pushlightuserdata(L, (void*)&instance->guiScreenLabelsMutex);
    return 1;
}

static int ForgottenGUI_get_selectedObject(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return HandBinding::push(L, instance->selectedObject);
}

static int ForgottenGUI_get_selectedPlayerCharacter(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return HandBinding::push(L, instance->selectedPlayerCharacter);
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

static int ForgottenGUI_get_cursorActionPlayer(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return HandBinding::push(L, instance->cursorActionPlayer);
}

static int ForgottenGUI_get_cursorActionTarget(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return HandBinding::push(L, instance->cursorActionTarget);
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

static int ForgottenGUI_get_inventoryWindowsOpen(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return pushObject<ForgottenInventoryWindowsOpenMapBinding::MapType>(L, &instance->inventoryWindowsOpen, ForgottenInventoryWindowsOpenMapBinding::getMetatableName());
}

static int ForgottenGUI_get_inventoryWindowsPermanent(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return pushObject<ForgottenInventoryWindowsPermanentSetBinding::SetType>(L, &instance->inventoryWindowsPermanent, ForgottenInventoryWindowsPermanentSetBinding::getMetatableName());
}

static int ForgottenGUI_get_guiWindows(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return pushObject<lektor<GUIWindow*>>(L, &instance->guiWindows, LektorPtrBinding<GUIWindow*>::metaName);
}

static int ForgottenGUI_get_guiDatapanels(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return pushObject<lektor<DatapanelGUI*>>(L, &instance->guiDatapanels, LektorPtrBinding<DatapanelGUI*>::metaName);
}

static int ForgottenGUI_get_guiScreenLabels(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    return pushObject<lektor<ScreenLabelInterface*>>(L, &instance->guiScreenLabels, LektorPtrBinding<ScreenLabelInterface*>::metaName);
}

// --- Setters for ForgottenGUI ---
static int ForgottenGUI_set_inventoryWindowsOpen(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    auto* val = checkObject<ForgottenInventoryWindowsOpenMapBinding::MapType>(L, 2, ForgottenInventoryWindowsOpenMapBinding::getMetatableName());
    if (val) instance->inventoryWindowsOpen = *val;
    return 0;
}

static int ForgottenGUI_set_inventoryWindowsPermanent(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    auto* val = checkObject<ForgottenInventoryWindowsPermanentSetBinding::SetType>(L, 2, ForgottenInventoryWindowsPermanentSetBinding::getMetatableName());
    if (val) instance->inventoryWindowsPermanent = *val;
    return 0;
}

static int ForgottenGUI_set_hasMouse(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->hasMouse = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ForgottenGUI_set_mainbar(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->mainbar = lua_isnoneornil(L, 2) ? nullptr : checkObject<MainBarGUI>(L, 2, MainBarGUIBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_tooltip(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->tooltip = lua_isnoneornil(L, 2) ? nullptr : checkObject<ToolTip>(L, 2, ToolTipBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_dialogue(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->dialogue = lua_isnoneornil(L, 2) ? nullptr : checkObject<DialogueWindow>(L, 2, DialogueWindowBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_tutorial(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->tutorial = lua_isnoneornil(L, 2) ? nullptr : checkObject<TutorialGUI>(L, 2, TutorialGUIBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_tutorialpedia(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->tutorialpedia = lua_isnoneornil(L, 2) ? nullptr : checkObject<TutorialpediaGUI>(L, 2, TutorialpediaGUIBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_currentCursor(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->currentCursor = (CursorType)luaL_checkinteger(L, 2);
    return 0;
}

static int ForgottenGUI_set_Scale(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    readVector2(L, 2, instance->Scale);
    return 0;
}

static int ForgottenGUI_set__closeTradeWindowMsg(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->_closeTradeWindowMsg = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ForgottenGUI_set_tradeA(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->tradeA = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_tradeB(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->tradeB = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_inventoryWindowBuilding(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->inventoryWindowBuilding = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_inventoryWindowCharacter(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->inventoryWindowCharacter = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_inventoryWindowTrader(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->inventoryWindowTrader = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_inventoryWindowNPC(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->inventoryWindowNPC = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_characterEditor(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->characterEditor = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharacterEditWindow>(L, 2, CharacterEditWindowBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_guiScreenLabelsMutex(lua_State* L)
{
    return luaL_error(L, "guiScreenLabelsMutex is read-only");
}

static int ForgottenGUI_set_guiWindows(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    auto* val = checkObject<lektor<GUIWindow*>>(L, 2, LektorPtrBinding<GUIWindow*>::metaName);
    if (val) instance->guiWindows = *val;
    return 0;
}

static int ForgottenGUI_set_guiDatapanels(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    auto* val = checkObject<lektor<DatapanelGUI*>>(L, 2, LektorPtrBinding<DatapanelGUI*>::metaName);
    if (val) instance->guiDatapanels = *val;
    return 0;
}

static int ForgottenGUI_set_guiScreenLabels(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    auto* val = checkObject<lektor<ScreenLabelInterface*>>(L, 2, LektorPtrBinding<ScreenLabelInterface*>::metaName);
    if (val) instance->guiScreenLabels = *val;
    return 0;
}

static int ForgottenGUI_set_selectedObject(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->selectedObject = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_selectedPlayerCharacter(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->selectedPlayerCharacter = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_cursorPanel(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->cursorPanel = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_cursorAction(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->cursorAction = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ForgottenGUI_set_cursorActionPlayer(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->cursorActionPlayer = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int ForgottenGUI_set_cursorActionTarget(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");
    instance->cursorActionTarget = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
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
    return pushObject<ToolTip>(L, result, ToolTipBinding::getMetatableName());
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

int ForgottenGUIBinding::notifyTownDeleted(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    Town* t = checkObject<Town>(L, 2, TownBinding::getMetatableName());
    instance->notifyTownDeleted(t);
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
    return pushObject<InventoryGUI>(L, result, InventoryGUIBinding::getMetatableName());
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

int ForgottenGUIBinding::addWindowToUpdateList(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    GUIWindow* win = checkObject<GUIWindow>(L, 2, GUIWindowBinding::getMetatableName());
    instance->addWindowToUpdateList(win);
    return 0;
}

int ForgottenGUIBinding::removeWindowFromUpdateList(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    GUIWindow* win = checkObject<GUIWindow>(L, 2, GUIWindowBinding::getMetatableName());
    instance->removeWindowFromUpdateList(win);
    return 0;
}

int ForgottenGUIBinding::addDatapanelToUpdateList(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    instance->addDatapanelToUpdateList(datapanel);
    return 0;
}

int ForgottenGUIBinding::removeDatapanelFromUpdateList(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    instance->removeDatapanelFromUpdateList(datapanel);
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

    const std::string name = luaL_checkstring(L, 2);
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

    const std::string name = luaL_checkstring(L, 2);
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

    const std::string name = luaL_checkstring(L, 2);
    float top = (float)luaL_checknumber(L, 3);
    float left = (float)luaL_checknumber(L, 4);
    float width = (float)luaL_checknumber(L, 5);
    float height = (float)luaL_checknumber(L, 6);
    const std::string layer = luaL_checkstring(L, 7);
    const std::string skin = luaL_checkstring(L, 8);
    MyGUI::TabControl* result = instance->createTabPanel(name, top, left, width, height, layer, skin);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ForgottenGUIBinding::createFloatingImage(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    const std::string image = luaL_checkstring(L, 2);
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

    const std::string image = luaL_checkstring(L, 2);
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
    return pushObject<FloatingProgressBar>(L, result, FloatingProgressBarBinding::getMetatableName());
}

int ForgottenGUIBinding::createScreenLabelD(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    const std::string text = luaL_checkstring(L, 2);
    float time = (float)luaL_checknumber(L, 3);
    ScreenLabelDebug* result = instance->createScreenLabelD(text, time);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ForgottenGUIBinding::showCharacterStatsWindow(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    hand* owner = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!owner) return luaL_error(L, "Argument 2 to showCharacterStatsWindow must be hand");
    instance->showCharacterStatsWindow(*owner);
    return 0;
}

int ForgottenGUIBinding::closeCharacterStatsWindow(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    hand* owner = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!owner) return luaL_error(L, "Argument 2 to closeCharacterStatsWindow must be hand");
    instance->closeCharacterStatsWindow(*owner);
    return 0;
}

int ForgottenGUIBinding::toggleStatsWindow(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    hand* owner = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!owner) return luaL_error(L, "Argument 2 to toggleStatsWindow must be hand");
    instance->toggleStatsWindow(*owner);
    return 0;
}

int ForgottenGUIBinding::toggleCharacterStatsWindowPermanent(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    hand* owner = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!owner) return luaL_error(L, "Argument 2 to toggleCharacterStatsWindowPermanent must be hand");
    instance->toggleCharacterStatsWindowPermanent(*owner);
    return 0;
}

int ForgottenGUIBinding::showInventory(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    hand* owner = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!owner) return luaL_error(L, "Argument 2 to showInventory must be hand");
    bool autoPosition = lua_toboolean(L, 3) != 0;
    float x = (float)luaL_optnumber(L, 4, 0.0f);
    float y = (float)luaL_optnumber(L, 5, 0.0f);
    InventoryGUI* result = instance->showInventory(*owner, autoPosition, x, y);
    return pushObject<InventoryGUI>(L, result, InventoryGUIBinding::getMetatableName());
}

int ForgottenGUIBinding::showTraderInventory(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    hand* owner = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!owner) return luaL_error(L, "Argument 2 to showTraderInventory must be hand");
    InventoryGUI* result = instance->showTraderInventory(*owner);
    return pushObject<InventoryGUI>(L, result, InventoryGUIBinding::getMetatableName());
}

int ForgottenGUIBinding::showInventoryBuilding(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    hand* owner = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!owner) return luaL_error(L, "Argument 2 to showInventoryBuilding must be hand");
    InventoryGUI* result = instance->showInventoryBuilding(*owner);
    return pushObject<InventoryGUI>(L, result, InventoryGUIBinding::getMetatableName());
}

int ForgottenGUIBinding::showInventoryNPC(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    hand* owner = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!owner) return luaL_error(L, "Argument 2 to showInventoryNPC must be hand");
    InventoryGUI* result = instance->showInventoryNPC(*owner);
    return pushObject<InventoryGUI>(L, result, InventoryGUIBinding::getMetatableName());
}

int ForgottenGUIBinding::closeInventory(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    hand* owner = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!owner) return luaL_error(L, "Argument 2 to closeInventory must be hand");
    instance->closeInventory(*owner);
    return 0;
}

int ForgottenGUIBinding::getInventoryWindow(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    hand* who = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!who) return luaL_error(L, "Argument 2 to getInventoryWindow must be hand");
    InventoryGUI* result = instance->getInventoryWindow(*who);
    return pushObject<InventoryGUI>(L, result, InventoryGUIBinding::getMetatableName());
}

int ForgottenGUIBinding::hasInventoryWindowOpen(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    hand* obj = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!obj) return luaL_error(L, "Argument 2 to hasInventoryWindowOpen must be hand");
    bool result = instance->hasInventoryWindowOpen(*obj);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ForgottenGUIBinding::toggleInventoryWindowPermanent(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    hand* owner = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!owner) return luaL_error(L, "Argument 2 to toggleInventoryWindowPermanent must be hand");
    instance->toggleInventoryWindowPermanent(*owner);
    return 0;
}

int ForgottenGUIBinding::getSelectedObject(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    return HandBinding::push(L, instance->getSelectedObject());
}

int ForgottenGUIBinding::getSelectedPlayerCharacter(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    return HandBinding::push(L, instance->getSelectedPlayerCharacter());
}

int ForgottenGUIBinding::showTradeWindow(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    hand* a = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    hand* b = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    if (!a || !b) return luaL_error(L, "Arguments 2 and 3 to showTradeWindow must be hand");
    TradeWindowType type = (TradeWindowType)luaL_checkinteger(L, 4);
    instance->showTradeWindow(*a, *b, type);
    return 0;
}

int ForgottenGUIBinding::changeFontSize(lua_State* L)
{
    ForgottenGUI::changeFontSize();
    return 0;
}

int ForgottenGUIBinding::destroy(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    if (testObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName()))
    {
        DatapanelGUI* dp = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
        instance->destroy(dp);
        return 0;
    }
    else if (testObject<GUIWindow>(L, 2, GUIWindowBinding::getMetatableName()))
    {
        GUIWindow* win = checkObject<GUIWindow>(L, 2, GUIWindowBinding::getMetatableName());
        instance->destroy(win);
        return 0;
    }
    else if (testObject<ScreenLabelInterface>(L, 2, ScreenLabelInterfaceBinding::getMetatableName()))
    {
        ScreenLabelInterface* label = checkObject<ScreenLabelInterface>(L, 2, ScreenLabelInterfaceBinding::getMetatableName());
        instance->destroy(label);
        return 0;
    }

    return luaL_error(L, "Invalid argument for ForgottenGUI:destroy");
}

int ForgottenGUIBinding::changeMouseCursor(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    CursorType cursor = (CursorType)luaL_checkinteger(L, 2);
    if (lua_gettop(L) >= 4)
    {
        hand* player = checkObject<hand>(L, 3, HandBinding::getMetatableName());
        hand* target = checkObject<hand>(L, 4, HandBinding::getMetatableName());
        if (!player || !target) return luaL_error(L, "Arguments 3 and 4 to changeMouseCursor must be hand");
        instance->changeMouseCursor(cursor, *player, *target);
        return 0;
    }
    else
    {
        instance->changeMouseCursor(cursor);
        return 0;
    }
}

int ForgottenGUIBinding::createInventoryWindow(lua_State* L)
{
    ForgottenGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ForgottenGUI is nil");

    hand* owner = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!owner) return luaL_error(L, "Argument 2 to createInventoryWindow must be hand");

    if (lua_gettop(L) >= 5)
    {
        Inventory* inventory = checkObject<Inventory>(L, 3, InventoryBinding::getMetatableName());
        InventoryLayout* layout = checkObject<InventoryLayout>(L, 4, InventoryLayoutBinding::getMetatableName());
        RootObject* trader = lua_isnoneornil(L, 5) ? nullptr : checkObject<RootObject>(L, 5, RootObjectBinding::getMetatableName());
        InventoryGUI* result = instance->createInventoryWindow(*owner, inventory, layout, trader);
        return pushObject<InventoryGUI>(L, result, InventoryGUIBinding::getMetatableName());
    }
    else
    {
        InventoryLayout* layout = checkObject<InventoryLayout>(L, 3, InventoryLayoutBinding::getMetatableName());
        InventoryGUI* result = instance->createInventoryWindow(*owner, layout);
        return pushObject<InventoryGUI>(L, result, InventoryGUIBinding::getMetatableName());
    }
}

/*
Skipped methods needing manual binding:
  line 68: DatapanelGUI* createDatapanel(...) - overloaded method
  line 69: DatapanelGUI* createDatapanel(...) - overloaded method
  line 70: MyGUI::Window* messageBox(...) - unsupported arg type
  line 82: void showCharacterEditor(...) - unsupported arg type
  line 107: InventoryGUI* toggleInventory(...) - non-string reference arg
  line 118: void addScreenLabel(...) - unsupported arg type
  line 121: void destroyWidget(...) - unsupported arg type
  line 122: void destroyWidgets(...) - overloaded method
  line 123: void destroyWidgets(...) - overloaded method
  line 124: bool widgetHasMouse(...) - unsupported arg type
  line 132: void setup(...) - unsupported arg type
  line 141: void _showTradeWindow(...) - unsupported arg type
  line 142: void setInventoryPosition(...) - non-string reference arg
  line 145: void inventoriesSelectedObjectUpdate(...) - non-string reference arg
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
LIGHTUSERDATA DEPENDENCIES:
  - ForgottenGUI_get_manager: MyGUI::Gui* (unbound pointer)
  - ForgottenGUI_get_guiPlatform: MyGUI::OgrePlatform* (unbound pointer)
  - ForgottenGUIBinding::getGuiManager: MyGUI::Gui* (unbound pointer)
  - ForgottenGUIBinding::createPanel: MyGUI::Window* (unbound pointer)
  - ForgottenGUIBinding::createPanelAbs: MyGUI::Window* (unbound pointer)
  - ForgottenGUIBinding::createTabPanel: MyGUI::TabControl* (unbound pointer)
  - ForgottenGUIBinding::createFloatingImage: MyGUI::Window* (unbound pointer)
  - ForgottenGUIBinding::createFloatingImageAbs: MyGUI::Window* (unbound pointer)
  - ForgottenGUIBinding::createScreenLabelD: ScreenLabelDebug* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 146: _showTradeWindowMsg (TradeWindowType) - unsupported type
  line 150: inventoryWindowsOpen (ogre_unordered_map<hand, InventoryGUI*>::type) - unsupported type
  line 155: inventoryWindowsPermanent (ogre_unordered_set<hand>::type) - unsupported type
  line 156: inventoryWindowsKillList (Ogre::vector<InventoryGUI*>::type) - unsupported type
  line 158: characterStatsWindows (Ogre::vector<CharacterStatsWindow*>::type) - unsupported type
  line 159: characterStatsWindowsKillList (Ogre::vector<CharacterStatsWindow*>::type) - unsupported type
  line 160: guiWindows (lektor<GUIWindow*>) - unsupported type
  line 161: guiDatapanels (lektor<DatapanelGUI*>) - unsupported type
  line 163: guiScreenLabels (lektor<ScreenLabelInterface*>) - unsupported type
  line 164: guiScreenLabelsToAdd (lektor<ScreenLabelInterface*>) - unsupported type
  line 165: guiScreenLabelsToRemove (lektor<ScreenLabelInterface*>) - unsupported type
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
    ForgottenInventoryWindowsOpenMapBinding::registerBinding(L, "ogre_unordered_map<hand, InventoryGUI*>", HandBinding::getMetatableName(), InventoryGUIBinding::getMetatableName());
    ForgottenInventoryWindowsPermanentSetBinding::registerBinding(L, "ogre_unordered_set<hand>", HandBinding::getMetatableName());

    static const luaL_Reg meta[] = {
        { "__gc",       ForgottenGUIBinding::gc },
        { "__tostring", ForgottenGUIBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
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
        { "notifyTownDeleted", ForgottenGUIBinding::notifyTownDeleted },
        { "update", ForgottenGUIBinding::update },
        { "closeTradeWindow", ForgottenGUIBinding::closeTradeWindow },
        { "closeInventoryBuilding", ForgottenGUIBinding::closeInventoryBuilding },
        { "closeAllInventories", ForgottenGUIBinding::closeAllInventories },
        { "closeAllWindows", ForgottenGUIBinding::closeAllWindows },
        { "getNumOpenInventoryWindows", ForgottenGUIBinding::getNumOpenInventoryWindows },
        { "getInventoryWindowWithMouse", ForgottenGUIBinding::getInventoryWindowWithMouse },
        { "isAnyInventoryWindowOpen", ForgottenGUIBinding::isAnyInventoryWindowOpen },
        { "toggleHelpWindow", ForgottenGUIBinding::toggleHelpWindow },
        { "addWindowToUpdateList", ForgottenGUIBinding::addWindowToUpdateList },
        { "removeWindowFromUpdateList", ForgottenGUIBinding::removeWindowFromUpdateList },
        { "addDatapanelToUpdateList", ForgottenGUIBinding::addDatapanelToUpdateList },
        { "removeDatapanelFromUpdateList", ForgottenGUIBinding::removeDatapanelFromUpdateList },
        { "setMouseCursorVisible", ForgottenGUIBinding::setMouseCursorVisible },
        { "getGuiManager", ForgottenGUIBinding::getGuiManager },
        { "createPanel", ForgottenGUIBinding::createPanel },
        { "createPanelAbs", ForgottenGUIBinding::createPanelAbs },
        { "createTabPanel", ForgottenGUIBinding::createTabPanel },
        { "createFloatingImage", ForgottenGUIBinding::createFloatingImage },
        { "createFloatingImageAbs", ForgottenGUIBinding::createFloatingImageAbs },
        { "createFloatingProgressBar", ForgottenGUIBinding::createFloatingProgressBar },
        { "createScreenLabelD", ForgottenGUIBinding::createScreenLabelD },
        { "showCharacterStatsWindow", ForgottenGUIBinding::showCharacterStatsWindow },
        { "closeCharacterStatsWindow", ForgottenGUIBinding::closeCharacterStatsWindow },
        { "toggleStatsWindow", ForgottenGUIBinding::toggleStatsWindow },
        { "toggleCharacterStatsWindowPermanent", ForgottenGUIBinding::toggleCharacterStatsWindowPermanent },
        { "showInventory", ForgottenGUIBinding::showInventory },
        { "showTraderInventory", ForgottenGUIBinding::showTraderInventory },
        { "showInventoryBuilding", ForgottenGUIBinding::showInventoryBuilding },
        { "showInventoryNPC", ForgottenGUIBinding::showInventoryNPC },
        { "closeInventory", ForgottenGUIBinding::closeInventory },
        { "getInventoryWindow", ForgottenGUIBinding::getInventoryWindow },
        { "hasInventoryWindowOpen", ForgottenGUIBinding::hasInventoryWindowOpen },
        { "toggleInventoryWindowPermanent", ForgottenGUIBinding::toggleInventoryWindowPermanent },
        { "getSelectedObject", ForgottenGUIBinding::getSelectedObject },
        { "getSelectedPlayerCharacter", ForgottenGUIBinding::getSelectedPlayerCharacter },
        { "showTradeWindow", ForgottenGUIBinding::showTradeWindow },
        { "changeFontSize", ForgottenGUIBinding::changeFontSize },
        { "destroy", ForgottenGUIBinding::destroy },
        { "changeMouseCursor", ForgottenGUIBinding::changeMouseCursor },
        { "createInventoryWindow", ForgottenGUIBinding::createInventoryWindow },
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
    registerGetter(L, "hasMouse", ForgottenGUI_get_hasMouse);
    registerGetter(L, "mainbar", ForgottenGUI_get_mainbar);
    registerGetter(L, "tooltip", ForgottenGUI_get_tooltip);
    registerGetter(L, "dialogue", ForgottenGUI_get_dialogue);
    registerGetter(L, "tutorial", ForgottenGUI_get_tutorial);
    registerGetter(L, "tutorialpedia", ForgottenGUI_get_tutorialpedia);
    registerGetter(L, "currentCursor", ForgottenGUI_get_currentCursor);
    registerGetter(L, "Scale", ForgottenGUI_get_Scale);
    registerGetter(L, "manager", ForgottenGUI_get_manager);
    registerGetter(L, "guiPlatform", ForgottenGUI_get_guiPlatform);
    registerGetter(L, "_closeTradeWindowMsg", ForgottenGUI_get__closeTradeWindowMsg);
    registerGetter(L, "tradeA", ForgottenGUI_get_tradeA);
    registerGetter(L, "tradeB", ForgottenGUI_get_tradeB);
    registerGetter(L, "inventoryWindowsOpen", ForgottenGUI_get_inventoryWindowsOpen);
    registerGetter(L, "inventoryWindowBuilding", ForgottenGUI_get_inventoryWindowBuilding);
    registerGetter(L, "inventoryWindowCharacter", ForgottenGUI_get_inventoryWindowCharacter);
    registerGetter(L, "inventoryWindowTrader", ForgottenGUI_get_inventoryWindowTrader);
    registerGetter(L, "inventoryWindowNPC", ForgottenGUI_get_inventoryWindowNPC);
    registerGetter(L, "inventoryWindowsPermanent", ForgottenGUI_get_inventoryWindowsPermanent);
    registerGetter(L, "guiWindows", ForgottenGUI_get_guiWindows);
    registerGetter(L, "guiDatapanels", ForgottenGUI_get_guiDatapanels);
    registerGetter(L, "guiScreenLabels", ForgottenGUI_get_guiScreenLabels);
    registerGetter(L, "characterEditor", ForgottenGUI_get_characterEditor);
    registerGetter(L, "guiScreenLabelsMutex", ForgottenGUI_get_guiScreenLabelsMutex);
    registerGetter(L, "selectedObject", ForgottenGUI_get_selectedObject);
    registerGetter(L, "selectedPlayerCharacter", ForgottenGUI_get_selectedPlayerCharacter);
    registerGetter(L, "cursorPanel", ForgottenGUI_get_cursorPanel);
    registerGetter(L, "cursorAction", ForgottenGUI_get_cursorAction);
    registerGetter(L, "cursorActionPlayer", ForgottenGUI_get_cursorActionPlayer);
    registerGetter(L, "cursorActionTarget", ForgottenGUI_get_cursorActionTarget);
    registerGetter(L, "visible", ForgottenGUI_get_visible);
    registerGetter(L, "created", ForgottenGUI_get_created);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "hasMouse", ForgottenGUI_set_hasMouse);
    registerSetter(L, "mainbar", ForgottenGUI_set_mainbar);
    registerSetter(L, "tooltip", ForgottenGUI_set_tooltip);
    registerSetter(L, "dialogue", ForgottenGUI_set_dialogue);
    registerSetter(L, "tutorial", ForgottenGUI_set_tutorial);
    registerSetter(L, "tutorialpedia", ForgottenGUI_set_tutorialpedia);
    registerSetter(L, "currentCursor", ForgottenGUI_set_currentCursor);
    registerSetter(L, "Scale", ForgottenGUI_set_Scale);
    registerSetter(L, "_closeTradeWindowMsg", ForgottenGUI_set__closeTradeWindowMsg);
    registerSetter(L, "tradeA", ForgottenGUI_set_tradeA);
    registerSetter(L, "tradeB", ForgottenGUI_set_tradeB);
    registerSetter(L, "inventoryWindowsOpen", ForgottenGUI_set_inventoryWindowsOpen);
    registerSetter(L, "inventoryWindowBuilding", ForgottenGUI_set_inventoryWindowBuilding);
    registerSetter(L, "inventoryWindowCharacter", ForgottenGUI_set_inventoryWindowCharacter);
    registerSetter(L, "inventoryWindowTrader", ForgottenGUI_set_inventoryWindowTrader);
    registerSetter(L, "inventoryWindowNPC", ForgottenGUI_set_inventoryWindowNPC);
    registerSetter(L, "inventoryWindowsPermanent", ForgottenGUI_set_inventoryWindowsPermanent);
    registerSetter(L, "guiWindows", ForgottenGUI_set_guiWindows);
    registerSetter(L, "guiDatapanels", ForgottenGUI_set_guiDatapanels);
    registerSetter(L, "guiScreenLabels", ForgottenGUI_set_guiScreenLabels);
    registerSetter(L, "characterEditor", ForgottenGUI_set_characterEditor);
    registerSetter(L, "guiScreenLabelsMutex", ForgottenGUI_set_guiScreenLabelsMutex);
    registerSetter(L, "selectedObject", ForgottenGUI_set_selectedObject);
    registerSetter(L, "selectedPlayerCharacter", ForgottenGUI_set_selectedPlayerCharacter);
    registerSetter(L, "cursorPanel", ForgottenGUI_set_cursorPanel);
    registerSetter(L, "cursorAction", ForgottenGUI_set_cursorAction);
    registerSetter(L, "cursorActionPlayer", ForgottenGUI_set_cursorActionPlayer);
    registerSetter(L, "cursorActionTarget", ForgottenGUI_set_cursorActionTarget);
    registerSetter(L, "visible", ForgottenGUI_set_visible);
    registerSetter(L, "created", ForgottenGUI_set_created);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, ForgottenGUIBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "changeFontSize", ForgottenGUIBinding::changeFontSize);
    lua_setglobal(L, "ForgottenGUI");
}

} // namespace KenshiLua
