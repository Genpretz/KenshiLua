#include "pch.h"
#include "kenshi\gui\DialogueWindow.h"
#include "DialogueWindowBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/DialogueBinding.h"
#include "Bindings/Gui/GUIWindowBinding.h"
#include "Bindings/Util/OgreFastArrayBinding.h"

namespace KenshiLua
{
typedef OgreFastArrayPtrBinding<MyGUI::EditBox*> EditBoxFastArrayBinding;

static DialogueWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<DialogueWindow>(L, idx, DialogueWindowBinding::getMetatableName());
}

// --- Getters for DialogueWindow ---
static int DialogueWindow_get_dialogue(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return pushObject<Dialogue>(L, instance->dialogue, DialogueBinding::getMetatableName());
}

static int DialogueWindow_get_conversationPanelsMargin(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushinteger(L, instance->conversationPanelsMargin);
    return 1;
}

static int DialogueWindow_get_converstaionPCPanelBottom(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushinteger(L, instance->converstaionPCPanelBottom);
    return 1;
}

static int DialogueWindow_get_conversationPCSpeechPanelMinHeight(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushinteger(L, instance->conversationPCSpeechPanelMinHeight);
    return 1;
}

static int DialogueWindow_get_conversationNPCSpeechPanelMinHeight(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushinteger(L, instance->conversationNPCSpeechPanelMinHeight);
    return 1;
}

static int DialogueWindow_get_conversationPCPanelHeightDiffSpeechPanel(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushinteger(L, instance->conversationPCPanelHeightDiffSpeechPanel);
    return 1;
}

static int DialogueWindow_get_conversationNPCPanelHeightDiffSpeechPanel(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushinteger(L, instance->conversationNPCPanelHeightDiffSpeechPanel);
    return 1;
}

static int DialogueWindow_get_conversationPC(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return pushObject<Character>(L, instance->conversationPC, CharacterBinding::getMetatableName());
}

static int DialogueWindow_get_conversationPCPanel(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->conversationPCPanel);
    return 1;
}

static int DialogueWindow_get_conversationNPCPanel(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->conversationNPCPanel);
    return 1;
}

static int DialogueWindow_get_conversationNPCNameText(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->conversationNPCNameText);
    return 1;
}

static int DialogueWindow_get_conversationPCNameText(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->conversationPCNameText);
    return 1;
}

static int DialogueWindow_get_conversationPCMoneyText(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->conversationPCMoneyText);
    return 1;
}

static int DialogueWindow_get_conversationNPCSpeech(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->conversationNPCSpeech);
    return 1;
}

static int DialogueWindow_get_conversationPCSpeechPanel(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->conversationPCSpeechPanel);
    return 1;
}

static int DialogueWindow_get_conversationNPCPortrait(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->conversationNPCPortrait);
    return 1;
}

static int DialogueWindow_get_conversationPCPortrait(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->conversationPCPortrait);
    return 1;
}

static int DialogueWindow_get_replyTexts(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return pushObject<EditBoxFastArrayBinding::ArrayType>(L, &instance->replyTexts, "Ogre::FastArray<MyGUI::EditBox*>");
}

// --- Setters for DialogueWindow ---
static int DialogueWindow_set_replyTexts(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    if (lua_isnoneornil(L, 2))
    {
        instance->replyTexts.clear();
        return 0;
    }
    auto* src = EditBoxFastArrayBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set replyTexts must be Ogre::FastArray<MyGUI::EditBox*>");
    instance->replyTexts = *src;
    return 0;
}

static int DialogueWindow_set_dialogue(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    instance->dialogue = lua_isnoneornil(L, 2) ? nullptr : checkObject<Dialogue>(L, 2, DialogueBinding::getMetatableName());
    return 0;
}

static int DialogueWindow_set_conversationPanelsMargin(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    instance->conversationPanelsMargin = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogueWindow_set_converstaionPCPanelBottom(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    instance->converstaionPCPanelBottom = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogueWindow_set_conversationPCSpeechPanelMinHeight(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    instance->conversationPCSpeechPanelMinHeight = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogueWindow_set_conversationNPCSpeechPanelMinHeight(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    instance->conversationNPCSpeechPanelMinHeight = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogueWindow_set_conversationPCPanelHeightDiffSpeechPanel(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    instance->conversationPCPanelHeightDiffSpeechPanel = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogueWindow_set_conversationNPCPanelHeightDiffSpeechPanel(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    instance->conversationNPCPanelHeightDiffSpeechPanel = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogueWindow_set_conversationPC(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    instance->conversationPC = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

int DialogueWindowBinding::getVisible(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueWindowBinding::setVisible(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setVisible(visible);
    return 0;
}

int DialogueWindowBinding::_NV_show(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_show(on);
    return 0;
}

int DialogueWindowBinding::hide(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    Dialogue* _dialogue = checkObject<Dialogue>(L, 2, DialogueBinding::getMetatableName());
    instance->hide(_dialogue);
    return 0;
}

int DialogueWindowBinding::isVisible(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    bool result = instance->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueWindowBinding::_NV_isVisible(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    bool result = instance->_NV_isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DialogueWindowBinding::update(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    instance->update();
    return 0;
}

int DialogueWindowBinding::_NV_update(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    instance->_NV_update();
    return 0;
}

int DialogueWindowBinding::getTop(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    int result = instance->getTop();
    lua_pushinteger(L, result);
    return 1;
}

int DialogueWindowBinding::activateResponse(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    int index = (int)luaL_checkinteger(L, 2);
    instance->activateResponse(index);
    return 0;
}

int DialogueWindowBinding::setNPCText(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    const std::string text = luaL_checkstring(L, 2);
    instance->setNPCText(text);
    return 0;
}

int DialogueWindowBinding::clearResponses(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    instance->clearResponses();
    return 0;
}

int DialogueWindowBinding::changePortrait(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool player = lua_toboolean(L, 3) != 0;
    instance->changePortrait(character, player);
    return 0;
}

int DialogueWindowBinding::show(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    if (lua_isboolean(L, 2))
    {
        bool on = lua_toboolean(L, 2) != 0;
        instance->show(on);
    }
    else
    {
        Dialogue* _dialogue = checkObject<Dialogue>(L, 2, DialogueBinding::getMetatableName());
        instance->show(_dialogue);
    }
    return 0;
}

int DialogueWindowBinding::setResponses(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    luaL_checktype(L, 2, LUA_TTABLE);
    Ogre::vector<std::string>::type responses;
    int len = (int)lua_objlen(L, 2);
    for (int i = 1; i <= len; ++i)
    {
        lua_rawgeti(L, 2, i);
        if (lua_isstring(L, -1))
        {
            responses.push_back(lua_tostring(L, -1));
        }
        lua_pop(L, 1);
    }
    instance->setResponses(responses);
    return 0;
}

int DialogueWindowBinding::updatePanelsPosition(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    instance->updatePanelsPosition();
    return 0;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - EditBoxFastArrayBinding: MyGUI::EditBox* (unbound pointer element)
*/

/*
Skipped properties needing manual binding:
  line 53: conversationTextColor (MyGUI::Colour) - unsupported type
  line 54: conversationTextSelectedColor (MyGUI::Colour) - unsupported type
*/

int DialogueWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DialogueWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DialogueWindow object");
    return 1;
}

void DialogueWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogueWindowBinding::gc },
        { "__tostring", DialogueWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getVisible", DialogueWindowBinding::getVisible },
        { "setVisible", DialogueWindowBinding::setVisible },
        { "show", DialogueWindowBinding::show },
        { "_NV_show", DialogueWindowBinding::_NV_show },
        { "hide", DialogueWindowBinding::hide },
        { "isVisible", DialogueWindowBinding::isVisible },
        { "_NV_isVisible", DialogueWindowBinding::_NV_isVisible },
        { "update", DialogueWindowBinding::update },
        { "_NV_update", DialogueWindowBinding::_NV_update },
        { "getTop", DialogueWindowBinding::getTop },
        { "activateResponse", DialogueWindowBinding::activateResponse },
        { "setNPCText", DialogueWindowBinding::setNPCText },
        { "setResponses", DialogueWindowBinding::setResponses },
        { "clearResponses", DialogueWindowBinding::clearResponses },
        { "changePortrait", DialogueWindowBinding::changePortrait },
        { "updatePanelsPosition", DialogueWindowBinding::updatePanelsPosition },
        { 0, 0 }
    };

    registerClass(
        L, 
        DialogueWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DialogueWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "dialogue", DialogueWindow_get_dialogue);
    registerGetter(L, "conversationPanelsMargin", DialogueWindow_get_conversationPanelsMargin);
    registerGetter(L, "converstaionPCPanelBottom", DialogueWindow_get_converstaionPCPanelBottom);
    registerGetter(L, "conversationPCSpeechPanelMinHeight", DialogueWindow_get_conversationPCSpeechPanelMinHeight);
    registerGetter(L, "conversationNPCSpeechPanelMinHeight", DialogueWindow_get_conversationNPCSpeechPanelMinHeight);
    registerGetter(L, "conversationPCPanelHeightDiffSpeechPanel", DialogueWindow_get_conversationPCPanelHeightDiffSpeechPanel);
    registerGetter(L, "conversationNPCPanelHeightDiffSpeechPanel", DialogueWindow_get_conversationNPCPanelHeightDiffSpeechPanel);
    registerGetter(L, "conversationPC", DialogueWindow_get_conversationPC);
    registerGetter(L, "conversationPCPanel", DialogueWindow_get_conversationPCPanel);
    registerGetter(L, "conversationNPCPanel", DialogueWindow_get_conversationNPCPanel);
    registerGetter(L, "conversationNPCNameText", DialogueWindow_get_conversationNPCNameText);
    registerGetter(L, "conversationPCNameText", DialogueWindow_get_conversationPCNameText);
    registerGetter(L, "conversationPCMoneyText", DialogueWindow_get_conversationPCMoneyText);
    registerGetter(L, "conversationNPCSpeech", DialogueWindow_get_conversationNPCSpeech);
    registerGetter(L, "conversationPCSpeechPanel", DialogueWindow_get_conversationPCSpeechPanel);
    registerGetter(L, "conversationNPCPortrait", DialogueWindow_get_conversationNPCPortrait);
    registerGetter(L, "conversationPCPortrait", DialogueWindow_get_conversationPCPortrait);
    registerGetter(L, "replyTexts", DialogueWindow_get_replyTexts);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "dialogue", DialogueWindow_set_dialogue);
    registerSetter(L, "conversationPanelsMargin", DialogueWindow_set_conversationPanelsMargin);
    registerSetter(L, "converstaionPCPanelBottom", DialogueWindow_set_converstaionPCPanelBottom);
    registerSetter(L, "conversationPCSpeechPanelMinHeight", DialogueWindow_set_conversationPCSpeechPanelMinHeight);
    registerSetter(L, "conversationNPCSpeechPanelMinHeight", DialogueWindow_set_conversationNPCSpeechPanelMinHeight);
    registerSetter(L, "conversationPCPanelHeightDiffSpeechPanel", DialogueWindow_set_conversationPCPanelHeightDiffSpeechPanel);
    registerSetter(L, "conversationNPCPanelHeightDiffSpeechPanel", DialogueWindow_set_conversationNPCPanelHeightDiffSpeechPanel);
    registerSetter(L, "conversationPC", DialogueWindow_set_conversationPC);
    registerSetter(L, "replyTexts", DialogueWindow_set_replyTexts);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    EditBoxFastArrayBinding::registerBinding(L, "Ogre::FastArray<MyGUI::EditBox*>", nullptr);

    // Wire up inheritance to GUIWindow
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, DialogueWindowBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua