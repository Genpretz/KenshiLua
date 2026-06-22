#include "pch.h"
#include "Bindings/Building/GenericInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/UseableStuff.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static GenericInventoryLayout* getS(lua_State* L, int idx)
{
    return checkObject<GenericInventoryLayout>(L, idx, GenericInventoryLayoutBinding::getMetatableName());
}

int GenericInventoryLayoutBinding::gc(lua_State* L) { return noopGc(L); }

int GenericInventoryLayoutBinding::tostring(lua_State* L)
{
    GenericInventoryLayout* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int GenericInventoryLayoutBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, GenericInventoryLayoutBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    GenericInventoryLayout* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "arrangeButton") == 0) { lua_pushinteger(L, (lua_Integer)s->arrangeButton); return 1; }

    lua_pushnil(L);
    return 1;
}

int GenericInventoryLayoutBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    GenericInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "GenericInventoryLayout is nil");

    // TODO MyGUI::Widget* arrangeButton; unsupported __newindex type from header line 16

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int GenericInventoryLayoutBinding::setSize(lua_State* L)
{
    GenericInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "GenericInventoryLayout is nil");

    int slotsW = (int)luaL_checkinteger(L, 2);
    int slotsH = (int)luaL_checkinteger(L, 3);
    bool hasArrange = lua_toboolean(L, 4) != 0;
    bool hasType = lua_toboolean(L, 5) != 0;
    s->setSize(slotsW, slotsH, hasArrange, hasType);
    return 0;
}

int GenericInventoryLayoutBinding::_NV_setSize(lua_State* L)
{
    GenericInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "GenericInventoryLayout is nil");

    int slotsW = (int)luaL_checkinteger(L, 2);
    int slotsH = (int)luaL_checkinteger(L, 3);
    bool hasArrange = lua_toboolean(L, 4) != 0;
    bool hasType = lua_toboolean(L, 5) != 0;
    s->_NV_setSize(slotsW, slotsH, hasArrange, hasType);
    return 0;
}

int GenericInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    GenericInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "GenericInventoryLayout is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 11: GenericInventoryLayout* _CONSTRUCTOR(...) - overloaded method
  line 13: GenericInventoryLayout* _CONSTRUCTOR(...) - overloaded method
*/

void GenericInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GenericInventoryLayoutBinding::gc },
        { "__tostring", GenericInventoryLayoutBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setSize", GenericInventoryLayoutBinding::setSize },
        { "_NV_setSize", GenericInventoryLayoutBinding::_NV_setSize },
        { "_DESTRUCTOR", GenericInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, GenericInventoryLayoutBinding::getMetatableName(), meta, methods, GenericInventoryLayoutBinding::index, GenericInventoryLayoutBinding::newindex);
}

} // namespace KenshiLua