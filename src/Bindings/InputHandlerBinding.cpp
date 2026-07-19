#include "pch.h"
#include "kenshi\InputHandler.h"
#include "InputHandlerBinding.h"
#include "Lua/BindingHelpers.h"

typedef InputHandler::GameMode GameMode;

namespace KenshiLua
{

static InputHandler* getB(lua_State* L, int idx)
{
    return checkObject<InputHandler>(L, idx, InputHandlerBinding::getMetatableName());
}

// --- Getters for InputHandler ---
static int InputHandler_get_commands(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    // TODO: Unsupported type for commands (std::map<std::string, Command, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, Command>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'commands' (type: std::map<std::string, Command, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, Command>, Ogre::GeneralAllocPolicy > >)");
}

static int InputHandler_get_map(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    // TODO: Unsupported type for map (std::map<int, Command*, std::less<int>, Ogre::STLAllocator<std::pair<int const, Command*>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'map' (type: std::map<int, Command*, std::less<int>, Ogre::STLAllocator<std::pair<int const, Command*>, Ogre::GeneralAllocPolicy > >)");
}

static int InputHandler_get_editMap(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    // TODO: Unsupported type for editMap (std::map<int, Command*, std::less<int>, Ogre::STLAllocator<std::pair<int const, Command*>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'editMap' (type: std::map<int, Command*, std::less<int>, Ogre::STLAllocator<std::pair<int const, Command*>, Ogre::GeneralAllocPolicy > >)");
}

static int InputHandler_get_events(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    // TODO: Unsupported type for events (std::set<Command*, std::less<Command*>, Ogre::STLAllocator<Command*, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'events' (type: std::set<Command*, std::less<Command*>, Ogre::STLAllocator<Command*, Ogre::GeneralAllocPolicy > >)");
}

static int InputHandler_get_keyboard(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushinteger(L, (lua_Integer)b->keyboard);
    return 1;
}

static int InputHandler_get_keyNameMap(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    // TODO: Unsupported type for keyNameMap (std::map<std::string, int, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'keyNameMap' (type: std::map<std::string, int, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > >)");
}

static int InputHandler_get_controlEnabled(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->controlEnabled ? 1 : 0);
    return 1;
}

static int InputHandler_get_gameMode(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushinteger(L, (lua_Integer)b->gameMode);
    return 1;
}

static int InputHandler_get_ctrl(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->ctrl ? 1 : 0);
    return 1;
}

static int InputHandler_get_shift(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->shift ? 1 : 0);
    return 1;
}

static int InputHandler_get_alt(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->alt ? 1 : 0);
    return 1;
}

static int InputHandler_get_up(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->up ? 1 : 0);
    return 1;
}

static int InputHandler_get_down(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->down ? 1 : 0);
    return 1;
}

static int InputHandler_get_left(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->left ? 1 : 0);
    return 1;
}

static int InputHandler_get_right(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->right ? 1 : 0);
    return 1;
}

static int InputHandler_get_space(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->space ? 1 : 0);
    return 1;
}

static int InputHandler_get_pgup(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->pgup ? 1 : 0);
    return 1;
}

static int InputHandler_get_pgdn(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->pgdn ? 1 : 0);
    return 1;
}

static int InputHandler_get_comma(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->comma ? 1 : 0);
    return 1;
}

static int InputHandler_get_period(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->period ? 1 : 0);
    return 1;
}

static int InputHandler_get_f1(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->f1 ? 1 : 0);
    return 1;
}

static int InputHandler_get_f2(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->f2 ? 1 : 0);
    return 1;
}

static int InputHandler_get_escape(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->escape ? 1 : 0);
    return 1;
}

static int InputHandler_get_del(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->del ? 1 : 0);
    return 1;
}

static int InputHandler_get_escape_msg(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->escape_msg ? 1 : 0);
    return 1;
}

static int InputHandler_get_zoomin(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->zoomin ? 1 : 0);
    return 1;
}

static int InputHandler_get_zoomout(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->zoomout ? 1 : 0);
    return 1;
}

static int InputHandler_get_buildTiltInc(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->buildTiltInc ? 1 : 0);
    return 1;
}

static int InputHandler_get_buildTiltDec(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->buildTiltDec ? 1 : 0);
    return 1;
}

static int InputHandler_get_rotate(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->rotate ? 1 : 0);
    return 1;
}

static int InputHandler_get_rotRight(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->rotRight ? 1 : 0);
    return 1;
}

static int InputHandler_get_rotLeft(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->rotLeft ? 1 : 0);
    return 1;
}

static int InputHandler_get_tiltDown(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->tiltDown ? 1 : 0);
    return 1;
}

static int InputHandler_get_tiltUp(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->tiltUp ? 1 : 0);
    return 1;
}

static int InputHandler_get_highlight(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->highlight ? 1 : 0);
    return 1;
}

static int InputHandler_get_mLeft(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->mLeft ? 1 : 0);
    return 1;
}

static int InputHandler_get_mRight(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->mRight ? 1 : 0);
    return 1;
}

static int InputHandler_get_lastMLeft(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->lastMLeft ? 1 : 0);
    return 1;
}

static int InputHandler_get_lastMRight(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->lastMRight ? 1 : 0);
    return 1;
}

static int InputHandler_get_mLDown(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->mLDown ? 1 : 0);
    return 1;
}

static int InputHandler_get_mRDown(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->mRDown ? 1 : 0);
    return 1;
}

static int InputHandler_get_mLUp(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->mLUp ? 1 : 0);
    return 1;
}

static int InputHandler_get_mRUp(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->mRUp ? 1 : 0);
    return 1;
}

static int InputHandler_get_swapMouseButtons(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushboolean(L, b->swapMouseButtons ? 1 : 0);
    return 1;
}

static int InputHandler_get_mPos(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_newtable(L);
    lua_pushnumber(L, b->mPos.x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, b->mPos.y);
    lua_setfield(L, -2, "y");
    return 1;
}

static int InputHandler_get_mPosAbs(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_newtable(L);
    lua_pushnumber(L, b->mPosAbs.x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, b->mPosAbs.y);
    lua_setfield(L, -2, "y");
    return 1;
}

static int InputHandler_get_mSpeed(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    pushVector3(L, b->mSpeed);
    return 1;
}

static int InputHandler_get_mWheel(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    lua_pushinteger(L, b->mWheel);
    return 1;
}

// --- Setters for InputHandler ---
static int InputHandler_set_commands(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    return luaL_error(L, "Read-only or unsupported setter type for commands");
}

static int InputHandler_set_map(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    return luaL_error(L, "Read-only or unsupported setter type for map");
}

static int InputHandler_set_editMap(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    return luaL_error(L, "Read-only or unsupported setter type for editMap");
}

static int InputHandler_set_events(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    return luaL_error(L, "Read-only or unsupported setter type for events");
}

static int InputHandler_set_keyboard(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    return luaL_error(L, "Read-only or unsupported setter type for keyboard");
}

static int InputHandler_set_keyNameMap(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    return luaL_error(L, "Read-only or unsupported setter type for keyNameMap");
}

static int InputHandler_set_controlEnabled(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->controlEnabled = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_gameMode(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->gameMode = (GameMode)luaL_checkinteger(L, 2);
    return 0;
}

static int InputHandler_set_ctrl(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->ctrl = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_shift(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->shift = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_alt(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->alt = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_up(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->up = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_down(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->down = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_left(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->left = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_right(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->right = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_space(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->space = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_pgup(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->pgup = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_pgdn(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->pgdn = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_comma(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->comma = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_period(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->period = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_f1(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->f1 = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_f2(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->f2 = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_escape(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->escape = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_del(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->del = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_escape_msg(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->escape_msg = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_zoomin(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->zoomin = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_zoomout(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->zoomout = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_buildTiltInc(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->buildTiltInc = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_buildTiltDec(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->buildTiltDec = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_rotate(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->rotate = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_rotRight(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->rotRight = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_rotLeft(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->rotLeft = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_tiltDown(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->tiltDown = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_tiltUp(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->tiltUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_highlight(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->highlight = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_mLeft(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->mLeft = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_mRight(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->mRight = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_lastMLeft(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->lastMLeft = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_lastMRight(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->lastMRight = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_mLDown(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->mLDown = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_mRDown(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->mRDown = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_mLUp(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->mLUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_mRUp(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->mRUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_swapMouseButtons(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->swapMouseButtons = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InputHandler_set_mPos(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    if (!lua_istable(L, 2)) return luaL_error(L, "Expected table for mPos");
    lua_getfield(L, 2, "x");
    b->mPos.x = (float)luaL_checknumber(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, 2, "y");
    b->mPos.y = (float)luaL_checknumber(L, -1);
    lua_pop(L, 1);
    return 0;
}

static int InputHandler_set_mPosAbs(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    if (!lua_istable(L, 2)) return luaL_error(L, "Expected table for mPosAbs");
    lua_getfield(L, 2, "x");
    b->mPosAbs.x = (float)luaL_checknumber(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, 2, "y");
    b->mPosAbs.y = (float)luaL_checknumber(L, -1);
    lua_pop(L, 1);
    return 0;
}

static int InputHandler_set_mSpeed(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    readVector3(L, 2, b->mSpeed);
    return 0;
}

static int InputHandler_set_mWheel(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    b->mWheel = (int)luaL_checkinteger(L, 2);
    return 0;
}

int InputHandlerBinding::getKeyUTF8(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    int key = (int)luaL_checkinteger(L, 2);
    std::string result = b->getKeyUTF8(key);
    lua_pushstring(L, result.c_str());
    return 1;
}

int InputHandlerBinding::parseKey(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    std::string s = luaL_checkstring(L, 2);
    int result = b->parseKey(s);
    lua_pushinteger(L, result);
    return 1;
}

int InputHandlerBinding::keyDownEvent(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    OIS::KeyCode key = (OIS::KeyCode)luaL_checkinteger(L, 2);
    b->keyDownEvent(key);
    return 0;
}

int InputHandlerBinding::keyUpEvent(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    OIS::KeyCode key = (OIS::KeyCode)luaL_checkinteger(L, 2);
    b->keyUpEvent(key);
    return 0;
}

int InputHandlerBinding::clearMessages(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    b->clearMessages();
    return 0;
}

int InputHandlerBinding::_CONSTRUCTOR(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    InputHandler* result = b->_CONSTRUCTOR();
    return pushObject<InputHandler>(L, result, InputHandlerBinding::getMetatableName());
}

int InputHandlerBinding::initialise(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    b->initialise();
    return 0;
}

int InputHandlerBinding::bind(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    std::string name = luaL_checkstring(L, 2);
    int key = (int)luaL_checkinteger(L, 3);
    b->bind(name, key);
    return 0;
}

int InputHandlerBinding::unbindAll(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    b->unbindAll();
    return 0;
}

int InputHandlerBinding::isKeyState(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    std::string command = luaL_checkstring(L, 2);
    bool result = b->isKeyState(command);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InputHandlerBinding::getMode(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    std::string command = luaL_checkstring(L, 2);
    GameMode result = b->getMode(command);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int InputHandlerBinding::sendEvent(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    std::string name = luaL_checkstring(L, 2);
    b->sendEvent(name);
    return 0;
}

int InputHandlerBinding::loadConfig(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    b->loadConfig();
    return 0;
}

int InputHandlerBinding::saveConfig(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    b->saveConfig();
    return 0;
}

int InputHandlerBinding::keyString(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    int key = (int)luaL_checkinteger(L, 2);
    bool translated = lua_toboolean(L, 3) != 0;
    std::string result = b->keyString(key, translated);
    lua_pushstring(L, result.c_str());
    return 1;
}

int InputHandlerBinding::_DESTRUCTOR(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 68: void addKey(...) - non-string reference arg
  line 82: const std::string& getBoundCommand(...) - reference return type
*/

int InputHandlerBinding::getCommand(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    std::string s = luaL_checkstring(L, 2);
    InputHandler::Command* res = b->getCommand(s);
    lua_pushlightuserdata(L, (void*)res);
    return 1;
}

int InputHandlerBinding::addCommand(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    std::string name = luaL_checkstring(L, 2);
    int value = (int)luaL_checkinteger(L, 3);
    int key = (int)luaL_checkinteger(L, 4);
    int alt = (int)luaL_checkinteger(L, 5);
    InputHandler::Masks masks = (InputHandler::Masks)luaL_checkinteger(L, 6);
    GameMode mode = (GameMode)luaL_checkinteger(L, 7);
    b->addCommand(name, value, key, alt, masks, mode);
    return 0;
}

int InputHandlerBinding::unbind(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    if (lua_isnumber(L, 2))
    {
        int code = (int)luaL_checkinteger(L, 2);
        GameMode mode = (GameMode)luaL_checkinteger(L, 3);
        b->unbind(code, mode);
    }
    else
    {
        std::string cmd = luaL_checkstring(L, 2);
        b->unbind(cmd);
    }
    return 0;
}

int InputHandlerBinding::isBound(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    bool res;
    if (lua_isnumber(L, 2))
    {
        int key = (int)luaL_checkinteger(L, 2);
        res = b->isBound(key);
    }
    else
    {
        std::string cmd = luaL_checkstring(L, 2);
        res = b->isBound(cmd);
    }
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int InputHandlerBinding::getBoundKeys(lua_State* L)
{
    InputHandler* b = getB(L, 1);
    if (!b) return luaL_error(L, "InputHandler is nil");
    std::string command = luaL_checkstring(L, 2);
    lektor<int> keys = b->getBoundKeys(command);
    lua_newtable(L);
    for (unsigned int i = 0; i < keys.size(); ++i)
    {
        lua_pushinteger(L, keys[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

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
        { "getCommand", InputHandlerBinding::getCommand },
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
    lua_pushcfunction(L, InputHandler_get_commands);
    lua_setfield(L, -2, "commands");
    lua_pushcfunction(L, InputHandler_get_map);
    lua_setfield(L, -2, "map");
    lua_pushcfunction(L, InputHandler_get_editMap);
    lua_setfield(L, -2, "editMap");
    lua_pushcfunction(L, InputHandler_get_events);
    lua_setfield(L, -2, "events");
    lua_pushcfunction(L, InputHandler_get_keyboard);
    lua_setfield(L, -2, "keyboard");
    lua_pushcfunction(L, InputHandler_get_keyNameMap);
    lua_setfield(L, -2, "keyNameMap");
    lua_pushcfunction(L, InputHandler_get_controlEnabled);
    lua_setfield(L, -2, "controlEnabled");
    lua_pushcfunction(L, InputHandler_get_gameMode);
    lua_setfield(L, -2, "gameMode");
    lua_pushcfunction(L, InputHandler_get_ctrl);
    lua_setfield(L, -2, "ctrl");
    lua_pushcfunction(L, InputHandler_get_shift);
    lua_setfield(L, -2, "shift");
    lua_pushcfunction(L, InputHandler_get_alt);
    lua_setfield(L, -2, "alt");
    lua_pushcfunction(L, InputHandler_get_up);
    lua_setfield(L, -2, "up");
    lua_pushcfunction(L, InputHandler_get_down);
    lua_setfield(L, -2, "down");
    lua_pushcfunction(L, InputHandler_get_left);
    lua_setfield(L, -2, "left");
    lua_pushcfunction(L, InputHandler_get_right);
    lua_setfield(L, -2, "right");
    lua_pushcfunction(L, InputHandler_get_space);
    lua_setfield(L, -2, "space");
    lua_pushcfunction(L, InputHandler_get_pgup);
    lua_setfield(L, -2, "pgup");
    lua_pushcfunction(L, InputHandler_get_pgdn);
    lua_setfield(L, -2, "pgdn");
    lua_pushcfunction(L, InputHandler_get_comma);
    lua_setfield(L, -2, "comma");
    lua_pushcfunction(L, InputHandler_get_period);
    lua_setfield(L, -2, "period");
    lua_pushcfunction(L, InputHandler_get_f1);
    lua_setfield(L, -2, "f1");
    lua_pushcfunction(L, InputHandler_get_f2);
    lua_setfield(L, -2, "f2");
    lua_pushcfunction(L, InputHandler_get_escape);
    lua_setfield(L, -2, "escape");
    lua_pushcfunction(L, InputHandler_get_del);
    lua_setfield(L, -2, "del");
    lua_pushcfunction(L, InputHandler_get_escape_msg);
    lua_setfield(L, -2, "escape_msg");
    lua_pushcfunction(L, InputHandler_get_zoomin);
    lua_setfield(L, -2, "zoomin");
    lua_pushcfunction(L, InputHandler_get_zoomout);
    lua_setfield(L, -2, "zoomout");
    lua_pushcfunction(L, InputHandler_get_buildTiltInc);
    lua_setfield(L, -2, "buildTiltInc");
    lua_pushcfunction(L, InputHandler_get_buildTiltDec);
    lua_setfield(L, -2, "buildTiltDec");
    lua_pushcfunction(L, InputHandler_get_rotate);
    lua_setfield(L, -2, "rotate");
    lua_pushcfunction(L, InputHandler_get_rotRight);
    lua_setfield(L, -2, "rotRight");
    lua_pushcfunction(L, InputHandler_get_rotLeft);
    lua_setfield(L, -2, "rotLeft");
    lua_pushcfunction(L, InputHandler_get_tiltDown);
    lua_setfield(L, -2, "tiltDown");
    lua_pushcfunction(L, InputHandler_get_tiltUp);
    lua_setfield(L, -2, "tiltUp");
    lua_pushcfunction(L, InputHandler_get_highlight);
    lua_setfield(L, -2, "highlight");
    lua_pushcfunction(L, InputHandler_get_mLeft);
    lua_setfield(L, -2, "mLeft");
    lua_pushcfunction(L, InputHandler_get_mRight);
    lua_setfield(L, -2, "mRight");
    lua_pushcfunction(L, InputHandler_get_lastMLeft);
    lua_setfield(L, -2, "lastMLeft");
    lua_pushcfunction(L, InputHandler_get_lastMRight);
    lua_setfield(L, -2, "lastMRight");
    lua_pushcfunction(L, InputHandler_get_mLDown);
    lua_setfield(L, -2, "mLDown");
    lua_pushcfunction(L, InputHandler_get_mRDown);
    lua_setfield(L, -2, "mRDown");
    lua_pushcfunction(L, InputHandler_get_mLUp);
    lua_setfield(L, -2, "mLUp");
    lua_pushcfunction(L, InputHandler_get_mRUp);
    lua_setfield(L, -2, "mRUp");
    lua_pushcfunction(L, InputHandler_get_swapMouseButtons);
    lua_setfield(L, -2, "swapMouseButtons");
    lua_pushcfunction(L, InputHandler_get_mPos);
    lua_setfield(L, -2, "mPos");
    lua_pushcfunction(L, InputHandler_get_mPosAbs);
    lua_setfield(L, -2, "mPosAbs");
    lua_pushcfunction(L, InputHandler_get_mSpeed);
    lua_setfield(L, -2, "mSpeed");
    lua_pushcfunction(L, InputHandler_get_mWheel);
    lua_setfield(L, -2, "mWheel");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, InputHandler_set_commands);
    lua_setfield(L, -2, "commands");
    lua_pushcfunction(L, InputHandler_set_map);
    lua_setfield(L, -2, "map");
    lua_pushcfunction(L, InputHandler_set_editMap);
    lua_setfield(L, -2, "editMap");
    lua_pushcfunction(L, InputHandler_set_events);
    lua_setfield(L, -2, "events");
    lua_pushcfunction(L, InputHandler_set_keyboard);
    lua_setfield(L, -2, "keyboard");
    lua_pushcfunction(L, InputHandler_set_keyNameMap);
    lua_setfield(L, -2, "keyNameMap");
    lua_pushcfunction(L, InputHandler_set_controlEnabled);
    lua_setfield(L, -2, "controlEnabled");
    lua_pushcfunction(L, InputHandler_set_gameMode);
    lua_setfield(L, -2, "gameMode");
    lua_pushcfunction(L, InputHandler_set_ctrl);
    lua_setfield(L, -2, "ctrl");
    lua_pushcfunction(L, InputHandler_set_shift);
    lua_setfield(L, -2, "shift");
    lua_pushcfunction(L, InputHandler_set_alt);
    lua_setfield(L, -2, "alt");
    lua_pushcfunction(L, InputHandler_set_up);
    lua_setfield(L, -2, "up");
    lua_pushcfunction(L, InputHandler_set_down);
    lua_setfield(L, -2, "down");
    lua_pushcfunction(L, InputHandler_set_left);
    lua_setfield(L, -2, "left");
    lua_pushcfunction(L, InputHandler_set_right);
    lua_setfield(L, -2, "right");
    lua_pushcfunction(L, InputHandler_set_space);
    lua_setfield(L, -2, "space");
    lua_pushcfunction(L, InputHandler_set_pgup);
    lua_setfield(L, -2, "pgup");
    lua_pushcfunction(L, InputHandler_set_pgdn);
    lua_setfield(L, -2, "pgdn");
    lua_pushcfunction(L, InputHandler_set_comma);
    lua_setfield(L, -2, "comma");
    lua_pushcfunction(L, InputHandler_set_period);
    lua_setfield(L, -2, "period");
    lua_pushcfunction(L, InputHandler_set_f1);
    lua_setfield(L, -2, "f1");
    lua_pushcfunction(L, InputHandler_set_f2);
    lua_setfield(L, -2, "f2");
    lua_pushcfunction(L, InputHandler_set_escape);
    lua_setfield(L, -2, "escape");
    lua_pushcfunction(L, InputHandler_set_del);
    lua_setfield(L, -2, "del");
    lua_pushcfunction(L, InputHandler_set_escape_msg);
    lua_setfield(L, -2, "escape_msg");
    lua_pushcfunction(L, InputHandler_set_zoomin);
    lua_setfield(L, -2, "zoomin");
    lua_pushcfunction(L, InputHandler_set_zoomout);
    lua_setfield(L, -2, "zoomout");
    lua_pushcfunction(L, InputHandler_set_buildTiltInc);
    lua_setfield(L, -2, "buildTiltInc");
    lua_pushcfunction(L, InputHandler_set_buildTiltDec);
    lua_setfield(L, -2, "buildTiltDec");
    lua_pushcfunction(L, InputHandler_set_rotate);
    lua_setfield(L, -2, "rotate");
    lua_pushcfunction(L, InputHandler_set_rotRight);
    lua_setfield(L, -2, "rotRight");
    lua_pushcfunction(L, InputHandler_set_rotLeft);
    lua_setfield(L, -2, "rotLeft");
    lua_pushcfunction(L, InputHandler_set_tiltDown);
    lua_setfield(L, -2, "tiltDown");
    lua_pushcfunction(L, InputHandler_set_tiltUp);
    lua_setfield(L, -2, "tiltUp");
    lua_pushcfunction(L, InputHandler_set_highlight);
    lua_setfield(L, -2, "highlight");
    lua_pushcfunction(L, InputHandler_set_mLeft);
    lua_setfield(L, -2, "mLeft");
    lua_pushcfunction(L, InputHandler_set_mRight);
    lua_setfield(L, -2, "mRight");
    lua_pushcfunction(L, InputHandler_set_lastMLeft);
    lua_setfield(L, -2, "lastMLeft");
    lua_pushcfunction(L, InputHandler_set_lastMRight);
    lua_setfield(L, -2, "lastMRight");
    lua_pushcfunction(L, InputHandler_set_mLDown);
    lua_setfield(L, -2, "mLDown");
    lua_pushcfunction(L, InputHandler_set_mRDown);
    lua_setfield(L, -2, "mRDown");
    lua_pushcfunction(L, InputHandler_set_mLUp);
    lua_setfield(L, -2, "mLUp");
    lua_pushcfunction(L, InputHandler_set_mRUp);
    lua_setfield(L, -2, "mRUp");
    lua_pushcfunction(L, InputHandler_set_swapMouseButtons);
    lua_setfield(L, -2, "swapMouseButtons");
    lua_pushcfunction(L, InputHandler_set_mPos);
    lua_setfield(L, -2, "mPos");
    lua_pushcfunction(L, InputHandler_set_mPosAbs);
    lua_setfield(L, -2, "mPosAbs");
    lua_pushcfunction(L, InputHandler_set_mSpeed);
    lua_setfield(L, -2, "mSpeed");
    lua_pushcfunction(L, InputHandler_set_mWheel);
    lua_setfield(L, -2, "mWheel");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
