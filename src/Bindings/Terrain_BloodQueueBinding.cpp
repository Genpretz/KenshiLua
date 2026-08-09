#include "pch.h"
#include "Bindings/Terrain_BloodQueueBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Terrain::BloodQueue* getInstance(lua_State* L, int idx)
{
    return checkObject<Terrain::BloodQueue>(L, idx, Terrain_BloodQueueBinding::getMetatableName());
}

// --- Getters for BloodQueue ---
static int BloodQueue_get_patch(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::BloodQueue is nil");
    lua_pushinteger(L, inst->patch);
    return 1;
}

static int BloodQueue_get_sector(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::BloodQueue is nil");
    lua_pushinteger(L, inst->sector);
    return 1;
}

static int BloodQueue_get_depth(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::BloodQueue is nil");
    lua_pushinteger(L, inst->depth);
    return 1;
}

static int BloodQueue_get_texture(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::BloodQueue is nil");
    lua_pushlightuserdata(L, (void*)&inst->texture);
    return 1;
}

// --- Setters for BloodQueue ---
static int BloodQueue_set_patch(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::BloodQueue is nil");
    inst->patch = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int BloodQueue_set_sector(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::BloodQueue is nil");
    inst->sector = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int BloodQueue_set_depth(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::BloodQueue is nil");
    inst->depth = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int BloodQueue_set_texture(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::BloodQueue is nil");
    // Ogre::SharedPtr<Ogre::Texture> is unbound - read-only
    return luaL_error(L, "texture is read-only (Ogre::SharedPtr<Ogre::Texture> is unbound)");
    return 0;
}

int Terrain_BloodQueueBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (Terrain::BloodQueue*)::operator new(sizeof(Terrain::BloodQueue));
    ::new ((void*)obj) Terrain::BloodQueue();
    if (lua_gettop(L) >= 1)
        obj->patch = (unsigned int)luaL_checkinteger(L, 1);
    if (lua_gettop(L) >= 2)
        obj->sector = (int)luaL_checkinteger(L, 2);
    if (lua_gettop(L) >= 3)
        obj->depth = (int)luaL_checkinteger(L, 3);
    return pushObject<Terrain::BloodQueue>(L, obj, getMetatableName());
}

int Terrain_BloodQueueBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::BloodQueue is nil");
    inst->~BloodQueue();
    return 0;
}

int Terrain_BloodQueueBinding::gc(lua_State* L)
{
    return 0;
}

int Terrain_BloodQueueBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Terrain_BloodQueue object");
    return 1;
}

int Terrain_BloodQueueBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->patch == b->patch && a->sector == b->sector && a->depth == b->depth && a->texture == b->texture)) ? 1 : 0);
    return 1;
}

void Terrain_BloodQueueBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", _CONSTRUCTOR },
        { "_DESTRUCTOR",  _DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "patch", BloodQueue_get_patch);
    registerGetter(L, "sector", BloodQueue_get_sector);
    registerGetter(L, "depth", BloodQueue_get_depth);
    registerGetter(L, "texture", BloodQueue_get_texture);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "patch", BloodQueue_set_patch);
    registerSetter(L, "sector", BloodQueue_set_sector);
    registerSetter(L, "depth", BloodQueue_set_depth);
    registerSetter(L, "texture", BloodQueue_set_texture);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
