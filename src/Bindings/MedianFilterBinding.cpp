#include "pch.h"
#include "kenshi\CharMovement.h"
#include "MedianFilterBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/StdDequeBinding.h"

namespace KenshiLua
{
typedef StdDequePrimitiveBinding<float> FloatDequeBinding;


static MedianFilter* getInstance(lua_State* L, int idx)
{
    return checkObject<MedianFilter>(L, idx, MedianFilterBinding::getMetatableName());
}

// --- Getters for MedianFilter ---
static int MedianFilter_get_isPositionsFilter(lua_State* L)
{
    MedianFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter is nil");
    lua_pushboolean(L, instance->isPositionsFilter ? 1 : 0);
    return 1;
}

static int MedianFilter_get_edgeSkips(lua_State* L)
{
    MedianFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter is nil");
    lua_pushinteger(L, instance->edgeSkips);
    return 1;
}

static int MedianFilter_get_maxLength(lua_State* L)
{
    MedianFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter is nil");
    lua_pushinteger(L, instance->maxLength);
    return 1;
}

static int MedianFilter_get_mHistoryBufferX(lua_State* L)
{
    MedianFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter is nil");
    return pushObject<FloatDequeBinding::DequeType>(L, &instance->mHistoryBufferX, "std::deque<float>");
}

// --- Setters for MedianFilter ---
static int MedianFilter_set_isPositionsFilter(lua_State* L)
{
    MedianFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter is nil");
    instance->isPositionsFilter = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedianFilter_set_edgeSkips(lua_State* L)
{
    MedianFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter is nil");
    instance->edgeSkips = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int MedianFilter_set_maxLength(lua_State* L)
{
    MedianFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter is nil");
    instance->maxLength = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int MedianFilter_set_mHistoryBufferX(lua_State* L)
{
    MedianFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter is nil");
    if (lua_isnoneornil(L, 2))
    {
        instance->mHistoryBufferX.clear();
        return 0;
    }
    auto* src = FloatDequeBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set mHistoryBufferX must be std::deque<float>");
    instance->mHistoryBufferX = *src;
    return 0;
}

int MedianFilterBinding::_CONSTRUCTOR(lua_State* L)
{
    MedianFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter is nil");

    MedianFilter* result = instance->_CONSTRUCTOR();
    return pushObject<MedianFilter>(L, result, MedianFilterBinding::getMetatableName());
}

int MedianFilterBinding::setup(lua_State* L)
{
    MedianFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter is nil");

    int numFrames = (int)luaL_checkinteger(L, 2);
    int numSamples = (int)luaL_checkinteger(L, 3);
    bool _isPositionsFilter = lua_toboolean(L, 4) != 0;
    instance->setup(numFrames, numSamples, _isPositionsFilter);
    return 0;
}

int MedianFilterBinding::reset(lua_State* L)
{
    MedianFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter is nil");

    instance->reset();
    return 0;
}

int MedianFilterBinding::applySilent(lua_State* L)
{
    MedianFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter is nil");

    float delta_mouse_x = (float)luaL_checknumber(L, 2);
    instance->applySilent(delta_mouse_x);
    return 0;
}

int MedianFilterBinding::_DESTRUCTOR(lua_State* L)
{
    MedianFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedianFilter is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
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
        { "_CONSTRUCTOR", MedianFilterBinding::_CONSTRUCTOR },
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
    registerGetter(L, "isPositionsFilter", MedianFilter_get_isPositionsFilter);
    registerGetter(L, "edgeSkips", MedianFilter_get_edgeSkips);
    registerGetter(L, "maxLength", MedianFilter_get_maxLength);
    registerGetter(L, "mHistoryBufferX", MedianFilter_get_mHistoryBufferX);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "isPositionsFilter", MedianFilter_set_isPositionsFilter);
    registerSetter(L, "edgeSkips", MedianFilter_set_edgeSkips);
    registerSetter(L, "maxLength", MedianFilter_set_maxLength);
    registerSetter(L, "mHistoryBufferX", MedianFilter_set_mHistoryBufferX);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    FloatDequeBinding::registerBinding(L, "std::deque<float>", nullptr);

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua