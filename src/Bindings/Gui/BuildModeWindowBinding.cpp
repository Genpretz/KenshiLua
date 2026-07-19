#include "pch.h"
#include "Bindings/Gui/BuildingGroupBinding.h"

#include "Bindings/GameDataBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

#include <kenshi/gui/BuildModeWindow.h>
#include "BuildModeWindowBinding.h"
#include "GUIWindowBinding.h"
#include "Lua/BindingHelpers.h"

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
    return pushObject(L, &instance->currentBuildingGroup, BuildingGroupBinding::getMetatableName());
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
    BuildModeWindow::BuildingGroup* val = checkObject<BuildModeWindow::BuildingGroup>(L, 2, BuildingGroupBinding::getMetatableName());
    if (val) instance->currentBuildingGroup = *val;
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

    std::string message = luaL_checkstring(L, 2);
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
    lua_pushcfunction(L, BuildModeWindow_get_playerBuildMode);
    lua_setfield(L, -2, "playerBuildMode");
    lua_pushcfunction(L, BuildModeWindow_get_levelEditorMode);
    lua_setfield(L, -2, "levelEditorMode");
    lua_pushcfunction(L, BuildModeWindow_get_playerResearch);
    lua_setfield(L, -2, "playerResearch");
    lua_pushcfunction(L, BuildModeWindow_get_currentBuildingCategory);
    lua_setfield(L, -2, "currentBuildingCategory");
    lua_pushcfunction(L, BuildModeWindow_get_currentBuildingGroup);
    lua_setfield(L, -2, "currentBuildingGroup");
    lua_pushcfunction(L, BuildModeWindow_get_currentBuildingInfo);
    lua_setfield(L, -2, "currentBuildingInfo");
    lua_pushcfunction(L, BuildModeWindow_get_currentBuildingIndex);
    lua_setfield(L, -2, "currentBuildingIndex");
    lua_pushcfunction(L, BuildModeWindow_get_switchBuildingIndex);
    lua_setfield(L, -2, "switchBuildingIndex");
    lua_pushcfunction(L, BuildModeWindow_get_statsDataPanel);
    lua_setfield(L, -2, "statsDataPanel");
    lua_pushcfunction(L, BuildModeWindow_get_confirmButton);
    lua_setfield(L, -2, "confirmButton");
    lua_pushcfunction(L, BuildModeWindow_get_undoButton);
    lua_setfield(L, -2, "undoButton");
    lua_pushcfunction(L, BuildModeWindow_get_closeButton);
    lua_setfield(L, -2, "closeButton");
    lua_pushcfunction(L, BuildModeWindow_get_categoriesList);
    lua_setfield(L, -2, "categoriesList");
    lua_pushcfunction(L, BuildModeWindow_get_buildingsList);
    lua_setfield(L, -2, "buildingsList");
    lua_pushcfunction(L, BuildModeWindow_get_buildingTxt);
    lua_setfield(L, -2, "buildingTxt");
    lua_pushcfunction(L, BuildModeWindow_get_buildingTypePrevButton);
    lua_setfield(L, -2, "buildingTypePrevButton");
    lua_pushcfunction(L, BuildModeWindow_get_buildingTypeNextButton);
    lua_setfield(L, -2, "buildingTypeNextButton");
    lua_pushcfunction(L, BuildModeWindow_get_buildingImageBox);
    lua_setfield(L, -2, "buildingImageBox");
    lua_pushcfunction(L, BuildModeWindow_get_statsPanel);
    lua_setfield(L, -2, "statsPanel");
    lua_pushcfunction(L, BuildModeWindow_get_descriptionTxt);
    lua_setfield(L, -2, "descriptionTxt");
    lua_pushcfunction(L, BuildModeWindow_get_messageTextBox);
    lua_setfield(L, -2, "messageTextBox");
    lua_pushcfunction(L, BuildModeWindow_get_floorDownButton);
    lua_setfield(L, -2, "floorDownButton");
    lua_pushcfunction(L, BuildModeWindow_get_floorUpButton);
    lua_setfield(L, -2, "floorUpButton");
    lua_pushcfunction(L, BuildModeWindow_get_floorText);
    lua_setfield(L, -2, "floorText");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, BuildModeWindow_set_levelEditorMode);
    lua_setfield(L, -2, "levelEditorMode");
    lua_pushcfunction(L, BuildModeWindow_set_currentBuildingGroup);
    lua_setfield(L, -2, "currentBuildingGroup");
    lua_pushcfunction(L, BuildModeWindow_set_currentBuildingIndex);
    lua_setfield(L, -2, "currentBuildingIndex");
    lua_pushcfunction(L, BuildModeWindow_set_switchBuildingIndex);
    lua_setfield(L, -2, "switchBuildingIndex");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // setMetatableParent(L, BuildModeWindowBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

        // Wire up inheritance
    // setMetatableParent(L, BuildModeWindowBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
