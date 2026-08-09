#include "pch.h"
#include "kenshi\GameData.h"
#include "ObjectInstanceBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef GameData::ObjectInstance ObjectInstance;

static ObjectInstance* getInstance(lua_State* L, int idx)
{
    return checkObject<ObjectInstance>(L, idx, ObjectInstanceBinding::getMetatableName());
}

// --- Getters for ObjectInstance ---
static int ObjectInstance_get_pos(lua_State* L)
{
    ObjectInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ObjectInstance is nil");
    pushVector3(L, instance->pos);
    return 1;
}

static int ObjectInstance_get_rot(lua_State* L)
{
    ObjectInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ObjectInstance is nil");
    pushQuaternion(L, instance->rot);
    return 1;
}

static int ObjectInstance_get_refID(lua_State* L)
{
    ObjectInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ObjectInstance is nil");
    lua_pushstring(L, instance->refID.c_str());
    return 1;
}

static int ObjectInstance_get_created(lua_State* L)
{
    ObjectInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ObjectInstance is nil");
    lua_pushinteger(L, instance->created);
    return 1;
}

static int ObjectInstance_get_modified(lua_State* L)
{
    ObjectInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ObjectInstance is nil");
    lua_pushinteger(L, instance->modified);
    return 1;
}

// --- Setters for ObjectInstance ---
static int ObjectInstance_set_pos(lua_State* L)
{
    ObjectInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ObjectInstance is nil");
    readVector3(L, 2, instance->pos);
    return 0;
}

static int ObjectInstance_set_rot(lua_State* L)
{
    ObjectInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ObjectInstance is nil");
    readQuaternion(L, 2, instance->rot);
    return 0;
}

static int ObjectInstance_set_refID(lua_State* L)
{
    ObjectInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ObjectInstance is nil");
    instance->refID = luaL_checkstring(L, 2);
    return 0;
}

static int ObjectInstance_set_created(lua_State* L)
{
    ObjectInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ObjectInstance is nil");
    instance->created = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int ObjectInstance_set_modified(lua_State* L)
{
    ObjectInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ObjectInstance is nil");
    instance->modified = (short)luaL_checkinteger(L, 2);
    return 0;
}

int ObjectInstanceBinding::_DESTRUCTOR(lua_State* L)
{
    ObjectInstance* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ObjectInstance is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 140: ObjectInstance* _CONSTRUCTOR(...) - overloaded method
  line 142: ObjectInstance* _CONSTRUCTOR(...) - overloaded method
  line 149: const GameData::ObjectInstance& operator=(...) - operator
  line 150: void updateInstancedObjectAttachedDatas(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 148: stateIDs (lektor<std::string >) - unsupported type
*/

int ObjectInstanceBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ObjectInstanceBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ObjectInstance object");
    return 1;
}

void ObjectInstanceBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ObjectInstanceBinding::gc },
        { "__tostring", ObjectInstanceBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ObjectInstanceBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        ObjectInstanceBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ObjectInstanceBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "pos", ObjectInstance_get_pos);
    registerGetter(L, "rot", ObjectInstance_get_rot);
    registerGetter(L, "refID", ObjectInstance_get_refID);
    registerGetter(L, "created", ObjectInstance_get_created);
    registerGetter(L, "modified", ObjectInstance_get_modified);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "pos", ObjectInstance_set_pos);
    registerSetter(L, "rot", ObjectInstance_set_rot);
    registerSetter(L, "refID", ObjectInstance_set_refID);
    registerSetter(L, "created", ObjectInstance_set_created);
    registerSetter(L, "modified", ObjectInstance_set_modified);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua