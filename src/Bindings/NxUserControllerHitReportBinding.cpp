#include "pch.h"
#include "kenshi\CharMovement.h"
#include "NxUserControllerHitReportBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static NxUserControllerHitReport* getB(lua_State* L, int idx)
{
    return checkObject<NxUserControllerHitReport>(L, idx, NxUserControllerHitReportBinding::getMetatableName());
}

// --- Getters for NxUserControllerHitReport ---
// --- Setters for NxUserControllerHitReport ---
int NxUserControllerHitReportBinding::_DESTRUCTOR(lua_State* L)
{
    NxUserControllerHitReport* b = getB(L, 1);
    if (!b) return luaL_error(L, "NxUserControllerHitReport is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 123: NxControllerAction onShapeHit(...) - unsupported return type
  line 124: NxControllerAction onControllerHit(...) - unsupported return type
  line 129: NxUserControllerHitReport* _CONSTRUCTOR(...) - unsupported return type
*/

int NxUserControllerHitReportBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int NxUserControllerHitReportBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NxUserControllerHitReport object");
    return 1;
}

void NxUserControllerHitReportBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       NxUserControllerHitReportBinding::gc },
        { "__tostring", NxUserControllerHitReportBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", NxUserControllerHitReportBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        NxUserControllerHitReportBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, NxUserControllerHitReportBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua