#include "pch.h"
#include "KENSHI\GameWorld.h"
#include "SysMessageBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

typedef GameWorld::SysMessage SysMessage;

static SysMessage* getInstance(lua_State* L, int idx)
{
    return checkObject<SysMessage>(L, idx, SysMessageBinding::getMetatableName());
}

// --- Getters for SysMessage ---
static int SysMessage_get_msg(lua_State* L)
{
    SysMessage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SysMessage is nil");
    lua_pushinteger(L, (lua_Integer)instance->msg);
    return 1;
}

static int SysMessage_get_target(lua_State* L)
{
    SysMessage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SysMessage is nil");
    return HandBinding::push(L, instance->target);
}

static int SysMessage_get_from(lua_State* L)
{
    SysMessage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SysMessage is nil");
    return HandBinding::push(L, instance->from);
}

static int SysMessage_get_on(lua_State* L)
{
    SysMessage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SysMessage is nil");
    lua_pushboolean(L, instance->on ? 1 : 0);
    return 1;
}

static int SysMessage_get_number(lua_State* L)
{
    SysMessage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SysMessage is nil");
    lua_pushnumber(L, instance->number);
    return 1;
}

static int SysMessage_get_data(lua_State* L)
{
    SysMessage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SysMessage is nil");
    lua_pushlightuserdata(L, (void*)instance->data);
    return 1;
}

// --- Setters for SysMessage ---
static int SysMessage_set_msg(lua_State* L)
{
    SysMessage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SysMessage is nil");
    instance->msg = (GameWorld::SysMessageEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int SysMessage_set_target(lua_State* L)
{
    SysMessage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SysMessage is nil");
    instance->target = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int SysMessage_set_from(lua_State* L)
{
    SysMessage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SysMessage is nil");
    instance->from = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int SysMessage_set_on(lua_State* L)
{
    SysMessage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SysMessage is nil");
    instance->on = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SysMessage_set_number(lua_State* L)
{
    SysMessage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SysMessage is nil");
    instance->number = (float)luaL_checknumber(L, 2);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 185: SysMessage* _CONSTRUCTOR(...) - overloaded method
  line 187: SysMessage* _CONSTRUCTOR(...) - overloaded method
  line 189: bool operator==(...) - operator
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - SysMessage_get_data: void* (unbound pointer)
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
    registerGetter(L, "msg", SysMessage_get_msg);
    registerGetter(L, "target", SysMessage_get_target);
    registerGetter(L, "from", SysMessage_get_from);
    registerGetter(L, "on", SysMessage_get_on);
    registerGetter(L, "number", SysMessage_get_number);
    registerGetter(L, "data", SysMessage_get_data);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "msg", SysMessage_set_msg);
    registerSetter(L, "target", SysMessage_set_target);
    registerSetter(L, "from", SysMessage_set_from);
    registerSetter(L, "on", SysMessage_set_on);
    registerSetter(L, "number", SysMessage_set_number);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua