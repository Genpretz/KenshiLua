#include "pch.h"
#include "Bindings/MyGUI/PointerManagerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

int PointerManagerBinding::getInstance(lua_State* L)
{
    if (MyGUI::PointerManager::getInstancePtr())
    {
        return pushObject<MyGUI::PointerManager>(L, MyGUI::PointerManager::getInstancePtr(), getMetatableName());
    }
    lua_pushnil(L);
    return 1;
}

int PointerManagerBinding::setPointer(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    const char* ptr = luaL_checkstring(L, idx);
    if (MyGUI::PointerManager::getInstancePtr())
    {
        MyGUI::PointerManager::getInstance().setPointer(ptr);
    }
    return 0;
}

int PointerManagerBinding::clearPointer(lua_State* L)
{
    if (MyGUI::PointerManager::getInstancePtr())
    {
        MyGUI::PointerManager::getInstance().resetToDefaultPointer();
    }
    return 0;
}

int PointerManagerBinding::getVisible(lua_State* L)
{
    if (MyGUI::PointerManager::getInstancePtr())
    {
        lua_pushboolean(L, MyGUI::PointerManager::getInstance().isVisible() ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

int PointerManagerBinding::setVisible(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    bool v = lua_toboolean(L, idx) != 0;
    if (MyGUI::PointerManager::getInstancePtr())
    {
        MyGUI::PointerManager::getInstance().setVisible(v);
    }
    return 0;
}

int PointerManagerBinding::isVisible(lua_State* L)
{
    return getVisible(L);
}

int PointerManagerBinding::getDefaultPointer(lua_State* L)
{
    if (MyGUI::PointerManager::getInstancePtr())
    {
        lua_pushstring(L, MyGUI::PointerManager::getInstance().getDefaultPointer().c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int PointerManagerBinding::setDefaultPointer(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    const char* ptr = luaL_checkstring(L, idx);
    if (MyGUI::PointerManager::getInstancePtr())
    {
        MyGUI::PointerManager::getInstance().setDefaultPointer(ptr);
    }
    return 0;
}

int PointerManagerBinding::getLayerName(lua_State* L)
{
    if (MyGUI::PointerManager::getInstancePtr())
    {
        lua_pushstring(L, MyGUI::PointerManager::getInstance().getLayerName().c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int PointerManagerBinding::setLayerName(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    const char* layer = luaL_checkstring(L, idx);
    if (MyGUI::PointerManager::getInstancePtr())
    {
        MyGUI::PointerManager::getInstance().setLayerName(layer);
    }
    return 0;
}

void PointerManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc", noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getInstance",       getInstance },
        { "setPointer",        setPointer },
        { "clearPointer",      clearPointer },
        { "getVisible",        getVisible },
        { "setVisible",        setVisible },
        { "isVisible",         isVisible },
        { "getDefaultPointer", getDefaultPointer },
        { "setDefaultPointer", setDefaultPointer },
        { "getLayerName",      getLayerName },
        { "setLayerName",      setLayerName },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);
    registerStaticMethod(L, "PointerManager", getInstance);
}

} // namespace KenshiLua
