#include "pch.h"
#include "Bindings/MyGUI/EditBoxBinding.h"
#include "Bindings/MyGUI/TextBoxBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::EditBox* EditBoxBinding::getEditBox(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::EditBox>(false);
}

int EditBoxBinding::getTextSelection(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb)
    {
        std::string sel = eb->getTextSelection();
        lua_pushstring(L, sel.c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int EditBoxBinding::setTextSelection(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    size_t start = (size_t)luaL_checkinteger(L, 2);
    size_t end = (size_t)luaL_checkinteger(L, 3);
    if (eb) eb->setTextSelection(start, end);
    return 0;
}

int EditBoxBinding::deleteTextSelection(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb) eb->deleteTextSelection();
    return 0;
}

int EditBoxBinding::isTextSelection(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb) lua_pushboolean(L, eb->isTextSelection() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int EditBoxBinding::getTextSelectionStart(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb) lua_pushinteger(L, (lua_Integer)eb->getTextSelectionStart());
    else lua_pushinteger(L, 0);
    return 1;
}

int EditBoxBinding::getTextSelectionEnd(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb) lua_pushinteger(L, (lua_Integer)eb->getTextSelectionEnd());
    else lua_pushinteger(L, 0);
    return 1;
}

int EditBoxBinding::getTextSelectionLength(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb) lua_pushinteger(L, (lua_Integer)eb->getTextSelectionLength());
    else lua_pushinteger(L, 0);
    return 1;
}

int EditBoxBinding::getTextInterval(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    size_t start = (size_t)luaL_checkinteger(L, 2);
    size_t count = (size_t)luaL_checkinteger(L, 3);
    if (eb)
    {
        std::string s = eb->getTextInterval(start, count);
        lua_pushstring(L, s.c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int EditBoxBinding::setTextCursor(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    size_t pos = (size_t)luaL_checkinteger(L, 2);
    if (eb) eb->setTextCursor(pos);
    return 0;
}

int EditBoxBinding::getTextCursor(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb) lua_pushinteger(L, (lua_Integer)eb->getTextCursor());
    else lua_pushinteger(L, 0);
    return 1;
}

int EditBoxBinding::getTextLength(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb) lua_pushinteger(L, (lua_Integer)eb->getTextLength());
    else lua_pushinteger(L, 0);
    return 1;
}

int EditBoxBinding::setOverflowToTheLeft(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    bool val = lua_toboolean(L, 2) != 0;
    if (eb) eb->setOverflowToTheLeft(val);
    return 0;
}

int EditBoxBinding::getOverflowToTheLeft(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb) lua_pushboolean(L, eb->getOverflowToTheLeft() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int EditBoxBinding::setMaxTextLength(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    size_t len = (size_t)luaL_checkinteger(L, 2);
    if (eb) eb->setMaxTextLength(len);
    return 0;
}

int EditBoxBinding::getMaxTextLength(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb) lua_pushinteger(L, (lua_Integer)eb->getMaxTextLength());
    else lua_pushinteger(L, 0);
    return 1;
}

int EditBoxBinding::setEditWordWrap(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    bool wrap = lua_toboolean(L, 2) != 0;
    if (eb) eb->setEditWordWrap(wrap);
    return 0;
}

int EditBoxBinding::getEditWordWrap(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb) lua_pushboolean(L, eb->getEditWordWrap() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int EditBoxBinding::setEditReadOnly(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    bool ro = lua_toboolean(L, 2) != 0;
    if (eb) eb->setEditReadOnly(ro);
    return 0;
}

int EditBoxBinding::getEditReadOnly(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb) lua_pushboolean(L, eb->getEditReadOnly() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int EditBoxBinding::setEditMultiLine(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    bool ml = lua_toboolean(L, 2) != 0;
    if (eb) eb->setEditMultiLine(ml);
    return 0;
}

int EditBoxBinding::getEditMultiLine(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb) lua_pushboolean(L, eb->getEditMultiLine() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int EditBoxBinding::setEditPassword(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    bool p = lua_toboolean(L, 2) != 0;
    if (eb) eb->setEditPassword(p);
    return 0;
}

int EditBoxBinding::getEditPassword(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb) lua_pushboolean(L, eb->getEditPassword() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int EditBoxBinding::setEditStatic(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    bool s = lua_toboolean(L, 2) != 0;
    if (eb) eb->setEditStatic(s);
    return 0;
}

int EditBoxBinding::getEditStatic(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb) lua_pushboolean(L, eb->getEditStatic() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int EditBoxBinding::setPasswordChar(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    const char* str = luaL_checkstring(L, 2);
    if (eb && str && str[0]) eb->setPasswordChar(str[0]);
    return 0;
}

int EditBoxBinding::getPasswordChar(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb)
    {
        char buf[2] = { (char)eb->getPasswordChar(), '\0' };
        lua_pushstring(L, buf);
        return 1;
    }
    lua_pushstring(L, "*");
    return 1;
}

int EditBoxBinding::setOnlyText(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    const char* text = luaL_checkstring(L, 2);
    if (eb) eb->setOnlyText(text);
    return 0;
}

int EditBoxBinding::getOnlyText(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb)
    {
        std::string ot = eb->getOnlyText().asUTF8();
        lua_pushstring(L, ot.c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int EditBoxBinding::addText(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    const char* text = luaL_checkstring(L, 2);
    if (eb) eb->addText(text);
    return 0;
}

int EditBoxBinding::insertText(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    const char* text = luaL_checkstring(L, 2);
    size_t idx = (size_t)luaL_optinteger(L, 3, (lua_Integer)MyGUI::ITEM_NONE);
    if (eb) eb->insertText(text, idx);
    return 0;
}

int EditBoxBinding::eraseText(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    size_t start = (size_t)luaL_checkinteger(L, 2);
    size_t count = (size_t)luaL_optinteger(L, 3, 1);
    if (eb) eb->eraseText(start, count);
    return 0;
}

int EditBoxBinding::setTextIntervalColour(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    size_t start = (size_t)luaL_checkinteger(L, 2);
    size_t count = (size_t)luaL_checkinteger(L, 3);
    if (eb)
    {
        MyGUI::Colour col = MyGUIBindings::readColour(L, 4);
        eb->setTextIntervalColour(start, count, col);
    }
    return 0;
}

int EditBoxBinding::setTextSelectionColour(lua_State* L)
{
    MyGUI::EditBox* eb = getEditBox(L, 1);
    if (eb)
    {
        MyGUI::Colour col = MyGUIBindings::readColour(L, 2);
        eb->setTextSelectionColour(col);
    }
    return 0;
}

static int EditBox_index(lua_State* L)
{
    MyGUI::EditBox* eb = EditBoxBinding::getEditBox(L, 1);
    if (!eb) return luaL_error(L, "EditBox is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "readOnly") == 0)
    {
        lua_pushboolean(L, eb->getEditReadOnly() ? 1 : 0);
        return 1;
    }
    if (strcmp(key, "multiLine") == 0)
    {
        lua_pushboolean(L, eb->getEditMultiLine() ? 1 : 0);
        return 1;
    }
    if (strcmp(key, "wordWrap") == 0)
    {
        lua_pushboolean(L, eb->getEditWordWrap() ? 1 : 0);
        return 1;
    }
    return genericPropertyIndex(L);
}

static int EditBox_newindex(lua_State* L)
{
    MyGUI::EditBox* eb = EditBoxBinding::getEditBox(L, 1);
    if (!eb) return luaL_error(L, "EditBox is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "readOnly") == 0)
    {
        eb->setEditReadOnly(lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "multiLine") == 0)
    {
        eb->setEditMultiLine(lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "wordWrap") == 0)
    {
        eb->setEditWordWrap(lua_toboolean(L, 3) != 0);
        return 0;
    }
    return genericPropertyNewIndex(L);
}

static int EditBox_tostring(lua_State* L)
{
    MyGUI::EditBox* eb = EditBoxBinding::getEditBox(L, 1);
    char buf[128];
    if (eb)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.EditBox('%s'):%p", eb->getName().c_str(), eb);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.EditBox(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void EditBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", EditBox_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getTextSelection",        getTextSelection },
        { "setTextSelection",        setTextSelection },
        { "deleteTextSelection",     deleteTextSelection },
        { "isTextSelection",         isTextSelection },
        { "getTextSelectionStart",   getTextSelectionStart },
        { "getTextSelectionEnd",     getTextSelectionEnd },
        { "getTextSelectionLength",  getTextSelectionLength },
        { "getTextInterval",         getTextInterval },
        { "setTextCursor",           setTextCursor },
        { "getTextCursor",           getTextCursor },
        { "getTextLength",           getTextLength },
        { "setOverflowToTheLeft",    setOverflowToTheLeft },
        { "getOverflowToTheLeft",    getOverflowToTheLeft },
        { "setMaxTextLength",        setMaxTextLength },
        { "getMaxTextLength",        getMaxTextLength },
        { "setEditWordWrap",         setEditWordWrap },
        { "getEditWordWrap",         getEditWordWrap },
        { "setEditReadOnly",         setEditReadOnly },
        { "getEditReadOnly",         getEditReadOnly },
        { "setEditMultiLine",        setEditMultiLine },
        { "getEditMultiLine",        getEditMultiLine },
        { "setEditPassword",         setEditPassword },
        { "getEditPassword",         getEditPassword },
        { "setEditStatic",           setEditStatic },
        { "getEditStatic",           getEditStatic },
        { "setPasswordChar",         setPasswordChar },
        { "getPasswordChar",         getPasswordChar },
        { "setOnlyText",             setOnlyText },
        { "getOnlyText",             getOnlyText },
        { "addText",                 addText },
        { "insertText",              insertText },
        { "eraseText",               eraseText },
        { "setTextIntervalColour",   setTextIntervalColour },
        { "setTextSelectionColour",  setTextSelectionColour },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, EditBox_index, EditBox_newindex);
    setMetatableParent(L, getMetatableName(), TextBoxBinding::getMetatableName());
}

} // namespace KenshiLua
