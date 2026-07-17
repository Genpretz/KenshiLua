#include "pch.h"
#include <kenshi/gui/ToolTip.h>
#include "ToolTipBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ToolTip* getInstance(lua_State* L, int idx)
{
    return checkObject<ToolTip>(L, idx, ToolTipBinding::getMetatableName());
}

// --- Getters for ToolTip ---
static int ToolTip_get_panel(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    lua_pushlightuserdata(L, (void*)instance->panel);
    return 1;
}

static int ToolTip_get_panelWidth(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    lua_pushinteger(L, instance->panelWidth);
    return 1;
}

static int ToolTip_get_lineMarginH(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    lua_pushnumber(L, instance->lineMarginH);
    return 1;
}

static int ToolTip_get_panelMarginV(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    lua_pushinteger(L, instance->panelMarginV);
    return 1;
}

static int ToolTip_get_lineSpacing(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    lua_pushinteger(L, instance->lineSpacing);
    return 1;
}

static int ToolTip_get_caller(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    lua_pushlightuserdata(L, (void*)instance->caller);
    return 1;
}

// --- Setters for ToolTip ---
static int ToolTip_set_panelWidth(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    instance->panelWidth = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ToolTip_set_lineMarginH(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    instance->lineMarginH = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ToolTip_set_panelMarginV(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    instance->panelMarginV = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ToolTip_set_lineSpacing(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    instance->lineSpacing = (int)luaL_checkinteger(L, 2);
    return 0;
}

int ToolTipBinding::_DESTRUCTOR(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ToolTipBinding::update(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    instance->update();
    return 0;
}

int ToolTipBinding::_NV_update(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    instance->_NV_update();
    return 0;
}

int ToolTipBinding::hide(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    instance->hide();
    return 0;
}

int ToolTipBinding::_NV_hide(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    instance->_NV_hide();
    return 0;
}

int ToolTipBinding::getVisible(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ToolTipBinding::setVisible(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setVisible(visible);
    return 0;
}

int ToolTipBinding::_NV_setVisible(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(visible);
    return 0;
}

int ToolTipBinding::addLine(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    std::string textLeft = luaL_checkstring(L, 2);
    std::string textRight = luaL_checkstring(L, 3);
    instance->addLine(textLeft, textRight);
    return 0;
}

int ToolTipBinding::clearLines(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    instance->clearLines();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 38: ToolTip* _CONSTRUCTOR(...) - unsupported arg type
  line 41: void setup(...) - overloaded method
  line 42: void setup(...) - overloaded method
  line 43: void setup(...) - overloaded method
  line 44: void setup(...) - overloaded method
  line 45: void clear(...) - unsupported arg type
  line 46: void _NV_clear(...) - unsupported arg type
  line 52: void _setup(...) - unsupported arg type
  line 53: void _NV__setup(...) - unsupported arg type
  line 54: void clearData(...) - unsupported arg type
  line 55: void _NV_clearData(...) - unsupported arg type
  line 56: void show(...) - unsupported arg type
  line 57: void _NV_show(...) - unsupported arg type
  line 58: void setContent(...) - unsupported arg type
  line 59: void _NV_setContent(...) - unsupported arg type
  line 60: void showText(...) - unsupported arg type
  line 61: void showMultiLine(...) - unsupported arg type
  line 62: void showGameData(...) - overloaded method
  line 63: void showGameData(...) - overloaded method
  line 66: void setPosition(...) - unsupported arg type
  line 67: void _NV_setPosition(...) - unsupported arg type
  line 70: void notifyToolTip(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 72: lines (Ogre::vector<ToolTip::ToolTipLine*>::type) - unsupported type
*/

int ToolTipBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ToolTipBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ToolTip object");
    return 1;
}

void ToolTipBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ToolTipBinding::gc },
        { "__tostring", ToolTipBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ToolTipBinding::_DESTRUCTOR },
        { "update", ToolTipBinding::update },
        { "_NV_update", ToolTipBinding::_NV_update },
        { "hide", ToolTipBinding::hide },
        { "_NV_hide", ToolTipBinding::_NV_hide },
        { "getVisible", ToolTipBinding::getVisible },
        { "setVisible", ToolTipBinding::setVisible },
        { "_NV_setVisible", ToolTipBinding::_NV_setVisible },
        { "addLine", ToolTipBinding::addLine },
        { "clearLines", ToolTipBinding::clearLines },
        { 0, 0 }
    };

    registerClass(
        L, 
        ToolTipBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ToolTipBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ToolTip_get_panel);
    lua_setfield(L, -2, "panel");
    lua_pushcfunction(L, ToolTip_get_panelWidth);
    lua_setfield(L, -2, "panelWidth");
    lua_pushcfunction(L, ToolTip_get_lineMarginH);
    lua_setfield(L, -2, "lineMarginH");
    lua_pushcfunction(L, ToolTip_get_panelMarginV);
    lua_setfield(L, -2, "panelMarginV");
    lua_pushcfunction(L, ToolTip_get_lineSpacing);
    lua_setfield(L, -2, "lineSpacing");
    lua_pushcfunction(L, ToolTip_get_caller);
    lua_setfield(L, -2, "caller");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ToolTip_set_panelWidth);
    lua_setfield(L, -2, "panelWidth");
    lua_pushcfunction(L, ToolTip_set_lineMarginH);
    lua_setfield(L, -2, "lineMarginH");
    lua_pushcfunction(L, ToolTip_set_panelMarginV);
    lua_setfield(L, -2, "panelMarginV");
    lua_pushcfunction(L, ToolTip_set_lineSpacing);
    lua_setfield(L, -2, "lineSpacing");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // // // // // // // // // setMetatableParent(L, ToolTipBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua