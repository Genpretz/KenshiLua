#include "pch.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Bindings/MyGUI/MyGuiCallbacks.h"
#include "Bindings/MyGUI/TypesBinding.h"
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
#include "Bindings/MyGUI/MenuControlBinding.h"
#include "Bindings/MyGUI/MenuBarBinding.h"
#include "Bindings/MyGUI/PopupMenuBinding.h"
#include "Bindings/MyGUI/MenuItemBinding.h"
#include "Bindings/MyGUI/GuiBinding.h"
#include "Bindings/MyGUI/InputManagerBinding.h"
#include "Bindings/MyGUI/PointerManagerBinding.h"
#include "Bindings/MyGUI/ClipboardManagerBinding.h"
#include "Bindings/MyGUI/LayoutManagerBinding.h"
#include "Bindings/MyGUI/RenderManagerBinding.h"
#include "Bindings/MyGUI/SkinManagerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

void MyGUIBinding::destroyWidgetsBySource(const std::string& source)
{
    MyGUIBindings::destroyWidgetsBySource(source);
}

void MyGUIBinding::shutdown()
{
    MyGUIBindings::shutdownMyGui();
}

// ============================================================================
// Global Convenience Factory Helpers
// ============================================================================

static int global_createWidget(lua_State* L)
{
    return GuiBinding::createWidget(L);
}

static int global_createWidgetReal(lua_State* L)
{
    return GuiBinding::createWidgetReal(L);
}

static int global_createButton(lua_State* L)
{
    const char* text = luaL_checkstring(L, 1);
    auto p = MyGUIBindings::parseWidgetParams(L, 2, "Button");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("Button", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("Button", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("Button", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("Button", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        w->setProperty("Caption", text);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createButtonReal(lua_State* L)
{
    const char* text = luaL_checkstring(L, 1);
    auto p = MyGUIBindings::parseWidgetParams(L, 2, "Button", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("Button", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("Button", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        w->setProperty("Caption", text);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createWindow(lua_State* L)
{
    const char* caption = luaL_checkstring(L, 1);
    auto p = MyGUIBindings::parseWidgetParams(L, 2, "WindowCS");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("Window", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("Window", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("Window", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("Window", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        w->setProperty("Caption", caption);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createWindowReal(lua_State* L)
{
    const char* caption = luaL_checkstring(L, 1);
    auto p = MyGUIBindings::parseWidgetParams(L, 2, "WindowCS", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("Window", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("Window", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        w->setProperty("Caption", caption);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createTextBox(lua_State* L)
{
    const char* text = luaL_checkstring(L, 1);
    auto p = MyGUIBindings::parseWidgetParams(L, 2, "TextBox");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("TextBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("TextBox", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("TextBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("TextBox", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        w->setProperty("Caption", text);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createTextBoxReal(lua_State* L)
{
    const char* text = luaL_checkstring(L, 1);
    auto p = MyGUIBindings::parseWidgetParams(L, 2, "TextBox", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("TextBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("TextBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        w->setProperty("Caption", text);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createEditBox(lua_State* L)
{
    const char* text = luaL_checkstring(L, 1);
    auto p = MyGUIBindings::parseWidgetParams(L, 2, "EditBox");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("EditBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("EditBox", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("EditBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("EditBox", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        w->setProperty("Caption", text);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createEditBoxReal(lua_State* L)
{
    const char* text = luaL_checkstring(L, 1);
    auto p = MyGUIBindings::parseWidgetParams(L, 2, "EditBox", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("EditBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("EditBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        w->setProperty("Caption", text);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createListBox(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ListBox");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("ListBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("ListBox", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("ListBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("ListBox", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createListBoxReal(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ListBox", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("ListBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("ListBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createComboBox(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ComboBox");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("ComboBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("ComboBox", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("ComboBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("ComboBox", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createComboBoxReal(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ComboBox", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("ComboBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("ComboBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createTabControl(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "TabControl");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("TabControl", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("TabControl", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("TabControl", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("TabControl", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createTabControlReal(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "TabControl", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("TabControl", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("TabControl", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createMultiListBox(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "MultiListBox");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("MultiListBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("MultiListBox", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("MultiListBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("MultiListBox", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createMultiListBoxReal(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "MultiListBox", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("MultiListBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("MultiListBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createScrollBar(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ScrollBarH");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("ScrollBar", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("ScrollBar", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("ScrollBar", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("ScrollBar", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createScrollBarReal(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ScrollBarH", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("ScrollBar", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("ScrollBar", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createScrollView(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ScrollView");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("ScrollView", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("ScrollView", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("ScrollView", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("ScrollView", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createScrollViewReal(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ScrollView", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("ScrollView", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("ScrollView", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createProgressBar(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ProgressBar");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("ProgressBar", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("ProgressBar", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("ProgressBar", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("ProgressBar", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createProgressBarReal(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ProgressBar", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("ProgressBar", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("ProgressBar", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createImageBox(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ImageBox");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("ImageBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("ImageBox", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("ImageBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("ImageBox", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createImageBoxReal(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ImageBox", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("ImageBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("ImageBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createItemBox(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ItemBox");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("ItemBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("ItemBox", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("ItemBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("ItemBox", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createItemBoxReal(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ItemBox", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("ItemBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("ItemBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createDDContainer(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "DDContainer");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("DDContainer", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("DDContainer", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("DDContainer", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("DDContainer", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createDDContainerReal(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "DDContainer", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("DDContainer", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("DDContainer", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createCanvas(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "Canvas");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("Canvas", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("Canvas", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("Canvas", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("Canvas", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createCanvasReal(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "Canvas", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("Canvas", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("Canvas", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createMenuBar(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "MenuBar");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("MenuBar", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("MenuBar", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("MenuBar", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("MenuBar", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createMenuBarReal(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "MenuBar", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("MenuBar", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("MenuBar", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createPopupMenu(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "PopupMenu");
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
    {
        w = p.isRelative
            ? p.parent->createWidgetRealT("PopupMenu", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name)
            : p.parent->createWidgetT("PopupMenu", p.skin, p.left, p.top, p.width, p.height, p.align, p.name);
    }
    else
    {
        w = p.isRelative
            ? MyGUI::Gui::getInstance().createWidgetRealT("PopupMenu", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name)
            : MyGUI::Gui::getInstance().createWidgetT("PopupMenu", p.skin, p.left, p.top, p.width, p.height, p.align, p.layer, p.name);
    }
    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createPopupMenuReal(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "PopupMenu", true);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("PopupMenu", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("PopupMenu", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_findWidget(lua_State* L)
{
    return GuiBinding::findWidget(L);
}

static int global_destroyWidget(lua_State* L)
{
    return GuiBinding::destroyWidget(L);
}

static int global_destroyWidgets(lua_State* L)
{
    return GuiBinding::destroyWidgets(L);
}

static int global_hidePointer(lua_State* L)
{
    return GuiBinding::hidePointer(L);
}

static int global_showPointer(lua_State* L)
{
    return GuiBinding::showPointer(L);
}

static int global_isPointerVisible(lua_State* L)
{
    return GuiBinding::isPointerVisible(L);
}

static int global_setPointer(lua_State* L)
{
    return PointerManagerBinding::setPointer(L);
}

static int global_clearPointer(lua_State* L)
{
    return PointerManagerBinding::clearPointer(L);
}

static int global_getMousePosition(lua_State* L)
{
    return InputManagerBinding::getMousePosition(L);
}

static int global_loadLayout(lua_State* L)
{
    return LayoutManagerBinding::loadLayout(L);
}

static int global_unloadLayout(lua_State* L)
{
    return LayoutManagerBinding::unloadLayout(L);
}

static int global_getViewSize(lua_State* L)
{
    return RenderManagerBinding::getViewSize(L);
}

static int global_getViewWidth(lua_State* L)
{
    return RenderManagerBinding::getViewWidth(L);
}

static int global_getViewHeight(lua_State* L)
{
    return RenderManagerBinding::getViewHeight(L);
}

static int global_setClipboardText(lua_State* L)
{
    return ClipboardManagerBinding::setText(L);
}

static int global_getClipboardText(lua_State* L)
{
    return ClipboardManagerBinding::getText(L);
}

static int global_isSkinExist(lua_State* L)
{
    return SkinManagerBinding::isExist(L);
}

static int global_getDefaultSkin(lua_State* L)
{
    return SkinManagerBinding::getDefaultSkin(L);
}

static int global_setDefaultSkin(lua_State* L)
{
    return SkinManagerBinding::setDefaultSkin(L);
}

// ============================================================================
// Registration Entry Point
// ============================================================================

void MyGUIBinding::registerBinding(lua_State* L)
{
    // 1. Register value types
    IntPointBinding::registerBinding(L);
    IntSizeBinding::registerBinding(L);
    IntCoordBinding::registerBinding(L);
    IntRectBinding::registerBinding(L);
    FloatPointBinding::registerBinding(L);
    FloatSizeBinding::registerBinding(L);
    FloatCoordBinding::registerBinding(L);
    FloatRectBinding::registerBinding(L);
    ColourBinding::registerBinding(L);

    // 2. Register widget hierarchy (base to derived)
    WidgetBinding::registerBinding(L);
    ButtonBinding::registerBinding(L);
    TextBoxBinding::registerBinding(L);
    EditBoxBinding::registerBinding(L);
    WindowBinding::registerBinding(L);
    ListBoxBinding::registerBinding(L);
    ComboBoxBinding::registerBinding(L);
    TabControlBinding::registerBinding(L);
    TabItemBinding::registerBinding(L);
    MultiListBoxBinding::registerBinding(L);
    ScrollBarBinding::registerBinding(L);
    ScrollViewBinding::registerBinding(L);
    ProgressBarBinding::registerBinding(L);
    ImageBoxBinding::registerBinding(L);
    DDContainerBinding::registerBinding(L);
    ItemBoxBinding::registerBinding(L);
    CanvasBinding::registerBinding(L);
    MenuControlBinding::registerBinding(L);
    MenuBarBinding::registerBinding(L);
    PopupMenuBinding::registerBinding(L);
    MenuItemBinding::registerBinding(L);

    // 3. Register managers
    GuiBinding::registerBinding(L);
    InputManagerBinding::registerBinding(L);
    PointerManagerBinding::registerBinding(L);
    ClipboardManagerBinding::registerBinding(L);
    LayoutManagerBinding::registerBinding(L);
    RenderManagerBinding::registerBinding(L);
    SkinManagerBinding::registerBinding(L);

    // Initialize callback manager
    MyGUIBindings::LuaWidgetCallbackManager::get().setLuaState(L);

    // 4. Register global MyGUI table
    lua_newtable(L);

    // Global widget creation helpers
    static const luaL_Reg globalMethods[] = {
        { "createButton",           global_createButton },
        { "createButtonReal",       global_createButtonReal },
        { "createWindow",           global_createWindow },
        { "createWindowReal",       global_createWindowReal },
        { "createTextBox",          global_createTextBox },
        { "createTextBoxReal",      global_createTextBoxReal },
        { "createEditBox",          global_createEditBox },
        { "createEditBoxReal",      global_createEditBoxReal },
        { "createListBox",          global_createListBox },
        { "createListBoxReal",      global_createListBoxReal },
        { "createComboBox",         global_createComboBox },
        { "createComboBoxReal",     global_createComboBoxReal },
        { "createTabControl",       global_createTabControl },
        { "createTabControlReal",   global_createTabControlReal },
        { "createMultiListBox",     global_createMultiListBox },
        { "createMultiListBoxReal", global_createMultiListBoxReal },
        { "createScrollBar",        global_createScrollBar },
        { "createScrollBarReal",    global_createScrollBarReal },
        { "createScrollView",       global_createScrollView },
        { "createScrollViewReal",   global_createScrollViewReal },
        { "createProgressBar",      global_createProgressBar },
        { "createProgressBarReal",  global_createProgressBarReal },
        { "createImageBox",         global_createImageBox },
        { "createImageBoxReal",     global_createImageBoxReal },
        { "createItemBox",          global_createItemBox },
        { "createItemBoxReal",      global_createItemBoxReal },
        { "createDDContainer",      global_createDDContainer },
        { "createDDContainerReal",  global_createDDContainerReal },
        { "createCanvas",           global_createCanvas },
        { "createCanvasReal",       global_createCanvasReal },
        { "createMenuBar",          global_createMenuBar },
        { "createMenuBarReal",      global_createMenuBarReal },
        { "createPopupMenu",        global_createPopupMenu },
        { "createPopupMenuReal",    global_createPopupMenuReal },
        { "createWidget",           global_createWidget },
        { "createWidgetReal",       global_createWidgetReal },
        { "findWidget",             global_findWidget },
        { "findWidgetT",            global_findWidget },
        { "destroyWidget",          global_destroyWidget },
        { "destroyWidgets",         global_destroyWidgets },
        { "hidePointer",            global_hidePointer },
        { "showPointer",            global_showPointer },
        { "isPointerVisible",       global_isPointerVisible },
        { "setPointer",             global_setPointer },
        { "clearPointer",           global_clearPointer },
        { "getMousePosition",       global_getMousePosition },
        { "loadLayout",             global_loadLayout },
        { "unloadLayout",           global_unloadLayout },
        { "getViewSize",            global_getViewSize },
        { "getViewWidth",           global_getViewWidth },
        { "getViewHeight",          global_getViewHeight },
        { "setClipboardText",       global_setClipboardText },
        { "getClipboardText",       global_getClipboardText },
        { "isSkinExist",            global_isSkinExist },
        { "getDefaultSkin",         global_getDefaultSkin },
        { "setDefaultSkin",         global_setDefaultSkin },
        { 0, 0 }
    };
    luaL_register(L, NULL, globalMethods);

    // Register Align enum table
    lua_newtable(L);
    lua_pushinteger(L, (int)MyGUI::Align::HCenter); lua_setfield(L, -2, "HCenter");
    lua_pushinteger(L, (int)MyGUI::Align::VCenter); lua_setfield(L, -2, "VCenter");
    lua_pushinteger(L, (int)MyGUI::Align::Center);  lua_setfield(L, -2, "Center");
    lua_pushinteger(L, (int)MyGUI::Align::Left);    lua_setfield(L, -2, "Left");
    lua_pushinteger(L, (int)MyGUI::Align::Right);   lua_setfield(L, -2, "Right");
    lua_pushinteger(L, (int)MyGUI::Align::HStretch);lua_setfield(L, -2, "HStretch");
    lua_pushinteger(L, (int)MyGUI::Align::Top);     lua_setfield(L, -2, "Top");
    lua_pushinteger(L, (int)MyGUI::Align::Bottom);  lua_setfield(L, -2, "Bottom");
    lua_pushinteger(L, (int)MyGUI::Align::VStretch);lua_setfield(L, -2, "VStretch");
    lua_pushinteger(L, (int)MyGUI::Align::Stretch); lua_setfield(L, -2, "Stretch");
    lua_pushinteger(L, (int)MyGUI::Align::Default); lua_setfield(L, -2, "Default");
    lua_setfield(L, -2, "Align");

    // Register WidgetStyle enum table
    lua_newtable(L);
    lua_pushinteger(L, (int)MyGUI::WidgetStyle::Child);     lua_setfield(L, -2, "Child");
    lua_pushinteger(L, (int)MyGUI::WidgetStyle::Overlapped);lua_setfield(L, -2, "Overlapped");
    lua_pushinteger(L, (int)MyGUI::WidgetStyle::Popup);     lua_setfield(L, -2, "Popup");
    lua_setfield(L, -2, "WidgetStyle");

    // Register FlowDirection enum table
    lua_newtable(L);
    lua_pushinteger(L, (int)MyGUI::FlowDirection::LeftToRight); lua_setfield(L, -2, "LeftToRight");
    lua_pushinteger(L, (int)MyGUI::FlowDirection::RightToLeft); lua_setfield(L, -2, "RightToLeft");
    lua_pushinteger(L, (int)MyGUI::FlowDirection::TopToBottom); lua_setfield(L, -2, "TopToBottom");
    lua_pushinteger(L, (int)MyGUI::FlowDirection::BottomToTop); lua_setfield(L, -2, "BottomToTop");
    lua_setfield(L, -2, "FlowDirection");

    // Register MenuItemType enum table
    lua_newtable(L);
    lua_pushinteger(L, (int)MyGUI::MenuItemType::Normal);    lua_setfield(L, -2, "Normal");
    lua_pushinteger(L, (int)MyGUI::MenuItemType::Popup);     lua_setfield(L, -2, "Popup");
    lua_pushinteger(L, (int)MyGUI::MenuItemType::Separator); lua_setfield(L, -2, "Separator");
    lua_setfield(L, -2, "MenuItemType");

    // Register MouseButton enum table
    lua_newtable(L);
    lua_pushinteger(L, (int)MyGUI::MouseButton::Left);    lua_setfield(L, -2, "Left");
    lua_pushinteger(L, (int)MyGUI::MouseButton::Right);   lua_setfield(L, -2, "Right");
    lua_pushinteger(L, (int)MyGUI::MouseButton::Middle);  lua_setfield(L, -2, "Middle");
    lua_pushinteger(L, (int)MyGUI::MouseButton::Button0); lua_setfield(L, -2, "Button0");
    lua_pushinteger(L, (int)MyGUI::MouseButton::Button1); lua_setfield(L, -2, "Button1");
    lua_pushinteger(L, (int)MyGUI::MouseButton::Button2); lua_setfield(L, -2, "Button2");
    lua_pushinteger(L, (int)MyGUI::MouseButton::Button3); lua_setfield(L, -2, "Button3");
    lua_pushinteger(L, (int)MyGUI::MouseButton::Button4); lua_setfield(L, -2, "Button4");
    lua_pushinteger(L, (int)MyGUI::MouseButton::Button5); lua_setfield(L, -2, "Button5");
    lua_pushinteger(L, (int)MyGUI::MouseButton::Button6); lua_setfield(L, -2, "Button6");
    lua_pushinteger(L, (int)MyGUI::MouseButton::Button7); lua_setfield(L, -2, "Button7");
    lua_pushinteger(L, (int)MyGUI::MouseButton::None);    lua_setfield(L, -2, "None");
    lua_setfield(L, -2, "MouseButton");

    // Register KeyCode enum table
    lua_newtable(L);
    lua_pushinteger(L, (int)MyGUI::KeyCode::None);         lua_setfield(L, -2, "None");
    lua_pushinteger(L, (int)MyGUI::KeyCode::Escape);       lua_setfield(L, -2, "Escape");
    lua_pushinteger(L, (int)MyGUI::KeyCode::Return);       lua_setfield(L, -2, "Return");
    lua_pushinteger(L, (int)MyGUI::KeyCode::Space);        lua_setfield(L, -2, "Space");
    lua_pushinteger(L, (int)MyGUI::KeyCode::Tab);          lua_setfield(L, -2, "Tab");
    lua_pushinteger(L, (int)MyGUI::KeyCode::Backspace);    lua_setfield(L, -2, "Backspace");
    lua_pushinteger(L, (int)MyGUI::KeyCode::Delete);       lua_setfield(L, -2, "Delete");
    lua_pushinteger(L, (int)MyGUI::KeyCode::LeftShift);    lua_setfield(L, -2, "LeftShift");
    lua_pushinteger(L, (int)MyGUI::KeyCode::RightShift);   lua_setfield(L, -2, "RightShift");
    lua_pushinteger(L, (int)MyGUI::KeyCode::LeftControl);  lua_setfield(L, -2, "LeftControl");
    lua_pushinteger(L, (int)MyGUI::KeyCode::RightControl); lua_setfield(L, -2, "RightControl");
    lua_pushinteger(L, (int)MyGUI::KeyCode::LeftAlt);      lua_setfield(L, -2, "LeftAlt");
    lua_pushinteger(L, (int)MyGUI::KeyCode::RightAlt);     lua_setfield(L, -2, "RightAlt");
    lua_pushinteger(L, (int)MyGUI::KeyCode::ArrowUp);      lua_setfield(L, -2, "ArrowUp");
    lua_pushinteger(L, (int)MyGUI::KeyCode::ArrowDown);    lua_setfield(L, -2, "ArrowDown");
    lua_pushinteger(L, (int)MyGUI::KeyCode::ArrowLeft);    lua_setfield(L, -2, "ArrowLeft");
    lua_pushinteger(L, (int)MyGUI::KeyCode::ArrowRight);   lua_setfield(L, -2, "ArrowRight");
    lua_setfield(L, -2, "KeyCode");

    // Register ResizingPolicy enum table
    lua_newtable(L);
    lua_pushinteger(L, (int)MyGUI::ResizingPolicy::Auto);  lua_setfield(L, -2, "Auto");
    lua_pushinteger(L, (int)MyGUI::ResizingPolicy::Fixed); lua_setfield(L, -2, "Fixed");
    lua_pushinteger(L, (int)MyGUI::ResizingPolicy::Fill);  lua_setfield(L, -2, "Fill");
    lua_setfield(L, -2, "ResizingPolicy");

    lua_setglobal(L, "MyGUI");
}

} // namespace KenshiLua
