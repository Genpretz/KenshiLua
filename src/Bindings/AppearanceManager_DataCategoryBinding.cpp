#include "pch.h"
#include "Bindings/AppearanceManager_DataCategoryBinding.h"
#include "Bindings/AppearanceManager_DataRangeBinding.h"
#include "Bindings/AppearanceManager_DataRangePoseBinding.h"
#include "Bindings/AppearanceManager_DataRangeVectorBinding.h"
#include "Bindings/Util/OgreFastArrayBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef OgreFastArrayValueBinding<AppearanceManager::DataRange> DataRangeFastArrayBinding;
typedef OgreFastArrayValueBinding<AppearanceManager::DataRangePose> DataRangePoseFastArrayBinding;
typedef OgreFastArrayValueBinding<AppearanceManager::DataRangeVector> DataRangeVectorFastArrayBinding;

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

static int DataCategory_get_ranges(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataCategory is nil");
    return pushObject<DataRangeFastArrayBinding::ArrayType>(L, &inst->ranges, "Ogre::FastArray<DataRange>");
}

static int DataCategory_get_posesRanges(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataCategory is nil");
    return pushObject<DataRangePoseFastArrayBinding::ArrayType>(L, &inst->posesRanges, "Ogre::FastArray<DataRangePose>");
}

static int DataCategory_get_vectorRanges(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataCategory is nil");
    return pushObject<DataRangeVectorFastArrayBinding::ArrayType>(L, &inst->vectorRanges, "Ogre::FastArray<DataRangeVector>");
}

// --- Setters for DataCategory ---
static int DataCategory_set_value(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataCategory is nil");
    inst->value = (AppearanceManager::DataCategory::Enum)luaL_checkinteger(L, 2);
    return 0;
}

static int DataCategory_set_ranges(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataCategory is nil");
    if (lua_isnoneornil(L, 2))
    {
        inst->ranges.clear();
        return 0;
    }
    auto* src = DataRangeFastArrayBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set ranges must be Ogre::FastArray<DataRange>");
    inst->ranges = *src;
    return 0;
}

static int DataCategory_set_posesRanges(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataCategory is nil");
    if (lua_isnoneornil(L, 2))
    {
        inst->posesRanges.clear();
        return 0;
    }
    auto* src = DataRangePoseFastArrayBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set posesRanges must be Ogre::FastArray<DataRangePose>");
    inst->posesRanges = *src;
    return 0;
}

static int DataCategory_set_vectorRanges(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::DataCategory is nil");
    if (lua_isnoneornil(L, 2))
    {
        inst->vectorRanges.clear();
        return 0;
    }
    auto* src = DataRangeVectorFastArrayBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set vectorRanges must be Ogre::FastArray<DataRangeVector>");
    inst->vectorRanges = *src;
    return 0;
}

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
    registerGetter(L, "ranges", DataCategory_get_ranges);
    registerGetter(L, "posesRanges", DataCategory_get_posesRanges);
    registerGetter(L, "vectorRanges", DataCategory_get_vectorRanges);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "value", DataCategory_set_value);
    registerSetter(L, "ranges", DataCategory_set_ranges);
    registerSetter(L, "posesRanges", DataCategory_set_posesRanges);
    registerSetter(L, "vectorRanges", DataCategory_set_vectorRanges);
    lua_setfield(L, -2, "__setters");

    DataRangeFastArrayBinding::registerBinding(L, "Ogre::FastArray<DataRange>", AppearanceManager_DataRangeBinding::getMetatableName());
    DataRangePoseFastArrayBinding::registerBinding(L, "Ogre::FastArray<DataRangePose>", AppearanceManager_DataRangePoseBinding::getMetatableName());
    DataRangeVectorFastArrayBinding::registerBinding(L, "Ogre::FastArray<DataRangeVector>", AppearanceManager_DataRangeVectorBinding::getMetatableName());

    lua_pop(L, 1);
}

} // namespace KenshiLua
