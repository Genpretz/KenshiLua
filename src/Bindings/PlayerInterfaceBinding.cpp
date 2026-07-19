#include "pch.h"
#include "kenshi\PlayerInterface.h"
#include "PlayerInterfaceBinding.h"
#include "Templates/OgreUnorderedBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CameraClassBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/RootObjectContainerBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/ItemBinding.h"
#include "kenshi\CameraClass.h"
#include "CameraClassBinding.h"
#include "kenshi\RootObject.h"
#include "RootObjectBinding.h"
#include "RootObjectContainerBinding.h"
#include "kenshi\Platoon.h"
#include "PlatoonBinding.h"
#include "FactionBinding.h"
#include "Bindings/Templates/LektorBinding.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/AIOptionsBinding.h"
#include "Bindings/ContextMenuBinding.h"
#include "Bindings/SelectionBoxBinding.h"
#include "Bindings/InputHandlerBinding.h"
#include <kenshi/InputHandler.h>

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
    lua_pushlightuserdata(L, (void*)b->technology);
    return 1;
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
    return pushObject<ContextMenu>(L, &b->contextMenu, ContextMenuBinding::getMetatableName());
}

static int PlayerInterface_get_selectBox(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<SelectionBox>(L, &b->selectBox, SelectionBoxBinding::getMetatableName());
}

static int PlayerInterface_get_moveMarker(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lua_pushlightuserdata(L, (void*)b->moveMarker);
    return 1;
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
    return pushObject<PlayerInterface::AIOptions>(L, &b->aiOptions, AIOptionsBinding::getMetatableName());
}

static int PlayerInterface_get_zonesVisibilities(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<ogre_unordered_map<ZoneMap*, unsigned char>::type>(L, &b->zonesVisibilities, "ogre_unordered_map<ZoneMap*, unsigned char>");
}

static int PlayerInterface_get_townsActive(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<ogre_unordered_set<TownBase*>::type>(L, &b->townsActive, "ogre_unordered_set<TownBase*>");
}

static int PlayerInterface_get_interiorsVisible(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<ogre_unordered_set<hand>::type>(L, &b->interiorsVisible, OgreUnorderedSetBinding<hand>::getMetatableName());
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
    return pushObject<ogre_unordered_set<hand>::type>(L, &b->selectedCharacters, OgreUnorderedSetBinding<hand>::getMetatableName());
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
    lua_pushlightuserdata(L, (void*)b->levelEditor);
    return 1;
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
    return pushObject<lektor<Character*>>(L, &b->playerCharacters, "lektor<Character*>");
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
    lua_pushlightuserdata(L, (void*)b->placementObject);
    return 1;
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
    b->camera = lua_isnoneornil(L, 2) ? nullptr : checkObject<CameraClass>(L, 2, CameraClassBinding::getMetatableName());
    return 0;
}

static int PlayerInterface_set_technology(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->technology = (Research*)lua_touserdata(L, 2);
    return 0;
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
    ContextMenu* val = checkObject<ContextMenu>(L, 2, ContextMenuBinding::getMetatableName());
    b->contextMenu = *val;
    return 0;
}

static int PlayerInterface_set_selectBox(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    SelectionBox* val = checkObject<SelectionBox>(L, 2, SelectionBoxBinding::getMetatableName());
    b->selectBox = *val;
    return 0;
}

static int PlayerInterface_set_moveMarker(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->moveMarker = (MoveMarker*)lua_touserdata(L, 2);
    return 0;
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
    PlayerInterface::AIOptions* val = checkObject<PlayerInterface::AIOptions>(L, 2, AIOptionsBinding::getMetatableName());
    b->aiOptions = *val;
    return 0;
}

static int PlayerInterface_set_zonesVisibilities(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->zonesVisibilities = *checkObject<ogre_unordered_map<ZoneMap*, unsigned char>::type>(L, 2, "ogre_unordered_map<ZoneMap*, unsigned char>");
    return 0;
}

static int PlayerInterface_set_townsActive(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->townsActive = *checkObject<ogre_unordered_set<TownBase*>::type>(L, 2, "ogre_unordered_set<TownBase*>");
    return 0;
}

static int PlayerInterface_set_interiorsVisible(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->interiorsVisible = *checkObject<ogre_unordered_set<hand>::type>(L, 2, OgreUnorderedSetBinding<hand>::getMetatableName());
    return 0;
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
    b->mouseRightTarget = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    return 0;
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
    b->selectedCharacters = *checkObject<ogre_unordered_set<hand>::type>(L, 2, OgreUnorderedSetBinding<hand>::getMetatableName());
    return 0;
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
    b->levelEditor = (LevelEditor*)lua_touserdata(L, 2);
    return 0;
}

static int PlayerInterface_set_participant(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->participant = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int PlayerInterface_set_currentPlatoon(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    b->currentPlatoon = lua_isnoneornil(L, 2) ? nullptr : checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    return 0;
}

static int PlayerInterface_set_playerCharacters(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lektor<Character*>* src = LektorPtrBinding<Character*>::get(L, 2);
    b->playerCharacters = *src;
    return 0;
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
    b->placementObject = (PlacementObject*)lua_touserdata(L, 2);
    return 0;
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

int PlayerInterfaceBinding::getLevelEditor(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    LevelEditor* result = b->getLevelEditor();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PlayerInterfaceBinding::objectSelected(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool select = lua_toboolean(L, 3) != 0;
    b->objectSelected(obj, select);
    return 0;
}

int PlayerInterfaceBinding::toggleObjectSelected(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    b->toggleObjectSelected(obj);
    return 0;
}

int PlayerInterfaceBinding::isObjectSelected(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = b->isObjectSelected(obj);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::unselectPlayerCharacter(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    b->unselectPlayerCharacter(obj);
    return 0;
}

int PlayerInterfaceBinding::updatePlayerSelection(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    hand* oldHandle = checkObject<hand>(L, 2, handBinding::getMetatableName());
    hand* newHandle = checkObject<hand>(L, 3, handBinding::getMetatableName());
    b->updatePlayerSelection(*oldHandle, *newHandle);
    return 0;
}

int PlayerInterfaceBinding::getAllSelectedObjects(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lektor<RootObject*>* out = checkObject<lektor<RootObject*>>(L, 2, "lektor<RootObject*>");
    itemType type = (itemType)luaL_checkinteger(L, 3);
    b->getAllSelectedObjects(*out, type);
    return 0;
}

int PlayerInterfaceBinding::newPlayerTaskSelectedCharacters(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    hand* targetH = checkObject<hand>(L, 3, handBinding::getMetatableName());
    Building* destinationIndoors = nullptr;
    if (!lua_isnil(L, 4)) {
        destinationIndoors = checkObject<Building>(L, 4, BuildingBinding::getMetatableName());
    }
    Ogre::Vector3 clickpos;
    readVector3(L, 5, clickpos);
    bool addDontClear = lua_toboolean(L, 6) != 0;
    b->newPlayerTaskSelectedCharacters(t, *targetH, destinationIndoors, clickpos, addDontClear);
    return 0;
}

int PlayerInterfaceBinding::getPlayerTaskProbability(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    TaskType task = (TaskType)luaL_checkinteger(L, 2);
    RootObject* target = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    float probability = 0.0f;
    bool result = b->getPlayerTaskProbability(task, target, probability);
    lua_pushboolean(L, result ? 1 : 0);
    lua_pushnumber(L, probability);
    return 2;
}

int PlayerInterfaceBinding::addOrderSelectedCharacters(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Building* destinationIndoors = nullptr;
    if (!lua_isnil(L, 2)) {
        destinationIndoors = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    }
    TaskType task = (TaskType)luaL_checkinteger(L, 3);
    RootObject* subject = nullptr;
    if (!lua_isnil(L, 4)) {
        subject = checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
    }
    bool shift = lua_toboolean(L, 5) != 0;
    bool addDontClear = lua_toboolean(L, 6) != 0;
    Ogre::Vector3 location;
    readVector3(L, 7, location);
    b->addOrderSelectedCharacters(destinationIndoors, task, subject, shift, addDontClear, location);
    return 0;
}

int PlayerInterfaceBinding::addJobSelectedCharacters(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    TaskType task = (TaskType)luaL_checkinteger(L, 2);
    RootObject* subject = nullptr;
    if (!lua_isnil(L, 3)) {
        subject = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    }
    bool shift = lua_toboolean(L, 4) != 0;
    bool add = lua_toboolean(L, 5) != 0;
    Ogre::Vector3 location;
    readVector3(L, 6, location);
    b->addJobSelectedCharacters(task, subject, shift, add, location);
    return 0;
}

int PlayerInterfaceBinding::isEnemy(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = b->isEnemy(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::isFactionKnown(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = b->isFactionKnown(f);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::encounterFaction(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Faction* faction = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    b->encounterFaction(faction);
    return 0;
}

int PlayerInterfaceBinding::pickupItem(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    b->pickupItem(item);
    return 0;
}

int PlayerInterfaceBinding::getAllPlayerCharacters(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    
    if (lua_gettop(L) >= 2) {
        lektor<RootObject*>* list = checkObject<lektor<RootObject*>>(L, 2, "lektor<RootObject*>");
        b->getAllPlayerCharacters(*list);
        return 0;
    } else {
        const lektor<Character*>& result = b->getAllPlayerCharacters();
        return pushObject<lektor<Character*>>(L, const_cast<lektor<Character*>*>(&result), "lektor<Character*>");
    }
}

int PlayerInterfaceBinding::serialise(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    b->serialise(data);
    return 0;
}

int PlayerInterfaceBinding::loadFromSerialise(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    b->loadFromSerialise(data);
    return 0;
}

int PlayerInterfaceBinding::getInteriorsVisible(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    bool result = b->getInteriorsVisible(building);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::updateFloorVisibility(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    lektor<Character*>* characters = checkObject<lektor<Character*>>(L, 2, "lektor<Character*>");
    b->updateFloorVisibility(*characters);
    return 0;
}

int PlayerInterfaceBinding::addTaskNearestSelectedCharacter(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Building* dest = nullptr;
    if (!lua_isnil(L, 2)) {
        dest = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    }
    TaskType t = (TaskType)luaL_checkinteger(L, 3);
    RootObject* subject = nullptr;
    if (!lua_isnil(L, 4)) {
        subject = checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
    }
    bool shift = lua_toboolean(L, 5) != 0;
    Ogre::Vector3 location;
    readVector3(L, 6, location);
    bool noAnimals = lua_toboolean(L, 7) != 0;
    b->addTaskNearestSelectedCharacter(dest, t, subject, shift, location, noAnimals);
    return 0;
}

int PlayerInterfaceBinding::updateLastMoveWaypointSelectedCharacters(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Ogre::Vector3 location;
    readVector3(L, 2, location);
    Building* dest = nullptr;
    if (!lua_isnil(L, 3)) {
        dest = checkObject<Building>(L, 3, BuildingBinding::getMetatableName());
    }
    b->updateLastMoveWaypointSelectedCharacters(location, dest);
    return 0;
}

int PlayerInterfaceBinding::playerControl(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    InputHandler* key = checkObject<InputHandler>(L, 2, InputHandlerBinding::getMetatableName());
    b->playerControl(*key);
    return 0;
}

int PlayerInterfaceBinding::characterSelected(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    b->characterSelected(target);
    return 0;
}

int PlayerInterfaceBinding::itemSelected(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    b->itemSelected(item);
    return 0;
}

int PlayerInterfaceBinding::buildingSelected(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    bool interiorsVisible = lua_toboolean(L, 4) != 0;
    bool result = b->buildingSelected(building, position, interiorsVisible);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::playerMove(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Building* destBuilding = nullptr;
    if (!lua_isnil(L, 3)) {
        destBuilding = checkObject<Building>(L, 3, BuildingBinding::getMetatableName());
    }
    b->playerMove(pos, destBuilding);
    return 0;
}

int PlayerInterfaceBinding::_isPlayerCharacter(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = b->_isPlayerCharacter(obj);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::playerSetup(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    CameraClass* cam = lua_isnoneornil(L, 2) ? nullptr : checkObject<CameraClass>(L, 2, CameraClassBinding::getMetatableName());
    b->playerSetup(cam);
    return 0;
}

int PlayerInterfaceBinding::factoryObjectCreatedCallback(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    b->factoryObjectCreatedCallback(obj);
    return 0;
}

int PlayerInterfaceBinding::_NV_factoryObjectCreatedCallback(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    b->_NV_factoryObjectCreatedCallback(obj);
    return 0;
}

int PlayerInterfaceBinding::setFaction(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Faction* f = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    b->setFaction(f);
    return 0;
}

int PlayerInterfaceBinding::setCurrentPlatoon(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Platoon* squad = lua_isnoneornil(L, 2) ? nullptr : checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    bool res = b->setCurrentPlatoon(squad);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::recruit(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    bool editor = lua_toboolean(L, 3) != 0;
    bool res = false;
    if (testObject<lektor<Character*>>(L, 2, "lektor<Character*>") != nullptr) {
        lektor<Character*>* list = LektorPtrBinding<Character*>::get(L, 2);
        res = b->recruit(*list, editor);
    } else {
        Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
        res = b->recruit(c, editor);
    }
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::createSquad(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    ActivePlatoon* res = b->createSquad();
    return pushObject<ActivePlatoon>(L, res, ActivePlatoonBinding::getMetatableName());
}

int PlayerInterfaceBinding::getDeadSquad(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    ActivePlatoon* res = b->getDeadSquad();
    return pushObject<ActivePlatoon>(L, res, ActivePlatoonBinding::getMetatableName());
}

int PlayerInterfaceBinding::getDeadSquadHandle(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    const hand& res = b->getDeadSquadHandle();
    return pushObject<hand>(L, new hand(res), handBinding::getMetatableName());
}

int PlayerInterfaceBinding::activateObjectPlacementMode(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    GameData* data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    b->activateObjectPlacementMode(data);
    return 0;
}

int PlayerInterfaceBinding::activateCharacterEditMode(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    Character* c = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    b->activateCharacterEditMode(c);
    return 0;
}

int PlayerInterfaceBinding::triggerAreaArrivalDialogue(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    GameData* area = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool res = b->triggerAreaArrivalDialogue(area);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::selectObject(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    RootObject* obj = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool modifier = lua_toboolean(L, 3) != 0;
    b->selectObject(obj, modifier);
    return 0;
}

int PlayerInterfaceBinding::_selectPlayerCharacter(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    RootObject* obj = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool modifier = lua_toboolean(L, 3) != 0;
    bool track = lua_toboolean(L, 4) != 0;
    b->_selectPlayerCharacter(obj, modifier, track);
    return 0;
}

int PlayerInterfaceBinding::activateSelection(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    RootObject* obj = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    b->activateSelection(obj);
    return 0;
}

int PlayerInterfaceBinding::startTrackCharacter(lua_State* L)
{
    PlayerInterface* b = getB(L, 1);
    if (!b) return luaL_error(L, "PlayerInterface is nil");
    RootObject* obj = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    b->startTrackCharacter(obj);
    return 0;
}

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
        { "playerSetup", PlayerInterfaceBinding::playerSetup },
        { "factoryObjectCreatedCallback", PlayerInterfaceBinding::factoryObjectCreatedCallback },
        { "_NV_factoryObjectCreatedCallback", PlayerInterfaceBinding::_NV_factoryObjectCreatedCallback },
        { "setFaction", PlayerInterfaceBinding::setFaction },
        { "setCurrentPlatoon", PlayerInterfaceBinding::setCurrentPlatoon },
        { "recruit", PlayerInterfaceBinding::recruit },
        { "createSquad", PlayerInterfaceBinding::createSquad },
        { "getDeadSquad", PlayerInterfaceBinding::getDeadSquad },
        { "getDeadSquadHandle", PlayerInterfaceBinding::getDeadSquadHandle },
        { "activateObjectPlacementMode", PlayerInterfaceBinding::activateObjectPlacementMode },
        { "activateCharacterEditMode", PlayerInterfaceBinding::activateCharacterEditMode },
        { "triggerAreaArrivalDialogue", PlayerInterfaceBinding::triggerAreaArrivalDialogue },
        { "selectObject", PlayerInterfaceBinding::selectObject },
        { "_selectPlayerCharacter", PlayerInterfaceBinding::_selectPlayerCharacter },
        { "activateSelection", PlayerInterfaceBinding::activateSelection },
        { "startTrackCharacter", PlayerInterfaceBinding::startTrackCharacter },
        { "getLevelEditor", PlayerInterfaceBinding::getLevelEditor },
        { "objectSelected", PlayerInterfaceBinding::objectSelected },
        { "toggleObjectSelected", PlayerInterfaceBinding::toggleObjectSelected },
        { "isObjectSelected", PlayerInterfaceBinding::isObjectSelected },
        { "unselectPlayerCharacter", PlayerInterfaceBinding::unselectPlayerCharacter },
        { "updatePlayerSelection", PlayerInterfaceBinding::updatePlayerSelection },
        { "getAllSelectedObjects", PlayerInterfaceBinding::getAllSelectedObjects },
        { "newPlayerTaskSelectedCharacters", PlayerInterfaceBinding::newPlayerTaskSelectedCharacters },
        { "getPlayerTaskProbability", PlayerInterfaceBinding::getPlayerTaskProbability },
        { "addOrderSelectedCharacters", PlayerInterfaceBinding::addOrderSelectedCharacters },
        { "addJobSelectedCharacters", PlayerInterfaceBinding::addJobSelectedCharacters },
        { "isEnemy", PlayerInterfaceBinding::isEnemy },
        { "isFactionKnown", PlayerInterfaceBinding::isFactionKnown },
        { "encounterFaction", PlayerInterfaceBinding::encounterFaction },
        { "pickupItem", PlayerInterfaceBinding::pickupItem },
        { "getAllPlayerCharacters", PlayerInterfaceBinding::getAllPlayerCharacters },
        { "serialise", PlayerInterfaceBinding::serialise },
        { "loadFromSerialise", PlayerInterfaceBinding::loadFromSerialise },
        { "getInteriorsVisible", PlayerInterfaceBinding::getInteriorsVisible },
        { "updateFloorVisibility", PlayerInterfaceBinding::updateFloorVisibility },
        { "addTaskNearestSelectedCharacter", PlayerInterfaceBinding::addTaskNearestSelectedCharacter },
        { "updateLastMoveWaypointSelectedCharacters", PlayerInterfaceBinding::updateLastMoveWaypointSelectedCharacters },
        { "playerControl", PlayerInterfaceBinding::playerControl },
        { "characterSelected", PlayerInterfaceBinding::characterSelected },
        { "itemSelected", PlayerInterfaceBinding::itemSelected },
        { "buildingSelected", PlayerInterfaceBinding::buildingSelected },
        { "playerMove", PlayerInterfaceBinding::playerMove },
        { "_isPlayerCharacter", PlayerInterfaceBinding::_isPlayerCharacter },
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
