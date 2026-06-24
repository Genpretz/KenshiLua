#include "pch.h"
#include "kenshi\SensoryData.h"
#include "SenseItrBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static SenseItr* getB(lua_State* L, int idx)
{
    return checkObject<SenseItr>(L, idx, SenseItrBinding::getMetatableName());
}

// --- Getters for SenseItr ---
static int SenseItr_get_it(lua_State* L)
{
    SenseItr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SenseItr is nil");
    // TODO: Unsupported type for it (boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > >)
    lua_pushnil(L);
    return 1;
}

static int SenseItr_get__end(lua_State* L)
{
    SenseItr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SenseItr is nil");
    // TODO: Unsupported type for _end (boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > >)
    lua_pushnil(L);
    return 1;
}

static int SenseItr_get_flagsAny(lua_State* L)
{
    SenseItr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SenseItr is nil");
    lua_pushinteger(L, b->flagsAny);
    return 1;
}

static int SenseItr_get_flagsNot(lua_State* L)
{
    SenseItr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SenseItr is nil");
    lua_pushinteger(L, b->flagsNot);
    return 1;
}

// --- Setters for SenseItr ---
static int SenseItr_set_it(lua_State* L)
{
    SenseItr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SenseItr is nil");
    return luaL_error(L, "Read-only or unsupported setter type for it");
}

static int SenseItr_set__end(lua_State* L)
{
    SenseItr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SenseItr is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _end");
}

static int SenseItr_set_flagsAny(lua_State* L)
{
    SenseItr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SenseItr is nil");
    b->flagsAny = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int SenseItr_set_flagsNot(lua_State* L)
{
    SenseItr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SenseItr is nil");
    b->flagsNot = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

int SenseItrBinding::getCharacter(lua_State* L)
{
    SenseItr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SenseItr is nil");

    Character* result = b->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int SenseItrBinding::ended(lua_State* L)
{
    SenseItr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SenseItr is nil");

    bool result = b->ended();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SenseItrBinding::increment(lua_State* L)
{
    SenseItr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SenseItr is nil");

    b->increment();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 68: SeenSomeone* getData(...) - unsupported return type
  line 71: void operator++(...) - operator
  line 74: SenseItr* _CONSTRUCTOR(...) - unsupported return type
*/

int SenseItrBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SenseItrBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SenseItr object");
    return 1;
}

void SenseItrBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SenseItrBinding::gc },
        { "__tostring", SenseItrBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getCharacter", SenseItrBinding::getCharacter },
        { "ended", SenseItrBinding::ended },
        { "increment", SenseItrBinding::increment },
        { 0, 0 }
    };

    registerClass(
        L, 
        SenseItrBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SenseItrBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, SenseItr_get_it);
    lua_setfield(L, -2, "it");
    lua_pushcfunction(L, SenseItr_get__end);
    lua_setfield(L, -2, "_end");
    lua_pushcfunction(L, SenseItr_get_flagsAny);
    lua_setfield(L, -2, "flagsAny");
    lua_pushcfunction(L, SenseItr_get_flagsNot);
    lua_setfield(L, -2, "flagsNot");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, SenseItr_set_it);
    lua_setfield(L, -2, "it");
    lua_pushcfunction(L, SenseItr_set__end);
    lua_setfield(L, -2, "_end");
    lua_pushcfunction(L, SenseItr_set_flagsAny);
    lua_setfield(L, -2, "flagsAny");
    lua_pushcfunction(L, SenseItr_set_flagsNot);
    lua_setfield(L, -2, "flagsNot");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua