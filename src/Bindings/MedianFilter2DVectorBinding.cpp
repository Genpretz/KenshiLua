#include "pch.h"
#include "kenshi\CharMovement.h"
#include "MedianFilter2DVectorBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MedianFilter2DVector* getB(lua_State* L, int idx)
{
    return checkObject<MedianFilter2DVector>(L, idx, MedianFilter2DVectorBinding::getMetatableName());
}

// --- Getters for MedianFilter2DVector ---
static int MedianFilter2DVector_get_filters(lua_State* L)
{
    MedianFilter2DVector* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter2DVector is nil");
    // TODO: Unsupported type for filters (MedianFilter)
    return luaL_error(L, "Unsupported property 'filters' (type: MedianFilter)");
}

// --- Setters for MedianFilter2DVector ---
static int MedianFilter2DVector_set_filters(lua_State* L)
{
    MedianFilter2DVector* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter2DVector is nil");
    return luaL_error(L, "Read-only or unsupported setter type for filters");
}

int MedianFilter2DVectorBinding::setup(lua_State* L)
{
    MedianFilter2DVector* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter2DVector is nil");

    int numFrames = (int)luaL_checkinteger(L, 2);
    int numSamples = (int)luaL_checkinteger(L, 3);
    bool positions = lua_toboolean(L, 4) != 0;
    b->setup(numFrames, numSamples, positions);
    return 0;
}

int MedianFilter2DVectorBinding::reset(lua_State* L)
{
    MedianFilter2DVector* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter2DVector is nil");

    b->reset();
    return 0;
}

int MedianFilter2DVectorBinding::_DESTRUCTOR(lua_State* L)
{
    MedianFilter2DVector* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter2DVector is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 107: MedianFilter2DVector* _CONSTRUCTOR(...) - unsupported return type
*/

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
    lua_pushcfunction(L, MedianFilter2DVector_get_filters);
    lua_setfield(L, -2, "filters");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, MedianFilter2DVector_set_filters);
    lua_setfield(L, -2, "filters");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua