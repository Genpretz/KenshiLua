#pragma once

#include "kenshi/gui/CharacterEditWindow.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CharacterEditWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CharacterEditWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int update(lua_State* L);
    static int loadData(lua_State* L);
    static int initCharacters(lua_State* L);
    static int updateRace(lua_State* L);
    static int updateCharacterPoses(lua_State* L);
    static int clearCharacterPoses(lua_State* L);
    static int updateCharacter(lua_State* L);
    static int showCharacter(lua_State* L);
    static int updateCurrentCategory(lua_State* L);
    static int loadImportedCharacter(lua_State* L);
    static int setClothesVisible(lua_State* L);
    static int confirmMessageCallback(lua_State* L);
    static int setupUI(lua_State* L);
    static int setUIEnabled(lua_State* L);
    static int refreshUI(lua_State* L);
    static int updateLiveObject(lua_State* L);
    static int refreshCharacterPoses(lua_State* L);
    static int exportMeshes(lua_State* L);
    static int getCurrentHeadName(lua_State* L);
    static int getCurrentAttachmentName(lua_State* L);
    static int setCurrentHeadName(lua_State* L);
    static int setCurrentAttachmentName(lua_State* L);
    static int nameChanged(lua_State* L);
    static int prevRace(lua_State* L);
    static int nextRace(lua_State* L);
    static int prevSubRace(lua_State* L);
    static int nextSubRace(lua_State* L);
    static int changeGender(lua_State* L);
    static int changeAppearanceData(lua_State* L);
    static int prevCharacter(lua_State* L);
    static int nextCharacter(lua_State* L);
    static int changeCategory(lua_State* L);
    static int resetAppearance(lua_State* L);
    static int randomiseAll(lua_State* L);
    static int randomisePart(lua_State* L);
    static int importCharacter(lua_State* L);
    static int exportCharacter(lua_State* L);
    static int toggleClothes(lua_State* L);
    static int confirmButton(lua_State* L);
};
}