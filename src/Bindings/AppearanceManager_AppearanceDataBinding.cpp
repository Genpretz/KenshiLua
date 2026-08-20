#include "pch.h"
#include "Bindings/AppearanceManager_AppearanceDataBinding.h"
#include "Bindings/AppearanceManager_GenderBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Util/OgreFastArrayBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef OgreFastArrayPtrBinding<GameData*> GameDataFastArrayBinding;
typedef OgreFastArrayPrimitiveBinding<float> FloatFastArrayBinding;

static AppearanceManager::AppearanceData* getInstance(lua_State* L, int idx)
{
    return checkObject<AppearanceManager::AppearanceData>(L, idx, AppearanceManager_AppearanceDataBinding::getMetatableName());
}

// --- Getters for AppearanceData ---
static int AppearanceData_get_race(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::AppearanceData is nil");
    return pushObject<GameData>(L, inst->race, GameDataBinding::getMetatableName());
}

static int AppearanceData_get_gender(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::AppearanceData is nil");
    return pushValue<AppearanceManager::Gender>(L, inst->gender, AppearanceManager_GenderBinding::getMetatableName());
}

static int AppearanceData_get_meshFile(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::AppearanceData is nil");
    lua_pushlstring(L, inst->meshFile.c_str(), inst->meshFile.size());
    return 1;
}

static int AppearanceData_get_headsData(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::AppearanceData is nil");
    return pushObject<GameDataFastArrayBinding::ArrayType>(L, &inst->headsData, "Ogre::FastArray<GameData*>");
}

static int AppearanceData_get_headsDataProb(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::AppearanceData is nil");
    return pushObject<FloatFastArrayBinding::ArrayType>(L, &inst->headsDataProb, "Ogre::FastArray<float>");
}

// --- Setters for AppearanceData ---
static int AppearanceData_set_race(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::AppearanceData is nil");
    inst->race = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int AppearanceData_set_gender(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::AppearanceData is nil");
    if (lua_isuserdata(L, 2))
    {
        auto* g = checkObject<AppearanceManager::Gender>(L, 2, AppearanceManager_GenderBinding::getMetatableName());
        if (g) inst->gender = *g;
    }
    else
    {
        inst->gender = AppearanceManager::Gender((AppearanceManager::Gender::Enum)luaL_checkinteger(L, 2));
    }
    return 0;
}

static int AppearanceData_set_meshFile(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::AppearanceData is nil");
    inst->meshFile = luaL_checkstring(L, 2);
    return 0;
}

static int AppearanceData_set_headsData(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::AppearanceData is nil");
    if (lua_isnoneornil(L, 2))
    {
        inst->headsData.clear();
        return 0;
    }
    auto* src = GameDataFastArrayBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set headsData must be Ogre::FastArray<GameData*>");
    inst->headsData = *src;
    return 0;
}

static int AppearanceData_set_headsDataProb(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::AppearanceData is nil");
    if (lua_isnoneornil(L, 2))
    {
        inst->headsDataProb.clear();
        return 0;
    }
    auto* src = FloatFastArrayBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set headsDataProb must be Ogre::FastArray<float>");
    inst->headsDataProb = *src;
    return 0;
}

/*
Skipped methods needing manual binding:
  line 150: AppearanceData& operator=(...) - operator
*/

/*
Skipped properties needing manual binding:
  line 140: attachments (boost::unordered::unordered_map<int, Ogre::FastArray<GameData*>, boost::hash<int>, std::equal_to<int>, Ogre::STLAllocator<std::pair<int const, Ogre::FastArray<GameData*> >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 141: categories (ogre_unordered_map<DataCategory::Enum, DataCategory>::type) - unsupported type
  line 142: rangesByName (boost::unordered::unordered_map<std::string, DataRange const*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, DataRange const*>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 144: attachmentsProb (boost::unordered::unordered_map<int, Ogre::FastArray<float>, boost::hash<int>, std::equal_to<int>, Ogre::STLAllocator<std::pair<int const, Ogre::FastArray<float> >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 145: factionAttachments (boost::unordered::unordered_map<unsigned __int64, Ogre::FastArray<float>, boost::hash<unsigned __int64>, std::equal_to<unsigned __int64>, Ogre::STLAllocator<std::pair<unsigned __int64 const, Ogre::FastArray<float> >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 146: texturesSkin (boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > >) - unsupported type
*/

int AppearanceManager_AppearanceDataBinding::gc(lua_State* L)
{
    return 0;
}

int AppearanceManager_AppearanceDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AppearanceManager_AppearanceData object");
    return 1;
}

int AppearanceManager_AppearanceDataBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void AppearanceManager_AppearanceDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       AppearanceManager_AppearanceDataBinding::operator_eq },
        { "__gc",       AppearanceManager_AppearanceDataBinding::gc },
        { "__tostring", AppearanceManager_AppearanceDataBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "race", AppearanceData_get_race);
    registerGetter(L, "gender", AppearanceData_get_gender);
    registerGetter(L, "meshFile", AppearanceData_get_meshFile);
    registerGetter(L, "headsData", AppearanceData_get_headsData);
    registerGetter(L, "headsDataProb", AppearanceData_get_headsDataProb);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "race", AppearanceData_set_race);
    registerSetter(L, "gender", AppearanceData_set_gender);
    registerSetter(L, "meshFile", AppearanceData_set_meshFile);
    registerSetter(L, "headsData", AppearanceData_set_headsData);
    registerSetter(L, "headsDataProb", AppearanceData_set_headsDataProb);
    lua_setfield(L, -2, "__setters");

    GameDataFastArrayBinding::registerBinding(L, "Ogre::FastArray<GameData*>", GameDataBinding::getMetatableName());
    FloatFastArrayBinding::registerBinding(L, "Ogre::FastArray<float>");

    lua_pop(L, 1);
}

} // namespace KenshiLua
