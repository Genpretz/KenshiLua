#include "pch.h"
#include "kenshi/HandleManager.h"
#include "HandleContainerListBinding.h"
#include "HandleListBaseBinding.h"
#include "Bindings/Kenshi/RootObjectBaseBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static HandleContainerList* getInstance(lua_State* L, int idx)
{
    return checkObject<HandleContainerList>(L, idx, HandleContainerListBinding::getMetatableName());
}

int HandleContainerListBinding::add(lua_State* L)
{
    HandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleContainerList is nil");
    RootObjectBase* o = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    hand res = instance->add(o);
    return HandBinding::push(L, res);
}

int HandleContainerListBinding::_NV_add(lua_State* L)
{
    HandleContainerList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleContainerList is nil");
    RootObjectBase* o = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    hand res = instance->_NV_add(o);
    return HandBinding::push(L, res);
}

int HandleContainerListBinding::gc(lua_State* L)
{
    return 0;
}

int HandleContainerListBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.HandleContainerList object");
    return 1;
}

void HandleContainerListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       HandleContainerListBinding::gc },
        { "__tostring", HandleContainerListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "add", HandleContainerListBinding::add },
        { "_NV_add", HandleContainerListBinding::_NV_add },
        { 0, 0 }
    };

    registerClass(
        L,
        HandleContainerListBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );
}

} // namespace KenshiLua

