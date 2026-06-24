#include "pch.h"
#include <kenshi/Building/Building.h>
#include "BuildMaterialBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef Building::ConstructionState::BuildMaterial BuildMaterial;

static BuildMaterial* getInstance(lua_State* L, int idx)
{
    return checkObject<BuildMaterial>(L, idx, BuildMaterialBinding::getMetatableName());
}

// --- Getters for BuildMaterial ---
static int BuildMaterial_get_mat(lua_State* L)
{
    BuildMaterial* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildMaterial is nil");
    return pushObject<GameData>(L, instance->mat, GameDataBinding::getMetatableName());
}

static int BuildMaterial_get_buildMatsTotal(lua_State* L)
{
    BuildMaterial* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildMaterial is nil");
    lua_pushnumber(L, instance->buildMatsTotal);
    return 1;
}

static int BuildMaterial_get_amountOfMaterials(lua_State* L)
{
    BuildMaterial* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildMaterial is nil");
    lua_pushnumber(L, instance->amountOfMaterials);
    return 1;
}

// --- Setters for BuildMaterial ---
static int BuildMaterial_set_mat(lua_State* L)
{
    BuildMaterial* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildMaterial is nil");
    return luaL_error(L, "Read-only or unsupported setter type for mat");
}

static int BuildMaterial_set_buildMatsTotal(lua_State* L)
{
    BuildMaterial* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildMaterial is nil");
    instance->buildMatsTotal = (float)luaL_checknumber(L, 2);
    return 0;
}

static int BuildMaterial_set_amountOfMaterials(lua_State* L)
{
    BuildMaterial* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildMaterial is nil");
    instance->amountOfMaterials = (float)luaL_checknumber(L, 2);
    return 0;
}

int BuildMaterialBinding::getMaterialsBarProgress(lua_State* L)
{
    BuildMaterial* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildMaterial is nil");

    float result = instance->getMaterialsBarProgress();
    lua_pushnumber(L, result);
    return 1;
}

int BuildMaterialBinding::getNumRemaining(lua_State* L)
{
    BuildMaterial* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildMaterial is nil");

    float result = instance->getNumRemaining();
    lua_pushnumber(L, result);
    return 1;
}

int BuildMaterialBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BuildMaterialBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BuildMaterial object");
    return 1;
}

void BuildMaterialBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildMaterialBinding::gc },
        { "__tostring", BuildMaterialBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getMaterialsBarProgress", BuildMaterialBinding::getMaterialsBarProgress },
        { "getNumRemaining", BuildMaterialBinding::getNumRemaining },
        { 0, 0 }
    };

    registerClass(
        L, 
        BuildMaterialBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BuildMaterialBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, BuildMaterial_get_mat);
    lua_setfield(L, -2, "mat");
    lua_pushcfunction(L, BuildMaterial_get_buildMatsTotal);
    lua_setfield(L, -2, "buildMatsTotal");
    lua_pushcfunction(L, BuildMaterial_get_amountOfMaterials);
    lua_setfield(L, -2, "amountOfMaterials");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, BuildMaterial_set_mat);
    lua_setfield(L, -2, "mat");
    lua_pushcfunction(L, BuildMaterial_set_buildMatsTotal);
    lua_setfield(L, -2, "buildMatsTotal");
    lua_pushcfunction(L, BuildMaterial_set_amountOfMaterials);
    lua_setfield(L, -2, "amountOfMaterials");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}
}