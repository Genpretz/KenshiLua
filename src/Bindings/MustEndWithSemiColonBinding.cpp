#include "pch.h"
#include <kenshi/PhysicsCollection.h>
#include "MustEndWithSemiColonBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef PhysicsCollection::MustEndWithSemiColon MustEndWithSemiColon;

static MustEndWithSemiColon* getInstance(lua_State* L, int idx)
{
    return checkObject<MustEndWithSemiColon>(L, idx, MustEndWithSemiColonBinding::getMetatableName());
}

// --- Getters for MustEndWithSemiColon ---
// --- Setters for MustEndWithSemiColon ---


int MustEndWithSemiColonBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MustEndWithSemiColonBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MustEndWithSemiColon object");
    return 1;
}

void MustEndWithSemiColonBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MustEndWithSemiColonBinding::gc },
        { "__tostring", MustEndWithSemiColonBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        MustEndWithSemiColonBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MustEndWithSemiColonBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua