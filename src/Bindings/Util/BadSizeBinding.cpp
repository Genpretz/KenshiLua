#include "pch.h"
#include "kenshi\util\array2d.h"
#include "BadSizeBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static BadSize* getInstance(lua_State* L, int idx)
{
    return checkObject<BadSize>(L, idx, BadSizeBinding::getMetatableName());
}

// --- Getters for BadSize ---
// --- Setters for BadSize ---


int BadSizeBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BadSizeBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BadSize object");
    return 1;
}

void BadSizeBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BadSizeBinding::gc },
        { "__tostring", BadSizeBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        BadSizeBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BadSizeBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua