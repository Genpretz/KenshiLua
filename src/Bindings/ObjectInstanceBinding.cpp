#include "pch.h"
#include "kenshi\GameData.h"
#include "ObjectInstanceBinding.h"
#include "Lua/BindingHelpers.h"

typedef GameData::ObjectInstance ObjectInstance;

namespace KenshiLua
{

static ObjectInstance* getB(lua_State* L, int idx)
{
    return checkObject<ObjectInstance>(L, idx, ObjectInstanceBinding::getMetatableName());
}

// --- Getters for ObjectInstance ---
static int ObjectInstance_get_pos(lua_State* L)
{
    ObjectInstance* b = getB(L, 1);
    if (!b) return luaL_error(L, "ObjectInstance is nil");
    pushVector3(L, b->pos);
    return 1;
}

static int ObjectInstance_get_rot(lua_State* L)
{
    ObjectInstance* b = getB(L, 1);
    if (!b) return luaL_error(L, "ObjectInstance is nil");
    pushQuaternion(L, b->rot);
    return 1;
}

static int ObjectInstance_get_refID(lua_State* L)
{
    ObjectInstance* b = getB(L, 1);
    if (!b) return luaL_error(L, "ObjectInstance is nil");
    lua_pushstring(L, b->refID.c_str());
    return 1;
}

static int ObjectInstance_get_created(lua_State* L)
{
    ObjectInstance* b = getB(L, 1);
    if (!b) return luaL_error(L, "ObjectInstance is nil");
    lua_pushinteger(L, b->created);
    return 1;
}

static int ObjectInstance_get_modified(lua_State* L)
{
    ObjectInstance* b = getB(L, 1);
    if (!b) return luaL_error(L, "ObjectInstance is nil");
    lua_pushinteger(L, b->modified);
    return 1;
}

static int ObjectInstance_get_stateIDs(lua_State* L)
{
    ObjectInstance* b = getB(L, 1);
    if (!b) return luaL_error(L, "ObjectInstance is nil");
    // TODO: Unsupported type for stateIDs (lektor<std::string >)
    return luaL_error(L, "Unsupported property 'stateIDs' (type: lektor<std::string >)");
}

// --- Setters for ObjectInstance ---
static int ObjectInstance_set_pos(lua_State* L)
{
    ObjectInstance* b = getB(L, 1);
    if (!b) return luaL_error(L, "ObjectInstance is nil");
    readVector3(L, 2, b->pos);
    return 0;
}

static int ObjectInstance_set_rot(lua_State* L)
{
    ObjectInstance* b = getB(L, 1);
    if (!b) return luaL_error(L, "ObjectInstance is nil");
    readQuaternion(L, 2, b->rot);
    return 0;
}

static int ObjectInstance_set_refID(lua_State* L)
{
    ObjectInstance* b = getB(L, 1);
    if (!b) return luaL_error(L, "ObjectInstance is nil");
    b->refID = luaL_checkstring(L, 2);
    return 0;
}

static int ObjectInstance_set_created(lua_State* L)
{
    ObjectInstance* b = getB(L, 1);
    if (!b) return luaL_error(L, "ObjectInstance is nil");
    b->created = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int ObjectInstance_set_modified(lua_State* L)
{
    ObjectInstance* b = getB(L, 1);
    if (!b) return luaL_error(L, "ObjectInstance is nil");
    b->modified = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int ObjectInstance_set_stateIDs(lua_State* L)
{
    ObjectInstance* b = getB(L, 1);
    if (!b) return luaL_error(L, "ObjectInstance is nil");
    return luaL_error(L, "Read-only or unsupported setter type for stateIDs");
}

int ObjectInstanceBinding::_DESTRUCTOR(lua_State* L)
{
    ObjectInstance* b = getB(L, 1);
    if (!b) return luaL_error(L, "ObjectInstance is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 140: ObjectInstance* _CONSTRUCTOR(...) - overloaded method
  line 142: ObjectInstance* _CONSTRUCTOR(...) - overloaded method
  line 149: const GameData::ObjectInstance& operator=(...) - operator
  line 150: void updateInstancedObjectAttachedDatas(...) - unsupported arg type
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
    lua_pushcfunction(L, ObjectInstance_get_pos);
    lua_setfield(L, -2, "pos");
    lua_pushcfunction(L, ObjectInstance_get_rot);
    lua_setfield(L, -2, "rot");
    lua_pushcfunction(L, ObjectInstance_get_refID);
    lua_setfield(L, -2, "refID");
    lua_pushcfunction(L, ObjectInstance_get_created);
    lua_setfield(L, -2, "created");
    lua_pushcfunction(L, ObjectInstance_get_modified);
    lua_setfield(L, -2, "modified");
    lua_pushcfunction(L, ObjectInstance_get_stateIDs);
    lua_setfield(L, -2, "stateIDs");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ObjectInstance_set_pos);
    lua_setfield(L, -2, "pos");
    lua_pushcfunction(L, ObjectInstance_set_rot);
    lua_setfield(L, -2, "rot");
    lua_pushcfunction(L, ObjectInstance_set_refID);
    lua_setfield(L, -2, "refID");
    lua_pushcfunction(L, ObjectInstance_set_created);
    lua_setfield(L, -2, "created");
    lua_pushcfunction(L, ObjectInstance_set_modified);
    lua_setfield(L, -2, "modified");
    lua_pushcfunction(L, ObjectInstance_set_stateIDs);
    lua_setfield(L, -2, "stateIDs");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
