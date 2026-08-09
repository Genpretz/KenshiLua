#include "pch.h"
#include "Bindings/ManagementScreen_TechItemViewDataBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/gui/ManagementScreen.h>

namespace KenshiLua
{

static ManagementScreen::TechItemViewData* getInstance(lua_State* L, int idx)
{
    return checkObject<ManagementScreen::TechItemViewData>(L, idx, ManagementScreen_TechItemViewDataBinding::getMetatableName());
}

// --- Getters for TechItemViewData ---
static int TechItemViewData_get_item(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ManagementScreen::TechItemViewData is nil");
    if (inst->item) lua_pushlightuserdata(L, (void*)inst->item); else lua_pushnil(L);
    return 1;
}

// --- Setters for TechItemViewData ---
static int TechItemViewData_set_item(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ManagementScreen::TechItemViewData is nil");
    inst->item = (ResearchItem*)lua_touserdata(L, 2);
    return 0;
}

int ManagementScreen_TechItemViewDataBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (ManagementScreen::TechItemViewData*)::operator new(sizeof(ManagementScreen::TechItemViewData));
    ::new ((void*)obj) ManagementScreen::TechItemViewData();
    return pushObject<ManagementScreen::TechItemViewData>(L, obj, getMetatableName());
}

int ManagementScreen_TechItemViewDataBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ManagementScreen::TechItemViewData is nil");
    inst->~TechItemViewData();
    return 0;
}

int ManagementScreen_TechItemViewDataBinding::gc(lua_State* L)
{
    return 0;
}

int ManagementScreen_TechItemViewDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ManagementScreen_TechItemViewData object");
    return 1;
}

int ManagementScreen_TechItemViewDataBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->item == b->item)) ? 1 : 0);
    return 1;
}

void ManagementScreen_TechItemViewDataBinding::registerBinding(lua_State* L)
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

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "item", TechItemViewData_get_item);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "item", TechItemViewData_set_item);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
