#include "pch.h"
#include <kenshi/PhysicsActual.h>
#include "TriggerCallbackBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef PhysicsActual::TriggerCallback TriggerCallback;

static TriggerCallback* getInstance(lua_State* L, int idx)
{
    return checkObject<TriggerCallback>(L, idx, TriggerCallbackBinding::getMetatableName());
}

// --- Getters for TriggerCallback ---
// --- Setters for TriggerCallback ---
int TriggerCallbackBinding::updateFrameEndMT(lua_State* L)
{
    TriggerCallback* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TriggerCallback is nil");

    instance->updateFrameEndMT();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 252: void onTrigger(...) - unsupported arg type
  line 253: void _NV_onTrigger(...) - unsupported arg type
*/


/*
Skipped properties needing manual binding:
  line 255: triggerUpdateMap (ogre_unordered_map<hand, hand>::type) - unsupported type
*/

int TriggerCallbackBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TriggerCallbackBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TriggerCallback object");
    return 1;
}

void TriggerCallbackBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TriggerCallbackBinding::gc },
        { "__tostring", TriggerCallbackBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "updateFrameEndMT", TriggerCallbackBinding::updateFrameEndMT },
        { 0, 0 }
    };

    registerClass(
        L, 
        TriggerCallbackBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TriggerCallbackBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to NxUserTriggerReport
    // setMetatableParent(L, TriggerCallbackBinding::getMetatableName(), NxUserTriggerReportBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua