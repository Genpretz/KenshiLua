#include "pch.h"
#include "kenshi\RootObject.h"
#include "DataObjectContainerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static DataObjectContainer* getB(lua_State* L, int idx)
{
    return checkObject<DataObjectContainer>(L, idx, DataObjectContainerBinding::getMetatableName());
}

// --- Getters for DataObjectContainer ---
static int DataObjectContainer_get_isStored(lua_State* L)
{
    DataObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "DataObjectContainer is nil");
    lua_pushboolean(L, b->isStored ? 1 : 0);
    return 1;
}

static int DataObjectContainer_get_objectDatas(lua_State* L)
{
    DataObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "DataObjectContainer is nil");
    // TODO: Unsupported type for objectDatas (GameDataContainer*)
    return luaL_error(L, "Unsupported property 'objectDatas' (type: GameDataContainer*)");
}

static int DataObjectContainer_get_datasFile(lua_State* L)
{
    DataObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "DataObjectContainer is nil");
    lua_pushstring(L, b->datasFile.c_str());
    return 1;
}

static int DataObjectContainer_get_selfType(lua_State* L)
{
    DataObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "DataObjectContainer is nil");
    lua_pushinteger(L, (lua_Integer)b->selfType);
    return 1;
}

// --- Setters for DataObjectContainer ---
static int DataObjectContainer_set_isStored(lua_State* L)
{
    DataObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "DataObjectContainer is nil");
    b->isStored = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DataObjectContainer_set_objectDatas(lua_State* L)
{
    DataObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "DataObjectContainer is nil");
    return luaL_error(L, "Read-only or unsupported setter type for objectDatas");
}

static int DataObjectContainer_set_datasFile(lua_State* L)
{
    DataObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "DataObjectContainer is nil");
    b->datasFile = luaL_checkstring(L, 2);
    return 0;
}

static int DataObjectContainer_set_selfType(lua_State* L)
{
    DataObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "DataObjectContainer is nil");
    b->selfType = (DataObjectContainer::GroupType)luaL_checkinteger(L, 2);
    return 0;
}

int DataObjectContainerBinding::_DESTRUCTOR(lua_State* L)
{
    DataObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "DataObjectContainer is nil");

    b->_DESTRUCTOR();
    return 0;
}

int DataObjectContainerBinding::getType(lua_State* L)
{
    DataObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "DataObjectContainer is nil");

    DataObjectContainer::GroupType result = b->getType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int DataObjectContainerBinding::destroyObjectDatas(lua_State* L)
{
    DataObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "DataObjectContainer is nil");

    b->destroyObjectDatas();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 155: DataObjectContainer* _CONSTRUCTOR(...) - overloaded method
  line 157: DataObjectContainer* _CONSTRUCTOR(...) - overloaded method
  line 161: void setupDataFile(...) - unsupported arg type
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
    lua_pushcfunction(L, DataObjectContainer_get_isStored);
    lua_setfield(L, -2, "isStored");
    lua_pushcfunction(L, DataObjectContainer_get_objectDatas);
    lua_setfield(L, -2, "objectDatas");
    lua_pushcfunction(L, DataObjectContainer_get_datasFile);
    lua_setfield(L, -2, "datasFile");
    lua_pushcfunction(L, DataObjectContainer_get_selfType);
    lua_setfield(L, -2, "selfType");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DataObjectContainer_set_isStored);
    lua_setfield(L, -2, "isStored");
    lua_pushcfunction(L, DataObjectContainer_set_objectDatas);
    lua_setfield(L, -2, "objectDatas");
    lua_pushcfunction(L, DataObjectContainer_set_datasFile);
    lua_setfield(L, -2, "datasFile");
    lua_pushcfunction(L, DataObjectContainer_set_selfType);
    lua_setfield(L, -2, "selfType");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua