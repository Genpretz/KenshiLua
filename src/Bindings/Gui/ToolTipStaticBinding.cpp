#include "pch.h"
#include <kenshi/gui/ToolTip.h>
#include "ToolTipStaticBinding.h"
#include "ToolTipBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ToolTipStatic* getInstance(lua_State* L, int idx)
{
    return checkObject<ToolTipStatic>(L, idx, ToolTipStaticBinding::getMetatableName());
}

// --- Getters for ToolTipStatic ---
// --- Setters for ToolTipStatic ---
int ToolTipStaticBinding::_DESTRUCTOR(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ToolTipStaticBinding::update(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");

    instance->update();
    return 0;
}

int ToolTipStaticBinding::_NV_update(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");

    instance->_NV_update();
    return 0;
}

int ToolTipStaticBinding::setVisible(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setVisible(visible);
    return 0;
}

int ToolTipStaticBinding::_NV_setVisible(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(visible);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 117: ToolTipStatic* _CONSTRUCTOR(...) - unsupported arg type
  line 122: void clear(...) - unsupported arg type
  line 123: void _NV_clear(...) - unsupported arg type
  line 124: void _setup(...) - unsupported arg type
  line 125: void _NV__setup(...) - unsupported arg type
  line 128: void setPosition(...) - unsupported arg type
  line 129: void _NV_setPosition(...) - unsupported arg type
  line 130: void mouseMoved(...) - unsupported arg type
*/

int ToolTipStaticBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ToolTipStaticBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ToolTipStatic object");
    return 1;
}

void ToolTipStaticBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ToolTipStaticBinding::gc },
        { "__tostring", ToolTipStaticBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ToolTipStaticBinding::_DESTRUCTOR },
        { "update", ToolTipStaticBinding::update },
        { "_NV_update", ToolTipStaticBinding::_NV_update },
        { "setVisible", ToolTipStaticBinding::setVisible },
        { "_NV_setVisible", ToolTipStaticBinding::_NV_setVisible },
        { 0, 0 }
    };

    registerClass(
        L, 
        ToolTipStaticBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ToolTipStaticBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ToolTip
    setMetatableParent(L, ToolTipStaticBinding::getMetatableName(), ToolTipBinding::getMetatableName());

        // Wire up inheritance
    setMetatableParent(L, ToolTipStaticBinding::getMetatableName(), ToolTipBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua