#include "pch.h"
#include "kenshi\gui\ManagementScreen.h"
#include "ManagementScreenBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Gui/FactionsScreenBinding.h"
#include "Bindings/Gui/MapScreenBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/Gui/SquadManagementScreenBinding.h"
#include "Bindings/Gui/ToolTipBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"

namespace KenshiLua
{

static ManagementScreen* getInstance(lua_State* L, int idx)
{
    return checkObject<ManagementScreen>(L, idx, ManagementScreenBinding::getMetatableName());
}

// --- Getters for ManagementScreen ---
static int ManagementScreen_get_squadScreen(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    return pushObject<SquadManagementScreen>(L, instance->squadScreen, SquadManagementScreenBinding::getMetatableName());
}

static int ManagementScreen_get_mapScreen(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    return pushObject<MapScreen>(L, instance->mapScreen, MapScreenBinding::getMetatableName());
}

static int ManagementScreen_get_currentCategoryList(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    return pushObject<lektor<GameData*>>(L, &instance->currentCategoryList, LektorPtrBinding<GameData*>::metaName);
}

static int ManagementScreen_get_factionScreen(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    return pushObject<FactionsScreen>(L, instance->factionScreen, FactionsScreenBinding::getMetatableName());
}

static int ManagementScreen_get_researchCategoriesListBox(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->researchCategoriesListBox);
    return 1;
}

static int ManagementScreen_get_availableList(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    return pushObject<DatapanelGUI>(L, instance->availableList, DatapanelGUIBinding::getMetatableName());
}

static int ManagementScreen_get_info(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    return pushObject<DatapanelGUI>(L, instance->info, DatapanelGUIBinding::getMetatableName());
}

static int ManagementScreen_get_info2(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    return pushObject<DatapanelGUI>(L, instance->info2, DatapanelGUIBinding::getMetatableName());
}

static int ManagementScreen_get_techCategory(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    lua_pushstring(L, instance->techCategory.c_str());
    return 1;
}

static int ManagementScreen_get_currentResearch(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    return pushObject<GameData>(L, instance->currentResearch, GameDataBinding::getMetatableName());
}

static int ManagementScreen_get_researchBenchMessage(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->researchBenchMessage);
    return 1;
}

static int ManagementScreen_get_researchDescriptionUpdateRequest(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    lua_pushboolean(L, instance->researchDescriptionUpdateRequest ? 1 : 0);
    return 1;
}

static int ManagementScreen_get_lastResearchRate(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    lua_pushnumber(L, instance->lastResearchRate);
    return 1;
}

static int ManagementScreen_get_todoList(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->todoList);
    return 1;
}

static int ManagementScreen_get_craftingQueue(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->craftingQueue);
    return 1;
}

static int ManagementScreen_get_messagesTextBox(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->messagesTextBox);
    return 1;
}

static int ManagementScreen_get_messagesUpdated(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    lua_pushboolean(L, instance->messagesUpdated ? 1 : 0);
    return 1;
}

static int ManagementScreen_get_messagesMutex(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    lua_pushlightuserdata(L, (void*)&instance->messagesMutex);
    return 1;
}

static int ManagementScreen_get_messagesPlayerColor(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    lua_pushstring(L, instance->messagesPlayerColor.c_str());
    return 1;
}

static int ManagementScreen_get_messagesNPCColor(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    lua_pushstring(L, instance->messagesNPCColor.c_str());
    return 1;
}

static int ManagementScreen_get_aiScreen(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    return pushObject<DatapanelGUI>(L, instance->aiScreen, DatapanelGUIBinding::getMetatableName());
}

static int ManagementScreen_get_aiToolTip(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    return pushObject<ToolTip>(L, instance->aiToolTip, ToolTipBinding::getMetatableName());
}

static int ManagementScreen_get_toolTip(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    return pushObject<ToolTip>(L, instance->toolTip, ToolTipBinding::getMetatableName());
}

static int ManagementScreen_get_window(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->window);
    return 1;
}

static int ManagementScreen_get_tabs(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->tabs);
    return 1;
}

// --- Setters for ManagementScreen ---
static int ManagementScreen_set_squadScreen(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->squadScreen = lua_isnoneornil(L, 2) ? nullptr : checkObject<SquadManagementScreen>(L, 2, SquadManagementScreenBinding::getMetatableName());
    return 0;
}

static int ManagementScreen_set_factionScreen(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->factionScreen = lua_isnoneornil(L, 2) ? nullptr : checkObject<FactionsScreen>(L, 2, FactionsScreenBinding::getMetatableName());
    return 0;
}

static int ManagementScreen_set_availableList(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->availableList = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int ManagementScreen_set_info(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->info = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int ManagementScreen_set_info2(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->info2 = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int ManagementScreen_set_techCategory(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->techCategory = luaL_checkstring(L, 2);
    return 0;
}

static int ManagementScreen_set_currentResearch(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->currentResearch = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int ManagementScreen_set_researchDescriptionUpdateRequest(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->researchDescriptionUpdateRequest = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ManagementScreen_set_lastResearchRate(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->lastResearchRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ManagementScreen_set_messagesUpdated(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->messagesUpdated = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ManagementScreen_set_messagesMutex(lua_State* L)
{
    return luaL_error(L, "messagesMutex is read-only");
}

static int ManagementScreen_set_messagesPlayerColor(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->messagesPlayerColor = luaL_checkstring(L, 2);
    return 0;
}

static int ManagementScreen_set_messagesNPCColor(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->messagesNPCColor = luaL_checkstring(L, 2);
    return 0;
}

static int ManagementScreen_set_aiScreen(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->aiScreen = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int ManagementScreen_set_aiToolTip(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->aiToolTip = lua_isnoneornil(L, 2) ? nullptr : checkObject<ToolTip>(L, 2, ToolTipBinding::getMetatableName());
    return 0;
}

static int ManagementScreen_set_toolTip(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->toolTip = lua_isnoneornil(L, 2) ? nullptr : checkObject<ToolTip>(L, 2, ToolTipBinding::getMetatableName());
    return 0;
}

int ManagementScreenBinding::update(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    instance->update();
    return 0;
}

int ManagementScreenBinding::clear(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    instance->clear();
    return 0;
}

int ManagementScreenBinding::getVisible(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ManagementScreenBinding::setVisible(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    bool on = lua_toboolean(L, 2) != 0;
    int tab = (int)luaL_checkinteger(L, 3);
    instance->setVisible(on, tab);
    return 0;
}

int ManagementScreenBinding::getCurrentTab(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    int result = instance->getCurrentTab();
    lua_pushinteger(L, result);
    return 1;
}

int ManagementScreenBinding::getTab(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    int index = (int)luaL_checkinteger(L, 2);
    MyGUI::TabItem* result = instance->getTab(index);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ManagementScreenBinding::getWidget(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    const std::string name = luaL_checkstring(L, 2);
    MyGUI::Widget* result = instance->getWidget(name);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ManagementScreenBinding::refresh(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    GameData* current = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    float progress = (float)luaL_checknumber(L, 3);
    instance->refresh(current, progress);
    return 0;
}

int ManagementScreenBinding::refreshResearchList(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    instance->refreshResearchList();
    return 0;
}

int ManagementScreenBinding::refreshResearchRate(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    instance->refreshResearchRate();
    return 0;
}

int ManagementScreenBinding::refreshDiplomacy(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    instance->refreshDiplomacy();
    return 0;
}

int ManagementScreenBinding::refreshSquads(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    instance->refreshSquads();
    return 0;
}

int ManagementScreenBinding::refreshMap(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    bool centerCamera = lua_toboolean(L, 2) != 0;
    instance->refreshMap(centerCamera);
    return 0;
}

int ManagementScreenBinding::showRoads(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    bool v = lua_toboolean(L, 2) != 0;
    instance->showRoads(v);
    return 0;
}

int ManagementScreenBinding::addSquadToMap(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    Platoon* squad = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->addSquadToMap(squad);
    return 0;
}

int ManagementScreenBinding::removeSquadFromMap(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    Platoon* squad = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->removeSquadFromMap(squad);
    return 0;
}

int ManagementScreenBinding::resetSquads(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    instance->resetSquads();
    return 0;
}

int ManagementScreenBinding::refreshMessages(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    instance->refreshMessages();
    return 0;
}

int ManagementScreenBinding::refreshAI(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    instance->refreshAI();
    return 0;
}

int ManagementScreenBinding::showDebugMarker(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    instance->showDebugMarker(p);
    return 0;
}

int ManagementScreenBinding::updateResearchListRate(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    instance->updateResearchListRate();
    return 0;
}

int ManagementScreenBinding::refreshResearchListDescription(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    instance->refreshResearchListDescription();
    return 0;
}

int ManagementScreenBinding::setCraftingBench(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 to setCraftingBench must be hand");
    instance->setCraftingBench(*h);
    return 0;
}

int ManagementScreenBinding::printResearch(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, idx, DatapanelGUIBinding::getMetatableName());
    GameData* d = checkObject<GameData>(L, idx + 1, GameDataBinding::getMetatableName());
    const std::string listname = luaL_checkstring(L, idx + 2);
    const std::string displayname = luaL_checkstring(L, idx + 3);
    int cat = (int)luaL_checkinteger(L, idx + 4);

    ManagementScreen::printResearch(panel, d, listname, displayname, cat);
    return 0;
}

int ManagementScreenBinding::addMessage(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");

    const std::string owner = luaL_checkstring(L, 2);
    const std::string message = luaL_checkstring(L, 3);
    MessageLogColor isPlayer = (MessageLogColor)luaL_checkinteger(L, 4);
    instance->addMessage(owner, message, isPlayer);
    return 0;
}

int ManagementScreenBinding::getSingleton(lua_State* L)
{
    ManagementScreen* result = ManagementScreen::getSingleton();
    return pushObject<ManagementScreen>(L, result, ManagementScreenBinding::getMetatableName());
}

static int ManagementScreen_set_mapScreen(lua_State* L)
{
    ManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ManagementScreen is nil");
    instance->mapScreen = lua_isnoneornil(L, 2) ? nullptr : checkObject<MapScreen>(L, 2, MapScreenBinding::getMetatableName());
    return 0;
}

/*
Skipped methods needing manual binding:
  line 69: void closeEverythingButton(...) - unsupported arg type
  line 70: void tabCallback(...) - unsupported arg type
  line 99: void researchTypeSelect(...) - unsupported arg type
  line 100: void addButtonPress(...) - unsupported arg type
  line 101: void removeButtonPress(...) - unsupported arg type
  line 102: void mouseOverCallback(...) - unsupported arg type
  line 134: void researchQueueTooltip(...) - unsupported arg type
  line 135: void researchRemoved(...) - non-string reference arg
  line 136: void researchValidateOrder(...) - non-string reference arg
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - ManagementScreen_get_researchCategoriesListBox: MyGUI::ListBox* (unbound pointer)
  - ManagementScreen_get_researchBenchMessage: MyGUI::EditBox* (unbound pointer)
  - ManagementScreen_get_todoList: ReorderableList<std::deque<ResearchItem, Ogre::STLAllocator<ResearchItem, Ogre::GeneralAllocPolicy > >, ManagementScreen::TechItemViewData>* (unbound pointer)
  - ManagementScreen_get_craftingQueue: CraftingQueue* (unbound pointer)
  - ManagementScreen_get_messagesTextBox: MyGUI::EditBox* (unbound pointer)
  - ManagementScreen_get_window: MyGUI::Window* (unbound pointer)
  - ManagementScreen_get_tabs: MyGUI::TabControl* (unbound pointer)
  - ManagementScreenBinding::getTab: MyGUI::TabItem* (unbound pointer)
  - ManagementScreenBinding::getWidget: MyGUI::Widget* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 139: messagesStream (std::basic_ostringstream<char, std::char_traits<char>, std::allocator<char> >) - unsupported type
*/

int ManagementScreenBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ManagementScreenBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ManagementScreen object");
    return 1;
}

void ManagementScreenBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ManagementScreenBinding::gc },
        { "__tostring", ManagementScreenBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", ManagementScreenBinding::update },
        { "clear", ManagementScreenBinding::clear },
        { "getVisible", ManagementScreenBinding::getVisible },
        { "setVisible", ManagementScreenBinding::setVisible },
        { "getCurrentTab", ManagementScreenBinding::getCurrentTab },
        { "getTab", ManagementScreenBinding::getTab },
        { "getWidget", ManagementScreenBinding::getWidget },
        { "refresh", ManagementScreenBinding::refresh },
        { "refreshResearchList", ManagementScreenBinding::refreshResearchList },
        { "refreshResearchRate", ManagementScreenBinding::refreshResearchRate },
        { "refreshDiplomacy", ManagementScreenBinding::refreshDiplomacy },
        { "refreshSquads", ManagementScreenBinding::refreshSquads },
        { "refreshMap", ManagementScreenBinding::refreshMap },
        { "showRoads", ManagementScreenBinding::showRoads },
        { "addSquadToMap", ManagementScreenBinding::addSquadToMap },
        { "removeSquadFromMap", ManagementScreenBinding::removeSquadFromMap },
        { "resetSquads", ManagementScreenBinding::resetSquads },
        { "refreshMessages", ManagementScreenBinding::refreshMessages },
        { "refreshAI", ManagementScreenBinding::refreshAI },
        { "showDebugMarker", ManagementScreenBinding::showDebugMarker },
        { "setCraftingBench", ManagementScreenBinding::setCraftingBench },
        { "printResearch", ManagementScreenBinding::printResearch },
        { "addMessage", ManagementScreenBinding::addMessage },
        { "getSingleton", ManagementScreenBinding::getSingleton },
        { "updateResearchListRate", ManagementScreenBinding::updateResearchListRate },
        { "refreshResearchListDescription", ManagementScreenBinding::refreshResearchListDescription },
        { 0, 0 }
    };

    registerClass(
        L, 
        ManagementScreenBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ManagementScreenBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "squadScreen", ManagementScreen_get_squadScreen);
    registerGetter(L, "mapScreen", ManagementScreen_get_mapScreen);
    registerGetter(L, "currentCategoryList", ManagementScreen_get_currentCategoryList);
    registerGetter(L, "factionScreen", ManagementScreen_get_factionScreen);
    registerGetter(L, "researchCategoriesListBox", ManagementScreen_get_researchCategoriesListBox);
    registerGetter(L, "availableList", ManagementScreen_get_availableList);
    registerGetter(L, "info", ManagementScreen_get_info);
    registerGetter(L, "info2", ManagementScreen_get_info2);
    registerGetter(L, "techCategory", ManagementScreen_get_techCategory);
    registerGetter(L, "currentResearch", ManagementScreen_get_currentResearch);
    registerGetter(L, "researchBenchMessage", ManagementScreen_get_researchBenchMessage);
    registerGetter(L, "researchDescriptionUpdateRequest", ManagementScreen_get_researchDescriptionUpdateRequest);
    registerGetter(L, "lastResearchRate", ManagementScreen_get_lastResearchRate);
    registerGetter(L, "todoList", ManagementScreen_get_todoList);
    registerGetter(L, "craftingQueue", ManagementScreen_get_craftingQueue);
    registerGetter(L, "messagesTextBox", ManagementScreen_get_messagesTextBox);
    registerGetter(L, "messagesUpdated", ManagementScreen_get_messagesUpdated);
    registerGetter(L, "messagesMutex", ManagementScreen_get_messagesMutex);
    registerGetter(L, "messagesPlayerColor", ManagementScreen_get_messagesPlayerColor);
    registerGetter(L, "messagesNPCColor", ManagementScreen_get_messagesNPCColor);
    registerGetter(L, "aiScreen", ManagementScreen_get_aiScreen);
    registerGetter(L, "aiToolTip", ManagementScreen_get_aiToolTip);
    registerGetter(L, "toolTip", ManagementScreen_get_toolTip);
    registerGetter(L, "window", ManagementScreen_get_window);
    registerGetter(L, "tabs", ManagementScreen_get_tabs);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "squadScreen", ManagementScreen_set_squadScreen);
    registerSetter(L, "mapScreen", ManagementScreen_set_mapScreen);
    registerSetter(L, "factionScreen", ManagementScreen_set_factionScreen);
    registerSetter(L, "availableList", ManagementScreen_set_availableList);
    registerSetter(L, "info", ManagementScreen_set_info);
    registerSetter(L, "info2", ManagementScreen_set_info2);
    registerSetter(L, "techCategory", ManagementScreen_set_techCategory);
    registerSetter(L, "currentResearch", ManagementScreen_set_currentResearch);
    registerSetter(L, "researchDescriptionUpdateRequest", ManagementScreen_set_researchDescriptionUpdateRequest);
    registerSetter(L, "lastResearchRate", ManagementScreen_set_lastResearchRate);
    registerSetter(L, "messagesUpdated", ManagementScreen_set_messagesUpdated);
    registerSetter(L, "messagesMutex", ManagementScreen_set_messagesMutex);
    registerSetter(L, "messagesPlayerColor", ManagementScreen_set_messagesPlayerColor);
    registerSetter(L, "messagesNPCColor", ManagementScreen_set_messagesNPCColor);
    registerSetter(L, "aiScreen", ManagementScreen_set_aiScreen);
    registerSetter(L, "aiToolTip", ManagementScreen_set_aiToolTip);
    registerSetter(L, "toolTip", ManagementScreen_set_toolTip);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "getSingleton", ManagementScreenBinding::getSingleton);
    registerStaticMethod(L, "printResearch", ManagementScreenBinding::printResearch);
    lua_setglobal(L, "ManagementScreen");
}

} // namespace KenshiLua