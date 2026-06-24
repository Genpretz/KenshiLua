#include "pch.h"
#include "kenshi\Character.h"
#include "WaterStateBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static WaterState* getB(lua_State* L, int idx)
{
    return checkObject<WaterState>(L, idx, WaterStateBinding::getMetatableName());
}

// --- Getters for WaterState ---
// --- Setters for WaterState ---


int WaterStateBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int WaterStateBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.WaterState object");
    return 1;
}

void WaterStateBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WaterStateBinding::gc },
        { "__tostring", WaterStateBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        WaterStateBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, WaterStateBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua