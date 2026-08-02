#include "pch.h"
#include "kenshi/Dialogue.h"
#include "DialogLineDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/DialogChoiceListBinding.h"
#include "Bindings/DialogueBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
#include "Bindings/WorldEventStateQueryListBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/FitnessSelectorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Bindings/CampaignTriggerDataBinding.h"
#include "Bindings/GameDataValuePairBinding.h"
#include "Bindings/DialogConditionBinding.h"
#include "Bindings/DialogActionBinding.h"

namespace KenshiLua
{

typedef OgreUnorderedMapBinding<GameData*, int> FactionRelationEffectsMapBinding;

static DialogLineData* getInstance(lua_State* L, int idx)
{
    return checkObject<DialogLineData>(L, idx, DialogLineDataBinding::getMetatableName());
}

// --- Getters for DialogLineData ---
static int DialogLineData_get_targetFlagsNeeded(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, instance->targetFlagsNeeded);
    return 1;
}

static int DialogLineData_get_targetFlagsNotWanted(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, instance->targetFlagsNotWanted);
    return 1;
}

static int DialogLineData_get_personalityNeeded(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, instance->personalityNeeded);
    return 1;
}

static int DialogLineData_get_personalityNotWanted(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, instance->personalityNotWanted);
    return 1;
}

static int DialogLineData_get_campaignTriggers(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<FitnessSelector<CampaignTriggerData*>>(L, &instance->campaignTriggers, FitnessSelectorBinding<CampaignTriggerData*>::metaName);
}

static int DialogLineData_get_isTargetRace(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<lektor<GameData*>>(L, &instance->isTargetRace, LektorPtrBinding<GameData*>::metaName);
}

static int DialogLineData_get_isTargetSubRace_specificallyTheTarget(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<lektor<GameData*>>(L, &instance->isTargetSubRace_specificallyTheTarget, LektorPtrBinding<GameData*>::metaName);
}

static int DialogLineData_get_givesItem(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<lektor<GameDataValuePair>>(L, &instance->givesItem, LektorValueReadOnlyBinding<GameDataValuePair>::metaName);
}

static int DialogLineData_get_inTownOf(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_newtable(L);
    int i = 1;
    for (std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy>>::const_iterator it = instance->inTownOf.begin(); it != instance->inTownOf.end(); ++it)
    {
        pushObject<Faction>(L, *it, FactionBinding::getMetatableName());
        lua_rawseti(L, -2, i++);
    }
    return 1;
}

static int DialogLineData_get_isTargetFaction(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_newtable(L);
    int i = 1;
    for (std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy>>::const_iterator it = instance->isTargetFaction.begin(); it != instance->isTargetFaction.end(); ++it)
    {
        pushObject<Faction>(L, *it, FactionBinding::getMetatableName());
        lua_rawseti(L, -2, i++);
    }
    return 1;
}

static int DialogLineData_get_isMyFaction(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_newtable(L);
    int i = 1;
    for (std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy>>::const_iterator it = instance->isMyFaction.begin(); it != instance->isMyFaction.end(); ++it)
    {
        pushObject<Faction>(L, *it, FactionBinding::getMetatableName());
        lua_rawseti(L, -2, i++);
    }
    return 1;
}

static int DialogLineData_get_isCharacter(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<lektor<GameData*>>(L, &instance->isCharacter, LektorPtrBinding<GameData*>::metaName);
}

static int DialogLineData_get_isTargetCarryingCharacter(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<lektor<GameData*>>(L, &instance->isTargetCarryingCharacter, LektorPtrBinding<GameData*>::metaName);
}

static int DialogLineData_get_hasPackage(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<lektor<GameData*>>(L, &instance->_hasPackage, LektorPtrBinding<GameData*>::metaName);
}

static int DialogLineData_get_isMyRace(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<lektor<GameData*>>(L, &instance->isMyRace, LektorPtrBinding<GameData*>::metaName);
}

static int DialogLineData_get_isMySubRace(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<lektor<GameData*>>(L, &instance->isMySubRace, LektorPtrBinding<GameData*>::metaName);
}

static int DialogLineData_get_hasItemType(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, (lua_Integer)instance->hasItemType);
    return 1;
}

static int DialogLineData_get_hasItem(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<lektor<GameData*>>(L, &instance->hasItem, LektorPtrBinding<GameData*>::metaName);
}

static int DialogLineData_get_worldState(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<WorldEventStateQueryList>(L, instance->worldState, WorldEventStateQueryListBinding::getMetatableName());
}

static int DialogLineData_get_data(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<GameData>(L, instance->data, GameDataBinding::getMetatableName());
}

static int DialogLineData_get_onceOnly(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushboolean(L, instance->onceOnly ? 1 : 0);
    return 1;
}

static int DialogLineData_get_isMonologue(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushboolean(L, instance->isMonologue ? 1 : 0);
    return 1;
}

static int DialogLineData_get_forCertainType(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, (lua_Integer)instance->forCertainType);
    return 1;
}

static int DialogLineData_get_children(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<DialogChoiceList>(L, instance->children, DialogChoiceListBinding::getMetatableName());
}

static int DialogLineData_get_conditions(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<lektor<DialogLineData::DialogCondition*>>(L, &instance->conditions, LektorPtrBinding<DialogLineData::DialogCondition*>::metaName);
}

static int DialogLineData_get_actions(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<lektor<DialogLineData::DialogAction*>>(L, &instance->actions, LektorPtrBinding<DialogLineData::DialogAction*>::metaName);
}

static int DialogLineData_get_lineCount(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, instance->lineCount);
    return 1;
}

static int DialogLineData_get_texts(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    if (!instance->texts) { lua_pushnil(L); return 1; }
    lua_newtable(L);
    int count = instance->lineCount > 0 ? instance->lineCount : 1;
    for (int i = 0; i < count; ++i)
    {
        lua_pushstring(L, instance->texts[i].c_str());
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int DialogLineData_get_parent(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<DialogLineData>(L, instance->parent, DialogLineDataBinding::getMetatableName());
}

static int DialogLineData_get_chancePermanent(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushnumber(L, instance->chancePermanent);
    return 1;
}

static int DialogLineData_get_chanceTemporary(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushnumber(L, instance->chanceTemporary);
    return 1;
}

static int DialogLineData_get_unique(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushboolean(L, instance->unique ? 1 : 0);
    return 1;
}

static int DialogLineData_get_uniqueOwner(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return HandBinding::push(L, instance->uniqueOwner);
}

static int DialogLineData_get_dialogRepeatMinTimeInHours(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushnumber(L, instance->dialogRepeatMinTimeInHours);
    return 1;
}

static int DialogLineData_get_lastTimeSaid(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<TimeOfDay>(L, &instance->lastTimeSaid, TimeOfDayBinding::getMetatableName());
}

static int DialogLineData_get_score(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, instance->score);
    return 1;
}

static int DialogLineData_get_oneAtATime(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushboolean(L, instance->oneAtATime ? 1 : 0);
    return 1;
}

static int DialogLineData_get_isLocked(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushboolean(L, instance->isLocked ? 1 : 0);
    return 1;
}

static int DialogLineData_get_locks(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<lektor<DialogLineData*>>(L, &instance->locks, LektorPtrBinding<DialogLineData*>::metaName);
}

static int DialogLineData_get_unlocks_lockMe(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<lektor<DialogLineData*>>(L, &instance->unlocks_lockMe, LektorPtrBinding<DialogLineData*>::metaName);
}

static int DialogLineData_get_unlocks_dontLockMe(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<lektor<DialogLineData*>>(L, &instance->unlocks_dontLockMe, LektorPtrBinding<DialogLineData*>::metaName);
}

static int DialogLineData_get_crowdTrigger(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<DialogLineData>(L, instance->crowdTrigger, DialogLineDataBinding::getMetatableName());
}

static int DialogLineData_get_factionRelationEffects(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<ogre_unordered_map<GameData*, int>::type>(L, &instance->factionRelationEffects, FactionRelationEffectsMapBinding::metaName);
}

static int DialogLineData_get_playerInterruptionDialog(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    return pushObject<DialogLineData>(L, instance->playerInterruptionDialog, DialogLineDataBinding::getMetatableName());
}

static int DialogLineData_get_isInterjection(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushboolean(L, instance->isInterjection ? 1 : 0);
    return 1;
}

static int DialogLineData_get_speaker(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lua_pushinteger(L, (lua_Integer)instance->speaker);
    return 1;
}

// --- Setters for DialogLineData ---
static int DialogLineData_set_targetFlagsNeeded(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->targetFlagsNeeded = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_targetFlagsNotWanted(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->targetFlagsNotWanted = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_personalityNeeded(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->personalityNeeded = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_personalityNotWanted(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->personalityNotWanted = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_campaignTriggers(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    FitnessSelector<CampaignTriggerData*>* val = FitnessSelectorBinding<CampaignTriggerData*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected FitnessSelector_CampaignTriggerData");
    instance->campaignTriggers = *val;
    return 0;
}

static int DialogLineData_set_isTargetRace(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lektor<GameData*>* val = checkObject<lektor<GameData*>>(L, 2, LektorPtrBinding<GameData*>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<GameData*>");
    instance->isTargetRace = *val;
    return 0;
}

static int DialogLineData_set_isTargetSubRace_specificallyTheTarget(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lektor<GameData*>* val = checkObject<lektor<GameData*>>(L, 2, LektorPtrBinding<GameData*>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<GameData*>");
    instance->isTargetSubRace_specificallyTheTarget = *val;
    return 0;
}

static int DialogLineData_set_givesItem(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lektor<GameDataValuePair>* val = checkObject<lektor<GameDataValuePair>>(L, 2, LektorValueReadOnlyBinding<GameDataValuePair>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<GameDataValuePair>");
    instance->givesItem = *val;
    return 0;
}

static int DialogLineData_set_inTownOf(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->inTownOf.clear();
    if (lua_istable(L, 2)) {
        int len = (int)lua_objlen(L, 2);
        for (int i = 1; i <= len; ++i) {
            lua_rawgeti(L, 2, i);
            Faction* f = checkObject<Faction>(L, -1, FactionBinding::getMetatableName());
            if (f) instance->inTownOf.insert(f);
            lua_pop(L, 1);
        }
    }
    return 0;
}

static int DialogLineData_set_isTargetFaction(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->isTargetFaction.clear();
    if (lua_istable(L, 2)) {
        int len = (int)lua_objlen(L, 2);
        for (int i = 1; i <= len; ++i) {
            lua_rawgeti(L, 2, i);
            Faction* f = checkObject<Faction>(L, -1, FactionBinding::getMetatableName());
            if (f) instance->isTargetFaction.insert(f);
            lua_pop(L, 1);
        }
    }
    return 0;
}

static int DialogLineData_set_isMyFaction(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->isMyFaction.clear();
    if (lua_istable(L, 2)) {
        int len = (int)lua_objlen(L, 2);
        for (int i = 1; i <= len; ++i) {
            lua_rawgeti(L, 2, i);
            Faction* f = checkObject<Faction>(L, -1, FactionBinding::getMetatableName());
            if (f) instance->isMyFaction.insert(f);
            lua_pop(L, 1);
        }
    }
    return 0;
}

static int DialogLineData_set_isCharacter(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    auto* val = checkObject<lektor<GameData*>>(L, 2, LektorPtrBinding<GameData*>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<GameData*>");
    instance->isCharacter = *val;
    return 0;
}

static int DialogLineData_set_isTargetCarryingCharacter(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    auto* val = checkObject<lektor<GameData*>>(L, 2, LektorPtrBinding<GameData*>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<GameData*>");
    instance->isTargetCarryingCharacter = *val;
    return 0;
}

static int DialogLineData_set_hasPackage(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    auto* val = checkObject<lektor<GameData*>>(L, 2, LektorPtrBinding<GameData*>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<GameData*>");
    instance->_hasPackage = *val;
    return 0;
}

static int DialogLineData_set_isMyRace(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    auto* val = checkObject<lektor<GameData*>>(L, 2, LektorPtrBinding<GameData*>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<GameData*>");
    instance->isMyRace = *val;
    return 0;
}

static int DialogLineData_set_isMySubRace(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    auto* val = checkObject<lektor<GameData*>>(L, 2, LektorPtrBinding<GameData*>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<GameData*>");
    instance->isMySubRace = *val;
    return 0;
}

static int DialogLineData_set_hasItemType(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->hasItemType = (ItemFunction)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_hasItem(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lektor<GameData*>* val = checkObject<lektor<GameData*>>(L, 2, LektorPtrBinding<GameData*>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<GameData*>");
    instance->hasItem = *val;
    return 0;
}

static int DialogLineData_set_worldState(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->worldState = lua_isnoneornil(L, 2) ? nullptr : checkObject<WorldEventStateQueryList>(L, 2, WorldEventStateQueryListBinding::getMetatableName());
    return 0;
}

static int DialogLineData_set_data(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int DialogLineData_set_onceOnly(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->onceOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogLineData_set_isMonologue(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->isMonologue = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogLineData_set_forCertainType(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->forCertainType = (CharacterTypeEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_children(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->children = lua_isnoneornil(L, 2) ? nullptr : checkObject<DialogChoiceList>(L, 2, DialogChoiceListBinding::getMetatableName());
    return 0;
}

static int DialogLineData_set_conditions(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lektor<DialogLineData::DialogCondition*>* val = checkObject<lektor<DialogLineData::DialogCondition*>>(L, 2, LektorPtrBinding<DialogLineData::DialogCondition*>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<DialogCondition*>");
    instance->conditions = *val;
    return 0;
}

static int DialogLineData_set_actions(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lektor<DialogLineData::DialogAction*>* val = checkObject<lektor<DialogLineData::DialogAction*>>(L, 2, LektorPtrBinding<DialogLineData::DialogAction*>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<DialogAction*>");
    instance->actions = *val;
    return 0;
}

static int DialogLineData_set_lineCount(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->lineCount = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_texts(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    if (lua_istable(L, 2))
    {
        int len = (int)lua_objlen(L, 2);
        delete[] instance->texts;
        instance->lineCount = len;
        instance->texts = new std::string[len];
        for (int i = 1; i <= len; ++i)
        {
            lua_rawgeti(L, 2, i);
            instance->texts[i - 1] = luaL_optstring(L, -1, "");
            lua_pop(L, 1);
        }
    }
    else if (lua_isstring(L, 2))
    {
        delete[] instance->texts;
        instance->lineCount = 1;
        instance->texts = new std::string[1];
        instance->texts[0] = luaL_checkstring(L, 2);
    }
    return 0;
}

static int DialogLineData_set_parent(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->parent = lua_isnoneornil(L, 2) ? nullptr : checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    return 0;
}

static int DialogLineData_set_chancePermanent(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->chancePermanent = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DialogLineData_set_chanceTemporary(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->chanceTemporary = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DialogLineData_set_unique(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->unique = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogLineData_set_uniqueOwner(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->uniqueOwner = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int DialogLineData_set_dialogRepeatMinTimeInHours(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->dialogRepeatMinTimeInHours = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DialogLineData_set_lastTimeSaid(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->lastTimeSaid = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int DialogLineData_set_score(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->score = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogLineData_set_oneAtATime(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->oneAtATime = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogLineData_set_isLocked(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->isLocked = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogLineData_set_locks(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lektor<DialogLineData*>* val = checkObject<lektor<DialogLineData*>>(L, 2, LektorPtrBinding<DialogLineData*>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<DialogLineData*>");
    instance->locks = *val;
    return 0;
}

static int DialogLineData_set_unlocks_lockMe(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lektor<DialogLineData*>* val = checkObject<lektor<DialogLineData*>>(L, 2, LektorPtrBinding<DialogLineData*>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<DialogLineData*>");
    instance->unlocks_lockMe = *val;
    return 0;
}

static int DialogLineData_set_unlocks_dontLockMe(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    lektor<DialogLineData*>* val = checkObject<lektor<DialogLineData*>>(L, 2, LektorPtrBinding<DialogLineData*>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<DialogLineData*>");
    instance->unlocks_dontLockMe = *val;
    return 0;
}

static int DialogLineData_set_crowdTrigger(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->crowdTrigger = lua_isnoneornil(L, 2) ? nullptr : checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    return 0;
}

static int DialogLineData_set_factionRelationEffects(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    ogre_unordered_map<GameData*, int>::type* val = FactionRelationEffectsMapBinding::get(L, 2);
    if (!val) return luaL_error(L, "Expected FactionRelationEffects map object");
    instance->factionRelationEffects = *val;
    return 0;
}

static int DialogLineData_set_playerInterruptionDialog(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->playerInterruptionDialog = lua_isnoneornil(L, 2) ? nullptr : checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    return 0;
}

static int DialogLineData_set_isInterjection(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->isInterjection = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogLineData_set_speaker(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");
    instance->speaker = (TalkerEnum)luaL_checkinteger(L, 2);
    return 0;
}

int DialogLineDataBinding::getParent(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    DialogLineData* result = instance->getParent();
    return pushObject<DialogLineData>(L, result, DialogLineDataBinding::getMetatableName());
}

int DialogLineDataBinding::isForSpecificCharacter(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    GameData* who = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->isForSpecificCharacter(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::hasSpecificCharacterRequirement(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    bool result = instance->hasSpecificCharacterRequirement();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::_CONSTRUCTOR(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    DialogLineData* result = instance->_CONSTRUCTOR(dat);
    return pushObject<DialogLineData>(L, result, DialogLineDataBinding::getMetatableName());
}

int DialogLineDataBinding::_DESTRUCTOR(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int DialogLineDataBinding::setupChildren(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    instance->setupChildren();
    return 0;
}

int DialogLineDataBinding::checkRepeatLimits(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    bool result = instance->checkRepeatLimits();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::checkTags(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Character* target = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool result = instance->checkTags(me, target);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::getName(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    std::string result = instance->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int DialogLineDataBinding::saidItBefore(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    bool result = instance->saidItBefore();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::willTalkToEnemies(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    bool result = instance->willTalkToEnemies();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::isEmptyNode(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    bool result = instance->isEmptyNode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::_NV_isEmptyNode(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    bool result = instance->_NV_isEmptyNode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::isAnnouncement(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    bool result = instance->isAnnouncement();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::stampLastTimeSaid(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    instance->stampLastTimeSaid();
    return 0;
}

int DialogLineDataBinding::getScore(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    int result = instance->getScore(target);
    lua_pushinteger(L, result);
    return 1;
}

int DialogLineDataBinding::getScorePlusChildrenIfEmpty(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    int result = instance->getScorePlusChildrenIfEmpty(target);
    lua_pushinteger(L, result);
    return 1;
}

int DialogLineDataBinding::hasChildren(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    bool result = instance->hasChildren();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::checkConditions(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    Dialogue* dialog = checkObject<Dialogue>(L, 2, DialogueBinding::getMetatableName());
    Character* target = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool isWordswap = lua_toboolean(L, 4) != 0;
    bool result = instance->checkConditions(dialog, target, isWordswap);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogLineDataBinding::chooseAChild(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    Dialogue* who = checkObject<Dialogue>(L, 2, DialogueBinding::getMetatableName());
    Character* target = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool isForWordswaps = lua_toboolean(L, 4) != 0;
    DialogLineData* result = instance->chooseAChild(who, target, isForWordswaps);
    return pushObject<DialogLineData>(L, result, DialogLineDataBinding::getMetatableName());
}

int DialogLineDataBinding::getStringID(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    std::string result = instance->getStringID();
    lua_pushstring(L, result.c_str());
    return 1;
}

int DialogLineDataBinding::getGameData(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    GameData* result = instance->getGameData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int DialogLineDataBinding::getChildByStringID(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    const std::string sid = luaL_checkstring(L, 2);
    DialogLineData* result = instance->getChildByStringID(sid);
    return pushObject<DialogLineData>(L, result, DialogLineDataBinding::getMetatableName());
}

int DialogLineDataBinding::setParent(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    DialogLineData* p = checkObject<DialogLineData>(L, 2, DialogLineDataBinding::getMetatableName());
    instance->setParent(p);
    return 0;
}

int DialogLineDataBinding::getMoneyCostForLine(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    int result = instance->getMoneyCostForLine();
    lua_pushinteger(L, result);
    return 1;
}

int DialogLineDataBinding::getText(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    bool stampTime = lua_toboolean(L, 2) != 0;
    std::string text = instance->getText(stampTime);
    lua_pushstring(L, text.c_str());
    return 1;
}

int DialogLineDataBinding::getPlayerReplies(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    auto* out = checkObject<lektor<DialogLineData*>>(L, 2, LektorPtrBinding<DialogLineData*>::metaName);
    if (!out) return luaL_error(L, "Argument 2 to getPlayerReplies must be lektor<DialogLineData*>");
    Dialogue* who = checkObject<Dialogue>(L, 3, DialogueBinding::getMetatableName());
    Character* target = checkObject<Character>(L, 4, CharacterBinding::getMetatableName());

    instance->getPlayerReplies(*out, who, target);
    return 0;
}

int DialogLineDataBinding::getActions(lua_State* L)
{
    DialogLineData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogLineData is nil");

    const lektor<DialogLineData::DialogAction*>* result = instance->getActions();
    return pushObject<lektor<DialogLineData::DialogAction*>>(L, const_cast<lektor<DialogLineData::DialogAction*>*>(result), LektorPtrBinding<DialogLineData::DialogAction*>::metaName);
}

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
        { "getParent", DialogLineDataBinding::getParent },
        { "isForSpecificCharacter", DialogLineDataBinding::isForSpecificCharacter },
        { "hasSpecificCharacterRequirement", DialogLineDataBinding::hasSpecificCharacterRequirement },
        { "_CONSTRUCTOR", DialogLineDataBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", DialogLineDataBinding::_DESTRUCTOR },
        { "setupChildren", DialogLineDataBinding::setupChildren },
        { "checkRepeatLimits", DialogLineDataBinding::checkRepeatLimits },
        { "checkTags", DialogLineDataBinding::checkTags },
        { "getName", DialogLineDataBinding::getName },
        { "saidItBefore", DialogLineDataBinding::saidItBefore },
        { "willTalkToEnemies", DialogLineDataBinding::willTalkToEnemies },
        { "isEmptyNode", DialogLineDataBinding::isEmptyNode },
        { "_NV_isEmptyNode", DialogLineDataBinding::_NV_isEmptyNode },
        { "isAnnouncement", DialogLineDataBinding::isAnnouncement },
        { "stampLastTimeSaid", DialogLineDataBinding::stampLastTimeSaid },
        { "getScore", DialogLineDataBinding::getScore },
        { "getScorePlusChildrenIfEmpty", DialogLineDataBinding::getScorePlusChildrenIfEmpty },
        { "hasChildren", DialogLineDataBinding::hasChildren },
        { "checkConditions", DialogLineDataBinding::checkConditions },
        { "chooseAChild", DialogLineDataBinding::chooseAChild },
        { "getStringID", DialogLineDataBinding::getStringID },
        { "getGameData", DialogLineDataBinding::getGameData },
        { "getChildByStringID", DialogLineDataBinding::getChildByStringID },
        { "setParent", DialogLineDataBinding::setParent },
        { "getMoneyCostForLine", DialogLineDataBinding::getMoneyCostForLine },
        { "getText", DialogLineDataBinding::getText },
        { "getPlayerReplies", DialogLineDataBinding::getPlayerReplies },
        { "getActions", DialogLineDataBinding::getActions },
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
    registerGetter(L, "targetFlagsNeeded", DialogLineData_get_targetFlagsNeeded);
    registerGetter(L, "targetFlagsNotWanted", DialogLineData_get_targetFlagsNotWanted);
    registerGetter(L, "personalityNeeded", DialogLineData_get_personalityNeeded);
    registerGetter(L, "personalityNotWanted", DialogLineData_get_personalityNotWanted);
    registerGetter(L, "campaignTriggers", DialogLineData_get_campaignTriggers);
    registerGetter(L, "isTargetRace", DialogLineData_get_isTargetRace);
    registerGetter(L, "isTargetSubRace_specificallyTheTarget", DialogLineData_get_isTargetSubRace_specificallyTheTarget);
    registerGetter(L, "givesItem", DialogLineData_get_givesItem);
    registerGetter(L, "inTownOf", DialogLineData_get_inTownOf);
    registerGetter(L, "isTargetFaction", DialogLineData_get_isTargetFaction);
    registerGetter(L, "isMyFaction", DialogLineData_get_isMyFaction);
    registerGetter(L, "isCharacter", DialogLineData_get_isCharacter);
    registerGetter(L, "isTargetCarryingCharacter", DialogLineData_get_isTargetCarryingCharacter);
    registerGetter(L, "hasPackage", DialogLineData_get_hasPackage);
    registerGetter(L, "isMyRace", DialogLineData_get_isMyRace);
    registerGetter(L, "isMySubRace", DialogLineData_get_isMySubRace);
    registerGetter(L, "hasItemType", DialogLineData_get_hasItemType);
    registerGetter(L, "hasItem", DialogLineData_get_hasItem);
    registerGetter(L, "worldState", DialogLineData_get_worldState);
    registerGetter(L, "data", DialogLineData_get_data);
    registerGetter(L, "onceOnly", DialogLineData_get_onceOnly);
    registerGetter(L, "isMonologue", DialogLineData_get_isMonologue);
    registerGetter(L, "forCertainType", DialogLineData_get_forCertainType);
    registerGetter(L, "children", DialogLineData_get_children);
    registerGetter(L, "conditions", DialogLineData_get_conditions);
    registerGetter(L, "actions", DialogLineData_get_actions);
    registerGetter(L, "lineCount", DialogLineData_get_lineCount);
    registerGetter(L, "texts", DialogLineData_get_texts);
    registerGetter(L, "parent", DialogLineData_get_parent);
    registerGetter(L, "chancePermanent", DialogLineData_get_chancePermanent);
    registerGetter(L, "chanceTemporary", DialogLineData_get_chanceTemporary);
    registerGetter(L, "unique", DialogLineData_get_unique);
    registerGetter(L, "uniqueOwner", DialogLineData_get_uniqueOwner);
    registerGetter(L, "dialogRepeatMinTimeInHours", DialogLineData_get_dialogRepeatMinTimeInHours);
    registerGetter(L, "lastTimeSaid", DialogLineData_get_lastTimeSaid);
    registerGetter(L, "score", DialogLineData_get_score);
    registerGetter(L, "oneAtATime", DialogLineData_get_oneAtATime);
    registerGetter(L, "isLocked", DialogLineData_get_isLocked);
    registerGetter(L, "locks", DialogLineData_get_locks);
    registerGetter(L, "unlocks_lockMe", DialogLineData_get_unlocks_lockMe);
    registerGetter(L, "unlocks_dontLockMe", DialogLineData_get_unlocks_dontLockMe);
    registerGetter(L, "crowdTrigger", DialogLineData_get_crowdTrigger);
    registerGetter(L, "factionRelationEffects", DialogLineData_get_factionRelationEffects);
    registerGetter(L, "playerInterruptionDialog", DialogLineData_get_playerInterruptionDialog);
    registerGetter(L, "isInterjection", DialogLineData_get_isInterjection);
    registerGetter(L, "speaker", DialogLineData_get_speaker);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "targetFlagsNeeded", DialogLineData_set_targetFlagsNeeded);
    registerSetter(L, "targetFlagsNotWanted", DialogLineData_set_targetFlagsNotWanted);
    registerSetter(L, "personalityNeeded", DialogLineData_set_personalityNeeded);
    registerSetter(L, "personalityNotWanted", DialogLineData_set_personalityNotWanted);
    registerSetter(L, "campaignTriggers", DialogLineData_set_campaignTriggers); //
    registerSetter(L, "isTargetRace", DialogLineData_set_isTargetRace); //
    registerSetter(L, "isTargetSubRace_specificallyTheTarget", DialogLineData_set_isTargetSubRace_specificallyTheTarget);
    registerSetter(L, "givesItem", DialogLineData_set_givesItem); //
    registerSetter(L, "inTownOf", DialogLineData_set_inTownOf); //
    registerSetter(L, "isTargetFaction", DialogLineData_set_isTargetFaction);
    registerSetter(L, "isMyFaction", DialogLineData_set_isMyFaction);
    registerSetter(L, "isCharacter", DialogLineData_set_isCharacter); //
    registerSetter(L, "isTargetCarryingCharacter", DialogLineData_set_isTargetCarryingCharacter); //
    registerSetter(L, "hasPackage", DialogLineData_set_hasPackage); //
    registerSetter(L, "isMyRace", DialogLineData_set_isMyRace); //
    registerSetter(L, "isMySubRace", DialogLineData_set_isMySubRace); //
    registerSetter(L, "hasItemType", DialogLineData_set_hasItemType);
    registerSetter(L, "hasItem", DialogLineData_set_hasItem); //
    registerSetter(L, "worldState", DialogLineData_set_worldState);
    registerSetter(L, "data", DialogLineData_set_data);
    registerSetter(L, "onceOnly", DialogLineData_set_onceOnly);
    registerSetter(L, "isMonologue", DialogLineData_set_isMonologue);
    registerSetter(L, "forCertainType", DialogLineData_set_forCertainType); //
    registerSetter(L, "children", DialogLineData_set_children);
    registerSetter(L, "conditions", DialogLineData_set_conditions); //
    registerSetter(L, "actions", DialogLineData_set_actions); //
    registerSetter(L, "lineCount", DialogLineData_set_lineCount);
    registerSetter(L, "texts", DialogLineData_set_texts); //
    registerSetter(L, "parent", DialogLineData_set_parent);
    registerSetter(L, "chancePermanent", DialogLineData_set_chancePermanent);
    registerSetter(L, "chanceTemporary", DialogLineData_set_chanceTemporary);
    registerSetter(L, "unique", DialogLineData_set_unique);
    registerSetter(L, "uniqueOwner", DialogLineData_set_uniqueOwner);
    registerSetter(L, "dialogRepeatMinTimeInHours", DialogLineData_set_dialogRepeatMinTimeInHours);
    registerSetter(L, "lastTimeSaid", DialogLineData_set_lastTimeSaid);
    registerSetter(L, "score", DialogLineData_set_score);
    registerSetter(L, "oneAtATime", DialogLineData_set_oneAtATime);
    registerSetter(L, "isLocked", DialogLineData_set_isLocked);
    registerSetter(L, "locks", DialogLineData_set_locks); //
    registerSetter(L, "unlocks_lockMe", DialogLineData_set_unlocks_lockMe); //
    registerSetter(L, "unlocks_dontLockMe", DialogLineData_set_unlocks_dontLockMe); //
    registerSetter(L, "crowdTrigger", DialogLineData_set_crowdTrigger); //
    registerSetter(L, "factionRelationEffects", DialogLineData_set_factionRelationEffects);
    registerSetter(L, "playerInterruptionDialog", DialogLineData_set_playerInterruptionDialog);
    registerSetter(L, "isInterjection", DialogLineData_set_isInterjection);
    registerSetter(L, "speaker", DialogLineData_set_speaker);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    FitnessSelectorBinding<CampaignTriggerData*>::registerBinding(L, "FitnessSelector<CampaignTriggerData*>", CampaignTriggerDataBinding::getMetatableName(), nullptr, nullptr);
    //LektorValueReadOnlyBinding<GameDataValuePair>::registerBinding(L, "lektor<GameDataValuePair>", GameDataValuePairBinding::getMetatableName());
    //LektorPtrBinding<DialogLineData::DialogCondition*>::registerBinding(L, "lektor<DialogCondition*>", DialogConditionBinding::getMetatableName());
    //LektorPtrBinding<DialogLineData::DialogAction*>::registerBinding(L, "lektor<DialogAction*>", DialogActionBinding::getMetatableName());
    FactionRelationEffectsMapBinding::registerBinding(L, "KenshiLua.FactionRelationEffectsMap", GameDataBinding::getMetatableName(), nullptr);


    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua