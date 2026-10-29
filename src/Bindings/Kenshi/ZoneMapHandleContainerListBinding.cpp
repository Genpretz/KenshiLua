#include "pch.h"
#include "kenshi/HandleManager.h"
#include "ZoneMapHandleContainerListBinding.h"
#include "HandleContainerListBinding.h"
#include "HandleListBinding.h"
#include "Bindings/Kenshi/ZoneMapContentBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ZoneMapHandleContainerList* getInstance(lua_State* L, int idx)
{
    return checkObject<ZoneMapHandleContainerList>(L, idx, ZoneMapHandleContainerListBinding::getMetatableName());
}

int ZoneMapHandleContainerListBinding::getZoneMap(lua_State* L)
{
    ZoneMapHandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapHandleContainerList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    ZoneMapContent* res = instance->getZoneMap(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<ZoneMapContent>(L, res, ZoneMapContentBinding::getMetatableName());
}

int ZoneMapHandleContainerListBinding::getObject(lua_State* L)
{
    ZoneMapHandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapHandleContainerList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    RootObject* res = instance->getObject(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<RootObject>(L, res, RootObjectBinding::getMetatableName());
}

int ZoneMapHandleContainerListBinding::setUnloaded(lua_State* L)
{
    ZoneMapHandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapHandleContainerList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->setUnloaded(*h);
    return 0;
}

int ZoneMapHandleContainerListBinding::_NV_setUnloaded(lua_State* L)
{
    ZoneMapHandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapHandleContainerList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->_NV_setUnloaded(*h);
    return 0;
}

int ZoneMapHandleContainerListBinding::destroy(lua_State* L)
{
    ZoneMapHandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapHandleContainerList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->destroy(*h);
    return 0;
}

int ZoneMapHandleContainerListBinding::_NV_destroy(lua_State* L)
{
    ZoneMapHandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapHandleContainerList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->_NV_destroy(*h);
    return 0;
}

int ZoneMapHandleContainerListBinding::getCorrectHandleList(lua_State* L)
{
    ZoneMapHandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapHandleContainerList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    HandleList* res = instance->getCorrectHandleList(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<HandleList>(L, res, HandleListBinding::getMetatableName());
}

int ZoneMapHandleContainerListBinding::gc(lua_State* L)
{
    return 0;
}

int ZoneMapHandleContainerListBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ZoneMapHandleContainerList object");
    return 1;
}

void ZoneMapHandleContainerListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ZoneMapHandleContainerListBinding::gc },
        { "__tostring", ZoneMapHandleContainerListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getZoneMap", ZoneMapHandleContainerListBinding::getZoneMap },
        { "getObject", ZoneMapHandleContainerListBinding::getObject },
        { "setUnloaded", ZoneMapHandleContainerListBinding::setUnloaded },
        { "_NV_setUnloaded", ZoneMapHandleContainerListBinding::_NV_setUnloaded },
        { "destroy", ZoneMapHandleContainerListBinding::destroy },
        { "_NV_destroy", ZoneMapHandleContainerListBinding::_NV_destroy },
        { "getCorrectHandleList", ZoneMapHandleContainerListBinding::getCorrectHandleList },
        { 0, 0 }
    };

    registerClass(
        L,
        ZoneMapHandleContainerListBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );
}

} // namespace KenshiLua

