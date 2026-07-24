#include "pch.h"
#include "kenshi\gui\ScreenLabel.h"
#include "ScreenLabelDebugBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ScreenLabelDebug* getInstance(lua_State* L, int idx)
{
    return checkObject<ScreenLabelDebug>(L, idx, ScreenLabelDebugBinding::getMetatableName());
}

// --- Getters for ScreenLabelDebug ---
static int ScreenLabelDebug_get_timeLeft(lua_State* L)
{
    ScreenLabelDebug* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelDebug is nil");
    lua_pushnumber(L, instance->timeLeft);
    return 1;
}

// --- Setters for ScreenLabelDebug ---
static int ScreenLabelDebug_set_timeLeft(lua_State* L)
{
    ScreenLabelDebug* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelDebug is nil");
    instance->timeLeft = (float)luaL_checknumber(L, 2);
    return 0;
}

int ScreenLabelDebugBinding::update(lua_State* L)
{
    ScreenLabelDebug* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelDebug is nil");

    instance->update();
    return 0;
}

int ScreenLabelDebugBinding::_NV_update(lua_State* L)
{
    ScreenLabelDebug* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelDebug is nil");

    instance->_NV_update();
    return 0;
}

int ScreenLabelDebugBinding::_CONSTRUCTOR(lua_State* L)
{
    ScreenLabelDebug* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelDebug is nil");

    const std::string caption = luaL_checkstring(L, 2);
    float time = (float)luaL_checknumber(L, 3);
    ScreenLabelDebug* result = instance->_CONSTRUCTOR(caption, time);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ScreenLabelDebugBinding::_DESTRUCTOR(lua_State* L)
{
    ScreenLabelDebug* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelDebug is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 88: const std::string& getCaption(...) - reference return type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - ScreenLabelDebugBinding::_CONSTRUCTOR: ScreenLabelDebug* (unbound pointer)
*/

int ScreenLabelDebugBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ScreenLabelDebugBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ScreenLabelDebug object");
    return 1;
}

void ScreenLabelDebugBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ScreenLabelDebugBinding::gc },
        { "__tostring", ScreenLabelDebugBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", ScreenLabelDebugBinding::update },
        { "_NV_update", ScreenLabelDebugBinding::_NV_update },
        { "_CONSTRUCTOR", ScreenLabelDebugBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ScreenLabelDebugBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        ScreenLabelDebugBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ScreenLabelDebugBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "timeLeft", ScreenLabelDebug_get_timeLeft);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "timeLeft", ScreenLabelDebug_set_timeLeft);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ScreenLabel
    // setMetatableParent(L, ScreenLabelDebugBinding::getMetatableName(), ScreenLabelBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua