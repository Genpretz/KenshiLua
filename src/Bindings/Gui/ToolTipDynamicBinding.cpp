#include "pch.h"
#include <kenshi/gui/ToolTip.h>
#include "ToolTipDynamicBinding.h"
#include "ToolTipBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ToolTipDynamic* getInstance(lua_State* L, int idx)
{
    return checkObject<ToolTipDynamic>(L, idx, ToolTipDynamicBinding::getMetatableName());
}

// --- Getters for ToolTipDynamic ---
// --- Setters for ToolTipDynamic ---
int ToolTipDynamicBinding::_CONSTRUCTOR(lua_State* L)
{
    ToolTipDynamic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipDynamic is nil");

    ToolTipDynamic* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ToolTipDynamicBinding::_DESTRUCTOR(lua_State* L)
{
    ToolTipDynamic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipDynamic is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ToolTipDynamicBinding::setVisible(lua_State* L)
{
    ToolTipDynamic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipDynamic is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setVisible(visible);
    return 0;
}

int ToolTipDynamicBinding::_NV_setVisible(lua_State* L)
{
    ToolTipDynamic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipDynamic is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(visible);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 146: void setPosition(...) - unsupported arg type
  line 147: void _NV_setPosition(...) - unsupported arg type
*/

int ToolTipDynamicBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ToolTipDynamicBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ToolTipDynamic object");
    return 1;
}

void ToolTipDynamicBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ToolTipDynamicBinding::gc },
        { "__tostring", ToolTipDynamicBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ToolTipDynamicBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ToolTipDynamicBinding::_DESTRUCTOR },
        { "setVisible", ToolTipDynamicBinding::setVisible },
        { "_NV_setVisible", ToolTipDynamicBinding::_NV_setVisible },
        { 0, 0 }
    };

    registerClass(
        L, 
        ToolTipDynamicBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ToolTipDynamicBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ToolTip
    // setMetatableParent(L, ToolTipDynamicBinding::getMetatableName(), ToolTipBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
