#include "pch.h"
#include "kenshi\Dialogue.h"
#include "DialogActionBinding.h"
#include "Lua/BindingHelpers.h"

typedef DialogLineData::DialogAction DialogAction;

namespace KenshiLua
{

static DialogAction* getB(lua_State* L, int idx)
{
    return checkObject<DialogAction>(L, idx, DialogActionBinding::getMetatableName());
}

// --- Getters for DialogAction ---
static int DialogAction_get_key(lua_State* L)
{
    DialogAction* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogAction is nil");
    // TODO: Unsupported type for key (DialogActionEnum)
    return luaL_error(L, "Unsupported property 'key' (type: DialogActionEnum)");
}

static int DialogAction_get_value(lua_State* L)
{
    DialogAction* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogAction is nil");
    lua_pushinteger(L, b->value);
    return 1;
}

// --- Setters for DialogAction ---
static int DialogAction_set_key(lua_State* L)
{
    DialogAction* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogAction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for key");
}

static int DialogAction_set_value(lua_State* L)
{
    DialogAction* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogAction is nil");
    b->value = (int)luaL_checkinteger(L, 2);
    return 0;
}



int DialogActionBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DialogActionBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DialogAction object");
    return 1;
}

void DialogActionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogActionBinding::gc },
        { "__tostring", DialogActionBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        DialogActionBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DialogActionBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DialogAction_get_key);
    lua_setfield(L, -2, "key");
    lua_pushcfunction(L, DialogAction_get_value);
    lua_setfield(L, -2, "value");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DialogAction_set_key);
    lua_setfield(L, -2, "key");
    lua_pushcfunction(L, DialogAction_set_value);
    lua_setfield(L, -2, "value");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
