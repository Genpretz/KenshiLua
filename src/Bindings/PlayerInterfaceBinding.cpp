#include "pch.h"
#include "Bindings/PlayerInterfaceBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/HandBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/CameraClassBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/BuildingBinding.h"
#include "Bindings/ItemBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/PlayerInterface.h>
#include <kenshi/Faction.h>
#include <kenshi/Character.h>
#include <kenshi/Platoon.h>

namespace KenshiLua
{

    static PlayerInterface* getP(lua_State* L, int idx)
    {
        return checkObject<PlayerInterface>(L, idx, PlayerInterfaceBinding::getMetatableName());
    }

    int PlayerInterfaceBinding::gc(lua_State* L)       { return noopGc(L); }

    int PlayerInterfaceBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        // 1. Check the metatable first so obj:method() syntax continues to work.
        luaL_getmetatable(L, PlayerInterfaceBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;   // found a method - return it
        lua_pop(L, 2);  // pop nil result + metatable

        // 2. Fall through to raw member variable access.
        PlayerInterface* p = getP(L, 1);
        if (!p) { lua_pushnil(L); return 1; }

        // --- boolean members ---
        if (strcmp(key, "isBuildMode") == 0) { lua_pushboolean(L, p->isBuildMode() ? 1 : 0); return 1; }
        if (strcmp(key, "characterEditorMode") == 0) { lua_pushboolean(L, p->characterEditorMode ? 1 : 0); return 1; }
        if (strcmp(key, "mouseRightTargetSet") == 0) { lua_pushboolean(L, p->mouseRightTargetSet ? 1 : 0); return 1; }
        if (strcmp(key, "onlyAnimalsSelected") == 0) { lua_pushboolean(L, p->onlyAnimalsSelected ? 1 : 0); return 1; }

        // --- integer/float/enum members ---
        if (strcmp(key, "currentFloor") == 0) { lua_pushinteger(L, p->currentFloor); return 1; }
        if (strcmp(key, "currentMouseTask") == 0) { lua_pushinteger(L, (int)p->currentMouseTask); return 1; }
        if (strcmp(key, "mouseTaskTypeRestriction") == 0) { lua_pushinteger(L, (int)p->mouseTaskTypeRestriction); return 1; }
        if (strcmp(key, "rmouseTimer") == 0) { lua_pushnumber(L, p->rmouseTimer); return 1; }
        if (strcmp(key, "selectedLoadedLeft") == 0) { lua_pushinteger(L, p->selectedLoadedLeft); return 1; }
        if (strcmp(key, "trackedCharacterFloor") == 0) { lua_pushinteger(L, p->trackedCharacterFloor); return 1; }

        // --- unique object members ---
        if (strcmp(key, "faction") == 0) {
            return pushObject<Faction>(L, p->getFaction(), FactionBinding::getMetatableName());
        }
        if (strcmp(key, "anyPlayerCharacter") == 0) {
            return pushObject<Character>(L, p->getAnyPlayerCharacter(), CharacterBinding::getMetatableName());
        }
        if (strcmp(key, "selectedCharacter") == 0 || strcmp(key, "selectedCharacterHandle") == 0) {
            return HandBinding::pushHand(L, p->selectedCharacter);
        }
        if (strcmp(key, "selectedObject") == 0) {
            return HandBinding::pushHand(L, p->selectedObject);
        }
        if (strcmp(key, "camera") == 0) {
            return pushObject<CameraClass>(L, p->camera, CameraClassBinding::getMetatableName());
        }
        if (strcmp(key, "factionName") == 0) {
            lua_pushstring(L, p->factionName.c_str());
            return 1;
        }
        if (strcmp(key, "participant") == 0) {
            return pushObject<Faction>(L, p->participant, FactionBinding::getMetatableName());
        }
        if (strcmp(key, "currentPlatoon") == 0) {
            if (!p->currentPlatoon) { lua_pushnil(L); return 1; }
            ActivePlatoon* ap = p->currentPlatoon->activePlatoon;
            if (ap) return pushObject<ActivePlatoon>(L, ap, PlatoonBinding::getMetatableName());
            return pushObject<Platoon>(L, p->currentPlatoon, PlatoonBinding::getMetatableName());
        }
        if (strcmp(key, "technology") == 0) {
            if (p->technology) lua_pushlightuserdata(L, (void*)p->technology);
            else              lua_pushnil(L);
            return 1;
        }
        if (strcmp(key, "playerCharacters") == 0) {
            lua_createtable(L, p->playerCharacters.size(), 0);
            for (uint32_t i = 0; i < p->playerCharacters.size(); ++i) {
                pushObject<Character>(L, p->playerCharacters[i], CharacterBinding::getMetatableName());
                lua_rawseti(L, -2, i + 1);
            }
            return 1;
        }
        if (strcmp(key, "deadPlayerSquad") == 0) {
            return HandBinding::pushHand(L, p->deadPlayerSquad);
        }
        if (strcmp(key, "mouseRightTarget") == 0) {
            return pushObject<RootObject>(L, p->mouseRightTarget, RootObjectBinding::getMetatableName());
        }
        if (strcmp(key, "selectedCharacters") == 0) {
            lua_createtable(L, p->selectedCharacters.size(), 0);
            int i = 1;
            for (ogre_unordered_set<hand>::type::iterator it = p->selectedCharacters.begin(); it != p->selectedCharacters.end(); ++it) {
                HandBinding::pushHand(L, *it);
                lua_rawseti(L, -2, i++);
            }
            return 1;
        }
        if (strcmp(key, "trackedCharacterHandle") == 0) {
            return HandBinding::pushHand(L, p->trackedCharacterHandle);
        }
        if (strcmp(key, "placementObject") == 0) {
            if (p->placementObject) lua_pushlightuserdata(L, (void*)p->placementObject);
            else                    lua_pushnil(L);
            return 1;
        }

        lua_pushnil(L);
        return 1;
    }

    int PlayerInterfaceBinding::newindex(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");

        // --- writable properties ---
        if (strcmp(key, "currentFloor") == 0) {
            p->currentFloor = (int)luaL_checkinteger(L, 3);
            return 0;
        }
        if (strcmp(key, "characterEditorMode") == 0) {
            p->characterEditorMode = (lua_toboolean(L, 3) != 0);
            return 0;
        }
        if (strcmp(key, "camera") == 0) {
            return luaL_error(L, "PlayerInterface: camera is read-only");
        }
        if (strcmp(key, "factionName") == 0) {
            p->factionName = luaL_checkstring(L, 3);
            return 0;
        }
        if (strcmp(key, "deadPlayerSquad") == 0) {
            hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
            if (!h) return luaL_error(L, "expected hand userdata");
            p->deadPlayerSquad = *h;
            return 0;
        }
        if (strcmp(key, "currentMouseTask") == 0) {
            p->currentMouseTask = (TaskType)luaL_checkinteger(L, 3);
            return 0;
        }
        if (strcmp(key, "mouseTaskTypeRestriction") == 0) {
            p->mouseTaskTypeRestriction = (itemType)luaL_checkinteger(L, 3);
            return 0;
        }
        if (strcmp(key, "mouseRightTargetSet") == 0) {
            p->mouseRightTargetSet = (lua_toboolean(L, 3) != 0);
            return 0;
        }
        if (strcmp(key, "mouseRightTarget") == 0) {
            p->mouseRightTarget = lua_isnil(L, 3) ? nullptr : checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
            return 0;
        }
        if (strcmp(key, "rmouseTimer") == 0) {
            p->rmouseTimer = (float)luaL_checknumber(L, 3);
            return 0;
        }
        if (strcmp(key, "selectedObject") == 0) {
            hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
            if (!h) return luaL_error(L, "expected hand userdata");
            p->selectedObject = *h;
            return 0;
        }
        if (strcmp(key, "onlyAnimalsSelected") == 0) {
            p->onlyAnimalsSelected = (lua_toboolean(L, 3) != 0);
            return 0;
        }
        if (strcmp(key, "selectedLoadedLeft") == 0) {
            p->selectedLoadedLeft = (int)luaL_checkinteger(L, 3);
            return 0;
        }
        if (strcmp(key, "trackedCharacterHandle") == 0) {
            hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
            if (!h) return luaL_error(L, "expected hand userdata");
            p->trackedCharacterHandle = *h;
            return 0;
        }
        if (strcmp(key, "trackedCharacterFloor") == 0) {
            p->trackedCharacterFloor = (int)luaL_checkinteger(L, 3);
            return 0;
        }
        if (strcmp(key, "participant") == 0) {
            p->participant = lua_isnil(L, 3) ? nullptr : getFactionFromLua(L, 3);
            return 0;
        }
        if (strcmp(key, "currentPlatoon") == 0) {
            Platoon* platoon = lua_isnil(L, 3) ? nullptr : getPlatoonFromLua(L, 3);
            p->setCurrentPlatoon(platoon);
            return 0;
        }
        if (strcmp(key, "placementObject") == 0) {
            p->placementObject = (PlacementObject*)lua_touserdata(L, 3);
            return 0;
        }
        if (strcmp(key, "selectedCharacters") == 0) {
            if (!lua_istable(L, 3)) return luaL_error(L, "expected table of hands");
            p->selectedCharacters.clear();
            int len = (int)lua_rawlen(L, 3);
            for (int i = 1; i <= len; ++i) {
                lua_rawgeti(L, 3, i);
                hand* h = (hand*)luaL_testudata(L, -1, HandBinding::getMetatableName());
                if (h) p->selectedCharacters.insert(*h);
                lua_pop(L, 1);
            }
            return 0;
        }

        if (strcmp(key, "technology") == 0) return luaL_error(L, "PlayerInterface: technology is read-only");
        if (strcmp(key, "playerCharacters") == 0) return luaL_error(L, "PlayerInterface: playerCharacters is read-only");

        return luaL_error(L, "PlayerInterface: field '%s' is read-only or does not exist", key);
    }
    int PlayerInterfaceBinding::tostring(lua_State* L) { return genericTostringPtr(L, "PlayerInterface", (void*)getP(L, 1)); }

    int PlayerInterfaceBinding::getFaction(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        return pushObject<Faction>(L, p->getFaction(), FactionBinding::getMetatableName());
    }

    int PlayerInterfaceBinding::setFaction(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Faction* f = getFactionFromLua(L, 2);
        if (!f) return luaL_error(L, "Faction is nil");
        p->setFaction(f);
        return 0;
    }

    int PlayerInterfaceBinding::getCurrentPlatoon(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        return pushObject<Platoon>(L, p->getCurrentPlatoon(), PlatoonBinding::getMetatableName());
    }

    int PlayerInterfaceBinding::setCurrentPlatoon(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Platoon* platoon = getPlatoonFromLua(L, 2);
        if (!platoon) return luaL_error(L, "Platoon is nil");
        p->setCurrentPlatoon(platoon);
        return 0;
    }

    int PlayerInterfaceBinding::getCurrentActivePlatoon(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        ActivePlatoon* ap = static_cast<ActivePlatoon*>(p->getCurrentActivePlatoon());
        return pushObject<ActivePlatoon>(L, ap, PlatoonBinding::getMetatableName());
    }

    int PlayerInterfaceBinding::recruit(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
        if (!character) return luaL_error(L, "Character is nil");
        bool editor = lua_toboolean(L, 3);
        p->recruit(character, editor);
        return 0;
    }

    int PlayerInterfaceBinding::getAnyPlayerCharacter(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        return pushObject<Character>(L, p->getAnyPlayerCharacter(), CharacterBinding::getMetatableName());
    }

    int PlayerInterfaceBinding::setCharacterEditMode(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        bool editor = lua_toboolean(L, 2);
        p->setCharacterEditMode(editor);
        return 0;
    }

    int PlayerInterfaceBinding::triggerAreaArrivalDialogue(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        GameData* area = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
        if (!area) return luaL_error(L, "GameData is nil");
        p->triggerAreaArrivalDialogue(area);
        return 0;
    }



    int PlayerInterfaceBinding::getCharacterEditMode(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        lua_pushboolean(L, p->getCharacterEditMode() ? 1 : 0);
        return 1;
    }

    int PlayerInterfaceBinding::isBuildMode(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        lua_pushboolean(L, p && p->isBuildMode() ? 1 : 0);
        return 1;
    }

    int PlayerInterfaceBinding::selectObject(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
        if (!obj) return luaL_error(L, "RootObject is nil");
        bool modifier = lua_toboolean(L, 3);
        p->selectObject(obj, modifier);
        return 0;
    }

    int PlayerInterfaceBinding::selectPlayerCharacter(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
        if (!obj) return luaL_error(L, "RootObject is nil");
        bool modifier = lua_toboolean(L, 3);
        bool track = lua_toboolean(L, 4);
        p->_selectPlayerCharacter(obj, modifier, track);
        return 0;
    }

    int PlayerInterfaceBinding::selectPlayerCharacterByIndex(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        int index = luaL_checkinteger(L, 2);
        bool modifier = lua_toboolean(L, 3);
        bool track = lua_toboolean(L, 4);
        p->selectPlayerCharacter(index, modifier, track);
        return 0;
    }

    int PlayerInterfaceBinding::getNearestSelectedCharacterTo(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Ogre::Vector3 pos;
        if (readVector3(L, 2, pos))
            pushObject<Character>(L, p->getNearestSelectedCharacterTo(pos), CharacterBinding::getMetatableName());
        else
            lua_pushnil(L);
        return 1;
    }

    int PlayerInterfaceBinding::getNearestCharacterTo(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Ogre::Vector3 pos;
        if (readVector3(L, 2, pos))
            pushObject<Character>(L, p->getNearestCharacterTo(pos), CharacterBinding::getMetatableName());
        else
            lua_pushnil(L);
        return 1;
    }

    int PlayerInterfaceBinding::unselectPlayerCharacter(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
        if (!obj) return luaL_error(L, "RootObject is nil");
        p->unselectPlayerCharacter(obj);
        return 0;
    }

    int PlayerInterfaceBinding::startTrackCharacter(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
        if (!obj) return luaL_error(L, "RootObject is nil");
        p->startTrackCharacter(obj);
        return 0;
    }

    int PlayerInterfaceBinding::stopTrackCharacter(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (p) p->stopTrackCharacter();
        return 0;
    }

    int PlayerInterfaceBinding::isTrackingCharacter(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) { lua_pushnil(L); return 1; }
        lua_pushboolean(L, p->isTrackingCharacter() ? 1 : 0);
        return 1;
    }

    int PlayerInterfaceBinding::unselectAll(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (p) p->unselectAll();
        return 0;
    }

    int PlayerInterfaceBinding::getSelectedCharacterHandle(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) { lua_pushnil(L); return 1; }
        // selectedCharacter is a hand value member, so we copy it out and
        // push it as a new hand userdata via HandBinding::pushHand.
        return HandBinding::pushHand(L, p->selectedCharacter);
    }

    static bool readQuaternion(lua_State* L, int idx, Ogre::Quaternion& out)
    {
        if (!lua_istable(L, idx)) return false;
        lua_getfield(L, idx, "w"); out.w = (float)luaL_checknumber(L, -1); lua_pop(L, 1);
        lua_getfield(L, idx, "x"); out.x = (float)luaL_checknumber(L, -1); lua_pop(L, 1);
        lua_getfield(L, idx, "y"); out.y = (float)luaL_checknumber(L, -1); lua_pop(L, 1);
        lua_getfield(L, idx, "z"); out.z = (float)luaL_checknumber(L, -1); lua_pop(L, 1);
        return true;
    }

    int PlayerInterfaceBinding::focusCamera(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Ogre::Vector3 pos;
        if (readVector3(L, 2, pos)) p->focusCamera(pos);
        return 0;
    }

    int PlayerInterfaceBinding::focusCameraSelectedCharacter(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (p) p->focusCameraSelectedCharacter();
        return 0;
    }

    int PlayerInterfaceBinding::manuallyOrientCamera(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Ogre::Quaternion rot;
        float zoom = (float)luaL_checknumber(L, 3);
        if (readQuaternion(L, 2, rot)) p->manuallyOrientCamera(rot, zoom);
        return 0;
    }

    int PlayerInterfaceBinding::getDistanceFromCamera(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) { lua_pushnumber(L, 0.0); return 1; }
        Ogre::Vector3 pos;
        if (readVector3(L, 2, pos))
            lua_pushnumber(L, p->getDistanceFromCamera(pos));
        else
            lua_pushnumber(L, 0.0);
        return 1;
    }

    int PlayerInterfaceBinding::getCameraCenter(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) { lua_pushnil(L); return 1; }
        pushVector3(L, p->getCameraCenter());
        return 1;
    }

    int PlayerInterfaceBinding::toggleLevelEditorOnSelectedTown(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        p->toggleLevelEditorOnSelectedTown();
        return 0;
    }

    int PlayerInterfaceBinding::isEnemy(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
        if (!character) return luaL_error(L, "Character is nil");
        lua_pushboolean(L, p->isEnemy(character) ? 1 : 0);
        return 1;
    }


    int PlayerInterfaceBinding::newPlayerTaskSelectedCharacters(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        TaskType t = (TaskType)luaL_checkinteger(L, 2);
        hand* targetH = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
        if (!targetH) return luaL_error(L, "expected hand userdata for targetH");
        Building* destinationIndoors = lua_isnil(L, 4) ? nullptr : checkObject<Building>(L, 4, BuildingBinding::getMetatableName());
        Ogre::Vector3 clickpos;
        if (!readVector3(L, 5, clickpos)) return luaL_error(L, "expected Vector3 table for clickpos");
        bool addDontClear = lua_toboolean(L, 6) != 0;
        
        p->newPlayerTaskSelectedCharacters(t, *targetH, destinationIndoors, clickpos, addDontClear);
        return 0;
    }

    int PlayerInterfaceBinding::getPlayerTaskProbability(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        TaskType task = (TaskType)luaL_checkinteger(L, 2);
        RootObject* target = lua_isnil(L, 3) ? nullptr : checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
        float probability = 0.0f;
        bool result = p->getPlayerTaskProbability(task, target, probability);
        lua_pushboolean(L, result ? 1 : 0);
        lua_pushnumber(L, probability);
        return 2;
    }

    int PlayerInterfaceBinding::addOrderSelectedCharacters(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Building* destinationIndoors = lua_isnil(L, 2) ? nullptr : checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
        TaskType task = (TaskType)luaL_checkinteger(L, 3);
        RootObject* subject = lua_isnil(L, 4) ? nullptr : checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
        bool shift = lua_toboolean(L, 5) != 0;
        bool addDontClear = lua_toboolean(L, 6) != 0;
        Ogre::Vector3 location;
        if (!readVector3(L, 7, location)) return luaL_error(L, "expected Vector3 table for location");
        
        p->addOrderSelectedCharacters(destinationIndoors, task, subject, shift, addDontClear, location);
        return 0;
    }

    int PlayerInterfaceBinding::addJobSelectedCharacters(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        TaskType task = (TaskType)luaL_checkinteger(L, 2);
        RootObject* subject = lua_isnil(L, 3) ? nullptr : checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
        bool shift = lua_toboolean(L, 4) != 0;
        bool add = lua_toboolean(L, 5) != 0;
        Ogre::Vector3 location;
        if (!readVector3(L, 6, location)) return luaL_error(L, "expected Vector3 table for location");
        
        p->addJobSelectedCharacters(task, subject, shift, add, location);
        return 0;
    }

    int PlayerInterfaceBinding::removeJobSelectedCharacters(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        TaskType t = (TaskType)luaL_checkinteger(L, 2);
        p->removeJobSelectedCharacters(t);
        return 0;
    }

    int PlayerInterfaceBinding::removePermaJobSelectedCharacters(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        int id = (int)luaL_checkinteger(L, 2);
        p->removePermaJobSelectedCharacters(id);
        return 0;
    }

    int PlayerInterfaceBinding::isFactionKnown(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Faction* f = getFactionFromLua(L, 2);
        if (!f) return luaL_error(L, "Faction is nil");
        lua_pushboolean(L, p->isFactionKnown(f) ? 1 : 0);
        return 1;
    }

    int PlayerInterfaceBinding::encounterFaction(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Faction* faction = getFactionFromLua(L, 2);
        if (!faction) return luaL_error(L, "Faction is nil");
        p->encounterFaction(faction);
        return 0;
    }

    int PlayerInterfaceBinding::pickupItem(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
        if (!item) return luaL_error(L, "Item is nil");
        p->pickupItem(item);
        return 0;
    }

    int PlayerInterfaceBinding::characterSelected(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
        if (!target) return luaL_error(L, "Character is nil");
        p->characterSelected(target);
        return 0;
    }

    int PlayerInterfaceBinding::itemSelected(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
        if (!item) return luaL_error(L, "Item is nil");
        p->itemSelected(item);
        return 0;
    }

    int PlayerInterfaceBinding::buildingSelected(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
        if (!building) return luaL_error(L, "Building is nil");
        Ogre::Vector3 position;
        if (!readVector3(L, 3, position)) return luaL_error(L, "expected Vector3 table for position");
        bool interiorsVisible = lua_toboolean(L, 4) != 0;
        lua_pushboolean(L, p->buildingSelected(building, position, interiorsVisible) ? 1 : 0);
        return 1;
    }

    int PlayerInterfaceBinding::playerMove(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        Ogre::Vector3 pos;
        if (!readVector3(L, 2, pos)) return luaL_error(L, "expected Vector3 table for pos");
        Building* destBuilding = lua_isnil(L, 3) ? nullptr : checkObject<Building>(L, 3, BuildingBinding::getMetatableName());
        p->playerMove(pos, destBuilding);
        return 0;
    }

    int PlayerInterfaceBinding::_isPlayerCharacter(lua_State* L)
    {
        PlayerInterface* p = getP(L, 1);
        if (!p) return luaL_error(L, "PlayerInterface is nil");
        RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
        if (!obj) return luaL_error(L, "RootObject is nil");
        lua_pushboolean(L, p->_isPlayerCharacter(obj) ? 1 : 0);
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
            { "getFaction",                         PlayerInterfaceBinding::getFaction },
            { "setFaction",                         PlayerInterfaceBinding::setFaction },
            { "getCurrentPlatoon",                  PlayerInterfaceBinding::getCurrentPlatoon },
            { "setCurrentPlatoon",                  PlayerInterfaceBinding::setCurrentPlatoon },
            { "getCurrentActivePlatoon",            PlayerInterfaceBinding::getCurrentActivePlatoon },
            { "recruit",                            PlayerInterfaceBinding::recruit },
            { "selectObject",                       PlayerInterfaceBinding::selectObject },
            { "selectPlayerCharacter",              PlayerInterfaceBinding::selectPlayerCharacter },
            { "selectPlayerCharacterByIndex",       PlayerInterfaceBinding::selectPlayerCharacterByIndex },
            { "getNearestSelectedCharacterTo",      PlayerInterfaceBinding::getNearestSelectedCharacterTo },
            { "getNearestCharacterTo",            PlayerInterfaceBinding::getNearestCharacterTo },
            { "unselectPlayerCharacter",            PlayerInterfaceBinding::unselectPlayerCharacter },
            { "startTrackCharacter",                PlayerInterfaceBinding::startTrackCharacter },
            { "stopTrackCharacter",                 PlayerInterfaceBinding::stopTrackCharacter },
            { "isTrackingCharacter",                PlayerInterfaceBinding::isTrackingCharacter },
            { "getAnyPlayerCharacter",              PlayerInterfaceBinding::getAnyPlayerCharacter },
            { "isBuildMode",                        PlayerInterfaceBinding::isBuildMode },
            { "unselectAll",                        PlayerInterfaceBinding::unselectAll },
            { "getSelectedCharacterHandle",         PlayerInterfaceBinding::getSelectedCharacterHandle },
            { "focusCamera",                        PlayerInterfaceBinding::focusCamera },
            { "focusCameraSelectedCharacter",       PlayerInterfaceBinding::focusCameraSelectedCharacter },
            { "manuallyOrientCamera",               PlayerInterfaceBinding::manuallyOrientCamera },
            { "getDistanceFromCamera",              PlayerInterfaceBinding::getDistanceFromCamera },
            { "getCameraCenter",                    PlayerInterfaceBinding::getCameraCenter },
            { "toggleLevelEditorOnSelectedTown",    PlayerInterfaceBinding::toggleLevelEditorOnSelectedTown },
            { "newPlayerTaskSelectedCharacters",    PlayerInterfaceBinding::newPlayerTaskSelectedCharacters },
            { "getPlayerTaskProbability",           PlayerInterfaceBinding::getPlayerTaskProbability },
            { "addOrderSelectedCharacters",          PlayerInterfaceBinding::addOrderSelectedCharacters },
            { "addJobSelectedCharacters",            PlayerInterfaceBinding::addJobSelectedCharacters },
            { "removeJobSelectedCharacters",         PlayerInterfaceBinding::removeJobSelectedCharacters },
            { "removePermaJobSelectedCharacters",    PlayerInterfaceBinding::removePermaJobSelectedCharacters },
            { "isFactionKnown",                     PlayerInterfaceBinding::isFactionKnown },
            { "encounterFaction",                   PlayerInterfaceBinding::encounterFaction },
            { "pickupItem",                         PlayerInterfaceBinding::pickupItem },
            { "characterSelected",                  PlayerInterfaceBinding::characterSelected },
            { "itemSelected",                       PlayerInterfaceBinding::itemSelected },
            { "buildingSelected",                   PlayerInterfaceBinding::buildingSelected },
            { "playerMove",                         PlayerInterfaceBinding::playerMove },
            { "_isPlayerCharacter",                 PlayerInterfaceBinding::_isPlayerCharacter },
            { 0, 0 }
        };
        registerClass(L, PlayerInterfaceBinding::getMetatableName(), meta, methods, PlayerInterfaceBinding::index, PlayerInterfaceBinding::newindex);
    }

} // namespace KenshiLua
