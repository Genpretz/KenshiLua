#include "pch.h"
#include "Bindings/Character_CarryMsgBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Character::CarryMsg* getInstance(lua_State* L, int idx)
{
    return checkObject<Character::CarryMsg>(L, idx, Character_CarryMsgBinding::getMetatableName());
}

// --- Getters for CarryMsg ---
static int CarryMsg_get_on(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Character::CarryMsg is nil");
    lua_pushboolean(L, inst->on ? 1 : 0);
    return 1;
}

static int CarryMsg_get_rag(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Character::CarryMsg is nil");
    lua_pushboolean(L, inst->rag ? 1 : 0);
    return 1;
}

static int CarryMsg_get_hull(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Character::CarryMsg is nil");
    lua_pushboolean(L, inst->hull ? 1 : 0);
    return 1;
}

// --- Setters for CarryMsg ---
static int CarryMsg_set_on(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Character::CarryMsg is nil");
    inst->on = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CarryMsg_set_rag(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Character::CarryMsg is nil");
    inst->rag = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CarryMsg_set_hull(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Character::CarryMsg is nil");
    inst->hull = lua_toboolean(L, 2) != 0;
    return 0;
}

int Character_CarryMsgBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (Character::CarryMsg*)::operator new(sizeof(Character::CarryMsg));
    ::new ((void*)obj) Character::CarryMsg();
    if (lua_gettop(L) >= 1)
        obj->on = lua_toboolean(L, 1) != 0;
    if (lua_gettop(L) >= 2)
        obj->rag = lua_toboolean(L, 2) != 0;
    if (lua_gettop(L) >= 3)
        obj->hull = lua_toboolean(L, 3) != 0;
    return pushObjectOwned<Character::CarryMsg>(L, obj, getMetatableName());
}

int Character_CarryMsgBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Character::CarryMsg is nil");
    inst->~CarryMsg();
    return 0;
}

int Character_CarryMsgBinding::gc(lua_State* L)
{
    return 0;
}

int Character_CarryMsgBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Character_CarryMsg object");
    return 1;
}

int Character_CarryMsgBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->on == b->on && a->rag == b->rag && a->hull == b->hull)) ? 1 : 0);
    return 1;
}

void Character_CarryMsgBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "on", CarryMsg_get_on);
    registerGetter(L, "rag", CarryMsg_get_rag);
    registerGetter(L, "hull", CarryMsg_get_hull);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "on", CarryMsg_set_on);
    registerSetter(L, "rag", CarryMsg_set_rag);
    registerSetter(L, "hull", CarryMsg_set_hull);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
