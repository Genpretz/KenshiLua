#include "pch.h"
#include "kenshi\CharMovement.h"
#include "MotionFilterBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/StdDequeBinding.h"

namespace KenshiLua
{
typedef StdDequePrimitiveBinding<float> FloatDequeBinding;


static MotionFilter* getInstance(lua_State* L, int idx)
{
    return checkObject<MotionFilter>(L, idx, MotionFilterBinding::getMetatableName());
}

// --- Getters for MotionFilter ---
static int MotionFilter_get_mWeightModifier(lua_State* L)
{
    MotionFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MotionFilter is nil");
    lua_pushnumber(L, instance->mWeightModifier);
    return 1;
}

static int MotionFilter_get_mHistoryBufferX(lua_State* L)
{
    MotionFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MotionFilter is nil");
    return pushObject<FloatDequeBinding::DequeType>(L, &instance->mHistoryBufferX, "std::deque<float>");
}

// --- Setters for MotionFilter ---
static int MotionFilter_set_mWeightModifier(lua_State* L)
{
    MotionFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MotionFilter is nil");
    instance->mWeightModifier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MotionFilter_set_mHistoryBufferX(lua_State* L)
{
    MotionFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MotionFilter is nil");
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

int MotionFilterBinding::_CONSTRUCTOR(lua_State* L)
{
    MotionFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MotionFilter is nil");

    int length = (int)luaL_checkinteger(L, 2);
    float weight_modifier = (float)luaL_checknumber(L, 3);
    float fill = (float)luaL_checknumber(L, 4);
    MotionFilter* result = instance->_CONSTRUCTOR(length, weight_modifier, fill);
    return pushObject<MotionFilter>(L, result, MotionFilterBinding::getMetatableName());
}

int MotionFilterBinding::SetHistoryBufferLength(lua_State* L)
{
    MotionFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MotionFilter is nil");

    int length = (int)luaL_checkinteger(L, 2);
    float fill = (float)luaL_checknumber(L, 3);
    bool result = instance->SetHistoryBufferLength(length, fill);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MotionFilterBinding::_DESTRUCTOR(lua_State* L)
{
    MotionFilter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MotionFilter is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 268: void Apply(...) - non-string reference arg
*/

int MotionFilterBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MotionFilterBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MotionFilter object");
    return 1;
}

void MotionFilterBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MotionFilterBinding::gc },
        { "__tostring", MotionFilterBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", MotionFilterBinding::_CONSTRUCTOR },
        { "SetHistoryBufferLength", MotionFilterBinding::SetHistoryBufferLength },
        { "_DESTRUCTOR", MotionFilterBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        MotionFilterBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MotionFilterBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "mWeightModifier", MotionFilter_get_mWeightModifier);
    registerGetter(L, "mHistoryBufferX", MotionFilter_get_mHistoryBufferX);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "mWeightModifier", MotionFilter_set_mWeightModifier);
    registerSetter(L, "mHistoryBufferX", MotionFilter_set_mHistoryBufferX);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    FloatDequeBinding::registerBinding(L, "std::deque<float>", nullptr);

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua