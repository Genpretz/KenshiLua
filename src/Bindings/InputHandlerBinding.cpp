#include "pch.h"
#include "kenshi\InputHandler.h"
#include "InputHandlerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static InputHandler* getInstance(lua_State* L, int idx)
{
    return checkObject<InputHandler>(L, idx, InputHandlerBinding::getMetatableName());
}

// --- Getters for InputHandler ---
static int InputHandler_get_keyboard(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushlightuserdata(L, (void*)instance->keyboard);
    return 1;
}

static int InputHandler_get_controlEnabled(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->controlEnabled ? 1 : 0);
    return 1;
}

static int InputHandler_get_gameMode(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushinteger(L, (lua_Integer)instance->gameMode);
    return 1;
}

static int InputHandler_get_ctrl(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->ctrl ? 1 : 0);
    return 1;
}

static int InputHandler_get_shift(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->shift ? 1 : 0);
    return 1;
}

static int InputHandler_get_alt(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->alt ? 1 : 0);
    return 1;
}

static int InputHandler_get_up(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->up ? 1 : 0);
    return 1;
}

static int InputHandler_get_down(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->down ? 1 : 0);
    return 1;
}

static int InputHandler_get_left(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->left ? 1 : 0);
    return 1;
}

static int InputHandler_get_right(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->right ? 1 : 0);
    return 1;
}

static int InputHandler_get_space(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->space ? 1 : 0);
    return 1;
}

static int InputHandler_get_pgup(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->pgup ? 1 : 0);
    return 1;
}

static int InputHandler_get_pgdn(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->pgdn ? 1 : 0);
    return 1;
}

static int InputHandler_get_comma(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->comma ? 1 : 0);
    return 1;
}

static int InputHandler_get_period(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->period ? 1 : 0);
    return 1;
}

static int InputHandler_get_f1(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->f1 ? 1 : 0);
    return 1;
}

static int InputHandler_get_f2(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->f2 ? 1 : 0);
    return 1;
}

static int InputHandler_get_escape(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->escape ? 1 : 0);
    return 1;
}

static int InputHandler_get_del(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->del ? 1 : 0);
    return 1;
}

static int InputHandler_get_escape_msg(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->escape_msg ? 1 : 0);
    return 1;
}

static int InputHandler_get_zoomin(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->zoomin ? 1 : 0);
    return 1;
}

static int InputHandler_get_zoomout(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->zoomout ? 1 : 0);
    return 1;
}

static int InputHandler_get_buildTiltInc(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->buildTiltInc ? 1 : 0);
    return 1;
}

static int InputHandler_get_buildTiltDec(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->buildTiltDec ? 1 : 0);
    return 1;
}

static int InputHandler_get_rotate(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->rotate ? 1 : 0);
    return 1;
}

static int InputHandler_get_rotRight(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->rotRight ? 1 : 0);
    return 1;
}

static int InputHandler_get_rotLeft(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->rotLeft ? 1 : 0);
    return 1;
}

static int InputHandler_get_tiltDown(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->tiltDown ? 1 : 0);
    return 1;
}

static int InputHandler_get_tiltUp(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->tiltUp ? 1 : 0);
    return 1;
}

static int InputHandler_get_highlight(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->highlight ? 1 : 0);
    return 1;
}

static int InputHandler_get_mLeft(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->mLeft ? 1 : 0);
    return 1;
}

static int InputHandler_get_mRight(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->mRight ? 1 : 0);
    return 1;
}

static int InputHandler_get_lastMLeft(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->lastMLeft ? 1 : 0);
    return 1;
}

static int InputHandler_get_lastMRight(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->lastMRight ? 1 : 0);
    return 1;
}

static int InputHandler_get_mLDown(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->mLDown ? 1 : 0);
    return 1;
}

static int InputHandler_get_mRDown(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->mRDown ? 1 : 0);
    return 1;
}

static int InputHandler_get_mLUp(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->mLUp ? 1 : 0);
    return 1;
}

static int InputHandler_get_mRUp(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->mRUp ? 1 : 0);
    return 1;
}

static int InputHandler_get_swapMouseButtons(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, instance->swapMouseButtons ? 1 : 0);
    return 1;
}

static int InputHandler_get_mPos(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    pushVector2(L, instance->mPos);
    return 1;
}

static int InputHandler_get_mPosAbs(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    pushVector2(L, instance->mPosAbs);
    return 1;
}

static int InputHandler_get_mSpeed(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    pushVector3(L, instance->mSpeed);
    return 1;
}

static int InputHandler_get_mWheel(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    lua_pushinteger(L, instance->mWheel);
    return 1;
}

// --- Setters for InputHandler ---
static int InputHandler_set_controlEnabled(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->controlEnabled = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_gameMode(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->gameMode = (InputHandler::GameMode)luaL_checkinteger(L, 2);
    return 0;
}

static int InputHandler_set_ctrl(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->ctrl = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_shift(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->shift = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_alt(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->alt = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_up(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->up = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_down(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->down = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_left(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->left = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_right(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->right = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_space(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->space = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_pgup(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->pgup = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_pgdn(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->pgdn = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_comma(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->comma = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_period(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->period = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_f1(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->f1 = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_f2(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->f2 = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_escape(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->escape = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_del(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->del = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_escape_msg(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->escape_msg = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_zoomin(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->zoomin = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_zoomout(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->zoomout = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_buildTiltInc(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->buildTiltInc = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_buildTiltDec(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->buildTiltDec = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_rotate(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->rotate = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_rotRight(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->rotRight = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_rotLeft(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->rotLeft = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_tiltDown(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->tiltDown = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_tiltUp(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->tiltUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_highlight(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->highlight = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_mLeft(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->mLeft = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_mRight(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->mRight = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_lastMLeft(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->lastMLeft = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_lastMRight(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->lastMRight = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_mLDown(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->mLDown = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_mRDown(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->mRDown = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_mLUp(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->mLUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_mRUp(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->mRUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_swapMouseButtons(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->swapMouseButtons = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_mPos(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    readVector2(L, 2, instance->mPos);
    return 0;
}

static int InputHandler_set_mPosAbs(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    readVector2(L, 2, instance->mPosAbs);
    return 0;
}

static int InputHandler_set_mSpeed(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    readVector3(L, 2, instance->mSpeed);
    return 0;
}

static int InputHandler_set_mWheel(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    instance->mWheel = (int)luaL_checkinteger(L, 2);
    return 0;
}

int InputHandlerBinding::getKeyUTF8(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    int key = (int)luaL_checkinteger(L, 2);
    std::string result = instance->getKeyUTF8(key);
    lua_pushstring(L, result.c_str());
    return 1;
}

int InputHandlerBinding::parseKey(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    const std::string s = luaL_checkstring(L, 2);
    int result = instance->parseKey(s);
    lua_pushinteger(L, result);
    return 1;
}

int InputHandlerBinding::getCommand(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    const std::string s = luaL_checkstring(L, 2);
    InputHandler::Command* result = instance->getCommand(s);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int InputHandlerBinding::keyDownEvent(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    OIS::KeyCode key = (OIS::KeyCode)luaL_checkinteger(L, 2);
    instance->keyDownEvent(key);
    return 0;
}

int InputHandlerBinding::keyUpEvent(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    OIS::KeyCode key = (OIS::KeyCode)luaL_checkinteger(L, 2);
    instance->keyUpEvent(key);
    return 0;
}

int InputHandlerBinding::clearMessages(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    instance->clearMessages();
    return 0;
}

int InputHandlerBinding::_CONSTRUCTOR(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    InputHandler* result = instance->_CONSTRUCTOR();
    return pushObject<InputHandler>(L, result, InputHandlerBinding::getMetatableName());
}

int InputHandlerBinding::initialise(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    instance->initialise();
    return 0;
}

int InputHandlerBinding::bind(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    const std::string name = luaL_checkstring(L, 2);
    int key = (int)luaL_checkinteger(L, 3);
    instance->bind(name, key);
    return 0;
}

int InputHandlerBinding::unbindAll(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    instance->unbindAll();
    return 0;
}

int InputHandlerBinding::isKeyState(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    const std::string command = luaL_checkstring(L, 2);
    bool result = instance->isKeyState(command);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InputHandlerBinding::getMode(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    const std::string command = luaL_checkstring(L, 2);
    InputHandler::GameMode result = instance->getMode(command);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int InputHandlerBinding::sendEvent(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    const std::string name = luaL_checkstring(L, 2);
    instance->sendEvent(name);
    return 0;
}

int InputHandlerBinding::loadConfig(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    instance->loadConfig();
    return 0;
}

int InputHandlerBinding::saveConfig(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    instance->saveConfig();
    return 0;
}

int InputHandlerBinding::keyString(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    int key = (int)luaL_checkinteger(L, 2);
    bool translated = lua_toboolean(L, 3) != 0;
    std::string result = instance->keyString(key, translated);
    lua_pushstring(L, result.c_str());
    return 1;
}

int InputHandlerBinding::_DESTRUCTOR(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 66: void addCommand(...) - overloaded method
  line 67: void addCommand(...) - overloaded method
  line 68: void addKey(...) - non-string reference arg
  line 70: void unbind(...) - overloaded method
  line 71: void unbind(...) - overloaded method
  line 73: bool isBound(...) - overloaded method
  line 74: bool isBound(...) - overloaded method
  line 81: lektor<int> getBoundKeys(...) - unsupported return type
  line 82: const std::string& getBoundCommand(...) - reference return type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - InputHandler_get_keyboard: OIS::Keyboard* (unbound pointer)
  - InputHandlerBinding::getCommand: InputHandler::Command* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 50: commands (std::map<std::string, InputHandler::Command, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, InputHandler::Command>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 51: map (std::map<int, InputHandler::Command*, std::less<int>, Ogre::STLAllocator<std::pair<int const, InputHandler::Command*>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 52: editMap (std::map<int, InputHandler::Command*, std::less<int>, Ogre::STLAllocator<std::pair<int const, InputHandler::Command*>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 53: events (std::set<InputHandler::Command*, std::less<InputHandler::Command*>, Ogre::STLAllocator<InputHandler::Command*, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 55: keyNameMap (std::map<std::string, int, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > >) - unsupported type
*/

int InputHandlerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int InputHandlerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.InputHandler object");
    return 1;
}



static int InputHandler_get_commands(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    // TODO: Unsupported type for commands (std::map<std::string, InputHandler::Command, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, InputHandler::Command>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'commands' (type: std::map<std::string, InputHandler::Command, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, InputHandler::Command>, Ogre::GeneralAllocPolicy > >)");
}


static int InputHandler_get_editMap(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    // TODO: Unsupported type for editMap (std::map<int, InputHandler::Command*, std::less<int>, Ogre::STLAllocator<std::pair<int const, InputHandler::Command*>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'editMap' (type: std::map<int, InputHandler::Command*, std::less<int>, Ogre::STLAllocator<std::pair<int const, InputHandler::Command*>, Ogre::GeneralAllocPolicy > >)");
}


static int InputHandler_get_events(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    // TODO: Unsupported type for events (std::set<InputHandler::Command*, std::less<InputHandler::Command*>, Ogre::STLAllocator<InputHandler::Command*, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'events' (type: std::set<InputHandler::Command*, std::less<InputHandler::Command*>, Ogre::STLAllocator<InputHandler::Command*, Ogre::GeneralAllocPolicy > >)");
}


static int InputHandler_get_keyNameMap(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    // TODO: Unsupported type for keyNameMap (std::map<std::string, int, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'keyNameMap' (type: std::map<std::string, int, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > >)");
}


static int InputHandler_get_map(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    // TODO: Unsupported type for map (std::map<int, InputHandler::Command*, std::less<int>, Ogre::STLAllocator<std::pair<int const, InputHandler::Command*>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'map' (type: std::map<int, InputHandler::Command*, std::less<int>, Ogre::STLAllocator<std::pair<int const, InputHandler::Command*>, Ogre::GeneralAllocPolicy > >)");
}


static int InputHandler_set_commands(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    return luaL_error(L, "Read-only or unsupported setter type for commands");
}


static int InputHandler_set_editMap(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    return luaL_error(L, "Read-only or unsupported setter type for editMap");
}


static int InputHandler_set_events(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    return luaL_error(L, "Read-only or unsupported setter type for events");
}


static int InputHandler_set_keyNameMap(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    return luaL_error(L, "Read-only or unsupported setter type for keyNameMap");
}


static int InputHandler_set_keyboard(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    return luaL_error(L, "Read-only or unsupported setter type for keyboard");
}


static int InputHandler_set_map(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    return luaL_error(L, "Read-only or unsupported setter type for map");
}


int InputHandlerBinding::addCommand(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    std::string name = luaL_checkstring(L, 2);
    int value = (int)luaL_checkinteger(L, 3);
    int key = (int)luaL_checkinteger(L, 4);
    int alt = (int)luaL_checkinteger(L, 5);
    InputHandler::Masks masks = (InputHandler::Masks)luaL_checkinteger(L, 6);
    InputHandler::GameMode mode = (InputHandler::GameMode)luaL_checkinteger(L, 7);
    instance->addCommand(name, value, key, alt, masks, mode);
    return 0;
}


int InputHandlerBinding::getBoundKeys(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    std::string command = luaL_checkstring(L, 2);
    lektor<int> keys = instance->getBoundKeys(command);
    lua_newtable(L);
    for (unsigned int i = 0; i < keys.size(); ++i)
    {
        lua_pushinteger(L, keys[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}


int InputHandlerBinding::isBound(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    bool res;
    if (lua_isnumber(L, 2))
    {
        int key = (int)luaL_checkinteger(L, 2);
        res = instance->isBound(key);
    }
    else
    {
        std::string cmd = luaL_checkstring(L, 2);
        res = instance->isBound(cmd);
    }
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


int InputHandlerBinding::unbind(lua_State* L)
{
    InputHandler* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InputHandler is nil");
    if (lua_isnumber(L, 2))
    {
        int code = (int)luaL_checkinteger(L, 2);
        InputHandler::GameMode mode = (InputHandler::GameMode)luaL_checkinteger(L, 3);
        instance->unbind(code, mode);
    }
    else
    {
        std::string cmd = luaL_checkstring(L, 2);
        instance->unbind(cmd);
    }
    return 0;
}


void InputHandlerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       InputHandlerBinding::gc },
        { "__tostring", InputHandlerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getKeyUTF8", InputHandlerBinding::getKeyUTF8 },
        { "parseKey", InputHandlerBinding::parseKey },
        { "getCommand", InputHandlerBinding::getCommand },
        { "keyDownEvent", InputHandlerBinding::keyDownEvent },
        { "keyUpEvent", InputHandlerBinding::keyUpEvent },
        { "clearMessages", InputHandlerBinding::clearMessages },
        { "_CONSTRUCTOR", InputHandlerBinding::_CONSTRUCTOR },
        { "initialise", InputHandlerBinding::initialise },
        { "bind", InputHandlerBinding::bind },
        { "unbindAll", InputHandlerBinding::unbindAll },
        { "isKeyState", InputHandlerBinding::isKeyState },
        { "getMode", InputHandlerBinding::getMode },
        { "sendEvent", InputHandlerBinding::sendEvent },
        { "loadConfig", InputHandlerBinding::loadConfig },
        { "saveConfig", InputHandlerBinding::saveConfig },
        { "keyString", InputHandlerBinding::keyString },
        { "_DESTRUCTOR", InputHandlerBinding::_DESTRUCTOR },
                { "addCommand", InputHandlerBinding::addCommand },
        { "unbind", InputHandlerBinding::unbind },
        { "isBound", InputHandlerBinding::isBound },
        { "getBoundKeys", InputHandlerBinding::getBoundKeys },
        { 0, 0 }
    };

    registerClass(
        L, 
        InputHandlerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, InputHandlerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "keyboard", InputHandler_get_keyboard);
    registerGetter(L, "controlEnabled", InputHandler_get_controlEnabled);
    registerGetter(L, "gameMode", InputHandler_get_gameMode);
    registerGetter(L, "ctrl", InputHandler_get_ctrl);
    registerGetter(L, "shift", InputHandler_get_shift);
    registerGetter(L, "alt", InputHandler_get_alt);
    registerGetter(L, "up", InputHandler_get_up);
    registerGetter(L, "down", InputHandler_get_down);
    registerGetter(L, "left", InputHandler_get_left);
    registerGetter(L, "right", InputHandler_get_right);
    registerGetter(L, "space", InputHandler_get_space);
    registerGetter(L, "pgup", InputHandler_get_pgup);
    registerGetter(L, "pgdn", InputHandler_get_pgdn);
    registerGetter(L, "comma", InputHandler_get_comma);
    registerGetter(L, "period", InputHandler_get_period);
    registerGetter(L, "f1", InputHandler_get_f1);
    registerGetter(L, "f2", InputHandler_get_f2);
    registerGetter(L, "escape", InputHandler_get_escape);
    registerGetter(L, "del", InputHandler_get_del);
    registerGetter(L, "escape_msg", InputHandler_get_escape_msg);
    registerGetter(L, "zoomin", InputHandler_get_zoomin);
    registerGetter(L, "zoomout", InputHandler_get_zoomout);
    registerGetter(L, "buildTiltInc", InputHandler_get_buildTiltInc);
    registerGetter(L, "buildTiltDec", InputHandler_get_buildTiltDec);
    registerGetter(L, "rotate", InputHandler_get_rotate);
    registerGetter(L, "rotRight", InputHandler_get_rotRight);
    registerGetter(L, "rotLeft", InputHandler_get_rotLeft);
    registerGetter(L, "tiltDown", InputHandler_get_tiltDown);
    registerGetter(L, "tiltUp", InputHandler_get_tiltUp);
    registerGetter(L, "highlight", InputHandler_get_highlight);
    registerGetter(L, "mLeft", InputHandler_get_mLeft);
    registerGetter(L, "mRight", InputHandler_get_mRight);
    registerGetter(L, "lastMLeft", InputHandler_get_lastMLeft);
    registerGetter(L, "lastMRight", InputHandler_get_lastMRight);
    registerGetter(L, "mLDown", InputHandler_get_mLDown);
    registerGetter(L, "mRDown", InputHandler_get_mRDown);
    registerGetter(L, "mLUp", InputHandler_get_mLUp);
    registerGetter(L, "mRUp", InputHandler_get_mRUp);
    registerGetter(L, "swapMouseButtons", InputHandler_get_swapMouseButtons);
    registerGetter(L, "mPos", InputHandler_get_mPos);
    registerGetter(L, "mPosAbs", InputHandler_get_mPosAbs);
    registerGetter(L, "mSpeed", InputHandler_get_mSpeed);
    registerGetter(L, "mWheel", InputHandler_get_mWheel);
    registerGetter(L, "commands", InputHandler_get_commands);
    registerGetter(L, "editMap", InputHandler_get_editMap);
    registerGetter(L, "events", InputHandler_get_events);
    registerGetter(L, "keyNameMap", InputHandler_get_keyNameMap);
    registerGetter(L, "map", InputHandler_get_map);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "controlEnabled", InputHandler_set_controlEnabled);
    registerSetter(L, "gameMode", InputHandler_set_gameMode);
    registerSetter(L, "ctrl", InputHandler_set_ctrl);
    registerSetter(L, "shift", InputHandler_set_shift);
    registerSetter(L, "alt", InputHandler_set_alt);
    registerSetter(L, "up", InputHandler_set_up);
    registerSetter(L, "down", InputHandler_set_down);
    registerSetter(L, "left", InputHandler_set_left);
    registerSetter(L, "right", InputHandler_set_right);
    registerSetter(L, "space", InputHandler_set_space);
    registerSetter(L, "pgup", InputHandler_set_pgup);
    registerSetter(L, "pgdn", InputHandler_set_pgdn);
    registerSetter(L, "comma", InputHandler_set_comma);
    registerSetter(L, "period", InputHandler_set_period);
    registerSetter(L, "f1", InputHandler_set_f1);
    registerSetter(L, "f2", InputHandler_set_f2);
    registerSetter(L, "escape", InputHandler_set_escape);
    registerSetter(L, "del", InputHandler_set_del);
    registerSetter(L, "escape_msg", InputHandler_set_escape_msg);
    registerSetter(L, "zoomin", InputHandler_set_zoomin);
    registerSetter(L, "zoomout", InputHandler_set_zoomout);
    registerSetter(L, "buildTiltInc", InputHandler_set_buildTiltInc);
    registerSetter(L, "buildTiltDec", InputHandler_set_buildTiltDec);
    registerSetter(L, "rotate", InputHandler_set_rotate);
    registerSetter(L, "rotRight", InputHandler_set_rotRight);
    registerSetter(L, "rotLeft", InputHandler_set_rotLeft);
    registerSetter(L, "tiltDown", InputHandler_set_tiltDown);
    registerSetter(L, "tiltUp", InputHandler_set_tiltUp);
    registerSetter(L, "highlight", InputHandler_set_highlight);
    registerSetter(L, "mLeft", InputHandler_set_mLeft);
    registerSetter(L, "mRight", InputHandler_set_mRight);
    registerSetter(L, "lastMLeft", InputHandler_set_lastMLeft);
    registerSetter(L, "lastMRight", InputHandler_set_lastMRight);
    registerSetter(L, "mLDown", InputHandler_set_mLDown);
    registerSetter(L, "mRDown", InputHandler_set_mRDown);
    registerSetter(L, "mLUp", InputHandler_set_mLUp);
    registerSetter(L, "mRUp", InputHandler_set_mRUp);
    registerSetter(L, "swapMouseButtons", InputHandler_set_swapMouseButtons);
    registerSetter(L, "mPos", InputHandler_set_mPos);
    registerSetter(L, "mPosAbs", InputHandler_set_mPosAbs);
    registerSetter(L, "mSpeed", InputHandler_set_mSpeed);
    registerSetter(L, "mWheel", InputHandler_set_mWheel);
    registerSetter(L, "commands", InputHandler_set_commands);
    registerSetter(L, "editMap", InputHandler_set_editMap);
    registerSetter(L, "events", InputHandler_set_events);
    registerSetter(L, "keyNameMap", InputHandler_set_keyNameMap);
    registerSetter(L, "keyboard", InputHandler_set_keyboard);
    registerSetter(L, "map", InputHandler_set_map);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, InputHandlerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua