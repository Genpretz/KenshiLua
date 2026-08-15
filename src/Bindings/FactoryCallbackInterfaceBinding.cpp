#include "pch.h"
#include "kenshi\PlayerInterface.h"
#include "FactoryCallbackInterfaceBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/RootObjectBinding.h"

namespace KenshiLua
{

static FactoryCallbackInterface* getInstance(lua_State* L, int idx)
{
    return checkObject<FactoryCallbackInterface>(L, idx, FactoryCallbackInterfaceBinding::getMetatableName());
}

// --- Getters for FactoryCallbackInterface ---
// --- Setters for FactoryCallbackInterface ---
int FactoryCallbackInterfaceBinding::factoryObjectCreatedCallback(lua_State* L)
{
    FactoryCallbackInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactoryCallbackInterface is nil");

    RootObject* _a1 = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->factoryObjectCreatedCallback(_a1);
    return 0;
}

int FactoryCallbackInterfaceBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FactoryCallbackInterfaceBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FactoryCallbackInterface object");
    return 1;
}

void FactoryCallbackInterfaceBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FactoryCallbackInterfaceBinding::gc },
        { "__tostring", FactoryCallbackInterfaceBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "factoryObjectCreatedCallback", FactoryCallbackInterfaceBinding::factoryObjectCreatedCallback },
        { 0, 0 }
    };

    registerClass(
        L, 
        FactoryCallbackInterfaceBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FactoryCallbackInterfaceBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua