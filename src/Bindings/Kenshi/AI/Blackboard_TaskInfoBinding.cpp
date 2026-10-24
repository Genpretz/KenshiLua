#include "pch.h"
// Tasker.h must come before AI.h; see TaskDataBinding.cpp.
#include "kenshi/Tasker.h"
#include "kenshi/AI/Blackboard.h"
#include "Blackboard_TaskInfoBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

// Lua-created values are copied with the implicit copy constructor, which the game inlines.
static_assert(sizeof(Blackboard::TaskInfo) == 0x48, "Blackboard::TaskInfo size does not match the game");
static_assert(offsetof(Blackboard::TaskInfo, subTarget) == 0x28, "Blackboard::TaskInfo::subTarget offset does not match the game");

static Blackboard::TaskInfo* getInstance(lua_State* L, int idx)
{
    return checkObject<Blackboard::TaskInfo>(L, idx, Blackboard_TaskInfoBinding::getMetatableName());
}

// --- Getters for Blackboard::TaskInfo ---
static int TaskInfo_get_type(lua_State* L)
{
    Blackboard::TaskInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard_TaskInfo is nil");
    lua_pushinteger(L, (lua_Integer)instance->type);
    return 1;
}

static int TaskInfo_get_subject(lua_State* L)
{
    Blackboard::TaskInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard_TaskInfo is nil");
    return HandBinding::push(L, instance->subject);
}

static int TaskInfo_get_subTarget(lua_State* L)
{
    Blackboard::TaskInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard_TaskInfo is nil");
    return HandBinding::push(L, instance->subTarget);
}

// --- Setters for Blackboard::TaskInfo ---
static int TaskInfo_set_type(lua_State* L)
{
    Blackboard::TaskInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard_TaskInfo is nil");
    instance->type = (TaskType)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskInfo_set_subject(lua_State* L)
{
    Blackboard::TaskInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard_TaskInfo is nil");
    instance->subject = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int TaskInfo_set_subTarget(lua_State* L)
{
    Blackboard::TaskInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard_TaskInfo is nil");
    instance->subTarget = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

// TaskInfo() or a copy of another TaskInfo.
int Blackboard_TaskInfoBinding::constructor(lua_State* L)
{
    int startIdx = lua_istable(L, 1) ? 2 : 1; // Called through the Blackboard_TaskInfo table's __call
    int numArgs = lua_gettop(L) - startIdx + 1;

    if (numArgs <= 0)
    {
        Blackboard::TaskInfo value;
        return pushValue<Blackboard::TaskInfo>(L, value, Blackboard_TaskInfoBinding::getMetatableName());
    }
    Blackboard::TaskInfo* other = getInstance(L, startIdx);
    return pushValue<Blackboard::TaskInfo>(L, *other, Blackboard_TaskInfoBinding::getMetatableName());
}

// operator=(const Blackboard::TaskInfo&); returns self.
int Blackboard_TaskInfoBinding::operator_assign(lua_State* L)
{
    Blackboard::TaskInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Blackboard_TaskInfo is nil");

    Blackboard::TaskInfo* other = getInstance(L, 2);
    *instance = *other;
    lua_settop(L, 1);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 174: _CONSTRUCTOR() - exposed through the Blackboard_TaskInfo(...) constructor instead
*/

int Blackboard_TaskInfoBinding::gc(lua_State* L)
{
    // Lua-created values use the owned metatable's __gc; others are borrowed from Blackboard::currentTasks
    return 0;
}

int Blackboard_TaskInfoBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Blackboard_TaskInfo object");
    return 1;
}

void Blackboard_TaskInfoBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       Blackboard_TaskInfoBinding::gc },
        { "__tostring", Blackboard_TaskInfoBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "operator_assign", Blackboard_TaskInfoBinding::operator_assign },
        { 0, 0 }
    };

    registerClass(
        L,
        Blackboard_TaskInfoBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, Blackboard_TaskInfoBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "type", TaskInfo_get_type);
    registerGetter(L, "subject", TaskInfo_get_subject);
    registerGetter(L, "subTarget", TaskInfo_get_subTarget);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "type", TaskInfo_set_type);
    registerSetter(L, "subject", TaskInfo_set_subject);
    registerSetter(L, "subTarget", TaskInfo_set_subTarget);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    pushGlobalTable(L, "Blackboard_TaskInfo");
    registerConstructor(L, Blackboard_TaskInfoBinding::constructor);
    lua_setglobal(L, "Blackboard_TaskInfo");
}

} // namespace KenshiLua
