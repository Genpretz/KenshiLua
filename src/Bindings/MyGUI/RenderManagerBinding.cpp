#include "pch.h"
#include "Bindings/MyGUI/RenderManagerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

int RenderManagerBinding::getInstance(lua_State* L)
{
    if (MyGUI::RenderManager::getInstancePtr())
    {
        return pushObject<MyGUI::RenderManager>(L, MyGUI::RenderManager::getInstancePtr(), getMetatableName());
    }
    lua_pushnil(L);
    return 1;
}

int RenderManagerBinding::getViewSize(lua_State* L)
{
    if (MyGUI::RenderManager::getInstancePtr())
    {
        MyGUI::IntSize sz = MyGUI::RenderManager::getInstance().getViewSize();
        lua_pushinteger(L, sz.width);
        lua_pushinteger(L, sz.height);
        return 2;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

int RenderManagerBinding::getViewWidth(lua_State* L)
{
    if (MyGUI::RenderManager::getInstancePtr())
    {
        lua_pushinteger(L, MyGUI::RenderManager::getInstance().getViewSize().width);
        return 1;
    }
    lua_pushinteger(L, 0);
    return 1;
}

int RenderManagerBinding::getViewHeight(lua_State* L)
{
    if (MyGUI::RenderManager::getInstancePtr())
    {
        lua_pushinteger(L, MyGUI::RenderManager::getInstance().getViewSize().height);
        return 1;
    }
    lua_pushinteger(L, 0);
    return 1;
}

void RenderManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc", noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getInstance",   getInstance },
        { "getViewSize",   getViewSize },
        { "getViewWidth",  getViewWidth },
        { "getViewHeight", getViewHeight },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "getInstance", getInstance);
    lua_setglobal(L, "RenderManager");
}

} // namespace KenshiLua
