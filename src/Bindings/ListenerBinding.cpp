#include "pch.h"
#include <kenshi/PhysicsCollection.h>
#include "ListenerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef WeatherRegion::Listener Listener;

static Listener* getInstance(lua_State* L, int idx)
{
    return checkObject<Listener>(L, idx, ListenerBinding::getMetatableName());
}

// --- Getters for Listener ---
// --- Setters for Listener ---
int ListenerBinding::_CONSTRUCTOR(lua_State* L)
{
    Listener* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Listener is nil");

    Listener* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 59: void weatherUpdated(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - ListenerBinding::_CONSTRUCTOR: Listener* (unbound pointer)
*/

int ListenerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ListenerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Listener object");
    return 1;
}

void ListenerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ListenerBinding::gc },
        { "__tostring", ListenerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ListenerBinding::_CONSTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        ListenerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ListenerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua