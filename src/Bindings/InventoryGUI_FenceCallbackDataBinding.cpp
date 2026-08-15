#include "pch.h"
#include "Bindings/InventoryGUI_FenceCallbackDataBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/gui/InventoryGUI.h>

namespace KenshiLua
{

static InventoryGUI::FenceCallbackData* getInstance(lua_State* L, int idx)
{
    return checkObject<InventoryGUI::FenceCallbackData>(L, idx, InventoryGUI_FenceCallbackDataBinding::getMetatableName());
}

// --- Getters for FenceCallbackData ---
static int FenceCallbackData_get_mode(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InventoryGUI::FenceCallbackData is nil");
    lua_pushinteger(L, inst->mode);
    return 1;
}

static int FenceCallbackData_get_sectionName(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InventoryGUI::FenceCallbackData is nil");
    lua_pushstring(L, inst->sectionName.c_str());

    return 1;
}

static int FenceCallbackData_get_point(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InventoryGUI::FenceCallbackData is nil");
    lua_pushlightuserdata(L, (void*)&inst->point);
    return 1;
}

// --- Setters for FenceCallbackData ---
static int FenceCallbackData_set_mode(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InventoryGUI::FenceCallbackData is nil");
    inst->mode = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int FenceCallbackData_set_sectionName(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InventoryGUI::FenceCallbackData is nil");
    inst->sectionName = luaL_checkstring(L, 2);
    return 0;
}

static int FenceCallbackData_set_point(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "InventoryGUI::FenceCallbackData is nil");
    inst->point = *(MyGUI::types::TPoint<int>*)lua_touserdata(L, 2);
    return 0;
}

int InventoryGUI_FenceCallbackDataBinding::gc(lua_State* L)
{
    return 0;
}

int InventoryGUI_FenceCallbackDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.InventoryGUI_FenceCallbackData object");
    return 1;
}

int InventoryGUI_FenceCallbackDataBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->mode == b->mode && a->sectionName == b->sectionName && a->point == b->point)) ? 1 : 0);
    return 1;
}

void InventoryGUI_FenceCallbackDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "mode", FenceCallbackData_get_mode);
    registerGetter(L, "sectionName", FenceCallbackData_get_sectionName);
    registerGetter(L, "point", FenceCallbackData_get_point);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "mode", FenceCallbackData_set_mode);
    registerSetter(L, "sectionName", FenceCallbackData_set_sectionName);
    registerSetter(L, "point", FenceCallbackData_set_point);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
