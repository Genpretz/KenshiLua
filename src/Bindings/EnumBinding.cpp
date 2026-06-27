#include "pch.h"
#include "Bindings/EnumBinding.h"
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
    // ----------------------------------------------
    // Building.h
    // ----------------------------------------------

    void registerBuildingDesignation(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, BuildingDesignation::BD_NONE);
        lua_setfield(L, -2, "BD_NONE");
        lua_pushinteger(L, BuildingDesignation::BD_NONE);
        lua_setfield(L, -2, "NONE");

        lua_pushinteger(L, BuildingDesignation::BD_SHOP);
        lua_setfield(L, -2, "BD_SHOP");
        lua_pushinteger(L, BuildingDesignation::BD_SHOP);
        lua_setfield(L, -2, "SHOP");

        lua_pushinteger(L, BuildingDesignation::BD_BARRACKS);
        lua_setfield(L, -2, "BD_BARRACKS");
        lua_pushinteger(L, BuildingDesignation::BD_BARRACKS);
        lua_setfield(L, -2, "BARRACKS");

        lua_pushinteger(L, BuildingDesignation::BD_BAR);
        lua_setfield(L, -2, "BD_BAR");
        lua_pushinteger(L, BuildingDesignation::BD_BAR);
        lua_setfield(L, -2, "BAR");

        lua_pushinteger(L, BuildingDesignation::BD_HOSPITAL);
        lua_setfield(L, -2, "BD_HOSPITAL");
        lua_pushinteger(L, BuildingDesignation::BD_HOSPITAL);
        lua_setfield(L, -2, "HOSPITAL");

        lua_pushinteger(L, BuildingDesignation::BD_ARMOURY);
        lua_setfield(L, -2, "BD_ARMOURY");
        lua_pushinteger(L, BuildingDesignation::BD_ARMOURY);
        lua_setfield(L, -2, "ARMOURY");

        lua_pushinteger(L, BuildingDesignation::BD_TREASURE);
        lua_setfield(L, -2, "BD_TREASURE");
        lua_pushinteger(L, BuildingDesignation::BD_TREASURE);
        lua_setfield(L, -2, "TREASURE");

        lua_pushinteger(L, BuildingDesignation::BD_PRISON);
        lua_setfield(L, -2, "BD_PRISON");
        lua_pushinteger(L, BuildingDesignation::BD_PRISON);
        lua_setfield(L, -2, "PRISON");

        lua_pushinteger(L, BuildingDesignation::BD_HQ);
        lua_setfield(L, -2, "BD_HQ");
        lua_pushinteger(L, BuildingDesignation::BD_HQ);
        lua_setfield(L, -2, "HQ");

        lua_pushinteger(L, BuildingDesignation::BD_RESIDENTIAL);
        lua_setfield(L, -2, "BD_RESIDENTIAL");
        lua_pushinteger(L, BuildingDesignation::BD_RESIDENTIAL);
        lua_setfield(L, -2, "RESIDENTIAL");

        lua_pushinteger(L, BuildingDesignation::BD_SLAVE_STORAGE);
        lua_setfield(L, -2, "BD_SLAVE_STORAGE");
        lua_pushinteger(L, BuildingDesignation::BD_SLAVE_STORAGE);
        lua_setfield(L, -2, "SLAVE_STORAGE");

        lua_pushinteger(L, BuildingDesignation::BD_RESIDENTIAL_SMALL);
        lua_setfield(L, -2, "BD_RESIDENTIAL_SMALL");
        lua_pushinteger(L, BuildingDesignation::BD_RESIDENTIAL_SMALL);
        lua_setfield(L, -2, "RESIDENTIAL_SMALL");

        lua_setglobal(L, "BuildingDesignation");
    }

    void registerBuildingClassType(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, BuildingClassType::BCTYPE_FLUFF);
        lua_setfield(L, -2, "BCTYPE_FLUFF");
        lua_pushinteger(L, BuildingClassType::BCTYPE_FLUFF);
        lua_setfield(L, -2, "FLUFF");

        lua_pushinteger(L, BuildingClassType::BCTYPE_DOOR);
        lua_setfield(L, -2, "BCTYPE_DOOR");
        lua_pushinteger(L, BuildingClassType::BCTYPE_DOOR);
        lua_setfield(L, -2, "DOOR");

        lua_pushinteger(L, BuildingClassType::BCTYPE_USABLE);
        lua_setfield(L, -2, "BCTYPE_USABLE");
        lua_pushinteger(L, BuildingClassType::BCTYPE_USABLE);
        lua_setfield(L, -2, "USABLE");

        lua_pushinteger(L, BuildingClassType::BCTYPE_STORAGE);
        lua_setfield(L, -2, "BCTYPE_STORAGE");
        lua_pushinteger(L, BuildingClassType::BCTYPE_STORAGE);
        lua_setfield(L, -2, "STORAGE");

        lua_pushinteger(L, BuildingClassType::BCTYPE_PRODUCTION);
        lua_setfield(L, -2, "BCTYPE_PRODUCTION");
        lua_pushinteger(L, BuildingClassType::BCTYPE_PRODUCTION);
        lua_setfield(L, -2, "PRODUCTION");

        lua_pushinteger(L, BuildingClassType::BCTYPE_RESEARCH);
        lua_setfield(L, -2, "BCTYPE_RESEARCH");
        lua_pushinteger(L, BuildingClassType::BCTYPE_RESEARCH);
        lua_setfield(L, -2, "RESEARCH");

        lua_pushinteger(L, BuildingClassType::BCTYPE_CRAFTING);
        lua_setfield(L, -2, "BCTYPE_CRAFTING");
        lua_pushinteger(L, BuildingClassType::BCTYPE_CRAFTING);
        lua_setfield(L, -2, "CRAFTING");

        lua_pushinteger(L, BuildingClassType::BCTYPE_GATEWAY);
        lua_setfield(L, -2, "BCTYPE_GATEWAY");
        lua_pushinteger(L, BuildingClassType::BCTYPE_GATEWAY);
        lua_setfield(L, -2, "GATEWAY");

        lua_pushinteger(L, BuildingClassType::BCTYPE_TURRET);
        lua_setfield(L, -2, "BCTYPE_TURRET");
        lua_pushinteger(L, BuildingClassType::BCTYPE_TURRET);
        lua_setfield(L, -2, "TURRET");

        lua_pushinteger(L, BuildingClassType::BCTYPE_WALL);
        lua_setfield(L, -2, "BCTYPE_WALL");
        lua_pushinteger(L, BuildingClassType::BCTYPE_WALL);
        lua_setfield(L, -2, "WALL");

        lua_pushinteger(L, BuildingClassType::BCTYPE_ITEM_FURNACE);
        lua_setfield(L, -2, "BCTYPE_ITEM_FURNACE");
        lua_pushinteger(L, BuildingClassType::BCTYPE_ITEM_FURNACE);
        lua_setfield(L, -2, "ITEM_FURNACE");

        lua_pushinteger(L, BuildingClassType::BCTYPE_LIGHT);
        lua_setfield(L, -2, "BCTYPE_LIGHT");
        lua_pushinteger(L, BuildingClassType::BCTYPE_LIGHT);
        lua_setfield(L, -2, "LIGHT");

        lua_pushinteger(L, BuildingClassType::BCTYPE_SHELL_WITH_INTERIOR);
        lua_setfield(L, -2, "BCTYPE_SHELL_WITH_INTERIOR");
        lua_pushinteger(L, BuildingClassType::BCTYPE_SHELL_WITH_INTERIOR);
        lua_setfield(L, -2, "SHELL_WITH_INTERIOR");

        lua_pushinteger(L, BuildingClassType::BCTYPE_FARM);
        lua_setfield(L, -2, "BCTYPE_FARM");
        lua_pushinteger(L, BuildingClassType::BCTYPE_FARM);
        lua_setfield(L, -2, "FARM");

        lua_setglobal(L, "BuildingClassType");
    }

    void registerBuildingPlacementGroundType(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, BuildingPlacementGroundType::Enum::ANY);
        lua_setfield(L, -2, "ANY");

        lua_pushinteger(L, BuildingPlacementGroundType::Enum::LAND);
        lua_setfield(L, -2, "LAND");

        lua_pushinteger(L, BuildingPlacementGroundType::Enum::WATER);
        lua_setfield(L, -2, "WATER");

        lua_setglobal(L, "BuildingPlacementGroundType");
    }

    void registerPreviewBuildingPlacementResult(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, PreviewBuilding::PlacementResult::PLACEMENT_VALID);
        lua_setfield(L, -2, "PLACEMENT_VALID");
        lua_pushinteger(L, PreviewBuilding::PlacementResult::PLACEMENT_VALID);
        lua_setfield(L, -2, "VALID");

        lua_pushinteger(L, PreviewBuilding::PlacementResult::PLACEMENT_OUTSIDE);
        lua_setfield(L, -2, "PLACEMENT_OUTSIDE");
        lua_pushinteger(L, PreviewBuilding::PlacementResult::PLACEMENT_OUTSIDE);
        lua_setfield(L, -2, "OUTSIDE");

        lua_pushinteger(L, PreviewBuilding::PlacementResult::PLACEMENT_INVALID);
        lua_setfield(L, -2, "PLACEMENT_INVALID");
        lua_pushinteger(L, PreviewBuilding::PlacementResult::PLACEMENT_INVALID);
        lua_setfield(L, -2, "INVALID");

        lua_setglobal(L, "PreviewBuildingPlacementResult");
    }

    void registerPreviewBuildingClassType(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, PreviewBuilding::PreviewBuildingClassType::PREVIEW_NORMAL);
        lua_setfield(L, -2, "PREVIEW_NORMAL");
        lua_pushinteger(L, PreviewBuilding::PreviewBuildingClassType::PREVIEW_NORMAL);
        lua_setfield(L, -2, "NORMAL");

        lua_pushinteger(L, PreviewBuilding::PreviewBuildingClassType::PREVIEW_WALL);
        lua_setfield(L, -2, "PREVIEW_WALL");
        lua_pushinteger(L, PreviewBuilding::PreviewBuildingClassType::PREVIEW_WALL);
        lua_setfield(L, -2, "WALL");

        lua_setglobal(L, "PreviewBuildingClassType");
    }

    // ----------------------------------------------
    // Character.h
	// ----------------------------------------------

    void registerProneState(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, ProneState::PS_NORMAL);
        lua_setfield(L, -2, "PS_NORMAL");
        lua_pushinteger(L, ProneState::PS_NORMAL);
        lua_setfield(L, -2, "NORMAL");

        lua_pushinteger(L, ProneState::PS_STAYING_LOW);
        lua_setfield(L, -2, "PS_STAYING_LOW");
        lua_pushinteger(L, ProneState::PS_STAYING_LOW);
        lua_setfield(L, -2, "STAYING_LOW");

        lua_pushinteger(L, ProneState::PS_CRIPPLED);
        lua_setfield(L, -2, "PS_CRIPPLED");
        lua_pushinteger(L, ProneState::PS_CRIPPLED);
        lua_setfield(L, -2, "CRIPPLED");

        lua_pushinteger(L, ProneState::PS_PLAYING_DEAD);
        lua_setfield(L, -2, "PS_PLAYING_DEAD");
        lua_pushinteger(L, ProneState::PS_PLAYING_DEAD);
        lua_setfield(L, -2, "PLAYING_DEAD");

        lua_pushinteger(L, ProneState::PS_KO);
        lua_setfield(L, -2, "PS_KO");
        lua_pushinteger(L, ProneState::PS_KO);
        lua_setfield(L, -2, "KO");

        lua_setglobal(L, "ProneState");
    }

    void registerWaterState(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, WaterState::Enum::NO_WATER);
        lua_setfield(L, -2, "NO_WATER");

        lua_pushinteger(L, WaterState::Enum::VERY_SHALLOW_WATER);
        lua_setfield(L, -2, "VERY_SHALLOW_WATER");

        lua_pushinteger(L, WaterState::Enum::THIGH_DEEP_WATER);
        lua_setfield(L, -2, "THIGH_DEEP_WATER");

        lua_pushinteger(L, WaterState::Enum::DEEP_WATER);
        lua_setfield(L, -2, "DEEP_WATER");

        lua_setglobal(L, "WaterState");
    }

    void registerRagdollPart(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, RagdollPart::Enum::NONE);
        lua_setfield(L, -2, "NONE");

        lua_pushinteger(L, RagdollPart::Enum::WHOLE);
        lua_setfield(L, -2, "WHOLE");

        lua_pushinteger(L, RagdollPart::Enum::RIGHT_ARM);
        lua_setfield(L, -2, "RIGHT_ARM");

        lua_pushinteger(L, RagdollPart::Enum::LEFT_ARM);
        lua_setfield(L, -2, "LEFT_ARM");

        lua_pushinteger(L, RagdollPart::Enum::HEAD);
        lua_setfield(L, -2, "HEAD");

        lua_pushinteger(L, RagdollPart::Enum::RIGHT_LEG);
        lua_setfield(L, -2, "RIGHT_LEG");

        lua_pushinteger(L, RagdollPart::Enum::LEFT_LEG);
        lua_setfield(L, -2, "LEFT_LEG");

        lua_pushinteger(L, RagdollPart::Enum::CARRY_MODE);
        lua_setfield(L, -2, "CARRY_MODE");

        lua_pushinteger(L, RagdollPart::Enum::ARMS);
        lua_setfield(L, -2, "ARMS");

        lua_pushinteger(L, RagdollPart::Enum::LEGS);
        lua_setfield(L, -2, "LEGS");

        lua_pushinteger(L, RagdollPart::Enum::ALL);
        lua_setfield(L, -2, "ALL");

        lua_setglobal(L, "RagdollPart");
    }

    void registerCharacterPerceptionTagsShortTerm(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_NONE);
        lua_setfield(L, -2, "ST_NONE");
        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_NONE);
        lua_setfield(L, -2, "NONE");

        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_INTRUDER);
        lua_setfield(L, -2, "ST_INTRUDER");
        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_INTRUDER);
        lua_setfield(L, -2, "INTRUDER");

        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_AGGRESSOR);
        lua_setfield(L, -2, "ST_AGGRESSOR");
        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_AGGRESSOR);
        lua_setfield(L, -2, "AGGRESSOR");

        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_TEMPORARY_ALLY);
        lua_setfield(L, -2, "ST_TEMPORARY_ALLY");
        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_TEMPORARY_ALLY);
        lua_setfield(L, -2, "TEMPORARY_ALLY");

        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_TEMPORARY_ENEMY);
        lua_setfield(L, -2, "ST_TEMPORARY_ENEMY");
        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_TEMPORARY_ENEMY);
        lua_setfield(L, -2, "TEMPORARY_ENEMY");

        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_PRISONER);
        lua_setfield(L, -2, "ST_PRISONER");
        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_PRISONER);
        lua_setfield(L, -2, "PRISONER");

        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_HAS_BEEN_LOOTED);
        lua_setfield(L, -2, "ST_HAS_BEEN_LOOTED");
        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_HAS_BEEN_LOOTED);
        lua_setfield(L, -2, "HAS_BEEN_LOOTED");

        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_CRIMINAL);
        lua_setfield(L, -2, "ST_CRIMINAL");
        lua_pushinteger(L,CharacterPerceptionTags_ShortTerm::ST_CRIMINAL);
        lua_setfield(L, -2, "CRIMINAL");

        lua_setglobal(L, "CharacterPerceptionTags_ShortTerm");
    }

    void registerCharacterPerceptionTagsLongTerm(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_NONE);
        lua_setfield(L, -2, "LT_NONE");
        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_NONE);
        lua_setfield(L, -2, "NONE");

        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_MY_INTRUDER);
        lua_setfield(L, -2, "LT_MY_INTRUDER");
        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_MY_INTRUDER);
        lua_setfield(L, -2, "MY_INTRUDER");

        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_MY_LIFESAVER);
        lua_setfield(L, -2, "LT_MY_LIFESAVER");
        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_MY_LIFESAVER);
        lua_setfield(L, -2, "MY_LIFESAVER");

        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_FREED_ME);
        lua_setfield(L, -2, "LT_FREED_ME");
        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_FREED_ME);
        lua_setfield(L, -2, "FREED_ME");

        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_STOLE_FROM_ME);
        lua_setfield(L, -2, "LT_STOLE_FROM_ME");
        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_STOLE_FROM_ME);
        lua_setfield(L, -2, "STOLE_FROM_ME");

        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_MY_CAPTOR);
        lua_setfield(L, -2, "LT_MY_CAPTOR");
        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_MY_CAPTOR);
        lua_setfield(L, -2, "MY_CAPTOR");

        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_FRIENDLY_AQUAINTANCE);
        lua_setfield(L, -2, "LT_FRIENDLY_AQUAINTANCE");
        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_FRIENDLY_AQUAINTANCE);
        lua_setfield(L, -2, "FRIENDLY_AQUAINTANCE");

        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_DEFEATED_MY_SQUAD_ONCE);
        lua_setfield(L, -2, "LT_DEFEATED_MY_SQUAD_ONCE");
        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_DEFEATED_MY_SQUAD_ONCE);
        lua_setfield(L, -2, "DEFEATED_MY_SQUAD_ONCE");

        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_SQUAD_LOST_TO_ME_ONCE);
        lua_setfield(L, -2, "LT_SQUAD_LOST_TO_ME_ONCE");
        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_SQUAD_LOST_TO_ME_ONCE);
        lua_setfield(L, -2, "SQUAD_LOST_TO_ME_ONCE");

        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_KILLED_MY_FRIEND);
        lua_setfield(L, -2, "LT_KILLED_MY_FRIEND");
        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_KILLED_MY_FRIEND);
        lua_setfield(L, -2, "KILLED_MY_FRIEND");

        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_I_SCREWED_THIS_GUY);
        lua_setfield(L, -2, "LT_I_SCREWED_THIS_GUY");
        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_I_SCREWED_THIS_GUY);
        lua_setfield(L, -2, "I_SCREWED_THIS_GUY");

        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_MAX);
        lua_setfield(L, -2, "LT_MAX");
        lua_pushinteger(L,CharacterPerceptionTags_LongTerm::LT_MAX);
        lua_setfield(L, -2, "MAX");

        lua_setglobal(L, "CharacterPerceptionTags_LongTerm");
    }

    void registerSoundRange(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L,SoundRange::SOUNDRANGE_SHORT);
        lua_setfield(L, -2, "SOUNDRANGE_SHORT");
        lua_pushinteger(L,SoundRange::SOUNDRANGE_SHORT);
        lua_setfield(L, -2, "SHORT");

        lua_pushinteger(L,SoundRange::SOUNDRANGE_LONG);
        lua_setfield(L, -2, "SOUNDRANGE_LONG");
        lua_pushinteger(L,SoundRange::SOUNDRANGE_LONG);
        lua_setfield(L, -2, "LONG");

        lua_pushinteger(L,SoundRange::SOUNDRANGE_ALWAYS);
        lua_setfield(L, -2, "SOUNDRANGE_ALWAYS");
        lua_pushinteger(L,SoundRange::SOUNDRANGE_ALWAYS);
        lua_setfield(L, -2, "ALWAYS");

        lua_setglobal(L, "SoundRange");
    }

    void registerSquadMemberType(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L,SquadMemberType::SQUAD_1);
        lua_setfield(L, -2, "SQUAD_1");
		lua_pushinteger(L,SquadMemberType::SQUAD_1);
		lua_setfield(L, -2, "1");

        lua_pushinteger(L,SquadMemberType::SQUAD_2);
        lua_setfield(L, -2, "SQUAD_2");
		lua_pushinteger(L,SquadMemberType::SQUAD_2);
		lua_setfield(L, -2, "2");

        lua_pushinteger(L,SquadMemberType::SQUAD_LEADER);
        lua_setfield(L, -2, "SQUAD_LEADER");
		lua_pushinteger(L,SquadMemberType::SQUAD_LEADER);
		lua_setfield(L, -2, "LEADER");

        lua_pushinteger(L,SquadMemberType::SQUAD_SIGNALS_PLAN);
        lua_setfield(L, -2, "SQUAD_SIGNALS_PLAN");
		lua_pushinteger(L,SquadMemberType::SQUAD_SIGNALS_PLAN);
		lua_setfield(L, -2, "SIGNALS_PLAN");

        lua_pushinteger(L,SquadMemberType::SQUAD_SLAVE);
        lua_setfield(L, -2, "SQUAD_SLAVE");
		lua_pushinteger(L,SquadMemberType::SQUAD_SLAVE);
		lua_setfield(L, -2, "SLAVE");

        lua_setglobal(L, "SquadMemberType");
    }

    void registerCharacterMessage(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, ATTACKING_MELEE);
        lua_setfield(L, -2, "ATTACKING_MELEE");

        lua_setglobal(L, "CharacterMessage");
    }



    // --------------------------------------------------
    // Dialogue.h
    // --------------------------------------------------

    void registerTalker(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, T_ME);
        lua_setfield(L, -2, "T_ME");
        lua_pushinteger(L, T_ME);
        lua_setfield(L, -2, "ME");

        lua_pushinteger(L, T_TARGET);
        lua_setfield(L, -2, "T_TARGET");
        lua_pushinteger(L, T_TARGET);
        lua_setfield(L, -2, "TARGET");

        lua_pushinteger(L, T_TARGET_IF_PLAYER);
        lua_setfield(L, -2, "T_TARGET_IF_PLAYER");
        lua_pushinteger(L, T_TARGET_IF_PLAYER);
        lua_setfield(L, -2, "TARGET_IF_PLAYER");

        lua_pushinteger(L, T_INTERJECTOR1);
        lua_setfield(L, -2, "T_INTERJECTOR1");
        lua_pushinteger(L, T_INTERJECTOR1);
        lua_setfield(L, -2, "INTERJECTOR1");

        lua_pushinteger(L, T_INTERJECTOR2);
        lua_setfield(L, -2, "T_INTERJECTOR2");
        lua_pushinteger(L, T_INTERJECTOR2);
        lua_setfield(L, -2, "INTERJECTOR2");

        lua_pushinteger(L, T_INTERJECTOR3);
        lua_setfield(L, -2, "T_INTERJECTOR3");
        lua_pushinteger(L, T_INTERJECTOR3);
        lua_setfield(L, -2, "INTERJECTOR3");

        lua_pushinteger(L, T_WHOLE_SQUAD);
        lua_setfield(L, -2, "T_WHOLE_SQUAD");
        lua_pushinteger(L, T_WHOLE_SQUAD);
        lua_setfield(L, -2, "WHOLE_SQUAD");

        lua_pushinteger(L, T_TARGET_WITH_RACE);
        lua_setfield(L, -2, "T_TARGET_WITH_RACE");
        lua_pushinteger(L, T_TARGET_WITH_RACE);
        lua_setfield(L, -2, "TARGET_WITH_RACE");

		lua_setglobal(L, "Talker");
    }

    void registerDialogueAction(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, DA_NONE);
        lua_setfield(L, -2, "DA_NONE");
        lua_pushinteger(L , DA_NONE);
        lua_setfield(L, -2, "NONE");

        lua_pushinteger(L , DA_TRADE);
        lua_setfield(L, -2, "DA_TRADE");
        lua_pushinteger(L , DA_TRADE);
        lua_setfield(L, -2, "TRADE");

        lua_pushinteger(L , DA_TALK_TO_LEADER);
        lua_setfield(L, -2, "DA_TALK_TO_LEADER");
        lua_pushinteger(L , DA_TALK_TO_LEADER);
        lua_setfield(L, -2, "TALK_TO_LEADER");

        lua_pushinteger(L , DA_JOIN_SQUAD_WITH_EDIT);
        lua_setfield(L, -2, "DA_JOIN_SQUAD_WITH_EDIT");
        lua_pushinteger(L , DA_JOIN_SQUAD_WITH_EDIT);
        lua_setfield(L, -2, "JOIN_SQUAD_WITH_EDIT");

        lua_pushinteger(L , DA_AFFECT_RELATIONS);
        lua_setfield(L, -2, "DA_AFFECT_RELATIONS");
        lua_pushinteger(L , DA_AFFECT_RELATIONS);
        lua_setfield(L, -2, "AFFECT_RELATIONS");


        lua_pushinteger(L , DA_AFFECT_REPUTATION);
        lua_setfield(L, -2, "DA_AFFECT_REPUTATION");
        lua_pushinteger(L , DA_AFFECT_REPUTATION);
        lua_setfield(L, -2, "AFFECT_REPUTATION");

		lua_pushinteger(L , DA_ATTACK_CHASE_FOREVER);
		lua_setfield(L, -2, "DA_ATTACK_CHASE_FOREVER");
		lua_pushinteger(L , DA_ATTACK_CHASE_FOREVER);
		lua_setfield(L, -2, "ATTACK_CHASE_FOREVER");

        lua_pushinteger(L , DA_GO_HOME);
        lua_setfield(L, -2, "DA_GO_HOME");
        lua_pushinteger(L , DA_GO_HOME);
        lua_setfield(L, -2, "GO_HOME");

        lua_pushinteger(L , DA_TAKE_MONEY);
        lua_setfield(L, -2, "DA_TAKE_MONEY");
        lua_pushinteger(L , DA_TAKE_MONEY);
        lua_setfield(L, -2, "TAKE_MONEY");

        lua_pushinteger(L , DA_GIVE_MONEY);
        lua_setfield(L, -2, "DA_GIVE_MONEY");
        lua_pushinteger(L , DA_GIVE_MONEY);
        lua_setfield(L, -2, "GIVE_MONEY");

        lua_pushinteger(L , DA_PAY_BOUNTY);
        lua_setfield(L, -2, "DA_PAY_BOUNTY");
        lua_pushinteger(L , DA_PAY_BOUNTY);
        lua_setfield(L, -2, "PAY_BOUNTY");

        lua_pushinteger(L , DA_CHARACTER_EDITOR);
        lua_setfield(L, -2, "DA_CHARACTER_EDITOR");
        lua_pushinteger(L , DA_CHARACTER_EDITOR);
        lua_setfield(L, -2, "CHARACTER_EDITOR");

        lua_pushinteger(L , DA_FORCE_SPEECH_TIMER);
        lua_setfield(L, -2, "DA_FORCE_SPEECH_TIMER");
        lua_pushinteger(L , DA_FORCE_SPEECH_TIMER);
        lua_setfield(L, -2, "FORCE_SPEECH_TIMER");

        lua_pushinteger(L , DA_DECLARE_WAR);
        lua_setfield(L, -2, "DA_DECLARE_WAR");
        lua_pushinteger(L , DA_DECLARE_WAR);
        lua_setfield(L, -2, "DECLARE_WAR");

        lua_pushinteger(L , DA_END_WAR);
        lua_setfield(L, -2, "DA_END_WAR");
        lua_pushinteger(L , DA_END_WAR);
        lua_setfield(L, -2, "END_WAR");

        lua_pushinteger(L , DA_CLEAR_AI);
        lua_setfield(L, -2, "DA_CLEAR_AI");
        lua_pushinteger(L , DA_CLEAR_AI);
        lua_setfield(L, -2, "CLEAR_AI");

        lua_pushinteger(L , DA_FOLLOW_WHILE_TALKING);
        lua_setfield(L, -2, "DA_FOLLOW_WHILE_TALKING");
        lua_pushinteger(L , DA_FOLLOW_WHILE_TALKING);
        lua_setfield(L, -2, "FOLLOW_WHILE_TALKING");

        lua_pushinteger(L , DA_THUG_HUNTER);
        lua_setfield(L, -2, "DA_THUG_HUNTER");
        lua_pushinteger(L , DA_THUG_HUNTER);
        lua_setfield(L, -2, "THUG_HUNTER");

        lua_pushinteger(L , DA_JOIN_SQUAD_FAST);
        lua_setfield(L, -2, "DA_JOIN_SQUAD_FAST");
        lua_pushinteger(L , DA_JOIN_SQUAD_FAST);
        lua_setfield(L, -2, "JOIN_SQUAD_FAST");

		lua_pushinteger(L , DA_REMEMBER_CHARACTER);
		lua_setfield(L, -2, "DA_REMEMBER_CHARACTER");
		lua_pushinteger(L , DA_REMEMBER_CHARACTER);
		lua_setfield(L, -2, "REMEMBER_CHARACTER");

        lua_pushinteger(L , DA_FLAG_TEMP_ALLY);
        lua_setfield(L, -2, "DA_FLAG_TEMP_ALLY");
        lua_pushinteger(L , DA_FLAG_TEMP_ALLY);
        lua_setfield(L, -2, "FLAG_TEMP_ALLY");

        lua_pushinteger(L , DA_FLAG_TEMP_ENEMY);
        lua_setfield(L, -2, "DA_FLAG_TEMP_ENEMY");
        lua_pushinteger(L , DA_FLAG_TEMP_ENEMY);
        lua_setfield(L, -2, "FLAG_TEMP_ENEMY");

        lua_pushinteger(L , DA_MATES_KILL_ME);
        lua_setfield(L, -2, "DA_MATES_KILL_ME");
        lua_pushinteger(L , DA_MATES_KILL_ME);
        lua_setfield(L, -2, "MATES_KILL_ME");

        lua_pushinteger(L , DA_MAKE_TARGET_RUN_FASTER);
        lua_setfield(L, -2, "DA_MAKE_TARGET_RUN_FASTER");
        lua_pushinteger(L , DA_MAKE_TARGET_RUN_FASTER);
        lua_setfield(L, -2, "MAKE_TARGET_RUN_FASTER");

        lua_pushinteger(L , DA_GIVE_TARGET_MY_SLAVES);
        lua_setfield(L, -2, "DA_GIVE_TARGET_MY_SLAVES");
        lua_pushinteger(L , DA_GIVE_TARGET_MY_SLAVES);
        lua_setfield(L, -2, "GIVE_TARGET_MY_SLAVES");

        lua_pushinteger(L , DA_TAG_ESCAPED_SLAVE);
        lua_setfield(L, -2, "DA_TAG_ESCAPED_SLAVE");
        lua_pushinteger(L , DA_TAG_ESCAPED_SLAVE);
        lua_setfield(L, -2, "TAG_ESCAPED_SLAVE");

        lua_pushinteger(L , DA_FREE_TARGET_SLAVE);
        lua_setfield(L, -2, "DA_FREE_TARGET_SLAVE");
        lua_pushinteger(L , DA_FREE_TARGET_SLAVE);
        lua_setfield(L, -2, "FREE_TARGET_SLAVE");

        lua_pushinteger(L , DA_MERGE_WITH_SIMILAR_SQUADS);
        lua_setfield(L, -2, "DA_MERGE_WITH_SIMILAR_SQUADS");
        lua_pushinteger(L , DA_MERGE_WITH_SIMILAR_SQUADS);
        lua_setfield(L, -2, "MERGE_WITH_SIMILAR_SQUADS");

        lua_pushinteger(L , DA_SEPARATE_TO_MY_OWN_SQUAD);
        lua_setfield(L, -2, "DA_SEPARATE_TO_MY_OWN_SQUAD");
        lua_pushinteger(L , DA_SEPARATE_TO_MY_OWN_SQUAD);
        lua_setfield(L, -2, "SEPARATE_TO_MY_OWN_SQUAD");

        lua_pushinteger(L , DA_ARREST_TARGET);
        lua_setfield(L, -2, "DA_ARREST_TARGET");
        lua_pushinteger(L , DA_ARREST_TARGET);
        lua_setfield(L, -2, "ARREST_TARGET");

        lua_pushinteger(L , DA_ARREST_TARGETS_CARRIED_PERSON);
        lua_setfield(L, -2, "DA_ARREST_TARGETS_CARRIED_PERSON");
        lua_pushinteger(L , DA_ARREST_TARGETS_CARRIED_PERSON);
        lua_setfield(L, -2, "ARREST_TARGETS_CARRIED_PERSON");

		lua_pushinteger(L , DA_ATTACK_TOWN);
		lua_setfield(L, -2, "DA_ATTACK_TOWN");
		lua_pushinteger(L , DA_ATTACK_TOWN);
		lua_setfield(L, -2, "ATTACK_TOWN");

		lua_pushinteger(L , DA_ASSIGN_BOUNTY);
		lua_setfield(L, -2, "DA_ASSIGN_BOUNTY");
		lua_pushinteger(L , DA_ASSIGN_BOUNTY);
		lua_setfield(L, -2, "ASSIGN_BOUNTY");

        lua_pushinteger(L , DA_CRIME_ALARM);
        lua_setfield(L, -2, "DA_CRIME_ALARM");
        lua_pushinteger(L , DA_CRIME_ALARM);
        lua_setfield(L, -2, "CRIME_ALARM");

        lua_pushinteger(L , DA_RUN_AWAY);
        lua_setfield(L, -2, "DA_RUN_AWAY");
        lua_pushinteger(L , DA_RUN_AWAY);
        lua_setfield(L, -2, "RUN_AWAY");

        lua_pushinteger(L , DA_INCREASE_FACTION_RANK);
        lua_setfield(L, -2, "DA_INCREASE_FACTION_RANK");
        lua_pushinteger(L , DA_INCREASE_FACTION_RANK);
        lua_setfield(L, -2, "INCREASE_FACTION_RANK");

        lua_pushinteger(L , DA_LOCK_THIS_DIALOG);
        lua_setfield(L, -2, "DA_LOCK_THIS_DIALOG");
        lua_pushinteger(L , DA_LOCK_THIS_DIALOG);
        lua_setfield(L, -2, "LOCK_THIS_DIALOG");

		lua_pushinteger(L , DA_ASSAULT_PHASE);
		lua_setfield(L, -2, "DA_ASSAULT_PHASE");
		lua_pushinteger(L , DA_ASSAULT_PHASE);
		lua_setfield(L, -2, "ASSAULT_PHASE");

		lua_pushinteger(L , DA_RETREAT_PHASE);
		lua_setfield(L, -2, "DA_RETREAT_PHASE");
		lua_pushinteger(L , DA_RETREAT_PHASE);
		lua_setfield(L, -2, "RETREAT_PHASE");

		lua_pushinteger(L , DA_VICTORY_PHASE);
		lua_setfield(L, -2, "DA_VICTORY_PHASE");
		lua_pushinteger(L , DA_VICTORY_PHASE);
		lua_setfield(L, -2, "VICTORY_PHASE");

		lua_pushinteger(L , DA_ENSLAVE_TARGETS_CARRIED_PERSON);
		lua_setfield(L, -2, "DA_ENSLAVE_TARGETS_CARRIED_PERSON");
		lua_pushinteger(L , DA_ENSLAVE_TARGETS_CARRIED_PERSON);
		lua_setfield(L, -2, "ENSLAVE_TARGETS_CARRIED_PERSON");

        lua_pushinteger(L , DA_CLEAR_BOUNTY);
        lua_setfield(L, -2, "DA_CLEAR_BOUNTY");
        lua_pushinteger(L , DA_CLEAR_BOUNTY);
        lua_setfield(L, -2, "CLEAR_BOUNTY");

        lua_pushinteger(L , DA_PLAYER_SELL_PRISONERS);
        lua_setfield(L, -2, "DA_PLAYER_SELL_PRISONERS");
        lua_pushinteger(L , DA_PLAYER_SELL_PRISONERS);
        lua_setfield(L, -2, "PLAYER_SELL_PRISONERS");

		lua_pushinteger(L , DA_PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE);
		lua_setfield(L, -2, "DA_PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE");
		lua_pushinteger(L , DA_PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE);
		lua_setfield(L, -2, "PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE");

		lua_pushinteger(L , DA_SUMMON_MY_SQUAD);
		lua_setfield(L, -2, "DA_SUMMON_MY_SQUAD");
		lua_pushinteger(L , DA_SUMMON_MY_SQUAD);
		lua_setfield(L, -2, "SUMMON_MY_SQUAD");

		lua_pushinteger(L , DA_REMOVE_SLAVE_STATUS);
		lua_setfield(L, -2, "DA_REMOVE_SLAVE_STATUS");
		lua_pushinteger(L , DA_REMOVE_SLAVE_STATUS);
		lua_setfield(L, -2, "REMOVE_SLAVE_STATUS");

		lua_pushinteger(L , DA_OPEN_NEAREST_GATE);
		lua_setfield(L, -2, "DA_OPEN_NEAREST_GATE");
		lua_pushinteger(L , DA_OPEN_NEAREST_GATE);
		lua_setfield(L, -2, "OPEN_NEAREST_GATE");

		lua_pushinteger(L , DA_ATTACK_STAY_NEAR_HOME);
		lua_setfield(L, -2, "DA_ATTACK_STAY_NEAR_HOME");
		lua_pushinteger(L , DA_ATTACK_STAY_NEAR_HOME);
		lua_setfield(L, -2, "ATTACK_STAY_NEAR_HOME");

		lua_pushinteger(L , DA_MASSIVE_ALARM);
		lua_setfield(L, -2, "DA_MASSIVE_ALARM");
		lua_pushinteger(L , DA_MASSIVE_ALARM);
		lua_setfield(L, -2, "MASSIVE_ALARM");

		lua_pushinteger(L , DA_ATTACK_IF_NO_COEXIST);
		lua_setfield(L, -2, "DA_ATTACK_IF_NO_COEXIST");
		lua_pushinteger(L , DA_ATTACK_IF_NO_COEXIST);
		lua_setfield(L, -2, "ATTACK_IF_NO_COEXIST");

		lua_pushinteger(L , DA_KNOCKOUT);
		lua_setfield(L, -2, "DA_KNOCKOUT");
		lua_pushinteger(L , DA_KNOCKOUT);
		lua_setfield(L, -2, "KNOCKOUT");

        lua_pushinteger(L , DA_END);
        lua_setfield(L, -2, "DA_END");
        lua_pushinteger(L , DA_END);
        lua_setfield(L, -2, "END");

		lua_setglobal(L, "DialogueAction");
    }

	// --------------------------------------------------
    // Enums.h
	// --------------------------------------------------

    void registersItemType(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, itemType::BUILDING);
        lua_setfield(L, -2, "BUILDING");

        lua_pushinteger(L, itemType::CHARACTER);
        lua_setfield(L, -2, "CHARACTER");

        lua_pushinteger(L, itemType::WEAPON);
        lua_setfield(L, -2, "WEAPON");

        lua_pushinteger(L, itemType::ARMOUR);
        lua_setfield(L, -2, "ARMOUR");

        lua_pushinteger(L, itemType::ITEM);
        lua_setfield(L, -2, "ITEM");

        lua_pushinteger(L, itemType::ANIMAL_ANIMATION);
        lua_setfield(L, -2, "ANIMAL_ANIMATION");

        lua_pushinteger(L, itemType::ATTACHMENT);
        lua_setfield(L, -2, "ATTACHMENT");

        lua_pushinteger(L, itemType::RACE);
        lua_setfield(L, -2, "RACE");

        lua_pushinteger(L, itemType::LOCATION);
        lua_setfield(L, -2, "LOCATION");

        lua_pushinteger(L, itemType::WAR_SAVESTATE);
        lua_setfield(L, -2, "WAR_SAVESTATE");

        lua_pushinteger(L, itemType::FACTION);
        lua_setfield(L, -2, "FACTION");

        lua_pushinteger(L, itemType::NULL_ITEM);
        lua_setfield(L, -2, "NULL_ITEM");

        lua_pushinteger(L, itemType::ZONE_MAP);
        lua_setfield(L, -2, "ZONE_MAP");

        lua_pushinteger(L, itemType::TOWN);
        lua_setfield(L, -2, "TOWN");

        lua_pushinteger(L, itemType::WORLDMAP_CHARACTER);
        lua_setfield(L, -2, "WORLDMAP_CHARACTER");

        lua_pushinteger(L, itemType::CHARACTER_APPEARANCE_OLD);
        lua_setfield(L, -2, "CHARACTER_APPEARANCE_OLD");

        lua_pushinteger(L, itemType::LOCATIONAL_DAMAGE);
        lua_setfield(L, -2, "LOCATIONAL_DAMAGE");

        lua_pushinteger(L, itemType::COMBAT_TECHNIQUE);
        lua_setfield(L, -2, "COMBAT_TECHNIQUE");

        lua_pushinteger(L, itemType::DIALOGUE);
        lua_setfield(L, -2, "DIALOGUE");

        lua_pushinteger(L, itemType::DIALOGUE_LINE);
        lua_setfield(L, -2, "DIALOGUE_LINE");

        lua_pushinteger(L, itemType::TECHTREE);
        lua_setfield(L, -2, "TECHTREE");

        lua_pushinteger(L, itemType::RESEARCH);
        lua_setfield(L, -2, "RESEARCH");

        lua_pushinteger(L, itemType::AI_TASK);
        lua_setfield(L, -2, "AI_TASK");

        lua_pushinteger(L, itemType::AI_STATE);
        lua_setfield(L, -2, "AI_STATE");

        lua_pushinteger(L, itemType::ANIMATION);
        lua_setfield(L, -2, "ANIMATION");

        lua_pushinteger(L, itemType::STATS);
        lua_setfield(L, -2, "STATS");

        lua_pushinteger(L, itemType::PERSONALITY);
        lua_setfield(L, -2, "PERSONALITY");

        lua_pushinteger(L, itemType::CONSTANTS);
        lua_setfield(L, -2, "CONSTANTS");

        lua_pushinteger(L, itemType::BIOMES);
        lua_setfield(L, -2, "BIOMES");

        lua_pushinteger(L, itemType::BUILDING_PART);
        lua_setfield(L, -2, "BUILDING_PART");

        lua_pushinteger(L, itemType::INSTANCE_COLLECTION);
        lua_setfield(L, -2, "INSTANCE_COLLECTION");

        lua_pushinteger(L, itemType::DIALOG_ACTION);
        lua_setfield(L, -2, "DIALOG_ACTION");

        lua_pushinteger(L, itemType::TEMPORARY_INFO);
        lua_setfield(L, -2, "TEMPORARY_INFO");

        lua_pushinteger(L, itemType::MOD_FILENAME);
        lua_setfield(L, -2, "MOD_FILENAME");

        lua_pushinteger(L, itemType::PLATOON);
        lua_setfield(L, -2, "PLATOON");

        lua_pushinteger(L, itemType::GAMESTATE_BUILDING);
        lua_setfield(L, -2, "GAMESTATE_BUILDING");

        lua_pushinteger(L, itemType::GAMESTATE_CHARACTER);
        lua_setfield(L, -2, "GAMESTATE_CHARACTER");

        lua_pushinteger(L, itemType::GAMESTATE_FACTION);
        lua_setfield(L, -2, "GAMESTATE_FACTION");

        lua_pushinteger(L, itemType::GAMESTATE_TOWN_INSTANCE_LIST);
        lua_setfield(L, -2, "GAMESTATE_TOWN_INSTANCE_LIST");

        lua_pushinteger(L, itemType::STATE);
        lua_setfield(L, -2, "STATE");

        lua_pushinteger(L, itemType::SAVED_STATE);
        lua_setfield(L, -2, "SAVED_STATE");

        lua_pushinteger(L, itemType::INVENTORY_STATE);
        lua_setfield(L, -2, "INVENTORY_STATE");

        lua_pushinteger(L, itemType::INVENTORY_ITEM_STATE);
        lua_setfield(L, -2, "INVENTORY_ITEM_STATE");

        lua_pushinteger(L, itemType::REPEATABLE_BUILDING_PART_SLOT);
        lua_setfield(L, -2, "REPEATABLE_BUILDING_PART_SLOT");

        lua_pushinteger(L, itemType::MATERIAL_SPEC);
        lua_setfield(L, -2, "MATERIAL_SPEC");

        lua_pushinteger(L, itemType::MATERIAL_SPECS_COLLECTION);
        lua_setfield(L, -2, "MATERIAL_SPECS_COLLECTION");

        lua_pushinteger(L, itemType::CONTAINER);
        lua_setfield(L, -2, "CONTAINER");

        lua_pushinteger(L, itemType::MATERIAL_SPECS_CLOTHING);
        lua_setfield(L, -2, "MATERIAL_SPECS_CLOTHING");

        lua_pushinteger(L, itemType::GAMESTATE_BUILDING_INTERIOR);
        lua_setfield(L, -2, "GAMESTATE_BUILDING_INTERIOR");

        lua_pushinteger(L, itemType::VENDOR_LIST);
        lua_setfield(L, -2, "VENDOR_LIST");

        lua_pushinteger(L, itemType::MATERIAL_SPECS_WEAPON);
        lua_setfield(L, -2, "MATERIAL_SPECS_WEAPON");

        lua_pushinteger(L, itemType::WEAPON_MANUFACTURER);
        lua_setfield(L, -2, "WEAPON_MANUFACTURER");

        lua_pushinteger(L, itemType::SQUAD_TEMPLATE);
        lua_setfield(L, -2, "SQUAD_TEMPLATE");

        lua_pushinteger(L, itemType::ROAD);
        lua_setfield(L, -2, "ROAD");

        lua_pushinteger(L, itemType::LOCATION_NODE);
        lua_setfield(L, -2, "LOCATION_NODE");

        lua_pushinteger(L, itemType::COLOR_DATA);
        lua_setfield(L, -2, "COLOR_DATA");

        lua_pushinteger(L, itemType::CAMERA);
        lua_setfield(L, -2, "CAMERA");

        lua_pushinteger(L, itemType::MEDICAL_STATE);
        lua_setfield(L, -2, "MEDICAL_STATE");

        lua_pushinteger(L, itemType::MEDICAL_PART_STATE);
        lua_setfield(L, -2, "MEDICAL_PART_STATE");

        lua_pushinteger(L, itemType::FOLIAGE_LAYER);
        lua_setfield(L, -2, "FOLIAGE_LAYER");

        lua_pushinteger(L, itemType::FOLIAGE_MESH);
        lua_setfield(L, -2, "FOLIAGE_MESH");

        lua_pushinteger(L, itemType::GRASS);
        lua_setfield(L, -2, "GRASS");

        lua_pushinteger(L, itemType::BUILDING_FUNCTIONALITY);
        lua_setfield(L, -2, "BUILDING_FUNCTIONALITY");

        lua_pushinteger(L, itemType::DAY_SCHEDULE);
        lua_setfield(L, -2, "DAY_SCHEDULE");

        lua_pushinteger(L, itemType::NEW_GAME_STARTOFF);
        lua_setfield(L, -2, "NEW_GAME_STARTOFF");

        lua_pushinteger(L, itemType::GAMESTATE_CRAFTING);
        lua_setfield(L, -2, "GAMESTATE_CRAFTING");

        lua_pushinteger(L, itemType::CHARACTER_APPEARANCE);
        lua_setfield(L, -2, "CHARACTER_APPEARANCE");

        lua_pushinteger(L, itemType::GAMESTATE_AI);
        lua_setfield(L, -2, "GAMESTATE_AI");

        lua_pushinteger(L, itemType::WILDLIFE_BIRDS);
        lua_setfield(L, -2, "WILDLIFE_BIRDS");

        lua_pushinteger(L, itemType::MAP_FEATURES);
        lua_setfield(L, -2, "MAP_FEATURES");

        lua_pushinteger(L, itemType::DIPLOMATIC_ASSAULTS);
        lua_setfield(L, -2, "DIPLOMATIC_ASSAULTS");

        lua_pushinteger(L, itemType::SINGLE_DIPLOMATIC_ASSAULT);
        lua_setfield(L, -2, "SINGLE_DIPLOMATIC_ASSAULT");

        lua_pushinteger(L, itemType::AI_PACKAGE);
        lua_setfield(L, -2, "AI_PACKAGE");

        lua_pushinteger(L, itemType::DIALOGUE_PACKAGE);
        lua_setfield(L, -2, "DIALOGUE_PACKAGE");

        lua_pushinteger(L, itemType::GUN_DATA);
        lua_setfield(L, -2, "GUN_DATA");

        lua_pushinteger(L, itemType::HUMAN_CHARACTER);
        lua_setfield(L, -2, "HUMAN_CHARACTER");

        lua_pushinteger(L, itemType::ANIMAL_CHARACTER);
        lua_setfield(L, -2, "ANIMAL_CHARACTER");

        lua_pushinteger(L, itemType::UNIQUE_SQUAD_TEMPLATE);
        lua_setfield(L, -2, "UNIQUE_SQUAD_TEMPLATE");

        lua_pushinteger(L, itemType::FACTION_TEMPLATE);
        lua_setfield(L, -2, "FACTION_TEMPLATE");

        lua_pushinteger(L, itemType::AI_SCHEDULE);
        lua_setfield(L, -2, "AI_SCHEDULE");

        lua_pushinteger(L, itemType::WEATHER);
        lua_setfield(L, -2, "WEATHER");

        lua_pushinteger(L, itemType::SEASON);
        lua_setfield(L, -2, "SEASON");

        lua_pushinteger(L, itemType::EFFECT);
        lua_setfield(L, -2, "EFFECT");

        lua_pushinteger(L, itemType::ITEM_PLACEMENT_GROUP);
        lua_setfield(L, -2, "ITEM_PLACEMENT_GROUP");

        lua_pushinteger(L, itemType::WORD_SWAPS);
        lua_setfield(L, -2, "WORD_SWAPS");

        lua_pushinteger(L, itemType::NEST);
        lua_setfield(L, -2, "NEST");

        lua_pushinteger(L, itemType::NEST_ITEM);
        lua_setfield(L, -2, "NEST_ITEM");

        lua_pushinteger(L, itemType::CHARACTER_PHYSICS_ATTACHMENT);
        lua_setfield(L, -2, "CHARACTER_PHYSICS_ATTACHMENT");

        lua_pushinteger(L, itemType::LIGHT);
        lua_setfield(L, -2, "LIGHT");

        lua_pushinteger(L, itemType::HEAD);
        lua_setfield(L, -2, "HEAD");

        lua_pushinteger(L, itemType::BLUEPRINT);
        lua_setfield(L, -2, "BLUEPRINT");

        lua_pushinteger(L, itemType::SHOP_TRADER_CLASS);
        lua_setfield(L, -2, "SHOP_TRADER_CLASS");

        lua_pushinteger(L, itemType::FOLIAGE_BUILDING);
        lua_setfield(L, -2, "FOLIAGE_BUILDING");

        lua_pushinteger(L, itemType::FACTION_CAMPAIGN);
        lua_setfield(L, -2, "FACTION_CAMPAIGN");

        lua_pushinteger(L, itemType::GAMESTATE_TOWN);
        lua_setfield(L, -2, "GAMESTATE_TOWN");

        lua_pushinteger(L, itemType::BIOME_GROUP);
        lua_setfield(L, -2, "BIOME_GROUP");

        lua_pushinteger(L, itemType::EFFECT_FOG_VOLUME);
        lua_setfield(L, -2, "EFFECT_FOG_VOLUME");

        lua_pushinteger(L, itemType::FARM_DATA);
        lua_setfield(L, -2, "FARM_DATA");

        lua_pushinteger(L, itemType::FARM_PART);
        lua_setfield(L, -2, "FARM_PART");

        lua_pushinteger(L, itemType::ENVIRONMENT_RESOURCES);
        lua_setfield(L, -2, "ENVIRONMENT_RESOURCES");

        lua_pushinteger(L, itemType::RACE_GROUP);
        lua_setfield(L, -2, "RACE_GROUP");

        lua_pushinteger(L, itemType::ARTIFACTS);
        lua_setfield(L, -2, "ARTIFACTS");

        lua_pushinteger(L, itemType::MAP_ITEM);
        lua_setfield(L, -2, "MAP_ITEM");

        lua_pushinteger(L, itemType::BUILDINGS_SWAP);
        lua_setfield(L, -2, "BUILDINGS_SWAP");

        lua_pushinteger(L, itemType::ITEMS_CULTURE);
        lua_setfield(L, -2, "ITEMS_CULTURE");

        lua_pushinteger(L, itemType::ANIMATION_EVENT);
        lua_setfield(L, -2, "ANIMATION_EVENT");

        lua_pushinteger(L, itemType::TUTORIAL);
        lua_setfield(L, -2, "TUTORIAL");

        lua_pushinteger(L, itemType::CROSSBOW);
        lua_setfield(L, -2, "CROSSBOW");

        lua_pushinteger(L, itemType::TERRAIN_DECALS);
        lua_setfield(L, -2, "TERRAIN_DECALS");

        lua_pushinteger(L, itemType::AMBIENT_SOUND);
        lua_setfield(L, -2, "AMBIENT_SOUND");

        lua_pushinteger(L, itemType::WORLD_EVENT_STATE);
        lua_setfield(L, -2, "WORLD_EVENT_STATE");

        lua_pushinteger(L, itemType::LIMB_REPLACEMENT);
        lua_setfield(L, -2, "LIMB_REPLACEMENT");

        lua_pushinteger(L, itemType::ANIMATION_FILE);
        lua_setfield(L, -2, "ANIMATION_FILE");

        lua_pushinteger(L, itemType::____XXX___);
        lua_setfield(L, -2, "___XXX___");

        lua_pushinteger(L, itemType::OBJECT_TYPE_MAX);
        lua_setfield(L, -2, "OBJECT_TYPE_MAX");

        lua_setglobal(L, "itemType");
    }

    void registerBuildingFunction(lua_State* L)
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

    void registerCutDirection(lua_State* L)
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

    void registerCutOrigination(lua_State* L)
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

    void registerHitMaterialType(lua_State* L)
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

    void registerWeatherAffecting(lua_State* L)
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

    void registerAttachSlot(lua_State* L)
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

    void registerItemFunction(lua_State* L)
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

    void registerArmourType(lua_State* L)
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

    void registerCharacterTypeEnum(lua_State* L)
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

    void registerSlaveStateEnum(lua_State* L)
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

        lua_pushvalue(L, -1);
        lua_setglobal(L, "SlaveStateEnum");
        lua_setglobal(L, "SlaveState");
    }

    void registerTaskType(lua_State* L)
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

    void registerWeaponCategory(lua_State* L)
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

    void registerLeftRight(lua_State* L)
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

    void registerMessageType(lua_State* L)
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

    void registerStandingOrder(lua_State* L)
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

    void registerStatsEnumerated(lua_State* L)
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


        lua_pushvalue(L, -1);
        lua_setglobal(L, "StatsEnumerated");
        lua_setglobal(L, "Stats");
    }

    void registerEventTriggerEnum(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, EventTriggerEnum::EV_NONE);
        lua_setfield(L, -2, "EV_NONE");
        lua_pushinteger(L, EventTriggerEnum::EV_NONE);
        lua_setfield(L, -2, "NONE");

        lua_pushinteger(L, EventTriggerEnum::EV_PLAYER_TALK_TO_ME);
        lua_setfield(L, -2, "EV_PLAYER_TALK_TO_ME");
        lua_pushinteger(L, EventTriggerEnum::EV_PLAYER_TALK_TO_ME);
        lua_setfield(L, -2, "PLAYER_TALK_TO_ME");

        lua_pushinteger(L, EventTriggerEnum::EV_ANNOUNCEMENT);
        lua_setfield(L, -2, "EV_ANNOUNCEMENT");
        lua_pushinteger(L, EventTriggerEnum::EV_ANNOUNCEMENT);
        lua_setfield(L, -2, "ANNOUNCEMENT");

        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_NEUTRAL_SQUAD);
        lua_setfield(L, -2, "EV_I_SEE_NEUTRAL_SQUAD");
        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_NEUTRAL_SQUAD);
        lua_setfield(L, -2, "I_SEE_NEUTRAL_SQUAD");

        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_RAGDOLL);
        lua_setfield(L, -2, "EV_I_SEE_RAGDOLL");
        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_RAGDOLL);
        lua_setfield(L, -2, "I_SEE_RAGDOLL");

        lua_pushinteger(L, EventTriggerEnum::EV_______);
        lua_setfield(L, -2, "EV_______");
        lua_pushinteger(L, EventTriggerEnum::EV_______);
        lua_setfield(L, -2, "______");

        lua_pushinteger(L, EventTriggerEnum::EV_I_________);
        lua_setfield(L, -2, "EV_I_________");
        lua_pushinteger(L, EventTriggerEnum::EV_I_________);
        lua_setfield(L, -2, "I_________");

        lua_pushinteger(L, EventTriggerEnum::EV_SHOO_FROM_MY_BUILDING);
        lua_setfield(L, -2, "EV_SHOO_FROM_MY_BUILDING");
        lua_pushinteger(L, EventTriggerEnum::EV_SHOO_FROM_MY_BUILDING);
        lua_setfield(L, -2, "SHOO_FROM_MY_BUILDING");

        lua_pushinteger(L, EventTriggerEnum::EV_MARKED_FOR_DEATH);
        lua_setfield(L, -2, "EV_MARKED_FOR_DEATH");
        lua_pushinteger(L, EventTriggerEnum::EV_MARKED_FOR_DEATH);
        lua_setfield(L, -2, "MARKED_FOR_DEATH");

        lua_pushinteger(L, EventTriggerEnum::EV_SCREAMING_TORTURE);
        lua_setfield(L, -2, "EV_SCREAMING_TORTURE");
        lua_pushinteger(L, EventTriggerEnum::EV_SCREAMING_TORTURE);
        lua_setfield(L, -2, "SCREAMING_TORTURE");

        lua_pushinteger(L, EventTriggerEnum::EV_BAR_TALK);
        lua_setfield(L, -2, "EV_BAR_TALK");
        lua_pushinteger(L, EventTriggerEnum::EV_BAR_TALK);
        lua_setfield(L, -2, "BAR_TALK");

        lua_pushinteger(L, EventTriggerEnum::EV_UNLOCK_MY_CAGE_OR_SHACKLES);
        lua_setfield(L, -2, "EV_UNLOCK_MY_CAGE_OR_SHACKLES");
        lua_pushinteger(L, EventTriggerEnum::EV_UNLOCK_MY_CAGE_OR_SHACKLES);
        lua_setfield(L, -2, "UNLOCK_MY_CAGE_OR_SHACKLES");

        lua_pushinteger(L, EventTriggerEnum::EV_UNLOCK_MY_CAGE_ATTEMPT);
        lua_setfield(L, -2, "EV_UNLOCK_MY_CAGE_ATTEMPT");
        lua_pushinteger(L, EventTriggerEnum::EV_UNLOCK_MY_CAGE_ATTEMPT);
        lua_setfield(L, -2, "UNLOCK_MY_CAGE_ATTEMPT");

        lua_pushinteger(L, EventTriggerEnum::EV_I_DEFEATED_SQUAD);
        lua_setfield(L, -2, "EV_I_DEFEATED_SQUAD");
        lua_pushinteger(L, EventTriggerEnum::EV_I_DEFEATED_SQUAD);
        lua_setfield(L, -2, "I_DEFEATED_SQUAD");

        lua_pushinteger(L, EventTriggerEnum::EV_LAUNCH_ATTACK);
        lua_setfield(L, -2, "EV_LAUNCH_ATTACK");
        lua_pushinteger(L, EventTriggerEnum::EV_LAUNCH_ATTACK);
        lua_setfield(L, -2, "LAUNCH_ATTACK");

        lua_pushinteger(L, EventTriggerEnum::EV_INTRUDER_FOUND);
        lua_setfield(L, -2, "EV_INTRUDER_FOUND");
        lua_pushinteger(L, EventTriggerEnum::EV_INTRUDER_FOUND);
        lua_setfield(L, -2, "INTRUDER_FOUND");

        lua_pushinteger(L, EventTriggerEnum::EV_HEALING_OTHER_START);
        lua_setfield(L, -2, "EV_HEALING_OTHER_START");
        lua_pushinteger(L, EventTriggerEnum::EV_HEALING_OTHER_START);
        lua_setfield(L, -2, "HEALING_OTHER_START");

        lua_pushinteger(L, EventTriggerEnum::EV_BEING_HEALED_START);
        lua_setfield(L, -2, "EV_BEING_HEALED_START");
        lua_pushinteger(L, EventTriggerEnum::EV_BEING_HEALED_START);
        lua_setfield(L, -2, "BEING_HEALED_START");

        lua_pushinteger(L, EventTriggerEnum::EV_HEALING_OTHER_FINISHED);
        lua_setfield(L, -2, "EV_HEALING_OTHER_FINISHED");
        lua_pushinteger(L, EventTriggerEnum::EV_HEALING_OTHER_FINISHED);
        lua_setfield(L, -2, "HEALING_OTHER_FINISHED");

        lua_pushinteger(L, EventTriggerEnum::EV_BEING_HEALED_FINISHED);
        lua_setfield(L, -2, "EV_BEING_HEALED_FINISHED");
        lua_pushinteger(L, EventTriggerEnum::EV_BEING_HEALED_FINISHED);
        lua_setfield(L, -2, "BEING_HEALED_FINISHED");

        lua_pushinteger(L, EventTriggerEnum::EV_FIRSTAID_KIT_EMPTY);
        lua_setfield(L, -2, "EV_FIRSTAID_KIT_EMPTY");
        lua_pushinteger(L, EventTriggerEnum::EV_FIRSTAID_KIT_EMPTY);
        lua_setfield(L, -2, "FIRSTAID_KIT_EMPTY");

        lua_pushinteger(L, EventTriggerEnum::EV_GET_UP_PEACE);
        lua_setfield(L, -2, "EV_GET_UP_PEACE");
        lua_pushinteger(L, EventTriggerEnum::EV_GET_UP_PEACE);
        lua_setfield(L, -2, "GET_UP_PEACE");

        lua_pushinteger(L, EventTriggerEnum::EV_GET_UP_FIGHT);
        lua_setfield(L, -2, "EV_GET_UP_FIGHT");
        lua_pushinteger(L, EventTriggerEnum::EV_GET_UP_FIGHT);
        lua_setfield(L, -2, "GET_UP_FIGHT");

        lua_pushinteger(L, EventTriggerEnum::EV_GET_UP_UNNECCESSARY_FIGHT);
        lua_setfield(L, -2, "EV_GET_UP_UNNECCESSARY_FIGHT");
        lua_pushinteger(L, EventTriggerEnum::EV_GET_UP_UNNECCESSARY_FIGHT);
        lua_setfield(L, -2, "GET_UP_UNNECCESSARY_FIGHT");

        lua_pushinteger(L, EventTriggerEnum::EV_HARRASSMENT_SHOUTS);
        lua_setfield(L, -2, "EV_HARRASSMENT_SHOUTS");
        lua_pushinteger(L, EventTriggerEnum::EV_HARRASSMENT_SHOUTS);
        lua_setfield(L, -2, "HARRASSMENT_SHOUTS");

        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_ANIMAL_SQUAD);
        lua_setfield(L, -2, "EV_I_SEE_ANIMAL_SQUAD");
        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_ANIMAL_SQUAD);
        lua_setfield(L, -2, "I_SEE_ANIMAL_SQUAD");

        lua_pushinteger(L, EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_TARGET);
        lua_setfield(L, -2, "EV_SPEECH_INTERRUPTED_ATTACKED_BY_TARGET");
        lua_pushinteger(L, EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_TARGET);
        lua_setfield(L, -2, "SPEECH_INTERRUPTED_ATTACKED_BY_TARGET");

        lua_pushinteger(L, EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS);
        lua_setfield(L, -2, "EV_SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS");
        lua_pushinteger(L, EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS);
        lua_setfield(L, -2, "SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS");

        lua_pushinteger(L, EventTriggerEnum::EV_CONTRACT_JOB_ENDED);
        lua_setfield(L, -2, "EV_CONTRACT_JOB_ENDED");
        lua_pushinteger(L, EventTriggerEnum::EV_CONTRACT_JOB_ENDED);
        lua_setfield(L, -2, "CONTRACT_JOB_ENDED");

        lua_pushinteger(L, EventTriggerEnum::EV_BETRAYAL);
        lua_setfield(L, -2, "EV_BETRAYAL");
        lua_pushinteger(L, EventTriggerEnum::EV_BETRAYAL);
        lua_setfield(L, -2, "BETRAYAL");

        lua_pushinteger(L, EventTriggerEnum::EV_LOOTING_WEAPON_ONLY);
        lua_setfield(L, -2, "EV_LOOTING_WEAPON_ONLY");
        lua_pushinteger(L, EventTriggerEnum::EV_LOOTING_WEAPON_ONLY);
        lua_setfield(L, -2, "LOOTING_WEAPON_ONLY");

        lua_pushinteger(L, EventTriggerEnum::EV_LOOTING_EVERYTHING);
        lua_setfield(L, -2, "EV_LOOTING_EVERYTHING");
        lua_pushinteger(L, EventTriggerEnum::EV_LOOTING_EVERYTHING);
        lua_setfield(L, -2, "LOOTING_EVERYTHING");

        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_UNIFORM_IMPOSTER);
        lua_setfield(L, -2, "EV_I_SEE_UNIFORM_IMPOSTER");
        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_UNIFORM_IMPOSTER);
        lua_setfield(L, -2, "I_SEE_UNIFORM_IMPOSTER");

        lua_pushinteger(L, EventTriggerEnum::EV_INTRODUCING_NEW_SLAVE);
        lua_setfield(L, -2, "EV_INTRODUCING_NEW_SLAVE");
        lua_pushinteger(L, EventTriggerEnum::EV_INTRODUCING_NEW_SLAVE);
        lua_setfield(L, -2, "INTRODUCING_NEW_SLAVE");

        lua_pushinteger(L, EventTriggerEnum::EV_ESCAPING_SLAVE_SPOTTED);
        lua_setfield(L, -2, "EV_ESCAPING_SLAVE_SPOTTED");
        lua_pushinteger(L, EventTriggerEnum::EV_ESCAPING_SLAVE_SPOTTED);
        lua_setfield(L, -2, "ESCAPING_SLAVE_SPOTTED");

        lua_pushinteger(L, EventTriggerEnum::EV_RECAPTURED_A_SLAVE);
        lua_setfield(L, -2, "EV_RECAPTURED_A_SLAVE");
        lua_pushinteger(L, EventTriggerEnum::EV_RECAPTURED_A_SLAVE);
        lua_setfield(L, -2, "RECAPTURED_A_SLAVE");

        lua_pushinteger(L, EventTriggerEnum::EV_SHOUT_AT_SLAVE_WORKER);
        lua_setfield(L, -2, "EV_SHOUT_AT_SLAVE_WORKER");
        lua_pushinteger(L, EventTriggerEnum::EV_SHOUT_AT_SLAVE_WORKER);
        lua_setfield(L, -2, "SHOUT_AT_SLAVE_WORKER");

        lua_pushinteger(L, EventTriggerEnum::EV_SLAVE_DELIVERY);
        lua_setfield(L, -2, "EV_SLAVE_DELIVERY");
        lua_pushinteger(L, EventTriggerEnum::EV_SLAVE_DELIVERY);
        lua_setfield(L, -2, "SLAVE_DELIVERY");

        lua_pushinteger(L, EventTriggerEnum::EV_ESCAPED_EX_SLAVE_SPOTTED);
        lua_setfield(L, -2, "EV_ESCAPED_EX_SLAVE_SPOTTED");
        lua_pushinteger(L, EventTriggerEnum::EV_ESCAPED_EX_SLAVE_SPOTTED);
        lua_setfield(L, -2, "ESCAPED_EX_SLAVE_SPOTTED");

        lua_pushinteger(L, EventTriggerEnum::EV_WITNESS_GENERIC_ASSAULT);
        lua_setfield(L, -2, "EV_WITNESS_GENERIC_ASSAULT");
        lua_pushinteger(L, EventTriggerEnum::EV_WITNESS_GENERIC_ASSAULT);
        lua_setfield(L, -2, "WITNESS_GENERIC_ASSAULT");

        lua_pushinteger(L, EventTriggerEnum::EV_WITNESS_LOOTING_ALLY);
        lua_setfield(L, -2, "EV_WITNESS_LOOTING_ALLY");
        lua_pushinteger(L, EventTriggerEnum::EV_WITNESS_LOOTING_ALLY);
        lua_setfield(L, -2, "WITNESS_LOOTING_ALLY");

        lua_pushinteger(L, EventTriggerEnum::EV_WITNESS_THIEF_OR_LOCKPICK);
        lua_setfield(L, -2, "EV_WITNESS_THIEF_OR_LOCKPICK");
        lua_pushinteger(L, EventTriggerEnum::EV_WITNESS_THIEF_OR_LOCKPICK);
        lua_setfield(L, -2, "WITNESS_THIEF_OR_LOCKPICK");

        lua_pushinteger(L, EventTriggerEnum::EV_BOUNTY_SPOTTED);
        lua_setfield(L, -2, "EV_BOUNTY_SPOTTED");
        lua_pushinteger(L, EventTriggerEnum::EV_BOUNTY_SPOTTED);
        lua_setfield(L, -2, "BOUNTY_SPOTTED");

        lua_pushinteger(L, EventTriggerEnum::EV_ESCAPED_PRISONER_SPOTTED);
        lua_setfield(L, -2, "EV_ESCAPED_PRISONER_SPOTTED");
        lua_pushinteger(L, EventTriggerEnum::EV_ESCAPED_PRISONER_SPOTTED);
        lua_setfield(L, -2, "ESCAPED_PRISONER_SPOTTED");

        lua_pushinteger(L, EventTriggerEnum::EV_PRISONER_FREE_TO_GO);
        lua_setfield(L, -2, "EV_PRISONER_FREE_TO_GO");
        lua_pushinteger(L, EventTriggerEnum::EV_PRISONER_FREE_TO_GO);
        lua_setfield(L, -2, "PRISONER_FREE_TO_GO");

        lua_pushinteger(L, EventTriggerEnum::EV_ALMOST_WOKE_UP);
        lua_setfield(L, -2, "EV_ALMOST_WOKE_UP");
        lua_pushinteger(L, EventTriggerEnum::EV_ALMOST_WOKE_UP);
        lua_setfield(L, -2, "ALMOST_WOKE_UP");

        lua_pushinteger(L, EventTriggerEnum::EV_ENTER_BIOME);
        lua_setfield(L, -2, "EV_ENTER_BIOME");
        lua_pushinteger(L, EventTriggerEnum::EV_ENTER_BIOME);
        lua_setfield(L, -2, "ENTER_BIOME");

        lua_pushinteger(L, EventTriggerEnum::EV_ENTER_TOWN);
        lua_setfield(L, -2, "EV_ENTER_TOWN");
        lua_pushinteger(L, EventTriggerEnum::EV_ENTER_TOWN);
        lua_setfield(L, -2, "ENTER_TOWN");

        lua_pushinteger(L, EventTriggerEnum::EV_SQUAD_BROKEN);
        lua_setfield(L, -2, "EV_SQUAD_BROKEN");
        lua_pushinteger(L, EventTriggerEnum::EV_SQUAD_BROKEN);
        lua_setfield(L, -2, "SQUAD_BROKEN");

        lua_pushinteger(L, EventTriggerEnum::EV_BOUGHT_ME_FROM_SLAVERY);
        lua_setfield(L, -2, "EV_BOUGHT_ME_FROM_SLAVERY");
        lua_pushinteger(L, EventTriggerEnum::EV_BOUGHT_ME_FROM_SLAVERY);
        lua_setfield(L, -2, "BOUGHT_ME_FROM_SLAVERY");

        lua_pushinteger(L, EventTriggerEnum::EV_EATING_SOMETHING_SOUNDS);
        lua_setfield(L, -2, "EV_EATING_SOMETHING_SOUNDS");
        lua_pushinteger(L, EventTriggerEnum::EV_EATING_SOMETHING_SOUNDS);
        lua_setfield(L, -2, "EATING_SOMETHING_SOUNDS");

        lua_pushinteger(L, EventTriggerEnum::EV_WORSHIPING_SOMETHING);
        lua_setfield(L, -2, "EV_WORSHIPING_SOMETHING");
        lua_pushinteger(L, EventTriggerEnum::EV_WORSHIPING_SOMETHING);
        lua_setfield(L, -2, "WORSHIPING_SOMETHING");

        lua_pushinteger(L, EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_SAVIOR);
        lua_setfield(L, -2, "EV_SLAVE_ESCAPE_OPPORTUNITY_SAVIOR");
        lua_pushinteger(L, EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_SAVIOR);
        lua_setfield(L, -2, "SLAVE_ESCAPE_OPPORTUNITY_SAVIOR");

        lua_pushinteger(L, EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_ALONE);
        lua_setfield(L, -2, "EV_SLAVE_ESCAPE_OPPORTUNITY_ALONE");
        lua_pushinteger(L, EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_ALONE);
        lua_setfield(L, -2, "SLAVE_ESCAPE_OPPORTUNITY_ALONE");

        lua_pushinteger(L, EventTriggerEnum::EV_ASSASSINATION_FAILED);
        lua_setfield(L, -2, "EV_ASSASSINATION_FAILED");
        lua_pushinteger(L, EventTriggerEnum::EV_ASSASSINATION_FAILED);
        lua_setfield(L, -2, "ASSASSINATION_FAILED");

        lua_pushinteger(L, EventTriggerEnum::EV_EATING_MY_CROPS);
        lua_setfield(L, -2, "EV_EATING_MY_CROPS");
        lua_pushinteger(L, EventTriggerEnum::EV_EATING_MY_CROPS);
        lua_setfield(L, -2, "EATING_MY_CROPS");

        lua_pushinteger(L, EventTriggerEnum::EV_KIDNAPPING_MY_ALLY);
        lua_setfield(L, -2, "EV_KIDNAPPING_MY_ALLY");
        lua_pushinteger(L, EventTriggerEnum::EV_KIDNAPPING_MY_ALLY);
        lua_setfield(L, -2, "KIDNAPPING_MY_ALLY");

        lua_pushinteger(L, EventTriggerEnum::EV_USING_MY_TRAINING_EQUIPMENT);
        lua_setfield(L, -2, "EV_USING_MY_TRAINING_EQUIPMENT");
        lua_pushinteger(L, EventTriggerEnum::EV_USING_MY_TRAINING_EQUIPMENT);
        lua_setfield(L, -2, "USING_MY_TRAINING_EQUIPMENT");

        lua_pushinteger(L, EventTriggerEnum::EV_GIVE_UP_CHASE);
        lua_setfield(L, -2, "EV_GIVE_UP_CHASE");
        lua_pushinteger(L, EventTriggerEnum::EV_GIVE_UP_CHASE);
        lua_setfield(L, -2, "GIVE_UP_CHASE");

        lua_pushinteger(L, EventTriggerEnum::EV_ACID_FEET);
        lua_setfield(L, -2, "EV_ACID_FEET");
        lua_pushinteger(L, EventTriggerEnum::EV_ACID_FEET);
        lua_setfield(L, -2, "ACID_FEET");

        lua_pushinteger(L, EventTriggerEnum::EV_ACID_RAIN);
        lua_setfield(L, -2, "EV_ACID_RAIN");
        lua_pushinteger(L, EventTriggerEnum::EV_ACID_RAIN);
        lua_setfield(L, -2, "ACID_RAIN");

        lua_pushinteger(L, EventTriggerEnum::EV_ACID_WATER);
        lua_setfield(L, -2, "EV_ACID_WATER");
        lua_pushinteger(L, EventTriggerEnum::EV_ACID_WATER);
        lua_setfield(L, -2, "ACID_WATER");

        lua_pushinteger(L, EventTriggerEnum::EV_WINDY);
        lua_setfield(L, -2, "EV_WINDY");
        lua_pushinteger(L, EventTriggerEnum::EV_WINDY);
        lua_setfield(L, -2, "WINDY");

        lua_pushinteger(L, EventTriggerEnum::EV_POISON_GAS);
        lua_setfield(L, -2, "EV_POISON_GAS");
        lua_pushinteger(L, EventTriggerEnum::EV_POISON_GAS);
        lua_setfield(L, -2, "POISON_GAS");

        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_ENEMY_PLAYER);
        lua_setfield(L, -2, "EV_I_SEE_ENEMY_PLAYER");
        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_ENEMY_PLAYER);
        lua_setfield(L, -2, "I_SEE_ENEMY_PLAYER");

        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_ALLY_PLAYER);
        lua_setfield(L, -2, "EV_I_SEE_ALLY_PLAYER");
        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_ALLY_PLAYER);
        lua_setfield(L, -2, "I_SEE_ALLY_PLAYER");

        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_ILLEGAL_PLAYER_BUILDING);
        lua_setfield(L, -2, "EV_I_SEE_ILLEGAL_PLAYER_BUILDING");
        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_ILLEGAL_PLAYER_BUILDING);
        lua_setfield(L, -2, "I_SEE_ILLEGAL_PLAYER_BUILDING");

        lua_pushinteger(L, EventTriggerEnum::EV_BURNING);
        lua_setfield(L, -2, "EV_BURNING");
        lua_pushinteger(L, EventTriggerEnum::EV_BURNING);
        lua_setfield(L, -2, "BURNING");

        lua_pushinteger(L, EventTriggerEnum::EV_LOST_LEG);
        lua_setfield(L, -2, "EV_LOST_LEG");
        lua_pushinteger(L, EventTriggerEnum::EV_LOST_LEG);
        lua_setfield(L, -2, "LOST_LEG");

        lua_pushinteger(L, EventTriggerEnum::EV_LOST_ARM);
        lua_setfield(L, -2, "EV_LOST_ARM");
        lua_pushinteger(L, EventTriggerEnum::EV_LOST_ARM);
        lua_setfield(L, -2, "LOST_ARM");

        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_PLAYER_NICE_BUILDING);
        lua_setfield(L, -2, "EV_I_SEE_PLAYER_NICE_BUILDING");
        lua_pushinteger(L, EventTriggerEnum::EV_I_SEE_PLAYER_NICE_BUILDING);
        lua_setfield(L, -2, "I_SEE_PLAYER_NICE_BUILDING");

        lua_pushinteger(L, EventTriggerEnum::EV_TAKEN_OVER_PLAYER_TOWN);
        lua_setfield(L, -2, "EV_TAKEN_OVER_PLAYER_TOWN");
        lua_pushinteger(L, EventTriggerEnum::EV_TAKEN_OVER_PLAYER_TOWN);
        lua_setfield(L, -2, "TAKEN_OVER_PLAYER_TOWN");

        lua_pushinteger(L, EventTriggerEnum::EV_CROWD_TRIGGERED);
        lua_setfield(L, -2, "EV_CROWD_TRIGGERED");
        lua_pushinteger(L, EventTriggerEnum::EV_CROWD_TRIGGERED);
        lua_setfield(L, -2, "CROWD_TRIGGERED");

        lua_pushinteger(L, EventTriggerEnum::EV_MAX);
        lua_setfield(L, -2, "EV_MAX");
        lua_pushinteger(L, EventTriggerEnum::EV_MAX);
        lua_setfield(L, -2, "MAX");

        lua_pushvalue(L, -1);
        lua_setglobal(L, "EventTriggerEnum");
        lua_setglobal(L, "EventTrigger");
    }

    void registerDialogConditionEnum(lua_State* L)
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

        lua_pushvalue(L, -1);
        lua_setglobal(L, "DialogConditionEnum");
        lua_setglobal(L, "DialogCondition");
    }

    void registerComparisonEnum(lua_State* L)
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

        lua_pushvalue(L, -1);
        lua_setglobal(L, "ComparisonEnum");
        lua_setglobal(L, "Comparison");
    }

    void registerGroundType(lua_State* L)
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

    void registerEffectType(lua_State* L)
    {
        lua_createtable(L, 0, 11);

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

    void registerSquadType(lua_State* L)
    {
        lua_createtable(L, 0, 3);

        lua_pushinteger(L, SquadType::SQ_UNKNOWN);
        lua_setfield(L, -2, "SQ_UNKNOWN");

        lua_pushinteger(L, SquadType::SQ_RESIDENT);
        lua_setfield(L, -2, "SQ_RESIDENT");

        lua_pushinteger(L, SquadType::SQ_ROAMING);
        lua_setfield(L, -2, "SQ_ROAMING");

        lua_setglobal(L, "SquadType");
    }

    void registerMoveSpeed(lua_State* L)
    {
        lua_createtable(L, 0, 5);

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

    void registerSwordStateEnum(lua_State* L)
    {
        lua_createtable(L, 0, 12);

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

        lua_pushvalue(L, -1);
        lua_setglobal(L, "swordStateEnum");
        lua_setglobal(L, "SwordState");
    }

    void registerMiningResource(lua_State* L)
    {
        lua_createtable(L, 0, 7);

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

    void registerCursorType(lua_State* L)
    {
        lua_createtable(L, 0, 16);

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

    void registerMapZoomLevel(lua_State* L)
    {
        lua_createtable(L, 0, 8);

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

    // --------------------------------------
    // InputHandler.h
    // --------------------------------------

    void registerMasks(lua_State* L)
    {
        lua_createtable(L, 0, 10);

        lua_pushinteger(L, InputHandler::SHIFT_MASK);
        lua_setfield(L, -2, "SHIFT_MASK");
        lua_pushinteger(L, InputHandler::SHIFT_MASK);
        lua_setfield(L, -2, "SHIFT");

        lua_pushinteger(L, InputHandler::CTRL_MASK);
        lua_setfield(L, -2, "CTRL_MASK");
        lua_pushinteger(L, InputHandler::CTRL_MASK);
        lua_setfield(L, -2, "CTRL");

        lua_pushinteger(L, InputHandler::ALT_MASK);
        lua_setfield(L, -2, "ALT_MASK");
        lua_pushinteger(L, InputHandler::ALT_MASK);
        lua_setfield(L, -2, "ALT");

        lua_pushinteger(L, InputHandler::ALL_MASK);
        lua_setfield(L, -2, "ALL_MASK");
        lua_pushinteger(L, InputHandler::ALL_MASK);
        lua_setfield(L, -2, "ALL");

        lua_pushinteger(L, InputHandler::NONE_MASK);
        lua_setfield(L, -2, "NONE_MASK");
        lua_pushinteger(L, InputHandler::NONE_MASK);
        lua_setfield(L, -2, "NONE");

        lua_setglobal(L, "Masks");
    }

    void registerGlobalMode(lua_State* L)
    {
        lua_createtable(L, 0, 2);

        lua_pushinteger(L, InputHandler::GLOBAL);
        lua_setfield(L, -2, "GLOBAL");

        lua_pushinteger(L, InputHandler::EDITOR);
        lua_setfield(L, -2, "EDITOR");

        lua_setglobal(L, "GlobalMode");
    }

    // --------------------------------------
    // MedicalSystem.h
    // --------------------------------------

    void registerLimbState(lua_State* L)
    {
        lua_createtable(L, 0, 8);

        lua_pushinteger(L, LimbState::LIMB_ORIGINAL);
        lua_setfield(L, -2, "LIMB_ORIGINAL");
        lua_pushinteger(L, LimbState::LIMB_ORIGINAL);
        lua_setfield(L, -2, "ORIGINAL");

        lua_pushinteger(L, LimbState::LIMB_STUMP);
        lua_setfield(L, -2, "LIMB_STUMP");
        lua_pushinteger(L, LimbState::LIMB_STUMP);
        lua_setfield(L, -2, "STUMP");

        lua_pushinteger(L, LimbState::LIMB_REPLACED);
        lua_setfield(L, -2, "LIMB_REPLACED");
        lua_pushinteger(L, LimbState::LIMB_REPLACED);
        lua_setfield(L, -2, "REPLACED");

        lua_pushinteger(L, LimbState::LIMB_CRUSHED);
        lua_setfield(L, -2, "LIMB_CRUSHED");
        lua_pushinteger(L, LimbState::LIMB_CRUSHED);
        lua_setfield(L, -2, "CRUSHED");

        lua_setglobal(L, "LimbState");
    }

    void registerRobotLimbs(lua_State* L)
    {
        lua_createtable(L, 0, 5);

        lua_pushinteger(L, RobotLimbs::Limb::LEFT_ARM);
        lua_setfield(L, -2, "LEFT_ARM");

        lua_pushinteger(L, RobotLimbs::Limb::RIGHT_ARM);
        lua_setfield(L, -2, "RIGHT_ARM");

        lua_pushinteger(L, RobotLimbs::Limb::LEFT_LEG);
        lua_setfield(L, -2, "LEFT_LEG");

        lua_pushinteger(L, RobotLimbs::Limb::RIGHT_LEG);
        lua_setfield(L, -2, "RIGHT_LEG");

        lua_pushinteger(L, RobotLimbs::Limb::NULL_LIMB);
        lua_setfield(L, -2, "NULL_LIMB");

        lua_setglobal(L, "RobotLimbs");
    }

    void registerAttackDirection(lua_State* L)
    {
        lua_createtable(L, 0, 6);

        lua_pushinteger(L, AttackDirection::Enum::FRONT);
        lua_setfield(L, -2, "FRONT");

        lua_pushinteger(L, AttackDirection::Enum::BACK);
        lua_setfield(L, -2, "BACK");

        lua_pushinteger(L, AttackDirection::Enum::LEFT);
        lua_setfield(L, -2, "LEFT");

        lua_pushinteger(L, AttackDirection::Enum::RIGHT);
        lua_setfield(L, -2, "RIGHT");

        lua_pushinteger(L, AttackDirection::Enum::TOP);
        lua_setfield(L, -2, "TOP");

        lua_pushinteger(L, AttackDirection::Enum::BOTTOM);
        lua_setfield(L, -2, "BOTTOM");

        lua_setglobal(L, "AttackDirection");
    }

    void registerHealthPartStatus(lua_State* L)
    {
        lua_createtable(L, 0, 8);

        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PART_TORSO);
        lua_setfield(L, -2, "PART_TORSO");
        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PART_TORSO);
        lua_setfield(L, -2, "TORSO");

        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PartType::PART_LEG);
        lua_setfield(L, -2, "PART_LEG");
        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PartType::PART_LEG);
        lua_setfield(L, -2, "LEG");

        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PartType::PART_ARM);
        lua_setfield(L, -2, "PART_ARM");
        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PartType::PART_ARM);
        lua_setfield(L, -2, "ARM");

        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PartType::PART_HEAD);
        lua_setfield(L, -2, "PART_HEAD");
        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PartType::PART_HEAD);
        lua_setfield(L, -2, "HEAD");

        lua_setglobal(L, "HealthPartStatus");
    }

    void registerCollapseStage(lua_State* L)
    {
        lua_createtable(L, 0, 6);

        lua_pushinteger(L, MedicalSystem::CollapseStage::COLLAPSE_NONE);
        lua_setfield(L, -2, "COLLAPSE_NONE");
        lua_pushinteger(L, MedicalSystem::CollapseStage::COLLAPSE_NONE);
        lua_setfield(L, -2, "NONE");

        lua_pushinteger(L, MedicalSystem::CollapseStage::COLLAPSE_BUT_NO_RAGDOLL);
        lua_setfield(L, -2, "COLLAPSE_BUT_NO_RAGDOLL");
        lua_pushinteger(L, MedicalSystem::CollapseStage::COLLAPSE_BUT_NO_RAGDOLL);
        lua_setfield(L, -2, "BUT_NO_RAGDOLL");

        lua_pushinteger(L, MedicalSystem::CollapseStage::COLLAPSE_KO);
        lua_setfield(L, -2, "COLLAPSE_KO");
        lua_pushinteger(L, MedicalSystem::CollapseStage::COLLAPSE_KO);
        lua_setfield(L, -2, "KO");

        lua_setglobal(L, "CollapseStage");
    }

    void registerEnumBindings(lua_State* L)
    {
        registerBuildingDesignation(L);
        registerBuildingClassType(L);
        registerBuildingPlacementGroundType(L);
        registerPreviewBuildingPlacementResult(L);
        registerPreviewBuildingClassType(L);
        registerProneState(L);
        registerWaterState(L);
        registerRagdollPart(L);
        registerCharacterPerceptionTagsShortTerm(L);
        registerCharacterPerceptionTagsLongTerm(L);
        registerSoundRange(L);
        registerSquadMemberType(L);
        registerCharacterMessage(L);
        registerTalker(L);
        registerDialogueAction(L);
        registersItemType(L);
        registerBuildingFunction(L);
        registerCutDirection(L);
        registerCutOrigination(L);
        registerHitMaterialType(L);
        registerWeatherAffecting(L);
        registerAttachSlot(L);
        registerItemFunction(L);
        registerArmourType(L);
        registerCharacterTypeEnum(L);
        registerSlaveStateEnum(L);
        registerTaskType(L);
        registerWeaponCategory(L);
        registerLeftRight(L);
        registerMessageType(L);
        registerStandingOrder(L);
        registerStatsEnumerated(L);
        registerEventTriggerEnum(L);
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
        registerLimbState(L);
        registerRobotLimbs(L);
        registerAttackDirection(L);
        registerHealthPartStatus(L);
        registerCollapseStage(L);
	}
} // namespace KenshiLua
