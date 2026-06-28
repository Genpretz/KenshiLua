#include "pch.h"
#include "kenshi\Dialogue.h"
#include "RepetitionCounterBinding.h"
#include "Lua/BindingHelpers.h"

typedef Dialogue::RepetitionCounter RepetitionCounter;

namespace KenshiLua
{

static RepetitionCounter* getB(lua_State* L, int idx)
{
    return checkObject<RepetitionCounter>(L, idx, RepetitionCounterBinding::getMetatableName());
}

// --- Getters for RepetitionCounter ---
static int RepetitionCounter_get_states(lua_State* L)
{
    RepetitionCounter* b = getB(L, 1);
    if (!b) return luaL_error(L, "RepetitionCounter is nil");
    // TODO: Unsupported type for states (std::map<EventTriggerEnum, Dialogue::RepetitionCounter::DialogState, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, Dialogue::RepetitionCounter::DialogState>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'states' (type: std::map<EventTriggerEnum, Dialogue::RepetitionCounter::DialogState, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, Dialogue::RepetitionCounter::DialogState>, Ogre::GeneralAllocPolicy > >)");
}

// --- Setters for RepetitionCounter ---
static int RepetitionCounter_set_states(lua_State* L)
{
    RepetitionCounter* b = getB(L, 1);
    if (!b) return luaL_error(L, "RepetitionCounter is nil");
    return luaL_error(L, "Read-only or unsupported setter type for states");
}

int RepetitionCounterBinding::setup(lua_State* L)
{
    RepetitionCounter* b = getB(L, 1);
    if (!b) return luaL_error(L, "RepetitionCounter is nil");

    b->setup();
    return 0;
}

int RepetitionCounterBinding::count(lua_State* L)
{
    RepetitionCounter* b = getB(L, 1);
    if (!b) return luaL_error(L, "RepetitionCounter is nil");

    EventTriggerEnum ev = (EventTriggerEnum)luaL_checkinteger(L, 2);
    bool result = b->count(ev);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RepetitionCounterBinding::getTimeSinceLastTrigger(lua_State* L)
{
    RepetitionCounter* b = getB(L, 1);
    if (!b) return luaL_error(L, "RepetitionCounter is nil");

    EventTriggerEnum ev = (EventTriggerEnum)luaL_checkinteger(L, 2);
    double result = b->getTimeSinceLastTrigger(ev);
    lua_pushnumber(L, result);
    return 1;
}

int RepetitionCounterBinding::getCount(lua_State* L)
{
    RepetitionCounter* b = getB(L, 1);
    if (!b) return luaL_error(L, "RepetitionCounter is nil");

    EventTriggerEnum ev = (EventTriggerEnum)luaL_checkinteger(L, 2);
    int result = b->getCount(ev);
    lua_pushinteger(L, result);
    return 1;
}

int RepetitionCounterBinding::_DESTRUCTOR(lua_State* L)
{
    RepetitionCounter* b = getB(L, 1);
    if (!b) return luaL_error(L, "RepetitionCounter is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 303: RepetitionCounter* _CONSTRUCTOR(...) - unsupported return type
*/

int RepetitionCounterBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int RepetitionCounterBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RepetitionCounter object");
    return 1;
}

void RepetitionCounterBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RepetitionCounterBinding::gc },
        { "__tostring", RepetitionCounterBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setup", RepetitionCounterBinding::setup },
        { "count", RepetitionCounterBinding::count },
        { "getTimeSinceLastTrigger", RepetitionCounterBinding::getTimeSinceLastTrigger },
        { "getCount", RepetitionCounterBinding::getCount },
        { "_DESTRUCTOR", RepetitionCounterBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        RepetitionCounterBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RepetitionCounterBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, RepetitionCounter_get_states);
    lua_setfield(L, -2, "states");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, RepetitionCounter_set_states);
    lua_setfield(L, -2, "states");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua