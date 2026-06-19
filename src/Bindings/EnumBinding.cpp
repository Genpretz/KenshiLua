#include "pch.h"
#include "Bindings/EnumBinding.h"
#include "Bindings/BuildingEnumBinding.h"
#include "Bindings/MedicalSystemBinding.h"

#include "kenshi/Character.h"
#include "kenshi/Dialogue.h"
#include "kenshi/Enums.h"
#include "kenshi/MedicalSystem.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{    

    // setEnum helper defined in EnumBinding.h

    // ----------------------------------------------
    // Character.h
	// ----------------------------------------------

    void CharacterEnumBinding::registerProneState(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "PS_NORMAL", ProneState::PS_NORMAL);
        setEnum(L, "NORMAL", ProneState::PS_NORMAL);
        setEnum(L, "PS_STAYING_LOW", ProneState::PS_STAYING_LOW);
        setEnum(L, "STAYING_LOW", ProneState::PS_STAYING_LOW);
        setEnum(L, "PS_CRIPPLED", ProneState::PS_CRIPPLED);
        setEnum(L, "CRIPPLED", ProneState::PS_CRIPPLED);
        setEnum(L, "PS_PLAYING_DEAD", ProneState::PS_PLAYING_DEAD);
        setEnum(L, "PLAYING_DEAD", ProneState::PS_PLAYING_DEAD);
        setEnum(L, "PS_KO", ProneState::PS_KO);
        setEnum(L, "KO", ProneState::PS_KO);

        lua_setglobal(L, "ProneState");
    }

    void CharacterEnumBinding::registerWaterState(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "NO_WATER", WaterState::NO_WATER);
        setEnum(L, "VERY_SHALLOW_WATER", WaterState::VERY_SHALLOW_WATER);
        setEnum(L, "THIGH_DEEP_WATER", WaterState::THIGH_DEEP_WATER);
        setEnum(L, "DEEP_WATER", WaterState::DEEP_WATER);

        lua_setglobal(L, "WaterState");
    }

    void CharacterEnumBinding::registerRagdollPart(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "NONE", RagdollPart::Enum::NONE);
        setEnum(L, "WHOLE", RagdollPart::Enum::WHOLE);
        setEnum(L, "RIGHT_ARM", RagdollPart::Enum::RIGHT_ARM);
        setEnum(L, "LEFT_ARM", RagdollPart::Enum::LEFT_ARM);
        setEnum(L, "HEAD", RagdollPart::Enum::HEAD);
        setEnum(L, "RIGHT_LEG", RagdollPart::Enum::RIGHT_LEG);
        setEnum(L, "LEFT_LEG", RagdollPart::Enum::LEFT_LEG);
        setEnum(L, "CARRY_MODE", RagdollPart::Enum::CARRY_MODE);
        setEnum(L, "ARMS", RagdollPart::Enum::ARMS);
        setEnum(L, "LEGS", RagdollPart::Enum::LEGS);
        setEnum(L, "ALL", RagdollPart::Enum::ALL);

        lua_setglobal(L, "RagdollPart");
    }

    void CharacterEnumBinding::registerCharacterPerceptionTagsShortTerm(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "ST_NONE", ST_NONE);
        setEnum(L, "NONE", ST_NONE);
        setEnum(L, "ST_INTRUDER", ST_INTRUDER);
        setEnum(L, "INTRUDER", ST_INTRUDER);
        setEnum(L, "ST_AGGRESSOR", ST_AGGRESSOR);
        setEnum(L, "AGGRESSOR", ST_AGGRESSOR);
        setEnum(L, "ST_TEMPORARY_ALLY", ST_TEMPORARY_ALLY);
        setEnum(L, "TEMPORARY_ALLY", ST_TEMPORARY_ALLY);
        setEnum(L, "ST_TEMPORARY_ENEMY", ST_TEMPORARY_ENEMY);
        setEnum(L, "TEMPORARY_ENEMY", ST_TEMPORARY_ENEMY);
        setEnum(L, "ST_PRISONER", ST_PRISONER);
        setEnum(L, "PRISONER", ST_PRISONER);
        setEnum(L, "ST_HAS_BEEN_LOOTED", ST_HAS_BEEN_LOOTED);
        setEnum(L, "HAS_BEEN_LOOTED", ST_HAS_BEEN_LOOTED);
        setEnum(L, "ST_CRIMINAL", ST_CRIMINAL);
        setEnum(L, "CRIMINAL", ST_CRIMINAL);

        lua_setglobal(L, "CharacterPerceptionTags_ShortTerm");
    }

    void CharacterEnumBinding::registerCharacterPerceptionTagsLongTerm(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "LT_NONE", LT_NONE);
        setEnum(L, "NONE", LT_NONE);
        setEnum(L, "LT_MY_INTRUDER", LT_MY_INTRUDER);
        setEnum(L, "MY_INTRUDER", LT_MY_INTRUDER);
        setEnum(L, "LT_MY_LIFESAVER", LT_MY_LIFESAVER);
        setEnum(L, "MY_LIFESAVER", LT_MY_LIFESAVER);
        setEnum(L, "LT_FREED_ME", LT_FREED_ME);
        setEnum(L, "FREED_ME", LT_FREED_ME);
        setEnum(L, "LT_STOLE_FROM_ME", LT_STOLE_FROM_ME);
        setEnum(L, "STOLE_FROM_ME", LT_STOLE_FROM_ME);
        setEnum(L, "LT_MY_CAPTOR", LT_MY_CAPTOR);
        setEnum(L, "MY_CAPTOR", LT_MY_CAPTOR);
        setEnum(L, "LT_FRIENDLY_AQUAINTANCE", LT_FRIENDLY_AQUAINTANCE);
        setEnum(L, "FRIENDLY_AQUAINTANCE", LT_FRIENDLY_AQUAINTANCE);
        setEnum(L, "LT_DEFEATED_MY_SQUAD_ONCE", LT_DEFEATED_MY_SQUAD_ONCE);
        setEnum(L, "DEFEATED_MY_SQUAD_ONCE", LT_DEFEATED_MY_SQUAD_ONCE);
        setEnum(L, "LT_SQUAD_LOST_TO_ME_ONCE", LT_SQUAD_LOST_TO_ME_ONCE);
        setEnum(L, "SQUAD_LOST_TO_ME_ONCE", LT_SQUAD_LOST_TO_ME_ONCE);
        setEnum(L, "LT_KILLED_MY_FRIEND", LT_KILLED_MY_FRIEND);
        setEnum(L, "KILLED_MY_FRIEND", LT_KILLED_MY_FRIEND);
        setEnum(L, "LT_I_SCREWED_THIS_GUY", LT_I_SCREWED_THIS_GUY);
        setEnum(L, "I_SCREWED_THIS_GUY", LT_I_SCREWED_THIS_GUY);
        setEnum(L, "LT_MAX", LT_MAX);
        setEnum(L, "MAX", LT_MAX);

        lua_setglobal(L, "CharacterPerceptionTags_LongTerm");
    }

    void CharacterEnumBinding::registerSoundRange(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "SOUNDRANGE_SHORT", SOUNDRANGE_SHORT);
        setEnum(L, "SHORT", SOUNDRANGE_SHORT);
        setEnum(L, "SOUNDRANGE_LONG", SOUNDRANGE_LONG);
        setEnum(L, "LONG", SOUNDRANGE_LONG);
        setEnum(L, "SOUNDRANGE_ALWAYS", SOUNDRANGE_ALWAYS);
        setEnum(L, "ALWAYS", SOUNDRANGE_ALWAYS);

        lua_setglobal(L, "SoundRange");
    }

    void CharacterEnumBinding::registerSquadMemberType(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "SQUAD_1", SQUAD_1);
        setEnum(L, "1", SQUAD_1);
        setEnum(L, "SQUAD_2", SQUAD_2);
        setEnum(L, "2", SQUAD_2);
        setEnum(L, "SQUAD_LEADER", SQUAD_LEADER);
        setEnum(L, "LEADER", SQUAD_LEADER);
        setEnum(L, "SQUAD_SIGNALS_PLAN", SQUAD_SIGNALS_PLAN);
        setEnum(L, "SIGNALS_PLAN", SQUAD_SIGNALS_PLAN);
        setEnum(L, "SQUAD_SLAVE", SQUAD_SLAVE);
        setEnum(L, "SLAVE", SQUAD_SLAVE);

        lua_setglobal(L, "SquadMemberType");
    }

    void CharacterEnumBinding::registerCharacterMessage(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "ATTACKING_MELEE", ATTACKING_MELEE);

        lua_setglobal(L, "CharacterMessage");
    }

    void CharacterEnumBinding::registerBinding(lua_State* L)
    {
        registerProneState(L);
        registerWaterState(L);
        registerRagdollPart(L);
        registerCharacterPerceptionTagsShortTerm(L);
        registerCharacterPerceptionTagsLongTerm(L);
        registerSoundRange(L);
        registerSquadMemberType(L);
        registerCharacterMessage(L);
	}

    // --------------------------------------------------
    // Dialogue.h
    // --------------------------------------------------

    void DialogueEnumBinding::registerTalker(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "T_ME", T_ME);
        setEnum(L, "ME", T_ME);

        setEnum(L, "T_TARGET", T_TARGET);
        setEnum(L, "TARGET", T_TARGET);

        setEnum(L, "T_TARGET_IF_PLAYER", T_TARGET_IF_PLAYER);
        setEnum(L, "TARGET_IF_PLAYER", T_TARGET_IF_PLAYER);

        setEnum(L, "T_INTERJECTOR1", T_INTERJECTOR1);
        setEnum(L, "INTERJECTOR1", T_INTERJECTOR1);

        setEnum(L, "T_INTERJECTOR2", T_INTERJECTOR2);
        setEnum(L, "INTERJECTOR2", T_INTERJECTOR2);

        setEnum(L, "T_INTERJECTOR3", T_INTERJECTOR3);
        setEnum(L, "INTERJECTOR3", T_INTERJECTOR3);

        setEnum(L, "T_WHOLE_SQUAD", T_WHOLE_SQUAD);
        setEnum(L, "WHOLE_SQUAD", T_WHOLE_SQUAD);

        setEnum(L, "T_TARGET_WITH_RACE", T_TARGET_WITH_RACE);
        setEnum(L, "TARGET_WITH_RACE", T_TARGET_WITH_RACE);

		lua_setglobal(L, "Talker");
    }

    void DialogueEnumBinding::registerDialogueAction(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "DA_NONE", DA_NONE);
        setEnum(L, "NONE", DA_NONE);

        setEnum(L, "DA_TRADE", DA_TRADE);
        setEnum(L, "TRADE", DA_TRADE);

        setEnum(L, "DA_TALK_TO_LEADER", DA_TALK_TO_LEADER);
        setEnum(L, "TALK_TO_LEADER", DA_TALK_TO_LEADER);

        setEnum(L, "DA_JOIN_SQUAD_WITH_EDIT", DA_JOIN_SQUAD_WITH_EDIT);
        setEnum(L, "JOIN_SQUAD_WITH_EDIT", DA_JOIN_SQUAD_WITH_EDIT);

        setEnum(L, "DA_AFFECT_RELATIONS", DA_AFFECT_RELATIONS);
        setEnum(L, "AFFECT_RELATIONS", DA_AFFECT_RELATIONS);

        setEnum(L, "DA_AFFECT_REPUTATION", DA_AFFECT_REPUTATION);
        setEnum(L, "AFFECT_REPUTATION", DA_AFFECT_REPUTATION);

		setEnum(L, "DA_ATTACK_CHASE_FOREVER", DA_ATTACK_CHASE_FOREVER);
		setEnum(L, "ATTACK_CHASE_FOREVER", DA_ATTACK_CHASE_FOREVER);

        setEnum(L, "DA_GO_HOME", DA_GO_HOME);
        setEnum(L, "GO_HOME", DA_GO_HOME);

        setEnum(L, "DA_TAKE_MONEY", DA_TAKE_MONEY);
        setEnum(L, "TAKE_MONEY", DA_TAKE_MONEY);

        setEnum(L, "DA_GIVE_MONEY", DA_GIVE_MONEY);
        setEnum(L, "GIVE_MONEY", DA_GIVE_MONEY);

        setEnum(L, "DA_PAY_BOUNTY", DA_PAY_BOUNTY);
        setEnum(L, "PAY_BOUNTY", DA_PAY_BOUNTY);

        setEnum(L, "DA_CHARACTER_EDITOR", DA_CHARACTER_EDITOR);
        setEnum(L, "CHARACTER_EDITOR", DA_CHARACTER_EDITOR);

        setEnum(L, "DA_FORCE_SPEECH_TIMER", DA_FORCE_SPEECH_TIMER);
        setEnum(L, "FORCE_SPEECH_TIMER", DA_FORCE_SPEECH_TIMER);

        setEnum(L, "DA_DECLARE_WAR", DA_DECLARE_WAR);
        setEnum(L, "DECLARE_WAR", DA_DECLARE_WAR);

        setEnum(L, "DA_END_WAR", DA_END_WAR);
        setEnum(L, "END_WAR", DA_END_WAR);

        setEnum(L, "DA_CLEAR_AI", DA_CLEAR_AI);
        setEnum(L, "CLEAR_AI", DA_CLEAR_AI);

        setEnum(L, "DA_FOLLOW_WHILE_TALKING", DA_FOLLOW_WHILE_TALKING);
        setEnum(L, "FOLLOW_WHILE_TALKING", DA_FOLLOW_WHILE_TALKING);

        setEnum(L, "DA_THUG_HUNTER", DA_THUG_HUNTER);
        setEnum(L, "THUG_HUNTER", DA_THUG_HUNTER);

        setEnum(L, "DA_JOIN_SQUAD_FAST", DA_JOIN_SQUAD_FAST);
        setEnum(L, "JOIN_SQUAD_FAST", DA_JOIN_SQUAD_FAST);

		setEnum(L, "DA_REMEMBER_CHARACTER", DA_REMEMBER_CHARACTER);
		setEnum(L, "REMEMBER_CHARACTER", DA_REMEMBER_CHARACTER);

        setEnum(L, "DA_FLAG_TEMP_ALLY", DA_FLAG_TEMP_ALLY);
        setEnum(L, "FLAG_TEMP_ALLY", DA_FLAG_TEMP_ALLY);

        setEnum(L, "DA_FLAG_TEMP_ENEMY", DA_FLAG_TEMP_ENEMY);
        setEnum(L, "FLAG_TEMP_ENEMY", DA_FLAG_TEMP_ENEMY);

        setEnum(L, "DA_MATES_KILL_ME", DA_MATES_KILL_ME);
        setEnum(L, "MATES_KILL_ME", DA_MATES_KILL_ME);

        setEnum(L, "DA_MAKE_TARGET_RUN_FASTER", DA_MAKE_TARGET_RUN_FASTER);
        setEnum(L, "MAKE_TARGET_RUN_FASTER", DA_MAKE_TARGET_RUN_FASTER);

        setEnum(L, "DA_GIVE_TARGET_MY_SLAVES", DA_GIVE_TARGET_MY_SLAVES);
        setEnum(L, "GIVE_TARGET_MY_SLAVES", DA_GIVE_TARGET_MY_SLAVES);

        setEnum(L, "DA_TAG_ESCAPED_SLAVE", DA_TAG_ESCAPED_SLAVE);
        setEnum(L, "TAG_ESCAPED_SLAVE", DA_TAG_ESCAPED_SLAVE);

        setEnum(L, "DA_FREE_TARGET_SLAVE", DA_FREE_TARGET_SLAVE);
        setEnum(L, "FREE_TARGET_SLAVE", DA_FREE_TARGET_SLAVE);

        setEnum(L, "DA_MERGE_WITH_SIMILAR_SQUADS", DA_MERGE_WITH_SIMILAR_SQUADS);
        setEnum(L, "MERGE_WITH_SIMILAR_SQUADS", DA_MERGE_WITH_SIMILAR_SQUADS);

        setEnum(L, "DA_SEPARATE_TO_MY_OWN_SQUAD", DA_SEPARATE_TO_MY_OWN_SQUAD);
        setEnum(L, "SEPARATE_TO_MY_OWN_SQUAD", DA_SEPARATE_TO_MY_OWN_SQUAD);

        setEnum(L, "DA_ARREST_TARGET", DA_ARREST_TARGET);
        setEnum(L, "ARREST_TARGET", DA_ARREST_TARGET);

        setEnum(L, "DA_ARREST_TARGETS_CARRIED_PERSON", DA_ARREST_TARGETS_CARRIED_PERSON);
        setEnum(L, "ARREST_TARGETS_CARRIED_PERSON", DA_ARREST_TARGETS_CARRIED_PERSON);

		setEnum(L, "DA_ATTACK_TOWN", DA_ATTACK_TOWN);
		setEnum(L, "ATTACK_TOWN", DA_ATTACK_TOWN);

		setEnum(L, "DA_ASSIGN_BOUNTY", DA_ASSIGN_BOUNTY);
		setEnum(L, "ASSIGN_BOUNTY", DA_ASSIGN_BOUNTY);

        setEnum(L, "DA_CRIME_ALARM", DA_CRIME_ALARM);
        setEnum(L, "CRIME_ALARM", DA_CRIME_ALARM);

        setEnum(L, "DA_RUN_AWAY", DA_RUN_AWAY);
        setEnum(L, "RUN_AWAY", DA_RUN_AWAY);

        setEnum(L, "DA_INCREASE_FACTION_RANK", DA_INCREASE_FACTION_RANK);
        setEnum(L, "INCREASE_FACTION_RANK", DA_INCREASE_FACTION_RANK);

        setEnum(L, "DA_LOCK_THIS_DIALOG", DA_LOCK_THIS_DIALOG);
        setEnum(L, "LOCK_THIS_DIALOG", DA_LOCK_THIS_DIALOG);

		setEnum(L, "DA_ASSAULT_PHASE", DA_ASSAULT_PHASE);
		setEnum(L, "ASSAULT_PHASE", DA_ASSAULT_PHASE);

		setEnum(L, "DA_RETREAT_PHASE", DA_RETREAT_PHASE);
		setEnum(L, "RETREAT_PHASE", DA_RETREAT_PHASE);

		setEnum(L, "DA_VICTORY_PHASE", DA_VICTORY_PHASE);
		setEnum(L, "VICTORY_PHASE", DA_VICTORY_PHASE);

		setEnum(L, "DA_ENSLAVE_TARGETS_CARRIED_PERSON", DA_ENSLAVE_TARGETS_CARRIED_PERSON);
		setEnum(L, "ENSLAVE_TARGETS_CARRIED_PERSON", DA_ENSLAVE_TARGETS_CARRIED_PERSON);

        setEnum(L, "DA_CLEAR_BOUNTY", DA_CLEAR_BOUNTY);
        setEnum(L, "CLEAR_BOUNTY", DA_CLEAR_BOUNTY);

        setEnum(L, "DA_PLAYER_SELL_PRISONERS", DA_PLAYER_SELL_PRISONERS);
        setEnum(L, "PLAYER_SELL_PRISONERS", DA_PLAYER_SELL_PRISONERS);

		setEnum(L, "DA_PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE", DA_PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE);
		setEnum(L, "PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE", DA_PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE);

		setEnum(L, "DA_SUMMON_MY_SQUAD", DA_SUMMON_MY_SQUAD);
		setEnum(L, "SUMMON_MY_SQUAD", DA_SUMMON_MY_SQUAD);

		setEnum(L, "DA_REMOVE_SLAVE_STATUS", DA_REMOVE_SLAVE_STATUS);
		setEnum(L, "REMOVE_SLAVE_STATUS", DA_REMOVE_SLAVE_STATUS);

		setEnum(L, "DA_OPEN_NEAREST_GATE", DA_OPEN_NEAREST_GATE);
		setEnum(L, "OPEN_NEAREST_GATE", DA_OPEN_NEAREST_GATE);

		setEnum(L, "DA_ATTACK_STAY_NEAR_HOME", DA_ATTACK_STAY_NEAR_HOME);
		setEnum(L, "ATTACK_STAY_NEAR_HOME", DA_ATTACK_STAY_NEAR_HOME);

		setEnum(L, "DA_MASSIVE_ALARM", DA_MASSIVE_ALARM);
		setEnum(L, "MASSIVE_ALARM", DA_MASSIVE_ALARM);

		setEnum(L, "DA_ATTACK_IF_NO_COEXIST", DA_ATTACK_IF_NO_COEXIST);
		setEnum(L, "ATTACK_IF_NO_COEXIST", DA_ATTACK_IF_NO_COEXIST);

		setEnum(L, "DA_KNOCKOUT", DA_KNOCKOUT);
		setEnum(L, "KNOCKOUT", DA_KNOCKOUT);

        setEnum(L, "DA_END", DA_END);
        setEnum(L, "END", DA_END);

		lua_setglobal(L, "DialogueAction");
    }

    void DialogueEnumBinding::registerBinding(lua_State* L)
    {
        registerTalker(L);
        registerDialogueAction(L);
    }

	// --------------------------------------------------
    // Enums.h
	// --------------------------------------------------

    void EnumsEnumBinding::registersItemType(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "BUILDING", itemType::BUILDING);
        setEnum(L, "CHARACTER", itemType::CHARACTER);
        setEnum(L, "WEAPON", itemType::WEAPON);
        setEnum(L, "ARMOUR", itemType::ARMOUR);
        setEnum(L, "ITEM", itemType::ITEM);
        setEnum(L, "ANIMAL_ANIMATION", itemType::ANIMAL_ANIMATION);
        setEnum(L, "ATTACHMENT", itemType::ATTACHMENT);
        setEnum(L, "RACE", itemType::RACE);
        setEnum(L, "LOCATION", itemType::LOCATION);
        setEnum(L, "WAR_SAVESTATE", itemType::WAR_SAVESTATE);
        setEnum(L, "FACTION", itemType::FACTION);
        setEnum(L, "NULL_ITEM", itemType::NULL_ITEM);
        setEnum(L, "ZONE_MAP", itemType::ZONE_MAP);
        setEnum(L, "TOWN", itemType::TOWN);
        setEnum(L, "WORLDMAP_CHARACTER", itemType::WORLDMAP_CHARACTER);
        setEnum(L, "CHARACTER_APPEARANCE_OLD", itemType::CHARACTER_APPEARANCE_OLD);
        setEnum(L, "LOCATIONAL_DAMAGE", itemType::LOCATIONAL_DAMAGE);
        setEnum(L, "COMBAT_TECHNIQUE", itemType::COMBAT_TECHNIQUE);
        setEnum(L, "DIALOGUE", itemType::DIALOGUE);
        setEnum(L, "DIALOGUE_LINE", itemType::DIALOGUE_LINE);
        setEnum(L, "TECHTREE", itemType::TECHTREE);
        setEnum(L, "RESEARCH", itemType::RESEARCH);
        setEnum(L, "AI_TASK", itemType::AI_TASK);
        setEnum(L, "AI_STATE", itemType::AI_STATE);
        setEnum(L, "ANIMATION", itemType::ANIMATION);
        setEnum(L, "STATS", itemType::STATS);
        setEnum(L, "PERSONALITY", itemType::PERSONALITY);
        setEnum(L, "CONSTANTS", itemType::CONSTANTS);
        setEnum(L, "BIOMES", itemType::BIOMES);
        setEnum(L, "BUILDING_PART", itemType::BUILDING_PART);
        setEnum(L, "INSTANCE_COLLECTION", itemType::INSTANCE_COLLECTION);
        setEnum(L, "DIALOG_ACTION", itemType::DIALOG_ACTION);
        setEnum(L, "TEMPORARY_INFO", itemType::TEMPORARY_INFO);
        setEnum(L, "MOD_FILENAME", itemType::MOD_FILENAME);
        setEnum(L, "PLATOON", itemType::PLATOON);
        setEnum(L, "GAMESTATE_BUILDING", itemType::GAMESTATE_BUILDING);
        setEnum(L, "GAMESTATE_CHARACTER", itemType::GAMESTATE_CHARACTER);
        setEnum(L, "GAMESTATE_FACTION", itemType::GAMESTATE_FACTION);
        setEnum(L, "GAMESTATE_TOWN_INSTANCE_LIST", itemType::GAMESTATE_TOWN_INSTANCE_LIST);
        setEnum(L, "STATE", itemType::STATE);
        setEnum(L, "SAVED_STATE", itemType::SAVED_STATE);
        setEnum(L, "INVENTORY_STATE", itemType::INVENTORY_STATE);
        setEnum(L, "INVENTORY_ITEM_STATE", itemType::INVENTORY_ITEM_STATE);
        setEnum(L, "REPEATABLE_BUILDING_PART_SLOT", itemType::REPEATABLE_BUILDING_PART_SLOT);
        setEnum(L, "MATERIAL_SPEC", itemType::MATERIAL_SPEC);
        setEnum(L, "MATERIAL_SPECS_COLLECTION", itemType::MATERIAL_SPECS_COLLECTION);
        setEnum(L, "CONTAINER", itemType::CONTAINER);
        setEnum(L, "MATERIAL_SPECS_CLOTHING", itemType::MATERIAL_SPECS_CLOTHING);
        setEnum(L, "GAMESTATE_BUILDING_INTERIOR", itemType::GAMESTATE_BUILDING_INTERIOR);
        setEnum(L, "VENDOR_LIST", itemType::VENDOR_LIST);
        setEnum(L, "MATERIAL_SPECS_WEAPON", itemType::MATERIAL_SPECS_WEAPON);
        setEnum(L, "WEAPON_MANUFACTURER", itemType::WEAPON_MANUFACTURER);
        setEnum(L, "SQUAD_TEMPLATE", itemType::SQUAD_TEMPLATE);
        setEnum(L, "ROAD", itemType::ROAD);
        setEnum(L, "LOCATION_NODE", itemType::LOCATION_NODE);
        setEnum(L, "COLOR_DATA", itemType::COLOR_DATA);
        setEnum(L, "CAMERA", itemType::CAMERA);
        setEnum(L, "MEDICAL_STATE", itemType::MEDICAL_STATE);
        setEnum(L, "MEDICAL_PART_STATE", itemType::MEDICAL_PART_STATE);
        setEnum(L, "FOLIAGE_LAYER", itemType::FOLIAGE_LAYER);
        setEnum(L, "FOLIAGE_MESH", itemType::FOLIAGE_MESH);
        setEnum(L, "GRASS", itemType::GRASS);
        setEnum(L, "BUILDING_FUNCTIONALITY", itemType::BUILDING_FUNCTIONALITY);
        setEnum(L, "DAY_SCHEDULE", itemType::DAY_SCHEDULE);
        setEnum(L, "NEW_GAME_STARTOFF", itemType::NEW_GAME_STARTOFF);
        setEnum(L, "GAMESTATE_CRAFTING", itemType::GAMESTATE_CRAFTING);
        setEnum(L, "CHARACTER_APPEARANCE", itemType::CHARACTER_APPEARANCE);
        setEnum(L, "GAMESTATE_AI", itemType::GAMESTATE_AI);
        setEnum(L, "WILDLIFE_BIRDS", itemType::WILDLIFE_BIRDS);
        setEnum(L, "MAP_FEATURES", itemType::MAP_FEATURES);
        setEnum(L, "DIPLOMATIC_ASSAULTS", itemType::DIPLOMATIC_ASSAULTS);
        setEnum(L, "SINGLE_DIPLOMATIC_ASSAULT", itemType::SINGLE_DIPLOMATIC_ASSAULT);
        setEnum(L, "AI_PACKAGE", itemType::AI_PACKAGE);
        setEnum(L, "DIALOGUE_PACKAGE", itemType::DIALOGUE_PACKAGE);
        setEnum(L, "GUN_DATA", itemType::GUN_DATA);
        setEnum(L, "HUMAN_CHARACTER", itemType::HUMAN_CHARACTER);
        setEnum(L, "ANIMAL_CHARACTER", itemType::ANIMAL_CHARACTER);
        setEnum(L, "UNIQUE_SQUAD_TEMPLATE", itemType::UNIQUE_SQUAD_TEMPLATE);
        setEnum(L, "FACTION_TEMPLATE", itemType::FACTION_TEMPLATE);
        setEnum(L, "AI_SCHEDULE", itemType::AI_SCHEDULE);
        setEnum(L, "WEATHER", itemType::WEATHER);
        setEnum(L, "SEASON", itemType::SEASON);
        setEnum(L, "EFFECT", itemType::EFFECT);
        setEnum(L, "ITEM_PLACEMENT_GROUP", itemType::ITEM_PLACEMENT_GROUP);
        setEnum(L, "WORD_SWAPS", itemType::WORD_SWAPS);
        setEnum(L, "NEST", itemType::NEST);
        setEnum(L, "NEST_ITEM", itemType::NEST_ITEM);
        setEnum(L, "CHARACTER_PHYSICS_ATTACHMENT", itemType::CHARACTER_PHYSICS_ATTACHMENT);
        setEnum(L, "LIGHT", itemType::LIGHT);
        setEnum(L, "HEAD", itemType::HEAD);
        setEnum(L, "BLUEPRINT", itemType::BLUEPRINT);
        setEnum(L, "SHOP_TRADER_CLASS", itemType::SHOP_TRADER_CLASS);
        setEnum(L, "FOLIAGE_BUILDING", itemType::FOLIAGE_BUILDING);
        setEnum(L, "FACTION_CAMPAIGN", itemType::FACTION_CAMPAIGN);
        setEnum(L, "GAMESTATE_TOWN", itemType::GAMESTATE_TOWN);
        setEnum(L, "BIOME_GROUP", itemType::BIOME_GROUP);
        setEnum(L, "EFFECT_FOG_VOLUME", itemType::EFFECT_FOG_VOLUME);
        setEnum(L, "FARM_DATA", itemType::FARM_DATA);
        setEnum(L, "FARM_PART", itemType::FARM_PART);
        setEnum(L, "ENVIRONMENT_RESOURCES", itemType::ENVIRONMENT_RESOURCES);
        setEnum(L, "RACE_GROUP", itemType::RACE_GROUP);
        setEnum(L, "ARTIFACTS", itemType::ARTIFACTS);
        setEnum(L, "MAP_ITEM", itemType::MAP_ITEM);
        setEnum(L, "BUILDINGS_SWAP", itemType::BUILDINGS_SWAP);
        setEnum(L, "ITEMS_CULTURE", itemType::ITEMS_CULTURE);
        setEnum(L, "ANIMATION_EVENT", itemType::ANIMATION_EVENT);
        setEnum(L, "TUTORIAL", itemType::TUTORIAL);
        setEnum(L, "CROSSBOW", itemType::CROSSBOW);
        setEnum(L, "TERRAIN_DECALS", itemType::TERRAIN_DECALS);
        setEnum(L, "AMBIENT_SOUND", itemType::AMBIENT_SOUND);
        setEnum(L, "WORLD_EVENT_STATE", itemType::WORLD_EVENT_STATE);
        setEnum(L, "LIMB_REPLACEMENT", itemType::LIMB_REPLACEMENT);
        setEnum(L, "ANIMATION_FILE", itemType::ANIMATION_FILE);
        setEnum(L, "___XXX___", itemType::____XXX___);
        setEnum(L, "OBJECT_TYPE_MAX", itemType::OBJECT_TYPE_MAX);

        lua_setglobal(L, "itemType");
    }

    void EnumsEnumBinding::registerBuildingFunction(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, BuildingFunction::BF_ANY);
        lua_setfield(L, -2, "ANY");
        lua_pushinteger(L, BuildingFunction::BF_ANY);
        lua_setfield(L, -2, "BF_ANY");

        lua_pushinteger(L, BuildingFunction::BF_MINE);
        lua_setfield(L, -2, "MINE");
        lua_pushinteger(L, BuildingFunction::BF_MINE);
        lua_setfield(L, -2, "BF_MINE");

        lua_pushinteger(L, BuildingFunction::BF_RESOURCE_STORAGE);
        lua_setfield(L, -2, "RESOURCE_STORAGE");
        lua_pushinteger(L, BuildingFunction::BF_RESOURCE_STORAGE);
        lua_setfield(L, -2, "BF_RESOURCE_STORAGE");

        lua_pushinteger(L, BuildingFunction::BF_RESEARCH);
        lua_setfield(L, -2, "RESEARCH");
        lua_pushinteger(L, BuildingFunction::BF_RESEARCH);
        lua_setfield(L, -2, "BF_RESEARCH");

        lua_pushinteger(L, BuildingFunction::BF_REFINERY);
        lua_setfield(L, -2, "REFINERY");
        lua_pushinteger(L, BuildingFunction::BF_REFINERY);
        lua_setfield(L, -2, "BF_REFINERY");

        lua_pushinteger(L, BuildingFunction::BF_GENERATOR);
        lua_setfield(L, -2, "GENERATOR");
		lua_pushinteger(L, BuildingFunction::BF_GENERATOR);
		lua_setfield(L, -2, "BF_GENERATOR");

        lua_pushinteger(L, BuildingFunction::BF_BED);
        lua_setfield(L, -2, "BED");
		lua_pushinteger(L, BuildingFunction::BF_BED);
		lua_setfield(L, -2, "BF_BED");

        lua_pushinteger(L, BuildingFunction::BF_TRAINING);
        lua_setfield(L, -2, "TRAINING");
		lua_pushinteger(L, BuildingFunction::BF_TRAINING);
		lua_setfield(L, -2, "BF_TRAINING");

        lua_pushinteger(L, BuildingFunction::BF_CAGE);
        lua_setfield(L, -2, "CAGE");
		lua_pushinteger(L, BuildingFunction::BF_CAGE);
		lua_setfield(L, -2, "BF_CAGE");

        lua_pushinteger(L, BuildingFunction::BF_SHOP);
        lua_setfield(L, -2, "SHOP");
		lua_pushinteger(L, BuildingFunction::BF_SHOP);
		lua_setfield(L, -2, "BF_SHOP");

        lua_pushinteger(L, BuildingFunction::BF_CRAFTING);
        lua_setfield(L, -2, "CRAFTING");
		lua_pushinteger(L, BuildingFunction::BF_CRAFTING);
		lua_setfield(L, -2, "BF_CRAFTING");

        lua_pushinteger(L, BuildingFunction::BF_CORPSE_DISPOSAL);
        lua_setfield(L, -2, "CORPSE_DISPOSAL");
		lua_pushinteger(L, BuildingFunction::BF_CORPSE_DISPOSAL);
		lua_setfield(L, -2, "BF_CORPSE_DISPOSAL");

        lua_pushinteger(L, BuildingFunction::BF_TURRET);
        lua_setfield(L, -2, "TURRET");
		lua_pushinteger(L, BuildingFunction::BF_TURRET);
		lua_setfield(L, -2, "BF_TURRET");

        lua_pushinteger(L, BuildingFunction::BF_GENERAL_STORAGE);
        lua_setfield(L, -2, "GENERAL_STORAGE");
		lua_pushinteger(L, BuildingFunction::BF_GENERAL_STORAGE);
		lua_setfield(L, -2, "BF_GENERAL_STORAGE");

        lua_pushinteger(L, BuildingFunction::BF_ITEM_FURNACE);
        lua_setfield(L, -2, "ITEM_FURNACE");
		lua_pushinteger(L, BuildingFunction::BF_ITEM_FURNACE);
		lua_setfield(L, -2, "BF_ITEM_FURNACE");
        
        lua_pushinteger(L, BuildingFunction::BF_LIGHT);
        lua_setfield(L, -2, "LIGHT");
		lua_pushinteger(L, BuildingFunction::BF_LIGHT);
		lua_setfield(L, -2, "BF_LIGHT");

        lua_pushinteger(L, BuildingFunction::BF_TABLE);
        lua_setfield(L, -2, "TABLE");
		lua_pushinteger(L, BuildingFunction::BF_TABLE);
		lua_setfield(L, -2, "BF_TABLE");

        lua_pushinteger(L, BuildingFunction::BF_CHAIR);
        lua_setfield(L, -2, "CHAIR");
		lua_pushinteger(L, BuildingFunction::BF_CHAIR);
		lua_setfield(L, -2, "BF_CHAIR");

        lua_pushinteger(L, BuildingFunction::BF_FLUFF);
        lua_setfield(L, -2, "FLUFF");
		lua_pushinteger(L, BuildingFunction::BF_FLUFF);
		lua_setfield(L, -2, "BF_FLUFF");

        lua_pushinteger(L, BuildingFunction::BF_SHELL_WITH_INTERIOR);
        lua_setfield(L, -2, "SHELL_WITH_INTERIOR");
		lua_pushinteger(L, BuildingFunction::BF_SHELL_WITH_INTERIOR);
		lua_setfield(L, -2, "BF_SHELL_WITH_INTERIOR");

        lua_pushinteger(L, BuildingFunction::BF_WALL);
        lua_setfield(L, -2, "WALL");
		lua_pushinteger(L, BuildingFunction::BF_WALL);
		lua_setfield(L, -2, "BF_WALL");

        lua_pushinteger(L, BuildingFunction::BF_GATE);
        lua_setfield(L, -2, "GATE");
		lua_pushinteger(L, BuildingFunction::BF_GATE);
		lua_setfield(L, -2, "BF_GATE");

        lua_pushinteger(L, BuildingFunction::BF_DOOR);
        lua_setfield(L, -2, "DOOR");
		lua_pushinteger(L, BuildingFunction::BF_DOOR);
		lua_setfield(L, -2, "BF_DOOR");

        lua_pushinteger(L, BuildingFunction::BF_BATTERY);
        lua_setfield(L, -2, "BATTERY");
		lua_pushinteger(L, BuildingFunction::BF_BATTERY);
		lua_setfield(L, -2, "BF_BATTERY");

        lua_pushinteger(L, BuildingFunction::BF_THRONE);
        lua_setfield(L, -2, "THRONE");
		lua_pushinteger(L, BuildingFunction::BF_THRONE);
		lua_setfield(L, -2, "BF_THRONE");

        lua_pushinteger(L, BuildingFunction::BF_SKELETON_BED);
        lua_setfield(L, -2, "SKELETON_BED");
		lua_pushinteger(L, BuildingFunction::BF_SKELETON_BED);
		lua_setfield(L, -2, "BF_SKELETON_BED");

        lua_pushinteger(L, BuildingFunction::BF_RAIN_COLLECTOR);
        lua_setfield(L, -2, "RAIN_COLLECTOR");
		lua_pushinteger(L, BuildingFunction::BF_RAIN_COLLECTOR);
		lua_setfield(L, -2, "BF_RAIN_COLLECTOR");

        lua_pushinteger(L, BuildingFunction::BF_MINE_NATURAL);
        lua_setfield(L, -2, "MINE_NATURAL");
		lua_pushinteger(L, BuildingFunction::BF_MINE_NATURAL);
		lua_setfield(L, -2, "BF_MINE_NATURAL");

        lua_pushinteger(L, BuildingFunction::BF_STEERING);
        lua_setfield(L, -2, "STEERING");
		lua_pushinteger(L, BuildingFunction::BF_STEERING);
		lua_setfield(L, -2, "BF_STEERING");

        lua_pushinteger(L, BuildingFunction::BF_ENGINE);
        lua_setfield(L, -2, "ENGINE");
		lua_pushinteger(L, BuildingFunction::BF_ENGINE);
		lua_setfield(L, -2, "BF_ENGINE");

        lua_pushinteger(L, BuildingFunction::BF_LIQUID_TANK);
        lua_setfield(L, -2, "LIQUID_TANK");
		lua_pushinteger(L, BuildingFunction::BF_LIQUID_TANK);
		lua_setfield(L, -2, "BF_LIQUID_TANK");

        lua_setglobal(L, "BuildingFunction");
    }

    void EnumsEnumBinding::registerCutDirection(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, CutDirection::CUT_DEFAULT);
        lua_setfield(L, -2, "DEFAULT");
		lua_pushinteger(L, CutDirection::CUT_DEFAULT);
		lua_setfield(L, -2, "CUT_DEFAULT");

        lua_pushinteger(L, CutDirection::CUT_DOWNWARD);
        lua_setfield(L, -2, "DOWNWARD");
		lua_pushinteger(L, CutDirection::CUT_DOWNWARD);
		lua_setfield(L, -2, "CUT_DOWNWARD");

        lua_pushinteger(L, CutDirection::CUT_LEFT);
        lua_setfield(L, -2, "LEFT");
		lua_pushinteger(L, CutDirection::CUT_LEFT);
		lua_setfield(L, -2, "CUT_LEFT");

        lua_pushinteger(L, CutDirection::CUT_RIGHT);
        lua_setfield(L, -2, "RIGHT");
		lua_pushinteger(L, CutDirection::CUT_RIGHT);
		lua_setfield(L, -2, "CUT_RIGHT");

        lua_pushinteger(L, CutDirection::CUT_THRUST);
        lua_setfield(L, -2, "THRUST");
		lua_pushinteger(L, CutDirection::CUT_THRUST);
		lua_setfield(L, -2, "CUT_THRUST");

        lua_pushinteger(L, CutDirection::CUT_UPWARDS);
        lua_setfield(L, -2, "UPWARDS");
		lua_pushinteger(L, CutDirection::CUT_UPWARDS);
		lua_setfield(L, -2, "CUT_UPWARDS");

        lua_pushinteger(L, CutDirection::CUT_PIERCED);
        lua_setfield(L, -2, "PIERCED");
		lua_pushinteger(L, CutDirection::CUT_PIERCED);
		lua_setfield(L, -2, "CUT_PIERCED");

        lua_pushinteger(L, CutDirection::CUT_REAR_DOWNWARD);
        lua_setfield(L, -2, "REAR_DOWNWARD");
		lua_pushinteger(L, CutDirection::CUT_REAR_DOWNWARD);
		lua_setfield(L, -2, "CUT_REAR_DOWNWARD");

        lua_pushinteger(L, CutDirection::CUT_REAR_LEFT);
        lua_setfield(L, -2, "REAR_LEFT");
		lua_pushinteger(L, CutDirection::CUT_REAR_LEFT);
		lua_setfield(L, -2, "CUT_REAR_LEFT");

        lua_pushinteger(L, CutDirection::CUT_REAR_RIGHT);
        lua_setfield(L, -2, "REAR_RIGHT");
		lua_pushinteger(L, CutDirection::CUT_REAR_RIGHT);
		lua_setfield(L, -2, "CUT_REAR_RIGHT");

        lua_setglobal(L, "CutDirection");
    }

    void EnumsEnumBinding::registerCutOrigination(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, CutOrigination::FRONT);
        lua_setfield(L, -2, "FRONT");

        lua_pushinteger(L, CutOrigination::REAR);
        lua_setfield(L, -2, "REAR");

        lua_pushinteger(L, CutOrigination::LEFTSIDE);
        lua_setfield(L, -2, "LEFTSIDE");

        lua_pushinteger(L, CutOrigination::RIGHTSIDE);
        lua_setfield(L, -2, "RIGHTSIDE");

        lua_setglobal(L, "CutOrigination");
    }

    void EnumsEnumBinding::registerHitMaterialType(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, HitMaterialType::HIT_MISSED);
        lua_setfield(L, -2, "MISSED");
		lua_pushinteger(L, HitMaterialType::HIT_MISSED);
		lua_setfield(L, -2, "HIT_MISSED");

        lua_pushinteger(L, HitMaterialType::HIT_METAL);
        lua_setfield(L, -2, "METAL");
		lua_pushinteger(L, HitMaterialType::HIT_METAL);
		lua_setfield(L, -2, "HIT_METAL");

        lua_pushinteger(L, HitMaterialType::HIT_FLESH);
        lua_setfield(L, -2, "FLESH");
		lua_pushinteger(L, HitMaterialType::HIT_FLESH);
		lua_setfield(L, -2, "HIT_FLESH");

        lua_pushinteger(L, HitMaterialType::HIT_SAND);
        lua_setfield(L, -2, "SAND");
		lua_pushinteger(L, HitMaterialType::HIT_SAND);
		lua_setfield(L, -2, "HIT_SAND");

        lua_pushinteger(L, HitMaterialType::HIT_WOOD);
        lua_setfield(L, -2, "WOOD");
		lua_pushinteger(L, HitMaterialType::HIT_WOOD);
		lua_setfield(L, -2, "HIT_WOOD");

        lua_pushinteger(L, HitMaterialType::HIT_SWORD);
        lua_setfield(L, -2, "SWORD");
		lua_pushinteger(L, HitMaterialType::HIT_SWORD);
		lua_setfield(L, -2, "HIT_SWORD");

        lua_pushinteger(L, HitMaterialType::HIT_CHAIN);
        lua_setfield(L, -2, "CHAIN");
		lua_pushinteger(L, HitMaterialType::HIT_CHAIN);
		lua_setfield(L, -2, "HIT_CHAIN");

        lua_setglobal(L, "HitMaterialType");
    }

    void EnumsEnumBinding::registerWeatherAffecting(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, WeatherAffecting::WA_NONE);
        lua_setfield(L, -2, "NONE");
		lua_pushinteger(L, WeatherAffecting::WA_NONE);
		lua_setfield(L, -2, "WA_NONE");

        lua_pushinteger(L, WeatherAffecting::WA_DUSTSTORM);
        lua_setfield(L, -2, "DUSTSTORM");
		lua_pushinteger(L, WeatherAffecting::WA_DUSTSTORM);
		lua_setfield(L, -2, "WA_DUSTSTORM");

        lua_pushinteger(L, WeatherAffecting::WA_ACID);
        lua_setfield(L, -2, "ACID");
		lua_pushinteger(L, WeatherAffecting::WA_ACID);
		lua_setfield(L, -2, "WA_ACID");

        lua_pushinteger(L, WeatherAffecting::WA_BURNING);
        lua_setfield(L, -2, "BURNING");
		lua_pushinteger(L, WeatherAffecting::WA_BURNING);
		lua_setfield(L, -2, "WA_BURNING");

        lua_pushinteger(L, WeatherAffecting::WA_GAS);
        lua_setfield(L, -2, "GAS");
		lua_pushinteger(L, WeatherAffecting::WA_GAS);
		lua_setfield(L, -2, "WA_GAS");

        lua_pushinteger(L, WeatherAffecting::WA_RAIN);
        lua_setfield(L, -2, "RAIN");
		lua_pushinteger(L, WeatherAffecting::WA_RAIN);
		lua_setfield(L, -2, "WA_RAIN");

        lua_setglobal(L, "WeatherAffecting");
    }

    void EnumsEnumBinding::registerAttachSlot(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, AttachSlot::ATTACH_WEAPON);
        lua_setfield(L, -2, "ATTACH_WEAPON");
		lua_pushinteger(L, AttachSlot::ATTACH_WEAPON);
		lua_setfield(L, -2, "WEAPON");

        lua_pushinteger(L, AttachSlot::ATTACH_BACK);
        lua_setfield(L, -2, "ATTACH_BACK");
		lua_pushinteger(L, AttachSlot::ATTACH_BACK);
		lua_setfield(L, -2, "BACK");

        lua_pushinteger(L, AttachSlot::ATTACH_HAIR);
        lua_setfield(L, -2, "ATTACH_HAIR");
		lua_pushinteger(L, AttachSlot::ATTACH_HAIR);
		lua_setfield(L, -2, "HAIR");

        lua_pushinteger(L, AttachSlot::ATTACH_HAT);
        lua_setfield(L, -2, "ATTACH_HAT");
		lua_pushinteger(L, AttachSlot::ATTACH_HAT);
		lua_setfield(L, -2, "HAT");

        lua_pushinteger(L, AttachSlot::ATTACH_EYES);
        lua_setfield(L, -2, "ATTACH_EYES");
		lua_pushinteger(L, AttachSlot::ATTACH_EYES);
		lua_setfield(L, -2, "EYES");

        lua_pushinteger(L, AttachSlot::ATTACH_BODY);
        lua_setfield(L, -2, "ATTACH_BODY");
		lua_pushinteger(L, AttachSlot::ATTACH_BODY);
		lua_setfield(L, -2, "BODY");

        lua_pushinteger(L, AttachSlot::ATTACH_LEGS);
        lua_setfield(L, -2, "ATTACH_LEGS");
		lua_pushinteger(L, AttachSlot::ATTACH_LEGS);
		lua_setfield(L, -2, "LEGS");

        lua_pushinteger(L, AttachSlot::ATTACH_NONE);
        lua_setfield(L, -2, "ATTACH_NONE");
		lua_pushinteger(L, AttachSlot::ATTACH_NONE);
		lua_setfield(L, -2, "NONE");

        lua_pushinteger(L, AttachSlot::ATTACH_SHIRT);
        lua_setfield(L, -2, "ATTACH_SHIRT");
		lua_pushinteger(L, AttachSlot::ATTACH_SHIRT);
		lua_setfield(L, -2, "SHIRT");

        lua_pushinteger(L, AttachSlot::ATTACH_BOOTS);
        lua_setfield(L, -2, "ATTACH_BOOTS");
        lua_pushinteger(L, AttachSlot::ATTACH_BOOTS);
		lua_setfield(L, -2, "BOOTS");

        lua_pushinteger(L, AttachSlot::ATTACH_GLOVES);
        lua_setfield(L, -2, "ATTACH_GLOVES");
		lua_pushinteger(L, AttachSlot::ATTACH_GLOVES);
		lua_setfield(L, -2, "GLOVES");

        lua_pushinteger(L, AttachSlot::ATTACH_NECK);
        lua_setfield(L, -2, "ATTACH_NECK");
		lua_pushinteger(L, AttachSlot::ATTACH_NECK);
		lua_setfield(L, -2, "NECK");

        lua_pushinteger(L, AttachSlot::ATTACH_BACKPACK);
        lua_setfield(L, -2, "ATTACH_BACKPACK");
		lua_pushinteger(L, AttachSlot::ATTACH_BACKPACK);
		lua_setfield(L, -2, "BACKPACK");

        lua_pushinteger(L, AttachSlot::ATTACH_BEARD);
        lua_setfield(L, -2, "ATTACH_BEARD");
		lua_pushinteger(L, AttachSlot::ATTACH_BEARD);
		lua_setfield(L, -2, "BEARD");

        lua_pushinteger(L, AttachSlot::ATTACH_BELT);
        lua_setfield(L, -2, "ATTACH_BELT");
		lua_pushinteger(L, AttachSlot::ATTACH_BELT);
		lua_setfield(L, -2, "BELT");

        lua_pushinteger(L, AttachSlot::ATTACH_LEFT_ARM);
        lua_setfield(L, -2, "ATTACH_LEFT_ARM");
		lua_pushinteger(L, AttachSlot::ATTACH_LEFT_ARM);
		lua_setfield(L, -2, "LEFT_ARM");

        lua_pushinteger(L, AttachSlot::ATTACH_RIGHT_ARM);
        lua_setfield(L, -2, "ATTACH_RIGHT_ARM");
		lua_pushinteger(L, AttachSlot::ATTACH_RIGHT_ARM);
		lua_setfield(L, -2, "RIGHT_ARM");

        lua_pushinteger(L, AttachSlot::ATTACH_LEFT_LEG);
        lua_setfield(L, -2, "ATTACH_LEFT_LEG");
		lua_pushinteger(L, AttachSlot::ATTACH_LEFT_LEG);
		lua_setfield(L, -2, "LEFT_LEG");

        lua_pushinteger(L, AttachSlot::ATTACH_RIGHT_LEG);
        lua_setfield(L, -2, "ATTACH_RIGHT_LEG");
		lua_pushinteger(L, AttachSlot::ATTACH_RIGHT_LEG);
		lua_setfield(L, -2, "RIGHT_LEG");

        lua_setglobal(L, "AttachSlot");
    }

    void EnumsEnumBinding::registerItemFunction(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, ItemFunction::ITEM_NO_FUNCTION);
        lua_setfield(L, -2, "ITEM_NO_FUNCTION");
        lua_pushinteger(L, ItemFunction::ITEM_NO_FUNCTION);
        lua_setfield(L, -2, "NO_FUNCTION");

        lua_pushinteger(L, ItemFunction::ITEM_FIRSTAID);
        lua_setfield(L, -2, "ITEM_FIRSTAID");
        lua_pushinteger(L, ItemFunction::ITEM_FIRSTAID);
        lua_setfield(L, -2, "FIRSTAID");

        lua_pushinteger(L, ItemFunction::ITEM_MEDRIGGING);
        lua_setfield(L, -2, "ITEM_MEDRIGGING");
        lua_pushinteger(L, ItemFunction::ITEM_MEDRIGGING);
        lua_setfield(L, -2, "MEDRIGGING");

        lua_pushinteger(L, ItemFunction::ITEM_FOOD);
        lua_setfield(L, -2, "ITEM_FOOD");
        lua_pushinteger(L, ItemFunction::ITEM_FOOD);
        lua_setfield(L, -2, "FOOD");

        lua_pushinteger(L, ItemFunction::ITEM_CONTAINER);
        lua_setfield(L, -2, "ITEM_CONTAINER");
lua_pushinteger(L, ItemFunction::ITEM_CONTAINER);
        lua_setfield(L, -2, "CONTAINER");

        lua_pushinteger(L, ItemFunction::ITEM_WEAPON);
        lua_setfield(L, -2, "ITEM_WEAPON");
        lua_pushinteger(L, ItemFunction::ITEM_WEAPON);
        lua_setfield(L, -2, "WEAPON");

        lua_pushinteger(L, ItemFunction::ITEM_CLOTHING);
        lua_setfield(L, -2, "ITEM_CLOTHING");
        lua_pushinteger(L, ItemFunction::ITEM_CLOTHING);
        lua_setfield(L, -2, "CLOTHING");

        lua_pushinteger(L, ItemFunction::ITEM____);
        lua_setfield(L, -2, "ITEM____");
        lua_pushinteger(L, ItemFunction::ITEM____);
        lua_setfield(L, -2, "___");

        lua_pushinteger(L, ItemFunction::ITEM_NARCOTIC);
        lua_setfield(L, -2, "ITEM_NARCOTIC");
        lua_pushinteger(L, ItemFunction::ITEM_NARCOTIC);
        lua_setfield(L, -2, "NARCOTIC");

        lua_pushinteger(L, ItemFunction::ITEM_TOOL);
        lua_setfield(L, -2, "ITEM_TOOL");
        lua_pushinteger(L, ItemFunction::ITEM_TOOL);
        lua_setfield(L, -2, "TOOL");

        lua_pushinteger(L, ItemFunction::ITEM_ANYTHING);
        lua_setfield(L, -2, "ITEM_ANYTHING");
        lua_pushinteger(L, ItemFunction::ITEM_ANYTHING);
        lua_setfield(L, -2, "ANYTHING");

        lua_pushinteger(L, ItemFunction::ITEM_BLUEPRINT);
        lua_setfield(L, -2, "ITEM_BLUEPRINT");
        lua_pushinteger(L, ItemFunction::ITEM_BLUEPRINT);
        lua_setfield(L, -2, "BLUEPRINT");

        lua_pushinteger(L, ItemFunction::ITEM_ROBOTREPAIR);
        lua_setfield(L, -2, "ITEM_ROBOTREPAIR");
        lua_pushinteger(L, ItemFunction::ITEM_ROBOTREPAIR);
        lua_setfield(L, -2, "ROBOTREPAIR");

        lua_pushinteger(L, ItemFunction::ITEM_BOOK);
        lua_setfield(L, -2, "ITEM_BOOK");
        lua_pushinteger(L, ItemFunction::ITEM_BOOK);
        lua_setfield(L, -2, "BOOK");

        lua_pushinteger(L, ItemFunction::ITEM_MONEY);
        lua_setfield(L, -2, "ITEM_MONEY");
        lua_pushinteger(L, ItemFunction::ITEM_MONEY);
        lua_setfield(L, -2, "MONEY");

        lua_pushinteger(L, ItemFunction::ITEM_FOOD_RESTRICTED);
        lua_setfield(L, -2, "ITEM_FOOD_RESTRICTED");
        lua_pushinteger(L, ItemFunction::ITEM_FOOD_RESTRICTED);
        lua_setfield(L, -2, "FOOD_RESTRICTED");

        lua_pushinteger(L, ItemFunction::ITEM_AMMO);
        lua_setfield(L, -2, "ITEM_AMMO");
        lua_pushinteger(L, ItemFunction::ITEM_AMMO);
        lua_setfield(L, -2, "AMMO");

        lua_pushinteger(L, ItemFunction::ITEM_SEVERED_LIMB);
        lua_setfield(L, -2, "ITEM_SEVERED_LIMB");
        lua_pushinteger(L, ItemFunction::ITEM_SEVERED_LIMB);
        lua_setfield(L, -2, "SEVERED_LIMB");

        lua_setglobal(L, "ItemFunction");
    }

    void EnumsEnumBinding::registerArmourType(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, ArmourType::CLOTH);
        lua_setfield(L, -2, "CLOTH");

        lua_pushinteger(L, ArmourType::LEATHER);
        lua_setfield(L, -2, "LEATHER");

        lua_pushinteger(L, ArmourType::CHAIN);
        lua_setfield(L, -2, "CHAIN");

        lua_pushinteger(L, ArmourType::METAL_PLATE);
        lua_setfield(L, -2, "METAL_PLATE");

        lua_setglobal(L, "ArmourType");
    }

    void EnumsEnumBinding::registerCharacterTypeEnum(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, CharacterTypeEnum::OT_NONE);
        lua_setfield(L, -2, "OT_NONE");
        lua_pushinteger(L, CharacterTypeEnum::OT_NONE);
        lua_setfield(L, -2, "NONE");

        lua_pushinteger(L, CharacterTypeEnum::OT_LAW_ENFORCEMENT);
        lua_setfield(L, -2, "OT_LAW_ENFORCEMENT");
        lua_pushinteger(L, CharacterTypeEnum::OT_LAW_ENFORCEMENT);
        lua_setfield(L, -2, "LAW_ENFORCEMENT");

        lua_pushinteger(L, CharacterTypeEnum::OT_MILITARY);
        lua_setfield(L, -2, "OT_MILITARY");
        lua_pushinteger(L, CharacterTypeEnum::OT_MILITARY);
        lua_setfield(L, -2, "MILITARY");

        lua_pushinteger(L, CharacterTypeEnum::OT_TRADER);
        lua_setfield(L, -2, "OT_TRADER");
        lua_pushinteger(L, CharacterTypeEnum::OT_TRADER);
        lua_setfield(L, -2, "TRADER");

        lua_pushinteger(L, CharacterTypeEnum::OT_CIVILIAN);
        lua_setfield(L, -2, "OT_CIVILIAN");
        lua_pushinteger(L, CharacterTypeEnum::OT_CIVILIAN);
        lua_setfield(L, -2, "CIVILIAN");

        lua_pushinteger(L, CharacterTypeEnum::OT_DIPLOMAT);
        lua_setfield(L, -2, "OT_DIPLOMAT");
        lua_pushinteger(L, CharacterTypeEnum::OT_DIPLOMAT);
        lua_setfield(L, -2, "DIPLOMAT");

        lua_pushinteger(L, CharacterTypeEnum::OT_SLAVE);
        lua_setfield(L, -2, "OT_SLAVE");
        lua_pushinteger(L, CharacterTypeEnum::OT_SLAVE);
        lua_setfield(L, -2, "SLAVE");

        lua_pushinteger(L, CharacterTypeEnum::OT_SLAVER);
        lua_setfield(L, -2, "OT_SLAVER");
        lua_pushinteger(L, CharacterTypeEnum::OT_SLAVER);
        lua_setfield(L, -2, "SLAVER");

        lua_pushinteger(L, CharacterTypeEnum::OT_BANDIT);
        lua_setfield(L, -2, "OT_BANDIT");
        lua_pushinteger(L, CharacterTypeEnum::OT_BANDIT);
        lua_setfield(L, -2, "BANDIT");

        lua_pushinteger(L, CharacterTypeEnum::OT_ADVENTURER);
        lua_setfield(L, -2, "OT_ADVENTURER");
        lua_pushinteger(L, CharacterTypeEnum::OT_ADVENTURER);
        lua_setfield(L, -2, "ADVENTURER");

        lua_pushinteger(L, CharacterTypeEnum::OT_END);
        lua_setfield(L, -2, "OT_END");
        lua_pushinteger(L, CharacterTypeEnum::OT_END);
        lua_setfield(L, -2, "END");

        // Duplicate the table reference on top of the stack
        lua_pushvalue(L, -1); // Stack: [table, table]

        // Set the first global (pops the top copy)
        lua_setglobal(L, "CharacterTypeEnum"); // Stack: [table]

        // Set the second global (pops the remaining copy)
        lua_setglobal(L, "CharacterType"); // Stack: [empty]
    }

    void EnumsEnumBinding::registerSlaveStateEnum(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, SlaveStateEnum::NOT_SLAVE);
        lua_setfield(L, -2, "NOT_SLAVE");

        lua_pushinteger(L, SlaveStateEnum::IS_SLAVE);
        lua_setfield(L, -2, "IS_SLAVE");

        lua_pushinteger(L, SlaveStateEnum::ESCAPING_SLAVE);
        lua_setfield(L, -2, "ESCAPING_SLAVE");

        lua_pushinteger(L, SlaveStateEnum::EX_SLAVE);
        lua_setfield(L, -2, "EX_SLAVE");

        lua_setglobal(L, "SlaveStateEnum");
        lua_setglobal(L, "SlaveState");
    }

    void EnumsEnumBinding::registerTaskType(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, TaskType::NULL_TASK);
        lua_setfield(L, -2, "NULL_TASK");

        lua_pushinteger(L, TaskType::MOVE_ON_FREE_WILL);
        lua_setfield(L, -2, "MOVE_ON_FREE_WILL");

        lua_pushinteger(L, TaskType::BUILD);
        lua_setfield(L, -2, "BUILD");

        lua_pushinteger(L, TaskType::PICKUP);
        lua_setfield(L, -2, "PICKUP");

        lua_pushinteger(L, TaskType::MELEE_ATTACK);
        lua_setfield(L, -2, "MELEE_ATTACK");

        lua_pushinteger(L, TaskType::FOCUSED_MELEE_ATTACK);
        lua_setfield(L, -2, "FOCUSED_MELEE_ATTACK");

        lua_pushinteger(L, TaskType::EQUIP_WEAPON);
        lua_setfield(L, -2, "EQUIP_WEAPON");

        lua_pushinteger(L, TaskType::UNEQUIP_WEAPON);
        lua_setfield(L, -2, "UNEQUIP_WEAPON");

        lua_pushinteger(L, TaskType::FIND_WEAPON);
        lua_setfield(L, -2, "FIND_WEAPON");

        lua_pushinteger(L, TaskType::CHOOSE_ENEMY_AND_ATTACK);
        lua_setfield(L, -2, "CHOOSE_ENEMY_AND_ATTACK");

        lua_pushinteger(L, TaskType::CHOOSE_ATTACKER_OF_ALLY);
        lua_setfield(L, -2, "CHOOSE_ATTACKER_OF_ALLY");

        lua_pushinteger(L, TaskType::ATTACK_CHARACTERS_ATTACKER);
        lua_setfield(L, -2, "ATTACK_CHARACTERS_ATTACKER");

        lua_pushinteger(L, TaskType::PLAYER_TALK_TO);
        lua_setfield(L, -2, "PLAYER_TALK_TO");

        lua_pushinteger(L, TaskType::ATTACK_ATTACKERS_OF);
        lua_setfield(L, -2, "ATTACK_ATTACKERS_OF");

        lua_pushinteger(L, TaskType::IDLE);
        lua_setfield(L, -2, "IDLE");

        lua_pushinteger(L, TaskType::PROTECT_ALLIES);
        lua_setfield(L, -2, "PROTECT_ALLIES");

        lua_pushinteger(L, TaskType::ATTACK_ENEMIES);
        lua_setfield(L, -2, "ATTACK_ENEMIES");

        lua_pushinteger(L, TaskType::PROTECTION);
        lua_setfield(L, -2, "PROTECTION");

        lua_pushinteger(L, TaskType::RAID_TOWN);
        lua_setfield(L, -2, "RAID_TOWN");

        lua_pushinteger(L, TaskType::GO_HOMEBUILDING);
        lua_setfield(L, -2, "GO_HOMEBUILDING");

        lua_pushinteger(L, TaskType::STAND_AT_SHOPKEEPER_NODE);
        lua_setfield(L, -2, "STAND_AT_SHOPKEEPER_NODE");

        lua_pushinteger(L, TaskType::ATTACK_ENEMIES_AND_NEUTRALS);
        lua_setfield(L, -2, "ATTACK_ENEMIES_AND_NEUTRALS");

        lua_pushinteger(L, TaskType::PATROL);
        lua_setfield(L, -2, "PATROL");

        lua_pushinteger(L, TaskType::ATTACK_TOWN);
        lua_setfield(L, -2, "ATTACK_TOWN");

        lua_pushinteger(L, TaskType::WANDERER);
        lua_setfield(L, -2, "WANDERER");

        lua_pushinteger(L, TaskType::FIRST_AID_ORDER);
        lua_setfield(L, -2, "FIRST_AID_ORDER");

        lua_pushinteger(L, TaskType::LOOT_TARGET);
        lua_setfield(L, -2, "LOOT_TARGET");

        lua_pushinteger(L, TaskType::CROUCH);
        lua_setfield(L, -2, "CROUCH");

        lua_pushinteger(L, TaskType::STAND_UP);
        lua_setfield(L, -2, "STAND_UP");

        lua_pushinteger(L, TaskType::MOVE_CUS_ORDERED);
        lua_setfield(L, -2, "MOVE_CUS_ORDERED");

        lua_pushinteger(L, TaskType::HOLD_POSITION);
        lua_setfield(L, -2, "HOLD_POSITION");

        lua_pushinteger(L, TaskType::STAY_CLOSE_TO_TARGET);
        lua_setfield(L, -2, "STAY_CLOSE_TO_TARGET");

        lua_pushinteger(L, TaskType::SELF_PRESERVATION);
        lua_setfield(L, -2, "SELF_PRESERVATION");

        lua_pushinteger(L, TaskType::QUELL_AGGRESSION);
        lua_setfield(L, -2, "QUELL_AGGRESSION");

        lua_pushinteger(L, TaskType::ATTACK_TROUBLE_MAKERS);
        lua_setfield(L, -2, "ATTACK_TROUBLE_MAKERS");

        lua_pushinteger(L, TaskType::RUN_AWAY);
        lua_setfield(L, -2, "RUN_AWAY");

        lua_pushinteger(L, TaskType::PATROL_TOWN);
        lua_setfield(L, -2, "PATROL_TOWN");

        lua_pushinteger(L, TaskType::WANDER_TOWN);
        lua_setfield(L, -2, "WANDER_TOWN");

        lua_pushinteger(L, TaskType::STAND_AT_GUARD_NODE_HOMEBUILDING_IN_OUT);
        lua_setfield(L, -2, "STAND_AT_GUARD_NODE_HOMEBUILDING_IN_OUT");

        lua_pushinteger(L, TaskType::WANDERING_TRADER);
        lua_setfield(L, -2, "WANDERING_TRADER");

        lua_pushinteger(L, TaskType::GET_NEAR_TO);
        lua_setfield(L, -2, "GET_NEAR_TO");

        lua_pushinteger(L, TaskType::ATTACK_ENEMIES_OF_MY_SLAVEMASTER);
        lua_setfield(L, -2, "ATTACK_ENEMIES_OF_MY_SLAVEMASTER");

        lua_pushinteger(L, TaskType::NOT_BE_UNARMED);
        lua_setfield(L, -2, "NOT_BE_UNARMED");

        lua_pushinteger(L, TaskType::STAY_IN_HOME);
        lua_setfield(L, -2, "STAY_IN_HOME");

        lua_pushinteger(L, TaskType::FOLLOW_PLAYER_ORDER);
        lua_setfield(L, -2, "FOLLOW_PLAYER_ORDER");

        lua_pushinteger(L, TaskType::BODYGUARD);
        lua_setfield(L, -2, "BODYGUARD");

        lua_pushinteger(L, TaskType::CHASE);
        lua_setfield(L, -2, "CHASE");

        lua_pushinteger(L, TaskType::STAND_AT_GENERAL_NODE);
        lua_setfield(L, -2, "STAND_AT_GENERAL_NODE");

        lua_pushinteger(L, TaskType::STAND_AT_DEFENSIVE_NODE);
        lua_setfield(L, -2, "STAND_AT_DEFENSIVE_NODE");

        lua_pushinteger(L, TaskType::STAND_AT_BUILDING_GUARD_NODE);
        lua_setfield(L, -2, "STAND_AT_BUILDING_GUARD_NODE");

        lua_pushinteger(L, TaskType::STAND_AT_BUILDING_DEFENSIVE_NODE);
        lua_setfield(L, -2, "STAND_AT_BUILDING_DEFENSIVE_NODE");

        lua_pushinteger(L, TaskType::STAND_AT_NODE);
        lua_setfield(L, -2, "STAND_AT_NODE");

        lua_pushinteger(L, TaskType::GET_UP_STAY_DOWN_THOUGH);
        lua_setfield(L, -2, "GET_UP_STAY_DOWN_THOUGH");

        lua_pushinteger(L, TaskType::TRAVEL_TO_TARGET_TOWN);
        lua_setfield(L, -2, "TRAVEL_TO_TARGET_TOWN");

        lua_pushinteger(L, TaskType::REST);
        lua_setfield(L, -2, "REST");

        lua_pushinteger(L, TaskType::RECRUIT_AT_JOBCENTER);
        lua_setfield(L, -2, "RECRUIT_AT_JOBCENTER");

        lua_pushinteger(L, TaskType::SWITCH_FOLLOW_ME_MODE_ON);
        lua_setfield(L, -2, "SWITCH_FOLLOW_ME_MODE_ON");

        lua_pushinteger(L, TaskType::JOB_REPAIR_ROBOT);
        lua_setfield(L, -2, "JOB_REPAIR_ROBOT");

        lua_pushinteger(L, TaskType::JOB_MEDIC);
        lua_setfield(L, -2, "JOB_MEDIC");

        lua_pushinteger(L, TaskType::GET_READY_FOR_ACTION);
        lua_setfield(L, -2, "GET_READY_FOR_ACTION");

        lua_pushinteger(L, TaskType::FIRST_AID_ROBOT);
        lua_setfield(L, -2, "FIRST_AID_ROBOT");

        lua_pushinteger(L, TaskType::UNPROVOKED_FOCUSED_MELEE_ATTACK);
        lua_setfield(L, -2, "UNPROVOKED_FOCUSED_MELEE_ATTACK");

        lua_pushinteger(L, TaskType::STAND_STILL);
        lua_setfield(L, -2, "STAND_STILL");

        lua_pushinteger(L, TaskType::SQUAD_WAIT_FOR_ME);
        lua_setfield(L, -2, "SQUAD_WAIT_FOR_ME");

        lua_pushinteger(L, TaskType::MAKE_TARGET_STAND_STILL);
        lua_setfield(L, -2, "MAKE_TARGET_STAND_STILL");

        lua_pushinteger(L, TaskType::GET_UP_STAND_UP);
        lua_setfield(L, -2, "GET_UP_STAND_UP");

        lua_pushinteger(L, TaskType::FORCE_GET_UP);
        lua_setfield(L, -2, "FORCE_GET_UP");

        lua_pushinteger(L, TaskType::MOVE_ON_FREE_WILL_FAST);
        lua_setfield(L, -2, "MOVE_ON_FREE_WILL_FAST");

        lua_pushinteger(L, TaskType::LIFT_PERSON);
        lua_setfield(L, -2, "LIFT_PERSON");

        lua_pushinteger(L, TaskType::PUT_DOWN_OBJECT);
        lua_setfield(L, -2, "PUT_DOWN_OBJECT");

        lua_pushinteger(L, TaskType::PUT_DOWN_CHARACTER_IN_BED);
        lua_setfield(L, -2, "PUT_DOWN_CHARACTER_IN_BED");

        lua_pushinteger(L, TaskType::ADD_MATERIALS_TO_BUILDING);
        lua_setfield(L, -2, "ADD_MATERIALS_TO_BUILDING");

        lua_pushinteger(L, TaskType::OPEN_DOOR);
        lua_setfield(L, -2, "OPEN_DOOR");

        lua_pushinteger(L, TaskType::CLOSE_DOOR);
        lua_setfield(L, -2, "CLOSE_DOOR");

        lua_pushinteger(L, TaskType::OPEN_DOOR_HERE);
        lua_setfield(L, -2, "OPEN_DOOR_HERE");

        lua_pushinteger(L, TaskType::CLOSE_DOOR_HERE);
        lua_setfield(L, -2, "CLOSE_DOOR_HERE");

        lua_pushinteger(L, TaskType::PICK_LOCK);
        lua_setfield(L, -2, "PICK_LOCK");

        lua_pushinteger(L, TaskType::LOCK_DOOR);
        lua_setfield(L, -2, "LOCK_DOOR");

        lua_pushinteger(L, TaskType::UNLOCK_DOOR);
        lua_setfield(L, -2, "UNLOCK_DOOR");

        lua_pushinteger(L, TaskType::LOCK_DOOR_HERE);
        lua_setfield(L, -2, "LOCK_DOOR_HERE");

        lua_pushinteger(L, TaskType::UNLOCK_DOOR_HERE);
        lua_setfield(L, -2, "UNLOCK_DOOR_HERE");

        lua_pushinteger(L, TaskType::BASH_DOOR);
        lua_setfield(L, -2, "BASH_DOOR");

        lua_pushinteger(L, TaskType::MOVE_TO_BUILDING_DOOR);
        lua_setfield(L, -2, "MOVE_TO_BUILDING_DOOR");

        lua_pushinteger(L, TaskType::MOVE_TO_CURRENT_LOCATION_BUILDING_DOOR);
        lua_setfield(L, -2, "MOVE_TO_CURRENT_LOCATION_BUILDING_DOOR");

        lua_pushinteger(L, TaskType::OPEN_DOOR_FOR_CURRENT_LOCATION);
        lua_setfield(L, -2, "OPEN_DOOR_FOR_CURRENT_LOCATION");

        lua_pushinteger(L, TaskType::OPEN_DOOR_FOR_DESTINATION);
        lua_setfield(L, -2, "OPEN_DOOR_FOR_DESTINATION");

        lua_pushinteger(L, TaskType::OPEN_UP_SHOP_DOORS);
        lua_setfield(L, -2, "OPEN_UP_SHOP_DOORS");

        lua_pushinteger(L, TaskType::OPERATE_MACHINERY);
        lua_setfield(L, -2, "OPERATE_MACHINERY");

        lua_pushinteger(L, TaskType::DELIVER_RESOURCES);
        lua_setfield(L, -2, "DELIVER_RESOURCES");

        lua_pushinteger(L, TaskType::JOB_KEEP_EVERYTHING_RUNNING);
        lua_setfield(L, -2, "JOB_KEEP_EVERYTHING_RUNNING");

        lua_pushinteger(L, TaskType::UNJAM_ALL_MACHINES);
        lua_setfield(L, -2, "UNJAM_ALL_MACHINES");

        lua_pushinteger(L, TaskType::UNJAM_MACHINE);
        lua_setfield(L, -2, "UNJAM_MACHINE");

        lua_pushinteger(L, TaskType::COLLECT_OUTPUT_RESOURCE);
        lua_setfield(L, -2, "COLLECT_OUTPUT_RESOURCE");

        lua_pushinteger(L, TaskType::FILL_MACHINE);
        lua_setfield(L, -2, "FILL_MACHINE");

        lua_pushinteger(L, TaskType::WANT_TO_FILL_MACHINE);
        lua_setfield(L, -2, "WANT_TO_FILL_MACHINE");

        lua_pushinteger(L, TaskType::REPAIR);
        lua_setfield(L, -2, "REPAIR");

        lua_pushinteger(L, TaskType::DISMANTLE);
        lua_setfield(L, -2, "DISMANTLE");

        lua_pushinteger(L, TaskType::USE_TRAINING_DUMMY);
        lua_setfield(L, -2, "USE_TRAINING_DUMMY");

        lua_pushinteger(L, TaskType::USE_BED);
        lua_setfield(L, -2, "USE_BED");

        lua_pushinteger(L, TaskType::PUT_SOMEONE_IN_BED);
        lua_setfield(L, -2, "PUT_SOMEONE_IN_BED");

        lua_pushinteger(L, TaskType::GET_PUT_IN_BED);
        lua_setfield(L, -2, "GET_PUT_IN_BED");

        lua_pushinteger(L, TaskType::DEFEAT_SQUAD);
        lua_setfield(L, -2, "DEFEAT_SQUAD");

        lua_pushinteger(L, TaskType::SEEK_AND_TALK_AND_SEND_SIGNAL);
        lua_setfield(L, -2, "SEEK_AND_TALK_AND_SEND_SIGNAL");

        lua_pushinteger(L, TaskType::MAKE_ANNOUNCEMENT);
        lua_setfield(L, -2, "MAKE_ANNOUNCEMENT");

        lua_pushinteger(L, TaskType::ALWAYS_IMPOSSIBLE_TASK);
        lua_setfield(L, -2, "ALWAYS_IMPOSSIBLE_TASK");

        lua_pushinteger(L, TaskType::FIND_AND_RESCUE);
        lua_setfield(L, -2, "FIND_AND_RESCUE");

        lua_pushinteger(L, TaskType::FIND_BED_AND_PUT_IN);
        lua_setfield(L, -2, "FIND_BED_AND_PUT_IN");

        lua_pushinteger(L, TaskType::USE_CAGE);
        lua_setfield(L, -2, "USE_CAGE");

        lua_pushinteger(L, TaskType::PUT_IN_CAGE);
        lua_setfield(L, -2, "PUT_IN_CAGE");

        lua_pushinteger(L, TaskType::KNOCKOUT_PRISONER);
        lua_setfield(L, -2, "KNOCKOUT_PRISONER");

        lua_pushinteger(L, TaskType::RELEASE_PRISONER);
        lua_setfield(L, -2, "RELEASE_PRISONER");

        lua_pushinteger(L, TaskType::BREAKOUT_PRISONER);
        lua_setfield(L, -2, "BREAKOUT_PRISONER");

        lua_pushinteger(L, TaskType::FIND_CAGE_AND_PUT_IN);
        lua_setfield(L, -2, "FIND_CAGE_AND_PUT_IN");

        lua_pushinteger(L, TaskType::EMPTY_MACHINE_OUTPUTS);
        lua_setfield(L, -2, "EMPTY_MACHINE_OUTPUTS");

        lua_pushinteger(L, TaskType::GET_RID_OF_RESOURCES_IN_MY_INVENTORY);
        lua_setfield(L, -2, "GET_RID_OF_RESOURCES_IN_MY_INVENTORY");

        lua_pushinteger(L, TaskType::FIND_SOME_BUILDING_MATERIALS);
        lua_setfield(L, -2, "FIND_SOME_BUILDING_MATERIALS");

        lua_pushinteger(L, TaskType::GET_OUT_OF_BED);
        lua_setfield(L, -2, "GET_OUT_OF_BED");

        lua_pushinteger(L, TaskType::FIND_A_SHOP);
        lua_setfield(L, -2, "FIND_A_SHOP");

        lua_pushinteger(L, TaskType::SHOPPING);
        lua_setfield(L, -2, "SHOPPING");

        lua_pushinteger(L, TaskType::BUY_SHIT);
        lua_setfield(L, -2, "BUY_SHIT");

        lua_pushinteger(L, TaskType::MOVE_INSIDE_BUILDING);
        lua_setfield(L, -2, "MOVE_INSIDE_BUILDING");

        lua_pushinteger(L, TaskType::MOVE_TO_FORTIFICATION_GATE);
        lua_setfield(L, -2, "MOVE_TO_FORTIFICATION_GATE");

        lua_pushinteger(L, TaskType::OPEN_FORTIFICATION_GATE);
        lua_setfield(L, -2, "OPEN_FORTIFICATION_GATE");

        lua_pushinteger(L, TaskType::BASH_GATE);
        lua_setfield(L, -2, "BASH_GATE");

        lua_pushinteger(L, TaskType::OPERATE_STORAGE);
        lua_setfield(L, -2, "OPERATE_STORAGE");

        lua_pushinteger(L, TaskType::JOB_BUILDER);
        lua_setfield(L, -2, "JOB_BUILDER");

        lua_pushinteger(L, TaskType::TALKTO_NEAREST_PLAYER_CHARACTER);
        lua_setfield(L, -2, "TALKTO_NEAREST_PLAYER_CHARACTER");

        lua_pushinteger(L, TaskType::RUN_AWAY_HOMETOWN);
        lua_setfield(L, -2, "RUN_AWAY_HOMETOWN");

        lua_pushinteger(L, TaskType::RETREAT_HOMETOWN);
        lua_setfield(L, -2, "RETREAT_HOMETOWN");

        lua_pushinteger(L, TaskType::MAKE_ANNOUNCEMENT_FAST);
        lua_setfield(L, -2, "MAKE_ANNOUNCEMENT_FAST");

        lua_pushinteger(L, TaskType::TRAVEL_TO_TARGET_TOWN_FAST);
        lua_setfield(L, -2, "TRAVEL_TO_TARGET_TOWN_FAST");

        lua_pushinteger(L, TaskType::LOOT_FOOD_AND_STUFF);
        lua_setfield(L, -2, "LOOT_FOOD_AND_STUFF");

        lua_pushinteger(L, TaskType::FIND_AND_KIDNAP);
        lua_setfield(L, -2, "FIND_AND_KIDNAP");

        lua_pushinteger(L, TaskType::GET_OUT_OF_CAGE_LEGIT);
        lua_setfield(L, -2, "GET_OUT_OF_CAGE_LEGIT");

        lua_pushinteger(L, TaskType::KILL_CAGE_OCCUPANT);
        lua_setfield(L, -2, "KILL_CAGE_OCCUPANT");

        lua_pushinteger(L, TaskType::KILL_A_RANDOM_CAGE_OCCUPANT);
        lua_setfield(L, -2, "KILL_A_RANDOM_CAGE_OCCUPANT");

        lua_pushinteger(L, TaskType::FEED_CORPSE_INTO_MACHINE);
        lua_setfield(L, -2, "FEED_CORPSE_INTO_MACHINE");

        lua_pushinteger(L, TaskType::DEAD_GUYS_GO_IN_THE_POT);
        lua_setfield(L, -2, "DEAD_GUYS_GO_IN_THE_POT");

        lua_pushinteger(L, TaskType::FIND_A_DEAD_GUY);
        lua_setfield(L, -2, "FIND_A_DEAD_GUY");

        lua_pushinteger(L, TaskType::EAT_A_RANDOM_CAGE_OCCUPANT);
        lua_setfield(L, -2, "EAT_A_RANDOM_CAGE_OCCUPANT");

        lua_pushinteger(L, TaskType::UNLOCK_DOOR_PLAYER_ORDER);
        lua_setfield(L, -2, "UNLOCK_DOOR_PLAYER_ORDER");

        lua_pushinteger(L, TaskType::FOLLOW_SQUADLEADER);
        lua_setfield(L, -2, "FOLLOW_SQUADLEADER");

        lua_pushinteger(L, TaskType::FIND_AND_RESCUE_LEADER);
        lua_setfield(L, -2, "FIND_AND_RESCUE_LEADER");

        lua_pushinteger(L, TaskType::PROTECT_OWN_SQUAD);
        lua_setfield(L, -2, "PROTECT_OWN_SQUAD");

        lua_pushinteger(L, TaskType::TERRITORIAL_AGGRESSION_BUT_DONT_LEAVE_HOME);
        lua_setfield(L, -2, "TERRITORIAL_AGGRESSION_BUT_DONT_LEAVE_HOME");

        lua_pushinteger(L, TaskType::GET_RE_EQUIPPED);
        lua_setfield(L, -2, "GET_RE_EQUIPPED");

        lua_pushinteger(L, TaskType::USE_TURRET);
        lua_setfield(L, -2, "USE_TURRET");

        lua_pushinteger(L, TaskType::STUMBLE_TASK_FORCED);
        lua_setfield(L, -2, "STUMBLE_TASK_FORCED");

        lua_pushinteger(L, TaskType::FIND_AND_RESCUE_IF_THERES_BEDS);
        lua_setfield(L, -2, "FIND_AND_RESCUE_IF_THERES_BEDS");

        lua_pushinteger(L, TaskType::MAN_A_TURRET);
        lua_setfield(L, -2, "MAN_A_TURRET");

        lua_pushinteger(L, TaskType::PROSPECTING);
        lua_setfield(L, -2, "PROSPECTING");

        lua_pushinteger(L, TaskType::EMPTYING_MACHINE);
        lua_setfield(L, -2, "EMPTYING_MACHINE");

        lua_pushinteger(L, TaskType::OPERATE_AUTOMATIC_MACHINERY);
        lua_setfield(L, -2, "OPERATE_AUTOMATIC_MACHINERY");

        lua_pushinteger(L, TaskType::GO_HOME_AND_GO_TO_BED);
        lua_setfield(L, -2, "GO_HOME_AND_GO_TO_BED");

        lua_pushinteger(L, TaskType::GO_TO_THE_BAR_AND_DRINK);
        lua_setfield(L, -2, "GO_TO_THE_BAR_AND_DRINK");

        lua_pushinteger(L, TaskType::LOCK_ALL_MY_DOORS);
        lua_setfield(L, -2, "LOCK_ALL_MY_DOORS");

        lua_pushinteger(L, TaskType::ENTER_BUILDING);
        lua_setfield(L, -2, "ENTER_BUILDING");

        lua_pushinteger(L, TaskType::STAND_AT_GUARD_NODE_HOMETOWN_OUTSIDE);
        lua_setfield(L, -2, "STAND_AT_GUARD_NODE_HOMETOWN_OUTSIDE");

        lua_pushinteger(L, TaskType::SHOO_STRANGERS_OUT_OF_MY_BUILDING);
        lua_setfield(L, -2, "SHOO_STRANGERS_OUT_OF_MY_BUILDING");

        lua_pushinteger(L, TaskType::SEND_DIALOGUE_SIGNAL);
        lua_setfield(L, -2, "SEND_DIALOGUE_SIGNAL");

        lua_pushinteger(L, TaskType::SEND_DIALOGUE_SIGNAL_REPEAT);
        lua_setfield(L, -2, "SEND_DIALOGUE_SIGNAL_REPEAT");

        lua_pushinteger(L, TaskType::SEND_DIALOGUE_SIGNAL_WITHOUT_MOVING);
        lua_setfield(L, -2, "SEND_DIALOGUE_SIGNAL_WITHOUT_MOVING");

        lua_pushinteger(L, TaskType::LOCK_DOOR_FROM_INSIDE);
        lua_setfield(L, -2, "LOCK_DOOR_FROM_INSIDE");

        lua_pushinteger(L, TaskType::MOVE_TO_BUILDING_DOOR_INSIDEPOS);
        lua_setfield(L, -2, "MOVE_TO_BUILDING_DOOR_INSIDEPOS");

        lua_pushinteger(L, TaskType::FOLLOW_WHILE_TALKING);
        lua_setfield(L, -2, "FOLLOW_WHILE_TALKING");

        lua_pushinteger(L, TaskType::TOWN_STALKER);
        lua_setfield(L, -2, "TOWN_STALKER");

        lua_pushinteger(L, TaskType::CHAIN_TARGET);
        lua_setfield(L, -2, "CHAIN_TARGET");

        lua_pushinteger(L, TaskType::CAPTURE_NEW_SLAVES);
        lua_setfield(L, -2, "CAPTURE_NEW_SLAVES");

        lua_pushinteger(L, TaskType::CARRY_WOUNDED_SLAVES);
        lua_setfield(L, -2, "CARRY_WOUNDED_SLAVES");

        lua_pushinteger(L, TaskType::PUT_DOWN_CARRIED_DUDE_IF_THEY_CAN_WALK);
        lua_setfield(L, -2, "PUT_DOWN_CARRIED_DUDE_IF_THEY_CAN_WALK");

        lua_pushinteger(L, TaskType::LIFT_OBJECT_BUT_HEAL_FIRST);
        lua_setfield(L, -2, "LIFT_OBJECT_BUT_HEAL_FIRST");

        lua_pushinteger(L, TaskType::FOLLOW_SLAVEMASTER);
        lua_setfield(L, -2, "FOLLOW_SLAVEMASTER");

        lua_pushinteger(L, TaskType::SLAVE_GET_IN_MY_MASTERS_CAGE);
        lua_setfield(L, -2, "SLAVE_GET_IN_MY_MASTERS_CAGE");

        lua_pushinteger(L, TaskType::GATHER_SLAVES_FROM_CAGES);
        lua_setfield(L, -2, "GATHER_SLAVES_FROM_CAGES");

        lua_pushinteger(L, TaskType::GET_SLAVE);
        lua_setfield(L, -2, "GET_SLAVE");

        lua_pushinteger(L, TaskType::SLEEP_ON_FLOOR);
        lua_setfield(L, -2, "SLEEP_ON_FLOOR");

        lua_pushinteger(L, TaskType::HUNTING_BLOODSMELL);
        lua_setfield(L, -2, "HUNTING_BLOODSMELL");

        lua_pushinteger(L, TaskType::LOOT_THE_DEAD);
        lua_setfield(L, -2, "LOOT_THE_DEAD");

        lua_pushinteger(L, TaskType::LOOT_TO_REPLACE_MISSING_WEAPON);
        lua_setfield(L, -2, "LOOT_TO_REPLACE_MISSING_WEAPON");

        lua_pushinteger(L, TaskType::HUNT_MY_THIEF);
        lua_setfield(L, -2, "HUNT_MY_THIEF");

        lua_pushinteger(L, TaskType::MAN_THE_GATE);
        lua_setfield(L, -2, "MAN_THE_GATE");

        lua_pushinteger(L, TaskType::STRIP_TARGETS_WEAPONS);
        lua_setfield(L, -2, "STRIP_TARGETS_WEAPONS");

        lua_pushinteger(L, TaskType::PROCESS_AND_STRIP_NEW_SLAVE);
        lua_setfield(L, -2, "PROCESS_AND_STRIP_NEW_SLAVE");

        lua_pushinteger(L, TaskType::SLAVE_WATCHING);
        lua_setfield(L, -2, "SLAVE_WATCHING");

        lua_pushinteger(L, TaskType::PUT_LOOT_IN_STORAGE);
        lua_setfield(L, -2, "PUT_LOOT_IN_STORAGE");

        lua_pushinteger(L, TaskType::CUT_SHACKLES);
        lua_setfield(L, -2, "SHACKLES");

        lua_pushinteger(L, TaskType::BRUTE_FORCE_SHACKLES);
        lua_setfield(L, -2, "BRUTE_FORCE_SHACKLES");

        lua_pushinteger(L, TaskType::_SLAVE_OBEDIENCE);
        lua_setfield(L, -2, "SLAVE_OBEDIENCE");

        lua_pushinteger(L, TaskType::WORK_THE_SLAVES);
        lua_setfield(L, -2, "WORK_THE_SLAVES");

        lua_pushinteger(L, TaskType::AUTO_LABOURING_MINES);
        lua_setfield(L, -2, "AUTO_LABOURING_MINES");

        lua_pushinteger(L, TaskType::AUTO_LABOURING_MINES_PRETEND);
        lua_setfield(L, -2, "AUTO_LABOURING_MINES_PRETEND");

        lua_pushinteger(L, TaskType::GO_TO_NEAREST_HQ);
        lua_setfield(L, -2, "GO_TO_NEAREST_HQ");

        lua_pushinteger(L, TaskType::GO_TO_SOMEWHERE_FOR_DELIVERING_SLAVES);
        lua_setfield(L, -2, "GO_TO_SOMEWHERE_FOR_DELIVERING_SLAVES");

        lua_pushinteger(L, TaskType::CAPTURE_ESCAPING_SLAVES);
        lua_setfield(L, -2, "CAPTURE_ESCAPING_SLAVES");

        lua_pushinteger(L, TaskType::GIVE_ALL_MY_SLAVES_TO);
        lua_setfield(L, -2, "GIVE_ALL_MY_SLAVES_TO");

        lua_pushinteger(L, TaskType::LOCK_ALL_THE_CAGES);
        lua_setfield(L, -2, "LOCK_ALL_THE_CAGES");

        lua_pushinteger(L, TaskType::BEAT_CAGE_OCCUPANT);
        lua_setfield(L, -2, "BEAT_CAGE_OCCUPANT");

        lua_pushinteger(L, TaskType::LOCK_ALL_MY_DOORS_FROM_OUTSIDE);
        lua_setfield(L, -2, "LOCK_ALL_MY_DOORS_FROM_OUTSIDE");

        lua_pushinteger(L, TaskType::LOCK_DOOR_FROM_OUTSIDE);
        lua_setfield(L, -2, "LOCK_DOOR_FROM_OUTSIDE");

        lua_pushinteger(L, TaskType::MOVE_TO_BUILDING_DOOR_OUTSIDEPOS);
        lua_setfield(L, -2, "MOVE_TO_BUILDING_DOOR_OUTSIDEPOS");

        lua_pushinteger(L, TaskType::LEAVE_BUILDING);
        lua_setfield(L, -2, "LEAVE_BUILDING");

        lua_pushinteger(L, TaskType::PICK_LOCK_ON_SHACKLES);
        lua_setfield(L, -2, "PICK_LOCK_ON_SHACKLES");

        lua_pushinteger(L, TaskType::TOTAL_ESCAPE);
        lua_setfield(L, -2, "TOTAL_ESCAPE");

        lua_pushinteger(L, TaskType::ARREST_TARGET);
        lua_setfield(L, -2, "ARREST_TARGET");

        lua_pushinteger(L, TaskType::HUNT_BOUNTIES);
        lua_setfield(L, -2, "HUNT_BOUNTIES");

        lua_pushinteger(L, TaskType::ARREST_TARGETS_CARRIED_PERSON);
        lua_setfield(L, -2, "ARREST_TARGETS_CARRIED_PERSON");

        lua_pushinteger(L, TaskType::FIND_CAGE_AND_PUT_IN_IF_BOUNTY);
        lua_setfield(L, -2, "FIND_CAGE_AND_PUT_IN_IF_BOUNTY");

        lua_pushinteger(L, TaskType::GET_OUT_OF_CAGE_ESCAPE);
        lua_setfield(L, -2, "GET_OUT_OF_CAGE_ESCAPE");

        lua_pushinteger(L, TaskType::GET_OUT_OF_BED_IF_ITS_EMERGENCY);
        lua_setfield(L, -2, "GET_OUT_OF_BED_IF_ITS_EMERGENCY");

        lua_pushinteger(L, TaskType::INVESTIGATE_ALARMS);
        lua_setfield(L, -2, "INVESTIGATE_ALARMS");

        lua_pushinteger(L, TaskType::INVESTIGATE_ALARMS_ALLIES_ONLY);
        lua_setfield(L, -2, "INVESTIGATE_ALARMS_ALLIES_ONLY");

        lua_pushinteger(L, TaskType::POLICE_FREE_PRISONERS_WHEN_DONE);
        lua_setfield(L, -2, "POLICE_FREE_PRISONERS_WHEN_DONE");

        lua_pushinteger(L, TaskType::LOOT_STOLEN_GOODS);
        lua_setfield(L, -2, "LOOT_STOLEN_GOODS");

        lua_pushinteger(L, TaskType::LIFT_PERSON_SNATCHING_ALLOWED);
        lua_setfield(L, -2, "LIFT_PERSON_SNATCHING_ALLOWED");

        lua_pushinteger(L, TaskType::RELAX_IN_TOWN_PACKAGE);
        lua_setfield(L, -2, "RELAX_IN_TOWN_PACKAGE");

        lua_pushinteger(L, TaskType::TRAVEL_TO_TARGET_PACKAGE);
        lua_setfield(L, -2, "TRAVEL_TO_TARGET_PACKAGE");

        lua_pushinteger(L, TaskType::RUN_AROUND_TOWN_LOOKING_FOR_PEOPLE);
        lua_setfield(L, -2, "RUN_AROUND_TOWN_LOOKING_FOR_PEOPLE");

        lua_pushinteger(L, TaskType::GATHER_SLAVES_FROM_CAGES_IF_ITS_AN_EXPORT_TOWN);
        lua_setfield(L, -2, "GATHER_SLAVES_FROM_CAGES_IF_ITS_AN_EXPORT_TOWN");

        lua_pushinteger(L, TaskType::GIVE_ALL_MY_SLAVES_TO_IF_ITS_AN_IMPORT_TOWN);
        lua_setfield(L, -2, "GIVE_ALL_MY_SLAVES_TO_IF_ITS_AN_IMPORT_TOWN");

        lua_pushinteger(L, TaskType::TAKE_OFF_MY_SHACKLES);
        lua_setfield(L, -2, "TAKE_OFF_MY_SHACKLES");

        lua_pushinteger(L, TaskType::EAT_TARGET_ALIVE);
        lua_setfield(L, -2, "EAT_TARGET_ALIVE");

        lua_pushinteger(L, TaskType::PRETEND_TO_OPERATE_MACHINERY);
        lua_setfield(L, -2, "PRETEND_TO_OPERATE_MACHINERY");

        lua_pushinteger(L, TaskType::MAN_A_TURRET_ON_BUILDING);
        lua_setfield(L, -2, "MAN_A_TURRET_ON_BUILDING");

        lua_pushinteger(L, TaskType::PICKUP_INTRUDERS_BUILDING);
        lua_setfield(L, -2, "PICKUP_INTRUDERS_BUILDING");

        lua_pushinteger(L, TaskType::TAKE_INTRUDER_OUTSIDE);
        lua_setfield(L, -2, "TAKE_INTRUDER_OUTSIDE");

        lua_pushinteger(L, TaskType::LIFT_PERSON_PLAYER_ORDER);
        lua_setfield(L, -2, "LIFT_PERSON_PLAYER_ORDER");

        lua_pushinteger(L, TaskType::BASH_DOOR_PLAYER_ORDER);
        lua_setfield(L, -2, "BASH_DOOR_PLAYER_ORDER");

        lua_pushinteger(L, TaskType::MELEE_ATTACK_ANIMAL);
        lua_setfield(L, -2, "MELEE_ATTACK_ANIMAL");

        lua_pushinteger(L, TaskType::STEALTH_KNOCKOUT);
        lua_setfield(L, -2, "STEALTH_KNOCKOUT");

        lua_pushinteger(L, TaskType::STEALTH_KILL);
        lua_setfield(L, -2, "STEALTH_KILL");

        lua_pushinteger(L, TaskType::EAT_A_RANDOM_DEAD_BODY);
        lua_setfield(L, -2, "EAT_A_RANDOM_DEAD_BODY");

        lua_pushinteger(L, TaskType::EAT_CROPS);
        lua_setfield(L, -2, "EAT_CROPS");

        lua_pushinteger(L, TaskType::FIND_CROPS_TO_EAT);
        lua_setfield(L, -2, "FIND_CROPS_TO_EAT");

        lua_pushinteger(L, TaskType::EAT_A_RANDOM_KO_BODY);
        lua_setfield(L, -2, "EAT_A_RANDOM_KO_BODY");

        lua_pushinteger(L, TaskType::MAN_A_TURRET_PLAYER_JOB);
        lua_setfield(L, -2, "MAN_A_TURRET_PLAYER_JOB");

        lua_pushinteger(L, TaskType::SHOOT_AT_TARGET);
        lua_setfield(L, -2, "SHOOT_AT_TARGET");

        lua_pushinteger(L, TaskType::WORSHIP_TARGET);
        lua_setfield(L, -2, "WORSHIP_TARGET");

        lua_pushinteger(L, TaskType::FOGMAN_WORSHIP_VICTIM);
        lua_setfield(L, -2, "FOGMAN_WORSHIP_VICTIM");

        lua_pushinteger(L, TaskType::LOOT_ANIMALS_JOB);
        lua_setfield(L, -2, "LOOT_ANIMALS_JOB");

        lua_pushinteger(L, TaskType::GO_HOME_AND_GO_TO_BED_SECURE);
        lua_setfield(L, -2, "GO_HOME_AND_GO_TO_BED_SECURE");

        lua_pushinteger(L, TaskType::LIFT_PERSON_SNATCHING_ALLOWED_IN_TOWN_ONLY);
        lua_setfield(L, -2, "LIFT_PERSON_SNATCHING_ALLOWED_IN_TOWN_ONLY");

        lua_pushinteger(L, TaskType::LOOT_RESOURCE_ITEMS_WE_HAVE_STORAGE_FOR);
        lua_setfield(L, -2, "LOOT_RESOURCE_ITEMS_WE_HAVE_STORAGE_FOR");

        lua_pushinteger(L, TaskType::DITCH_ALL_RESOURCES);
        lua_setfield(L, -2, "DITCH_ALL_RESOURCES");

        lua_pushinteger(L, TaskType::AQUIRE_FOOD_AT_HOMEBASE);
        lua_setfield(L, -2, "AQUIRE_FOOD_AT_HOMEBASE");

        lua_pushinteger(L, TaskType::GRAB_ONE_FOOD);
        lua_setfield(L, -2, "GRAB_ONE_FOOD");

        lua_pushinteger(L, TaskType::GATHER_PRISONERS_FROM_CAGES_IF_FEMALE_OR_BEAST);
        lua_setfield(L, -2, "GATHER_PRISONERS_FROM_CAGES_IF_FEMALE_OR_BEAST");

        lua_pushinteger(L, TaskType::KIDNAP_ORDER);
        lua_setfield(L, -2, "KIDNAP_ORDER");

        lua_pushinteger(L, TaskType::COLLECT_OUTPUT_RESOURCE_BUILD_MATS);
        lua_setfield(L, -2, "COLLECT_OUTPUT_RESOURCE_BUILD_MATS");

        lua_pushinteger(L, TaskType::DEFEAT_SQUAD_LIMIT_CHASE_RANGE);
        lua_setfield(L, -2, "DEFEAT_SQUAD_LIMIT_CHASE_RANGE");

        lua_pushinteger(L, TaskType::SPLINT_ORDER);
        lua_setfield(L, -2, "SPLINT_ORDER");

        lua_pushinteger(L, TaskType::SPLINT_JOB);
        lua_setfield(L, -2, "SPLINT_JOB");

        lua_pushinteger(L, TaskType::ESCAPE_KIDNAP);
        lua_setfield(L, -2, "ESCAPE_KIDNAP");

        lua_pushinteger(L, TaskType::ESCAPE_KIDNAP_STR);
        lua_setfield(L, -2, "ESCAPE_KIDNAP_STR");

        lua_pushinteger(L, TaskType::FOLLOW_URGENT_ESCAPE);
        lua_setfield(L, -2, "FOLLOW_URGENT_ESCAPE");

        lua_pushinteger(L, TaskType::FINAL_KIDNAPPER_CAGE_JOB);
        lua_setfield(L, -2, "FINAL_KIDNAPPER_CAGE_JOB");

        lua_pushinteger(L, TaskType::SIT_ON_THRONE);
        lua_setfield(L, -2, "SIT_ON_THRONE");

        lua_pushinteger(L, TaskType::GET_OUT_OF_CAGE_OPPORTUNISTIC);
        lua_setfield(L, -2, "GET_OUT_OF_CAGE_OPPORTUNISTIC");

        lua_pushinteger(L, TaskType::GET_OUT_OF_BED_ONCE_HEALED);
        lua_setfield(L, -2, "GET_OUT_OF_BED_ONCE_HEALED");

        lua_pushinteger(L, TaskType::USE_BED_ORDER);
        lua_setfield(L, -2, "USE_BED_ORDER");

        lua_pushinteger(L, TaskType::EAT_FOOD_ON_GROUND);
        lua_setfield(L, -2, "EAT_FOOD_ON_GROUND");

        lua_pushinteger(L, TaskType::NEW_SLAVE_PROCESSING);
        lua_setfield(L, -2, "NEW_SLAVE_PROCESSING");

        lua_pushinteger(L, TaskType::SLEEP_ON_FLOOR_FAKE_AMBUSH);
        lua_setfield(L, -2, "SLEEP_ON_FLOOR_FAKE_AMBUSH");

        lua_pushinteger(L, TaskType::RANGED_ATTACK);
        lua_setfield(L, -2, "RANGED_ATTACK");

        lua_pushinteger(L, TaskType::RANGED_ATTACK_FOCUSED);
        lua_setfield(L, -2, "RANGED_ATTACK_FOCUSED");

        lua_pushinteger(L, TaskType::EQUIP_CROSSBOW);
        lua_setfield(L, -2, "EQUIP_CROSSBOW");

        lua_pushinteger(L, TaskType::UNEQUIP_CROSSBOW);
        lua_setfield(L, -2, "UNEQUIP_CROSSBOW");

        lua_pushinteger(L, TaskType::RANGED_ATTACK_FOCUSED_UNPROVOKED);
        lua_setfield(L, -2, "RANGED_ATTACK_FOCUSED_UNPROVOKED");

        lua_pushinteger(L, TaskType::MOVE_IN_BOW_RANGE);
        lua_setfield(L, -2, "MOVE_IN_BOW_RANGE");

        lua_pushinteger(L, TaskType::STAND_AT_GUARD_NODE_HOMEBUILDING_INDOORS_ONLY);
        lua_setfield(L, -2, "STAND_AT_GUARD_NODE_HOMEBUILDING_INDOORS_ONLY");

        lua_pushinteger(L, TaskType::HEAL_MY_LEGS);
        lua_setfield(L, -2, "HEAL_MY_LEGS");

        lua_pushinteger(L, TaskType::ASSAULT_FORTIFICATIONS_PREFER_GATES);
        lua_setfield(L, -2, "ASSAULT_FORTIFICATIONS_PREFER_GATES");

        lua_pushinteger(L, TaskType::ASSAULT_FORTIFICATIONS_PREFER_WALLS);
        lua_setfield(L, -2, "ASSAULT_FORTIFICATIONS_PREFER_WALLS");

        lua_pushinteger(L, TaskType::SMASH_BUILDING);
        lua_setfield(L, -2, "SMASH_BUILDING");

        lua_pushinteger(L, TaskType::PICKUP_INTRUDERS_TOWN);
        lua_setfield(L, -2, "PICKUP_INTRUDERS_TOWN");

        lua_pushinteger(L, TaskType::TAKE_INTRUDER_OUTSIDE_TOWN);
        lua_setfield(L, -2, "TAKE_INTRUDER_OUTSIDE_TOWN");

        lua_pushinteger(L, TaskType::SIT_AROUND);
        lua_setfield(L, -2, "SIT_AROUND");

        lua_pushinteger(L, TaskType::LIBERATE_ALL_THE_PRISONERS);
        lua_setfield(L, -2, "LIBERATE_ALL_THE_PRISONERS");

        lua_pushinteger(L, TaskType::ANIMAL_FETCH_A_LIMB);
        lua_setfield(L, -2, "ANIMAL_FETCH_A_LIMB");

        lua_pushinteger(L, TaskType::PLAY_BECAUSE_I_HAVE_A_LIMB_IN_MOUTH);
        lua_setfield(L, -2, "PLAY_BECAUSE_I_HAVE_A_LIMB_IN_MOUTH");

        lua_pushinteger(L, TaskType::CHASE_ALLY_DOGS_WITH_MOUTH_LIMBS);
        lua_setfield(L, -2, "CHASE_ALLY_DOGS_WITH_MOUTH_LIMBS");

        lua_pushinteger(L, TaskType::RUN_AWAY_FORCED);
        lua_setfield(L, -2, "RUN_AWAY_FORCED");

        lua_pushinteger(L, TaskType::FIND_CAGE_AND_PUT_DEADGUY_IN);
        lua_setfield(L, -2, "FIND_CAGE_AND_PUT_DEADGUY_IN");

        lua_pushinteger(L, TaskType::EAT_A_RANDOM_CAGE_OCCUPANT_MEASURED_RATE);
        lua_setfield(L, -2, "EAT_A_RANDOM_CAGE_OCCUPANT_MEASURED_RATE");

        lua_pushinteger(L, TaskType::SHOO_STRANGERS_OUT_OF_MY_BUILDING_IF_PRIVATE);
        lua_setfield(L, -2, "SHOO_STRANGERS_OUT_OF_MY_BUILDING_IF_PRIVATE");

        lua_pushinteger(L, TaskType::LOOT_CONTAINER);
        lua_setfield(L, -2, "LOOT_CONTAINER");

        lua_pushinteger(L, TaskType::CUT_LOCK);
        lua_setfield(L, -2, "LOCK");

        lua_pushinteger(L, TaskType::BRUTE_FORCE_LOCK);
        lua_setfield(L, -2, "BRUTE_FORCE_LOCK");

        lua_pushinteger(L, TaskType::BASH_DOOR_HERE);
        lua_setfield(L, -2, "BASH_DOOR_HERE");

        lua_pushinteger(L, TaskType::PROTECT_ALLIES_STAY_IN_TOWN);
        lua_setfield(L, -2, "PROTECT_ALLIES_STAY_IN_TOWN");

        lua_pushinteger(L, TaskType::STAY_CLOSE_TO_TARGET_ANIMAL);
        lua_setfield(L, -2, "STAY_CLOSE_TO_TARGET_ANIMAL");

        lua_pushinteger(L, TaskType::BASH_GATE_PLAYER_ORDER);
        lua_setfield(L, -2, "BASH_GATE_PLAYER_ORDER");

        lua_setglobal(L, "TaskType");
    }

    void EnumsEnumBinding::registerWeaponCategory(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, WeaponCategory::SKILL_KATANAS);
        lua_setfield(L, -2, "SKILL_KATANAS");
		lua_pushinteger(L, WeaponCategory::SKILL_KATANAS);
		lua_setfield(L, -2, "KATANAS");

        lua_pushinteger(L, WeaponCategory::SKILL_SABRES);
        lua_setfield(L, -2, "SKILL_SABRES");
		lua_pushinteger(L, WeaponCategory::SKILL_SABRES);
		lua_setfield(L, -2, "SABRES");

        lua_pushinteger(L, WeaponCategory::SKILL_BLUNT);
        lua_setfield(L, -2, "SKILL_BLUNT");
		lua_pushinteger(L, WeaponCategory::SKILL_BLUNT);
		lua_setfield(L, -2, "BLUNT");

        lua_pushinteger(L, WeaponCategory::SKILL_HEAVY);
        lua_setfield(L, -2, "SKILL_HEAVY");
		lua_pushinteger(L, WeaponCategory::SKILL_HEAVY);
		lua_setfield(L, -2, "HEAVY");

        lua_pushinteger(L, WeaponCategory::SKILL_HACKERS);
        lua_setfield(L, -2, "SKILL_HACKERS");
		lua_pushinteger(L, WeaponCategory::SKILL_HACKERS);
		lua_setfield(L, -2, "HACKERS");

        lua_pushinteger(L, WeaponCategory::SKILL_UNARMED);
        lua_setfield(L, -2, "SKILL_UNARMED");
		lua_pushinteger(L, WeaponCategory::SKILL_UNARMED);
		lua_setfield(L, -2, "UNARMED");

        lua_pushinteger(L, WeaponCategory::SKILL_BOW);
        lua_setfield(L, -2, "SKILL_BOW");
		lua_pushinteger(L, WeaponCategory::SKILL_BOW);
		lua_setfield(L, -2, "BOW");

        lua_pushinteger(L, WeaponCategory::SKILL_TURRET);
        lua_setfield(L, -2, "SKILL_TURRET");
		lua_pushinteger(L, WeaponCategory::SKILL_TURRET);
		lua_setfield(L, -2, "TURRET");

        lua_pushinteger(L, WeaponCategory::ATTACK_POLEARMS);
        lua_setfield(L, -2, "ATTACK_POLEARMS");
		lua_pushinteger(L, WeaponCategory::ATTACK_POLEARMS);
		lua_setfield(L, -2, "POLEARMS");

        lua_pushinteger(L, WeaponCategory::ATTACK_ELEPHANT);
        lua_setfield(L, -2, "ATTACK_ELEPHANT");
		lua_pushinteger(L, WeaponCategory::ATTACK_ELEPHANT);
		lua_setfield(L, -2, "ELEPHANT");

        lua_pushinteger(L, WeaponCategory::ATTACK_DOG);
        lua_setfield(L, -2, "ATTACK_DOG");
		lua_pushinteger(L, WeaponCategory::ATTACK_DOG);
		lua_setfield(L, -2, "DOG");

        lua_pushinteger(L, WeaponCategory::ATTACK_BULL);
        lua_setfield(L, -2, "ATTACK_BULL");
		lua_pushinteger(L, WeaponCategory::ATTACK_BULL);
		lua_setfield(L, -2, "BULL");

        lua_pushinteger(L, WeaponCategory::ATTACK_ROBOTSPIDER);
        lua_setfield(L, -2, "ATTACK_ROBOTSPIDER");
		lua_pushinteger(L, WeaponCategory::ATTACK_ROBOTSPIDER);
		lua_setfield(L, -2, "ROBOTSPIDER");

        lua_pushinteger(L, WeaponCategory::ATTACK_SPIDER);
        lua_setfield(L, -2, "ATTACK_SPIDER");
		lua_pushinteger(L, WeaponCategory::ATTACK_SPIDER);
		lua_setfield(L, -2, "SPIDER");

        lua_pushinteger(L, WeaponCategory::ATTACK_CAGEBEAST);
        lua_setfield(L, -2, "ATTACK_CAGEBEAST");
		lua_pushinteger(L, WeaponCategory::ATTACK_CAGEBEAST);
		lua_setfield(L, -2, "CAGEBEAST");

        lua_pushinteger(L, WeaponCategory::ATTACK_DUCK);
        lua_setfield(L, -2, "ATTACK_DUCK");
		lua_pushinteger(L, WeaponCategory::ATTACK_DUCK);
		lua_setfield(L, -2, "DUCK");

        lua_pushinteger(L, WeaponCategory::ATTACK_GORILLA);
        lua_setfield(L, -2, "ATTACK_GORILLA");
		lua_pushinteger(L, WeaponCategory::ATTACK_GORILLA);
		lua_setfield(L, -2, "GORILLA");

        lua_pushinteger(L, WeaponCategory::ATTACK_GAR);
        lua_setfield(L, -2, "ATTACK_GAR");
		lua_pushinteger(L, WeaponCategory::ATTACK_GAR);
		lua_setfield(L, -2, "GAR");

        lua_pushinteger(L, WeaponCategory::ATTACK_FROG);
        lua_setfield(L, -2, "ATTACK_FROG");
		lua_pushinteger(L, WeaponCategory::ATTACK_FROG);
		lua_setfield(L, -2, "FROG");

        lua_pushinteger(L, WeaponCategory::ATTACK_GOAT);
        lua_setfield(L, -2, "ATTACK_GOAT");
		lua_pushinteger(L, WeaponCategory::ATTACK_GOAT);
		lua_setfield(L, -2, "GOAT");

        lua_pushinteger(L, WeaponCategory::ATTACK_GIRAFFE);
        lua_setfield(L, -2, "ATTACK_GIRAFFE");
		lua_pushinteger(L, WeaponCategory::ATTACK_GIRAFFE);
		lua_setfield(L, -2, "GIRAFFE");

        lua_pushinteger(L, WeaponCategory::ATTACK_NULL);
        lua_setfield(L, -2, "ATTACK_NULL");
		lua_pushinteger(L, WeaponCategory::ATTACK_NULL);
		lua_setfield(L, -2, "NULL");

        lua_pushinteger(L, WeaponCategory::NUM_SKILL_TYPES);
        lua_setfield(L, -2, "NUM_SKILL_TYPES");

        lua_setglobal(L, "WeaponCategory");
    }

    void EnumsEnumBinding::registerLeftRight(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, LeftRight::SIDE_NEITHER);
        lua_setfield(L, -2, "SIDE_NEITHER");
		lua_pushinteger(L, LeftRight::SIDE_NEITHER);
		lua_setfield(L, -2, "NEITHER");

        lua_pushinteger(L, LeftRight::SIDE_LEFT);
        lua_setfield(L, -2, "SIDE_LEFT");
		lua_pushinteger(L, LeftRight::SIDE_LEFT);
		lua_setfield(L, -2, "LEFT");

        lua_pushinteger(L, LeftRight::SIDE_RIGHT);
        lua_setfield(L, -2, "SIDE_RIGHT");
		lua_pushinteger(L, LeftRight::SIDE_RIGHT);
		lua_setfield(L, -2, "RIGHT");

        lua_pushinteger(L, LeftRight::SIDE_BOTH);
        lua_setfield(L, -2, "SIDE_BOTH");
		lua_pushinteger(L, LeftRight::SIDE_BOTH);
		lua_setfield(L, -2, "BOTH");

        lua_setglobal(L, "LeftRight");
    }

    void EnumsEnumBinding::registerMessageType(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, MessageForB::MessageType::M_UNSELECT_ALL);
        lua_setfield(L, -2, "M_UNSELECT_ALL");
		lua_pushinteger(L, MessageForB::MessageType::M_UNSELECT_ALL);
		lua_setfield(L, -2, "UNSELECT_ALL");

        lua_pushinteger(L, MessageForB::MessageType::M_GIVE_TASK);
        lua_setfield(L, -2, "M_GIVE_TASK");
		lua_pushinteger(L, MessageForB::MessageType::M_GIVE_TASK);
		lua_setfield(L, -2, "GIVE_TASK");

        lua_setglobal(L, "MessageType");
    }

    void EnumsEnumBinding::registerStandingOrder(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_RUN);
        lua_setfield(L, -2, "M_SET_ORDER_RUN");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_JOG);
        lua_setfield(L, -2, "M_SET_ORDER_JOG");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_WALK);
        lua_setfield(L, -2, "M_SET_ORDER_WALK");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_STEALTH_ON);
        lua_setfield(L, -2, "M_SET_ORDER_STEALTH_ON");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_STEALTH_OFF);
        lua_setfield(L, -2, "M_SET_ORDER_STEALTH_OFF");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_AGG);
        lua_setfield(L, -2, "M_SET_ORDER_AGG");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_DEF);
        lua_setfield(L, -2, "M_SET_ORDER_DEF");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_EVADE);
        lua_setfield(L, -2, "M_SET_ORDER_EVADE");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_FAR);
        lua_setfield(L, -2, "M_SET_ORDER_FAR");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_NEAR);
        lua_setfield(L, -2, "M_SET_ORDER_NEAR");

        lua_pushinteger(L, MessageForB::StandingOrder::M__TOGGLEORDERS__AFTER__THIS_);
        lua_setfield(L, -2, "M__TOGGLEORDERS__AFTER__THIS_");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_DEFENSIVE_COMBAT);
        lua_setfield(L, -2, "M_SET_ORDER_DEFENSIVE_COMBAT");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_HOLD);
        lua_setfield(L, -2, "M_SET_ORDER_HOLD");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_PASSIVE);
        lua_setfield(L, -2, "M_SET_ORDER_PASSIVE");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_TAUNT);
        lua_setfield(L, -2, "M_SET_ORDER_TAUNT");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_CHASE);
        lua_setfield(L, -2, "M_SET_ORDER_CHASE");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_GROUP_SPEED);
        lua_setfield(L, -2, "M_SET_ORDER_GROUP_SPEED");

        lua_pushinteger(L, MessageForB::StandingOrder::M_SET_ORDER_RANGED);
        lua_setfield(L, -2, "M_SET_ORDER_RANGED");

        lua_setglobal(L, "MessageB::StandingOrder");
    }

    void EnumsEnumBinding::registerStatsEnumerated(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, StatsEnumerated::STAT_NONE);
        lua_setfield(L, -2, "NONE");
        lua_pushinteger(L, StatsEnumerated::STAT_NONE);
		lua_setfield(L, -2, "STAT_NONE");

        lua_pushinteger(L, StatsEnumerated::STAT_STRENGTH);
        lua_setfield(L, -2, "STRENGTH");
		lua_pushinteger(L, StatsEnumerated::STAT_STRENGTH);
		lua_setfield(L, -2, "STAT_STRENGTH");

        lua_pushinteger(L, StatsEnumerated::STAT_MELEE_ATTACK);
        lua_setfield(L, -2, "MELEE_ATTACK");
		lua_pushinteger(L, StatsEnumerated::STAT_MELEE_ATTACK);
		lua_setfield(L, -2, "STAT_MELEE_ATTACK");

        lua_pushinteger(L, StatsEnumerated::STAT_LABOURING);
        lua_setfield(L, -2, "LABOURING");
		lua_pushinteger(L, StatsEnumerated::STAT_LABOURING);
		lua_setfield(L, -2, "STAT_LABOURING");

        lua_pushinteger(L, StatsEnumerated::STAT_SCIENCE);
        lua_setfield(L, -2, "SCIENCE");
		lua_pushinteger(L, StatsEnumerated::STAT_SCIENCE);
		lua_setfield(L, -2, "STAT_SCIENCE");

        lua_pushinteger(L, StatsEnumerated::STAT_ENGINEERING);
        lua_setfield(L, -2, "ENGINEERING");
		lua_pushinteger(L, StatsEnumerated::STAT_ENGINEERING);
		lua_setfield(L, -2, "STAT_ENGINEERING");

        lua_pushinteger(L, StatsEnumerated::STAT_ROBOTICS);
        lua_setfield(L, -2, "ROBOTICS");
		lua_pushinteger(L, StatsEnumerated::STAT_ROBOTICS);
		lua_setfield(L, -2, "STAT_ROBOTICS");

        lua_pushinteger(L, StatsEnumerated::STAT_SMITHING_WEAPON);
        lua_setfield(L, -2, "SMITHING_WEAPON");
		lua_pushinteger(L, StatsEnumerated::STAT_SMITHING_WEAPON);
		lua_setfield(L, -2, "STAT_SMITHING_WEAPON");

        lua_pushinteger(L, StatsEnumerated::STAT_SMITHING_ARMOUR);
        lua_setfield(L, -2, "SMITHING_ARMOUR");
		lua_pushinteger(L, StatsEnumerated::STAT_SMITHING_ARMOUR);
		lua_setfield(L, -2, "STAT_SMITHING_ARMOUR");

        lua_pushinteger(L, StatsEnumerated::STAT_MEDIC);
        lua_setfield(L, -2, "MEDIC");
		lua_pushinteger(L, StatsEnumerated::STAT_MEDIC);
		lua_setfield(L, -2, "STAT_MEDIC");

        lua_pushinteger(L, StatsEnumerated::STAT_THIEVING);
        lua_setfield(L, -2, "THIEVING");
		lua_pushinteger(L, StatsEnumerated::STAT_THIEVING);
		lua_setfield(L, -2, "STAT_THIEVING");

        lua_pushinteger(L, StatsEnumerated::STAT_TURRETS);
        lua_setfield(L, -2, "TURRETS");
		lua_pushinteger(L, StatsEnumerated::STAT_TURRETS);
		lua_setfield(L, -2, "STAT_TURRETS");

        lua_pushinteger(L, StatsEnumerated::STAT_FARMING);
        lua_setfield(L, -2, "FARMING");
		lua_pushinteger(L, StatsEnumerated::STAT_FARMING);
		lua_setfield(L, -2, "STAT_FARMING");

        lua_pushinteger(L, StatsEnumerated::STAT_COOKING);
        lua_setfield(L, -2, "COOKING");
		lua_pushinteger(L, StatsEnumerated::STAT_COOKING);
		lua_setfield(L, -2, "STAT_COOKING");

        lua_pushinteger(L, StatsEnumerated::STAT_HIVEMEDIC);
        lua_setfield(L, -2, "HIVEMEDIC");
		lua_pushinteger(L, StatsEnumerated::STAT_HIVEMEDIC);
		lua_setfield(L, -2, "STAT_HIVEMEDIC");

        lua_pushinteger(L, StatsEnumerated::STAT_VET);
        lua_setfield(L, -2, "VET");
		lua_pushinteger(L, StatsEnumerated::STAT_VET);
		lua_setfield(L, -2, "STAT_VET");

        lua_pushinteger(L, StatsEnumerated::STAT_STEALTH);
        lua_setfield(L, -2, "STEALTH");
		lua_pushinteger(L, StatsEnumerated::STAT_STEALTH);
		lua_setfield(L, -2, "STAT_STEALTH");

        lua_pushinteger(L, StatsEnumerated::STAT_ATHLETICS);
        lua_setfield(L, -2, "ATHLETICS");
		lua_pushinteger(L, StatsEnumerated::STAT_ATHLETICS);
		lua_setfield(L, -2, "STAT_ATHLETICS");

        lua_pushinteger(L, StatsEnumerated::STAT_DEXTERITY);
        lua_setfield(L, -2, "DEXTERITY");
		lua_pushinteger(L, StatsEnumerated::STAT_DEXTERITY);
		lua_setfield(L, -2, "STAT_DEXTERITY");

        lua_pushinteger(L, StatsEnumerated::STAT_MELEE_DEFENCE);
        lua_setfield(L, -2, "MELEE_DEFENCE");
		lua_pushinteger(L, StatsEnumerated::STAT_MELEE_DEFENCE);
		lua_setfield(L, -2, "STAT_MELEE_DEFENCE");

        lua_pushinteger(L, StatsEnumerated::STAT_WEAPONS);
        lua_setfield(L, -2, "WEAPONS");
		lua_pushinteger(L, StatsEnumerated::STAT_WEAPONS);
		lua_setfield(L, -2, "STAT_WEAPONS");

        lua_pushinteger(L, StatsEnumerated::STAT_TOUGHNESS);
        lua_setfield(L, -2, "TOUGHNESS");
		lua_pushinteger(L, StatsEnumerated::STAT_TOUGHNESS);
		lua_setfield(L, -2, "STAT_TOUGHNESS");

        lua_pushinteger(L, StatsEnumerated::STAT_ASSASSINATION);
        lua_setfield(L, -2, "ASSASSINATION");
		lua_pushinteger(L, StatsEnumerated::STAT_ASSASSINATION);
		lua_setfield(L, -2, "STAT_ASSASSINATION");

        lua_pushinteger(L, StatsEnumerated::STAT_SWIMMING);
        lua_setfield(L, -2, "SWIMMING");
		lua_pushinteger(L, StatsEnumerated::STAT_SWIMMING);
		lua_setfield(L, -2, "STAT_SWIMMING");

        lua_pushinteger(L, StatsEnumerated::STAT_PERCEPTION);
        lua_setfield(L, -2, "PERCEPTION");
		lua_pushinteger(L, StatsEnumerated::STAT_PERCEPTION);
		lua_setfield(L, -2, "STAT_PERCEPTION");

        lua_pushinteger(L, StatsEnumerated::STAT_KATANAS);
        lua_setfield(L, -2, "KATANAS");
        lua_pushinteger(L, StatsEnumerated::STAT_KATANAS);
        lua_setfield(L, -2, "STAT_KATANAS");

        lua_pushinteger(L, StatsEnumerated::STAT_SABRES);
        lua_setfield(L, -2, "SABRES");
        lua_pushinteger(L, StatsEnumerated::STAT_SABRES);
        lua_setfield(L, -2, "STAT_SABRES");

        lua_pushinteger(L, StatsEnumerated::STAT_HACKERS);
        lua_setfield(L, -2, "HACKERS");
        lua_pushinteger(L, StatsEnumerated::STAT_HACKERS);
        lua_setfield(L, -2, "STAT_HACKERS");

        lua_pushinteger(L, StatsEnumerated::STAT_HEAVYWEAPONS);
        lua_setfield(L, -2, "HEAVYWEAPONS");
        lua_pushinteger(L, StatsEnumerated::STAT_HEAVYWEAPONS);
        lua_setfield(L, -2, "STAT_HEAVYWEAPONS");

        lua_pushinteger(L, StatsEnumerated::STAT_BLUNT);
        lua_setfield(L, -2, "BLUNT");
        lua_pushinteger(L, StatsEnumerated::STAT_BLUNT);
        lua_setfield(L, -2, "STAT_BLUNT");

        lua_pushinteger(L, StatsEnumerated::STAT_MARTIALARTS);
        lua_setfield(L, -2, "MARTIALARTS");
        lua_pushinteger(L, StatsEnumerated::STAT_MARTIALARTS);
        lua_setfield(L, -2, "STAT_MARTIALARTS");

        lua_pushinteger(L, StatsEnumerated::STAT_MASSCOMBAT);
        lua_setfield(L, -2, "MASSCOMBAT");
        lua_pushinteger(L, StatsEnumerated::STAT_MASSCOMBAT);
        lua_setfield(L, -2, "STAT_MASSCOMBAT");

        lua_pushinteger(L, StatsEnumerated::STAT_DODGE);
        lua_setfield(L, -2, "DODGE");
        lua_pushinteger(L, StatsEnumerated::STAT_DODGE);
        lua_setfield(L, -2, "STAT_DODGE");

        lua_pushinteger(L, StatsEnumerated::STAT_SURVIVAL);
        lua_setfield(L, -2, "SURVIVAL");
        lua_pushinteger(L, StatsEnumerated::STAT_SURVIVAL);
        lua_setfield(L, -2, "STAT_SURVIVAL");

        lua_pushinteger(L, StatsEnumerated::STAT_POLEARMS);
        lua_setfield(L, -2, "POLEARMS");
        lua_pushinteger(L, StatsEnumerated::STAT_POLEARMS);
        lua_setfield(L, -2, "STAT_POLEARMS");

        lua_pushinteger(L, StatsEnumerated::STAT_CROSSBOWS);
        lua_setfield(L, -2, "CROSSBOWS");
        lua_pushinteger(L, StatsEnumerated::STAT_CROSSBOWS);
        lua_setfield(L, -2, "STAT_CROSSBOWS");

        lua_pushinteger(L, StatsEnumerated::STAT_FRIENDLY_FIRE);
        lua_setfield(L, -2, "FRIENDLY_FIRE");
        lua_pushinteger(L, StatsEnumerated::STAT_FRIENDLY_FIRE);
        lua_setfield(L, -2, "STAT_FRIENDLY_FIRE");

        lua_pushinteger(L, StatsEnumerated::STAT_LOCKPICKING);
        lua_setfield(L, -2, "LOCKPICKING");
        lua_pushinteger(L, StatsEnumerated::STAT_LOCKPICKING);
        lua_setfield(L, -2, "STAT_LOCKPICKING");

        lua_pushinteger(L, StatsEnumerated::STAT_SMITHING_BOW);
        lua_setfield(L, -2, "SMITHING_BOW");
        lua_pushinteger(L, StatsEnumerated::STAT_SMITHING_BOW);
        lua_setfield(L, -2, "STAT_SMITHING_BOW");

        lua_pushinteger(L, StatsEnumerated::STAT_END);
        lua_setfield(L, -2, "END");
        lua_pushinteger(L, StatsEnumerated::STAT_END);
        lua_setfield(L, -2, "STAT_END");

        lua_pushinteger(L, StatsEnumerated::_PrimaryWeaponDamage);
        lua_setfield(L, -2, "PrimaryWeaponDamage");
        lua_pushinteger(L, StatsEnumerated::_PrimaryWeaponDamage);
        lua_setfield(L, -2, "_PrimaryWeaponDamage");

        lua_pushinteger(L, StatsEnumerated::_PrimaryWeaponSpeed);
        lua_setfield(L, -2, "PrimaryWeaponSpeed");
        lua_pushinteger(L, StatsEnumerated::_PrimaryWeaponSpeed);
        lua_setfield(L, -2, "_PrimaryWeaponSpeed");

        lua_pushinteger(L, StatsEnumerated::_SecondaryWeaponDamage);
        lua_setfield(L, -2, "SecondaryWeaponDamage");
        lua_pushinteger(L, StatsEnumerated::_SecondaryWeaponDamage);
        lua_setfield(L, -2, "_SecondaryWeaponDamage");

        lua_pushinteger(L, StatsEnumerated::_SecondaryWeaponSpeed);
        lua_setfield(L, -2, "SecondaryWeaponSpeed");
        lua_pushinteger(L, StatsEnumerated::_SecondaryWeaponSpeed);
        lua_setfield(L, -2, "_SecondaryWeaponSpeed");

        lua_pushinteger(L, StatsEnumerated::_MaxCarryWeight);
        lua_setfield(L, -2, "MaxCarryWeight");
        lua_pushinteger(L, StatsEnumerated::_MaxCarryWeight);
        lua_setfield(L, -2, "_MaxCarryWeight");

        lua_pushinteger(L, StatsEnumerated::_StrengthXPRateWalk);
        lua_setfield(L, -2, "StrengthXPRateWalk");
        lua_pushinteger(L, StatsEnumerated::_StrengthXPRateWalk);
        lua_setfield(L, -2, "_StrengthXPRateWalk");

        lua_pushinteger(L, StatsEnumerated::_StrengthXPRateCombat);
        lua_setfield(L, -2, "StrengthXPRateCombat");
        lua_pushinteger(L, StatsEnumerated::_StrengthXPRateCombat);
        lua_setfield(L, -2, "_StrengthXPRateCombat");

        lua_pushinteger(L, StatsEnumerated::_AttackSpeedHeavyWeapons);
        lua_setfield(L, -2, "AttackSpeedHeavyWeapons");
        lua_pushinteger(L, StatsEnumerated::_AttackSpeedHeavyWeapons);
        lua_setfield(L, -2, "_AttackSpeedHeavyWeapons");

        lua_pushinteger(L, StatsEnumerated::_DamageResistance);
        lua_setfield(L, -2, "DamageResistance");
        lua_pushinteger(L, StatsEnumerated::_DamageResistance);
        lua_setfield(L, -2, "_DamageResistance");

        lua_pushinteger(L, StatsEnumerated::_ToughnessXPRate);
        lua_setfield(L, -2, "ToughnessXPRate");
        lua_pushinteger(L, StatsEnumerated::_ToughnessXPRate);
        lua_setfield(L, -2, "_ToughnessXPRate");

        lua_pushinteger(L, StatsEnumerated::_KnockoutTime);
        lua_setfield(L, -2, "KnockoutTime");
        lua_pushinteger(L, StatsEnumerated::_KnockoutTime);
        lua_setfield(L, -2, "_KnockoutTime");

        lua_pushinteger(L, StatsEnumerated::_ToughnessKnockoutPoint);
        lua_setfield(L, -2, "ToughnessKnockoutPoint");
        lua_pushinteger(L, StatsEnumerated::_ToughnessKnockoutPoint);
        lua_setfield(L, -2, "_ToughnessKnockoutPoint");

        lua_pushinteger(L, StatsEnumerated::_WoundDeteriorationSpeed);
        lua_setfield(L, -2, "WoundDeteriorationSpeed");
        lua_pushinteger(L, StatsEnumerated::_WoundDeteriorationSpeed);
        lua_setfield(L, -2, "_WoundDeteriorationSpeed");

        lua_pushinteger(L, StatsEnumerated::_MaxRunSpeed);
        lua_setfield(L, -2, "MaxRunSpeed");
        lua_pushinteger(L, StatsEnumerated::_MaxRunSpeed);
        lua_setfield(L, -2, "_MaxRunSpeed");

        lua_pushinteger(L, StatsEnumerated::_CurrentRunSpeed);
        lua_setfield(L, -2, "CurrentRunSpeed");
        lua_pushinteger(L, StatsEnumerated::_CurrentRunSpeed);
        lua_setfield(L, -2, "_CurrentRunSpeed");

        lua_pushinteger(L, StatsEnumerated::_AthleticsXPBonus);
        lua_setfield(L, -2, "AthleticsXPBonus");
        lua_pushinteger(L, StatsEnumerated::_AthleticsXPBonus);
        lua_setfield(L, -2, "_AthleticsXPBonus");

        lua_pushinteger(L, StatsEnumerated::_TurretAccuracy);
        lua_setfield(L, -2, "TurretAccuracy");
        lua_pushinteger(L, StatsEnumerated::_TurretAccuracy);
        lua_setfield(L, -2, "_TurretAccuracy");

        lua_pushinteger(L, StatsEnumerated::_TurretRateOfFire);
        lua_setfield(L, -2, "TurretRateOfFire");
        lua_pushinteger(L, StatsEnumerated::_TurretRateOfFire);
        lua_setfield(L, -2, "_TurretRateOfFire");

        lua_pushinteger(L, StatsEnumerated::_TurretFriendlyFireAvoidance);
        lua_setfield(L, -2, "TurretFriendlyFireAvoidance");
        lua_pushinteger(L, StatsEnumerated::_TurretFriendlyFireAvoidance);
        lua_setfield(L, -2, "_TurretFriendlyFireAvoidance");

        lua_pushinteger(L, StatsEnumerated::_BuildingRate);
        lua_setfield(L, -2, "BuildingRate");
        lua_pushinteger(L, StatsEnumerated::_BuildingRate);
        lua_setfield(L, -2, "_BuildingRate");

        lua_pushinteger(L, StatsEnumerated::_RepairingRate);
        lua_setfield(L, -2, "RepairingRate");
        lua_pushinteger(L, StatsEnumerated::_RepairingRate);
        lua_setfield(L, -2, "_RepairingRate");

        lua_pushinteger(L, StatsEnumerated::_Mining);
        lua_setfield(L, -2, "Mining");
        lua_pushinteger(L, StatsEnumerated::_Mining);
        lua_setfield(L, -2, "_Mining");

        lua_pushinteger(L, StatsEnumerated::_Farming);
        lua_setfield(L, -2, "Farming");
        lua_pushinteger(L, StatsEnumerated::_Farming);
        lua_setfield(L, -2, "_Farming");

        lua_pushinteger(L, StatsEnumerated::_UsingMachinery);
        lua_setfield(L, -2, "UsingMachinery");
        lua_pushinteger(L, StatsEnumerated::_UsingMachinery);
        lua_setfield(L, -2, "_UsingMachinery");

        lua_pushinteger(L, StatsEnumerated::_encumbrance);
        lua_setfield(L, -2, "Encumbrance");
        lua_pushinteger(L, StatsEnumerated::_encumbrance);
        lua_setfield(L, -2, "encumbrance");
        lua_pushinteger(L, StatsEnumerated::_encumbrance);
        lua_setfield(L, -2, "_encumbrance");

        lua_pushinteger(L, StatsEnumerated::_combatSpeed);
        lua_setfield(L, -2, "CombatSpeed");
        lua_pushinteger(L, StatsEnumerated::_combatSpeed);
        lua_setfield(L, -2, "combatSpeed");
        lua_pushinteger(L, StatsEnumerated::_combatSpeed);
        lua_setfield(L, -2, "_combatSpeed");


        lua_setglobal(L, "StatsEnumerated");
        lua_setglobal(L, "Stats");
    }

    void EnumsEnumBinding::registerEventTriggerEnum(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "EV_NONE", EventTriggerEnum::EV_NONE);
        setEnum(L, "NONE", EventTriggerEnum::EV_NONE);

        setEnum(L, "EV_PLAYER_TALK_TO_ME", EventTriggerEnum::EV_PLAYER_TALK_TO_ME);
        setEnum(L, "PLAYER_TALK_TO_ME", EventTriggerEnum::EV_PLAYER_TALK_TO_ME);

        setEnum(L, "EV_ANNOUNCEMENT", EventTriggerEnum::EV_ANNOUNCEMENT);
        setEnum(L, "ANNOUNCEMENT", EventTriggerEnum::EV_ANNOUNCEMENT);

        setEnum(L, "EV_I_SEE_NEUTRAL_SQUAD", EventTriggerEnum::EV_I_SEE_NEUTRAL_SQUAD);
        setEnum(L, "I_SEE_NEUTRAL_SQUAD", EventTriggerEnum::EV_I_SEE_NEUTRAL_SQUAD);

        setEnum(L, "EV_I_SEE_RAGDOLL", EventTriggerEnum::EV_I_SEE_RAGDOLL);
        setEnum(L, "I_SEE_RAGDOLL", EventTriggerEnum::EV_I_SEE_RAGDOLL);

        setEnum(L, "EV_______", EventTriggerEnum::EV_______);
        setEnum(L, "______", EventTriggerEnum::EV_______);

        setEnum(L, "EV_I_________", EventTriggerEnum::EV_I_________);
        setEnum(L, "I_________", EventTriggerEnum::EV_I_________);

        setEnum(L, "EV_SHOO_FROM_MY_BUILDING", EventTriggerEnum::EV_SHOO_FROM_MY_BUILDING);
        setEnum(L, "SHOO_FROM_MY_BUILDING", EventTriggerEnum::EV_SHOO_FROM_MY_BUILDING);

        setEnum(L, "EV_MARKED_FOR_DEATH", EventTriggerEnum::EV_MARKED_FOR_DEATH);
        setEnum(L, "MARKED_FOR_DEATH", EventTriggerEnum::EV_MARKED_FOR_DEATH);

        setEnum(L, "EV_SCREAMING_TORTURE", EventTriggerEnum::EV_SCREAMING_TORTURE);
        setEnum(L, "SCREAMING_TORTURE", EventTriggerEnum::EV_SCREAMING_TORTURE);

        setEnum(L, "EV_BAR_TALK", EventTriggerEnum::EV_BAR_TALK);
        setEnum(L, "BAR_TALK", EventTriggerEnum::EV_BAR_TALK);

        setEnum(L, "EV_UNLOCK_MY_CAGE_OR_SHACKLES", EventTriggerEnum::EV_UNLOCK_MY_CAGE_OR_SHACKLES);
        setEnum(L, "UNLOCK_MY_CAGE_OR_SHACKLES", EventTriggerEnum::EV_UNLOCK_MY_CAGE_OR_SHACKLES);

        setEnum(L, "EV_UNLOCK_MY_CAGE_ATTEMPT", EventTriggerEnum::EV_UNLOCK_MY_CAGE_ATTEMPT);
        setEnum(L, "UNLOCK_MY_CAGE_ATTEMPT", EventTriggerEnum::EV_UNLOCK_MY_CAGE_ATTEMPT);

        setEnum(L, "EV_I_DEFEATED_SQUAD", EventTriggerEnum::EV_I_DEFEATED_SQUAD);
        setEnum(L, "I_DEFEATED_SQUAD", EventTriggerEnum::EV_I_DEFEATED_SQUAD);

        setEnum(L, "EV_LAUNCH_ATTACK", EventTriggerEnum::EV_LAUNCH_ATTACK);
        setEnum(L, "LAUNCH_ATTACK", EventTriggerEnum::EV_LAUNCH_ATTACK);

        setEnum(L, "EV_INTRUDER_FOUND", EventTriggerEnum::EV_INTRUDER_FOUND);
        setEnum(L, "INTRUDER_FOUND", EventTriggerEnum::EV_INTRUDER_FOUND);

        setEnum(L, "EV_HEALING_OTHER_START", EventTriggerEnum::EV_HEALING_OTHER_START);
        setEnum(L, "HEALING_OTHER_START", EventTriggerEnum::EV_HEALING_OTHER_START);

        setEnum(L, "EV_BEING_HEALED_START", EventTriggerEnum::EV_BEING_HEALED_START);
        setEnum(L, "BEING_HEALED_START", EventTriggerEnum::EV_BEING_HEALED_START);

        setEnum(L, "EV_HEALING_OTHER_FINISHED", EventTriggerEnum::EV_HEALING_OTHER_FINISHED);
        setEnum(L, "HEALING_OTHER_FINISHED", EventTriggerEnum::EV_HEALING_OTHER_FINISHED);

        setEnum(L, "EV_BEING_HEALED_FINISHED", EventTriggerEnum::EV_BEING_HEALED_FINISHED);
        setEnum(L, "BEING_HEALED_FINISHED", EventTriggerEnum::EV_BEING_HEALED_FINISHED);

        setEnum(L, "EV_FIRSTAID_KIT_EMPTY", EventTriggerEnum::EV_FIRSTAID_KIT_EMPTY);
        setEnum(L, "FIRSTAID_KIT_EMPTY", EventTriggerEnum::EV_FIRSTAID_KIT_EMPTY);

        setEnum(L, "EV_GET_UP_PEACE", EventTriggerEnum::EV_GET_UP_PEACE);
        setEnum(L, "GET_UP_PEACE", EventTriggerEnum::EV_GET_UP_PEACE);

        setEnum(L, "EV_GET_UP_FIGHT", EventTriggerEnum::EV_GET_UP_FIGHT);
        setEnum(L, "GET_UP_FIGHT", EventTriggerEnum::EV_GET_UP_FIGHT);

        setEnum(L, "EV_GET_UP_UNNECCESSARY_FIGHT", EventTriggerEnum::EV_GET_UP_UNNECCESSARY_FIGHT);
        setEnum(L, "GET_UP_UNNECCESSARY_FIGHT", EventTriggerEnum::EV_GET_UP_UNNECCESSARY_FIGHT);

        setEnum(L, "EV_HARRASSMENT_SHOUTS", EventTriggerEnum::EV_HARRASSMENT_SHOUTS);
        setEnum(L, "HARRASSMENT_SHOUTS", EventTriggerEnum::EV_HARRASSMENT_SHOUTS);

        setEnum(L, "EV_I_SEE_ANIMAL_SQUAD", EventTriggerEnum::EV_I_SEE_ANIMAL_SQUAD);
        setEnum(L, "I_SEE_ANIMAL_SQUAD", EventTriggerEnum::EV_I_SEE_ANIMAL_SQUAD);

        setEnum(L, "EV_SPEECH_INTERRUPTED_ATTACKED_BY_TARGET", EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_TARGET);
        setEnum(L, "SPEECH_INTERRUPTED_ATTACKED_BY_TARGET", EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_TARGET);

        setEnum(L, "EV_SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS", EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS);
        setEnum(L, "SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS", EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS);

        setEnum(L, "EV_CONTRACT_JOB_ENDED", EventTriggerEnum::EV_CONTRACT_JOB_ENDED);
        setEnum(L, "CONTRACT_JOB_ENDED", EventTriggerEnum::EV_CONTRACT_JOB_ENDED);

        setEnum(L, "EV_BETRAYAL", EventTriggerEnum::EV_BETRAYAL);
        setEnum(L, "BETRAYAL", EventTriggerEnum::EV_BETRAYAL);

        setEnum(L, "EV_LOOTING_WEAPON_ONLY", EventTriggerEnum::EV_LOOTING_WEAPON_ONLY);
        setEnum(L, "LOOTING_WEAPON_ONLY", EventTriggerEnum::EV_LOOTING_WEAPON_ONLY);

        setEnum(L, "EV_LOOTING_EVERYTHING", EventTriggerEnum::EV_LOOTING_EVERYTHING);
        setEnum(L, "LOOTING_EVERYTHING", EventTriggerEnum::EV_LOOTING_EVERYTHING);

        setEnum(L, "EV_I_SEE_UNIFORM_IMPOSTER", EventTriggerEnum::EV_I_SEE_UNIFORM_IMPOSTER);
        setEnum(L, "I_SEE_UNIFORM_IMPOSTER", EventTriggerEnum::EV_I_SEE_UNIFORM_IMPOSTER);

        setEnum(L, "EV_INTRODUCING_NEW_SLAVE", EventTriggerEnum::EV_INTRODUCING_NEW_SLAVE);
        setEnum(L, "INTRODUCING_NEW_SLAVE", EventTriggerEnum::EV_INTRODUCING_NEW_SLAVE);

        setEnum(L, "EV_ESCAPING_SLAVE_SPOTTED", EventTriggerEnum::EV_ESCAPING_SLAVE_SPOTTED);
        setEnum(L, "ESCAPING_SLAVE_SPOTTED", EventTriggerEnum::EV_ESCAPING_SLAVE_SPOTTED);

        setEnum(L, "EV_RECAPTURED_A_SLAVE", EventTriggerEnum::EV_RECAPTURED_A_SLAVE);
        setEnum(L, "RECAPTURED_A_SLAVE", EventTriggerEnum::EV_RECAPTURED_A_SLAVE);

        setEnum(L, "EV_SHOUT_AT_SLAVE_WORKER", EventTriggerEnum::EV_SHOUT_AT_SLAVE_WORKER);
        setEnum(L, "SHOUT_AT_SLAVE_WORKER", EventTriggerEnum::EV_SHOUT_AT_SLAVE_WORKER);

        setEnum(L, "EV_SLAVE_DELIVERY", EventTriggerEnum::EV_SLAVE_DELIVERY);
        setEnum(L, "SLAVE_DELIVERY", EventTriggerEnum::EV_SLAVE_DELIVERY);

        setEnum(L, "EV_ESCAPED_EX_SLAVE_SPOTTED", EventTriggerEnum::EV_ESCAPED_EX_SLAVE_SPOTTED);
        setEnum(L, "ESCAPED_EX_SLAVE_SPOTTED", EventTriggerEnum::EV_ESCAPED_EX_SLAVE_SPOTTED);

        setEnum(L, "EV_WITNESS_GENERIC_ASSAULT", EventTriggerEnum::EV_WITNESS_GENERIC_ASSAULT);
        setEnum(L, "WITNESS_GENERIC_ASSAULT", EventTriggerEnum::EV_WITNESS_GENERIC_ASSAULT);

        setEnum(L, "EV_WITNESS_LOOTING_ALLY", EventTriggerEnum::EV_WITNESS_LOOTING_ALLY);
        setEnum(L, "WITNESS_LOOTING_ALLY", EventTriggerEnum::EV_WITNESS_LOOTING_ALLY);

        setEnum(L, "EV_WITNESS_THIEF_OR_LOCKPICK", EventTriggerEnum::EV_WITNESS_THIEF_OR_LOCKPICK);
        setEnum(L, "WITNESS_THIEF_OR_LOCKPICK", EventTriggerEnum::EV_WITNESS_THIEF_OR_LOCKPICK);

        setEnum(L, "EV_BOUNTY_SPOTTED", EventTriggerEnum::EV_BOUNTY_SPOTTED);
        setEnum(L, "BOUNTY_SPOTTED", EventTriggerEnum::EV_BOUNTY_SPOTTED);

        setEnum(L, "EV_ESCAPED_PRISONER_SPOTTED", EventTriggerEnum::EV_ESCAPED_PRISONER_SPOTTED);
        setEnum(L, "ESCAPED_PRISONER_SPOTTED", EventTriggerEnum::EV_ESCAPED_PRISONER_SPOTTED);

        setEnum(L, "EV_PRISONER_FREE_TO_GO", EventTriggerEnum::EV_PRISONER_FREE_TO_GO);
        setEnum(L, "PRISONER_FREE_TO_GO", EventTriggerEnum::EV_PRISONER_FREE_TO_GO);

        setEnum(L, "EV_ALMOST_WOKE_UP", EventTriggerEnum::EV_ALMOST_WOKE_UP);
        setEnum(L, "ALMOST_WOKE_UP", EventTriggerEnum::EV_ALMOST_WOKE_UP);

        setEnum(L, "EV_ENTER_BIOME", EventTriggerEnum::EV_ENTER_BIOME);
        setEnum(L, "ENTER_BIOME", EventTriggerEnum::EV_ENTER_BIOME);

        setEnum(L, "EV_ENTER_TOWN", EventTriggerEnum::EV_ENTER_TOWN);
        setEnum(L, "ENTER_TOWN", EventTriggerEnum::EV_ENTER_TOWN);

        setEnum(L, "EV_SQUAD_BROKEN", EventTriggerEnum::EV_SQUAD_BROKEN);
        setEnum(L, "SQUAD_BROKEN", EventTriggerEnum::EV_SQUAD_BROKEN);

        setEnum(L, "EV_BOUGHT_ME_FROM_SLAVERY", EventTriggerEnum::EV_BOUGHT_ME_FROM_SLAVERY);
        setEnum(L, "BOUGHT_ME_FROM_SLAVERY", EventTriggerEnum::EV_BOUGHT_ME_FROM_SLAVERY);

        setEnum(L, "EV_EATING_SOMETHING_SOUNDS", EventTriggerEnum::EV_EATING_SOMETHING_SOUNDS);
        setEnum(L, "EATING_SOMETHING_SOUNDS", EventTriggerEnum::EV_EATING_SOMETHING_SOUNDS);

        setEnum(L, "EV_WORSHIPING_SOMETHING", EventTriggerEnum::EV_WORSHIPING_SOMETHING);
        setEnum(L, "WORSHIPING_SOMETHING", EventTriggerEnum::EV_WORSHIPING_SOMETHING);

        setEnum(L, "EV_SLAVE_ESCAPE_OPPORTUNITY_SAVIOR", EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_SAVIOR);
        setEnum(L, "SLAVE_ESCAPE_OPPORTUNITY_SAVIOR", EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_SAVIOR);

        setEnum(L, "EV_SLAVE_ESCAPE_OPPORTUNITY_ALONE", EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_ALONE);
        setEnum(L, "SLAVE_ESCAPE_OPPORTUNITY_ALONE", EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_ALONE);

        setEnum(L, "EV_ASSASSINATION_FAILED", EventTriggerEnum::EV_ASSASSINATION_FAILED);
        setEnum(L, "ASSASSINATION_FAILED", EventTriggerEnum::EV_ASSASSINATION_FAILED);

        setEnum(L, "EV_EATING_MY_CROPS", EventTriggerEnum::EV_EATING_MY_CROPS);
        setEnum(L, "EATING_MY_CROPS", EventTriggerEnum::EV_EATING_MY_CROPS);

        setEnum(L, "EV_KIDNAPPING_MY_ALLY", EventTriggerEnum::EV_KIDNAPPING_MY_ALLY);
        setEnum(L, "KIDNAPPING_MY_ALLY", EventTriggerEnum::EV_KIDNAPPING_MY_ALLY);

        setEnum(L, "EV_USING_MY_TRAINING_EQUIPMENT", EventTriggerEnum::EV_USING_MY_TRAINING_EQUIPMENT);
        setEnum(L, "USING_MY_TRAINING_EQUIPMENT", EventTriggerEnum::EV_USING_MY_TRAINING_EQUIPMENT);

        setEnum(L, "EV_GIVE_UP_CHASE", EventTriggerEnum::EV_GIVE_UP_CHASE);
        setEnum(L, "GIVE_UP_CHASE", EventTriggerEnum::EV_GIVE_UP_CHASE);

        setEnum(L, "EV_ACID_FEET", EventTriggerEnum::EV_ACID_FEET);
        setEnum(L, "ACID_FEET", EventTriggerEnum::EV_ACID_FEET);

        setEnum(L, "EV_ACID_RAIN", EventTriggerEnum::EV_ACID_RAIN);
        setEnum(L, "ACID_RAIN", EventTriggerEnum::EV_ACID_RAIN);

        setEnum(L, "EV_ACID_WATER", EventTriggerEnum::EV_ACID_WATER);
        setEnum(L, "ACID_WATER", EventTriggerEnum::EV_ACID_WATER);

        setEnum(L, "EV_WINDY", EventTriggerEnum::EV_WINDY);
        setEnum(L, "WINDY", EventTriggerEnum::EV_WINDY);

        setEnum(L, "EV_POISON_GAS", EventTriggerEnum::EV_POISON_GAS);
        setEnum(L, "POISON_GAS", EventTriggerEnum::EV_POISON_GAS);

        setEnum(L, "EV_I_SEE_ENEMY_PLAYER", EventTriggerEnum::EV_I_SEE_ENEMY_PLAYER);
        setEnum(L, "I_SEE_ENEMY_PLAYER", EventTriggerEnum::EV_I_SEE_ENEMY_PLAYER);

        setEnum(L, "EV_I_SEE_ALLY_PLAYER", EventTriggerEnum::EV_I_SEE_ALLY_PLAYER);
        setEnum(L, "I_SEE_ALLY_PLAYER", EventTriggerEnum::EV_I_SEE_ALLY_PLAYER);

        setEnum(L, "EV_I_SEE_ILLEGAL_PLAYER_BUILDING", EventTriggerEnum::EV_I_SEE_ILLEGAL_PLAYER_BUILDING);
        setEnum(L, "I_SEE_ILLEGAL_PLAYER_BUILDING", EventTriggerEnum::EV_I_SEE_ILLEGAL_PLAYER_BUILDING);

        setEnum(L, "EV_BURNING", EventTriggerEnum::EV_BURNING);
        setEnum(L, "BURNING", EventTriggerEnum::EV_BURNING);

        setEnum(L, "EV_LOST_LEG", EventTriggerEnum::EV_LOST_LEG);
        setEnum(L, "LOST_LEG", EventTriggerEnum::EV_LOST_LEG);

        setEnum(L, "EV_LOST_ARM", EventTriggerEnum::EV_LOST_ARM);
        setEnum(L, "LOST_ARM", EventTriggerEnum::EV_LOST_ARM);

        setEnum(L, "EV_I_SEE_PLAYER_NICE_BUILDING", EventTriggerEnum::EV_I_SEE_PLAYER_NICE_BUILDING);
        setEnum(L, "I_SEE_PLAYER_NICE_BUILDING", EventTriggerEnum::EV_I_SEE_PLAYER_NICE_BUILDING);

        setEnum(L, "EV_TAKEN_OVER_PLAYER_TOWN", EventTriggerEnum::EV_TAKEN_OVER_PLAYER_TOWN);
        setEnum(L, "TAKEN_OVER_PLAYER_TOWN", EventTriggerEnum::EV_TAKEN_OVER_PLAYER_TOWN);

        setEnum(L, "EV_CROWD_TRIGGERED", EventTriggerEnum::EV_CROWD_TRIGGERED);
        setEnum(L, "CROWD_TRIGGERED", EventTriggerEnum::EV_CROWD_TRIGGERED);

        setEnum(L, "EV_MAX", EventTriggerEnum::EV_MAX);
        setEnum(L, "MAX", EventTriggerEnum::EV_MAX);

        lua_setglobal(L, "EventTriggerEnum");
        lua_setglobal(L, "EventTrigger");
    }

    void EnumsEnumBinding::registerDialogConditionEnum(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, DialogConditionEnum::DC_NONE);
        lua_setfield(L, -2, "DC_NONE");
        lua_pushinteger(L, DialogConditionEnum::DC_NONE);
        lua_setfield(L, -2, "NONE");

        lua_pushinteger(L, DialogConditionEnum::DC_RELATIONS);
        lua_setfield(L, -2, "DC_RELATIONS");
        lua_pushinteger(L, DialogConditionEnum::DC_RELATIONS);
        lua_setfield(L, -2, "RELATIONS");

        lua_pushinteger(L, DialogConditionEnum::DC_PLAYERMONEY);
        lua_setfield(L, -2, "DC_PLAYERMONEY");
        lua_pushinteger(L, DialogConditionEnum::DC_PLAYERMONEY);
        lua_setfield(L, -2, "PLAYERMONEY");

        lua_pushinteger(L, DialogConditionEnum::DC_REPUTATION);
        lua_setfield(L, -2, "DC_REPUTATION");
        lua_pushinteger(L, DialogConditionEnum::DC_REPUTATION);
        lua_setfield(L, -2, "REPUTATION");

        lua_pushinteger(L, DialogConditionEnum::DC_CARRYING_BOUNTY_ALIVE);
        lua_setfield(L, -2, "DC_CARRYING_BOUNTY_ALIVE");
        lua_pushinteger(L, DialogConditionEnum::DC_CARRYING_BOUNTY_ALIVE);
        lua_setfield(L, -2, "CARRYING_BOUNTY_ALIVE");

        lua_pushinteger(L, DialogConditionEnum::DC_CARRYING_BOUNTY_DEAD);
        lua_setfield(L, -2, "DC_CARRYING_BOUNTY_DEAD");
        lua_pushinteger(L, DialogConditionEnum::DC_CARRYING_BOUNTY_DEAD);
        lua_setfield(L, -2, "CARRYING_BOUNTY_DEAD");

        lua_pushinteger(L, DialogConditionEnum::DC_FACTION_VARIABLE);
        lua_setfield(L, -2, "DC_FACTION_VARIABLE");
        lua_pushinteger(L, DialogConditionEnum::DC_FACTION_VARIABLE);
        lua_setfield(L, -2, "FACTION_VARIABLE");

        lua_pushinteger(L, DialogConditionEnum::DC_IMPRISONED_BY_TARGET);
        lua_setfield(L, -2, "DC_IMPRISONED_BY_TARGET");
        lua_pushinteger(L, DialogConditionEnum::DC_IMPRISONED_BY_TARGET);
        lua_setfield(L, -2, "IMPRISONED_BY_TARGET");

        lua_pushinteger(L, DialogConditionEnum::DC_IMPRISONED_BY_OTHER);
        lua_setfield(L, -2, "DC_IMPRISONED_BY_OTHER");
        lua_pushinteger(L, DialogConditionEnum::DC_IMPRISONED_BY_OTHER);
        lua_setfield(L, -2, "IMPRISONED_BY_OTHER");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_A_TRADER);
        lua_setfield(L, -2, "DC_IS_A_TRADER");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_A_TRADER);
        lua_setfield(L, -2, "IS_A_TRADER");

        lua_pushinteger(L, DialogConditionEnum::DC_FACTION_RANK);
        lua_setfield(L, -2, "DC_FACTION_RANK");
        lua_pushinteger(L, DialogConditionEnum::DC_FACTION_RANK);
        lua_setfield(L, -2, "FACTION_RANK");

        lua_pushinteger(L, DialogConditionEnum::DC_BUILDING_IS_CLOSED_AND_SECURED);
        lua_setfield(L, -2, "DC_BUILDING_IS_CLOSED_AND_SECURED");
        lua_pushinteger(L, DialogConditionEnum::DC_BUILDING_IS_CLOSED_AND_SECURED);
        lua_setfield(L, -2, "BUILDING_IS_CLOSED_AND_SECURED");

        lua_pushinteger(L, DialogConditionEnum::DC_PLAYER_TECH_LEVEL);
        lua_setfield(L, -2, "DC_PLAYER_TECH_LEVEL");
        lua_pushinteger(L, DialogConditionEnum::DC_PLAYER_TECH_LEVEL);
        lua_setfield(L, -2, "PLAYER_TECH_LEVEL");

        lua_pushinteger(L, DialogConditionEnum::DC_NUM_DIALOG_EVENT_REPEATS);
        lua_setfield(L, -2, "DC_NUM_DIALOG_EVENT_REPEATS");
        lua_pushinteger(L, DialogConditionEnum::DC_NUM_DIALOG_EVENT_REPEATS);
        lua_setfield(L, -2, "NUM_DIALOG_EVENT_REPEATS");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_IMPRISONED);
        lua_setfield(L, -2, "DC_IS_IMPRISONED");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_IMPRISONED);
        lua_setfield(L, -2, "IS_IMPRISONED");

        lua_pushinteger(L, DialogConditionEnum::DC_IMPRISONMENT_IS_DEATHROW);
        lua_setfield(L, -2, "DC_IMPRISONMENT_IS_DEATHROW");
        lua_pushinteger(L, DialogConditionEnum::DC_IMPRISONMENT_IS_DEATHROW);
        lua_setfield(L, -2, "IMPRISONMENT_IS_DEATHROW");

        lua_pushinteger(L, DialogConditionEnum::DC_TARGET_IN_TALKING_RANGE);
        lua_setfield(L, -2, "DC_TARGET_IN_TALKING_RANGE");
        lua_pushinteger(L, DialogConditionEnum::DC_TARGET_IN_TALKING_RANGE);
        lua_setfield(L, -2, "TARGET_IN_TALKING_RANGE");

        lua_pushinteger(L, DialogConditionEnum::DC_IN_MY_BUILDING);
        lua_setfield(L, -2, "DC_IN_MY_BUILDING");
        lua_pushinteger(L, DialogConditionEnum::DC_IN_MY_BUILDING);
        lua_setfield(L, -2, "IN_MY_BUILDING");

        lua_pushinteger(L, DialogConditionEnum::DC_TARGET_LAST_SEEN_X_HOURS_AGO);
        lua_setfield(L, -2, "DC_TARGET_LAST_SEEN_X_HOURS_AGO");
        lua_pushinteger(L, DialogConditionEnum::DC_TARGET_LAST_SEEN_X_HOURS_AGO);
        lua_setfield(L, -2, "TARGET_LAST_SEEN_X_HOURS_AGO");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_LEADER);
        lua_setfield(L, -2, "DC_IS_LEADER");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_LEADER);
        lua_setfield(L, -2, "IS_LEADER");

        lua_pushinteger(L, DialogConditionEnum::DC_MET_TARGET_BEFORE);
        lua_setfield(L, -2, "DC_MET_TARGET_BEFORE");
        lua_pushinteger(L, DialogConditionEnum::DC_MET_TARGET_BEFORE);
        lua_setfield(L, -2, "MET_TARGET_BEFORE");

        lua_pushinteger(L, DialogConditionEnum::DC_WEAKER_THAN_ME);
        lua_setfield(L, -2, "DC_WEAKER_THAN_ME");
        lua_pushinteger(L, DialogConditionEnum::DC_WEAKER_THAN_ME);
        lua_setfield(L, -2, "WEAKER_THAN_ME");

        lua_pushinteger(L, DialogConditionEnum::DC_STRONGER_THAN_ME);
        lua_setfield(L, -2, "DC_STRONGER_THAN_ME");
        lua_pushinteger(L, DialogConditionEnum::DC_STRONGER_THAN_ME);
        lua_setfield(L, -2, "STRONGER_THAN_ME");

        lua_pushinteger(L, DialogConditionEnum::DC_HAS_TAG);
        lua_setfield(L, -2, "DC_HAS_TAG");
        lua_pushinteger(L, DialogConditionEnum::DC_HAS_TAG);
        lua_setfield(L, -2, "HAS_TAG");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_ALLY);
        lua_setfield(L, -2, "DC_IS_ALLY");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_ALLY);
        lua_setfield(L, -2, "IS_ALLY");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_ENEMY);
        lua_setfield(L, -2, "DC_IS_ENEMY");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_ENEMY);
        lua_setfield(L, -2, "IS_ENEMY");

        lua_pushinteger(L, DialogConditionEnum::DC_PERSONALITY_TAG);
        lua_setfield(L, -2, "DC_PERSONALITY_TAG");
        lua_pushinteger(L, DialogConditionEnum::DC_PERSONALITY_TAG);
        lua_setfield(L, -2, "PERSONALITY_TAG");

        lua_pushinteger(L, DialogConditionEnum::DC_BROKEN_LEG);
        lua_setfield(L, -2, "DC_BROKEN_LEG");
        lua_pushinteger(L, DialogConditionEnum::DC_BROKEN_LEG);
        lua_setfield(L, -2, "BROKEN_LEG");

        lua_pushinteger(L, DialogConditionEnum::DC_BROKEN_ARM);
        lua_setfield(L, -2, "DC_BROKEN_ARM");
        lua_pushinteger(L, DialogConditionEnum::DC_BROKEN_ARM);
        lua_setfield(L, -2, "BROKEN_ARM");

        lua_pushinteger(L, DialogConditionEnum::DC_DAMAGED_HEAD);
        lua_setfield(L, -2, "DC_DAMAGED_HEAD");
        lua_pushinteger(L, DialogConditionEnum::DC_DAMAGED_HEAD);
        lua_setfield(L, -2, "DAMAGED_HEAD");

        lua_pushinteger(L, DialogConditionEnum::DC_NEARLY_KO);
        lua_setfield(L, -2, "DC_NEARLY_KO");
        lua_pushinteger(L, DialogConditionEnum::DC_NEARLY_KO);
        lua_setfield(L, -2, "NEARLY_KO");

        lua_pushinteger(L, DialogConditionEnum::DC_IN_A_NON_PLAYER_TOWN);
        lua_setfield(L, -2, "DC_IN_A_NON_PLAYER_TOWN");
        lua_pushinteger(L, DialogConditionEnum::DC_IN_A_NON_PLAYER_TOWN);
        lua_setfield(L, -2, "IN_A_NON_PLAYER_TOWN");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_RUNNING);
        lua_setfield(L, -2, "DC_IS_RUNNING");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_RUNNING);
        lua_setfield(L, -2, "IS_RUNNING");

        lua_pushinteger(L, DialogConditionEnum::DC_COPS_AROUND);
        lua_setfield(L, -2, "DC_COPS_AROUND");
        lua_pushinteger(L, DialogConditionEnum::DC_COPS_AROUND);
        lua_setfield(L, -2, "COPS_AROUND");

        lua_pushinteger(L, DialogConditionEnum::DC_SQUAD_SIZE);
        lua_setfield(L, -2, "DC_SQUAD_SIZE");
        lua_pushinteger(L, DialogConditionEnum::DC_SQUAD_SIZE);
        lua_setfield(L, -2, "SQUAD_SIZE");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_PLAYER);
        lua_setfield(L, -2, "DC_IS_PLAYER");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_PLAYER);
        lua_setfield(L, -2, "IS_PLAYER");

        lua_pushinteger(L, DialogConditionEnum::DC_NUM_BACKPACKS);
        lua_setfield(L, -2, "DC_NUM_BACKPACKS");
        lua_pushinteger(L, DialogConditionEnum::DC_NUM_BACKPACKS);
        lua_setfield(L, -2, "NUM_BACKPACKS");

        lua_pushinteger(L, DialogConditionEnum::DC_SQUAD_ONLY_ANIMALS);
        lua_setfield(L, -2, "DC_SQUAD_ONLY_ANIMALS");
        lua_pushinteger(L, DialogConditionEnum::DC_SQUAD_ONLY_ANIMALS);
        lua_setfield(L, -2, "SQUAD_ONLY_ANIMALS");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_OUTNUMBERED);
        lua_setfield(L, -2, "DC_IS_OUTNUMBERED");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_OUTNUMBERED);
        lua_setfield(L, -2, "IS_OUTNUMBERED");

        lua_pushinteger(L, DialogConditionEnum::DC_BOUNTY_AMOUNT_PERCEIVED);
        lua_setfield(L, -2, "DC_BOUNTY_AMOUNT_PERCEIVED");
        lua_pushinteger(L, DialogConditionEnum::DC_BOUNTY_AMOUNT_PERCEIVED);
        lua_setfield(L, -2, "BOUNTY_AMOUNT_PERCEIVED");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_KO);
        lua_setfield(L, -2, "DC_IS_KO");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_KO);
        lua_setfield(L, -2, "IS_KO");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_NEARLY_KO);
        lua_setfield(L, -2, "DC_IS_NEARLY_KO");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_NEARLY_KO);
        lua_setfield(L, -2, "IS_NEARLY_KO");

        lua_pushinteger(L, DialogConditionEnum::DC_SQUAD_IS_DOWN);
        lua_setfield(L, -2, "DC_SQUAD_IS_DOWN");
        lua_pushinteger(L, DialogConditionEnum::DC_SQUAD_IS_DOWN);
        lua_setfield(L, -2, "SQUAD_IS_DOWN");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_DEAD);
        lua_setfield(L, -2, "DC_IS_DEAD");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_DEAD);
        lua_setfield(L, -2, "IS_DEAD");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_FEMALE);
        lua_setfield(L, -2, "DC_IS_FEMALE");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_FEMALE);
        lua_setfield(L, -2, "IS_FEMALE");

        lua_pushinteger(L, DialogConditionEnum::DC_CARRYING_SOMEONE_TO_ENSLAVE);
        lua_setfield(L, -2, "DC_CARRYING_SOMEONE_TO_ENSLAVE");
        lua_pushinteger(L, DialogConditionEnum::DC_CARRYING_SOMEONE_TO_ENSLAVE);
        lua_setfield(L, -2, "CARRYING_SOMEONE_TO_ENSLAVE");

        lua_pushinteger(L, DialogConditionEnum::DC_BOUNTY_AMOUNT_ACTUAL);
        lua_setfield(L, -2, "DC_BOUNTY_AMOUNT_ACTUAL");
        lua_pushinteger(L, DialogConditionEnum::DC_BOUNTY_AMOUNT_ACTUAL);
        lua_setfield(L, -2, "BOUNTY_AMOUNT_ACTUAL");

        lua_pushinteger(L, DialogConditionEnum::DC_IM_UNARMED);
        lua_setfield(L, -2, "DC_IM_UNARMED");
        lua_pushinteger(L, DialogConditionEnum::DC_IM_UNARMED);
        lua_setfield(L, -2, "IM_UNARMED");

        lua_pushinteger(L, DialogConditionEnum::DC_TOWN_HAS_FORTIFICATIONS_WALLS);
        lua_setfield(L, -2, "DC_TOWN_HAS_FORTIFICATIONS_WALLS");
        lua_pushinteger(L, DialogConditionEnum::DC_TOWN_HAS_FORTIFICATIONS_WALLS);
        lua_setfield(L, -2, "TOWN_HAS_FORTIFICATIONS_WALLS");

        lua_pushinteger(L, DialogConditionEnum::DC_TARGET_IS_MY_MISSION_TARGET);
        lua_setfield(L, -2, "DC_TARGET_IS_MY_MISSION_TARGET");
        lua_pushinteger(L, DialogConditionEnum::DC_TARGET_IS_MY_MISSION_TARGET);
        lua_setfield(L, -2, "TARGET_IS_MY_MISSION_TARGET");

        lua_pushinteger(L, DialogConditionEnum::DC_MY_MISSION_IS_FRIENDLY);
        lua_setfield(L, -2, "DC_MY_MISSION_IS_FRIENDLY");
        lua_pushinteger(L, DialogConditionEnum::DC_MY_MISSION_IS_FRIENDLY);
        lua_setfield(L, -2, "MY_MISSION_IS_FRIENDLY");

        lua_pushinteger(L, DialogConditionEnum::DC_I_LOVE_THIS_GUY);
        lua_setfield(L, -2, "DC_I_LOVE_THIS_GUY");
        lua_pushinteger(L, DialogConditionEnum::DC_I_LOVE_THIS_GUY);
        lua_setfield(L, -2, "I_LOVE_THIS_GUY");

        lua_pushinteger(L, DialogConditionEnum::DC_I_HATE_THIS_GUY);
        lua_setfield(L, -2, "DC_I_HATE_THIS_GUY");
        lua_pushinteger(L, DialogConditionEnum::DC_I_HATE_THIS_GUY);
        lua_setfield(L, -2, "I_HATE_THIS_GUY");

        lua_pushinteger(L, DialogConditionEnum::DC_I_SHOULD_SCREW_THIS_GUY_OVER);
        lua_setfield(L, -2, "DC_I_SHOULD_SCREW_THIS_GUY_OVER");
        lua_pushinteger(L, DialogConditionEnum::DC_I_SHOULD_SCREW_THIS_GUY_OVER);
        lua_setfield(L, -2, "I_SHOULD_SCREW_THIS_GUY_OVER");

        lua_pushinteger(L, DialogConditionEnum::DC_I_SHOULD_HELP_THIS_GUY);
        lua_setfield(L, -2, "DC_I_SHOULD_HELP_THIS_GUY");
        lua_pushinteger(L, DialogConditionEnum::DC_I_SHOULD_HELP_THIS_GUY);
        lua_setfield(L, -2, "I_SHOULD_HELP_THIS_GUY");

        lua_pushinteger(L, DialogConditionEnum::DC_IN_COMBAT);
        lua_setfield(L, -2, "DC_IN_COMBAT");
        lua_pushinteger(L, DialogConditionEnum::DC_IN_COMBAT);
        lua_setfield(L, -2, "IN_COMBAT");

        lua_pushinteger(L, DialogConditionEnum::DC_WITHIN_TOWN_WALLS);
        lua_setfield(L, -2, "DC_WITHIN_TOWN_WALLS");
        lua_pushinteger(L, DialogConditionEnum::DC_WITHIN_TOWN_WALLS);
        lua_setfield(L, -2, "WITHIN_TOWN_WALLS");

        lua_pushinteger(L, DialogConditionEnum::DC_TOWN_WALLS_LOCKED_UP);
        lua_setfield(L, -2, "DC_TOWN_WALLS_LOCKED_UP");
        lua_pushinteger(L, DialogConditionEnum::DC_TOWN_WALLS_LOCKED_UP);
        lua_setfield(L, -2, "TOWN_WALLS_LOCKED_UP");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_SLAVE);
        lua_setfield(L, -2, "DC_IS_SLAVE");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_SLAVE);
        lua_setfield(L, -2, "IS_SLAVE");

        lua_pushinteger(L, DialogConditionEnum::DC_HAS_A_BASE_NEARBY);
        lua_setfield(L, -2, "DC_HAS_A_BASE_NEARBY");
        lua_pushinteger(L, DialogConditionEnum::DC_HAS_A_BASE_NEARBY);
        lua_setfield(L, -2, "HAS_A_BASE_NEARBY");

        lua_pushinteger(L, DialogConditionEnum::DC_TARGET_IS_SLAVE_OF_MY_FACTION);
        lua_setfield(L, -2, "DC_TARGET_IS_SLAVE_OF_MY_FACTION");
        lua_pushinteger(L, DialogConditionEnum::DC_TARGET_IS_SLAVE_OF_MY_FACTION);
        lua_setfield(L, -2, "TARGET_IS_SLAVE_OF_MY_FACTION");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_ESCAPED_SLAVE);
        lua_setfield(L, -2, "DC_IS_ESCAPED_SLAVE");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_ESCAPED_SLAVE);
        lua_setfield(L, -2, "IS_ESCAPED_SLAVE");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_IN_LOCKED_CAGE);
        lua_setfield(L, -2, "DC_IS_IN_LOCKED_CAGE");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_IN_LOCKED_CAGE);
        lua_setfield(L, -2, "IS_IN_LOCKED_CAGE");

        lua_pushinteger(L, DialogConditionEnum::DC_WEARING_LOCKED_SHACKLES);
        lua_setfield(L, -2, "DC_WEARING_LOCKED_SHACKLES");
        lua_pushinteger(L, DialogConditionEnum::DC_WEARING_LOCKED_SHACKLES);
        lua_setfield(L, -2, "WEARING_LOCKED_SHACKLES");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_SAME_RACE_AS_ME);
        lua_setfield(L, -2, "DC_IS_SAME_RACE_AS_ME");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_SAME_RACE_AS_ME);
        lua_setfield(L, -2, "IS_SAME_RACE_AS_ME");

        lua_pushinteger(L, DialogConditionEnum::DC_CAN_AFFORD_BOUNTY);
        lua_setfield(L, -2, "DC_CAN_AFFORD_BOUNTY");
        lua_pushinteger(L, DialogConditionEnum::DC_CAN_AFFORD_BOUNTY);
        lua_setfield(L, -2, "CAN_AFFORD_BOUNTY");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_SNEAKING);
        lua_setfield(L, -2, "DC_IS_SNEAKING");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_SNEAKING);
        lua_setfield(L, -2, "IS_SNEAKING");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_INDOORS);
        lua_setfield(L, -2, "DC_IS_INDOORS");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_INDOORS);
        lua_setfield(L, -2, "IS_INDOORS");

        lua_pushinteger(L, DialogConditionEnum::DC_HAS_ILLEGAL_ITEM);
        lua_setfield(L, -2, "DC_HAS_ILLEGAL_ITEM");
        lua_pushinteger(L, DialogConditionEnum::DC_HAS_ILLEGAL_ITEM);
        lua_setfield(L, -2, "HAS_ILLEGAL_ITEM");

        lua_pushinteger(L, DialogConditionEnum::DC_USING_MY_TRAINING_EQUIPMENT);
        lua_setfield(L, -2, "DC_USING_MY_TRAINING_EQUIPMENT");
        lua_pushinteger(L, DialogConditionEnum::DC_USING_MY_TRAINING_EQUIPMENT);
        lua_setfield(L, -2, "USING_MY_TRAINING_EQUIPMENT");

        lua_pushinteger(L, DialogConditionEnum::DC_STARVING);
        lua_setfield(L, -2, "DC_STARVING");
        lua_pushinteger(L, DialogConditionEnum::DC_STARVING);
        lua_setfield(L, -2, "STARVING");

        lua_pushinteger(L, DialogConditionEnum::DC_MIXED_GENDER_GROUP);
        lua_setfield(L, -2, "DC_MIXED_GENDER_GROUP");
        lua_pushinteger(L, DialogConditionEnum::DC_MIXED_GENDER_GROUP);
        lua_setfield(L, -2, "MIXED_GENDER_GROUP");

        lua_pushinteger(L, DialogConditionEnum::DC_TOWN_LEVEL_CURRENT_LOCATION);
        lua_setfield(L, -2, "DC_TOWN_LEVEL_CURRENT_LOCATION");
        lua_pushinteger(L, DialogConditionEnum::DC_TOWN_LEVEL_CURRENT_LOCATION);
        lua_setfield(L, -2, "TOWN_LEVEL_CURRENT_LOCATION");

        lua_pushinteger(L, DialogConditionEnum::DC_PLAYERS_BEST_TOWN_LEVEL);
        lua_setfield(L, -2, "DC_PLAYERS_BEST_TOWN_LEVEL");
        lua_pushinteger(L, DialogConditionEnum::DC_PLAYERS_BEST_TOWN_LEVEL);
        lua_setfield(L, -2, "PLAYERS_BEST_TOWN_LEVEL");

        lua_pushinteger(L, DialogConditionEnum::DC_IN_A_PLAYER_TOWN);
        lua_setfield(L, -2, "DC_IN_A_PLAYER_TOWN");
        lua_pushinteger(L, DialogConditionEnum::DC_IN_A_PLAYER_TOWN);
        lua_setfield(L, -2, "IN_A_PLAYER_TOWN");

        lua_pushinteger(L, DialogConditionEnum::DC_TARGET_CHARACTER_EXISTS);
        lua_setfield(L, -2, "DC_TARGET_CHARACTER_EXISTS");
        lua_pushinteger(L, DialogConditionEnum::DC_TARGET_CHARACTER_EXISTS);
        lua_setfield(L, -2, "TARGET_CHARACTER_EXISTS");

        lua_pushinteger(L, DialogConditionEnum::DC_IS_RECRUITABLE);
        lua_setfield(L, -2, "DC_IS_RECRUITABLE");
        lua_pushinteger(L, DialogConditionEnum::DC_IS_RECRUITABLE);
        lua_setfield(L, -2, "IS_RECRUITABLE");

        lua_pushinteger(L, DialogConditionEnum::DC_HAS_AI_CONTRACT);
        lua_setfield(L, -2, "DC_HAS_AI_CONTRACT");
        lua_pushinteger(L, DialogConditionEnum::DC_HAS_AI_CONTRACT);
        lua_setfield(L, -2, "HAS_AI_CONTRACT");

        lua_pushinteger(L, DialogConditionEnum::DC_HAS_ROBOT_LIMBS);
        lua_setfield(L, -2, "DC_HAS_ROBOT_LIMBS");
        lua_pushinteger(L, DialogConditionEnum::DC_HAS_ROBOT_LIMBS);
        lua_setfield(L, -2, "HAS_ROBOT_LIMBS");

        lua_pushinteger(L, DialogConditionEnum::DC_END);
        lua_setfield(L, -2, "DC_END");
        lua_pushinteger(L, DialogConditionEnum::DC_END);
        lua_setfield(L, -2, "END");

        lua_setglobal(L, "DialogConditionEnum");
        lua_setglobal(L, "DialogCondition");
    }

    void EnumsEnumBinding::registerComparisonEnum(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, ComparisonEnum::CE_EQUALS);
        lua_setfield(L, -2, "CE_EQUALS");
        lua_pushinteger(L, ComparisonEnum::CE_EQUALS);
        lua_setfield(L, -2, "EQUALS");

        lua_pushinteger(L, ComparisonEnum::CE_LESS_THAN);
        lua_setfield(L, -2, "CE_LESS_THAN");
        lua_pushinteger(L, ComparisonEnum::CE_LESS_THAN);
        lua_setfield(L, -2, "LESS_THAN");

        lua_pushinteger(L, ComparisonEnum::CE_MORE_THAN);
        lua_setfield(L, -2, "CE_MORE_THAN");
        lua_pushinteger(L, ComparisonEnum::CE_MORE_THAN);
        lua_setfield(L, -2, "MORE_THAN");

        lua_setglobal(L, "ComparisonEnum");                                               
        lua_setglobal(L, "Comparison");
    }

    void EnumsEnumBinding::registerGroundType(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, GroundType::GROUND_SAND);
        lua_setfield(L, -2, "GROUND_SAND");
		lua_pushinteger(L, GroundType::GROUND_SAND);
		lua_setfield(L, -2, "SAND");

        lua_pushinteger(L, GroundType::GROUND_GRASS);
        lua_setfield(L, -2, "GROUND_GRASS");
		lua_pushinteger(L, GroundType::GROUND_GRASS);
		lua_setfield(L, -2, "GRASS");

        lua_pushinteger(L, GroundType::GROUND_CONCRETE);
        lua_setfield(L, -2, "GROUND_CONCRETE");
		lua_pushinteger(L, GroundType::GROUND_CONCRETE);
		lua_setfield(L, -2, "CONCRETE");

        lua_pushinteger(L, GroundType::GROUND_WOOD);
        lua_setfield(L, -2, "GROUND_WOOD");
		lua_pushinteger(L, GroundType::GROUND_WOOD);
		lua_setfield(L, -2, "WOOD");

        lua_pushinteger(L, GroundType::GROUND_METAL);
        lua_setfield(L, -2, "GROUND_METAL");
		lua_pushinteger(L, GroundType::GROUND_METAL);
		lua_setfield(L, -2, "METAL");

        lua_pushinteger(L, GroundType::GROUND_WATER);
        lua_setfield(L, -2, "GROUND_WATER");
		lua_pushinteger(L, GroundType::GROUND_WATER);
		lua_setfield(L, -2, "WATER");

        lua_pushinteger(L, GroundType::GROUND_MUD);
        lua_setfield(L, -2, "GROUND_MUD");
		lua_pushinteger(L, GroundType::GROUND_MUD);
		lua_setfield(L, -2, "MUD");

        lua_pushinteger(L, GroundType::GROUND_SNOW);
        lua_setfield(L, -2, "GROUND_SNOW");
		lua_pushinteger(L, GroundType::GROUND_SNOW);
		lua_setfield(L, -2, "SNOW");

        lua_pushinteger(L, GroundType::GROUND_DIRT);
        lua_setfield(L, -2, "GROUND_DIRT");
		lua_pushinteger(L, GroundType::GROUND_DIRT);
		lua_setfield(L, -2, "DIRT");

        lua_setglobal(L, "GroundType");
    }

    void EnumsEnumBinding::registerEffectType(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, EffectType::Enum::NONE);
        lua_setfield(L, -2, "NONE");

        lua_pushinteger(L, EffectType::Enum::CAMERA);
        lua_setfield(L, -2, "CAMERA");

        lua_pushinteger(L, EffectType::Enum::POINT);
        lua_setfield(L, -2, "POINT");

        lua_pushinteger(L, EffectType::Enum::WANDERING);
        lua_setfield(L, -2, "WANDERING");

        lua_pushinteger(L, EffectType::Enum::GLOBAL);
        lua_setfield(L, -2, "GLOBAL");

        lua_pushinteger(L, EffectType::Enum::CAMERA_RAIN);
        lua_setfield(L, -2, "CAMERA_RAIN");

        lua_pushinteger(L, EffectType::Enum::CAMERA_ACID_RAIN);
        lua_setfield(L, -2, "CAMERA_ACID_RAIN");

        lua_pushinteger(L, EffectType::Enum::POINT_LIGHTING);
        lua_setfield(L, -2, "POINT_LIGHTING");

        lua_pushinteger(L, EffectType::Enum::WANDERING_STORM);
        lua_setfield(L, -2, "WANDERING_STORM");

        lua_pushinteger(L, EffectType::Enum::WANDERING_GAS);
        lua_setfield(L, -2, "WANDERING_GAS");

        lua_pushinteger(L, EffectType::Enum::GLOBAL_POINT);
        lua_setfield(L, -2, "GLOBAL_POINT");

        lua_setglobal(L, "EffectType");
    }

    void EnumsEnumBinding::registerSquadType(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, SquadType::SQ_UNKNOWN);
        lua_setfield(L, -2, "SQ_UNKNOWN");

        lua_pushinteger(L, SquadType::SQ_RESIDENT);
        lua_setfield(L, -2, "SQ_RESIDENT");

        lua_pushinteger(L, SquadType::SQ_ROAMING);
        lua_setfield(L, -2, "SQ_ROAMING");

        lua_setglobal(L, "SquadType");
    }

    void EnumsEnumBinding::registerMoveSpeed(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, MoveSpeed::WALK);
        lua_setfield(L, -2, "WALK");

        lua_pushinteger(L, MoveSpeed::JOG);
        lua_setfield(L, -2, "JOG");

        lua_pushinteger(L, MoveSpeed::RUN);
        lua_setfield(L, -2, "RUN");

        lua_pushinteger(L, MoveSpeed::GROUPED);
        lua_setfield(L, -2, "GROUPED");

        lua_pushinteger(L, MoveSpeed::NO_SPEED_CHANGE);
        lua_setfield(L, -2, "NO_SPEED_CHANGE");

        lua_setglobal(L, "MoveSpeed");
    }

    void EnumsEnumBinding::registerSwordStateEnum(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, swordStateEnum::CHOP_WEAPON);
        lua_setfield(L, -2, "CHOP_WEAPON");

        lua_pushinteger(L, swordStateEnum::BLOCK);
        lua_setfield(L, -2, "BLOCK");

        lua_pushinteger(L, swordStateEnum::REACTION_BLOCK);
        lua_setfield(L, -2, "REACTION_BLOCK");

        lua_pushinteger(L, swordStateEnum::STARTUP_STATE);
        lua_setfield(L, -2, "STARTUP_STATE");

        lua_pushinteger(L, swordStateEnum::DECISION);
        lua_setfield(L, -2, "DECISION");

        lua_pushinteger(L, swordStateEnum::CIRCLE_MENACINGLY);
        lua_setfield(L, -2, "CIRCLE_MENACINGLY");

        lua_pushinteger(L, swordStateEnum::WAIT_MENACINGLY);
        lua_setfield(L, -2, "WAIT_MENACINGLY");

        lua_pushinteger(L, swordStateEnum::HESITATE);
        lua_setfield(L, -2, "HESITATE");

        lua_pushinteger(L, swordStateEnum::STUMBLE);
        lua_setfield(L, -2, "STUMBLE");

        lua_pushinteger(L, swordStateEnum::COMBAT_FINISHED);
        lua_setfield(L, -2, "COMBAT_FINISHED");

        lua_pushinteger(L, swordStateEnum::TARGET_PATHFINDING_STARTUP);
        lua_setfield(L, -2, "TARGET_PATHFINDING_STARTUP");

        lua_pushinteger(L, swordStateEnum::TARGET_PATHFINDING);
        lua_setfield(L, -2, "TARGET_PATHFINDING");

        lua_setglobal(L, "SwordStateEnum");
        lua_setglobal(L, "SwordState");
    }

    void EnumsEnumBinding::registerMiningResource(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, MiningResource::NONE);
        lua_setfield(L, -2, "NONE");

        lua_pushinteger(L, MiningResource::IRON);
        lua_setfield(L, -2, "IRON");

        lua_pushinteger(L, MiningResource::STONE);
        lua_setfield(L, -2, "STONE");

        lua_pushinteger(L, MiningResource::COPPER);
        lua_setfield(L, -2, "COPPER");

        lua_pushinteger(L, MiningResource::CARBON);
        lua_setfield(L, -2, "CARBON");

        lua_pushinteger(L, MiningResource::WATER);
        lua_setfield(L, -2, "WATER");

        lua_pushinteger(L, MiningResource::GROUND);
        lua_setfield(L, -2, "GROUND");

        lua_setglobal(L, "MiningResource");
    }

    void EnumsEnumBinding::registerCursorType(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, CursorType::DEFAULT_CURSOR);
        lua_setfield(L, -2, "DEFAULT_CURSOR");

        lua_pushinteger(L, CursorType::MEDIC_CURSOR);
        lua_setfield(L, -2, "MEDIC_CURSOR");

        lua_pushinteger(L, CursorType::LOOT_CURSOR);
        lua_setfield(L, -2, "LOOT_CURSOR");

        lua_pushinteger(L, CursorType::LIFT_CURSOR);
        lua_setfield(L, -2, "LIFT_CURSOR");

        lua_pushinteger(L, CursorType::PICKUP_ITEM_CURSOR);
        lua_setfield(L, -2, "PICKUP_ITEM_CURSOR");

        lua_pushinteger(L, CursorType::ATTACK_CURSOR);
        lua_setfield(L, -2, "ATTACK_CURSOR");

        lua_pushinteger(L, CursorType::GUARD_CURSOR);
        lua_setfield(L, -2, "GUARD_CURSOR");

        lua_pushinteger(L, CursorType::TALK_CURSOR);
        lua_setfield(L, -2, "TALK_CURSOR");

        lua_pushinteger(L, CursorType::SPECIAL_TALK_CURSOR);
        lua_setfield(L, -2, "SPECIAL_TALK_CURSOR");

        lua_pushinteger(L, CursorType::USE_CURSOR);
        lua_setfield(L, -2, "USE_CURSOR");

        lua_pushinteger(L, CursorType::TRADER_CURSOR);
        lua_setfield(L, -2, "TRADER_CURSOR");

        lua_pushinteger(L, CursorType::BUILD_CURSOR);
        lua_setfield(L, -2, "BUILD_CURSOR");

        lua_pushinteger(L, CursorType::OPEN_DOOR_CURSOR);
        lua_setfield(L, -2, "OPEN_DOOR_CURSOR");

        lua_pushinteger(L, CursorType::DOOR_ESCAPE_CURSOR);
        lua_setfield(L, -2, "DOOR_ESCAPE_CURSOR");

        lua_pushinteger(L, CursorType::LOCKED_CURSOR);
        lua_setfield(L, -2, "LOCKED_CURSOR");

        lua_pushinteger(L, CursorType::PICK_LOCK_CURSOR);
        lua_setfield(L, -2, "PICK_LOCK_CURSOR");

        lua_pushinteger(L, CursorType::BUY_HOUSE_CURSOR);
        lua_setfield(L, -2, "BUY_HOUSE_CURSOR");

        lua_pushinteger(L, CursorType::GREEN_CURSOR);
        lua_setfield(L, -2, "GREEN_CURSOR");

        lua_pushinteger(L, CursorType::MINE_CURSOR);
        lua_setfield(L, -2, "MINE_CURSOR");

        lua_pushinteger(L, CursorType::REPAIR_CURSOR);
        lua_setfield(L, -2, "REPAIR_CURSOR");

        lua_pushinteger(L, CursorType::LIGHT_CURSOR);
        lua_setfield(L, -2, "LIGHT_CURSOR");

        lua_pushinteger(L, CursorType::STEAL_CURSOR);
        lua_setfield(L, -2, "STEAL_CURSOR");

        lua_pushinteger(L, CursorType::HAND_CURSOR);
        lua_setfield(L, -2, "HAND_CURSOR");

        lua_pushinteger(L, CursorType::INVALID_MOVEMENT_CURSOR);
        lua_setfield(L, -2, "INVALID_MOVEMENT_CURSOR");

        lua_pushinteger(L, CursorType::LOOT_CURSOR_RED);
        lua_setfield(L, -2, "LOOT_CURSOR_RED");

        lua_pushinteger(L, CursorType::KNOCKOUT_CURSOR);
        lua_setfield(L, -2, "KNOCKOUT_CURSOR");

        lua_setglobal(L, "CursorType");
    }

    void EnumsEnumBinding::registerMapZoomLevel(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, MapZoomLevel::ZOOM_MIN);
        lua_setfield(L, -2, "ZOOM_MIN");
		lua_pushinteger(L, MapZoomLevel::ZOOM_MIN);
		lua_setfield(L, -2, "MIN");

        lua_pushinteger(L, MapZoomLevel::ZOOM_MID);
        lua_setfield(L, -2, "ZOOM_MID");
		lua_pushinteger(L, MapZoomLevel::ZOOM_MID);
		lua_setfield(L, -2, "MID");

        lua_pushinteger(L, MapZoomLevel::ZOOM_MAX);
        lua_setfield(L, -2, "ZOOM_MAX");
		lua_pushinteger(L, MapZoomLevel::ZOOM_MAX);
		lua_setfield(L, -2, "MAX");

        lua_pushinteger(L, MapZoomLevel::ZOOM_CHARACTERS);
        lua_setfield(L, -2, "ZOOM_CHARACTERS");
		lua_pushinteger(L, MapZoomLevel::ZOOM_CHARACTERS);
		lua_setfield(L, -2, "CHARACTERS");

        lua_setglobal(L, "MapZoomLevel");
    }

    void EnumsEnumBinding::registerBinding(lua_State* L)
    {
        registerDialogConditionEnum(L);
        registerComparisonEnum(L);
        registerGroundType(L);
        registerEffectType(L);
        registerSquadType(L);
        registerMoveSpeed(L);
        registerSwordStateEnum(L);
        registerMiningResource(L);
        registerCursorType(L);
        registerMapZoomLevel(L);
	}

// --------------------------------------------------
// Registration function
// --------------------------------------------------

    void registerEnums(lua_State* L)
    {
        BuildingEnumBinding::registerBinding(L);
		CharacterEnumBinding::registerBinding(L);
		//DialogueEnumBinding::registerBinding(L);
		//EnumsEnumBinding::registerBinding(L);

  //      //MedicalSystemBinding.h
  //      MedicalSystemEnumBinding::registerBinding(L);
    }
} // namespace KenshiLua
