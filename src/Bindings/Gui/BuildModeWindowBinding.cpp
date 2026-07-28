#include "pch.h"
#include "kenshi\gui\BuildModeWindow.h"
#include "BuildModeWindowBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Gui/BuildingGroupBinding.h"

namespace KenshiLua
{

static BuildModeWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<BuildModeWindow>(L, idx, BuildModeWindowBinding::getMetatableName());
}

// --- Getters for BuildModeWindow ---
static int BuildModeWindow_get_playerBuildMode(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->playerBuildMode);
    return 1;
}

static int BuildModeWindow_get_levelEditorMode(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushboolean(L, instance->levelEditorMode ? 1 : 0);
    return 1;
}

static int BuildModeWindow_get_playerResearch(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->playerResearch);
    return 1;
}

static int BuildModeWindow_get_currentBuildingCategory(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->currentBuildingCategory);
    return 1;
}

static int BuildModeWindow_get_currentBuildingGroup(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return pushObject<BuildModeWindow::BuildingGroup>(L, &instance->currentBuildingGroup, BuildingGroupBinding::getMetatableName());
}

static int BuildModeWindow_get_currentBuildingInfo(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return pushObject<GameData>(L, instance->currentBuildingInfo, GameDataBinding::getMetatableName());
}

static int BuildModeWindow_get_currentBuildingIndex(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushinteger(L, instance->currentBuildingIndex);
    return 1;
}

static int BuildModeWindow_get_switchBuildingIndex(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushinteger(L, instance->switchBuildingIndex);
    return 1;
}

static int BuildModeWindow_get_statsDataPanel(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->statsDataPanel, DatapanelGUIBinding::getMetatableName());
}

static int BuildModeWindow_get_confirmButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->confirmButton);
    return 1;
}

static int BuildModeWindow_get_undoButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->undoButton);
    return 1;
}

static int BuildModeWindow_get_closeButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->closeButton);
    return 1;
}

static int BuildModeWindow_get_categoriesList(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->categoriesList);
    return 1;
}

static int BuildModeWindow_get_buildingsList(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->buildingsList);
    return 1;
}

static int BuildModeWindow_get_buildingTxt(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->buildingTxt);
    return 1;
}

static int BuildModeWindow_get_buildingTypePrevButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->buildingTypePrevButton);
    return 1;
}

static int BuildModeWindow_get_buildingTypeNextButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->buildingTypeNextButton);
    return 1;
}

static int BuildModeWindow_get_buildingImageBox(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->buildingImageBox);
    return 1;
}

static int BuildModeWindow_get_statsPanel(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->statsPanel);
    return 1;
}

static int BuildModeWindow_get_descriptionTxt(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->descriptionTxt);
    return 1;
}

static int BuildModeWindow_get_messageTextBox(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->messageTextBox);
    return 1;
}

static int BuildModeWindow_get_floorDownButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->floorDownButton);
    return 1;
}

static int BuildModeWindow_get_floorUpButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->floorUpButton);
    return 1;
}

static int BuildModeWindow_get_floorText(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->floorText);
    return 1;
}

// --- Setters for BuildModeWindow ---
static int BuildModeWindow_set_levelEditorMode(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->levelEditorMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int BuildModeWindow_set_currentBuildingGroup(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    auto* val = checkObject<BuildModeWindow::BuildingGroup>(L, 2, BuildingGroupBinding::getMetatableName());
    if (!val) return luaL_error(L, "Argument 2 to set 'currentBuildingGroup' must be BuildingGroup");
    instance->currentBuildingGroup = *val;
    return 0;
}

static int BuildModeWindow_set_currentBuildingInfo(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->currentBuildingInfo = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_set_currentBuildingIndex(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->currentBuildingIndex = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int BuildModeWindow_set_switchBuildingIndex(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->switchBuildingIndex = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int BuildModeWindow_set_statsDataPanel(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->statsDataPanel = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

int BuildModeWindowBinding::_DESTRUCTOR(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int BuildModeWindowBinding::setMessage(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");

    const std::string message = luaL_checkstring(L, 2);
    instance->setMessage(message);
    return 0;
}

int BuildModeWindowBinding::getBuildingListWidget(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");

    MyGUI::Widget* result = instance->getBuildingListWidget();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int BuildModeWindowBinding::setVisible(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");

    bool v = lua_toboolean(L, 2) != 0;
    instance->setVisible(v);
    return 0;
}

int BuildModeWindowBinding::setupData(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");

    instance->setupData();
    return 0;
}

int BuildModeWindowBinding::listCategories(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");

    instance->listCategories();
    return 0;
}

int BuildModeWindowBinding::listBuildingGroups(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");

    instance->listBuildingGroups();
    return 0;
}

int BuildModeWindowBinding::updateBuildingUI(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");

    instance->updateBuildingUI();
    return 0;
}

int BuildModeWindowBinding::build(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");

    instance->build();
    return 0;
}

int BuildModeWindowBinding::showBuildingStats(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");

    instance->showBuildingStats();
    return 0;
}

int BuildModeWindowBinding::update(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");

    instance->update();
    return 0;
}

int BuildModeWindowBinding::changeCurrentIndex(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");

    int index = (int)luaL_checkinteger(L, 2);
    instance->changeCurrentIndex(index);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 52: BuildModeWindow* _CONSTRUCTOR(...) - unsupported arg type
  line 62: void categorySelected(...) - unsupported arg type
  line 63: void buildingSelected(...) - unsupported arg type
  line 65: void confirm(...) - unsupported arg type
  line 66: void undo(...) - unsupported arg type
  line 67: void close(...) - unsupported arg type
  line 68: void buildingTypePrev(...) - unsupported arg type
  line 69: void buildingTypeNext(...) - unsupported arg type
  line 72: bool compareBuildMaterials(...) - static method
  line 74: void changeFloorButtonUp(...) - unsupported arg type
  line 75: void changeFloorButtonDown(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 79: playerCategories (Ogre::vector<BuildModeWindow::BuildingCategory*>::type) - unsupported type
*/

int BuildModeWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BuildModeWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BuildModeWindow object");
    return 1;
}

void BuildModeWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildModeWindowBinding::gc },
        { "__tostring", BuildModeWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", BuildModeWindowBinding::_DESTRUCTOR },
        { "setMessage", BuildModeWindowBinding::setMessage },
        { "getBuildingListWidget", BuildModeWindowBinding::getBuildingListWidget },
        { "setVisible", BuildModeWindowBinding::setVisible },
        { "setupData", BuildModeWindowBinding::setupData },
        { "listCategories", BuildModeWindowBinding::listCategories },
        { "listBuildingGroups", BuildModeWindowBinding::listBuildingGroups },
        { "updateBuildingUI", BuildModeWindowBinding::updateBuildingUI },
        { "build", BuildModeWindowBinding::build },
        { "showBuildingStats", BuildModeWindowBinding::showBuildingStats },
        { "update", BuildModeWindowBinding::update },
        { "changeCurrentIndex", BuildModeWindowBinding::changeCurrentIndex },
        { 0, 0 }
    };

    registerClass(
        L, 
        BuildModeWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BuildModeWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "playerBuildMode", BuildModeWindow_get_playerBuildMode);
    registerGetter(L, "levelEditorMode", BuildModeWindow_get_levelEditorMode);
    registerGetter(L, "playerResearch", BuildModeWindow_get_playerResearch);
    registerGetter(L, "currentBuildingCategory", BuildModeWindow_get_currentBuildingCategory);
    registerGetter(L, "currentBuildingGroup", BuildModeWindow_get_currentBuildingGroup);
    registerGetter(L, "currentBuildingInfo", BuildModeWindow_get_currentBuildingInfo);
    registerGetter(L, "currentBuildingIndex", BuildModeWindow_get_currentBuildingIndex);
    registerGetter(L, "switchBuildingIndex", BuildModeWindow_get_switchBuildingIndex);
    registerGetter(L, "statsDataPanel", BuildModeWindow_get_statsDataPanel);
    registerGetter(L, "confirmButton", BuildModeWindow_get_confirmButton);
    registerGetter(L, "undoButton", BuildModeWindow_get_undoButton);
    registerGetter(L, "closeButton", BuildModeWindow_get_closeButton);
    registerGetter(L, "categoriesList", BuildModeWindow_get_categoriesList);
    registerGetter(L, "buildingsList", BuildModeWindow_get_buildingsList);
    registerGetter(L, "buildingTxt", BuildModeWindow_get_buildingTxt);
    registerGetter(L, "buildingTypePrevButton", BuildModeWindow_get_buildingTypePrevButton);
    registerGetter(L, "buildingTypeNextButton", BuildModeWindow_get_buildingTypeNextButton);
    registerGetter(L, "buildingImageBox", BuildModeWindow_get_buildingImageBox);
    registerGetter(L, "statsPanel", BuildModeWindow_get_statsPanel);
    registerGetter(L, "descriptionTxt", BuildModeWindow_get_descriptionTxt);
    registerGetter(L, "messageTextBox", BuildModeWindow_get_messageTextBox);
    registerGetter(L, "floorDownButton", BuildModeWindow_get_floorDownButton);
    registerGetter(L, "floorUpButton", BuildModeWindow_get_floorUpButton);
    registerGetter(L, "floorText", BuildModeWindow_get_floorText);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "levelEditorMode", BuildModeWindow_set_levelEditorMode);
    registerSetter(L, "currentBuildingGroup", BuildModeWindow_set_currentBuildingGroup);
    registerSetter(L, "currentBuildingInfo", BuildModeWindow_set_currentBuildingInfo);
    registerSetter(L, "currentBuildingIndex", BuildModeWindow_set_currentBuildingIndex);
    registerSetter(L, "switchBuildingIndex", BuildModeWindow_set_switchBuildingIndex);
    registerSetter(L, "statsDataPanel", BuildModeWindow_set_statsDataPanel);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, BuildModeWindowBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua