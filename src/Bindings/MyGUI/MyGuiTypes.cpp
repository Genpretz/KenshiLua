#include "pch.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Bindings/MyGUI/MyGuiCallbacks.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/ButtonBinding.h"
#include "Bindings/MyGUI/WindowBinding.h"
#include "Bindings/MyGUI/TextBoxBinding.h"
#include "Bindings/MyGUI/EditBoxBinding.h"
#include "Bindings/MyGUI/ListBoxBinding.h"
#include "Bindings/MyGUI/ComboBoxBinding.h"
#include "Bindings/MyGUI/TabControlBinding.h"
#include "Bindings/MyGUI/TabItemBinding.h"
#include "Bindings/MyGUI/MultiListBoxBinding.h"
#include "Bindings/MyGUI/ScrollBarBinding.h"
#include "Bindings/MyGUI/ScrollViewBinding.h"
#include "Bindings/MyGUI/ProgressBarBinding.h"
#include "Bindings/MyGUI/ImageBoxBinding.h"
#include "Bindings/MyGUI/ItemBoxBinding.h"
#include "Bindings/MyGUI/CanvasBinding.h"
#include "Bindings/MyGUI/DDContainerBinding.h"
#include "Bindings/MyGUI/MenuBarBinding.h"
#include "Bindings/MyGUI/PopupMenuBinding.h"
#include "Bindings/MyGUI/MenuControlBinding.h"
#include "Bindings/MyGUI/MenuItemBinding.h"
#include "Bindings/MyGUI/TypesBinding.h"
#include "Lua/BindingHelpers.h"
#include <algorithm>

namespace KenshiLua
{
namespace MyGUIBindings
{

static std::unordered_set<MyGUI::Widget*> g_luaCreatedWidgets;
static std::vector<MyGUI::Widget*> g_luaCreatedRootWidgets;
static std::map<MyGUI::Widget*, std::string> g_luaCreatedWidgetSources;

static std::string getCallerSource(lua_State* L)
{
    if (!L) return "";
    lua_Debug ar;
    if (lua_getstack(L, 1, &ar))
    {
        if (lua_getinfo(L, "S", &ar))
        {
            if (ar.source)
            {
                return ar.source;
            }
        }
    }
    return "";
}

void trackLuaCreatedWidget(lua_State* L, MyGUI::Widget* widget, MyGUI::Widget* parent)
{
    if (!widget) return;
    g_luaCreatedWidgets.insert(widget);
    if (!parent || g_luaCreatedWidgets.find(parent) == g_luaCreatedWidgets.end())
    {
        if (std::find(g_luaCreatedRootWidgets.begin(), g_luaCreatedRootWidgets.end(), widget) == g_luaCreatedRootWidgets.end())
        {
            g_luaCreatedRootWidgets.push_back(widget);
            std::string src = getCallerSource(L);
            if (!src.empty())
            {
                g_luaCreatedWidgetSources[widget] = src;
            }
        }
    }
}

void untrackLuaCreatedWidget(MyGUI::Widget* widget)
{
    if (!widget) return;
    auto it = std::find(g_luaCreatedRootWidgets.begin(), g_luaCreatedRootWidgets.end(), widget);
    if (it != g_luaCreatedRootWidgets.end())
    {
        g_luaCreatedRootWidgets.erase(it);
    }
    g_luaCreatedWidgets.erase(widget);
    g_luaCreatedWidgetSources.erase(widget);
}

void cleanupWidgetRecursive(MyGUI::Widget* widget)
{
    if (!widget) return;
    LuaWidgetCallbackManager::get().unregisterAll(widget);
    untrackLuaCreatedWidget(widget);
    size_t count = widget->getChildCount();
    for (size_t i = 0; i < count; ++i)
    {
        cleanupWidgetRecursive(widget->getChildAt(i));
    }
}

void destroyWidgetsBySource(const std::string& source)
{
    if (!MyGUI::Gui::getInstancePtr()) return;
    if (source.empty()) return;

    std::vector<MyGUI::Widget*> toDestroy;
    for (auto it = g_luaCreatedWidgetSources.begin(); it != g_luaCreatedWidgetSources.end(); ++it)
    {
        if (sourceMatches(it->second, source))
        {
            toDestroy.push_back(it->first);
        }
    }

    for (size_t i = 0; i < toDestroy.size(); ++i)
    {
        MyGUI::Widget* w = toDestroy[i];
        cleanupWidgetRecursive(w);
        try
        {
            MyGUI::Gui::getInstance().destroyWidget(w);
        }
        catch (...)
        {
        }
    }
}

void shutdownMyGui()
{
    LuaWidgetCallbackManager::get().clear();
    if (MyGUI::Gui::getInstancePtr())
    {
        for (size_t i = 0; i < g_luaCreatedRootWidgets.size(); ++i)
        {
            MyGUI::Widget* w = g_luaCreatedRootWidgets[i];
            try
            {
                MyGUI::Gui::getInstance().destroyWidget(w);
            }
            catch (...)
            {
            }
        }
    }
    g_luaCreatedRootWidgets.clear();
    g_luaCreatedWidgets.clear();
    g_luaCreatedWidgetSources.clear();
}

int pushWidget(lua_State* L, MyGUI::Widget* widget)
{
    if (!widget)
    {
        lua_pushnil(L);
        return 1;
    }

    if (widget->isType<MyGUI::Button>())
    {
        if (widget->isType<MyGUI::MenuItem>())
            return pushObject<MyGUI::MenuItem>(L, static_cast<MyGUI::MenuItem*>(widget), MenuItemBinding::getMetatableName());
        return pushObject<MyGUI::Button>(L, static_cast<MyGUI::Button*>(widget), ButtonBinding::getMetatableName());
    }
    if (widget->isType<MyGUI::Window>())
        return pushObject<MyGUI::Window>(L, static_cast<MyGUI::Window*>(widget), WindowBinding::getMetatableName());
    if (widget->isType<MyGUI::EditBox>())
    {
        if (widget->isType<MyGUI::ComboBox>())
            return pushObject<MyGUI::ComboBox>(L, static_cast<MyGUI::ComboBox*>(widget), ComboBoxBinding::getMetatableName());
        return pushObject<MyGUI::EditBox>(L, static_cast<MyGUI::EditBox*>(widget), EditBoxBinding::getMetatableName());
    }
    if (widget->isType<MyGUI::TextBox>())
        return pushObject<MyGUI::TextBox>(L, static_cast<MyGUI::TextBox*>(widget), TextBoxBinding::getMetatableName());
    if (widget->isType<MyGUI::ListBox>())
        return pushObject<MyGUI::ListBox>(L, static_cast<MyGUI::ListBox*>(widget), ListBoxBinding::getMetatableName());
    if (widget->isType<MyGUI::TabControl>())
        return pushObject<MyGUI::TabControl>(L, static_cast<MyGUI::TabControl*>(widget), TabControlBinding::getMetatableName());
    if (widget->isType<MyGUI::TabItem>())
        return pushObject<MyGUI::TabItem>(L, static_cast<MyGUI::TabItem*>(widget), TabItemBinding::getMetatableName());
    if (widget->isType<MyGUI::MultiListBox>())
        return pushObject<MyGUI::MultiListBox>(L, static_cast<MyGUI::MultiListBox*>(widget), MultiListBoxBinding::getMetatableName());
    if (widget->isType<MyGUI::ScrollBar>())
        return pushObject<MyGUI::ScrollBar>(L, static_cast<MyGUI::ScrollBar*>(widget), ScrollBarBinding::getMetatableName());
    if (widget->isType<MyGUI::ScrollView>())
        return pushObject<MyGUI::ScrollView>(L, static_cast<MyGUI::ScrollView*>(widget), ScrollViewBinding::getMetatableName());
    if (widget->isType<MyGUI::ProgressBar>())
        return pushObject<MyGUI::ProgressBar>(L, static_cast<MyGUI::ProgressBar*>(widget), ProgressBarBinding::getMetatableName());
    if (widget->isType<MyGUI::ImageBox>())
        return pushObject<MyGUI::ImageBox>(L, static_cast<MyGUI::ImageBox*>(widget), ImageBoxBinding::getMetatableName());
    if (widget->isType<MyGUI::ItemBox>())
        return pushObject<MyGUI::ItemBox>(L, static_cast<MyGUI::ItemBox*>(widget), ItemBoxBinding::getMetatableName());
    if (widget->isType<MyGUI::Canvas>())
        return pushObject<MyGUI::Canvas>(L, static_cast<MyGUI::Canvas*>(widget), CanvasBinding::getMetatableName());
    if (widget->isType<MyGUI::DDContainer>())
        return pushObject<MyGUI::DDContainer>(L, static_cast<MyGUI::DDContainer*>(widget), DDContainerBinding::getMetatableName());
    if (widget->isType<MyGUI::MenuBar>())
        return pushObject<MyGUI::MenuBar>(L, static_cast<MyGUI::MenuBar*>(widget), MenuBarBinding::getMetatableName());
    if (widget->isType<MyGUI::PopupMenu>())
        return pushObject<MyGUI::PopupMenu>(L, static_cast<MyGUI::PopupMenu*>(widget), PopupMenuBinding::getMetatableName());
    if (widget->isType<MyGUI::MenuControl>())
        return pushObject<MyGUI::MenuControl>(L, static_cast<MyGUI::MenuControl*>(widget), MenuControlBinding::getMetatableName());

    return pushObject<MyGUI::Widget>(L, widget, WidgetBinding::getMetatableName());
}

WidgetCreateParams parseWidgetParams(lua_State* L, int startIdx, const std::string& defaultSkin, bool forceRelative)
{
    WidgetCreateParams params;
    params.skin = luaL_optstring(L, startIdx, defaultSkin.c_str());
    params.left = (int)luaL_optinteger(L, startIdx + 1, 0);
    params.top = (int)luaL_optinteger(L, startIdx + 2, 0);
    params.width = (int)luaL_optinteger(L, startIdx + 3, 100);
    params.height = (int)luaL_optinteger(L, startIdx + 4, 30);
    params.relLeft = (float)luaL_optnumber(L, startIdx + 1, 0.0);
    params.relTop = (float)luaL_optnumber(L, startIdx + 2, 0.0);
    params.relWidth = (float)luaL_optnumber(L, startIdx + 3, 0.1);
    params.relHeight = (float)luaL_optnumber(L, startIdx + 4, 0.05);
    params.isRelative = forceRelative || (params.relLeft <= 1.0f && params.relTop <= 1.0f && params.relWidth <= 1.0f && params.relHeight <= 1.0f && (params.relWidth > 0.0f || params.relHeight > 0.0f));
    params.align = MyGUI::Align::Default;
    params.layer = "Window";
    params.parent = nullptr;
    params.name = "";

    int top = lua_gettop(L);
    int trailIdx = startIdx + 5;
    if (top >= trailIdx)
    {
        if (lua_type(L, trailIdx) == LUA_TNUMBER)
        {
            params.align = MyGUI::Align((MyGUI::Align::Enum)(int)lua_tointeger(L, trailIdx));
            if (top >= trailIdx + 1 && !lua_isnil(L, trailIdx + 1))
            {
                if (lua_isuserdata(L, trailIdx + 1))
                {
                    params.parent = testObject<MyGUI::Widget>(L, trailIdx + 1, WidgetBinding::getMetatableName());
                }
                else if (lua_isstring(L, trailIdx + 1))
                {
                    params.layer = lua_tostring(L, trailIdx + 1);
                }
            }
            if (top >= trailIdx + 2 && lua_isstring(L, trailIdx + 2))
            {
                params.name = lua_tostring(L, trailIdx + 2);
            }
        }
        else if (lua_isuserdata(L, trailIdx))
        {
            params.parent = testObject<MyGUI::Widget>(L, trailIdx, WidgetBinding::getMetatableName());
            if (top >= trailIdx + 1 && lua_isstring(L, trailIdx + 1))
            {
                params.name = lua_tostring(L, trailIdx + 1);
            }
        }
        else if (lua_isstring(L, trailIdx))
        {
            if (top >= trailIdx + 1 && !lua_isnil(L, trailIdx + 1))
            {
                params.name = lua_tostring(L, trailIdx);
                if (lua_isuserdata(L, trailIdx + 1))
                {
                    params.parent = testObject<MyGUI::Widget>(L, trailIdx + 1, WidgetBinding::getMetatableName());
                }
                else if (lua_isstring(L, trailIdx + 1))
                {
                    params.layer = lua_tostring(L, trailIdx + 1);
                }
            }
            else
            {
                params.name = lua_tostring(L, trailIdx);
            }
        }
    }
    return params;
}

MyGUI::IntCoord readIntCoord(lua_State* L, int idx)
{
    if (MyGUI::IntCoord* c = testObject<MyGUI::IntCoord>(L, idx, IntCoordBinding::getMetatableName()))
    {
        return *c;
    }
    if (lua_istable(L, idx))
    {
        lua_getfield(L, idx, "left");
        int left = lua_isnumber(L, -1) ? (int)lua_tointeger(L, -1) : 0;
        lua_pop(L, 1);

        lua_getfield(L, idx, "top");
        int top = lua_isnumber(L, -1) ? (int)lua_tointeger(L, -1) : 0;
        lua_pop(L, 1);

        lua_getfield(L, idx, "width");
        int width = lua_isnumber(L, -1) ? (int)lua_tointeger(L, -1) : 0;
        lua_pop(L, 1);

        lua_getfield(L, idx, "height");
        int height = lua_isnumber(L, -1) ? (int)lua_tointeger(L, -1) : 0;
        lua_pop(L, 1);

        return MyGUI::IntCoord(left, top, width, height);
    }
    int left = (int)luaL_optinteger(L, idx, 0);
    int top = (int)luaL_optinteger(L, idx + 1, 0);
    int width = (int)luaL_optinteger(L, idx + 2, 0);
    int height = (int)luaL_optinteger(L, idx + 3, 0);
    return MyGUI::IntCoord(left, top, width, height);
}

MyGUI::IntPoint readIntPoint(lua_State* L, int idx)
{
    if (MyGUI::IntPoint* p = testObject<MyGUI::IntPoint>(L, idx, IntPointBinding::getMetatableName()))
    {
        return *p;
    }
    if (lua_istable(L, idx))
    {
        lua_getfield(L, idx, "left");
        if (lua_isnil(L, -1))
        {
            lua_pop(L, 1);
            lua_getfield(L, idx, "x");
        }
        int left = lua_isnumber(L, -1) ? (int)lua_tointeger(L, -1) : 0;
        lua_pop(L, 1);

        lua_getfield(L, idx, "top");
        if (lua_isnil(L, -1))
        {
            lua_pop(L, 1);
            lua_getfield(L, idx, "y");
        }
        int top = lua_isnumber(L, -1) ? (int)lua_tointeger(L, -1) : 0;
        lua_pop(L, 1);

        return MyGUI::IntPoint(left, top);
    }
    int left = (int)luaL_optinteger(L, idx, 0);
    int top = (int)luaL_optinteger(L, idx + 1, 0);
    return MyGUI::IntPoint(left, top);
}

MyGUI::IntSize readIntSize(lua_State* L, int idx)
{
    if (MyGUI::IntSize* s = testObject<MyGUI::IntSize>(L, idx, IntSizeBinding::getMetatableName()))
    {
        return *s;
    }
    if (lua_istable(L, idx))
    {
        lua_getfield(L, idx, "width");
        if (lua_isnil(L, -1))
        {
            lua_pop(L, 1);
            lua_getfield(L, idx, "w");
        }
        int width = lua_isnumber(L, -1) ? (int)lua_tointeger(L, -1) : 0;
        lua_pop(L, 1);

        lua_getfield(L, idx, "height");
        if (lua_isnil(L, -1))
        {
            lua_pop(L, 1);
            lua_getfield(L, idx, "h");
        }
        int height = lua_isnumber(L, -1) ? (int)lua_tointeger(L, -1) : 0;
        lua_pop(L, 1);

        return MyGUI::IntSize(width, height);
    }
    int width = (int)luaL_optinteger(L, idx, 0);
    int height = (int)luaL_optinteger(L, idx + 1, 0);
    return MyGUI::IntSize(width, height);
}

MyGUI::IntRect readIntRect(lua_State* L, int idx)
{
    if (MyGUI::IntRect* r = testObject<MyGUI::IntRect>(L, idx, IntRectBinding::getMetatableName()))
    {
        return *r;
    }
    if (lua_istable(L, idx))
    {
        lua_getfield(L, idx, "left");
        int left = lua_isnumber(L, -1) ? (int)lua_tointeger(L, -1) : 0;
        lua_pop(L, 1);

        lua_getfield(L, idx, "top");
        int top = lua_isnumber(L, -1) ? (int)lua_tointeger(L, -1) : 0;
        lua_pop(L, 1);

        lua_getfield(L, idx, "right");
        int right = lua_isnumber(L, -1) ? (int)lua_tointeger(L, -1) : 0;
        lua_pop(L, 1);

        lua_getfield(L, idx, "bottom");
        int bottom = lua_isnumber(L, -1) ? (int)lua_tointeger(L, -1) : 0;
        lua_pop(L, 1);

        return MyGUI::IntRect(left, top, right, bottom);
    }
    int left = (int)luaL_optinteger(L, idx, 0);
    int top = (int)luaL_optinteger(L, idx + 1, 0);
    int right = (int)luaL_optinteger(L, idx + 2, 0);
    int bottom = (int)luaL_optinteger(L, idx + 3, 0);
    return MyGUI::IntRect(left, top, right, bottom);
}

MyGUI::Colour readColour(lua_State* L, int idx)
{
    if (MyGUI::Colour* c = testObject<MyGUI::Colour>(L, idx, ColourBinding::getMetatableName()))
    {
        return *c;
    }
    if (lua_istable(L, idx))
    {
        lua_getfield(L, idx, "red");
        if (lua_isnil(L, -1))
        {
            lua_pop(L, 1);
            lua_getfield(L, idx, "r");
        }
        float r = lua_isnumber(L, -1) ? (float)lua_tonumber(L, -1) : 1.0f;
        lua_pop(L, 1);

        lua_getfield(L, idx, "green");
        if (lua_isnil(L, -1))
        {
            lua_pop(L, 1);
            lua_getfield(L, idx, "g");
        }
        float g = lua_isnumber(L, -1) ? (float)lua_tonumber(L, -1) : 1.0f;
        lua_pop(L, 1);

        lua_getfield(L, idx, "blue");
        if (lua_isnil(L, -1))
        {
            lua_pop(L, 1);
            lua_getfield(L, idx, "b");
        }
        float b = lua_isnumber(L, -1) ? (float)lua_tonumber(L, -1) : 1.0f;
        lua_pop(L, 1);

        lua_getfield(L, idx, "alpha");
        if (lua_isnil(L, -1))
        {
            lua_pop(L, 1);
            lua_getfield(L, idx, "a");
        }
        float a = lua_isnumber(L, -1) ? (float)lua_tonumber(L, -1) : 1.0f;
        lua_pop(L, 1);

        return MyGUI::Colour(r, g, b, a);
    }
    if (lua_isstring(L, idx))
    {
        const char* str = lua_tostring(L, idx);
        return MyGUI::Colour::parse(str);
    }
    float r = (float)luaL_optnumber(L, idx, 1.0);
    float g = (float)luaL_optnumber(L, idx + 1, 1.0);
    float b = (float)luaL_optnumber(L, idx + 2, 1.0);
    float a = (float)luaL_optnumber(L, idx + 3, 1.0);
    return MyGUI::Colour(r, g, b, a);
}

} // namespace MyGUIBindings
} // namespace KenshiLua
