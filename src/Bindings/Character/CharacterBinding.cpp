#include "pch.h"
#include "Bindings/Character/CharacterBinding.h"
#include "Bindings/Character/CharStatsBinding.h"
#include "Bindings/Core/EnumBinding.h"
#include "Bindings/Utility/HandBinding.h"
#include "Bindings/World/PlatoonBinding.h"
#include "Bindings/World/FactionBinding.h"
#include "Bindings/Equipment/ItemBinding.h"
#include "Bindings/Equipment/InventoryBinding.h"
#include "Bindings/System/MedicalSystemBinding.h"
#include "Bindings/Character/RaceDataBinding.h"
#include "Bindings/System/BountyManagerBinding.h"
#include "Bindings/Dialogue/DialogueBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Character.h>
#include <kenshi/CharBody.h>
#include <kenshi/CharStats.h>
#include <kenshi/util/hand.h>
#include <kenshi/MedicalSystem.h>
#include <kenshi/Platoon.h>
#include <kenshi/Faction.h>
#include <kenshi/Item.h>
#include <kenshi/Inventory.h>

#include <ogre/OgreVector3.h>

#include <cstdio>
#include <cstring>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

static Character* getC(lua_State* L, int idx)
{
    return checkObject<Character>(L, idx, CharacterBinding::getMetatableName());
}

int CharacterBinding::gc(lua_State* L)        { return noopGc(L); }

int CharacterBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    // 1. Check the metatable first so obj:method() syntax continues to work.
    luaL_getmetatable(L, CharacterBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;   // found a method — return it
    lua_pop(L, 2);  // pop nil result + metatable

    // 2. Fall through to raw member variable access.
    Character* c = getC(L, 1);
    if (!c) { lua_pushnil(L); return 1; }

    // Readable fields
    
    // --- boolean members ---
    if (strcmp(key, "stealthMode") == 0) { lua_pushboolean(L, c->stealthMode ? 1 : 0); return 1;}
    if (strcmp(key, "_isOnARoof") == 0) { lua_pushboolean(L, c->_isOnARoof ? 1 : 0); return 1; }
	if (strcmp(key, "needsLightLevel") == 0) { lua_pushboolean(L, c->needsLightLevel ? 1 : 0); return 1; }
	if (strcmp(key, "isVisibleUpdateMode") == 0) { lua_pushboolean(L, c->isVisibleUpdateMode ? 1 : 0); return 1; }
	if (strcmp(key, "setVisibleMsg") == 0) { lua_pushboolean(L, c->setVisibleMsg ? 1 : 0); return 1; }
	if (strcmp(key, "playerWantsMeToGetUp") == 0) { lua_pushboolean(L, c->playerWantsMeToGetUp ? 1 : 0); return 1; }
	if (strcmp(key, "isCarryingSomething") == 0) { lua_pushboolean(L, c->isCarryingSomething ? 1 : 0); return 1; }
	if (strcmp(key, "isCarryingLeftSide") == 0) { lua_pushboolean(L, c->isCarryingLeftSide ? 1 : 0); return 1; }
	if (strcmp(key, "_isBeingCarried") == 0) { lua_pushboolean(L, c->_isBeingCarried ? 1 : 0); return 1; }
	if (strcmp(key, "isPhysicalMode") == 0) { lua_pushboolean(L, c->isPhysicalMode ? 1 : 0); return 1; }
	if (strcmp(key, "isChained") == 0) { lua_pushboolean(L, c->isChained ? 1 : 0); return 1; }
	if (strcmp(key, "isCurrentlyGettingUp") == 0) { lua_pushboolean(L, c->isCurrentlyGettingUp ? 1 : 0); return 1; }
	if (strcmp(key, "_isEngagedWithAPlayer") == 0) { lua_pushboolean(L, c->_isEngagedWithAPlayer ? 1 : 0); return 1; }
	if (strcmp(key, "isVisibleAndNear") == 0) { lua_pushboolean(L, c->isVisibleAndNear ? 1 : 0); return 1; }
	if (strcmp(key, "isOnScreen") == 0) { lua_pushboolean(L, c->isOnScreen ? 1 : 0); return 1; }
    if (strcmp(key, "isLiterallyUnderAttack") == 0) { lua_pushboolean(L, c->_isLiterallyUnderMeleeAttackRightNowForSure ? 1 : 0); return 1; }

    if (strcmp(key, "isOnARoof") == 0) { lua_pushboolean(L, c->_isOnARoof ? 1 : 0); return 1; }
    if (strcmp(key, "isEngagedWithAPlayer") == 0) { lua_pushboolean(L, c->_isEngagedWithAPlayer ? 1 : 0); return 1; }
    if (strcmp(key, "isBeingCarried") == 0) { lua_pushboolean(L, c->_isBeingCarried ? 1 : 0); return 1; }
    // --- float members ---
	if (strcmp(key, "offscreenFrameTime") == 0) { lua_pushnumber(L, c->offscreenFrameTime); return 1; }
	if (strcmp(key, "frameTIME") == 0) { lua_pushnumber(L, c->frameTIME); return 1; }
	if (strcmp(key, "frameTIMEfour") == 0) { lua_pushnumber(L, c->frameTIMEfour); return 1; }
	if (strcmp(key, "frameTIME_P") == 0) { lua_pushnumber(L, c->frameTIME_P); return 1; }
	if (strcmp(key, "bodyDecayTimer") == 0) { lua_pushnumber(L, c->bodyDecayTimer); return 1; }
	if (strcmp(key, "_lightLevel") == 0) { lua_pushnumber(L, c->_lightLevel); return 1; }
	if (strcmp(key, "diplomacyMultiplier") == 0) { lua_pushnumber(L, c->diplomacyMultiplier); return 1; }
	if (strcmp(key, "terrainHeightPosition") == 0) { lua_pushnumber(L, c->terrainHeightPosition); return 1; }
    // c++ cleaned up naming
    if (strcmp(key, "lightLevel") == 0) { lua_pushnumber(L, c->_lightLevel); return 1; }

    // --- integer enum members ---
    if (strcmp(key, "_currentProneState") == 0) { lua_pushinteger(L, (int)c->_currentProneState); return 1; } // enum
	if (strcmp(key, "squadMemberID") == 0) { lua_pushinteger(L, (int)c->squadMemberID); return 1; }
	if (strcmp(key, "_destinationInsideWalls") == 0) { lua_pushinteger(L, (int)c->_destinationInsideWalls); return 1; }
	if (strcmp(key, "portraitIndex") == 0) { lua_pushinteger(L, (int)c->portraitIndex); return 1; } // short?
	if (strcmp(key, "portraitSerial") == 0) { lua_pushinteger(L, (int)c->portraitSerial); return 1; } // unsigned int?
	if (strcmp(key, "audioObject") == 0) { lua_pushinteger(L, (int)c->audioObject); return 1; } // unsigned int64?
    if (strcmp(key, "stealthUnseen") == 0) { lua_pushinteger(L, c->stealthUnseen.toInt()); return 1; } // enum
    if (strcmp(key, "currentSkillUsing") == 0) { lua_pushinteger(L, (int)c->currentSkillUsing); return 1; }
    if (strcmp(key, "isGettingEaten") == 0) { lua_pushinteger(L, (int)c->isGettingEaten); return 1; }
    if (strcmp(key, "inSomething") == 0) { lua_pushinteger(L, (int)c->inSomething); return 1; }
    if (strcmp(key, "lastUsedWeaponCategory") == 0) { lua_pushinteger(L, (int)c->lastUsedWeaponCategory); return 1; }
    if (strcmp(key, "groundType") == 0) { lua_pushinteger(L, (int)c->groundType); return 1; }
    if (strcmp(key, "armourType") == 0) { lua_pushinteger(L, (int)c->armourType); return 1; }

    // c++ cleaned up naming
    if (strcmp(key, "currentProneState") == 0) { lua_pushinteger(L, (int)c->_currentProneState); return 1; } // enum
    if (strcmp(key, "destinationInsideWalls") == 0) { lua_pushinteger(L, (int)c->_destinationInsideWalls); return 1; }

    

    // hand
    if (strcmp(key, "isUsingTurret") == 0) { return HandBinding::pushHand(L, c->isUsingTurret); }
    if (strcmp(key, "slaveOwner") == 0) { return HandBinding::pushHand(L, c->slaveOwner); }
    if (strcmp(key, "inWhat") == 0) { return HandBinding::pushHand(L, c->inWhat); }
    if (strcmp(key, "carryingObject") == 0) { return HandBinding::pushHand(L, c->carryingObject); }
    if (strcmp(key, "messageSubject") == 0) { return HandBinding::pushHand(L, c->messageSubject); }
    if (strcmp(key, "_destinationInsideBuilding") == 0) { return HandBinding::pushHand(L, c->_destinationInsideBuilding); }
    if (strcmp(key, "lastGuyWhoDefeatedMe") == 0) { return HandBinding::pushHand(L, c->lastGuyWhoDefeatedMe); }
    // c++ cleanup up naming
    if (strcmp(key, "destinationInsideBuilding") == 0) { return HandBinding::pushHand(L, c->_destinationInsideBuilding); }
    
    // --- unique object members ---
    if (strcmp(key, "stats") == 0) {
        if (c->stats) return pushObject<CharStats>(L, c->stats, CharStatsBinding::getMetatableName());
        lua_pushnil(L); return 1;
    }
    if (strcmp(key, "medical") == 0) {
        if (&c->medical) return pushObject<MedicalSystem>(L, &c->medical, MedicalSystemBinding::getMetatableName());
        lua_pushnil(L); return 1;
    }
    if (strcmp(key, "inventory") == 0) {
        if (c->inventory) return pushObject<Inventory>(L, c->inventory, InventoryBinding::getMetatableName());
        lua_pushnil(L); return 1;
    }
    if (strcmp(key, "race") == 0) {
        if (c->myRace) return pushObject<RaceData>(L, c->myRace, RaceDataBinding::getMetatableName());
        lua_pushnil(L); return 1;
    }
    if (strcmp(key, "crimes") == 0) {
        if (&c->crimes) return pushObject<BountyManager>(L, &c->crimes, BountyManagerBinding::getMetatableName());
        lua_pushnil(L); return 1;
    }
    if (strcmp(key, "dialogue") == 0) {
        if (c->dialogue) return pushObject<Dialogue>(L, c->dialogue, DialogueBinding::getMetatableName());
        lua_pushnil(L); return 1;
    }

    // --- string members ---
    if (strcmp(key, "currentStumblePainAnimation") == 0) { lua_pushstring(L, c->currentStumblePainAnimation.c_str()); return 1; }
    if (strcmp(key, "carryingObjectLeftOrRight") == 0) { lua_pushstring(L, c->carringObjectLeftOrRight.c_str()); return 1; }
    if (strcmp(key, "sex") == 0) { lua_pushstring(L, c->sex.c_str()); return 1; }

    // --- Ogre::Vector3 members ---
    if (strcmp(key, "ragdollNavmeshPosition") == 0) {
        pushVector3(L, c->ragdollNavmeshPosition);
        return 1;
    }

    // --- ??? members ---
    if (strcmp(key, "myMemory") == 0) {
        if (c->_myMemory) lua_pushlightuserdata(L, (void*)c->_myMemory);
        else             lua_pushnil(L);
        return 1;
    }
    
    //if (strcmp(key, "slaveOwner") == 0) { return HandBinding::pushHand(L, c->slaveOwner); }
    //if (strcmp(key, "inWhat") == 0) { return HandBinding::pushHand(L c->inWhat); }
    // Unknown key.
    lua_pushnil(L);
    return 1;
}


int CharacterBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    Character* c = checkObject<Character>(L, 1, CharacterBinding::getMetatableName());
    if (!c) return luaL_error(L, "Character is nil");

    // Writeable fields

// --- boolean members ---
    if (strcmp(key, "stealthMode") == 0) { c->stealthMode = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "_isOnARoof") == 0) { c->_isOnARoof = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "needsLightLevel") == 0) { c->needsLightLevel = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "isVisibleUpdateMode") == 0) { c->isVisibleUpdateMode = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "setVisibleMsg") == 0) { c->setVisibleMsg = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "playerWantsMeToGetUp") == 0) { c->playerWantsMeToGetUp = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "isCarryingSomething") == 0) { c->isCarryingSomething = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "isCarryingLeftSide") == 0) { c->isCarryingLeftSide = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "_isBeingCarried") == 0) { c->_isBeingCarried = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "isPhysicalMode") == 0) { c->isPhysicalMode = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "isChained") == 0) { c->isChained = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "isCurrentlyGettingUp") == 0) { c->isCurrentlyGettingUp = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "_isEngagedWithAPlayer") == 0) { c->_isEngagedWithAPlayer = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "isVisibleAndNear") == 0) { c->isVisibleAndNear = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "isOnScreen") == 0) { c->isOnScreen = (lua_toboolean(L, 3) != 0); return 0; }
    // --- float members ---
    if (strcmp(key, "offscreenFrameTime") == 0) { c->offscreenFrameTime = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "frameTIME") == 0) { c->frameTIME = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "frameTIMEfour") == 0) { c->frameTIMEfour = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "frameTIME_P") == 0) { c->frameTIME_P = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "bodyDecayTimer") == 0) { c->bodyDecayTimer = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "_lightLevel") == 0) { c->_lightLevel = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "diplomacyMultiplier") == 0) { c->diplomacyMultiplier = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "terrainHeightPosition") == 0) { c->terrainHeightPosition = (float)luaL_checknumber(L, 3); return 0; }
    // --- integer enum members ---
    if (strcmp(key, "_currentProneState") == 0) { c->_currentProneState = (ProneState)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "squadMemberID") == 0) { c->squadMemberID = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "_destinationInsideWalls") == 0) { c->_destinationInsideWalls = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "portraitIndex") == 0) { c->portraitIndex = (short)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "portraitSerial") == 0) { c->portraitSerial = (unsigned int)luaL_checkinteger(L, 3); return 0; }

    // audioObject intentionally omitted - unsigned __int64 audio handle, should not be written directly
    // if (strcmp(key, "audioObject") == 0) { c->audioObject = (unsigned __int64)luaL_checkinteger(L, 3); return 0; }
    
    // --- unique object members ---
    // hand members - these are value types so we need to copy from a hand userdata at arg 3
    if (strcmp(key, "isUsingTurret") == 0)
    {
        hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
        if (!h) return luaL_error(L, "Character.isUsingTurret: expected hand userdata");
        c->isUsingTurret = *h;
        return 0;
    }
    if (strcmp(key, "slaveOwner") == 0)
    {
        hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
        if (!h) return luaL_error(L, "Character.slaveOwner: expected hand userdata");
        c->slaveOwner = *h;
        return 0;
    }
    if (strcmp(key, "inWhat") == 0)
    {
        hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
        if (!h) return luaL_error(L, "Character.inWhat: expected hand userdata");
        c->inWhat = *h;
        return 0;
    }
    if (strcmp(key, "carryingObject") == 0)
    {
        hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
        if (!h) return luaL_error(L, "Character.carryingObject: expected hand userdata");
        c->carryingObject = *h;
        return 0;
    }
    if (strcmp(key, "messageSubject") == 0)
    {
        hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
        if (!h) return luaL_error(L, "Character.messageSubject: expected hand userdata");
        c->messageSubject = *h;
        return 0;
    }
    if (strcmp(key, "_destinationInsideBuilding") == 0)
    {
        hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
        if (!h) return luaL_error(L, "Character._destinationInsideBuilding: expected hand userdata");
        c->_destinationInsideBuilding = *h;
        return 0;
    }
    // stats and medical are pointers/references to engine subsystems, writing them directly
    // would replace the engine's own subsystem pointers which would likely cause crashes.
    // if (strcmp(key, "stats") == 0) { c->stats = (CharStats*)lua_touserdata(L, 3); return 0; }
    
    // if (strcmp(key, "medical") == 0)
    //{
    //    MedicalSystem* src = checkObject<MedicalSystem>(L, 3, MedicalSystemBinding::getMetatableName());
    //    if (!src) return luaL_error(L, "Character.medical: expected MedicalSystem userdata");
    //    c->medical = *src;
    //    return 0;
    //}
    
    // Use the methods on those subsystems directly instead.
    if (strcmp(key, "stats") == 0) return luaL_error(L, "Character: stats is read-only, modify fields via getStats()");
    if (strcmp(key, "medical") == 0) return luaL_error(L, "Character: medical is read-only, modify fields via medical.{field} or getMedical().{field}. \nFor example, `character:getMedical().blood = 1.0` or 'character.medical.blood = 1.0'");
    if (strcmp(key, "race") == 0) return luaL_error(L, "Character: race is read-only");
    if (strcmp(key, "crimes") == 0) return luaL_error(L, "Character: crimes is read-only, modify fields/call methods on the crimes object directly");
    if (strcmp(key, "bounties") == 0) return luaL_error(L, "Character: bounties is read-only");
    if (strcmp(key, "dialogue") == 0) return luaL_error(L, "Character: dialogue is read-only");
    if (strcmp(key, "myMemory") == 0) return luaL_error(L, "Character: myMemory is read-only");

    if (strcmp(key, "stealthUnseen") == 0) { c->stealthUnseen = YesNoMaybe((int)luaL_checkinteger(L, 3)); return 0; }
    if (strcmp(key, "currentSkillUsing") == 0) { c->currentSkillUsing = (StatsEnumerated)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "isGettingEaten") == 0) { c->isGettingEaten = (unsigned char)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "currentStumblePainAnimation") == 0) { c->currentStumblePainAnimation = luaL_checkstring(L, 3); return 0; }
    if (strcmp(key, "isLiterallyUnderAttack") == 0) { c->_isLiterallyUnderMeleeAttackRightNowForSure = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "inSomething") == 0) { c->inSomething = (UseStuffState)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "carryingObjectLeftOrRight") == 0) { c->carringObjectLeftOrRight = luaL_checkstring(L, 3); return 0; }
    if (strcmp(key, "lastUsedWeaponCategory") == 0) { c->lastUsedWeaponCategory = (WeaponCategory)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "sex") == 0) { c->sex = luaL_checkstring(L, 3); return 0; }
    if (strcmp(key, "groundType") == 0) { c->groundType = (GroundType)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "armourType") == 0) { c->armourType = (ArmourType)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "ragdollNavmeshPosition") == 0) {
        Ogre::Vector3 v(0.0f, 0.0f, 0.0f);
        if (!readVector3(L, 3, v)) return luaL_error(L, "expected vector3 {x,y,z}");
        c->ragdollNavmeshPosition = v;
        return 0;
    }

    // Unknown key
    return luaL_error(L, "Character: field '%s' does not exist", key);
}

int CharacterBinding::tostring(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) { lua_pushstring(L, "Character:nil"); return 1; }
    char buf[160];
    _snprintf(buf, sizeof(buf), "Character:%s(%p)", c->isValid() ? c->getName().c_str() : "?", (void*)c);
    lua_pushstring(L, buf);
    return 1;
}

// --- Identity / existence ----------------------------------------------------

int CharacterBinding::isValid(lua_State* L)            { Character* c = getC(L, 1); lua_pushboolean(L, c && c->isValid() ? 1 : 0); return 1; }
int CharacterBinding::isPlayerCharacter(lua_State* L)  { Character* c = getC(L, 1); lua_pushboolean(L, c && c->isPlayerCharacter() ? 1 : 0); return 1; }
int CharacterBinding::isUnique(lua_State* L)           { Character* c = getC(L, 1); lua_pushboolean(L, c && c->isUnique() ? 1 : 0); return 1; }
int CharacterBinding::isFemale(lua_State* L)           { Character* c = getC(L, 1); lua_pushboolean(L, c && c->isFemale() ? 1 : 0); return 1; }
int CharacterBinding::isDestroyed(lua_State* L)        { Character* c = getC(L, 1); lua_pushboolean(L, c && c->isDestroyed() ? 1 : 0); return 1; }
int CharacterBinding::isDead(lua_State* L)             { Character* c = getC(L, 1); lua_pushboolean(L, c && c->isDead() ? 1 : 0); return 1; }

// --- Naming / appearance -----------------------------------------------------

int CharacterBinding::getName(lua_State* L)
{
    Character* c = getC(L, 1);
    if (c) lua_pushstring(L, c->getName().c_str()); else lua_pushnil(L);
    return 1;
}

int CharacterBinding::setName(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    c->setName(luaL_checkstring(L, 2));
    return 0;
}

int CharacterBinding::setNameTagVisible(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    c->setNameTagVisible(lua_toboolean(L, 2) != 0);
    return 0;
}

int CharacterBinding::getVisible(lua_State* L) { Character* c = getC(L, 1); lua_pushboolean(L, c && c->getVisible() ? 1 : 0); return 1; }

int CharacterBinding::setVisible(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    c->setVisible(lua_toboolean(L, 2) != 0);
    return 0;
}

// --- Position / movement -----------------------------------------------------

int CharacterBinding::getPosition(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) { lua_pushnil(L); return 1; }
    Ogre::Vector3 p = c->getPosition();
    pushVector3(L, p);
    return 1;
}

int CharacterBinding::getBoneWorldPosition(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) { lua_pushnil(L); return 1; }
    const char* bone = luaL_checkstring(L, 2);
    Ogre::Vector3 p = c->getBoneWorldPosition(bone);
    pushVector3(L, p);
    return 1;
}

int CharacterBinding::getMovementSpeed(lua_State* L)
{
    Character* c = getC(L, 1);
    if (c) lua_pushnumber(L, c->getMovementSpeed()); else lua_pushnil(L);
    return 1;
}

int CharacterBinding::getMovementDirection(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) { lua_pushnil(L); return 1; }
    Ogre::Vector3 d = c->getMovementDirection();
    pushVector3(L, d);
    return 1;
}

int CharacterBinding::teleport(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    Ogre::Vector3 pos(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 2, pos)) return luaL_error(L, "teleport: expected {x,y,z}");
    c->teleport(pos);
    return 0;
}

int CharacterBinding::setDestination(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    Ogre::Vector3 pos(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 2, pos)) return luaL_error(L, "setDestination: expected {x,y,z}");
    bool shift = lua_toboolean(L, 3) != 0;
    c->setDestination(pos, shift);
    return 0;
}

// --- Faction / race / platoon -----------------------------------------------

int CharacterBinding::getFaction(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c || !c->getBody()) { lua_pushnil(L); return 1; }
    return pushObject<Faction>(L, c->getBody()->getFaction(), FactionBinding::getMetatableName());
}

int CharacterBinding::setFaction(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    if (!f) return luaL_error(L, "setFaction: expected Faction userdata");
    c->setFaction(f, 0);
    return 0;
}

int CharacterBinding::getRace(lua_State* L)
{
    Character* c = getC(L, 1);
    if (c && c->myRace) {
        return pushObject<RaceData>(L, c->myRace, RaceDataBinding::getMetatableName());
    }
    lua_pushnil(L);
    return 1;
}

int CharacterBinding::getPlatoon(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) { lua_pushnil(L); return 1; }
    ActivePlatoon* ap = c->getPlatoon();
    if (!ap) { lua_pushnil(L); return 1; }
    // ActivePlatoon is the engine-owned struct; we wrap it through the
    // Platoon binding since modders address platoons (squads) abstractly.
    return pushObject<ActivePlatoon>(L, ap, PlatoonBinding::getMetatableName());
}

int CharacterBinding::getSquadLeader(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) { lua_pushnil(L); return 1; }
    return pushObject<Character>(L, c->getSquadLeader(), CharacterBinding::getMetatableName());
}

// --- State checks ------------------------------------------------------------

int CharacterBinding::isUnconcious(lua_State* L)        { Character* c = getC(L, 1); lua_pushboolean(L, c && c->isUnconcious() ? 1 : 0); return 1; }
int CharacterBinding::isDown(lua_State* L)              { Character* c = getC(L, 1); lua_pushboolean(L, c && c->isDown() ? 1 : 0); return 1; }
int CharacterBinding::isRagdoll(lua_State* L)           { Character* c = getC(L, 1); lua_pushboolean(L, c && c->isRagdoll() ? 1 : 0); return 1; }
int CharacterBinding::isCrippled(lua_State* L)          { Character* c = getC(L, 1); lua_pushboolean(L, c && c->isCrippled() ? 1 : 0); return 1; }
int CharacterBinding::isFleeing(lua_State* L)           { Character* c = getC(L, 1); lua_pushboolean(L, c && c->isFleeing() ? 1 : 0); return 1; }
int CharacterBinding::isStealthMode(lua_State* L)       { Character* c = getC(L, 1); lua_pushboolean(L, c && c->isStealthMode() ? 1 : 0); return 1; }
int CharacterBinding::isKidnapped(lua_State* L)         { Character* c = getC(L, 1); lua_pushboolean(L, c && c->isKidnapped() ? 1 : 0); return 1; }

int CharacterBinding::isInCombatMode(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) { lua_pushboolean(L, 0); return 1; }
    bool melee = lua_isnoneornil(L, 2) ? true : (lua_toboolean(L, 2) != 0);
    bool ranged = lua_isnoneornil(L, 3) ? true : (lua_toboolean(L, 3) != 0);
    lua_pushboolean(L, c->isInCombatMode(melee, ranged) ? 1 : 0);
    return 1;
}

int CharacterBinding::isInRangedCombatMode(lua_State* L) { Character* c = getC(L, 1); lua_pushboolean(L, c && c->isInRangedCombatMode() ? 1 : 0); return 1; }
int CharacterBinding::isInjured(lua_State* L)            { Character* c = getC(L, 1); bool robot = lua_toboolean(L, 2) != 0; lua_pushboolean(L, c && c->isInjured(robot) ? 1 : 0); return 1; }

int CharacterBinding::getProneState(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) { lua_pushnil(L); return 1; }
    lua_pushinteger(L, (int)c->getProneState());
    return 1;
}

int CharacterBinding::setProneState(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    ProneState state = (ProneState)luaL_checkinteger(L, 2);
    c->setProneState(state);
    return 0;
}

// --- Relations ---------------------------------------------------------------

int CharacterBinding::isEnemy(lua_State* L)
{
    Character* c = getC(L, 1);
    Character* o = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    if (!c || !o) { lua_pushboolean(L, 0); return 1; }
    bool disguises = lua_toboolean(L, 3) != 0;
    lua_pushboolean(L, c->isEnemy(o, disguises) ? 1 : 0);
    return 1;
}

int CharacterBinding::isAlly(lua_State* L)
{
    Character* c = getC(L, 1);
    Character* o = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    if (!c || !o) { lua_pushboolean(L, 0); return 1; }
    bool disguises = lua_toboolean(L, 3) != 0;
    lua_pushboolean(L, c->isAlly(o, disguises) ? 1 : 0);
    return 1;
}

// --- Combat ------------------------------------------------------------------

int CharacterBinding::attackTarget(lua_State* L)
{
    Character* c = getC(L, 1);
    Character* t = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    if (!c || !t) return luaL_error(L, "attackTarget: Character + target Character expected");
    c->attackTarget(t);
    return 0;
}

int CharacterBinding::endCombatMode(lua_State* L)
{
    Character* c = getC(L, 1);
    if (c) c->endCombatMode();
    return 0;
}

int CharacterBinding::getCurrentWeapon(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) { lua_pushnil(L); return 1; }
    // Weapon* derives from Item* in Kenshi; expose via ItemBinding so modders
    // can use the ordinary Item API on the returned wrapper.
    Item* w = (Item*)c->getCurrentWeapon();
    return pushObject<Item>(L, w, ItemBinding::getMetatableName());
}

int CharacterBinding::getAttackTarget(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) { lua_pushnil(L); return 1; }
    hand h = c->getAttackTarget();
    return pushObject<Character>(L, h.getCharacter(), CharacterBinding::getMetatableName());
}

int CharacterBinding::healCompletely(lua_State* L)
{
    Character* c = getC(L, 1);
    if (c) c->healCompletely();
    return 0;
}

// --- Inventory / stats / medical --------------------------------------------

int CharacterBinding::getInventory(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) { lua_pushnil(L); return 1; }
    return pushObject<Inventory>(L, c->inventory, InventoryBinding::getMetatableName());
}

int CharacterBinding::getStats(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) { lua_pushnil(L); return 1; }
    return pushObject<CharStats>(L, c->getStats(), CharStatsBinding::getMetatableName());
}

int CharacterBinding::getMedical(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) { lua_pushnil(L); return 1; }
    return pushObject<MedicalSystem>(L, c->getMedical(), MedicalSystemBinding::getMetatableName());
}

int CharacterBinding::getMoney(lua_State* L)
{
    Character* c = getC(L, 1);
    if (c) lua_pushinteger(L, c->getMoney()); else lua_pushnil(L);
    return 1;
}

int CharacterBinding::takeMoney(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    int n = (int)luaL_checkinteger(L, 2);
    lua_pushboolean(L, c->takeMoney(n) ? 1 : 0);
    return 1;
}

int CharacterBinding::hasItem(lua_State* L)
{
    Character* c = getC(L, 1);
    GameData* data = (GameData*)lua_touserdata(L, 2);
    if (!c) { lua_pushboolean(L, 0); return 1; }
    lua_pushboolean(L, c->hasItem(data) ? 1 : 0);
    return 1;
}

int CharacterBinding::hasRoomForItem(lua_State* L)
{
    Character* c = getC(L, 1);
    GameData* data = (GameData*)lua_touserdata(L, 2);
    if (!c) { lua_pushboolean(L, 0); return 1; }
    lua_pushboolean(L, c->hasRoomForItem(data) ? 1 : 0);
    return 1;
}

// --- Dialogue ----------------------------------------------------------------

int CharacterBinding::sayALine(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    const char* line = luaL_checkstring(L, 2);
    bool force = lua_toboolean(L, 3) != 0;
    c->sayALine(line, force);
    return 0;
}

int CharacterBinding::say(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    c->say(luaL_checkstring(L, 2));
    return 0;
}

int CharacterBinding::sendDialogEvent(lua_State* L)
{
    Character* c = getC(L, 1);
    Character* t = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    if (!c || !t) return luaL_error(L, "sendDialogEvent: Character + target Character expected");
    int ev = (int)luaL_checkinteger(L, 3);
    lua_pushboolean(L, c->sendDialogEvent(t, (EventTriggerEnum)ev) ? 1 : 0);
    return 1;
}

int CharacterBinding::sendDialogEventOverride(lua_State* L)
{
    Character* c = getC(L, 1);
    Character* t = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    if (!c || !t) return luaL_error(L, "sendDialogEventOverride: Character + target Character expected");
    int ev = (int)luaL_checkinteger(L, 3);
    bool force = lua_toboolean(L, 4) != 0;
    lua_pushboolean(L, c->sendDialogEventOverride(t, (EventTriggerEnum)ev, force) ? 1 : 0);
    return 1;
}

int CharacterBinding::hasDialogue(lua_State* L)
{
    Character* c = getC(L, 1);
    lua_pushboolean(L, c && c->hasDialogue() ? 1 : 0);
    return 1;
}

// --- Orders ------------------------------------------------------------------

int CharacterBinding::setStandingOrder(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    int order = (int)luaL_checkinteger(L, 2);
    bool on = lua_toboolean(L, 3) != 0;
    c->setStandingOrder((MessageForB::StandingOrder)order, on);
    return 0;
}

int CharacterBinding::getStandingOrder(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) { lua_pushboolean(L, 0); return 1; }
    int order = (int)luaL_checkinteger(L, 2);
    lua_pushboolean(L, c->getStandingOrder((MessageForB::StandingOrder)order) ? 1 : 0);
    return 1;
}

int CharacterBinding::setStealthMode(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    c->setStealthMode(lua_toboolean(L, 2) != 0);
    return 0;
}

// --- Age ---------------------------------------------------------------------

int CharacterBinding::getAge(lua_State* L)
{
    Character* c = getC(L, 1);
    if (c) lua_pushnumber(L, c->getAge()); else lua_pushnil(L);
    return 1;
}

int CharacterBinding::setAge(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    c->setAge((float)luaL_checknumber(L, 2));
    return 0;
}

int CharacterBinding::setSquadMemberType(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    c->setSquadMemberType((SquadMemberType)luaL_checkinteger(L, 2));
    return 0;
}

int CharacterBinding::isImmuneToOffscreenMode(lua_State* L)
{
    Character* c = getC(L, 1);
    lua_pushboolean(L, c && c->isImmuneToOffscreenMode() ? 1 : 0);
    return 1;
}

int CharacterBinding::rememberCharacter(lua_State* L)
{
    Character* c = getC(L, 1);
    if (!c) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    if (!who) return luaL_error(L, "rememberCharacter: expected Character userdata as argument 2");

    if (lua_isnumber(L, 3))
    {
        int tag = (int)lua_tointeger(L, 3);
        if (tag < 10)
            c->rememberCharacter(who, (CharacterPerceptionTags_ShortTerm)tag);
        else
            c->rememberCharacter(who, (CharacterPerceptionTags_LongTerm)(tag - 10));
    }
    else
    {
        const char* s = luaL_checkstring(L, 3);
        if (strcmp(s, "intruder") == 0) c->rememberCharacter(who, ST_INTRUDER);
        else if (strcmp(s, "aggressor") == 0) c->rememberCharacter(who, ST_AGGRESSOR);
        else if (strcmp(s, "temporary_ally") == 0) c->rememberCharacter(who, ST_TEMPORARY_ALLY);
        else if (strcmp(s, "temporary_enemy") == 0) c->rememberCharacter(who, ST_TEMPORARY_ENEMY);
        else if (strcmp(s, "prisoner") == 0) c->rememberCharacter(who, ST_PRISONER);
        else if (strcmp(s, "has_been_looted") == 0) c->rememberCharacter(who, ST_HAS_BEEN_LOOTED);
        else if (strcmp(s, "criminal") == 0) c->rememberCharacter(who, ST_CRIMINAL);
        else if (strcmp(s, "my_intruder") == 0) c->rememberCharacter(who, LT_MY_INTRUDER);
        else if (strcmp(s, "my_lifesaver") == 0) c->rememberCharacter(who, LT_MY_LIFESAVER);
        else if (strcmp(s, "freed_me") == 0) c->rememberCharacter(who, LT_FREED_ME);
        else if (strcmp(s, "stole_from_me") == 0) c->rememberCharacter(who, LT_STOLE_FROM_ME);
        else if (strcmp(s, "my_captor") == 0) c->rememberCharacter(who, LT_MY_CAPTOR);
        else if (strcmp(s, "friendly_acquaintance") == 0) c->rememberCharacter(who, LT_FRIENDLY_AQUAINTANCE);
        else if (strcmp(s, "defeated_my_squad_once") == 0) c->rememberCharacter(who, LT_DEFEATED_MY_SQUAD_ONCE);
        else if (strcmp(s, "squad_lost_to_me_once") == 0) c->rememberCharacter(who, LT_SQUAD_LOST_TO_ME_ONCE);
        else if (strcmp(s, "killed_my_friend") == 0) c->rememberCharacter(who, LT_KILLED_MY_FRIEND);
        else if (strcmp(s, "i_screwed_this_guy") == 0) c->rememberCharacter(who, LT_I_SCREWED_THIS_GUY);

        else if (strcmp(s, "ST_INTRUDER") == 0) c->rememberCharacter(who, ST_INTRUDER);
        else if (strcmp(s, "ST_AGGRESSOR") == 0) c->rememberCharacter(who, ST_AGGRESSOR);
        else if (strcmp(s, "ST_TEMPORARY_ALLY") == 0) c->rememberCharacter(who, ST_TEMPORARY_ALLY);
        else if (strcmp(s, "ST_TEMPORARY_ENEMY") == 0) c->rememberCharacter(who, ST_TEMPORARY_ENEMY);
        else if (strcmp(s, "ST_PRISONER") == 0) c->rememberCharacter(who, ST_PRISONER);
        else if (strcmp(s, "ST_HAS_BEEN_LOOTED") == 0) c->rememberCharacter(who, ST_HAS_BEEN_LOOTED);
        else if (strcmp(s, "ST_CRIMINAL") == 0) c->rememberCharacter(who, ST_CRIMINAL);
        else if (strcmp(s, "LT_MY_INTRUDER") == 0) c->rememberCharacter(who, LT_MY_INTRUDER);
        else if (strcmp(s, "LT_MY_LIFESAVER") == 0) c->rememberCharacter(who, LT_MY_LIFESAVER);
        else if (strcmp(s, "LT_FREED_ME") == 0) c->rememberCharacter(who, LT_FREED_ME);
        else if (strcmp(s, "LT_STOLE_FROM_ME") == 0) c->rememberCharacter(who, LT_STOLE_FROM_ME);
        else if (strcmp(s, "LT_MY_CAPTOR") == 0) c->rememberCharacter(who, LT_MY_CAPTOR);
        else if (strcmp(s, "LT_FRIENDLY_AQUAINTANCE") == 0) c->rememberCharacter(who, LT_FRIENDLY_AQUAINTANCE);
        else if (strcmp(s, "LT_DEFEATED_MY_SQUAD_ONCE") == 0) c->rememberCharacter(who, LT_DEFEATED_MY_SQUAD_ONCE);
        else if (strcmp(s, "LT_SQUAD_LOST_TO_ME_ONCE") == 0) c->rememberCharacter(who, LT_SQUAD_LOST_TO_ME_ONCE);
        else if (strcmp(s, "LT_KILLED_MY_FRIEND") == 0) c->rememberCharacter(who, LT_KILLED_MY_FRIEND);
        else if (strcmp(s, "LT_I_SCREWED_THIS_GUY") == 0) c->rememberCharacter(who, LT_I_SCREWED_THIS_GUY);
        else return luaL_error(L, "rememberCharacter: unknown perception tag '%s'", s);
    }
    return 0;
}

// --- Registration ------------------------------------------------------------

void CharacterBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg metamethods[] = {
        { "__gc", CharacterBinding::gc },
        { "__tostring", CharacterBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        // identity
        { "isValid",                  CharacterBinding::isValid },
        { "isPlayerCharacter",        CharacterBinding::isPlayerCharacter },
        { "isUnique",                 CharacterBinding::isUnique },
        { "isFemale",                 CharacterBinding::isFemale },
        { "isDestroyed",              CharacterBinding::isDestroyed },
        { "isDead",                   CharacterBinding::isDead },
        // name / visibility
        { "getName",                  CharacterBinding::getName },
        { "setName",                  CharacterBinding::setName },
        { "setNameTagVisible",        CharacterBinding::setNameTagVisible },
        { "getVisible",               CharacterBinding::getVisible },
        { "setVisible",               CharacterBinding::setVisible },
        // movement
        { "getPosition",              CharacterBinding::getPosition },
        { "getBoneWorldPosition",     CharacterBinding::getBoneWorldPosition },
        { "getMovementSpeed",         CharacterBinding::getMovementSpeed },
        { "getMovementDirection",     CharacterBinding::getMovementDirection },
        { "teleport",                 CharacterBinding::teleport },
        { "setDestination",           CharacterBinding::setDestination },
        // faction / race / platoon
        { "getFaction",               CharacterBinding::getFaction },
        { "setFaction",               CharacterBinding::setFaction },
        { "getRace",                  CharacterBinding::getRace },
        { "getPlatoon",               CharacterBinding::getPlatoon },
        { "getSquadLeader",           CharacterBinding::getSquadLeader },
        // state
        { "isUnconcious",             CharacterBinding::isUnconcious },
        { "isDown",                   CharacterBinding::isDown },
        { "isRagdoll",                CharacterBinding::isRagdoll },
        { "isCrippled",               CharacterBinding::isCrippled },
        { "isInCombatMode",           CharacterBinding::isInCombatMode },
        { "isInRangedCombatMode",     CharacterBinding::isInRangedCombatMode },
        { "isFleeing",                CharacterBinding::isFleeing },
        { "isStealthMode",            CharacterBinding::isStealthMode },
        { "isInjured",                CharacterBinding::isInjured },
        { "isKidnapped",              CharacterBinding::isKidnapped },
		{ "getProneState",            CharacterBinding::getProneState },
		{ "setProneState",            CharacterBinding::setProneState },
        // relations
        { "isEnemy",                  CharacterBinding::isEnemy },
        { "isAlly",                   CharacterBinding::isAlly },
        // combat
        { "attackTarget",             CharacterBinding::attackTarget },
        { "endCombatMode",            CharacterBinding::endCombatMode },
        { "getCurrentWeapon",         CharacterBinding::getCurrentWeapon },
        { "getAttackTarget",          CharacterBinding::getAttackTarget },
        { "healCompletely",           CharacterBinding::healCompletely },
        // inventory / stats / medical
        { "getInventory",             CharacterBinding::getInventory },
        { "getStats",                 CharacterBinding::getStats },
        { "getMedical",               CharacterBinding::getMedical },
        { "getMoney",                 CharacterBinding::getMoney },
        { "takeMoney",                CharacterBinding::takeMoney },
        { "hasItem",                  CharacterBinding::hasItem },
        { "hasRoomForItem",           CharacterBinding::hasRoomForItem },
        // dialogue
        { "sayALine",                 CharacterBinding::sayALine },
        { "say",                      CharacterBinding::say },
        { "sendDialogEvent",          CharacterBinding::sendDialogEvent },
        { "sendDialogEventOverride",  CharacterBinding::sendDialogEventOverride },
        { "hasDialogue",              CharacterBinding::hasDialogue },
        // orders
        { "setStandingOrder",         CharacterBinding::setStandingOrder },
        { "getStandingOrder",         CharacterBinding::getStandingOrder },
        { "setStealthMode",           CharacterBinding::setStealthMode },
        // age
        { "getAge",                   CharacterBinding::getAge },
        { "setAge",                   CharacterBinding::setAge },
        { "setSquadMemberType",       CharacterBinding::setSquadMemberType },
        { "rememberCharacter",        CharacterBinding::rememberCharacter },
        { "isImmuneToOffscreenMode",  CharacterBinding::isImmuneToOffscreenMode },
        { 0, 0 }
    };

    registerClass(
        L,
        CharacterBinding::getMetatableName(),
        metamethods,
        methods,
        CharacterBinding::index,
        CharacterBinding::newindex
    );
}

} // namespace KenshiLua