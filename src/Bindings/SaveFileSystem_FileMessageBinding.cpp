#include "pch.h"
#include "Bindings/SaveFileSystem_FileMessageBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static SaveFileSystem::FileMessage* getInstance(lua_State* L, int idx)
{
    return checkObject<SaveFileSystem::FileMessage>(L, idx, SaveFileSystem_FileMessageBinding::getMetatableName());
}

// --- Getters for FileMessage ---
static int FileMessage_get_mode(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveFileSystem::FileMessage is nil");
    lua_pushinteger(L, (lua_Integer)inst->mode);

    return 1;
}

static int FileMessage_get_source(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveFileSystem::FileMessage is nil");
    lua_pushstring(L, inst->source.c_str());

    return 1;
}

static int FileMessage_get_dest(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveFileSystem::FileMessage is nil");
    lua_pushstring(L, inst->dest.c_str());

    return 1;
}

// --- Setters for FileMessage ---
static int FileMessage_set_mode(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveFileSystem::FileMessage is nil");
    inst->mode = (SaveFileSystem::MessageType)luaL_checkinteger(L, 2);
    return 0;
}

static int FileMessage_set_source(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveFileSystem::FileMessage is nil");
    inst->source = luaL_checkstring(L, 2);
    return 0;
}

static int FileMessage_set_dest(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "SaveFileSystem::FileMessage is nil");
    inst->dest = luaL_checkstring(L, 2);
    return 0;
}

int SaveFileSystem_FileMessageBinding::gc(lua_State* L)
{
    return 0;
}

int SaveFileSystem_FileMessageBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SaveFileSystem_FileMessage object");
    return 1;
}

int SaveFileSystem_FileMessageBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->mode == b->mode && a->source == b->source && a->dest == b->dest)) ? 1 : 0);
    return 1;
}

void SaveFileSystem_FileMessageBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "mode", FileMessage_get_mode);
    registerGetter(L, "source", FileMessage_get_source);
    registerGetter(L, "dest", FileMessage_get_dest);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "mode", FileMessage_set_mode);
    registerSetter(L, "source", FileMessage_set_source);
    registerSetter(L, "dest", FileMessage_set_dest);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
