#include "pch.h"
#include "Bindings/MyGUI/ClipboardManagerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

int ClipboardManagerBinding::getInstance(lua_State* L)
{
    if (MyGUI::ClipboardManager::getInstancePtr())
    {
        return pushObject<MyGUI::ClipboardManager>(L, MyGUI::ClipboardManager::getInstancePtr(), getMetatableName());
    }
    lua_pushnil(L);
    return 1;
}

int ClipboardManagerBinding::setClipboardData(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    const char* type = luaL_checkstring(L, idx);
    const char* data = luaL_checkstring(L, idx + 1);
    if (MyGUI::ClipboardManager::getInstancePtr())
    {
        MyGUI::ClipboardManager::getInstance().setClipboardData(type, data);
    }
    return 0;
}

int ClipboardManagerBinding::clearClipboardData(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    const char* type = luaL_checkstring(L, idx);
    if (MyGUI::ClipboardManager::getInstancePtr())
    {
        MyGUI::ClipboardManager::getInstance().clearClipboardData(type);
    }
    return 0;
}

int ClipboardManagerBinding::getClipboardData(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    const char* type = luaL_checkstring(L, idx);
    if (MyGUI::ClipboardManager::getInstancePtr())
    {
        std::string d = MyGUI::ClipboardManager::getInstance().getClipboardData(type);
        lua_pushstring(L, d.c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int ClipboardManagerBinding::setText(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    const char* text = luaL_checkstring(L, idx);
    if (MyGUI::ClipboardManager::getInstancePtr())
    {
        MyGUI::ClipboardManager::getInstance().setClipboardData("Text", text);
    }
    return 0;
}

int ClipboardManagerBinding::getText(lua_State* L)
{
    if (MyGUI::ClipboardManager::getInstancePtr())
    {
        std::string d = MyGUI::ClipboardManager::getInstance().getClipboardData("Text");
        lua_pushstring(L, d.c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

void ClipboardManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc", noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getInstance",        getInstance },
        { "setClipboardData",   setClipboardData },
        { "clearClipboardData", clearClipboardData },
        { "getClipboardData",   getClipboardData },
        { "setText",            setText },
        { "getText",            getText },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "getInstance", getInstance);
    lua_setglobal(L, "ClipboardManager");
}

} // namespace KenshiLua
