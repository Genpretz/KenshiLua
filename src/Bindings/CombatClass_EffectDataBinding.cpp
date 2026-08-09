#include "pch.h"
#include "Bindings/CombatClass_EffectDataBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/CombatClass.h>

#include "Bindings/GameDataBinding.h"

#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

static CombatClass::EffectData* getInstance(lua_State* L, int idx)
{
    return checkObject<CombatClass::EffectData>(L, idx, CombatClass_EffectDataBinding::getMetatableName());
}

// --- Getters for EffectData ---
static int EffectData_get_data(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::EffectData is nil");
    return pushObject<GameData>(L, inst->data, GameDataBinding::getMetatableName());
}

static int EffectData_get_character(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::EffectData is nil");
    return HandBinding::push(L, inst->character);
}

static int EffectData_get_boneName(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::EffectData is nil");
    lua_pushstring(L, inst->boneName.c_str());

    return 1;
}

static int EffectData_get_pos(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::EffectData is nil");
    pushVector3(L, inst->pos);
    return 1;
}

static int EffectData_get_rot(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::EffectData is nil");
    pushQuaternion(L, inst->rot);
    return 1;
}

// --- Setters for EffectData ---
static int EffectData_set_data(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::EffectData is nil");
    inst->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int EffectData_set_character(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::EffectData is nil");
    auto* val = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (val) inst->character = *val;
    return 0;
}

static int EffectData_set_boneName(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::EffectData is nil");
    inst->boneName = luaL_checkstring(L, 2);
    return 0;
}

static int EffectData_set_pos(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::EffectData is nil");
    readVector3(L, 2, inst->pos);
    return 0;
}

static int EffectData_set_rot(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::EffectData is nil");
    readQuaternion(L, 2, inst->rot);
    return 0;
}

int CombatClass_EffectDataBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (CombatClass::EffectData*)::operator new(sizeof(CombatClass::EffectData));
    ::new ((void*)obj) CombatClass::EffectData();
    if (lua_gettop(L) >= 4)
        readVector3(L, 4, obj->pos);
    return pushObject<CombatClass::EffectData>(L, obj, getMetatableName());
}

int CombatClass_EffectDataBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::EffectData is nil");
    inst->~EffectData();
    return 0;
}

int CombatClass_EffectDataBinding::gc(lua_State* L)
{
    return 0;
}

int CombatClass_EffectDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CombatClass_EffectData object");
    return 1;
}

int CombatClass_EffectDataBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->data == b->data && a->character == b->character && a->boneName == b->boneName && a->pos == b->pos && a->rot == b->rot)) ? 1 : 0);
    return 1;
}

void CombatClass_EffectDataBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "data", EffectData_get_data);
    registerGetter(L, "character", EffectData_get_character);
    registerGetter(L, "boneName", EffectData_get_boneName);
    registerGetter(L, "pos", EffectData_get_pos);
    registerGetter(L, "rot", EffectData_get_rot);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "data", EffectData_set_data);
    registerSetter(L, "character", EffectData_set_character);
    registerSetter(L, "boneName", EffectData_set_boneName);
    registerSetter(L, "pos", EffectData_set_pos);
    registerSetter(L, "rot", EffectData_set_rot);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
