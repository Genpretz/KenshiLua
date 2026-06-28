#include "pch.h"
#include "kenshi\CharMovement.h"
#include "MotionFilterBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MotionFilter* getB(lua_State* L, int idx)
{
    return checkObject<MotionFilter>(L, idx, MotionFilterBinding::getMetatableName());
}

// --- Getters for MotionFilter ---
static int MotionFilter_get_mWeightModifier(lua_State* L)
{
    MotionFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MotionFilter is nil");
    lua_pushnumber(L, b->mWeightModifier);
    return 1;
}

static int MotionFilter_get_mHistoryBufferX(lua_State* L)
{
    MotionFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MotionFilter is nil");
    // TODO: Unsupported type for mHistoryBufferX (std::deque<float, std::allocator<float> >)
    return luaL_error(L, "Unsupported property 'mHistoryBufferX' (type: std::deque<float, std::allocator<float> >)");
}

// --- Setters for MotionFilter ---
static int MotionFilter_set_mWeightModifier(lua_State* L)
{
    MotionFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MotionFilter is nil");
    b->mWeightModifier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MotionFilter_set_mHistoryBufferX(lua_State* L)
{
    MotionFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MotionFilter is nil");
    return luaL_error(L, "Read-only or unsupported setter type for mHistoryBufferX");
}

int MotionFilterBinding::SetHistoryBufferLength(lua_State* L)
{
    MotionFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MotionFilter is nil");

    int length = (int)luaL_checkinteger(L, 2);
    float fill = (float)luaL_checknumber(L, 3);
    bool result = b->SetHistoryBufferLength(length, fill);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MotionFilterBinding::_DESTRUCTOR(lua_State* L)
{
    MotionFilter* b = getB(L, 1);
    if (!b) return luaL_error(L, "MotionFilter is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 265: MotionFilter* _CONSTRUCTOR(...) - unsupported return type
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
    lua_pushcfunction(L, MotionFilter_get_mWeightModifier);
    lua_setfield(L, -2, "mWeightModifier");
    lua_pushcfunction(L, MotionFilter_get_mHistoryBufferX);
    lua_setfield(L, -2, "mHistoryBufferX");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, MotionFilter_set_mWeightModifier);
    lua_setfield(L, -2, "mWeightModifier");
    lua_pushcfunction(L, MotionFilter_set_mHistoryBufferX);
    lua_setfield(L, -2, "mHistoryBufferX");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua