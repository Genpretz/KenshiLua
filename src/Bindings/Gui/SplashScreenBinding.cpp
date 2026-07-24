#include "pch.h"
#include "kenshi\gui\SplashScreen.h"
#include "SplashScreenBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static SplashScreen* getInstance(lua_State* L, int idx)
{
    return checkObject<SplashScreen>(L, idx, SplashScreenBinding::getMetatableName());
}

// --- Getters for SplashScreen ---
static int SplashScreen_get_currentState(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");
    lua_pushinteger(L, instance->currentState);
    return 1;
}

static int SplashScreen_get_startTime(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");
    lua_pushnumber(L, instance->startTime);
    return 1;
}

static int SplashScreen_get_skipLogo(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");
    lua_pushboolean(L, instance->skipLogo ? 1 : 0);
    return 1;
}

static int SplashScreen_get_delay(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");
    lua_pushinteger(L, instance->delay);
    return 1;
}

static int SplashScreen_get_mainPanel(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->mainPanel);
    return 1;
}

// --- Setters for SplashScreen ---
static int SplashScreen_set_currentState(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");
    instance->currentState = (char)luaL_checkinteger(L, 2);
    return 0;
}

static int SplashScreen_set_startTime(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");
    instance->startTime = (double)luaL_checknumber(L, 2);
    return 0;
}

static int SplashScreen_set_skipLogo(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");
    instance->skipLogo = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SplashScreen_set_delay(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");
    instance->delay = (int)luaL_checkinteger(L, 2);
    return 0;
}

int SplashScreenBinding::_CONSTRUCTOR(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");

    SplashScreen* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int SplashScreenBinding::_DESTRUCTOR(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int SplashScreenBinding::update(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");

    instance->update();
    return 0;
}

int SplashScreenBinding::getState(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");

    char result = instance->getState();
    lua_pushinteger(L, result);
    return 1;
}

int SplashScreenBinding::getEnded(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");

    bool result = instance->getEnded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SplashScreenBinding::skip(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");

    instance->skip();
    return 0;
}

int SplashScreenBinding::addLogo(lua_State* L)
{
    SplashScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SplashScreen is nil");

    const std::string file = luaL_checkstring(L, 2);
    float scale = (float)luaL_checknumber(L, 3);
    instance->addLogo(file, scale);
    return 0;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - SplashScreen_get_mainPanel: MyGUI::Widget* (unbound pointer)
  - SplashScreenBinding::_CONSTRUCTOR: SplashScreen* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 23: logos (lektor<MyGUI::ImageBox*>) - unsupported type
*/

int SplashScreenBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SplashScreenBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SplashScreen object");
    return 1;
}

void SplashScreenBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SplashScreenBinding::gc },
        { "__tostring", SplashScreenBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", SplashScreenBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", SplashScreenBinding::_DESTRUCTOR },
        { "update", SplashScreenBinding::update },
        { "getState", SplashScreenBinding::getState },
        { "getEnded", SplashScreenBinding::getEnded },
        { "skip", SplashScreenBinding::skip },
        { "addLogo", SplashScreenBinding::addLogo },
        { 0, 0 }
    };

    registerClass(
        L, 
        SplashScreenBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SplashScreenBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "currentState", SplashScreen_get_currentState);
    registerGetter(L, "startTime", SplashScreen_get_startTime);
    registerGetter(L, "skipLogo", SplashScreen_get_skipLogo);
    registerGetter(L, "delay", SplashScreen_get_delay);
    registerGetter(L, "mainPanel", SplashScreen_get_mainPanel);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "currentState", SplashScreen_set_currentState);
    registerSetter(L, "startTime", SplashScreen_set_startTime);
    registerSetter(L, "skipLogo", SplashScreen_set_skipLogo);
    registerSetter(L, "delay", SplashScreen_set_delay);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua