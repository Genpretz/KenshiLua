#include "pch.h"
#include "Bindings/BuildInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/ProductionBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static BuildInventoryLayout* getS(lua_State* L, int idx)
{
    return checkObject<BuildInventoryLayout>(L, idx, BuildInventoryLayoutBinding::getMetatableName());
}

int BuildInventoryLayoutBinding::gc(lua_State* L) { return noopGc(L); }

int BuildInventoryLayoutBinding::tostring(lua_State* L)
{
    BuildInventoryLayout* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int BuildInventoryLayoutBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, BuildInventoryLayoutBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    BuildInventoryLayout* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "input1NameText") == 0) { lua_pushinteger(L, (lua_Integer)s->input1NameText); return 1; }
    if (strcmp(key, "input2NameText") == 0) { lua_pushinteger(L, (lua_Integer)s->input2NameText); return 1; }
    if (strcmp(key, "input1StatusText") == 0) { lua_pushinteger(L, (lua_Integer)s->input1StatusText); return 1; }
    if (strcmp(key, "input2StatusText") == 0) { lua_pushinteger(L, (lua_Integer)s->input2StatusText); return 1; }
    if (strcmp(key, "input1ItemIcon") == 0) { lua_pushinteger(L, (lua_Integer)s->input1ItemIcon); return 1; }
    if (strcmp(key, "input2ItemIcon") == 0) { lua_pushinteger(L, (lua_Integer)s->input2ItemIcon); return 1; }
    if (strcmp(key, "outputNameText") == 0) { lua_pushinteger(L, (lua_Integer)s->outputNameText); return 1; }
    if (strcmp(key, "outputItemIcon") == 0) { lua_pushinteger(L, (lua_Integer)s->outputItemIcon); return 1; }
    if (strcmp(key, "input1Panel") == 0) { lua_pushinteger(L, (lua_Integer)s->input1Panel); return 1; }
    if (strcmp(key, "input2Panel") == 0) { lua_pushinteger(L, (lua_Integer)s->input2Panel); return 1; }
    if (strcmp(key, "input1Progress") == 0) { lua_pushinteger(L, (lua_Integer)s->input1Progress); return 1; }
    if (strcmp(key, "input2Progress") == 0) { lua_pushinteger(L, (lua_Integer)s->input2Progress); return 1; }
    if (strcmp(key, "outputProgress") == 0) { lua_pushinteger(L, (lua_Integer)s->outputProgress); return 1; }
    if (strcmp(key, "inputs") == 0) { lua_pushinteger(L, s->inputs); return 1; }
    if (strcmp(key, "outputs") == 0) { lua_pushinteger(L, s->outputs); return 1; }
    if (strcmp(key, "input1Item") == 0) { return pushObject<Item>(L, s->input1Item, ItemBinding::getMetatableName()); }
    if (strcmp(key, "input2Item") == 0) { return pushObject<Item>(L, s->input2Item, ItemBinding::getMetatableName()); }
    if (strcmp(key, "outputItem") == 0) { return pushObject<Item>(L, s->outputItem, ItemBinding::getMetatableName()); }

    lua_pushnil(L);
    return 1;
}

int BuildInventoryLayoutBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    BuildInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildInventoryLayout is nil");

    // TODO MyGUI::TextBox* input1NameText; unsupported __newindex type from header line 21
    // TODO MyGUI::TextBox* input2NameText; unsupported __newindex type from header line 22
    // TODO MyGUI::TextBox* input1StatusText; unsupported __newindex type from header line 23
    // TODO MyGUI::TextBox* input2StatusText; unsupported __newindex type from header line 24
    // TODO MyGUI::ImageBox* input1ItemIcon; unsupported __newindex type from header line 25
    // TODO MyGUI::ImageBox* input2ItemIcon; unsupported __newindex type from header line 26
    // TODO MyGUI::TextBox* outputNameText; unsupported __newindex type from header line 27
    // TODO MyGUI::ImageBox* outputItemIcon; unsupported __newindex type from header line 28
    // TODO MyGUI::Widget* input1Panel; unsupported __newindex type from header line 29
    // TODO MyGUI::Widget* input2Panel; unsupported __newindex type from header line 30
    // TODO MyGUI::ProgressBar* input1Progress; unsupported __newindex type from header line 31
    // TODO MyGUI::ProgressBar* input2Progress; unsupported __newindex type from header line 32
    // TODO MyGUI::ProgressBar* outputProgress; unsupported __newindex type from header line 33
    if (strcmp(key, "inputs") == 0) { s->inputs = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "outputs") == 0) { s->outputs = (int)luaL_checkinteger(L, 3); return 0; }
    // TODO Item* input1Item; unsupported __newindex type from header line 36
    // TODO Item* input2Item; unsupported __newindex type from header line 37
    // TODO Item* outputItem; unsupported __newindex type from header line 38

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int BuildInventoryLayoutBinding::setInput(lua_State* L)
{
    BuildInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildInventoryLayout is nil");

    int inputIndex = (int)luaL_checkinteger(L, 2);
    std::string name = luaL_checkstring(L, 3);
    std::string status = luaL_checkstring(L, 4);
    s->setInput(inputIndex, name, status);
    return 0;
}

int BuildInventoryLayoutBinding::setOutput(lua_State* L)
{
    BuildInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildInventoryLayout is nil");

    std::string name = luaL_checkstring(L, 2);
    s->setOutput(name);
    return 0;
}

int BuildInventoryLayoutBinding::setInputProgress(lua_State* L)
{
    BuildInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildInventoryLayout is nil");

    int inputIdx = (int)luaL_checkinteger(L, 2);
    float progress = (float)luaL_checknumber(L, 3);
    s->setInputProgress(inputIdx, progress);
    return 0;
}

int BuildInventoryLayoutBinding::setInputEnabled(lua_State* L)
{
    BuildInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildInventoryLayout is nil");

    int inputIdx = (int)luaL_checkinteger(L, 2);
    bool value = lua_toboolean(L, 3) != 0;
    s->setInputEnabled(inputIdx, value);
    return 0;
}

int BuildInventoryLayoutBinding::setOutputProgress(lua_State* L)
{
    BuildInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildInventoryLayout is nil");

    float progress = (float)luaL_checknumber(L, 2);
    s->setOutputProgress(progress);
    return 0;
}

int BuildInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    BuildInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildInventoryLayout is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 11: BuildInventoryLayout* _CONSTRUCTOR(...) - unsupported return type
  line 12: void setupSections(...) - unsupported arg type
  line 13: void _NV_setupSections(...) - unsupported arg type
  line 19: void setInputItem(...) - unsupported arg type
  line 20: void setOutputItem(...) - unsupported arg type
*/

void BuildInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildInventoryLayoutBinding::gc },
        { "__tostring", BuildInventoryLayoutBinding::tostring },
        { "__index",    BuildInventoryLayoutBinding::index },
        { "__newindex", BuildInventoryLayoutBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setInput", BuildInventoryLayoutBinding::setInput },
        { "setOutput", BuildInventoryLayoutBinding::setOutput },
        { "setInputProgress", BuildInventoryLayoutBinding::setInputProgress },
        { "setInputEnabled", BuildInventoryLayoutBinding::setInputEnabled },
        { "setOutputProgress", BuildInventoryLayoutBinding::setOutputProgress },
        { "_DESTRUCTOR", BuildInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, BuildInventoryLayoutBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua