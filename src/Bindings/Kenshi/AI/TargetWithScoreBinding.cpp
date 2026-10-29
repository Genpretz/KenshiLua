#include "pch.h"
// Tasker.h must come before AI.h; see TaskDataBinding.cpp.
#include "kenshi/Tasker.h"
#include "kenshi/AI/AI.h"
#include "TargetWithScoreBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

// Lua owns every TargetWithScore it creates; copies use the exported copy constructor.
static_assert(sizeof(TargetWithScore) == 0x28, "TargetWithScore size does not match the game");
static_assert(offsetof(TargetWithScore, score) == 0x20, "TargetWithScore::score offset does not match the game");

static TargetWithScore* getInstance(lua_State* L, int idx)
{
    return checkObject<TargetWithScore>(L, idx, TargetWithScoreBinding::getMetatableName());
}

// --- Getters for TargetWithScore ---
static int TargetWithScore_get_target(lua_State* L)
{
    TargetWithScore* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetWithScore is nil");
    return HandBinding::push(L, instance->target);
}

static int TargetWithScore_get_score(lua_State* L)
{
    TargetWithScore* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetWithScore is nil");
    lua_pushnumber(L, instance->score);
    return 1;
}

// --- Setters for TargetWithScore ---
static int TargetWithScore_set_target(lua_State* L)
{
    TargetWithScore* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetWithScore is nil");
    instance->target = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int TargetWithScore_set_score(lua_State* L)
{
    TargetWithScore* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetWithScore is nil");
    instance->score = (float)luaL_checknumber(L, 2);
    return 0;
}

// TargetWithScore(const TargetWithScore&) or TargetWithScore(const hand&, float); the SDK has no default constructor.
int TargetWithScoreBinding::constructor(lua_State* L)
{
    int startIdx = lua_istable(L, 1) ? 2 : 1; // Called through the TargetWithScore table's __call
    int numArgs = lua_gettop(L) - startIdx + 1;

    if (numArgs == 1)
    {
        TargetWithScore* other = getInstance(L, startIdx);
        return pushValue<TargetWithScore>(L, *other, TargetWithScoreBinding::getMetatableName());
    }

    hand* t = checkObject<hand>(L, startIdx, HandBinding::getMetatableName());
    float s = (float)luaL_checknumber(L, startIdx + 1);
    TargetWithScore value(*t, s);
    return pushValue<TargetWithScore>(L, value, TargetWithScoreBinding::getMetatableName());
}

// operator=(const TargetWithScore&); returns self.
int TargetWithScoreBinding::operator_assign(lua_State* L)
{
    TargetWithScore* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetWithScore is nil");

    TargetWithScore* other = getInstance(L, 2);
    *instance = *other;
    lua_settop(L, 1);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 31-34: _CONSTRUCTOR(...) - exposed through the TargetWithScore(...) constructor instead
*/

int TargetWithScoreBinding::gc(lua_State* L)
{
    // Lua-created values use the owned metatable's __gc
    return 0;
}

int TargetWithScoreBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TargetWithScore object");
    return 1;
}

void TargetWithScoreBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TargetWithScoreBinding::gc },
        { "__tostring", TargetWithScoreBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "operator_assign", TargetWithScoreBinding::operator_assign },
        { 0, 0 }
    };

    registerClass(
        L,
        TargetWithScoreBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TargetWithScoreBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "target", TargetWithScore_get_target);
    registerGetter(L, "score", TargetWithScore_get_score);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "target", TargetWithScore_set_target);
    registerSetter(L, "score", TargetWithScore_set_score);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    pushGlobalTable(L, "TargetWithScore");
    registerConstructor(L, TargetWithScoreBinding::constructor);
    lua_setglobal(L, "TargetWithScore");
}

} // namespace KenshiLua
