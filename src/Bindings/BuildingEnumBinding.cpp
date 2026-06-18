#include "pch.h"
#include "Lua/BindingHelpers.h"
#include "BuildingEnumBinding.h"

#include <kenshi/Building/Building.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    void BuildingEnumBinding::registerBuildingDesignation(lua_State* L)
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

    void BuildingEnumBinding::registerBuildingClassType(lua_State* L)
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

    void BuildingEnumBinding::registerBuildingPlacementGroundType(lua_State* L)
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

    void BuildingEnumBinding::registerPreviewBuildingPlacementResult(lua_State* L)
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

    void BuildingEnumBinding::registerPreviewBuildingClassType(lua_State* L)
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

    void BuildingEnumBinding::registerBinding(lua_State* L)
    {
        registerBuildingDesignation(L);
        registerBuildingClassType(L);
        registerBuildingPlacementGroundType(L);
        registerPreviewBuildingPlacementResult(L);
        registerPreviewBuildingClassType(L);
    }

} // namespace KenshiLua
