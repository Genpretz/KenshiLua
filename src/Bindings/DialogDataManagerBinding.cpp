#include "pch.h"
#include "kenshi\Dialogue.h"
#include "DialogDataManagerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static DialogDataManager* getB(lua_State* L, int idx)
{
    return checkObject<DialogDataManager>(L, idx, DialogDataManagerBinding::getMetatableName());
}

// --- Getters for DialogDataManager ---
// --- Setters for DialogDataManager ---
/*
Skipped methods needing manual binding:
  line 438: DialogLineData* _createData(...) - static method
  line 439: void initialise(...) - static method
  line 440: void save(...) - static method
  line 441: void load(...) - static method
  line 442: void newGameReset(...) - static method
  line 443: DialogLineData* getData(...) - static method
*/

int DialogDataManagerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DialogDataManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DialogDataManager object");
    return 1;
}

void DialogDataManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogDataManagerBinding::gc },
        { "__tostring", DialogDataManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        DialogDataManagerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DialogDataManagerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua