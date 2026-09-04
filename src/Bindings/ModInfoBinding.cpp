#include "pch.h"
#include <kenshi/ModInfo.h>
#include "ModInfoBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataHeaderBinding.h"

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
    return pushObject<GameDataHeader>(L, &instance->header, GameDataHeaderBinding::getMetatableName());
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
    GameDataHeader* val = checkObject<GameDataHeader>(L, 2, GameDataHeaderBinding::getMetatableName());
    if (!val) return luaL_error(L, "Argument 2 to set 'header' must be GameDataHeader");
    instance->header = *val;
    return 0;
}

// --- Methods for ModInfo
/*
Skipped methods needing manual binding:
  line 21: bool getLocale(...) - non-string reference arg
  line 24: ModInfo& operator=(...) - operator
*/

int ModInfoBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
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
    registerGetter(L, "name", ModInfo_get_name);
    registerGetter(L, "file", ModInfo_get_file);
    registerGetter(L, "path", ModInfo_get_path);
    registerGetter(L, "isWorkshop", ModInfo_get_isWorkshop);
    registerGetter(L, "isBaseMod", ModInfo_get_isBaseMod);
    registerGetter(L, "leveldataFolder", ModInfo_get_leveldataFolder);
    registerGetter(L, "header", ModInfo_get_header);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "name", ModInfo_set_name);
    registerSetter(L, "file", ModInfo_set_file);
    registerSetter(L, "path", ModInfo_set_path);
    registerSetter(L, "isWorkshop", ModInfo_set_isWorkshop);
    registerSetter(L, "isBaseMod", ModInfo_set_isBaseMod);
    registerSetter(L, "leveldataFolder", ModInfo_set_leveldataFolder);
    registerSetter(L, "header", ModInfo_set_header);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
