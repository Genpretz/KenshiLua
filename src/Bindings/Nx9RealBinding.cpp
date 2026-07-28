#include "pch.h"
#include "kenshi\physicsactual.h"
#include "Nx9RealBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Nx9Real* getInstance(lua_State* L, int idx)
{
    return checkObject<Nx9Real>(L, idx, Nx9RealBinding::getMetatableName());
}

// --- Getters for Nx9Real ---
// --- Setters for Nx9Real ---


/*
Skipped properties needing manual binding:
  line 371: s (S) - unsupported type
*/

int Nx9RealBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int Nx9RealBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Nx9Real object");
    return 1;
}

void Nx9RealBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       Nx9RealBinding::gc },
        { "__tostring", Nx9RealBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        Nx9RealBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, Nx9RealBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua