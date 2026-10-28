#include "pch.h"
#include "kenshi/HandleManager.h"
#include "ItemHandleListBinding.h"
#include "HandleListBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ItemHandleList* getInstance(lua_State* L, int idx)
{
    return checkObject<ItemHandleList>(L, idx, ItemHandleListBinding::getMetatableName());
}

int ItemHandleListBinding::setUnloaded(lua_State* L)
{
    ItemHandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemHandleList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->setUnloaded(*h);
    return 0;
}

int ItemHandleListBinding::_NV_setUnloaded(lua_State* L)
{
    ItemHandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemHandleList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->_NV_setUnloaded(*h);
    return 0;
}

int ItemHandleListBinding::gc(lua_State* L)
{
    return 0;
}

int ItemHandleListBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ItemHandleList object");
    return 1;
}

void ItemHandleListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ItemHandleListBinding::gc },
        { "__tostring", ItemHandleListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setUnloaded", ItemHandleListBinding::setUnloaded },
        { "_NV_setUnloaded", ItemHandleListBinding::_NV_setUnloaded },
        { 0, 0 }
    };

    registerClass(
        L,
        ItemHandleListBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );
}

} // namespace KenshiLua

