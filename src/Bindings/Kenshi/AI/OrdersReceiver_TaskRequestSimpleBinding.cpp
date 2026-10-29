#include "pch.h"
#include "kenshi/Tasker.h"
#include "kenshi/AI/AITaskSystem.h"
#include "OrdersReceiver_TaskRequestSimpleBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/TaskerBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

static_assert(offsetof(OrdersReceiver::TaskRequestSimple, targeting) == 0x28, "OrdersReceiver::TaskRequestSimple::targeting offset does not match the game");

static OrdersReceiver::TaskRequestSimple* getInstance(lua_State* L, int idx)
{
    return checkObject<OrdersReceiver::TaskRequestSimple>(L, idx, OrdersReceiver_TaskRequestSimpleBinding::getMetatableName());
}

// --- Getters for OrdersReceiver::TaskRequestSimple ---
static int TaskRequestSimple_get_key(lua_State* L)
{
    OrdersReceiver::TaskRequestSimple* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver_TaskRequestSimple is nil");
    lua_pushinteger(L, (lua_Integer)instance->key);
    return 1;
}

static int TaskRequestSimple_get_subject(lua_State* L)
{
    OrdersReceiver::TaskRequestSimple* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver_TaskRequestSimple is nil");
    return HandBinding::push(L, instance->subject);
}

static int TaskRequestSimple_get_targeting(lua_State* L)
{
    OrdersReceiver::TaskRequestSimple* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver_TaskRequestSimple is nil");
    lua_pushinteger(L, (lua_Integer)instance->targeting);
    return 1;
}

// --- Setters for OrdersReceiver::TaskRequestSimple ---
static int TaskRequestSimple_set_key(lua_State* L)
{
    OrdersReceiver::TaskRequestSimple* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver_TaskRequestSimple is nil");
    instance->key = (TaskType)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskRequestSimple_set_subject(lua_State* L)
{
    OrdersReceiver::TaskRequestSimple* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver_TaskRequestSimple is nil");
    instance->subject = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int TaskRequestSimple_set_targeting(lua_State* L)
{
    OrdersReceiver::TaskRequestSimple* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver_TaskRequestSimple is nil");
    instance->targeting = (TaskTargetType)luaL_checkinteger(L, 2);
    return 0;
}

int OrdersReceiver_TaskRequestSimpleBinding::sameAs(lua_State* L)
{
    OrdersReceiver::TaskRequestSimple* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver_TaskRequestSimple is nil");

    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    bool result = instance->sameAs(t);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 147-149: constructors and operator= - no address; the engine creates these through addSlaveJob, which also has no address
*/

int OrdersReceiver_TaskRequestSimpleBinding::gc(lua_State* L)
{
    // Borrowed from OrdersReceiver::slaveJobs
    return 0;
}

int OrdersReceiver_TaskRequestSimpleBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.OrdersReceiver_TaskRequestSimple object");
    return 1;
}

void OrdersReceiver_TaskRequestSimpleBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       OrdersReceiver_TaskRequestSimpleBinding::gc },
        { "__tostring", OrdersReceiver_TaskRequestSimpleBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "sameAs", OrdersReceiver_TaskRequestSimpleBinding::sameAs },
        { 0, 0 }
    };

    registerClass(
        L,
        OrdersReceiver_TaskRequestSimpleBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, OrdersReceiver_TaskRequestSimpleBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "key", TaskRequestSimple_get_key);
    registerGetter(L, "subject", TaskRequestSimple_get_subject);
    registerGetter(L, "targeting", TaskRequestSimple_get_targeting);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "key", TaskRequestSimple_set_key);
    registerSetter(L, "subject", TaskRequestSimple_set_subject);
    registerSetter(L, "targeting", TaskRequestSimple_set_targeting);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
