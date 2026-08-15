#include "pch.h"
#include "kenshi\dialogue.h"
#include "DialogueSpeechBubbleBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static DialogueSpeechBubble* getInstance(lua_State* L, int idx)
{
    return checkObject<DialogueSpeechBubble>(L, idx, DialogueSpeechBubbleBinding::getMetatableName());
}

// --- Getters for DialogueSpeechBubble ---
static int DialogueSpeechBubble_get_stayOnScreen(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");
    lua_pushboolean(L, instance->stayOnScreen ? 1 : 0);
    return 1;
}

static int DialogueSpeechBubble_get_shout(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");
    lua_pushboolean(L, instance->shout ? 1 : 0);
    return 1;
}

static int DialogueSpeechBubble_get_marginW(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");
    lua_pushinteger(L, instance->marginW);
    return 1;
}

static int DialogueSpeechBubble_get_marginH(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");
    lua_pushinteger(L, instance->marginH);
    return 1;
}

static int DialogueSpeechBubble_get_textBox(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");
    lua_pushlightuserdata(L, (void*)instance->textBox);
    return 1;
}

// --- Setters for DialogueSpeechBubble ---
static int DialogueSpeechBubble_get_baseSize(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");
    lua_newtable(L);
    lua_pushinteger(L, instance->baseSize.width);
    lua_setfield(L, -2, "width");
    lua_pushinteger(L, instance->baseSize.height);
    lua_setfield(L, -2, "height");
    return 1;
}

static int DialogueSpeechBubble_set_stayOnScreen(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");
    instance->stayOnScreen = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogueSpeechBubble_set_shout(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");
    instance->shout = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DialogueSpeechBubble_set_marginW(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");
    instance->marginW = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogueSpeechBubble_set_marginH(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");
    instance->marginH = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogueSpeechBubble_set_textBox(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");
    instance->textBox = (MyGUI::EditBox*)lua_touserdata(L, 2);
    return 0;
}

static int DialogueSpeechBubble_set_baseSize(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");
    if (!lua_istable(L, 2)) return luaL_error(L, "Argument 2 to set baseSize must be a table {width, height}");
    lua_getfield(L, 2, "width");
    int w = (int)luaL_optinteger(L, -1, instance->baseSize.width);
    lua_pop(L, 1);
    lua_getfield(L, 2, "height");
    int h = (int)luaL_optinteger(L, -1, instance->baseSize.height);
    lua_pop(L, 1);
    instance->baseSize.width = w;
    instance->baseSize.height = h;
    return 0;
}

int DialogueSpeechBubbleBinding::setText(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");

    const std::string text = luaL_checkstring(L, 2);
    instance->setText(text);
    return 0;
}

int DialogueSpeechBubbleBinding::setAlpha(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");

    float value = (float)luaL_checknumber(L, 2);
    instance->setAlpha(value);
    return 0;
}

int DialogueSpeechBubbleBinding::setPosition(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");

    if (lua_gettop(L) >= 3 && lua_isnumber(L, 2) && lua_isnumber(L, 3))
    {
        int x = (int)luaL_checkinteger(L, 2);
        int y = (int)luaL_checkinteger(L, 3);
        instance->setPosition(x, y);
    }
    else
    {
        Ogre::Vector3 pos;
        readVector3(L, 2, pos);
        instance->setPosition(pos);
    }
    return 0;
}

int DialogueSpeechBubbleBinding::reset(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");

    instance->reset();
    return 0;
}

int DialogueSpeechBubbleBinding::getAlpha(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");

    float result = instance->getAlpha();
    lua_pushnumber(L, result);
    return 1;
}

int DialogueSpeechBubbleBinding::getRect(lua_State* L)
{
    DialogueSpeechBubble* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueSpeechBubble is nil");

    MyGUI::types::TRect<int> r = instance->getRect();
    lua_newtable(L);
    lua_pushinteger(L, r.left);
    lua_setfield(L, -2, "left");
    lua_pushinteger(L, r.top);
    lua_setfield(L, -2, "top");
    lua_pushinteger(L, r.width());
    lua_setfield(L, -2, "width");
    lua_pushinteger(L, r.height());
    lua_setfield(L, -2, "height");
    return 1;
}

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
        { "setText", DialogueSpeechBubbleBinding::setText },
        { "setAlpha", DialogueSpeechBubbleBinding::setAlpha },
        { "setPosition", DialogueSpeechBubbleBinding::setPosition },
        { "reset", DialogueSpeechBubbleBinding::reset },
        { "getAlpha", DialogueSpeechBubbleBinding::getAlpha },
        { "getRect", DialogueSpeechBubbleBinding::getRect },
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
    registerGetter(L, "stayOnScreen", DialogueSpeechBubble_get_stayOnScreen);
    registerGetter(L, "shout", DialogueSpeechBubble_get_shout);
    registerGetter(L, "marginW", DialogueSpeechBubble_get_marginW);
    registerGetter(L, "marginH", DialogueSpeechBubble_get_marginH);
    registerGetter(L, "textBox", DialogueSpeechBubble_get_textBox);
    registerGetter(L, "baseSize", DialogueSpeechBubble_get_baseSize);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "stayOnScreen", DialogueSpeechBubble_set_stayOnScreen);
    registerSetter(L, "shout", DialogueSpeechBubble_set_shout);
    registerSetter(L, "marginW", DialogueSpeechBubble_set_marginW);
    registerSetter(L, "marginH", DialogueSpeechBubble_set_marginH);
    registerSetter(L, "textBox", DialogueSpeechBubble_set_textBox);
    registerSetter(L, "baseSize", DialogueSpeechBubble_set_baseSize);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua