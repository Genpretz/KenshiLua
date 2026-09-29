#include "pch.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Bindings/MyGUI/ButtonBinding.h"
#include "Bindings/MyGUI/WindowBinding.h"
#include "Bindings/MyGUI/TextBoxBinding.h"
#include "Bindings/MyGUI/ListBoxBinding.h"
#include "Bindings/MyGUI/EditBoxBinding.h"

#include "kenshi\gui\InteriorModeButtonWindow.h"
#include "InteriorModeButtonWindowBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Building/BuildingBinding.h"
#include "Bindings/Kenshi/Gui/GameDataEditorWindowBinding.h"

namespace KenshiLua
{

static InteriorModeButtonWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<InteriorModeButtonWindow>(L, idx, InteriorModeButtonWindowBinding::getMetatableName());
}

// --- Getters for InteriorModeButtonWindow ---
static int InteriorModeButtonWindow_get_exteriorsInvisible(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushboolean(L, instance->exteriorsInvisible ? 1 : 0);
    return 1;
}

static int InteriorModeButtonWindow_get_interiorMode(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushboolean(L, instance->interiorMode ? 1 : 0);
    return 1;
}

static int InteriorModeButtonWindow_get_dataEditWindow(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return pushObject<GameDataEditorWindow>(L, instance->dataEditWindow, GameDataEditorWindowBinding::getMetatableName());
}

static int InteriorModeButtonWindow_get_currentBuilding(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return HandBinding::push(L, instance->currentBuilding);
}

static int InteriorModeButtonWindow_get_currentInterior(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushstring(L, instance->currentInterior.c_str());
    return 1;
}

static int InteriorModeButtonWindow_get_currentExterior(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushstring(L, instance->currentExterior.c_str());
    return 1;
}

static int InteriorModeButtonWindow_get_interiorModeButton(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->interiorModeButton);
}

static int InteriorModeButtonWindow_set_interiorModeButton(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->interiorModeButton = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Button>(L, 2, ButtonBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_get_win(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->win);
}

static int InteriorModeButtonWindow_set_win(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->win = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Window>(L, 2, WindowBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_get_centerButton(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->centerButton);
}

static int InteriorModeButtonWindow_set_centerButton(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->centerButton = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Button>(L, 2, ButtonBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_get_exteriorButton(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->exteriorButton);
}

static int InteriorModeButtonWindow_set_exteriorButton(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->exteriorButton = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Button>(L, 2, ButtonBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_get_titleLabel(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->titleLabel);
}

static int InteriorModeButtonWindow_set_titleLabel(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->titleLabel = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, TextBoxBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_get_saveBut(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->saveBut);
}

static int InteriorModeButtonWindow_set_saveBut(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->saveBut = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Button>(L, 2, ButtonBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_get_deleteBut(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->deleteBut);
}

static int InteriorModeButtonWindow_set_deleteBut(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->deleteBut = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Button>(L, 2, ButtonBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_get_listbox(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->listbox);
}

static int InteriorModeButtonWindow_set_listbox(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->listbox = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ListBox>(L, 2, ListBoxBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_get_namebox(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->namebox);
}

static int InteriorModeButtonWindow_set_namebox(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->namebox = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::EditBox>(L, 2, EditBoxBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_get_saveBut2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->saveBut2);
}

static int InteriorModeButtonWindow_set_saveBut2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->saveBut2 = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Button>(L, 2, ButtonBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_get_deleteBut2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->deleteBut2);
}

static int InteriorModeButtonWindow_set_deleteBut2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->deleteBut2 = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Button>(L, 2, ButtonBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_get_listbox2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->listbox2);
}

static int InteriorModeButtonWindow_set_listbox2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->listbox2 = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ListBox>(L, 2, ListBoxBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_get_namebox2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->namebox2);
}

static int InteriorModeButtonWindow_set_namebox2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->namebox2 = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::EditBox>(L, 2, EditBoxBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_get_updateNodesMessages(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    return LektorValueBinding<hand>::push(L, &instance->updateNodesMessages);
}

static int InteriorModeButtonWindow_set_updateNodesMessages(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lektor<hand>* val = checkObject<lektor<hand>>(L, 2, LektorValueBinding<hand>::metaName);
    if (!val) return luaL_error(L, "Argument 2 must be lektor<hand>");
    instance->updateNodesMessages = *val;
    return 0;
}

// --- Setters for InteriorModeButtonWindow ---
static int InteriorModeButtonWindow_set_exteriorsInvisible(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->exteriorsInvisible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InteriorModeButtonWindow_set_interiorMode(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->interiorMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InteriorModeButtonWindow_set_dataEditWindow(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->dataEditWindow = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameDataEditorWindow>(L, 2, GameDataEditorWindowBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_set_currentBuilding(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->currentBuilding = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int InteriorModeButtonWindow_set_currentInterior(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->currentInterior = luaL_checkstring(L, 2);
    return 0;
}

static int InteriorModeButtonWindow_set_currentExterior(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    instance->currentExterior = luaL_checkstring(L, 2);
    return 0;
}

int InteriorModeButtonWindowBinding::toggleInteriorMode(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    instance->toggleInteriorMode();
    return 0;
}

int InteriorModeButtonWindowBinding::setVisible(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    bool v = lua_toboolean(L, 2) != 0;
    instance->setVisible(v);
    return 0;
}

int InteriorModeButtonWindowBinding::wantExteriorsInvisible(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    bool result = instance->wantExteriorsInvisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InteriorModeButtonWindowBinding::setSelectedBuilding(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    Building* b = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    instance->setSelectedBuilding(b);
    return 0;
}

int InteriorModeButtonWindowBinding::getSelectedBuilding(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    Building* result = instance->getSelectedBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int InteriorModeButtonWindowBinding::updateUsageNodes(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    bool result = instance->updateUsageNodes();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InteriorModeButtonWindowBinding::refresh(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    instance->refresh();
    return 0;
}

int InteriorModeButtonWindowBinding::activateInteriorMode(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->activateInteriorMode(on);
    return 0;
}

int InteriorModeButtonWindowBinding::confirmDeleteInteriorLayout(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    int c = (int)luaL_checkinteger(L, 2);
    instance->confirmDeleteInteriorLayout(c);
    return 0;
}

int InteriorModeButtonWindowBinding::confirmDeleteExteriorLayout(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    int c = (int)luaL_checkinteger(L, 2);
    instance->confirmDeleteExteriorLayout(c);
    return 0;
}

int InteriorModeButtonWindowBinding::setInteriorLayout(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    const std::string name = luaL_checkstring(L, 2);
    instance->setInteriorLayout(name);
    return 0;
}

int InteriorModeButtonWindowBinding::setExteriorLayout(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    const std::string name = luaL_checkstring(L, 2);
    instance->setExteriorLayout(name);
    return 0;
}

int InteriorModeButtonWindowBinding::recheckOutsideFurniture(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    instance->recheckOutsideFurniture(building);
    return 0;
}

int InteriorModeButtonWindowBinding::wasTheInteriorLoadedFromASave(lua_State* L)
{
    int idx = (testObject<InteriorModeButtonWindow>(L, 1, InteriorModeButtonWindowBinding::getMetatableName()) != nullptr) ? 2 : 1;
    BuildingInterior* interior = (BuildingInterior*)lua_touserdata(L, idx);
    if (!interior) return luaL_error(L, "Argument %d to wasTheInteriorLoadedFromASave must be a BuildingInterior pointer", idx);

    bool result = InteriorModeButtonWindow::wasTheInteriorLoadedFromASave(interior);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InteriorModeButtonWindowBinding::closeWindow(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::Window* sender = checkObject<MyGUI::Window>(L, 2, WindowBinding::getMetatableName());
    const std::string name = luaL_checkstring(L, 3);
    instance->closeWindow(sender, name);
    return 0;
}

int InteriorModeButtonWindowBinding::toggleVisButtonPressed(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->toggleVisButtonPressed(sender);
    return 0;
}

int InteriorModeButtonWindowBinding::interiorModePressed(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->interiorModePressed(sender);
    return 0;
}

int InteriorModeButtonWindowBinding::interiorModeButtonUpdate(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    MyGUI::MouseButton a4 = MyGUI::MouseButton::Enum((int)luaL_checkinteger(L, 5));
    instance->interiorModeButtonUpdate(sender, a2, a3, a4);
    return 0;
}

int InteriorModeButtonWindowBinding::interiorModeButtonUpdate2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    MyGUI::Widget* sender2 = checkObject<MyGUI::Widget>(L, 3, MyGUIBinding::getMetatableName());
    instance->interiorModeButtonUpdate2(sender, sender2);
    return 0;
}

int InteriorModeButtonWindowBinding::notifyEditTextChange(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::EditBox* sender = checkObject<MyGUI::EditBox>(L, 2, EditBoxBinding::getMetatableName());
    instance->notifyEditTextChange(sender);
    return 0;
}

int InteriorModeButtonWindowBinding::centerButtonPressed(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->centerButtonPressed(sender);
    return 0;
}

int InteriorModeButtonWindowBinding::saveButtonPressed(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->saveButtonPressed(sender);
    return 0;
}

int InteriorModeButtonWindowBinding::deleteButtonPressed(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->deleteButtonPressed(sender);
    return 0;
}

int InteriorModeButtonWindowBinding::clearNodes(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->clearNodes(sender);
    return 0;
}

int InteriorModeButtonWindowBinding::clearAll(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->clearAll(sender);
    return 0;
}

int InteriorModeButtonWindowBinding::listItemSelected(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::ListBox* sender = checkObject<MyGUI::ListBox>(L, 2, ListBoxBinding::getMetatableName());
    unsigned __int64 index = (unsigned __int64)luaL_checkinteger(L, 3);
    instance->listItemSelected(sender, index);
    return 0;
}

int InteriorModeButtonWindowBinding::saveButtonPressed2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->saveButtonPressed2(sender);
    return 0;
}

int InteriorModeButtonWindowBinding::deleteButtonPressed2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->deleteButtonPressed2(sender);
    return 0;
}

int InteriorModeButtonWindowBinding::listItemSelected2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::ListBox* sender = checkObject<MyGUI::ListBox>(L, 2, ListBoxBinding::getMetatableName());
    unsigned __int64 index = (unsigned __int64)luaL_checkinteger(L, 3);
    instance->listItemSelected2(sender, index);
    return 0;
}

int InteriorModeButtonWindowBinding::notifyEditTextChange2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    MyGUI::EditBox* sender = checkObject<MyGUI::EditBox>(L, 2, EditBoxBinding::getMetatableName());
    instance->notifyEditTextChange2(sender);
    return 0;
}

int InteriorModeButtonWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int InteriorModeButtonWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.InteriorModeButtonWindow object");
    return 1;
}

void InteriorModeButtonWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       InteriorModeButtonWindowBinding::gc },
        { "__tostring", InteriorModeButtonWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "toggleInteriorMode", InteriorModeButtonWindowBinding::toggleInteriorMode },
        { "setVisible", InteriorModeButtonWindowBinding::setVisible },
        { "wantExteriorsInvisible", InteriorModeButtonWindowBinding::wantExteriorsInvisible },
        { "setSelectedBuilding", InteriorModeButtonWindowBinding::setSelectedBuilding },
        { "getSelectedBuilding", InteriorModeButtonWindowBinding::getSelectedBuilding },
        { "updateUsageNodes", InteriorModeButtonWindowBinding::updateUsageNodes },
        { "refresh", InteriorModeButtonWindowBinding::refresh },
        { "activateInteriorMode", InteriorModeButtonWindowBinding::activateInteriorMode },
        { "confirmDeleteInteriorLayout", InteriorModeButtonWindowBinding::confirmDeleteInteriorLayout },
        { "confirmDeleteExteriorLayout", InteriorModeButtonWindowBinding::confirmDeleteExteriorLayout },
        { "setInteriorLayout", InteriorModeButtonWindowBinding::setInteriorLayout },
        { "setExteriorLayout", InteriorModeButtonWindowBinding::setExteriorLayout },
        { "recheckOutsideFurniture", InteriorModeButtonWindowBinding::recheckOutsideFurniture },
        { "wasTheInteriorLoadedFromASave", InteriorModeButtonWindowBinding::wasTheInteriorLoadedFromASave },
        { "interiorModePressed", InteriorModeButtonWindowBinding::interiorModePressed },
        { "interiorModeButtonUpdate", InteriorModeButtonWindowBinding::interiorModeButtonUpdate },
        { "interiorModeButtonUpdate2", InteriorModeButtonWindowBinding::interiorModeButtonUpdate2 },
        { "deleteButtonPressed", InteriorModeButtonWindowBinding::deleteButtonPressed },
        { "deleteButtonPressed2", InteriorModeButtonWindowBinding::deleteButtonPressed2 },
        { "closeWindow", InteriorModeButtonWindowBinding::closeWindow },
        { "toggleVisButtonPressed", InteriorModeButtonWindowBinding::toggleVisButtonPressed },
        { "notifyEditTextChange", InteriorModeButtonWindowBinding::notifyEditTextChange },
        { "centerButtonPressed", InteriorModeButtonWindowBinding::centerButtonPressed },
        { "saveButtonPressed", InteriorModeButtonWindowBinding::saveButtonPressed },
        { "clearNodes", InteriorModeButtonWindowBinding::clearNodes },
        { "clearAll", InteriorModeButtonWindowBinding::clearAll },
        { "listItemSelected", InteriorModeButtonWindowBinding::listItemSelected },
        { "saveButtonPressed2", InteriorModeButtonWindowBinding::saveButtonPressed2 },
        { "listItemSelected2", InteriorModeButtonWindowBinding::listItemSelected2 },
        { "notifyEditTextChange2", InteriorModeButtonWindowBinding::notifyEditTextChange2 },
        { 0, 0 }
    };

    registerClass(
        L, 
        InteriorModeButtonWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, InteriorModeButtonWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "exteriorsInvisible", InteriorModeButtonWindow_get_exteriorsInvisible);
    registerGetter(L, "interiorMode", InteriorModeButtonWindow_get_interiorMode);
    registerGetter(L, "dataEditWindow", InteriorModeButtonWindow_get_dataEditWindow);
    registerGetter(L, "currentBuilding", InteriorModeButtonWindow_get_currentBuilding);
    registerGetter(L, "currentInterior", InteriorModeButtonWindow_get_currentInterior);
    registerGetter(L, "currentExterior", InteriorModeButtonWindow_get_currentExterior);
    registerGetter(L, "interiorModeButton", InteriorModeButtonWindow_get_interiorModeButton);
    registerGetter(L, "win", InteriorModeButtonWindow_get_win);
    registerGetter(L, "centerButton", InteriorModeButtonWindow_get_centerButton);
    registerGetter(L, "exteriorButton", InteriorModeButtonWindow_get_exteriorButton);
    registerGetter(L, "titleLabel", InteriorModeButtonWindow_get_titleLabel);
    registerGetter(L, "saveBut", InteriorModeButtonWindow_get_saveBut);
    registerGetter(L, "deleteBut", InteriorModeButtonWindow_get_deleteBut);
    registerGetter(L, "listbox", InteriorModeButtonWindow_get_listbox);
    registerGetter(L, "namebox", InteriorModeButtonWindow_get_namebox);
    registerGetter(L, "saveBut2", InteriorModeButtonWindow_get_saveBut2);
    registerGetter(L, "deleteBut2", InteriorModeButtonWindow_get_deleteBut2);
    registerGetter(L, "listbox2", InteriorModeButtonWindow_get_listbox2);
    registerGetter(L, "namebox2", InteriorModeButtonWindow_get_namebox2);
    registerGetter(L, "updateNodesMessages", InteriorModeButtonWindow_get_updateNodesMessages);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "exteriorsInvisible", InteriorModeButtonWindow_set_exteriorsInvisible);
    registerSetter(L, "interiorMode", InteriorModeButtonWindow_set_interiorMode);
    registerSetter(L, "dataEditWindow", InteriorModeButtonWindow_set_dataEditWindow);
    registerSetter(L, "currentBuilding", InteriorModeButtonWindow_set_currentBuilding);
    registerSetter(L, "currentInterior", InteriorModeButtonWindow_set_currentInterior);
    registerSetter(L, "currentExterior", InteriorModeButtonWindow_set_currentExterior);
    registerSetter(L, "interiorModeButton", InteriorModeButtonWindow_set_interiorModeButton);
    registerSetter(L, "win", InteriorModeButtonWindow_set_win);
    registerSetter(L, "centerButton", InteriorModeButtonWindow_set_centerButton);
    registerSetter(L, "exteriorButton", InteriorModeButtonWindow_set_exteriorButton);
    registerSetter(L, "titleLabel", InteriorModeButtonWindow_set_titleLabel);
    registerSetter(L, "saveBut", InteriorModeButtonWindow_set_saveBut);
    registerSetter(L, "deleteBut", InteriorModeButtonWindow_set_deleteBut);
    registerSetter(L, "listbox", InteriorModeButtonWindow_set_listbox);
    registerSetter(L, "namebox", InteriorModeButtonWindow_set_namebox);
    registerSetter(L, "saveBut2", InteriorModeButtonWindow_set_saveBut2);
    registerSetter(L, "deleteBut2", InteriorModeButtonWindow_set_deleteBut2);
    registerSetter(L, "listbox2", InteriorModeButtonWindow_set_listbox2);
    registerSetter(L, "namebox2", InteriorModeButtonWindow_set_namebox2);
    registerSetter(L, "updateNodesMessages", InteriorModeButtonWindow_set_updateNodesMessages);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, InteriorModeButtonWindowBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    pushGlobalTable(L, "InteriorModeButtonWindow");
    registerStaticMethod(L, "wasTheInteriorLoadedFromASave", InteriorModeButtonWindowBinding::wasTheInteriorLoadedFromASave);
    lua_setglobal(L, "InteriorModeButtonWindow");
}

} // namespace KenshiLua