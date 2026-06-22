#include "pch.h"
#include "Bindings/Dialogue/DialogChoiceListBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Dialogue.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static DialogChoiceList* getS(lua_State* L, int idx)
{
    return checkObject<DialogChoiceList>(L, idx, DialogChoiceListBinding::getMetatableName());
}

int DialogChoiceListBinding::gc(lua_State* L) { return noopGc(L); }

int DialogChoiceListBinding::tostring(lua_State* L)
{
    DialogChoiceList* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int DialogChoiceListBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, DialogChoiceListBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    DialogChoiceList* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO lektor<DialogLineData*> conversationChoices; unsupported __index type from header line 262

    lua_pushnil(L);
    return 1;
}

int DialogChoiceListBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    DialogChoiceList* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogChoiceList is nil");

    // TODO lektor<DialogLineData*> conversationChoices; unsupported __newindex type from header line 262

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int DialogChoiceListBinding::_DESTRUCTOR(lua_State* L)
{
    DialogChoiceList* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogChoiceList is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 265: DialogChoiceList* _CONSTRUCTOR(...) - unsupported return type
  line 268: void add(...) - unsupported arg type
*/

void DialogChoiceListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogChoiceListBinding::gc },
        { "__tostring", DialogChoiceListBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", DialogChoiceListBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, DialogChoiceListBinding::getMetatableName(), meta, methods, DialogChoiceListBinding::index, DialogChoiceListBinding::newindex);
}

} // namespace KenshiLua