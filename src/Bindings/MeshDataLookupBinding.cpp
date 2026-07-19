#include "pch.h"
#include "kenshi\Appearance.h"
#include "MeshDataLookupBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MeshDataLookup* getB(lua_State* L, int idx)
{
    return checkObject<MeshDataLookup>(L, idx, MeshDataLookupBinding::getMetatableName());
}

// --- Getters for MeshDataLookup ---
static int MeshDataLookup_get_boneAssignments(lua_State* L)
{
    MeshDataLookup* b = getB(L, 1);
    if (!b) return luaL_error(L, "MeshDataLookup is nil");
    // TODO: Unsupported type for boneAssignments (boost::unordered::unordered_map<Ogre::IdString, lektor<lektor<int> >, boost::hash<Ogre::IdString>, std::equal_to<Ogre::IdString>, Ogre::STLAllocator<std::pair<Ogre::IdString const, lektor<lektor<int> > >, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'boneAssignments' (type: boost::unordered::unordered_map<Ogre::IdString, lektor<lektor<int> >, boost::hash<Ogre::IdString>, std::equal_to<Ogre::IdString>, Ogre::STLAllocator<std::pair<Ogre::IdString const, lektor<lektor<int> > >, Ogre::GeneralAllocPolicy > >)");
}

static int MeshDataLookup_get_vertCount(lua_State* L)
{
    MeshDataLookup* b = getB(L, 1);
    if (!b) return luaL_error(L, "MeshDataLookup is nil");
    // TODO: Unsupported type for vertCount (unsigned __int64)
    return luaL_error(L, "Unsupported property 'vertCount' (type: unsigned __int64)");
}

static int MeshDataLookup_get_verts(lua_State* L)
{
    MeshDataLookup* b = getB(L, 1);
    if (!b) return luaL_error(L, "MeshDataLookup is nil");
    // TODO: Unsupported type for verts (Ogre::Vector3*)
    return luaL_error(L, "Unsupported property 'verts' (type: Ogre::Vector3*)");
}

static int MeshDataLookup_get_uvs(lua_State* L)
{
    MeshDataLookup* b = getB(L, 1);
    if (!b) return luaL_error(L, "MeshDataLookup is nil");
    // TODO: Unsupported type for uvs (Ogre::Vector2*)
    return luaL_error(L, "Unsupported property 'uvs' (type: Ogre::Vector2*)");
}

// --- Setters for MeshDataLookup ---
static int MeshDataLookup_set_boneAssignments(lua_State* L)
{
    MeshDataLookup* b = getB(L, 1);
    if (!b) return luaL_error(L, "MeshDataLookup is nil");
    return luaL_error(L, "Read-only or unsupported setter type for boneAssignments");
}

static int MeshDataLookup_set_vertCount(lua_State* L)
{
    MeshDataLookup* b = getB(L, 1);
    if (!b) return luaL_error(L, "MeshDataLookup is nil");
    return luaL_error(L, "Read-only or unsupported setter type for vertCount");
}

static int MeshDataLookup_set_verts(lua_State* L)
{
    MeshDataLookup* b = getB(L, 1);
    if (!b) return luaL_error(L, "MeshDataLookup is nil");
    return luaL_error(L, "Read-only or unsupported setter type for verts");
}

static int MeshDataLookup_set_uvs(lua_State* L)
{
    MeshDataLookup* b = getB(L, 1);
    if (!b) return luaL_error(L, "MeshDataLookup is nil");
    return luaL_error(L, "Read-only or unsupported setter type for uvs");
}

int MeshDataLookupBinding::_DESTRUCTOR(lua_State* L)
{
    MeshDataLookup* b = getB(L, 1);
    if (!b) return luaL_error(L, "MeshDataLookup is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 40: MeshDataLookup* _CONSTRUCTOR(...) - unsupported return type
  line 47: void init(...) - unsupported arg type
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
        { "_DESTRUCTOR", MeshDataLookupBinding::_DESTRUCTOR },
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
    lua_pushcfunction(L, MeshDataLookup_get_boneAssignments);
    lua_setfield(L, -2, "boneAssignments");
    lua_pushcfunction(L, MeshDataLookup_get_vertCount);
    lua_setfield(L, -2, "vertCount");
    lua_pushcfunction(L, MeshDataLookup_get_verts);
    lua_setfield(L, -2, "verts");
    lua_pushcfunction(L, MeshDataLookup_get_uvs);
    lua_setfield(L, -2, "uvs");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, MeshDataLookup_set_boneAssignments);
    lua_setfield(L, -2, "boneAssignments");
    lua_pushcfunction(L, MeshDataLookup_set_vertCount);
    lua_setfield(L, -2, "vertCount");
    lua_pushcfunction(L, MeshDataLookup_set_verts);
    lua_setfield(L, -2, "verts");
    lua_pushcfunction(L, MeshDataLookup_set_uvs);
    lua_setfield(L, -2, "uvs");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
