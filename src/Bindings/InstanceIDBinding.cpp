#include "pch.h"
#include "kenshi\InstanceID.h"
#include "InstanceIDBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static InstanceID* getInstance(lua_State* L, int idx)
{
    return checkObject<InstanceID>(L, idx, InstanceIDBinding::getMetatableName());
}

// --- Getters for InstanceID ---
static int InstanceID_get_uid(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");
    lua_pushstring(L, instance->uid.c_str());
    return 1;
}

static int InstanceID_get_baseIndex(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");
    lua_pushinteger(L, instance->baseIndex);
    return 1;
}

static int InstanceID_get_modIndex(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");
    lua_pushinteger(L, instance->modIndex);
    return 1;
}

static int InstanceID_get_modified(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");
    lua_pushboolean(L, instance->modified ? 1 : 0);
    return 1;
}

// --- Setters for InstanceID ---
static int InstanceID_set_uid(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");
    instance->uid = luaL_checkstring(L, 2);
    return 0;
}

static int InstanceID_set_baseIndex(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");
    instance->baseIndex = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int InstanceID_set_modIndex(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");
    instance->modIndex = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int InstanceID_set_modified(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");
    instance->modified = lua_toboolean(L, 2) != 0;
    return 0;
}

int InstanceIDBinding::assign(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");

    std::string id = luaL_checkstring(L, 2);
    instance->assign(id);
    return 0;
}

int InstanceIDBinding::clear(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");

    instance->clear();
    return 0;
}

int InstanceIDBinding::needsSaving(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");

    std::string mod = luaL_checkstring(L, 2);
    bool result = instance->needsSaving(mod);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InstanceIDBinding::notifyChange(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");

    instance->notifyChange();
    return 0;
}

int InstanceIDBinding::hasChanges(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");

    bool result = instance->hasChanges();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InstanceIDBinding::notifySaved(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");

    std::string mod = luaL_checkstring(L, 2);
    instance->notifySaved(mod);
    return 0;
}

int InstanceIDBinding::empty(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");

    bool result = instance->empty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InstanceIDBinding::getBaseIndex(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");

    int result = instance->getBaseIndex();
    lua_pushinteger(L, result);
    return 1;
}

int InstanceIDBinding::_DESTRUCTOR(lua_State* L)
{
    InstanceID* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InstanceID is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 13: int getModIndex(...) - overloaded method
  line 14: short getModIndex(...) - static method
  line 16: InstanceID* _CONSTRUCTOR(...) - overloaded method
  line 18: InstanceID* _CONSTRUCTOR(...) - overloaded method
  line 20: InstanceID* _CONSTRUCTOR(...) - overloaded method
  line 29: bool operator==(...) - operator
  line 33: InstanceID& operator=(...) - operator
*/

int InstanceIDBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int InstanceIDBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.InstanceID object");
    return 1;
}

void InstanceIDBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       InstanceIDBinding::gc },
        { "__tostring", InstanceIDBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "assign", InstanceIDBinding::assign },
        { "clear", InstanceIDBinding::clear },
        { "needsSaving", InstanceIDBinding::needsSaving },
        { "notifyChange", InstanceIDBinding::notifyChange },
        { "hasChanges", InstanceIDBinding::hasChanges },
        { "notifySaved", InstanceIDBinding::notifySaved },
        { "empty", InstanceIDBinding::empty },
        { "getBaseIndex", InstanceIDBinding::getBaseIndex },
        { "_DESTRUCTOR", InstanceIDBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        InstanceIDBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, InstanceIDBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, InstanceID_get_uid);
    lua_setfield(L, -2, "uid");
    lua_pushcfunction(L, InstanceID_get_baseIndex);
    lua_setfield(L, -2, "baseIndex");
    lua_pushcfunction(L, InstanceID_get_modIndex);
    lua_setfield(L, -2, "modIndex");
    lua_pushcfunction(L, InstanceID_get_modified);
    lua_setfield(L, -2, "modified");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, InstanceID_set_uid);
    lua_setfield(L, -2, "uid");
    lua_pushcfunction(L, InstanceID_set_baseIndex);
    lua_setfield(L, -2, "baseIndex");
    lua_pushcfunction(L, InstanceID_set_modIndex);
    lua_setfield(L, -2, "modIndex");
    lua_pushcfunction(L, InstanceID_set_modified);
    lua_setfield(L, -2, "modified");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
