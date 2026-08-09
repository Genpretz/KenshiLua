#include "pch.h"
#include "Bindings/FactionsScreen_FactionRelationsLine_LessSortBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/gui/FactionsScreen.h>

namespace KenshiLua
{

static FactionsScreen::FactionRelationsLine::LessSort* getInstance(lua_State* L, int idx)
{
    return checkObject<FactionsScreen::FactionRelationsLine::LessSort>(L, idx, FactionsScreen_FactionRelationsLine_LessSortBinding::getMetatableName());
}

int FactionsScreen_FactionRelationsLine_LessSortBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (FactionsScreen::FactionRelationsLine::LessSort*)::operator new(sizeof(FactionsScreen::FactionRelationsLine::LessSort));
    ::new ((void*)obj) FactionsScreen::FactionRelationsLine::LessSort();
    return pushObject<FactionsScreen::FactionRelationsLine::LessSort>(L, obj, getMetatableName());
}

int FactionsScreen_FactionRelationsLine_LessSortBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FactionsScreen::FactionRelationsLine::LessSort is nil");
    inst->~LessSort();
    return 0;
}

int FactionsScreen_FactionRelationsLine_LessSortBinding::gc(lua_State* L)
{
    return 0;
}

int FactionsScreen_FactionRelationsLine_LessSortBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FactionsScreen_FactionRelationsLine_LessSort object");
    return 1;
}

int FactionsScreen_FactionRelationsLine_LessSortBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void FactionsScreen_FactionRelationsLine_LessSortBinding::registerBinding(lua_State* L)
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
