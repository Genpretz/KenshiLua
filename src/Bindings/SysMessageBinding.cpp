#include "pch.h"
#include "kenshi\GameWorld.h"
#include "SysMessageBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

typedef GameWorld::SysMessage SysMessage;

static SysMessage* getB(lua_State* L, int idx)
{
    return checkObject<SysMessage>(L, idx, SysMessageBinding::getMetatableName());
}

// --- Getters for SysMessage ---
static int SysMessage_get_msg(lua_State* L)
{
    SysMessage* b = getB(L, 1);
    if (!b) return luaL_error(L, "SysMessage is nil");
    lua_pushinteger(L, (lua_Integer)b->msg);
    return 1;
}

static int SysMessage_get_target(lua_State* L)
{
    SysMessage* b = getB(L, 1);
    if (!b) return luaL_error(L, "SysMessage is nil");
    return handBinding::push(L, b->target);
}

static int SysMessage_get_from(lua_State* L)
{
    SysMessage* b = getB(L, 1);
    if (!b) return luaL_error(L, "SysMessage is nil");
    return handBinding::push(L, b->from);
}

static int SysMessage_get_on(lua_State* L)
{
    SysMessage* b = getB(L, 1);
    if (!b) return luaL_error(L, "SysMessage is nil");
    lua_pushboolean(L, b->on ? 1 : 0);
    return 1;
}

static int SysMessage_get_number(lua_State* L)
{
    SysMessage* b = getB(L, 1);
    if (!b) return luaL_error(L, "SysMessage is nil");
    lua_pushnumber(L, b->number);
    return 1;
}

static int SysMessage_get_data(lua_State* L)
{
    SysMessage* b = getB(L, 1);
    if (!b) return luaL_error(L, "SysMessage is nil");
    // TODO: Unsupported type for data (void*)
    return luaL_error(L, "Unsupported property 'data' (type: void*)");
}

// --- Setters for SysMessage ---
static int SysMessage_set_msg(lua_State* L)
{
    SysMessage* b = getB(L, 1);
    if (!b) return luaL_error(L, "SysMessage is nil");
    b->msg = (GameWorld::SysMessageEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int SysMessage_set_target(lua_State* L)
{
    SysMessage* b = getB(L, 1);
    if (!b) return luaL_error(L, "SysMessage is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->target = *val;
    return 0;
}

static int SysMessage_set_from(lua_State* L)
{
    SysMessage* b = getB(L, 1);
    if (!b) return luaL_error(L, "SysMessage is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->from = *val;
    return 0;
}

static int SysMessage_set_on(lua_State* L)
{
    SysMessage* b = getB(L, 1);
    if (!b) return luaL_error(L, "SysMessage is nil");
    b->on = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SysMessage_set_number(lua_State* L)
{
    SysMessage* b = getB(L, 1);
    if (!b) return luaL_error(L, "SysMessage is nil");
    b->number = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SysMessage_set_data(lua_State* L)
{
    SysMessage* b = getB(L, 1);
    if (!b) return luaL_error(L, "SysMessage is nil");
    return luaL_error(L, "Read-only or unsupported setter type for data");
}

/*
Skipped methods needing manual binding:
  line 185: SysMessage* _CONSTRUCTOR(...) - overloaded method
  line 187: SysMessage* _CONSTRUCTOR(...) - overloaded method
  line 189: bool operator==(...) - operator
*/

int SysMessageBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SysMessageBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SysMessage object");
    return 1;
}

void SysMessageBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SysMessageBinding::gc },
        { "__tostring", SysMessageBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        SysMessageBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SysMessageBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, SysMessage_get_msg);
    lua_setfield(L, -2, "msg");
    lua_pushcfunction(L, SysMessage_get_target);
    lua_setfield(L, -2, "target");
    lua_pushcfunction(L, SysMessage_get_from);
    lua_setfield(L, -2, "from");
    lua_pushcfunction(L, SysMessage_get_on);
    lua_setfield(L, -2, "on");
    lua_pushcfunction(L, SysMessage_get_number);
    lua_setfield(L, -2, "number");
    lua_pushcfunction(L, SysMessage_get_data);
    lua_setfield(L, -2, "data");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, SysMessage_set_msg);
    lua_setfield(L, -2, "msg");
    lua_pushcfunction(L, SysMessage_set_target);
    lua_setfield(L, -2, "target");
    lua_pushcfunction(L, SysMessage_set_from);
    lua_setfield(L, -2, "from");
    lua_pushcfunction(L, SysMessage_set_on);
    lua_setfield(L, -2, "on");
    lua_pushcfunction(L, SysMessage_set_number);
    lua_setfield(L, -2, "number");
    lua_pushcfunction(L, SysMessage_set_data);
    lua_setfield(L, -2, "data");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
