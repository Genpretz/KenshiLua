#include "pch.h"
#include "Bindings/Dialogue/DialogDataManagerBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Dialogue.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static DialogDataManager* getS(lua_State* L, int idx)
{
    return checkObject<DialogDataManager>(L, idx, DialogDataManagerBinding::getMetatableName());
}

int DialogDataManagerBinding::gc(lua_State* L) { return noopGc(L); }

int DialogDataManagerBinding::tostring(lua_State* L)
{
    DialogDataManager* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int DialogDataManagerBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, DialogDataManagerBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    DialogDataManager* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }


    lua_pushnil(L);
    return 1;
}

int DialogDataManagerBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    DialogDataManager* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogDataManager is nil");


    return luaL_error(L, "unknown or read-only field '%s'", key);
}

/*
Skipped methods needing manual binding:
  line 438: DialogLineData* _createData(...) - static method
  line 439: void initialise(...) - static method
  line 440: void save(...) - static method
  line 441: void load(...) - static method
  line 442: void newGameReset(...) - static method
  line 443: DialogLineData* getData(...) - static method
*/

void DialogDataManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogDataManagerBinding::gc },
        { "__tostring", DialogDataManagerBinding::tostring },
        { "__index",    DialogDataManagerBinding::index },
        { "__newindex", DialogDataManagerBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };
    registerClass(L, DialogDataManagerBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua