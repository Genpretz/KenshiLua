#include "pch.h"
#include "Bindings/AppearanceManager_DataCategoryBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static AppearanceManager::DataCategory* getInstance(lua_State* L, int idx)
{
    return checkObject<AppearanceManager::DataCategory>(L, idx, AppearanceManager_DataCategoryBinding::getMetatableName());
}

// --- Methods ---
int AppearanceManager_DataCategoryBinding::setValue(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataCategory is nil");
    inst->setValue(luaL_checkstring(L, 2));
    return 0;
}

int AppearanceManager_DataCategoryBinding::getValue(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataCategory is nil");
    AppearanceManager::DataCategory::Enum result = inst->getValue();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

// --- Getters for DataCategory ---
static int DataCategory_get_value(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataCategory is nil");
    lua_pushinteger(L, (lua_Integer)inst->value);
    return 1;
}

// --- Setters for DataCategory ---
static int DataCategory_set_value(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataCategory is nil");
    inst->value = (AppearanceManager::DataCategory::Enum)luaL_checkinteger(L, 2);
    return 0;
}

/*
Skipped properties needing manual binding:
  line 98: ranges (Ogre::FastArray<DataRange>) - unsupported type
  line 99: posesRanges (Ogre::FastArray<DataRangePose>) - unsupported type
  line 100: vectorRanges (Ogre::FastArray<DataRangeVector>) - unsupported type
*/

int AppearanceManager_DataCategoryBinding::gc(lua_State* L)
{
    return 0;
}

int AppearanceManager_DataCategoryBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AppearanceManager_DataCategory object");
    return 1;
}

int AppearanceManager_DataCategoryBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void AppearanceManager_DataCategoryBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       AppearanceManager_DataCategoryBinding::operator_eq },
        { "__gc",       AppearanceManager_DataCategoryBinding::gc },
        { "__tostring", AppearanceManager_DataCategoryBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setValue",   AppearanceManager_DataCategoryBinding::setValue },
        { "getValue",   AppearanceManager_DataCategoryBinding::getValue },
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "value", DataCategory_get_value);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "value", DataCategory_set_value);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
