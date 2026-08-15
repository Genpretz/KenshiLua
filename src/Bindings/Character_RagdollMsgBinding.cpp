#include "pch.h"
#include "Bindings/Character_RagdollMsgBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
static Character::RagdollMsg* getInstance(lua_State* L, int idx)
{
    return checkObject<Character::RagdollMsg>(L, idx, Character_RagdollMsgBinding::getMetatableName());
}

// --- Getters for Character::RagdollMsg ---
static int RagdollMsg_get_on(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Character::RagdollMsg is nil");
    lua_pushboolean(L, inst->on ? 1 : 0);
    return 1;
}

static int RagdollMsg_get_part(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Character::RagdollMsg is nil");
    lua_pushinteger(L, (lua_Integer)inst->part);
    return 1;
}

// --- Setters for Character::RagdollMsg ---
static int RagdollMsg_set_on(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Character::RagdollMsg is nil");
    inst->on = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RagdollMsg_set_part(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Character::RagdollMsg is nil");
    inst->part = (RagdollPart::Enum)luaL_checkinteger(L, 2);
    return 0;
}

int Character_RagdollMsgBinding::_CONSTRUCTOR(lua_State* L)
{
    bool on = lua_toboolean(L, 1) != 0;
    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 2);
    
    auto* obj = (Character::RagdollMsg*)::operator new(sizeof(Character::RagdollMsg));
    ::new ((void*)obj) Character::RagdollMsg(on, part);
    return pushObjectOwned<Character::RagdollMsg>(L, obj, getMetatableName());
}

int Character_RagdollMsgBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Character::RagdollMsg is nil");
    inst->~RagdollMsg();
    return 0;
}

int Character_RagdollMsgBinding::gc(lua_State* L)
{
    return 0;
}

int Character_RagdollMsgBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Character_RagdollMsg object");
    return 1;
}

int Character_RagdollMsgBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (*a == *b)) ? 1 : 0);
    return 1;
}

void Character_RagdollMsgBinding::registerBinding(lua_State* L)
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
    lua_newtable(L);
    registerGetter(L, "on", RagdollMsg_get_on);
    registerGetter(L, "part", RagdollMsg_get_part);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "on", RagdollMsg_set_on);
    registerSetter(L, "part", RagdollMsg_set_part);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
}

