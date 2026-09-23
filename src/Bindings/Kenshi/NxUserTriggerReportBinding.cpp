#include "pch.h"
#include "kenshi\physicsactual.h"
#include "NxUserTriggerReportBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static NxUserTriggerReport* getInstance(lua_State* L, int idx)
{
    return checkObject<NxUserTriggerReport>(L, idx, NxUserTriggerReportBinding::getMetatableName());
}

// --- Getters for NxUserTriggerReport ---
// --- Setters for NxUserTriggerReport ---
/*
Skipped methods needing manual binding:
  line 53: void onTrigger(...) - unsupported arg type
*/


int NxUserTriggerReportBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int NxUserTriggerReportBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NxUserTriggerReport object");
    return 1;
}

void NxUserTriggerReportBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       NxUserTriggerReportBinding::gc },
        { "__tostring", NxUserTriggerReportBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        NxUserTriggerReportBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, NxUserTriggerReportBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua