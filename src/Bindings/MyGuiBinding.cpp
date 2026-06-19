#include "pch.h"
#include "Bindings/MyGuiBinding.h"
#include "Lua/BindingHelpers.h"
#include "Lua/Logger.h"

#include <MyGUI.h>
#include <map>
#include <string>

namespace KenshiLua
{

class LuaWidgetCallbackManager
{
public:
    static LuaWidgetCallbackManager& get()
    {
        static LuaWidgetCallbackManager inst;
        return inst;
    }

    enum EventType
    {
        OnClick,
        OnTextChanged,
        OnWindowButtonPressed,
        EventType_Count
    };

    struct CallbackKey
    {
        MyGUI::Widget* widget;
        EventType type;

        bool operator<(const CallbackKey& o) const
        {
            if (widget != o.widget) return widget < o.widget;
            return type < o.type;
        }
    };

    struct CallbackInfo
    {
        int luaRef;
        lua_State* L;
        CallbackInfo() : luaRef(0), L(NULL) {}
        CallbackInfo(int ref, lua_State* state) : luaRef(ref), L(state) {}
    };

    std::map<CallbackKey, CallbackInfo> m_callbacks;

    LuaWidgetCallbackManager() {}

    void registerCallback(MyGUI::Widget* widget, EventType type, int luaRef, lua_State* L)
    {
        CallbackKey key = { widget, type };
        std::map<CallbackKey, CallbackInfo>::iterator it = m_callbacks.find(key);
        if (it != m_callbacks.end())
        {
            if (it->second.L && it->second.luaRef != LUA_NOREF)
            {
                luaL_unref(it->second.L, LUA_REGISTRYINDEX, it->second.luaRef);
            }
            it->second.luaRef = luaRef;
            it->second.L = L;
        }
        else
        {
            m_callbacks[key] = CallbackInfo(luaRef, L);
            if (type == OnClick)
            {
                widget->eventMouseButtonClick += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseButtonClick);
            }
            else if (type == OnTextChanged)
            {
                MyGUI::EditBox* editBox = widget->castType<MyGUI::EditBox>(false);
                if (editBox)
                {
                    editBox->eventEditTextChange += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onEditTextChange);
                }
            }
            else if (type == OnWindowButtonPressed)
            {
                MyGUI::Window* window = widget->castType<MyGUI::Window>(false);
                if (window)
                {
                    window->eventWindowButtonPressed += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onWindowButtonPressed);
                }
            }
        }
    }

    void clearCallbacksForWidget(MyGUI::Widget* widget)
    {
        for (int type = 0; type < EventType_Count; ++type)
        {
            CallbackKey key = { widget, (EventType)type };
            auto it = m_callbacks.find(key);
            if (it != m_callbacks.end())
            {
                if (it->second.L && it->second.luaRef != LUA_NOREF)
                {
                    luaL_unref(it->second.L, LUA_REGISTRYINDEX, it->second.luaRef);
                }
                m_callbacks.erase(it);
            }
        }
    }

    void clearAll()
    {
        for (auto it = m_callbacks.begin(); it != m_callbacks.end(); ++it)
        {
            if (it->second.L && it->second.luaRef != LUA_NOREF)
            {
                luaL_unref(it->second.L, LUA_REGISTRYINDEX, it->second.luaRef);
            }
        }
        m_callbacks.clear();
    }

private:
    void onMouseButtonClick(MyGUI::Widget* sender)
    {
        CallbackKey key = { sender, OnClick };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second.luaRef == LUA_NOREF) return;

        lua_State* L = it->second.L;
        if (!L) return;

        int top = lua_gettop(L);
        lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
        pushObject<MyGUI::Widget>(L, sender, MyGuiBinding::getMetatableName());

        if (lua_pcall(L, 1, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(L, 1);
        }
        lua_settop(L, top);
    }

    void onEditTextChange(MyGUI::EditBox* sender)
    {
        CallbackKey key = { sender, OnTextChanged };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second.luaRef == LUA_NOREF) return;

        lua_State* L = it->second.L;
        if (!L) return;

        int top = lua_gettop(L);
        lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
        pushObject<MyGUI::Widget>(L, sender, MyGuiBinding::getMetatableName());

        if (lua_pcall(L, 1, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(L, 1);
        }
        lua_settop(L, top);
    }

    void onWindowButtonPressed(MyGUI::Window* sender, const std::string& name)
    {
        CallbackKey key = { sender, OnWindowButtonPressed };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second.luaRef == LUA_NOREF) return;

        lua_State* L = it->second.L;
        if (!L) return;

        int top = lua_gettop(L);
        lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
        pushObject<MyGUI::Widget>(L, sender, MyGuiBinding::getMetatableName());
        lua_pushstring(L, name.c_str());

        if (lua_pcall(L, 2, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(L, 1);
        }
        lua_settop(L, top);
    }
};

static MyGUI::Widget* getWidget(lua_State* L, int idx)
{
    return checkObject<MyGUI::Widget>(L, idx, MyGuiBinding::getMetatableName());
}

static int widget_setSize(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int width = (int)luaL_checkinteger(L, 2);
    int height = (int)luaL_checkinteger(L, 3);
    if (w) w->setSize(width, height);
    return 0;
}

static int widget_setPosition(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    if (w) w->setPosition(x, y);
    return 0;
}

static int widget_setCaption(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* caption = luaL_checkstring(L, 2);
    if (w)
    {
        MyGUI::TextBox* tb = w->castType<MyGUI::TextBox>(false);
        if (tb) tb->setCaption(caption);
    }
    return 0;
}

static int widget_getCaption(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::TextBox* tb = w->castType<MyGUI::TextBox>(false);
        if (tb)
        {
            lua_pushstring(L, tb->getCaption().asUTF8().c_str());
            return 1;
        }
    }
    lua_pushstring(L, "");
    return 1;
}

static int widget_setVisible(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool visible = lua_toboolean(L, 2) != 0;
    if (w) w->setVisible(visible);
    return 0;
}

static int widget_getVisible(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    lua_pushboolean(L, (w && w->getVisible()) ? 1 : 0);
    return 1;
}

static int widget_setEnabled(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool enabled = lua_toboolean(L, 2) != 0;
    if (w) w->setEnabled(enabled);
    return 0;
}

static int widget_getEnabled(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    lua_pushboolean(L, (w && w->getEnabled()) ? 1 : 0);
    return 1;
}

static int widget_getType(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    lua_pushstring(L, w ? w->getTypeName().c_str() : "");
    return 1;
}

static int widget_getName(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    lua_pushstring(L, w ? w->getName().c_str() : "");
    return 1;
}

static int widget_destroy(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        LuaWidgetCallbackManager::get().clearCallbacksForWidget(w);
        MyGUI::Gui::getInstance().destroyWidget(w);
    }
    return 0;
}

static int widget_findWidget(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* name = luaL_checkstring(L, 2);
    if (w)
    {
        MyGUI::Widget* child = w->findWidget(name);
        if (child)
        {
            return pushObject<MyGUI::Widget>(L, child, MyGuiBinding::getMetatableName());
        }
    }
    lua_pushnil(L);
    return 1;
}

static int widget_getClientWidget(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::Window* win = w->castType<MyGUI::Window>(false);
        if (win)
        {
            MyGUI::Widget* client = win->getClientWidget();
            if (client)
            {
                return pushObject<MyGUI::Widget>(L, client, MyGuiBinding::getMetatableName());
            }
        }
    }
    lua_pushnil(L);
    return 1;
}

static int widget_setProperty(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* key = luaL_checkstring(L, 2);
    const char* value = luaL_checkstring(L, 3);
    if (w) w->setProperty(key, value);
    return 0;
}

static int widget_registerCallback(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* eventType = luaL_checkstring(L, 2);

    int luaRef = LUA_NOREF;
    if (lua_isfunction(L, 3))
    {
        lua_pushvalue(L, 3);
        luaRef = luaL_ref(L, LUA_REGISTRYINDEX);
    }

    LuaWidgetCallbackManager::EventType type;
    if (strcmp(eventType, "MouseButtonClick") == 0 || strcmp(eventType, "click") == 0)
    {
        type = LuaWidgetCallbackManager::OnClick;
    }
    else if (strcmp(eventType, "EditTextChange") == 0 || strcmp(eventType, "change") == 0)
    {
        type = LuaWidgetCallbackManager::OnTextChanged;
    }
    else if (strcmp(eventType, "WindowButtonPressed") == 0 || strcmp(eventType, "windowButtonPressed") == 0)
    {
        type = LuaWidgetCallbackManager::OnWindowButtonPressed;
    }
    else
    {
        if (luaRef != LUA_NOREF)
        {
            luaL_unref(L, LUA_REGISTRYINDEX, luaRef);
        }
        return luaL_error(L, "Unsupported event type: %s", eventType);
    }

    if (w)
    {
        LuaWidgetCallbackManager::get().registerCallback(w, type, luaRef, L);
    }
    else if (luaRef != LUA_NOREF)
    {
        luaL_unref(L, LUA_REGISTRYINDEX, luaRef);
    }

    return 0;
}

static int widget_index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, MyGuiBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    lua_pushnil(L);
    return 1;
}

static int widget_newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    return luaL_error(L, "Widget field '%s' is read-only or does not exist", key);
}

static int lua_resetKeyFocus(lua_State* L)
{
    MyGUI::InputManager::getInstance().resetKeyFocusWidget();
    return 0;
}

static int lua_createWidget(lua_State* L)
{
    const char* type = luaL_checkstring(L, 1);
    const char* skin = luaL_checkstring(L, 2);
    int x = (int)luaL_checkinteger(L, 3);
    int y = (int)luaL_checkinteger(L, 4);
    int w = (int)luaL_checkinteger(L, 5);
    int h = (int)luaL_checkinteger(L, 6);
    const char* name = luaL_checkstring(L, 7);

    MyGUI::Widget* parent = nullptr;
    std::string layer = "Window";

    if (lua_gettop(L) >= 8 && !lua_isnil(L, 8))
    {
        if (lua_isstring(L, 8))
        {
            layer = lua_tostring(L, 8);
        }
        else
        {
            parent = testObject<MyGUI::Widget>(L, 8, MyGuiBinding::getMetatableName());
        }
    }

    MyGUI::Widget* widget = nullptr;
    if (parent)
    {
        widget = parent->createWidgetT(type, skin, x, y, w, h, MyGUI::Align::Default, name);
    }
    else
    {
        MyGUI::Gui* gui = MyGUI::Gui::getInstancePtr();
        if (gui)
        {
            widget = gui->createWidgetT(type, skin, x, y, w, h, MyGUI::Align::Default, layer, name);
        }
    }

    if (widget)
    {
        return pushObject<MyGUI::Widget>(L, widget, MyGuiBinding::getMetatableName());
    }
    lua_pushnil(L);
    return 1;
}

static int lua_loadLayout(lua_State* L)
{
    const char* layoutFile = luaL_checkstring(L, 1);
    MyGUI::Widget* parent = nullptr;
    if (lua_gettop(L) >= 2 && !lua_isnil(L, 2))
    {
        parent = checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    }

    MyGUI::LayoutManager& lm = MyGUI::LayoutManager::getInstance();
    MyGUI::VectorWidgetPtr widgets;
    if (parent)
    {
        widgets = lm.loadLayout(layoutFile, "", parent);
    }
    else
    {
        widgets = lm.loadLayout(layoutFile);
    }

    lua_newtable(L);
    for (size_t i = 0; i < widgets.size(); ++i)
    {
        pushObject<MyGUI::Widget>(L, widgets[i], MyGuiBinding::getMetatableName());
        lua_rawseti(L, -2, (int)(i + 1));
    }
    return 1;
}

void MyGuiBinding::registerBinding(lua_State* L)
{

    static const luaL_Reg meta[] = {
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setSize",          widget_setSize },
        { "setPosition",      widget_setPosition },
        { "setCaption",       widget_setCaption },
        { "getCaption",       widget_getCaption },
        { "setVisible",       widget_setVisible },
        { "getVisible",       widget_getVisible },
        { "setEnabled",       widget_setEnabled },
        { "getEnabled",       widget_getEnabled },
        { "getType",          widget_getType },
        { "getName",          widget_getName },
        { "destroy",          widget_destroy },
        { "findWidget",       widget_findWidget },
        { "getClientWidget",  widget_getClientWidget },
        { "setProperty",      widget_setProperty },
        { "registerCallback", widget_registerCallback },
        { 0, 0 }
    };
    registerClass(L, MyGuiBinding::getMetatableName(), meta, methods, widget_index, widget_newindex);

    lua_getglobal(L, "KenshiLua");
    if (!lua_istable(L, -1))
    {
        lua_pop(L, 1);
        lua_newtable(L);
        lua_pushvalue(L, -1);
        lua_setglobal(L, "KenshiLua");
    }
    lua_pushcfunction(L, lua_createWidget);
    lua_setfield(L, -2, "createWidget");

    lua_pushcfunction(L, lua_loadLayout);
    lua_setfield(L, -2, "loadLayout");

    lua_pushcfunction(L, lua_resetKeyFocus);
    lua_setfield(L, -2, "resetKeyFocus");
    lua_pop(L, 1);
}

void MyGuiBinding::shutdown()
{
    LuaWidgetCallbackManager::get().clearAll();
}

} // namespace KenshiLua
