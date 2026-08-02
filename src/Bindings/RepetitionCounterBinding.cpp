#include "pch.h"
#include "KENSHI\Dialogue.h"
#include "RepetitionCounterBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/StdMapBinding.h"
#include "Bindings/DialogStateBinding.h"

typedef Dialogue::RepetitionCounter RepetitionCounter;

namespace KenshiLua
{

typedef StdMapBinding<EventTriggerEnum, Dialogue::RepetitionCounter::DialogState> RepetitionStatesMapBinding;

static RepetitionCounter* getInstance(lua_State* L, int idx)
{
    return checkObject<RepetitionCounter>(L, idx, RepetitionCounterBinding::getMetatableName());
}

// --- Getters for RepetitionCounter ---
static int RepetitionCounter_get_states(lua_State* L)
{
    RepetitionCounter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RepetitionCounter is nil");
    return pushObject<RepetitionStatesMapBinding::MapType>(L, &instance->states, RepetitionStatesMapBinding::metaName);
}

// --- Setters for RepetitionCounter ---
static int RepetitionCounter_set_states(lua_State* L)
{
    RepetitionCounter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RepetitionCounter is nil");
    auto* val = RepetitionStatesMapBinding::get(L, 2);
    if (!val) return luaL_error(L, "Expected RepetitionStates map object");
    instance->states = *val;
    return 0;
}

// --- Methods ---
int RepetitionCounterBinding::setup(lua_State* L)
{
    RepetitionCounter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RepetitionCounter is nil");

    instance->setup();
    return 0;
}

int RepetitionCounterBinding::count(lua_State* L)
{
    RepetitionCounter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RepetitionCounter is nil");

    EventTriggerEnum ev = (EventTriggerEnum)luaL_checkinteger(L, 2);
    bool result = instance->count(ev);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RepetitionCounterBinding::getTimeSinceLastTrigger(lua_State* L)
{
    RepetitionCounter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RepetitionCounter is nil");

    EventTriggerEnum ev = (EventTriggerEnum)luaL_checkinteger(L, 2);
    double result = instance->getTimeSinceLastTrigger(ev);
    lua_pushnumber(L, result);
    return 1;
}

int RepetitionCounterBinding::getCount(lua_State* L)
{
    RepetitionCounter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RepetitionCounter is nil");

    EventTriggerEnum ev = (EventTriggerEnum)luaL_checkinteger(L, 2);
    int result = instance->getCount(ev);
    lua_pushinteger(L, result);
    return 1;
}

int RepetitionCounterBinding::_CONSTRUCTOR(lua_State* L)
{
    RepetitionCounter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RepetitionCounter is nil");

    RepetitionCounter* result = instance->_CONSTRUCTOR();
    return pushObject<RepetitionCounter>(L, result, RepetitionCounterBinding::getMetatableName());
}

int RepetitionCounterBinding::_DESTRUCTOR(lua_State* L)
{
    RepetitionCounter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RepetitionCounter is nil");

    instance->_DESTRUCTOR();
    return 0;
}

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
        { "_CONSTRUCTOR", RepetitionCounterBinding::_CONSTRUCTOR },
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
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    RepetitionStatesMapBinding::registerBinding(L, "KenshiLua.RepetitionStatesMap", nullptr, DialogStateBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua