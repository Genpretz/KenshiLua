#pragma once

#include <string>

extern "C" {
#include <lua.h>
}

class PlayerInterface;

namespace KenshiLua
{

    class PlayerInterfaceBinding
    {
    public:
        static const char* getMetatableName() { return "KenshiLua.PlayerInterface"; }

        static void registerBinding(lua_State* L);

        static int gc(lua_State* L);
        static int tostring(lua_State* L);
        static int index(lua_State* L);
        static int newindex(lua_State* L);

        static int getFaction(lua_State* L);
        static int setFaction(lua_State* L);

        static int getCurrentPlatoon(lua_State* L);
        static int setCurrentPlatoon(lua_State* L);
        static int getCurrentActivePlatoon(lua_State* L);
        static int recruit(lua_State* L);
        static int setCharacterEditMode(lua_State* L);
        static int triggerAreaArrivalDialogue(lua_State* L);
        static int getCharacterEditMode(lua_State* L);
        static int selectObject(lua_State* L);
        static int isTrackingCharacter(lua_State* L);

        static int getAnyPlayerCharacter(lua_State* L);
        static int isBuildMode(lua_State* L);
        static int unselectAll(lua_State* L);
        static int selectPlayerCharacter(lua_State* L);
        static int selectPlayerCharacterByIndex(lua_State* L);
        static int getNearestSelectedCharacterTo(lua_State* L);
        static int getNearestCharacterTo(lua_State* L);
        static int unselectPlayerCharacter(lua_State* L);
        static int startTrackCharacter(lua_State* L);
        static int stopTrackCharacter(lua_State* L);
        static int isEnemy(lua_State* L);
        static int getSelectedCharacterHandle(lua_State* L);
        static int focusCamera(lua_State* L);
        static int focusCameraSelectedCharacter(lua_State* L);
        static int manuallyOrientCamera(lua_State* L);
        static int getDistanceFromCamera(lua_State* L);
        static int getCameraCenter(lua_State* L);
        static int toggleLevelEditorOnSelectedTown(lua_State* L);

        static int newPlayerTaskSelectedCharacters(lua_State* L);
        static int getPlayerTaskProbability(lua_State* L);
        static int addOrderSelectedCharacters(lua_State* L);
        static int addJobSelectedCharacters(lua_State* L);
        static int removeJobSelectedCharacters(lua_State* L);
        static int removePermaJobSelectedCharacters(lua_State* L);
        static int isFactionKnown(lua_State* L);
        static int encounterFaction(lua_State* L);
        static int pickupItem(lua_State* L);
        static int characterSelected(lua_State* L);
        static int itemSelected(lua_State* L);
        static int buildingSelected(lua_State* L);
        static int playerMove(lua_State* L);
        static int _isPlayerCharacter(lua_State* L);
    };

} // namespace KenshiLua