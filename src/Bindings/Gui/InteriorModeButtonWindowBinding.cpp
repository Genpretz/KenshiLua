#include "pch.h"
#include "kenshi\gui\InteriorModeButtonWindow.h"
#include "InteriorModeButtonWindowBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Gui/GameDataEditorWindowBinding.h"

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
    return handBinding::push(L, instance->currentBuilding);
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
    lua_pushlightuserdata(L, (void*)instance->interiorModeButton);
    return 1;
}

static int InteriorModeButtonWindow_get_win(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->win);
    return 1;
}

static int InteriorModeButtonWindow_get_centerButton(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->centerButton);
    return 1;
}

static int InteriorModeButtonWindow_get_exteriorButton(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->exteriorButton);
    return 1;
}

static int InteriorModeButtonWindow_get_titleLabel(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->titleLabel);
    return 1;
}

static int InteriorModeButtonWindow_get_saveBut(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->saveBut);
    return 1;
}

static int InteriorModeButtonWindow_get_deleteBut(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->deleteBut);
    return 1;
}

static int InteriorModeButtonWindow_get_listbox(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->listbox);
    return 1;
}

static int InteriorModeButtonWindow_get_namebox(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->namebox);
    return 1;
}

static int InteriorModeButtonWindow_get_saveBut2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->saveBut2);
    return 1;
}

static int InteriorModeButtonWindow_get_deleteBut2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->deleteBut2);
    return 1;
}

static int InteriorModeButtonWindow_get_listbox2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->listbox2);
    return 1;
}

static int InteriorModeButtonWindow_get_namebox2(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->namebox2);
    return 1;
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
    instance->currentBuilding = *checkObject<hand>(L, 2, handBinding::getMetatableName());
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

int InteriorModeButtonWindowBinding::_CONSTRUCTOR(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    InteriorModeButtonWindow* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int InteriorModeButtonWindowBinding::_DESTRUCTOR(lua_State* L)
{
    InteriorModeButtonWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InteriorModeButtonWindow is nil");

    instance->_DESTRUCTOR();
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

/*
Skipped methods needing manual binding:
  line 50: void closeWindow(...) - unsupported arg type
  line 51: void toggleVisButtonPressed(...) - unsupported arg type
  line 52: void interiorModePressed(...) - unsupported arg type
  line 53: void interiorModeButtonUpdate(...) - unsupported arg type
  line 54: void interiorModeButtonUpdate2(...) - unsupported arg type
  line 55: void notifyEditTextChange(...) - unsupported arg type
  line 56: void centerButtonPressed(...) - unsupported arg type
  line 57: void saveButtonPressed(...) - unsupported arg type
  line 58: void deleteButtonPressed(...) - unsupported arg type
  line 59: void clearNodes(...) - unsupported arg type
  line 60: void clearAll(...) - unsupported arg type
  line 61: void listItemSelected(...) - unsupported arg type
  line 64: void saveButtonPressed2(...) - unsupported arg type
  line 65: void deleteButtonPressed2(...) - unsupported arg type
  line 66: void listItemSelected2(...) - unsupported arg type
  line 67: void notifyEditTextChange2(...) - unsupported arg type
  line 71: bool wasTheInteriorLoadedFromASave(...) - static method
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - InteriorModeButtonWindow_get_interiorModeButton: MyGUI::Button* (unbound pointer)
  - InteriorModeButtonWindow_get_win: MyGUI::Window* (unbound pointer)
  - InteriorModeButtonWindow_get_centerButton: MyGUI::Button* (unbound pointer)
  - InteriorModeButtonWindow_get_exteriorButton: MyGUI::Button* (unbound pointer)
  - InteriorModeButtonWindow_get_titleLabel: MyGUI::TextBox* (unbound pointer)
  - InteriorModeButtonWindow_get_saveBut: MyGUI::Button* (unbound pointer)
  - InteriorModeButtonWindow_get_deleteBut: MyGUI::Button* (unbound pointer)
  - InteriorModeButtonWindow_get_listbox: MyGUI::ListBox* (unbound pointer)
  - InteriorModeButtonWindow_get_namebox: MyGUI::EditBox* (unbound pointer)
  - InteriorModeButtonWindow_get_saveBut2: MyGUI::Button* (unbound pointer)
  - InteriorModeButtonWindow_get_deleteBut2: MyGUI::Button* (unbound pointer)
  - InteriorModeButtonWindow_get_listbox2: MyGUI::ListBox* (unbound pointer)
  - InteriorModeButtonWindow_get_namebox2: MyGUI::EditBox* (unbound pointer)
  - InteriorModeButtonWindowBinding::_CONSTRUCTOR: InteriorModeButtonWindow* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 35: updateNodesMessages (lektor<hand>) - unsupported type
*/

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
        { "_CONSTRUCTOR", InteriorModeButtonWindowBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", InteriorModeButtonWindowBinding::_DESTRUCTOR },
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
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "exteriorsInvisible", InteriorModeButtonWindow_set_exteriorsInvisible);
    registerSetter(L, "interiorMode", InteriorModeButtonWindow_set_interiorMode);
    registerSetter(L, "dataEditWindow", InteriorModeButtonWindow_set_dataEditWindow);
    registerSetter(L, "currentBuilding", InteriorModeButtonWindow_set_currentBuilding);
    registerSetter(L, "currentInterior", InteriorModeButtonWindow_set_currentInterior);
    registerSetter(L, "currentExterior", InteriorModeButtonWindow_set_currentExterior);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    setMetatableParent(L, InteriorModeButtonWindowBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua