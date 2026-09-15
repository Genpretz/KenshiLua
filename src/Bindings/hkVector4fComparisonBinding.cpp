#include "pch.h"
#include "kenshi\havok.h"
#include "hkVector4fComparisonBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static hkVector4fComparison* getInstance(lua_State* L, int idx)
{
    return checkObject<hkVector4fComparison>(L, idx, hkVector4fComparisonBinding::getMetatableName());
}

// --- Getters for hkVector4fComparison ---
// --- Setters for hkVector4fComparison ---
int hkVector4fComparisonBinding::getIndexOfLastComponentSet(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    int result = instance->getIndexOfLastComponentSet();
    lua_pushinteger(L, result);
    return 1;
}

int hkVector4fComparisonBinding::getIndexOfFirstComponentSet(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    int result = instance->getIndexOfFirstComponentSet();
    lua_pushinteger(L, result);
    return 1;
}

int hkVector4fComparisonBinding::allAreSet(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    unsigned int result = instance->allAreSet();
    lua_pushinteger(L, result);
    return 1;
}

int hkVector4fComparisonBinding::anyIsSet(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    if (lua_gettop(L) >= 2)
    {
        hkVector4fComparison::Mask m = (hkVector4fComparison::Mask)luaL_checkinteger(L, 2);
        unsigned int res = instance->anyIsSet(m);
        lua_pushinteger(L, res);
        return 1;
    }
    unsigned int res = instance->anyIsSet();
    lua_pushinteger(L, res);
    return 1;
}

int hkVector4fComparisonBinding::getMask(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    if (lua_gettop(L) >= 2)
    {
        hkVector4fComparison::Mask m = (hkVector4fComparison::Mask)luaL_checkinteger(L, 2);
        hkVector4fComparison::Mask res = instance->getMask(m);
        lua_pushinteger(L, (lua_Integer)res);
        return 1;
    }
    hkVector4fComparison::Mask res = instance->getMask();
    lua_pushinteger(L, (lua_Integer)res);
    return 1;
}

int hkVector4fComparisonBinding::getMaskForComponent(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    int i = (int)luaL_checkinteger(L, idx);
    hkVector4fComparison::Mask res = hkVector4fComparison::getMaskForComponent(i);
    lua_pushinteger(L, (lua_Integer)res);
    return 1;
}

int hkVector4fComparisonBinding::set(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    hkVector4fComparison::Mask m = (hkVector4fComparison::Mask)luaL_checkinteger(L, 2);
    instance->set(m);
    return 0;
}

int hkVector4fComparisonBinding::setAnd(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    hkVector4fComparison* a = getInstance(L, 2);
    hkVector4fComparison* b = getInstance(L, 3);
    if (!a || !b) return luaL_error(L, "Arguments 2 and 3 must be hkVector4fComparison");

    instance->setAnd(*a, *b);
    return 0;
}

int hkVector4fComparisonBinding::setAndNot(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    hkVector4fComparison* a = getInstance(L, 2);
    hkVector4fComparison* b = getInstance(L, 3);
    if (!a || !b) return luaL_error(L, "Arguments 2 and 3 must be hkVector4fComparison");

    instance->setAndNot(*a, *b);
    return 0;
}

int hkVector4fComparisonBinding::setXor(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    hkVector4fComparison* a = getInstance(L, 2);
    hkVector4fComparison* b = getInstance(L, 3);
    if (!a || !b) return luaL_error(L, "Arguments 2 and 3 must be hkVector4fComparison");

    instance->setXor(*a, *b);
    return 0;
}

int hkVector4fComparisonBinding::setOr(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    hkVector4fComparison* a = getInstance(L, 2);
    hkVector4fComparison* b = getInstance(L, 3);
    if (!a || !b) return luaL_error(L, "Arguments 2 and 3 must be hkVector4fComparison");

    instance->setOr(*a, *b);
    return 0;
}

int hkVector4fComparisonBinding::setNot(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    hkVector4fComparison* a = getInstance(L, 2);
    if (!a) return luaL_error(L, "Argument 2 must be hkVector4fComparison");

    instance->setNot(*a);
    return 0;
}

int hkVector4fComparisonBinding::setSelect(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    hkVector4fComparison* comp = getInstance(L, 2);
    hkVector4fComparison* trueVal = getInstance(L, 3);
    hkVector4fComparison* falseVal = getInstance(L, 4);
    if (!comp || !trueVal || !falseVal) return luaL_error(L, "Arguments 2, 3, and 4 must be hkVector4fComparison");

    instance->setSelect(*comp, *trueVal, *falseVal);
    return 0;
}

int hkVector4fComparisonBinding::create(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    hkVector4fComparison::Mask m = (hkVector4fComparison::Mask)luaL_optinteger(L, idx, hkVector4fComparison::MASK_NONE);
    hkVector4fComparison comp;
    comp.set(m);
    return pushValue<hkVector4fComparison>(L, comp, hkVector4fComparisonBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 44: const hkVector4fComparison convert(...) - static method
*/

/*
Skipped properties needing manual binding:
  line 62: m_mask (union __m128) - unsupported type
*/

int hkVector4fComparisonBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int hkVector4fComparisonBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.hkVector4fComparison object");
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) {
        lua_pushstring(L, "hkVector4fComparison(nil)");
        return 1;
    }
    char buf[64];
    sprintf_s(buf, "hkVector4fComparison(mask=0x%X)", (unsigned int)instance->getMask());
    lua_pushstring(L, buf);
    return 1;
}

void hkVector4fComparisonBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       hkVector4fComparisonBinding::gc },
        { "__tostring", hkVector4fComparisonBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getIndexOfLastComponentSet", hkVector4fComparisonBinding::getIndexOfLastComponentSet },
        { "getIndexOfFirstComponentSet", hkVector4fComparisonBinding::getIndexOfFirstComponentSet },
        { "allAreSet", hkVector4fComparisonBinding::allAreSet },
        { "anyIsSet", hkVector4fComparisonBinding::anyIsSet },
        { "getMask", hkVector4fComparisonBinding::getMask },
        { "getMaskForComponent", hkVector4fComparisonBinding::getMaskForComponent },
        { "set", hkVector4fComparisonBinding::set },
        { "setAnd", hkVector4fComparisonBinding::setAnd },
        { "setAndNot", hkVector4fComparisonBinding::setAndNot },
        { "setXor", hkVector4fComparisonBinding::setXor },
        { "setOr", hkVector4fComparisonBinding::setOr },
        { "setNot", hkVector4fComparisonBinding::setNot },
        { "setSelect", hkVector4fComparisonBinding::setSelect },
        { "create", hkVector4fComparisonBinding::create },
        { 0, 0 }
    };

    registerClass(
        L, 
        hkVector4fComparisonBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, hkVector4fComparisonBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    pushGlobalTable(L, "hkVector4fComparison");
    registerStaticMethod(L, "create", hkVector4fComparisonBinding::create);
    registerStaticMethod(L, "getMaskForComponent", hkVector4fComparisonBinding::getMaskForComponent);
    lua_setglobal(L, "hkVector4fComparison");
}

} // namespace KenshiLua