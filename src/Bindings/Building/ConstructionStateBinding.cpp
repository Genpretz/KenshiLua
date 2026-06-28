#include "pch.h"
#include <kenshi/Building/Building.h>
#include "ConstructionStateBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef Building::ConstructionState ConstructionState;

static ConstructionState* getInstance(lua_State* L, int idx)
{
    return checkObject<ConstructionState>(L, idx, ConstructionStateBinding::getMetatableName());
}

// --- Getters for ConstructionState ---
static int ConstructionState_get_isComplete(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    lua_pushboolean(L, instance->isComplete ? 1 : 0);
    return 1;
}

static int ConstructionState_get_isPaused(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    lua_pushboolean(L, instance->isPaused ? 1 : 0);
    return 1;
}

static int ConstructionState_get_isDismantled(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    lua_pushboolean(L, instance->isDismantled ? 1 : 0);
    return 1;
}

static int ConstructionState_get_constructionProgress(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    lua_pushnumber(L, instance->constructionProgress);
    return 1;
}

static int ConstructionState_get_msgDismantleAmount(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    lua_pushnumber(L, instance->msgDismantleAmount);
    return 1;
}

static int ConstructionState_get_mats(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    // TODO: Unsupported type for mats (lektor<ConstructionState::BuildMaterial*>)
    return luaL_error(L, "Unsupported property 'mats' (type: lektor<ConstructionState::BuildMaterial*>)");
}

static int ConstructionState_get_totalMats(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    lua_pushnumber(L, instance->totalMats);
    return 1;
}

static int ConstructionState_get_buildTimeMult(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    lua_pushnumber(L, instance->buildTimeMult);
    return 1;
}

static int ConstructionState_get_buildersThisFrame(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    lua_pushinteger(L, instance->buildersThisFrame);
    return 1;
}

static int ConstructionState_get_pathThreshold(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    lua_pushnumber(L, instance->pathThreshold);
    return 1;
}

// --- Setters for ConstructionState ---
static int ConstructionState_set_isComplete(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    instance->isComplete = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ConstructionState_set_isPaused(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    instance->isPaused = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ConstructionState_set_isDismantled(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    instance->isDismantled = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ConstructionState_set_constructionProgress(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    instance->constructionProgress = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ConstructionState_set_msgDismantleAmount(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    instance->msgDismantleAmount = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ConstructionState_set_mats(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    return luaL_error(L, "Read-only or unsupported setter type for mats");
}

static int ConstructionState_set_totalMats(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    instance->totalMats = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ConstructionState_set_buildTimeMult(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    instance->buildTimeMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ConstructionState_set_buildersThisFrame(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    instance->buildersThisFrame = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ConstructionState_set_pathThreshold(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");
    instance->pathThreshold = (float)luaL_checknumber(L, 2);
    return 0;
}

int ConstructionStateBinding::_DESTRUCTOR(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ConstructionStateBinding::materialsEmpty(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");

    bool result = instance->materialsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ConstructionStateBinding::isOverThreshold(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");

    bool result = instance->isOverThreshold();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ConstructionStateBinding::getHealthBarProgress(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");

    float result = instance->getHealthBarProgress();
    lua_pushnumber(L, result);
    return 1;
}

int ConstructionStateBinding::getConstructionMaterialProgress(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");

    float result = instance->getConstructionMaterialProgress();
    lua_pushnumber(L, result);
    return 1;
}

int ConstructionStateBinding::getHealthBarActual(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");

    std::string result = instance->getHealthBarActual();
    lua_pushstring(L, result.c_str());
    return 1;
}

int ConstructionStateBinding::getTotalMats(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");

    float result = instance->getTotalMats();
    lua_pushnumber(L, result);
    return 1;
}

int ConstructionStateBinding::getTotalMatsPresent(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");

    float result = instance->getTotalMatsPresent();
    lua_pushnumber(L, result);
    return 1;
}

int ConstructionStateBinding::needMats(lua_State* L)
{
    ConstructionState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConstructionState is nil");

    bool result = instance->needMats();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 101: ConstructionState* _CONSTRUCTOR(...) - overloaded method
  line 103: ConstructionState* _CONSTRUCTOR(...) - overloaded method
  line 106: void addMaterials(...) - unsupported arg type
  line 126: ConstructionState::BuildMaterial* getMaterial(...) - unsupported arg type
  line 127: void setup(...) - unsupported arg type
  line 130: void getNeededMats(...) - unsupported arg type
  line 131: int needsMat(...) - unsupported arg type
  line 133: float getBuildingSpeedMultiplier(...) - static method
  line 134: float getBuildingTimeInHours(...) - static method
*/

int ConstructionStateBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ConstructionStateBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ConstructionState object");
    return 1;
}

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

    registerClass(
        L, 
        ConstructionStateBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ConstructionStateBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ConstructionState_get_isComplete);
    lua_setfield(L, -2, "isComplete");
    lua_pushcfunction(L, ConstructionState_get_isPaused);
    lua_setfield(L, -2, "isPaused");
    lua_pushcfunction(L, ConstructionState_get_isDismantled);
    lua_setfield(L, -2, "isDismantled");
    lua_pushcfunction(L, ConstructionState_get_constructionProgress);
    lua_setfield(L, -2, "constructionProgress");
    lua_pushcfunction(L, ConstructionState_get_msgDismantleAmount);
    lua_setfield(L, -2, "msgDismantleAmount");
    lua_pushcfunction(L, ConstructionState_get_mats);
    lua_setfield(L, -2, "mats");
    lua_pushcfunction(L, ConstructionState_get_totalMats);
    lua_setfield(L, -2, "totalMats");
    lua_pushcfunction(L, ConstructionState_get_buildTimeMult);
    lua_setfield(L, -2, "buildTimeMult");
    lua_pushcfunction(L, ConstructionState_get_buildersThisFrame);
    lua_setfield(L, -2, "buildersThisFrame");
    lua_pushcfunction(L, ConstructionState_get_pathThreshold);
    lua_setfield(L, -2, "pathThreshold");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ConstructionState_set_isComplete);
    lua_setfield(L, -2, "isComplete");
    lua_pushcfunction(L, ConstructionState_set_isPaused);
    lua_setfield(L, -2, "isPaused");
    lua_pushcfunction(L, ConstructionState_set_isDismantled);
    lua_setfield(L, -2, "isDismantled");
    lua_pushcfunction(L, ConstructionState_set_constructionProgress);
    lua_setfield(L, -2, "constructionProgress");
    lua_pushcfunction(L, ConstructionState_set_msgDismantleAmount);
    lua_setfield(L, -2, "msgDismantleAmount");
    lua_pushcfunction(L, ConstructionState_set_mats);
    lua_setfield(L, -2, "mats");
    lua_pushcfunction(L, ConstructionState_set_totalMats);
    lua_setfield(L, -2, "totalMats");
    lua_pushcfunction(L, ConstructionState_set_buildTimeMult);
    lua_setfield(L, -2, "buildTimeMult");
    lua_pushcfunction(L, ConstructionState_set_buildersThisFrame);
    lua_setfield(L, -2, "buildersThisFrame");
    lua_pushcfunction(L, ConstructionState_set_pathThreshold);
    lua_setfield(L, -2, "pathThreshold");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // // // // // setMetatableParent(L, ConstructionStateBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}
}