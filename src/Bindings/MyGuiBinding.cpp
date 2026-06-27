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
        OnMouseButtonPressed,
        OnMouseButtonReleased,
        OnMouseSetFocus,
        OnMouseLostFocus,
        OnMouseMove,
        OnMouseWheel,
        OnKeyButtonPressed,
        OnKeyButtonReleased,
        OnComboAccept,
        OnComboChangePosition,
        OnListSelectAccept,
        OnListChangePosition,
        OnWindowChangeCoord,
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

    std::map<CallbackKey, int> m_callbacks;
    lua_State* m_L;

    LuaWidgetCallbackManager() : m_L(nullptr) {}

    void setLuaState(lua_State* L) { m_L = L; }

    void registerCallback(MyGUI::Widget* widget, EventType type, int luaRef)
    {
        CallbackKey key = { widget, type };
        auto it = m_callbacks.find(key);
        if (it != m_callbacks.end())
        {
            if (m_L && it->second != LUA_NOREF)
            {
                luaL_unref(m_L, LUA_REGISTRYINDEX, it->second);
            }
            it->second = luaRef;
        }
        else
        {
            m_callbacks[key] = luaRef;
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
            else if (type == OnMouseButtonPressed)
            {
                widget->eventMouseButtonPressed += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseButtonPressed);
            }
            else if (type == OnMouseButtonReleased)
            {
                widget->eventMouseButtonReleased += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseButtonReleased);
            }
            else if (type == OnMouseSetFocus)
            {
                widget->eventMouseSetFocus += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseSetFocus);
            }
            else if (type == OnMouseLostFocus)
            {
                widget->eventMouseLostFocus += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseLostFocus);
            }
            else if (type == OnMouseMove)
            {
                widget->eventMouseMove += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseMove);
            }
            else if (type == OnMouseWheel)
            {
                widget->eventMouseWheel += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseWheel);
            }
            else if (type == OnKeyButtonPressed)
            {
                widget->eventKeyButtonPressed += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onKeyButtonPressed);
            }
            else if (type == OnKeyButtonReleased)
            {
                widget->eventKeyButtonReleased += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onKeyButtonReleased);
            }
            else if (type == OnComboAccept)
            {
                MyGUI::ComboBox* comboBox = widget->castType<MyGUI::ComboBox>(false);
                if (comboBox)
                {
                    comboBox->eventComboAccept += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onComboAccept);
                }
            }
            else if (type == OnComboChangePosition)
            {
                MyGUI::ComboBox* comboBox = widget->castType<MyGUI::ComboBox>(false);
                if (comboBox)
                {
                    comboBox->eventComboChangePosition += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onComboChangePosition);
                }
            }
            else if (type == OnListSelectAccept)
            {
                MyGUI::ListBox* listBox = widget->castType<MyGUI::ListBox>(false);
                if (listBox)
                {
                    listBox->eventListSelectAccept += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onListSelectAccept);
                }
            }
            else if (type == OnListChangePosition)
            {
                MyGUI::ListBox* listBox = widget->castType<MyGUI::ListBox>(false);
                if (listBox)
                {
                    listBox->eventListChangePosition += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onListChangePosition);
                }
            }
            else if (type == OnWindowChangeCoord)
            {
                MyGUI::Window* window = widget->castType<MyGUI::Window>(false);
                if (window)
                {
                    window->eventWindowChangeCoord += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onWindowChangeCoord);
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
                if (m_L && it->second != LUA_NOREF)
                {
                    luaL_unref(m_L, LUA_REGISTRYINDEX, it->second);
                }
                m_callbacks.erase(it);
            }
        }
    }

    void clearAll()
    {
        if (m_L)
        {
            for (std::map<CallbackKey, int>::iterator it = m_callbacks.begin(); it != m_callbacks.end(); ++it)
            {
                if (it->second != LUA_NOREF)
                {
                    luaL_unref(m_L, LUA_REGISTRYINDEX, it->second);
                }
            }
        }
        m_callbacks.clear();
    }

private:
    void onMouseButtonClick(MyGUI::Widget* sender)
    {
        if (!m_L) return;
        CallbackKey key = { sender, OnClick };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());

        if (lua_pcall(m_L, 1, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top);
    }

    void onEditTextChange(MyGUI::EditBox* sender)
    {
        if (!m_L) return;
        CallbackKey key = { sender, OnTextChanged };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top = m_L ? lua_gettop(m_L) : 0;
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());

        if (lua_pcall(m_L, 1, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top);
    }

    void onWindowButtonPressed(MyGUI::Window* sender, const std::string& name)
    {
        if (!m_L) return;
        CallbackKey key = { sender, OnWindowButtonPressed };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());
        lua_pushstring(m_L, name.c_str());

        if (lua_pcall(m_L, 2, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top);
    }

    void onMouseButtonPressed(MyGUI::Widget* sender, int left, int top, MyGUI::MouseButton id)
    {
        if (!m_L) return;
        CallbackKey key = { sender, OnMouseButtonPressed };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top_stack = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());
        lua_pushinteger(m_L, left);
        lua_pushinteger(m_L, top);
        lua_pushinteger(m_L, id.getValue());

        if (lua_pcall(m_L, 4, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top_stack);
    }

    void onMouseButtonReleased(MyGUI::Widget* sender, int left, int top, MyGUI::MouseButton id)
    {
        if (!m_L) return;
        CallbackKey key = { sender, OnMouseButtonReleased };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top_stack = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());
        lua_pushinteger(m_L, left);
        lua_pushinteger(m_L, top);
        lua_pushinteger(m_L, id.getValue());

        if (lua_pcall(m_L, 4, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top_stack);
    }

    void onMouseSetFocus(MyGUI::Widget* sender, MyGUI::Widget* old)
    {
        if (!m_L) return;
        CallbackKey key = { sender, OnMouseSetFocus };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top_stack = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());
        pushObject<MyGUI::Widget>(m_L, old, MyGuiBinding::getMetatableName());

        if (lua_pcall(m_L, 2, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top_stack);
    }

    void onMouseLostFocus(MyGUI::Widget* sender, MyGUI::Widget* new_)
    {
        if (!m_L) return;
        CallbackKey key = { sender, OnMouseLostFocus };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top_stack = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());
        pushObject<MyGUI::Widget>(m_L, new_, MyGuiBinding::getMetatableName());

        if (lua_pcall(m_L, 2, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top_stack);
    }

    void onMouseMove(MyGUI::Widget* sender, int left, int top)
    {
        if (!m_L) return;
        CallbackKey key = { sender, OnMouseMove };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top_stack = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());
        lua_pushinteger(m_L, left);
        lua_pushinteger(m_L, top);

        if (lua_pcall(m_L, 3, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top_stack);
    }

    void onMouseWheel(MyGUI::Widget* sender, int rel)
    {
        if (!m_L) return;
        CallbackKey key = { sender, OnMouseWheel };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top_stack = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());
        lua_pushinteger(m_L, rel);

        if (lua_pcall(m_L, 2, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top_stack);
    }

    void onKeyButtonPressed(MyGUI::Widget* sender, MyGUI::KeyCode key, MyGUI::Char ch)
    {
        if (!m_L) return;
        CallbackKey callbackKey = { sender, OnKeyButtonPressed };
        auto it = m_callbacks.find(callbackKey);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top_stack = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());
        lua_pushinteger(m_L, key.getValue());
        lua_pushinteger(m_L, ch);

        if (lua_pcall(m_L, 3, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top_stack);
    }

    void onKeyButtonReleased(MyGUI::Widget* sender, MyGUI::KeyCode key)
    {
        if (!m_L) return;
        CallbackKey callbackKey = { sender, OnKeyButtonReleased };
        auto it = m_callbacks.find(callbackKey);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top_stack = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());
        lua_pushinteger(m_L, key.getValue());

        if (lua_pcall(m_L, 2, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top_stack);
    }

    void onComboAccept(MyGUI::ComboBox* sender, size_t index)
    {
        if (!m_L) return;
        CallbackKey key = { sender, OnComboAccept };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top_stack = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());
        lua_pushinteger(m_L, index);

        if (lua_pcall(m_L, 2, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top_stack);
    }

    void onComboChangePosition(MyGUI::ComboBox* sender, size_t index)
    {
        if (!m_L) return;
        CallbackKey key = { sender, OnComboChangePosition };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top_stack = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());
        lua_pushinteger(m_L, index);

        if (lua_pcall(m_L, 2, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top_stack);
    }

    void onListSelectAccept(MyGUI::ListBox* sender, size_t index)
    {
        if (!m_L) return;
        CallbackKey key = { sender, OnListSelectAccept };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top_stack = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());
        lua_pushinteger(m_L, index);

        if (lua_pcall(m_L, 2, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top_stack);
    }

    void onListChangePosition(MyGUI::ListBox* sender, size_t index)
    {
        if (!m_L) return;
        CallbackKey key = { sender, OnListChangePosition };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top_stack = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());
        lua_pushinteger(m_L, index);

        if (lua_pcall(m_L, 2, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top_stack);
    }

    void onWindowChangeCoord(MyGUI::Window* sender)
    {
        if (!m_L) return;
        CallbackKey key = { sender, OnWindowChangeCoord };
        auto it = m_callbacks.find(key);
        if (it == m_callbacks.end() || it->second == LUA_NOREF) return;

        int top_stack = lua_gettop(m_L);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, it->second);
        pushObject<MyGUI::Widget>(m_L, sender, MyGuiBinding::getMetatableName());

        if (lua_pcall(m_L, 1, 0, 0) != LUA_OK)
        {
            const char* err = lua_tostring(m_L, -1);
            logToFile(std::string("MyGUI Event Error: ") + (err ? err : "unknown"));
            lua_pop(m_L, 1);
        }
        lua_settop(m_L, top_stack);
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
    else if (strcmp(eventType, "MouseButtonPressed") == 0 || strcmp(eventType, "mouseButtonPressed") == 0 || strcmp(eventType, "mouseDown") == 0)
    {
        type = LuaWidgetCallbackManager::OnMouseButtonPressed;
    }
    else if (strcmp(eventType, "MouseButtonReleased") == 0 || strcmp(eventType, "mouseButtonReleased") == 0 || strcmp(eventType, "mouseUp") == 0)
    {
        type = LuaWidgetCallbackManager::OnMouseButtonReleased;
    }
    else if (strcmp(eventType, "MouseSetFocus") == 0 || strcmp(eventType, "mouseSetFocus") == 0 || strcmp(eventType, "mouseOver") == 0)
    {
        type = LuaWidgetCallbackManager::OnMouseSetFocus;
    }
    else if (strcmp(eventType, "MouseLostFocus") == 0 || strcmp(eventType, "mouseLostFocus") == 0 || strcmp(eventType, "mouseOut") == 0)
    {
        type = LuaWidgetCallbackManager::OnMouseLostFocus;
    }
    else if (strcmp(eventType, "MouseMove") == 0 || strcmp(eventType, "mouseMove") == 0)
    {
        type = LuaWidgetCallbackManager::OnMouseMove;
    }
    else if (strcmp(eventType, "MouseWheel") == 0 || strcmp(eventType, "mouseWheel") == 0)
    {
        type = LuaWidgetCallbackManager::OnMouseWheel;
    }
    else if (strcmp(eventType, "KeyButtonPressed") == 0 || strcmp(eventType, "keyButtonPressed") == 0 || strcmp(eventType, "keyDown") == 0)
    {
        type = LuaWidgetCallbackManager::OnKeyButtonPressed;
    }
    else if (strcmp(eventType, "KeyButtonReleased") == 0 || strcmp(eventType, "keyButtonReleased") == 0 || strcmp(eventType, "keyUp") == 0)
    {
        type = LuaWidgetCallbackManager::OnKeyButtonReleased;
    }
    else if (strcmp(eventType, "ComboAccept") == 0 || strcmp(eventType, "comboAccept") == 0)
    {
        type = LuaWidgetCallbackManager::OnComboAccept;
    }
    else if (strcmp(eventType, "ComboChangePosition") == 0 || strcmp(eventType, "comboChangePosition") == 0)
    {
        type = LuaWidgetCallbackManager::OnComboChangePosition;
    }
    else if (strcmp(eventType, "ListSelectAccept") == 0 || strcmp(eventType, "listSelectAccept") == 0)
    {
        type = LuaWidgetCallbackManager::OnListSelectAccept;
    }
    else if (strcmp(eventType, "ListChangePosition") == 0 || strcmp(eventType, "listChangePosition") == 0)
    {
        type = LuaWidgetCallbackManager::OnListChangePosition;
    }
    else if (strcmp(eventType, "WindowChangeCoord") == 0 || strcmp(eventType, "windowChangeCoord") == 0)
    {
        type = LuaWidgetCallbackManager::OnWindowChangeCoord;
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
        LuaWidgetCallbackManager::get().registerCallback(w, type, luaRef);
    }
    else if (luaRef != LUA_NOREF)
    {
        luaL_unref(L, LUA_REGISTRYINDEX, luaRef);
    }

    return 0;
}

// General / Coordinates / Hierarchy methods
static int widget_getCoord(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::IntCoord c = w->getCoord();
        lua_pushinteger(L, c.left);
        lua_pushinteger(L, c.top);
        lua_pushinteger(L, c.width);
        lua_pushinteger(L, c.height);
        return 4;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 4;
}

static int widget_setCoord(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int left = (int)luaL_checkinteger(L, 2);
    int top = (int)luaL_checkinteger(L, 3);
    int width = (int)luaL_checkinteger(L, 4);
    int height = (int)luaL_checkinteger(L, 5);
    if (w) w->setCoord(left, top, width, height);
    return 0;
}

static int widget_getPosition(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::IntPoint p = w->getPosition();
        lua_pushinteger(L, p.left);
        lua_pushinteger(L, p.top);
        return 2;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

static int widget_getSize(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::IntSize s = w->getSize();
        lua_pushinteger(L, s.width);
        lua_pushinteger(L, s.height);
        return 2;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

static int widget_getParent(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::Widget* parent = w->getParent();
        if (parent)
        {
            return pushObject<MyGUI::Widget>(L, parent, MyGuiBinding::getMetatableName());
        }
    }
    lua_pushnil(L);
    return 1;
}

static int widget_detachFromWidget(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* layer = "";
    if (lua_gettop(L) >= 2 && !lua_isnil(L, 2))
    {
        layer = luaL_checkstring(L, 2);
    }
    if (w) w->detachFromWidget(layer);
    return 0;
}

static int widget_attachToWidget(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    MyGUI::Widget* parent = checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    
    int styleVal = (int)MyGUI::WidgetStyle::Child;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3))
    {
        styleVal = (int)luaL_checkinteger(L, 3);
    }
    
    const char* layer = "";
    if (lua_gettop(L) >= 4 && !lua_isnil(L, 4))
    {
        layer = luaL_checkstring(L, 4);
    }
    
    if (w && parent) w->attachToWidget(parent, MyGUI::WidgetStyle((MyGUI::WidgetStyle::Enum)styleVal), layer);
    return 0;
}

static int widget_setNeedKeyFocus(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool need = lua_toboolean(L, 2) != 0;
    if (w) w->setNeedKeyFocus(need);
    return 0;
}

static int widget_setNeedMouseFocus(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool need = lua_toboolean(L, 2) != 0;
    if (w) w->setNeedMouseFocus(need);
    return 0;
}

static int widget_setPointer(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* ptrStr = luaL_checkstring(L, 2);
    if (w) w->setPointer(ptrStr);
    return 0;
}

static int widget_setUserString(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* key = luaL_checkstring(L, 2);
    const char* value = luaL_checkstring(L, 3);
    if (w) w->setUserString(key, value);
    return 0;
}

static int widget_getUserString(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* key = luaL_checkstring(L, 2);
    if (w && w->isUserString(key))
    {
        lua_pushstring(L, w->getUserString(key).c_str());
        return 1;
    }
    lua_pushnil(L);
    return 1;
}

static int widget_isUserString(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* key = luaL_checkstring(L, 2);
    lua_pushboolean(L, (w && w->isUserString(key)) ? 1 : 0);
    return 1;
}

static int widget_clearUserString(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* key = luaL_checkstring(L, 2);
    if (w) w->clearUserString(key);
    return 0;
}

// Button methods
static int widget_setStateSelected(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool state = lua_toboolean(L, 2) != 0;
    if (w)
    {
        MyGUI::Button* btn = w->castType<MyGUI::Button>(false);
        if (btn) btn->setStateSelected(state);
    }
    return 0;
}

static int widget_getStateSelected(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::Button* btn = w->castType<MyGUI::Button>(false);
        if (btn)
        {
            lua_pushboolean(L, btn->getStateSelected());
            return 1;
        }
    }
    lua_pushboolean(L, false);
    return 1;
}

// EditBox methods
static int widget_setOnlyText(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* text = luaL_checkstring(L, 2);
    if (w)
    {
        MyGUI::EditBox* eb = w->castType<MyGUI::EditBox>(false);
        if (eb) eb->setOnlyText(text);
    }
    return 0;
}

static int widget_getOnlyText(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::EditBox* eb = w->castType<MyGUI::EditBox>(false);
        if (eb)
        {
            lua_pushstring(L, eb->getOnlyText().asUTF8().c_str());
            return 1;
        }
    }
    lua_pushstring(L, "");
    return 1;
}

static int widget_setEditReadOnly(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool readOnly = lua_toboolean(L, 2) != 0;
    if (w)
    {
        MyGUI::EditBox* eb = w->castType<MyGUI::EditBox>(false);
        if (eb) eb->setEditReadOnly(readOnly);
    }
    return 0;
}

static int widget_getEditReadOnly(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::EditBox* eb = w->castType<MyGUI::EditBox>(false);
        if (eb)
        {
            lua_pushboolean(L, eb->getEditReadOnly());
            return 1;
        }
    }
    lua_pushboolean(L, false);
    return 1;
}

static int widget_setEditPassword(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool pwd = lua_toboolean(L, 2) != 0;
    if (w)
    {
        MyGUI::EditBox* eb = w->castType<MyGUI::EditBox>(false);
        if (eb) eb->setEditPassword(pwd);
    }
    return 0;
}

static int widget_getEditPassword(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::EditBox* eb = w->castType<MyGUI::EditBox>(false);
        if (eb)
        {
            lua_pushboolean(L, eb->getEditPassword());
            return 1;
        }
    }
    lua_pushboolean(L, false);
    return 1;
}

static int widget_setEditMultiLine(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool ml = lua_toboolean(L, 2) != 0;
    if (w)
    {
        MyGUI::EditBox* eb = w->castType<MyGUI::EditBox>(false);
        if (eb) eb->setEditMultiLine(ml);
    }
    return 0;
}

static int widget_getEditMultiLine(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::EditBox* eb = w->castType<MyGUI::EditBox>(false);
        if (eb)
        {
            lua_pushboolean(L, eb->getEditMultiLine());
            return 1;
        }
    }
    lua_pushboolean(L, false);
    return 1;
}

static int widget_setEditStatic(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool st = lua_toboolean(L, 2) != 0;
    if (w)
    {
        MyGUI::EditBox* eb = w->castType<MyGUI::EditBox>(false);
        if (eb) eb->setEditStatic(st);
    }
    return 0;
}

static int widget_getEditStatic(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::EditBox* eb = w->castType<MyGUI::EditBox>(false);
        if (eb)
        {
            lua_pushboolean(L, eb->getEditStatic());
            return 1;
        }
    }
    lua_pushboolean(L, false);
    return 1;
}

static int widget_setPasswordChar(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* pwdChar = luaL_checkstring(L, 2);
    if (w)
    {
        MyGUI::EditBox* eb = w->castType<MyGUI::EditBox>(false);
        if (eb) eb->setPasswordChar(pwdChar);
    }
    return 0;
}

// Item Container (ListBox / ComboBox / TabControl) methods
static int widget_getItemCount(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::ListBox* lb = w->castType<MyGUI::ListBox>(false);
        if (lb)
        {
            lua_pushinteger(L, lb->getItemCount());
            return 1;
        }
        MyGUI::ComboBox* cb = w->castType<MyGUI::ComboBox>(false);
        if (cb)
        {
            lua_pushinteger(L, cb->getItemCount());
            return 1;
        }
        MyGUI::TabControl* tc = w->castType<MyGUI::TabControl>(false);
        if (tc)
        {
            lua_pushinteger(L, tc->getItemCount());
            return 1;
        }
    }
    lua_pushinteger(L, 0);
    return 1;
}

static int widget_addItem(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* name = luaL_checkstring(L, 2);
    if (w)
    {
        MyGUI::ListBox* lb = w->castType<MyGUI::ListBox>(false);
        if (lb)
        {
            lb->addItem(name);
            return 0;
        }
        MyGUI::ComboBox* cb = w->castType<MyGUI::ComboBox>(false);
        if (cb)
        {
            cb->addItem(name);
            return 0;
        }
        MyGUI::TabControl* tc = w->castType<MyGUI::TabControl>(false);
        if (tc)
        {
            MyGUI::TabItem* tab = tc->addItem(name);
            if (tab)
            {
                return pushObject<MyGUI::Widget>(L, tab, MyGuiBinding::getMetatableName());
            }
        }
    }
    return 0;
}

static int widget_insertItemAt(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int idx = (int)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    if (w)
    {
        MyGUI::ListBox* lb = w->castType<MyGUI::ListBox>(false);
        if (lb)
        {
            lb->insertItemAt(idx, name);
            return 0;
        }
        MyGUI::ComboBox* cb = w->castType<MyGUI::ComboBox>(false);
        if (cb)
        {
            cb->insertItemAt(idx, name);
            return 0;
        }
        MyGUI::TabControl* tc = w->castType<MyGUI::TabControl>(false);
        if (tc)
        {
            MyGUI::TabItem* tab = tc->insertItemAt(idx, name);
            if (tab)
            {
                return pushObject<MyGUI::Widget>(L, tab, MyGuiBinding::getMetatableName());
            }
        }
    }
    return 0;
}

static int widget_removeItemAt(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int idx = (int)luaL_checkinteger(L, 2);
    if (w)
    {
        MyGUI::ListBox* lb = w->castType<MyGUI::ListBox>(false);
        if (lb)
        {
            lb->removeItemAt(idx);
            return 0;
        }
        MyGUI::ComboBox* cb = w->castType<MyGUI::ComboBox>(false);
        if (cb)
        {
            cb->removeItemAt(idx);
            return 0;
        }
        MyGUI::TabControl* tc = w->castType<MyGUI::TabControl>(false);
        if (tc)
        {
            tc->removeItemAt(idx);
            return 0;
        }
    }
    return 0;
}

static int widget_removeAllItems(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::ListBox* lb = w->castType<MyGUI::ListBox>(false);
        if (lb)
        {
            lb->removeAllItems();
            return 0;
        }
        MyGUI::ComboBox* cb = w->castType<MyGUI::ComboBox>(false);
        if (cb)
        {
            cb->removeAllItems();
            return 0;
        }
        MyGUI::TabControl* tc = w->castType<MyGUI::TabControl>(false);
        if (tc)
        {
            tc->removeAllItems();
            return 0;
        }
    }
    return 0;
}

static int widget_getIndexSelected(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::ListBox* lb = w->castType<MyGUI::ListBox>(false);
        if (lb)
        {
            lua_pushinteger(L, lb->getIndexSelected());
            return 1;
        }
        MyGUI::ComboBox* cb = w->castType<MyGUI::ComboBox>(false);
        if (cb)
        {
            lua_pushinteger(L, cb->getIndexSelected());
            return 1;
        }
        MyGUI::TabControl* tc = w->castType<MyGUI::TabControl>(false);
        if (tc)
        {
            lua_pushinteger(L, tc->getIndexSelected());
            return 1;
        }
    }
    lua_pushinteger(L, -1);
    return 1;
}

static int widget_setIndexSelected(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int idx = (int)luaL_checkinteger(L, 2);
    if (w)
    {
        MyGUI::ListBox* lb = w->castType<MyGUI::ListBox>(false);
        if (lb)
        {
            lb->setIndexSelected(idx);
            return 0;
        }
        MyGUI::ComboBox* cb = w->castType<MyGUI::ComboBox>(false);
        if (cb)
        {
            cb->setIndexSelected(idx);
            return 0;
        }
        MyGUI::TabControl* tc = w->castType<MyGUI::TabControl>(false);
        if (tc)
        {
            tc->setIndexSelected(idx);
            return 0;
        }
    }
    return 0;
}

static int widget_clearIndexSelected(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::ListBox* lb = w->castType<MyGUI::ListBox>(false);
        if (lb)
        {
            lb->clearIndexSelected();
            return 0;
        }
        MyGUI::ComboBox* cb = w->castType<MyGUI::ComboBox>(false);
        if (cb)
        {
            cb->clearIndexSelected();
            return 0;
        }
    }
    return 0;
}

static int widget_getItemNameAt(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int idx = (int)luaL_checkinteger(L, 2);
    if (w)
    {
        MyGUI::ListBox* lb = w->castType<MyGUI::ListBox>(false);
        if (lb)
        {
            lua_pushstring(L, lb->getItemNameAt(idx).asUTF8().c_str());
            return 1;
        }
        MyGUI::ComboBox* cb = w->castType<MyGUI::ComboBox>(false);
        if (cb)
        {
            lua_pushstring(L, cb->getItemNameAt(idx).asUTF8().c_str());
            return 1;
        }
        MyGUI::TabControl* tc = w->castType<MyGUI::TabControl>(false);
        if (tc)
        {
            lua_pushstring(L, tc->getItemNameAt(idx).asUTF8().c_str());
            return 1;
        }
    }
    lua_pushstring(L, "");
    return 1;
}

static int widget_setItemNameAt(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int idx = (int)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    if (w)
    {
        MyGUI::ListBox* lb = w->castType<MyGUI::ListBox>(false);
        if (lb)
        {
            lb->setItemNameAt(idx, name);
            return 0;
        }
        MyGUI::ComboBox* cb = w->castType<MyGUI::ComboBox>(false);
        if (cb)
        {
            cb->setItemNameAt(idx, name);
            return 0;
        }
        MyGUI::TabControl* tc = w->castType<MyGUI::TabControl>(false);
        if (tc)
        {
            tc->setItemNameAt(idx, name);
            return 0;
        }
    }
    return 0;
}

// ListBox specific methods
static int widget_getOptimalHeight(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::ListBox* lb = w->castType<MyGUI::ListBox>(false);
        if (lb)
        {
            lua_pushinteger(L, lb->getOptimalHeight());
            return 1;
        }
    }
    lua_pushinteger(L, 0);
    return 1;
}

static int widget_getWidgetByIndex(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int idx = (int)luaL_checkinteger(L, 2);
    if (w)
    {
        MyGUI::ListBox* lb = w->castType<MyGUI::ListBox>(false);
        if (lb)
        {
            MyGUI::Widget* item = lb->getWidgetByIndex(idx);
            if (item)
            {
                return pushObject<MyGUI::Widget>(L, item, MyGuiBinding::getMetatableName());
            }
        }
    }
    lua_pushnil(L);
    return 1;
}

// Window specific methods
static int widget_setMinSize(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int width = (int)luaL_checkinteger(L, 2);
    int height = (int)luaL_checkinteger(L, 3);
    if (w)
    {
        MyGUI::Window* win = w->castType<MyGUI::Window>(false);
        if (win) win->setMinSize(width, height);
    }
    return 0;
}

static int widget_getMinSize(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::Window* win = w->castType<MyGUI::Window>(false);
        if (win)
        {
            MyGUI::IntSize sz = win->getMinSize();
            lua_pushinteger(L, sz.width);
            lua_pushinteger(L, sz.height);
            return 2;
        }
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

static int widget_setMaxSize(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int width = (int)luaL_checkinteger(L, 2);
    int height = (int)luaL_checkinteger(L, 3);
    if (w)
    {
        MyGUI::Window* win = w->castType<MyGUI::Window>(false);
        if (win) win->setMaxSize(width, height);
    }
    return 0;
}

static int widget_getMaxSize(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::Window* win = w->castType<MyGUI::Window>(false);
        if (win)
        {
            MyGUI::IntSize sz = win->getMaxSize();
            lua_pushinteger(L, sz.width);
            lua_pushinteger(L, sz.height);
            return 2;
        }
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

static int widget_setVisibleSmooth(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool visible = lua_toboolean(L, 2) != 0;
    if (w)
    {
        MyGUI::Window* win = w->castType<MyGUI::Window>(false);
        if (win) win->setVisibleSmooth(visible);
    }
    return 0;
}

static int widget_destroySmooth(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::Window* win = w->castType<MyGUI::Window>(false);
        if (win)
        {
            LuaWidgetCallbackManager::get().clearCallbacksForWidget(w);
            win->destroySmooth();
        }
    }
    return 0;
}

static int widget_setMovable(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool movable = lua_toboolean(L, 2) != 0;
    if (w)
    {
        MyGUI::Window* win = w->castType<MyGUI::Window>(false);
        if (win) win->setMovable(movable);
    }
    return 0;
}

static int widget_getMovable(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::Window* win = w->castType<MyGUI::Window>(false);
        if (win)
        {
            lua_pushboolean(L, win->getMovable());
            return 1;
        }
    }
    lua_pushboolean(L, false);
    return 1;
}

// ImageBox specific methods
static int widget_setImageTexture(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* texture = luaL_checkstring(L, 2);
    if (w)
    {
        MyGUI::ImageBox* ib = w->castType<MyGUI::ImageBox>(false);
        if (ib) ib->setImageTexture(texture);
    }
    return 0;
}

static int widget_setImageCoord(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    int width = (int)luaL_checkinteger(L, 4);
    int height = (int)luaL_checkinteger(L, 5);
    if (w)
    {
        MyGUI::ImageBox* ib = w->castType<MyGUI::ImageBox>(false);
        if (ib) ib->setImageCoord(MyGUI::IntCoord(x, y, width, height));
    }
    return 0;
}

static int widget_setImageTile(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int width = (int)luaL_checkinteger(L, 2);
    int height = (int)luaL_checkinteger(L, 3);
    if (w)
    {
        MyGUI::ImageBox* ib = w->castType<MyGUI::ImageBox>(false);
        if (ib) ib->setImageTile(MyGUI::IntSize(width, height));
    }
    return 0;
}

static int widget_setImageIndex(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int idx = (int)luaL_checkinteger(L, 2);
    if (w)
    {
        MyGUI::ImageBox* ib = w->castType<MyGUI::ImageBox>(false);
        if (ib) ib->setImageIndex(idx);
    }
    return 0;
}

static int widget_getImageIndex(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::ImageBox* ib = w->castType<MyGUI::ImageBox>(false);
        if (ib)
        {
            lua_pushinteger(L, ib->getImageIndex());
            return 1;
        }
    }
    lua_pushinteger(L, 0);
    return 1;
}

// Widget creation helpers
static int helper_createWidgetType(lua_State* L, const char* type)
{
    const char* skin = luaL_checkstring(L, 1);
    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    int w = (int)luaL_checkinteger(L, 4);
    int h = (int)luaL_checkinteger(L, 5);
    const char* name = luaL_checkstring(L, 6);

    MyGUI::Widget* parent = nullptr;
    std::string layer = "Window";

    if (lua_gettop(L) >= 7 && !lua_isnil(L, 7))
    {
        if (lua_isstring(L, 7))
        {
            layer = lua_tostring(L, 7);
        }
        else
        {
            parent = testObject<MyGUI::Widget>(L, 7, MyGuiBinding::getMetatableName());
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

static int lua_createButton(lua_State* L) { return helper_createWidgetType(L, "Button"); }
static int lua_createWindow(lua_State* L) { return helper_createWidgetType(L, "Window"); }
static int lua_createTextBox(lua_State* L) { return helper_createWidgetType(L, "TextBox"); }
static int lua_createEditBox(lua_State* L) { return helper_createWidgetType(L, "EditBox"); }
static int lua_createComboBox(lua_State* L) { return helper_createWidgetType(L, "ComboBox"); }
static int lua_createListBox(lua_State* L) { return helper_createWidgetType(L, "ListBox"); }
static int lua_createProgressBar(lua_State* L) { return helper_createWidgetType(L, "ProgressBar"); }
static int lua_createScrollView(lua_State* L) { return helper_createWidgetType(L, "ScrollView"); }
static int lua_createTabControl(lua_State* L) { return helper_createWidgetType(L, "TabControl"); }
static int lua_createImageBox(lua_State* L) { return helper_createWidgetType(L, "ImageBox"); }

// Layout / Resource helper functions
static int lua_unloadLayout(lua_State* L)
{
    if (lua_istable(L, 1))
    {
        MyGUI::VectorWidgetPtr widgets;
        int len = (int)lua_rawlen(L, 1);
        for (int i = 1; i <= len; ++i)
        {
            lua_rawgeti(L, 1, i);
            MyGUI::Widget* w = testObject<MyGUI::Widget>(L, -1, MyGuiBinding::getMetatableName());
            if (w)
            {
                widgets.push_back(w);
                LuaWidgetCallbackManager::get().clearCallbacksForWidget(w);
            }
            lua_pop(L, 1);
        }
        if (!widgets.empty())
        {
            MyGUI::LayoutManager::getInstance().unloadLayout(widgets);
        }
    }
    return 0;
}

static int lua_loadResource(lua_State* L)
{
    const char* file = luaL_checkstring(L, 1);
    bool success = MyGUI::ResourceManager::getInstance().load(file);
    lua_pushboolean(L, success ? 1 : 0);
    return 1;
}

static int lua_isResourceExist(lua_State* L)
{
    const char* name = luaL_checkstring(L, 1);
    bool exist = MyGUI::ResourceManager::getInstance().isExist(name);
    lua_pushboolean(L, exist ? 1 : 0);
    return 1;
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
    LuaWidgetCallbackManager::get().setLuaState(L);

    static const luaL_Reg meta[] = {
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setSize",              widget_setSize },
        { "setPosition",          widget_setPosition },
        { "setCaption",           widget_setCaption },
        { "getCaption",           widget_getCaption },
        { "setVisible",           widget_setVisible },
        { "getVisible",           widget_getVisible },
        { "setEnabled",           widget_setEnabled },
        { "getEnabled",           widget_getEnabled },
        { "getType",              widget_getType },
        { "getName",              widget_getName },
        { "destroy",              widget_destroy },
        { "findWidget",           widget_findWidget },
        { "getClientWidget",      widget_getClientWidget },
        { "setProperty",          widget_setProperty },
        { "registerCallback",     widget_registerCallback },

        // Coordinate / Hierarchy / General methods
        { "getCoord",             widget_getCoord },
        { "setCoord",             widget_setCoord },
        { "getPosition",          widget_getPosition },
        { "getSize",              widget_getSize },
        { "getParent",            widget_getParent },
        { "detachFromWidget",     widget_detachFromWidget },
        { "attachToWidget",       widget_attachToWidget },
        { "setNeedKeyFocus",      widget_setNeedKeyFocus },
        { "setNeedMouseFocus",    widget_setNeedMouseFocus },
        { "setPointer",           widget_setPointer },
        { "setUserString",        widget_setUserString },
        { "getUserString",        widget_getUserString },
        { "isUserString",         widget_isUserString },
        { "clearUserString",      widget_clearUserString },

        // Button methods
        { "setStateSelected",     widget_setStateSelected },
        { "getStateSelected",     widget_getStateSelected },

        // EditBox methods
        { "setOnlyText",          widget_setOnlyText },
        { "getOnlyText",          widget_getOnlyText },
        { "setEditReadOnly",      widget_setEditReadOnly },
        { "getEditReadOnly",      widget_getEditReadOnly },
        { "setEditPassword",      widget_setEditPassword },
        { "getEditPassword",      widget_getEditPassword },
        { "setEditMultiLine",     widget_setEditMultiLine },
        { "getEditMultiLine",     widget_getEditMultiLine },
        { "setEditStatic",        widget_setEditStatic },
        { "getEditStatic",        widget_getEditStatic },
        { "setPasswordChar",      widget_setPasswordChar },

        // Item Container (ListBox / ComboBox / TabControl) methods
        { "getItemCount",         widget_getItemCount },
        { "addItem",              widget_addItem },
        { "insertItemAt",         widget_insertItemAt },
        { "removeItemAt",         widget_removeItemAt },
        { "removeAllItems",       widget_removeAllItems },
        { "getIndexSelected",     widget_getIndexSelected },
        { "setIndexSelected",     widget_setIndexSelected },
        { "clearIndexSelected",   widget_clearIndexSelected },
        { "getItemNameAt",        widget_getItemNameAt },
        { "setItemNameAt",        widget_setItemNameAt },

        // ListBox Specific methods
        { "getOptimalHeight",     widget_getOptimalHeight },
        { "getWidgetByIndex",     widget_getWidgetByIndex },

        // Window Specific methods
        { "setMinSize",           widget_setMinSize },
        { "getMinSize",           widget_getMinSize },
        { "setMaxSize",           widget_setMaxSize },
        { "getMaxSize",           widget_getMaxSize },
        { "setVisibleSmooth",     widget_setVisibleSmooth },
        { "destroySmooth",        widget_destroySmooth },
        { "setMovable",           widget_setMovable },
        { "getMovable",           widget_getMovable },

        // ImageBox Specific methods
        { "setImageTexture",      widget_setImageTexture },
        { "setImageCoord",        widget_setImageCoord },
        { "setImageTile",         widget_setImageTile },
        { "setImageIndex",        widget_setImageIndex },
        { "getImageIndex",        widget_getImageIndex },

        { 0, 0 }
    };
    registerClass(L, MyGuiBinding::getMetatableName(), meta, methods, widget_index, widget_newindex);

    lua_getglobal(L, "MyGUI");
    if (!lua_istable(L, -1))
    {
        lua_pop(L, 1);
        lua_newtable(L);
        lua_pushvalue(L, -1);
        lua_setglobal(L, "MyGUI");
    }
    
    // Core creation functions
    lua_pushcfunction(L, lua_createWidget);
    lua_setfield(L, -2, "createWidget");

    lua_pushcfunction(L, lua_loadLayout);
    lua_setfield(L, -2, "loadLayout");

    lua_pushcfunction(L, lua_resetKeyFocus);
    lua_setfield(L, -2, "resetKeyFocus");

    // Specific creation helper functions
    lua_pushcfunction(L, lua_createButton);
    lua_setfield(L, -2, "createButton");

    lua_pushcfunction(L, lua_createWindow);
    lua_setfield(L, -2, "createWindow");

    lua_pushcfunction(L, lua_createTextBox);
    lua_setfield(L, -2, "createTextBox");

    lua_pushcfunction(L, lua_createEditBox);
    lua_setfield(L, -2, "createEditBox");

    lua_pushcfunction(L, lua_createComboBox);
    lua_setfield(L, -2, "createComboBox");

    lua_pushcfunction(L, lua_createListBox);
    lua_setfield(L, -2, "createListBox");

    lua_pushcfunction(L, lua_createProgressBar);
    lua_setfield(L, -2, "createProgressBar");

    lua_pushcfunction(L, lua_createScrollView);
    lua_setfield(L, -2, "createScrollView");

    lua_pushcfunction(L, lua_createTabControl);
    lua_setfield(L, -2, "createTabControl");

    lua_pushcfunction(L, lua_createImageBox);
    lua_setfield(L, -2, "createImageBox");

    // Layout / Resource helpers
    lua_pushcfunction(L, lua_unloadLayout);
    lua_setfield(L, -2, "unloadLayout");

    lua_pushcfunction(L, lua_loadResource);
    lua_setfield(L, -2, "loadResource");

    lua_pushcfunction(L, lua_isResourceExist);
    lua_setfield(L, -2, "isResourceExist");

    // WidgetStyle enum constants
    lua_newtable(L);
    lua_pushinteger(L, (int)MyGUI::WidgetStyle::Child);
    lua_setfield(L, -2, "Child");
    lua_pushinteger(L, (int)MyGUI::WidgetStyle::Popup);
    lua_setfield(L, -2, "Popup");
    lua_pushinteger(L, (int)MyGUI::WidgetStyle::Overlapped);
    lua_setfield(L, -2, "Overlapped");
    lua_setfield(L, -2, "WidgetStyle");

    lua_pop(L, 1);
}

void MyGuiBinding::shutdown()
{
    LuaWidgetCallbackManager::get().clearAll();
}

} // namespace KenshiLua
