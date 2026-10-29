#include "pch.h"
#include "kenshi/HandleManager.h"
#include "PlatoonHandleContainerListBinding.h"
#include "HandleContainerListBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/RootObjectBaseBinding.h"
#include "Bindings/Kenshi/ActivePlatoonBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static PlatoonHandleContainerList* getInstance(lua_State* L, int idx)
{
    return checkObject<PlatoonHandleContainerList>(L, idx, PlatoonHandleContainerListBinding::getMetatableName());
}

int PlatoonHandleContainerListBinding::getCharacterOrZero(lua_State* L)
{
    PlatoonHandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlatoonHandleContainerList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    RootObject* res = instance->getCharacterOrZero(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<RootObject>(L, res, RootObjectBinding::getMetatableName());
}

int PlatoonHandleContainerListBinding::getCharacterOrPlatoon(lua_State* L)
{
    PlatoonHandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlatoonHandleContainerList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    RootObjectBase* res = instance->getCharacterOrPlatoon(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<RootObjectBase>(L, res, RootObjectBaseBinding::getMetatableName());
}

int PlatoonHandleContainerListBinding::getActivePlatoon(lua_State* L)
{
    PlatoonHandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlatoonHandleContainerList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    ActivePlatoon* res = instance->getActivePlatoon(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<ActivePlatoon>(L, res, ActivePlatoonBinding::getMetatableName());
}

int PlatoonHandleContainerListBinding::setUnloaded(lua_State* L)
{
    PlatoonHandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlatoonHandleContainerList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->setUnloaded(*h);
    return 0;
}

int PlatoonHandleContainerListBinding::_NV_setUnloaded(lua_State* L)
{
    PlatoonHandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlatoonHandleContainerList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->_NV_setUnloaded(*h);
    return 0;
}

int PlatoonHandleContainerListBinding::destroy(lua_State* L)
{
    PlatoonHandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlatoonHandleContainerList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->destroy(*h);
    return 0;
}

int PlatoonHandleContainerListBinding::_NV_destroy(lua_State* L)
{
    PlatoonHandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PlatoonHandleContainerList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->_NV_destroy(*h);
    return 0;
}

int PlatoonHandleContainerListBinding::gc(lua_State* L)
{
    return 0;
}

int PlatoonHandleContainerListBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.PlatoonHandleContainerList object");
    return 1;
}

void PlatoonHandleContainerListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PlatoonHandleContainerListBinding::gc },
        { "__tostring", PlatoonHandleContainerListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getCharacterOrZero", PlatoonHandleContainerListBinding::getCharacterOrZero },
        { "getCharacterOrPlatoon", PlatoonHandleContainerListBinding::getCharacterOrPlatoon },
        { "getActivePlatoon", PlatoonHandleContainerListBinding::getActivePlatoon },
        { "setUnloaded", PlatoonHandleContainerListBinding::setUnloaded },
        { "_NV_setUnloaded", PlatoonHandleContainerListBinding::_NV_setUnloaded },
        { "destroy", PlatoonHandleContainerListBinding::destroy },
        { "_NV_destroy", PlatoonHandleContainerListBinding::_NV_destroy },
        { 0, 0 }
    };

    registerClass(
        L,
        PlatoonHandleContainerListBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );
}

} // namespace KenshiLua

