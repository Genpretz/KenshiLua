#include "pch.h"
#include "Bindings/Building/BuildMaterialBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/Building.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static Building::ConstructionState::BuildMaterial* getB(lua_State* L, int idx)
{
    return checkObject<Building::ConstructionState::BuildMaterial>(L, idx, BuildMaterialBinding::getMetatableName());
}

int BuildMaterialBinding::gc(lua_State* L) { return noopGc(L); }

int BuildMaterialBinding::tostring(lua_State* L)
{
    Building::ConstructionState::BuildMaterial* b = getB(L, 1);
    return genericTostringPtr(L, "%s", b);
}

int BuildMaterialBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, BuildMaterialBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    Building::ConstructionState::BuildMaterial* b = getB(L, 1);
    if (!b) { lua_pushnil(L); return 1; }

    if (strcmp(key, "mat") == 0) { return pushObject<GameData>(L, b->mat, GameDataBinding::getMetatableName()); }
    if (strcmp(key, "buildMatsTotal") == 0) { lua_pushnumber(L, b->buildMatsTotal); return 1; }
    if (strcmp(key, "amountOfMaterials") == 0) { lua_pushnumber(L, b->amountOfMaterials); return 1; }

    lua_pushnil(L);
    return 1;
}

int BuildMaterialBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    Building::ConstructionState::BuildMaterial* b = getB(L, 1);
    if (!b) return luaL_error(L, "BuildMaterial is nil");

    // TODO GameData* mat; unsupported __newindex type from header line 120
    if (strcmp(key, "buildMatsTotal") == 0) { b->buildMatsTotal = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "amountOfMaterials") == 0) { b->amountOfMaterials = (float)luaL_checknumber(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int BuildMaterialBinding::getMaterialsBarProgress(lua_State* L)
{
    Building::ConstructionState::BuildMaterial* b = getB(L, 1);
    if (!b) return luaL_error(L, "BuildMaterial is nil");

    float result = b->getMaterialsBarProgress();
    lua_pushnumber(L, result);
    return 1;
}

int BuildMaterialBinding::getNumRemaining(lua_State* L)
{
    Building::ConstructionState::BuildMaterial* b = getB(L, 1);
    if (!b) return luaL_error(L, "BuildMaterial is nil");

    float result = b->getNumRemaining();
    lua_pushnumber(L, result);
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
    registerClass(L, BuildMaterialBinding::getMetatableName(), meta, methods, BuildMaterialBinding::index, BuildMaterialBinding::newindex);
}

} // namespace KenshiLua