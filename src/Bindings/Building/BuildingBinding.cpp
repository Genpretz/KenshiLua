#include "pch.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Core/EnumBinding.h"
#include "Bindings/World/FactionBinding.h"
#include "Bindings/Core/GameDataBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/Building.h>

#include <cstdio>

namespace KenshiLua
{

    static Building* getB(lua_State* L, int idx)
    {
        return checkObject<Building>(L, idx, BuildingBinding::getMetatableName());
    }

    int BuildingBinding::gc(lua_State* L) { return noopGc(L); }
    int BuildingBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        // 1. Check the metatable first so obj:method() syntax continues to work.
        luaL_getmetatable(L, BuildingBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;   // found a method — return it
        lua_pop(L, 2);  // pop nil result + metatable

        // 2. Fall through to raw member variable access.
        Building* b = getB(L, 1);
        if (!b) { lua_pushnil(L); return 1; }

        // --- boolean members ---
        if (strcmp(key, "is_foliage") == 0 || strcmp(key, "isFoliage") == 0) { lua_pushboolean(L, b->isFoliage ? 1 : 0);          return 1; }
        if (strcmp(key, "has_terrain_inside") == 0 || strcmp(key, "hasTerrainInside") == 0) { lua_pushboolean(L, b->hasTerrainInside ? 1 : 0);   return 1; }
        if (strcmp(key, "is_cavernous") == 0 || strcmp(key, "isCavernous") == 0) { lua_pushboolean(L, b->isCavernous ? 1 : 0);        return 1; }
        if (strcmp(key, "is_ceiling_enforced") == 0 || strcmp(key, "enforceCeiling") == 0) { lua_pushboolean(L, b->enforceCeiling ? 1 : 0);     return 1; }
        if (strcmp(key, "is_public_daytime") == 0 || strcmp(key, "publicDaytime") == 0) { lua_pushboolean(L, b->publicDaytime ? 1 : 0);      return 1; }
        if (strcmp(key, "update_navmesh") == 0 || strcmp(key, "updateNavmesh") == 0) { lua_pushboolean(L, b->updateNavmesh ? 1 : 0);      return 1; }
        if (strcmp(key, "is_visible") == 0 || strcmp(key, "visible") == 0) { lua_pushboolean(L, b->visible ? 1 : 0);            return 1; }
        if (strcmp(key, "is_interior_visible") == 0 || strcmp(key, "interiorVisibility") == 0) { lua_pushboolean(L, b->interiorVisibility ? 1 : 0); return 1; }
        if (strcmp(key, "is_a_door") == 0 || strcmp(key, "imADoor") == 0) { lua_pushboolean(L, b->imADoor ? 1 : 0);            return 1; }
        if (strcmp(key, "is_destroyed") == 0 || strcmp(key, "destroyed") == 0) { lua_pushboolean(L, b->destroyed ? 1 : 0);          return 1; }
        if (strcmp(key, "has_moving_parts") == 0 || strcmp(key, "hasMovingParts") == 0) { lua_pushboolean(L, b->hasMovingParts ? 1 : 0);     return 1; }
        if (strcmp(key, "is_interior_object") == 0 || strcmp(key, "isAnInteriorObject") == 0) { lua_pushboolean(L, b->isAnInteriorObject ? 1 : 0); return 1; }
        if (strcmp(key, "justBeenUpgraded") == 0) { lua_pushboolean(L, b->justBeenUpgradedFlag ? 1 : 0); return 1; }
        if (strcmp(key, "isOutsideFurniture") == 0) { lua_pushboolean(L, b->isOutsideFurniture ? 1 : 0); return 1; }
        if (strcmp(key, "lightsVisible") == 0) { lua_pushboolean(L, b->lightsVisible ? 1 : 0); return 1; }

        // --- float members ---
        if (strcmp(key, "production_mult") == 0 || strcmp(key, "productionMult") == 0) { lua_pushnumber(L, b->productionMult);          return 1; }
        if (strcmp(key, "production_mult_basedata") == 0 || strcmp(key, "productionMult_baseData") == 0) { lua_pushnumber(L, b->productionMult_baseData); return 1; }
        if (strcmp(key, "heightAboveGround") == 0) { lua_pushnumber(L, b->heightAboveGround); return 1; }

        // --- integer enum members ---
        if (strcmp(key, "designation") == 0) { lua_pushinteger(L, (int)b->designation); return 1; }
        if (strcmp(key, "class_type") == 0 || strcmp(key, "classType") == 0) { lua_pushinteger(L, (int)b->classType);   return 1; }

        // --- string members ---
        if (strcmp(key, "materialName") == 0) { lua_pushstring(L, b->materialName.c_str()); return 1; }

        // --- unique object members ---
        if (strcmp(key, "doors") == 0) {
            lua_createtable(L, b->doors.size(), 0);
            for (uint32_t i = 0; i < b->doors.size(); ++i) {
                pushObject<Building>(L, b->doors[i], BuildingBinding::getMetatableName());
                lua_rawseti(L, -2, i + 1);
            }
            return 1;
        }
        if (strcmp(key, "isFurnitureOf") == 0) {
            if (b->isFurnitureOf) lua_pushlightuserdata(L, (void*)b->isFurnitureOf);
            else                 lua_pushnil(L);
            return 1;
        }
        if (strcmp(key, "baseMaterial") == 0) {
            return pushObject<GameData>(L, b->baseMaterial, GameDataBinding::getMetatableName());
        }

        // Unknown key.
        lua_pushnil(L);
        return 1;
    }
    int BuildingBinding::newindex(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);
        Building* b = checkObject<Building>(L, 1, BuildingBinding::getMetatableName());
        if (!b) return luaL_error(L, "Building is nil");

        // Fields writable directly (no side-effects requiring a method).

		// --- boolean members ---
        if (strcmp(key, "isFoliage") == 0) { b->isFoliage = (lua_toboolean(L, 3) != 0);          return 0; }
        if (strcmp(key, "hasTerrainInside") == 0) { b->hasTerrainInside = (lua_toboolean(L, 3) != 0);   return 0; }
        if (strcmp(key, "isCavernous") == 0) { b->isCavernous = (lua_toboolean(L, 3) != 0);        return 0; }
        if (strcmp(key, "enforceCeiling") == 0) { b->enforceCeiling = (lua_toboolean(L, 3) != 0);     return 0; }
        if (strcmp(key, "publicDaytime") == 0) { b->publicDaytime = (lua_toboolean(L, 3) != 0);      return 0; }
        if (strcmp(key, "updateNavmesh") == 0) { b->updateNavmesh = (lua_toboolean(L, 3) != 0);      return 0; }
        if (strcmp(key, "visible") == 0) { b->visible = (lua_toboolean(L, 3) != 0);            return 0; }
        if (strcmp(key, "interiorVisibility") == 0) { b->interiorVisibility = (lua_toboolean(L, 3) != 0); return 0; }
		if (strcmp(key, "imADoor") == 0) { b->imADoor = (lua_toboolean(L, 3) != 0);            return 0; }
        if (strcmp(key, "hasMovingParts") == 0) { b->hasMovingParts = (lua_toboolean(L, 3) != 0);     return 0; }
		if (strcmp(key, "isAnInteriorObject") == 0) { b->isAnInteriorObject = (lua_toboolean(L, 3) != 0); return 0; }

		// --- float members ---
        if (strcmp(key, "productionMult") == 0 || strcmp(key, "production_mult") == 0) { b->productionMult = (float)luaL_checknumber(L, 3);  return 0; }
		if (strcmp(key, "productionMult_baseData") == 0 || strcmp(key, "production_mult_basedata") == 0) { b->productionMult_baseData = (float)luaL_checknumber(L, 3); return 0; }
		if (strcmp(key, "heightAboveGround") == 0) { b->heightAboveGround = (float)luaL_checknumber(L, 3); return 0; }

		// --- integer enum members ---
		if (strcmp(key, "classType") == 0 || strcmp(key, "class_type") == 0) { b->classType = (BuildingClassType)luaL_checkinteger(L, 3); return 0; }
		if (strcmp(key, "designation") == 0) { b->designation = (BuildingDesignation)luaL_checkinteger(L, 3); return 0; }

        // --- string members ---
        if (strcmp(key, "materialName") == 0) {
            b->materialName = luaL_checkstring(L, 3);
            return 0;
        }

        // --- boolean members extra ---
        if (strcmp(key, "justBeenUpgraded") == 0) { b->justBeenUpgradedFlag = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "isOutsideFurniture") == 0) { b->isOutsideFurniture = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "lightsVisible") == 0) { b->lightsVisible = (lua_toboolean(L, 3) != 0); return 0; }

        // Fields that have dedicated setter methods or are genuinely read-only.
        // Redirect the user to the correct API rather than silently failing.
        if (strcmp(key, "destroyed") == 0)   return luaL_error(L, "Building: use setDestroyed(bool) instead");
        if (strcmp(key, "designation") == 0) return luaL_error(L, "Building: use setDesignation(int) instead");

        return luaL_error(L, "Building: field '%s' does not exist", key);
    }

    int BuildingBinding::tostring(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushstring(L, "Building:nil"); return 1; }
        char buf[160];
        const char* nm = (b->getGameData() ? b->getGameData()->name.c_str() : "Unknown");
        _snprintf(buf, sizeof(buf), "Building:%s(%p)", nm, (void*)b);
        lua_pushstring(L, buf);
        return 1;
    }

    int BuildingBinding::getName(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (b) lua_pushstring(L, b->getName().c_str()); else lua_pushnil(L);
        return 1;
    }

    int BuildingBinding::getPosition(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushnil(L); return 1; }
        Ogre::Vector3 p = b->getPosition();
        pushVector3(L, p);
        return 1;
    }

    int BuildingBinding::getBuildingDesignation(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushnil(L); return 1; }

        lua_pushinteger(L, (int)b->getBuildingDesignation());
        return 1;
    }

    int BuildingBinding::getBuildingClass(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushnil(L); return 1; }
        lua_pushinteger(L, (int)b->getBuildingClass());
        return 1;
    }

    int BuildingBinding::getSpecialFunction(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushnil(L); return 1; }
        lua_pushinteger(L, (int)b->getSpecialFunction());
        return 1;
    }

    int BuildingBinding::getBuildState(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushnil(L); return 1; }
        Building::ConstructionState* state = b->getBuildState();
        if (!state) { lua_pushnil(L); return 1; }
        lua_createtable(L, 0, 6);
        lua_pushboolean(L, state->isComplete ? 1 : 0);     lua_setfield(L, -2, "isComplete");
        lua_pushboolean(L, state->isPaused ? 1 : 0);       lua_setfield(L, -2, "isPaused");
        lua_pushboolean(L, state->isDismantled ? 1 : 0);   lua_setfield(L, -2, "isDismantled");
        lua_pushnumber(L,  state->constructionProgress);   lua_setfield(L, -2, "constructionProgress");
        lua_pushnumber(L,  state->getHealthBarProgress()); lua_setfield(L, -2, "healthBarProgress");
        lua_pushnumber(L,  state->getConstructionMaterialProgress()); lua_setfield(L, -2, "materialProgress");
        return 1;
    }

    int BuildingBinding::getConstructionProgress(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushnil(L); return 1; }
        Building::ConstructionState* s = b->getBuildState();
        if (s) lua_pushnumber(L, s->constructionProgress);
        else   lua_pushnumber(L, 0);
        return 1;
    }

    int BuildingBinding::isPublic(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, b->isPublic() ? 1 : 0);
        return 1;
    }

    int BuildingBinding::isAShop(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, b->isAShop() ? 1 : 0);
        return 1;
    }

    int BuildingBinding::isForSale(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, b->isForSale() ? 1 : 0);
        return 1;
    }

    int BuildingBinding::isAWall(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, b->isAWall() ? 1 : 0);
        return 1;
    }

    int BuildingBinding::isDamaged(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, b->isDamaged() ? 1 : 0);
        return 1;
    }

    int BuildingBinding::isDestroyed(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, b->isDestroyed() ? 1 : 0);
        return 1;
    }

    int BuildingBinding::isBroken(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, b->isBroken() ? 1 : 0);
        return 1;
    }

    int BuildingBinding::isPowerOn(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, b->isPowerOn() ? 1 : 0);
        return 1;
    }

    int BuildingBinding::getScale(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushnil(L); return 1; }
        lua_pushnumber(L, b->getScale());
        return 1;
    }

    int BuildingBinding::getMiningResourceLevel(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushnil(L); return 1; }
        lua_pushnumber(L, b->getMiningResourceLevel());
        return 1;
    }

    int BuildingBinding::isValid(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, b->isValid() ? 1 : 0);
        return 1;
    }

    int BuildingBinding::setDesignation(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) return luaL_error(L, "Building is nil");
        int d = (int)luaL_checkinteger(L, 2);
        b->setDesignation((BuildingDesignation)d);
        return 0;
    }

    int BuildingBinding::setBroken(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) return luaL_error(L, "Building is nil");
        b->setBroken(lua_toboolean(L, 2) != 0);
        return 0;
    }

    int BuildingBinding::setDestroyed(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) return luaL_error(L, "Building is nil");
        b->setDestroyed(lua_toboolean(L, 2) != 0);
        return 0;
    }

    int BuildingBinding::setConstructionProgress(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) return luaL_error(L, "Building is nil");
        b->setConstructionProgress((float)luaL_checknumber(L, 2));
        return 0;
    }

    int BuildingBinding::setVisible(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) return luaL_error(L, "Building is nil");
        b->visible = lua_toboolean(L, 2) != 0;
        return 0;
    }

    int BuildingBinding::switchPowerOn(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) return luaL_error(L, "Building is nil");
        b->switchPowerOn(lua_toboolean(L, 2) != 0);
        return 0;
    }

    int BuildingBinding::togglePublic(lua_State* L)
    {
        Building* b = getB(L, 1);
        if (!b) return luaL_error(L, "Building is nil");
        if (lua_gettop(L) >= 2) {
            bool target = lua_toboolean(L, 2) != 0;
            if (b->publicDaytime != target) {
                b->togglePublic(NULL);
            }
        } else {
            b->togglePublic(NULL);
        }
        return 0;
    }

    void BuildingBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg meta[] = {
            { "__gc",       BuildingBinding::gc },
            { "__tostring", BuildingBinding::tostring },
            { 0, 0 }
        };

        // Register all methods directly onto the metatable so that our
        // __index C function can find them with lua_getfield.
        static const luaL_Reg methods[] = {
            { "getName",                   BuildingBinding::getName },
            { "getPosition",               BuildingBinding::getPosition },
            { "getBuildingDesignation",    BuildingBinding::getBuildingDesignation },
            { "getBuildingClass",          BuildingBinding::getBuildingClass },
            { "getSpecialFunction",        BuildingBinding::getSpecialFunction },
            { "getBuildState",             BuildingBinding::getBuildState },
            { "getConstructionProgress",   BuildingBinding::getConstructionProgress },
            { "isPublic",                  BuildingBinding::isPublic },
            { "isAShop",                   BuildingBinding::isAShop },
            { "isForSale",                 BuildingBinding::isForSale },
            { "isAWall",                   BuildingBinding::isAWall },
            { "isDamaged",                 BuildingBinding::isDamaged },
            { "isDestroyed",               BuildingBinding::isDestroyed },
            { "isBroken",                  BuildingBinding::isBroken },
            { "isPowerOn",                 BuildingBinding::isPowerOn },
            { "getScale",                  BuildingBinding::getScale },
            { "getMiningResourceLevel",    BuildingBinding::getMiningResourceLevel },
            { "isValid",                   BuildingBinding::isValid },
            { "setDesignation",            BuildingBinding::setDesignation },
            { "setBroken",                 BuildingBinding::setBroken },
            { "setDestroyed",              BuildingBinding::setDestroyed },
            { "setConstructionProgress",   BuildingBinding::setConstructionProgress },
            { "setVisible",                BuildingBinding::setVisible },
            { "switchPowerOn",             BuildingBinding::switchPowerOn },
            { "togglePublic",              BuildingBinding::togglePublic },
            { 0, 0 }
        };

        registerClass(
            L,
            BuildingBinding::getMetatableName(),
            meta,
            methods,
            BuildingBinding::index,
            BuildingBinding::newindex
        );
    }

} // namespace KenshiLua