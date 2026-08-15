#include "pch.h"
#include "Bindings/EnumBinding.h"
#include "Lua/BindingHelpers.h"

#include "kenshi/Appearance.h"
#include "kenshi/AppearanceManager.h"
#include "kenshi/Bounty.h"
#include "kenshi/Building/DoorStuff.h"
#include "kenshi/Building/ProductionBuilding.h"
#include "kenshi/Building/WallBuilding.h"
#include "kenshi/Character.h"
#include "kenshi/CharMovement.h"
#include "kenshi/Dialogue.h"
#include "kenshi/Enums.h"
#include "kenshi/FactionRelations.h"
#include "kenshi/FactionWarMgr.h"
#include "kenshi/Building/FarmBuilding.h"
#include "kenshi/GameData.h"
#include "kenshi/GameWorld.h"
#include "kenshi/Gear.h"
#include "kenshi/HavokCharacter.h"
#include "kenshi/InputHandler.h"
#include "kenshi/MedicalSystem.h"
#include "kenshi/NavMesh.h"
#include "kenshi/PhysicsActual.h"
#include "kenshi/PhysicsCollection.h"
#include "kenshi/Platoon.h"
#include "kenshi/RootObject.h"
#include "kenshi/SaveFileSystem.h"
#include "kenshi/SaveManager.h"
#include "kenshi/SensoryData.h"
#include "kenshi/Town.h"
#include "kenshi/Tasker.h"
#include "kenshi/WorldEventStateQuery.h"
#include "kenshi/ZoneManager.h"
#include "kenshi/gui/CharacterStatsWindow.h"
#include "kenshi/gui/DataPanelLine.h"
#include "kenshi/gui/ForgottenGUI.h"
#include "kenshi/gui/InventoryGUI.h"
#include "kenshi/gui/ManagementScreen.h"
#include "kenshi/gui/ScreenLabel.h"
#include "kenshi/gui/SquadManagementScreen.h"
#include "kenshi/gui/ToolTip.h"
#include "kenshi/gui/TutorialGUI.h"
#include "kenshi/Logger.h"
#include "kenshi/util/YesNoMaybe.h"

#include <lua.hpp>

namespace KenshiLua
{

    // ------------------------------------------
    // Appearance.h
    // ------------------------------------------

    void registerMeshDataLookup(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "FRONT", MeshDataLookup::Dir::FRONT);
        setEnum(L, "BACK", MeshDataLookup::Dir::BACK);
        setEnum(L, "NUM_DIRS", MeshDataLookup::Dir::NUM_DIRS);

        lua_setglobal(L, "MeshDataLookup");
    }

    // ------------------------------------------
    // AppearanceManager.h
    // ------------------------------------------

    void registerAppearanceManagerDataCategory(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "None", AppearanceManager::DataCategory::None);
        setEnum(L, "Face", AppearanceManager::DataCategory::Face);
        setEnum(L, "Body", AppearanceManager::DataCategory::Body);
        setEnum(L, "Hair", AppearanceManager::DataCategory::Hair);
        setEnum(L, "Personality", AppearanceManager::DataCategory::Personality);
       
        lua_pushvalue(L, -1); // duplicate the table
        lua_setglobal(L, "AppearanceManager_DataCategory"); // original
        lua_setglobal(L, "AppearanceDataCategory"); // alias for convenience
    }

    void registerAppearanceManagerGender(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "MALE", AppearanceManager::Gender::MALE);
        setEnum(L, "FEMALE", AppearanceManager::Gender::FEMALE);

        lua_pushvalue(L, -1); // duplicate the table
        lua_setglobal(L, "AppearanceManager_Gender"); // original
        lua_setglobal(L, "Gender"); // alias for convenience
    }

    // ------------------------------------------
    // Bounty.h
    // ------------------------------------------

    void registerCrimeEnum(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "CRIME_NONE", CrimeEnum::CRIME_NONE);
        setEnum(L, "CRIME_ENSLAVING", CrimeEnum::CRIME_ENSLAVING);
        setEnum(L, "CRIME_LOCKPICKING", CrimeEnum::CRIME_LOCKPICKING);
        setEnum(L, "CRIME_STEALING", CrimeEnum::CRIME_STEALING);
        setEnum(L, "CRIME_MURDER", CrimeEnum::CRIME_MURDER);
        setEnum(L, "CRIME_ASSAULT", CrimeEnum::CRIME_ASSAULT);
        setEnum(L, "CRIME_ASSAULT_VIP", CrimeEnum::CRIME_ASSAULT_VIP);
        setEnum(L, "CRIME_SLAVE_FREEING", CrimeEnum::CRIME_SLAVE_FREEING);
        setEnum(L, "CRIME_SMUGGLING", CrimeEnum::CRIME_SMUGGLING);
        setEnum(L, "CRIME_TERRORISM", CrimeEnum::CRIME_TERRORISM);
        setEnum(L, "CRIME_LOOTING", CrimeEnum::CRIME_LOOTING);
        setEnum(L, "CRIME_TRESSPASSING", CrimeEnum::CRIME_TRESSPASSING);
        setEnum(L, "CRIME_ESCAPE_PRISON", CrimeEnum::CRIME_ESCAPE_PRISON);
        setEnum(L, "CRIME_FENCING", CrimeEnum::CRIME_FENCING);
        setEnum(L, "CRIME_FARM_EATING", CrimeEnum::CRIME_FARM_EATING);
        setEnum(L, "CRIME_KIDNAPPING", CrimeEnum::CRIME_KIDNAPPING);
        setEnum(L, "CRIME_UNIFORM_THEFT", CrimeEnum::CRIME_UNIFORM_THEFT);
        setEnum(L, "CRIME_END", CrimeEnum::CRIME_END);
    // aliases
        setEnum(L, "NONE", CrimeEnum::CRIME_NONE);
        setEnum(L, "ENSLAVING", CrimeEnum::CRIME_ENSLAVING);
        setEnum(L, "LOCKPICKING", CrimeEnum::CRIME_LOCKPICKING);
        setEnum(L, "STEALING", CrimeEnum::CRIME_STEALING);
        setEnum(L, "MURDER", CrimeEnum::CRIME_MURDER);
        setEnum(L, "ASSAULT", CrimeEnum::CRIME_ASSAULT);
        setEnum(L, "ASSAULT_VIP", CrimeEnum::CRIME_ASSAULT_VIP);
        setEnum(L, "SLAVE_FREEING", CrimeEnum::CRIME_SLAVE_FREEING);
        setEnum(L, "SMUGGLING", CrimeEnum::CRIME_SMUGGLING);
        setEnum(L, "TERRORISM", CrimeEnum::CRIME_TERRORISM);
        setEnum(L, "LOOTING", CrimeEnum::CRIME_LOOTING);
        setEnum(L, "TRESSPASSING", CrimeEnum::CRIME_TRESSPASSING);
        setEnum(L, "ESCAPE_PRISON", CrimeEnum::CRIME_ESCAPE_PRISON);
        setEnum(L, "FENCING", CrimeEnum::CRIME_FENCING);
        setEnum(L, "FARM_EATING", CrimeEnum::CRIME_FARM_EATING);
        setEnum(L, "KIDNAPPING", CrimeEnum::CRIME_KIDNAPPING);
        setEnum(L, "UNIFORM_THEFT", CrimeEnum::CRIME_UNIFORM_THEFT);
        setEnum(L, "END", CrimeEnum::CRIME_END);

        lua_setglobal(L, "CrimeEnum");
        lua_pushvalue(L, -1); // duplicate the table
        lua_setglobal(L, "Crime"); // alias for convenience
    }

    // ------------------------------------------
    // Building.h
    // ------------------------------------------

        void registerBuildingDesignation(lua_State* L)
    {
        lua_newtable(L);

    // original
        setEnum(L, "BD_NONE", BuildingDesignation::BD_NONE);
        setEnum(L, "BD_SHOP", BuildingDesignation::BD_SHOP);
        setEnum(L, "BD_BARRACKS", BuildingDesignation::BD_BARRACKS);
        setEnum(L, "BD_BAR", BuildingDesignation::BD_BAR);
        setEnum(L, "BD_HOSPITAL", BuildingDesignation::BD_HOSPITAL);
        setEnum(L, "BD_ARMOURY", BuildingDesignation::BD_ARMOURY);
        setEnum(L, "BD_TREASURE", BuildingDesignation::BD_TREASURE);
        setEnum(L, "BD_PRISON", BuildingDesignation::BD_PRISON);
        setEnum(L, "BD_HQ", BuildingDesignation::BD_HQ);
        setEnum(L, "BD_RESIDENTIAL", BuildingDesignation::BD_RESIDENTIAL);
        setEnum(L, "BD_SLAVE_STORAGE", BuildingDesignation::BD_SLAVE_STORAGE);
        setEnum(L, "BD_RESIDENTIAL_SMALL", BuildingDesignation::BD_RESIDENTIAL_SMALL);
    // aliases
        setEnum(L, "NONE", BuildingDesignation::BD_NONE);
        setEnum(L, "SHOP", BuildingDesignation::BD_SHOP);
        setEnum(L, "BARRACKS", BuildingDesignation::BD_BARRACKS);
        setEnum(L, "BAR", BuildingDesignation::BD_BAR);
        setEnum(L, "HOSPITAL", BuildingDesignation::BD_HOSPITAL);
        setEnum(L, "ARMOURY", BuildingDesignation::BD_ARMOURY);
        setEnum(L, "TREASURE", BuildingDesignation::BD_TREASURE);
        setEnum(L, "PRISON", BuildingDesignation::BD_PRISON);
        setEnum(L, "HQ", BuildingDesignation::BD_HQ);
        setEnum(L, "RESIDENTIAL", BuildingDesignation::BD_RESIDENTIAL);
        setEnum(L, "SLAVE_STORAGE", BuildingDesignation::BD_SLAVE_STORAGE);
        setEnum(L, "RESIDENTIAL_SMALL", BuildingDesignation::BD_RESIDENTIAL_SMALL);
    // global
        lua_setglobal(L, "BuildingDesignation");
    }

    void registerBuildingClassType(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "BCTYPE_FLUFF", BuildingClassType::BCTYPE_FLUFF);
        setEnum(L, "BCTYPE_DOOR", BuildingClassType::BCTYPE_DOOR);
        setEnum(L, "BCTYPE_USABLE", BuildingClassType::BCTYPE_USABLE);
        setEnum(L, "BCTYPE_STORAGE", BuildingClassType::BCTYPE_STORAGE);
        setEnum(L, "BCTYPE_PRODUCTION", BuildingClassType::BCTYPE_PRODUCTION);
        setEnum(L, "BCTYPE_RESEARCH", BuildingClassType::BCTYPE_RESEARCH);
        setEnum(L, "BCTYPE_CRAFTING", BuildingClassType::BCTYPE_CRAFTING);
        setEnum(L, "BCTYPE_GATEWAY", BuildingClassType::BCTYPE_GATEWAY);
        setEnum(L, "BCTYPE_TURRET", BuildingClassType::BCTYPE_TURRET);
        setEnum(L, "BCTYPE_WALL", BuildingClassType::BCTYPE_WALL);
        setEnum(L, "BCTYPE_ITEM_FURNACE", BuildingClassType::BCTYPE_ITEM_FURNACE);
        setEnum(L, "BCTYPE_LIGHT", BuildingClassType::BCTYPE_LIGHT);
        setEnum(L, "BCTYPE_SHELL_WITH_INTERIOR", BuildingClassType::BCTYPE_SHELL_WITH_INTERIOR);
        setEnum(L, "BCTYPE_FARM", BuildingClassType::BCTYPE_FARM);
    // aliases
        setEnum(L, "FLUFF", BuildingClassType::BCTYPE_FLUFF);
        setEnum(L, "DOOR", BuildingClassType::BCTYPE_DOOR);
        setEnum(L, "USABLE", BuildingClassType::BCTYPE_USABLE);
        setEnum(L, "STORAGE", BuildingClassType::BCTYPE_STORAGE);
        setEnum(L, "PRODUCTION", BuildingClassType::BCTYPE_PRODUCTION);
        setEnum(L, "RESEARCH", BuildingClassType::BCTYPE_RESEARCH);
        setEnum(L, "CRAFTING", BuildingClassType::BCTYPE_CRAFTING);
        setEnum(L, "GATEWAY", BuildingClassType::BCTYPE_GATEWAY);
        setEnum(L, "TURRET", BuildingClassType::BCTYPE_TURRET);
        setEnum(L, "WALL", BuildingClassType::BCTYPE_WALL);
        setEnum(L, "ITEM_FURNACE", BuildingClassType::BCTYPE_ITEM_FURNACE);
        setEnum(L, "LIGHT", BuildingClassType::BCTYPE_LIGHT);
        setEnum(L, "SHELL_WITH_INTERIOR", BuildingClassType::BCTYPE_SHELL_WITH_INTERIOR);
        setEnum(L, "FARM", BuildingClassType::BCTYPE_FARM);

        lua_setglobal(L, "BuildingClassType");
    }

    void registerBuildingPlacementGroundType(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "ANY", BuildingPlacementGroundType::Enum::ANY);
        setEnum(L, "LAND", BuildingPlacementGroundType::Enum::LAND);
        setEnum(L, "WATER", BuildingPlacementGroundType::Enum::WATER);

        lua_setglobal(L, "BuildingPlacementGroundType");
    }

    void registerPreviewBuildingPlacementResult(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "PLACEMENT_VALID", PreviewBuilding::PlacementResult::PLACEMENT_VALID);
        setEnum(L, "PLACEMENT_OUTSIDE", PreviewBuilding::PlacementResult::PLACEMENT_OUTSIDE);
        setEnum(L, "PLACEMENT_INVALID", PreviewBuilding::PlacementResult::PLACEMENT_INVALID);
    // aliases
        setEnum(L, "VALID", PreviewBuilding::PlacementResult::PLACEMENT_VALID);
        setEnum(L, "OUTSIDE", PreviewBuilding::PlacementResult::PLACEMENT_OUTSIDE);
        setEnum(L, "INVALID", PreviewBuilding::PlacementResult::PLACEMENT_INVALID);

        lua_setglobal(L, "PreviewBuildingPlacementResult");
    }

    void registerPreviewBuildingClassType(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "PREVIEW_NORMAL", PreviewBuilding::PreviewBuildingClassType::PREVIEW_NORMAL);
        setEnum(L, "PREVIEW_WALL", PreviewBuilding::PreviewBuildingClassType::PREVIEW_WALL);
    // aliases
        setEnum(L, "NORMAL", PreviewBuilding::PreviewBuildingClassType::PREVIEW_NORMAL);
        setEnum(L, "WALL", PreviewBuilding::PreviewBuildingClassType::PREVIEW_WALL);

        lua_setglobal(L, "PreviewBuildingClassType");
    }

    // ------------------------------------------
    // Building/DoorStuff.h
    // ------------------------------------------

    void registerDoorState(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "DOORSTATE_CLOSED", DOORSTATE_CLOSED);
        setEnum(L, "DOORSTATE_OPEN", DOORSTATE_OPEN);
        setEnum(L, "DOORSTATE_OPENING", DOORSTATE_OPENING);
        setEnum(L, "DOORSTATE_CLOSING", DOORSTATE_CLOSING);
    // aliase
        setEnum(L, "CLOSED", DOORSTATE_CLOSED);
        setEnum(L, "OPEN", DOORSTATE_OPEN);
        setEnum(L, "OPENING", DOORSTATE_OPENING);
        setEnum(L, "CLOSING", DOORSTATE_CLOSING);

        lua_setglobal(L, "DoorState");
    }

    void registerDoorStateInitial(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "CLOSED", DoorStuff::CLOSED);
        setEnum(L, "OPEN", DoorStuff::OPEN);
        setEnum(L, "LOCKED", DoorStuff::LOCKED);
        setEnum(L, "BROKEN", DoorStuff::BROKEN);

        lua_setglobal(L, "DoorStateInitial");
    }

    // ------------------------------------------
    // Building/FarmBuilding.h
    // ------------------------------------------

    void registerCropType(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "CROP_NULL", CROP_NULL);
        setEnum(L, "CROP_GREEN", CROP_GREEN);
        setEnum(L, "CROP_ARID", CROP_ARID);
        setEnum(L, "CROP_SWAMP", CROP_SWAMP);
    // aliases
        setEnum(L, "NULL", CROP_NULL);
        setEnum(L, "GREEN", CROP_GREEN);
        setEnum(L, "ARID", CROP_ARID);
        setEnum(L, "SWAMP", CROP_SWAMP);

        lua_setglobal(L, "CropType");
    }

    // ------------------------------------------
    // Building/ProductionBuilding.h
    // ------------------------------------------

    void registerProductionState(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "PRODUCTION_STARVED", ProductionBuilding::PRODUCTION_STARVED);
        setEnum(L, "PRODUCTION_FULL", ProductionBuilding::PRODUCTION_FULL);
        setEnum(L, "PRODUCTION_NORMAL", ProductionBuilding::PRODUCTION_NORMAL);
        setEnum(L, "PRODUCTION_IMPOSSIBLE", ProductionBuilding::PRODUCTION_IMPOSSIBLE);
    // aliases
        setEnum(L, "STARVED", ProductionBuilding::PRODUCTION_STARVED);
        setEnum(L, "FULL", ProductionBuilding::PRODUCTION_FULL);
        setEnum(L, "NORMAL", ProductionBuilding::PRODUCTION_NORMAL);
        setEnum(L, "IMPOSSIBLE", ProductionBuilding::PRODUCTION_IMPOSSIBLE);

        lua_setglobal(L, "ProductionState");
    }

    // ------------------------------------------
    // Building/WallBuilding.h
    // ------------------------------------------

    void registerWallSectionLinkType(lua_State* L)
    {
        lua_newtable(L);
    // original    
        setEnum(L, "WALLTYPE_NORMAL", WALLTYPE_NORMAL);
        setEnum(L, "WALLTYPE_CONNECTOR", WALLTYPE_CONNECTOR);
        setEnum(L, "WALLTYPE_LOWER_WEDGE", WALLTYPE_LOWER_WEDGE);
        setEnum(L, "WALLTYPE_SINGLE", WALLTYPE_SINGLE);
        setEnum(L, "WALLTYPE_SHORT", WALLTYPE_SHORT);
    // aliases
        setEnum(L, "NORMAL", WALLTYPE_NORMAL);
        setEnum(L, "CONNECTOR", WALLTYPE_CONNECTOR);
        setEnum(L, "LOWER_WEDGE", WALLTYPE_LOWER_WEDGE);
        setEnum(L, "SINGLE", WALLTYPE_SINGLE);
        setEnum(L, "SHORT", WALLTYPE_SHORT);

        lua_setglobal(L, "WallSectionLinkType");
    }

    // ------------------------------------------
    // Character.h
    // ------------------------------------------

    void registerProneState(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "PS_NORMAL", ProneState::PS_NORMAL);
        setEnum(L, "PS_STAYING_LOW", ProneState::PS_STAYING_LOW);
        setEnum(L, "PS_CRIPPLED", ProneState::PS_CRIPPLED);
        setEnum(L, "PS_PLAYING_DEAD", ProneState::PS_PLAYING_DEAD);
        setEnum(L, "PS_KO", ProneState::PS_KO);
    // aliases
        setEnum(L, "NORMAL", ProneState::PS_NORMAL);
        setEnum(L, "STAYING_LOW", ProneState::PS_STAYING_LOW);
        setEnum(L, "CRIPPLED", ProneState::PS_CRIPPLED);
        setEnum(L, "PLAYING_DEAD", ProneState::PS_PLAYING_DEAD);
        setEnum(L, "KO", ProneState::PS_KO);

        lua_setglobal(L, "ProneState");
    }

    void registerWaterState(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "NO_WATER", WaterState::Enum::NO_WATER);
        setEnum(L, "VERY_SHALLOW_WATER", WaterState::Enum::VERY_SHALLOW_WATER);
        setEnum(L, "THIGH_DEEP_WATER", WaterState::Enum::THIGH_DEEP_WATER);
        setEnum(L, "DEEP_WATER", WaterState::Enum::DEEP_WATER);
    // aliases
        setEnum(L, "NONE", WaterState::Enum::NO_WATER);
        setEnum(L, "VERY_SHALLOW", WaterState::Enum::VERY_SHALLOW_WATER);
        setEnum(L, "THIGH_DEEP", WaterState::Enum::THIGH_DEEP_WATER);
        setEnum(L, "DEEP", WaterState::Enum::DEEP_WATER);

        lua_setglobal(L, "WaterState");
    }

    void registerRagdollPart(lua_State* L)
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

    void registerCharacterPerceptionTagsShortTerm(lua_State* L)
    {
        lua_newtable(L);
    // orignal
        setEnum(L, "ST_NONE", CharacterPerceptionTags_ShortTerm::ST_NONE);
        setEnum(L, "ST_INTRUDER", CharacterPerceptionTags_ShortTerm::ST_INTRUDER);
        setEnum(L, "ST_AGGRESSOR", CharacterPerceptionTags_ShortTerm::ST_AGGRESSOR);
        setEnum(L, "ST_TEMPORARY_ALLY", CharacterPerceptionTags_ShortTerm::ST_TEMPORARY_ALLY);
        setEnum(L, "ST_TEMPORARY_ENEMY", CharacterPerceptionTags_ShortTerm::ST_TEMPORARY_ENEMY);
        setEnum(L, "ST_PRISONER", CharacterPerceptionTags_ShortTerm::ST_PRISONER);
        setEnum(L, "ST_HAS_BEEN_LOOTED", CharacterPerceptionTags_ShortTerm::ST_HAS_BEEN_LOOTED);
        setEnum(L, "ST_CRIMINAL", CharacterPerceptionTags_ShortTerm::ST_CRIMINAL);
    // aliases
        setEnum(L, "NONE", CharacterPerceptionTags_ShortTerm::ST_NONE);
        setEnum(L, "INTRUDER", CharacterPerceptionTags_ShortTerm::ST_INTRUDER);
        setEnum(L, "AGGRESSOR", CharacterPerceptionTags_ShortTerm::ST_AGGRESSOR);
        setEnum(L, "TEMPORARY_ALLY", CharacterPerceptionTags_ShortTerm::ST_TEMPORARY_ALLY);
        setEnum(L, "TEMPORARY_ENEMY", CharacterPerceptionTags_ShortTerm::ST_TEMPORARY_ENEMY);
        setEnum(L, "PRISONER", CharacterPerceptionTags_ShortTerm::ST_PRISONER);
        setEnum(L, "HAS_BEEN_LOOTED", CharacterPerceptionTags_ShortTerm::ST_HAS_BEEN_LOOTED);
        setEnum(L, "CRIMINAL", CharacterPerceptionTags_ShortTerm::ST_CRIMINAL);

        lua_setglobal(L, "CharacterPerceptionTags_ShortTerm");
    }

        void registerCharacterPerceptionTagsLongTerm(lua_State* L)
    {
        lua_newtable(L);

    // original
        setEnum(L, "LT_NONE", CharacterPerceptionTags_LongTerm::LT_NONE);
        setEnum(L, "LT_MY_INTRUDER", CharacterPerceptionTags_LongTerm::LT_MY_INTRUDER);
        setEnum(L, "LT_MY_LIFESAVER", CharacterPerceptionTags_LongTerm::LT_MY_LIFESAVER);
        setEnum(L, "LT_FREED_ME", CharacterPerceptionTags_LongTerm::LT_FREED_ME);
        setEnum(L, "LT_STOLE_FROM_ME", CharacterPerceptionTags_LongTerm::LT_STOLE_FROM_ME);
        setEnum(L, "LT_MY_CAPTOR", CharacterPerceptionTags_LongTerm::LT_MY_CAPTOR);
        setEnum(L, "LT_FRIENDLY_AQUAINTANCE", CharacterPerceptionTags_LongTerm::LT_FRIENDLY_AQUAINTANCE);
        setEnum(L, "LT_DEFEATED_MY_SQUAD_ONCE", CharacterPerceptionTags_LongTerm::LT_DEFEATED_MY_SQUAD_ONCE);
        setEnum(L, "LT_SQUAD_LOST_TO_ME_ONCE", CharacterPerceptionTags_LongTerm::LT_SQUAD_LOST_TO_ME_ONCE);
        setEnum(L, "LT_KILLED_MY_FRIEND", CharacterPerceptionTags_LongTerm::LT_KILLED_MY_FRIEND);
        setEnum(L, "LT_I_SCREWED_THIS_GUY", CharacterPerceptionTags_LongTerm::LT_I_SCREWED_THIS_GUY);
        setEnum(L, "LT_MAX", CharacterPerceptionTags_LongTerm::LT_MAX);
    // aliases
        setEnum(L, "NONE", CharacterPerceptionTags_LongTerm::LT_NONE);
        setEnum(L, "MY_INTRUDER", CharacterPerceptionTags_LongTerm::LT_MY_INTRUDER);
        setEnum(L, "MY_LIFESAVER", CharacterPerceptionTags_LongTerm::LT_MY_LIFESAVER);
        setEnum(L, "FREED_ME", CharacterPerceptionTags_LongTerm::LT_FREED_ME);
        setEnum(L, "STOLE_FROM_ME", CharacterPerceptionTags_LongTerm::LT_STOLE_FROM_ME);
        setEnum(L, "MY_CAPTOR", CharacterPerceptionTags_LongTerm::LT_MY_CAPTOR);
        setEnum(L, "FRIENDLY_AQUAINTANCE", CharacterPerceptionTags_LongTerm::LT_FRIENDLY_AQUAINTANCE);
        setEnum(L, "DEFEATED_MY_SQUAD_ONCE", CharacterPerceptionTags_LongTerm::LT_DEFEATED_MY_SQUAD_ONCE);
        setEnum(L, "SQUAD_LOST_TO_ME_ONCE", CharacterPerceptionTags_LongTerm::LT_SQUAD_LOST_TO_ME_ONCE);
        setEnum(L, "KILLED_MY_FRIEND", CharacterPerceptionTags_LongTerm::LT_KILLED_MY_FRIEND);
        setEnum(L, "I_SCREWED_THIS_GUY", CharacterPerceptionTags_LongTerm::LT_I_SCREWED_THIS_GUY);
        setEnum(L, "MAX", CharacterPerceptionTags_LongTerm::LT_MAX);
    // global
        lua_setglobal(L, "CharacterPerceptionTags_LongTerm");
    }

    void registerSoundRange(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "SOUNDRANGE_SHORT", SoundRange::SOUNDRANGE_SHORT);
        setEnum(L, "SOUNDRANGE_LONG", SoundRange::SOUNDRANGE_LONG);
        setEnum(L, "SOUNDRANGE_ALWAYS", SoundRange::SOUNDRANGE_ALWAYS);
    // aliases
        setEnum(L, "SHORT", SoundRange::SOUNDRANGE_SHORT);
        setEnum(L, "LONG", SoundRange::SOUNDRANGE_LONG);
        setEnum(L, "ALWAYS", SoundRange::SOUNDRANGE_ALWAYS);

        lua_setglobal(L, "SoundRange");
    }

    void registerSquadMemberType(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "SQUAD_1", SquadMemberType::SQUAD_1);
        setEnum(L, "SQUAD_2", SquadMemberType::SQUAD_2);
        setEnum(L, "SQUAD_LEADER", SquadMemberType::SQUAD_LEADER);
        setEnum(L, "SQUAD_SIGNALS_PLAN", SquadMemberType::SQUAD_SIGNALS_PLAN);
        setEnum(L, "SQUAD_SLAVE", SquadMemberType::SQUAD_SLAVE);
    // aliases
        setEnum(L, "1", SquadMemberType::SQUAD_1);
        setEnum(L, "2", SquadMemberType::SQUAD_2);
        setEnum(L, "LEADER", SquadMemberType::SQUAD_LEADER);
        setEnum(L, "SIGNALS_PLAN", SquadMemberType::SQUAD_SIGNALS_PLAN);
        setEnum(L, "SLAVE", SquadMemberType::SQUAD_SLAVE);

        lua_setglobal(L, "SquadMemberType");
    }

    void registerCharacterMessage(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "ATTACKING_MELEE", ATTACKING_MELEE);

        lua_setglobal(L, "CharacterMessage");
    }

    void registerUseStuffState(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "IN_NOTHING", UseStuffState::IN_NOTHING);
        setEnum(L, "IN_BED", UseStuffState::IN_BED);
        setEnum(L, "IN_PRISON", UseStuffState::IN_PRISON);

        lua_setglobal(L, "UseStuffState");
    }

    void registerDisguiseGUIFeedback(lua_State* L)
    {
        lua_newtable(L);
    // orignal
        setEnum(L, "DGF_SAME_FACTION", Character::DGF_SAME_FACTION);
        setEnum(L, "DGF_MY_SLAVE", Character::DGF_MY_SLAVE);
        setEnum(L, "DGF_I_HATE_YOU", Character::DGF_I_HATE_YOU);
    // aliases
        setEnum(L, "SAME_FACTION", Character::DGF_SAME_FACTION);
        setEnum(L, "MY_SLAVE", Character::DGF_MY_SLAVE);
        setEnum(L, "I_HATE_YOU", Character::DGF_I_HATE_YOU);

        lua_setglobal(L, "DisguiseGUIFeedback");
    }

    void registerCharMessage(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "CHARMESSAGE_NONE", Character::CHARMESSAGE_NONE);
        setEnum(L, "CHARMESSAGE_CARRY", Character::CHARMESSAGE_CARRY);
        setEnum(L, "CHARMESSAGE_CAGE", Character::CHARMESSAGE_CAGE);
    // aliases
        setEnum(L, "NONE", Character::CHARMESSAGE_NONE);
        setEnum(L, "CARRY", Character::CHARMESSAGE_CARRY);
        setEnum(L, "CAGE", Character::CHARMESSAGE_CAGE);

        lua_setglobal(L, "CharMessage");
    }

    // ------------------------------------------
    // CharacterStatsWindow.h
    // ------------------------------------------

    void registerCharacterStatsWindowGroup(lua_State* L)
    {
        lua_newtable(L);
        setEnum(L, "NONE", CharacterStatsWindow::StatGroup::NONE);
        setEnum(L, "WEAPONS", CharacterStatsWindow::StatGroup::WEAPONS);
        setEnum(L, "COMBAT", CharacterStatsWindow::StatGroup::COMBAT);
        setEnum(L, "THIEVERY", CharacterStatsWindow::StatGroup::THIEVERY);
        setEnum(L, "ATHLETICS", CharacterStatsWindow::StatGroup::ATHLETICS);
        setEnum(L, "SCIENCES", CharacterStatsWindow::StatGroup::SCIENCES);
        setEnum(L, "TRADES", CharacterStatsWindow::StatGroup::TRADES);
        setEnum(L, "RANGED", CharacterStatsWindow::StatGroup::RANGED);
        lua_setglobal(L, "StatGroup");
    }

    // ------------------------------------------
    // CharMovement.h
    // ------------------------------------------

    void registerUpdatePriority(lua_State* L)
    {
        lua_newtable(L);
    // orignal
        setEnum(L, "LOW_PRIORITY", UpdatePriority::LOW_PRIORITY);
        setEnum(L, "MED_PRIORITY", UpdatePriority::MED_PRIORITY);
        setEnum(L, "HIGH_PRIORITY", UpdatePriority::HIGH_PRIORITY);
    // aliases
        setEnum(L, "LOW", UpdatePriority::LOW_PRIORITY);
        setEnum(L, "MED", UpdatePriority::MED_PRIORITY);
        setEnum(L, "HIGH", UpdatePriority::HIGH_PRIORITY);

        lua_setglobal(L, "UpdatePriority");
    }

    void registerNxControllerAction(lua_State* L)
    {
        lua_newtable(L);
        setEnum(L, "NX_ACTION_NONE", NxControllerAction::NX_ACTION_NONE);
        setEnum(L, "NX_ACTION_PUSH", NxControllerAction::NX_ACTION_PUSH);
        setEnum(L, "NONE", NxControllerAction::NX_ACTION_NONE);
        setEnum(L, "PUSH", NxControllerAction::NX_ACTION_PUSH);
        lua_setglobal(L, "NxControllerAction");
    }

    // ------------------------------------------
    // DataPanelLine.h
    // ------------------------------------------

    void registerDataPanelLineLineType(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "DPL_BASE", DataPanelLine::DPL_BASE);
        setEnum(L, "DPL_MEDICAL", DataPanelLine::DPL_MEDICAL);
        setEnum(L, "DPL_FACTION", DataPanelLine::DPL_FACTION);
        setEnum(L, "DPL_RESEARCH", DataPanelLine::DPL_RESEARCH);
        setEnum(L, "DPL_BUTTON", DataPanelLine::DPL_BUTTON);
        setEnum(L, "DPL_EDIT", DataPanelLine::DPL_EDIT);
        setEnum(L, "DPL_CHECK", DataPanelLine::DPL_CHECK);
        setEnum(L, "DPL_DROPBOX", DataPanelLine::DPL_DROPBOX);
        setEnum(L, "DPL_TEXT", DataPanelLine::DPL_TEXT);
        setEnum(L, "DPL_TEXT_EDIT", DataPanelLine::DPL_TEXT_EDIT);
        setEnum(L, "DPL_SLIDER", DataPanelLine::DPL_SLIDER);
        setEnum(L, "DPL_PROGRESS", DataPanelLine::DPL_PROGRESS);
        setEnum(L, "DPL_CUSTOM", DataPanelLine::DPL_CUSTOM);
    // aliases
        setEnum(L, "BASE", DataPanelLine::DPL_BASE);
        setEnum(L, "MEDICAL", DataPanelLine::DPL_MEDICAL);
        setEnum(L, "FACTION", DataPanelLine::DPL_FACTION);
        setEnum(L, "RESEARCH", DataPanelLine::DPL_RESEARCH);
        setEnum(L, "BUTTON", DataPanelLine::DPL_BUTTON);
        setEnum(L, "EDIT", DataPanelLine::DPL_EDIT);
        setEnum(L, "CHECK", DataPanelLine::DPL_CHECK);
        setEnum(L, "DROPBOX", DataPanelLine::DPL_DROPBOX);
        setEnum(L, "TEXT", DataPanelLine::DPL_TEXT);
        setEnum(L, "TEXT_EDIT", DataPanelLine::DPL_TEXT_EDIT);
        setEnum(L, "SLIDER", DataPanelLine::DPL_SLIDER);
        setEnum(L, "PROGRESS", DataPanelLine::DPL_PROGRESS);
        setEnum(L, "CUSTOM", DataPanelLine::DPL_CUSTOM);
    // global
        lua_setglobal(L, "DataPanelsLineType");
    }

    // ------------------------------------------
    // Dialogue.h
    // ------------------------------------------

    void registerTalker(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "T_ME", T_ME);
        setEnum(L, "T_TARGET", T_TARGET);
        setEnum(L, "T_TARGET_IF_PLAYER", T_TARGET_IF_PLAYER);
        setEnum(L, "T_INTERJECTOR1", T_INTERJECTOR1);
        setEnum(L, "T_INTERJECTOR2", T_INTERJECTOR2);
        setEnum(L, "T_INTERJECTOR3", T_INTERJECTOR3);
        setEnum(L, "T_WHOLE_SQUAD", T_WHOLE_SQUAD);
        setEnum(L, "T_TARGET_WITH_RACE", T_TARGET_WITH_RACE);

        setEnum(L, "ME", T_ME);
        setEnum(L, "TARGET", T_TARGET);
        setEnum(L, "TARGET_IF_PLAYER", T_TARGET_IF_PLAYER);
        setEnum(L, "INTERJECTOR1", T_INTERJECTOR1);
        setEnum(L, "INTERJECTOR2", T_INTERJECTOR2);
        setEnum(L, "INTERJECTOR3", T_INTERJECTOR3);
        setEnum(L, "WHOLE_SQUAD", T_WHOLE_SQUAD);
        setEnum(L, "TARGET_WITH_RACE", T_TARGET_WITH_RACE);

        lua_pushvalue(L, -1);
        lua_setglobal(L, "TalkerEnum"); // original
        lua_setglobal(L, "Talker"); // alias for convenience
    }

    // void registerTalkerEnum(lua_State* L)
    // {
    //     lua_newtable(L);
    //     setEnum(L, "T_ME", T_ME);
    //     setEnum(L, "T_TARGET", T_TARGET);
    //     setEnum(L, "T_TARGET_IF_PLAYER", T_TARGET_IF_PLAYER);
    //     setEnum(L, "T_INTERJECTOR1", T_INTERJECTOR1);
    //     setEnum(L, "T_INTERJECTOR2", T_INTERJECTOR2);
    //     setEnum(L, "T_INTERJECTOR3", T_INTERJECTOR3);
    //     setEnum(L, "T_WHOLE_SQUAD", T_WHOLE_SQUAD);
    //     setEnum(L, "T_TARGET_WITH_RACE", T_TARGET_WITH_RACE);

    //     lua_setglobal(L, "TalkerEnum"); // original
    // }

    // void registerTalker(lua_State* L)
    // {
    //     lua_newtable(L);
    //     setEnum(L, "ME", T_ME);
    //     setEnum(L, "TARGET", T_TARGET);
    //     setEnum(L, "TARGET_IF_PLAYER", T_TARGET_IF_PLAYER);
    //     setEnum(L, "INTERJECTOR1", T_INTERJECTOR1);
    //     setEnum(L, "INTERJECTOR2", T_INTERJECTOR2);
    //     setEnum(L, "INTERJECTOR3", T_INTERJECTOR3);
    //     setEnum(L, "WHOLE_SQUAD", T_WHOLE_SQUAD);
    //     setEnum(L, "TARGET_WITH_RACE", T_TARGET_WITH_RACE);

    //     lua_setglobal(L, "Talker"); // alias for convenience
    // }


    void registerDialogueAction(lua_State* L)
    {
        lua_newtable(L);

    // original
        setEnum(L, "DA_NONE", DA_NONE);
        setEnum(L, "DA_TRADE", DA_TRADE);
        setEnum(L, "DA_TALK_TO_LEADER", DA_TALK_TO_LEADER);
        setEnum(L, "DA_JOIN_SQUAD_WITH_EDIT", DA_JOIN_SQUAD_WITH_EDIT);
        setEnum(L, "DA_AFFECT_RELATIONS", DA_AFFECT_RELATIONS);
        setEnum(L, "DA_AFFECT_REPUTATION", DA_AFFECT_REPUTATION);
        setEnum(L, "DA_ATTACK_CHASE_FOREVER", DA_ATTACK_CHASE_FOREVER);
        setEnum(L, "DA_GO_HOME", DA_GO_HOME);
        setEnum(L, "DA_TAKE_MONEY", DA_TAKE_MONEY);
        setEnum(L, "DA_GIVE_MONEY", DA_GIVE_MONEY);
        setEnum(L, "DA_PAY_BOUNTY", DA_PAY_BOUNTY);
        setEnum(L, "DA_CHARACTER_EDITOR", DA_CHARACTER_EDITOR);
        setEnum(L, "DA_FORCE_SPEECH_TIMER", DA_FORCE_SPEECH_TIMER);
        setEnum(L, "DA_DECLARE_WAR", DA_DECLARE_WAR);
        setEnum(L, "DA_END_WAR", DA_END_WAR);
        setEnum(L, "DA_CLEAR_AI", DA_CLEAR_AI);
        setEnum(L, "DA_FOLLOW_WHILE_TALKING", DA_FOLLOW_WHILE_TALKING);
        setEnum(L, "DA_THUG_HUNTER", DA_THUG_HUNTER);
        setEnum(L, "DA_JOIN_SQUAD_FAST", DA_JOIN_SQUAD_FAST);
        setEnum(L, "DA_REMEMBER_CHARACTER", DA_REMEMBER_CHARACTER);
        setEnum(L, "DA_FLAG_TEMP_ALLY", DA_FLAG_TEMP_ALLY);
        setEnum(L, "DA_FLAG_TEMP_ENEMY", DA_FLAG_TEMP_ENEMY);
        setEnum(L, "DA_MATES_KILL_ME", DA_MATES_KILL_ME);
        setEnum(L, "DA_MAKE_TARGET_RUN_FASTER", DA_MAKE_TARGET_RUN_FASTER);
        setEnum(L, "DA_GIVE_TARGET_MY_SLAVES", DA_GIVE_TARGET_MY_SLAVES);
        setEnum(L, "DA_TAG_ESCAPED_SLAVE", DA_TAG_ESCAPED_SLAVE);
        setEnum(L, "DA_FREE_TARGET_SLAVE", DA_FREE_TARGET_SLAVE);
        setEnum(L, "DA_MERGE_WITH_SIMILAR_SQUADS", DA_MERGE_WITH_SIMILAR_SQUADS);
        setEnum(L, "DA_SEPARATE_TO_MY_OWN_SQUAD", DA_SEPARATE_TO_MY_OWN_SQUAD);
        setEnum(L, "DA_ARREST_TARGET", DA_ARREST_TARGET);
        setEnum(L, "DA_ARREST_TARGETS_CARRIED_PERSON", DA_ARREST_TARGETS_CARRIED_PERSON);
        setEnum(L, "DA_ATTACK_TOWN", DA_ATTACK_TOWN);
        setEnum(L, "DA_ASSIGN_BOUNTY", DA_ASSIGN_BOUNTY);
        setEnum(L, "DA_CRIME_ALARM", DA_CRIME_ALARM);
        setEnum(L, "DA_RUN_AWAY", DA_RUN_AWAY);
        setEnum(L, "DA_INCREASE_FACTION_RANK", DA_INCREASE_FACTION_RANK);
        setEnum(L, "DA_LOCK_THIS_DIALOG", DA_LOCK_THIS_DIALOG);
        setEnum(L, "DA_ASSAULT_PHASE", DA_ASSAULT_PHASE);
        setEnum(L, "DA_RETREAT_PHASE", DA_RETREAT_PHASE);
        setEnum(L, "DA_VICTORY_PHASE", DA_VICTORY_PHASE);
        setEnum(L, "DA_ENSLAVE_TARGETS_CARRIED_PERSON", DA_ENSLAVE_TARGETS_CARRIED_PERSON);
        setEnum(L, "DA_CLEAR_BOUNTY", DA_CLEAR_BOUNTY);
        setEnum(L, "DA_PLAYER_SELL_PRISONERS", DA_PLAYER_SELL_PRISONERS);
        setEnum(L, "DA_PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE", DA_PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE);
        setEnum(L, "DA_SUMMON_MY_SQUAD", DA_SUMMON_MY_SQUAD);
        setEnum(L, "DA_REMOVE_SLAVE_STATUS", DA_REMOVE_SLAVE_STATUS);
        setEnum(L, "DA_OPEN_NEAREST_GATE", DA_OPEN_NEAREST_GATE);
        setEnum(L, "DA_ATTACK_STAY_NEAR_HOME", DA_ATTACK_STAY_NEAR_HOME);
        setEnum(L, "DA_MASSIVE_ALARM", DA_MASSIVE_ALARM);
        setEnum(L, "DA_ATTACK_IF_NO_COEXIST", DA_ATTACK_IF_NO_COEXIST);
        setEnum(L, "DA_KNOCKOUT", DA_KNOCKOUT);
        setEnum(L, "DA_END", DA_END);
    // aliases
        setEnum(L, "NONE", DA_NONE);
        setEnum(L, "TRADE", DA_TRADE);
        setEnum(L, "TALK_TO_LEADER", DA_TALK_TO_LEADER);
        setEnum(L, "JOIN_SQUAD_WITH_EDIT", DA_JOIN_SQUAD_WITH_EDIT);
        setEnum(L, "AFFECT_RELATIONS", DA_AFFECT_RELATIONS);
        setEnum(L, "AFFECT_REPUTATION", DA_AFFECT_REPUTATION);
        setEnum(L, "ATTACK_CHASE_FOREVER", DA_ATTACK_CHASE_FOREVER);
        setEnum(L, "GO_HOME", DA_GO_HOME);
        setEnum(L, "TAKE_MONEY", DA_TAKE_MONEY);
        setEnum(L, "GIVE_MONEY", DA_GIVE_MONEY);
        setEnum(L, "PAY_BOUNTY", DA_PAY_BOUNTY);
        setEnum(L, "CHARACTER_EDITOR", DA_CHARACTER_EDITOR);
        setEnum(L, "FORCE_SPEECH_TIMER", DA_FORCE_SPEECH_TIMER);
        setEnum(L, "DECLARE_WAR", DA_DECLARE_WAR);
        setEnum(L, "END_WAR", DA_END_WAR);
        setEnum(L, "CLEAR_AI", DA_CLEAR_AI);
        setEnum(L, "FOLLOW_WHILE_TALKING", DA_FOLLOW_WHILE_TALKING);
        setEnum(L, "THUG_HUNTER", DA_THUG_HUNTER);
        setEnum(L, "JOIN_SQUAD_FAST", DA_JOIN_SQUAD_FAST);
        setEnum(L, "REMEMBER_CHARACTER", DA_REMEMBER_CHARACTER);
        setEnum(L, "FLAG_TEMP_ALLY", DA_FLAG_TEMP_ALLY);
        setEnum(L, "FLAG_TEMP_ENEMY", DA_FLAG_TEMP_ENEMY);
        setEnum(L, "MATES_KILL_ME", DA_MATES_KILL_ME);
        setEnum(L, "MAKE_TARGET_RUN_FASTER", DA_MAKE_TARGET_RUN_FASTER);
        setEnum(L, "GIVE_TARGET_MY_SLAVES", DA_GIVE_TARGET_MY_SLAVES);
        setEnum(L, "TAG_ESCAPED_SLAVE", DA_TAG_ESCAPED_SLAVE);
        setEnum(L, "FREE_TARGET_SLAVE", DA_FREE_TARGET_SLAVE);
        setEnum(L, "MERGE_WITH_SIMILAR_SQUADS", DA_MERGE_WITH_SIMILAR_SQUADS);
        setEnum(L, "SEPARATE_TO_MY_OWN_SQUAD", DA_SEPARATE_TO_MY_OWN_SQUAD);
        setEnum(L, "ARREST_TARGET", DA_ARREST_TARGET);
        setEnum(L, "ARREST_TARGETS_CARRIED_PERSON", DA_ARREST_TARGETS_CARRIED_PERSON);
        setEnum(L, "ATTACK_TOWN", DA_ATTACK_TOWN);
        setEnum(L, "ASSIGN_BOUNTY", DA_ASSIGN_BOUNTY);
        setEnum(L, "CRIME_ALARM", DA_CRIME_ALARM);
        setEnum(L, "RUN_AWAY", DA_RUN_AWAY);
        setEnum(L, "INCREASE_FACTION_RANK", DA_INCREASE_FACTION_RANK);
        setEnum(L, "LOCK_THIS_DIALOG", DA_LOCK_THIS_DIALOG);
        setEnum(L, "ASSAULT_PHASE", DA_ASSAULT_PHASE);
        setEnum(L, "RETREAT_PHASE", DA_RETREAT_PHASE);
        setEnum(L, "VICTORY_PHASE", DA_VICTORY_PHASE);
        setEnum(L, "ENSLAVE_TARGETS_CARRIED_PERSON", DA_ENSLAVE_TARGETS_CARRIED_PERSON);
        setEnum(L, "CLEAR_BOUNTY", DA_CLEAR_BOUNTY);
        setEnum(L, "PLAYER_SELL_PRISONERS", DA_PLAYER_SELL_PRISONERS);
        setEnum(L, "PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE", DA_PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE);
        setEnum(L, "SUMMON_MY_SQUAD", DA_SUMMON_MY_SQUAD);
        setEnum(L, "REMOVE_SLAVE_STATUS", DA_REMOVE_SLAVE_STATUS);
        setEnum(L, "OPEN_NEAREST_GATE", DA_OPEN_NEAREST_GATE);
        setEnum(L, "ATTACK_STAY_NEAR_HOME", DA_ATTACK_STAY_NEAR_HOME);
        setEnum(L, "MASSIVE_ALARM", DA_MASSIVE_ALARM);
        setEnum(L, "ATTACK_IF_NO_COEXIST", DA_ATTACK_IF_NO_COEXIST);
        setEnum(L, "KNOCKOUT", DA_KNOCKOUT);
        setEnum(L, "END", DA_END);
    // global
        lua_setglobal(L, "DialogueAction");
    }

    // ------------------------------------------
    // Enums.h
    // ------------------------------------------

    void registerItemType(lua_State* L)
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

        void registerBuildingFunction(lua_State* L)
    {
        lua_newtable(L);

    // original
        setEnum(L, "BF_ANY", BuildingFunction::BF_ANY);
        setEnum(L, "BF_MINE", BuildingFunction::BF_MINE);
        setEnum(L, "BF_RESOURCE_STORAGE", BuildingFunction::BF_RESOURCE_STORAGE);
        setEnum(L, "BF_RESEARCH", BuildingFunction::BF_RESEARCH);
        setEnum(L, "BF_REFINERY", BuildingFunction::BF_REFINERY);
        setEnum(L, "BF_GENERATOR", BuildingFunction::BF_GENERATOR);
        setEnum(L, "BF_BED", BuildingFunction::BF_BED);
        setEnum(L, "BF_TRAINING", BuildingFunction::BF_TRAINING);
        setEnum(L, "BF_CAGE", BuildingFunction::BF_CAGE);
        setEnum(L, "BF_SHOP", BuildingFunction::BF_SHOP);
        setEnum(L, "BF_CRAFTING", BuildingFunction::BF_CRAFTING);
        setEnum(L, "BF_CORPSE_DISPOSAL", BuildingFunction::BF_CORPSE_DISPOSAL);
        setEnum(L, "BF_TURRET", BuildingFunction::BF_TURRET);
        setEnum(L, "BF_GENERAL_STORAGE", BuildingFunction::BF_GENERAL_STORAGE);
        setEnum(L, "BF_ITEM_FURNACE", BuildingFunction::BF_ITEM_FURNACE);
        setEnum(L, "BF_LIGHT", BuildingFunction::BF_LIGHT);
        setEnum(L, "BF_TABLE", BuildingFunction::BF_TABLE);
        setEnum(L, "BF_CHAIR", BuildingFunction::BF_CHAIR);
        setEnum(L, "BF_FLUFF", BuildingFunction::BF_FLUFF);
        setEnum(L, "BF_SHELL_WITH_INTERIOR", BuildingFunction::BF_SHELL_WITH_INTERIOR);
        setEnum(L, "BF_WALL", BuildingFunction::BF_WALL);
        setEnum(L, "BF_GATE", BuildingFunction::BF_GATE);
        setEnum(L, "BF_DOOR", BuildingFunction::BF_DOOR);
        setEnum(L, "BF_BATTERY", BuildingFunction::BF_BATTERY);
        setEnum(L, "BF_THRONE", BuildingFunction::BF_THRONE);
        setEnum(L, "BF_SKELETON_BED", BuildingFunction::BF_SKELETON_BED);
        setEnum(L, "BF_RAIN_COLLECTOR", BuildingFunction::BF_RAIN_COLLECTOR);
        setEnum(L, "BF_MINE_NATURAL", BuildingFunction::BF_MINE_NATURAL);
        setEnum(L, "BF_STEERING", BuildingFunction::BF_STEERING);
        setEnum(L, "BF_ENGINE", BuildingFunction::BF_ENGINE);
        setEnum(L, "BF_LIQUID_TANK", BuildingFunction::BF_LIQUID_TANK);
    // aliases
        setEnum(L, "ANY", BuildingFunction::BF_ANY);
        setEnum(L, "MINE", BuildingFunction::BF_MINE);
        setEnum(L, "RESOURCE_STORAGE", BuildingFunction::BF_RESOURCE_STORAGE);
        setEnum(L, "RESEARCH", BuildingFunction::BF_RESEARCH);
        setEnum(L, "REFINERY", BuildingFunction::BF_REFINERY);
        setEnum(L, "GENERATOR", BuildingFunction::BF_GENERATOR);
        setEnum(L, "BED", BuildingFunction::BF_BED);
        setEnum(L, "TRAINING", BuildingFunction::BF_TRAINING);
        setEnum(L, "CAGE", BuildingFunction::BF_CAGE);
        setEnum(L, "SHOP", BuildingFunction::BF_SHOP);
        setEnum(L, "CRAFTING", BuildingFunction::BF_CRAFTING);
        setEnum(L, "CORPSE_DISPOSAL", BuildingFunction::BF_CORPSE_DISPOSAL);
        setEnum(L, "TURRET", BuildingFunction::BF_TURRET);
        setEnum(L, "GENERAL_STORAGE", BuildingFunction::BF_GENERAL_STORAGE);
        setEnum(L, "ITEM_FURNACE", BuildingFunction::BF_ITEM_FURNACE);
        setEnum(L, "LIGHT", BuildingFunction::BF_LIGHT);
        setEnum(L, "TABLE", BuildingFunction::BF_TABLE);
        setEnum(L, "CHAIR", BuildingFunction::BF_CHAIR);
        setEnum(L, "FLUFF", BuildingFunction::BF_FLUFF);
        setEnum(L, "SHELL_WITH_INTERIOR", BuildingFunction::BF_SHELL_WITH_INTERIOR);
        setEnum(L, "WALL", BuildingFunction::BF_WALL);
        setEnum(L, "GATE", BuildingFunction::BF_GATE);
        setEnum(L, "DOOR", BuildingFunction::BF_DOOR);
        setEnum(L, "BATTERY", BuildingFunction::BF_BATTERY);
        setEnum(L, "THRONE", BuildingFunction::BF_THRONE);
        setEnum(L, "SKELETON_BED", BuildingFunction::BF_SKELETON_BED);
        setEnum(L, "RAIN_COLLECTOR", BuildingFunction::BF_RAIN_COLLECTOR);
        setEnum(L, "MINE_NATURAL", BuildingFunction::BF_MINE_NATURAL);
        setEnum(L, "STEERING", BuildingFunction::BF_STEERING);
        setEnum(L, "ENGINE", BuildingFunction::BF_ENGINE);
        setEnum(L, "LIQUID_TANK", BuildingFunction::BF_LIQUID_TANK);
    // global
        lua_setglobal(L, "BuildingFunction");
    }

        void registerCutDirection(lua_State* L)
    {
        lua_newtable(L);

    // original
        setEnum(L, "CUT_DEFAULT", CutDirection::CUT_DEFAULT);
        setEnum(L, "CUT_DOWNWARD", CutDirection::CUT_DOWNWARD);
        setEnum(L, "CUT_LEFT", CutDirection::CUT_LEFT);
        setEnum(L, "CUT_RIGHT", CutDirection::CUT_RIGHT);
        setEnum(L, "CUT_THRUST", CutDirection::CUT_THRUST);
        setEnum(L, "CUT_UPWARDS", CutDirection::CUT_UPWARDS);
        setEnum(L, "CUT_PIERCED", CutDirection::CUT_PIERCED);
        setEnum(L, "CUT_REAR_DOWNWARD", CutDirection::CUT_REAR_DOWNWARD);
        setEnum(L, "CUT_REAR_LEFT", CutDirection::CUT_REAR_LEFT);
        setEnum(L, "CUT_REAR_RIGHT", CutDirection::CUT_REAR_RIGHT);
    // aliases
        setEnum(L, "DEFAULT", CutDirection::CUT_DEFAULT);
        setEnum(L, "DOWNWARD", CutDirection::CUT_DOWNWARD);
        setEnum(L, "LEFT", CutDirection::CUT_LEFT);
        setEnum(L, "RIGHT", CutDirection::CUT_RIGHT);
        setEnum(L, "THRUST", CutDirection::CUT_THRUST);
        setEnum(L, "UPWARDS", CutDirection::CUT_UPWARDS);
        setEnum(L, "PIERCED", CutDirection::CUT_PIERCED);
        setEnum(L, "REAR_DOWNWARD", CutDirection::CUT_REAR_DOWNWARD);
        setEnum(L, "REAR_LEFT", CutDirection::CUT_REAR_LEFT);
        setEnum(L, "REAR_RIGHT", CutDirection::CUT_REAR_RIGHT);
    // global
        lua_setglobal(L, "CutDirection");
    }

    void registerCutOrigination(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "FRONT", CutOrigination::FRONT);
        setEnum(L, "REAR", CutOrigination::REAR);
        setEnum(L, "LEFTSIDE", CutOrigination::LEFTSIDE);
        setEnum(L, "RIGHTSIDE", CutOrigination::RIGHTSIDE);

        lua_setglobal(L, "CutOrigination");
    }

    void registerHitMaterialType(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "HIT_MISSED", HitMaterialType::HIT_MISSED);
        setEnum(L, "HIT_METAL", HitMaterialType::HIT_METAL);
        setEnum(L, "HIT_FLESH", HitMaterialType::HIT_FLESH);
        setEnum(L, "HIT_SAND", HitMaterialType::HIT_SAND);
        setEnum(L, "HIT_WOOD", HitMaterialType::HIT_WOOD);
        setEnum(L, "HIT_SWORD", HitMaterialType::HIT_SWORD);
        setEnum(L, "HIT_CHAIN", HitMaterialType::HIT_CHAIN);
    //aliases
        setEnum(L, "MISSED", HitMaterialType::HIT_MISSED);
        setEnum(L, "METAL", HitMaterialType::HIT_METAL);
        setEnum(L, "FLESH", HitMaterialType::HIT_FLESH);
        setEnum(L, "SAND", HitMaterialType::HIT_SAND);
        setEnum(L, "WOOD", HitMaterialType::HIT_WOOD);
        setEnum(L, "SWORD", HitMaterialType::HIT_SWORD);
        setEnum(L, "CHAIN", HitMaterialType::HIT_CHAIN);
    // global
        lua_setglobal(L, "HitMaterialType");
    }

    void registerWeatherAffecting(lua_State* L)
    {
        lua_newtable(L);
    // orignal
        setEnum(L, "WA_NONE", WeatherAffecting::WA_NONE);
        setEnum(L, "WA_DUSTSTORM", WeatherAffecting::WA_DUSTSTORM);
        setEnum(L, "WA_ACID", WeatherAffecting::WA_ACID);
        setEnum(L, "WA_BURNING", WeatherAffecting::WA_BURNING);
        setEnum(L, "WA_GAS", WeatherAffecting::WA_GAS);
        setEnum(L, "WA_RAIN", WeatherAffecting::WA_RAIN);
    // aliases
        setEnum(L, "NONE", WeatherAffecting::WA_NONE);
        setEnum(L, "DUSTSTORM", WeatherAffecting::WA_DUSTSTORM);
        setEnum(L, "ACID", WeatherAffecting::WA_ACID);
        setEnum(L, "BURNING", WeatherAffecting::WA_BURNING);
        setEnum(L, "GAS", WeatherAffecting::WA_GAS);
        setEnum(L, "RAIN", WeatherAffecting::WA_RAIN);

        lua_setglobal(L, "WeatherAffecting");
    }

        void registerAttachSlot(lua_State* L)
    {
        lua_newtable(L);

    // original
        setEnum(L, "ATTACH_WEAPON", AttachSlot::ATTACH_WEAPON);
        setEnum(L, "ATTACH_BACK", AttachSlot::ATTACH_BACK);
        setEnum(L, "ATTACH_HAIR", AttachSlot::ATTACH_HAIR);
        setEnum(L, "ATTACH_HAT", AttachSlot::ATTACH_HAT);
        setEnum(L, "ATTACH_EYES", AttachSlot::ATTACH_EYES);
        setEnum(L, "ATTACH_BODY", AttachSlot::ATTACH_BODY);
        setEnum(L, "ATTACH_LEGS", AttachSlot::ATTACH_LEGS);
        setEnum(L, "ATTACH_NONE", AttachSlot::ATTACH_NONE);
        setEnum(L, "ATTACH_SHIRT", AttachSlot::ATTACH_SHIRT);
        setEnum(L, "ATTACH_BOOTS", AttachSlot::ATTACH_BOOTS);
        setEnum(L, "ATTACH_GLOVES", AttachSlot::ATTACH_GLOVES);
        setEnum(L, "ATTACH_NECK", AttachSlot::ATTACH_NECK);
        setEnum(L, "ATTACH_BACKPACK", AttachSlot::ATTACH_BACKPACK);
        setEnum(L, "ATTACH_BEARD", AttachSlot::ATTACH_BEARD);
        setEnum(L, "ATTACH_BELT", AttachSlot::ATTACH_BELT);
        setEnum(L, "ATTACH_LEFT_ARM", AttachSlot::ATTACH_LEFT_ARM);
        setEnum(L, "ATTACH_RIGHT_ARM", AttachSlot::ATTACH_RIGHT_ARM);
        setEnum(L, "ATTACH_LEFT_LEG", AttachSlot::ATTACH_LEFT_LEG);
        setEnum(L, "ATTACH_RIGHT_LEG", AttachSlot::ATTACH_RIGHT_LEG);
    // aliases
        setEnum(L, "WEAPON", AttachSlot::ATTACH_WEAPON);
        setEnum(L, "BACK", AttachSlot::ATTACH_BACK);
        setEnum(L, "HAIR", AttachSlot::ATTACH_HAIR);
        setEnum(L, "HAT", AttachSlot::ATTACH_HAT);
        setEnum(L, "EYES", AttachSlot::ATTACH_EYES);
        setEnum(L, "BODY", AttachSlot::ATTACH_BODY);
        setEnum(L, "LEGS", AttachSlot::ATTACH_LEGS);
        setEnum(L, "NONE", AttachSlot::ATTACH_NONE);
        setEnum(L, "SHIRT", AttachSlot::ATTACH_SHIRT);
        setEnum(L, "BOOTS", AttachSlot::ATTACH_BOOTS);
        setEnum(L, "GLOVES", AttachSlot::ATTACH_GLOVES);
        setEnum(L, "NECK", AttachSlot::ATTACH_NECK);
        setEnum(L, "BACKPACK", AttachSlot::ATTACH_BACKPACK);
        setEnum(L, "BEARD", AttachSlot::ATTACH_BEARD);
        setEnum(L, "BELT", AttachSlot::ATTACH_BELT);
        setEnum(L, "LEFT_ARM", AttachSlot::ATTACH_LEFT_ARM);
        setEnum(L, "RIGHT_ARM", AttachSlot::ATTACH_RIGHT_ARM);
        setEnum(L, "LEFT_LEG", AttachSlot::ATTACH_LEFT_LEG);
        setEnum(L, "RIGHT_LEG", AttachSlot::ATTACH_RIGHT_LEG);
    // global
        lua_setglobal(L, "AttachSlot");
    }

    void registerItemFunction(lua_State* L)
    {
        lua_newtable(L);
    // orignal
        setEnum(L, "ITEM_NO_FUNCTION", ItemFunction::ITEM_NO_FUNCTION);
        setEnum(L, "ITEM_FIRSTAID", ItemFunction::ITEM_FIRSTAID);
        setEnum(L, "ITEM_MEDRIGGING", ItemFunction::ITEM_MEDRIGGING);
        setEnum(L, "ITEM_FOOD", ItemFunction::ITEM_FOOD);
        setEnum(L, "ITEM_CONTAINER", ItemFunction::ITEM_CONTAINER);
        setEnum(L, "ITEM_WEAPON", ItemFunction::ITEM_WEAPON);
        setEnum(L, "ITEM_CLOTHING", ItemFunction::ITEM_CLOTHING);
        setEnum(L, "ITEM____", ItemFunction::ITEM____);
        setEnum(L, "ITEM_NARCOTIC", ItemFunction::ITEM_NARCOTIC);
        setEnum(L, "ITEM_TOOL", ItemFunction::ITEM_TOOL);
        setEnum(L, "ITEM_ANYTHING", ItemFunction::ITEM_ANYTHING);
        setEnum(L, "ITEM_BLUEPRINT", ItemFunction::ITEM_BLUEPRINT);
        setEnum(L, "ITEM_ROBOTREPAIR", ItemFunction::ITEM_ROBOTREPAIR);
        setEnum(L, "ITEM_BOOK", ItemFunction::ITEM_BOOK);
        setEnum(L, "ITEM_MONEY", ItemFunction::ITEM_MONEY);
        setEnum(L, "ITEM_FOOD_RESTRICTED", ItemFunction::ITEM_FOOD_RESTRICTED);
        setEnum(L, "ITEM_AMMO", ItemFunction::ITEM_AMMO);
        setEnum(L, "ITEM_SEVERED_LIMB", ItemFunction::ITEM_SEVERED_LIMB);
    // aliases
        setEnum(L, "FIRSTAID", ItemFunction::ITEM_FIRSTAID);
        setEnum(L, "NO_FUNCTION", ItemFunction::ITEM_NO_FUNCTION);
        setEnum(L, "MEDRIGGING", ItemFunction::ITEM_MEDRIGGING);
        setEnum(L, "FOOD", ItemFunction::ITEM_FOOD);
        setEnum(L, "CONTAINER", ItemFunction::ITEM_CONTAINER);
        setEnum(L, "WEAPON", ItemFunction::ITEM_WEAPON);
        setEnum(L, "CLOTHING", ItemFunction::ITEM_CLOTHING);
        setEnum(L, "___", ItemFunction::ITEM____);
        setEnum(L, "NARCOTIC", ItemFunction::ITEM_NARCOTIC);
        setEnum(L, "TOOL", ItemFunction::ITEM_TOOL);
        setEnum(L, "ANYTHING", ItemFunction::ITEM_ANYTHING);
        setEnum(L, "BLUEPRINT", ItemFunction::ITEM_BLUEPRINT);
        setEnum(L, "ROBOTREPAIR", ItemFunction::ITEM_ROBOTREPAIR);
        setEnum(L, "BOOK", ItemFunction::ITEM_BOOK);
        setEnum(L, "MONEY", ItemFunction::ITEM_MONEY);
        setEnum(L, "FOOD_RESTRICTED", ItemFunction::ITEM_FOOD_RESTRICTED);
        setEnum(L, "AMMO", ItemFunction::ITEM_AMMO);
        setEnum(L, "SEVERED_LIMB", ItemFunction::ITEM_SEVERED_LIMB);

        lua_setglobal(L, "ItemFunction");
    }

    void registerArmourType(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "CLOTH", ArmourType::CLOTH);
        setEnum(L, "LEATHER", ArmourType::LEATHER);
        setEnum(L, "CHAIN", ArmourType::CHAIN);
        setEnum(L, "METAL_PLATE", ArmourType::METAL_PLATE);

        lua_setglobal(L, "ArmourType");
    }

    void registerCharacterTypeEnum(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "OT_NONE", CharacterTypeEnum::OT_NONE);
        setEnum(L, "OT_LAW_ENFORCEMENT", CharacterTypeEnum::OT_LAW_ENFORCEMENT);
        setEnum(L, "OT_MILITARY", CharacterTypeEnum::OT_MILITARY);
        setEnum(L, "OT_TRADER", CharacterTypeEnum::OT_TRADER);
        setEnum(L, "OT_CIVILIAN", CharacterTypeEnum::OT_CIVILIAN);
        setEnum(L, "OT_DIPLOMAT", CharacterTypeEnum::OT_DIPLOMAT);
        setEnum(L, "OT_SLAVE", CharacterTypeEnum::OT_SLAVE);
        setEnum(L, "OT_SLAVER", CharacterTypeEnum::OT_SLAVER);
        setEnum(L, "OT_BANDIT", CharacterTypeEnum::OT_BANDIT);
        setEnum(L, "OT_ADVENTURER", CharacterTypeEnum::OT_ADVENTURER);
        setEnum(L, "OT_END", CharacterTypeEnum::OT_END);
    // aliases
        setEnum(L, "LAW_ENFORCEMENT", CharacterTypeEnum::OT_LAW_ENFORCEMENT);
        setEnum(L, "NONE", CharacterTypeEnum::OT_NONE);
        setEnum(L, "MILITARY", CharacterTypeEnum::OT_MILITARY);
        setEnum(L, "TRADER", CharacterTypeEnum::OT_TRADER);
        setEnum(L, "CIVILIAN", CharacterTypeEnum::OT_CIVILIAN);
        setEnum(L, "DIPLOMAT", CharacterTypeEnum::OT_DIPLOMAT);
        setEnum(L, "SLAVE", CharacterTypeEnum::OT_SLAVE);
        setEnum(L, "SLAVER", CharacterTypeEnum::OT_SLAVER);
        setEnum(L, "BANDIT", CharacterTypeEnum::OT_BANDIT);
        setEnum(L, "ADVENTURER", CharacterTypeEnum::OT_ADVENTURER);
        setEnum(L, "END", CharacterTypeEnum::OT_END);

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

        setEnum(L, "NOT_SLAVE", SlaveStateEnum::NOT_SLAVE);
        setEnum(L, "IS_SLAVE", SlaveStateEnum::IS_SLAVE);
        setEnum(L, "ESCAPING_SLAVE", SlaveStateEnum::ESCAPING_SLAVE);
        setEnum(L, "EX_SLAVE", SlaveStateEnum::EX_SLAVE);

        lua_pushvalue(L, -1);
        lua_setglobal(L, "SlaveStateEnum");
        lua_setglobal(L, "SlaveState");
    }

    void registerTaskType(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "NULL_TASK", TaskType::NULL_TASK);
        setEnum(L, "MOVE_ON_FREE_WILL", TaskType::MOVE_ON_FREE_WILL);
        setEnum(L, "BUILD", TaskType::BUILD);
        setEnum(L, "PICKUP", TaskType::PICKUP);
        setEnum(L, "MELEE_ATTACK", TaskType::MELEE_ATTACK);
        setEnum(L, "FOCUSED_MELEE_ATTACK", TaskType::FOCUSED_MELEE_ATTACK);
        setEnum(L, "EQUIP_WEAPON", TaskType::EQUIP_WEAPON);
        setEnum(L, "UNEQUIP_WEAPON", TaskType::UNEQUIP_WEAPON);
        setEnum(L, "FIND_WEAPON", TaskType::FIND_WEAPON);
        setEnum(L, "CHOOSE_ENEMY_AND_ATTACK", TaskType::CHOOSE_ENEMY_AND_ATTACK);
        setEnum(L, "CHOOSE_ATTACKER_OF_ALLY", TaskType::CHOOSE_ATTACKER_OF_ALLY);
        setEnum(L, "ATTACK_CHARACTERS_ATTACKER", TaskType::ATTACK_CHARACTERS_ATTACKER);
        setEnum(L, "PLAYER_TALK_TO", TaskType::PLAYER_TALK_TO);
        setEnum(L, "ATTACK_ATTACKERS_OF", TaskType::ATTACK_ATTACKERS_OF);
        setEnum(L, "IDLE", TaskType::IDLE);
        setEnum(L, "PROTECT_ALLIES", TaskType::PROTECT_ALLIES);
        setEnum(L, "ATTACK_ENEMIES", TaskType::ATTACK_ENEMIES);
        setEnum(L, "PROTECTION", TaskType::PROTECTION);
        setEnum(L, "RAID_TOWN", TaskType::RAID_TOWN);
        setEnum(L, "GO_HOMEBUILDING", TaskType::GO_HOMEBUILDING);
        setEnum(L, "STAND_AT_SHOPKEEPER_NODE", TaskType::STAND_AT_SHOPKEEPER_NODE);
        setEnum(L, "ATTACK_ENEMIES_AND_NEUTRALS", TaskType::ATTACK_ENEMIES_AND_NEUTRALS);
        setEnum(L, "PATROL", TaskType::PATROL);
        setEnum(L, "ATTACK_TOWN", TaskType::ATTACK_TOWN);
        setEnum(L, "WANDERER", TaskType::WANDERER);
        setEnum(L, "FIRST_AID_ORDER", TaskType::FIRST_AID_ORDER);
        setEnum(L, "LOOT_TARGET", TaskType::LOOT_TARGET);
        setEnum(L, "CROUCH", TaskType::CROUCH);
        setEnum(L, "STAND_UP", TaskType::STAND_UP);
        setEnum(L, "MOVE_CUS_ORDERED", TaskType::MOVE_CUS_ORDERED);
        setEnum(L, "HOLD_POSITION", TaskType::HOLD_POSITION);
        setEnum(L, "STAY_CLOSE_TO_TARGET", TaskType::STAY_CLOSE_TO_TARGET);
        setEnum(L, "SELF_PRESERVATION", TaskType::SELF_PRESERVATION);
        setEnum(L, "QUELL_AGGRESSION", TaskType::QUELL_AGGRESSION);
        setEnum(L, "ATTACK_TROUBLE_MAKERS", TaskType::ATTACK_TROUBLE_MAKERS);
        setEnum(L, "RUN_AWAY", TaskType::RUN_AWAY);
        setEnum(L, "PATROL_TOWN", TaskType::PATROL_TOWN);
        setEnum(L, "WANDER_TOWN", TaskType::WANDER_TOWN);
        setEnum(L, "STAND_AT_GUARD_NODE_HOMEBUILDING_IN_OUT", TaskType::STAND_AT_GUARD_NODE_HOMEBUILDING_IN_OUT);
        setEnum(L, "WANDERING_TRADER", TaskType::WANDERING_TRADER);
        setEnum(L, "GET_NEAR_TO", TaskType::GET_NEAR_TO);
        setEnum(L, "ATTACK_ENEMIES_OF_MY_SLAVEMASTER", TaskType::ATTACK_ENEMIES_OF_MY_SLAVEMASTER);
        setEnum(L, "NOT_BE_UNARMED", TaskType::NOT_BE_UNARMED);
        setEnum(L, "STAY_IN_HOME", TaskType::STAY_IN_HOME);
        setEnum(L, "FOLLOW_PLAYER_ORDER", TaskType::FOLLOW_PLAYER_ORDER);
        setEnum(L, "BODYGUARD", TaskType::BODYGUARD);
        setEnum(L, "CHASE", TaskType::CHASE);
        setEnum(L, "STAND_AT_GENERAL_NODE", TaskType::STAND_AT_GENERAL_NODE);
        setEnum(L, "STAND_AT_DEFENSIVE_NODE", TaskType::STAND_AT_DEFENSIVE_NODE);
        setEnum(L, "STAND_AT_BUILDING_GUARD_NODE", TaskType::STAND_AT_BUILDING_GUARD_NODE);
        setEnum(L, "STAND_AT_BUILDING_DEFENSIVE_NODE", TaskType::STAND_AT_BUILDING_DEFENSIVE_NODE);
        setEnum(L, "STAND_AT_NODE", TaskType::STAND_AT_NODE);
        setEnum(L, "GET_UP_STAY_DOWN_THOUGH", TaskType::GET_UP_STAY_DOWN_THOUGH);
        setEnum(L, "TRAVEL_TO_TARGET_TOWN", TaskType::TRAVEL_TO_TARGET_TOWN);
        setEnum(L, "REST", TaskType::REST);
        setEnum(L, "RECRUIT_AT_JOBCENTER", TaskType::RECRUIT_AT_JOBCENTER);
        setEnum(L, "SWITCH_FOLLOW_ME_MODE_ON", TaskType::SWITCH_FOLLOW_ME_MODE_ON);
        setEnum(L, "JOB_REPAIR_ROBOT", TaskType::JOB_REPAIR_ROBOT);
        setEnum(L, "JOB_MEDIC", TaskType::JOB_MEDIC);
        setEnum(L, "GET_READY_FOR_ACTION", TaskType::GET_READY_FOR_ACTION);
        setEnum(L, "FIRST_AID_ROBOT", TaskType::FIRST_AID_ROBOT);
        setEnum(L, "UNPROVOKED_FOCUSED_MELEE_ATTACK", TaskType::UNPROVOKED_FOCUSED_MELEE_ATTACK);
        setEnum(L, "STAND_STILL", TaskType::STAND_STILL);
        setEnum(L, "SQUAD_WAIT_FOR_ME", TaskType::SQUAD_WAIT_FOR_ME);
        setEnum(L, "MAKE_TARGET_STAND_STILL", TaskType::MAKE_TARGET_STAND_STILL);
        setEnum(L, "GET_UP_STAND_UP", TaskType::GET_UP_STAND_UP);
        setEnum(L, "FORCE_GET_UP", TaskType::FORCE_GET_UP);
        setEnum(L, "MOVE_ON_FREE_WILL_FAST", TaskType::MOVE_ON_FREE_WILL_FAST);
        setEnum(L, "LIFT_PERSON", TaskType::LIFT_PERSON);
        setEnum(L, "PUT_DOWN_OBJECT", TaskType::PUT_DOWN_OBJECT);
        setEnum(L, "PUT_DOWN_CHARACTER_IN_BED", TaskType::PUT_DOWN_CHARACTER_IN_BED);
        setEnum(L, "ADD_MATERIALS_TO_BUILDING", TaskType::ADD_MATERIALS_TO_BUILDING);
        setEnum(L, "OPEN_DOOR", TaskType::OPEN_DOOR);
        setEnum(L, "CLOSE_DOOR", TaskType::CLOSE_DOOR);
        setEnum(L, "OPEN_DOOR_HERE", TaskType::OPEN_DOOR_HERE);
        setEnum(L, "CLOSE_DOOR_HERE", TaskType::CLOSE_DOOR_HERE);
        setEnum(L, "PICK_LOCK", TaskType::PICK_LOCK);
        setEnum(L, "LOCK_DOOR", TaskType::LOCK_DOOR);
        setEnum(L, "UNLOCK_DOOR", TaskType::UNLOCK_DOOR);
        setEnum(L, "LOCK_DOOR_HERE", TaskType::LOCK_DOOR_HERE);
        setEnum(L, "UNLOCK_DOOR_HERE", TaskType::UNLOCK_DOOR_HERE);
        setEnum(L, "BASH_DOOR", TaskType::BASH_DOOR);
        setEnum(L, "MOVE_TO_BUILDING_DOOR", TaskType::MOVE_TO_BUILDING_DOOR);
        setEnum(L, "MOVE_TO_CURRENT_LOCATION_BUILDING_DOOR", TaskType::MOVE_TO_CURRENT_LOCATION_BUILDING_DOOR);
        setEnum(L, "OPEN_DOOR_FOR_CURRENT_LOCATION", TaskType::OPEN_DOOR_FOR_CURRENT_LOCATION);
        setEnum(L, "OPEN_DOOR_FOR_DESTINATION", TaskType::OPEN_DOOR_FOR_DESTINATION);
        setEnum(L, "OPEN_UP_SHOP_DOORS", TaskType::OPEN_UP_SHOP_DOORS);
        setEnum(L, "OPERATE_MACHINERY", TaskType::OPERATE_MACHINERY);
        setEnum(L, "DELIVER_RESOURCES", TaskType::DELIVER_RESOURCES);
        setEnum(L, "JOB_KEEP_EVERYTHING_RUNNING", TaskType::JOB_KEEP_EVERYTHING_RUNNING);
        setEnum(L, "UNJAM_ALL_MACHINES", TaskType::UNJAM_ALL_MACHINES);
        setEnum(L, "UNJAM_MACHINE", TaskType::UNJAM_MACHINE);
        setEnum(L, "COLLECT_OUTPUT_RESOURCE", TaskType::COLLECT_OUTPUT_RESOURCE);
        setEnum(L, "FILL_MACHINE", TaskType::FILL_MACHINE);
        setEnum(L, "WANT_TO_FILL_MACHINE", TaskType::WANT_TO_FILL_MACHINE);
        setEnum(L, "REPAIR", TaskType::REPAIR);
        setEnum(L, "DISMANTLE", TaskType::DISMANTLE);
        setEnum(L, "USE_TRAINING_DUMMY", TaskType::USE_TRAINING_DUMMY);
        setEnum(L, "USE_BED", TaskType::USE_BED);
        setEnum(L, "PUT_SOMEONE_IN_BED", TaskType::PUT_SOMEONE_IN_BED);
        setEnum(L, "GET_PUT_IN_BED", TaskType::GET_PUT_IN_BED);
        setEnum(L, "DEFEAT_SQUAD", TaskType::DEFEAT_SQUAD);
        setEnum(L, "SEEK_AND_TALK_AND_SEND_SIGNAL", TaskType::SEEK_AND_TALK_AND_SEND_SIGNAL);
        setEnum(L, "MAKE_ANNOUNCEMENT", TaskType::MAKE_ANNOUNCEMENT);
        setEnum(L, "ALWAYS_IMPOSSIBLE_TASK", TaskType::ALWAYS_IMPOSSIBLE_TASK);
        setEnum(L, "FIND_AND_RESCUE", TaskType::FIND_AND_RESCUE);
        setEnum(L, "FIND_BED_AND_PUT_IN", TaskType::FIND_BED_AND_PUT_IN);
        setEnum(L, "USE_CAGE", TaskType::USE_CAGE);
        setEnum(L, "PUT_IN_CAGE", TaskType::PUT_IN_CAGE);
        setEnum(L, "KNOCKOUT_PRISONER", TaskType::KNOCKOUT_PRISONER);
        setEnum(L, "RELEASE_PRISONER", TaskType::RELEASE_PRISONER);
        setEnum(L, "BREAKOUT_PRISONER", TaskType::BREAKOUT_PRISONER);
        setEnum(L, "FIND_CAGE_AND_PUT_IN", TaskType::FIND_CAGE_AND_PUT_IN);
        setEnum(L, "EMPTY_MACHINE_OUTPUTS", TaskType::EMPTY_MACHINE_OUTPUTS);
        setEnum(L, "GET_RID_OF_RESOURCES_IN_MY_INVENTORY", TaskType::GET_RID_OF_RESOURCES_IN_MY_INVENTORY);
        setEnum(L, "FIND_SOME_BUILDING_MATERIALS", TaskType::FIND_SOME_BUILDING_MATERIALS);
        setEnum(L, "GET_OUT_OF_BED", TaskType::GET_OUT_OF_BED);
        setEnum(L, "FIND_A_SHOP", TaskType::FIND_A_SHOP);
        setEnum(L, "SHOPPING", TaskType::SHOPPING);
        setEnum(L, "BUY_SHIT", TaskType::BUY_SHIT);
        setEnum(L, "MOVE_INSIDE_BUILDING", TaskType::MOVE_INSIDE_BUILDING);
        setEnum(L, "MOVE_TO_FORTIFICATION_GATE", TaskType::MOVE_TO_FORTIFICATION_GATE);
        setEnum(L, "OPEN_FORTIFICATION_GATE", TaskType::OPEN_FORTIFICATION_GATE);
        setEnum(L, "BASH_GATE", TaskType::BASH_GATE);
        setEnum(L, "OPERATE_STORAGE", TaskType::OPERATE_STORAGE);
        setEnum(L, "JOB_BUILDER", TaskType::JOB_BUILDER);
        setEnum(L, "TALKTO_NEAREST_PLAYER_CHARACTER", TaskType::TALKTO_NEAREST_PLAYER_CHARACTER);
        setEnum(L, "RUN_AWAY_HOMETOWN", TaskType::RUN_AWAY_HOMETOWN);
        setEnum(L, "RETREAT_HOMETOWN", TaskType::RETREAT_HOMETOWN);
        setEnum(L, "MAKE_ANNOUNCEMENT_FAST", TaskType::MAKE_ANNOUNCEMENT_FAST);
        setEnum(L, "TRAVEL_TO_TARGET_TOWN_FAST", TaskType::TRAVEL_TO_TARGET_TOWN_FAST);
        setEnum(L, "LOOT_FOOD_AND_STUFF", TaskType::LOOT_FOOD_AND_STUFF);
        setEnum(L, "FIND_AND_KIDNAP", TaskType::FIND_AND_KIDNAP);
        setEnum(L, "GET_OUT_OF_CAGE_LEGIT", TaskType::GET_OUT_OF_CAGE_LEGIT);
        setEnum(L, "KILL_CAGE_OCCUPANT", TaskType::KILL_CAGE_OCCUPANT);
        setEnum(L, "KILL_A_RANDOM_CAGE_OCCUPANT", TaskType::KILL_A_RANDOM_CAGE_OCCUPANT);
        setEnum(L, "FEED_CORPSE_INTO_MACHINE", TaskType::FEED_CORPSE_INTO_MACHINE);
        setEnum(L, "DEAD_GUYS_GO_IN_THE_POT", TaskType::DEAD_GUYS_GO_IN_THE_POT);
        setEnum(L, "FIND_A_DEAD_GUY", TaskType::FIND_A_DEAD_GUY);
        setEnum(L, "EAT_A_RANDOM_CAGE_OCCUPANT", TaskType::EAT_A_RANDOM_CAGE_OCCUPANT);
        setEnum(L, "UNLOCK_DOOR_PLAYER_ORDER", TaskType::UNLOCK_DOOR_PLAYER_ORDER);
        setEnum(L, "FOLLOW_SQUADLEADER", TaskType::FOLLOW_SQUADLEADER);
        setEnum(L, "FIND_AND_RESCUE_LEADER", TaskType::FIND_AND_RESCUE_LEADER);
        setEnum(L, "PROTECT_OWN_SQUAD", TaskType::PROTECT_OWN_SQUAD);
        setEnum(L, "TERRITORIAL_AGGRESSION_BUT_DONT_LEAVE_HOME", TaskType::TERRITORIAL_AGGRESSION_BUT_DONT_LEAVE_HOME);
        setEnum(L, "GET_RE_EQUIPPED", TaskType::GET_RE_EQUIPPED);
        setEnum(L, "USE_TURRET", TaskType::USE_TURRET);
        setEnum(L, "STUMBLE_TASK_FORCED", TaskType::STUMBLE_TASK_FORCED);
        setEnum(L, "FIND_AND_RESCUE_IF_THERES_BEDS", TaskType::FIND_AND_RESCUE_IF_THERES_BEDS);
        setEnum(L, "MAN_A_TURRET", TaskType::MAN_A_TURRET);
        setEnum(L, "PROSPECTING", TaskType::PROSPECTING);
        setEnum(L, "EMPTYING_MACHINE", TaskType::EMPTYING_MACHINE);
        setEnum(L, "OPERATE_AUTOMATIC_MACHINERY", TaskType::OPERATE_AUTOMATIC_MACHINERY);
        setEnum(L, "GO_HOME_AND_GO_TO_BED", TaskType::GO_HOME_AND_GO_TO_BED);
        setEnum(L, "GO_TO_THE_BAR_AND_DRINK", TaskType::GO_TO_THE_BAR_AND_DRINK);
        setEnum(L, "LOCK_ALL_MY_DOORS", TaskType::LOCK_ALL_MY_DOORS);
        setEnum(L, "ENTER_BUILDING", TaskType::ENTER_BUILDING);
        setEnum(L, "STAND_AT_GUARD_NODE_HOMETOWN_OUTSIDE", TaskType::STAND_AT_GUARD_NODE_HOMETOWN_OUTSIDE);
        setEnum(L, "SHOO_STRANGERS_OUT_OF_MY_BUILDING", TaskType::SHOO_STRANGERS_OUT_OF_MY_BUILDING);
        setEnum(L, "SEND_DIALOGUE_SIGNAL", TaskType::SEND_DIALOGUE_SIGNAL);
        setEnum(L, "SEND_DIALOGUE_SIGNAL_REPEAT", TaskType::SEND_DIALOGUE_SIGNAL_REPEAT);
        setEnum(L, "SEND_DIALOGUE_SIGNAL_WITHOUT_MOVING", TaskType::SEND_DIALOGUE_SIGNAL_WITHOUT_MOVING);
        setEnum(L, "LOCK_DOOR_FROM_INSIDE", TaskType::LOCK_DOOR_FROM_INSIDE);
        setEnum(L, "MOVE_TO_BUILDING_DOOR_INSIDEPOS", TaskType::MOVE_TO_BUILDING_DOOR_INSIDEPOS);
        setEnum(L, "FOLLOW_WHILE_TALKING", TaskType::FOLLOW_WHILE_TALKING);
        setEnum(L, "TOWN_STALKER", TaskType::TOWN_STALKER);
        setEnum(L, "CHAIN_TARGET", TaskType::CHAIN_TARGET);
        setEnum(L, "CAPTURE_NEW_SLAVES", TaskType::CAPTURE_NEW_SLAVES);
        setEnum(L, "CARRY_WOUNDED_SLAVES", TaskType::CARRY_WOUNDED_SLAVES);
        setEnum(L, "PUT_DOWN_CARRIED_DUDE_IF_THEY_CAN_WALK", TaskType::PUT_DOWN_CARRIED_DUDE_IF_THEY_CAN_WALK);
        setEnum(L, "LIFT_OBJECT_BUT_HEAL_FIRST", TaskType::LIFT_OBJECT_BUT_HEAL_FIRST);
        setEnum(L, "FOLLOW_SLAVEMASTER", TaskType::FOLLOW_SLAVEMASTER);
        setEnum(L, "SLAVE_GET_IN_MY_MASTERS_CAGE", TaskType::SLAVE_GET_IN_MY_MASTERS_CAGE);
        setEnum(L, "GATHER_SLAVES_FROM_CAGES", TaskType::GATHER_SLAVES_FROM_CAGES);
        setEnum(L, "GET_SLAVE", TaskType::GET_SLAVE);
        setEnum(L, "SLEEP_ON_FLOOR", TaskType::SLEEP_ON_FLOOR);
        setEnum(L, "HUNTING_BLOODSMELL", TaskType::HUNTING_BLOODSMELL);
        setEnum(L, "LOOT_THE_DEAD", TaskType::LOOT_THE_DEAD);
        setEnum(L, "LOOT_TO_REPLACE_MISSING_WEAPON", TaskType::LOOT_TO_REPLACE_MISSING_WEAPON);
        setEnum(L, "HUNT_MY_THIEF", TaskType::HUNT_MY_THIEF);
        setEnum(L, "MAN_THE_GATE", TaskType::MAN_THE_GATE);
        setEnum(L, "STRIP_TARGETS_WEAPONS", TaskType::STRIP_TARGETS_WEAPONS);
        setEnum(L, "PROCESS_AND_STRIP_NEW_SLAVE", TaskType::PROCESS_AND_STRIP_NEW_SLAVE);
        setEnum(L, "SLAVE_WATCHING", TaskType::SLAVE_WATCHING);
        setEnum(L, "PUT_LOOT_IN_STORAGE", TaskType::PUT_LOOT_IN_STORAGE);
        setEnum(L, "SHACKLES", TaskType::CUT_SHACKLES);
        setEnum(L, "BRUTE_FORCE_SHACKLES", TaskType::BRUTE_FORCE_SHACKLES);
        setEnum(L, "SLAVE_OBEDIENCE", TaskType::_SLAVE_OBEDIENCE);
        setEnum(L, "WORK_THE_SLAVES", TaskType::WORK_THE_SLAVES);
        setEnum(L, "AUTO_LABOURING_MINES", TaskType::AUTO_LABOURING_MINES);
        setEnum(L, "AUTO_LABOURING_MINES_PRETEND", TaskType::AUTO_LABOURING_MINES_PRETEND);
        setEnum(L, "GO_TO_NEAREST_HQ", TaskType::GO_TO_NEAREST_HQ);
        setEnum(L, "GO_TO_SOMEWHERE_FOR_DELIVERING_SLAVES", TaskType::GO_TO_SOMEWHERE_FOR_DELIVERING_SLAVES);
        setEnum(L, "CAPTURE_ESCAPING_SLAVES", TaskType::CAPTURE_ESCAPING_SLAVES);
        setEnum(L, "GIVE_ALL_MY_SLAVES_TO", TaskType::GIVE_ALL_MY_SLAVES_TO);
        setEnum(L, "LOCK_ALL_THE_CAGES", TaskType::LOCK_ALL_THE_CAGES);
        setEnum(L, "BEAT_CAGE_OCCUPANT", TaskType::BEAT_CAGE_OCCUPANT);
        setEnum(L, "LOCK_ALL_MY_DOORS_FROM_OUTSIDE", TaskType::LOCK_ALL_MY_DOORS_FROM_OUTSIDE);
        setEnum(L, "LOCK_DOOR_FROM_OUTSIDE", TaskType::LOCK_DOOR_FROM_OUTSIDE);
        setEnum(L, "MOVE_TO_BUILDING_DOOR_OUTSIDEPOS", TaskType::MOVE_TO_BUILDING_DOOR_OUTSIDEPOS);
        setEnum(L, "LEAVE_BUILDING", TaskType::LEAVE_BUILDING);
        setEnum(L, "PICK_LOCK_ON_SHACKLES", TaskType::PICK_LOCK_ON_SHACKLES);
        setEnum(L, "TOTAL_ESCAPE", TaskType::TOTAL_ESCAPE);
        setEnum(L, "ARREST_TARGET", TaskType::ARREST_TARGET);
        setEnum(L, "HUNT_BOUNTIES", TaskType::HUNT_BOUNTIES);
        setEnum(L, "ARREST_TARGETS_CARRIED_PERSON", TaskType::ARREST_TARGETS_CARRIED_PERSON);
        setEnum(L, "FIND_CAGE_AND_PUT_IN_IF_BOUNTY", TaskType::FIND_CAGE_AND_PUT_IN_IF_BOUNTY);
        setEnum(L, "GET_OUT_OF_CAGE_ESCAPE", TaskType::GET_OUT_OF_CAGE_ESCAPE);
        setEnum(L, "GET_OUT_OF_BED_IF_ITS_EMERGENCY", TaskType::GET_OUT_OF_BED_IF_ITS_EMERGENCY);
        setEnum(L, "INVESTIGATE_ALARMS", TaskType::INVESTIGATE_ALARMS);
        setEnum(L, "INVESTIGATE_ALARMS_ALLIES_ONLY", TaskType::INVESTIGATE_ALARMS_ALLIES_ONLY);
        setEnum(L, "POLICE_FREE_PRISONERS_WHEN_DONE", TaskType::POLICE_FREE_PRISONERS_WHEN_DONE);
        setEnum(L, "LOOT_STOLEN_GOODS", TaskType::LOOT_STOLEN_GOODS);
        setEnum(L, "LIFT_PERSON_SNATCHING_ALLOWED", TaskType::LIFT_PERSON_SNATCHING_ALLOWED);
        setEnum(L, "RELAX_IN_TOWN_PACKAGE", TaskType::RELAX_IN_TOWN_PACKAGE);
        setEnum(L, "TRAVEL_TO_TARGET_PACKAGE", TaskType::TRAVEL_TO_TARGET_PACKAGE);
        setEnum(L, "RUN_AROUND_TOWN_LOOKING_FOR_PEOPLE", TaskType::RUN_AROUND_TOWN_LOOKING_FOR_PEOPLE);
        setEnum(L, "GATHER_SLAVES_FROM_CAGES_IF_ITS_AN_EXPORT_TOWN", TaskType::GATHER_SLAVES_FROM_CAGES_IF_ITS_AN_EXPORT_TOWN);
        setEnum(L, "GIVE_ALL_MY_SLAVES_TO_IF_ITS_AN_IMPORT_TOWN", TaskType::GIVE_ALL_MY_SLAVES_TO_IF_ITS_AN_IMPORT_TOWN);
        setEnum(L, "TAKE_OFF_MY_SHACKLES", TaskType::TAKE_OFF_MY_SHACKLES);
        setEnum(L, "EAT_TARGET_ALIVE", TaskType::EAT_TARGET_ALIVE);
        setEnum(L, "PRETEND_TO_OPERATE_MACHINERY", TaskType::PRETEND_TO_OPERATE_MACHINERY);
        setEnum(L, "MAN_A_TURRET_ON_BUILDING", TaskType::MAN_A_TURRET_ON_BUILDING);
        setEnum(L, "PICKUP_INTRUDERS_BUILDING", TaskType::PICKUP_INTRUDERS_BUILDING);
        setEnum(L, "TAKE_INTRUDER_OUTSIDE", TaskType::TAKE_INTRUDER_OUTSIDE);
        setEnum(L, "LIFT_PERSON_PLAYER_ORDER", TaskType::LIFT_PERSON_PLAYER_ORDER);
        setEnum(L, "BASH_DOOR_PLAYER_ORDER", TaskType::BASH_DOOR_PLAYER_ORDER);
        setEnum(L, "MELEE_ATTACK_ANIMAL", TaskType::MELEE_ATTACK_ANIMAL);
        setEnum(L, "STEALTH_KNOCKOUT", TaskType::STEALTH_KNOCKOUT);
        setEnum(L, "STEALTH_KILL", TaskType::STEALTH_KILL);
        setEnum(L, "EAT_A_RANDOM_DEAD_BODY", TaskType::EAT_A_RANDOM_DEAD_BODY);
        setEnum(L, "EAT_CROPS", TaskType::EAT_CROPS);
        setEnum(L, "FIND_CROPS_TO_EAT", TaskType::FIND_CROPS_TO_EAT);
        setEnum(L, "EAT_A_RANDOM_KO_BODY", TaskType::EAT_A_RANDOM_KO_BODY);
        setEnum(L, "MAN_A_TURRET_PLAYER_JOB", TaskType::MAN_A_TURRET_PLAYER_JOB);
        setEnum(L, "SHOOT_AT_TARGET", TaskType::SHOOT_AT_TARGET);
        setEnum(L, "WORSHIP_TARGET", TaskType::WORSHIP_TARGET);
        setEnum(L, "FOGMAN_WORSHIP_VICTIM", TaskType::FOGMAN_WORSHIP_VICTIM);
        setEnum(L, "LOOT_ANIMALS_JOB", TaskType::LOOT_ANIMALS_JOB);
        setEnum(L, "GO_HOME_AND_GO_TO_BED_SECURE", TaskType::GO_HOME_AND_GO_TO_BED_SECURE);
        setEnum(L, "LIFT_PERSON_SNATCHING_ALLOWED_IN_TOWN_ONLY", TaskType::LIFT_PERSON_SNATCHING_ALLOWED_IN_TOWN_ONLY);
        setEnum(L, "LOOT_RESOURCE_ITEMS_WE_HAVE_STORAGE_FOR", TaskType::LOOT_RESOURCE_ITEMS_WE_HAVE_STORAGE_FOR);
        setEnum(L, "DITCH_ALL_RESOURCES", TaskType::DITCH_ALL_RESOURCES);
        setEnum(L, "AQUIRE_FOOD_AT_HOMEBASE", TaskType::AQUIRE_FOOD_AT_HOMEBASE);
        setEnum(L, "GRAB_ONE_FOOD", TaskType::GRAB_ONE_FOOD);
        setEnum(L, "GATHER_PRISONERS_FROM_CAGES_IF_FEMALE_OR_BEAST", TaskType::GATHER_PRISONERS_FROM_CAGES_IF_FEMALE_OR_BEAST);
        setEnum(L, "KIDNAP_ORDER", TaskType::KIDNAP_ORDER);
        setEnum(L, "COLLECT_OUTPUT_RESOURCE_BUILD_MATS", TaskType::COLLECT_OUTPUT_RESOURCE_BUILD_MATS);
        setEnum(L, "DEFEAT_SQUAD_LIMIT_CHASE_RANGE", TaskType::DEFEAT_SQUAD_LIMIT_CHASE_RANGE);
        setEnum(L, "SPLINT_ORDER", TaskType::SPLINT_ORDER);
        setEnum(L, "SPLINT_JOB", TaskType::SPLINT_JOB);
        setEnum(L, "ESCAPE_KIDNAP", TaskType::ESCAPE_KIDNAP);
        setEnum(L, "ESCAPE_KIDNAP_STR", TaskType::ESCAPE_KIDNAP_STR);
        setEnum(L, "FOLLOW_URGENT_ESCAPE", TaskType::FOLLOW_URGENT_ESCAPE);
        setEnum(L, "FINAL_KIDNAPPER_CAGE_JOB", TaskType::FINAL_KIDNAPPER_CAGE_JOB);
        setEnum(L, "SIT_ON_THRONE", TaskType::SIT_ON_THRONE);
        setEnum(L, "GET_OUT_OF_CAGE_OPPORTUNISTIC", TaskType::GET_OUT_OF_CAGE_OPPORTUNISTIC);
        setEnum(L, "GET_OUT_OF_BED_ONCE_HEALED", TaskType::GET_OUT_OF_BED_ONCE_HEALED);
        setEnum(L, "USE_BED_ORDER", TaskType::USE_BED_ORDER);
        setEnum(L, "EAT_FOOD_ON_GROUND", TaskType::EAT_FOOD_ON_GROUND);
        setEnum(L, "NEW_SLAVE_PROCESSING", TaskType::NEW_SLAVE_PROCESSING);
        setEnum(L, "SLEEP_ON_FLOOR_FAKE_AMBUSH", TaskType::SLEEP_ON_FLOOR_FAKE_AMBUSH);
        setEnum(L, "RANGED_ATTACK", TaskType::RANGED_ATTACK);
        setEnum(L, "RANGED_ATTACK_FOCUSED", TaskType::RANGED_ATTACK_FOCUSED);
        setEnum(L, "EQUIP_CROSSBOW", TaskType::EQUIP_CROSSBOW);
        setEnum(L, "UNEQUIP_CROSSBOW", TaskType::UNEQUIP_CROSSBOW);
        setEnum(L, "RANGED_ATTACK_FOCUSED_UNPROVOKED", TaskType::RANGED_ATTACK_FOCUSED_UNPROVOKED);
        setEnum(L, "MOVE_IN_BOW_RANGE", TaskType::MOVE_IN_BOW_RANGE);
        setEnum(L, "STAND_AT_GUARD_NODE_HOMEBUILDING_INDOORS_ONLY", TaskType::STAND_AT_GUARD_NODE_HOMEBUILDING_INDOORS_ONLY);
        setEnum(L, "HEAL_MY_LEGS", TaskType::HEAL_MY_LEGS);
        setEnum(L, "ASSAULT_FORTIFICATIONS_PREFER_GATES", TaskType::ASSAULT_FORTIFICATIONS_PREFER_GATES);
        setEnum(L, "ASSAULT_FORTIFICATIONS_PREFER_WALLS", TaskType::ASSAULT_FORTIFICATIONS_PREFER_WALLS);
        setEnum(L, "SMASH_BUILDING", TaskType::SMASH_BUILDING);
        setEnum(L, "PICKUP_INTRUDERS_TOWN", TaskType::PICKUP_INTRUDERS_TOWN);
        setEnum(L, "TAKE_INTRUDER_OUTSIDE_TOWN", TaskType::TAKE_INTRUDER_OUTSIDE_TOWN);
        setEnum(L, "SIT_AROUND", TaskType::SIT_AROUND);
        setEnum(L, "LIBERATE_ALL_THE_PRISONERS", TaskType::LIBERATE_ALL_THE_PRISONERS);
        setEnum(L, "ANIMAL_FETCH_A_LIMB", TaskType::ANIMAL_FETCH_A_LIMB);
        setEnum(L, "PLAY_BECAUSE_I_HAVE_A_LIMB_IN_MOUTH", TaskType::PLAY_BECAUSE_I_HAVE_A_LIMB_IN_MOUTH);
        setEnum(L, "CHASE_ALLY_DOGS_WITH_MOUTH_LIMBS", TaskType::CHASE_ALLY_DOGS_WITH_MOUTH_LIMBS);
        setEnum(L, "RUN_AWAY_FORCED", TaskType::RUN_AWAY_FORCED);
        setEnum(L, "FIND_CAGE_AND_PUT_DEADGUY_IN", TaskType::FIND_CAGE_AND_PUT_DEADGUY_IN);
        setEnum(L, "EAT_A_RANDOM_CAGE_OCCUPANT_MEASURED_RATE", TaskType::EAT_A_RANDOM_CAGE_OCCUPANT_MEASURED_RATE);
        setEnum(L, "SHOO_STRANGERS_OUT_OF_MY_BUILDING_IF_PRIVATE", TaskType::SHOO_STRANGERS_OUT_OF_MY_BUILDING_IF_PRIVATE);
        setEnum(L, "LOOT_CONTAINER", TaskType::LOOT_CONTAINER);
        setEnum(L, "LOCK", TaskType::CUT_LOCK);
        setEnum(L, "BRUTE_FORCE_LOCK", TaskType::BRUTE_FORCE_LOCK);
        setEnum(L, "BASH_DOOR_HERE", TaskType::BASH_DOOR_HERE);
        setEnum(L, "PROTECT_ALLIES_STAY_IN_TOWN", TaskType::PROTECT_ALLIES_STAY_IN_TOWN);
        setEnum(L, "STAY_CLOSE_TO_TARGET_ANIMAL", TaskType::STAY_CLOSE_TO_TARGET_ANIMAL);
        setEnum(L, "BASH_GATE_PLAYER_ORDER", TaskType::BASH_GATE_PLAYER_ORDER);

        lua_setglobal(L, "TaskType");
    }

        void registerWeaponCategory(lua_State* L)
    {
        lua_newtable(L);

    // original
        setEnum(L, "SKILL_KATANAS", WeaponCategory::SKILL_KATANAS);
        setEnum(L, "SKILL_SABRES", WeaponCategory::SKILL_SABRES);
        setEnum(L, "SKILL_BLUNT", WeaponCategory::SKILL_BLUNT);
        setEnum(L, "SKILL_HEAVY", WeaponCategory::SKILL_HEAVY);
        setEnum(L, "SKILL_HACKERS", WeaponCategory::SKILL_HACKERS);
        setEnum(L, "SKILL_UNARMED", WeaponCategory::SKILL_UNARMED);
        setEnum(L, "SKILL_BOW", WeaponCategory::SKILL_BOW);
        setEnum(L, "SKILL_TURRET", WeaponCategory::SKILL_TURRET);
        setEnum(L, "ATTACK_POLEARMS", WeaponCategory::ATTACK_POLEARMS);
        setEnum(L, "ATTACK_ELEPHANT", WeaponCategory::ATTACK_ELEPHANT);
        setEnum(L, "ATTACK_DOG", WeaponCategory::ATTACK_DOG);
        setEnum(L, "ATTACK_BULL", WeaponCategory::ATTACK_BULL);
        setEnum(L, "ATTACK_ROBOTSPIDER", WeaponCategory::ATTACK_ROBOTSPIDER);
        setEnum(L, "ATTACK_SPIDER", WeaponCategory::ATTACK_SPIDER);
        setEnum(L, "ATTACK_CAGEBEAST", WeaponCategory::ATTACK_CAGEBEAST);
        setEnum(L, "ATTACK_DUCK", WeaponCategory::ATTACK_DUCK);
        setEnum(L, "ATTACK_GORILLA", WeaponCategory::ATTACK_GORILLA);
        setEnum(L, "ATTACK_GAR", WeaponCategory::ATTACK_GAR);
        setEnum(L, "ATTACK_FROG", WeaponCategory::ATTACK_FROG);
        setEnum(L, "ATTACK_GOAT", WeaponCategory::ATTACK_GOAT);
        setEnum(L, "ATTACK_GIRAFFE", WeaponCategory::ATTACK_GIRAFFE);
        setEnum(L, "ATTACK_NULL", WeaponCategory::ATTACK_NULL);
        setEnum(L, "NUM_SKILL_TYPES", WeaponCategory::NUM_SKILL_TYPES);
    // aliases
        setEnum(L, "KATANAS", WeaponCategory::SKILL_KATANAS);
        setEnum(L, "SABRES", WeaponCategory::SKILL_SABRES);
        setEnum(L, "BLUNT", WeaponCategory::SKILL_BLUNT);
        setEnum(L, "HEAVY", WeaponCategory::SKILL_HEAVY);
        setEnum(L, "HACKERS", WeaponCategory::SKILL_HACKERS);
        setEnum(L, "UNARMED", WeaponCategory::SKILL_UNARMED);
        setEnum(L, "BOW", WeaponCategory::SKILL_BOW);
        setEnum(L, "TURRET", WeaponCategory::SKILL_TURRET);
        setEnum(L, "POLEARMS", WeaponCategory::ATTACK_POLEARMS);
        setEnum(L, "ELEPHANT", WeaponCategory::ATTACK_ELEPHANT);
        setEnum(L, "DOG", WeaponCategory::ATTACK_DOG);
        setEnum(L, "BULL", WeaponCategory::ATTACK_BULL);
        setEnum(L, "ROBOTSPIDER", WeaponCategory::ATTACK_ROBOTSPIDER);
        setEnum(L, "SPIDER", WeaponCategory::ATTACK_SPIDER);
        setEnum(L, "CAGEBEAST", WeaponCategory::ATTACK_CAGEBEAST);
        setEnum(L, "DUCK", WeaponCategory::ATTACK_DUCK);
        setEnum(L, "GORILLA", WeaponCategory::ATTACK_GORILLA);
        setEnum(L, "GAR", WeaponCategory::ATTACK_GAR);
        setEnum(L, "FROG", WeaponCategory::ATTACK_FROG);
        setEnum(L, "GOAT", WeaponCategory::ATTACK_GOAT);
        setEnum(L, "GIRAFFE", WeaponCategory::ATTACK_GIRAFFE);
        setEnum(L, "NULL", WeaponCategory::ATTACK_NULL);
    // global
        lua_setglobal(L, "WeaponCategory");
    }

    void registerLeftRight(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "SIDE_NEITHER", LeftRight::SIDE_NEITHER);
        setEnum(L, "SIDE_LEFT", LeftRight::SIDE_LEFT);
        setEnum(L, "SIDE_RIGHT", LeftRight::SIDE_RIGHT);
        setEnum(L, "SIDE_BOTH", LeftRight::SIDE_BOTH);
    // aliases
        setEnum(L, "NEITHER", LeftRight::SIDE_NEITHER);
        setEnum(L, "LEFT", LeftRight::SIDE_LEFT);
        setEnum(L, "RIGHT", LeftRight::SIDE_RIGHT);
        setEnum(L, "BOTH", LeftRight::SIDE_BOTH);

        lua_setglobal(L, "LeftRight");
    }

    void registerMessageType(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "M_UNSELECT_ALL", MessageForB::MessageType::M_UNSELECT_ALL);
        setEnum(L, "M_GIVE_TASK", MessageForB::MessageType::M_GIVE_TASK);
    // aliases
        setEnum(L, "UNSELECT_ALL", MessageForB::MessageType::M_UNSELECT_ALL);
        setEnum(L, "GIVE_TASK", MessageForB::MessageType::M_GIVE_TASK);

        lua_setglobal(L, "MessageType");
    }

    void registerStandingOrder(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "M_SET_ORDER_RUN", MessageForB::StandingOrder::M_SET_ORDER_RUN);
        setEnum(L, "M_SET_ORDER_JOG", MessageForB::StandingOrder::M_SET_ORDER_JOG);
        setEnum(L, "M_SET_ORDER_WALK", MessageForB::StandingOrder::M_SET_ORDER_WALK);
        setEnum(L, "M_SET_ORDER_STEALTH_ON", MessageForB::StandingOrder::M_SET_ORDER_STEALTH_ON);
        setEnum(L, "M_SET_ORDER_STEALTH_OFF", MessageForB::StandingOrder::M_SET_ORDER_STEALTH_OFF);
        setEnum(L, "M_SET_ORDER_AGG", MessageForB::StandingOrder::M_SET_ORDER_AGG);
        setEnum(L, "M_SET_ORDER_DEF", MessageForB::StandingOrder::M_SET_ORDER_DEF);
        setEnum(L, "M_SET_ORDER_EVADE", MessageForB::StandingOrder::M_SET_ORDER_EVADE);
        setEnum(L, "M_SET_ORDER_FAR", MessageForB::StandingOrder::M_SET_ORDER_FAR);
        setEnum(L, "M_SET_ORDER_NEAR", MessageForB::StandingOrder::M_SET_ORDER_NEAR);
        setEnum(L, "M__TOGGLEORDERS__AFTER__THIS_", MessageForB::StandingOrder::M__TOGGLEORDERS__AFTER__THIS_);
        setEnum(L, "M_SET_ORDER_DEFENSIVE_COMBAT", MessageForB::StandingOrder::M_SET_ORDER_DEFENSIVE_COMBAT);
        setEnum(L, "M_SET_ORDER_HOLD", MessageForB::StandingOrder::M_SET_ORDER_HOLD);
        setEnum(L, "M_SET_ORDER_PASSIVE", MessageForB::StandingOrder::M_SET_ORDER_PASSIVE);
        setEnum(L, "M_SET_ORDER_TAUNT", MessageForB::StandingOrder::M_SET_ORDER_TAUNT);
        setEnum(L, "M_SET_ORDER_CHASE", MessageForB::StandingOrder::M_SET_ORDER_CHASE);
        setEnum(L, "M_SET_ORDER_GROUP_SPEED", MessageForB::StandingOrder::M_SET_ORDER_GROUP_SPEED);
        setEnum(L, "M_SET_ORDER_RANGED", MessageForB::StandingOrder::M_SET_ORDER_RANGED);
    // aliases
        setEnum(L, "RUN", MessageForB::StandingOrder::M_SET_ORDER_RUN);
        setEnum(L, "JOG", MessageForB::StandingOrder::M_SET_ORDER_JOG);
        setEnum(L, "WALK", MessageForB::StandingOrder::M_SET_ORDER_WALK);
        setEnum(L, "STEALTH_ON", MessageForB::StandingOrder::M_SET_ORDER_STEALTH_ON);
        setEnum(L, "STEALTH_OFF", MessageForB::StandingOrder::M_SET_ORDER_STEALTH_OFF);
        setEnum(L, "AGG", MessageForB::StandingOrder::M_SET_ORDER_AGG);
        setEnum(L, "DEF", MessageForB::StandingOrder::M_SET_ORDER_DEF);
        setEnum(L, "EVADE", MessageForB::StandingOrder::M_SET_ORDER_EVADE);
        setEnum(L, "FAR", MessageForB::StandingOrder::M_SET_ORDER_FAR);
        setEnum(L, "NEAR", MessageForB::StandingOrder::M_SET_ORDER_NEAR);
        setEnum(L, "TOGGLEORDERS__AFTER__THIS", MessageForB::StandingOrder::M__TOGGLEORDERS__AFTER__THIS_);
        setEnum(L, "DEFENSIVE_COMBAT", MessageForB::StandingOrder::M_SET_ORDER_DEFENSIVE_COMBAT);
        setEnum(L, "HOLD", MessageForB::StandingOrder::M_SET_ORDER_HOLD);
        setEnum(L, "PASSIVE", MessageForB::StandingOrder::M_SET_ORDER_PASSIVE);
        setEnum(L, "TAUNT", MessageForB::StandingOrder::M_SET_ORDER_TAUNT);
        setEnum(L, "CHASE", MessageForB::StandingOrder::M_SET_ORDER_CHASE);
        setEnum(L, "GROUP_SPEED", MessageForB::StandingOrder::M_SET_ORDER_GROUP_SPEED);
        setEnum(L, "RANGED", MessageForB::StandingOrder::M_SET_ORDER_RANGED);

        lua_setglobal(L, "MessageB_StandingOrder");
    }

    void registerStatsEnumerated(lua_State* L)
    {
        lua_newtable(L);
    // orignal
        setEnum(L, "STAT_NONE", StatsEnumerated::STAT_NONE);
        setEnum(L, "STAT_STRENGTH", StatsEnumerated::STAT_STRENGTH);
        setEnum(L, "STAT_MELEE_ATTACK", StatsEnumerated::STAT_MELEE_ATTACK);
        setEnum(L, "STAT_LABOURING", StatsEnumerated::STAT_LABOURING);
        setEnum(L, "STAT_SCIENCE", StatsEnumerated::STAT_SCIENCE);
        setEnum(L, "STAT_ENGINEERING", StatsEnumerated::STAT_ENGINEERING);
        setEnum(L, "STAT_ROBOTICS", StatsEnumerated::STAT_ROBOTICS);
        setEnum(L, "STAT_SMITHING_WEAPON", StatsEnumerated::STAT_SMITHING_WEAPON);
        setEnum(L, "STAT_SMITHING_ARMOUR", StatsEnumerated::STAT_SMITHING_ARMOUR);
        setEnum(L, "STAT_MEDIC", StatsEnumerated::STAT_MEDIC);
        setEnum(L, "STAT_THIEVING", StatsEnumerated::STAT_THIEVING);
        setEnum(L, "STAT_TURRETS", StatsEnumerated::STAT_TURRETS);
        setEnum(L, "STAT_FARMING", StatsEnumerated::STAT_FARMING);
        setEnum(L, "STAT_COOKING", StatsEnumerated::STAT_COOKING);
        setEnum(L, "STAT_HIVEMEDIC", StatsEnumerated::STAT_HIVEMEDIC);
        setEnum(L, "STAT_VET", StatsEnumerated::STAT_VET);
        setEnum(L, "STAT_STEALTH", StatsEnumerated::STAT_STEALTH);
        setEnum(L, "STAT_ATHLETICS", StatsEnumerated::STAT_ATHLETICS);
        setEnum(L, "STAT_DEXTERITY", StatsEnumerated::STAT_DEXTERITY);
        setEnum(L, "STAT_MELEE_DEFENCE", StatsEnumerated::STAT_MELEE_DEFENCE);
        setEnum(L, "STAT_WEAPONS", StatsEnumerated::STAT_WEAPONS);
        setEnum(L, "STAT_TOUGHNESS", StatsEnumerated::STAT_TOUGHNESS);
        setEnum(L, "STAT_ASSASSINATION", StatsEnumerated::STAT_ASSASSINATION);
        setEnum(L, "STAT_SWIMMING", StatsEnumerated::STAT_SWIMMING);
        setEnum(L, "STAT_PERCEPTION", StatsEnumerated::STAT_PERCEPTION);
        setEnum(L, "STAT_KATANAS", StatsEnumerated::STAT_KATANAS);
        setEnum(L, "STAT_SABRES", StatsEnumerated::STAT_SABRES);
        setEnum(L, "STAT_HACKERS", StatsEnumerated::STAT_HACKERS);
        setEnum(L, "STAT_HEAVYWEAPONS", StatsEnumerated::STAT_HEAVYWEAPONS);
        setEnum(L, "STAT_BLUNT", StatsEnumerated::STAT_BLUNT);
        setEnum(L, "STAT_MARTIALARTS", StatsEnumerated::STAT_MARTIALARTS);
        setEnum(L, "STAT_MASSCOMBAT", StatsEnumerated::STAT_MASSCOMBAT);
        setEnum(L, "STAT_DODGE", StatsEnumerated::STAT_DODGE);
        setEnum(L, "STAT_SURVIVAL", StatsEnumerated::STAT_SURVIVAL);
        setEnum(L, "STAT_POLEARMS", StatsEnumerated::STAT_POLEARMS);
        setEnum(L, "STAT_CROSSBOWS", StatsEnumerated::STAT_CROSSBOWS);
        setEnum(L, "STAT_FRIENDLY_FIRE", StatsEnumerated::STAT_FRIENDLY_FIRE);
        setEnum(L, "STAT_LOCKPICKING", StatsEnumerated::STAT_LOCKPICKING);
        setEnum(L, "STAT_SMITHING_BOW", StatsEnumerated::STAT_SMITHING_BOW);
        setEnum(L, "STAT_END", StatsEnumerated::STAT_END);
        setEnum(L, "_PrimaryWeaponDamage", StatsEnumerated::_PrimaryWeaponDamage);
        setEnum(L, "_PrimaryWeaponSpeed", StatsEnumerated::_PrimaryWeaponSpeed);
        setEnum(L, "_SecondaryWeaponDamage", StatsEnumerated::_SecondaryWeaponDamage);
        setEnum(L, "_SecondaryWeaponSpeed", StatsEnumerated::_SecondaryWeaponSpeed);
        setEnum(L, "_MaxCarryWeight", StatsEnumerated::_MaxCarryWeight);
        setEnum(L, "_StrengthXPRateWalk", StatsEnumerated::_StrengthXPRateWalk);
        setEnum(L, "_StrengthXPRateCombat", StatsEnumerated::_StrengthXPRateCombat);
        setEnum(L, "_AttackSpeedHeavyWeapons", StatsEnumerated::_AttackSpeedHeavyWeapons);
        setEnum(L, "_DamageResistance", StatsEnumerated::_DamageResistance);
        setEnum(L, "_ToughnessXPRate", StatsEnumerated::_ToughnessXPRate);
        setEnum(L, "_KnockoutTime", StatsEnumerated::_KnockoutTime);
        setEnum(L, "_ToughnessKnockoutPoint", StatsEnumerated::_ToughnessKnockoutPoint);
        setEnum(L, "_WoundDeteriorationSpeed", StatsEnumerated::_WoundDeteriorationSpeed);
        setEnum(L, "_MaxRunSpeed", StatsEnumerated::_MaxRunSpeed);
        setEnum(L, "_CurrentRunSpeed", StatsEnumerated::_CurrentRunSpeed);
        setEnum(L, "_AthleticsXPBonus", StatsEnumerated::_AthleticsXPBonus);
        setEnum(L, "_TurretAccuracy", StatsEnumerated::_TurretAccuracy);
        setEnum(L, "TurretRateOfFire", StatsEnumerated::_TurretRateOfFire);
        setEnum(L, "TurretFriendlyFireAvoidance", StatsEnumerated::_TurretFriendlyFireAvoidance);
        setEnum(L, "_BuildingRate", StatsEnumerated::_BuildingRate);
        setEnum(L, "_RepairingRate", StatsEnumerated::_RepairingRate);
        setEnum(L, "_Mining", StatsEnumerated::_Mining);
        setEnum(L, "_Farming", StatsEnumerated::_Farming);
        setEnum(L, "_UsingMachinery", StatsEnumerated::_UsingMachinery);
        setEnum(L, "_encumbrance", StatsEnumerated::_encumbrance);
        setEnum(L, "_combatSpeed", StatsEnumerated::_combatSpeed);
    //aliases
        setEnum(L, "NONE", StatsEnumerated::STAT_NONE);
        setEnum(L, "STRENGTH", StatsEnumerated::STAT_STRENGTH);
        setEnum(L, "MELEE_ATTACK", StatsEnumerated::STAT_MELEE_ATTACK);
        setEnum(L, "LABOURING", StatsEnumerated::STAT_LABOURING);
        setEnum(L, "SCIENCE", StatsEnumerated::STAT_SCIENCE);
        setEnum(L, "ENGINEERING", StatsEnumerated::STAT_ENGINEERING);
        setEnum(L, "ROBOTICS", StatsEnumerated::STAT_ROBOTICS);
        setEnum(L, "SMITHING_WEAPON", StatsEnumerated::STAT_SMITHING_WEAPON);
        setEnum(L, "SMITHING_ARMOUR", StatsEnumerated::STAT_SMITHING_ARMOUR);
        setEnum(L, "MEDIC", StatsEnumerated::STAT_MEDIC);
        setEnum(L, "THIEVING", StatsEnumerated::STAT_THIEVING);
        setEnum(L, "TURRETS", StatsEnumerated::STAT_TURRETS);
        setEnum(L, "FARMING", StatsEnumerated::STAT_FARMING);
        setEnum(L, "COOKING", StatsEnumerated::STAT_COOKING);
        setEnum(L, "HIVEMEDIC", StatsEnumerated::STAT_HIVEMEDIC);
        setEnum(L, "VET", StatsEnumerated::STAT_VET);
        setEnum(L, "STEALTH", StatsEnumerated::STAT_STEALTH);
        setEnum(L, "ATHLETICS", StatsEnumerated::STAT_ATHLETICS);
        setEnum(L, "DEXTERITY", StatsEnumerated::STAT_DEXTERITY);
        setEnum(L, "MELEE_DEFENCE", StatsEnumerated::STAT_MELEE_DEFENCE);
        setEnum(L, "WEAPONS", StatsEnumerated::STAT_WEAPONS);
        setEnum(L, "TOUGHNESS", StatsEnumerated::STAT_TOUGHNESS);
        setEnum(L, "ASSASSINATION", StatsEnumerated::STAT_ASSASSINATION);
        setEnum(L, "SWIMMING", StatsEnumerated::STAT_SWIMMING);
        setEnum(L, "PERCEPTION", StatsEnumerated::STAT_PERCEPTION);
        setEnum(L, "KATANAS", StatsEnumerated::STAT_KATANAS);
        setEnum(L, "SABRES", StatsEnumerated::STAT_SABRES);
        setEnum(L, "HACKERS", StatsEnumerated::STAT_HACKERS);
        setEnum(L, "HEAVYWEAPONS", StatsEnumerated::STAT_HEAVYWEAPONS);
        setEnum(L, "BLUNT", StatsEnumerated::STAT_BLUNT);
        setEnum(L, "MARTIALARTS", StatsEnumerated::STAT_MARTIALARTS);
        setEnum(L, "MASSCOMBAT", StatsEnumerated::STAT_MASSCOMBAT);
        setEnum(L, "DODGE", StatsEnumerated::STAT_DODGE);
        setEnum(L, "SURVIVAL", StatsEnumerated::STAT_SURVIVAL);
        setEnum(L, "POLEARMS", StatsEnumerated::STAT_POLEARMS);
        setEnum(L, "CROSSBOWS", StatsEnumerated::STAT_CROSSBOWS);
        setEnum(L, "FRIENDLY_FIRE", StatsEnumerated::STAT_FRIENDLY_FIRE);
        setEnum(L, "LOCKPICKING", StatsEnumerated::STAT_LOCKPICKING);
        setEnum(L, "SMITHING_BOW", StatsEnumerated::STAT_SMITHING_BOW);
        setEnum(L, "END", StatsEnumerated::STAT_END);
        setEnum(L, "PrimaryWeaponDamage", StatsEnumerated::_PrimaryWeaponDamage);
        setEnum(L, "PrimaryWeaponSpeed", StatsEnumerated::_PrimaryWeaponSpeed);
        setEnum(L, "SecondaryWeaponDamage", StatsEnumerated::_SecondaryWeaponDamage);
        setEnum(L, "SecondaryWeaponSpeed", StatsEnumerated::_SecondaryWeaponSpeed);
        setEnum(L, "MaxCarryWeight", StatsEnumerated::_MaxCarryWeight);
        setEnum(L, "StrengthXPRateWalk", StatsEnumerated::_StrengthXPRateWalk);
        setEnum(L, "StrengthXPRateCombat", StatsEnumerated::_StrengthXPRateCombat);
        setEnum(L, "AttackSpeedHeavyWeapons", StatsEnumerated::_AttackSpeedHeavyWeapons);
        setEnum(L, "DamageResistance", StatsEnumerated::_DamageResistance);
        setEnum(L, "ToughnessXPRate", StatsEnumerated::_ToughnessXPRate);
        setEnum(L, "KnockoutTime", StatsEnumerated::_KnockoutTime);
        setEnum(L, "ToughnessKnockoutPoint", StatsEnumerated::_ToughnessKnockoutPoint);
        setEnum(L, "WoundDeteriorationSpeed", StatsEnumerated::_WoundDeteriorationSpeed);
        setEnum(L, "MaxRunSpeed", StatsEnumerated::_MaxRunSpeed);
        setEnum(L, "CurrentRunSpeed", StatsEnumerated::_CurrentRunSpeed);
        setEnum(L, "AthleticsXPBonus", StatsEnumerated::_AthleticsXPBonus);
        setEnum(L, "TurretAccuracy", StatsEnumerated::_TurretAccuracy);
        setEnum(L, "TurretRateOfFire", StatsEnumerated::_TurretRateOfFire);
        setEnum(L, "TurretFriendlyFireAvoidance", StatsEnumerated::_TurretFriendlyFireAvoidance);
        setEnum(L, "BuildingRate", StatsEnumerated::_BuildingRate);
        setEnum(L, "RepairingRate", StatsEnumerated::_RepairingRate);
        setEnum(L, "Mining", StatsEnumerated::_Mining);
        setEnum(L, "Farming", StatsEnumerated::_Farming);
        setEnum(L, "UsingMachinery", StatsEnumerated::_UsingMachinery);
        setEnum(L, "Encumbrance", StatsEnumerated::_encumbrance);
        setEnum(L, "CombatSpeed", StatsEnumerated::_combatSpeed);

        lua_pushvalue(L, -1);
        lua_setglobal(L, "StatsEnumerated");
        lua_setglobal(L, "Stats");
    }

        void registerEventTriggerEnum(lua_State* L)
    {
        lua_newtable(L);

    // original
        setEnum(L, "EV_NONE", EventTriggerEnum::EV_NONE);
        setEnum(L, "EV_PLAYER_TALK_TO_ME", EventTriggerEnum::EV_PLAYER_TALK_TO_ME);
        setEnum(L, "EV_ANNOUNCEMENT", EventTriggerEnum::EV_ANNOUNCEMENT);
        setEnum(L, "EV_I_SEE_NEUTRAL_SQUAD", EventTriggerEnum::EV_I_SEE_NEUTRAL_SQUAD);
        setEnum(L, "EV_I_SEE_RAGDOLL", EventTriggerEnum::EV_I_SEE_RAGDOLL);
        setEnum(L, "EV_______", EventTriggerEnum::EV_______);
        setEnum(L, "EV_I_________", EventTriggerEnum::EV_I_________);
        setEnum(L, "EV_SHOO_FROM_MY_BUILDING", EventTriggerEnum::EV_SHOO_FROM_MY_BUILDING);
        setEnum(L, "EV_MARKED_FOR_DEATH", EventTriggerEnum::EV_MARKED_FOR_DEATH);
        setEnum(L, "EV_SCREAMING_TORTURE", EventTriggerEnum::EV_SCREAMING_TORTURE);
        setEnum(L, "EV_BAR_TALK", EventTriggerEnum::EV_BAR_TALK);
        setEnum(L, "EV_UNLOCK_MY_CAGE_OR_SHACKLES", EventTriggerEnum::EV_UNLOCK_MY_CAGE_OR_SHACKLES);
        setEnum(L, "EV_UNLOCK_MY_CAGE_ATTEMPT", EventTriggerEnum::EV_UNLOCK_MY_CAGE_ATTEMPT);
        setEnum(L, "EV_I_DEFEATED_SQUAD", EventTriggerEnum::EV_I_DEFEATED_SQUAD);
        setEnum(L, "EV_LAUNCH_ATTACK", EventTriggerEnum::EV_LAUNCH_ATTACK);
        setEnum(L, "EV_INTRUDER_FOUND", EventTriggerEnum::EV_INTRUDER_FOUND);
        setEnum(L, "EV_HEALING_OTHER_START", EventTriggerEnum::EV_HEALING_OTHER_START);
        setEnum(L, "EV_BEING_HEALED_START", EventTriggerEnum::EV_BEING_HEALED_START);
        setEnum(L, "EV_HEALING_OTHER_FINISHED", EventTriggerEnum::EV_HEALING_OTHER_FINISHED);
        setEnum(L, "EV_BEING_HEALED_FINISHED", EventTriggerEnum::EV_BEING_HEALED_FINISHED);
        setEnum(L, "EV_FIRSTAID_KIT_EMPTY", EventTriggerEnum::EV_FIRSTAID_KIT_EMPTY);
        setEnum(L, "EV_GET_UP_PEACE", EventTriggerEnum::EV_GET_UP_PEACE);
        setEnum(L, "EV_GET_UP_FIGHT", EventTriggerEnum::EV_GET_UP_FIGHT);
        setEnum(L, "EV_GET_UP_UNNECCESSARY_FIGHT", EventTriggerEnum::EV_GET_UP_UNNECCESSARY_FIGHT);
        setEnum(L, "EV_HARRASSMENT_SHOUTS", EventTriggerEnum::EV_HARRASSMENT_SHOUTS);
        setEnum(L, "EV_I_SEE_ANIMAL_SQUAD", EventTriggerEnum::EV_I_SEE_ANIMAL_SQUAD);
        setEnum(L, "EV_SPEECH_INTERRUPTED_ATTACKED_BY_TARGET", EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_TARGET);
        setEnum(L, "EV_SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS", EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS);
        setEnum(L, "EV_CONTRACT_JOB_ENDED", EventTriggerEnum::EV_CONTRACT_JOB_ENDED);
        setEnum(L, "EV_BETRAYAL", EventTriggerEnum::EV_BETRAYAL);
        setEnum(L, "EV_LOOTING_WEAPON_ONLY", EventTriggerEnum::EV_LOOTING_WEAPON_ONLY);
        setEnum(L, "EV_LOOTING_EVERYTHING", EventTriggerEnum::EV_LOOTING_EVERYTHING);
        setEnum(L, "EV_I_SEE_UNIFORM_IMPOSTER", EventTriggerEnum::EV_I_SEE_UNIFORM_IMPOSTER);
        setEnum(L, "EV_INTRODUCING_NEW_SLAVE", EventTriggerEnum::EV_INTRODUCING_NEW_SLAVE);
        setEnum(L, "EV_ESCAPING_SLAVE_SPOTTED", EventTriggerEnum::EV_ESCAPING_SLAVE_SPOTTED);
        setEnum(L, "EV_RECAPTURED_A_SLAVE", EventTriggerEnum::EV_RECAPTURED_A_SLAVE);
        setEnum(L, "EV_SHOUT_AT_SLAVE_WORKER", EventTriggerEnum::EV_SHOUT_AT_SLAVE_WORKER);
        setEnum(L, "EV_SLAVE_DELIVERY", EventTriggerEnum::EV_SLAVE_DELIVERY);
        setEnum(L, "EV_ESCAPED_EX_SLAVE_SPOTTED", EventTriggerEnum::EV_ESCAPED_EX_SLAVE_SPOTTED);
        setEnum(L, "EV_WITNESS_GENERIC_ASSAULT", EventTriggerEnum::EV_WITNESS_GENERIC_ASSAULT);
        setEnum(L, "EV_WITNESS_LOOTING_ALLY", EventTriggerEnum::EV_WITNESS_LOOTING_ALLY);
        setEnum(L, "EV_WITNESS_THIEF_OR_LOCKPICK", EventTriggerEnum::EV_WITNESS_THIEF_OR_LOCKPICK);
        setEnum(L, "EV_BOUNTY_SPOTTED", EventTriggerEnum::EV_BOUNTY_SPOTTED);
        setEnum(L, "EV_ESCAPED_PRISONER_SPOTTED", EventTriggerEnum::EV_ESCAPED_PRISONER_SPOTTED);
        setEnum(L, "EV_PRISONER_FREE_TO_GO", EventTriggerEnum::EV_PRISONER_FREE_TO_GO);
        setEnum(L, "EV_ALMOST_WOKE_UP", EventTriggerEnum::EV_ALMOST_WOKE_UP);
        setEnum(L, "EV_ENTER_BIOME", EventTriggerEnum::EV_ENTER_BIOME);
        setEnum(L, "EV_ENTER_TOWN", EventTriggerEnum::EV_ENTER_TOWN);
        setEnum(L, "EV_SQUAD_BROKEN", EventTriggerEnum::EV_SQUAD_BROKEN);
        setEnum(L, "EV_BOUGHT_ME_FROM_SLAVERY", EventTriggerEnum::EV_BOUGHT_ME_FROM_SLAVERY);
        setEnum(L, "EV_EATING_SOMETHING_SOUNDS", EventTriggerEnum::EV_EATING_SOMETHING_SOUNDS);
        setEnum(L, "EV_WORSHIPING_SOMETHING", EventTriggerEnum::EV_WORSHIPING_SOMETHING);
        setEnum(L, "EV_SLAVE_ESCAPE_OPPORTUNITY_SAVIOR", EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_SAVIOR);
        setEnum(L, "EV_SLAVE_ESCAPE_OPPORTUNITY_ALONE", EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_ALONE);
        setEnum(L, "EV_ASSASSINATION_FAILED", EventTriggerEnum::EV_ASSASSINATION_FAILED);
        setEnum(L, "EV_EATING_MY_CROPS", EventTriggerEnum::EV_EATING_MY_CROPS);
        setEnum(L, "EV_KIDNAPPING_MY_ALLY", EventTriggerEnum::EV_KIDNAPPING_MY_ALLY);
        setEnum(L, "EV_USING_MY_TRAINING_EQUIPMENT", EventTriggerEnum::EV_USING_MY_TRAINING_EQUIPMENT);
        setEnum(L, "EV_GIVE_UP_CHASE", EventTriggerEnum::EV_GIVE_UP_CHASE);
        setEnum(L, "EV_ACID_FEET", EventTriggerEnum::EV_ACID_FEET);
        setEnum(L, "EV_ACID_RAIN", EventTriggerEnum::EV_ACID_RAIN);
        setEnum(L, "EV_ACID_WATER", EventTriggerEnum::EV_ACID_WATER);
        setEnum(L, "EV_WINDY", EventTriggerEnum::EV_WINDY);
        setEnum(L, "EV_POISON_GAS", EventTriggerEnum::EV_POISON_GAS);
        setEnum(L, "EV_I_SEE_ENEMY_PLAYER", EventTriggerEnum::EV_I_SEE_ENEMY_PLAYER);
        setEnum(L, "EV_I_SEE_ALLY_PLAYER", EventTriggerEnum::EV_I_SEE_ALLY_PLAYER);
        setEnum(L, "EV_I_SEE_ILLEGAL_PLAYER_BUILDING", EventTriggerEnum::EV_I_SEE_ILLEGAL_PLAYER_BUILDING);
        setEnum(L, "EV_BURNING", EventTriggerEnum::EV_BURNING);
        setEnum(L, "EV_LOST_LEG", EventTriggerEnum::EV_LOST_LEG);
        setEnum(L, "EV_LOST_ARM", EventTriggerEnum::EV_LOST_ARM);
        setEnum(L, "EV_I_SEE_PLAYER_NICE_BUILDING", EventTriggerEnum::EV_I_SEE_PLAYER_NICE_BUILDING);
        setEnum(L, "EV_TAKEN_OVER_PLAYER_TOWN", EventTriggerEnum::EV_TAKEN_OVER_PLAYER_TOWN);
        setEnum(L, "EV_CROWD_TRIGGERED", EventTriggerEnum::EV_CROWD_TRIGGERED);
        setEnum(L, "EV_MAX", EventTriggerEnum::EV_MAX);
    // aliases
        setEnum(L, "NONE", EventTriggerEnum::EV_NONE);
        setEnum(L, "PLAYER_TALK_TO_ME", EventTriggerEnum::EV_PLAYER_TALK_TO_ME);
        setEnum(L, "ANNOUNCEMENT", EventTriggerEnum::EV_ANNOUNCEMENT);
        setEnum(L, "I_SEE_NEUTRAL_SQUAD", EventTriggerEnum::EV_I_SEE_NEUTRAL_SQUAD);
        setEnum(L, "I_SEE_RAGDOLL", EventTriggerEnum::EV_I_SEE_RAGDOLL);
        setEnum(L, "______", EventTriggerEnum::EV_______);
        setEnum(L, "I_________", EventTriggerEnum::EV_I_________);
        setEnum(L, "SHOO_FROM_MY_BUILDING", EventTriggerEnum::EV_SHOO_FROM_MY_BUILDING);
        setEnum(L, "MARKED_FOR_DEATH", EventTriggerEnum::EV_MARKED_FOR_DEATH);
        setEnum(L, "SCREAMING_TORTURE", EventTriggerEnum::EV_SCREAMING_TORTURE);
        setEnum(L, "BAR_TALK", EventTriggerEnum::EV_BAR_TALK);
        setEnum(L, "UNLOCK_MY_CAGE_OR_SHACKLES", EventTriggerEnum::EV_UNLOCK_MY_CAGE_OR_SHACKLES);
        setEnum(L, "UNLOCK_MY_CAGE_ATTEMPT", EventTriggerEnum::EV_UNLOCK_MY_CAGE_ATTEMPT);
        setEnum(L, "I_DEFEATED_SQUAD", EventTriggerEnum::EV_I_DEFEATED_SQUAD);
        setEnum(L, "LAUNCH_ATTACK", EventTriggerEnum::EV_LAUNCH_ATTACK);
        setEnum(L, "INTRUDER_FOUND", EventTriggerEnum::EV_INTRUDER_FOUND);
        setEnum(L, "HEALING_OTHER_START", EventTriggerEnum::EV_HEALING_OTHER_START);
        setEnum(L, "BEING_HEALED_START", EventTriggerEnum::EV_BEING_HEALED_START);
        setEnum(L, "HEALING_OTHER_FINISHED", EventTriggerEnum::EV_HEALING_OTHER_FINISHED);
        setEnum(L, "BEING_HEALED_FINISHED", EventTriggerEnum::EV_BEING_HEALED_FINISHED);
        setEnum(L, "FIRSTAID_KIT_EMPTY", EventTriggerEnum::EV_FIRSTAID_KIT_EMPTY);
        setEnum(L, "GET_UP_PEACE", EventTriggerEnum::EV_GET_UP_PEACE);
        setEnum(L, "GET_UP_FIGHT", EventTriggerEnum::EV_GET_UP_FIGHT);
        setEnum(L, "GET_UP_UNNECCESSARY_FIGHT", EventTriggerEnum::EV_GET_UP_UNNECCESSARY_FIGHT);
        setEnum(L, "HARRASSMENT_SHOUTS", EventTriggerEnum::EV_HARRASSMENT_SHOUTS);
        setEnum(L, "I_SEE_ANIMAL_SQUAD", EventTriggerEnum::EV_I_SEE_ANIMAL_SQUAD);
        setEnum(L, "SPEECH_INTERRUPTED_ATTACKED_BY_TARGET", EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_TARGET);
        setEnum(L, "SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS", EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS);
        setEnum(L, "CONTRACT_JOB_ENDED", EventTriggerEnum::EV_CONTRACT_JOB_ENDED);
        setEnum(L, "BETRAYAL", EventTriggerEnum::EV_BETRAYAL);
        setEnum(L, "LOOTING_WEAPON_ONLY", EventTriggerEnum::EV_LOOTING_WEAPON_ONLY);
        setEnum(L, "LOOTING_EVERYTHING", EventTriggerEnum::EV_LOOTING_EVERYTHING);
        setEnum(L, "I_SEE_UNIFORM_IMPOSTER", EventTriggerEnum::EV_I_SEE_UNIFORM_IMPOSTER);
        setEnum(L, "INTRODUCING_NEW_SLAVE", EventTriggerEnum::EV_INTRODUCING_NEW_SLAVE);
        setEnum(L, "ESCAPING_SLAVE_SPOTTED", EventTriggerEnum::EV_ESCAPING_SLAVE_SPOTTED);
        setEnum(L, "RECAPTURED_A_SLAVE", EventTriggerEnum::EV_RECAPTURED_A_SLAVE);
        setEnum(L, "SHOUT_AT_SLAVE_WORKER", EventTriggerEnum::EV_SHOUT_AT_SLAVE_WORKER);
        setEnum(L, "SLAVE_DELIVERY", EventTriggerEnum::EV_SLAVE_DELIVERY);
        setEnum(L, "ESCAPED_EX_SLAVE_SPOTTED", EventTriggerEnum::EV_ESCAPED_EX_SLAVE_SPOTTED);
        setEnum(L, "WITNESS_GENERIC_ASSAULT", EventTriggerEnum::EV_WITNESS_GENERIC_ASSAULT);
        setEnum(L, "WITNESS_LOOTING_ALLY", EventTriggerEnum::EV_WITNESS_LOOTING_ALLY);
        setEnum(L, "WITNESS_THIEF_OR_LOCKPICK", EventTriggerEnum::EV_WITNESS_THIEF_OR_LOCKPICK);
        setEnum(L, "BOUNTY_SPOTTED", EventTriggerEnum::EV_BOUNTY_SPOTTED);
        setEnum(L, "ESCAPED_PRISONER_SPOTTED", EventTriggerEnum::EV_ESCAPED_PRISONER_SPOTTED);
        setEnum(L, "PRISONER_FREE_TO_GO", EventTriggerEnum::EV_PRISONER_FREE_TO_GO);
        setEnum(L, "ALMOST_WOKE_UP", EventTriggerEnum::EV_ALMOST_WOKE_UP);
        setEnum(L, "ENTER_BIOME", EventTriggerEnum::EV_ENTER_BIOME);
        setEnum(L, "ENTER_TOWN", EventTriggerEnum::EV_ENTER_TOWN);
        setEnum(L, "SQUAD_BROKEN", EventTriggerEnum::EV_SQUAD_BROKEN);
        setEnum(L, "BOUGHT_ME_FROM_SLAVERY", EventTriggerEnum::EV_BOUGHT_ME_FROM_SLAVERY);
        setEnum(L, "EATING_SOMETHING_SOUNDS", EventTriggerEnum::EV_EATING_SOMETHING_SOUNDS);
        setEnum(L, "WORSHIPING_SOMETHING", EventTriggerEnum::EV_WORSHIPING_SOMETHING);
        setEnum(L, "SLAVE_ESCAPE_OPPORTUNITY_SAVIOR", EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_SAVIOR);
        setEnum(L, "SLAVE_ESCAPE_OPPORTUNITY_ALONE", EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_ALONE);
        setEnum(L, "ASSASSINATION_FAILED", EventTriggerEnum::EV_ASSASSINATION_FAILED);
        setEnum(L, "EATING_MY_CROPS", EventTriggerEnum::EV_EATING_MY_CROPS);
        setEnum(L, "KIDNAPPING_MY_ALLY", EventTriggerEnum::EV_KIDNAPPING_MY_ALLY);
        setEnum(L, "USING_MY_TRAINING_EQUIPMENT", EventTriggerEnum::EV_USING_MY_TRAINING_EQUIPMENT);
        setEnum(L, "GIVE_UP_CHASE", EventTriggerEnum::EV_GIVE_UP_CHASE);
        setEnum(L, "ACID_FEET", EventTriggerEnum::EV_ACID_FEET);
        setEnum(L, "ACID_RAIN", EventTriggerEnum::EV_ACID_RAIN);
        setEnum(L, "ACID_WATER", EventTriggerEnum::EV_ACID_WATER);
        setEnum(L, "WINDY", EventTriggerEnum::EV_WINDY);
        setEnum(L, "POISON_GAS", EventTriggerEnum::EV_POISON_GAS);
        setEnum(L, "I_SEE_ENEMY_PLAYER", EventTriggerEnum::EV_I_SEE_ENEMY_PLAYER);
        setEnum(L, "I_SEE_ALLY_PLAYER", EventTriggerEnum::EV_I_SEE_ALLY_PLAYER);
        setEnum(L, "I_SEE_ILLEGAL_PLAYER_BUILDING", EventTriggerEnum::EV_I_SEE_ILLEGAL_PLAYER_BUILDING);
        setEnum(L, "BURNING", EventTriggerEnum::EV_BURNING);
        setEnum(L, "LOST_LEG", EventTriggerEnum::EV_LOST_LEG);
        setEnum(L, "LOST_ARM", EventTriggerEnum::EV_LOST_ARM);
        setEnum(L, "I_SEE_PLAYER_NICE_BUILDING", EventTriggerEnum::EV_I_SEE_PLAYER_NICE_BUILDING);
        setEnum(L, "TAKEN_OVER_PLAYER_TOWN", EventTriggerEnum::EV_TAKEN_OVER_PLAYER_TOWN);
        setEnum(L, "CROWD_TRIGGERED", EventTriggerEnum::EV_CROWD_TRIGGERED);
        setEnum(L, "MAX", EventTriggerEnum::EV_MAX);
    // global
        lua_pushvalue(L, -1);
        lua_setglobal(L, "EventTriggerEnum");
        lua_setglobal(L, "EventTrigger");
    }

        void registerDialogConditionEnum(lua_State* L)
    {
        lua_newtable(L);

    // original
        setEnum(L, "DC_NONE", DialogConditionEnum::DC_NONE);
        setEnum(L, "DC_RELATIONS", DialogConditionEnum::DC_RELATIONS);
        setEnum(L, "DC_PLAYERMONEY", DialogConditionEnum::DC_PLAYERMONEY);
        setEnum(L, "DC_REPUTATION", DialogConditionEnum::DC_REPUTATION);
        setEnum(L, "DC_CARRYING_BOUNTY_ALIVE", DialogConditionEnum::DC_CARRYING_BOUNTY_ALIVE);
        setEnum(L, "DC_CARRYING_BOUNTY_DEAD", DialogConditionEnum::DC_CARRYING_BOUNTY_DEAD);
        setEnum(L, "DC_FACTION_VARIABLE", DialogConditionEnum::DC_FACTION_VARIABLE);
        setEnum(L, "DC_IMPRISONED_BY_TARGET", DialogConditionEnum::DC_IMPRISONED_BY_TARGET);
        setEnum(L, "DC_IMPRISONED_BY_OTHER", DialogConditionEnum::DC_IMPRISONED_BY_OTHER);
        setEnum(L, "DC_IS_A_TRADER", DialogConditionEnum::DC_IS_A_TRADER);
        setEnum(L, "DC_FACTION_RANK", DialogConditionEnum::DC_FACTION_RANK);
        setEnum(L, "DC_BUILDING_IS_CLOSED_AND_SECURED", DialogConditionEnum::DC_BUILDING_IS_CLOSED_AND_SECURED);
        setEnum(L, "DC_PLAYER_TECH_LEVEL", DialogConditionEnum::DC_PLAYER_TECH_LEVEL);
        setEnum(L, "DC_NUM_DIALOG_EVENT_REPEATS", DialogConditionEnum::DC_NUM_DIALOG_EVENT_REPEATS);
        setEnum(L, "DC_IS_IMPRISONED", DialogConditionEnum::DC_IS_IMPRISONED);
        setEnum(L, "DC_IMPRISONMENT_IS_DEATHROW", DialogConditionEnum::DC_IMPRISONMENT_IS_DEATHROW);
        setEnum(L, "DC_TARGET_IN_TALKING_RANGE", DialogConditionEnum::DC_TARGET_IN_TALKING_RANGE);
        setEnum(L, "DC_IN_MY_BUILDING", DialogConditionEnum::DC_IN_MY_BUILDING);
        setEnum(L, "DC_TARGET_LAST_SEEN_X_HOURS_AGO", DialogConditionEnum::DC_TARGET_LAST_SEEN_X_HOURS_AGO);
        setEnum(L, "DC_IS_LEADER", DialogConditionEnum::DC_IS_LEADER);
        setEnum(L, "DC_MET_TARGET_BEFORE", DialogConditionEnum::DC_MET_TARGET_BEFORE);
        setEnum(L, "DC_WEAKER_THAN_ME", DialogConditionEnum::DC_WEAKER_THAN_ME);
        setEnum(L, "DC_STRONGER_THAN_ME", DialogConditionEnum::DC_STRONGER_THAN_ME);
        setEnum(L, "DC_HAS_TAG", DialogConditionEnum::DC_HAS_TAG);
        setEnum(L, "DC_IS_ALLY", DialogConditionEnum::DC_IS_ALLY);
        setEnum(L, "DC_IS_ENEMY", DialogConditionEnum::DC_IS_ENEMY);
        setEnum(L, "DC_PERSONALITY_TAG", DialogConditionEnum::DC_PERSONALITY_TAG);
        setEnum(L, "DC_BROKEN_LEG", DialogConditionEnum::DC_BROKEN_LEG);
        setEnum(L, "DC_BROKEN_ARM", DialogConditionEnum::DC_BROKEN_ARM);
        setEnum(L, "DC_DAMAGED_HEAD", DialogConditionEnum::DC_DAMAGED_HEAD);
        setEnum(L, "DC_NEARLY_KO", DialogConditionEnum::DC_NEARLY_KO);
        setEnum(L, "DC_IN_A_NON_PLAYER_TOWN", DialogConditionEnum::DC_IN_A_NON_PLAYER_TOWN);
        setEnum(L, "DC_IS_RUNNING", DialogConditionEnum::DC_IS_RUNNING);
        setEnum(L, "DC_COPS_AROUND", DialogConditionEnum::DC_COPS_AROUND);
        setEnum(L, "DC_SQUAD_SIZE", DialogConditionEnum::DC_SQUAD_SIZE);
        setEnum(L, "DC_IS_PLAYER", DialogConditionEnum::DC_IS_PLAYER);
        setEnum(L, "DC_NUM_BACKPACKS", DialogConditionEnum::DC_NUM_BACKPACKS);
        setEnum(L, "DC_SQUAD_ONLY_ANIMALS", DialogConditionEnum::DC_SQUAD_ONLY_ANIMALS);
        setEnum(L, "DC_IS_OUTNUMBERED", DialogConditionEnum::DC_IS_OUTNUMBERED);
        setEnum(L, "DC_BOUNTY_AMOUNT_PERCEIVED", DialogConditionEnum::DC_BOUNTY_AMOUNT_PERCEIVED);
        setEnum(L, "DC_IS_KO", DialogConditionEnum::DC_IS_KO);
        setEnum(L, "DC_IS_NEARLY_KO", DialogConditionEnum::DC_IS_NEARLY_KO);
        setEnum(L, "DC_SQUAD_IS_DOWN", DialogConditionEnum::DC_SQUAD_IS_DOWN);
        setEnum(L, "DC_IS_DEAD", DialogConditionEnum::DC_IS_DEAD);
        setEnum(L, "DC_IS_FEMALE", DialogConditionEnum::DC_IS_FEMALE);
        setEnum(L, "DC_CARRYING_SOMEONE_TO_ENSLAVE", DialogConditionEnum::DC_CARRYING_SOMEONE_TO_ENSLAVE);
        setEnum(L, "DC_BOUNTY_AMOUNT_ACTUAL", DialogConditionEnum::DC_BOUNTY_AMOUNT_ACTUAL);
        setEnum(L, "DC_IM_UNARMED", DialogConditionEnum::DC_IM_UNARMED);
        setEnum(L, "DC_TOWN_HAS_FORTIFICATIONS_WALLS", DialogConditionEnum::DC_TOWN_HAS_FORTIFICATIONS_WALLS);
        setEnum(L, "DC_TARGET_IS_MY_MISSION_TARGET", DialogConditionEnum::DC_TARGET_IS_MY_MISSION_TARGET);
        setEnum(L, "DC_MY_MISSION_IS_FRIENDLY", DialogConditionEnum::DC_MY_MISSION_IS_FRIENDLY);
        setEnum(L, "DC_I_LOVE_THIS_GUY", DialogConditionEnum::DC_I_LOVE_THIS_GUY);
        setEnum(L, "DC_I_HATE_THIS_GUY", DialogConditionEnum::DC_I_HATE_THIS_GUY);
        setEnum(L, "DC_I_SHOULD_SCREW_THIS_GUY_OVER", DialogConditionEnum::DC_I_SHOULD_SCREW_THIS_GUY_OVER);
        setEnum(L, "DC_I_SHOULD_HELP_THIS_GUY", DialogConditionEnum::DC_I_SHOULD_HELP_THIS_GUY);
        setEnum(L, "DC_IN_COMBAT", DialogConditionEnum::DC_IN_COMBAT);
        setEnum(L, "DC_WITHIN_TOWN_WALLS", DialogConditionEnum::DC_WITHIN_TOWN_WALLS);
        setEnum(L, "DC_TOWN_WALLS_LOCKED_UP", DialogConditionEnum::DC_TOWN_WALLS_LOCKED_UP);
        setEnum(L, "DC_IS_SLAVE", DialogConditionEnum::DC_IS_SLAVE);
        setEnum(L, "DC_HAS_A_BASE_NEARBY", DialogConditionEnum::DC_HAS_A_BASE_NEARBY);
        setEnum(L, "DC_TARGET_IS_SLAVE_OF_MY_FACTION", DialogConditionEnum::DC_TARGET_IS_SLAVE_OF_MY_FACTION);
        setEnum(L, "DC_IS_ESCAPED_SLAVE", DialogConditionEnum::DC_IS_ESCAPED_SLAVE);
        setEnum(L, "DC_IS_IN_LOCKED_CAGE", DialogConditionEnum::DC_IS_IN_LOCKED_CAGE);
        setEnum(L, "DC_WEARING_LOCKED_SHACKLES", DialogConditionEnum::DC_WEARING_LOCKED_SHACKLES);
        setEnum(L, "DC_IS_SAME_RACE_AS_ME", DialogConditionEnum::DC_IS_SAME_RACE_AS_ME);
        setEnum(L, "DC_CAN_AFFORD_BOUNTY", DialogConditionEnum::DC_CAN_AFFORD_BOUNTY);
        setEnum(L, "DC_IS_SNEAKING", DialogConditionEnum::DC_IS_SNEAKING);
        setEnum(L, "DC_IS_INDOORS", DialogConditionEnum::DC_IS_INDOORS);
        setEnum(L, "DC_HAS_ILLEGAL_ITEM", DialogConditionEnum::DC_HAS_ILLEGAL_ITEM);
        setEnum(L, "DC_USING_MY_TRAINING_EQUIPMENT", DialogConditionEnum::DC_USING_MY_TRAINING_EQUIPMENT);
        setEnum(L, "DC_STARVING", DialogConditionEnum::DC_STARVING);
        setEnum(L, "DC_MIXED_GENDER_GROUP", DialogConditionEnum::DC_MIXED_GENDER_GROUP);
        setEnum(L, "DC_TOWN_LEVEL_CURRENT_LOCATION", DialogConditionEnum::DC_TOWN_LEVEL_CURRENT_LOCATION);
        setEnum(L, "DC_PLAYERS_BEST_TOWN_LEVEL", DialogConditionEnum::DC_PLAYERS_BEST_TOWN_LEVEL);
        setEnum(L, "DC_IN_A_PLAYER_TOWN", DialogConditionEnum::DC_IN_A_PLAYER_TOWN);
        setEnum(L, "DC_TARGET_CHARACTER_EXISTS", DialogConditionEnum::DC_TARGET_CHARACTER_EXISTS);
        setEnum(L, "DC_IS_RECRUITABLE", DialogConditionEnum::DC_IS_RECRUITABLE);
        setEnum(L, "DC_HAS_AI_CONTRACT", DialogConditionEnum::DC_HAS_AI_CONTRACT);
        setEnum(L, "DC_HAS_ROBOT_LIMBS", DialogConditionEnum::DC_HAS_ROBOT_LIMBS);
        setEnum(L, "DC_END", DialogConditionEnum::DC_END);
    // aliases
        setEnum(L, "NONE", DialogConditionEnum::DC_NONE);
        setEnum(L, "RELATIONS", DialogConditionEnum::DC_RELATIONS);
        setEnum(L, "PLAYERMONEY", DialogConditionEnum::DC_PLAYERMONEY);
        setEnum(L, "REPUTATION", DialogConditionEnum::DC_REPUTATION);
        setEnum(L, "CARRYING_BOUNTY_ALIVE", DialogConditionEnum::DC_CARRYING_BOUNTY_ALIVE);
        setEnum(L, "CARRYING_BOUNTY_DEAD", DialogConditionEnum::DC_CARRYING_BOUNTY_DEAD);
        setEnum(L, "FACTION_VARIABLE", DialogConditionEnum::DC_FACTION_VARIABLE);
        setEnum(L, "IMPRISONED_BY_TARGET", DialogConditionEnum::DC_IMPRISONED_BY_TARGET);
        setEnum(L, "IMPRISONED_BY_OTHER", DialogConditionEnum::DC_IMPRISONED_BY_OTHER);
        setEnum(L, "IS_A_TRADER", DialogConditionEnum::DC_IS_A_TRADER);
        setEnum(L, "FACTION_RANK", DialogConditionEnum::DC_FACTION_RANK);
        setEnum(L, "BUILDING_IS_CLOSED_AND_SECURED", DialogConditionEnum::DC_BUILDING_IS_CLOSED_AND_SECURED);
        setEnum(L, "PLAYER_TECH_LEVEL", DialogConditionEnum::DC_PLAYER_TECH_LEVEL);
        setEnum(L, "NUM_DIALOG_EVENT_REPEATS", DialogConditionEnum::DC_NUM_DIALOG_EVENT_REPEATS);
        setEnum(L, "IS_IMPRISONED", DialogConditionEnum::DC_IS_IMPRISONED);
        setEnum(L, "IMPRISONMENT_IS_DEATHROW", DialogConditionEnum::DC_IMPRISONMENT_IS_DEATHROW);
        setEnum(L, "TARGET_IN_TALKING_RANGE", DialogConditionEnum::DC_TARGET_IN_TALKING_RANGE);
        setEnum(L, "IN_MY_BUILDING", DialogConditionEnum::DC_IN_MY_BUILDING);
        setEnum(L, "TARGET_LAST_SEEN_X_HOURS_AGO", DialogConditionEnum::DC_TARGET_LAST_SEEN_X_HOURS_AGO);
        setEnum(L, "IS_LEADER", DialogConditionEnum::DC_IS_LEADER);
        setEnum(L, "MET_TARGET_BEFORE", DialogConditionEnum::DC_MET_TARGET_BEFORE);
        setEnum(L, "WEAKER_THAN_ME", DialogConditionEnum::DC_WEAKER_THAN_ME);
        setEnum(L, "STRONGER_THAN_ME", DialogConditionEnum::DC_STRONGER_THAN_ME);
        setEnum(L, "HAS_TAG", DialogConditionEnum::DC_HAS_TAG);
        setEnum(L, "IS_ALLY", DialogConditionEnum::DC_IS_ALLY);
        setEnum(L, "IS_ENEMY", DialogConditionEnum::DC_IS_ENEMY);
        setEnum(L, "PERSONALITY_TAG", DialogConditionEnum::DC_PERSONALITY_TAG);
        setEnum(L, "BROKEN_LEG", DialogConditionEnum::DC_BROKEN_LEG);
        setEnum(L, "BROKEN_ARM", DialogConditionEnum::DC_BROKEN_ARM);
        setEnum(L, "DAMAGED_HEAD", DialogConditionEnum::DC_DAMAGED_HEAD);
        setEnum(L, "NEARLY_KO", DialogConditionEnum::DC_NEARLY_KO);
        setEnum(L, "IN_A_NON_PLAYER_TOWN", DialogConditionEnum::DC_IN_A_NON_PLAYER_TOWN);
        setEnum(L, "IS_RUNNING", DialogConditionEnum::DC_IS_RUNNING);
        setEnum(L, "COPS_AROUND", DialogConditionEnum::DC_COPS_AROUND);
        setEnum(L, "SQUAD_SIZE", DialogConditionEnum::DC_SQUAD_SIZE);
        setEnum(L, "IS_PLAYER", DialogConditionEnum::DC_IS_PLAYER);
        setEnum(L, "NUM_BACKPACKS", DialogConditionEnum::DC_NUM_BACKPACKS);
        setEnum(L, "SQUAD_ONLY_ANIMALS", DialogConditionEnum::DC_SQUAD_ONLY_ANIMALS);
        setEnum(L, "IS_OUTNUMBERED", DialogConditionEnum::DC_IS_OUTNUMBERED);
        setEnum(L, "BOUNTY_AMOUNT_PERCEIVED", DialogConditionEnum::DC_BOUNTY_AMOUNT_PERCEIVED);
        setEnum(L, "IS_KO", DialogConditionEnum::DC_IS_KO);
        setEnum(L, "IS_NEARLY_KO", DialogConditionEnum::DC_IS_NEARLY_KO);
        setEnum(L, "SQUAD_IS_DOWN", DialogConditionEnum::DC_SQUAD_IS_DOWN);
        setEnum(L, "IS_DEAD", DialogConditionEnum::DC_IS_DEAD);
        setEnum(L, "IS_FEMALE", DialogConditionEnum::DC_IS_FEMALE);
        setEnum(L, "CARRYING_SOMEONE_TO_ENSLAVE", DialogConditionEnum::DC_CARRYING_SOMEONE_TO_ENSLAVE);
        setEnum(L, "BOUNTY_AMOUNT_ACTUAL", DialogConditionEnum::DC_BOUNTY_AMOUNT_ACTUAL);
        setEnum(L, "IM_UNARMED", DialogConditionEnum::DC_IM_UNARMED);
        setEnum(L, "TOWN_HAS_FORTIFICATIONS_WALLS", DialogConditionEnum::DC_TOWN_HAS_FORTIFICATIONS_WALLS);
        setEnum(L, "TARGET_IS_MY_MISSION_TARGET", DialogConditionEnum::DC_TARGET_IS_MY_MISSION_TARGET);
        setEnum(L, "MY_MISSION_IS_FRIENDLY", DialogConditionEnum::DC_MY_MISSION_IS_FRIENDLY);
        setEnum(L, "I_LOVE_THIS_GUY", DialogConditionEnum::DC_I_LOVE_THIS_GUY);
        setEnum(L, "I_HATE_THIS_GUY", DialogConditionEnum::DC_I_HATE_THIS_GUY);
        setEnum(L, "I_SHOULD_SCREW_THIS_GUY_OVER", DialogConditionEnum::DC_I_SHOULD_SCREW_THIS_GUY_OVER);
        setEnum(L, "I_SHOULD_HELP_THIS_GUY", DialogConditionEnum::DC_I_SHOULD_HELP_THIS_GUY);
        setEnum(L, "IN_COMBAT", DialogConditionEnum::DC_IN_COMBAT);
        setEnum(L, "WITHIN_TOWN_WALLS", DialogConditionEnum::DC_WITHIN_TOWN_WALLS);
        setEnum(L, "TOWN_WALLS_LOCKED_UP", DialogConditionEnum::DC_TOWN_WALLS_LOCKED_UP);
        setEnum(L, "IS_SLAVE", DialogConditionEnum::DC_IS_SLAVE);
        setEnum(L, "HAS_A_BASE_NEARBY", DialogConditionEnum::DC_HAS_A_BASE_NEARBY);
        setEnum(L, "TARGET_IS_SLAVE_OF_MY_FACTION", DialogConditionEnum::DC_TARGET_IS_SLAVE_OF_MY_FACTION);
        setEnum(L, "IS_ESCAPED_SLAVE", DialogConditionEnum::DC_IS_ESCAPED_SLAVE);
        setEnum(L, "IS_IN_LOCKED_CAGE", DialogConditionEnum::DC_IS_IN_LOCKED_CAGE);
        setEnum(L, "WEARING_LOCKED_SHACKLES", DialogConditionEnum::DC_WEARING_LOCKED_SHACKLES);
        setEnum(L, "IS_SAME_RACE_AS_ME", DialogConditionEnum::DC_IS_SAME_RACE_AS_ME);
        setEnum(L, "CAN_AFFORD_BOUNTY", DialogConditionEnum::DC_CAN_AFFORD_BOUNTY);
        setEnum(L, "IS_SNEAKING", DialogConditionEnum::DC_IS_SNEAKING);
        setEnum(L, "IS_INDOORS", DialogConditionEnum::DC_IS_INDOORS);
        setEnum(L, "HAS_ILLEGAL_ITEM", DialogConditionEnum::DC_HAS_ILLEGAL_ITEM);
        setEnum(L, "USING_MY_TRAINING_EQUIPMENT", DialogConditionEnum::DC_USING_MY_TRAINING_EQUIPMENT);
        setEnum(L, "STARVING", DialogConditionEnum::DC_STARVING);
        setEnum(L, "MIXED_GENDER_GROUP", DialogConditionEnum::DC_MIXED_GENDER_GROUP);
        setEnum(L, "TOWN_LEVEL_CURRENT_LOCATION", DialogConditionEnum::DC_TOWN_LEVEL_CURRENT_LOCATION);
        setEnum(L, "PLAYERS_BEST_TOWN_LEVEL", DialogConditionEnum::DC_PLAYERS_BEST_TOWN_LEVEL);
        setEnum(L, "IN_A_PLAYER_TOWN", DialogConditionEnum::DC_IN_A_PLAYER_TOWN);
        setEnum(L, "TARGET_CHARACTER_EXISTS", DialogConditionEnum::DC_TARGET_CHARACTER_EXISTS);
        setEnum(L, "IS_RECRUITABLE", DialogConditionEnum::DC_IS_RECRUITABLE);
        setEnum(L, "HAS_AI_CONTRACT", DialogConditionEnum::DC_HAS_AI_CONTRACT);
        setEnum(L, "HAS_ROBOT_LIMBS", DialogConditionEnum::DC_HAS_ROBOT_LIMBS);
        setEnum(L, "END", DialogConditionEnum::DC_END);
    // global
        lua_pushvalue(L, -1);
        lua_setglobal(L, "DialogConditionEnum");
        lua_setglobal(L, "DialogCondition");
    }

    void registerComparisonEnum(lua_State* L)
    {
        lua_newtable(L);
    // original c++
        setEnum(L, "CE_EQUALS", ComparisonEnum::CE_EQUALS);
        setEnum(L, "CE_LESS_THAN", ComparisonEnum::CE_LESS_THAN);
        setEnum(L, "CE_MORE_THAN", ComparisonEnum::CE_MORE_THAN);
    // aliases
        setEnum(L, "EQUALS", ComparisonEnum::CE_EQUALS);
        setEnum(L, "LESS_THAN", ComparisonEnum::CE_LESS_THAN);
        setEnum(L, "MORE_THAN", ComparisonEnum::CE_MORE_THAN);
    // global
        lua_pushvalue(L, -1);
        lua_setglobal(L, "ComparisonEnum");
        lua_setglobal(L, "Comparison");
    }

    void registerGroundType(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "GROUND_SAND", GroundType::GROUND_SAND);
        setEnum(L, "GROUND_GRASS", GroundType::GROUND_GRASS);
        setEnum(L, "GROUND_CONCRETE", GroundType::GROUND_CONCRETE);
        setEnum(L, "GROUND_WOOD", GroundType::GROUND_WOOD);
        setEnum(L, "GROUND_METAL", GroundType::GROUND_METAL);
        setEnum(L, "GROUND_WATER", GroundType::GROUND_WATER);
        setEnum(L, "GROUND_MUD", GroundType::GROUND_MUD);
        setEnum(L, "GROUND_SNOW", GroundType::GROUND_SNOW);
        setEnum(L, "GROUND_DIRT", GroundType::GROUND_DIRT);
    // aliases
        setEnum(L, "SAND", GroundType::GROUND_SAND);
        setEnum(L, "GRASS", GroundType::GROUND_GRASS);
        setEnum(L, "CONCRETE", GroundType::GROUND_CONCRETE);
        setEnum(L, "WOOD", GroundType::GROUND_WOOD);
        setEnum(L, "METAL", GroundType::GROUND_METAL);
        setEnum(L, "WATER", GroundType::GROUND_WATER);
        setEnum(L, "MUD", GroundType::GROUND_MUD);
        setEnum(L, "SNOW", GroundType::GROUND_SNOW);
        setEnum(L, "DIRT", GroundType::GROUND_DIRT);
    // global
        lua_setglobal(L, "GroundType");
    }

    void registerEffectType(lua_State* L)
    {
        lua_createtable(L, 0, 11);

        setEnum(L, "NONE", EffectType::Enum::NONE);
        setEnum(L, "CAMERA", EffectType::Enum::CAMERA);
        setEnum(L, "POINT", EffectType::Enum::POINT);
        setEnum(L, "WANDERING", EffectType::Enum::WANDERING);
        setEnum(L, "GLOBAL", EffectType::Enum::GLOBAL);
        setEnum(L, "CAMERA_RAIN", EffectType::Enum::CAMERA_RAIN);
        setEnum(L, "CAMERA_ACID_RAIN", EffectType::Enum::CAMERA_ACID_RAIN);
        setEnum(L, "POINT_LIGHTING", EffectType::Enum::POINT_LIGHTING);
        setEnum(L, "WANDERING_STORM", EffectType::Enum::WANDERING_STORM);
        setEnum(L, "WANDERING_GAS", EffectType::Enum::WANDERING_GAS);
        setEnum(L, "GLOBAL_POINT", EffectType::Enum::GLOBAL_POINT);

        lua_setglobal(L, "EffectType");
    }

    void registerSquadType(lua_State* L)
    {
        lua_createtable(L, 0, 3);
    // original
        setEnum(L, "SQ_UNKNOWN", SquadType::SQ_UNKNOWN);
        setEnum(L, "SQ_RESIDENT", SquadType::SQ_RESIDENT);
        setEnum(L, "SQ_ROAMING", SquadType::SQ_ROAMING);
    // aliases
        setEnum(L, "UNKNOWN", SquadType::SQ_UNKNOWN);
        setEnum(L, "RESIDENT", SquadType::SQ_RESIDENT);
        setEnum(L, "ROAMING", SquadType::SQ_ROAMING);
    // global
        lua_setglobal(L, "SquadType");
    }

    void registerMoveSpeed(lua_State* L)
    {
        lua_createtable(L, 0, 5);

        setEnum(L, "WALK", MoveSpeed::WALK);
        setEnum(L, "JOG", MoveSpeed::JOG);
        setEnum(L, "RUN", MoveSpeed::RUN);
        setEnum(L, "GROUPED", MoveSpeed::GROUPED);
        setEnum(L, "NO_SPEED_CHANGE", MoveSpeed::NO_SPEED_CHANGE);

        lua_setglobal(L, "MoveSpeed");
    }

    void registerSwordStateEnum(lua_State* L)
    {
        lua_createtable(L, 0, 12);

        setEnum(L, "CHOP_WEAPON", swordStateEnum::CHOP_WEAPON);
        setEnum(L, "BLOCK", swordStateEnum::BLOCK);
        setEnum(L, "REACTION_BLOCK", swordStateEnum::REACTION_BLOCK);
        setEnum(L, "STARTUP_STATE", swordStateEnum::STARTUP_STATE);
        setEnum(L, "DECISION", swordStateEnum::DECISION);
        setEnum(L, "CIRCLE_MENACINGLY", swordStateEnum::CIRCLE_MENACINGLY);
        setEnum(L, "WAIT_MENACINGLY", swordStateEnum::WAIT_MENACINGLY);
        setEnum(L, "HESITATE", swordStateEnum::HESITATE);
        setEnum(L, "STUMBLE", swordStateEnum::STUMBLE);
        setEnum(L, "COMBAT_FINISHED", swordStateEnum::COMBAT_FINISHED);
        setEnum(L, "TARGET_PATHFINDING_STARTUP", swordStateEnum::TARGET_PATHFINDING_STARTUP);
        setEnum(L, "TARGET_PATHFINDING", swordStateEnum::TARGET_PATHFINDING);

        lua_pushvalue(L, -1);
        lua_setglobal(L, "swordStateEnum");
        lua_setglobal(L, "SwordState");
    }

    void registerMiningResource(lua_State* L)
    {
        lua_createtable(L, 0, 7);

        setEnum(L, "NONE", MiningResource::NONE);
        setEnum(L, "IRON", MiningResource::IRON);
        setEnum(L, "STONE", MiningResource::STONE);
        setEnum(L, "COPPER", MiningResource::COPPER);
        setEnum(L, "CARBON", MiningResource::CARBON);
        setEnum(L, "WATER", MiningResource::WATER);
        setEnum(L, "GROUND", MiningResource::GROUND);

        lua_setglobal(L, "MiningResource");
    }

    void registerCursorType(lua_State* L)
    {
        lua_createtable(L, 0, 16);
    // original
        setEnum(L, "DEFAULT_CURSOR", CursorType::DEFAULT_CURSOR);
        setEnum(L, "MEDIC_CURSOR", CursorType::MEDIC_CURSOR);
        setEnum(L, "LOOT_CURSOR", CursorType::LOOT_CURSOR);
        setEnum(L, "LIFT_CURSOR", CursorType::LIFT_CURSOR);
        setEnum(L, "PICKUP_ITEM_CURSOR", CursorType::PICKUP_ITEM_CURSOR);
        setEnum(L, "ATTACK_CURSOR", CursorType::ATTACK_CURSOR);
        setEnum(L, "GUARD_CURSOR", CursorType::GUARD_CURSOR);
        setEnum(L, "TALK_CURSOR", CursorType::TALK_CURSOR);
        setEnum(L, "SPECIAL_TALK_CURSOR", CursorType::SPECIAL_TALK_CURSOR);
        setEnum(L, "USE_CURSOR", CursorType::USE_CURSOR);
        setEnum(L, "TRADER_CURSOR", CursorType::TRADER_CURSOR);
        setEnum(L, "BUILD_CURSOR", CursorType::BUILD_CURSOR);
        setEnum(L, "OPEN_DOOR_CURSOR", CursorType::OPEN_DOOR_CURSOR);
        setEnum(L, "DOOR_ESCAPE_CURSOR", CursorType::DOOR_ESCAPE_CURSOR);
        setEnum(L, "LOCKED_CURSOR", CursorType::LOCKED_CURSOR);
        setEnum(L, "PICK_LOCK_CURSOR", CursorType::PICK_LOCK_CURSOR);
        setEnum(L, "BUY_HOUSE_CURSOR", CursorType::BUY_HOUSE_CURSOR);
        setEnum(L, "GREEN_CURSOR", CursorType::GREEN_CURSOR);
        setEnum(L, "MINE_CURSOR", CursorType::MINE_CURSOR);
        setEnum(L, "REPAIR_CURSOR", CursorType::REPAIR_CURSOR);
        setEnum(L, "LIGHT_CURSOR", CursorType::LIGHT_CURSOR);
        setEnum(L, "STEAL_CURSOR", CursorType::STEAL_CURSOR);
        setEnum(L, "HAND_CURSOR", CursorType::HAND_CURSOR);
        setEnum(L, "INVALID_MOVEMENT_CURSOR", CursorType::INVALID_MOVEMENT_CURSOR);
        setEnum(L, "LOOT_CURSOR_RED", CursorType::LOOT_CURSOR_RED);
        setEnum(L, "KNOCKOUT_CURSOR", CursorType::KNOCKOUT_CURSOR);
    // aliases
        setEnum(L, "DEFAULT", CursorType::DEFAULT_CURSOR);
        setEnum(L, "MEDIC", CursorType::MEDIC_CURSOR);
        setEnum(L, "LOOT", CursorType::LOOT_CURSOR);
        setEnum(L, "LIFT", CursorType::LIFT_CURSOR);
        setEnum(L, "PICKUP_ITEM", CursorType::PICKUP_ITEM_CURSOR);
        setEnum(L, "ATTACK", CursorType::ATTACK_CURSOR);
        setEnum(L, "GUARD", CursorType::GUARD_CURSOR);
        setEnum(L, "TALK", CursorType::TALK_CURSOR);
        setEnum(L, "SPECIAL_TALK", CursorType::SPECIAL_TALK_CURSOR);
        setEnum(L, "USE", CursorType::USE_CURSOR);
        setEnum(L, "TRADER", CursorType::TRADER_CURSOR);
        setEnum(L, "BUILD", CursorType::BUILD_CURSOR);
        setEnum(L, "OPEN_DOOR", CursorType::OPEN_DOOR_CURSOR);
        setEnum(L, "DOOR_ESCAPE", CursorType::DOOR_ESCAPE_CURSOR);
        setEnum(L, "LOCKED", CursorType::LOCKED_CURSOR);
        setEnum(L, "PICK_LOCK", CursorType::PICK_LOCK_CURSOR);
        setEnum(L, "BUY_HOUSE", CursorType::BUY_HOUSE_CURSOR);
        setEnum(L, "GREEN", CursorType::GREEN_CURSOR);
        setEnum(L, "MINE", CursorType::MINE_CURSOR);
        setEnum(L, "REPAIR", CursorType::REPAIR_CURSOR);
        setEnum(L, "LIGHT", CursorType::LIGHT_CURSOR);
        setEnum(L, "STEAL", CursorType::STEAL_CURSOR);
        setEnum(L, "HAND", CursorType::HAND_CURSOR);
        setEnum(L, "INVALID_MOVEMENT", CursorType::INVALID_MOVEMENT_CURSOR);
        setEnum(L, "LOOT_RED", CursorType::LOOT_CURSOR_RED);
        setEnum(L, "KNOCKOUT", CursorType::KNOCKOUT_CURSOR);
    // global
        lua_setglobal(L, "CursorType");
    }

    void registerMapZoomLevel(lua_State* L)
    {
        lua_createtable(L, 0, 8);
    //original c++ enums
        setEnum(L, "ZOOM_MIN", MapZoomLevel::ZOOM_MIN);
        setEnum(L, "ZOOM_MID", MapZoomLevel::ZOOM_MID);
        setEnum(L, "ZOOM_MAX", MapZoomLevel::ZOOM_MAX);
        setEnum(L, "ZOOM_CHARACTERS", MapZoomLevel::ZOOM_CHARACTERS);
    //aliases
        setEnum(L, "MIN", MapZoomLevel::ZOOM_MIN);
        setEnum(L, "MID", MapZoomLevel::ZOOM_MID);
        setEnum(L, "MAX", MapZoomLevel::ZOOM_MAX);
        setEnum(L, "CHARACTERS", MapZoomLevel::ZOOM_CHARACTERS);
    //set the global variable
        lua_setglobal(L, "MapZoomLevel");
    }

    // ------------------------------------------
    // FactionRelations.h
    // ------------------------------------------

    void registerFactionEvent(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "ATTACKED_US_DEFENSIVELY", FactionRelations::ATTACKED_US_DEFENSIVELY);
        setEnum(L, "ATTACKED_US_AGGRESSIVELY", FactionRelations::ATTACKED_US_AGGRESSIVELY);
        setEnum(L, "DEFEATED_ONE_OF_US_DEFENSIVELY", FactionRelations::DEFEATED_ONE_OF_US_DEFENSIVELY);
        setEnum(L, "DEFEATED_ONE_OF_US_AGGRESSIVELY", FactionRelations::DEFEATED_ONE_OF_US_AGGRESSIVELY);
        setEnum(L, "KILLED_ONE_OF_US_DIRECTLY", FactionRelations::KILLED_ONE_OF_US_DIRECTLY);
        setEnum(L, "KILLED_ONE_OF_US_INDIRECTLY", FactionRelations::KILLED_ONE_OF_US_INDIRECTLY);
        setEnum(L, "EXECUTED_ONE_OF_US", FactionRelations::EXECUTED_ONE_OF_US);
        setEnum(L, "AIDED_US_IN_BATTLE", FactionRelations::AIDED_US_IN_BATTLE);
        setEnum(L, "FIRST_AIDED_US", FactionRelations::FIRST_AIDED_US);
        setEnum(L, "TAKEN_TO_BED", FactionRelations::TAKEN_TO_BED);
        setEnum(L, "DEFEATED_AN_ENEMY", FactionRelations::DEFEATED_AN_ENEMY);
        setEnum(L, "KILLED_AN_ENEMY", FactionRelations::KILLED_AN_ENEMY);
        setEnum(L, "CAPTURED_US", FactionRelations::CAPTURED_US);

        lua_setglobal(L, "FactionEvent");
    }

    // ------------------------------------------
    // FactionWarMgr.h
    // ------------------------------------------

    void registerUnloadedPlatoonJob(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "UPJOB_NONE", UPJOB_NONE);
        setEnum(L, "UPJOB_PATROL_TOWN", UPJOB_PATROL_TOWN);
        setEnum(L, "UPJOB_PATROL_SHORTRANGE", UPJOB_PATROL_SHORTRANGE);
        setEnum(L, "UPJOB_PATROL_LONGRANGE", UPJOB_PATROL_LONGRANGE);
        setEnum(L, "UPJOB_GOHOME", UPJOB_GOHOME);
        setEnum(L, "UPJOB_TRAVEL_TARGET", UPJOB_TRAVEL_TARGET);
        setEnum(L, "UPJOB_TRAVEL_TARGET_FAST", UPJOB_TRAVEL_TARGET_FAST);

        setEnum(L, "NONE", UPJOB_NONE);
        setEnum(L, "PATROL_TOWN", UPJOB_PATROL_TOWN);
        setEnum(L, "PATROL_SHORTRANGE", UPJOB_PATROL_SHORTRANGE);
        setEnum(L, "PATROL_LONGRANGE", UPJOB_PATROL_LONGRANGE);
        setEnum(L, "GOHOME", UPJOB_GOHOME);
        setEnum(L, "TRAVEL_TARGET", UPJOB_TRAVEL_TARGET);
        setEnum(L, "TRAVEL_TARGET_FAST", UPJOB_TRAVEL_TARGET_FAST);

        lua_setglobal(L, "UnloadedPlatoonJob");
    }

    // ------------------------------------------
    // ForgottenGUI.h
    // ------------------------------------------

    void registerForgottenGUITradeWindowType(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "TW_OFF", TradeWindowType::TW_OFF);
        setEnum(L, "TW_MONEY_TRADING", TradeWindowType::TW_MONEY_TRADING);
        setEnum(L, "TW_LOOTING", TradeWindowType::TW_LOOTING);
        setEnum(L, "TW_AUTO", TradeWindowType::TW_AUTO);
    // aliases
        setEnum(L, "OFF", TradeWindowType::TW_OFF);
        setEnum(L, "MONEY_TRADING", TradeWindowType::TW_MONEY_TRADING);
        setEnum(L, "LOOTING", TradeWindowType::TW_LOOTING);
        setEnum(L, "AUTO", TradeWindowType::TW_AUTO);
    // global
        lua_setglobal(L, "TradeWindowType");
    }

    // ------------------------------------------
    // GameData.h
    // ------------------------------------------

    void registerGameDataDataType(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "NONE", GameData::NONE);
        setEnum(L, "INT", GameData::INT);
        setEnum(L, "FLOAT", GameData::FLOAT);
        setEnum(L, "BOOL", GameData::BOOL);
        setEnum(L, "FILE", GameData::FILE);
        setEnum(L, "STRING", GameData::STRING);

        lua_setglobal(L, "GameDataDataType");
    }

    // ------------------------------------------
    // GameWorld.h
    // ------------------------------------------

    void registerNxShapesType(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "NX_STATIC_SHAPES", NX_STATIC_SHAPES);
        setEnum(L, "NX_DYNAMIC_SHAPES", NX_DYNAMIC_SHAPES);
        setEnum(L, "NX_ALL_SHAPES", NX_ALL_SHAPES);

        setEnum(L, "STATIC_SHAPES", NX_STATIC_SHAPES);
        setEnum(L, "DYNAMIC_SHAPES", NX_DYNAMIC_SHAPES);
        setEnum(L, "ALL_SHAPES", NX_ALL_SHAPES);

        lua_setglobal(L, "NxShapesType");
    }

    void registerSysMessageEnum(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "SYS_NONE", GameWorld::SYS_NONE);
        setEnum(L, "SYS_RESIDENT_CHANGE", GameWorld::SYS_RESIDENT_CHANGE);
        setEnum(L, "SYS_SHOW_PROSPECTING_WINDOW", GameWorld::SYS_SHOW_PROSPECTING_WINDOW);
        setEnum(L, "SYS_CREATE_PHYSICAL", GameWorld::SYS_CREATE_PHYSICAL);
        setEnum(L, "SYS_DESTROY_PHYSICAL", GameWorld::SYS_DESTROY_PHYSICAL);
        setEnum(L, "SYS_SET_CHAINED_MODE", GameWorld::SYS_SET_CHAINED_MODE);
        setEnum(L, "SYS_UPDATE_ORDERS_PANEL", GameWorld::SYS_UPDATE_ORDERS_PANEL);
        setEnum(L, "SYS_UPDATE_PORTRAIT", GameWorld::SYS_UPDATE_PORTRAIT);
        setEnum(L, "SYS_RESEARCH_PROGRESS", GameWorld::SYS_RESEARCH_PROGRESS);
        setEnum(L, "SYS_CLOSE_ALL_INVENTORIES", GameWorld::SYS_CLOSE_ALL_INVENTORIES);
        setEnum(L, "SYS_CLOSE_INVENTORY", GameWorld::SYS_CLOSE_INVENTORY);
        setEnum(L, "SYS_BUILDING_PROGRESS", GameWorld::SYS_BUILDING_PROGRESS);
        setEnum(L, "SYS_DROP_ALL_GEAR", GameWorld::SYS_DROP_ALL_GEAR);
        setEnum(L, "SYS_CHARACTER_PARTICLES", GameWorld::SYS_CHARACTER_PARTICLES);
        setEnum(L, "SYS_RESTORE_SQUAD", GameWorld::SYS_RESTORE_SQUAD);
        setEnum(L, "SYS_DESTROY_PLATOON", GameWorld::SYS_DESTROY_PLATOON);
        setEnum(L, "SYS_BREAK_BUILDING", GameWorld::SYS_BREAK_BUILDING);

        lua_setglobal(L, "SysMessageEnum");
    }

    // ------------------------------------------
    // gui/InventoryGUI.h
    // ------------------------------------------

    void registerInventoryGUITradeResult(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "OK", InventoryGUI::TradeResult::OK);
        setEnum(L, "OUT_OF_RANGE", InventoryGUI::TradeResult::OUT_OF_RANGE);
        setEnum(L, "NO_ROOM", InventoryGUI::TradeResult::NO_ROOM);
        setEnum(L, "CANT_AFFORD", InventoryGUI::TradeResult::CANT_AFFORD);
        setEnum(L, "CANT_AFFORD_SHOPKEPPER", InventoryGUI::TradeResult::CANT_AFFORD_SHOPKEPPER);
        setEnum(L, "CANT_WEAR_ITEM", InventoryGUI::TradeResult::CANT_WEAR_ITEM);
        setEnum(L, "INCOMPATIBLE_ITEM", InventoryGUI::TradeResult::INCOMPATIBLE_ITEM);
        setEnum(L, "LOCKED", InventoryGUI::TradeResult::LOCKED);
        setEnum(L, "THIEF_DETECTED", InventoryGUI::TradeResult::THIEF_DETECTED);
        setEnum(L, "SELLING_STOLEN_ITEM_DETECTED", InventoryGUI::TradeResult::SELLING_STOLEN_ITEM_DETECTED);
        setEnum(L, "ERROR_ITEM_POSITION", InventoryGUI::TradeResult::ERROR_ITEM_POSITION);
        setEnum(L, "ERROR_INVALID", InventoryGUI::TradeResult::ERROR_INVALID);
        setEnum(L, "ERROR_THATS_MINE", InventoryGUI::TradeResult::ERROR_THATS_MINE);
        setEnum(L, "ERROR_TARGET_CONSCIOUS", InventoryGUI::TradeResult::ERROR_TARGET_CONSCIOUS);
        setEnum(L, "SMUGGLING_ONLY", InventoryGUI::TradeResult::SMUGGLING_ONLY);
        setEnum(L, "ILLEGAL_GOODS", InventoryGUI::TradeResult::ILLEGAL_GOODS);
        setEnum(L, "UNIFORMS", InventoryGUI::TradeResult::UNIFORMS);
        setEnum(L, "CONTAINER_NOT_EMPTY", InventoryGUI::TradeResult::CONTAINER_NOT_EMPTY);

        lua_pushvalue(L, -1);
        lua_setglobal(L, "InventoryGUITradeResult");
        lua_setglobal(L, "TradeResult");
    }

    // ------------------------------------------
    // HavokCharacter.h
    // ------------------------------------------

    void registerHavokCharacterState(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "IDLE", HavokCharacter::IDLE);
        setEnum(L, "GOAL_REACHED", HavokCharacter::GOAL_REACHED);
        setEnum(L, "FOLLOWING_PATH", HavokCharacter::FOLLOWING_PATH);
        setEnum(L, "MANUAL", HavokCharacter::MANUAL);

        lua_setglobal(L, "HavokCharacterState");
    }

    void registerHavokPathState(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "NONE", HavokCharacter::NONE);
        setEnum(L, "COMPLETE", HavokCharacter::COMPLETE);
        setEnum(L, "INCOMPLETE", HavokCharacter::INCOMPLETE);
        setEnum(L, "FAILED", HavokCharacter::FAILED);
        setEnum(L, "WAITING", HavokCharacter::WAITING);
        setEnum(L, "UPDATING", HavokCharacter::UPDATING);
        setEnum(L, "BROKEN", HavokCharacter::BROKEN);

        lua_setglobal(L, "HavokPathState");
    }

    // ------------------------------------------
    // InputHandler.h
    // ------------------------------------------

    void registerMasks(lua_State* L)
    {
        lua_createtable(L, 0, 10);

    // original
        setEnum(L, "SHIFT_MASK", InputHandler::SHIFT_MASK);
        setEnum(L, "CTRL_MASK", InputHandler::CTRL_MASK);
        setEnum(L, "ALT_MASK", InputHandler::ALT_MASK);
        setEnum(L, "ALL_MASK", InputHandler::ALL_MASK);
        setEnum(L, "NONE_MASK", InputHandler::NONE_MASK);
    // aliases
        setEnum(L, "SHIFT", InputHandler::SHIFT_MASK);
        setEnum(L, "CTRL", InputHandler::CTRL_MASK);
        setEnum(L, "ALT", InputHandler::ALT_MASK);
        setEnum(L, "ALL", InputHandler::ALL_MASK);
        setEnum(L, "NONE", InputHandler::NONE_MASK);
    // global
        lua_setglobal(L, "Masks");
    }

    void registerGlobalMode(lua_State* L)
    {
        lua_createtable(L, 0, 2);

        setEnum(L, "GLOBAL", InputHandler::GLOBAL);
        setEnum(L, "EDITOR", InputHandler::EDITOR);

        lua_setglobal(L, "GlobalMode");
    }

    void registerInputHandlerGameMode(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "GLOBAL", InputHandler::GLOBAL);
        setEnum(L, "EDITOR", InputHandler::EDITOR);

        lua_setglobal(L, "InputHandlerGameMode");
    }

    // ------------------------------------------
    // Logger.h
    // ------------------------------------------

    void registerLoggerSeverity(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "LOG_INFO", Logger::Info);
        setEnum(L, "LOG_WARNING", Logger::Warning);
        setEnum(L, "LOG_ERROR", Logger::Error);

        setEnum(L, "TRACE", Logger::Trace);
        setEnum(L, "DEBUG", Logger::Debug);
        setEnum(L, "INFO", Logger::Info);
        setEnum(L, "WARNING", Logger::Warning);
        setEnum(L, "ERROR", Logger::Error);
        setEnum(L, "FATAL", Logger::Fatal);

        lua_setglobal(L, "LoggerSeverity");
    }

    // ------------------------------------------
    // ManagementScreen.h
    // ------------------------------------------

    void registerManagementScreenMessageLogColor(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "ML_NORMAL", MessageLogColor::ML_NORMAL);
        setEnum(L, "ML_PLAYER", MessageLogColor::ML_PLAYER);
        setEnum(L, "ML_SYSTEM", MessageLogColor::ML_SYSTEM);
    // aliases
        setEnum(L, "NORMAL", MessageLogColor::ML_NORMAL);
        setEnum(L, "PLAYER", MessageLogColor::ML_PLAYER);
        setEnum(L, "SYSTEM", MessageLogColor::ML_SYSTEM);
    // global
        lua_setglobal(L, "MessageLogColor");
    }

    // ------------------------------------------
    // MedicalSystem.h
    // ------------------------------------------

    void registerLimbState(lua_State* L)
    {
        lua_createtable(L, 0, 8);
    // original c++
        setEnum(L, "LIMB_ORIGINAL", LimbState::LIMB_ORIGINAL);
        setEnum(L, "LIMB_STUMP", LimbState::LIMB_STUMP);
        setEnum(L, "LIMB_REPLACED", LimbState::LIMB_REPLACED);
        setEnum(L, "LIMB_CRUSHED", LimbState::LIMB_CRUSHED);
    // aliases
        setEnum(L, "ORIGINAL", LimbState::LIMB_ORIGINAL);
        setEnum(L, "STUMP", LimbState::LIMB_STUMP);
        setEnum(L, "REPLACED", LimbState::LIMB_REPLACED);
        setEnum(L, "CRUSHED", LimbState::LIMB_CRUSHED);

        lua_setglobal(L, "LimbState");
    }

    void registerRobotLimbs(lua_State* L)
    {
        lua_createtable(L, 0, 5);

        setEnum(L, "LEFT_ARM", RobotLimbs::Limb::LEFT_ARM);
        setEnum(L, "RIGHT_ARM", RobotLimbs::Limb::RIGHT_ARM);
        setEnum(L, "LEFT_LEG", RobotLimbs::Limb::LEFT_LEG);
        setEnum(L, "RIGHT_LEG", RobotLimbs::Limb::RIGHT_LEG);
        setEnum(L, "NULL_LIMB", RobotLimbs::Limb::NULL_LIMB);

        lua_setglobal(L, "RobotLimbs");
    }

    void registerAttackDirection(lua_State* L)
    {
        lua_createtable(L, 0, 6);

        setEnum(L, "FRONT", AttackDirection::Enum::FRONT);
        setEnum(L, "BACK", AttackDirection::Enum::BACK);
        setEnum(L, "LEFT", AttackDirection::Enum::LEFT);
        setEnum(L, "RIGHT", AttackDirection::Enum::RIGHT);
        setEnum(L, "TOP", AttackDirection::Enum::TOP);
        setEnum(L, "BOTTOM", AttackDirection::Enum::BOTTOM);

        lua_setglobal(L, "AttackDirection");
    }

    void registerHealthPartStatus(lua_State* L)
    {
        lua_createtable(L, 0, 8);
    // original c++ enums
        setEnum(L, "PART_TORSO", MedicalSystem::HealthPartStatus::PART_TORSO);
        setEnum(L, "PART_LEG", MedicalSystem::HealthPartStatus::PartType::PART_LEG);
        setEnum(L, "PART_ARM", MedicalSystem::HealthPartStatus::PartType::PART_ARM);
        setEnum(L, "PART_HEAD", MedicalSystem::HealthPartStatus::PartType::PART_HEAD);
    // aliases
        setEnum(L, "TORSO", MedicalSystem::HealthPartStatus::PART_TORSO);
        setEnum(L, "LEG", MedicalSystem::HealthPartStatus::PartType::PART_LEG);
        setEnum(L, "ARM", MedicalSystem::HealthPartStatus::PartType::PART_ARM);
        setEnum(L, "HEAD", MedicalSystem::HealthPartStatus::PartType::PART_HEAD);
    // set the global variable
        lua_setglobal(L, "HealthPartStatus");
    }

    void registerCollapseStage(lua_State* L)
    {
        lua_createtable(L, 0, 6);
    // original c++ enums
        setEnum(L, "COLLAPSE_NONE", MedicalSystem::CollapseStage::COLLAPSE_NONE);
        setEnum(L, "COLLAPSE_BUT_NO_RAGDOLL", MedicalSystem::CollapseStage::COLLAPSE_BUT_NO_RAGDOLL);
        setEnum(L, "COLLAPSE_KO", MedicalSystem::CollapseStage::COLLAPSE_KO);
    // aliases
        setEnum(L, "NONE", MedicalSystem::CollapseStage::COLLAPSE_NONE);
        setEnum(L, "BUT_NO_RAGDOLL", MedicalSystem::CollapseStage::COLLAPSE_BUT_NO_RAGDOLL);
        setEnum(L, "KO", MedicalSystem::CollapseStage::COLLAPSE_KO);
    //set the global variable
        lua_setglobal(L, "CollapseStage");
    }

    // ------------------------------------------
    // NavMesh.h
    // ------------------------------------------

    void registerNavMeshState(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "MISSING", NavMesh::MISSING);
        setEnum(L, "ORIGINAL", NavMesh::ORIGINAL);
        setEnum(L, "MODIFIED", NavMesh::MODIFIED);
        setEnum(L, "LOADING", NavMesh::LOADING);
        setEnum(L, "GENERATING", NavMesh::GENERATING);

        lua_setglobal(L, "NavMeshState");
    }

    void registerNavMeshFileMode(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "AUTO", NavMesh::AUTO);
        setEnum(L, "BASE", NavMesh::BASE);
        setEnum(L, "USER", NavMesh::USER);

        lua_setglobal(L, "NavMeshFileMode");
    }

    // ------------------------------------------
    // PhysicsActual.h
    // ------------------------------------------

    void registerNxShapeFlag(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "NX_TRIGGER_ON_ENTER", NX_TRIGGER_ON_ENTER);
        setEnum(L, "NX_TRIGGER_ON_LEAVE", NX_TRIGGER_ON_LEAVE);
        setEnum(L, "NX_TRIGGER_ON_STAY", NX_TRIGGER_ON_STAY);
        setEnum(L, "NX_TRIGGER_ENABLE", NX_TRIGGER_ENABLE);
        setEnum(L, "NX_SF_VISUALIZATION", NX_SF_VISUALIZATION);
        setEnum(L, "NX_SF_DISABLE_COLLISION", NX_SF_DISABLE_COLLISION);
        setEnum(L, "NX_SF_FEATURE_INDICES", NX_SF_FEATURE_INDICES);
        setEnum(L, "NX_SF_DISABLE_RAYCASTING", NX_SF_DISABLE_RAYCASTING);

        lua_setglobal(L, "NxShapeFlag");
    }

    void registerNXU_FileType(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "FT_BINARY", NXU::FT_BINARY);
        setEnum(L, "FT_XML", NXU::FT_XML);
        setEnum(L, "FT_COLLADA", NXU::FT_COLLADA);

        lua_setglobal(L, "NXU_FileType");
    }

    // ------------------------------------------
    // PhysicsCollection.h
    // ------------------------------------------

    void registerBuildingRotation(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "ROTATION_NONE", ROTATION_NONE);
        setEnum(L, "ROTATION_CONSTANT", ROTATION_CONSTANT);
        setEnum(L, "ROTATION_OUTPUT_BASED", ROTATION_OUTPUT_BASED);
        setEnum(L, "ROTATION_WIND_SPEED", ROTATION_WIND_SPEED);
        setEnum(L, "ROTATION_FACE_WIND_DIRECTION", ROTATION_FACE_WIND_DIRECTION);
        setEnum(L, "ROTATION_TARGET", ROTATION_TARGET);
        setEnum(L, "ROTATION_MATCH_PARENT", ROTATION_MATCH_PARENT);

        lua_setglobal(L, "BuildingRotation");
    }

    // ------------------------------------------
    // Platoon.h
    // ------------------------------------------

    void registerPlatoonCreationMessage(lua_State* L)
    {
        lua_createtable(L, 0, 8);
    // original C++ enums
        setEnum(L, "CM_NO_MESSAGE", PlatoonCreationMessage::CM_NO_MESSAGE);
        setEnum(L, "CM_REFRESH", PlatoonCreationMessage::CM_REFRESH);
        setEnum(L, "CM_DECIMATE", PlatoonCreationMessage::CM_DECIMATE);
        setEnum(L, "CM_DELETE", PlatoonCreationMessage::CM_DELETE);
        setEnum(L, "CM_EMPTY", PlatoonCreationMessage::CM_EMPTY);
    // aliases
        setEnum(L, "NO_MESSAGE", PlatoonCreationMessage::CM_NO_MESSAGE);
        setEnum(L, "REFRESH", PlatoonCreationMessage::CM_REFRESH);
        setEnum(L, "DECIMATE", PlatoonCreationMessage::CM_DECIMATE);
        setEnum(L, "DELETE", PlatoonCreationMessage::CM_DELETE);
        setEnum(L, "EMPTY", PlatoonCreationMessage::CM_EMPTY);
    // set the global variable
        lua_setglobal(L, "PlatoonCreationMessage");
    }

    // ------------------------------------------
    // RootObject.h
    // ------------------------------------------

    void registerGroupType(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "TYPE_UNKNOWN", DataObjectContainer::TYPE_UNKNOWN);
        setEnum(L, "TYPE_PLATOON", DataObjectContainer::TYPE_PLATOON);
        setEnum(L, "TYPE_FACTION", DataObjectContainer::TYPE_FACTION);
        setEnum(L, "TYPE_TOWNLIST", DataObjectContainer::TYPE_TOWNLIST);
        setEnum(L, "TYPE_ZONEMAP", DataObjectContainer::TYPE_ZONEMAP);
        setEnum(L, "TYPE_BUILDING_INTERIOR", DataObjectContainer::TYPE_BUILDING_INTERIOR);

        lua_setglobal(L, "GroupType");
    }

    // ------------------------------------------
    // SaveFileSystem.h
    // ------------------------------------------

    void registerSaveFileSystemState(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "NORMAL", SaveFileSystem::NORMAL);
        setEnum(L, "SAVING", SaveFileSystem::SAVING);
        setEnum(L, "COMPLETE", SaveFileSystem::COMPLETE);

        lua_setglobal(L, "SaveFileSystemState");
    }

    void registerSaveFileSystemMessageType(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "MSG_COPY", SaveFileSystem::MSG_COPY);
        setEnum(L, "MSG_COPY_REPLACE", SaveFileSystem::MSG_COPY_REPLACE);
        setEnum(L, "MSG_DELETE", SaveFileSystem::MSG_DELETE);

        lua_setglobal(L, "SaveFileSystemMessageType");
    }

    // ------------------------------------------
    // SaveManager.h
    // ------------------------------------------

    void registerSaveManagerFlags(lua_State* L)
    {
        lua_createtable(L, 0, 6);

        setEnum(L, "RESET_POSITION", SaveManager::Flags::RESET_POSITION);
        setEnum(L, "IMPORT_SQUAD", SaveManager::Flags::IMPORT_SQUAD);
        setEnum(L, "IMPORT_BUILDINGS", SaveManager::Flags::IMPORT_BUILDINGS);
        setEnum(L, "IMPORT_RESEARCH", SaveManager::Flags::IMPORT_RESEARCH);
        setEnum(L, "IMPORT_NPC_STATES", SaveManager::Flags::IMPORT_NPC_STATES);
        setEnum(L, "IMPORT_RELATIONS", SaveManager::Flags::IMPORT_RELATIONS);

        lua_setglobal(L, "SaveManagerFlags");
    }

    void registerSaveManagerSignals(lua_State* L)
    {
        lua_createtable(L, 0, 4);

        setEnum(L, "SAVEGAME", SaveManager::Signal::SAVEGAME);
        setEnum(L, "LOADGAME", SaveManager::Signal::LOADGAME);
        setEnum(L, "IMPORTGAME", SaveManager::Signal::IMPORTGAME);
        setEnum(L, "NEWGAME", SaveManager::Signal::NEWGAME);

        lua_setglobal(L, "SaveManagerSignals");
    }

    // ------------------------------------------
    // ScreenLabel.h
    // ------------------------------------------

    void registerScreenLabelRisingSpeed(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "RS_STOPPED", ScreenLabel::RS_STOPPED);
        setEnum(L, "RS_SLOW", ScreenLabel::RS_SLOW);
        setEnum(L, "RS_NORMAL", ScreenLabel::RS_NORMAL);
        setEnum(L, "RS_FAST", ScreenLabel::RS_FAST);
    // aliases
        setEnum(L, "STOPPED", ScreenLabel::RS_STOPPED);
        setEnum(L, "SLOW", ScreenLabel::RS_SLOW);
        setEnum(L, "NORMAL", ScreenLabel::RS_NORMAL);
        setEnum(L, "FAST", ScreenLabel::RS_FAST);
        lua_setglobal(L, "RisingSpeed");
    }

    void registerScreenLabelLabelSize(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "LS_SMALL", ScreenLabel::LS_SMALL);
        setEnum(L, "LS_MEDIUM", ScreenLabel::LS_MEDIUM);
        setEnum(L, "LS_LARGE", ScreenLabel::LS_LARGE);
    // aliases
        setEnum(L, "SMALL", ScreenLabel::LS_SMALL);
        setEnum(L, "MEDIUM", ScreenLabel::LS_MEDIUM);
        setEnum(L, "LARGE", ScreenLabel::LS_LARGE);
    // global
        lua_setglobal(L, "LabelSize");
    }

    // ------------------------------------------
    // SensoryData.h
    // ------------------------------------------

    void registerSenseType(lua_State* L)
    {
        lua_createtable(L, 0, 6);

        setEnum(L, "SENSE_ALLY", SENSE_ALLY);
        setEnum(L, "SENSE_NEUTRAL", SENSE_NEUTRAL);
        setEnum(L, "SENSE_ENEMY", SENSE_ENEMY);
        setEnum(L, "SENSE_KO", SENSE_KO);
        setEnum(L, "SENSE_DEAD", SENSE_DEAD);
        setEnum(L, "SENSE_SLAVE", SENSE_SLAVE);
        setEnum(L, "SENSE_ESCAPED_SLAVE", SENSE_ESCAPED_SLAVE);
        setEnum(L, "SENSE_AUTHORITY_FIGURE", SENSE_AUTHORITY_FIGURE);
        setEnum(L, "SENSE_CANT_SEE", SENSE_CANT_SEE);
        setEnum(L, "SENSE_IN_CAGE", SENSE_IN_CAGE);
        setEnum(L, "SENSE_SAME_FACTION", SENSE_SAME_FACTION);
        setEnum(L, "SENSE_ROBOTS", SENSE_ROBOTS);
        setEnum(L, "SENSE_ENEMY_OF_MY_SLAVEMASTER", SENSE_ENEMY_OF_MY_SLAVEMASTER);
        setEnum(L, "SENSE_PLAYER", SENSE_PLAYER);
        setEnum(L, "SENSE_CRAWLING", SENSE_CRAWLING);
        setEnum(L, "SENSE_CARRIED", SENSE_CARRIED);
    // aliases
        setEnum(L, "ALLY", SENSE_ALLY);
        setEnum(L, "NEUTRAL", SENSE_NEUTRAL);
        setEnum(L, "ENEMY", SENSE_ENEMY);
        setEnum(L, "KO", SENSE_KO);
        setEnum(L, "DEAD", SENSE_DEAD);
        setEnum(L, "SLAVE", SENSE_SLAVE);
        setEnum(L, "ESCAPED_SLAVE", SENSE_ESCAPED_SLAVE);
        setEnum(L, "AUTHORITY_FIGURE", SENSE_AUTHORITY_FIGURE);
        setEnum(L, "CANT_SEE", SENSE_CANT_SEE);
        setEnum(L, "IN_CAGE", SENSE_IN_CAGE);
        setEnum(L, "SAME_FACTION", SENSE_SAME_FACTION);
        setEnum(L, "ROBOTS", SENSE_ROBOTS);
        setEnum(L, "ENEMY_OF_MY_SLAVEMASTER", SENSE_ENEMY_OF_MY_SLAVEMASTER);
        setEnum(L, "PLAYER", SENSE_PLAYER);
        setEnum(L, "CRAWLING", SENSE_CRAWLING);
        setEnum(L, "CARRIED", SENSE_CARRIED);
    // global
        lua_setglobal(L, "SenseType");
    }

    // ------------------------------------------
    // SquadManagementScreen.h
    // ------------------------------------------

    void registerSquadManagementScreenState(lua_State* L)
    {
        lua_newtable(L);
        setEnum(L, "NORMAL", PortraitData::NORMAL);
        setEnum(L, "SELECTED", PortraitData::SELECTED);
        setEnum(L, "HURT", PortraitData::HURT);
        setEnum(L, "DOWN", PortraitData::DOWN);
        setEnum(L, "COMBAT", PortraitData::COMBAT);
        setEnum(L, "SLAVE", PortraitData::SLAVE);
        setEnum(L, "PRISON", PortraitData::PRISON);
        setEnum(L, "EATEN", PortraitData::EATEN);
        setEnum(L, "HUNGER", PortraitData::HUNGER);
        lua_setglobal(L, "PortraitState");
    }

    // ------------------------------------------
    // Tasker.h
    // ------------------------------------------

    void registerTaskertaskPriority(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "TP_JUST_ACTION", taskPriority::TP_JUST_ACTION);
        setEnum(L, "TP_FLUFF", taskPriority::TP_FLUFF);
        setEnum(L, "TP_NON_URGENT", taskPriority::TP_NON_URGENT);
        setEnum(L, "TP_URGENT", taskPriority::TP_URGENT);
        setEnum(L, "TP_OBEDIENCE", taskPriority::TP_OBEDIENCE);
        setEnum(L, "TP_MAX_SIZE", taskPriority::TP_MAX_SIZE);
    // aliases
        setEnum(L, "JUST_ACTION", taskPriority::TP_JUST_ACTION);
        setEnum(L, "FLUFF", taskPriority::TP_FLUFF);
        setEnum(L, "NON_URGENT", taskPriority::TP_NON_URGENT);
        setEnum(L, "URGENT", taskPriority::TP_URGENT);
        setEnum(L, "OBEDIENCE", taskPriority::TP_OBEDIENCE);
        setEnum(L, "MAX_SIZE", taskPriority::TP_MAX_SIZE);
    // global
        lua_setglobal(L, "taskPriority");
    }

    void registerTaskerStateType(lua_State* L)
    {
        lua_newtable(L);
        setEnum(L, "NONE_RESULT", StateType::NONE_RESULT);
        setEnum(L, "AT_LOCATION", StateType::AT_LOCATION);
        setEnum(L, "BUILDING_COMPLETE", StateType::BUILDING_COMPLETE);
        setEnum(L, "SUBJECT_IN_INVENTORY", StateType::SUBJECT_IN_INVENTORY);
        setEnum(L, "HAS_WEAPON", StateType::HAS_WEAPON);
        setEnum(L, "HAS_WEAPON_EQUIPPED", StateType::HAS_WEAPON_EQUIPPED);
        setEnum(L, "NO_ENEMIES_IN_VICINITY", StateType::NO_ENEMIES_IN_VICINITY);
        setEnum(L, "TARGET_DOWN", StateType::TARGET_DOWN);
        setEnum(L, "WEAPON_AS_TARGET", StateType::WEAPON_AS_TARGET);
        setEnum(L, "HOSTILE_APPROACHING", StateType::HOSTILE_APPROACHING);
        setEnum(L, "UNDER_MELEE_ATTACK", StateType::UNDER_MELEE_ATTACK);
        setEnum(L, "UNDER_RANGED_ATTACK", StateType::UNDER_RANGED_ATTACK);
        setEnum(L, "ALLIES_UNDER_ATTACK", StateType::ALLIES_UNDER_ATTACK);
        setEnum(L, "TARGETED_ENEMY", StateType::TARGETED_ENEMY);
        setEnum(L, "TARGETED_ATTACKER_OF_ALLY", StateType::TARGETED_ATTACKER_OF_ALLY);
        setEnum(L, "ITEM_IS_PHYSICALLY_LOOTABLE", StateType::ITEM_IS_PHYSICALLY_LOOTABLE);
        setEnum(L, "AGGRESSION_TOWARDS_TARGET", StateType::AGGRESSION_TOWARDS_TARGET);
        setEnum(L, "AM_IDLE", StateType::AM_IDLE);
        setEnum(L, "AT_HOME_BUILDING", StateType::AT_HOME_BUILDING);
        setEnum(L, "VILLAGE_RAZED", StateType::VILLAGE_RAZED);
        setEnum(L, "NONE_REQUIREMENT", StateType::NONE_REQUIREMENT);
        setEnum(L, "CHARACTER_HEALTH_IN_DANGER", StateType::CHARACTER_HEALTH_IN_DANGER);
        setEnum(L, "NEEDS_FIRST_AID", StateType::NEEDS_FIRST_AID);
        setEnum(L, "HAS_FIRST_AID_KIT", StateType::HAS_FIRST_AID_KIT);
        setEnum(L, "IS_CROUCHING", StateType::IS_CROUCHING);
        setEnum(L, "IS_LYING", StateType::IS_LYING);
        setEnum(L, "IS_CROUCHING_OR_LYING", StateType::IS_CROUCHING_OR_LYING);
        setEnum(L, "MOVEMENT_ALLOWED", StateType::MOVEMENT_ALLOWED);
        setEnum(L, "NEAR_TO", StateType::NEAR_TO);
        setEnum(L, "GENERAL_AGGRESSION_LEVEL", StateType::GENERAL_AGGRESSION_LEVEL);
        setEnum(L, "NODE_UNOCCUPIED_BY_OTHERS", StateType::NODE_UNOCCUPIED_BY_OTHERS);
        setEnum(L, "AT_NODE", StateType::AT_NODE);
        setEnum(L, "HAS_VALID_TARGET_TOWN", StateType::HAS_VALID_TARGET_TOWN);
        setEnum(L, "TIRED", StateType::TIRED);
        setEnum(L, "FOLLOW_ME_MODE", StateType::FOLLOW_ME_MODE);
        setEnum(L, "HAS_ENOUGH_GUARDS", StateType::HAS_ENOUGH_GUARDS);
        setEnum(L, "AT_TARGET_TOWN", StateType::AT_TARGET_TOWN);
        setEnum(L, "READY_FOR_MELEE_ACTION", StateType::READY_FOR_MELEE_ACTION);
        setEnum(L, "HAS_ONE_WORKING_ARM", StateType::HAS_ONE_WORKING_ARM);
        setEnum(L, "AGGRESSION_TOWARDS_ME", StateType::AGGRESSION_TOWARDS_ME);
        setEnum(L, "WITHIN_10_METERS", StateType::WITHIN_10_METERS);
        setEnum(L, "WITHIN_50_METERS", StateType::WITHIN_50_METERS);
        setEnum(L, "TARGET_STANDING_STILL", StateType::TARGET_STANDING_STILL);
        setEnum(L, "I_AM_DOWN", StateType::I_AM_DOWN);
        setEnum(L, "WANTS_TO_GET_UP", StateType::WANTS_TO_GET_UP);
        setEnum(L, "CAN_GET_UP", StateType::CAN_GET_UP);
        setEnum(L, "AT_LOCATION_ASAP", StateType::AT_LOCATION_ASAP);
        setEnum(L, "IS_CARRYING_SOMETHING", StateType::IS_CARRYING_SOMETHING);
        setEnum(L, "IS_CARRYING_TARGET", StateType::IS_CARRYING_TARGET);
        setEnum(L, "PLAYER_FORCES_GET_UP", StateType::PLAYER_FORCES_GET_UP);
        setEnum(L, "HAS_SOME_BUILDING_MATERIALS", StateType::HAS_SOME_BUILDING_MATERIALS);
        setEnum(L, "BUILDING_HAS_SOME_BUILDING_MATERIALS", StateType::BUILDING_HAS_SOME_BUILDING_MATERIALS);
        setEnum(L, "DOOR_IS_OPEN", StateType::DOOR_IS_OPEN);
        setEnum(L, "DOOR_IS_OPEN_HERE", StateType::DOOR_IS_OPEN_HERE);
        setEnum(L, "DOOR_IS_LOCKED", StateType::DOOR_IS_LOCKED);
        setEnum(L, "DOOR_IS_LOCKED_HERE", StateType::DOOR_IS_LOCKED_HERE);
        setEnum(L, "DOOR_IS_BROKEN", StateType::DOOR_IS_BROKEN);
        setEnum(L, "AT_LOCATION_BUILDING_DOOR", StateType::AT_LOCATION_BUILDING_DOOR);
        setEnum(L, "AT_CURRENT_LOCATION_BUILDING_DOOR", StateType::AT_CURRENT_LOCATION_BUILDING_DOOR);
        setEnum(L, "DESTINATION_IS_ACCESSIBLE", StateType::DESTINATION_IS_ACCESSIBLE);
        setEnum(L, "LOCATION_IS_ACCESSIBLE", StateType::LOCATION_IS_ACCESSIBLE);
        setEnum(L, "INVENTORY_FULL_OF_RESOURCES", StateType::INVENTORY_FULL_OF_RESOURCES);
        setEnum(L, "MACHINES_INPUTS_EMPTY", StateType::MACHINES_INPUTS_EMPTY);
        setEnum(L, "MACHINES_OUTPUTS_FULL", StateType::MACHINES_OUTPUTS_FULL);
        setEnum(L, "MACHINE_IS_JAMMED", StateType::MACHINE_IS_JAMMED);
        setEnum(L, "ANY_MACHINES_JAMMED", StateType::ANY_MACHINES_JAMMED);
        setEnum(L, "HAVE_SOME_RESOURCES_FROM", StateType::HAVE_SOME_RESOURCES_FROM);
        setEnum(L, "HAVE_SOME_RESOURCES_FOR", StateType::HAVE_SOME_RESOURCES_FOR);
        setEnum(L, "HAVE_SOME_LOOT_FROM", StateType::HAVE_SOME_LOOT_FROM);
        setEnum(L, "ROUTE_IS_BLOCKED", StateType::ROUTE_IS_BLOCKED);
        setEnum(L, "I_OWN_OBJECT", StateType::I_OWN_OBJECT);
        setEnum(L, "BUILDING_IS_DAMAGED", StateType::BUILDING_IS_DAMAGED);
        setEnum(L, "IS_FULLY_RESTED", StateType::IS_FULLY_RESTED);
        setEnum(L, "MACHINE_HAS_FREE_OPERATOR_SLOT", StateType::MACHINE_HAS_FREE_OPERATOR_SLOT);
        setEnum(L, "ENEMY_FORCE_DEFEATED", StateType::ENEMY_FORCE_DEFEATED);
        setEnum(L, "MY_FORCE_DEFEATED", StateType::MY_FORCE_DEFEATED);
        setEnum(L, "MESSAGE_DELIVERED", StateType::MESSAGE_DELIVERED);
        setEnum(L, "CARRIED_DUDE_NOW_IN_BED", StateType::CARRIED_DUDE_NOW_IN_BED);
        setEnum(L, "TARGET_IS_IMPRISONED", StateType::TARGET_IS_IMPRISONED);
        setEnum(L, "I_AM_IMPRISONED", StateType::I_AM_IMPRISONED);
        setEnum(L, "CARRYING_ARM_IS_OK", StateType::CARRYING_ARM_IS_OK);
        setEnum(L, "CARRIED_DUDE_NOW_IN_CAGE", StateType::CARRIED_DUDE_NOW_IN_CAGE);
        setEnum(L, "GOT_INVENTORY_ROOM_FOR_RESOURCES", StateType::GOT_INVENTORY_ROOM_FOR_RESOURCES);
        setEnum(L, "I_AM_IN_BED", StateType::I_AM_IN_BED);
        setEnum(L, "AT_A_SHOP", StateType::AT_A_SHOP);
        setEnum(L, "BOUGHT_SHIT", StateType::BOUGHT_SHIT);
        setEnum(L, "AT_A_TOWN", StateType::AT_A_TOWN);
        setEnum(L, "ALL_DOORS_LOCKED_UP", StateType::ALL_DOORS_LOCKED_UP);
        setEnum(L, "INSIDE_BUILDING", StateType::INSIDE_BUILDING);
        setEnum(L, "HAVE_SOME_RESOURCES_FROM_THIS_MACHINE_BUT_WANT_THEM_GONE_IF_POSSIBLE", StateType::HAVE_SOME_RESOURCES_FROM_THIS_MACHINE_BUT_WANT_THEM_GONE_IF_POSSIBLE);
        setEnum(L, "DESTINATION_NOT_BLOCKED_BY_FORTIFICATIONS", StateType::DESTINATION_NOT_BLOCKED_BY_FORTIFICATIONS);
        setEnum(L, "AT_LOCATION_FORTIFICATION_GATE", StateType::AT_LOCATION_FORTIFICATION_GATE);
        setEnum(L, "IS_ENEMY", StateType::IS_ENEMY);
        setEnum(L, "BUILDING_HAS_POWER", StateType::BUILDING_HAS_POWER);
        setEnum(L, "AT_TARGET_TOWN_FAST", StateType::AT_TARGET_TOWN_FAST);
        setEnum(L, "AT_HOME_TOWN", StateType::AT_HOME_TOWN);
        setEnum(L, "TARGET_IS_FREE", StateType::TARGET_IS_FREE);
        setEnum(L, "CAGES_ARE_ALL_FULL", StateType::CAGES_ARE_ALL_FULL);
        setEnum(L, "MACHINE_OCCUPANT_IS_ALIVE", StateType::MACHINE_OCCUPANT_IS_ALIVE);
        setEnum(L, "CARRYING_A_DEAD_GUY", StateType::CARRYING_A_DEAD_GUY);
        setEnum(L, "CARRIED_DUDE_NOW_IN_DISPOSAL_MACHINE", StateType::CARRIED_DUDE_NOW_IN_DISPOSAL_MACHINE);
        setEnum(L, "LEADER_IS_DOWN", StateType::LEADER_IS_DOWN);
        setEnum(L, "SQUAD_UNDER_ATTACK", StateType::SQUAD_UNDER_ATTACK);
        setEnum(L, "MY_LEGS_MESSED_UP", StateType::MY_LEGS_MESSED_UP);
        setEnum(L, "USING_TARGET_TURRET", StateType::USING_TARGET_TURRET);
        setEnum(L, "MACHINES_OUTPUTS_EMPTY", StateType::MACHINES_OUTPUTS_EMPTY);
        setEnum(L, "MACHINES_INPUTS_FULL", StateType::MACHINES_INPUTS_FULL);
        setEnum(L, "I_AM_INSIDE_TARGET_BUILDING", StateType::I_AM_INSIDE_TARGET_BUILDING);
        setEnum(L, "STRANGERS_INSIDE_MY_BUILDING", StateType::STRANGERS_INSIDE_MY_BUILDING);
        setEnum(L, "SPOKEN_TO", StateType::SPOKEN_TO);
        setEnum(L, "SPOKEN_TO_WITHOUT_MOVING", StateType::SPOKEN_TO_WITHOUT_MOVING);
        setEnum(L, "AT_LOCATION_BUILDING_DOOR_INSIDE", StateType::AT_LOCATION_BUILDING_DOOR_INSIDE);
        setEnum(L, "DOOR_IS_LOCKED_AND_IM_INSIDE", StateType::DOOR_IS_LOCKED_AND_IM_INSIDE);
        setEnum(L, "TARGET_IN_TOWN", StateType::TARGET_IN_TOWN);
        setEnum(L, "TARGET_CUFFS_ARE_LOCKED", StateType::TARGET_CUFFS_ARE_LOCKED);
        setEnum(L, "IS_CARRYING_TARGET_HEALTHY", StateType::IS_CARRYING_TARGET_HEALTHY);
        setEnum(L, "TARGET_IS_MY_SLAVE", StateType::TARGET_IS_MY_SLAVE);
        setEnum(L, "TARGET_HAS_BEEN_LOOTED", StateType::TARGET_HAS_BEEN_LOOTED);
        setEnum(L, "TARGET_IS_UNARMED", StateType::TARGET_IS_UNARMED);
        setEnum(L, "TARGET_IS_SURRENDERED", StateType::TARGET_IS_SURRENDERED);
        setEnum(L, "TARGET_LOOKS_LIKE_A_SLAVE", StateType::TARGET_LOOKS_LIKE_A_SLAVE);
        setEnum(L, "CARRYING_EXCESS_LOOT", StateType::CARRYING_EXCESS_LOOT);
        setEnum(L, "HAS_TOOLS", StateType::HAS_TOOLS);
        setEnum(L, "IS_WORKING", StateType::IS_WORKING);
        setEnum(L, "TARGET_IS_ESCAPEE_OR_FREE", StateType::TARGET_IS_ESCAPEE_OR_FREE);
        setEnum(L, "TARGET_IS_CONSCIOUS", StateType::TARGET_IS_CONSCIOUS);
        setEnum(L, "AT_LOCATION_BUILDING_DOOR_OUTSIDE", StateType::AT_LOCATION_BUILDING_DOOR_OUTSIDE);
        setEnum(L, "DOOR_IS_LOCKED_AND_IM_OUTSIDE", StateType::DOOR_IS_LOCKED_AND_IM_OUTSIDE);
        setEnum(L, "IS_ALLY", StateType::IS_ALLY);
        setEnum(L, "TARGET_IS_ARRESTED", StateType::TARGET_IS_ARRESTED);
        setEnum(L, "ALARMS_IN_THE_VICINITY", StateType::ALARMS_IN_THE_VICINITY);
        setEnum(L, "AT_PACKAGE_TARGET", StateType::AT_PACKAGE_TARGET);
        setEnum(L, "HAS_REPAIR_KIT", StateType::HAS_REPAIR_KIT);
        setEnum(L, "NEEDS_REPAIR_ROBOT", StateType::NEEDS_REPAIR_ROBOT);
        setEnum(L, "TARGET_IS_WEARING_CUFFS", StateType::TARGET_IS_WEARING_CUFFS);
        setEnum(L, "TARGET_IS_EATEN", StateType::TARGET_IS_EATEN);
        setEnum(L, "IS_WORKING_PRETEND", StateType::IS_WORKING_PRETEND);
        setEnum(L, "INTRUDER_IS_OUTSIDE_BUILDING", StateType::INTRUDER_IS_OUTSIDE_BUILDING);
        setEnum(L, "AT_A_TOWN_FOR_SLAVE_SELLING", StateType::AT_A_TOWN_FOR_SLAVE_SELLING);
        setEnum(L, "IM_SWIMMING", StateType::IM_SWIMMING);
        setEnum(L, "TARGET_SWIMMING", StateType::TARGET_SWIMMING);
        setEnum(L, "STRANGERS_INSIDE_MY_BUILDING_AND_ITS_PRIVATE", StateType::STRANGERS_INSIDE_MY_BUILDING_AND_ITS_PRIVATE);
        setEnum(L, "TARGET_IS_RESTRAINED_OR_KO", StateType::TARGET_IS_RESTRAINED_OR_KO);
        setEnum(L, "TARGET_FARM_HAS_FOOD", StateType::TARGET_FARM_HAS_FOOD);
        setEnum(L, "AM_HUNGRY", StateType::AM_HUNGRY);
        setEnum(L, "IS_USING_ANY_TURRET", StateType::IS_USING_ANY_TURRET);
        setEnum(L, "TARGET_WORSHIPPED", StateType::TARGET_WORSHIPPED);
        setEnum(L, "DITCHED_ALL_RESOURCES", StateType::DITCHED_ALL_RESOURCES);
        setEnum(L, "LOOTED_STORABLE_ITEMS", StateType::LOOTED_STORABLE_ITEMS);
        setEnum(L, "GOT_A_FOOD_ITEM", StateType::GOT_A_FOOD_ITEM);
        setEnum(L, "HAVE_SOME_BUILD_MATS", StateType::HAVE_SOME_BUILD_MATS);
        setEnum(L, "HAS_SPLINT_KIT", StateType::HAS_SPLINT_KIT);
        setEnum(L, "NEEDS_SPLINT", StateType::NEEDS_SPLINT);
        setEnum(L, "FINAL_GOT_A_KIDNAP_VICTIM", StateType::FINAL_GOT_A_KIDNAP_VICTIM);
        setEnum(L, "FINAL_FOUND_AND_PUT_CARRIED_IN_A_CAGE", StateType::FINAL_FOUND_AND_PUT_CARRIED_IN_A_CAGE);
        setEnum(L, "I_AM_PRONE", StateType::I_AM_PRONE);
        setEnum(L, "BUILDING_IS_DESTROYED", StateType::BUILDING_IS_DESTROYED);
        setEnum(L, "INTRUDER_IS_OUTSIDE_GATES", StateType::INTRUDER_IS_OUTSIDE_GATES);
        setEnum(L, "CROWD_LIMIT_8_PEOPLE", StateType::CROWD_LIMIT_8_PEOPLE);
        setEnum(L, "I_HAVE_SUFFICIENT_LOCK_SKILL", StateType::I_HAVE_SUFFICIENT_LOCK_SKILL);
        setEnum(L, "I_HAVE_SUFFICIENT_LOCK_SKILL_FOR_SHACKLES", StateType::I_HAVE_SUFFICIENT_LOCK_SKILL_FOR_SHACKLES);
        setEnum(L, "DESTINATION_IS_ACCESSIBLE_ANIMAL", StateType::DESTINATION_IS_ACCESSIBLE_ANIMAL);
        setEnum(L, "MACHINE_HAS_INVALID_INPUTS", StateType::MACHINE_HAS_INVALID_INPUTS);
        lua_setglobal(L, "StateType");
    }

    void registerTaskerPermajobType(lua_State* L)
    {
        lua_newtable(L);
        setEnum(L, "NOT_A_PERMAJOB", PermajobType::NOT_A_PERMAJOB);
        setEnum(L, "PERMAJOB_NORMAL", PermajobType::PERMAJOB_NORMAL);
        setEnum(L, "PERMAJOB_HIGHCOMBAT", PermajobType::PERMAJOB_HIGHCOMBAT);
        lua_setglobal(L, "PermajobType");
    }

    // ------------------------------------------
    // ToolTip.h
    // ------------------------------------------

    void registerToolTipType(lua_State* L)
    {
        lua_newtable(L);
        setEnum(L, "TEXT", ToolTip::TEXT);
        setEnum(L, "MULTILINE", ToolTip::MULTILINE);
        setEnum(L, "GAMEDATA", ToolTip::GAMEDATA);
        setEnum(L, "ITEM", ToolTip::ITEM);
        setEnum(L, "HAND", ToolTip::HAND);
        lua_setglobal(L, "ToolTipType");
    }

    // ------------------------------------------
    // Town.h
    // ------------------------------------------

    void registerTownAlarmState(lua_State* L)
    {
        lua_createtable(L, 0, 8);

    //original
        setEnum(L, "ALARM_NONE", TownAlarmState::ALARM_NONE);
        setEnum(L, "ALARM_INTRUDER", TownAlarmState::ALARM_INTRUDER);
        setEnum(L, "ALARM_ESCAPE", TownAlarmState::ALARM_ESCAPE);
        setEnum(L, "ALARM_ATTACK", TownAlarmState::ALARM_ATTACK);
    //aliases
        setEnum(L, "NONE", TownAlarmState::ALARM_NONE);
        setEnum(L, "INTRUDER", TownAlarmState::ALARM_INTRUDER);
        setEnum(L, "ESCAPE", TownAlarmState::ALARM_ESCAPE);
        setEnum(L, "ATTACK", TownAlarmState::ALARM_ATTACK);
    //set the global variable
        lua_setglobal(L, "TownAlarmState");
    }

    void registerTownType(lua_State* L)
    {
        lua_createtable(L, 0, 11);
    //original
        setEnum(L, "TOWN_NEST", TownType::TOWN_NEST);
        setEnum(L, "TOWN_OUTPOST", TownType::TOWN_OUTPOST);
        setEnum(L, "TOWN_TOWN", TownType::TOWN_TOWN);
        setEnum(L, "TOWN_VILLAGE", TownType::TOWN_VILLAGE);
        setEnum(L, "TOWN_RUINS", TownType::TOWN_RUINS);
        setEnum(L, "TOWN_SLAVE_CAMP", TownType::TOWN_SLAVE_CAMP);
        setEnum(L, "TOWN_MILITARY", TownType::TOWN_MILITARY);
        setEnum(L, "TOWN_PRISON", TownType::TOWN_PRISON);
        setEnum(L, "TOWN_NEST_MARKER", TownType::TOWN_NEST_MARKER);
        setEnum(L, "TOWN_POI", TownType::TOWN_POI);
        setEnum(L, "TOWN_NULL", TownType::TOWN_NULL);
    //aliases
        setEnum(L, "NEST", TownType::TOWN_NEST);
        setEnum(L, "OUTPOST", TownType::TOWN_OUTPOST);
        setEnum(L, "TOWN", TownType::TOWN_TOWN);
        setEnum(L, "VILLAGE", TownType::TOWN_VILLAGE);
        setEnum(L, "RUINS", TownType::TOWN_RUINS);
        setEnum(L, "SLAVE_CAMP", TownType::TOWN_SLAVE_CAMP);
        setEnum(L, "MILITARY", TownType::TOWN_MILITARY);
        setEnum(L, "PRISON", TownType::TOWN_PRISON);
        setEnum(L, "NEST_MARKER", TownType::TOWN_NEST_MARKER);
        setEnum(L, "POI", TownType::TOWN_POI);
        setEnum(L, "NULL", TownType::TOWN_NULL);
    //set the global variable
        lua_setglobal(L, "TownType");
    }

    // ------------------------------------------
    // TutorialGUI.h
    // ------------------------------------------

    void registerTutorialGUIState(lua_State* L)
    {
        lua_newtable(L);
        setEnum(L, "INACTIVE", TutorialItem::INACTIVE);
        setEnum(L, "ACTIVE", TutorialItem::ACTIVE);
        setEnum(L, "ENDED", TutorialItem::ENDED);
        lua_setglobal(L, "TutorialItemState");
    }

    void registerTutorialGUIHighlightItem(lua_State* L)
    {
        lua_newtable(L);
        setEnum(L, "NONE", TutorialGUI::NONE);
        setEnum(L, "PORTRAITS", TutorialGUI::PORTRAITS);
        setEnum(L, "PANEL_STATS", TutorialGUI::PANEL_STATS);
        setEnum(L, "PANEL_STATS_BOTTOM", TutorialGUI::PANEL_STATS_BOTTOM);
        setEnum(L, "PANEL_STATS_BOTTOM_POWER_BUTTON", TutorialGUI::PANEL_STATS_BOTTOM_POWER_BUTTON);
        setEnum(L, "PANEL_STATS_BOTTOM_WORKERS", TutorialGUI::PANEL_STATS_BOTTOM_WORKERS);
        setEnum(L, "PANEL_MEDICAL", TutorialGUI::PANEL_MEDICAL);
        setEnum(L, "PANEL_MEDICAL_STATUS", TutorialGUI::PANEL_MEDICAL_STATUS);
        setEnum(L, "PANEL_MEDICAL_BAR_BODY", TutorialGUI::PANEL_MEDICAL_BAR_BODY);
        setEnum(L, "PANEL_MEDICAL_BAR_LIMBS", TutorialGUI::PANEL_MEDICAL_BAR_LIMBS);
        setEnum(L, "PANEL_MEDICAL_BAR_BLOOD", TutorialGUI::PANEL_MEDICAL_BAR_BLOOD);
        setEnum(L, "PANEL_MEDICAL_BAR_POWER", TutorialGUI::PANEL_MEDICAL_BAR_POWER);
        setEnum(L, "PANEL_MEDICAL_BAR_MATERIALS", TutorialGUI::PANEL_MEDICAL_BAR_MATERIALS);
        setEnum(L, "PANEL_MEDICAL_BAR_MATERIALS_BUILDING", TutorialGUI::PANEL_MEDICAL_BAR_MATERIALS_BUILDING);
        setEnum(L, "PANEL_MEDICAL_BAR_CONDITION", TutorialGUI::PANEL_MEDICAL_BAR_CONDITION);
        setEnum(L, "PANEL_MEDICAL_BAR_CONDITION_BUILDING", TutorialGUI::PANEL_MEDICAL_BAR_CONDITION_BUILDING);
        setEnum(L, "PANEL_GAME_SPEED", TutorialGUI::PANEL_GAME_SPEED);
        setEnum(L, "PANEL_TIME_MONEY", TutorialGUI::PANEL_TIME_MONEY);
        setEnum(L, "BUTTON_BUILD", TutorialGUI::BUTTON_BUILD);
        setEnum(L, "PANEL_BOUNTY", TutorialGUI::PANEL_BOUNTY);
        setEnum(L, "PANEL_MENU_BAR", TutorialGUI::PANEL_MENU_BAR);
        setEnum(L, "PANEL_MENU_BAR_SQUAD", TutorialGUI::PANEL_MENU_BAR_SQUAD);
        setEnum(L, "PANEL_MENU_BAR_STATS", TutorialGUI::PANEL_MENU_BAR_STATS);
        setEnum(L, "PANEL_MENU_BAR_TECH", TutorialGUI::PANEL_MENU_BAR_TECH);
        setEnum(L, "PANEL_ORDERS", TutorialGUI::PANEL_ORDERS);
        setEnum(L, "PANEL_ORDERS_COMMANDS", TutorialGUI::PANEL_ORDERS_COMMANDS);
        setEnum(L, "PANEL_ORDERS_JOBS", TutorialGUI::PANEL_ORDERS_JOBS);
        setEnum(L, "PANEL_ORDERS_JOB_REMOVE", TutorialGUI::PANEL_ORDERS_JOB_REMOVE);
        setEnum(L, "PANEL_ORDERS_JOB_OBEDIENCE", TutorialGUI::PANEL_ORDERS_JOB_OBEDIENCE);
        setEnum(L, "PANEL_ORDERS_MEDIC_BUTTON", TutorialGUI::PANEL_ORDERS_MEDIC_BUTTON);
        setEnum(L, "PANEL_ORDERS_RESCUE_BUTTON", TutorialGUI::PANEL_ORDERS_RESCUE_BUTTON);
        setEnum(L, "MAPSCREEN_CRAFT_TAB", TutorialGUI::MAPSCREEN_CRAFT_TAB);
        setEnum(L, "MAPSCREEN_CRAFT_TAB_ITEMS", TutorialGUI::MAPSCREEN_CRAFT_TAB_ITEMS);
        setEnum(L, "BUILDING_INVENTORY_INPUT", TutorialGUI::BUILDING_INVENTORY_INPUT);
        setEnum(L, "BUILD_MODE_PANEL_BUILDINGS", TutorialGUI::BUILD_MODE_PANEL_BUILDINGS);
        lua_setglobal(L, "HighlightItem");
    }

    void registerMovementMode(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "MOVE_NORMAL", MovementMode::MOVE_NORMAL);
        setEnum(L, "MOVE_COMBAT", MovementMode::MOVE_COMBAT);
        setEnum(L, "MOVE_DIRECTION", MovementMode::MOVE_DIRECTION);
    // aliases
        setEnum(L, "NORMAL", MovementMode::MOVE_NORMAL);
        setEnum(L, "COMBAT", MovementMode::MOVE_COMBAT);
        setEnum(L, "DIRECTION", MovementMode::MOVE_DIRECTION);
    // global
        lua_setglobal(L, "MovementMode");
    }

    void registerArmourClass(lua_State* L)
    {
        lua_newtable(L);
    // original
        setEnum(L, "GEAR_CLOTH", ArmourClass::GEAR_CLOTH);
        setEnum(L, "GEAR_LIGHT", ArmourClass::GEAR_LIGHT);
        setEnum(L, "GEAR_MEDIUM", ArmourClass::GEAR_MEDIUM);
        setEnum(L, "GEAR_HEAVY", ArmourClass::GEAR_HEAVY);
        setEnum(L, "GEAR_MAX", ArmourClass::GEAR_MAX);
    // aliases
        setEnum(L, "CLOTH", ArmourClass::GEAR_CLOTH);
        setEnum(L, "LIGHT", ArmourClass::GEAR_LIGHT);
        setEnum(L, "MEDIUM", ArmourClass::GEAR_MEDIUM);
        setEnum(L, "HEAVY", ArmourClass::GEAR_HEAVY);
        setEnum(L, "MAX", ArmourClass::GEAR_MAX);
        lua_setglobal(L, "ArmourClass");
    }

    // ------------------------------------------
    // util/YesNoMaybe.h
    // ------------------------------------------

    void registerYesNoMaybe(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "NO", YesNoMaybe::NO);
        setEnum(L, "YES", YesNoMaybe::YES);
        setEnum(L, "MAYBE", YesNoMaybe::MAYBE);

        lua_pushvalue(L, -1);
        lua_setglobal(L, "YesNoMaybe");
        lua_setglobal(L, "ynm");
    }

    // ------------------------------------------
    // WorldEventStateQuery.h
    // ------------------------------------------

    void registerWorldStateEnum(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "DEAD", DEAD);
        setEnum(L, "ALIVE", ALIVE);
        setEnum(L, "IMPRISONED", IMPRISONED);

        lua_setglobal(L, "WorldStateEnum");
    }

    void registerWarStateEnum(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "PEACE", WorldEventStateQuery::PEACE);
        setEnum(L, "WAR", WorldEventStateQuery::WAR);
        setEnum(L, "ALLIANCE", WorldEventStateQuery::ALLIANCE);

        lua_setglobal(L, "WarStateEnum");
    }

    // ------------------------------------------
    // ZoneManager.h
    // ------------------------------------------

    void registerZoneActivationType(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "ACTIVATION_CAMERA", ACTIVATION_CAMERA);
        setEnum(L, "ACTIVATION_PLAYER_CHARACTER", ACTIVATION_PLAYER_CHARACTER);
        setEnum(L, "ACTIVATION_TOWN", ACTIVATION_TOWN);

        lua_setglobal(L, "ZoneActivationType");
    }

    void registerZoneManagerResult(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "UNCHANGED", ZoneSpacialGrid::UNCHANGED);
        setEnum(L, "CHANGED_CELL", ZoneSpacialGrid::CHANGED_CELL);
        setEnum(L, "CHANGED_ZONE", ZoneSpacialGrid::CHANGED_ZONE);
        setEnum(L, "UNLOADED_ZONE", ZoneSpacialGrid::UNLOADED_ZONE);

        lua_setglobal(L, "ZoneManagerResult");
    }

    void registerZoneMessage(lua_State* L)
    {
        lua_newtable(L);

        setEnum(L, "BEING_LOADED_FALSE", ZoneMap::BEING_LOADED_FALSE);
        setEnum(L, "BEING_LOADED_TRUE", ZoneMap::BEING_LOADED_TRUE);

        lua_setglobal(L, "ZoneMessage");
    }

    // ------------------------------------------
    // Registration Entry Point
    // ------------------------------------------

    void registerEnumBindings(lua_State* L)
    {
        registerAppearanceManagerDataCategory(L);
        registerAppearanceManagerGender(L);
        registerArmourClass(L);
        registerArmourType(L);
        registerAttachSlot(L);
        registerAttackDirection(L);
        registerBuildingClassType(L);
        registerBuildingDesignation(L);
        registerBuildingFunction(L);
        registerBuildingPlacementGroundType(L);
        registerBuildingRotation(L);
        registerCharMessage(L);
        registerCharacterMessage(L);
        registerCharacterPerceptionTagsLongTerm(L);
        registerCharacterPerceptionTagsShortTerm(L);
        registerCharacterStatsWindowGroup(L);
        registerCharacterTypeEnum(L);
        registerCollapseStage(L);
        registerComparisonEnum(L);
        registerCrimeEnum(L);
        registerCropType(L);
        registerCursorType(L);
        registerCutDirection(L);
        registerCutOrigination(L);
        registerDataPanelLineLineType(L);
        registerDialogConditionEnum(L);
        registerDialogueAction(L);
        registerDisguiseGUIFeedback(L);
        registerDoorState(L);
        registerDoorStateInitial(L);
        registerEffectType(L);
        registerEventTriggerEnum(L);
        registerFactionEvent(L);
        registerForgottenGUITradeWindowType(L);
        registerGameDataDataType(L);
        registerGroundType(L);
        registerGroupType(L);
        registerHavokCharacterState(L);
        registerHavokPathState(L);
        registerHealthPartStatus(L);
        registerHitMaterialType(L);
        registerInputHandlerGameMode(L);
        registerInventoryGUITradeResult(L);
        registerItemFunction(L);
        registerLeftRight(L);
        registerLimbState(L);
        registerLoggerSeverity(L);
        registerManagementScreenMessageLogColor(L);
        registerMapZoomLevel(L);
        registerMeshDataLookup(L);
        registerMessageType(L);
        registerMiningResource(L);
        registerMoveSpeed(L);
        registerMovementMode(L);
        registerNXU_FileType(L);
        registerNavMeshFileMode(L);
        registerNavMeshState(L);
        registerNxShapeFlag(L);
        registerNxShapesType(L);
        registerPlatoonCreationMessage(L);
        registerPreviewBuildingClassType(L);
        registerPreviewBuildingPlacementResult(L);
        registerProductionState(L);
        registerProneState(L);
        registerRagdollPart(L);
        registerRobotLimbs(L);
        registerSaveFileSystemState(L);
        registerSaveFileSystemMessageType(L);
        registerSaveManagerFlags(L);
        registerSaveManagerSignals(L);
        registerScreenLabelLabelSize(L);
        registerScreenLabelRisingSpeed(L);
        registerSenseType(L);
        registerSlaveStateEnum(L);
        registerSoundRange(L);
        registerSquadManagementScreenState(L);
        registerSquadMemberType(L);
        registerSquadType(L);
        registerStandingOrder(L);
        registerStatsEnumerated(L);
        registerSwordStateEnum(L);
        registerSysMessageEnum(L);
        registerTalker(L);
        registerTaskType(L);
        registerTaskerPermajobType(L);
        registerTaskerStateType(L);
        registerTaskertaskPriority(L);
        registerToolTipType(L);
        registerTownAlarmState(L);
        registerTownType(L);
        registerTutorialGUIHighlightItem(L);
        registerTutorialGUIState(L);
        registerUnloadedPlatoonJob(L);
        registerUpdatePriority(L);
        registerNxControllerAction(L);
        registerUseStuffState(L);
        registerWallSectionLinkType(L);
        registerWarStateEnum(L);
        registerWaterState(L);
        registerWeaponCategory(L);
        registerWeatherAffecting(L);
        registerWorldStateEnum(L);
        registerYesNoMaybe(L);
        registerZoneActivationType(L);
        registerZoneManagerResult(L);
        registerZoneMessage(L);
        registerItemType(L);
    }
} // namespace KenshiLua
