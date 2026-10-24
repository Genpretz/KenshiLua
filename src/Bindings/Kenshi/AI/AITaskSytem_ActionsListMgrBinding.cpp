#include "pch.h"
#include "kenshi/Tasker.h"
#include "kenshi/AI/AITaskSystem.h"
#include "AITaskSytem_ActionsListMgrBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/TaskerBinding.h"

namespace KenshiLua
{

static AITaskSytem::ActionsListMgr* getInstance(lua_State* L, int idx)
{
    return checkObject<AITaskSytem::ActionsListMgr>(L, idx, AITaskSytem_ActionsListMgrBinding::getMetatableName());
}

int AITaskSytem_ActionsListMgrBinding::copyFrom(lua_State* L)
{
    AITaskSytem::ActionsListMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem_ActionsListMgr is nil");

    AITaskSytem::ActionsListMgr* a = getInstance(L, 2);
    instance->copyFrom(a);
    return 0;
}

int AITaskSytem_ActionsListMgrBinding::addFrom(lua_State* L)
{
    AITaskSytem::ActionsListMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem_ActionsListMgr is nil");

    AITaskSytem::ActionsListMgr* a = getInstance(L, 2);
    instance->addFrom(a);
    return 0;
}

int AITaskSytem_ActionsListMgrBinding::getTaskAfterCurrent(lua_State* L)
{
    AITaskSytem::ActionsListMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem_ActionsListMgr is nil");

    Tasker* result = instance->getTaskAfterCurrent();
    return pushObject<Tasker>(L, result, TaskerBinding::getMetatableName());
}

int AITaskSytem_ActionsListMgrBinding::get2TasksAfterCurrent(lua_State* L)
{
    AITaskSytem::ActionsListMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem_ActionsListMgr is nil");

    Tasker* result = instance->get2TasksAfterCurrent();
    return pushObject<Tasker>(L, result, TaskerBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 301-304: ActionsListMgr(), _CONSTRUCTOR, ~ActionsListMgr, _DESTRUCTOR - embedded in AITaskSytem
*/

int AITaskSytem_ActionsListMgrBinding::gc(lua_State* L)
{
    // Borrowed from the owning AITaskSytem
    return 0;
}

int AITaskSytem_ActionsListMgrBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AITaskSytem_ActionsListMgr object");
    return 1;
}

void AITaskSytem_ActionsListMgrBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AITaskSytem_ActionsListMgrBinding::gc },
        { "__tostring", AITaskSytem_ActionsListMgrBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "copyFrom", AITaskSytem_ActionsListMgrBinding::copyFrom },
        { "addFrom", AITaskSytem_ActionsListMgrBinding::addFrom },
        { "getTaskAfterCurrent", AITaskSytem_ActionsListMgrBinding::getTaskAfterCurrent },
        { "get2TasksAfterCurrent", AITaskSytem_ActionsListMgrBinding::get2TasksAfterCurrent },
        { 0, 0 }
    };

    registerClass(
        L,
        AITaskSytem_ActionsListMgrBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AITaskSytem_ActionsListMgrBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
