#include "pch.h"
#include "kenshi\GameData.h"
#include "ItemDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static GameData::ItemData* getB(lua_State* L, int idx)
{
    return checkObject<GameData::ItemData>(L, idx, ItemDataBinding::getMetatableName());
}

// --- Getters for ItemData ---
static int ItemData_get_visible(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    lua_pushboolean(L, b->visible ? 1 : 0);
    return 1;
}

static int ItemData_get_category(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    lua_pushstring(L, b->category.c_str());
    return 1;
}

static int ItemData_get_description(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    lua_pushstring(L, b->description.c_str());
    return 1;
}

static int ItemData_get_fileTypes(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    lua_pushstring(L, b->fileTypes.c_str());
    return 1;
}

static int ItemData_get_objectType(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    lua_pushinteger(L, (lua_Integer)b->objectType);
    return 1;
}

static int ItemData_get_maxSize(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    lua_pushinteger(L, b->maxSize);
    return 1;
}

static int ItemData_get_maxValue(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    lua_pushinteger(L, b->maxValue);
    return 1;
}

static int ItemData_get_minValue(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    lua_pushinteger(L, b->minValue);
    return 1;
}

static int ItemData_get_isSlider(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    lua_pushboolean(L, b->isSlider ? 1 : 0);
    return 1;
}

// --- Setters for ItemData ---
static int ItemData_set_visible(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    b->visible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ItemData_set_category(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    b->category = luaL_checkstring(L, 2);
    return 0;
}

static int ItemData_set_description(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    b->description = luaL_checkstring(L, 2);
    return 0;
}

static int ItemData_set_fileTypes(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    b->fileTypes = luaL_checkstring(L, 2);
    return 0;
}

static int ItemData_set_objectType(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    b->objectType = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int ItemData_set_maxSize(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    b->maxSize = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ItemData_set_maxValue(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    b->maxValue = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ItemData_set_minValue(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    b->minValue = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ItemData_set_isSlider(lua_State* L)
{
    GameData::ItemData* b = getB(L, 1);
    if (!b) return luaL_error(L, "ItemData is nil");
    b->isSlider = lua_toboolean(L, 2) != 0;
    return 0;
}



int ItemDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ItemDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ItemData object");
    return 1;
}

void ItemDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ItemDataBinding::gc },
        { "__tostring", ItemDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        ItemDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ItemDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ItemData_get_visible);
    lua_setfield(L, -2, "visible");
    lua_pushcfunction(L, ItemData_get_category);
    lua_setfield(L, -2, "category");
    lua_pushcfunction(L, ItemData_get_description);
    lua_setfield(L, -2, "description");
    lua_pushcfunction(L, ItemData_get_fileTypes);
    lua_setfield(L, -2, "fileTypes");
    lua_pushcfunction(L, ItemData_get_objectType);
    lua_setfield(L, -2, "objectType");
    lua_pushcfunction(L, ItemData_get_maxSize);
    lua_setfield(L, -2, "maxSize");
    lua_pushcfunction(L, ItemData_get_maxValue);
    lua_setfield(L, -2, "maxValue");
    lua_pushcfunction(L, ItemData_get_minValue);
    lua_setfield(L, -2, "minValue");
    lua_pushcfunction(L, ItemData_get_isSlider);
    lua_setfield(L, -2, "isSlider");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ItemData_set_visible);
    lua_setfield(L, -2, "visible");
    lua_pushcfunction(L, ItemData_set_category);
    lua_setfield(L, -2, "category");
    lua_pushcfunction(L, ItemData_set_description);
    lua_setfield(L, -2, "description");
    lua_pushcfunction(L, ItemData_set_fileTypes);
    lua_setfield(L, -2, "fileTypes");
    lua_pushcfunction(L, ItemData_set_objectType);
    lua_setfield(L, -2, "objectType");
    lua_pushcfunction(L, ItemData_set_maxSize);
    lua_setfield(L, -2, "maxSize");
    lua_pushcfunction(L, ItemData_set_maxValue);
    lua_setfield(L, -2, "maxValue");
    lua_pushcfunction(L, ItemData_set_minValue);
    lua_setfield(L, -2, "minValue");
    lua_pushcfunction(L, ItemData_set_isSlider);
    lua_setfield(L, -2, "isSlider");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
