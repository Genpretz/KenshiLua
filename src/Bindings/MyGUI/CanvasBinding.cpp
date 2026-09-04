#include "pch.h"
#include "Bindings/MyGUI/CanvasBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::Canvas* CanvasBinding::getCanvas(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::Canvas>(false);
}

int CanvasBinding::createTexture(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c)
    {
        if (lua_gettop(L) >= 3 && lua_isnumber(L, 2) && lua_isnumber(L, 3))
        {
            int w = (int)luaL_checkinteger(L, 2);
            int h = (int)luaL_checkinteger(L, 3);
            int mode = (int)luaL_optinteger(L, 4, (int)MyGUI::Canvas::TRM_PT_VIEW_ALL);
            c->createTexture(w, h, (MyGUI::Canvas::TextureResizeMode)mode);
        }
        else
        {
            int mode = (int)luaL_optinteger(L, 2, (int)MyGUI::Canvas::TRM_PT_VIEW_ALL);
            c->createTexture((MyGUI::Canvas::TextureResizeMode)mode);
        }
    }
    return 0;
}

int CanvasBinding::destroyTexture(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c) c->destroyTexture();
    return 0;
}

int CanvasBinding::updateTexture(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c) c->updateTexture();
    return 0;
}

int CanvasBinding::isTextureCreated(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c) lua_pushboolean(L, c->isTextureCreated() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int CanvasBinding::isTextureManaged(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c) lua_pushboolean(L, c->isTextureManaged() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int CanvasBinding::setTextureManaged(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    bool managed = lua_toboolean(L, 2) != 0;
    if (c) c->setTextureManaged(managed);
    return 0;
}

int CanvasBinding::getTextureRealWidth(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c) lua_pushinteger(L, c->getTextureRealWidth());
    else lua_pushinteger(L, 0);
    return 1;
}

int CanvasBinding::getTextureRealHeight(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c) lua_pushinteger(L, c->getTextureRealHeight());
    else lua_pushinteger(L, 0);
    return 1;
}

int CanvasBinding::getTextureRealSize(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c)
    {
        MyGUI::IntSize sz = c->getTextureRealSize();
        lua_pushinteger(L, sz.width);
        lua_pushinteger(L, sz.height);
        return 2;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

int CanvasBinding::getTextureSrcWidth(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c) lua_pushinteger(L, c->getTextureSrcWidth());
    else lua_pushinteger(L, 0);
    return 1;
}

int CanvasBinding::getTextureSrcHeight(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c) lua_pushinteger(L, c->getTextureSrcHeight());
    else lua_pushinteger(L, 0);
    return 1;
}

int CanvasBinding::getTextureSrcSize(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c)
    {
        MyGUI::IntSize sz = c->getTextureSrcSize();
        lua_pushinteger(L, sz.width);
        lua_pushinteger(L, sz.height);
        return 2;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

int CanvasBinding::isTextureSrcSize(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c) lua_pushboolean(L, c->isTextureSrcSize() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int CanvasBinding::getTextureName(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c)
    {
        lua_pushstring(L, c->getTextureName().c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int CanvasBinding::getTextureFormat(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c)
    {
        lua_pushinteger(L, c->getTextureFormat().getValue());
        return 1;
    }
    lua_pushinteger(L, 0);
    return 1;
}

int CanvasBinding::setResizeMode(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    int mode = (int)luaL_checkinteger(L, 2);
    if (c) c->setResizeMode((MyGUI::Canvas::TextureResizeMode)mode);
    return 0;
}

int CanvasBinding::getResizeMode(lua_State* L)
{
    MyGUI::Canvas* c = getCanvas(L, 1);
    if (c) lua_pushinteger(L, (lua_Integer)c->getResizeMode());
    else lua_pushinteger(L, 0);
    return 1;
}

static int Canvas_tostring(lua_State* L)
{
    MyGUI::Canvas* c = CanvasBinding::getCanvas(L, 1);
    char buf[128];
    if (c)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.Canvas('%s'):%p", c->getName().c_str(), c);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.Canvas(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void CanvasBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", Canvas_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "createTexture",       createTexture },
        { "destroyTexture",      destroyTexture },
        { "updateTexture",       updateTexture },
        { "isTextureCreated",    isTextureCreated },
        { "isTextureManaged",    isTextureManaged },
        { "setTextureManaged",   setTextureManaged },
        { "getTextureRealWidth", getTextureRealWidth },
        { "getTextureRealHeight",getTextureRealHeight },
        { "getTextureRealSize",  getTextureRealSize },
        { "getTextureSrcWidth",  getTextureSrcWidth },
        { "getTextureSrcHeight", getTextureSrcHeight },
        { "getTextureSrcSize",   getTextureSrcSize },
        { "isTextureSrcSize",    isTextureSrcSize },
        { "getTextureName",      getTextureName },
        { "getTextureFormat",    getTextureFormat },
        { "setResizeMode",       setResizeMode },
        { "getResizeMode",       getResizeMode },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);
    setMetatableParent(L, getMetatableName(), WidgetBinding::getMetatableName());
}

} // namespace KenshiLua
