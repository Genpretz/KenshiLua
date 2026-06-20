#include "pch.h"
#include "Bindings/Dialogue/DialogLineDataBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Dialogue.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static DialogLineData* getS(lua_State* L, int idx)
{
    return checkObject<DialogLineData>(L, idx, DialogLineDataBinding::getMetatableName());
}

int DialogLineDataBinding::gc(lua_State* L) { return noopGc(L); }

int DialogLineDataBinding::tostring(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int DialogLineDataBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, DialogLineDataBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    DialogLineData* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "targetFlagsNeeded") == 0) { lua_pushinteger(L, s->targetFlagsNeeded); return 1; }
    if (strcmp(key, "targetFlagsNotWanted") == 0) { lua_pushinteger(L, s->targetFlagsNotWanted); return 1; }
    if (strcmp(key, "personalityNeeded") == 0) { lua_pushinteger(L, s->personalityNeeded); return 1; }
    if (strcmp(key, "personalityNotWanted") == 0) { lua_pushinteger(L, s->personalityNotWanted); return 1; }
    // TODO FitnessSelector<CampaignTriggerData*> campaignTriggers; unsupported __index type from header line 179
    // TODO lektor<GameData*> isTargetRace; unsupported __index type from header line 180
    // TODO lektor<GameData*> isTargetSubRace_specificallyTheTarget; unsupported __index type from header line 181
    // TODO lektor<GameDataValuePair> givesItem; unsupported __index type from header line 183
    // TODO std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > inTownOf; unsupported __index type from header line 186
    // TODO std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > isTargetFaction; unsupported __index type from header line 187
    // TODO std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > isMyFaction; unsupported __index type from header line 188
    // TODO lektor<GameData*> isCharacter; unsupported __index type from header line 189
    // TODO lektor<GameData*> isTargetCarryingCharacter; unsupported __index type from header line 190
    // TODO lektor<GameData*> _hasPackage; unsupported __index type from header line 191
    // TODO lektor<GameData*> isMyRace; unsupported __index type from header line 192
    // TODO lektor<GameData*> isMySubRace; unsupported __index type from header line 193
    // TODO ItemFunction hasItemType; unsupported __index type from header line 194
    // TODO lektor<GameData*> hasItem; unsupported __index type from header line 195
    // TODO WorldEventStateQueryList* worldState; unsupported __index type from header line 196
    if (strcmp(key, "data") == 0) { return pushObject<GameData>(L, s->data, GameDataBinding::getMetatableName()); }
    if (strcmp(key, "onceOnly") == 0) { lua_pushboolean(L, s->onceOnly ? 1 : 0); return 1; }
    if (strcmp(key, "isMonologue") == 0) { lua_pushboolean(L, s->isMonologue ? 1 : 0); return 1; }
    // TODO CharacterTypeEnum forCertainType; unsupported __index type from header line 210
    // TODO DialogChoiceList* children; unsupported __index type from header line 211
    // TODO lektor<DialogLineData::DialogCondition*> conditions; unsupported __index type from header line 212
    // TODO lektor<DialogLineData::DialogAction*> actions; unsupported __index type from header line 213
    if (strcmp(key, "lineCount") == 0) { lua_pushinteger(L, s->lineCount); return 1; }
    if (strcmp(key, "texts") == 0) { lua_pushstring(L, s->texts.c_str()); return 1; }
    // TODO DialogLineData* parent; unsupported __index type from header line 216
    if (strcmp(key, "chancePermanent") == 0) { lua_pushnumber(L, s->chancePermanent); return 1; }
    if (strcmp(key, "chanceTemporary") == 0) { lua_pushnumber(L, s->chanceTemporary); return 1; }
    if (strcmp(key, "unique") == 0) { lua_pushboolean(L, s->unique ? 1 : 0); return 1; }
    // TODO hand uniqueOwner; unsupported __index type from header line 220
    if (strcmp(key, "dialogRepeatMinTimeInHours") == 0) { lua_pushnumber(L, s->dialogRepeatMinTimeInHours); return 1; }
    // TODO TimeOfDay lastTimeSaid; unsupported __index type from header line 222
    if (strcmp(key, "score") == 0) { lua_pushinteger(L, s->score); return 1; }
    if (strcmp(key, "oneAtATime") == 0) { lua_pushboolean(L, s->oneAtATime ? 1 : 0); return 1; }
    if (strcmp(key, "isLocked") == 0) { lua_pushboolean(L, s->isLocked ? 1 : 0); return 1; }
    // TODO lektor<DialogLineData*> locks; unsupported __index type from header line 226
    // TODO lektor<DialogLineData*> unlocks_lockMe; unsupported __index type from header line 227
    // TODO lektor<DialogLineData*> unlocks_dontLockMe; unsupported __index type from header line 228
    // TODO DialogLineData* crowdTrigger; unsupported __index type from header line 229
    // TODO ogre_unordered_map<GameData*, int>::type factionRelationEffects; unsupported __index type from header line 237
    // TODO DialogLineData* playerInterruptionDialog; unsupported __index type from header line 238
    if (strcmp(key, "isInterjection") == 0) { lua_pushboolean(L, s->isInterjection ? 1 : 0); return 1; }
    // TODO TalkerEnum speaker; unsupported __index type from header line 240

    lua_pushnil(L);
    return 1;
}

int DialogLineDataBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    if (strcmp(key, "targetFlagsNeeded") == 0) { s->targetFlagsNeeded = (unsigned int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "targetFlagsNotWanted") == 0) { s->targetFlagsNotWanted = (unsigned int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "personalityNeeded") == 0) { s->personalityNeeded = (unsigned int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "personalityNotWanted") == 0) { s->personalityNotWanted = (unsigned int)luaL_checkinteger(L, 3); return 0; }
    // TODO FitnessSelector<CampaignTriggerData*> campaignTriggers; unsupported __newindex type from header line 179
    // TODO lektor<GameData*> isTargetRace; unsupported __newindex type from header line 180
    // TODO lektor<GameData*> isTargetSubRace_specificallyTheTarget; unsupported __newindex type from header line 181
    // TODO lektor<GameDataValuePair> givesItem; unsupported __newindex type from header line 183
    // TODO std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > inTownOf; unsupported __newindex type from header line 186
    // TODO std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > isTargetFaction; unsupported __newindex type from header line 187
    // TODO std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > isMyFaction; unsupported __newindex type from header line 188
    // TODO lektor<GameData*> isCharacter; unsupported __newindex type from header line 189
    // TODO lektor<GameData*> isTargetCarryingCharacter; unsupported __newindex type from header line 190
    // TODO lektor<GameData*> _hasPackage; unsupported __newindex type from header line 191
    // TODO lektor<GameData*> isMyRace; unsupported __newindex type from header line 192
    // TODO lektor<GameData*> isMySubRace; unsupported __newindex type from header line 193
    // TODO ItemFunction hasItemType; unsupported __newindex type from header line 194
    // TODO lektor<GameData*> hasItem; unsupported __newindex type from header line 195
    // TODO WorldEventStateQueryList* worldState; unsupported __newindex type from header line 196
    // TODO GameData* data; unsupported __newindex type from header line 207
    if (strcmp(key, "onceOnly") == 0) { s->onceOnly = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "isMonologue") == 0) { s->isMonologue = lua_toboolean(L, 3) != 0; return 0; }
    // TODO CharacterTypeEnum forCertainType; unsupported __newindex type from header line 210
    // TODO DialogChoiceList* children; unsupported __newindex type from header line 211
    // TODO lektor<DialogLineData::DialogCondition*> conditions; unsupported __newindex type from header line 212
    // TODO lektor<DialogLineData::DialogAction*> actions; unsupported __newindex type from header line 213
    if (strcmp(key, "lineCount") == 0) { s->lineCount = (int)luaL_checkinteger(L, 3); return 0; }
    // TODO std::string* texts; unsupported __newindex type from header line 215
    // TODO DialogLineData* parent; unsupported __newindex type from header line 216
    if (strcmp(key, "chancePermanent") == 0) { s->chancePermanent = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "chanceTemporary") == 0) { s->chanceTemporary = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "unique") == 0) { s->unique = lua_toboolean(L, 3) != 0; return 0; }
    // TODO hand uniqueOwner; unsupported __newindex type from header line 220
    if (strcmp(key, "dialogRepeatMinTimeInHours") == 0) { s->dialogRepeatMinTimeInHours = (float)luaL_checknumber(L, 3); return 0; }
    // TODO TimeOfDay lastTimeSaid; unsupported __newindex type from header line 222
    if (strcmp(key, "score") == 0) { s->score = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "oneAtATime") == 0) { s->oneAtATime = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "isLocked") == 0) { s->isLocked = lua_toboolean(L, 3) != 0; return 0; }
    // TODO lektor<DialogLineData*> locks; unsupported __newindex type from header line 226
    // TODO lektor<DialogLineData*> unlocks_lockMe; unsupported __newindex type from header line 227
    // TODO lektor<DialogLineData*> unlocks_dontLockMe; unsupported __newindex type from header line 228
    // TODO DialogLineData* crowdTrigger; unsupported __newindex type from header line 229
    // TODO ogre_unordered_map<GameData*, int>::type factionRelationEffects; unsupported __newindex type from header line 237
    // TODO DialogLineData* playerInterruptionDialog; unsupported __newindex type from header line 238
    if (strcmp(key, "isInterjection") == 0) { s->isInterjection = lua_toboolean(L, 3) != 0; return 0; }
    // TODO TalkerEnum speaker; unsupported __newindex type from header line 240

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int DialogLineDataBinding::hasSpecificCharacterRequirement(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    bool result = s->hasSpecificCharacterRequirement();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::_DESTRUCTOR(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    s->_DESTRUCTOR();
    return 0;
}

int DialogLineDataBinding::setupChildren(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    s->setupChildren();
    return 0;
}

int DialogLineDataBinding::checkRepeatLimits(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    bool result = s->checkRepeatLimits();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::getName(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    std::string result = s->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int DialogLineDataBinding::saidItBefore(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    bool result = s->saidItBefore();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::willTalkToEnemies(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    bool result = s->willTalkToEnemies();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::isEmptyNode(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    bool result = s->isEmptyNode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::_NV_isEmptyNode(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    bool result = s->_NV_isEmptyNode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::isAnnouncement(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    bool result = s->isAnnouncement();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::stampLastTimeSaid(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    s->stampLastTimeSaid();
    return 0;
}

int DialogLineDataBinding::hasChildren(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    bool result = s->hasChildren();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::getStringID(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    std::string result = s->getStringID();
    lua_pushstring(L, result.c_str());
    return 1;
}

int DialogLineDataBinding::getGameData(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    GameData result = s->getGameData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int DialogLineDataBinding::getMoneyCostForLine(lua_State* L)
{
    DialogLineData* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogLineData is nil");

    int result = s->getMoneyCostForLine();
    lua_pushinteger(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 182: DialogLineData* getParent(...) - unsupported return type
  line 184: bool isForSpecificCharacter(...) - unsupported arg type
  line 197: void _initialiseAList(...) - overloaded method
  line 198: void _initialiseAList(...) - overloaded method
  line 201: DialogLineData* _CONSTRUCTOR(...) - unsupported return type
  line 206: bool checkTags(...) - unsupported arg type
  line 241: int getScore(...) - unsupported arg type
  line 242: int getScorePlusChildrenIfEmpty(...) - unsupported arg type
  line 244: bool checkConditions(...) - unsupported arg type
  line 245: DialogLineData* chooseAChild(...) - unsupported return type
  line 246: std::string getText(...) - overloaded method
  line 247: void getText(...) - overloaded method
  line 250: DialogLineData* getChildByStringID(...) - unsupported return type
  line 251: void getPlayerReplies(...) - unsupported arg type
  line 252: void setParent(...) - unsupported arg type
  line 254: const lektor<DialogLineData::DialogAction*>* getActions(...) - unsupported return type
*/

void DialogLineDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogLineDataBinding::gc },
        { "__tostring", DialogLineDataBinding::tostring },
        { "__index",    DialogLineDataBinding::index },
        { "__newindex", DialogLineDataBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "hasSpecificCharacterRequirement", DialogLineDataBinding::hasSpecificCharacterRequirement },
        { "_DESTRUCTOR", DialogLineDataBinding::_DESTRUCTOR },
        { "setupChildren", DialogLineDataBinding::setupChildren },
        { "checkRepeatLimits", DialogLineDataBinding::checkRepeatLimits },
        { "getName", DialogLineDataBinding::getName },
        { "saidItBefore", DialogLineDataBinding::saidItBefore },
        { "willTalkToEnemies", DialogLineDataBinding::willTalkToEnemies },
        { "isEmptyNode", DialogLineDataBinding::isEmptyNode },
        { "_NV_isEmptyNode", DialogLineDataBinding::_NV_isEmptyNode },
        { "isAnnouncement", DialogLineDataBinding::isAnnouncement },
        { "stampLastTimeSaid", DialogLineDataBinding::stampLastTimeSaid },
        { "hasChildren", DialogLineDataBinding::hasChildren },
        { "getStringID", DialogLineDataBinding::getStringID },
        { "getGameData", DialogLineDataBinding::getGameData },
        { "getMoneyCostForLine", DialogLineDataBinding::getMoneyCostForLine },
        { 0, 0 }
    };
    registerClass(L, DialogLineDataBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua