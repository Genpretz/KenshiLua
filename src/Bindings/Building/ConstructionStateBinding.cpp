#include "pch.h"
#include "Bindings/Building/ConstructionStateBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/Building.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static Building::ConstructionState* getB(lua_State* L, int idx)
{
    return checkObject<Building::ConstructionState>(L, idx, ConstructionStateBinding::getMetatableName());
}

int ConstructionStateBinding::gc(lua_State* L) { return noopGc(L); }

int ConstructionStateBinding::tostring(lua_State* L)
{
    Building::ConstructionState* b = getB(L, 1);
    return genericTostringPtr(L, "%s", b);
}

int ConstructionStateBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, ConstructionStateBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    Building::ConstructionState* b = getB(L, 1);
    if (!b) { lua_pushnil(L); return 1; }

    if (strcmp(key, "isComplete") == 0) { lua_pushboolean(L, b->isComplete ? 1 : 0); return 1; }
    if (strcmp(key, "isPaused") == 0) { lua_pushboolean(L, b->isPaused ? 1 : 0); return 1; }
    if (strcmp(key, "isDismantled") == 0) { lua_pushboolean(L, b->isDismantled ? 1 : 0); return 1; }
    if (strcmp(key, "constructionProgress") == 0) { lua_pushnumber(L, b->constructionProgress); return 1; }
    if (strcmp(key, "msgDismantleAmount") == 0) { lua_pushnumber(L, b->msgDismantleAmount); return 1; }
    // TODO lektor<ConstructionState::BuildMaterial*> mats; unsupported __index type from header line 135
    if (strcmp(key, "totalMats") == 0) { lua_pushnumber(L, b->totalMats); return 1; }
    if (strcmp(key, "buildTimeMult") == 0) { lua_pushnumber(L, b->buildTimeMult); return 1; }
    if (strcmp(key, "buildersThisFrame") == 0) { lua_pushinteger(L, b->buildersThisFrame); return 1; }
    if (strcmp(key, "pathThreshold") == 0) { lua_pushnumber(L, b->pathThreshold); return 1; }

    lua_pushnil(L);
    return 1;
}

int ConstructionStateBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    Building::ConstructionState* b = getB(L, 1);
    if (!b) return luaL_error(L, "ConstructionState is nil");

    if (strcmp(key, "isComplete") == 0) { b->isComplete = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "isPaused") == 0) { b->isPaused = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "isDismantled") == 0) { b->isDismantled = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "constructionProgress") == 0) { b->constructionProgress = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "msgDismantleAmount") == 0) { b->msgDismantleAmount = (float)luaL_checknumber(L, 3); return 0; }
    // TODO lektor<ConstructionState::BuildMaterial*> mats; unsupported __newindex type from header line 135
    if (strcmp(key, "totalMats") == 0) { b->totalMats = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "buildTimeMult") == 0) { b->buildTimeMult = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "buildersThisFrame") == 0) { b->buildersThisFrame = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "pathThreshold") == 0) { b->pathThreshold = (float)luaL_checknumber(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int ConstructionStateBinding::_DESTRUCTOR(lua_State* L)
{
    Building::ConstructionState* b = getB(L, 1);
    if (!b) return luaL_error(L, "ConstructionState is nil");

    b->_DESTRUCTOR();
    return 0;
}

int ConstructionStateBinding::materialsEmpty(lua_State* L)
{
    Building::ConstructionState* b = getB(L, 1);
    if (!b) return luaL_error(L, "ConstructionState is nil");

    bool result = b->materialsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ConstructionStateBinding::isOverThreshold(lua_State* L)
{
    Building::ConstructionState* b = getB(L, 1);
    if (!b) return luaL_error(L, "ConstructionState is nil");

    bool result = b->isOverThreshold();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ConstructionStateBinding::getHealthBarProgress(lua_State* L)
{
    Building::ConstructionState* b = getB(L, 1);
    if (!b) return luaL_error(L, "ConstructionState is nil");

    float result = b->getHealthBarProgress();
    lua_pushnumber(L, result);
    return 1;
}

int ConstructionStateBinding::getConstructionMaterialProgress(lua_State* L)
{
    Building::ConstructionState* b = getB(L, 1);
    if (!b) return luaL_error(L, "ConstructionState is nil");

    float result = b->getConstructionMaterialProgress();
    lua_pushnumber(L, result);
    return 1;
}

int ConstructionStateBinding::getHealthBarActual(lua_State* L)
{
    Building::ConstructionState* b = getB(L, 1);
    if (!b) return luaL_error(L, "ConstructionState is nil");

    std::string result = b->getHealthBarActual();
    lua_pushstring(L, result.c_str());
    return 1;
}

int ConstructionStateBinding::getTotalMats(lua_State* L)
{
    Building::ConstructionState* b = getB(L, 1);
    if (!b) return luaL_error(L, "ConstructionState is nil");

    float result = b->getTotalMats();
    lua_pushnumber(L, result);
    return 1;
}

int ConstructionStateBinding::getTotalMatsPresent(lua_State* L)
{
    Building::ConstructionState* b = getB(L, 1);
    if (!b) return luaL_error(L, "ConstructionState is nil");

    float result = b->getTotalMatsPresent();
    lua_pushnumber(L, result);
    return 1;
}

int ConstructionStateBinding::needMats(lua_State* L)
{
    Building::ConstructionState* b = getB(L, 1);
    if (!b) return luaL_error(L, "ConstructionState is nil");

    bool result = b->needMats();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 101: Building::ConstructionState* _CONSTRUCTOR(...) - overloaded method
  line 103: Building::ConstructionState* _CONSTRUCTOR(...) - overloaded method
  line 106: void addMaterials(...) - unsupported arg type
  line 126: ConstructionState::BuildMaterial* getMaterial(...) - unsupported arg type
  line 127: void setup(...) - unsupported arg type
  line 130: void getNeededMats(...) - unsupported arg type
  line 131: int needsMat(...) - unsupported arg type
  line 133: float getBuildingSpeedMultiplier(...) - static method
  line 134: float getBuildingTimeInHours(...) - static method
*/

void ConstructionStateBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ConstructionStateBinding::gc },
        { "__tostring", ConstructionStateBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ConstructionStateBinding::_DESTRUCTOR },
        { "materialsEmpty", ConstructionStateBinding::materialsEmpty },
        { "isOverThreshold", ConstructionStateBinding::isOverThreshold },
        { "getHealthBarProgress", ConstructionStateBinding::getHealthBarProgress },
        { "getConstructionMaterialProgress", ConstructionStateBinding::getConstructionMaterialProgress },
        { "getHealthBarActual", ConstructionStateBinding::getHealthBarActual },
        { "getTotalMats", ConstructionStateBinding::getTotalMats },
        { "getTotalMatsPresent", ConstructionStateBinding::getTotalMatsPresent },
        { "needMats", ConstructionStateBinding::needMats },
        { 0, 0 }
    };
    registerClass(L, ConstructionStateBinding::getMetatableName(), meta, methods, ConstructionStateBinding::index, ConstructionStateBinding::newindex);
}

} // namespace KenshiLua