#include "pch.h"
#include "kenshi\physicsactual.h"
#include "NxBoxBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static NxBox* getInstance(lua_State* L, int idx)
{
    return checkObject<NxBox>(L, idx, NxBoxBinding::getMetatableName());
}

// --- Getters for NxBox ---
// --- Setters for NxBox ---
int NxBoxBinding::operator_assign(lua_State* L)
{
    NxBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxBox is nil");

    NxBox* other = checkObject<NxBox>(L, 2, NxBoxBinding::getMetatableName());
    if (!other) return luaL_error(L, "Argument 1 to operator_assign must be NxBox");

    *instance = *other;
    lua_settop(L, 1);
    return 1;
}

/*
Skipped properties needing manual binding:
  line 493: center (NxVec3) - unsupported type
  line 494: extents (NxVec3) - unsupported type
  line 495: rot (NxMat33) - unsupported type
*/

int NxBoxBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int NxBoxBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NxBox object");
    return 1;
}

void NxBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       NxBoxBinding::gc },
        { "__tostring", NxBoxBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "operator_assign", NxBoxBinding::operator_assign },
        { 0, 0 }
    };

    registerClass(
        L, 
        NxBoxBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, NxBoxBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua