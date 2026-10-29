#include "pch.h"
#include "kenshi/AI/AITaskSystem.h"
#include "AITaskSytem_FailedTaskBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

static AITaskSytem::FailedTask* getInstance(lua_State* L, int idx)
{
    return checkObject<AITaskSytem::FailedTask>(L, idx, AITaskSytem_FailedTaskBinding::getMetatableName());
}

// --- Getters for AITaskSytem::FailedTask ---
static int FailedTask_get_subj(lua_State* L)
{
    AITaskSytem::FailedTask* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem_FailedTask is nil");
    return HandBinding::push(L, instance->subj);
}

// --- Setters for AITaskSytem::FailedTask ---
static int FailedTask_set_subj(lua_State* L)
{
    AITaskSytem::FailedTask* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem_FailedTask is nil");
    instance->subj = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

/*
Skipped methods needing manual binding:
  line 265-267: constructors and operator= - no address; only rememberFailedGOAP, which has no address, uses this type
*/

int AITaskSytem_FailedTaskBinding::gc(lua_State* L)
{
    // Borrowed
    return 0;
}

int AITaskSytem_FailedTaskBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AITaskSytem_FailedTask object");
    return 1;
}

void AITaskSytem_FailedTaskBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AITaskSytem_FailedTaskBinding::gc },
        { "__tostring", AITaskSytem_FailedTaskBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L,
        AITaskSytem_FailedTaskBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AITaskSytem_FailedTaskBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "subj", FailedTask_get_subj);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "subj", FailedTask_set_subj);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
