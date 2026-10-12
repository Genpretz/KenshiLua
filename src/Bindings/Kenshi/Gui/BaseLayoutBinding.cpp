#include "pch.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "mygui\common\baselayout\BaseLayout.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static wraps::BaseLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<wraps::BaseLayout>(L, idx, BaseLayoutBinding::getMetatableName());
}

// --- Getters for BaseLayout ---
static int BaseLayout_get_mMainWidget(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");
    return MyGUIBindings::pushWidget(L, instance->mMainWidget);
}

static int BaseLayout_get_mPrefix(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");
    lua_pushstring(L, instance->mPrefix.c_str());
    return 1;
}

static int BaseLayout_get_mLayoutName(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");
    lua_pushstring(L, instance->mLayoutName.c_str());
    return 1;
}

// --- Setters for BaseLayout ---
static int BaseLayout_set_mPrefix(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");
    instance->mPrefix = luaL_checkstring(L, 2);
    return 0;
}

static int BaseLayout_set_mLayoutName(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");
    instance->mLayoutName = luaL_checkstring(L, 2);
    return 0;
}

static int BaseLayout_assignWidget(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");

    std::string name = luaL_checkstring(L, 2);
    if (!lua_isnoneornil(L, 3))
        luaL_checktype(L, 3, LUA_TBOOLEAN);
    if (!lua_isnoneornil(L, 4))
        luaL_checktype(L, 4, LUA_TBOOLEAN);
    bool doThrow = lua_isnoneornil(L, 3)
        ? true
        : lua_toboolean(L, 3) != 0;
    bool createFakeWidgets = lua_isnoneornil(L, 4)
        ? true
        : lua_toboolean(L, 4) != 0;

    MyGUI::Widget* widget = nullptr;
    instance->assignWidget(widget, name, doThrow, createFakeWidgets);
    return MyGUIBindings::pushWidget(L, widget);
}

static int BaseLayout_initialise(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");

    std::string layoutName = luaL_checkstring(L, 2);
    MyGUI::Widget* parent = nullptr;
    if (!lua_isnoneornil(L, 3))
    {
        parent = MyGUIBindings::toWidget(L, 3);
        if (!parent)
            return luaL_argerror(L, 3, "MyGUI.Widget or nil expected");
    }
    if (!lua_isnoneornil(L, 4))
        luaL_checktype(L, 4, LUA_TBOOLEAN);
    if (!lua_isnoneornil(L, 5))
        luaL_checktype(L, 5, LUA_TBOOLEAN);
    bool doThrow = lua_isnoneornil(L, 4)
        ? true
        : lua_toboolean(L, 4) != 0;
    bool createFakeWidgets = lua_isnoneornil(L, 5)
        ? true
        : lua_toboolean(L, 5) != 0;

    instance->initialise(layoutName, parent, doThrow, createFakeWidgets);
    return 0;
}

// static int BaseLayout_shutdown(lua_State* L)
// {
//     wraps::BaseLayout* instance = getInstance(L, 1);
//     if (!instance) return luaL_error(L, "BaseLayout is nil");

//     instance->shutdown();
//     return 0;
// }

static int BaseLayout_FindParentPrefix(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");

    MyGUI::Widget* parent = MyGUIBindings::toWidget(L, 2);
    if (!parent)
        return luaL_argerror(L, 2, "MyGUI.Widget expected");

    std::string result = instance->FindParentPrefix(parent);
    lua_pushstring(L, result.c_str());
    return 1;
}

static int BaseLayout_snapToParent(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");

    MyGUI::Widget* child = MyGUIBindings::toWidget(L, 2);
    if (!child)
        return luaL_argerror(L, 2, "MyGUI.Widget expected");

    instance->snapToParent(child);
    return 0;
}

static int BaseLayout_createFakeWidgetT(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");

    std::string typeName = luaL_checkstring(L, 2);
    luaL_checkany(L, 3);
    MyGUI::Widget* parent = nullptr;
    if (!lua_isnil(L, 3))
    {
        parent = MyGUIBindings::toWidget(L, 3);
        if (!parent)
            return luaL_argerror(L, 3, "MyGUI.Widget or nil expected");
    }

    MyGUI::Widget* widget = instance->_createFakeWidgetT(typeName, parent);
    return MyGUIBindings::pushWidget(L, widget);
}


/*
Skipped template methods needing type-specific bindings:
  line 65: assignBase<T>(...) - creates an arbitrary wraps::BaseLayout-derived type
  line 150: initialiseByAttributes<Type>(...) - requires compile-time attribute metadata
  line 232: _createFakeWidget<T>(...) - use _createFakeWidgetT(typeName, parent)

Intentionally omitted methods:
  line 137: shutdown() - unloads the layout but does not clear mMainWidget, so exposing it could leave the read-only getter returning a dangling widget

Intentionally read-only properties:
  line 253: mMainWidget (MyGUI::Widget*) - borrowed widget selected by initialise(); replacing it independently could desynchronize the layout root and mListWindowRoot

Skipped properties needing manual binding:
  line 258: mListWindowRoot (MyGUI::VectorWidgetPtr) - unsupported type
  line 260: mListBase (VectorBasePtr) - unsupported type
*/

int BaseLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BaseLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BaseLayout object");
    return 1;
}

void BaseLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BaseLayoutBinding::gc },
        { "__tostring", BaseLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "assignWidget", BaseLayout_assignWidget },
        { "initialise", BaseLayout_initialise },
        //{ "shutdown", BaseLayout_shutdown },
        { "FindParentPrefix", BaseLayout_FindParentPrefix },
        { "snapToParent", BaseLayout_snapToParent },
        { "_createFakeWidgetT", BaseLayout_createFakeWidgetT },
        { 0, 0 }
    };

    registerClass(
        L, 
        BaseLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BaseLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "mMainWidget", BaseLayout_get_mMainWidget);
    registerGetter(L, "mPrefix", BaseLayout_get_mPrefix);
    registerGetter(L, "mLayoutName", BaseLayout_get_mLayoutName);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "mPrefix", BaseLayout_set_mPrefix);
    registerSetter(L, "mLayoutName", BaseLayout_set_mLayoutName);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
