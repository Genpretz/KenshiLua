#include "pch.h"
#include "kenshi\Appearance.h"
#include "MeshDataLookupBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MeshDataLookup* getInstance(lua_State* L, int idx)
{
    return checkObject<MeshDataLookup>(L, idx, MeshDataLookupBinding::getMetatableName());
}

// --- Getters for MeshDataLookup ---
static int MeshDataLookup_get_verts(lua_State* L)
{
    MeshDataLookup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MeshDataLookup is nil");
    lua_pushlightuserdata(L, (void*)instance->verts);
    return 1;
}

static int MeshDataLookup_get_uvs(lua_State* L)
{
    MeshDataLookup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MeshDataLookup is nil");
    lua_pushlightuserdata(L, (void*)instance->uvs);
    return 1;
}

// --- Setters for MeshDataLookup ---
static int MeshDataLookup_set_verts(lua_State* L)
{
    MeshDataLookup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MeshDataLookup is nil");
    instance->verts = (Ogre::Vector3*)lua_touserdata(L, 2);
    return 0;
}

static int MeshDataLookup_set_uvs(lua_State* L)
{
    MeshDataLookup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MeshDataLookup is nil");
    instance->uvs = (Ogre::Vector2*)lua_touserdata(L, 2);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 47: void init(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - MeshDataLookup_get_verts: Ogre::Vector3* (unbound pointer)
  - MeshDataLookup_get_uvs: Ogre::Vector2* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 43: boneAssignments (boost::unordered::unordered_map<Ogre::IdString, lektor<lektor<int> >, boost::hash<Ogre::IdString>, std::equal_to<Ogre::IdString>, Ogre::STLAllocator<std::pair<Ogre::IdString const, lektor<lektor<int> > >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 44: vertCount (unsigned __int64) - unsupported type
*/

int MeshDataLookupBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MeshDataLookupBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MeshDataLookup object");
    return 1;
}

void MeshDataLookupBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MeshDataLookupBinding::gc },
        { "__tostring", MeshDataLookupBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        MeshDataLookupBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MeshDataLookupBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "verts", MeshDataLookup_get_verts);
    registerGetter(L, "uvs", MeshDataLookup_get_uvs);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "verts", MeshDataLookup_set_verts);
    registerSetter(L, "uvs", MeshDataLookup_set_uvs);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, MeshDataLookupBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua