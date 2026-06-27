#include "pch.h"
#include <kenshi/gui/GUIWindow.h>
#include "GUIWindowBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static GUIWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<GUIWindow>(L, idx, GUIWindowBinding::getMetatableName());
}

// --- Getters for GUIWindow ---
static int GUIWindow_get_win(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->win);
    return 1;
}

static int GUIWindow_get_selectedObject(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");
    // TODO: Unsupported type for selectedObject (hand)
    lua_pushnil(L);
    return 1;
}

// --- Setters for GUIWindow ---
static int GUIWindow_set_win(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for win");
}

static int GUIWindow_set_selectedObject(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for selectedObject");
}

int GUIWindowBinding::_CONSTRUCTOR(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    GUIWindow* result = instance->_CONSTRUCTOR();
    return pushObject<GUIWindow>(L, result, GUIWindowBinding::getMetatableName());
}

int GUIWindowBinding::_DESTRUCTOR(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int GUIWindowBinding::clear(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    instance->clear();
    return 0;
}

int GUIWindowBinding::_NV_clear(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    instance->_NV_clear();
    return 0;
}

int GUIWindowBinding::show(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    bool _a1 = lua_toboolean(L, 2) != 0;
    instance->show(_a1);
    return 0;
}

int GUIWindowBinding::setPositionReal(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    instance->setPositionReal(x, y);
    return 0;
}

int GUIWindowBinding::_NV_setPositionReal(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    instance->_NV_setPositionReal(x, y);
    return 0;
}

int GUIWindowBinding::setPosition(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    instance->setPosition(x, y);
    return 0;
}

int GUIWindowBinding::_NV_setPosition(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    instance->_NV_setPosition(x, y);
    return 0;
}

int GUIWindowBinding::getWidth(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    int result = instance->getWidth();
    lua_pushinteger(L, result);
    return 1;
}

int GUIWindowBinding::_NV_getWidth(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    int result = instance->_NV_getWidth();
    lua_pushinteger(L, result);
    return 1;
}

int GUIWindowBinding::getHeight(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    int result = instance->getHeight();
    lua_pushinteger(L, result);
    return 1;
}

int GUIWindowBinding::_NV_getHeight(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    int result = instance->_NV_getHeight();
    lua_pushinteger(L, result);
    return 1;
}

int GUIWindowBinding::getWidthReal(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    float result = instance->getWidthReal();
    lua_pushnumber(L, result);
    return 1;
}

int GUIWindowBinding::_NV_getWidthReal(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    float result = instance->_NV_getWidthReal();
    lua_pushnumber(L, result);
    return 1;
}

int GUIWindowBinding::getHeightReal(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    float result = instance->getHeightReal();
    lua_pushnumber(L, result);
    return 1;
}

int GUIWindowBinding::_NV_getHeightReal(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    float result = instance->_NV_getHeightReal();
    lua_pushnumber(L, result);
    return 1;
}

int GUIWindowBinding::isVisible(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    bool result = instance->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GUIWindowBinding::_NV_isVisible(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    bool result = instance->_NV_isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GUIWindowBinding::update(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    instance->update();
    return 0;
}

int GUIWindowBinding::_NV_update(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    instance->_NV_update();
    return 0;
}

int GUIWindowBinding::getWidget(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    MyGUI::Widget* result = instance->getWidget();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int GUIWindowBinding::resize(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    int w = (int)luaL_checkinteger(L, 2);
    int h = (int)luaL_checkinteger(L, 3);
    instance->resize(w, h);
    return 0;
}

int GUIWindowBinding::_NV_resize(lua_State* L)
{
    GUIWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GUIWindow is nil");

    int w = (int)luaL_checkinteger(L, 2);
    int h = (int)luaL_checkinteger(L, 3);
    instance->_NV_resize(w, h);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 36: void autoChangeSelectedObject(...) - unsupported arg type
  line 37: void _NV_autoChangeSelectedObject(...) - unsupported arg type
*/

int GUIWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GUIWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GUIWindow object");
    return 1;
}

void GUIWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GUIWindowBinding::gc },
        { "__tostring", GUIWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", GUIWindowBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", GUIWindowBinding::_DESTRUCTOR },
        { "clear", GUIWindowBinding::clear },
        { "_NV_clear", GUIWindowBinding::_NV_clear },
        { "show", GUIWindowBinding::show },
        { "setPositionReal", GUIWindowBinding::setPositionReal },
        { "_NV_setPositionReal", GUIWindowBinding::_NV_setPositionReal },
        { "setPosition", GUIWindowBinding::setPosition },
        { "_NV_setPosition", GUIWindowBinding::_NV_setPosition },
        { "getWidth", GUIWindowBinding::getWidth },
        { "_NV_getWidth", GUIWindowBinding::_NV_getWidth },
        { "getHeight", GUIWindowBinding::getHeight },
        { "_NV_getHeight", GUIWindowBinding::_NV_getHeight },
        { "getWidthReal", GUIWindowBinding::getWidthReal },
        { "_NV_getWidthReal", GUIWindowBinding::_NV_getWidthReal },
        { "getHeightReal", GUIWindowBinding::getHeightReal },
        { "_NV_getHeightReal", GUIWindowBinding::_NV_getHeightReal },
        { "isVisible", GUIWindowBinding::isVisible },
        { "_NV_isVisible", GUIWindowBinding::_NV_isVisible },
        { "update", GUIWindowBinding::update },
        { "_NV_update", GUIWindowBinding::_NV_update },
        { "getWidget", GUIWindowBinding::getWidget },
        { "resize", GUIWindowBinding::resize },
        { "_NV_resize", GUIWindowBinding::_NV_resize },
        { 0, 0 }
    };

    registerClass(
        L, 
        GUIWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GUIWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, GUIWindow_get_win);
    lua_setfield(L, -2, "win");
    lua_pushcfunction(L, GUIWindow_get_selectedObject);
    lua_setfield(L, -2, "selectedObject");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, GUIWindow_set_win);
    lua_setfield(L, -2, "win");
    lua_pushcfunction(L, GUIWindow_set_selectedObject);
    lua_setfield(L, -2, "selectedObject");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // // setMetatableParent(L, GUIWindowBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua