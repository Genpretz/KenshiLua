#include "pch.h"
#include <kenshi/PhysicsActual.h>
#include "PhysicsClassBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef Scythe::PhysicsClass PhysicsClass;

static PhysicsClass* getInstance(lua_State* L, int idx)
{
    return checkObject<PhysicsClass>(L, idx, PhysicsClassBinding::getMetatableName());
}

// --- Getters for PhysicsClass ---
// --- Setters for PhysicsClass ---
/*
Skipped methods needing manual binding:
  line 88: bool insert(...) - overloaded method
  line 89: bool insert(...) - overloaded method
  line 90: bool insert(...) - overloaded method
  line 91: ScytheActor* createNewActor1(...) - unsupported arg type
  line 92: ScytheActor* createNewActor(...) - unsupported arg type
  line 93: NxJoint* createJoint1(...) - unsupported arg type
  line 94: NxJoint* createJoint(...) - unsupported arg type
  line 95: SkeletonData* createSkeletalModel(...) - unsupported arg type
*/

int PhysicsClassBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int PhysicsClassBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.PhysicsClass object");
    return 1;
}

void PhysicsClassBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PhysicsClassBinding::gc },
        { "__tostring", PhysicsClassBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        PhysicsClassBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, PhysicsClassBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua