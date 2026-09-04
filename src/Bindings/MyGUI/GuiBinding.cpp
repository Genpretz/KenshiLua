#include "pch.h"
#include "Bindings/MyGUI/GuiBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

int GuiBinding::getInstance(lua_State* L)
{
    if (MyGUI::Gui::getInstancePtr())
    {
        return pushObject<MyGUI::Gui>(L, MyGUI::Gui::getInstancePtr(), getMetatableName());
    }
    lua_pushnil(L);
    return 1;
}

int GuiBinding::createWidget(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    const char* type = luaL_checkstring(L, idx);
    const char* skin = luaL_checkstring(L, idx + 1);
    int left = (int)luaL_checkinteger(L, idx + 2);
    int top = (int)luaL_checkinteger(L, idx + 3);
    int width = (int)luaL_checkinteger(L, idx + 4);
    int height = (int)luaL_checkinteger(L, idx + 5);
    int align = (int)luaL_optinteger(L, idx + 6, (int)MyGUI::Align::Default);
    const char* layer = luaL_optstring(L, idx + 7, "Window");
    const char* name = luaL_optstring(L, idx + 8, "");

    if (!MyGUI::Gui::getInstancePtr())
    {
        return luaL_error(L, "MyGUI is not initialized");
    }

    MyGUI::Widget* w = MyGUI::Gui::getInstance().createWidgetT(
        type, skin, left, top, width, height, MyGUI::Align((MyGUI::Align::Enum)align), layer, name
    );
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, nullptr);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

int GuiBinding::createWidgetReal(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    const char* type = luaL_checkstring(L, idx);
    const char* skin = luaL_checkstring(L, idx + 1);
    float left = (float)luaL_checknumber(L, idx + 2);
    float top = (float)luaL_checknumber(L, idx + 3);
    float width = (float)luaL_checknumber(L, idx + 4);
    float height = (float)luaL_checknumber(L, idx + 5);
    int align = (int)luaL_optinteger(L, idx + 6, (int)MyGUI::Align::Default);
    const char* layer = luaL_optstring(L, idx + 7, "Window");
    const char* name = luaL_optstring(L, idx + 8, "");

    if (!MyGUI::Gui::getInstancePtr())
    {
        return luaL_error(L, "MyGUI is not initialized");
    }

    MyGUI::Widget* w = MyGUI::Gui::getInstance().createWidgetRealT(
        type, skin, left, top, width, height, MyGUI::Align((MyGUI::Align::Enum)align), layer, name
    );
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, nullptr);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

int GuiBinding::findWidget(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    const char* name = luaL_checkstring(L, idx);
    if (MyGUI::Gui::getInstancePtr())
    {
        MyGUI::Widget* w = MyGUI::Gui::getInstance().findWidget<MyGUI::Widget>(name, false);
        if (w) return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

int GuiBinding::findWidgetT(lua_State* L)
{
    return findWidget(L);
}

int GuiBinding::destroyWidget(lua_State* L)
{
    int idx = (lua_isuserdata(L, 1) && !testObject<MyGUI::Widget>(L, 1, WidgetBinding::getMetatableName())) ? 2 : 1;
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (w)
    {
        MyGUIBindings::cleanupWidgetRecursive(w);
        try
        {
            if (MyGUI::Gui::getInstancePtr())
            {
                MyGUI::Gui::getInstance().destroyWidget(w);
            }
        }
        catch (...)
        {
        }
    }
    return 0;
}

int GuiBinding::destroyWidgets(lua_State* L)
{
    int idx = (lua_isuserdata(L, 1) && !lua_istable(L, 1)) ? 2 : 1;
    if (lua_istable(L, idx))
    {
        int len = (int)lua_objlen(L, idx);
        for (int i = 1; i <= len; ++i)
        {
            lua_rawgeti(L, idx, i);
            MyGUI::Widget* w = WidgetBinding::getWidget(L, -1);
            if (w)
            {
                MyGUIBindings::cleanupWidgetRecursive(w);
                try
                {
                    if (MyGUI::Gui::getInstancePtr())
                    {
                        MyGUI::Gui::getInstance().destroyWidget(w);
                    }
                }
                catch (...)
                {
                }
            }
            lua_pop(L, 1);
        }
    }
    return 0;
}

int GuiBinding::hidePointer(lua_State* L)
{
    if (MyGUI::PointerManager::getInstancePtr())
    {
        MyGUI::PointerManager::getInstance().setVisible(false);
    }
    return 0;
}

int GuiBinding::showPointer(lua_State* L)
{
    if (MyGUI::PointerManager::getInstancePtr())
    {
        MyGUI::PointerManager::getInstance().setVisible(true);
    }
    return 0;
}

int GuiBinding::isPointerVisible(lua_State* L)
{
    if (MyGUI::PointerManager::getInstancePtr())
    {
        lua_pushboolean(L, MyGUI::PointerManager::getInstance().isVisible() ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

void GuiBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc", noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getInstance",      getInstance },
        { "createWidget",     createWidget },
        { "createWidgetReal", createWidgetReal },
        { "findWidget",       findWidget },
        { "findWidgetT",      findWidgetT },
        { "destroyWidget",    destroyWidget },
        { "destroyWidgets",   destroyWidgets },
        { "hidePointer",      hidePointer },
        { "showPointer",      showPointer },
        { "isPointerVisible", isPointerVisible },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);
    registerStaticMethod(L, "Gui", getInstance);
}

} // namespace KenshiLua
