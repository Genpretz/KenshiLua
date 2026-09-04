#include "pch.h"
#include "Bindings/MyGUI/SkinManagerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::SkinManager* SkinManagerBinding::getSkinManager(lua_State* L, int idx)
{
    if (lua_isuserdata(L, idx))
    {
        return checkObject<MyGUI::SkinManager>(L, idx, getMetatableName());
    }
    return MyGUI::SkinManager::getInstancePtr();
}

int SkinManagerBinding::getInstance(lua_State* L)
{
    MyGUI::SkinManager* sm = MyGUI::SkinManager::getInstancePtr();
    if (!sm) {
        lua_pushnil(L);
        return 1;
    }
    return pushObject<MyGUI::SkinManager>(L, sm, getMetatableName());
}

int SkinManagerBinding::isExist(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    const char* name = luaL_checkstring(L, idx);
    MyGUI::SkinManager* sm = MyGUI::SkinManager::getInstancePtr();
    if (sm)
    {
        lua_pushboolean(L, sm->isExist(name) ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

int SkinManagerBinding::getDefaultSkin(lua_State* L)
{
    MyGUI::SkinManager* sm = MyGUI::SkinManager::getInstancePtr();
    if (sm)
    {
        lua_pushstring(L, sm->getDefaultSkin().c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int SkinManagerBinding::setDefaultSkin(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    const char* skin = luaL_checkstring(L, idx);
    MyGUI::SkinManager* sm = MyGUI::SkinManager::getInstancePtr();
    if (sm)
    {
        sm->setDefaultSkin(skin);
    }
    return 0;
}

static int SkinManager_tostring(lua_State* L)
{
    MyGUI::SkinManager* sm = SkinManagerBinding::getSkinManager(L, 1);
    char buf[128];
    if (sm)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.SkinManager:%p", sm);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.SkinManager(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void SkinManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", SkinManager_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getInstance",    getInstance },
        { "isExist",        isExist },
        { "getDefaultSkin", getDefaultSkin },
        { "setDefaultSkin", setDefaultSkin },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);
}

} // namespace KenshiLua
