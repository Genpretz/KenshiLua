#include "pch.h"
#include "SerialisableBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

/*
Skipped methods needing manual binding:
  line 12: serialise(std::ofstream&) - pure virtual taking a C++ output stream, which has no Lua representation
  line 13: restore(std::ifstream&) - pure virtual taking a C++ input stream, which has no Lua representation
  line 15: Serialisable() - abstract interface; Lua cannot construct one
  line 16: _CONSTRUCTOR() - see above
Its only SDK subclasses, HandleListBase and HandleManager, have no bindings yet; once they do,
link them with setMetatableParent so they can be passed where a Serialisable is expected.
*/

int SerialisableBinding::gc(lua_State* L)
{
    // Borrowed; Serialisable is an interface of engine-owned objects
    return 0;
}

int SerialisableBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Serialisable object");
    return 1;
}

void SerialisableBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SerialisableBinding::gc },
        { "__tostring", SerialisableBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L,
        SerialisableBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SerialisableBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
