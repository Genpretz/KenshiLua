#include "pch.h"
#include "Bindings/InputHandler_CommandBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static InputHandler::Command* getInstance(lua_State* L, int idx)
{
    return checkObject<InputHandler::Command>(L, idx, InputHandler_CommandBinding::getMetatableName());
}

// --- Getters for Command ---
static int Command_get_gameMode(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    lua_pushinteger(L, (lua_Integer)inst->gameMode);
    return 1;
}

static int Command_get_isKey(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    lua_pushboolean(L, inst->isKey ? 1 : 0);
    return 1;
}

static int Command_get_code(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    lua_pushinteger(L, inst->code);
    return 1;
}

static int Command_get_boolean(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    if (inst->boolean) {

        lua_pushlightuserdata(L, (void*)inst->boolean);

    } else {

        lua_pushnil(L);

    }

    return 1;
}

static int Command_get_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    lua_pushstring(L, inst->name.c_str());

    return 1;
}

static int Command_get_bound(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    lua_pushinteger(L, inst->bound);
    return 1;
}

static int Command_get_masks(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    lua_pushinteger(L, (lua_Integer)inst->masks);
    return 1;
}

// --- Setters for Command ---
static int Command_set_gameMode(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    inst->gameMode = (InputHandler::GameMode)luaL_checkinteger(L, 2);
    return 0;
}

static int Command_set_isKey(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    inst->isKey = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Command_set_code(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    inst->code = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Command_set_boolean(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    inst->boolean = (bool*)lua_touserdata(L, 2);
    return 0;
}

static int Command_set_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    inst->name = luaL_checkstring(L, 2);
    return 0;
}

static int Command_set_bound(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    inst->bound = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Command_set_masks(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    inst->masks = (InputHandler::Masks)luaL_checkinteger(L, 2);
    return 0;
}

int InputHandler_CommandBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (InputHandler::Command*)::operator new(sizeof(InputHandler::Command));
    ::new ((void*)obj) InputHandler::Command();
    if (lua_gettop(L) >= 2)
        obj->isKey = lua_toboolean(L, 2) != 0;
    if (lua_gettop(L) >= 3)
        obj->code = (int)luaL_checkinteger(L, 3);
    if (lua_gettop(L) >= 6)
        obj->bound = (int)luaL_checkinteger(L, 6);
    return pushObject<InputHandler::Command>(L, obj, getMetatableName());
}

int InputHandler_CommandBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InputHandler::Command is nil");
    inst->~Command();
    return 0;
}

int InputHandler_CommandBinding::gc(lua_State* L)
{
    return 0;
}

int InputHandler_CommandBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.InputHandler_Command object");
    return 1;
}

int InputHandler_CommandBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->gameMode == b->gameMode && a->isKey == b->isKey && a->code == b->code && a->boolean == b->boolean && a->name == b->name && a->bound == b->bound && a->masks == b->masks)) ? 1 : 0);
    return 1;
}

void InputHandler_CommandBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", _CONSTRUCTOR },
        { "_DESTRUCTOR",  _DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "gameMode", Command_get_gameMode);
    registerGetter(L, "isKey", Command_get_isKey);
    registerGetter(L, "code", Command_get_code);
    registerGetter(L, "boolean", Command_get_boolean);
    registerGetter(L, "name", Command_get_name);
    registerGetter(L, "bound", Command_get_bound);
    registerGetter(L, "masks", Command_get_masks);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "gameMode", Command_set_gameMode);
    registerSetter(L, "isKey", Command_set_isKey);
    registerSetter(L, "code", Command_set_code);
    registerSetter(L, "boolean", Command_set_boolean);
    registerSetter(L, "name", Command_set_name);
    registerSetter(L, "bound", Command_set_bound);
    registerSetter(L, "masks", Command_set_masks);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
