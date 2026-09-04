#include "pch.h"
#include "Bindings/MyGUI/ImageBoxBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::ImageBox* ImageBoxBinding::getImageBox(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::ImageBox>(false);
}

int ImageBoxBinding::setImageTexture(lua_State* L)
{
    MyGUI::ImageBox* ib = getImageBox(L, 1);
    const char* tex = luaL_checkstring(L, 2);
    if (ib) ib->setImageTexture(tex);
    return 0;
}

int ImageBoxBinding::setImageCoord(lua_State* L)
{
    MyGUI::ImageBox* ib = getImageBox(L, 1);
    if (ib)
    {
        if (lua_gettop(L) >= 5)
        {
            int l = (int)luaL_checkinteger(L, 2);
            int t = (int)luaL_checkinteger(L, 3);
            int w = (int)luaL_checkinteger(L, 4);
            int h = (int)luaL_checkinteger(L, 5);
            ib->setImageCoord(MyGUI::IntCoord(l, t, w, h));
        }
        else
        {
            MyGUI::IntCoord c = MyGUIBindings::readIntCoord(L, 2);
            ib->setImageCoord(c);
        }
    }
    return 0;
}

int ImageBoxBinding::setImageTile(lua_State* L)
{
    MyGUI::ImageBox* ib = getImageBox(L, 1);
    if (ib)
    {
        if (lua_gettop(L) >= 3)
        {
            int w = (int)luaL_checkinteger(L, 2);
            int h = (int)luaL_checkinteger(L, 3);
            ib->setImageTile(MyGUI::IntSize(w, h));
        }
        else
        {
            MyGUI::IntSize sz = MyGUIBindings::readIntSize(L, 2);
            ib->setImageTile(sz);
        }
    }
    return 0;
}

int ImageBoxBinding::setImageIndex(lua_State* L)
{
    MyGUI::ImageBox* ib = getImageBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (ib) ib->setImageIndex(idx);
    return 0;
}

int ImageBoxBinding::getImageIndex(lua_State* L)
{
    MyGUI::ImageBox* ib = getImageBox(L, 1);
    if (ib) lua_pushinteger(L, (lua_Integer)ib->getImageIndex());
    else lua_pushinteger(L, 0);
    return 1;
}

int ImageBoxBinding::getItemCount(lua_State* L)
{
    MyGUI::ImageBox* ib = getImageBox(L, 1);
    if (ib) lua_pushinteger(L, (lua_Integer)ib->getItemCount());
    else lua_pushinteger(L, 0);
    return 1;
}

int ImageBoxBinding::setItemSelect(lua_State* L)
{
    MyGUI::ImageBox* ib = getImageBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (ib) ib->setItemSelect(idx);
    return 0;
}

int ImageBoxBinding::getItemSelect(lua_State* L)
{
    MyGUI::ImageBox* ib = getImageBox(L, 1);
    if (ib) lua_pushinteger(L, (lua_Integer)ib->getItemSelect());
    else lua_pushinteger(L, 0);
    return 1;
}

int ImageBoxBinding::resetItemSelect(lua_State* L)
{
    MyGUI::ImageBox* ib = getImageBox(L, 1);
    if (ib) ib->resetItemSelect();
    return 0;
}

int ImageBoxBinding::setItemResource(lua_State* L)
{
    MyGUI::ImageBox* ib = getImageBox(L, 1);
    const char* name = luaL_checkstring(L, 2);
    if (ib)
    {
        bool ok = ib->setItemResource(name);
        lua_pushboolean(L, ok ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

static int ImageBox_tostring(lua_State* L)
{
    MyGUI::ImageBox* ib = ImageBoxBinding::getImageBox(L, 1);
    char buf[128];
    if (ib)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.ImageBox('%s'):%p", ib->getName().c_str(), ib);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.ImageBox(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void ImageBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", ImageBox_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setImageTexture",   setImageTexture },
        { "setImageCoord",     setImageCoord },
        { "setImageTile",      setImageTile },
        { "setImageIndex",     setImageIndex },
        { "getImageIndex",     getImageIndex },
        { "getItemCount",      getItemCount },
        { "setItemSelect",     setItemSelect },
        { "getItemSelect",     getItemSelect },
        { "resetItemSelect",   resetItemSelect },
        { "setItemResource",   setItemResource },
        { "setImageResource",  setItemResource }, // alias for convenience
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);
    setMetatableParent(L, getMetatableName(), WidgetBinding::getMetatableName());
}

} // namespace KenshiLua
