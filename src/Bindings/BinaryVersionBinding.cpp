#include "pch.h"
#include "kenshi/Kenshi.h"
#include "Bindings/BinaryVersionBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static KenshiLib::BinaryVersion* getInstance(lua_State* L, int idx)
{
    return checkObject<KenshiLib::BinaryVersion>(L, idx, BinaryVersionBinding::getMetatableName());
}

// --- Methods for BinaryVersion ---

int BinaryVersionBinding::GetPlatform(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "BinaryVersion is nil");

    lua_pushinteger(L, (lua_Integer)inst->GetPlatform());
    return 1;
}

int BinaryVersionBinding::GetPlatformStr(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "BinaryVersion is nil");

    std::string result = inst->GetPlatformStr();
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}

int BinaryVersionBinding::GetBinaryName(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "BinaryVersion is nil");

    std::string result = inst->GetBinaryName();
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}

int BinaryVersionBinding::ToString(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "BinaryVersion is nil");

    std::string result = inst->ToString();
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}

int BinaryVersionBinding::GetVersion(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "BinaryVersion is nil");

    std::string result = inst->GetVersion();
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}

int BinaryVersionBinding::GetKenshiVersion(lua_State* L)
{
    KenshiLib::BinaryVersion ver = KenshiLib::GetKenshiVersion();
    return pushValue<KenshiLib::BinaryVersion>(L, ver, BinaryVersionBinding::getMetatableName());
}

int BinaryVersionBinding::create(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    KenshiLib::BinaryVersion::KenshiPlatform platform = (KenshiLib::BinaryVersion::KenshiPlatform)luaL_checkinteger(L, idx);
    const char* version = luaL_checkstring(L, idx + 1);

    KenshiLib::BinaryVersion ver(platform, std::string(version));
    return pushValue<KenshiLib::BinaryVersion>(L, ver, BinaryVersionBinding::getMetatableName());
}

int BinaryVersionBinding::gc(lua_State* L)
{
    return 0;
}

int BinaryVersionBinding::tostring(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (inst)
    {
        std::string str = inst->ToString();
        lua_pushlstring(L, str.c_str(), str.size());
    }
    else
    {
        lua_pushstring(L, "KenshiLua.BinaryVersion object");
    }
    return 1;
}

int BinaryVersionBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (*a == *b)) ? 1 : 0);
    return 1;
}

int BinaryVersionBinding::operator_lt(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (*a < *b)) ? 1 : 0);
    return 1;
}

void BinaryVersionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       BinaryVersionBinding::operator_eq },
        { "__lt",       BinaryVersionBinding::operator_lt },
        { "__gc",       BinaryVersionBinding::gc },
        { "__tostring", BinaryVersionBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "GetPlatform",       BinaryVersionBinding::GetPlatform },
        { "GetPlatformStr",    BinaryVersionBinding::GetPlatformStr },
        { "GetBinaryName",     BinaryVersionBinding::GetBinaryName },
        { "ToString",          BinaryVersionBinding::ToString },
        { "GetVersion",        BinaryVersionBinding::GetVersion },
        { "getPlatform",       BinaryVersionBinding::GetPlatform },
        { "getPlatformStr",    BinaryVersionBinding::GetPlatformStr },
        { "getBinaryName",     BinaryVersionBinding::GetBinaryName },
        { "toString",          BinaryVersionBinding::ToString },
        { "getVersion",        BinaryVersionBinding::GetVersion },
        { "GetKenshiVersion",  BinaryVersionBinding::GetKenshiVersion },
        { "getKenshiVersion",  BinaryVersionBinding::GetKenshiVersion },
        { "new",               BinaryVersionBinding::create },
        { 0, 0 }
    };

    registerClass(
        L, 
        BinaryVersionBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BinaryVersionBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "platform", BinaryVersionBinding::GetPlatform);
    registerGetter(L, "platformStr", BinaryVersionBinding::GetPlatformStr);
    registerGetter(L, "binaryName", BinaryVersionBinding::GetBinaryName);
    registerGetter(L, "version", BinaryVersionBinding::GetVersion);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1); // Pop metatable

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "GetKenshiVersion", BinaryVersionBinding::GetKenshiVersion);
    registerStaticMethod(L, "getKenshiVersion", BinaryVersionBinding::GetKenshiVersion);
    registerStaticMethod(L, "new", BinaryVersionBinding::create);
    lua_setglobal(L, "BinaryVersion");
}

} // namespace KenshiLua
