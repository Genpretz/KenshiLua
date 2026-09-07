#include "pch.h"
#include "Bindings/MyGUI/LayoutManagerBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

int LayoutManagerBinding::getInstance(lua_State* L)
{
    if (MyGUI::LayoutManager::getInstancePtr())
    {
        return pushObject<MyGUI::LayoutManager>(L, MyGUI::LayoutManager::getInstancePtr(), getMetatableName());
    }
    lua_pushnil(L);
    return 1;
}

int LayoutManagerBinding::loadLayout(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    const char* filename = luaL_checkstring(L, idx);
    const char* prefix = luaL_optstring(L, idx + 1, "");
    MyGUI::Widget* parent = nullptr;
    if (lua_gettop(L) >= idx + 2 && !lua_isnil(L, idx + 2))
    {
        parent = testObject<MyGUI::Widget>(L, idx + 2, WidgetBinding::getMetatableName());
    }

    if (!MyGUI::LayoutManager::getInstancePtr())
    {
        return luaL_error(L, "LayoutManager is not initialized");
    }

    MyGUI::VectorWidgetPtr widgets = MyGUI::LayoutManager::getInstance().loadLayout(filename, prefix, parent);
    lua_newtable(L);
    for (size_t i = 0; i < widgets.size(); ++i)
    {
        MyGUI::Widget* w = widgets[i];
        MyGUIBindings::trackLuaCreatedWidget(L, w, parent);
        MyGUIBindings::pushWidget(L, w);
        lua_rawseti(L, -2, (int)(i + 1));
    }
    return 1;
}

int LayoutManagerBinding::unloadLayout(lua_State* L)
{
    int idx = (lua_isuserdata(L, 1) && !lua_istable(L, 1)) ? 2 : 1;
    if (lua_istable(L, idx))
    {
        MyGUI::VectorWidgetPtr vec;
        int len = (int)lua_objlen(L, idx);
        for (int i = 1; i <= len; ++i)
        {
            lua_rawgeti(L, idx, i);
            MyGUI::Widget* w = WidgetBinding::getWidget(L, -1);
            if (w)
            {
                MyGUIBindings::cleanupWidgetRecursive(w);
                vec.push_back(w);
            }
            lua_pop(L, 1);
        }
        if (MyGUI::LayoutManager::getInstancePtr())
        {
            MyGUI::LayoutManager::getInstance().unloadLayout(vec);
        }
    }
    return 0;
}

void LayoutManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc", noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getInstance",  getInstance },
        { "loadLayout",   loadLayout },
        { "unloadLayout", unloadLayout },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "getInstance", getInstance);
    lua_setglobal(L, "LayoutManager");
}

} // namespace KenshiLua
