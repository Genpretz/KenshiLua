#include "pch.h"
#include "kenshi\gui\LevelEditor.h"
#include "LevelEditorBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Gui/FogEditorBinding.h"
#include "Bindings/Gui/InteriorModeButtonWindowBinding.h"
#include "Bindings/Gui/TownListWindowBinding.h"
#include "Bindings/Gui/FactionListWindowBinding.h"
#include "Bindings/Gui/SquadListWindowBinding.h"
#include "Bindings/Gui/NpcListWindowBinding.h"
#include "Bindings/Gui/ItemListWindowBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/RootObjectBinding.h"

namespace KenshiLua
{

static LevelEditor* getInstance(lua_State* L, int idx)
{
    return checkObject<LevelEditor>(L, idx, LevelEditorBinding::getMetatableName());
}

// --- Getters for LevelEditor ---
static int LevelEditor_get_levelEditModeOn(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    lua_pushboolean(L, instance->levelEditModeOn ? 1 : 0);
    return 1;
}

static int LevelEditor_get_panel(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->panel);
    return 1;
}

static int LevelEditor_get_interiorModeWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    return pushObject<InteriorModeButtonWindow>(L, instance->interiorModeWindow, InteriorModeButtonWindowBinding::getMetatableName());
}

static int LevelEditor_get_selectedLocked(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    lua_pushinteger(L, instance->selectedLocked);
    return 1;
}

static int LevelEditor_get_selectedObject(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    return HandBinding::push(L, instance->selectedObject);
}

static int LevelEditor_get_selectedFeature(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->selectedFeature);
    return 1;
}

static int LevelEditor_get_seedMode(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    lua_pushinteger(L, instance->seedMode);
    return 1;
}

static int LevelEditor_get_roadMode(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    lua_pushinteger(L, instance->roadMode);
    return 1;
}

static int LevelEditor_get_roadIndex(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    lua_pushinteger(L, instance->roadIndex);
    return 1;
}

static int LevelEditor_get_roadMarker(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->roadMarker);
    return 1;
}

static int LevelEditor_get_roadMakerMO(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->roadMakerMO);
    return 1;
}

static int LevelEditor_get_foliageEraser(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->foliageEraser);
    return 1;
}

static int LevelEditor_get_fogEditor(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    return pushObject<FogEditor>(L, instance->fogEditor, FogEditorBinding::getMetatableName());
}

static int LevelEditor_get_townListWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    return pushObject<LevelEditor::TownListWindow>(L, instance->townListWindow, TownListWindowBinding::getMetatableName());
}

static int LevelEditor_get_factionListWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    return pushObject<LevelEditor::FactionListWindow>(L, instance->factionListWindow, FactionListWindowBinding::getMetatableName());
}

static int LevelEditor_get_squadListWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    return pushObject<LevelEditor::SquadListWindow>(L, instance->squadListWindow, SquadListWindowBinding::getMetatableName());
}

static int LevelEditor_get_npcListWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    return pushObject<LevelEditor::NpcListWindow>(L, instance->npcListWindow, NpcListWindowBinding::getMetatableName());
}

static int LevelEditor_get_featureListWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    return pushObject<LevelEditor::NpcListWindow>(L, instance->featureListWindow, NpcListWindowBinding::getMetatableName());
}

static int LevelEditor_get_itemListWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    return pushObject<LevelEditor::ItemListWindow>(L, instance->itemListWindow, ItemListWindowBinding::getMetatableName());
}

static int LevelEditor_get_navmeshWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    return pushObject<DatapanelGUI>(L, instance->navmeshWindow, DatapanelGUIBinding::getMetatableName());
}

static int LevelEditor_get_editMapTitleWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->editMapTitleWindow);
    return 1;
}

static int LevelEditor_get_factionTxt(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->factionTxt);
    return 1;
}

static int LevelEditor_get_altitudeTxt(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->altitudeTxt);
    return 1;
}

static int LevelEditor_get_activeModTxt(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->activeModTxt);
    return 1;
}

// --- Setters for LevelEditor ---
static int LevelEditor_set_levelEditModeOn(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->levelEditModeOn = lua_toboolean(L, 2) != 0;
    return 0;
}

static int LevelEditor_set_selectedLocked(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->selectedLocked = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int LevelEditor_set_selectedObject(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->selectedObject = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int LevelEditor_set_seedMode(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->seedMode = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int LevelEditor_set_roadMode(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->roadMode = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int LevelEditor_set_roadIndex(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->roadIndex = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int LevelEditor_set_fogEditor(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->fogEditor = lua_isnoneornil(L, 2) ? nullptr : checkObject<FogEditor>(L, 2, FogEditorBinding::getMetatableName());
    return 0;
}

static int LevelEditor_set_navmeshWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->navmeshWindow = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int LevelEditor_set_interiorModeWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->interiorModeWindow = lua_isnoneornil(L, 2) ? nullptr : checkObject<InteriorModeButtonWindow>(L, 2, InteriorModeButtonWindowBinding::getMetatableName());
    return 0;
}

static int LevelEditor_set_townListWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->townListWindow = lua_isnoneornil(L, 2) ? nullptr : checkObject<LevelEditor::TownListWindow>(L, 2, TownListWindowBinding::getMetatableName());
    return 0;
}

static int LevelEditor_set_factionListWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->factionListWindow = lua_isnoneornil(L, 2) ? nullptr : checkObject<LevelEditor::FactionListWindow>(L, 2, FactionListWindowBinding::getMetatableName());
    return 0;
}

static int LevelEditor_set_squadListWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->squadListWindow = lua_isnoneornil(L, 2) ? nullptr : checkObject<LevelEditor::SquadListWindow>(L, 2, SquadListWindowBinding::getMetatableName());
    return 0;
}

static int LevelEditor_set_npcListWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->npcListWindow = lua_isnoneornil(L, 2) ? nullptr : checkObject<LevelEditor::NpcListWindow>(L, 2, NpcListWindowBinding::getMetatableName());
    return 0;
}

static int LevelEditor_set_featureListWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->featureListWindow = lua_isnoneornil(L, 2) ? nullptr : checkObject<LevelEditor::NpcListWindow>(L, 2, NpcListWindowBinding::getMetatableName());
    return 0;
}

static int LevelEditor_set_itemListWindow(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");
    instance->itemListWindow = lua_isnoneornil(L, 2) ? nullptr : checkObject<LevelEditor::ItemListWindow>(L, 2, ItemListWindowBinding::getMetatableName());
    return 0;
}

int LevelEditorBinding::_CONSTRUCTOR(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    LevelEditor* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int LevelEditorBinding::_DESTRUCTOR(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int LevelEditorBinding::close(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    instance->close();
    return 0;
}

int LevelEditorBinding::update(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    instance->update();
    return 0;
}

int LevelEditorBinding::updateGizmo(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    bool result = instance->updateGizmo();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LevelEditorBinding::levelEditMode(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->levelEditMode(on);
    return 0;
}

int LevelEditorBinding::isInteriorEditMode(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    bool result = instance->isInteriorEditMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LevelEditorBinding::getActiveModIndex(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    int result = instance->getActiveModIndex();
    lua_pushinteger(L, result);
    return 1;
}

int LevelEditorBinding::getActiveMod(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    std::string result = instance->getActiveMod();
    lua_pushstring(L, result.c_str());
    return 1;
}

int LevelEditorBinding::isBaseActive(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    bool result = instance->isBaseActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LevelEditorBinding::setEditSquad(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    GameData* squad = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->setEditSquad(squad);
    return 0;
}

int LevelEditorBinding::repath(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->repath(_a1);
    return 0;
}

int LevelEditorBinding::toggleSeedMode(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->toggleSeedMode(line);
    return 0;
}

int LevelEditorBinding::clearSeedPoints(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->clearSeedPoints(_a1);
    return 0;
}

int LevelEditorBinding::setSeedMode(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    int mode = (int)luaL_checkinteger(L, 2);
    instance->setSeedMode(mode);
    return 0;
}

int LevelEditorBinding::toggleRoadEditor(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    DatapanelGUI* _a1 = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int tab = (int)luaL_checkinteger(L, 3);
    instance->toggleRoadEditor(_a1, tab);
    return 0;
}

int LevelEditorBinding::toggleFoliageRemoval(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->toggleFoliageRemoval(line);
    return 0;
}

int LevelEditorBinding::clearChanges(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    RootObject* object = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->clearChanges(object);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LevelEditorBinding::deleteDuplicateBuildings(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    int result = instance->deleteDuplicateBuildings();
    lua_pushinteger(L, result);
    return 1;
}

int LevelEditorBinding::fixMountedBuildings(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    int result = instance->fixMountedBuildings();
    lua_pushinteger(L, result);
    return 1;
}

int LevelEditorBinding::deleteAll(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool confirmed = lua_toboolean(L, 3) != 0;
    int result = instance->deleteAll(data, confirmed);
    lua_pushinteger(L, result);
    return 1;
}

int LevelEditorBinding::adjustAltitudeSpeed(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    float s = (float)luaL_checknumber(L, 2);
    instance->adjustAltitudeSpeed(s);
    return 0;
}

int LevelEditorBinding::fixInvalidInteriorFurnitureStates(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    int result = instance->fixInvalidInteriorFurnitureStates();
    lua_pushinteger(L, result);
    return 1;
}

int LevelEditorBinding::fixBuildingFloorState(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    Building* b = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    Building* parent = checkObject<Building>(L, 3, BuildingBinding::getMetatableName());
    bool result = instance->fixBuildingFloorState(b, parent);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LevelEditorBinding::setSelectedObject(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->setSelectedObject(obj);
    return 0;
}

int LevelEditorBinding::updateRoadEditor(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    instance->updateRoadEditor();
    return 0;
}

int LevelEditorBinding::setRoadWidth(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    DataPanelLine* l = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->setRoadWidth(l);
    return 0;
}

int LevelEditorBinding::setRoadHidden(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    DataPanelLine* l = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->setRoadHidden(l);
    return 0;
}

int LevelEditorBinding::drawRoads(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->drawRoads(_a1);
    return 0;
}

int LevelEditorBinding::eraseRoads(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->eraseRoads(_a1);
    return 0;
}

int LevelEditorBinding::drawAllRoads(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->drawAllRoads(_a1);
    return 0;
}

int LevelEditorBinding::projectRoads(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->projectRoads(_a1);
    return 0;
}

int LevelEditorBinding::validateRoads(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->validateRoads(_a1);
    return 0;
}

int LevelEditorBinding::createRoadMarker(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    instance->createRoadMarker();
    return 0;
}

int LevelEditorBinding::destroyRoadMaker(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    instance->destroyRoadMaker();
    return 0;
}

int LevelEditorBinding::updateFoliageRemoval(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    instance->updateFoliageRemoval();
    return 0;
}

int LevelEditorBinding::updateSeedEditor(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    instance->updateSeedEditor();
    return 0;
}

int LevelEditorBinding::deleteObject(lua_State* L)
{
    LevelEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LevelEditor is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 to deleteObject must be hand");
    instance->deleteObject(*h);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 34: RootObject* hitFurnitureOrItemGroup(...) - unsupported arg type
  line 35: std::pair<bool, float> hitOgreMesh(...) - static method
  line 36: std::pair<bool, float> hitBuildingMesh(...) - static method
  line 45: void saveMod(...) - unsupported arg type
  line 46: void regenerate(...) - unsupported arg type
  line 53: void closeNavmeshWindow(...) - unsupported arg type
  line 54: void fixBuildings(...) - unsupported arg type
  line 185: void factionButton(...) - unsupported arg type
  line 186: void npcButton(...) - unsupported arg type
  line 187: void townButton(...) - unsupported arg type
  line 188: void squadButton(...) - unsupported arg type
  line 189: void featureButton(...) - unsupported arg type
  line 190: void fogButton(...) - unsupported arg type
  line 191: void itemsButton(...) - unsupported arg type
  line 192: void buildingsButton(...) - unsupported arg type
  line 193: void navmeshButton(...) - unsupported arg type
  line 194: void exitLevelEditMode(...) - unsupported arg type
  line 195: void activeModChanged(...) - unsupported arg type
  line 204: bool paintRoads(...) - unsupported arg type
  line 205: bool paintFoliageEraser(...) - unsupported arg type
  line 206: void selectRoad(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - LevelEditor_get_panel: LevelEditorPanel* (unbound pointer)
  - LevelEditor_get_selectedFeature: MapFeature* (unbound pointer)
  - LevelEditor_get_roadMarker: Ogre::SceneNode* (unbound pointer)
  - LevelEditor_get_roadMakerMO: Ogre::ManualObject* (unbound pointer)
  - LevelEditor_get_foliageEraser: FoliageEraser* (unbound pointer)
  - LevelEditor_get_editMapTitleWindow: MyGUI::Window* (unbound pointer)
  - LevelEditor_get_factionTxt: MyGUI::TextBox* (unbound pointer)
  - LevelEditor_get_altitudeTxt: MyGUI::TextBox* (unbound pointer)
  - LevelEditor_get_activeModTxt: MyGUI::ComboBox* (unbound pointer)
  - LevelEditorBinding::_CONSTRUCTOR: LevelEditor* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 71: selectedRoads (lektor<Road*>) - unsupported type
*/

int LevelEditorBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int LevelEditorBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.LevelEditor object");
    return 1;
}

void LevelEditorBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LevelEditorBinding::gc },
        { "__tostring", LevelEditorBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", LevelEditorBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", LevelEditorBinding::_DESTRUCTOR },
        { "close", LevelEditorBinding::close },
        { "update", LevelEditorBinding::update },
        { "updateGizmo", LevelEditorBinding::updateGizmo },
        { "levelEditMode", LevelEditorBinding::levelEditMode },
        { "isInteriorEditMode", LevelEditorBinding::isInteriorEditMode },
        { "getActiveModIndex", LevelEditorBinding::getActiveModIndex },
        { "getActiveMod", LevelEditorBinding::getActiveMod },
        { "isBaseActive", LevelEditorBinding::isBaseActive },
        { "setEditSquad", LevelEditorBinding::setEditSquad },
        { "repath", LevelEditorBinding::repath },
        { "toggleSeedMode", LevelEditorBinding::toggleSeedMode },
        { "clearSeedPoints", LevelEditorBinding::clearSeedPoints },
        { "setSeedMode", LevelEditorBinding::setSeedMode },
        { "toggleRoadEditor", LevelEditorBinding::toggleRoadEditor },
        { "toggleFoliageRemoval", LevelEditorBinding::toggleFoliageRemoval },
        { "clearChanges", LevelEditorBinding::clearChanges },
        { "deleteDuplicateBuildings", LevelEditorBinding::deleteDuplicateBuildings },
        { "fixMountedBuildings", LevelEditorBinding::fixMountedBuildings },
        { "deleteAll", LevelEditorBinding::deleteAll },
        { "adjustAltitudeSpeed", LevelEditorBinding::adjustAltitudeSpeed },
        { "fixInvalidInteriorFurnitureStates", LevelEditorBinding::fixInvalidInteriorFurnitureStates },
        { "fixBuildingFloorState", LevelEditorBinding::fixBuildingFloorState },
        { "setSelectedObject", LevelEditorBinding::setSelectedObject },
        { "updateRoadEditor", LevelEditorBinding::updateRoadEditor },
        { "setRoadWidth", LevelEditorBinding::setRoadWidth },
        { "setRoadHidden", LevelEditorBinding::setRoadHidden },
        { "drawRoads", LevelEditorBinding::drawRoads },
        { "eraseRoads", LevelEditorBinding::eraseRoads },
        { "drawAllRoads", LevelEditorBinding::drawAllRoads },
        { "projectRoads", LevelEditorBinding::projectRoads },
        { "validateRoads", LevelEditorBinding::validateRoads },
        { "createRoadMarker", LevelEditorBinding::createRoadMarker },
        { "destroyRoadMaker", LevelEditorBinding::destroyRoadMaker },
        { "updateFoliageRemoval", LevelEditorBinding::updateFoliageRemoval },
        { "updateSeedEditor", LevelEditorBinding::updateSeedEditor },
        { "deleteObject", LevelEditorBinding::deleteObject },
        { 0, 0 }
    };

    registerClass(
        L, 
        LevelEditorBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, LevelEditorBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "levelEditModeOn", LevelEditor_get_levelEditModeOn);
    registerGetter(L, "panel", LevelEditor_get_panel);
    registerGetter(L, "interiorModeWindow", LevelEditor_get_interiorModeWindow);
    registerGetter(L, "selectedLocked", LevelEditor_get_selectedLocked);
    registerGetter(L, "selectedObject", LevelEditor_get_selectedObject);
    registerGetter(L, "selectedFeature", LevelEditor_get_selectedFeature);
    registerGetter(L, "seedMode", LevelEditor_get_seedMode);
    registerGetter(L, "roadMode", LevelEditor_get_roadMode);
    registerGetter(L, "roadIndex", LevelEditor_get_roadIndex);
    registerGetter(L, "roadMarker", LevelEditor_get_roadMarker);
    registerGetter(L, "roadMakerMO", LevelEditor_get_roadMakerMO);
    registerGetter(L, "foliageEraser", LevelEditor_get_foliageEraser);
    registerGetter(L, "fogEditor", LevelEditor_get_fogEditor);
    registerGetter(L, "townListWindow", LevelEditor_get_townListWindow);
    registerGetter(L, "factionListWindow", LevelEditor_get_factionListWindow);
    registerGetter(L, "squadListWindow", LevelEditor_get_squadListWindow);
    registerGetter(L, "npcListWindow", LevelEditor_get_npcListWindow);
    registerGetter(L, "featureListWindow", LevelEditor_get_featureListWindow);
    registerGetter(L, "itemListWindow", LevelEditor_get_itemListWindow);
    registerGetter(L, "navmeshWindow", LevelEditor_get_navmeshWindow);
    registerGetter(L, "editMapTitleWindow", LevelEditor_get_editMapTitleWindow);
    registerGetter(L, "factionTxt", LevelEditor_get_factionTxt);
    registerGetter(L, "altitudeTxt", LevelEditor_get_altitudeTxt);
    registerGetter(L, "activeModTxt", LevelEditor_get_activeModTxt);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "levelEditModeOn", LevelEditor_set_levelEditModeOn);
    registerSetter(L, "interiorModeWindow", LevelEditor_set_interiorModeWindow);
    registerSetter(L, "selectedLocked", LevelEditor_set_selectedLocked);
    registerSetter(L, "selectedObject", LevelEditor_set_selectedObject);
    registerSetter(L, "seedMode", LevelEditor_set_seedMode);
    registerSetter(L, "roadMode", LevelEditor_set_roadMode);
    registerSetter(L, "roadIndex", LevelEditor_set_roadIndex);
    registerSetter(L, "fogEditor", LevelEditor_set_fogEditor);
    registerSetter(L, "townListWindow", LevelEditor_set_townListWindow);
    registerSetter(L, "factionListWindow", LevelEditor_set_factionListWindow);
    registerSetter(L, "squadListWindow", LevelEditor_set_squadListWindow);
    registerSetter(L, "npcListWindow", LevelEditor_set_npcListWindow);
    registerSetter(L, "featureListWindow", LevelEditor_set_featureListWindow);
    registerSetter(L, "itemListWindow", LevelEditor_set_itemListWindow);
    registerSetter(L, "navmeshWindow", LevelEditor_set_navmeshWindow);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua