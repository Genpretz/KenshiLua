#include "pch.h"
#include "kenshi\gui\CharacterEditWindow.h"
#include "CharacterEditWindowBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataCopyStandaloneBinding.h"
#include "Bindings/Gui/OpenSaveFileDialogBinding.h"

namespace KenshiLua
{

static CharacterEditWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<CharacterEditWindow>(L, idx, CharacterEditWindowBinding::getMetatableName());
}

// --- Getters for CharacterEditWindow ---
static int CharacterEditWindow_get_camera(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->camera);
    return 1;
}

static int CharacterEditWindow_get_txtName(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->txtName);
    return 1;
}

static int CharacterEditWindow_get_txtGender(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->txtGender);
    return 1;
}

static int CharacterEditWindow_get_txtRace(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->txtRace);
    return 1;
}

static int CharacterEditWindow_get_txtSubRace(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->txtSubRace);
    return 1;
}

static int CharacterEditWindow_get_txtCharIdx(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->txtCharIdx);
    return 1;
}

static int CharacterEditWindow_get_importButton(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->importButton);
    return 1;
}

static int CharacterEditWindow_get_exportButton(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->exportButton);
    return 1;
}

static int CharacterEditWindow_get_panelTabs(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->panelTabs);
    return 1;
}

static int CharacterEditWindow_get_panelTabsView(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->panelTabsView);
    return 1;
}

static int CharacterEditWindow_get_btnPrevGender(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->btnPrevGender);
    return 1;
}

static int CharacterEditWindow_get_btnNextGender(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->btnNextGender);
    return 1;
}

static int CharacterEditWindow_get_btnPrevRace(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->btnPrevRace);
    return 1;
}

static int CharacterEditWindow_get_btnNextRace(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->btnNextRace);
    return 1;
}

static int CharacterEditWindow_get_btnPrevSubRace(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->btnPrevSubRace);
    return 1;
}

static int CharacterEditWindow_get_btnNextSubRace(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->btnNextSubRace);
    return 1;
}

static int CharacterEditWindow_get_btnReset(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->btnReset);
    return 1;
}

static int CharacterEditWindow_get_btnRandomiseAll(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->btnRandomiseAll);
    return 1;
}

static int CharacterEditWindow_get_btnRandomisePart(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->btnRandomisePart);
    return 1;
}

static int CharacterEditWindow_get_descriptionPanel(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->descriptionPanel);
    return 1;
}

static int CharacterEditWindow_get_descriptionPanelText(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->descriptionPanelText);
    return 1;
}

static int CharacterEditWindow_get_statsPanel(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->statsPanel);
    return 1;
}

static int CharacterEditWindow_get_statsDataPanel(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->statsDataPanel, DatapanelGUIBinding::getMetatableName());
}

static int CharacterEditWindow_get_dialog(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    return pushObject<OpenSaveFileDialog>(L, instance->dialog, OpenSaveFileDialogBinding::getMetatableName());
}

static int CharacterEditWindow_get_isMidGame(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushboolean(L, instance->isMidGame ? 1 : 0);
    return 1;
}

static int CharacterEditWindow_get_multipleCharactersChangedCheck(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushinteger(L, instance->multipleCharactersChangedCheck);
    return 1;
}

static int CharacterEditWindow_get_characterEntityUpdated(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushboolean(L, instance->characterEntityUpdated ? 1 : 0);
    return 1;
}

static int CharacterEditWindow_get_clothVisible(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushboolean(L, instance->clothVisible ? 1 : 0);
    return 1;
}

static int CharacterEditWindow_get_appearanceData(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    return pushObject<GameDataCopyStandalone>(L, instance->appearanceData, GameDataCopyStandaloneBinding::getMetatableName());
}

static int CharacterEditWindow_get_raceData(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    return pushObject<GameData>(L, instance->raceData, GameDataBinding::getMetatableName());
}

static int CharacterEditWindow_get_currentCategory(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentCategory.getValue());
    return 1;
}

static int CharacterEditWindow_get_currentRaceGroupIndex(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushinteger(L, instance->currentRaceGroupIndex);
    return 1;
}

static int CharacterEditWindow_get_currentSubRaceIndex(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushinteger(L, instance->currentSubRaceIndex);
    return 1;
}

static int CharacterEditWindow_get_currentGender(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentGender.getValue());
    return 1;
}

static int CharacterEditWindow_get_currentRaceData(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->currentRaceData);
    return 1;
}

static int CharacterEditWindow_get_currentEditData(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->currentEditData);
    return 1;
}

static int CharacterEditWindow_get_character(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    return pushObject<Character>(L, instance->character, CharacterBinding::getMetatableName());
}

static int CharacterEditWindow_get_currentCharacterIdx(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushinteger(L, instance->currentCharacterIdx);
    return 1;
}

static int CharacterEditWindow_get_currentAnimation(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->currentAnimation);
    return 1;
}

static int CharacterEditWindow_get_raceLimits(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->raceLimits);
    return 1;
}

static int CharacterEditWindow_get_showNamesOption(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushboolean(L, instance->showNamesOption ? 1 : 0);
    return 1;
}

static int CharacterEditWindow_get_editorRootNode(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->editorRootNode);
    return 1;
}

static int CharacterEditWindow_get_characterPositionNode(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->characterPositionNode);
    return 1;
}

static int CharacterEditWindow_get_characterRotationNode(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->characterRotationNode);
    return 1;
}

static int CharacterEditWindow_get_workspace(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->workspace);
    return 1;
}

static int CharacterEditWindow_get_platform(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->platform);
    return 1;
}

static int CharacterEditWindow_get_requestUpdateLiveObject(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    lua_pushboolean(L, instance->requestUpdateLiveObject ? 1 : 0);
    return 1;
}

// --- Setters for CharacterEditWindow ---
static int CharacterEditWindow_set_statsDataPanel(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->statsDataPanel = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int CharacterEditWindow_set_dialog(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->dialog = lua_isnoneornil(L, 2) ? nullptr : checkObject<OpenSaveFileDialog>(L, 2, OpenSaveFileDialogBinding::getMetatableName());
    return 0;
}

static int CharacterEditWindow_set_isMidGame(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->isMidGame = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharacterEditWindow_set_multipleCharactersChangedCheck(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->multipleCharactersChangedCheck = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharacterEditWindow_set_characterEntityUpdated(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->characterEntityUpdated = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharacterEditWindow_set_clothVisible(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->clothVisible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharacterEditWindow_set_appearanceData(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->appearanceData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    return 0;
}

static int CharacterEditWindow_set_raceData(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->raceData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int CharacterEditWindow_set_currentCategory(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->currentCategory = AppearanceManager::DataCategory((AppearanceManager::DataCategory::Enum)luaL_checkinteger(L, 2));
    return 0;
}

static int CharacterEditWindow_set_currentRaceGroupIndex(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->currentRaceGroupIndex = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int CharacterEditWindow_set_currentSubRaceIndex(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->currentSubRaceIndex = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int CharacterEditWindow_set_currentGender(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->currentGender = AppearanceManager::Gender((AppearanceManager::Gender::Enum)luaL_checkinteger(L, 2));
    return 0;
}

static int CharacterEditWindow_set_character(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->character = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int CharacterEditWindow_set_currentCharacterIdx(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->currentCharacterIdx = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

static int CharacterEditWindow_set_showNamesOption(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->showNamesOption = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharacterEditWindow_set_requestUpdateLiveObject(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");
    instance->requestUpdateLiveObject = lua_toboolean(L, 2) != 0;
    return 0;
}

int CharacterEditWindowBinding::_DESTRUCTOR(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int CharacterEditWindowBinding::update(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    instance->update();
    return 0;
}

int CharacterEditWindowBinding::loadData(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    instance->loadData();
    return 0;
}

int CharacterEditWindowBinding::initCharacters(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    instance->initCharacters();
    return 0;
}

int CharacterEditWindowBinding::updateRace(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    instance->updateRace();
    return 0;
}

int CharacterEditWindowBinding::updateCharacterPoses(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    instance->updateCharacterPoses();
    return 0;
}

int CharacterEditWindowBinding::clearCharacterPoses(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    instance->clearCharacterPoses();
    return 0;
}

int CharacterEditWindowBinding::updateCharacter(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    instance->updateCharacter();
    return 0;
}

int CharacterEditWindowBinding::showCharacter(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool on = lua_toboolean(L, 3) != 0;
    instance->showCharacter(c, on);
    return 0;
}

int CharacterEditWindowBinding::updateCurrentCategory(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    instance->updateCurrentCategory();
    return 0;
}

int CharacterEditWindowBinding::loadImportedCharacter(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    OpenSaveFileDialog* _dialog = checkObject<OpenSaveFileDialog>(L, 2, OpenSaveFileDialogBinding::getMetatableName());
    bool accept = lua_toboolean(L, 3) != 0;
    std::string result = luaL_checkstring(L, 4);
    instance->loadImportedCharacter(_dialog, accept, result);
    return 0;
}

int CharacterEditWindowBinding::setClothesVisible(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    Character* _character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool visible = lua_toboolean(L, 3) != 0;
    instance->setClothesVisible(_character, visible);
    return 0;
}

int CharacterEditWindowBinding::confirmMessageCallback(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    int _btn = (int)luaL_checkinteger(L, 2);
    instance->confirmMessageCallback(_btn);
    return 0;
}

int CharacterEditWindowBinding::setupUI(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    instance->setupUI();
    return 0;
}

int CharacterEditWindowBinding::setUIEnabled(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    bool enabled = lua_toboolean(L, 2) != 0;
    instance->setUIEnabled(enabled);
    return 0;
}

int CharacterEditWindowBinding::refreshUI(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    instance->refreshUI();
    return 0;
}

int CharacterEditWindowBinding::updateLiveObject(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    instance->updateLiveObject();
    return 0;
}

int CharacterEditWindowBinding::refreshCharacterPoses(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    instance->refreshCharacterPoses();
    return 0;
}

int CharacterEditWindowBinding::exportMeshes(lua_State* L)
{
    CharacterEditWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterEditWindow is nil");

    instance->exportMeshes();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 38: CharacterEditWindow* _CONSTRUCTOR(...) - unsupported arg type
  line 44: void nameChanged(...) - unsupported arg type
  line 45: void prevRace(...) - unsupported arg type
  line 46: void nextRace(...) - unsupported arg type
  line 47: void prevSubRace(...) - unsupported arg type
  line 48: void nextSubRace(...) - unsupported arg type
  line 50: void changeGender(...) - unsupported arg type
  line 51: void changeAppearanceData(...) - non-string reference arg
  line 54: void prevCharacter(...) - unsupported arg type
  line 55: void nextCharacter(...) - unsupported arg type
  line 58: void changeCategory(...) - unsupported arg type
  line 60: void resetAppearance(...) - unsupported arg type
  line 61: void randomiseAll(...) - unsupported arg type
  line 62: void randomisePart(...) - unsupported arg type
  line 63: void importCharacter(...) - unsupported arg type
  line 64: void exportCharacter(...) - unsupported arg type
  line 66: void toggleClothes(...) - unsupported arg type
  line 68: void updateAppearanceSlider(...) - unsupported arg type
  line 69: void updateAppearanceSliderPose(...) - unsupported arg type
  line 70: void updateAppearanceSliderVector(...) - unsupported arg type
  line 71: void updateAppearanceList(...) - unsupported arg type
  line 72: void updateAppearanceMultiSlider(...) - unsupported arg type
  line 73: void updateAnimationIdle(...) - unsupported arg type
  line 74: void confirmButton(...) - unsupported arg type
  line 82: const std::string& getCurrentHeadName(...) - reference return type
  line 83: const std::string& getCurrentAttachmentName(...) - reference return type
  line 84: void setCurrentHeadName(...) - unsupported arg type
  line 85: void setCurrentAttachmentName(...) - unsupported arg type
  line 86: Ogre::Entity* getCharacterEntity(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 98: buttonsCategories (ogre_unordered_map<AppearanceManager::DataCategory::Enum, MyGUI::Button*>::type) - unsupported type
  line 107: sliderSize (MyGUI::types::TSize<int>) - unsupported type
  line 108: multiSliderSize (MyGUI::types::TSize<int>) - unsupported type
  line 109: listScrollBarSize (MyGUI::types::TSize<int>) - unsupported type
  line 130: idleAnimations (Ogre::FastArray<AnimationData*>) - unsupported type
  line 131: characters (Ogre::FastArray<Character*>) - unsupported type
  line 134: charactersAppearanceByRace (boost::unordered::unordered_map<Character*, boost::unordered::unordered_map<std::pair<GameData*, enum AppearanceManager::Gender::Enum>, GameDataCopyStandalone*, boost::hash<std::pair<GameData*, enum AppearanceManager::Gender::Enum> >, std::equal_to<std::pair<GameData*, enum AppearanceManager::Gender::Enum> >, Ogre::STLAllocator<std::pair<std::pair<GameData*, enum AppearanceManager::Gender::Enum> const, GameDataCopyStandalone*>, Ogre::GeneralAllocPolicy > >, boost::hash<Character*>, std::equal_to<Character*>, Ogre::STLAllocator<std::pair<Character*const, boost::unordered::unordered_map<std::pair<GameData*, enum AppearanceManager::Gender::Enum>, GameDataCopyStandalone*, boost::hash<std::pair<GameData*, enum AppearanceManager::Gender::Enum> >, std::equal_to<std::pair<GameData*, enum AppearanceManager::Gender::Enum> >, Ogre::STLAllocator<std::pair<std::pair<GameData*, enum AppearanceManager::Gender::Enum> const, GameDataCopyStandalone*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 137: races (boost::unordered::unordered_map<RaceGroupData*, Ogre::FastArray<GameData*>, boost::hash<RaceGroupData*>, std::equal_to<RaceGroupData*>, Ogre::STLAllocator<std::pair<RaceGroupData*const, Ogre::FastArray<GameData*> >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 138: racesGroups (Ogre::FastArray<RaceGroupData*>) - unsupported type
  line 139: raceAppearanceData (boost::unordered::unordered_map<GameData*, ogre_unordered_map<AppearanceManager::Gender::Enum, AppearanceManager::AppearanceData>::type, boost::hash<GameData*>, std::equal_to<GameData*>, Ogre::STLAllocator<std::pair<GameData*const, ogre_unordered_map<AppearanceManager::Gender::Enum, AppearanceManager::AppearanceData>::type >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 140: poses (boost::unordered::unordered_map<std::string, Ogre::Pose*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Pose*>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 141: posesCharactersValues (boost::unordered::unordered_map<Character*, boost::unordered::unordered_map<std::string, float, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::GeneralAllocPolicy > >, boost::hash<Character*>, std::equal_to<Character*>, Ogre::STLAllocator<std::pair<Character*const, boost::unordered::unordered_map<std::string, float, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 143: initialPositions (Ogre::FastArray<Ogre::Vector3>) - unsupported type
*/

int CharacterEditWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CharacterEditWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CharacterEditWindow object");
    return 1;
}

void CharacterEditWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CharacterEditWindowBinding::gc },
        { "__tostring", CharacterEditWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", CharacterEditWindowBinding::_DESTRUCTOR },
        { "update", CharacterEditWindowBinding::update },
        { "loadData", CharacterEditWindowBinding::loadData },
        { "initCharacters", CharacterEditWindowBinding::initCharacters },
        { "updateRace", CharacterEditWindowBinding::updateRace },
        { "updateCharacterPoses", CharacterEditWindowBinding::updateCharacterPoses },
        { "clearCharacterPoses", CharacterEditWindowBinding::clearCharacterPoses },
        { "updateCharacter", CharacterEditWindowBinding::updateCharacter },
        { "showCharacter", CharacterEditWindowBinding::showCharacter },
        { "updateCurrentCategory", CharacterEditWindowBinding::updateCurrentCategory },
        { "loadImportedCharacter", CharacterEditWindowBinding::loadImportedCharacter },
        { "setClothesVisible", CharacterEditWindowBinding::setClothesVisible },
        { "confirmMessageCallback", CharacterEditWindowBinding::confirmMessageCallback },
        { "setupUI", CharacterEditWindowBinding::setupUI },
        { "setUIEnabled", CharacterEditWindowBinding::setUIEnabled },
        { "refreshUI", CharacterEditWindowBinding::refreshUI },
        { "updateLiveObject", CharacterEditWindowBinding::updateLiveObject },
        { "refreshCharacterPoses", CharacterEditWindowBinding::refreshCharacterPoses },
        { "exportMeshes", CharacterEditWindowBinding::exportMeshes },
        { 0, 0 }
    };

    registerClass(
        L, 
        CharacterEditWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CharacterEditWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "camera", CharacterEditWindow_get_camera);
    registerGetter(L, "txtName", CharacterEditWindow_get_txtName);
    registerGetter(L, "txtGender", CharacterEditWindow_get_txtGender);
    registerGetter(L, "txtRace", CharacterEditWindow_get_txtRace);
    registerGetter(L, "txtSubRace", CharacterEditWindow_get_txtSubRace);
    registerGetter(L, "txtCharIdx", CharacterEditWindow_get_txtCharIdx);
    registerGetter(L, "importButton", CharacterEditWindow_get_importButton);
    registerGetter(L, "exportButton", CharacterEditWindow_get_exportButton);
    registerGetter(L, "panelTabs", CharacterEditWindow_get_panelTabs);
    registerGetter(L, "panelTabsView", CharacterEditWindow_get_panelTabsView);
    registerGetter(L, "btnPrevGender", CharacterEditWindow_get_btnPrevGender);
    registerGetter(L, "btnNextGender", CharacterEditWindow_get_btnNextGender);
    registerGetter(L, "btnPrevRace", CharacterEditWindow_get_btnPrevRace);
    registerGetter(L, "btnNextRace", CharacterEditWindow_get_btnNextRace);
    registerGetter(L, "btnPrevSubRace", CharacterEditWindow_get_btnPrevSubRace);
    registerGetter(L, "btnNextSubRace", CharacterEditWindow_get_btnNextSubRace);
    registerGetter(L, "btnReset", CharacterEditWindow_get_btnReset);
    registerGetter(L, "btnRandomiseAll", CharacterEditWindow_get_btnRandomiseAll);
    registerGetter(L, "btnRandomisePart", CharacterEditWindow_get_btnRandomisePart);
    registerGetter(L, "descriptionPanel", CharacterEditWindow_get_descriptionPanel);
    registerGetter(L, "descriptionPanelText", CharacterEditWindow_get_descriptionPanelText);
    registerGetter(L, "statsPanel", CharacterEditWindow_get_statsPanel);
    registerGetter(L, "statsDataPanel", CharacterEditWindow_get_statsDataPanel);
    registerGetter(L, "dialog", CharacterEditWindow_get_dialog);
    registerGetter(L, "isMidGame", CharacterEditWindow_get_isMidGame);
    registerGetter(L, "multipleCharactersChangedCheck", CharacterEditWindow_get_multipleCharactersChangedCheck);
    registerGetter(L, "characterEntityUpdated", CharacterEditWindow_get_characterEntityUpdated);
    registerGetter(L, "clothVisible", CharacterEditWindow_get_clothVisible);
    registerGetter(L, "appearanceData", CharacterEditWindow_get_appearanceData);
    registerGetter(L, "raceData", CharacterEditWindow_get_raceData);
    registerGetter(L, "currentCategory", CharacterEditWindow_get_currentCategory);
    registerGetter(L, "currentRaceGroupIndex", CharacterEditWindow_get_currentRaceGroupIndex);
    registerGetter(L, "currentSubRaceIndex", CharacterEditWindow_get_currentSubRaceIndex);
    registerGetter(L, "currentGender", CharacterEditWindow_get_currentGender);
    registerGetter(L, "currentRaceData", CharacterEditWindow_get_currentRaceData);
    registerGetter(L, "currentEditData", CharacterEditWindow_get_currentEditData);
    registerGetter(L, "character", CharacterEditWindow_get_character);
    registerGetter(L, "currentCharacterIdx", CharacterEditWindow_get_currentCharacterIdx);
    registerGetter(L, "currentAnimation", CharacterEditWindow_get_currentAnimation);
    registerGetter(L, "raceLimits", CharacterEditWindow_get_raceLimits);
    registerGetter(L, "showNamesOption", CharacterEditWindow_get_showNamesOption);
    registerGetter(L, "editorRootNode", CharacterEditWindow_get_editorRootNode);
    registerGetter(L, "characterPositionNode", CharacterEditWindow_get_characterPositionNode);
    registerGetter(L, "characterRotationNode", CharacterEditWindow_get_characterRotationNode);
    registerGetter(L, "workspace", CharacterEditWindow_get_workspace);
    registerGetter(L, "platform", CharacterEditWindow_get_platform);
    registerGetter(L, "requestUpdateLiveObject", CharacterEditWindow_get_requestUpdateLiveObject);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "statsDataPanel", CharacterEditWindow_set_statsDataPanel);
    registerSetter(L, "dialog", CharacterEditWindow_set_dialog);
    registerSetter(L, "isMidGame", CharacterEditWindow_set_isMidGame);
    registerSetter(L, "multipleCharactersChangedCheck", CharacterEditWindow_set_multipleCharactersChangedCheck);
    registerSetter(L, "characterEntityUpdated", CharacterEditWindow_set_characterEntityUpdated);
    registerSetter(L, "clothVisible", CharacterEditWindow_set_clothVisible);
    registerSetter(L, "appearanceData", CharacterEditWindow_set_appearanceData);
    registerSetter(L, "raceData", CharacterEditWindow_set_raceData);
    registerSetter(L, "currentCategory", CharacterEditWindow_set_currentCategory);
    registerSetter(L, "currentRaceGroupIndex", CharacterEditWindow_set_currentRaceGroupIndex);
    registerSetter(L, "currentSubRaceIndex", CharacterEditWindow_set_currentSubRaceIndex);
    registerSetter(L, "currentGender", CharacterEditWindow_set_currentGender);
    registerSetter(L, "character", CharacterEditWindow_set_character);
    registerSetter(L, "currentCharacterIdx", CharacterEditWindow_set_currentCharacterIdx);
    registerSetter(L, "showNamesOption", CharacterEditWindow_set_showNamesOption);
    registerSetter(L, "requestUpdateLiveObject", CharacterEditWindow_set_requestUpdateLiveObject);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, CharacterEditWindowBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua