#include "pch.h"
#include "Bindings/ResearchBuildingInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/ResearchBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static ResearchBuildingInventoryLayout* getS(lua_State* L, int idx)
{
    return checkObject<ResearchBuildingInventoryLayout>(L, idx, ResearchBuildingInventoryLayoutBinding::getMetatableName());
}

int ResearchBuildingInventoryLayoutBinding::gc(lua_State* L) { return noopGc(L); }

int ResearchBuildingInventoryLayoutBinding::tostring(lua_State* L)
{
    ResearchBuildingInventoryLayout* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int ResearchBuildingInventoryLayoutBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, ResearchBuildingInventoryLayoutBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    ResearchBuildingInventoryLayout* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "researchButton") == 0) { lua_pushinteger(L, (lua_Integer)s->researchButton); return 1; }

    lua_pushnil(L);
    return 1;
}

int ResearchBuildingInventoryLayoutBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    ResearchBuildingInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "ResearchBuildingInventoryLayout is nil");

    // TODO MyGUI::Button* researchButton; unsupported __newindex type from header line 17

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int ResearchBuildingInventoryLayoutBinding::getResearchButton(lua_State* L)
{
    ResearchBuildingInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "ResearchBuildingInventoryLayout is nil");

    MyGUI::Widget result = s->getResearchButton();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ResearchBuildingInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    ResearchBuildingInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "ResearchBuildingInventoryLayout is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 13: ResearchBuildingInventoryLayout* _CONSTRUCTOR(...) - unsupported return type
  line 14: void setupSections(...) - unsupported arg type
  line 15: void _NV_setupSections(...) - unsupported arg type
*/

void ResearchBuildingInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ResearchBuildingInventoryLayoutBinding::gc },
        { "__tostring", ResearchBuildingInventoryLayoutBinding::tostring },
        { "__index",    ResearchBuildingInventoryLayoutBinding::index },
        { "__newindex", ResearchBuildingInventoryLayoutBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getResearchButton", ResearchBuildingInventoryLayoutBinding::getResearchButton },
        { "_DESTRUCTOR", ResearchBuildingInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, ResearchBuildingInventoryLayoutBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua