#include "pch.h"
#include "kenshi/HandleManager.h"
#include "HandleListBaseBinding.h"
#include "Bindings/Kenshi/SerialisableBinding.h"
#include "Bindings/Kenshi/RootObjectBaseBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(HandleListBase, objects) == 0x8, "HandleListBase::objects offset mismatch");
static_assert(offsetof(HandleListBase, maxSize) == 0x10, "HandleListBase::maxSize offset mismatch");
static_assert(offsetof(HandleListBase, lastID) == 0x14, "HandleListBase::lastID offset mismatch");

static HandleListBase* getInstance(lua_State* L, int idx)
{
    return checkObject<HandleListBase>(L, idx, HandleListBaseBinding::getMetatableName());
}

static int HandleListBase_get_maxSize(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    lua_pushinteger(L, (lua_Integer)instance->maxSize);
    return 1;
}

static int HandleListBase_set_maxSize(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    instance->maxSize = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int HandleListBase_get_lastID(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    lua_pushinteger(L, (lua_Integer)instance->lastID);
    return 1;
}

static int HandleListBase_set_lastID(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    instance->lastID = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

int HandleListBaseBinding::clearToZero(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    instance->clearToZero();
    return 0;
}

int HandleListBaseBinding::_NV_clearToZero(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    instance->_NV_clearToZero();
    return 0;
}

int HandleListBaseBinding::get(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    RootObjectBase* res = instance->get(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<RootObjectBase>(L, res, RootObjectBaseBinding::getMetatableName());
}

int HandleListBaseBinding::_NV_get(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    RootObjectBase* res = instance->_NV_get(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<RootObjectBase>(L, res, RootObjectBaseBinding::getMetatableName());
}

int HandleListBaseBinding::isUnloadedNotDead(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    bool res = instance->isUnloadedNotDead(*h);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int HandleListBaseBinding::_NV_isUnloadedNotDead(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    bool res = instance->_NV_isUnloadedNotDead(*h);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int HandleListBaseBinding::addExisting(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    RootObjectBase* o = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    hand* h = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 must be hand");
    hand res = instance->addExisting(o, *h);
    return HandBinding::push(L, res);
}

int HandleListBaseBinding::_NV_addExisting(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    RootObjectBase* o = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    hand* h = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 must be hand");
    hand res = instance->_NV_addExisting(o, *h);
    return HandBinding::push(L, res);
}

int HandleListBaseBinding::setUnloaded(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->setUnloaded(*h);
    return 0;
}

int HandleListBaseBinding::_NV_setUnloaded(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->_NV_setUnloaded(*h);
    return 0;
}

int HandleListBaseBinding::destroy(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->destroy(*h);
    return 0;
}

int HandleListBaseBinding::_NV_destroy(lua_State* L)
{
    HandleListBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleListBase is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->_NV_destroy(*h);
    return 0;
}

int HandleListBaseBinding::gc(lua_State* L)
{
    return 0;
}

int HandleListBaseBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.HandleListBase object");
    return 1;
}

void HandleListBaseBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       HandleListBaseBinding::gc },
        { "__tostring", HandleListBaseBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "clearToZero", HandleListBaseBinding::clearToZero },
        { "_NV_clearToZero", HandleListBaseBinding::_NV_clearToZero },
        { "get", HandleListBaseBinding::get },
        { "_NV_get", HandleListBaseBinding::_NV_get },
        { "isUnloadedNotDead", HandleListBaseBinding::isUnloadedNotDead },
        { "_NV_isUnloadedNotDead", HandleListBaseBinding::_NV_isUnloadedNotDead },
        { "addExisting", HandleListBaseBinding::addExisting },
        { "_NV_addExisting", HandleListBaseBinding::_NV_addExisting },
        { "setUnloaded", HandleListBaseBinding::setUnloaded },
        { "_NV_setUnloaded", HandleListBaseBinding::_NV_setUnloaded },
        { "destroy", HandleListBaseBinding::destroy },
        { "_NV_destroy", HandleListBaseBinding::_NV_destroy },
        { 0, 0 }
    };

    registerClass(
        L,
        HandleListBaseBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, HandleListBaseBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "maxSize", HandleListBase_get_maxSize);
    registerGetter(L, "lastID", HandleListBase_get_lastID);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "maxSize", HandleListBase_set_maxSize);
    registerSetter(L, "lastID", HandleListBase_set_lastID);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua

