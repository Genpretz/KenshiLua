#include "pch.h"
#include "kenshi\gui\BuildModeWindow.h"
#include "BuildModeWindowBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Gui/BuildingGroupBinding.h"
#include "Bindings/Kenshi/Gui/BuildingCategoryBinding.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Bindings/MyGUI/ListBoxBinding.h"
#include "Bindings/MyGUI/ButtonBinding.h"
#include "Bindings/MyGUI/TextBoxBinding.h"
#include "Bindings/MyGUI/ImageBoxBinding.h"
#include "Bindings/MyGUI/EditBoxBinding.h"

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
    return pushObject<BuildModeWindow::BuildingCategory>(L, instance->currentBuildingCategory, BuildingCategoryBinding::getMetatableName());
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
    return MyGUIBindings::pushWidget(L, instance->confirmButton);
}

static int BuildModeWindow_set_confirmButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->confirmButton = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Button>(L, 2, ButtonBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_get_undoButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->undoButton);
}

static int BuildModeWindow_set_undoButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->undoButton = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Button>(L, 2, ButtonBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_get_closeButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->closeButton);
}

static int BuildModeWindow_set_closeButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->closeButton = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Button>(L, 2, ButtonBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_get_categoriesList(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->categoriesList);
}

static int BuildModeWindow_set_categoriesList(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->categoriesList = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ListBox>(L, 2, ListBoxBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_get_buildingsList(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->buildingsList);
}

static int BuildModeWindow_set_buildingsList(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->buildingsList = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ListBox>(L, 2, ListBoxBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_get_buildingTxt(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->buildingTxt);
}

static int BuildModeWindow_set_buildingTxt(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->buildingTxt = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, TextBoxBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_get_buildingTypePrevButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->buildingTypePrevButton);
}

static int BuildModeWindow_set_buildingTypePrevButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->buildingTypePrevButton = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Button>(L, 2, ButtonBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_get_buildingTypeNextButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->buildingTypeNextButton);
}

static int BuildModeWindow_set_buildingTypeNextButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->buildingTypeNextButton = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Button>(L, 2, ButtonBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_get_buildingImageBox(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->buildingImageBox);
}

static int BuildModeWindow_set_buildingImageBox(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->buildingImageBox = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ImageBox>(L, 2, ImageBoxBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_get_statsPanel(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->statsPanel);
}

static int BuildModeWindow_set_statsPanel(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->statsPanel = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_get_descriptionTxt(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->descriptionTxt);
}

static int BuildModeWindow_set_descriptionTxt(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->descriptionTxt = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, TextBoxBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_get_messageTextBox(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->messageTextBox);
}

static int BuildModeWindow_set_messageTextBox(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->messageTextBox = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::EditBox>(L, 2, EditBoxBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_get_floorDownButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->floorDownButton);
}

static int BuildModeWindow_set_floorDownButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->floorDownButton = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Button>(L, 2, ButtonBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_get_floorUpButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->floorUpButton);
}

static int BuildModeWindow_set_floorUpButton(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->floorUpButton = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Button>(L, 2, ButtonBinding::getMetatableName());
    return 0;
}

static int BuildModeWindow_get_floorText(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    return MyGUIBindings::pushWidget(L, instance->floorText);
}

static int BuildModeWindow_set_floorText(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->floorText = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, TextBoxBinding::getMetatableName());
    return 0;
}

// --- Setters for BuildModeWindow ---
static int BuildModeWindow_set_currentBuildingCategory(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    instance->currentBuildingCategory = lua_isnoneornil(L, 2) ? nullptr : checkObject<BuildModeWindow::BuildingCategory>(L, 2, BuildingCategoryBinding::getMetatableName());
    return 0;
}

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
    return MyGUIBindings::pushWidget(L, result);
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

int BuildModeWindowBinding::compareBuildMaterials(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    GameData* b1 = checkObject<GameData>(L, idx, GameDataBinding::getMetatableName());
    GameData* b2 = checkObject<GameData>(L, idx + 1, GameDataBinding::getMetatableName());
    bool result = BuildModeWindow::compareBuildMaterials(b1, b2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BuildModeWindowBinding::categorySelected(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    MyGUI::ListBox* sender = checkObject<MyGUI::ListBox>(L, 2, ListBoxBinding::getMetatableName());
    unsigned __int64 index = (unsigned __int64)luaL_checkinteger(L, 3);
    instance->categorySelected(sender, index);
    return 0;
}

int BuildModeWindowBinding::buildingSelected(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    MyGUI::ListBox* sender = checkObject<MyGUI::ListBox>(L, 2, ListBoxBinding::getMetatableName());
    unsigned __int64 index = (unsigned __int64)luaL_checkinteger(L, 3);
    instance->buildingSelected(sender, index);
    return 0;
}

int BuildModeWindowBinding::confirm(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->confirm(sender);
    return 0;
}

int BuildModeWindowBinding::undo(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->undo(sender);
    return 0;
}

int BuildModeWindowBinding::close(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->close(sender);
    return 0;
}

int BuildModeWindowBinding::buildingTypePrev(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->buildingTypePrev(sender);
    return 0;
}

int BuildModeWindowBinding::buildingTypeNext(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->buildingTypeNext(sender);
    return 0;
}

int BuildModeWindowBinding::changeFloorButtonUp(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->changeFloorButtonUp(sender);
    return 0;
}

int BuildModeWindowBinding::changeFloorButtonDown(lua_State* L)
{
    BuildModeWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildModeWindow is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->changeFloorButtonDown(sender);
    return 0;
}

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
        { "compareBuildMaterials", BuildModeWindowBinding::compareBuildMaterials },
        { "categorySelected", BuildModeWindowBinding::categorySelected },
        { "buildingSelected", BuildModeWindowBinding::buildingSelected },
        { "confirm", BuildModeWindowBinding::confirm },
        { "undo", BuildModeWindowBinding::undo },
        { "close", BuildModeWindowBinding::close },
        { "buildingTypePrev", BuildModeWindowBinding::buildingTypePrev },
        { "buildingTypeNext", BuildModeWindowBinding::buildingTypeNext },
        { "changeFloorButtonUp", BuildModeWindowBinding::changeFloorButtonUp },
        { "changeFloorButtonDown", BuildModeWindowBinding::changeFloorButtonDown },
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
    registerSetter(L, "currentBuildingCategory", BuildModeWindow_set_currentBuildingCategory);
    registerSetter(L, "currentBuildingGroup", BuildModeWindow_set_currentBuildingGroup);
    registerSetter(L, "currentBuildingInfo", BuildModeWindow_set_currentBuildingInfo);
    registerSetter(L, "currentBuildingIndex", BuildModeWindow_set_currentBuildingIndex);
    registerSetter(L, "switchBuildingIndex", BuildModeWindow_set_switchBuildingIndex);
    registerSetter(L, "statsDataPanel", BuildModeWindow_set_statsDataPanel);
    registerSetter(L, "confirmButton", BuildModeWindow_set_confirmButton);
    registerSetter(L, "undoButton", BuildModeWindow_set_undoButton);
    registerSetter(L, "closeButton", BuildModeWindow_set_closeButton);
    registerSetter(L, "categoriesList", BuildModeWindow_set_categoriesList);
    registerSetter(L, "buildingsList", BuildModeWindow_set_buildingsList);
    registerSetter(L, "buildingTxt", BuildModeWindow_set_buildingTxt);
    registerSetter(L, "buildingTypePrevButton", BuildModeWindow_set_buildingTypePrevButton);
    registerSetter(L, "buildingTypeNextButton", BuildModeWindow_set_buildingTypeNextButton);
    registerSetter(L, "buildingImageBox", BuildModeWindow_set_buildingImageBox);
    registerSetter(L, "statsPanel", BuildModeWindow_set_statsPanel);
    registerSetter(L, "descriptionTxt", BuildModeWindow_set_descriptionTxt);
    registerSetter(L, "messageTextBox", BuildModeWindow_set_messageTextBox);
    registerSetter(L, "floorDownButton", BuildModeWindow_set_floorDownButton);
    registerSetter(L, "floorUpButton", BuildModeWindow_set_floorUpButton);
    registerSetter(L, "floorText", BuildModeWindow_set_floorText);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    pushGlobalTable(L, "BuildModeWindow");
    registerStaticMethod(L, "compareBuildMaterials", BuildModeWindowBinding::compareBuildMaterials);
    lua_setglobal(L, "BuildModeWindow");
}

} // namespace KenshiLua