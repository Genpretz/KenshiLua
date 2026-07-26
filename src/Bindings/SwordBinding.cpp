#include "pch.h"
#include "kenshi\Gear.h"
#include "SwordBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/WeaponBinding.h"

namespace KenshiLua
{

static Sword* getInstance(lua_State* L, int idx)
{
    return checkObject<Sword>(L, idx, SwordBinding::getMetatableName());
}

// --- Getters for Sword ---
static int Sword_get_cutDamage(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");
    lua_pushnumber(L, instance->cutDamage);
    return 1;
}

static int Sword_get_bluntDamage(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");
    lua_pushnumber(L, instance->bluntDamage);
    return 1;
}

static int Sword_get_minCutDamage(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");
    lua_pushnumber(L, instance->minCutDamage);
    return 1;
}

static int Sword_get_modDefence(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");
    lua_pushinteger(L, instance->modDefence);
    return 1;
}

static int Sword_get_modIndoors(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");
    lua_pushinteger(L, instance->modIndoors);
    return 1;
}

// --- Setters for Sword ---
static int Sword_set_cutDamage(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");
    instance->cutDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Sword_set_bluntDamage(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");
    instance->bluntDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Sword_set_minCutDamage(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");
    instance->minCutDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Sword_set_modDefence(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");
    instance->modDefence = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Sword_set_modIndoors(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");
    instance->modIndoors = (int)luaL_checkinteger(L, 2);
    return 0;
}

int SwordBinding::_CONSTRUCTOR(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");

    GameData* baseData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* companyData = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* materialData = checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
    hand _handle = *checkObject<hand>(L, 5, handBinding::getMetatableName());
    int _level = (int)luaL_checkinteger(L, 6);
    Sword* result = instance->_CONSTRUCTOR(baseData, companyData, materialData, _handle, _level);
    return pushObject<Sword>(L, result, SwordBinding::getMetatableName());
}

int SwordBinding::getClassType(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");

    itemType result = instance->getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int SwordBinding::_NV_getClassType(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");

    itemType result = instance->_NV_getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int SwordBinding::isSword(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");

    Sword* result = instance->isSword();
    return pushObject<Sword>(L, result, SwordBinding::getMetatableName());
}

int SwordBinding::_NV_isSword(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");

    Sword* result = instance->_NV_isSword();
    return pushObject<Sword>(L, result, SwordBinding::getMetatableName());
}

int SwordBinding::setupStats(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");

    int _level = (int)luaL_checkinteger(L, 2);
    GameData* baseData = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* companyData = checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
    GameData* materialData = checkObject<GameData>(L, 5, GameDataBinding::getMetatableName());
    instance->setupStats(_level, baseData, companyData, materialData);
    return 0;
}

int SwordBinding::getSkillModIndoors(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");

    int result = instance->getSkillModIndoors();
    lua_pushinteger(L, result);
    return 1;
}

int SwordBinding::_NV_getSkillModIndoors(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");

    int result = instance->_NV_getSkillModIndoors();
    lua_pushinteger(L, result);
    return 1;
}

int SwordBinding::_DESTRUCTOR(lua_State* L)
{
    Sword* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Sword is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 92: void getTooltipData1(...) - unsupported arg type
  line 93: void _NV_getTooltipData1(...) - unsupported arg type
  line 94: void getTooltipData2(...) - unsupported arg type
  line 95: void _NV_getTooltipData2(...) - unsupported arg type
*/

int SwordBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SwordBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Sword object");
    return 1;
}

void SwordBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SwordBinding::gc },
        { "__tostring", SwordBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", SwordBinding::_CONSTRUCTOR },
        { "getClassType", SwordBinding::getClassType },
        { "_NV_getClassType", SwordBinding::_NV_getClassType },
        { "isSword", SwordBinding::isSword },
        { "_NV_isSword", SwordBinding::_NV_isSword },
        { "setupStats", SwordBinding::setupStats },
        { "getSkillModIndoors", SwordBinding::getSkillModIndoors },
        { "_NV_getSkillModIndoors", SwordBinding::_NV_getSkillModIndoors },
        { "_DESTRUCTOR", SwordBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        SwordBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SwordBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "cutDamage", Sword_get_cutDamage);
    registerGetter(L, "bluntDamage", Sword_get_bluntDamage);
    registerGetter(L, "minCutDamage", Sword_get_minCutDamage);
    registerGetter(L, "modDefence", Sword_get_modDefence);
    registerGetter(L, "modIndoors", Sword_get_modIndoors);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "cutDamage", Sword_set_cutDamage);
    registerSetter(L, "bluntDamage", Sword_set_bluntDamage);
    registerSetter(L, "minCutDamage", Sword_set_minCutDamage);
    registerSetter(L, "modDefence", Sword_set_modDefence);
    registerSetter(L, "modIndoors", Sword_set_modIndoors);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Weapon
    setMetatableParent(L, SwordBinding::getMetatableName(), WeaponBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua