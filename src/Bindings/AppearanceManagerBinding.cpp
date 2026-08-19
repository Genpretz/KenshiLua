#include "pch.h"
#include "Bindings/AppearanceManagerBinding.h"
#include "Bindings/AppearanceManager_AppearanceDataBinding.h"
#include "Bindings/AppearanceManager_GenderBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataCopyStandaloneBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static AppearanceManager* getInstanceSelf(lua_State* L, int idx)
{
    return checkObject<AppearanceManager>(L, idx, AppearanceManagerBinding::getMetatableName());
}

static AppearanceManager::Gender extractGender(lua_State* L, int idx)
{
    if (lua_isuserdata(L, idx))
    {
        auto* g = checkObject<AppearanceManager::Gender>(L, idx, AppearanceManager_GenderBinding::getMetatableName());
        if (g) return *g;
    }
    return AppearanceManager::Gender((AppearanceManager::Gender::Enum)luaL_checkinteger(L, idx));
}

// --- Static Methods ---
int AppearanceManagerBinding::getInstance(lua_State* L)
{
    return pushObject<AppearanceManager>(L, AppearanceManager::getInstance(), AppearanceManagerBinding::getMetatableName());
}

// --- Member Methods ---
int AppearanceManagerBinding::createAppearanceData(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* race = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameDataCopyStandalone* result = inst->createAppearanceData(race);
    return pushObject<GameDataCopyStandalone>(L, result, GameDataCopyStandaloneBinding::getMetatableName());
}

int AppearanceManagerBinding::cleanValidateAppearanceData(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    inst->cleanValidateAppearanceData(appearanceData);
    return 0;
}

int AppearanceManagerBinding::resetAll(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool clearAttachments = lua_toboolean(L, 3) != 0;
    inst->resetAll(appearanceData, clearAttachments);
    return 0;
}

int AppearanceManagerBinding::randomiseAll(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    inst->randomiseAll(appearanceData);
    return 0;
}

int AppearanceManagerBinding::randomiseAllManual(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    float faceRandomnessMult = (float)luaL_checknumber(L, 3);
    float bodyRandomnessMult = (float)luaL_checknumber(L, 4);
    inst->randomiseAllManual(appearanceData, faceRandomnessMult, bodyRandomnessMult);
    return 0;
}

int AppearanceManagerBinding::randomHair(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Faction* faction = lua_isnoneornil(L, 3) ? nullptr : checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    inst->randomHair(appearanceData, faction);
    return 0;
}

int AppearanceManagerBinding::randomFace(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    inst->randomFace(appearanceData);
    return 0;
}

int AppearanceManagerBinding::randomFaceManual(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    float randomnessMult = (float)luaL_checknumber(L, 3);
    inst->randomFaceManual(appearanceData, randomnessMult);
    return 0;
}

int AppearanceManagerBinding::randomPoses(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    float deviation = (float)luaL_checknumber(L, 3);
    inst->randomPoses(appearanceData, deviation);
    return 0;
}

int AppearanceManagerBinding::randomBody(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool isPlayer = lua_toboolean(L, 3) != 0;
    inst->randomBody(appearanceData, isPlayer);
    return 0;
}

int AppearanceManagerBinding::randomBodyManual(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    float randomnessMult = (float)luaL_checknumber(L, 3);
    inst->randomBodyManual(appearanceData, randomnessMult);
    return 0;
}

int AppearanceManagerBinding::randomGender(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    float femaleChance = (float)luaL_checknumber(L, 3);
    inst->randomGender(appearanceData, femaleChance);
    return 0;
}

int AppearanceManagerBinding::randomAnimations(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Character* character = lua_isnoneornil(L, 3) ? nullptr : checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    inst->randomAnimations(appearanceData, character);
    return 0;
}

int AppearanceManagerBinding::getRaceData(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    int index = (int)luaL_checkinteger(L, 2);
    GameData* result = inst->getRaceData(index);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int AppearanceManagerBinding::getRaceIndex(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int result = inst->getRaceIndex(data);
    lua_pushinteger(L, result);
    return 1;
}

int AppearanceManagerBinding::getRacesCount(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    int result = inst->getRacesCount();
    lua_pushinteger(L, result);
    return 1;
}

int AppearanceManagerBinding::isSingleGender(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* raceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = inst->isSingleGender(raceData);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceManagerBinding::setGender(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    AppearanceManager::Gender::Enum genderValue = (AppearanceManager::Gender::Enum)luaL_checkinteger(L, 3);
    inst->setGender(appearanceData, genderValue);
    return 0;
}

int AppearanceManagerBinding::setHead(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* headData = lua_isnoneornil(L, 3) ? nullptr : checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    inst->setHead(appearanceData, headData);
    return 0;
}

int AppearanceManagerBinding::getHeadName(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    AppearanceManager::AppearanceData* appearance = checkObject<AppearanceManager::AppearanceData>(L, 3, AppearanceManager_AppearanceDataBinding::getMetatableName());
    const std::string& result = inst->getHeadName(appearanceData, appearance);
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}

int AppearanceManagerBinding::setRandomHead(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* raceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* appearanceData = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    inst->setRandomHead(raceData, appearanceData);
    return 0;
}

int AppearanceManagerBinding::getHeadIsValid(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* raceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* appearanceData = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* headData = checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
    bool result = inst->getHeadIsValid(raceData, appearanceData, headData);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceManagerBinding::setAttachment(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    AppearanceManager::AppearanceData* appearance = checkObject<AppearanceManager::AppearanceData>(L, 3, AppearanceManager_AppearanceDataBinding::getMetatableName());
    AttachSlot slot = (AttachSlot)luaL_checkinteger(L, 4);
    int index = (int)luaL_checkinteger(L, 5);
    inst->setAttachment(appearanceData, appearance, slot, index);
    return 0;
}

int AppearanceManagerBinding::getAttachmentName(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    AppearanceManager::AppearanceData* appearance = checkObject<AppearanceManager::AppearanceData>(L, 3, AppearanceManager_AppearanceDataBinding::getMetatableName());
    AttachSlot slot = (AttachSlot)luaL_checkinteger(L, 4);
    const std::string& result = inst->getAttachmentName(appearanceData, appearance, slot);
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}

int AppearanceManagerBinding::updateModifiers(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* appearanceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* raceData = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    AppearanceManager::Gender gender = extractGender(L, 4);
    inst->updateModifiers(appearanceData, raceData, gender);
    return 0;
}

int AppearanceManagerBinding::getNormalMap_Plain(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* race = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    AppearanceManager::Gender gender = extractGender(L, 3);
    const std::string& result = inst->getNormalMap_Plain(race, gender);
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}

int AppearanceManagerBinding::getNormalMap_Muscle(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* race = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    AppearanceManager::Gender gender = extractGender(L, 3);
    const std::string& result = inst->getNormalMap_Muscle(race, gender);
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}

int AppearanceManagerBinding::getNormalMap_Starving(lua_State* L)
{
    auto* inst = getInstanceSelf(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager is nil");
    GameData* race = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    AppearanceManager::Gender gender = extractGender(L, 3);
    const std::string& result = inst->getNormalMap_Starving(race, gender);
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}

/*
Skipped methods needing manual binding:
  line 171: getEditorData(boost::unordered::unordered_map<RaceGroupData*, Ogre::FastArray<GameData*>...>&, ...) - complex boost container signature
  line 179: getCharacterIdleAnimations() const - returns const Ogre::FastArray<AnimationData*>&
*/

int AppearanceManagerBinding::gc(lua_State* L)
{
    return 0;
}

int AppearanceManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AppearanceManager object");
    return 1;
}

void AppearanceManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AppearanceManagerBinding::gc },
        { "__tostring", AppearanceManagerBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getInstance",                    AppearanceManagerBinding::getInstance },
        { "createAppearanceData",           AppearanceManagerBinding::createAppearanceData },
        { "cleanValidateAppearanceData",    AppearanceManagerBinding::cleanValidateAppearanceData },
        { "resetAll",                       AppearanceManagerBinding::resetAll },
        { "randomiseAll",                   AppearanceManagerBinding::randomiseAll },
        { "randomiseAllManual",             AppearanceManagerBinding::randomiseAllManual },
        { "randomHair",                     AppearanceManagerBinding::randomHair },
        { "randomFace",                     AppearanceManagerBinding::randomFace },
        { "randomFaceManual",               AppearanceManagerBinding::randomFaceManual },
        { "randomPoses",                    AppearanceManagerBinding::randomPoses },
        { "randomBody",                     AppearanceManagerBinding::randomBody },
        { "randomBodyManual",               AppearanceManagerBinding::randomBodyManual },
        { "randomGender",                   AppearanceManagerBinding::randomGender },
        { "randomAnimations",               AppearanceManagerBinding::randomAnimations },
        { "getRaceData",                    AppearanceManagerBinding::getRaceData },
        { "getRaceIndex",                   AppearanceManagerBinding::getRaceIndex },
        { "getRacesCount",                  AppearanceManagerBinding::getRacesCount },
        { "isSingleGender",                 AppearanceManagerBinding::isSingleGender },
        { "setGender",                      AppearanceManagerBinding::setGender },
        { "setHead",                        AppearanceManagerBinding::setHead },
        { "getHeadName",                    AppearanceManagerBinding::getHeadName },
        { "setRandomHead",                  AppearanceManagerBinding::setRandomHead },
        { "getHeadIsValid",                 AppearanceManagerBinding::getHeadIsValid },
        { "setAttachment",                  AppearanceManagerBinding::setAttachment },
        { "getAttachmentName",              AppearanceManagerBinding::getAttachmentName },
        { "updateModifiers",                AppearanceManagerBinding::updateModifiers },
        { "getNormalMap_Plain",             AppearanceManagerBinding::getNormalMap_Plain },
        { "getNormalMap_Muscle",            AppearanceManagerBinding::getNormalMap_Muscle },
        { "getNormalMap_Starving",          AppearanceManagerBinding::getNormalMap_Starving },
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    lua_pop(L, 1); // Pop metatable

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "getInstance", AppearanceManagerBinding::getInstance);
    lua_setglobal(L, "AppearanceManager");
}

} // namespace KenshiLua
