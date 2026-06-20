#include "pch.h"
#include "Bindings/BuildModeWindowBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/BuildModeWindow.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static BuildModeWindow* getS(lua_State* L, int idx)
{
    return checkObject<BuildModeWindow>(L, idx, BuildModeWindowBinding::getMetatableName());
}

int BuildModeWindowBinding::gc(lua_State* L) { return noopGc(L); }

int BuildModeWindowBinding::tostring(lua_State* L)
{
    BuildModeWindow* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int BuildModeWindowBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, BuildModeWindowBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    BuildModeWindow* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO PlayerBuildMode* playerBuildMode; unsupported __index type from header line 77
    if (strcmp(key, "levelEditorMode") == 0) { lua_pushboolean(L, s->levelEditorMode ? 1 : 0); return 1; }
    // TODO Ogre::vector<BuildModeWindow::BuildingCategory*>::type playerCategories; unsupported __index type from header line 79
    // TODO Research* playerResearch; unsupported __index type from header line 80
    if (strcmp(key, "currentBuildingCategory") == 0) { lua_pushinteger(L, (lua_Integer)s->currentBuildingCategory); return 1; }
    if (strcmp(key, "currentBuildingGroup") == 0) { lua_pushinteger(L, (lua_Integer)s->currentBuildingGroup); return 1; }
    if (strcmp(key, "currentBuildingInfo") == 0) { return pushObject<GameData>(L, s->currentBuildingInfo, GameDataBinding::getMetatableName()); }
    if (strcmp(key, "currentBuildingIndex") == 0) { lua_pushinteger(L, s->currentBuildingIndex); return 1; }
    if (strcmp(key, "switchBuildingIndex") == 0) { lua_pushinteger(L, s->switchBuildingIndex); return 1; }
    // TODO DatapanelGUI* statsDataPanel; unsupported __index type from header line 86
    if (strcmp(key, "confirmButton") == 0) { lua_pushinteger(L, (lua_Integer)s->confirmButton); return 1; }
    if (strcmp(key, "undoButton") == 0) { lua_pushinteger(L, (lua_Integer)s->undoButton); return 1; }
    if (strcmp(key, "closeButton") == 0) { lua_pushinteger(L, (lua_Integer)s->closeButton); return 1; }
    if (strcmp(key, "categoriesList") == 0) { lua_pushinteger(L, (lua_Integer)s->categoriesList); return 1; }
    if (strcmp(key, "buildingsList") == 0) { lua_pushinteger(L, (lua_Integer)s->buildingsList); return 1; }
    if (strcmp(key, "buildingTxt") == 0) { lua_pushinteger(L, (lua_Integer)s->buildingTxt); return 1; }
    if (strcmp(key, "buildingTypePrevButton") == 0) { lua_pushinteger(L, (lua_Integer)s->buildingTypePrevButton); return 1; }
    if (strcmp(key, "buildingTypeNextButton") == 0) { lua_pushinteger(L, (lua_Integer)s->buildingTypeNextButton); return 1; }
    if (strcmp(key, "buildingImageBox") == 0) { lua_pushinteger(L, (lua_Integer)s->buildingImageBox); return 1; }
    if (strcmp(key, "statsPanel") == 0) { lua_pushinteger(L, (lua_Integer)s->statsPanel); return 1; }
    if (strcmp(key, "descriptionTxt") == 0) { lua_pushinteger(L, (lua_Integer)s->descriptionTxt); return 1; }
    if (strcmp(key, "messageTextBox") == 0) { lua_pushinteger(L, (lua_Integer)s->messageTextBox); return 1; }
    if (strcmp(key, "floorDownButton") == 0) { lua_pushinteger(L, (lua_Integer)s->floorDownButton); return 1; }
    if (strcmp(key, "floorUpButton") == 0) { lua_pushinteger(L, (lua_Integer)s->floorUpButton); return 1; }
    if (strcmp(key, "floorText") == 0) { lua_pushinteger(L, (lua_Integer)s->floorText); return 1; }

    lua_pushnil(L);
    return 1;
}

int BuildModeWindowBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    BuildModeWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildModeWindow is nil");

    // TODO PlayerBuildMode* playerBuildMode; unsupported __newindex type from header line 77
    if (strcmp(key, "levelEditorMode") == 0) { s->levelEditorMode = lua_toboolean(L, 3) != 0; return 0; }
    // TODO Ogre::vector<BuildModeWindow::BuildingCategory*>::type playerCategories; unsupported __newindex type from header line 79
    // TODO Research* playerResearch; unsupported __newindex type from header line 80
    // TODO BuildModeWindow::BuildingCategory* currentBuildingCategory; unsupported __newindex type from header line 81
    if (strcmp(key, "currentBuildingGroup") == 0) { s->currentBuildingGroup = (BuildModeWindow::BuildingGroup)luaL_checkinteger(L, 3); return 0; }
    // TODO GameData* currentBuildingInfo; unsupported __newindex type from header line 83
    if (strcmp(key, "currentBuildingIndex") == 0) { s->currentBuildingIndex = (short)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "switchBuildingIndex") == 0) { s->switchBuildingIndex = (short)luaL_checkinteger(L, 3); return 0; }
    // TODO DatapanelGUI* statsDataPanel; unsupported __newindex type from header line 86
    // TODO MyGUI::Button* confirmButton; unsupported __newindex type from header line 87
    // TODO MyGUI::Button* undoButton; unsupported __newindex type from header line 88
    // TODO MyGUI::Button* closeButton; unsupported __newindex type from header line 89
    // TODO MyGUI::ListBox* categoriesList; unsupported __newindex type from header line 90
    // TODO MyGUI::ListBox* buildingsList; unsupported __newindex type from header line 91
    // TODO MyGUI::TextBox* buildingTxt; unsupported __newindex type from header line 92
    // TODO MyGUI::Button* buildingTypePrevButton; unsupported __newindex type from header line 93
    // TODO MyGUI::Button* buildingTypeNextButton; unsupported __newindex type from header line 94
    // TODO MyGUI::ImageBox* buildingImageBox; unsupported __newindex type from header line 95
    // TODO MyGUI::Widget* statsPanel; unsupported __newindex type from header line 96
    // TODO MyGUI::TextBox* descriptionTxt; unsupported __newindex type from header line 97
    // TODO MyGUI::EditBox* messageTextBox; unsupported __newindex type from header line 98
    // TODO MyGUI::Button* floorDownButton; unsupported __newindex type from header line 99
    // TODO MyGUI::Button* floorUpButton; unsupported __newindex type from header line 100
    // TODO MyGUI::TextBox* floorText; unsupported __newindex type from header line 101

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int BuildModeWindowBinding::_DESTRUCTOR(lua_State* L)
{
    BuildModeWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildModeWindow is nil");

    s->_DESTRUCTOR();
    return 0;
}

int BuildModeWindowBinding::setMessage(lua_State* L)
{
    BuildModeWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildModeWindow is nil");

    std::string message = luaL_checkstring(L, 2);
    s->setMessage(message);
    return 0;
}

int BuildModeWindowBinding::getBuildingListWidget(lua_State* L)
{
    BuildModeWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildModeWindow is nil");

    MyGUI::Widget result = s->getBuildingListWidget();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int BuildModeWindowBinding::setVisible(lua_State* L)
{
    BuildModeWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildModeWindow is nil");

    bool v = lua_toboolean(L, 2) != 0;
    s->setVisible(v);
    return 0;
}

int BuildModeWindowBinding::setupData(lua_State* L)
{
    BuildModeWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildModeWindow is nil");

    s->setupData();
    return 0;
}

int BuildModeWindowBinding::listCategories(lua_State* L)
{
    BuildModeWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildModeWindow is nil");

    s->listCategories();
    return 0;
}

int BuildModeWindowBinding::listBuildingGroups(lua_State* L)
{
    BuildModeWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildModeWindow is nil");

    s->listBuildingGroups();
    return 0;
}

int BuildModeWindowBinding::updateBuildingUI(lua_State* L)
{
    BuildModeWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildModeWindow is nil");

    s->updateBuildingUI();
    return 0;
}

int BuildModeWindowBinding::build(lua_State* L)
{
    BuildModeWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildModeWindow is nil");

    s->build();
    return 0;
}

int BuildModeWindowBinding::showBuildingStats(lua_State* L)
{
    BuildModeWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildModeWindow is nil");

    s->showBuildingStats();
    return 0;
}

int BuildModeWindowBinding::update(lua_State* L)
{
    BuildModeWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildModeWindow is nil");

    s->update();
    return 0;
}

int BuildModeWindowBinding::changeCurrentIndex(lua_State* L)
{
    BuildModeWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildModeWindow is nil");

    int index = (int)luaL_checkinteger(L, 2);
    s->changeCurrentIndex(index);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 52: BuildModeWindow* _CONSTRUCTOR(...) - unsupported return type
  line 62: void categorySelected(...) - pointer arg
  line 63: void buildingSelected(...) - pointer arg
  line 65: void confirm(...) - pointer arg
  line 66: void undo(...) - pointer arg
  line 67: void close(...) - pointer arg
  line 68: void buildingTypePrev(...) - pointer arg
  line 69: void buildingTypeNext(...) - pointer arg
  line 72: bool compareBuildMaterials(...) - static method
  line 74: void changeFloorButtonUp(...) - pointer arg
  line 75: void changeFloorButtonDown(...) - pointer arg
*/

void BuildModeWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildModeWindowBinding::gc },
        { "__tostring", BuildModeWindowBinding::tostring },
        { "__index",    BuildModeWindowBinding::index },
        { "__newindex", BuildModeWindowBinding::newindex },
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
    registerClass(L, BuildModeWindowBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua