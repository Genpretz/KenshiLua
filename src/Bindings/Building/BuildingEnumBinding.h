#pragma once

#include <lua.h>

namespace KenshiLua
{
    class BuildingEnumBinding
    {
        public:
            static void registerBinding(lua_State* L);
        private:
            static void registerBuildingDesignation(lua_State* L);
            static void registerBuildingClassType(lua_State* L);
            static void registerBuildingPlacementGroundType(lua_State* L);
            static void registerPreviewBuildingPlacementResult(lua_State* L);
            static void registerPreviewBuildingClassType(lua_State* L);
    };

} // namespace KenshiLua
