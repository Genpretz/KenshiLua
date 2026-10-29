#include "pch.h"
#include <windows.h>
#include "kenshi/LocaleInfo.h"
#include "LocaleInfoBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(LocaleInfo, isBase) == 0x0, "LocaleInfo::isBase offset mismatch");
static_assert(offsetof(LocaleInfo, id) == 0x8, "LocaleInfo::id offset mismatch");
static_assert(offsetof(LocaleInfo, name) == 0x30, "LocaleInfo::name offset mismatch");
static_assert(offsetof(LocaleInfo, steamCode) == 0x58, "LocaleInfo::steamCode offset mismatch");
static_assert(offsetof(LocaleInfo, isMod) == 0x80, "LocaleInfo::isMod offset mismatch");

static std::string wideToUtf8(const std::wstring& wstr)
{
    if (wstr.empty()) return std::string();
    int size = WideCharToMultiByte(CP_UTF8, 0, wstr.data(), (int)wstr.size(), NULL, 0, NULL, NULL);
    if (size <= 0) return std::string();
    std::string result(size, '\0');
    WideCharToMultiByte(CP_UTF8, 0, wstr.data(), (int)wstr.size(), &result[0], size, NULL, NULL);
    return result;
}

static std::wstring utf8ToWide(const std::string& str)
{
    if (str.empty()) return std::wstring();
    int size = MultiByteToWideChar(CP_UTF8, 0, str.data(), (int)str.size(), NULL, 0);
    if (size <= 0) return std::wstring();
    std::wstring result(size, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, str.data(), (int)str.size(), &result[0], size);
    return result;
}

static LocaleInfo* getInstance(lua_State* L, int idx)
{
    return checkObject<LocaleInfo>(L, idx, LocaleInfoBinding::getMetatableName());
}

static int LocaleInfo_get_isBase(lua_State* L)
{
    LocaleInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleInfo is nil");
    lua_pushboolean(L, instance->isBase ? 1 : 0);
    return 1;
}

static int LocaleInfo_set_isBase(lua_State* L)
{
    LocaleInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleInfo is nil");
    instance->isBase = lua_toboolean(L, 2) != 0;
    return 0;
}

static int LocaleInfo_get_id(lua_State* L)
{
    LocaleInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleInfo is nil");
    lua_pushstring(L, instance->id.c_str());
    return 1;
}

static int LocaleInfo_set_id(lua_State* L)
{
    LocaleInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleInfo is nil");
    const char* str = luaL_checkstring(L, 2);
    instance->id = str ? str : "";
    return 0;
}

static int LocaleInfo_get_name(lua_State* L)
{
    LocaleInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleInfo is nil");
    std::string utf8 = wideToUtf8(instance->name);
    lua_pushstring(L, utf8.c_str());
    return 1;
}

static int LocaleInfo_set_name(lua_State* L)
{
    LocaleInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleInfo is nil");
    const char* str = luaL_checkstring(L, 2);
    instance->name = utf8ToWide(str ? str : "");
    return 0;
}

static int LocaleInfo_get_steamCode(lua_State* L)
{
    LocaleInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleInfo is nil");
    lua_pushstring(L, instance->steamCode.c_str());
    return 1;
}

static int LocaleInfo_set_steamCode(lua_State* L)
{
    LocaleInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleInfo is nil");
    const char* str = luaL_checkstring(L, 2);
    instance->steamCode = str ? str : "";
    return 0;
}

static int LocaleInfo_get_isMod(lua_State* L)
{
    LocaleInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleInfo is nil");
    lua_pushboolean(L, instance->isMod ? 1 : 0);
    return 1;
}

static int LocaleInfo_set_isMod(lua_State* L)
{
    LocaleInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleInfo is nil");
    instance->isMod = lua_toboolean(L, 2) != 0;
    return 0;
}

int LocaleInfoBinding::operator_assign(lua_State* L)
{
    LocaleInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleInfo is nil");
    LocaleInfo* other = checkObject<LocaleInfo>(L, 2, LocaleInfoBinding::getMetatableName());
    if (!other) return luaL_error(L, "Argument 1 must be LocaleInfo");
    *instance = *other;
    return pushObject<LocaleInfo>(L, instance, LocaleInfoBinding::getMetatableName());
}

int LocaleInfoBinding::gc(lua_State* L)
{
    return 0;
}

int LocaleInfoBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.LocaleInfo object");
    return 1;
}

void LocaleInfoBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LocaleInfoBinding::gc },
        { "__tostring", LocaleInfoBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "operator_assign", LocaleInfoBinding::operator_assign },
        { 0, 0 }
    };

    registerClass(
        L,
        LocaleInfoBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, LocaleInfoBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "isBase", LocaleInfo_get_isBase);
    registerGetter(L, "id", LocaleInfo_get_id);
    registerGetter(L, "name", LocaleInfo_get_name);
    registerGetter(L, "steamCode", LocaleInfo_get_steamCode);
    registerGetter(L, "isMod", LocaleInfo_get_isMod);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "isBase", LocaleInfo_set_isBase);
    registerSetter(L, "id", LocaleInfo_set_id);
    registerSetter(L, "name", LocaleInfo_set_name);
    registerSetter(L, "steamCode", LocaleInfo_set_steamCode);
    registerSetter(L, "isMod", LocaleInfo_set_isMod);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua

