#include "pch.h"
#include "kenshi\RootObject.h"
#include "DataObjectContainerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/RootObjectContainerBinding.h"

namespace KenshiLua
{

static DataObjectContainer* getInstance(lua_State* L, int idx)
{
    return checkObject<DataObjectContainer>(L, idx, DataObjectContainerBinding::getMetatableName());
}

// --- Getters for DataObjectContainer ---
static int DataObjectContainer_get_isStored(lua_State* L)
{
    DataObjectContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataObjectContainer is nil");
    lua_pushboolean(L, instance->isStored ? 1 : 0);
    return 1;
}

static int DataObjectContainer_get_objectDatas(lua_State* L)
{
    DataObjectContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataObjectContainer is nil");
    return pushObject<GameDataContainer>(L, instance->objectDatas, GameDataContainerBinding::getMetatableName());
}

static int DataObjectContainer_get_datasFile(lua_State* L)
{
    DataObjectContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataObjectContainer is nil");
    lua_pushstring(L, instance->datasFile.c_str());
    return 1;
}

static int DataObjectContainer_get_selfType(lua_State* L)
{
    DataObjectContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataObjectContainer is nil");
    lua_pushinteger(L, (lua_Integer)instance->selfType);
    return 1;
}

// --- Setters for DataObjectContainer ---
static int DataObjectContainer_set_isStored(lua_State* L)
{
    DataObjectContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataObjectContainer is nil");
    instance->isStored = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DataObjectContainer_set_objectDatas(lua_State* L)
{
    DataObjectContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataObjectContainer is nil");
    instance->objectDatas = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    return 0;
}

static int DataObjectContainer_set_datasFile(lua_State* L)
{
    DataObjectContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataObjectContainer is nil");
    instance->datasFile = luaL_checkstring(L, 2);
    return 0;
}

static int DataObjectContainer_set_selfType(lua_State* L)
{
    DataObjectContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataObjectContainer is nil");
    instance->selfType = (DataObjectContainer::GroupType)luaL_checkinteger(L, 2);
    return 0;
}

int DataObjectContainerBinding::_DESTRUCTOR(lua_State* L)
{
    DataObjectContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataObjectContainer is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int DataObjectContainerBinding::getType(lua_State* L)
{
    DataObjectContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataObjectContainer is nil");

    DataObjectContainer::GroupType result = instance->getType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int DataObjectContainerBinding::setupDataFile(lua_State* L)
{
    DataObjectContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataObjectContainer is nil");

    const std::string filename = luaL_checkstring(L, 2);
    GameDataContainer* container = checkObject<GameDataContainer>(L, 3, GameDataContainerBinding::getMetatableName());
    instance->setupDataFile(filename, container);
    return 0;
}

int DataObjectContainerBinding::destroyObjectDatas(lua_State* L)
{
    DataObjectContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataObjectContainer is nil");

    instance->destroyObjectDatas();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 155: DataObjectContainer* _CONSTRUCTOR(...) - overloaded method
  line 157: DataObjectContainer* _CONSTRUCTOR(...) - overloaded method
  line 167: bool loadFromDisk(...) - unsupported arg type
  line 168: bool _NV_loadFromDisk(...) - unsupported arg type
*/

int DataObjectContainerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DataObjectContainerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DataObjectContainer object");
    return 1;
}

void DataObjectContainerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DataObjectContainerBinding::gc },
        { "__tostring", DataObjectContainerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", DataObjectContainerBinding::_DESTRUCTOR },
        { "getType", DataObjectContainerBinding::getType },
        { "setupDataFile", DataObjectContainerBinding::setupDataFile },
        { "destroyObjectDatas", DataObjectContainerBinding::destroyObjectDatas },
        { 0, 0 }
    };

    registerClass(
        L, 
        DataObjectContainerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DataObjectContainerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "isStored", DataObjectContainer_get_isStored);
    registerGetter(L, "objectDatas", DataObjectContainer_get_objectDatas);
    registerGetter(L, "datasFile", DataObjectContainer_get_datasFile);
    registerGetter(L, "selfType", DataObjectContainer_get_selfType);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "isStored", DataObjectContainer_set_isStored);
    registerSetter(L, "objectDatas", DataObjectContainer_set_objectDatas);
    registerSetter(L, "datasFile", DataObjectContainer_set_datasFile);
    registerSetter(L, "selfType", DataObjectContainer_set_selfType);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua