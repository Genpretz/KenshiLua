#include "pch.h"
#include "MustEndWithSemiColonBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

struct MustEndWithSemiColon {};

static MustEndWithSemiColon* getInstance(lua_State* L, int idx)
{
    return checkObject<MustEndWithSemiColon>(L, idx, MustEndWithSemiColonBinding::getMetatableName());
}


int MustEndWithSemiColonBinding::gc(lua_State* L)
{
    return 0;
}

int MustEndWithSemiColonBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MustEndWithSemiColon object");
    return 1;
}

void MustEndWithSemiColonBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MustEndWithSemiColonBinding::gc },
        { "__tostring", MustEndWithSemiColonBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        MustEndWithSemiColonBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );
}

} // namespace KenshiLua