#include "pch.h"
#include "kenshi\PlayerInterface.h"
#include "PlayerInterfaceBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CameraClassBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/RootObjectContainerBinding.h"
#include "Bindings/HandBinding.h"
#include "kenshi\CameraClass.h"
#include "CameraClassBinding.h"
#include "kenshi\RootObject.h"
#include "RootObjectBinding.h"
#include "RootObjectContainerBinding.h"
#include "kenshi\Platoon.h"
#include "PlatoonBinding.h"
#include "FactionBinding.h"

namespace KenshiLua
{

static PlayerInterface* getB(lua_State* L, int idx)
{
    return checkObject<PlayerInterface>(L, idx, PlayerInterfaceBinding::getMetatableName());
}

// --- Getters for PlayerInterface ---
static int PlayerInterface_get_factionName(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushstring(L, b->factionName.c_str());
    return 1;
}

static int PlayerInterface_get_camera(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<CameraClass>(L, b->camera, CameraClassBinding::getMetatableName());
}

static int PlayerInterface_get_technology(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    // TODO: Unsupported type for technology (Research*)
    return luaL_error(L, "Unsupported property 'technology' (type: Research*)");
}

static int PlayerInterface_get_selectedObjectsChangedThisFrame(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, b->selectedObjectsChangedThisFrame ? 1 : 0);
    return 1;
}

static int PlayerInterface_get_contextMenu(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    // TODO: Unsupported type for contextMenu (ContextMenu)
    return luaL_error(L, "Unsupported property 'contextMenu' (type: ContextMenu)");
}

static int PlayerInterface_get_selectBox(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    // TODO: Unsupported type for selectBox (SelectionBox)
    return luaL_error(L, "Unsupported property 'selectBox' (type: SelectionBox)");
}

static int PlayerInterface_get_moveMarker(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    // TODO: Unsupported type for moveMarker (MoveMarker*)
    return luaL_error(L, "Unsupported property 'moveMarker' (type: MoveMarker*)");
}

static int PlayerInterface_get_selectedCharacter(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return handBinding::push(L, b->selectedCharacter);
}

static int PlayerInterface_get_aiOptions(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    // TODO: Unsupported type for aiOptions (PlayerInterface::AIOptions)
    return luaL_error(L, "Unsupported property 'aiOptions' (type: PlayerInterface::AIOptions)");
}

static int PlayerInterface_get_zonesVisibilities(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    // TODO: Unsupported type for zonesVisibilities (ogre_unordered_map<ZoneMap*, unsigned char>::type)
    return luaL_error(L, "Unsupported property 'zonesVisibilities' (type: ogre_unordered_map<ZoneMap*, unsigned char>::type)");
}

static int PlayerInterface_get_townsActive(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    // TODO: Unsupported type for townsActive (ogre_unordered_set<TownBase*>::type)
    return luaL_error(L, "Unsupported property 'townsActive' (type: ogre_unordered_set<TownBase*>::type)");
}

static int PlayerInterface_get_interiorsVisible(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    // TODO: Unsupported type for interiorsVisible (ogre_unordered_set<hand>::type)
    return luaL_error(L, "Unsupported property 'interiorsVisible' (type: ogre_unordered_set<hand>::type)");
}

static int PlayerInterface_get_interiorsVisibleHash(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushinteger(L, b->interiorsVisibleHash);
    return 1;
}

static int PlayerInterface_get_currentFloor(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushinteger(L, b->currentFloor);
    return 1;
}

static int PlayerInterface_get_currentMouseTask(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushinteger(L, (lua_Integer)b->currentMouseTask);
    return 1;
}

static int PlayerInterface_get_mouseTaskTypeRestriction(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushinteger(L, (lua_Integer)b->mouseTaskTypeRestriction);
    return 1;
}

static int PlayerInterface_get_mouseRightTargetSet(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, b->mouseRightTargetSet ? 1 : 0);
    return 1;
}

static int PlayerInterface_get_mouseRightTarget(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<RootObject>(L, b->mouseRightTarget, RootObjectBinding::getMetatableName());
}

static int PlayerInterface_get_rmouseTimer(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushnumber(L, b->rmouseTimer);
    return 1;
}

static int PlayerInterface_get_selectedCharacters(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    // TODO: Unsupported type for selectedCharacters (ogre_unordered_set<hand>::type)
    return luaL_error(L, "Unsupported property 'selectedCharacters' (type: ogre_unordered_set<hand>::type)");
}

static int PlayerInterface_get_selectedObject(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return handBinding::push(L, b->selectedObject);
}

static int PlayerInterface_get_onlyAnimalsSelected(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, b->onlyAnimalsSelected ? 1 : 0);
    return 1;
}

static int PlayerInterface_get_selectedLoadedLeft(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushinteger(L, b->selectedLoadedLeft);
    return 1;
}

static int PlayerInterface_get_trackedCharacterHandle(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return handBinding::push(L, b->trackedCharacterHandle);
}

static int PlayerInterface_get_trackedCharacterFloor(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushinteger(L, b->trackedCharacterFloor);
    return 1;
}

static int PlayerInterface_get_levelEditor(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    // TODO: Unsupported type for levelEditor (LevelEditor*)
    return luaL_error(L, "Unsupported property 'levelEditor' (type: LevelEditor*)");
}

static int PlayerInterface_get_participant(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<Faction>(L, b->participant, FactionBinding::getMetatableName());
}

static int PlayerInterface_get_currentPlatoon(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<Platoon>(L, b->currentPlatoon, PlatoonBinding::getMetatableName());
}

static int PlayerInterface_get_playerCharacters(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    // TODO: Unsupported type for playerCharacters (lektor<Character*>)
    return luaL_error(L, "Unsupported property 'playerCharacters' (type: lektor<Character*>)");
}

static int PlayerInterface_get_deadPlayerSquad(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return handBinding::push(L, b->deadPlayerSquad);
}

static int PlayerInterface_get_placementObject(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    // TODO: Unsupported type for placementObject (PlacementObject*)
    return luaL_error(L, "Unsupported property 'placementObject' (type: PlacementObject*)");
}

static int PlayerInterface_get_characterEditorMode(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, b->characterEditorMode ? 1 : 0);
    return 1;
}

static int PlayerInterface_get_mLeftUp(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, b->mLeftUp ? 1 : 0);
    return 1;
}

static int PlayerInterface_get_mLeftDown(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, b->mLeftDown ? 1 : 0);
    return 1;
}

static int PlayerInterface_get_mRightUp(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, b->mRightUp ? 1 : 0);
    return 1;
}

static int PlayerInterface_get_mRightDown(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, b->mRightDown ? 1 : 0);
    return 1;
}

// --- Setters for PlayerInterface ---
static int PlayerInterface_set_factionName(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->factionName = luaL_checkstring(L, 2);
    return 0;
}

static int PlayerInterface_set_camera(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for camera");
}

static int PlayerInterface_set_technology(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for technology");
}

static int PlayerInterface_set_selectedObjectsChangedThisFrame(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->selectedObjectsChangedThisFrame = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlayerInterface_set_contextMenu(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for contextMenu");
}

static int PlayerInterface_set_selectBox(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for selectBox");
}

static int PlayerInterface_set_moveMarker(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for moveMarker");
}

static int PlayerInterface_set_selectedCharacter(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!val) return luaL_error(L, "hand is nil");
    b->selectedCharacter = *val;
    return 0;
}

static int PlayerInterface_set_aiOptions(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for aiOptions");
}

static int PlayerInterface_set_zonesVisibilities(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for zonesVisibilities");
}

static int PlayerInterface_set_townsActive(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for townsActive");
}

static int PlayerInterface_set_interiorsVisible(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for interiorsVisible");
}

static int PlayerInterface_set_interiorsVisibleHash(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->interiorsVisibleHash = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int PlayerInterface_set_currentFloor(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->currentFloor = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int PlayerInterface_set_currentMouseTask(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->currentMouseTask = (TaskType)luaL_checkinteger(L, 2);
    return 0;
}

static int PlayerInterface_set_mouseTaskTypeRestriction(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->mouseTaskTypeRestriction = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int PlayerInterface_set_mouseRightTargetSet(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->mouseRightTargetSet = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlayerInterface_set_mouseRightTarget(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for mouseRightTarget");
}

static int PlayerInterface_set_rmouseTimer(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->rmouseTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int PlayerInterface_set_selectedCharacters(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for selectedCharacters");
}

static int PlayerInterface_set_selectedObject(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!val) return luaL_error(L, "hand is nil");
    b->selectedObject = *val;
    return 0;
}

static int PlayerInterface_set_onlyAnimalsSelected(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->onlyAnimalsSelected = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlayerInterface_set_selectedLoadedLeft(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->selectedLoadedLeft = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int PlayerInterface_set_trackedCharacterHandle(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!val) return luaL_error(L, "hand is nil");
    b->trackedCharacterHandle = *val;
    return 0;
}

static int PlayerInterface_set_trackedCharacterFloor(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->trackedCharacterFloor = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int PlayerInterface_set_levelEditor(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for levelEditor");
}

static int PlayerInterface_set_participant(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for participant");
}

static int PlayerInterface_set_currentPlatoon(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for currentPlatoon");
}

static int PlayerInterface_set_playerCharacters(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for playerCharacters");
}

static int PlayerInterface_set_deadPlayerSquad(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!val) return luaL_error(L, "hand is nil");
    b->deadPlayerSquad = *val;
    return 0;
}

static int PlayerInterface_set_placementObject(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return luaL_error(L, "Read-only or unsupported setter type for placementObject");
}

static int PlayerInterface_set_characterEditorMode(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->characterEditorMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlayerInterface_set_mLeftUp(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->mLeftUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlayerInterface_set_mLeftDown(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->mLeftDown = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlayerInterface_set_mRightUp(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->mRightUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlayerInterface_set_mRightDown(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->mRightDown = lua_toboolean(L, 2) != 0;
    return 0;
}

int PlayerInterfaceBinding::_CONSTRUCTOR(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    PlayerInterface* result = b->_CONSTRUCTOR();
    return pushObject<PlayerInterface>(L, result, PlayerInterfaceBinding::getMetatableName());
}

int PlayerInterfaceBinding::_DESTRUCTOR(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    b->_DESTRUCTOR();
    return 0;
}

int PlayerInterfaceBinding::getCamera(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    CameraClass* result = b->getCamera();
    return pushObject<CameraClass>(L, result, CameraClassBinding::getMetatableName());
}

int PlayerInterfaceBinding::clearAndReset(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    b->clearAndReset();
    return 0;
}

int PlayerInterfaceBinding::getFaction(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    Faction* result = b->getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int PlayerInterfaceBinding::getCurrentPlatoon(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    Platoon* result = b->getCurrentPlatoon();
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int PlayerInterfaceBinding::getCurrentActivePlatoon(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    RootObjectContainer* result = b->getCurrentActivePlatoon();
    return pushObject<RootObjectContainer>(L, result, RootObjectContainerBinding::getMetatableName());
}

int PlayerInterfaceBinding::update(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    b->update();
    return 0;
}

int PlayerInterfaceBinding::updateUT(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    b->updateUT();
    return 0;
}

int PlayerInterfaceBinding::isBuildMode(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    bool result = b->isBuildMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::setCharacterEditMode(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->setCharacterEditMode(on);
    return 0;
}

int PlayerInterfaceBinding::getCharacterEditMode(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    bool result = b->getCharacterEditMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::unselectAll(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    b->unselectAll();
    return 0;
}

int PlayerInterfaceBinding::selectAll(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    b->selectAll();
    return 0;
}

int PlayerInterfaceBinding::selectPlayerCharacter(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    int index = (int)luaL_checkinteger(L, 2);
    bool modifier = lua_toboolean(L, 3) != 0;
    bool track = lua_toboolean(L, 4) != 0;
    b->selectPlayerCharacter(index, modifier, track);
    return 0;
}

int PlayerInterfaceBinding::getCameraCenter(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Vector3 result = b->getCameraCenter();
    pushVector3(L, result);
    return 1;
}

int PlayerInterfaceBinding::getDistanceFromCamera(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    float result = b->getDistanceFromCamera(v);
    lua_pushnumber(L, result);
    return 1;
}

int PlayerInterfaceBinding::getSquaredDistanceFromCamera(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    float result = b->getSquaredDistanceFromCamera(v);
    lua_pushnumber(L, result);
    return 1;
}

int PlayerInterfaceBinding::stopTrackCharacter(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    b->stopTrackCharacter();
    return 0;
}

int PlayerInterfaceBinding::isTrackingCharacter(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    bool result = b->isTrackingCharacter();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::focusCamera(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    b->focusCamera(pos);
    return 0;
}

int PlayerInterfaceBinding::manuallyOrientCamera(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Quaternion rot;
    readQuaternion(L, 2, rot);
    float zoom = (float)luaL_checknumber(L, 3);
    b->manuallyOrientCamera(rot, zoom);
    return 0;
}

int PlayerInterfaceBinding::focusCameraSelectedCharacter(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    b->focusCameraSelectedCharacter();
    return 0;
}

int PlayerInterfaceBinding::toggleLevelEditorOnSelectedTown(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    b->toggleLevelEditorOnSelectedTown();
    return 0;
}

int PlayerInterfaceBinding::isLevelEditMode(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    bool result = b->isLevelEditMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::isObjectPlacementMode(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    bool result = b->isObjectPlacementMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::setOrderSelectedCharacters(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    MessageForB::StandingOrder order = (MessageForB::StandingOrder)luaL_checkinteger(L, 2);
    b->setOrderSelectedCharacters(order);
    return 0;
}

int PlayerInterfaceBinding::getCurrentFloor(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    int result = b->getCurrentFloor();
    lua_pushinteger(L, result);
    return 1;
}

int PlayerInterfaceBinding::setCurrentFloor(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    int floor = (int)luaL_checkinteger(L, 2);
    b->setCurrentFloor(floor);
    return 0;
}

int PlayerInterfaceBinding::getNearestSelectedCharacterTo(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Character* result = b->getNearestSelectedCharacterTo(pos);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int PlayerInterfaceBinding::getNearestCharacterTo(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Character* result = b->getNearestCharacterTo(pos);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int PlayerInterfaceBinding::removeJobSelectedCharacters(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    b->removeJobSelectedCharacters(t);
    return 0;
}

int PlayerInterfaceBinding::removePermaJobSelectedCharacters(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    int id = (int)luaL_checkinteger(L, 2);
    b->removePermaJobSelectedCharacters(id);
    return 0;
}

int PlayerInterfaceBinding::selectedCharactersUnconcious(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    bool displayMessage = lua_toboolean(L, 2) != 0;
    bool result = b->selectedCharactersUnconcious(displayMessage);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::selectedCharactersLayingLow(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    bool result = b->selectedCharactersLayingLow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::useSpeedGroup(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    bool use = lua_toboolean(L, 2) != 0;
    b->useSpeedGroup(use);
    return 0;
}

int PlayerInterfaceBinding::assignSpeedGroup(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    bool create = lua_toboolean(L, 2) != 0;
    b->assignSpeedGroup(create);
    return 0;
}

int PlayerInterfaceBinding::cycleSquad(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    b->cycleSquad();
    return 0;
}

int PlayerInterfaceBinding::cycleCharacter(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    int d = (int)luaL_checkinteger(L, 2);
    b->cycleCharacter(d);
    return 0;
}

int PlayerInterfaceBinding::stopCharactersMovement(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    b->stopCharactersMovement();
    return 0;
}

int PlayerInterfaceBinding::getAnyPlayerCharacter(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    Character* result = b->getAnyPlayerCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int PlayerInterfaceBinding::isOrderValidForSelection(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    TaskType task = (TaskType)luaL_checkinteger(L, 2);
    bool result = b->isOrderValidForSelection(task);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::setVisibilityForReflections(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    bool set = lua_toboolean(L, 2) != 0;
    b->setVisibilityForReflections(set);
    return 0;
}

int PlayerInterfaceBinding::resetFloorsVisibility(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    b->resetFloorsVisibility();
    return 0;
}

int PlayerInterfaceBinding::setFloorsVisibility(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    int floor = (int)luaL_checkinteger(L, 2);
    b->setFloorsVisibility(floor);
    return 0;
}

int PlayerInterfaceBinding::clearSelection(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    b->clearSelection();
    return 0;
}

int PlayerInterfaceBinding::mouseScan(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");

    b->mouseScan();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 107: void playerSetup(...) - unsupported arg type
  line 109: void factoryObjectCreatedCallback(...) - unsupported arg type
  line 110: void _NV_factoryObjectCreatedCallback(...) - unsupported arg type
  line 111: void setFaction(...) - unsupported arg type
  line 113: bool setCurrentPlatoon(...) - unsupported arg type
  line 116: bool recruit(...) - overloaded method
  line 117: bool recruit(...) - overloaded method
  line 118: ActivePlatoon* createSquad(...) - unsupported return type
  line 119: ActivePlatoon* getDeadSquad(...) - unsupported return type
  line 120: const hand& getDeadSquadHandle(...) - reference return type
  line 124: void activateObjectPlacementMode(...) - unsupported arg type
  line 126: void activateCharacterEditMode(...) - unsupported arg type
  line 127: bool triggerAreaArrivalDialogue(...) - unsupported arg type
  line 132: void selectObject(...) - unsupported arg type
  line 134: void _selectPlayerCharacter(...) - unsupported arg type
  line 135: void activateSelection(...) - unsupported arg type
  line 139: void startTrackCharacter(...) - unsupported arg type
  line 149: LevelEditor* getLevelEditor(...) - unsupported return type
  line 150: void objectSelected(...) - unsupported arg type
  line 151: void toggleObjectSelected(...) - unsupported arg type
  line 152: bool isObjectSelected(...) - unsupported arg type
  line 153: void unselectPlayerCharacter(...) - unsupported arg type
  line 154: void updatePlayerSelection(...) - unsupported arg type
  line 157: void getAllSelectedObjects(...) - unsupported arg type
  line 160: void newPlayerTaskSelectedCharacters(...) - unsupported arg type
  line 161: bool getPlayerTaskProbability(...) - unsupported arg type
  line 162: void addOrderSelectedCharacters(...) - unsupported arg type
  line 163: void addJobSelectedCharacters(...) - unsupported arg type
  line 170: bool isEnemy(...) - unsupported arg type
  line 171: bool isFactionKnown(...) - unsupported arg type
  line 172: void encounterFaction(...) - unsupported arg type
  line 173: void pickupItem(...) - unsupported arg type
  line 178: void getAllPlayerCharacters(...) - overloaded method
  line 179: const lektor<Character*>& getAllPlayerCharacters(...) - overloaded method
  line 181: void serialise(...) - unsupported arg type
  line 182: void loadFromSerialise(...) - unsupported arg type
  line 183: bool getInteriorsVisible(...) - unsupported arg type
  line 216: void updateFloorVisibility(...) - unsupported arg type
  line 219: void addTaskNearestSelectedCharacter(...) - unsupported arg type
  line 220: void updateLastMoveWaypointSelectedCharacters(...) - unsupported arg type
  line 222: void playerControl(...) - unsupported arg type
  line 226: void characterSelected(...) - unsupported arg type
  line 227: void itemSelected(...) - unsupported arg type
  line 228: bool buildingSelected(...) - unsupported arg type
  line 229: void playerMove(...) - unsupported arg type
  line 230: bool _isPlayerCharacter(...) - unsupported arg type
*/

int PlayerInterfaceBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int PlayerInterfaceBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.PlayerInterface object");
    return 1;
}

void PlayerInterfaceBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PlayerInterfaceBinding::gc },
        { "__tostring", PlayerInterfaceBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", PlayerInterfaceBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", PlayerInterfaceBinding::_DESTRUCTOR },
        { "getCamera", PlayerInterfaceBinding::getCamera },
        { "clearAndReset", PlayerInterfaceBinding::clearAndReset },
        { "getFaction", PlayerInterfaceBinding::getFaction },
        { "getCurrentPlatoon", PlayerInterfaceBinding::getCurrentPlatoon },
        { "getCurrentActivePlatoon", PlayerInterfaceBinding::getCurrentActivePlatoon },
        { "update", PlayerInterfaceBinding::update },
        { "updateUT", PlayerInterfaceBinding::updateUT },
        { "isBuildMode", PlayerInterfaceBinding::isBuildMode },
        { "setCharacterEditMode", PlayerInterfaceBinding::setCharacterEditMode },
        { "getCharacterEditMode", PlayerInterfaceBinding::getCharacterEditMode },
        { "unselectAll", PlayerInterfaceBinding::unselectAll },
        { "selectAll", PlayerInterfaceBinding::selectAll },
        { "selectPlayerCharacter", PlayerInterfaceBinding::selectPlayerCharacter },
        { "getCameraCenter", PlayerInterfaceBinding::getCameraCenter },
        { "getDistanceFromCamera", PlayerInterfaceBinding::getDistanceFromCamera },
        { "getSquaredDistanceFromCamera", PlayerInterfaceBinding::getSquaredDistanceFromCamera },
        { "stopTrackCharacter", PlayerInterfaceBinding::stopTrackCharacter },
        { "isTrackingCharacter", PlayerInterfaceBinding::isTrackingCharacter },
        { "focusCamera", PlayerInterfaceBinding::focusCamera },
        { "manuallyOrientCamera", PlayerInterfaceBinding::manuallyOrientCamera },
        { "focusCameraSelectedCharacter", PlayerInterfaceBinding::focusCameraSelectedCharacter },
        { "toggleLevelEditorOnSelectedTown", PlayerInterfaceBinding::toggleLevelEditorOnSelectedTown },
        { "isLevelEditMode", PlayerInterfaceBinding::isLevelEditMode },
        { "isObjectPlacementMode", PlayerInterfaceBinding::isObjectPlacementMode },
        { "setOrderSelectedCharacters", PlayerInterfaceBinding::setOrderSelectedCharacters },
        { "getCurrentFloor", PlayerInterfaceBinding::getCurrentFloor },
        { "setCurrentFloor", PlayerInterfaceBinding::setCurrentFloor },
        { "getNearestSelectedCharacterTo", PlayerInterfaceBinding::getNearestSelectedCharacterTo },
        { "getNearestCharacterTo", PlayerInterfaceBinding::getNearestCharacterTo },
        { "removeJobSelectedCharacters", PlayerInterfaceBinding::removeJobSelectedCharacters },
        { "removePermaJobSelectedCharacters", PlayerInterfaceBinding::removePermaJobSelectedCharacters },
        { "selectedCharactersUnconcious", PlayerInterfaceBinding::selectedCharactersUnconcious },
        { "selectedCharactersLayingLow", PlayerInterfaceBinding::selectedCharactersLayingLow },
        { "useSpeedGroup", PlayerInterfaceBinding::useSpeedGroup },
        { "assignSpeedGroup", PlayerInterfaceBinding::assignSpeedGroup },
        { "cycleSquad", PlayerInterfaceBinding::cycleSquad },
        { "cycleCharacter", PlayerInterfaceBinding::cycleCharacter },
        { "stopCharactersMovement", PlayerInterfaceBinding::stopCharactersMovement },
        { "getAnyPlayerCharacter", PlayerInterfaceBinding::getAnyPlayerCharacter },
        { "isOrderValidForSelection", PlayerInterfaceBinding::isOrderValidForSelection },
        { "setVisibilityForReflections", PlayerInterfaceBinding::setVisibilityForReflections },
        { "resetFloorsVisibility", PlayerInterfaceBinding::resetFloorsVisibility },
        { "setFloorsVisibility", PlayerInterfaceBinding::setFloorsVisibility },
        { "clearSelection", PlayerInterfaceBinding::clearSelection },
        { "mouseScan", PlayerInterfaceBinding::mouseScan },
        { 0, 0 }
    };

    registerClass(
        L, 
        PlayerInterfaceBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, PlayerInterfaceBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, PlayerInterface_get_factionName);
    lua_setfield(L, -2, "factionName");
    lua_pushcfunction(L, PlayerInterface_get_camera);
    lua_setfield(L, -2, "camera");
    lua_pushcfunction(L, PlayerInterface_get_technology);
    lua_setfield(L, -2, "technology");
    lua_pushcfunction(L, PlayerInterface_get_selectedObjectsChangedThisFrame);
    lua_setfield(L, -2, "selectedObjectsChangedThisFrame");
    lua_pushcfunction(L, PlayerInterface_get_contextMenu);
    lua_setfield(L, -2, "contextMenu");
    lua_pushcfunction(L, PlayerInterface_get_selectBox);
    lua_setfield(L, -2, "selectBox");
    lua_pushcfunction(L, PlayerInterface_get_moveMarker);
    lua_setfield(L, -2, "moveMarker");
    lua_pushcfunction(L, PlayerInterface_get_selectedCharacter);
    lua_setfield(L, -2, "selectedCharacter");
    lua_pushcfunction(L, PlayerInterface_get_aiOptions);
    lua_setfield(L, -2, "aiOptions");
    lua_pushcfunction(L, PlayerInterface_get_zonesVisibilities);
    lua_setfield(L, -2, "zonesVisibilities");
    lua_pushcfunction(L, PlayerInterface_get_townsActive);
    lua_setfield(L, -2, "townsActive");
    lua_pushcfunction(L, PlayerInterface_get_interiorsVisible);
    lua_setfield(L, -2, "interiorsVisible");
    lua_pushcfunction(L, PlayerInterface_get_interiorsVisibleHash);
    lua_setfield(L, -2, "interiorsVisibleHash");
    lua_pushcfunction(L, PlayerInterface_get_currentFloor);
    lua_setfield(L, -2, "currentFloor");
    lua_pushcfunction(L, PlayerInterface_get_currentMouseTask);
    lua_setfield(L, -2, "currentMouseTask");
    lua_pushcfunction(L, PlayerInterface_get_mouseTaskTypeRestriction);
    lua_setfield(L, -2, "mouseTaskTypeRestriction");
    lua_pushcfunction(L, PlayerInterface_get_mouseRightTargetSet);
    lua_setfield(L, -2, "mouseRightTargetSet");
    lua_pushcfunction(L, PlayerInterface_get_mouseRightTarget);
    lua_setfield(L, -2, "mouseRightTarget");
    lua_pushcfunction(L, PlayerInterface_get_rmouseTimer);
    lua_setfield(L, -2, "rmouseTimer");
    lua_pushcfunction(L, PlayerInterface_get_selectedCharacters);
    lua_setfield(L, -2, "selectedCharacters");
    lua_pushcfunction(L, PlayerInterface_get_selectedObject);
    lua_setfield(L, -2, "selectedObject");
    lua_pushcfunction(L, PlayerInterface_get_onlyAnimalsSelected);
    lua_setfield(L, -2, "onlyAnimalsSelected");
    lua_pushcfunction(L, PlayerInterface_get_selectedLoadedLeft);
    lua_setfield(L, -2, "selectedLoadedLeft");
    lua_pushcfunction(L, PlayerInterface_get_trackedCharacterHandle);
    lua_setfield(L, -2, "trackedCharacterHandle");
    lua_pushcfunction(L, PlayerInterface_get_trackedCharacterFloor);
    lua_setfield(L, -2, "trackedCharacterFloor");
    lua_pushcfunction(L, PlayerInterface_get_levelEditor);
    lua_setfield(L, -2, "levelEditor");
    lua_pushcfunction(L, PlayerInterface_get_participant);
    lua_setfield(L, -2, "participant");
    lua_pushcfunction(L, PlayerInterface_get_currentPlatoon);
    lua_setfield(L, -2, "currentPlatoon");
    lua_pushcfunction(L, PlayerInterface_get_playerCharacters);
    lua_setfield(L, -2, "playerCharacters");
    lua_pushcfunction(L, PlayerInterface_get_deadPlayerSquad);
    lua_setfield(L, -2, "deadPlayerSquad");
    lua_pushcfunction(L, PlayerInterface_get_placementObject);
    lua_setfield(L, -2, "placementObject");
    lua_pushcfunction(L, PlayerInterface_get_characterEditorMode);
    lua_setfield(L, -2, "characterEditorMode");
    lua_pushcfunction(L, PlayerInterface_get_mLeftUp);
    lua_setfield(L, -2, "mLeftUp");
    lua_pushcfunction(L, PlayerInterface_get_mLeftDown);
    lua_setfield(L, -2, "mLeftDown");
    lua_pushcfunction(L, PlayerInterface_get_mRightUp);
    lua_setfield(L, -2, "mRightUp");
    lua_pushcfunction(L, PlayerInterface_get_mRightDown);
    lua_setfield(L, -2, "mRightDown");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, PlayerInterface_set_factionName);
    lua_setfield(L, -2, "factionName");
    lua_pushcfunction(L, PlayerInterface_set_camera);
    lua_setfield(L, -2, "camera");
    lua_pushcfunction(L, PlayerInterface_set_technology);
    lua_setfield(L, -2, "technology");
    lua_pushcfunction(L, PlayerInterface_set_selectedObjectsChangedThisFrame);
    lua_setfield(L, -2, "selectedObjectsChangedThisFrame");
    lua_pushcfunction(L, PlayerInterface_set_contextMenu);
    lua_setfield(L, -2, "contextMenu");
    lua_pushcfunction(L, PlayerInterface_set_selectBox);
    lua_setfield(L, -2, "selectBox");
    lua_pushcfunction(L, PlayerInterface_set_moveMarker);
    lua_setfield(L, -2, "moveMarker");
    lua_pushcfunction(L, PlayerInterface_set_selectedCharacter);
    lua_setfield(L, -2, "selectedCharacter");
    lua_pushcfunction(L, PlayerInterface_set_aiOptions);
    lua_setfield(L, -2, "aiOptions");
    lua_pushcfunction(L, PlayerInterface_set_zonesVisibilities);
    lua_setfield(L, -2, "zonesVisibilities");
    lua_pushcfunction(L, PlayerInterface_set_townsActive);
    lua_setfield(L, -2, "townsActive");
    lua_pushcfunction(L, PlayerInterface_set_interiorsVisible);
    lua_setfield(L, -2, "interiorsVisible");
    lua_pushcfunction(L, PlayerInterface_set_interiorsVisibleHash);
    lua_setfield(L, -2, "interiorsVisibleHash");
    lua_pushcfunction(L, PlayerInterface_set_currentFloor);
    lua_setfield(L, -2, "currentFloor");
    lua_pushcfunction(L, PlayerInterface_set_currentMouseTask);
    lua_setfield(L, -2, "currentMouseTask");
    lua_pushcfunction(L, PlayerInterface_set_mouseTaskTypeRestriction);
    lua_setfield(L, -2, "mouseTaskTypeRestriction");
    lua_pushcfunction(L, PlayerInterface_set_mouseRightTargetSet);
    lua_setfield(L, -2, "mouseRightTargetSet");
    lua_pushcfunction(L, PlayerInterface_set_mouseRightTarget);
    lua_setfield(L, -2, "mouseRightTarget");
    lua_pushcfunction(L, PlayerInterface_set_rmouseTimer);
    lua_setfield(L, -2, "rmouseTimer");
    lua_pushcfunction(L, PlayerInterface_set_selectedCharacters);
    lua_setfield(L, -2, "selectedCharacters");
    lua_pushcfunction(L, PlayerInterface_set_selectedObject);
    lua_setfield(L, -2, "selectedObject");
    lua_pushcfunction(L, PlayerInterface_set_onlyAnimalsSelected);
    lua_setfield(L, -2, "onlyAnimalsSelected");
    lua_pushcfunction(L, PlayerInterface_set_selectedLoadedLeft);
    lua_setfield(L, -2, "selectedLoadedLeft");
    lua_pushcfunction(L, PlayerInterface_set_trackedCharacterHandle);
    lua_setfield(L, -2, "trackedCharacterHandle");
    lua_pushcfunction(L, PlayerInterface_set_trackedCharacterFloor);
    lua_setfield(L, -2, "trackedCharacterFloor");
    lua_pushcfunction(L, PlayerInterface_set_levelEditor);
    lua_setfield(L, -2, "levelEditor");
    lua_pushcfunction(L, PlayerInterface_set_participant);
    lua_setfield(L, -2, "participant");
    lua_pushcfunction(L, PlayerInterface_set_currentPlatoon);
    lua_setfield(L, -2, "currentPlatoon");
    lua_pushcfunction(L, PlayerInterface_set_playerCharacters);
    lua_setfield(L, -2, "playerCharacters");
    lua_pushcfunction(L, PlayerInterface_set_deadPlayerSquad);
    lua_setfield(L, -2, "deadPlayerSquad");
    lua_pushcfunction(L, PlayerInterface_set_placementObject);
    lua_setfield(L, -2, "placementObject");
    lua_pushcfunction(L, PlayerInterface_set_characterEditorMode);
    lua_setfield(L, -2, "characterEditorMode");
    lua_pushcfunction(L, PlayerInterface_set_mLeftUp);
    lua_setfield(L, -2, "mLeftUp");
    lua_pushcfunction(L, PlayerInterface_set_mLeftDown);
    lua_setfield(L, -2, "mLeftDown");
    lua_pushcfunction(L, PlayerInterface_set_mRightUp);
    lua_setfield(L, -2, "mRightUp");
    lua_pushcfunction(L, PlayerInterface_set_mRightDown);
    lua_setfield(L, -2, "mRightDown");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua