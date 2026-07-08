#include "pch.h"
#include <kenshi/gui/ToolTip.h>
#include "ToolTipLineBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    typedef ToolTip::ToolTipLine ToolTipLine;

static ToolTipLine* getInstance(lua_State* L, int idx)
{
    return checkObject<ToolTipLine>(L, idx, ToolTipLineBinding::getMetatableName());
}

// --- Getters for ToolTipLine ---
static int ToolTipLine_get_content(lua_State* L)
{
    ToolTipLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipLine is nil");
    lua_pushlightuserdata(L, (void*)instance->content);
    return 1;
}

static int ToolTipLine_get_leftBox(lua_State* L)
{
    ToolTipLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipLine is nil");
    lua_pushlightuserdata(L, (void*)instance->leftBox);
    return 1;
}

static int ToolTipLine_get_rightBox(lua_State* L)
{
    ToolTipLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipLine is nil");
    lua_pushlightuserdata(L, (void*)instance->rightBox);
    return 1;
}

static int ToolTipLine_get_width(lua_State* L)
{
    ToolTipLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipLine is nil");
    lua_pushinteger(L, instance->width);
    return 1;
}

// --- Setters for ToolTipLine ---
static int ToolTipLine_set_width(lua_State* L)
{
    ToolTipLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipLine is nil");
    instance->width = (int)luaL_checkinteger(L, 2);
    return 0;
}

int ToolTipLineBinding::_DESTRUCTOR(lua_State* L)
{
    ToolTipLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipLine is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 27: ToolTipLine* _CONSTRUCTOR(...) - unsupported arg type
*/

int ToolTipLineBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ToolTipLineBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ToolTipLine object");
    return 1;
}

void ToolTipLineBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ToolTipLineBinding::gc },
        { "__tostring", ToolTipLineBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ToolTipLineBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        ToolTipLineBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ToolTipLineBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ToolTipLine_get_content);
    lua_setfield(L, -2, "content");
    lua_pushcfunction(L, ToolTipLine_get_leftBox);
    lua_setfield(L, -2, "leftBox");
    lua_pushcfunction(L, ToolTipLine_get_rightBox);
    lua_setfield(L, -2, "rightBox");
    lua_pushcfunction(L, ToolTipLine_get_width);
    lua_setfield(L, -2, "width");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ToolTipLine_set_width);
    lua_setfield(L, -2, "width");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua