#include "pch.h"
#include <kenshi/gui/DialogueWindow.h>
#include "DialogueWindowBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/DialogueBinding.h"
#include "Bindings/Gui/GUIWindowBinding.h"

namespace KenshiLua
{

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

static int DialogueWindow_get_conversationTextColor(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    // TODO: Unsupported type for conversationTextColor (MyGUI::Colour)
    return luaL_error(L, "Unsupported property 'conversationTextColor' (type: MyGUI::Colour)");
}

static int DialogueWindow_get_conversationTextSelectedColor(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    // TODO: Unsupported type for conversationTextSelectedColor (MyGUI::Colour)
    return luaL_error(L, "Unsupported property 'conversationTextSelectedColor' (type: MyGUI::Colour)");
}

static int DialogueWindow_get_replyTexts(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    // TODO: Unsupported type for replyTexts (Ogre::FastArray<MyGUI::EditBox*>)
    return luaL_error(L, "Unsupported property 'replyTexts' (type: Ogre::FastArray<MyGUI::EditBox*>)");
}

// --- Setters for DialogueWindow ---
static int DialogueWindow_set_dialogue(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for dialogue");
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
    return luaL_error(L, "Read-only or unsupported setter type for conversationPC");
}

static int DialogueWindow_set_conversationPCPanel(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for conversationPCPanel");
}

static int DialogueWindow_set_conversationNPCPanel(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for conversationNPCPanel");
}

static int DialogueWindow_set_conversationNPCNameText(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for conversationNPCNameText");
}

static int DialogueWindow_set_conversationPCNameText(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for conversationPCNameText");
}

static int DialogueWindow_set_conversationPCMoneyText(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for conversationPCMoneyText");
}

static int DialogueWindow_set_conversationNPCSpeech(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for conversationNPCSpeech");
}

static int DialogueWindow_set_conversationPCSpeechPanel(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for conversationPCSpeechPanel");
}

static int DialogueWindow_set_conversationNPCPortrait(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for conversationNPCPortrait");
}

static int DialogueWindow_set_conversationPCPortrait(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for conversationPCPortrait");
}

static int DialogueWindow_set_conversationTextColor(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for conversationTextColor");
}

static int DialogueWindow_set_conversationTextSelectedColor(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for conversationTextSelectedColor");
}

static int DialogueWindow_set_replyTexts(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for replyTexts");
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

    std::string text = luaL_checkstring(L, 2);
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

int DialogueWindowBinding::_CONSTRUCTOR(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    DialogueWindow* result = instance->_CONSTRUCTOR();
    return pushObject<DialogueWindow>(L, result, DialogueWindowBinding::getMetatableName());
}

int DialogueWindowBinding::_DESTRUCTOR(lua_State* L)
{
    DialogueWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogueWindow is nil");

    instance->_DESTRUCTOR();
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
Skipped methods needing manual binding:
  line 16: void show(...) - overloaded method
  line 18: void show(...) - overloaded method
  line 19: void hide(...) - unsupported arg type
  line 27: void setResponses(...) - unsupported arg type
  line 29: void changePortrait(...) - unsupported arg type
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
        { "_NV_show", DialogueWindowBinding::_NV_show },
        { "isVisible", DialogueWindowBinding::isVisible },
        { "_NV_isVisible", DialogueWindowBinding::_NV_isVisible },
        { "update", DialogueWindowBinding::update },
        { "_NV_update", DialogueWindowBinding::_NV_update },
        { "getTop", DialogueWindowBinding::getTop },
        { "activateResponse", DialogueWindowBinding::activateResponse },
        { "setNPCText", DialogueWindowBinding::setNPCText },
        { "clearResponses", DialogueWindowBinding::clearResponses },
        { "_CONSTRUCTOR", DialogueWindowBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", DialogueWindowBinding::_DESTRUCTOR },
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
    lua_pushcfunction(L, DialogueWindow_get_dialogue);
    lua_setfield(L, -2, "dialogue");
    lua_pushcfunction(L, DialogueWindow_get_conversationPanelsMargin);
    lua_setfield(L, -2, "conversationPanelsMargin");
    lua_pushcfunction(L, DialogueWindow_get_converstaionPCPanelBottom);
    lua_setfield(L, -2, "converstaionPCPanelBottom");
    lua_pushcfunction(L, DialogueWindow_get_conversationPCSpeechPanelMinHeight);
    lua_setfield(L, -2, "conversationPCSpeechPanelMinHeight");
    lua_pushcfunction(L, DialogueWindow_get_conversationNPCSpeechPanelMinHeight);
    lua_setfield(L, -2, "conversationNPCSpeechPanelMinHeight");
    lua_pushcfunction(L, DialogueWindow_get_conversationPCPanelHeightDiffSpeechPanel);
    lua_setfield(L, -2, "conversationPCPanelHeightDiffSpeechPanel");
    lua_pushcfunction(L, DialogueWindow_get_conversationNPCPanelHeightDiffSpeechPanel);
    lua_setfield(L, -2, "conversationNPCPanelHeightDiffSpeechPanel");
    lua_pushcfunction(L, DialogueWindow_get_conversationPC);
    lua_setfield(L, -2, "conversationPC");
    lua_pushcfunction(L, DialogueWindow_get_conversationPCPanel);
    lua_setfield(L, -2, "conversationPCPanel");
    lua_pushcfunction(L, DialogueWindow_get_conversationNPCPanel);
    lua_setfield(L, -2, "conversationNPCPanel");
    lua_pushcfunction(L, DialogueWindow_get_conversationNPCNameText);
    lua_setfield(L, -2, "conversationNPCNameText");
    lua_pushcfunction(L, DialogueWindow_get_conversationPCNameText);
    lua_setfield(L, -2, "conversationPCNameText");
    lua_pushcfunction(L, DialogueWindow_get_conversationPCMoneyText);
    lua_setfield(L, -2, "conversationPCMoneyText");
    lua_pushcfunction(L, DialogueWindow_get_conversationNPCSpeech);
    lua_setfield(L, -2, "conversationNPCSpeech");
    lua_pushcfunction(L, DialogueWindow_get_conversationPCSpeechPanel);
    lua_setfield(L, -2, "conversationPCSpeechPanel");
    lua_pushcfunction(L, DialogueWindow_get_conversationNPCPortrait);
    lua_setfield(L, -2, "conversationNPCPortrait");
    lua_pushcfunction(L, DialogueWindow_get_conversationPCPortrait);
    lua_setfield(L, -2, "conversationPCPortrait");
    lua_pushcfunction(L, DialogueWindow_get_conversationTextColor);
    lua_setfield(L, -2, "conversationTextColor");
    lua_pushcfunction(L, DialogueWindow_get_conversationTextSelectedColor);
    lua_setfield(L, -2, "conversationTextSelectedColor");
    lua_pushcfunction(L, DialogueWindow_get_replyTexts);
    lua_setfield(L, -2, "replyTexts");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DialogueWindow_set_dialogue);
    lua_setfield(L, -2, "dialogue");
    lua_pushcfunction(L, DialogueWindow_set_conversationPanelsMargin);
    lua_setfield(L, -2, "conversationPanelsMargin");
    lua_pushcfunction(L, DialogueWindow_set_converstaionPCPanelBottom);
    lua_setfield(L, -2, "converstaionPCPanelBottom");
    lua_pushcfunction(L, DialogueWindow_set_conversationPCSpeechPanelMinHeight);
    lua_setfield(L, -2, "conversationPCSpeechPanelMinHeight");
    lua_pushcfunction(L, DialogueWindow_set_conversationNPCSpeechPanelMinHeight);
    lua_setfield(L, -2, "conversationNPCSpeechPanelMinHeight");
    lua_pushcfunction(L, DialogueWindow_set_conversationPCPanelHeightDiffSpeechPanel);
    lua_setfield(L, -2, "conversationPCPanelHeightDiffSpeechPanel");
    lua_pushcfunction(L, DialogueWindow_set_conversationNPCPanelHeightDiffSpeechPanel);
    lua_setfield(L, -2, "conversationNPCPanelHeightDiffSpeechPanel");
    lua_pushcfunction(L, DialogueWindow_set_conversationPC);
    lua_setfield(L, -2, "conversationPC");
    lua_pushcfunction(L, DialogueWindow_set_conversationPCPanel);
    lua_setfield(L, -2, "conversationPCPanel");
    lua_pushcfunction(L, DialogueWindow_set_conversationNPCPanel);
    lua_setfield(L, -2, "conversationNPCPanel");
    lua_pushcfunction(L, DialogueWindow_set_conversationNPCNameText);
    lua_setfield(L, -2, "conversationNPCNameText");
    lua_pushcfunction(L, DialogueWindow_set_conversationPCNameText);
    lua_setfield(L, -2, "conversationPCNameText");
    lua_pushcfunction(L, DialogueWindow_set_conversationPCMoneyText);
    lua_setfield(L, -2, "conversationPCMoneyText");
    lua_pushcfunction(L, DialogueWindow_set_conversationNPCSpeech);
    lua_setfield(L, -2, "conversationNPCSpeech");
    lua_pushcfunction(L, DialogueWindow_set_conversationPCSpeechPanel);
    lua_setfield(L, -2, "conversationPCSpeechPanel");
    lua_pushcfunction(L, DialogueWindow_set_conversationNPCPortrait);
    lua_setfield(L, -2, "conversationNPCPortrait");
    lua_pushcfunction(L, DialogueWindow_set_conversationPCPortrait);
    lua_setfield(L, -2, "conversationPCPortrait");
    lua_pushcfunction(L, DialogueWindow_set_conversationTextColor);
    lua_setfield(L, -2, "conversationTextColor");
    lua_pushcfunction(L, DialogueWindow_set_conversationTextSelectedColor);
    lua_setfield(L, -2, "conversationTextSelectedColor");
    lua_pushcfunction(L, DialogueWindow_set_replyTexts);
    lua_setfield(L, -2, "replyTexts");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GUIWindow
    // setMetatableParent(L, DialogueWindowBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
