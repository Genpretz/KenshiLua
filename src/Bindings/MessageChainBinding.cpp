#include "pch.h"
#include "kenshi\physicsactual.h"
#include "MessageChainBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MessageChain* getInstance(lua_State* L, int idx)
{
    return checkObject<MessageChain>(L, idx, MessageChainBinding::getMetatableName());
}

// --- Getters for MessageChain ---
// --- Setters for MessageChain ---
int MessageChainBinding::flush(lua_State* L)
{
    MessageChain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MessageChain is nil");

    bool result = instance->flush();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped properties needing manual binding:
  line 156: mainThreadData (lektor<T>) - unsupported type
  line 157: backThreadData (lektor<T>) - unsupported type
*/

int MessageChainBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MessageChainBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MessageChain object");
    return 1;
}

void MessageChainBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MessageChainBinding::gc },
        { "__tostring", MessageChainBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "flush", MessageChainBinding::flush },
        { 0, 0 }
    };

    registerClass(
        L, 
        MessageChainBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MessageChainBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua