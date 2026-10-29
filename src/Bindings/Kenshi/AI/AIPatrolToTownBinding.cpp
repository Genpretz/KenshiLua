#include "pch.h"
#include "kenshi/AI/AIEventClass.h"
#include "AIPatrolToTownBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static AIPatrolToTown* getInstance(lua_State* L, int idx)
{
    return checkObject<AIPatrolToTown>(L, idx, AIPatrolToTownBinding::getMetatableName());
}

// Pure virtual; dispatches to the object's own implementation.
int AIPatrolToTownBinding::update(lua_State* L)
{
    AIPatrolToTown* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIPatrolToTown is nil");

    instance->update();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 24: startEvent() - no address
  line 25: endEvent() - no address
  line 26-28: constructors and operator= - no address; AIPatrolToTown is abstract
*/

int AIPatrolToTownBinding::gc(lua_State* L)
{
    // Borrowed
    return 0;
}

int AIPatrolToTownBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AIPatrolToTown object");
    return 1;
}

void AIPatrolToTownBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AIPatrolToTownBinding::gc },
        { "__tostring", AIPatrolToTownBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", AIPatrolToTownBinding::update },
        { 0, 0 }
    };

    registerClass(
        L,
        AIPatrolToTownBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AIPatrolToTownBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
