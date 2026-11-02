#include "pch.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Bindings/MyGUI/MyGuiCallbacks.h"
#include "Bindings/MyGUI/TypesBinding.h"
#include "Bindings/MyGUI/EnumeratorWidgetPtrSnapshotBinding.h"
#include "Bindings/MyGUI/EnumeratorLayerSnapshotBinding.h"
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
#include "Bindings/MyGUI/LayerManagerBinding.h"
#include "Bindings/MyGUI/ILayerBinding.h"
#include "Bindings/MyGUI/MyGUIEnumBinding.h"
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
    int startIdx = 1;
    const char* text = nullptr;
    if (lua_type(L, 1) == LUA_TSTRING && lua_type(L, 2) == LUA_TSTRING)
    {
        text = lua_tostring(L, 1);
        startIdx = 2;
    }
    auto p = MyGUIBindings::parseWidgetParams(L, startIdx, "Button");
    MyGUIBindings::validateWidgetSkin("Button", p.skin);
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
        if (text) w->setProperty("Caption", text);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createButtonReal(lua_State* L)
{
    int startIdx = 1;
    const char* text = nullptr;
    if (lua_type(L, 1) == LUA_TSTRING && lua_type(L, 2) == LUA_TSTRING)
    {
        text = lua_tostring(L, 1);
        startIdx = 2;
    }
    auto p = MyGUIBindings::parseWidgetParams(L, startIdx, "Button", true);
    MyGUIBindings::validateWidgetSkin("Button", p.skin);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("Button", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("Button", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        if (text) w->setProperty("Caption", text);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createWindow(lua_State* L)
{
    int startIdx = 1;
    const char* caption = nullptr;
    if (lua_type(L, 1) == LUA_TSTRING && lua_type(L, 2) == LUA_TSTRING)
    {
        caption = lua_tostring(L, 1);
        startIdx = 2;
    }
    auto p = MyGUIBindings::parseWidgetParams(L, startIdx, "WindowCS");
    MyGUIBindings::validateWidgetSkin("Window", p.skin);
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
        if (caption) w->setProperty("Caption", caption);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createWindowReal(lua_State* L)
{
    int startIdx = 1;
    const char* caption = nullptr;
    if (lua_type(L, 1) == LUA_TSTRING && lua_type(L, 2) == LUA_TSTRING)
    {
        caption = lua_tostring(L, 1);
        startIdx = 2;
    }
    auto p = MyGUIBindings::parseWidgetParams(L, startIdx, "WindowCS", true);
    MyGUIBindings::validateWidgetSkin("Window", p.skin);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("Window", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("Window", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        if (caption) w->setProperty("Caption", caption);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createTextBox(lua_State* L)
{
    int startIdx = 1;
    const char* text = nullptr;
    if (lua_type(L, 1) == LUA_TSTRING && lua_type(L, 2) == LUA_TSTRING)
    {
        text = lua_tostring(L, 1);
        startIdx = 2;
    }
    auto p = MyGUIBindings::parseWidgetParams(L, startIdx, "TextBox");
    MyGUIBindings::validateWidgetSkin("TextBox", p.skin);
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
        if (text) w->setProperty("Caption", text);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createTextBoxReal(lua_State* L)
{
    int startIdx = 1;
    const char* text = nullptr;
    if (lua_type(L, 1) == LUA_TSTRING && lua_type(L, 2) == LUA_TSTRING)
    {
        text = lua_tostring(L, 1);
        startIdx = 2;
    }
    auto p = MyGUIBindings::parseWidgetParams(L, startIdx, "TextBox", true);
    MyGUIBindings::validateWidgetSkin("TextBox", p.skin);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("TextBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("TextBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        if (text) w->setProperty("Caption", text);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createEditBox(lua_State* L)
{
    int startIdx = 1;
    const char* text = nullptr;
    if (lua_type(L, 1) == LUA_TSTRING && lua_type(L, 2) == LUA_TSTRING)
    {
        text = lua_tostring(L, 1);
        startIdx = 2;
    }
    auto p = MyGUIBindings::parseWidgetParams(L, startIdx, "EditBox");
    MyGUIBindings::validateWidgetSkin("EditBox", p.skin);
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
        if (text) w->setProperty("Caption", text);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createEditBoxReal(lua_State* L)
{
    int startIdx = 1;
    const char* text = nullptr;
    if (lua_type(L, 1) == LUA_TSTRING && lua_type(L, 2) == LUA_TSTRING)
    {
        text = lua_tostring(L, 1);
        startIdx = 2;
    }
    auto p = MyGUIBindings::parseWidgetParams(L, startIdx, "EditBox", true);
    MyGUIBindings::validateWidgetSkin("EditBox", p.skin);
    if (!MyGUI::Gui::getInstancePtr()) return luaL_error(L, "MyGUI is not initialized");

    MyGUI::Widget* w = nullptr;
    if (p.parent)
        w = p.parent->createWidgetRealT("EditBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.name);
    else
        w = MyGUI::Gui::getInstance().createWidgetRealT("EditBox", p.skin, p.relLeft, p.relTop, p.relWidth, p.relHeight, p.align, p.layer, p.name);

    if (w)
    {
        if (text) w->setProperty("Caption", text);
        MyGUIBindings::trackLuaCreatedWidget(L, w, p.parent);
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int global_createListBox(lua_State* L)
{
    auto p = MyGUIBindings::parseWidgetParams(L, 1, "ListBox");
    MyGUIBindings::validateWidgetSkin("ListBox", p.skin);
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
    MyGUIBindings::validateWidgetSkin("ListBox", p.skin);
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
    MyGUIBindings::validateWidgetSkin("ComboBox", p.skin);
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
    MyGUIBindings::validateWidgetSkin("ComboBox", p.skin);
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

static int global_upLayerItem(lua_State* L)
{
    return WidgetBinding::upLayerItem(L);
}

// ============================================================================
// Registration Entry Point
// ============================================================================

void MyGUIBinding::registerBinding(lua_State* L)
{
    int initialTop = lua_gettop(L);

#define CHECK_BINDING_STACK(L, name) \
    do { \
        int curTop = lua_gettop(L); \
        if (curTop != initialTop) { \
            KenshiLua::logToFileError(std::string("[MyGUIBinding] ") + (name) + \
                " changed Lua stack from " + std::to_string((long long)initialTop) + " to " + std::to_string((long long)curTop)); \
            lua_settop(L, initialTop); \
        } \
    } while (false)

    // 1. Register value types
    IntPointBinding::registerBinding(L);       CHECK_BINDING_STACK(L, "IntPointBinding");
    IntSizeBinding::registerBinding(L);        CHECK_BINDING_STACK(L, "IntSizeBinding");
    IntCoordBinding::registerBinding(L);       CHECK_BINDING_STACK(L, "IntCoordBinding");
    IntRectBinding::registerBinding(L);        CHECK_BINDING_STACK(L, "IntRectBinding");
    FloatPointBinding::registerBinding(L);     CHECK_BINDING_STACK(L, "FloatPointBinding");
    FloatSizeBinding::registerBinding(L);      CHECK_BINDING_STACK(L, "FloatSizeBinding");
    FloatCoordBinding::registerBinding(L);     CHECK_BINDING_STACK(L, "FloatCoordBinding");
    FloatRectBinding::registerBinding(L);      CHECK_BINDING_STACK(L, "FloatRectBinding");
    ColourBinding::registerBinding(L);         CHECK_BINDING_STACK(L, "ColourBinding");
    EnumeratorWidgetPtrSnapshotBinding::registerBinding(L); CHECK_BINDING_STACK(L, "EnumeratorWidgetPtrSnapshotBinding");
    EnumeratorLayerSnapshotBinding::registerBinding(L); CHECK_BINDING_STACK(L, "EnumeratorLayerSnapshotBinding");

    // 2. Register widget hierarchy (base to derived)
    WidgetBinding::registerBinding(L);         CHECK_BINDING_STACK(L, "WidgetBinding");
    ButtonBinding::registerBinding(L);         CHECK_BINDING_STACK(L, "ButtonBinding");
    TextBoxBinding::registerBinding(L);        CHECK_BINDING_STACK(L, "TextBoxBinding");
    EditBoxBinding::registerBinding(L);        CHECK_BINDING_STACK(L, "EditBoxBinding");
    WindowBinding::registerBinding(L);         CHECK_BINDING_STACK(L, "WindowBinding");
    ListBoxBinding::registerBinding(L);        CHECK_BINDING_STACK(L, "ListBoxBinding");
    ComboBoxBinding::registerBinding(L);       CHECK_BINDING_STACK(L, "ComboBoxBinding");
    TabControlBinding::registerBinding(L);     CHECK_BINDING_STACK(L, "TabControlBinding");
    TabItemBinding::registerBinding(L);        CHECK_BINDING_STACK(L, "TabItemBinding");
    MultiListBoxBinding::registerBinding(L);   CHECK_BINDING_STACK(L, "MultiListBoxBinding");
    ScrollBarBinding::registerBinding(L);      CHECK_BINDING_STACK(L, "ScrollBarBinding");
    ScrollViewBinding::registerBinding(L);     CHECK_BINDING_STACK(L, "ScrollViewBinding");
    ProgressBarBinding::registerBinding(L);    CHECK_BINDING_STACK(L, "ProgressBarBinding");
    ImageBoxBinding::registerBinding(L);       CHECK_BINDING_STACK(L, "ImageBoxBinding");
    DDContainerBinding::registerBinding(L);    CHECK_BINDING_STACK(L, "DDContainerBinding");
    ItemBoxBinding::registerBinding(L);        CHECK_BINDING_STACK(L, "ItemBoxBinding");
    CanvasBinding::registerBinding(L);         CHECK_BINDING_STACK(L, "CanvasBinding");
    MenuControlBinding::registerBinding(L);    CHECK_BINDING_STACK(L, "MenuControlBinding");
    MenuBarBinding::registerBinding(L);        CHECK_BINDING_STACK(L, "MenuBarBinding");
    PopupMenuBinding::registerBinding(L);      CHECK_BINDING_STACK(L, "PopupMenuBinding");
    MenuItemBinding::registerBinding(L);       CHECK_BINDING_STACK(L, "MenuItemBinding");

    // 3. Register managers
    GuiBinding::registerBinding(L);            CHECK_BINDING_STACK(L, "GuiBinding");
    InputManagerBinding::registerBinding(L);   CHECK_BINDING_STACK(L, "InputManagerBinding");
    PointerManagerBinding::registerBinding(L); CHECK_BINDING_STACK(L, "PointerManagerBinding");
    ClipboardManagerBinding::registerBinding(L); CHECK_BINDING_STACK(L, "ClipboardManagerBinding");
    LayoutManagerBinding::registerBinding(L);  CHECK_BINDING_STACK(L, "LayoutManagerBinding");
    RenderManagerBinding::registerBinding(L);  CHECK_BINDING_STACK(L, "RenderManagerBinding");
    SkinManagerBinding::registerBinding(L);    CHECK_BINDING_STACK(L, "SkinManagerBinding");
    LayerManagerBinding::registerBinding(L);   CHECK_BINDING_STACK(L, "LayerManagerBinding");
    ILayerBinding::registerBinding(L);         CHECK_BINDING_STACK(L, "ILayerBinding");
    registerMyGUIEnumBindings(L);              CHECK_BINDING_STACK(L, "MyGUIEnumBinding");

#undef CHECK_BINDING_STACK

    // Initialize callback manager
    MyGUIBindings::LuaWidgetCallbackManager::get().setLuaState(L);

    // 4. Populate global MyGUI table
    pushGlobalTablePath(L, "MyGUI");
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
        { "upLayerItem",            global_upLayerItem },
        { "bringToFront",           global_upLayerItem },
        { 0, 0 }
    };
    luaL_register(L, NULL, globalMethods);
    lua_pop(L, 1);
}

} // namespace KenshiLua
