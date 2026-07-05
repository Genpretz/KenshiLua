#include "pch.h"
#include "kenshi\ModInfo.h"
#include "ModInfoBinding.h"
#include "Lua/BindingHelpers.h"
// #include "Bindings/Ogre/GeneralAllocatedObjectBinding.h"

namespace KenshiLua
{

static ModInfo* getInstance(lua_State* L, int idx)
{
    return checkObject<ModInfo>(L, idx, ModInfoBinding::getMetatableName());
}

// --- Getters for ModInfo ---
static int ModInfo_get_name(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int ModInfo_get_file(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");
    lua_pushstring(L, instance->file.c_str());
    return 1;
}

static int ModInfo_get_path(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");
    lua_pushstring(L, instance->path.c_str());
    return 1;
}

static int ModInfo_get_isWorkshop(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");
    lua_pushboolean(L, instance->isWorkshop ? 1 : 0);
    return 1;
}

static int ModInfo_get_isBaseMod(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");
    lua_pushboolean(L, instance->isBaseMod ? 1 : 0);
    return 1;
}

static int ModInfo_get_leveldataFolder(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");
    lua_pushstring(L, instance->leveldataFolder.c_str());
    return 1;
}

static int ModInfo_get_header(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");
    // TODO: Unsupported type for header (GameDataHeader)
    lua_pushnil(L);
    return 1;
}

// --- Setters for ModInfo ---
static int ModInfo_set_name(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

static int ModInfo_set_file(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");
    instance->file = luaL_checkstring(L, 2);
    return 0;
}

static int ModInfo_set_path(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");
    instance->path = luaL_checkstring(L, 2);
    return 0;
}

static int ModInfo_set_isWorkshop(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");
    instance->isWorkshop = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ModInfo_set_isBaseMod(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");
    instance->isBaseMod = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ModInfo_set_leveldataFolder(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");
    instance->leveldataFolder = luaL_checkstring(L, 2);
    return 0;
}

static int ModInfo_set_header(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");
    return luaL_error(L, "Read-only or unsupported setter type for header");
}

// --- Methods for ModInfo
int ModInfoBinding::_DESTRUCTOR(lua_State* L)
{
    ModInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ModInfo is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ModInfoBinding::gc(lua_State* L)
{
    return 0;
}

int ModInfoBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ModInfo object");
    return 1;
}

void ModInfoBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ModInfoBinding::gc },
        { "__tostring", ModInfoBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ModInfoBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        ModInfoBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ModInfoBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ModInfo_get_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, ModInfo_get_file);
    lua_setfield(L, -2, "file");
    lua_pushcfunction(L, ModInfo_get_path);
    lua_setfield(L, -2, "path");
    lua_pushcfunction(L, ModInfo_get_isWorkshop);
    lua_setfield(L, -2, "isWorkshop");
    lua_pushcfunction(L, ModInfo_get_isBaseMod);
    lua_setfield(L, -2, "isBaseMod");
    lua_pushcfunction(L, ModInfo_get_leveldataFolder);
    lua_setfield(L, -2, "leveldataFolder");
    lua_pushcfunction(L, ModInfo_get_header);
    lua_setfield(L, -2, "header");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ModInfo_set_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, ModInfo_set_file);
    lua_setfield(L, -2, "file");
    lua_pushcfunction(L, ModInfo_set_path);
    lua_setfield(L, -2, "path");
    lua_pushcfunction(L, ModInfo_set_isWorkshop);
    lua_setfield(L, -2, "isWorkshop");
    lua_pushcfunction(L, ModInfo_set_isBaseMod);
    lua_setfield(L, -2, "isBaseMod");
    lua_pushcfunction(L, ModInfo_set_leveldataFolder);
    lua_setfield(L, -2, "leveldataFolder");
    lua_pushcfunction(L, ModInfo_set_header);
    lua_setfield(L, -2, "header");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setPlayableParent(L, ModInfoBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
