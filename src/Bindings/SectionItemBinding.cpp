#include "pch.h"
#include "kenshi\Inventory.h"
#include "SectionItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ItemBinding.h"
#include "ItemBinding.h"

namespace KenshiLua
{

static SectionItem* getInstance(lua_State* L, int idx)
{
    return checkObject<SectionItem>(L, idx, SectionItemBinding::getMetatableName());
}

// --- Getters for SectionItem ---
static int SectionItem_get_item(lua_State* L)
{
    SectionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SectionItem is nil");
    return pushObject<Item>(L, instance->item, ItemBinding::getMetatableName());
}

static int SectionItem_get_x(lua_State* L)
{
    SectionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SectionItem is nil");
    lua_pushinteger(L, instance->x);
    return 1;
}

static int SectionItem_get_y(lua_State* L)
{
    SectionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SectionItem is nil");
    lua_pushinteger(L, instance->y);
    return 1;
}

static int SectionItem_get_w(lua_State* L)
{
    SectionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SectionItem is nil");
    lua_pushinteger(L, instance->w);
    return 1;
}

static int SectionItem_get_h(lua_State* L)
{
    SectionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SectionItem is nil");
    lua_pushinteger(L, instance->h);
    return 1;
}

// --- Setters for SectionItem ---
static int SectionItem_set_item(lua_State* L)
{
    SectionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SectionItem is nil");
    instance->item = lua_isnoneornil(L, 2) ? nullptr : checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    return 0;
}

static int SectionItem_set_x(lua_State* L)
{
    SectionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SectionItem is nil");
    instance->x = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

static int SectionItem_set_y(lua_State* L)
{
    SectionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SectionItem is nil");
    instance->y = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

static int SectionItem_set_w(lua_State* L)
{
    SectionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SectionItem is nil");
    instance->w = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

static int SectionItem_set_h(lua_State* L)
{
    SectionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SectionItem is nil");
    instance->h = (unsigned short)luaL_checkinteger(L, 2);
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
    registerGetter(L, "item", SectionItem_get_item);
    registerGetter(L, "x", SectionItem_get_x);
    registerGetter(L, "y", SectionItem_get_y);
    registerGetter(L, "w", SectionItem_get_w);
    registerGetter(L, "h", SectionItem_get_h);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "item", SectionItem_set_item);
    registerSetter(L, "x", SectionItem_set_x);
    registerSetter(L, "y", SectionItem_set_y);
    registerSetter(L, "w", SectionItem_set_w);
    registerSetter(L, "h", SectionItem_set_h);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua