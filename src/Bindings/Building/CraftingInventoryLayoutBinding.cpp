#include "pch.h"
#include "Bindings/CraftingInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/CraftingBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static CraftingInventoryLayout* getS(lua_State* L, int idx)
{
    return checkObject<CraftingInventoryLayout>(L, idx, CraftingInventoryLayoutBinding::getMetatableName());
}

int CraftingInventoryLayoutBinding::gc(lua_State* L) { return noopGc(L); }

int CraftingInventoryLayoutBinding::tostring(lua_State* L)
{
    CraftingInventoryLayout* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int CraftingInventoryLayoutBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, CraftingInventoryLayoutBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    CraftingInventoryLayout* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "queueBtn") == 0) { lua_pushinteger(L, (lua_Integer)s->queueBtn); return 1; }
    if (strcmp(key, "craftingName") == 0) { lua_pushinteger(L, (lua_Integer)s->craftingName); return 1; }
    if (strcmp(key, "outputType") == 0) { lua_pushinteger(L, (lua_Integer)s->outputType); return 1; }

    lua_pushnil(L);
    return 1;
}

int CraftingInventoryLayoutBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    CraftingInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingInventoryLayout is nil");

    // TODO MyGUI::Button* queueBtn; unsupported __newindex type from header line 35
    // TODO MyGUI::TextBox* craftingName; unsupported __newindex type from header line 36
    if (strcmp(key, "outputType") == 0) { s->outputType = (itemType)luaL_checkinteger(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int CraftingInventoryLayoutBinding::refresh(lua_State* L)
{
    CraftingInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingInventoryLayout is nil");

    s->refresh();
    return 0;
}

int CraftingInventoryLayoutBinding::setOutputType(lua_State* L)
{
    CraftingInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingInventoryLayout is nil");

    itemType type = (itemType)luaL_checkinteger(L, 2);
    s->setOutputType(type);
    return 0;
}

int CraftingInventoryLayoutBinding::setCraftingName(lua_State* L)
{
    CraftingInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingInventoryLayout is nil");

    std::string name = luaL_checkstring(L, 2);
    s->setCraftingName(name);
    return 0;
}

int CraftingInventoryLayoutBinding::getQueueButton(lua_State* L)
{
    CraftingInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingInventoryLayout is nil");

    MyGUI::Button result = s->getQueueButton();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CraftingInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    CraftingInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingInventoryLayout is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 28: CraftingInventoryLayout* _CONSTRUCTOR(...) - unsupported return type
  line 29: void setupSections(...) - unsupported arg type
  line 30: void _NV_setupSections(...) - unsupported arg type
*/

void CraftingInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CraftingInventoryLayoutBinding::gc },
        { "__tostring", CraftingInventoryLayoutBinding::tostring },
        { "__index",    CraftingInventoryLayoutBinding::index },
        { "__newindex", CraftingInventoryLayoutBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "refresh", CraftingInventoryLayoutBinding::refresh },
        { "setOutputType", CraftingInventoryLayoutBinding::setOutputType },
        { "setCraftingName", CraftingInventoryLayoutBinding::setCraftingName },
        { "getQueueButton", CraftingInventoryLayoutBinding::getQueueButton },
        { "_DESTRUCTOR", CraftingInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, CraftingInventoryLayoutBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua