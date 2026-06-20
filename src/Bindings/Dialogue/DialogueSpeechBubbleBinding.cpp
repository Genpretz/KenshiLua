#include "pch.h"
#include "Bindings/Dialogue/DialogueSpeechBubbleBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Dialogue.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static DialogueSpeechBubble* getS(lua_State* L, int idx)
{
    return checkObject<DialogueSpeechBubble>(L, idx, DialogueSpeechBubbleBinding::getMetatableName());
}

int DialogueSpeechBubbleBinding::gc(lua_State* L) { return noopGc(L); }

int DialogueSpeechBubbleBinding::tostring(lua_State* L)
{
    DialogueSpeechBubble* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int DialogueSpeechBubbleBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, DialogueSpeechBubbleBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    DialogueSpeechBubble* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "stayOnScreen") == 0) { lua_pushboolean(L, s->stayOnScreen ? 1 : 0); return 1; }
    if (strcmp(key, "shout") == 0) { lua_pushboolean(L, s->shout ? 1 : 0); return 1; }
    if (strcmp(key, "marginW") == 0) { lua_pushinteger(L, s->marginW); return 1; }
    if (strcmp(key, "marginH") == 0) { lua_pushinteger(L, s->marginH); return 1; }
    if (strcmp(key, "textBox") == 0) { lua_pushinteger(L, (lua_Integer)s->textBox); return 1; }
    // TODO MyGUI::types::TSize<int> baseSize; unsupported __index type from header line 117

    lua_pushnil(L);
    return 1;
}

int DialogueSpeechBubbleBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    DialogueSpeechBubble* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogueSpeechBubble is nil");

    if (strcmp(key, "stayOnScreen") == 0) { s->stayOnScreen = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "shout") == 0) { s->shout = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "marginW") == 0) { s->marginW = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "marginH") == 0) { s->marginH = (int)luaL_checkinteger(L, 3); return 0; }
    // TODO MyGUI::EditBox* textBox; unsupported __newindex type from header line 116
    // TODO MyGUI::types::TSize<int> baseSize; unsupported __newindex type from header line 117

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int DialogueSpeechBubbleBinding::_DESTRUCTOR(lua_State* L)
{
    DialogueSpeechBubble* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogueSpeechBubble is nil");

    s->_DESTRUCTOR();
    return 0;
}

int DialogueSpeechBubbleBinding::setText(lua_State* L)
{
    DialogueSpeechBubble* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogueSpeechBubble is nil");

    std::string text = luaL_checkstring(L, 2);
    s->setText(text);
    return 0;
}

int DialogueSpeechBubbleBinding::setAlpha(lua_State* L)
{
    DialogueSpeechBubble* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogueSpeechBubble is nil");

    float value = (float)luaL_checknumber(L, 2);
    s->setAlpha(value);
    return 0;
}

int DialogueSpeechBubbleBinding::reset(lua_State* L)
{
    DialogueSpeechBubble* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogueSpeechBubble is nil");

    s->reset();
    return 0;
}

int DialogueSpeechBubbleBinding::getAlpha(lua_State* L)
{
    DialogueSpeechBubble* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogueSpeechBubble is nil");

    float result = s->getAlpha();
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

void DialogueSpeechBubbleBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogueSpeechBubbleBinding::gc },
        { "__tostring", DialogueSpeechBubbleBinding::tostring },
        { "__index",    DialogueSpeechBubbleBinding::index },
        { "__newindex", DialogueSpeechBubbleBinding::newindex },
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
    registerClass(L, DialogueSpeechBubbleBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua