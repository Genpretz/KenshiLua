#include "pch.h"
#include "kenshi/Research.h"
#include "ResearchBinding.h"
#include "ResearchItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Building/BuildingBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Gui/ManagementScreenBinding.h"

namespace KenshiLua
{

static_assert(offsetof(Research, screen) == 0x0, "Research::screen offset mismatch");
static_assert(offsetof(Research, theoreticalTechLevel) == 0x8, "Research::theoreticalTechLevel offset mismatch");
static_assert(offsetof(Research, changedSoUpdateGUI) == 0xC, "Research::changedSoUpdateGUI offset mismatch");
static_assert(offsetof(Research, categories) == 0xC0, "Research::categories offset mismatch");
static_assert(offsetof(Research, paidFor) == 0xD8, "Research::paidFor offset mismatch");
static_assert(offsetof(Research, finished) == 0xF0, "Research::finished offset mismatch");
static_assert(offsetof(Research, enabledObjects) == 0x130, "Research::enabledObjects offset mismatch");
static_assert(offsetof(Research, researchDeskLevel) == 0x170, "Research::researchDeskLevel offset mismatch");
static_assert(offsetof(Research, numResearchers) == 0x174, "Research::numResearchers offset mismatch");
static_assert(offsetof(Research, totalResearchThisFrame) == 0x178, "Research::totalResearchThisFrame offset mismatch");

static Research* getInstance(lua_State* L, int idx)
{
    return checkObject<Research>(L, idx, ResearchBinding::getMetatableName());
}

// --- Getters for Research ---
static int Research_get_screen(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    return pushObject<ManagementScreen>(L, instance->screen, ManagementScreenBinding::getMetatableName());
}

static int Research_get_theoreticalTechLevel(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    lua_pushinteger(L, instance->theoreticalTechLevel);
    return 1;
}

static int Research_get_changedSoUpdateGUI(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    lua_pushboolean(L, instance->changedSoUpdateGUI ? 1 : 0);
    return 1;
}

static int Research_get_categories(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    return pushObject<lektor<std::string>>(L, &instance->categories, "lektor<std::string>");
}

static int Research_get_paidFor(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    return pushObject<lektor<std::string>>(L, &instance->paidFor, "lektor<std::string>");
}

static int Research_get_finished(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    return pushObject<ogre_unordered_set<GameData*>::type>(L, &instance->finished, "ogre_unordered_set<GameData*>");
}

static int Research_get_enabledObjects(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    return pushObject<ogre_unordered_set<GameData*>::type>(L, &instance->enabledObjects, "ogre_unordered_set<GameData*>");
}

static int Research_get_researchDeskLevel(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    lua_pushinteger(L, instance->researchDeskLevel);
    return 1;
}

static int Research_get_numResearchers(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    lua_pushinteger(L, instance->numResearchers);
    return 1;
}

static int Research_get_totalResearchThisFrame(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    lua_pushnumber(L, instance->totalResearchThisFrame);
    return 1;
}

// --- Setters for Research ---
static int Research_set_screen(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    instance->screen = lua_isnoneornil(L, 2) ? nullptr : checkObject<ManagementScreen>(L, 2, ManagementScreenBinding::getMetatableName());
    return 0;
}

static int Research_set_theoreticalTechLevel(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    instance->theoreticalTechLevel = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Research_set_changedSoUpdateGUI(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    instance->changedSoUpdateGUI = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Research_set_researchDeskLevel(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    instance->researchDeskLevel = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Research_set_numResearchers(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    instance->numResearchers = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Research_set_totalResearchThisFrame(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    instance->totalResearchThisFrame = (float)luaL_checknumber(L, 2);
    return 0;
}

int ResearchBinding::_reset(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    instance->_reset();
    return 0;
}

int ResearchBinding::_setup(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    instance->_setup();
    return 0;
}

int ResearchBinding::getArmourCraftLevel(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");

    GameData* armour = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int skill = (int)luaL_checkinteger(L, 3);
    bool crit = lua_toboolean(L, 4) != 0;
    int result = instance->getArmourCraftLevel(armour, skill, crit);
    lua_pushinteger(L, result);
    return 1;
}

int ResearchBinding::startResearch(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->startResearch(d);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBinding::stopResearch(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->stopResearch(d);
    return 0;
}

int ResearchBinding::completeResearch(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->completeResearch(d);
    return 0;
}

int ResearchBinding::isFinished(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");

    GameData* what = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->isFinished(what);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBinding::isBuildingResearched(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->isBuildingResearched(d);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBinding::getETA(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool simple = lua_toboolean(L, 3) != 0;
    std::string result = instance->getETA(d, simple);
    lua_pushstring(L, result.c_str());
    return 1;
}

int ResearchBinding::payCosts(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->payCosts(d);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBinding::canPayCosts(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->canPayCosts(data);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBinding::getBlueprintsFor(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* result = instance->getBlueprintsFor(item);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int ResearchBinding::staticUpdate(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    instance->staticUpdate();
    return 0;
}

int ResearchBinding::getCurrentResearchRate(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    float result = instance->getCurrentResearchRate();
    lua_pushnumber(L, result);
    return 1;
}

int ResearchBinding::serialise(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->serialise(data);
    return 0;
}

int ResearchBinding::load(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->load(data);
    return 0;
}

int ResearchBinding::progressResearch(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    float amount = (float)luaL_checknumber(L, 2);
    instance->progressResearch(amount);
    return 0;
}

int ResearchBinding::checkRequirementsForInvisibility(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    GameData* what = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool twoLevels = lua_toboolean(L, 3) != 0;
    bool result = instance->checkRequirementsForInvisibility(what, twoLevels);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBinding::checkRequirements(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    GameData* what = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool twoLevels = lua_toboolean(L, 3) != 0;
    bool checkCost = lua_toboolean(L, 4) != 0;
    bool result = instance->checkRequirements(what, twoLevels, checkCost);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBinding::checkRequirements_andQueue(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    GameData* what = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->checkRequirements_andQueue(what);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBinding::isInQueue(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    GameData* what = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->isInQueue(what);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBinding::_updateTheAllList(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    instance->_updateTheAllList();
    return 0;
}

int ResearchBinding::setResearchDeskLevel(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    int level = (int)luaL_checkinteger(L, 2);
    instance->setResearchDeskLevel(level);
    return 0;
}

int ResearchBinding::refreshTheoreticalTechLevel(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    instance->refreshTheoreticalTechLevel();
    return 0;
}

int ResearchBinding::needsATechBench(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int result = instance->needsATechBench(d);
    lua_pushinteger(L, result);
    return 1;
}

int ResearchBinding::hasPaidFor(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->hasPaidFor(d);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBinding::getResearchDeskLevel(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    int result = instance->getResearchDeskLevel();
    lua_pushinteger(L, result);
    return 1;
}

int ResearchBinding::hasArtifact(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    GameData* artifact = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = instance->hasArtifact(artifact, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBinding::getResearchItem(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    ResearchItem result = instance->getResearchItem(d);
    return pushValue<ResearchItem>(L, result, ResearchItemBinding::getMetatableName());
}

int ResearchBinding::getResearchProgress(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");

    if (testObject<ResearchItem>(L, 2, ResearchItemBinding::getMetatableName())) {
        ResearchItem* item = checkObject<ResearchItem>(L, 2, ResearchItemBinding::getMetatableName());
        lua_pushnumber(L, instance->getResearchProgress(item));
        return 1;
    }
    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    lua_pushnumber(L, instance->getResearchProgress(d));
    return 1;
}

int ResearchBinding::getCategories(lua_State* L)
{
    Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Research is nil");
    return pushObject<lektor<std::string>>(L, const_cast<lektor<std::string>*>(&instance->getCategories()), "lektor<std::string>");
}

int ResearchBinding::gc(lua_State* L)
{
    return 0;
}

int ResearchBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Research object");
    return 1;
}

void ResearchBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ResearchBinding::gc },
        { "__tostring", ResearchBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_reset", ResearchBinding::_reset },
        { "_setup", ResearchBinding::_setup },
        { "getArmourCraftLevel", ResearchBinding::getArmourCraftLevel },
        { "startResearch", ResearchBinding::startResearch },
        { "stopResearch", ResearchBinding::stopResearch },
        { "completeResearch", ResearchBinding::completeResearch },
        { "isFinished", ResearchBinding::isFinished },
        { "isBuildingResearched", ResearchBinding::isBuildingResearched },
        { "getETA", ResearchBinding::getETA },
        { "payCosts", ResearchBinding::payCosts },
        { "canPayCosts", ResearchBinding::canPayCosts },
        { "getBlueprintsFor", ResearchBinding::getBlueprintsFor },
        { "staticUpdate", ResearchBinding::staticUpdate },
        { "getCurrentResearchRate", ResearchBinding::getCurrentResearchRate },
        { "serialise", ResearchBinding::serialise },
        { "load", ResearchBinding::load },
        { "progressResearch", ResearchBinding::progressResearch },
        { "checkRequirementsForInvisibility", ResearchBinding::checkRequirementsForInvisibility },
        { "checkRequirements", ResearchBinding::checkRequirements },
        { "checkRequirements_andQueue", ResearchBinding::checkRequirements_andQueue },
        { "isInQueue", ResearchBinding::isInQueue },
        { "_updateTheAllList", ResearchBinding::_updateTheAllList },
        { "setResearchDeskLevel", ResearchBinding::setResearchDeskLevel },
        { "refreshTheoreticalTechLevel", ResearchBinding::refreshTheoreticalTechLevel },
        { "needsATechBench", ResearchBinding::needsATechBench },
        { "hasPaidFor", ResearchBinding::hasPaidFor },
        { "getResearchDeskLevel", ResearchBinding::getResearchDeskLevel },
        { "hasArtifact", ResearchBinding::hasArtifact },
        { "getResearchItem", ResearchBinding::getResearchItem },
        { "getResearchProgress", ResearchBinding::getResearchProgress },
        { "getCategories", ResearchBinding::getCategories },
        { 0, 0 }
    };

    registerClass(
        L,
        ResearchBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ResearchBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "screen", Research_get_screen);
    registerGetter(L, "theoreticalTechLevel", Research_get_theoreticalTechLevel);
    registerGetter(L, "changedSoUpdateGUI", Research_get_changedSoUpdateGUI);
    registerGetter(L, "categories", Research_get_categories);
    registerGetter(L, "paidFor", Research_get_paidFor);
    registerGetter(L, "finished", Research_get_finished);
    registerGetter(L, "enabledObjects", Research_get_enabledObjects);
    registerGetter(L, "researchDeskLevel", Research_get_researchDeskLevel);
    registerGetter(L, "numResearchers", Research_get_numResearchers);
    registerGetter(L, "totalResearchThisFrame", Research_get_totalResearchThisFrame);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "screen", Research_set_screen);
    registerSetter(L, "theoreticalTechLevel", Research_set_theoreticalTechLevel);
    registerSetter(L, "changedSoUpdateGUI", Research_set_changedSoUpdateGUI);
    registerSetter(L, "researchDeskLevel", Research_set_researchDeskLevel);
    registerSetter(L, "numResearchers", Research_set_numResearchers);
    registerSetter(L, "totalResearchThisFrame", Research_set_totalResearchThisFrame);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
