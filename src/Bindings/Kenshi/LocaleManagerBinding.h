#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class LocaleManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.LocaleManager"; }
    static void registerBinding(lua_State* L);

    static int getInstanceMethod(lua_State* L);
    static int isEastAsian(lua_State* L);

    static int init(lua_State* L);
    static int getCurrentLocale(lua_State* L);
    static int setCurrentLocale(lua_State* L);
    static int trySetCurrentLocaleFromMod(lua_State* L);
    static int getCurrentLocalePath(lua_State* L);
    static int getCurrentLocaleMod(lua_State* L);
    static int getAvailableLanguages(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

