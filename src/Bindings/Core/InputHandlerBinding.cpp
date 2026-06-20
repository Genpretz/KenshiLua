#include "pch.h"
#include "Bindings/Core/InputHandlerBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/InputHandler.h>

namespace KenshiLua
{

static InputHandler* getI(lua_State* L, int idx)
{
    return checkObject<InputHandler>(L, idx, InputHandlerBinding::getMetatableName());
}

int InputHandlerBinding::gc(lua_State* L)       { return noopGc(L); }

int InputHandlerBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    // 1. Check the metatable first so obj:method() syntax continues to work.
    luaL_getmetatable(L, InputHandlerBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;   // found a method - return it
    lua_pop(L, 2);  // pop nil result + metatable

    // 2. Fall through to raw member variable access.
    InputHandler* ih = getI(L, 1);
    if (!ih) { lua_pushnil(L); return 1; }

    // --- boolean members ---
    if (strcmp(key, "ctrl") == 0) { lua_pushboolean(L, ih->ctrl ? 1 : 0); return 1; }
    if (strcmp(key, "shift") == 0) { lua_pushboolean(L, ih->shift ? 1 : 0); return 1; }
    if (strcmp(key, "alt") == 0) { lua_pushboolean(L, ih->alt ? 1 : 0); return 1; }
    if (strcmp(key, "up") == 0) { lua_pushboolean(L, ih->up ? 1 : 0); return 1; }
    if (strcmp(key, "down") == 0) { lua_pushboolean(L, ih->down ? 1 : 0); return 1; }
    if (strcmp(key, "left") == 0) { lua_pushboolean(L, ih->left ? 1 : 0); return 1; }
    if (strcmp(key, "right") == 0) { lua_pushboolean(L, ih->right ? 1 : 0); return 1; }
    if (strcmp(key, "space") == 0) { lua_pushboolean(L, ih->space ? 1 : 0); return 1; }
    if (strcmp(key, "pgup") == 0) { lua_pushboolean(L, ih->pgup ? 1 : 0); return 1; }
    if (strcmp(key, "pgdn") == 0) { lua_pushboolean(L, ih->pgdn ? 1 : 0); return 1; }
    if (strcmp(key, "comma") == 0) { lua_pushboolean(L, ih->comma ? 1 : 0); return 1; }
    if (strcmp(key, "period") == 0) { lua_pushboolean(L, ih->period ? 1 : 0); return 1; }
    if (strcmp(key, "f1") == 0) { lua_pushboolean(L, ih->f1 ? 1 : 0); return 1; }
    if (strcmp(key, "f2") == 0) { lua_pushboolean(L, ih->f2 ? 1 : 0); return 1; }
    if (strcmp(key, "escape") == 0) { lua_pushboolean(L, ih->escape ? 1 : 0); return 1; }
    if (strcmp(key, "del") == 0) { lua_pushboolean(L, ih->del ? 1 : 0); return 1; }
    if (strcmp(key, "zoomin") == 0) { lua_pushboolean(L, ih->zoomin ? 1 : 0); return 1; }
    if (strcmp(key, "zoomout") == 0) { lua_pushboolean(L, ih->zoomout ? 1 : 0); return 1; }
    if (strcmp(key, "rotate") == 0) { lua_pushboolean(L, ih->rotate ? 1 : 0); return 1; }
    if (strcmp(key, "highlight") == 0) { lua_pushboolean(L, ih->highlight ? 1 : 0); return 1; }
    if (strcmp(key, "mLeft") == 0) { lua_pushboolean(L, ih->mLeft ? 1 : 0); return 1; }
    if (strcmp(key, "mRight") == 0) { lua_pushboolean(L, ih->mRight ? 1 : 0); return 1; }
    if (strcmp(key, "mLDown") == 0) { lua_pushboolean(L, ih->mLDown ? 1 : 0); return 1; }
    if (strcmp(key, "mRDown") == 0) { lua_pushboolean(L, ih->mRDown ? 1 : 0); return 1; }
    if (strcmp(key, "mLUp") == 0) { lua_pushboolean(L, ih->mLUp ? 1 : 0); return 1; }
    if (strcmp(key, "mRUp") == 0) { lua_pushboolean(L, ih->mRUp ? 1 : 0); return 1; }

    // --- integer members ---
    if (strcmp(key, "mWheel") == 0) { lua_pushinteger(L, ih->mWheel); return 1; }

    // --- special/object members ---
    if (strcmp(key, "mPos") == 0) {
        lua_createtable(L, 0, 2);
        lua_pushnumber(L, ih->mPos.x); lua_setfield(L, -2, "x");
        lua_pushnumber(L, ih->mPos.y); lua_setfield(L, -2, "y");
        return 1;
    }
    if (strcmp(key, "mPosAbs") == 0) {
        lua_createtable(L, 0, 2);
        lua_pushnumber(L, ih->mPosAbs.x); lua_setfield(L, -2, "x");
        lua_pushnumber(L, ih->mPosAbs.y); lua_setfield(L, -2, "y");
        return 1;
    }

    lua_pushnil(L);
    return 1;
}

int InputHandlerBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    InputHandler* ih = getI(L, 1);
    if (!ih) return luaL_error(L, "InputHandler is nil");

    // --- writable properties ---
    if (strcmp(key, "ctrl") == 0) { ih->ctrl = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "shift") == 0) { ih->shift = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "alt") == 0) { ih->alt = (lua_toboolean(L, 3) != 0); return 0; }

    return luaL_error(L, "InputHandler: field '%s' is read-only or does not exist", key);
}
int InputHandlerBinding::tostring(lua_State* L) { return genericTostringPtr(L, "InputHandler", (void*)getI(L, 1)); }

int InputHandlerBinding::isKeyState(lua_State* L)
{
    InputHandler* ih = getI(L, 1);
    const char* cmd = luaL_checkstring(L, 2);
    if (ih) lua_pushboolean(L, ih->isKeyState(cmd) ? 1 : 0);
    else    lua_pushboolean(L, 0);
    return 1;
}

int InputHandlerBinding::isBound(lua_State* L)
{
    InputHandler* ih = getI(L, 1);
    if (!ih) { lua_pushboolean(L, 0); return 1; }
    if (lua_isnumber(L, 2)) {
        lua_pushboolean(L, ih->isBound((int)lua_tointeger(L, 2)) ? 1 : 0);
    } else {
        lua_pushboolean(L, ih->isBound(std::string(luaL_checkstring(L, 2))) ? 1 : 0);
    }
    return 1;
}

int InputHandlerBinding::sendEvent(lua_State* L)
{
    InputHandler* ih = getI(L, 1);
    if (!ih) return luaL_error(L, "InputHandler is nil");
    ih->sendEvent(luaL_checkstring(L, 2));
    return 0;
}

int InputHandlerBinding::bind(lua_State* L)
{
    InputHandler* ih = getI(L, 1);
    if (!ih) return luaL_error(L, "InputHandler is nil");
    const char* name = luaL_checkstring(L, 2);
    int key = (int)luaL_checkinteger(L, 3);
    ih->bind(name, key);
    return 0;
}

int InputHandlerBinding::unbind(lua_State* L)
{
    InputHandler* ih = getI(L, 1);
    if (!ih) return luaL_error(L, "InputHandler is nil");
    if (lua_isnumber(L, 2)) {
        int mode = (int)luaL_optinteger(L, 3, 0);
        ih->unbind((int)lua_tointeger(L, 2), (InputHandler::GameMode)mode);
    } else {
        ih->unbind(std::string(luaL_checkstring(L, 2)));
    }
    return 0;
}

int InputHandlerBinding::unbindAll(lua_State* L)
{
    InputHandler* ih = getI(L, 1);
    if (ih) ih->unbindAll();
    return 0;
}

int InputHandlerBinding::getMousePos(lua_State* L)
{
    InputHandler* ih = getI(L, 1);
    if (!ih) { lua_pushnil(L); return 1; }
    lua_createtable(L, 0, 2);
    lua_pushnumber(L, ih->mPos.x); lua_setfield(L, -2, "x");
    lua_pushnumber(L, ih->mPos.y); lua_setfield(L, -2, "y");
    return 1;
}

int InputHandlerBinding::getMousePosAbs(lua_State* L)
{
    InputHandler* ih = getI(L, 1);
    if (!ih) { lua_pushnil(L); return 1; }
    lua_createtable(L, 0, 2);
    lua_pushnumber(L, ih->mPosAbs.x); lua_setfield(L, -2, "x");
    lua_pushnumber(L, ih->mPosAbs.y); lua_setfield(L, -2, "y");
    return 1;
}

int InputHandlerBinding::getMouseWheel(lua_State* L)
{
    InputHandler* ih = getI(L, 1);
    if (ih) lua_pushinteger(L, ih->mWheel);
    else    lua_pushinteger(L, 0);
    return 1;
}

int InputHandlerBinding::getModifiers(lua_State* L)
{
    InputHandler* ih = getI(L, 1);
    if (!ih) { lua_pushnil(L); return 1; }
    lua_createtable(L, 0, 3);
    lua_pushboolean(L, ih->ctrl  ? 1 : 0); lua_setfield(L, -2, "ctrl");
    lua_pushboolean(L, ih->shift ? 1 : 0); lua_setfield(L, -2, "shift");
    lua_pushboolean(L, ih->alt   ? 1 : 0); lua_setfield(L, -2, "alt");
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
        { "isKeyState",     InputHandlerBinding::isKeyState },
        { "isBound",        InputHandlerBinding::isBound },
        { "sendEvent",      InputHandlerBinding::sendEvent },
        { "bind",           InputHandlerBinding::bind },
        { "unbind",         InputHandlerBinding::unbind },
        { "unbindAll",      InputHandlerBinding::unbindAll },
        { "getMousePos",    InputHandlerBinding::getMousePos },
        { "getMousePosAbs", InputHandlerBinding::getMousePosAbs },
        { "getMouseWheel",  InputHandlerBinding::getMouseWheel },
        { "getModifiers",   InputHandlerBinding::getModifiers },
        { 0, 0 }
    };
    registerClass(L, InputHandlerBinding::getMetatableName(), meta, methods, InputHandlerBinding::index, InputHandlerBinding::newindex);
}

} // namespace KenshiLua