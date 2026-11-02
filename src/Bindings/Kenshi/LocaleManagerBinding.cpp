#include "pch.h"
#include "kenshi/LocaleInfo.h"
#include "LocaleManagerBinding.h"
#include "LocaleInfoBinding.h"
#include "Bindings/Kenshi/ModInfoBinding.h"
#include "Bindings/Kenshi/Util/OgreFastArrayBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(LocaleManager, localeList) == 0x40, "LocaleManager::localeList offset mismatch");
static_assert(offsetof(LocaleManager, availableLanguages) == 0x58, "LocaleManager::availableLanguages offset mismatch");
static_assert(offsetof(LocaleManager, modLocale) == 0x70, "LocaleManager::modLocale offset mismatch");
static_assert(offsetof(LocaleManager, currentLocale) == 0x78, "LocaleManager::currentLocale offset mismatch");
static_assert(offsetof(LocaleManager, localePath) == 0x80, "LocaleManager::localePath offset mismatch");

typedef OgreFastArrayPtrBinding<LocaleInfo*> LocaleInfoPtrFastArrayBinding;
typedef OgreFastArrayValueBinding<LocaleInfo> LocaleInfoValueFastArrayBinding;

static LocaleManager* getInstance(lua_State* L, int idx)
{
    return checkObject<LocaleManager>(L, idx, LocaleManagerBinding::getMetatableName());
}

static int LocaleManager_get_currentLocale(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    if (!instance->currentLocale) { lua_pushnil(L); return 1; }
    return pushObject<LocaleInfo>(L, instance->currentLocale, LocaleInfoBinding::getMetatableName());
}

static int LocaleManager_set_currentLocale(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    instance->currentLocale = lua_isnoneornil(L, 2) ? nullptr : checkObject<LocaleInfo>(L, 2, LocaleInfoBinding::getMetatableName());
    return 0;
}

static int LocaleManager_get_modLocale(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    if (!instance->modLocale) { lua_pushnil(L); return 1; }
    return pushObject<LocaleInfo>(L, instance->modLocale, LocaleInfoBinding::getMetatableName());
}

static int LocaleManager_set_modLocale(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    instance->modLocale = lua_isnoneornil(L, 2) ? nullptr : checkObject<LocaleInfo>(L, 2, LocaleInfoBinding::getMetatableName());
    return 0;
}

static int LocaleManager_get_localePath(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    lua_pushstring(L, instance->localePath.string().c_str());
    return 1;
}

static int LocaleManager_set_localePath(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    const char* str = luaL_checkstring(L, 2);
    instance->localePath = str ? str : "";
    return 0;
}

static int LocaleManager_get_availableLanguages(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    return pushObject<LocaleInfoPtrFastArrayBinding::ArrayType>(L, &instance->availableLanguages, "Ogre::FastArray<LocaleInfo*>");
}

static int LocaleManager_set_availableLanguages(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    auto* val = LocaleInfoPtrFastArrayBinding::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set availableLanguages must be Ogre::FastArray<LocaleInfo*>");
    instance->availableLanguages = *val;
    return 0;
}

static int LocaleManager_get_localeList(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    return pushObject<LocaleInfoValueFastArrayBinding::ArrayType>(L, &instance->localeList, "Ogre::FastArray<LocaleInfo>");
}

static int LocaleManager_set_localeList(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    auto* val = LocaleInfoValueFastArrayBinding::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set localeList must be Ogre::FastArray<LocaleInfo>");
    instance->localeList = *val;
    return 0;
}

int LocaleManagerBinding::getInstanceMethod(lua_State* L)
{
    LocaleManager* instance = LocaleManager::getInstance();
    if (!instance) { lua_pushnil(L); return 1; }
    return pushObject<LocaleManager>(L, instance, LocaleManagerBinding::getMetatableName());
}

int LocaleManagerBinding::isEastAsian(lua_State* L)
{
    const char* id = luaL_checkstring(L, 1);
    bool res = LocaleManager::isEastAsian(id ? id : "");
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int LocaleManagerBinding::init(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    instance->init();
    return 0;
}

int LocaleManagerBinding::getCurrentLocale(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    LocaleInfo* res = instance->getCurrentLocale();
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<LocaleInfo>(L, res, LocaleInfoBinding::getMetatableName());
}

int LocaleManagerBinding::setCurrentLocale(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    LocaleInfo* locale = lua_isnoneornil(L, 2) ? nullptr : checkObject<LocaleInfo>(L, 2, LocaleInfoBinding::getMetatableName());
    instance->setCurrentLocale(locale);
    return 0;
}

int LocaleManagerBinding::trySetCurrentLocaleFromMod(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    ModInfo* mod = checkObject<ModInfo>(L, 2, ModInfoBinding::getMetatableName());
    if (!mod) return luaL_error(L, "Argument 1 must be ModInfo");
    bool res = instance->trySetCurrentLocaleFromMod(mod);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int LocaleManagerBinding::getCurrentLocalePath(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    std::string res = instance->getCurrentLocalePath();
    lua_pushstring(L, res.c_str());
    return 1;
}

int LocaleManagerBinding::getCurrentLocaleMod(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    std::string res = instance->getCurrentLocaleMod();
    lua_pushstring(L, res.c_str());
    return 1;
}

int LocaleManagerBinding::getAvailableLanguages(lua_State* L)
{
    LocaleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LocaleManager is nil");
    const Ogre::FastArray<LocaleInfo*>& res = instance->getAvailableLanguages();
    return pushObject<LocaleInfoPtrFastArrayBinding::ArrayType>(L, const_cast<Ogre::FastArray<LocaleInfo*>*>(&res), "Ogre::FastArray<LocaleInfo*>");
}

int LocaleManagerBinding::gc(lua_State* L)
{
    return 0;
}

int LocaleManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.LocaleManager object");
    return 1;
}

void LocaleManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LocaleManagerBinding::gc },
        { "__tostring", LocaleManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "init", LocaleManagerBinding::init },
        { "getCurrentLocale", LocaleManagerBinding::getCurrentLocale },
        { "setCurrentLocale", LocaleManagerBinding::setCurrentLocale },
        { "trySetCurrentLocaleFromMod", LocaleManagerBinding::trySetCurrentLocaleFromMod },
        { "getCurrentLocalePath", LocaleManagerBinding::getCurrentLocalePath },
        { "getCurrentLocaleMod", LocaleManagerBinding::getCurrentLocaleMod },
        { "getAvailableLanguages", LocaleManagerBinding::getAvailableLanguages },
        { 0, 0 }
    };

    registerClass(
        L,
        LocaleManagerBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, LocaleManagerBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "currentLocale", LocaleManager_get_currentLocale);
    registerGetter(L, "modLocale", LocaleManager_get_modLocale);
    registerGetter(L, "localePath", LocaleManager_get_localePath);
    registerGetter(L, "availableLanguages", LocaleManager_get_availableLanguages);
    registerGetter(L, "localeList", LocaleManager_get_localeList);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "currentLocale", LocaleManager_set_currentLocale);
    registerSetter(L, "modLocale", LocaleManager_set_modLocale);
    registerSetter(L, "localePath", LocaleManager_set_localePath);
    registerSetter(L, "availableLanguages", LocaleManager_set_availableLanguages);
    registerSetter(L, "localeList", LocaleManager_set_localeList);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);

    pushGlobalTable(L, "LocaleManager");
    registerStaticMethod(L, "getInstance", LocaleManagerBinding::getInstanceMethod);
    registerStaticMethod(L, "isEastAsian", LocaleManagerBinding::isEastAsian);
    lua_setglobal(L, "LocaleManager");

}

} // namespace KenshiLua
