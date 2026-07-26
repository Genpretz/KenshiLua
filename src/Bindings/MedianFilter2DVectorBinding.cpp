#include "pch.h"
#include "kenshi\CharMovement.h"
#include "MedianFilter2DVectorBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/MedianFilterBinding.h"

namespace KenshiLua
{

static MedianFilter2DVector* getInstance(lua_State* L, int idx)
{
    return checkObject<MedianFilter2DVector>(L, idx, MedianFilter2DVectorBinding::getMetatableName());
}

// --- Getters for MedianFilter2DVector ---
static int MedianFilter2DVector_get_filters(lua_State* L) { return 0; }

// --- Setters for MedianFilter2DVector ---
static int MedianFilter2DVector_set_filters(lua_State* L) { return 0; }

int MedianFilter2DVectorBinding::_CONSTRUCTOR(lua_State* L)
{
    MedianFilter2DVector* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter2DVector is nil");

    MedianFilter2DVector* result = instance->_CONSTRUCTOR();
    return pushObject<MedianFilter2DVector>(L, result, MedianFilter2DVectorBinding::getMetatableName());
}

int MedianFilter2DVectorBinding::setup(lua_State* L)
{
    MedianFilter2DVector* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter2DVector is nil");

    int numFrames = (int)luaL_checkinteger(L, 2);
    int numSamples = (int)luaL_checkinteger(L, 3);
    bool positions = lua_toboolean(L, 4) != 0;
    instance->setup(numFrames, numSamples, positions);
    return 0;
}

int MedianFilter2DVectorBinding::reset(lua_State* L)
{
    MedianFilter2DVector* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter2DVector is nil");

    instance->reset();
    return 0;
}

int MedianFilter2DVectorBinding::_DESTRUCTOR(lua_State* L)
{
    MedianFilter2DVector* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter2DVector is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int MedianFilter2DVectorBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MedianFilter2DVectorBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MedianFilter2DVector object");
    return 1;
}

void MedianFilter2DVectorBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MedianFilter2DVectorBinding::gc },
        { "__tostring", MedianFilter2DVectorBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", MedianFilter2DVectorBinding::_CONSTRUCTOR },
        { "setup", MedianFilter2DVectorBinding::setup },
        { "reset", MedianFilter2DVectorBinding::reset },
        { "_DESTRUCTOR", MedianFilter2DVectorBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        MedianFilter2DVectorBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MedianFilter2DVectorBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "filters", MedianFilter2DVector_get_filters);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "filters", MedianFilter2DVector_set_filters);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua