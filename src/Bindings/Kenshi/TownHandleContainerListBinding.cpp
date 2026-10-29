#include "pch.h"
#include "kenshi/HandleManager.h"
#include "TownHandleContainerListBinding.h"
#include "HandleContainerListBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

int TownHandleContainerListBinding::gc(lua_State* L)
{
    return 0;
}

int TownHandleContainerListBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TownHandleContainerList object");
    return 1;
}

void TownHandleContainerListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TownHandleContainerListBinding::gc },
        { "__tostring", TownHandleContainerListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L,
        TownHandleContainerListBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );
}

} // namespace KenshiLua

