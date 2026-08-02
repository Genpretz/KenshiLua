#include "pch.h"
#include "KENSHI\GameWorld.h"
#include "SimpleTimeStamperBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/CPerfTimerBinding.h"

namespace KenshiLua
{

static SimpleTimeStamper* getInstance(lua_State* L, int idx)
{
    return checkObject<SimpleTimeStamper>(L, idx, SimpleTimeStamperBinding::getMetatableName());
}

// --- Getters for SimpleTimeStamper ---
static int SimpleTimeStamper_get_timer(lua_State* L)
{
    SimpleTimeStamper* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SimpleTimeStamper is nil");
    return pushObject<CPerfTimer>(L, &instance->timer, CPerfTimerBinding::getMetatableName());
}

// --- Setters for SimpleTimeStamper ---
static int SimpleTimeStamper_set_timer(lua_State* L)
{
    SimpleTimeStamper* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SimpleTimeStamper is nil");
    instance->timer = *checkObject<CPerfTimer>(L, 2, CPerfTimerBinding::getMetatableName());
    return 0;
}

int SimpleTimeStamperBinding::_CONSTRUCTOR(lua_State* L)
{
    SimpleTimeStamper* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SimpleTimeStamper is nil");

    SimpleTimeStamper* result = instance->_CONSTRUCTOR();
    return pushObject<SimpleTimeStamper>(L, result, SimpleTimeStamperBinding::getMetatableName());
}

int SimpleTimeStamperBinding::getTime(lua_State* L)
{
    SimpleTimeStamper* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SimpleTimeStamper is nil");

    double _lastStamp = (double)luaL_checknumber(L, 2);
    double result = instance->getTime(_lastStamp);
    lua_pushnumber(L, result);
    return 1;
}

int SimpleTimeStamperBinding::stampTime(lua_State* L)
{
    SimpleTimeStamper* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SimpleTimeStamper is nil");

    double result = instance->stampTime();
    lua_pushnumber(L, result);
    return 1;
}

int SimpleTimeStamperBinding::_DESTRUCTOR(lua_State* L)
{
    SimpleTimeStamper* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SimpleTimeStamper is nil");

    instance->_DESTRUCTOR();
    return 0;
}

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
        { "_CONSTRUCTOR", SimpleTimeStamperBinding::_CONSTRUCTOR },
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
    registerGetter(L, "timer", SimpleTimeStamper_get_timer);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "timer", SimpleTimeStamper_set_timer);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua