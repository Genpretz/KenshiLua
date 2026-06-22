#include "pch.h"
#include "Bindings/CharacterEditWindowBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/CharacterEditWindow.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static CharacterEditWindow* getS(lua_State* L, int idx)
{
    return checkObject<CharacterEditWindow>(L, idx, CharacterEditWindowBinding::getMetatableName());
}

int CharacterEditWindowBinding::gc(lua_State* L) { return noopGc(L); }

int CharacterEditWindowBinding::tostring(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int CharacterEditWindowBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, CharacterEditWindowBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    CharacterEditWindow* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO CharacterEditCamera* camera; unsupported __index type from header line 90
    if (strcmp(key, "txtName") == 0) { lua_pushinteger(L, (lua_Integer)s->txtName); return 1; }
    if (strcmp(key, "txtGender") == 0) { lua_pushinteger(L, (lua_Integer)s->txtGender); return 1; }
    if (strcmp(key, "txtRace") == 0) { lua_pushinteger(L, (lua_Integer)s->txtRace); return 1; }
    if (strcmp(key, "txtSubRace") == 0) { lua_pushinteger(L, (lua_Integer)s->txtSubRace); return 1; }
    if (strcmp(key, "txtCharIdx") == 0) { lua_pushinteger(L, (lua_Integer)s->txtCharIdx); return 1; }
    if (strcmp(key, "importButton") == 0) { lua_pushinteger(L, (lua_Integer)s->importButton); return 1; }
    if (strcmp(key, "exportButton") == 0) { lua_pushinteger(L, (lua_Integer)s->exportButton); return 1; }
    // TODO ogre_unordered_map<AppearanceManager::DataCategory::Enum, MyGUI::Button*>::type buttonsCategories; unsupported __index type from header line 98
    if (strcmp(key, "panelTabs") == 0) { lua_pushinteger(L, (lua_Integer)s->panelTabs); return 1; }
    if (strcmp(key, "panelTabsView") == 0) { lua_pushinteger(L, (lua_Integer)s->panelTabsView); return 1; }
    if (strcmp(key, "btnPrevGender") == 0) { lua_pushinteger(L, (lua_Integer)s->btnPrevGender); return 1; }
    if (strcmp(key, "btnNextGender") == 0) { lua_pushinteger(L, (lua_Integer)s->btnNextGender); return 1; }
    if (strcmp(key, "btnPrevRace") == 0) { lua_pushinteger(L, (lua_Integer)s->btnPrevRace); return 1; }
    if (strcmp(key, "btnNextRace") == 0) { lua_pushinteger(L, (lua_Integer)s->btnNextRace); return 1; }
    if (strcmp(key, "btnPrevSubRace") == 0) { lua_pushinteger(L, (lua_Integer)s->btnPrevSubRace); return 1; }
    if (strcmp(key, "btnNextSubRace") == 0) { lua_pushinteger(L, (lua_Integer)s->btnNextSubRace); return 1; }
    // TODO MyGUI::types::TSize<int> sliderSize; unsupported __index type from header line 107
    // TODO MyGUI::types::TSize<int> multiSliderSize; unsupported __index type from header line 108
    // TODO MyGUI::types::TSize<int> listScrollBarSize; unsupported __index type from header line 109
    if (strcmp(key, "btnReset") == 0) { lua_pushinteger(L, (lua_Integer)s->btnReset); return 1; }
    if (strcmp(key, "btnRandomiseAll") == 0) { lua_pushinteger(L, (lua_Integer)s->btnRandomiseAll); return 1; }
    if (strcmp(key, "btnRandomisePart") == 0) { lua_pushinteger(L, (lua_Integer)s->btnRandomisePart); return 1; }
    if (strcmp(key, "descriptionPanel") == 0) { lua_pushinteger(L, (lua_Integer)s->descriptionPanel); return 1; }
    if (strcmp(key, "descriptionPanelText") == 0) { lua_pushinteger(L, (lua_Integer)s->descriptionPanelText); return 1; }
    if (strcmp(key, "statsPanel") == 0) { lua_pushinteger(L, (lua_Integer)s->statsPanel); return 1; }
    // TODO DatapanelGUI* statsDataPanel; unsupported __index type from header line 116
    // TODO OpenSaveFileDialog* dialog; unsupported __index type from header line 117
    if (strcmp(key, "isMidGame") == 0) { lua_pushboolean(L, s->isMidGame ? 1 : 0); return 1; }
    if (strcmp(key, "multipleCharactersChangedCheck") == 0) { lua_pushinteger(L, s->multipleCharactersChangedCheck); return 1; }
    if (strcmp(key, "characterEntityUpdated") == 0) { lua_pushboolean(L, s->characterEntityUpdated ? 1 : 0); return 1; }
    if (strcmp(key, "clothVisible") == 0) { lua_pushboolean(L, s->clothVisible ? 1 : 0); return 1; }
    // TODO GameDataCopyStandalone* appearanceData; unsupported __index type from header line 122
    if (strcmp(key, "raceData") == 0) { return pushObject<GameData>(L, s->raceData, GameDataBinding::getMetatableName()); }
    if (strcmp(key, "currentCategory") == 0) { lua_pushinteger(L, (lua_Integer)s->currentCategory); return 1; }
    if (strcmp(key, "currentRaceGroupIndex") == 0) { lua_pushinteger(L, s->currentRaceGroupIndex); return 1; }
    if (strcmp(key, "currentSubRaceIndex") == 0) { lua_pushinteger(L, s->currentSubRaceIndex); return 1; }
    if (strcmp(key, "currentGender") == 0) { lua_pushinteger(L, (lua_Integer)s->currentGender); return 1; }
    // TODO ogre_unordered_map<AppearanceManager::Gender::Enum, AppearanceManager::AppearanceData>::type* currentRaceData; unsupported __index type from header line 128
    if (strcmp(key, "currentEditData") == 0) { lua_pushinteger(L, (lua_Integer)s->currentEditData); return 1; }
    // TODO Ogre::FastArray<AnimationData*> idleAnimations; unsupported __index type from header line 130
    // TODO Ogre::FastArray<Character*> characters; unsupported __index type from header line 131
    if (strcmp(key, "character") == 0) { return pushObject<Character>(L, s->character, CharacterBinding::getMetatableName()); }
    if (strcmp(key, "currentCharacterIdx") == 0) { lua_pushinteger(L, s->currentCharacterIdx); return 1; }
    // TODO boost::unordered::unordered_map<Character*, boost::unordered::unordered_map<std::pair<GameData*, enum AppearanceManager::Gender::Enum>, GameDataCopyStandalone*, boost::hash<std::pair<GameData*, enum AppearanceManager::Gender::Enum> >, std::equal_to<std::pair<GameData*, enum AppearanceManager::Gender::Enum> >, Ogre::STLAllocator<std::pair<std::pair<GameData*, enum AppearanceManager::Gender::Enum> const, GameDataCopyStandalone*>, Ogre::GeneralAllocPolicy > >, boost::hash<Character*>, std::equal_to<Character*>, Ogre::STLAllocator<std::pair<Character*const, boost::unordered::unordered_map<std::pair<GameData*, enum AppearanceManager::Gender::Enum>, GameDataCopyStandalone*, boost::hash<std::pair<GameData*, enum AppearanceManager::Gender::Enum> >, std::equal_to<std::pair<GameData*, enum AppearanceManager::Gender::Enum> >, Ogre::STLAllocator<std::pair<std::pair<GameData*, enum AppearanceManager::Gender::Enum> const, GameDataCopyStandalone*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > > charactersAppearanceByRace; unsupported __index type from header line 134
    // TODO AnimationData* currentAnimation; unsupported __index type from header line 135
    // TODO const Ogre::vector<GameDataReference>::type* raceLimits; unsupported __index type from header line 136
    // TODO boost::unordered::unordered_map<RaceGroupData*, Ogre::FastArray<GameData*>, boost::hash<RaceGroupData*>, std::equal_to<RaceGroupData*>, Ogre::STLAllocator<std::pair<RaceGroupData*const, Ogre::FastArray<GameData*> >, Ogre::GeneralAllocPolicy > > races; unsupported __index type from header line 137
    // TODO Ogre::FastArray<RaceGroupData*> racesGroups; unsupported __index type from header line 138
    // TODO boost::unordered::unordered_map<GameData*, ogre_unordered_map<AppearanceManager::Gender::Enum, AppearanceManager::AppearanceData>::type, boost::hash<GameData*>, std::equal_to<GameData*>, Ogre::STLAllocator<std::pair<GameData*const, ogre_unordered_map<AppearanceManager::Gender::Enum, AppearanceManager::AppearanceData>::type >, Ogre::GeneralAllocPolicy > > raceAppearanceData; unsupported __index type from header line 139
    // TODO boost::unordered::unordered_map<std::string, Ogre::Pose*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Pose*>, Ogre::GeneralAllocPolicy > > poses; unsupported __index type from header line 140
    // TODO boost::unordered::unordered_map<Character*, boost::unordered::unordered_map<std::string, float, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::GeneralAllocPolicy > >, boost::hash<Character*>, std::equal_to<Character*>, Ogre::STLAllocator<std::pair<Character*const, boost::unordered::unordered_map<std::string, float, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > > posesCharactersValues; unsupported __index type from header line 141
    if (strcmp(key, "showNamesOption") == 0) { lua_pushboolean(L, s->showNamesOption ? 1 : 0); return 1; }
    // TODO Ogre::FastArray<Ogre::Vector3> initialPositions; unsupported __index type from header line 143
    // TODO Ogre::SceneNode* editorRootNode; unsupported __index type from header line 144
    // TODO Ogre::SceneNode* characterPositionNode; unsupported __index type from header line 145
    // TODO Ogre::SceneNode* characterRotationNode; unsupported __index type from header line 146
    // TODO Ogre::CompositorWorkspace* workspace; unsupported __index type from header line 147
    // TODO Ogre::Entity* platform; unsupported __index type from header line 148
    if (strcmp(key, "requestUpdateLiveObject") == 0) { lua_pushboolean(L, s->requestUpdateLiveObject ? 1 : 0); return 1; }

    lua_pushnil(L);
    return 1;
}

int CharacterEditWindowBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    // TODO CharacterEditCamera* camera; unsupported __newindex type from header line 90
    // TODO MyGUI::EditBox* txtName; unsupported __newindex type from header line 91
    // TODO MyGUI::TextBox* txtGender; unsupported __newindex type from header line 92
    // TODO MyGUI::TextBox* txtRace; unsupported __newindex type from header line 93
    // TODO MyGUI::TextBox* txtSubRace; unsupported __newindex type from header line 94
    // TODO MyGUI::TextBox* txtCharIdx; unsupported __newindex type from header line 95
    // TODO MyGUI::Button* importButton; unsupported __newindex type from header line 96
    // TODO MyGUI::Button* exportButton; unsupported __newindex type from header line 97
    // TODO ogre_unordered_map<AppearanceManager::DataCategory::Enum, MyGUI::Button*>::type buttonsCategories; unsupported __newindex type from header line 98
    // TODO MyGUI::Widget* panelTabs; unsupported __newindex type from header line 99
    // TODO MyGUI::ScrollView* panelTabsView; unsupported __newindex type from header line 100
    // TODO MyGUI::Button* btnPrevGender; unsupported __newindex type from header line 101
    // TODO MyGUI::Button* btnNextGender; unsupported __newindex type from header line 102
    // TODO MyGUI::Button* btnPrevRace; unsupported __newindex type from header line 103
    // TODO MyGUI::Button* btnNextRace; unsupported __newindex type from header line 104
    // TODO MyGUI::Button* btnPrevSubRace; unsupported __newindex type from header line 105
    // TODO MyGUI::Button* btnNextSubRace; unsupported __newindex type from header line 106
    // TODO MyGUI::types::TSize<int> sliderSize; unsupported __newindex type from header line 107
    // TODO MyGUI::types::TSize<int> multiSliderSize; unsupported __newindex type from header line 108
    // TODO MyGUI::types::TSize<int> listScrollBarSize; unsupported __newindex type from header line 109
    // TODO MyGUI::Button* btnReset; unsupported __newindex type from header line 110
    // TODO MyGUI::Button* btnRandomiseAll; unsupported __newindex type from header line 111
    // TODO MyGUI::Button* btnRandomisePart; unsupported __newindex type from header line 112
    // TODO MyGUI::Widget* descriptionPanel; unsupported __newindex type from header line 113
    // TODO MyGUI::EditBox* descriptionPanelText; unsupported __newindex type from header line 114
    // TODO MyGUI::Widget* statsPanel; unsupported __newindex type from header line 115
    // TODO DatapanelGUI* statsDataPanel; unsupported __newindex type from header line 116
    // TODO OpenSaveFileDialog* dialog; unsupported __newindex type from header line 117
    if (strcmp(key, "isMidGame") == 0) { s->isMidGame = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "multipleCharactersChangedCheck") == 0) { s->multipleCharactersChangedCheck = (unsigned int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "characterEntityUpdated") == 0) { s->characterEntityUpdated = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "clothVisible") == 0) { s->clothVisible = lua_toboolean(L, 3) != 0; return 0; }
    // TODO GameDataCopyStandalone* appearanceData; unsupported __newindex type from header line 122
    // TODO GameData* raceData; unsupported __newindex type from header line 123
    if (strcmp(key, "currentCategory") == 0) { s->currentCategory = (AppearanceManager::DataCategory)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "currentRaceGroupIndex") == 0) { s->currentRaceGroupIndex = (short)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "currentSubRaceIndex") == 0) { s->currentSubRaceIndex = (short)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "currentGender") == 0) { s->currentGender = (AppearanceManager::Gender)luaL_checkinteger(L, 3); return 0; }
    // TODO ogre_unordered_map<AppearanceManager::Gender::Enum, AppearanceManager::AppearanceData>::type* currentRaceData; unsupported __newindex type from header line 128
    // TODO AppearanceManager::AppearanceData* currentEditData; unsupported __newindex type from header line 129
    // TODO Ogre::FastArray<AnimationData*> idleAnimations; unsupported __newindex type from header line 130
    // TODO Ogre::FastArray<Character*> characters; unsupported __newindex type from header line 131
    // TODO Character* character; unsupported __newindex type from header line 132
    if (strcmp(key, "currentCharacterIdx") == 0) { s->currentCharacterIdx = (unsigned short)luaL_checkinteger(L, 3); return 0; }
    // TODO boost::unordered::unordered_map<Character*, boost::unordered::unordered_map<std::pair<GameData*, enum AppearanceManager::Gender::Enum>, GameDataCopyStandalone*, boost::hash<std::pair<GameData*, enum AppearanceManager::Gender::Enum> >, std::equal_to<std::pair<GameData*, enum AppearanceManager::Gender::Enum> >, Ogre::STLAllocator<std::pair<std::pair<GameData*, enum AppearanceManager::Gender::Enum> const, GameDataCopyStandalone*>, Ogre::GeneralAllocPolicy > >, boost::hash<Character*>, std::equal_to<Character*>, Ogre::STLAllocator<std::pair<Character*const, boost::unordered::unordered_map<std::pair<GameData*, enum AppearanceManager::Gender::Enum>, GameDataCopyStandalone*, boost::hash<std::pair<GameData*, enum AppearanceManager::Gender::Enum> >, std::equal_to<std::pair<GameData*, enum AppearanceManager::Gender::Enum> >, Ogre::STLAllocator<std::pair<std::pair<GameData*, enum AppearanceManager::Gender::Enum> const, GameDataCopyStandalone*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > > charactersAppearanceByRace; unsupported __newindex type from header line 134
    // TODO AnimationData* currentAnimation; unsupported __newindex type from header line 135
    // TODO const Ogre::vector<GameDataReference>::type* raceLimits; unsupported __newindex type from header line 136
    // TODO boost::unordered::unordered_map<RaceGroupData*, Ogre::FastArray<GameData*>, boost::hash<RaceGroupData*>, std::equal_to<RaceGroupData*>, Ogre::STLAllocator<std::pair<RaceGroupData*const, Ogre::FastArray<GameData*> >, Ogre::GeneralAllocPolicy > > races; unsupported __newindex type from header line 137
    // TODO Ogre::FastArray<RaceGroupData*> racesGroups; unsupported __newindex type from header line 138
    // TODO boost::unordered::unordered_map<GameData*, ogre_unordered_map<AppearanceManager::Gender::Enum, AppearanceManager::AppearanceData>::type, boost::hash<GameData*>, std::equal_to<GameData*>, Ogre::STLAllocator<std::pair<GameData*const, ogre_unordered_map<AppearanceManager::Gender::Enum, AppearanceManager::AppearanceData>::type >, Ogre::GeneralAllocPolicy > > raceAppearanceData; unsupported __newindex type from header line 139
    // TODO boost::unordered::unordered_map<std::string, Ogre::Pose*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Pose*>, Ogre::GeneralAllocPolicy > > poses; unsupported __newindex type from header line 140
    // TODO boost::unordered::unordered_map<Character*, boost::unordered::unordered_map<std::string, float, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::GeneralAllocPolicy > >, boost::hash<Character*>, std::equal_to<Character*>, Ogre::STLAllocator<std::pair<Character*const, boost::unordered::unordered_map<std::string, float, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > > posesCharactersValues; unsupported __newindex type from header line 141
    if (strcmp(key, "showNamesOption") == 0) { s->showNamesOption = lua_toboolean(L, 3) != 0; return 0; }
    // TODO Ogre::FastArray<Ogre::Vector3> initialPositions; unsupported __newindex type from header line 143
    // TODO Ogre::SceneNode* editorRootNode; unsupported __newindex type from header line 144
    // TODO Ogre::SceneNode* characterPositionNode; unsupported __newindex type from header line 145
    // TODO Ogre::SceneNode* characterRotationNode; unsupported __newindex type from header line 146
    // TODO Ogre::CompositorWorkspace* workspace; unsupported __newindex type from header line 147
    // TODO Ogre::Entity* platform; unsupported __newindex type from header line 148
    if (strcmp(key, "requestUpdateLiveObject") == 0) { s->requestUpdateLiveObject = lua_toboolean(L, 3) != 0; return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int CharacterEditWindowBinding::_DESTRUCTOR(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    s->_DESTRUCTOR();
    return 0;
}

int CharacterEditWindowBinding::update(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    s->update();
    return 0;
}

int CharacterEditWindowBinding::loadData(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    s->loadData();
    return 0;
}

int CharacterEditWindowBinding::initCharacters(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    s->initCharacters();
    return 0;
}

int CharacterEditWindowBinding::updateRace(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    s->updateRace();
    return 0;
}

int CharacterEditWindowBinding::updateCharacterPoses(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    s->updateCharacterPoses();
    return 0;
}

int CharacterEditWindowBinding::clearCharacterPoses(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    s->clearCharacterPoses();
    return 0;
}

int CharacterEditWindowBinding::updateCharacter(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    s->updateCharacter();
    return 0;
}

int CharacterEditWindowBinding::updateCurrentCategory(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    s->updateCurrentCategory();
    return 0;
}

int CharacterEditWindowBinding::confirmMessageCallback(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    int _btn = (int)luaL_checkinteger(L, 2);
    s->confirmMessageCallback(_btn);
    return 0;
}

int CharacterEditWindowBinding::setupUI(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    s->setupUI();
    return 0;
}

int CharacterEditWindowBinding::setUIEnabled(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    bool enabled = lua_toboolean(L, 2) != 0;
    s->setUIEnabled(enabled);
    return 0;
}

int CharacterEditWindowBinding::refreshUI(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    s->refreshUI();
    return 0;
}

int CharacterEditWindowBinding::updateLiveObject(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    s->updateLiveObject();
    return 0;
}

int CharacterEditWindowBinding::refreshCharacterPoses(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    s->refreshCharacterPoses();
    return 0;
}

int CharacterEditWindowBinding::exportMeshes(lua_State* L)
{
    CharacterEditWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterEditWindow is nil");

    s->exportMeshes();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 38: CharacterEditWindow* _CONSTRUCTOR(...) - unsupported return type
  line 44: void nameChanged(...) - pointer arg
  line 45: void prevRace(...) - pointer arg
  line 46: void nextRace(...) - pointer arg
  line 47: void prevSubRace(...) - pointer arg
  line 48: void nextSubRace(...) - pointer arg
  line 50: void changeGender(...) - pointer arg
  line 51: void changeAppearanceData(...) - unsupported arg type
  line 54: void prevCharacter(...) - pointer arg
  line 55: void nextCharacter(...) - pointer arg
  line 57: void showCharacter(...) - unsupported arg type
  line 58: void changeCategory(...) - pointer arg
  line 60: void resetAppearance(...) - pointer arg
  line 61: void randomiseAll(...) - pointer arg
  line 62: void randomisePart(...) - pointer arg
  line 63: void importCharacter(...) - pointer arg
  line 64: void exportCharacter(...) - pointer arg
  line 65: void loadImportedCharacter(...) - unsupported arg type
  line 66: void toggleClothes(...) - pointer arg
  line 67: void setClothesVisible(...) - unsupported arg type
  line 68: void updateAppearanceSlider(...) - pointer arg
  line 69: void updateAppearanceSliderPose(...) - pointer arg
  line 70: void updateAppearanceSliderVector(...) - pointer arg
  line 71: void updateAppearanceList(...) - pointer arg
  line 72: void updateAppearanceMultiSlider(...) - pointer arg
  line 73: void updateAnimationIdle(...) - pointer arg
  line 74: void confirmButton(...) - pointer arg
  line 82: const std::string& getCurrentHeadName(...) - reference return type
  line 83: const std::string& getCurrentAttachmentName(...) - reference return type
  line 84: void setCurrentHeadName(...) - unsupported arg type
  line 85: void setCurrentAttachmentName(...) - unsupported arg type
  line 86: Ogre::Entity* getCharacterEntity(...) - unsupported return type
*/

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
        { "updateCurrentCategory", CharacterEditWindowBinding::updateCurrentCategory },
        { "confirmMessageCallback", CharacterEditWindowBinding::confirmMessageCallback },
        { "setupUI", CharacterEditWindowBinding::setupUI },
        { "setUIEnabled", CharacterEditWindowBinding::setUIEnabled },
        { "refreshUI", CharacterEditWindowBinding::refreshUI },
        { "updateLiveObject", CharacterEditWindowBinding::updateLiveObject },
        { "refreshCharacterPoses", CharacterEditWindowBinding::refreshCharacterPoses },
        { "exportMeshes", CharacterEditWindowBinding::exportMeshes },
        { 0, 0 }
    };
    registerClass(L, CharacterEditWindowBinding::getMetatableName(), meta, methods, CharacterEditWindowBinding::index, CharacterEditWindowBinding::newindex);
}

} // namespace KenshiLua