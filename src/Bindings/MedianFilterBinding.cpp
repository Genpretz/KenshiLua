#include "pch.h"
#include "kenshi\CharMovement.h"
#include "MedianFilterBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MedianFilter* getB(lua_State* L, int idx)
{
    return checkObject<MedianFilter>(L, idx, MedianFilterBinding::getMetatableName());
}

// --- Getters for MedianFilter ---
static int MedianFilter_get_isPositionsFilter(lua_State* L)
{
    MedianFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter is nil");
    lua_pushboolean(L, b->isPositionsFilter ? 1 : 0);
    return 1;
}

static int MedianFilter_get_edgeSkips(lua_State* L)
{
    MedianFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter is nil");
    lua_pushinteger(L, b->edgeSkips);
    return 1;
}

static int MedianFilter_get_maxLength(lua_State* L)
{
    MedianFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter is nil");
    lua_pushinteger(L, b->maxLength);
    return 1;
}

static int MedianFilter_get_mHistoryBufferX(lua_State* L)
{
    MedianFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter is nil");
    // TODO: Unsupported type for mHistoryBufferX (std::deque<float, std::allocator<float> >)
    return luaL_error(L, "Unsupported property 'mHistoryBufferX' (type: std::deque<float, std::allocator<float> >)");
}

// --- Setters for MedianFilter ---
static int MedianFilter_set_isPositionsFilter(lua_State* L)
{
    MedianFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter is nil");
    b->isPositionsFilter = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedianFilter_set_edgeSkips(lua_State* L)
{
    MedianFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter is nil");
    b->edgeSkips = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int MedianFilter_set_maxLength(lua_State* L)
{
    MedianFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter is nil");
    b->maxLength = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int MedianFilter_set_mHistoryBufferX(lua_State* L)
{
    MedianFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter is nil");
    return luaL_error(L, "Read-only or unsupported setter type for mHistoryBufferX");
}

int MedianFilterBinding::setup(lua_State* L)
{
    MedianFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter is nil");

    int numFrames = (int)luaL_checkinteger(L, 2);
    int numSamples = (int)luaL_checkinteger(L, 3);
    bool _isPositionsFilter = lua_toboolean(L, 4) != 0;
    b->setup(numFrames, numSamples, _isPositionsFilter);
    return 0;
}

int MedianFilterBinding::reset(lua_State* L)
{
    MedianFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter is nil");

    b->reset();
    return 0;
}

int MedianFilterBinding::applySilent(lua_State* L)
{
    MedianFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter is nil");

    float delta_mouse_x = (float)luaL_checknumber(L, 2);
    b->applySilent(delta_mouse_x);
    return 0;
}

int MedianFilterBinding::_DESTRUCTOR(lua_State* L)
{
    MedianFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedianFilter is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 87: MedianFilter* _CONSTRUCTOR(...) - unsupported return type
  line 91: void apply(...) - non-string reference arg
*/

int MedianFilterBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MedianFilterBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MedianFilter object");
    return 1;
}

void MedianFilterBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MedianFilterBinding::gc },
        { "__tostring", MedianFilterBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setup", MedianFilterBinding::setup },
        { "reset", MedianFilterBinding::reset },
        { "applySilent", MedianFilterBinding::applySilent },
        { "_DESTRUCTOR", MedianFilterBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        MedianFilterBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MedianFilterBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, MedianFilter_get_isPositionsFilter);
    lua_setfield(L, -2, "isPositionsFilter");
    lua_pushcfunction(L, MedianFilter_get_edgeSkips);
    lua_setfield(L, -2, "edgeSkips");
    lua_pushcfunction(L, MedianFilter_get_maxLength);
    lua_setfield(L, -2, "maxLength");
    lua_pushcfunction(L, MedianFilter_get_mHistoryBufferX);
    lua_setfield(L, -2, "mHistoryBufferX");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, MedianFilter_set_isPositionsFilter);
    lua_setfield(L, -2, "isPositionsFilter");
    lua_pushcfunction(L, MedianFilter_set_edgeSkips);
    lua_setfield(L, -2, "edgeSkips");
    lua_pushcfunction(L, MedianFilter_set_maxLength);
    lua_setfield(L, -2, "maxLength");
    lua_pushcfunction(L, MedianFilter_set_mHistoryBufferX);
    lua_setfield(L, -2, "mHistoryBufferX");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
