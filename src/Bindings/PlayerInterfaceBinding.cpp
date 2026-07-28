#include "pch.h"
#include "kenshi\PlayerInterface.h"
#include "PlayerInterfaceBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/CameraClassBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Gui/ContextMenuBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/FactoryCallbackInterfaceBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/InputHandlerBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/Gui/LevelEditorBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/RootObjectContainerBinding.h"
#include "Bindings/SelectionBoxBinding.h"
#include "Bindings/AIOptionsBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "CameraClassBinding.h"
#include "FactionBinding.h"
#include "PlatoonBinding.h"
#include "RootObjectBinding.h"
#include "RootObjectContainerBinding.h"
#include "Util/OgreUnorderedBinding.h"
#include "kenshi\CameraClass.h"
#include "kenshi\Platoon.h"
#include "kenshi\RootObject.h"
#include <kenshi/InputHandler.h>

namespace KenshiLua
{

static PlayerInterface* getInstance(lua_State* L, int idx)
{
    return checkObject<PlayerInterface>(L, idx, PlayerInterfaceBinding::getMetatableName());
}

// --- Getters for PlayerInterface ---
static int PlayerInterface_get_factionName(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushstring(L, instance->factionName.c_str());
    return 1;
}

static int PlayerInterface_get_camera(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<CameraClass>(L, instance->camera, CameraClassBinding::getMetatableName());
}

static int PlayerInterface_get_technology(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushlightuserdata(L, (void*)instance->technology);
    return 1;
}

static int PlayerInterface_get_selectedObjectsChangedThisFrame(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, instance->selectedObjectsChangedThisFrame ? 1 : 0);
    return 1;
}

static int PlayerInterface_get_contextMenu(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<ContextMenu>(L, &instance->contextMenu, ContextMenuBinding::getMetatableName());
}

static int PlayerInterface_get_selectBox(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<SelectionBox>(L, &instance->selectBox, SelectionBoxBinding::getMetatableName());
}

static int PlayerInterface_get_moveMarker(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushlightuserdata(L, (void*)instance->moveMarker);
    return 1;
}

static int PlayerInterface_get_selectedCharacter(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return handBinding::push(L, instance->selectedCharacter);
}

static int PlayerInterface_get_aiOptions(lua_State* L) { PlayerInterface* instance = getInstance(L, 1); if (!instance) return luaL_error(L, "PlayerInterface is nil"); return pushObject<PlayerInterface::AIOptions>(L, &instance->aiOptions, AIOptionsBinding::getMetatableName()); }

static int PlayerInterface_get_interiorsVisibleHash(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushinteger(L, instance->interiorsVisibleHash);
    return 1;
}

static int PlayerInterface_get_currentFloor(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushinteger(L, instance->currentFloor);
    return 1;
}

static int PlayerInterface_get_currentMouseTask(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentMouseTask);
    return 1;
}

static int PlayerInterface_get_mouseTaskTypeRestriction(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushinteger(L, (lua_Integer)instance->mouseTaskTypeRestriction);
    return 1;
}

static int PlayerInterface_get_mouseRightTargetSet(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, instance->mouseRightTargetSet ? 1 : 0);
    return 1;
}

static int PlayerInterface_get_mouseRightTarget(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<RootObject>(L, instance->mouseRightTarget, RootObjectBinding::getMetatableName());
}

static int PlayerInterface_get_rmouseTimer(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushnumber(L, instance->rmouseTimer);
    return 1;
}

static int PlayerInterface_get_selectedObject(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return handBinding::push(L, instance->selectedObject);
}

static int PlayerInterface_get_onlyAnimalsSelected(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, instance->onlyAnimalsSelected ? 1 : 0);
    return 1;
}

static int PlayerInterface_get_selectedLoadedLeft(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushinteger(L, instance->selectedLoadedLeft);
    return 1;
}

static int PlayerInterface_get_trackedCharacterHandle(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return handBinding::push(L, instance->trackedCharacterHandle);
}

static int PlayerInterface_get_trackedCharacterFloor(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushinteger(L, instance->trackedCharacterFloor);
    return 1;
}

static int PlayerInterface_get_levelEditor(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<LevelEditor>(L, instance->levelEditor, LevelEditorBinding::getMetatableName());
}

static int PlayerInterface_get_participant(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<Faction>(L, instance->participant, FactionBinding::getMetatableName());
}

static int PlayerInterface_get_currentPlatoon(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<Platoon>(L, instance->currentPlatoon, PlatoonBinding::getMetatableName());
}

static int PlayerInterface_get_deadPlayerSquad(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return handBinding::push(L, instance->deadPlayerSquad);
}

static int PlayerInterface_get_placementObject(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushlightuserdata(L, (void*)instance->placementObject);
    return 1;
}

static int PlayerInterface_get_characterEditorMode(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, instance->characterEditorMode ? 1 : 0);
    return 1;
}

static int PlayerInterface_get_mLeftUp(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, instance->mLeftUp ? 1 : 0);
    return 1;
}

static int PlayerInterface_get_mLeftDown(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, instance->mLeftDown ? 1 : 0);
    return 1;
}

static int PlayerInterface_get_mRightUp(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, instance->mRightUp ? 1 : 0);
    return 1;
}

static int PlayerInterface_get_mRightDown(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lua_pushboolean(L, instance->mRightDown ? 1 : 0);
    return 1;
}

// --- Setters for PlayerInterface ---
static int PlayerInterface_set_factionName(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->factionName = luaL_checkstring(L, 2);
    return 0;
}

static int PlayerInterface_set_camera(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->camera = lua_isnoneornil(L, 2) ? nullptr : checkObject<CameraClass>(L, 2, CameraClassBinding::getMetatableName());
    return 0;
}

static int PlayerInterface_set_selectedObjectsChangedThisFrame(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->selectedObjectsChangedThisFrame = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlayerInterface_set_contextMenu(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->contextMenu = *checkObject<ContextMenu>(L, 2, ContextMenuBinding::getMetatableName());
    return 0;
}

static int PlayerInterface_set_selectBox(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->selectBox = *checkObject<SelectionBox>(L, 2, SelectionBoxBinding::getMetatableName());
    return 0;
}

static int PlayerInterface_set_selectedCharacter(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->selectedCharacter = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int PlayerInterface_set_aiOptions(lua_State* L) { return 0; }

static int PlayerInterface_set_interiorsVisibleHash(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->interiorsVisibleHash = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int PlayerInterface_set_currentFloor(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->currentFloor = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int PlayerInterface_set_currentMouseTask(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->currentMouseTask = (TaskType)luaL_checkinteger(L, 2);
    return 0;
}

static int PlayerInterface_set_mouseTaskTypeRestriction(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->mouseTaskTypeRestriction = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int PlayerInterface_set_mouseRightTargetSet(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->mouseRightTargetSet = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlayerInterface_set_mouseRightTarget(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->mouseRightTarget = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    return 0;
}

static int PlayerInterface_set_rmouseTimer(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->rmouseTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int PlayerInterface_set_selectedObject(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->selectedObject = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int PlayerInterface_set_onlyAnimalsSelected(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->onlyAnimalsSelected = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlayerInterface_set_selectedLoadedLeft(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->selectedLoadedLeft = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int PlayerInterface_set_trackedCharacterHandle(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->trackedCharacterHandle = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int PlayerInterface_set_trackedCharacterFloor(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->trackedCharacterFloor = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int PlayerInterface_set_levelEditor(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->levelEditor = lua_isnoneornil(L, 2) ? nullptr : checkObject<LevelEditor>(L, 2, LevelEditorBinding::getMetatableName());
    return 0;
}

static int PlayerInterface_set_participant(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->participant = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int PlayerInterface_set_currentPlatoon(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->currentPlatoon = lua_isnoneornil(L, 2) ? nullptr : checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    return 0;
}

static int PlayerInterface_set_deadPlayerSquad(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->deadPlayerSquad = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int PlayerInterface_set_characterEditorMode(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->characterEditorMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlayerInterface_set_mLeftUp(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->mLeftUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlayerInterface_set_mLeftDown(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->mLeftDown = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlayerInterface_set_mRightUp(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->mRightUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlayerInterface_set_mRightDown(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->mRightDown = lua_toboolean(L, 2) != 0;
    return 0;
}

int PlayerInterfaceBinding::_CONSTRUCTOR(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    PlayerInterface* result = instance->_CONSTRUCTOR();
    return pushObject<PlayerInterface>(L, result, PlayerInterfaceBinding::getMetatableName());
}

int PlayerInterfaceBinding::_DESTRUCTOR(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int PlayerInterfaceBinding::getCamera(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    CameraClass* result = instance->getCamera();
    return pushObject<CameraClass>(L, result, CameraClassBinding::getMetatableName());
}

int PlayerInterfaceBinding::playerSetup(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    CameraClass* cam = checkObject<CameraClass>(L, 2, CameraClassBinding::getMetatableName());
    instance->playerSetup(cam);
    return 0;
}

int PlayerInterfaceBinding::clearAndReset(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    instance->clearAndReset();
    return 0;
}

int PlayerInterfaceBinding::factoryObjectCreatedCallback(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    RootObject* building = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->factoryObjectCreatedCallback(building);
    return 0;
}

int PlayerInterfaceBinding::_NV_factoryObjectCreatedCallback(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    RootObject* building = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->_NV_factoryObjectCreatedCallback(building);
    return 0;
}

int PlayerInterfaceBinding::setFaction(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->setFaction(f);
    return 0;
}

int PlayerInterfaceBinding::getFaction(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Faction* result = instance->getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int PlayerInterfaceBinding::setCurrentPlatoon(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Platoon* platoon = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    bool result = instance->setCurrentPlatoon(platoon);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::getCurrentPlatoon(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Platoon* result = instance->getCurrentPlatoon();
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int PlayerInterfaceBinding::getCurrentActivePlatoon(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    RootObjectContainer* result = instance->getCurrentActivePlatoon();
    return pushObject<RootObjectContainer>(L, result, RootObjectContainerBinding::getMetatableName());
}

int PlayerInterfaceBinding::createSquad(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    ActivePlatoon* result = instance->createSquad();
    return pushObject<ActivePlatoon>(L, result, ActivePlatoonBinding::getMetatableName());
}

int PlayerInterfaceBinding::getDeadSquad(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    ActivePlatoon* result = instance->getDeadSquad();
    return pushObject<ActivePlatoon>(L, result, ActivePlatoonBinding::getMetatableName());
}

int PlayerInterfaceBinding::update(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    instance->update();
    return 0;
}

int PlayerInterfaceBinding::updateUT(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    instance->updateUT();
    return 0;
}

int PlayerInterfaceBinding::isBuildMode(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    bool result = instance->isBuildMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::activateObjectPlacementMode(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->activateObjectPlacementMode(data);
    return 0;
}

int PlayerInterfaceBinding::activateCharacterEditMode(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->activateCharacterEditMode(character);
    return 0;
}

int PlayerInterfaceBinding::triggerAreaArrivalDialogue(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    GameData* area = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->triggerAreaArrivalDialogue(area);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::setCharacterEditMode(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setCharacterEditMode(on);
    return 0;
}

int PlayerInterfaceBinding::getCharacterEditMode(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    bool result = instance->getCharacterEditMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::unselectAll(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    instance->unselectAll();
    return 0;
}

int PlayerInterfaceBinding::selectAll(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    instance->selectAll();
    return 0;
}

int PlayerInterfaceBinding::selectObject(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool modifier = lua_toboolean(L, 3) != 0;
    instance->selectObject(obj, modifier);
    return 0;
}

int PlayerInterfaceBinding::selectPlayerCharacter(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    int index = (int)luaL_checkinteger(L, 2);
    bool modifier = lua_toboolean(L, 3) != 0;
    bool track = lua_toboolean(L, 4) != 0;
    instance->selectPlayerCharacter(index, modifier, track);
    return 0;
}

int PlayerInterfaceBinding::_selectPlayerCharacter(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool modifier = lua_toboolean(L, 3) != 0;
    bool track = lua_toboolean(L, 4) != 0;
    instance->_selectPlayerCharacter(obj, modifier, track);
    return 0;
}

int PlayerInterfaceBinding::activateSelection(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->activateSelection(obj);
    return 0;
}

int PlayerInterfaceBinding::getCameraCenter(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    const Ogre::Vector3 result = instance->getCameraCenter();
    pushVector3(L, result);
    return 1;
}

int PlayerInterfaceBinding::getDistanceFromCamera(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    float result = instance->getDistanceFromCamera(v);
    lua_pushnumber(L, result);
    return 1;
}

int PlayerInterfaceBinding::getSquaredDistanceFromCamera(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    float result = instance->getSquaredDistanceFromCamera(v);
    lua_pushnumber(L, result);
    return 1;
}

int PlayerInterfaceBinding::startTrackCharacter(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    RootObject* target = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->startTrackCharacter(target);
    return 0;
}

int PlayerInterfaceBinding::stopTrackCharacter(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    instance->stopTrackCharacter();
    return 0;
}

int PlayerInterfaceBinding::isTrackingCharacter(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    bool result = instance->isTrackingCharacter();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::focusCamera(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    instance->focusCamera(pos);
    return 0;
}

int PlayerInterfaceBinding::manuallyOrientCamera(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Quaternion rot;
    readQuaternion(L, 2, rot);
    float zoom = (float)luaL_checknumber(L, 3);
    instance->manuallyOrientCamera(rot, zoom);
    return 0;
}

int PlayerInterfaceBinding::focusCameraSelectedCharacter(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    instance->focusCameraSelectedCharacter();
    return 0;
}

int PlayerInterfaceBinding::toggleLevelEditorOnSelectedTown(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    instance->toggleLevelEditorOnSelectedTown();
    return 0;
}

int PlayerInterfaceBinding::isLevelEditMode(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    bool result = instance->isLevelEditMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::isObjectPlacementMode(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    bool result = instance->isObjectPlacementMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::setOrderSelectedCharacters(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    MessageForB::StandingOrder order = (MessageForB::StandingOrder)luaL_checkinteger(L, 2);
    instance->setOrderSelectedCharacters(order);
    return 0;
}

int PlayerInterfaceBinding::getLevelEditor(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    LevelEditor* result = instance->getLevelEditor();
    return pushObject<LevelEditor>(L, result, LevelEditorBinding::getMetatableName());
}

int PlayerInterfaceBinding::objectSelected(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool select = lua_toboolean(L, 3) != 0;
    instance->objectSelected(obj, select);
    return 0;
}

int PlayerInterfaceBinding::toggleObjectSelected(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->toggleObjectSelected(obj);
    return 0;
}

int PlayerInterfaceBinding::isObjectSelected(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->isObjectSelected(obj);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::unselectPlayerCharacter(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->unselectPlayerCharacter(obj);
    return 0;
}

int PlayerInterfaceBinding::getCurrentFloor(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    int result = instance->getCurrentFloor();
    lua_pushinteger(L, result);
    return 1;
}

int PlayerInterfaceBinding::setCurrentFloor(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    int floor = (int)luaL_checkinteger(L, 2);
    instance->setCurrentFloor(floor);
    return 0;
}

int PlayerInterfaceBinding::getNearestSelectedCharacterTo(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Character* result = instance->getNearestSelectedCharacterTo(pos);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int PlayerInterfaceBinding::getNearestCharacterTo(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Character* result = instance->getNearestCharacterTo(pos);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int PlayerInterfaceBinding::addOrderSelectedCharacters(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Building* destinationIndoors = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    TaskType task = (TaskType)luaL_checkinteger(L, 3);
    RootObject* subject = checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
    bool shift = lua_toboolean(L, 5) != 0;
    bool addDontClear = lua_toboolean(L, 6) != 0;
    Ogre::Vector3 location;
    readVector3(L, 7, location);
    instance->addOrderSelectedCharacters(destinationIndoors, task, subject, shift, addDontClear, location);
    return 0;
}

int PlayerInterfaceBinding::addJobSelectedCharacters(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    TaskType task = (TaskType)luaL_checkinteger(L, 2);
    RootObject* subject = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    bool shift = lua_toboolean(L, 4) != 0;
    bool add = lua_toboolean(L, 5) != 0;
    Ogre::Vector3 location;
    readVector3(L, 6, location);
    instance->addJobSelectedCharacters(task, subject, shift, add, location);
    return 0;
}

int PlayerInterfaceBinding::removeJobSelectedCharacters(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    instance->removeJobSelectedCharacters(t);
    return 0;
}

int PlayerInterfaceBinding::removePermaJobSelectedCharacters(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    int id = (int)luaL_checkinteger(L, 2);
    instance->removePermaJobSelectedCharacters(id);
    return 0;
}

int PlayerInterfaceBinding::selectedCharactersUnconcious(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    bool displayMessage = lua_toboolean(L, 2) != 0;
    bool result = instance->selectedCharactersUnconcious(displayMessage);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::selectedCharactersLayingLow(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    bool result = instance->selectedCharactersLayingLow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::useSpeedGroup(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    bool use = lua_toboolean(L, 2) != 0;
    instance->useSpeedGroup(use);
    return 0;
}

int PlayerInterfaceBinding::assignSpeedGroup(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    bool create = lua_toboolean(L, 2) != 0;
    instance->assignSpeedGroup(create);
    return 0;
}

int PlayerInterfaceBinding::isEnemy(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->isEnemy(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::isFactionKnown(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->isFactionKnown(f);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::encounterFaction(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Faction* faction = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->encounterFaction(faction);
    return 0;
}

int PlayerInterfaceBinding::pickupItem(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->pickupItem(item);
    return 0;
}

int PlayerInterfaceBinding::cycleSquad(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    instance->cycleSquad();
    return 0;
}

int PlayerInterfaceBinding::cycleCharacter(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    int d = (int)luaL_checkinteger(L, 2);
    instance->cycleCharacter(d);
    return 0;
}

int PlayerInterfaceBinding::stopCharactersMovement(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    instance->stopCharactersMovement();
    return 0;
}

int PlayerInterfaceBinding::getAnyPlayerCharacter(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Character* result = instance->getAnyPlayerCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int PlayerInterfaceBinding::isOrderValidForSelection(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    TaskType task = (TaskType)luaL_checkinteger(L, 2);
    bool result = instance->isOrderValidForSelection(task);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::serialise(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->serialise(data);
    return 0;
}

int PlayerInterfaceBinding::loadFromSerialise(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->loadFromSerialise(data);
    return 0;
}

int PlayerInterfaceBinding::getInteriorsVisible(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    bool result = instance->getInteriorsVisible(building);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::setVisibilityForReflections(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    bool set = lua_toboolean(L, 2) != 0;
    instance->setVisibilityForReflections(set);
    return 0;
}

int PlayerInterfaceBinding::resetFloorsVisibility(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    instance->resetFloorsVisibility();
    return 0;
}

int PlayerInterfaceBinding::setFloorsVisibility(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    int floor = (int)luaL_checkinteger(L, 2);
    instance->setFloorsVisibility(floor);
    return 0;
}

int PlayerInterfaceBinding::addTaskNearestSelectedCharacter(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Building* dest = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    TaskType t = (TaskType)luaL_checkinteger(L, 3);
    RootObject* subject = checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
    bool shift = lua_toboolean(L, 5) != 0;
    Ogre::Vector3 location;
    readVector3(L, 6, location);
    bool noAnimals = lua_toboolean(L, 7) != 0;
    instance->addTaskNearestSelectedCharacter(dest, t, subject, shift, location, noAnimals);
    return 0;
}

int PlayerInterfaceBinding::updateLastMoveWaypointSelectedCharacters(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Vector3 location;
    readVector3(L, 2, location);
    Building* dest = checkObject<Building>(L, 3, BuildingBinding::getMetatableName());
    instance->updateLastMoveWaypointSelectedCharacters(location, dest);
    return 0;
}

int PlayerInterfaceBinding::clearSelection(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    instance->clearSelection();
    return 0;
}

int PlayerInterfaceBinding::mouseScan(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    instance->mouseScan();
    return 0;
}

int PlayerInterfaceBinding::characterSelected(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->characterSelected(target);
    return 0;
}

int PlayerInterfaceBinding::itemSelected(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->itemSelected(item);
    return 0;
}

int PlayerInterfaceBinding::buildingSelected(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    bool interiorsVisible = lua_toboolean(L, 4) != 0;
    bool result = instance->buildingSelected(building, position, interiorsVisible);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlayerInterfaceBinding::playerMove(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Building* destBuilding = checkObject<Building>(L, 3, BuildingBinding::getMetatableName());
    instance->playerMove(pos, destBuilding);
    return 0;
}

int PlayerInterfaceBinding::_isPlayerCharacter(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");

    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->_isPlayerCharacter(obj);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 94: bool recruit(...) - overloaded method
  line 95: bool recruit(...) - overloaded method
  line 98: const hand& getDeadSquadHandle(...) - reference return type
  line 132: void updatePlayerSelection(...) - non-string reference arg
  line 135: void getAllSelectedObjects(...) - unsupported arg type
  line 138: void newPlayerTaskSelectedCharacters(...) - non-string reference arg
  line 139: bool getPlayerTaskProbability(...) - non-string reference arg
  line 156: void getAllPlayerCharacters(...) - overloaded method
  line 157: const lektor<Character*>& getAllPlayerCharacters(...) - overloaded method
  line 194: void updateFloorVisibility(...) - unsupported arg type
  line 200: void playerControl(...) - non-string reference arg
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - PlayerInterface_get_technology: Research* (unbound pointer)
  - PlayerInterface_get_moveMarker: MoveMarker* (unbound pointer)
  - PlayerInterface_get_placementObject: PlacementObject* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 209: zonesVisibilities (ogre_unordered_map<ZoneMap*, unsigned char>::type) - unsupported type
  line 210: townsActive (ogre_unordered_set<TownBase*>::type) - unsupported type
  line 211: interiorsVisible (ogre_unordered_set<hand>::type) - unsupported type
  line 219: selectedCharacters (ogre_unordered_set<hand>::type) - unsupported type
  line 228: playerCharacters (lektor<Character*>) - unsupported type
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



static int PlayerInterface_get_interiorsVisible(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<ogre_unordered_set<hand>::type>(L, &instance->interiorsVisible, OgreUnorderedSetBinding<hand>::getMetatableName());
}


static int PlayerInterface_get_playerCharacters(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<lektor<Character*>>(L, &instance->playerCharacters, "lektor<Character*>");
}


static int PlayerInterface_get_selectedCharacters(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<ogre_unordered_set<hand>::type>(L, &instance->selectedCharacters, OgreUnorderedSetBinding<hand>::getMetatableName());
}


static int PlayerInterface_get_townsActive(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<ogre_unordered_set<TownBase*>::type>(L, &instance->townsActive, "ogre_unordered_set<TownBase*>");
}


static int PlayerInterface_get_zonesVisibilities(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    return pushObject<ogre_unordered_map<ZoneMap*, unsigned char>::type>(L, &instance->zonesVisibilities, "ogre_unordered_map<ZoneMap*, unsigned char>");
}


static int PlayerInterface_set_interiorsVisible(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->interiorsVisible = *checkObject<ogre_unordered_set<hand>::type>(L, 2, OgreUnorderedSetBinding<hand>::getMetatableName());
    return 0;
}


static int PlayerInterface_set_moveMarker(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->moveMarker = (MoveMarker*)lua_touserdata(L, 2);
    return 0;
}


static int PlayerInterface_set_placementObject(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->placementObject = (PlacementObject*)lua_touserdata(L, 2);
    return 0;
}


static int PlayerInterface_set_playerCharacters(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lektor<Character*>* src = LektorPtrBinding<Character*>::get(L, 2);
    instance->playerCharacters = *src;
    return 0;
}


static int PlayerInterface_set_selectedCharacters(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->selectedCharacters = *checkObject<ogre_unordered_set<hand>::type>(L, 2, OgreUnorderedSetBinding<hand>::getMetatableName());
    return 0;
}


static int PlayerInterface_set_technology(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->technology = (Research*)lua_touserdata(L, 2);
    return 0;
}


static int PlayerInterface_set_townsActive(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->townsActive = *checkObject<ogre_unordered_set<TownBase*>::type>(L, 2, "ogre_unordered_set<TownBase*>");
    return 0;
}


static int PlayerInterface_set_zonesVisibilities(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    instance->zonesVisibilities = *checkObject<ogre_unordered_map<ZoneMap*, unsigned char>::type>(L, 2, "ogre_unordered_map<ZoneMap*, unsigned char>");
    return 0;
}


int PlayerInterfaceBinding::getAllPlayerCharacters(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    
    if (lua_gettop(L) >= 2) {
        lektor<RootObject*>* list = checkObject<lektor<RootObject*>>(L, 2, "lektor<RootObject*>");
        instance->getAllPlayerCharacters(*list);
        return 0;
    } else {
        const lektor<Character*>& result = instance->getAllPlayerCharacters();
        return pushObject<lektor<Character*>>(L, const_cast<lektor<Character*>*>(&result), "lektor<Character*>");
    }
}


int PlayerInterfaceBinding::getAllSelectedObjects(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lektor<RootObject*>* out = checkObject<lektor<RootObject*>>(L, 2, "lektor<RootObject*>");
    itemType type = (itemType)luaL_checkinteger(L, 3);
    instance->getAllSelectedObjects(*out, type);
    return 0;
}


int PlayerInterfaceBinding::getDeadSquadHandle(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    const hand& res = instance->getDeadSquadHandle();
    return pushObject<hand>(L, new hand(res), handBinding::getMetatableName());
}


int PlayerInterfaceBinding::getPlayerTaskProbability(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    TaskType task = (TaskType)luaL_checkinteger(L, 2);
    RootObject* target = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    float probability = 0.0f;
    bool result = instance->getPlayerTaskProbability(task, target, probability);
    lua_pushboolean(L, result ? 1 : 0);
    lua_pushnumber(L, probability);
    return 2;
}


int PlayerInterfaceBinding::newPlayerTaskSelectedCharacters(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    hand* targetH = checkObject<hand>(L, 3, handBinding::getMetatableName());
    Building* destinationIndoors = nullptr;
    if (!lua_isnil(L, 4)) {
        destinationIndoors = checkObject<Building>(L, 4, BuildingBinding::getMetatableName());
    }
    Ogre::Vector3 clickpos;
    readVector3(L, 5, clickpos);
    bool addDontClear = lua_toboolean(L, 6) != 0;
    instance->newPlayerTaskSelectedCharacters(t, *targetH, destinationIndoors, clickpos, addDontClear);
    return 0;
}


int PlayerInterfaceBinding::playerControl(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    InputHandler* key = checkObject<InputHandler>(L, 2, InputHandlerBinding::getMetatableName());
    instance->playerControl(*key);
    return 0;
}


int PlayerInterfaceBinding::recruit(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    bool editor = lua_toboolean(L, 3) != 0;
    bool res = false;
    if (testObject<lektor<Character*>>(L, 2, "lektor<Character*>") != nullptr) {
        lektor<Character*>* list = LektorPtrBinding<Character*>::get(L, 2);
        res = instance->recruit(*list, editor);
    } else {
        Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
        res = instance->recruit(c, editor);
    }
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


int PlayerInterfaceBinding::updateFloorVisibility(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    lektor<Character*>* characters = checkObject<lektor<Character*>>(L, 2, "lektor<Character*>");
    instance->updateFloorVisibility(*characters);
    return 0;
}


int PlayerInterfaceBinding::updatePlayerSelection(lua_State* L)
{
    PlayerInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlayerInterface is nil");
    hand* oldHandle = checkObject<hand>(L, 2, handBinding::getMetatableName());
    hand* newHandle = checkObject<hand>(L, 3, handBinding::getMetatableName());
    instance->updatePlayerSelection(*oldHandle, *newHandle);
    return 0;
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
        { "playerSetup", PlayerInterfaceBinding::playerSetup },
        { "clearAndReset", PlayerInterfaceBinding::clearAndReset },
        { "factoryObjectCreatedCallback", PlayerInterfaceBinding::factoryObjectCreatedCallback },
        { "_NV_factoryObjectCreatedCallback", PlayerInterfaceBinding::_NV_factoryObjectCreatedCallback },
        { "setFaction", PlayerInterfaceBinding::setFaction },
        { "getFaction", PlayerInterfaceBinding::getFaction },
        { "setCurrentPlatoon", PlayerInterfaceBinding::setCurrentPlatoon },
        { "getCurrentPlatoon", PlayerInterfaceBinding::getCurrentPlatoon },
        { "getCurrentActivePlatoon", PlayerInterfaceBinding::getCurrentActivePlatoon },
        { "createSquad", PlayerInterfaceBinding::createSquad },
        { "getDeadSquad", PlayerInterfaceBinding::getDeadSquad },
        { "update", PlayerInterfaceBinding::update },
        { "updateUT", PlayerInterfaceBinding::updateUT },
        { "isBuildMode", PlayerInterfaceBinding::isBuildMode },
        { "activateObjectPlacementMode", PlayerInterfaceBinding::activateObjectPlacementMode },
        { "activateCharacterEditMode", PlayerInterfaceBinding::activateCharacterEditMode },
        { "triggerAreaArrivalDialogue", PlayerInterfaceBinding::triggerAreaArrivalDialogue },
        { "setCharacterEditMode", PlayerInterfaceBinding::setCharacterEditMode },
        { "getCharacterEditMode", PlayerInterfaceBinding::getCharacterEditMode },
        { "unselectAll", PlayerInterfaceBinding::unselectAll },
        { "selectAll", PlayerInterfaceBinding::selectAll },
        { "selectObject", PlayerInterfaceBinding::selectObject },
        { "selectPlayerCharacter", PlayerInterfaceBinding::selectPlayerCharacter },
        { "_selectPlayerCharacter", PlayerInterfaceBinding::_selectPlayerCharacter },
        { "activateSelection", PlayerInterfaceBinding::activateSelection },
        { "getCameraCenter", PlayerInterfaceBinding::getCameraCenter },
        { "getDistanceFromCamera", PlayerInterfaceBinding::getDistanceFromCamera },
        { "getSquaredDistanceFromCamera", PlayerInterfaceBinding::getSquaredDistanceFromCamera },
        { "startTrackCharacter", PlayerInterfaceBinding::startTrackCharacter },
        { "stopTrackCharacter", PlayerInterfaceBinding::stopTrackCharacter },
        { "isTrackingCharacter", PlayerInterfaceBinding::isTrackingCharacter },
        { "focusCamera", PlayerInterfaceBinding::focusCamera },
        { "manuallyOrientCamera", PlayerInterfaceBinding::manuallyOrientCamera },
        { "focusCameraSelectedCharacter", PlayerInterfaceBinding::focusCameraSelectedCharacter },
        { "toggleLevelEditorOnSelectedTown", PlayerInterfaceBinding::toggleLevelEditorOnSelectedTown },
        { "isLevelEditMode", PlayerInterfaceBinding::isLevelEditMode },
        { "isObjectPlacementMode", PlayerInterfaceBinding::isObjectPlacementMode },
        { "setOrderSelectedCharacters", PlayerInterfaceBinding::setOrderSelectedCharacters },
        { "getLevelEditor", PlayerInterfaceBinding::getLevelEditor },
        { "objectSelected", PlayerInterfaceBinding::objectSelected },
        { "toggleObjectSelected", PlayerInterfaceBinding::toggleObjectSelected },
        { "isObjectSelected", PlayerInterfaceBinding::isObjectSelected },
        { "unselectPlayerCharacter", PlayerInterfaceBinding::unselectPlayerCharacter },
        { "getCurrentFloor", PlayerInterfaceBinding::getCurrentFloor },
        { "setCurrentFloor", PlayerInterfaceBinding::setCurrentFloor },
        { "getNearestSelectedCharacterTo", PlayerInterfaceBinding::getNearestSelectedCharacterTo },
        { "getNearestCharacterTo", PlayerInterfaceBinding::getNearestCharacterTo },
        { "addOrderSelectedCharacters", PlayerInterfaceBinding::addOrderSelectedCharacters },
        { "addJobSelectedCharacters", PlayerInterfaceBinding::addJobSelectedCharacters },
        { "removeJobSelectedCharacters", PlayerInterfaceBinding::removeJobSelectedCharacters },
        { "removePermaJobSelectedCharacters", PlayerInterfaceBinding::removePermaJobSelectedCharacters },
        { "selectedCharactersUnconcious", PlayerInterfaceBinding::selectedCharactersUnconcious },
        { "selectedCharactersLayingLow", PlayerInterfaceBinding::selectedCharactersLayingLow },
        { "useSpeedGroup", PlayerInterfaceBinding::useSpeedGroup },
        { "assignSpeedGroup", PlayerInterfaceBinding::assignSpeedGroup },
        { "isEnemy", PlayerInterfaceBinding::isEnemy },
        { "isFactionKnown", PlayerInterfaceBinding::isFactionKnown },
        { "encounterFaction", PlayerInterfaceBinding::encounterFaction },
        { "pickupItem", PlayerInterfaceBinding::pickupItem },
        { "cycleSquad", PlayerInterfaceBinding::cycleSquad },
        { "cycleCharacter", PlayerInterfaceBinding::cycleCharacter },
        { "stopCharactersMovement", PlayerInterfaceBinding::stopCharactersMovement },
        { "getAnyPlayerCharacter", PlayerInterfaceBinding::getAnyPlayerCharacter },
        { "isOrderValidForSelection", PlayerInterfaceBinding::isOrderValidForSelection },
        { "serialise", PlayerInterfaceBinding::serialise },
        { "loadFromSerialise", PlayerInterfaceBinding::loadFromSerialise },
        { "getInteriorsVisible", PlayerInterfaceBinding::getInteriorsVisible },
        { "setVisibilityForReflections", PlayerInterfaceBinding::setVisibilityForReflections },
        { "resetFloorsVisibility", PlayerInterfaceBinding::resetFloorsVisibility },
        { "setFloorsVisibility", PlayerInterfaceBinding::setFloorsVisibility },
        { "addTaskNearestSelectedCharacter", PlayerInterfaceBinding::addTaskNearestSelectedCharacter },
        { "updateLastMoveWaypointSelectedCharacters", PlayerInterfaceBinding::updateLastMoveWaypointSelectedCharacters },
        { "clearSelection", PlayerInterfaceBinding::clearSelection },
        { "mouseScan", PlayerInterfaceBinding::mouseScan },
        { "characterSelected", PlayerInterfaceBinding::characterSelected },
        { "itemSelected", PlayerInterfaceBinding::itemSelected },
        { "buildingSelected", PlayerInterfaceBinding::buildingSelected },
        { "playerMove", PlayerInterfaceBinding::playerMove },
        { "_isPlayerCharacter", PlayerInterfaceBinding::_isPlayerCharacter },
                { "recruit", PlayerInterfaceBinding::recruit },
        { "getDeadSquadHandle", PlayerInterfaceBinding::getDeadSquadHandle },
        { "updatePlayerSelection", PlayerInterfaceBinding::updatePlayerSelection },
        { "getAllSelectedObjects", PlayerInterfaceBinding::getAllSelectedObjects },
        { "newPlayerTaskSelectedCharacters", PlayerInterfaceBinding::newPlayerTaskSelectedCharacters },
        { "getPlayerTaskProbability", PlayerInterfaceBinding::getPlayerTaskProbability },
        { "getAllPlayerCharacters", PlayerInterfaceBinding::getAllPlayerCharacters },
        { "updateFloorVisibility", PlayerInterfaceBinding::updateFloorVisibility },
        { "playerControl", PlayerInterfaceBinding::playerControl },
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
    registerGetter(L, "factionName", PlayerInterface_get_factionName);
    registerGetter(L, "camera", PlayerInterface_get_camera);
    registerGetter(L, "technology", PlayerInterface_get_technology);
    registerGetter(L, "selectedObjectsChangedThisFrame", PlayerInterface_get_selectedObjectsChangedThisFrame);
    registerGetter(L, "contextMenu", PlayerInterface_get_contextMenu);
    registerGetter(L, "selectBox", PlayerInterface_get_selectBox);
    registerGetter(L, "moveMarker", PlayerInterface_get_moveMarker);
    registerGetter(L, "selectedCharacter", PlayerInterface_get_selectedCharacter);
    registerGetter(L, "aiOptions", PlayerInterface_get_aiOptions);
    registerGetter(L, "interiorsVisibleHash", PlayerInterface_get_interiorsVisibleHash);
    registerGetter(L, "currentFloor", PlayerInterface_get_currentFloor);
    registerGetter(L, "currentMouseTask", PlayerInterface_get_currentMouseTask);
    registerGetter(L, "mouseTaskTypeRestriction", PlayerInterface_get_mouseTaskTypeRestriction);
    registerGetter(L, "mouseRightTargetSet", PlayerInterface_get_mouseRightTargetSet);
    registerGetter(L, "mouseRightTarget", PlayerInterface_get_mouseRightTarget);
    registerGetter(L, "rmouseTimer", PlayerInterface_get_rmouseTimer);
    registerGetter(L, "selectedObject", PlayerInterface_get_selectedObject);
    registerGetter(L, "onlyAnimalsSelected", PlayerInterface_get_onlyAnimalsSelected);
    registerGetter(L, "selectedLoadedLeft", PlayerInterface_get_selectedLoadedLeft);
    registerGetter(L, "trackedCharacterHandle", PlayerInterface_get_trackedCharacterHandle);
    registerGetter(L, "trackedCharacterFloor", PlayerInterface_get_trackedCharacterFloor);
    registerGetter(L, "levelEditor", PlayerInterface_get_levelEditor);
    registerGetter(L, "participant", PlayerInterface_get_participant);
    registerGetter(L, "currentPlatoon", PlayerInterface_get_currentPlatoon);
    registerGetter(L, "deadPlayerSquad", PlayerInterface_get_deadPlayerSquad);
    registerGetter(L, "placementObject", PlayerInterface_get_placementObject);
    registerGetter(L, "characterEditorMode", PlayerInterface_get_characterEditorMode);
    registerGetter(L, "mLeftUp", PlayerInterface_get_mLeftUp);
    registerGetter(L, "mLeftDown", PlayerInterface_get_mLeftDown);
    registerGetter(L, "mRightUp", PlayerInterface_get_mRightUp);
    registerGetter(L, "mRightDown", PlayerInterface_get_mRightDown);
        registerGetter(L, "playerCharacters", PlayerInterface_get_playerCharacters);
        registerGetter(L, "selectedCharacters", PlayerInterface_get_selectedCharacters);
        registerGetter(L, "townsActive", PlayerInterface_get_townsActive);
        registerGetter(L, "zonesVisibilities", PlayerInterface_get_zonesVisibilities);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "factionName", PlayerInterface_set_factionName);
    registerSetter(L, "camera", PlayerInterface_set_camera);
    registerSetter(L, "selectedObjectsChangedThisFrame", PlayerInterface_set_selectedObjectsChangedThisFrame);
    registerSetter(L, "contextMenu", PlayerInterface_set_contextMenu);
    registerSetter(L, "selectBox", PlayerInterface_set_selectBox);
    registerSetter(L, "selectedCharacter", PlayerInterface_set_selectedCharacter);
    registerSetter(L, "aiOptions", PlayerInterface_set_aiOptions);
    registerSetter(L, "interiorsVisibleHash", PlayerInterface_set_interiorsVisibleHash);
    registerSetter(L, "currentFloor", PlayerInterface_set_currentFloor);
    registerSetter(L, "currentMouseTask", PlayerInterface_set_currentMouseTask);
    registerSetter(L, "mouseTaskTypeRestriction", PlayerInterface_set_mouseTaskTypeRestriction);
    registerSetter(L, "mouseRightTargetSet", PlayerInterface_set_mouseRightTargetSet);
    registerSetter(L, "mouseRightTarget", PlayerInterface_set_mouseRightTarget);
    registerSetter(L, "rmouseTimer", PlayerInterface_set_rmouseTimer);
    registerSetter(L, "selectedObject", PlayerInterface_set_selectedObject);
    registerSetter(L, "onlyAnimalsSelected", PlayerInterface_set_onlyAnimalsSelected);
    registerSetter(L, "selectedLoadedLeft", PlayerInterface_set_selectedLoadedLeft);
    registerSetter(L, "trackedCharacterHandle", PlayerInterface_set_trackedCharacterHandle);
    registerSetter(L, "trackedCharacterFloor", PlayerInterface_set_trackedCharacterFloor);
    registerSetter(L, "levelEditor", PlayerInterface_set_levelEditor);
    registerSetter(L, "participant", PlayerInterface_set_participant);
    registerSetter(L, "currentPlatoon", PlayerInterface_set_currentPlatoon);
    registerSetter(L, "deadPlayerSquad", PlayerInterface_set_deadPlayerSquad);
    registerSetter(L, "characterEditorMode", PlayerInterface_set_characterEditorMode);
    registerSetter(L, "mLeftUp", PlayerInterface_set_mLeftUp);
    registerSetter(L, "mLeftDown", PlayerInterface_set_mLeftDown);
    registerSetter(L, "mRightUp", PlayerInterface_set_mRightUp);
    registerSetter(L, "mRightDown", PlayerInterface_set_mRightDown);
        registerSetter(L, "moveMarker", PlayerInterface_set_moveMarker);
        registerSetter(L, "placementObject", PlayerInterface_set_placementObject);
        registerSetter(L, "playerCharacters", PlayerInterface_set_playerCharacters);
        registerSetter(L, "selectedCharacters", PlayerInterface_set_selectedCharacters);
        registerSetter(L, "technology", PlayerInterface_set_technology);
        registerSetter(L, "townsActive", PlayerInterface_set_townsActive);
        registerSetter(L, "zonesVisibilities", PlayerInterface_set_zonesVisibilities);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to FactoryCallbackInterface
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, PlayerInterfaceBinding::getMetatableName(), FactoryCallbackInterfaceBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua