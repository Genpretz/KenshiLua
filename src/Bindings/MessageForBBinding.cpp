#include "pch.h"
#include "kenshi/Enums.h"
#include "Bindings/MessageForBBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MessageForB* getInstance(lua_State* L, int idx)
{
    return checkObject<MessageForB>(L, idx, MessageForBBinding::getMetatableName());
}

// --- Getters for MessageForB ---

static int MessageForB_get_messageType(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "MessageForB is nil");

    lua_pushinteger(L, (lua_Integer)inst->messageType);
    return 1;
}

static int MessageForB_get_messageInt(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "MessageForB is nil");

    lua_pushinteger(L, inst->messageInt);
    return 1;
}

// --- Setters for MessageForB ---

static int MessageForB_set_messageType(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "MessageForB is nil");

    inst->messageType = (MessageForB::MessageType)luaL_checkinteger(L, 2);
    return 0;
}

static int MessageForB_set_messageInt(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "MessageForB is nil");

    inst->messageInt = (int)luaL_checkinteger(L, 2);
    return 0;
}

int MessageForBBinding::create(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    int top = lua_gettop(L);

    MessageForB msg;
    msg.messageType = MessageForB::M_UNSELECT_ALL;
    msg.messageInt = 0;

    if (top >= idx)
    {
        msg.messageType = (MessageForB::MessageType)luaL_checkinteger(L, idx);
        if (top >= idx + 1)
        {
            msg.messageInt = (int)luaL_checkinteger(L, idx + 1);
        }
    }

    return pushValue<MessageForB>(L, msg, MessageForBBinding::getMetatableName());
}

int MessageForBBinding::gc(lua_State* L)
{
    return 0;
}

int MessageForBBinding::tostring(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (inst)
    {
        lua_pushfstring(L, "KenshiLua.MessageForB(type=%d, int=%d)", (int)inst->messageType, inst->messageInt);
    }
    else
    {
        lua_pushstring(L, "KenshiLua.MessageForB object");
    }
    return 1;
}

int MessageForBBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    if (a && b)
    {
        lua_pushboolean(L, (a->messageType == b->messageType && a->messageInt == b->messageInt) ? 1 : 0);
    }
    else
    {
        lua_pushboolean(L, 0);
    }
    return 1;
}

void MessageForBBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       MessageForBBinding::operator_eq },
        { "__gc",       MessageForBBinding::gc },
        { "__tostring", MessageForBBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "new",        MessageForBBinding::create },
        { 0, 0 }
    };

    registerClass(
        L, 
        MessageForBBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MessageForBBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "messageType", MessageForB_get_messageType);
    registerGetter(L, "messageInt", MessageForB_get_messageInt);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // Create __setters table
    registerSetter(L, "messageType", MessageForB_set_messageType);
    registerSetter(L, "messageInt", MessageForB_set_messageInt);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1); // Pop metatable

    // Register global class table
    lua_newtable(L);
    registerStaticMethod(L, "new", MessageForBBinding::create);
    lua_setglobal(L, "MessageForB");
}

} // namespace KenshiLua
