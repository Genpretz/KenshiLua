#include "pch.h"
#include "kenshi\Dialogue.h"
#include "DialogueSpeechBubbleBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static DialogueSpeechBubble* getB(lua_State* L, int idx)
{
    return checkObject<DialogueSpeechBubble>(L, idx, DialogueSpeechBubbleBinding::getMetatableName());
}

// --- Getters for DialogueSpeechBubble ---
static int DialogueSpeechBubble_get_stayOnScreen(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");
    lua_pushboolean(L, b->stayOnScreen ? 1 : 0);
    return 1;
}

static int DialogueSpeechBubble_get_shout(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");
    lua_pushboolean(L, b->shout ? 1 : 0);
    return 1;
}

static int DialogueSpeechBubble_get_marginW(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");
    lua_pushinteger(L, b->marginW);
    return 1;
}

static int DialogueSpeechBubble_get_marginH(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");
    lua_pushinteger(L, b->marginH);
    return 1;
}

static int DialogueSpeechBubble_get_textBox(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");
    lua_pushinteger(L, (lua_Integer)b->textBox);
    return 1;
}

static int DialogueSpeechBubble_get_baseSize(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");
    // TODO: Unsupported type for baseSize (MyGUI::types::TSize<int>)
    return luaL_error(L, "Unsupported property 'baseSize' (type: MyGUI::types::TSize<int>)");
}

// --- Setters for DialogueSpeechBubble ---
static int DialogueSpeechBubble_set_stayOnScreen(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");
    b->stayOnScreen = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogueSpeechBubble_set_shout(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");
    b->shout = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogueSpeechBubble_set_marginW(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");
    b->marginW = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogueSpeechBubble_set_marginH(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");
    b->marginH = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogueSpeechBubble_set_textBox(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");
    return luaL_error(L, "Read-only or unsupported setter type for textBox");
}

static int DialogueSpeechBubble_set_baseSize(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");
    return luaL_error(L, "Read-only or unsupported setter type for baseSize");
}

int DialogueSpeechBubbleBinding::_DESTRUCTOR(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");

    b->_DESTRUCTOR();
    return 0;
}

int DialogueSpeechBubbleBinding::setText(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");

    std::string text = luaL_checkstring(L, 2);
    b->setText(text);
    return 0;
}

int DialogueSpeechBubbleBinding::setAlpha(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");

    float value = (float)luaL_checknumber(L, 2);
    b->setAlpha(value);
    return 0;
}

int DialogueSpeechBubbleBinding::reset(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");

    b->reset();
    return 0;
}

int DialogueSpeechBubbleBinding::getAlpha(lua_State* L)
{
    DialogueSpeechBubble* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogueSpeechBubble is nil");

    float result = b->getAlpha();
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 102: DialogueSpeechBubble* _CONSTRUCTOR(...) - unsupported return type
  line 107: void setPosition(...) - overloaded method
  line 108: void setPosition(...) - overloaded method
  line 111: MyGUI::types::TRect<int> getRect(...) - unsupported return type
*/

int DialogueSpeechBubbleBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DialogueSpeechBubbleBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DialogueSpeechBubble object");
    return 1;
}

void DialogueSpeechBubbleBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogueSpeechBubbleBinding::gc },
        { "__tostring", DialogueSpeechBubbleBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", DialogueSpeechBubbleBinding::_DESTRUCTOR },
        { "setText", DialogueSpeechBubbleBinding::setText },
        { "setAlpha", DialogueSpeechBubbleBinding::setAlpha },
        { "reset", DialogueSpeechBubbleBinding::reset },
        { "getAlpha", DialogueSpeechBubbleBinding::getAlpha },
        { 0, 0 }
    };

    registerClass(
        L, 
        DialogueSpeechBubbleBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DialogueSpeechBubbleBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DialogueSpeechBubble_get_stayOnScreen);
    lua_setfield(L, -2, "stayOnScreen");
    lua_pushcfunction(L, DialogueSpeechBubble_get_shout);
    lua_setfield(L, -2, "shout");
    lua_pushcfunction(L, DialogueSpeechBubble_get_marginW);
    lua_setfield(L, -2, "marginW");
    lua_pushcfunction(L, DialogueSpeechBubble_get_marginH);
    lua_setfield(L, -2, "marginH");
    lua_pushcfunction(L, DialogueSpeechBubble_get_textBox);
    lua_setfield(L, -2, "textBox");
    lua_pushcfunction(L, DialogueSpeechBubble_get_baseSize);
    lua_setfield(L, -2, "baseSize");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DialogueSpeechBubble_set_stayOnScreen);
    lua_setfield(L, -2, "stayOnScreen");
    lua_pushcfunction(L, DialogueSpeechBubble_set_shout);
    lua_setfield(L, -2, "shout");
    lua_pushcfunction(L, DialogueSpeechBubble_set_marginW);
    lua_setfield(L, -2, "marginW");
    lua_pushcfunction(L, DialogueSpeechBubble_set_marginH);
    lua_setfield(L, -2, "marginH");
    lua_pushcfunction(L, DialogueSpeechBubble_set_textBox);
    lua_setfield(L, -2, "textBox");
    lua_pushcfunction(L, DialogueSpeechBubble_set_baseSize);
    lua_setfield(L, -2, "baseSize");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua