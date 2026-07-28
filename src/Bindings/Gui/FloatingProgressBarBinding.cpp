#include "pch.h"
#include "kenshi\gui\ScreenLabel.h"
#include "FloatingProgressBarBinding.h"
#include "ScreenLabelInterfaceBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static FloatingProgressBar* getInstance(lua_State* L, int idx)
{
    return checkObject<FloatingProgressBar>(L, idx, FloatingProgressBarBinding::getMetatableName());
}

// --- Getters for FloatingProgressBar ---
static int FloatingProgressBar_get_caption(lua_State* L)
{
    FloatingProgressBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FloatingProgressBar is nil");
    lua_pushstring(L, instance->caption.c_str());
    return 1;
}

static int FloatingProgressBar_get_progress(lua_State* L)
{
    FloatingProgressBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FloatingProgressBar is nil");
    lua_pushinteger(L, instance->progress);
    return 1;
}

static int FloatingProgressBar_get_bar(lua_State* L)
{
    FloatingProgressBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FloatingProgressBar is nil");
    lua_pushlightuserdata(L, (void*)instance->bar);
    return 1;
}

// --- Setters for FloatingProgressBar ---
static int FloatingProgressBar_set_caption(lua_State* L)
{
    FloatingProgressBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FloatingProgressBar is nil");
    instance->caption = luaL_checkstring(L, 2);
    return 0;
}

static int FloatingProgressBar_set_progress(lua_State* L)
{
    FloatingProgressBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FloatingProgressBar is nil");
    instance->progress = (int)luaL_checkinteger(L, 2);
    return 0;
}

int FloatingProgressBarBinding::_CONSTRUCTOR(lua_State* L)
{
    FloatingProgressBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FloatingProgressBar is nil");

    FloatingProgressBar* result = instance->_CONSTRUCTOR();
    return pushObject<FloatingProgressBar>(L, result, FloatingProgressBarBinding::getMetatableName());
}

int FloatingProgressBarBinding::_DESTRUCTOR(lua_State* L)
{
    FloatingProgressBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FloatingProgressBar is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int FloatingProgressBarBinding::setProgress(lua_State* L)
{
    FloatingProgressBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FloatingProgressBar is nil");

    float value = (float)luaL_checknumber(L, 2);
    instance->setProgress(value);
    return 0;
}

int FloatingProgressBarBinding::setCaption(lua_State* L)
{
    FloatingProgressBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FloatingProgressBar is nil");

    const std::string value = luaL_checkstring(L, 2);
    instance->setCaption(value);
    return 0;
}

int FloatingProgressBarBinding::update(lua_State* L)
{
    FloatingProgressBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FloatingProgressBar is nil");

    instance->update();
    return 0;
}

int FloatingProgressBarBinding::_NV_update(lua_State* L)
{
    FloatingProgressBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FloatingProgressBar is nil");

    instance->_NV_update();
    return 0;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - FloatingProgressBar_get_bar: FloatingProgressBar::ProgressBarWidget* (unbound pointer)
*/

int FloatingProgressBarBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FloatingProgressBarBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FloatingProgressBar object");
    return 1;
}

void FloatingProgressBarBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FloatingProgressBarBinding::gc },
        { "__tostring", FloatingProgressBarBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", FloatingProgressBarBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", FloatingProgressBarBinding::_DESTRUCTOR },
        { "setProgress", FloatingProgressBarBinding::setProgress },
        { "setCaption", FloatingProgressBarBinding::setCaption },
        { "update", FloatingProgressBarBinding::update },
        { "_NV_update", FloatingProgressBarBinding::_NV_update },
        { 0, 0 }
    };

    registerClass(
        L, 
        FloatingProgressBarBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FloatingProgressBarBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "caption", FloatingProgressBar_get_caption);
    registerGetter(L, "progress", FloatingProgressBar_get_progress);
    registerGetter(L, "bar", FloatingProgressBar_get_bar);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "caption", FloatingProgressBar_set_caption);
    registerSetter(L, "progress", FloatingProgressBar_set_progress);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ScreenLabelInterface
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, FloatingProgressBarBinding::getMetatableName(), ScreenLabelInterfaceBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua