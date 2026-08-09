#include "pch.h"
#include "Bindings/TraitBoolBinding.h"
#include "Lua/BindingHelpers.h"

typedef hkTrait::TraitBool<1> TraitBool;

namespace KenshiLua
{

static TraitBool* getInstance(lua_State* L, int idx)
{
    return checkObject<TraitBool>(L, idx, TraitBoolBinding::getMetatableName());
}

int TraitBoolBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (TraitBool*)::operator new(sizeof(TraitBool));
    ::new ((void*)obj) TraitBool();
    return pushObject<TraitBool>(L, obj, getMetatableName());
}

int TraitBoolBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TraitBool is nil");
    inst->~TraitBool();
    return 0;
}

int TraitBoolBinding::gc(lua_State* L)
{
    return 0;
}

int TraitBoolBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TraitBool object");
    return 1;
}

int TraitBoolBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void TraitBoolBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", _CONSTRUCTOR },
        { "_DESTRUCTOR",  _DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);
}
} // namespace KenshiLua
