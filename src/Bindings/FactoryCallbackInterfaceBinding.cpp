#include "pch.h"
#include "kenshi\PlayerInterface.h"
#include "FactoryCallbackInterfaceBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static FactoryCallbackInterface* getB(lua_State* L, int idx)
{
    return checkObject<FactoryCallbackInterface>(L, idx, FactoryCallbackInterfaceBinding::getMetatableName());
}

// --- Getters for FactoryCallbackInterface ---
// --- Setters for FactoryCallbackInterface ---
/*
Skipped methods needing manual binding:
  line 21: void factoryObjectCreatedCallback(...) - unsupported arg type
  line 24: FactoryCallbackInterface* _CONSTRUCTOR(...) - unsupported return type
*/

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
