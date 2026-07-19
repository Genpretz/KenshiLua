#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class PlayerInterfaceBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.PlayerInterface"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int getCamera(lua_State* L);
    static int clearAndReset(lua_State* L);
    static int getFaction(lua_State* L);
    static int getCurrentPlatoon(lua_State* L);
    static int getCurrentActivePlatoon(lua_State* L);
    static int update(lua_State* L);
    static int updateUT(lua_State* L);
    static int isBuildMode(lua_State* L);
    static int setCharacterEditMode(lua_State* L);
    static int getCharacterEditMode(lua_State* L);
    static int unselectAll(lua_State* L);
    static int selectAll(lua_State* L);
    static int selectPlayerCharacter(lua_State* L);
    static int getCameraCenter(lua_State* L);
    static int getDistanceFromCamera(lua_State* L);
    static int getSquaredDistanceFromCamera(lua_State* L);
    static int stopTrackCharacter(lua_State* L);
    static int isTrackingCharacter(lua_State* L);
    static int focusCamera(lua_State* L);
    static int manuallyOrientCamera(lua_State* L);
    static int focusCameraSelectedCharacter(lua_State* L);
    static int toggleLevelEditorOnSelectedTown(lua_State* L);
    static int isLevelEditMode(lua_State* L);
    static int isObjectPlacementMode(lua_State* L);
    static int setOrderSelectedCharacters(lua_State* L);
    static int getCurrentFloor(lua_State* L);
    static int setCurrentFloor(lua_State* L);
    static int getNearestSelectedCharacterTo(lua_State* L);
    static int getNearestCharacterTo(lua_State* L);
    static int removeJobSelectedCharacters(lua_State* L);
    static int removePermaJobSelectedCharacters(lua_State* L);
    static int selectedCharactersUnconcious(lua_State* L);
    static int selectedCharactersLayingLow(lua_State* L);
    static int useSpeedGroup(lua_State* L);
    static int assignSpeedGroup(lua_State* L);
    static int cycleSquad(lua_State* L);
    static int cycleCharacter(lua_State* L);
    static int stopCharactersMovement(lua_State* L);
    static int getAnyPlayerCharacter(lua_State* L);
    static int isOrderValidForSelection(lua_State* L);
    static int setVisibilityForReflections(lua_State* L);
    static int resetFloorsVisibility(lua_State* L);
    static int setFloorsVisibility(lua_State* L);
    static int clearSelection(lua_State* L);
    static int mouseScan(lua_State* L);
    static int playerSetup(lua_State* L);
    static int factoryObjectCreatedCallback(lua_State* L);
    static int _NV_factoryObjectCreatedCallback(lua_State* L);
    static int setFaction(lua_State* L);
    static int setCurrentPlatoon(lua_State* L);
    static int recruit(lua_State* L);
    static int createSquad(lua_State* L);
    static int getDeadSquad(lua_State* L);
    static int getDeadSquadHandle(lua_State* L);
    static int activateObjectPlacementMode(lua_State* L);
    static int activateCharacterEditMode(lua_State* L);
    static int triggerAreaArrivalDialogue(lua_State* L);
    static int selectObject(lua_State* L);
    static int _selectPlayerCharacter(lua_State* L);
    static int activateSelection(lua_State* L);
    static int startTrackCharacter(lua_State* L);
    static int getLevelEditor(lua_State* L);
    static int objectSelected(lua_State* L);
    static int toggleObjectSelected(lua_State* L);
    static int isObjectSelected(lua_State* L);
    static int unselectPlayerCharacter(lua_State* L);
    static int updatePlayerSelection(lua_State* L);
    static int getAllSelectedObjects(lua_State* L);
    static int newPlayerTaskSelectedCharacters(lua_State* L);
    static int getPlayerTaskProbability(lua_State* L);
    static int addOrderSelectedCharacters(lua_State* L);
    static int addJobSelectedCharacters(lua_State* L);
    static int isEnemy(lua_State* L);
    static int isFactionKnown(lua_State* L);
    static int encounterFaction(lua_State* L);
    static int pickupItem(lua_State* L);
    static int getAllPlayerCharacters(lua_State* L);
    static int serialise(lua_State* L);
    static int loadFromSerialise(lua_State* L);
    static int getInteriorsVisible(lua_State* L);
    static int updateFloorVisibility(lua_State* L);
    static int addTaskNearestSelectedCharacter(lua_State* L);
    static int updateLastMoveWaypointSelectedCharacters(lua_State* L);
    static int playerControl(lua_State* L);
    static int characterSelected(lua_State* L);
    static int itemSelected(lua_State* L);
    static int buildingSelected(lua_State* L);
    static int playerMove(lua_State* L);
    static int _isPlayerCharacter(lua_State* L);
};
}
