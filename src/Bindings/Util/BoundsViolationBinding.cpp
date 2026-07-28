#include "pch.h"
#include "kenshi\util\array2d.h"
#include "BoundsViolationBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static BoundsViolation* getInstance(lua_State* L, int idx)
{
    return checkObject<BoundsViolation>(L, idx, BoundsViolationBinding::getMetatableName());
}

// --- Getters for BoundsViolation ---
// --- Setters for BoundsViolation ---


int BoundsViolationBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BoundsViolationBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BoundsViolation object");
    return 1;
}

void BoundsViolationBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BoundsViolationBinding::gc },
        { "__tostring", BoundsViolationBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        BoundsViolationBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BoundsViolationBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua