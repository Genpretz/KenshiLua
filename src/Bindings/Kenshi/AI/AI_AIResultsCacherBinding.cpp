#include "pch.h"
#include "Lua/Containers/CommonTypes.h"
// Tasker.h must come before AI.h; see TaskDataBinding.cpp.
#include "kenshi/Tasker.h"
#include "kenshi/AI/AI.h"
#include "kenshi/AI/AITaskSystem.h"
#include "AI_AIResultsCacherBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/AI/AIBinding.h"
#include "Bindings/Kenshi/AI/TaskMatchBinding.h"
#include "Bindings/Kenshi/Building/StorageBuildingBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/StdMapBinding.h"

namespace KenshiLua
{

// AI embeds this cache at 0x208; the map offsets catch std::map size drift.
static_assert(offsetof(AI::AIResultsCacher, requirementsCache) == 0x30, "AI::AIResultsCacher::requirementsCache offset does not match the game");
static_assert(offsetof(AI::AIResultsCacher, resourceSourceCache) == 0x80, "AI::AIResultsCacher::resourceSourceCache offset does not match the game");

typedef StdMapBinding<TaskMatch, bool> TaskMatchBoolMapBinding;
// resourceSourceCache uses std::allocator rather than the Ogre allocator. Hand values are copied
// through LuaCodec<hand>; a value metatable would push borrowed hands.
typedef Containers::GameDataHandMapBinding GameDataHandMapBinding;

static AI::AIResultsCacher* getInstance(lua_State* L, int idx)
{
    return checkObject<AI::AIResultsCacher>(L, idx, AI_AIResultsCacherBinding::getMetatableName());
}

// --- Getters for AI::AIResultsCacher ---
static int AIResultsCacher_get_ai(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");
    return pushObject<AI>(L, instance->ai, AIBinding::getMetatableName());
}

static int AIResultsCacher_get_requirementsCache(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");
    return pushObject<TaskMatchBoolMapBinding::MapType>(L, &instance->requirementsCache, TaskMatchBoolMapBinding::getMetatableName());
}

static int AIResultsCacher_get_resultsCache(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");
    return pushObject<TaskMatchBoolMapBinding::MapType>(L, &instance->resultsCache, TaskMatchBoolMapBinding::getMetatableName());
}

static int AIResultsCacher_get_resourceSourceCache(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");
    return pushObject<GameDataHandMapBinding::MapType>(L, &instance->resourceSourceCache, GameDataHandMapBinding::getMetatableName());
}

// --- Setters for AI::AIResultsCacher ---
// getResourceSource calls the owning AI without a null check.
static int AIResultsCacher_set_ai(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");
    instance->ai = checkObject<AI>(L, 2, AIBinding::getMetatableName());
    return 0;
}

int AI_AIResultsCacherBinding::resetAllCaches(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");

    instance->resetAllCaches();
    return 0;
}

int AI_AIResultsCacherBinding::cacheResult_reqs(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");

    TaskMatch* key = checkObject<TaskMatch>(L, 2, TaskMatchBinding::getMetatableName());
    bool b = lua_toboolean(L, 3) != 0;
    instance->cacheResult_reqs(*key, b);
    return 0;
}

int AI_AIResultsCacherBinding::getCacheResult_reqs(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");

    TaskMatch* key = checkObject<TaskMatch>(L, 2, TaskMatchBinding::getMetatableName());
    bool result = instance->getCacheResult_reqs(*key);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AI_AIResultsCacherBinding::hasCacheResult_reqs(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");

    TaskMatch* key = checkObject<TaskMatch>(L, 2, TaskMatchBinding::getMetatableName());
    bool result = instance->hasCacheResult_reqs(*key);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AI_AIResultsCacherBinding::cacheResult_results(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");

    TaskMatch* key = checkObject<TaskMatch>(L, 2, TaskMatchBinding::getMetatableName());
    bool b = lua_toboolean(L, 3) != 0;
    instance->cacheResult_results(*key, b);
    return 0;
}

int AI_AIResultsCacherBinding::getCacheResult_results(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");

    TaskMatch* key = checkObject<TaskMatch>(L, 2, TaskMatchBinding::getMetatableName());
    bool result = instance->getCacheResult_results(*key);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AI_AIResultsCacherBinding::hasCacheResult_results(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");

    TaskMatch* key = checkObject<TaskMatch>(L, 2, TaskMatchBinding::getMetatableName());
    bool result = instance->hasCacheResult_results(*key);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AI_AIResultsCacherBinding::resetSpecificTargetFinderCache(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");

    TaskMatch* key = checkObject<TaskMatch>(L, 2, TaskMatchBinding::getMetatableName());
    instance->resetSpecificTargetFinderCache(*key);
    return 0;
}

// buildingFound is an out-parameter and is returned after the score. skip may be nil; the engine checks it.
// The engine writes buildingFound only when it finds a source, and hand() leaves the serials
// uninitialized, so the out-parameter starts as the null hand the engine caches for no source.
int AI_AIResultsCacherBinding::getResourceSource(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");

    GameData* resourceNeeded = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    StorageBuilding* skip = lua_isnoneornil(L, 3) ? nullptr : checkObject<StorageBuilding>(L, 3, StorageBuildingBinding::getMetatableName());
    hand buildingFound(0, 0, NULL_ITEM, 0, 0);
    float result = instance->getResourceSource(buildingFound, resourceNeeded, skip);
    lua_pushnumber(L, result);
    HandBinding::push(L, buildingFound);
    return 2;
}

int AI_AIResultsCacherBinding::cacheResult_targetFinder(lua_State* L)
{
    AI::AIResultsCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AI_AIResultsCacher is nil");

    TaskMatch* key = checkObject<TaskMatch>(L, 2, TaskMatchBinding::getMetatableName());
    hand* sub = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    float score = (float)luaL_checknumber(L, 4);
    instance->cacheResult_targetFinder(*key, *sub, score);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 122-123: AIResultsCacher(AI*), _CONSTRUCTOR - embedded in AI
  line 131: runTargetFinder(...) - takes an AI member-function pointer
  line 139-140: ~AIResultsCacher, _DESTRUCTOR - embedded in AI

Skipped properties needing manual binding:
  line 135: targetFindersCache (std::map<TaskMatch, TargetWithScore, ...>) - StdMapBinding default-constructs its values, and TargetWithScore has no default constructor

Read-only properties:
  requirementsCache, resultsCache, resourceSourceCache - containers are edited in place; whole-container assignment is not bound
*/

int AI_AIResultsCacherBinding::gc(lua_State* L)
{
    // Borrowed from the owning AI
    return 0;
}

int AI_AIResultsCacherBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AI_AIResultsCacher object");
    return 1;
}

void AI_AIResultsCacherBinding::registerBinding(lua_State* L)
{

    static const luaL_Reg meta[] = {
        { "__gc",       AI_AIResultsCacherBinding::gc },
        { "__tostring", AI_AIResultsCacherBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "resetAllCaches", AI_AIResultsCacherBinding::resetAllCaches },
        { "cacheResult_reqs", AI_AIResultsCacherBinding::cacheResult_reqs },
        { "getCacheResult_reqs", AI_AIResultsCacherBinding::getCacheResult_reqs },
        { "hasCacheResult_reqs", AI_AIResultsCacherBinding::hasCacheResult_reqs },
        { "cacheResult_results", AI_AIResultsCacherBinding::cacheResult_results },
        { "getCacheResult_results", AI_AIResultsCacherBinding::getCacheResult_results },
        { "hasCacheResult_results", AI_AIResultsCacherBinding::hasCacheResult_results },
        { "resetSpecificTargetFinderCache", AI_AIResultsCacherBinding::resetSpecificTargetFinderCache },
        { "getResourceSource", AI_AIResultsCacherBinding::getResourceSource },
        { "cacheResult_targetFinder", AI_AIResultsCacherBinding::cacheResult_targetFinder },
        { 0, 0 }
    };

    registerClass(
        L,
        AI_AIResultsCacherBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AI_AIResultsCacherBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "ai", AIResultsCacher_get_ai);
    registerGetter(L, "requirementsCache", AIResultsCacher_get_requirementsCache);
    registerGetter(L, "resultsCache", AIResultsCacher_get_resultsCache);
    registerGetter(L, "resourceSourceCache", AIResultsCacher_get_resourceSourceCache);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "ai", AIResultsCacher_set_ai);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
