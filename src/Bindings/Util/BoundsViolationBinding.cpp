#include "pch.h"
#include "BoundsViolationBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

struct BoundsViolation {};

static BoundsViolation* getInstance(lua_State* L, int idx)
{
    return checkObject<BoundsViolation>(L, idx, BoundsViolationBinding::getMetatableName());
}

int BoundsViolationBinding::gc(lua_State* L)
{
    return 0;
}

int BoundsViolationBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BoundsViolation object");
    return 1;
}

void BoundsViolationBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BoundsViolationBinding::gc },
        { "__tostring", BoundsViolationBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        BoundsViolationBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );
}

} // namespace KenshiLua