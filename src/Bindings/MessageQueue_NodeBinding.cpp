#include "pch.h"
#include "Bindings/MessageQueue_NodeBinding.h"
#include "Lua/BindingHelpers.h"

typedef MessageQueue<void*>::Node MessageQueue_Node;

namespace KenshiLua
{

static MessageQueue_Node* getInstance(lua_State* L, int idx)
{
    return checkObject<MessageQueue_Node>(L, idx, MessageQueue_NodeBinding::getMetatableName());
}

static int Node_get_value(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "MessageQueue::Node is nil");
    if (inst->value) lua_pushlightuserdata(L, inst->value);
    else lua_pushnil(L);
    return 1;
}

static int Node_get_next(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "MessageQueue::Node is nil");
    return pushObject<MessageQueue_Node>(L, inst->next, MessageQueue_NodeBinding::getMetatableName());
}

static int Node_set_value(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "MessageQueue::Node is nil");
    inst->value = lua_touserdata(L, 2);
    return 0;
}

static int Node_set_next(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "MessageQueue::Node is nil");
    inst->next = lua_isnoneornil(L, 2) ? nullptr : checkObject<MessageQueue_Node>(L, 2, MessageQueue_NodeBinding::getMetatableName());
    return 0;
}

int MessageQueue_NodeBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (MessageQueue_Node*)::operator new(sizeof(MessageQueue_Node));
    ::new ((void*)obj) MessageQueue_Node();
    return pushObject<MessageQueue_Node>(L, obj, getMetatableName());
}

int MessageQueue_NodeBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "MessageQueue::Node is nil");
    inst->~Node();
    return 0;
}

int MessageQueue_NodeBinding::gc(lua_State* L)
{
    return 0;
}

int MessageQueue_NodeBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MessageQueue_Node object");
    return 1;
}

int MessageQueue_NodeBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void MessageQueue_NodeBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", _CONSTRUCTOR },
        { "_DESTRUCTOR",  _DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "value", Node_get_value);
    registerGetter(L, "next", Node_get_next);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "value", Node_set_value);
    registerSetter(L, "next", Node_set_next);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
