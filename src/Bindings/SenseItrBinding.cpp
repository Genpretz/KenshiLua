#include "pch.h"
#include "kenshi\SensoryData.h"
#include "SenseItrBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/SeenSomeoneBinding.h"

namespace KenshiLua
{

static SenseItr* getInstance(lua_State* L, int idx)
{
    return checkObject<SenseItr>(L, idx, SenseItrBinding::getMetatableName());
}

// --- Getters for SenseItr ---
static int SenseItr_get_flagsAny(lua_State* L)
{
    SenseItr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SenseItr is nil");
    lua_pushinteger(L, instance->flagsAny);
    return 1;
}

static int SenseItr_get_flagsNot(lua_State* L)
{
    SenseItr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SenseItr is nil");
    lua_pushinteger(L, instance->flagsNot);
    return 1;
}

// --- Setters for SenseItr ---
static int SenseItr_set_flagsAny(lua_State* L)
{
    SenseItr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SenseItr is nil");
    instance->flagsAny = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int SenseItr_set_flagsNot(lua_State* L)
{
    SenseItr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SenseItr is nil");
    instance->flagsNot = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

int SenseItrBinding::getCharacter(lua_State* L)
{
    SenseItr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SenseItr is nil");

    Character* result = instance->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int SenseItrBinding::getData(lua_State* L)
{
    SenseItr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SenseItr is nil");

    SeenSomeone* result = instance->getData();
    return pushObject<SeenSomeone>(L, result, SeenSomeoneBinding::getMetatableName());
}

int SenseItrBinding::ended(lua_State* L)
{
    SenseItr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SenseItr is nil");

    bool result = instance->ended();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SenseItrBinding::increment(lua_State* L)
{
    SenseItr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SenseItr is nil");

    instance->increment();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 71: void operator++(...) - operator
  line 74: SenseItr* _CONSTRUCTOR(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 75: it (boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > >) - unsupported type
  line 76: _end (boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > >) - unsupported type
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



static int SenseItr_get__end(lua_State* L)
{
    SenseItr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SenseItr is nil");
    // TODO: Unsupported type for _end (boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > >)
    return luaL_error(L, "Unsupported property '_end' (type: boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > >)");
}


static int SenseItr_get_it(lua_State* L)
{
    SenseItr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SenseItr is nil");
    // TODO: Unsupported type for it (boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > >)
    return luaL_error(L, "Unsupported property 'it' (type: boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > >)");
}


static int SenseItr_set__end(lua_State* L)
{
    SenseItr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SenseItr is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _end");
}


static int SenseItr_set_it(lua_State* L)
{
    SenseItr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SenseItr is nil");
    return luaL_error(L, "Read-only or unsupported setter type for it");
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
        { "getData", SenseItrBinding::getData },
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
    registerGetter(L, "flagsAny", SenseItr_get_flagsAny);
    registerGetter(L, "flagsNot", SenseItr_get_flagsNot);
        registerGetter(L, "_end", SenseItr_get__end);
        registerGetter(L, "it", SenseItr_get_it);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "flagsAny", SenseItr_set_flagsAny);
    registerSetter(L, "flagsNot", SenseItr_set_flagsNot);
        registerSetter(L, "_end", SenseItr_set__end);
        registerSetter(L, "it", SenseItr_set_it);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua