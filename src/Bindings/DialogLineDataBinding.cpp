#include "pch.h"
#include "kenshi\Dialogue.h"
#include "DialogLineDataBinding.h"
#include "DialogChoiceListBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/DialogChoiceListBinding.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static DialogLineData* getB(lua_State* L, int idx)
{
    return checkObject<DialogLineData>(L, idx, DialogLineDataBinding::getMetatableName());
}

// --- Getters for DialogLineData ---
static int DialogLineData_get_targetFlagsNeeded(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, b->targetFlagsNeeded);
    return 1;
}

static int DialogLineData_get_targetFlagsNotWanted(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, b->targetFlagsNotWanted);
    return 1;
}

static int DialogLineData_get_personalityNeeded(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, b->personalityNeeded);
    return 1;
}

static int DialogLineData_get_personalityNotWanted(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, b->personalityNotWanted);
    return 1;
}

static int DialogLineData_get_campaignTriggers(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for campaignTriggers (FitnessSelector<CampaignTriggerData*>)
    return luaL_error(L, "Unsupported property 'campaignTriggers' (type: FitnessSelector<CampaignTriggerData*>)");
}

static int DialogLineData_get_isTargetRace(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for isTargetRace (lektor<GameData*>)
    return luaL_error(L, "Unsupported property 'isTargetRace' (type: lektor<GameData*>)");
}

static int DialogLineData_get_isTargetSubRace_specificallyTheTarget(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for isTargetSubRace_specificallyTheTarget (lektor<GameData*>)
    return luaL_error(L, "Unsupported property 'isTargetSubRace_specificallyTheTarget' (type: lektor<GameData*>)");
}

static int DialogLineData_get_givesItem(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for givesItem (lektor<GameDataValuePair>)
    return luaL_error(L, "Unsupported property 'givesItem' (type: lektor<GameDataValuePair>)");
}

static int DialogLineData_get_inTownOf(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for inTownOf (std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'inTownOf' (type: std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > >)");
}

static int DialogLineData_get_isTargetFaction(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for isTargetFaction (std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'isTargetFaction' (type: std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > >)");
}

static int DialogLineData_get_isMyFaction(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for isMyFaction (std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'isMyFaction' (type: std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > >)");
}

static int DialogLineData_get_isCharacter(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_newtable(L);
    for (unsigned int i = 0; i < b->isCharacter.size(); ++i)
    {
        pushObject<GameData>(L, b->isCharacter[i], GameDataBinding::getMetatableName());
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int DialogLineData_get_isTargetCarryingCharacter(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_newtable(L);
    for (unsigned int i = 0; i < b->isTargetCarryingCharacter.size(); ++i)
    {
        pushObject<GameData>(L, b->isTargetCarryingCharacter[i], GameDataBinding::getMetatableName());
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int DialogLineData_get__hasPackage(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_newtable(L);
    for (unsigned int i = 0; i < b->_hasPackage.size(); ++i)
    {
        pushObject<GameData>(L, b->_hasPackage[i], GameDataBinding::getMetatableName());
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int DialogLineData_get_isMyRace(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_newtable(L);
    for (unsigned int i = 0; i < b->isMyRace.size(); ++i)
    {
        pushObject<GameData>(L, b->isMyRace[i], GameDataBinding::getMetatableName());
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int DialogLineData_get_isMySubRace(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_newtable(L);
    for (unsigned int i = 0; i < b->isMySubRace.size(); ++i)
    {
        pushObject<GameData>(L, b->isMySubRace[i], GameDataBinding::getMetatableName());
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int DialogLineData_get_hasItemType(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, (lua_Integer)b->hasItemType);
    return 1;
}

static int DialogLineData_get_hasItem(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for hasItem (lektor<GameData*>)
    return luaL_error(L, "Unsupported property 'hasItem' (type: lektor<GameData*>)");
}

static int DialogLineData_get_worldState(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for worldState (WorldEventStateQueryList*)
    return luaL_error(L, "Unsupported property 'worldState' (type: WorldEventStateQueryList*)");
}

static int DialogLineData_get_data(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return pushObject<GameData>(L, b->data, GameDataBinding::getMetatableName());
}

static int DialogLineData_get_onceOnly(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushboolean(L, b->onceOnly ? 1 : 0);
    return 1;
}

static int DialogLineData_get_isMonologue(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushboolean(L, b->isMonologue ? 1 : 0);
    return 1;
}

static int DialogLineData_get_forCertainType(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for forCertainType (CharacterTypeEnum)
    return luaL_error(L, "Unsupported property 'forCertainType' (type: CharacterTypeEnum)");
}

static int DialogLineData_get_children(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return pushObject<DialogChoiceList>(L, b->children, DialogChoiceListBinding::getMetatableName());
}

static int DialogLineData_get_conditions(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for conditions (lektor<DialogLineData::DialogCondition*>)
    return luaL_error(L, "Unsupported property 'conditions' (type: lektor<DialogLineData::DialogCondition*>)");
}

static int DialogLineData_get_actions(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for actions (lektor<DialogLineData::DialogAction*>)
    return luaL_error(L, "Unsupported property 'actions' (type: lektor<DialogLineData::DialogAction*>)");
}

static int DialogLineData_get_lineCount(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, b->lineCount);
    return 1;
}

static int DialogLineData_get_texts(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushstring(L, b->texts ? b->texts->c_str() : "");
    return 1;
}

static int DialogLineData_get_parent(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for parent (DialogLineData*)
    return luaL_error(L, "Unsupported property 'parent' (type: DialogLineData*)");
}

static int DialogLineData_get_chancePermanent(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushnumber(L, b->chancePermanent);
    return 1;
}

static int DialogLineData_get_chanceTemporary(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushnumber(L, b->chanceTemporary);
    return 1;
}

static int DialogLineData_get_unique(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushboolean(L, b->unique ? 1 : 0);
    return 1;
}

static int DialogLineData_get_uniqueOwner(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for uniqueOwner (hand)
    return luaL_error(L, "Unsupported property 'uniqueOwner' (type: hand)");
}

static int DialogLineData_get_dialogRepeatMinTimeInHours(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushnumber(L, b->dialogRepeatMinTimeInHours);
    return 1;
}

static int DialogLineData_get_lastTimeSaid(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for lastTimeSaid (TimeOfDay)
    return luaL_error(L, "Unsupported property 'lastTimeSaid' (type: TimeOfDay)");
}

static int DialogLineData_get_score(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, b->score);
    return 1;
}

static int DialogLineData_get_oneAtATime(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushboolean(L, b->oneAtATime ? 1 : 0);
    return 1;
}

static int DialogLineData_get_isLocked(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushboolean(L, b->isLocked ? 1 : 0);
    return 1;
}

static int DialogLineData_get_locks(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for locks (lektor<DialogLineData*>)
    return luaL_error(L, "Unsupported property 'locks' (type: lektor<DialogLineData*>)");
}

static int DialogLineData_get_unlocks_lockMe(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for unlocks_lockMe (lektor<DialogLineData*>)
    return luaL_error(L, "Unsupported property 'unlocks_lockMe' (type: lektor<DialogLineData*>)");
}

static int DialogLineData_get_unlocks_dontLockMe(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for unlocks_dontLockMe (lektor<DialogLineData*>)
    return luaL_error(L, "Unsupported property 'unlocks_dontLockMe' (type: lektor<DialogLineData*>)");
}

static int DialogLineData_get_crowdTrigger(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for crowdTrigger (DialogLineData*)
    return luaL_error(L, "Unsupported property 'crowdTrigger' (type: DialogLineData*)");
}

static int DialogLineData_get_factionRelationEffects(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for factionRelationEffects (ogre_unordered_map<GameData*, int>::type)
    return luaL_error(L, "Unsupported property 'factionRelationEffects' (type: ogre_unordered_map<GameData*, int>::type)");
}

static int DialogLineData_get_playerInterruptionDialog(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for playerInterruptionDialog (DialogLineData*)
    return luaL_error(L, "Unsupported property 'playerInterruptionDialog' (type: DialogLineData*)");
}

static int DialogLineData_get_isInterjection(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    lua_pushboolean(L, b->isInterjection ? 1 : 0);
    return 1;
}

static int DialogLineData_get_speaker(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    // TODO: Unsupported type for speaker (TalkerEnum)
    return luaL_error(L, "Unsupported property 'speaker' (type: TalkerEnum)");
}

// --- Setters for DialogLineData ---
static int DialogLineData_set_targetFlagsNeeded(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->targetFlagsNeeded = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_targetFlagsNotWanted(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->targetFlagsNotWanted = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_personalityNeeded(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->personalityNeeded = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_personalityNotWanted(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->personalityNotWanted = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_campaignTriggers(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for campaignTriggers");
}

static int DialogLineData_set_isTargetRace(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isTargetRace");
}

static int DialogLineData_set_isTargetSubRace_specificallyTheTarget(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isTargetSubRace_specificallyTheTarget");
}

static int DialogLineData_set_givesItem(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for givesItem");
}

static int DialogLineData_set_inTownOf(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for inTownOf");
}

static int DialogLineData_set_isTargetFaction(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isTargetFaction");
}

static int DialogLineData_set_isMyFaction(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isMyFaction");
}

static int DialogLineData_set_isCharacter(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isCharacter");
}

static int DialogLineData_set_isTargetCarryingCharacter(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isTargetCarryingCharacter");
}

static int DialogLineData_set__hasPackage(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _hasPackage");
}

static int DialogLineData_set_isMyRace(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isMyRace");
}

static int DialogLineData_set_isMySubRace(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isMySubRace");
}

static int DialogLineData_set_hasItemType(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->hasItemType = (ItemFunction)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_hasItem(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for hasItem");
}

static int DialogLineData_set_worldState(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for worldState");
}

static int DialogLineData_set_data(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for data");
}

static int DialogLineData_set_onceOnly(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->onceOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogLineData_set_isMonologue(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->isMonologue = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogLineData_set_forCertainType(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for forCertainType");
}

static int DialogLineData_set_children(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for children");
}

static int DialogLineData_set_conditions(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for conditions");
}

static int DialogLineData_set_actions(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for actions");
}

static int DialogLineData_set_lineCount(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->lineCount = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_texts(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for texts");
}

static int DialogLineData_set_parent(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for parent");
}

static int DialogLineData_set_chancePermanent(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->chancePermanent = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DialogLineData_set_chanceTemporary(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->chanceTemporary = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DialogLineData_set_unique(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->unique = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogLineData_set_uniqueOwner(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for uniqueOwner");
}

static int DialogLineData_set_dialogRepeatMinTimeInHours(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->dialogRepeatMinTimeInHours = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DialogLineData_set_lastTimeSaid(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for lastTimeSaid");
}

static int DialogLineData_set_score(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->score = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_oneAtATime(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->oneAtATime = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogLineData_set_isLocked(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->isLocked = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogLineData_set_locks(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for locks");
}

static int DialogLineData_set_unlocks_lockMe(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for unlocks_lockMe");
}

static int DialogLineData_set_unlocks_dontLockMe(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for unlocks_dontLockMe");
}

static int DialogLineData_set_crowdTrigger(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for crowdTrigger");
}

static int DialogLineData_set_factionRelationEffects(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for factionRelationEffects");
}

static int DialogLineData_set_playerInterruptionDialog(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for playerInterruptionDialog");
}

static int DialogLineData_set_isInterjection(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    b->isInterjection = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogLineData_set_speaker(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for speaker");
}

int DialogLineDataBinding::hasSpecificCharacterRequirement(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    bool result = b->hasSpecificCharacterRequirement();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::_DESTRUCTOR(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    b->_DESTRUCTOR();
    return 0;
}

int DialogLineDataBinding::setupChildren(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    b->setupChildren();
    return 0;
}

int DialogLineDataBinding::checkRepeatLimits(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    bool result = b->checkRepeatLimits();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::getName(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    std::string result = b->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int DialogLineDataBinding::saidItBefore(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    bool result = b->saidItBefore();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::willTalkToEnemies(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    bool result = b->willTalkToEnemies();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::isEmptyNode(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    bool result = b->isEmptyNode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::_NV_isEmptyNode(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    bool result = b->_NV_isEmptyNode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::isAnnouncement(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    bool result = b->isAnnouncement();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::stampLastTimeSaid(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    b->stampLastTimeSaid();
    return 0;
}

int DialogLineDataBinding::hasChildren(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    bool result = b->hasChildren();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::getStringID(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    std::string result = b->getStringID();
    lua_pushstring(L, result.c_str());
    return 1;
}

int DialogLineDataBinding::getGameData(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    GameData* result = b->getGameData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int DialogLineDataBinding::getMoneyCostForLine(lua_State* L)
{
    DialogLineData* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogLineData is nil");

    int result = b->getMoneyCostForLine();
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

int DialogLineDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DialogLineDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DialogLineData object");
    return 1;
}

void DialogLineDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogLineDataBinding::gc },
        { "__tostring", DialogLineDataBinding::tostring },
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

    registerClass(
        L, 
        DialogLineDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DialogLineDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DialogLineData_get_targetFlagsNeeded);
    lua_setfield(L, -2, "targetFlagsNeeded");
    lua_pushcfunction(L, DialogLineData_get_targetFlagsNotWanted);
    lua_setfield(L, -2, "targetFlagsNotWanted");
    lua_pushcfunction(L, DialogLineData_get_personalityNeeded);
    lua_setfield(L, -2, "personalityNeeded");
    lua_pushcfunction(L, DialogLineData_get_personalityNotWanted);
    lua_setfield(L, -2, "personalityNotWanted");
    lua_pushcfunction(L, DialogLineData_get_campaignTriggers);
    lua_setfield(L, -2, "campaignTriggers");
    lua_pushcfunction(L, DialogLineData_get_isTargetRace);
    lua_setfield(L, -2, "isTargetRace");
    lua_pushcfunction(L, DialogLineData_get_isTargetSubRace_specificallyTheTarget);
    lua_setfield(L, -2, "isTargetSubRace_specificallyTheTarget");
    lua_pushcfunction(L, DialogLineData_get_givesItem);
    lua_setfield(L, -2, "givesItem");
    lua_pushcfunction(L, DialogLineData_get_inTownOf);
    lua_setfield(L, -2, "inTownOf");
    lua_pushcfunction(L, DialogLineData_get_isTargetFaction);
    lua_setfield(L, -2, "isTargetFaction");
    lua_pushcfunction(L, DialogLineData_get_isMyFaction);
    lua_setfield(L, -2, "isMyFaction");
    lua_pushcfunction(L, DialogLineData_get_isCharacter);
    lua_setfield(L, -2, "isCharacter");
    lua_pushcfunction(L, DialogLineData_get_isTargetCarryingCharacter);
    lua_setfield(L, -2, "isTargetCarryingCharacter");
    lua_pushcfunction(L, DialogLineData_get__hasPackage);
    lua_setfield(L, -2, "_hasPackage");
    lua_pushcfunction(L, DialogLineData_get_isMyRace);
    lua_setfield(L, -2, "isMyRace");
    lua_pushcfunction(L, DialogLineData_get_isMySubRace);
    lua_setfield(L, -2, "isMySubRace");
    lua_pushcfunction(L, DialogLineData_get_hasItemType);
    lua_setfield(L, -2, "hasItemType");
    lua_pushcfunction(L, DialogLineData_get_hasItem);
    lua_setfield(L, -2, "hasItem");
    lua_pushcfunction(L, DialogLineData_get_worldState);
    lua_setfield(L, -2, "worldState");
    lua_pushcfunction(L, DialogLineData_get_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, DialogLineData_get_onceOnly);
    lua_setfield(L, -2, "onceOnly");
    lua_pushcfunction(L, DialogLineData_get_isMonologue);
    lua_setfield(L, -2, "isMonologue");
    lua_pushcfunction(L, DialogLineData_get_forCertainType);
    lua_setfield(L, -2, "forCertainType");
    lua_pushcfunction(L, DialogLineData_get_children);
    lua_setfield(L, -2, "children");
    lua_pushcfunction(L, DialogLineData_get_conditions);
    lua_setfield(L, -2, "conditions");
    lua_pushcfunction(L, DialogLineData_get_actions);
    lua_setfield(L, -2, "actions");
    lua_pushcfunction(L, DialogLineData_get_lineCount);
    lua_setfield(L, -2, "lineCount");
    lua_pushcfunction(L, DialogLineData_get_texts);
    lua_setfield(L, -2, "texts");
    lua_pushcfunction(L, DialogLineData_get_parent);
    lua_setfield(L, -2, "parent");
    lua_pushcfunction(L, DialogLineData_get_chancePermanent);
    lua_setfield(L, -2, "chancePermanent");
    lua_pushcfunction(L, DialogLineData_get_chanceTemporary);
    lua_setfield(L, -2, "chanceTemporary");
    lua_pushcfunction(L, DialogLineData_get_unique);
    lua_setfield(L, -2, "unique");
    lua_pushcfunction(L, DialogLineData_get_uniqueOwner);
    lua_setfield(L, -2, "uniqueOwner");
    lua_pushcfunction(L, DialogLineData_get_dialogRepeatMinTimeInHours);
    lua_setfield(L, -2, "dialogRepeatMinTimeInHours");
    lua_pushcfunction(L, DialogLineData_get_lastTimeSaid);
    lua_setfield(L, -2, "lastTimeSaid");
    lua_pushcfunction(L, DialogLineData_get_score);
    lua_setfield(L, -2, "score");
    lua_pushcfunction(L, DialogLineData_get_oneAtATime);
    lua_setfield(L, -2, "oneAtATime");
    lua_pushcfunction(L, DialogLineData_get_isLocked);
    lua_setfield(L, -2, "isLocked");
    lua_pushcfunction(L, DialogLineData_get_locks);
    lua_setfield(L, -2, "locks");
    lua_pushcfunction(L, DialogLineData_get_unlocks_lockMe);
    lua_setfield(L, -2, "unlocks_lockMe");
    lua_pushcfunction(L, DialogLineData_get_unlocks_dontLockMe);
    lua_setfield(L, -2, "unlocks_dontLockMe");
    lua_pushcfunction(L, DialogLineData_get_crowdTrigger);
    lua_setfield(L, -2, "crowdTrigger");
    lua_pushcfunction(L, DialogLineData_get_factionRelationEffects);
    lua_setfield(L, -2, "factionRelationEffects");
    lua_pushcfunction(L, DialogLineData_get_playerInterruptionDialog);
    lua_setfield(L, -2, "playerInterruptionDialog");
    lua_pushcfunction(L, DialogLineData_get_isInterjection);
    lua_setfield(L, -2, "isInterjection");
    lua_pushcfunction(L, DialogLineData_get_speaker);
    lua_setfield(L, -2, "speaker");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DialogLineData_set_targetFlagsNeeded);
    lua_setfield(L, -2, "targetFlagsNeeded");
    lua_pushcfunction(L, DialogLineData_set_targetFlagsNotWanted);
    lua_setfield(L, -2, "targetFlagsNotWanted");
    lua_pushcfunction(L, DialogLineData_set_personalityNeeded);
    lua_setfield(L, -2, "personalityNeeded");
    lua_pushcfunction(L, DialogLineData_set_personalityNotWanted);
    lua_setfield(L, -2, "personalityNotWanted");
    lua_pushcfunction(L, DialogLineData_set_campaignTriggers);
    lua_setfield(L, -2, "campaignTriggers");
    lua_pushcfunction(L, DialogLineData_set_isTargetRace);
    lua_setfield(L, -2, "isTargetRace");
    lua_pushcfunction(L, DialogLineData_set_isTargetSubRace_specificallyTheTarget);
    lua_setfield(L, -2, "isTargetSubRace_specificallyTheTarget");
    lua_pushcfunction(L, DialogLineData_set_givesItem);
    lua_setfield(L, -2, "givesItem");
    lua_pushcfunction(L, DialogLineData_set_inTownOf);
    lua_setfield(L, -2, "inTownOf");
    lua_pushcfunction(L, DialogLineData_set_isTargetFaction);
    lua_setfield(L, -2, "isTargetFaction");
    lua_pushcfunction(L, DialogLineData_set_isMyFaction);
    lua_setfield(L, -2, "isMyFaction");
    lua_pushcfunction(L, DialogLineData_set_isCharacter);
    lua_setfield(L, -2, "isCharacter");
    lua_pushcfunction(L, DialogLineData_set_isTargetCarryingCharacter);
    lua_setfield(L, -2, "isTargetCarryingCharacter");
    lua_pushcfunction(L, DialogLineData_set__hasPackage);
    lua_setfield(L, -2, "_hasPackage");
    lua_pushcfunction(L, DialogLineData_set_isMyRace);
    lua_setfield(L, -2, "isMyRace");
    lua_pushcfunction(L, DialogLineData_set_isMySubRace);
    lua_setfield(L, -2, "isMySubRace");
    lua_pushcfunction(L, DialogLineData_set_hasItemType);
    lua_setfield(L, -2, "hasItemType");
    lua_pushcfunction(L, DialogLineData_set_hasItem);
    lua_setfield(L, -2, "hasItem");
    lua_pushcfunction(L, DialogLineData_set_worldState);
    lua_setfield(L, -2, "worldState");
    lua_pushcfunction(L, DialogLineData_set_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, DialogLineData_set_onceOnly);
    lua_setfield(L, -2, "onceOnly");
    lua_pushcfunction(L, DialogLineData_set_isMonologue);
    lua_setfield(L, -2, "isMonologue");
    lua_pushcfunction(L, DialogLineData_set_forCertainType);
    lua_setfield(L, -2, "forCertainType");
    lua_pushcfunction(L, DialogLineData_set_children);
    lua_setfield(L, -2, "children");
    lua_pushcfunction(L, DialogLineData_set_conditions);
    lua_setfield(L, -2, "conditions");
    lua_pushcfunction(L, DialogLineData_set_actions);
    lua_setfield(L, -2, "actions");
    lua_pushcfunction(L, DialogLineData_set_lineCount);
    lua_setfield(L, -2, "lineCount");
    lua_pushcfunction(L, DialogLineData_set_texts);
    lua_setfield(L, -2, "texts");
    lua_pushcfunction(L, DialogLineData_set_parent);
    lua_setfield(L, -2, "parent");
    lua_pushcfunction(L, DialogLineData_set_chancePermanent);
    lua_setfield(L, -2, "chancePermanent");
    lua_pushcfunction(L, DialogLineData_set_chanceTemporary);
    lua_setfield(L, -2, "chanceTemporary");
    lua_pushcfunction(L, DialogLineData_set_unique);
    lua_setfield(L, -2, "unique");
    lua_pushcfunction(L, DialogLineData_set_uniqueOwner);
    lua_setfield(L, -2, "uniqueOwner");
    lua_pushcfunction(L, DialogLineData_set_dialogRepeatMinTimeInHours);
    lua_setfield(L, -2, "dialogRepeatMinTimeInHours");
    lua_pushcfunction(L, DialogLineData_set_lastTimeSaid);
    lua_setfield(L, -2, "lastTimeSaid");
    lua_pushcfunction(L, DialogLineData_set_score);
    lua_setfield(L, -2, "score");
    lua_pushcfunction(L, DialogLineData_set_oneAtATime);
    lua_setfield(L, -2, "oneAtATime");
    lua_pushcfunction(L, DialogLineData_set_isLocked);
    lua_setfield(L, -2, "isLocked");
    lua_pushcfunction(L, DialogLineData_set_locks);
    lua_setfield(L, -2, "locks");
    lua_pushcfunction(L, DialogLineData_set_unlocks_lockMe);
    lua_setfield(L, -2, "unlocks_lockMe");
    lua_pushcfunction(L, DialogLineData_set_unlocks_dontLockMe);
    lua_setfield(L, -2, "unlocks_dontLockMe");
    lua_pushcfunction(L, DialogLineData_set_crowdTrigger);
    lua_setfield(L, -2, "crowdTrigger");
    lua_pushcfunction(L, DialogLineData_set_factionRelationEffects);
    lua_setfield(L, -2, "factionRelationEffects");
    lua_pushcfunction(L, DialogLineData_set_playerInterruptionDialog);
    lua_setfield(L, -2, "playerInterruptionDialog");
    lua_pushcfunction(L, DialogLineData_set_isInterjection);
    lua_setfield(L, -2, "isInterjection");
    lua_pushcfunction(L, DialogLineData_set_speaker);
    lua_setfield(L, -2, "speaker");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
