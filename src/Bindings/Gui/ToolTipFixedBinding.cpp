#include "pch.h"
#include <kenshi/gui/ToolTip.h>
#include "ToolTipFixedBinding.h"
#include "ToolTipBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ToolTipFixed* getInstance(lua_State* L, int idx)
{
    return checkObject<ToolTipFixed>(L, idx, ToolTipFixedBinding::getMetatableName());
}

// --- Getters for ToolTipFixed ---
static int ToolTipFixed_get_parentPanel(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    lua_pushlightuserdata(L, (void*)instance->parentPanel);
    return 1;
}

static int ToolTipFixed_get_minHeight(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    lua_pushinteger(L, instance->minHeight);
    return 1;
}

// --- Setters for ToolTipFixed ---
static int ToolTipFixed_set_minHeight(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    instance->minHeight = (int)luaL_checkinteger(L, 2);
    return 0;
}

int ToolTipFixedBinding::_DESTRUCTOR(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ToolTipFixedBinding::update(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");

    instance->update();
    return 0;
}

int ToolTipFixedBinding::_NV_update(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");

    instance->_NV_update();
    return 0;
}

int ToolTipFixedBinding::setVisible(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setVisible(visible);
    return 0;
}

int ToolTipFixedBinding::_NV_setVisible(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(visible);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 90: ToolTipFixed* _CONSTRUCTOR(...) - unsupported arg type
  line 93: void clear(...) - unsupported arg type
  line 94: void _NV_clear(...) - unsupported arg type
  line 97: void setBottomPosition(...) - unsupported arg type
  line 100: void setPosition(...) - unsupported arg type
  line 101: void _NV_setPosition(...) - unsupported arg type
  line 102: void _setup(...) - unsupported arg type
  line 103: void _NV__setup(...) - unsupported arg type
  line 104: void mouseMoved(...) - unsupported arg type
*/

int ToolTipFixedBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ToolTipFixedBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ToolTipFixed object");
    return 1;
}

void ToolTipFixedBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ToolTipFixedBinding::gc },
        { "__tostring", ToolTipFixedBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ToolTipFixedBinding::_DESTRUCTOR },
        { "update", ToolTipFixedBinding::update },
        { "_NV_update", ToolTipFixedBinding::_NV_update },
        { "setVisible", ToolTipFixedBinding::setVisible },
        { "_NV_setVisible", ToolTipFixedBinding::_NV_setVisible },
        { 0, 0 }
    };

    registerClass(
        L, 
        ToolTipFixedBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ToolTipFixedBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ToolTipFixed_get_parentPanel);
    lua_setfield(L, -2, "parentPanel");
    lua_pushcfunction(L, ToolTipFixed_get_minHeight);
    lua_setfield(L, -2, "minHeight");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ToolTipFixed_set_minHeight);
    lua_setfield(L, -2, "minHeight");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ToolTip
    // setMetatableParent(L, ToolTipFixedBinding::getMetatableName(), ToolTipBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
