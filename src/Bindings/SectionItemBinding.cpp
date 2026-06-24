#include "pch.h"
#include "kenshi\Inventory.h"
#include "SectionItemBinding.h"
#include "ItemBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef InventorySection::SectionItem SectionItem;

static SectionItem* getB(lua_State* L, int idx)
{
    return checkObject<SectionItem>(L, idx, SectionItemBinding::getMetatableName());
}

// --- Getters for SectionItem ---
static int SectionItem_get_item(lua_State* L)
{
    SectionItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "SectionItem is nil");
    return pushObject<Item>(L, b->item, ItemBinding::getMetatableName());
}

static int SectionItem_get_x(lua_State* L)
{
    SectionItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "SectionItem is nil");
    lua_pushinteger(L, b->x);
    return 1;
}

static int SectionItem_get_y(lua_State* L)
{
    SectionItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "SectionItem is nil");
    lua_pushinteger(L, b->y);
    return 1;
}

static int SectionItem_get_w(lua_State* L)
{
    SectionItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "SectionItem is nil");
    lua_pushinteger(L, b->w);
    return 1;
}

static int SectionItem_get_h(lua_State* L)
{
    SectionItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "SectionItem is nil");
    lua_pushinteger(L, b->h);
    return 1;
}

// --- Setters for SectionItem ---
static int SectionItem_set_item(lua_State* L)
{
    SectionItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "SectionItem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for item");
}

static int SectionItem_set_x(lua_State* L)
{
    SectionItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "SectionItem is nil");
    b->x = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

static int SectionItem_set_y(lua_State* L)
{
    SectionItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "SectionItem is nil");
    b->y = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

static int SectionItem_set_w(lua_State* L)
{
    SectionItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "SectionItem is nil");
    b->w = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

static int SectionItem_set_h(lua_State* L)
{
    SectionItem* b = getB(L, 1);
    if (!b) return luaL_error(L, "SectionItem is nil");
    b->h = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}



int SectionItemBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SectionItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SectionItem object");
    return 1;
}

void SectionItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SectionItemBinding::gc },
        { "__tostring", SectionItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        SectionItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SectionItemBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, SectionItem_get_item);
    lua_setfield(L, -2, "item");
    lua_pushcfunction(L, SectionItem_get_x);
    lua_setfield(L, -2, "x");
    lua_pushcfunction(L, SectionItem_get_y);
    lua_setfield(L, -2, "y");
    lua_pushcfunction(L, SectionItem_get_w);
    lua_setfield(L, -2, "w");
    lua_pushcfunction(L, SectionItem_get_h);
    lua_setfield(L, -2, "h");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, SectionItem_set_item);
    lua_setfield(L, -2, "item");
    lua_pushcfunction(L, SectionItem_set_x);
    lua_setfield(L, -2, "x");
    lua_pushcfunction(L, SectionItem_set_y);
    lua_setfield(L, -2, "y");
    lua_pushcfunction(L, SectionItem_set_w);
    lua_setfield(L, -2, "w");
    lua_pushcfunction(L, SectionItem_set_h);
    lua_setfield(L, -2, "h");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua