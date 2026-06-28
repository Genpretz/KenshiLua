#include "pch.h"
#include "kenshi\GameWorld.h"
#include "SimpleTimeStamperBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static SimpleTimeStamper* getB(lua_State* L, int idx)
{
    return checkObject<SimpleTimeStamper>(L, idx, SimpleTimeStamperBinding::getMetatableName());
}

// --- Getters for SimpleTimeStamper ---
static int SimpleTimeStamper_get_timer(lua_State* L)
{
    SimpleTimeStamper* b = getB(L, 1);
    if (!b) return luaL_error(L, "SimpleTimeStamper is nil");
    // TODO: Unsupported type for timer (CPerfTimer)
    return luaL_error(L, "Unsupported property 'timer' (type: CPerfTimer)");
}

// --- Setters for SimpleTimeStamper ---
static int SimpleTimeStamper_set_timer(lua_State* L)
{
    SimpleTimeStamper* b = getB(L, 1);
    if (!b) return luaL_error(L, "SimpleTimeStamper is nil");
    return luaL_error(L, "Read-only or unsupported setter type for timer");
}

int SimpleTimeStamperBinding::getTime(lua_State* L)
{
    SimpleTimeStamper* b = getB(L, 1);
    if (!b) return luaL_error(L, "SimpleTimeStamper is nil");

    double _lastStamp = (double)luaL_checknumber(L, 2);
    double result = b->getTime(_lastStamp);
    lua_pushnumber(L, result);
    return 1;
}

int SimpleTimeStamperBinding::stampTime(lua_State* L)
{
    SimpleTimeStamper* b = getB(L, 1);
    if (!b) return luaL_error(L, "SimpleTimeStamper is nil");

    double result = b->stampTime();
    lua_pushnumber(L, result);
    return 1;
}

int SimpleTimeStamperBinding::_DESTRUCTOR(lua_State* L)
{
    SimpleTimeStamper* b = getB(L, 1);
    if (!b) return luaL_error(L, "SimpleTimeStamper is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 48: SimpleTimeStamper* _CONSTRUCTOR(...) - unsupported return type
*/

int SimpleTimeStamperBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SimpleTimeStamperBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SimpleTimeStamper object");
    return 1;
}

void SimpleTimeStamperBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SimpleTimeStamperBinding::gc },
        { "__tostring", SimpleTimeStamperBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getTime", SimpleTimeStamperBinding::getTime },
        { "stampTime", SimpleTimeStamperBinding::stampTime },
        { "_DESTRUCTOR", SimpleTimeStamperBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        SimpleTimeStamperBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SimpleTimeStamperBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, SimpleTimeStamper_get_timer);
    lua_setfield(L, -2, "timer");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, SimpleTimeStamper_set_timer);
    lua_setfield(L, -2, "timer");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua