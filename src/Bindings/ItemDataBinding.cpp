#include "pch.h"
#include "KENSHI\GameData.h"
#include "ItemDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef GameData::ItemData ItemData;

static ItemData* getInstance(lua_State* L, int idx)
{
    return checkObject<ItemData>(L, idx, ItemDataBinding::getMetatableName());
}

// --- Getters for ItemData ---
static int ItemData_get_visible(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    lua_pushboolean(L, instance->visible ? 1 : 0);
    return 1;
}

static int ItemData_get_category(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    lua_pushstring(L, instance->category.c_str());
    return 1;
}

static int ItemData_get_description(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    lua_pushstring(L, instance->description.c_str());
    return 1;
}

static int ItemData_get_fileTypes(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    lua_pushstring(L, instance->fileTypes.c_str());
    return 1;
}

static int ItemData_get_objectType(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    lua_pushinteger(L, (lua_Integer)instance->objectType);
    return 1;
}

static int ItemData_get_maxSize(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    lua_pushinteger(L, instance->maxSize);
    return 1;
}

static int ItemData_get_maxValue(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    lua_pushinteger(L, instance->maxValue);
    return 1;
}

static int ItemData_get_minValue(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    lua_pushinteger(L, instance->minValue);
    return 1;
}

static int ItemData_get_isSlider(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    lua_pushboolean(L, instance->isSlider ? 1 : 0);
    return 1;
}

// --- Setters for ItemData ---
static int ItemData_set_visible(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    instance->visible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ItemData_set_category(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    instance->category = luaL_checkstring(L, 2);
    return 0;
}

static int ItemData_set_description(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    instance->description = luaL_checkstring(L, 2);
    return 0;
}

static int ItemData_set_fileTypes(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    instance->fileTypes = luaL_checkstring(L, 2);
    return 0;
}

static int ItemData_set_objectType(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    instance->objectType = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int ItemData_set_maxSize(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    instance->maxSize = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ItemData_set_maxValue(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    instance->maxValue = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ItemData_set_minValue(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    instance->minValue = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ItemData_set_isSlider(lua_State* L)
{
    ItemData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemData is nil");
    instance->isSlider = lua_toboolean(L, 2) != 0;
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
    registerGetter(L, "visible", ItemData_get_visible);
    registerGetter(L, "category", ItemData_get_category);
    registerGetter(L, "description", ItemData_get_description);
    registerGetter(L, "fileTypes", ItemData_get_fileTypes);
    registerGetter(L, "objectType", ItemData_get_objectType);
    registerGetter(L, "maxSize", ItemData_get_maxSize);
    registerGetter(L, "maxValue", ItemData_get_maxValue);
    registerGetter(L, "minValue", ItemData_get_minValue);
    registerGetter(L, "isSlider", ItemData_get_isSlider);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "visible", ItemData_set_visible);
    registerSetter(L, "category", ItemData_set_category);
    registerSetter(L, "description", ItemData_set_description);
    registerSetter(L, "fileTypes", ItemData_set_fileTypes);
    registerSetter(L, "objectType", ItemData_set_objectType);
    registerSetter(L, "maxSize", ItemData_set_maxSize);
    registerSetter(L, "maxValue", ItemData_set_maxValue);
    registerSetter(L, "minValue", ItemData_set_minValue);
    registerSetter(L, "isSlider", ItemData_set_isSlider);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua