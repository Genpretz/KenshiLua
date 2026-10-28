#include "pch.h"
#include "Bindings/MyGUI/TextBoxBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Bindings/MyGUI/TypesBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::TextBox* TextBoxBinding::getTextBox(lua_State* L, int idx)
{
    return MyGUIBindings::checkWidget<MyGUI::TextBox>(L, idx);
}

int TextBoxBinding::getTextRegion(lua_State* L)
{
    MyGUI::TextBox* tb = getTextBox(L, 1);
    if (tb)
    {
        MyGUI::IntCoord c = tb->getTextRegion();
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

int TextBoxBinding::getTextSize(lua_State* L)
{
    MyGUI::TextBox* tb = getTextBox(L, 1);
    if (tb)
    {
        MyGUI::IntSize s = tb->getTextSize();
        lua_pushinteger(L, s.width);
        lua_pushinteger(L, s.height);
        return 2;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

int TextBoxBinding::setFontName(lua_State* L)
{
    MyGUI::TextBox* tb = getTextBox(L, 1);
    const char* font = luaL_checkstring(L, 2);
    if (tb) tb->setFontName(font);
    return 0;
}

int TextBoxBinding::getFontName(lua_State* L)
{
    MyGUI::TextBox* tb = getTextBox(L, 1);
    if (tb)
    {
        lua_pushstring(L, tb->getFontName().c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int TextBoxBinding::setFontHeight(lua_State* L)
{
    MyGUI::TextBox* tb = getTextBox(L, 1);
    int h = (int)luaL_checkinteger(L, 2);
    if (tb) tb->setFontHeight(h);
    return 0;
}

int TextBoxBinding::getFontHeight(lua_State* L)
{
    MyGUI::TextBox* tb = getTextBox(L, 1);
    if (tb) lua_pushinteger(L, tb->getFontHeight());
    else lua_pushinteger(L, 0);
    return 1;
}

int TextBoxBinding::setTextAlign(lua_State* L)
{
    MyGUI::TextBox* tb = getTextBox(L, 1);
    int a = (int)luaL_checkinteger(L, 2);
    if (tb) tb->setTextAlign(MyGUI::Align((MyGUI::Align::Enum)a));
    return 0;
}

int TextBoxBinding::getTextAlign(lua_State* L)
{
    MyGUI::TextBox* tb = getTextBox(L, 1);
    if (tb) lua_pushinteger(L, (lua_Integer)tb->getTextAlign().getValue());
    else lua_pushinteger(L, 0);
    return 1;
}

int TextBoxBinding::setTextColour(lua_State* L)
{
    MyGUI::TextBox* tb = getTextBox(L, 1);
    if (tb)
    {
        MyGUI::Colour col = MyGUIBindings::readColour(L, 2);
        tb->setTextColour(col);
    }
    return 0;
}

int TextBoxBinding::getTextColour(lua_State* L)
{
    MyGUI::TextBox* tb = getTextBox(L, 1);
    if (tb)
    {
        MyGUI::Colour col = tb->getTextColour();
        return pushValue<MyGUI::Colour>(L, col, ColourBinding::getMetatableName());
    }
    lua_pushnil(L);
    return 1;
}

int TextBoxBinding::setCaptionWithReplacing(lua_State* L)
{
    MyGUI::TextBox* tb = getTextBox(L, 1);
    const char* text = luaL_checkstring(L, 2);
    if (tb) tb->setCaptionWithReplacing(text);
    return 0;
}

static int TextBox_tostring(lua_State* L)
{
    MyGUI::Widget* w = MyGUIBindings::toWidget(L, 1);
    MyGUI::TextBox* tb = w ? w->castType<MyGUI::TextBox>(false) : nullptr;
    char buf[128];
    if (tb)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.TextBox('%s'):%p", tb->getName().c_str(), tb);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.TextBox(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void TextBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", TextBox_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getTextRegion",            getTextRegion },
        { "getTextSize",              getTextSize },
        { "setFontName",              setFontName },
        { "getFontName",              getFontName },
        { "setFontHeight",            setFontHeight },
        { "getFontHeight",            getFontHeight },
        { "setTextAlign",             setTextAlign },
        { "getTextAlign",             getTextAlign },
        { "setTextColour",            setTextColour },
        { "getTextColour",            getTextColour },
        { "setCaptionWithReplacing",  setCaptionWithReplacing },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L);
    registerGetter(L, "fontName", TextBoxBinding::getFontName);
    registerGetter(L, "fontHeight", TextBoxBinding::getFontHeight);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "fontName", TextBoxBinding::setFontName);
    registerSetter(L, "fontHeight", TextBoxBinding::setFontHeight);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);

    setMetatableParent(L, getMetatableName(), WidgetBinding::getMetatableName());
}

} // namespace KenshiLua
