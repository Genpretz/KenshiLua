#include "pch.h"
#include "kenshi\gui\Tooltip.h"
#include "ToolTipBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/Util/StringPairBinding.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"

namespace KenshiLua
{

static ToolTip* getInstance(lua_State* L, int idx)
{
    return checkObject<ToolTip>(L, idx, ToolTipBinding::getMetatableName());
}

// --- Getters for ToolTip ---
static int ToolTip_get_panel(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    return MyGUIBindings::pushWidget(L, instance->panel);
}

static int ToolTip_get_panelWidth(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    lua_pushinteger(L, instance->panelWidth);
    return 1;
}

static int ToolTip_get_lineMarginH(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    lua_pushnumber(L, instance->lineMarginH);
    return 1;
}

static int ToolTip_get_panelMarginV(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    lua_pushinteger(L, instance->panelMarginV);
    return 1;
}

static int ToolTip_get_lineSpacing(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    lua_pushinteger(L, instance->lineSpacing);
    return 1;
}

static int ToolTip_get_caller(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    return MyGUIBindings::pushWidget(L, instance->caller);
}

// --- Setters for ToolTip ---
static int ToolTip_set_panelWidth(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    instance->panelWidth = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ToolTip_set_lineMarginH(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    instance->lineMarginH = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ToolTip_set_panelMarginV(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    instance->panelMarginV = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ToolTip_set_lineSpacing(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    instance->lineSpacing = (int)luaL_checkinteger(L, 2);
    return 0;
}

int ToolTipBinding::update(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    instance->update();
    return 0;
}

int ToolTipBinding::_NV_update(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    instance->_NV_update();
    return 0;
}

int ToolTipBinding::hide(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    instance->hide();
    return 0;
}

int ToolTipBinding::_NV_hide(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    instance->_NV_hide();
    return 0;
}

int ToolTipBinding::getVisible(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ToolTipBinding::setVisible(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setVisible(visible);
    return 0;
}

int ToolTipBinding::_NV_setVisible(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(visible);
    return 0;
}

int ToolTipBinding::addLine(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    const std::string textLeft = luaL_checkstring(L, 2);
    const std::string textRight = luaL_checkstring(L, 3);
    instance->addLine(textLeft, textRight);
    return 0;
}

int ToolTipBinding::clearLines(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");

    instance->clearLines();
    return 0;
}

// setup(Widget*, hand&)
int ToolTipBinding::setup_hand(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    hand* data = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    if (!data) return luaL_error(L, "Argument 3 must be hand");
    instance->setup(widget, *data);
    return 0;
}

// setup(Widget*, GameData*)
int ToolTipBinding::setup_gamedata(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    GameData* data = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->setup(widget, data);
    return 0;
}

// setup(Widget*, lektor<StringPair>&)
int ToolTipBinding::setup_stringpairs(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    lektor<StringPair>* lines = LektorValueBinding<StringPair>::get(L, 3);
    if (!lines) return luaL_error(L, "Argument 3 must be lektor<StringPair>");
    instance->setup(widget, *lines);
    return 0;
}

// setup(Widget*, string)
int ToolTipBinding::setup_text(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    const std::string text = luaL_checkstring(L, 3);
    instance->setup(widget, text);
    return 0;
}

int ToolTipBinding::clear(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->clear(widget);
    return 0;
}

int ToolTipBinding::_NV_clear(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_NV_clear(widget);
    return 0;
}

int ToolTipBinding::_setup(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_setup(widget);
    return 0;
}

int ToolTipBinding::_NV__setup(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_NV__setup(widget);
    return 0;
}

int ToolTipBinding::clearData(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->clearData(widget);
    return 0;
}

int ToolTipBinding::_NV_clearData(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_NV_clearData(widget);
    return 0;
}

int ToolTipBinding::show(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    MyGUI::IntPoint point = MyGUIBindings::readIntPoint(L, 3);
    instance->show(sender, point);
    return 0;
}

int ToolTipBinding::_NV_show(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    MyGUI::IntPoint point = MyGUIBindings::readIntPoint(L, 3);
    instance->_NV_show(sender, point);
    return 0;
}

int ToolTipBinding::setContent(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->setContent(widget);
    return 0;
}

int ToolTipBinding::_NV_setContent(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_NV_setContent(widget);
    return 0;
}

int ToolTipBinding::showText(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->showText(widget);
    return 0;
}

int ToolTipBinding::showMultiLine(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->showMultiLine(widget);
    return 0;
}

// showGameData(hand&) overload
int ToolTipBinding::showGameData_hand(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 must be hand");
    instance->showGameData(*h);
    return 0;
}

// showGameData(Widget*) overload
int ToolTipBinding::showGameData_widget(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->showGameData(widget);
    return 0;
}

int ToolTipBinding::setPosition(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::IntPoint point = MyGUIBindings::readIntPoint(L, 2);
    instance->setPosition(point);
    return 0;
}

int ToolTipBinding::_NV_setPosition(lua_State* L)
{
    ToolTip* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTip is nil");
    MyGUI::IntPoint point = MyGUIBindings::readIntPoint(L, 2);
    instance->_NV_setPosition(point);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 70: void notifyToolTip(...) - MyGUI::ToolTipInfo& unsupported
*/

/*
Skipped properties needing manual binding:
  line 72: lines (Ogre::vector<ToolTip::ToolTipLine*>::type) - unsupported type
*/

int ToolTipBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ToolTipBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ToolTip object");
    return 1;
}

void ToolTipBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ToolTipBinding::gc },
        { "__tostring", ToolTipBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", ToolTipBinding::update },
        { "_NV_update", ToolTipBinding::_NV_update },
        { "hide", ToolTipBinding::hide },
        { "_NV_hide", ToolTipBinding::_NV_hide },
        { "getVisible", ToolTipBinding::getVisible },
        { "setVisible", ToolTipBinding::setVisible },
        { "_NV_setVisible", ToolTipBinding::_NV_setVisible },
        { "addLine", ToolTipBinding::addLine },
        { "clearLines", ToolTipBinding::clearLines },
        { "setup_hand", ToolTipBinding::setup_hand },
        { "setup_gamedata", ToolTipBinding::setup_gamedata },
        { "setup_stringpairs", ToolTipBinding::setup_stringpairs },
        { "setup_text", ToolTipBinding::setup_text },
        { "clear", ToolTipBinding::clear },
        { "_NV_clear", ToolTipBinding::_NV_clear },
        { "_setup", ToolTipBinding::_setup },
        { "_NV__setup", ToolTipBinding::_NV__setup },
        { "clearData", ToolTipBinding::clearData },
        { "_NV_clearData", ToolTipBinding::_NV_clearData },
        { "show", ToolTipBinding::show },
        { "_NV_show", ToolTipBinding::_NV_show },
        { "setContent", ToolTipBinding::setContent },
        { "_NV_setContent", ToolTipBinding::_NV_setContent },
        { "showText", ToolTipBinding::showText },
        { "showMultiLine", ToolTipBinding::showMultiLine },
        { "showGameData_hand", ToolTipBinding::showGameData_hand },
        { "showGameData_widget", ToolTipBinding::showGameData_widget },
        { "setPosition", ToolTipBinding::setPosition },
        { "_NV_setPosition", ToolTipBinding::_NV_setPosition },
        { 0, 0 }
    };

    registerClass(
        L, 
        ToolTipBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ToolTipBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "panel", ToolTip_get_panel);
    registerGetter(L, "panelWidth", ToolTip_get_panelWidth);
    registerGetter(L, "lineMarginH", ToolTip_get_lineMarginH);
    registerGetter(L, "panelMarginV", ToolTip_get_panelMarginV);
    registerGetter(L, "lineSpacing", ToolTip_get_lineSpacing);
    registerGetter(L, "caller", ToolTip_get_caller);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "panelWidth", ToolTip_set_panelWidth);
    registerSetter(L, "lineMarginH", ToolTip_set_lineMarginH);
    registerSetter(L, "panelMarginV", ToolTip_set_panelMarginV);
    registerSetter(L, "lineSpacing", ToolTip_set_lineSpacing);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, ToolTipBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
