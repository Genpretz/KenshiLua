#include "pch.h"
#include "kenshi\navmesh.h"
#include "MessageQueueBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MessageQueue* getInstance(lua_State* L, int idx)
{
    return checkObject<MessageQueue>(L, idx, MessageQueueBinding::getMetatableName());
}

// --- Getters for MessageQueue ---
static int MessageQueue_get_s(lua_State* L)
{
    MessageQueue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MessageQueue is nil");
    lua_pushinteger(L, instance->s);
    return 1;
}

static int MessageQueue_get_root(lua_State* L)
{
    MessageQueue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MessageQueue is nil");
    lua_pushlightuserdata(L, (void*)instance->root);
    return 1;
}

static int MessageQueue_get_split(lua_State* L)
{
    MessageQueue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MessageQueue is nil");
    lua_pushlightuserdata(L, (void*)instance->split);
    return 1;
}

static int MessageQueue_get_back(lua_State* L)
{
    MessageQueue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MessageQueue is nil");
    lua_pushlightuserdata(L, (void*)instance->back);
    return 1;
}

static int MessageQueue_get_mutex(lua_State* L)
{
    MessageQueue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MessageQueue is nil");
    lua_pushinteger(L, (lua_Integer)instance->mutex);
    return 1;
}

// --- Setters for MessageQueue ---
static int MessageQueue_set_s(lua_State* L)
{
    MessageQueue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MessageQueue is nil");
    instance->s = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int MessageQueue_set_mutex(lua_State* L)
{
    MessageQueue* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MessageQueue is nil");
    instance->mutex = (boost::shared_mutex)luaL_checkinteger(L, 2);
    return 0;
}



/*
LIGHTUSERDATA DEPENDENCIES:
  - MessageQueue_get_root: MessageQueue<T>::Node* (unbound pointer)
  - MessageQueue_get_split: MessageQueue<T>::Node* (unbound pointer)
  - MessageQueue_get_back: MessageQueue<T>::Node* (unbound pointer)
*/

int MessageQueueBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MessageQueueBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MessageQueue object");
    return 1;
}

void MessageQueueBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MessageQueueBinding::gc },
        { "__tostring", MessageQueueBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        MessageQueueBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MessageQueueBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "s", MessageQueue_get_s);
    registerGetter(L, "root", MessageQueue_get_root);
    registerGetter(L, "split", MessageQueue_get_split);
    registerGetter(L, "back", MessageQueue_get_back);
    registerGetter(L, "mutex", MessageQueue_get_mutex);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "s", MessageQueue_set_s);
    registerSetter(L, "mutex", MessageQueue_set_mutex);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua