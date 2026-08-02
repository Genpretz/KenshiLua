#include "pch.h"
#include "kenshi\gui\ScreenLabel.h"
#include "ScreenLabelBinding.h"
#include "ScreenLabelInterfaceBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ScreenLabel* getInstance(lua_State* L, int idx)
{
    return checkObject<ScreenLabel>(L, idx, ScreenLabelBinding::getMetatableName());
}

// --- Getters for ScreenLabel ---
static int ScreenLabel_get_caption(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    lua_pushstring(L, instance->caption.c_str());
    return 1;
}

static int ScreenLabel_get_textWidget(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    lua_pushlightuserdata(L, (void*)instance->textWidget);
    return 1;
}

static int ScreenLabel_get_risingSpeed(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    lua_pushnumber(L, instance->risingSpeed);
    return 1;
}

static int ScreenLabel_get_risingHeight(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    lua_pushnumber(L, instance->risingHeight);
    return 1;
}

static int ScreenLabel_get_labelSize(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    lua_pushinteger(L, (lua_Integer)instance->labelSize);
    return 1;
}

static int ScreenLabel_get_trackingHandle(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    return HandBinding::push(L, instance->trackingHandle);
}

static int ScreenLabel_get_trackingOffset(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    pushVector3(L, instance->trackingOffset);
    return 1;
}

static int ScreenLabel_get_destroyed(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    lua_pushboolean(L, instance->destroyed ? 1 : 0);
    return 1;
}

// --- Setters for ScreenLabel ---
static int ScreenLabel_set_caption(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    instance->caption = luaL_checkstring(L, 2);
    return 0;
}

static int ScreenLabel_set_risingSpeed(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    instance->risingSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ScreenLabel_set_risingHeight(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    instance->risingHeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ScreenLabel_set_labelSize(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    instance->labelSize = (ScreenLabel::LabelSize)luaL_checkinteger(L, 2);
    return 0;
}

static int ScreenLabel_set_trackingHandle(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    instance->trackingHandle = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int ScreenLabel_set_trackingOffset(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    readVector3(L, 2, instance->trackingOffset);
    return 0;
}

static int ScreenLabel_set_destroyed(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");
    instance->destroyed = lua_toboolean(L, 2) != 0;
    return 0;
}

int ScreenLabelBinding::setCaption(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");

    const std::string value = luaL_checkstring(L, 2);
    instance->setCaption(value);
    return 0;
}

int ScreenLabelBinding::_NV_setCaption(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");

    const std::string value = luaL_checkstring(L, 2);
    instance->_NV_setCaption(value);
    return 0;
}

int ScreenLabelBinding::setRisingSpeed(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");

    ScreenLabel::RisingSpeed value = (ScreenLabel::RisingSpeed)luaL_checkinteger(L, 2);
    instance->setRisingSpeed(value);
    return 0;
}

int ScreenLabelBinding::_NV_setRisingSpeed(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");

    ScreenLabel::RisingSpeed value = (ScreenLabel::RisingSpeed)luaL_checkinteger(L, 2);
    instance->_NV_setRisingSpeed(value);
    return 0;
}

int ScreenLabelBinding::setPosition(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");

    Ogre::Vector3 value;
    readVector3(L, 2, value);
    instance->setPosition(value);
    return 0;
}

int ScreenLabelBinding::_NV_setPosition(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");

    Ogre::Vector3 value;
    readVector3(L, 2, value);
    instance->_NV_setPosition(value);
    return 0;
}

int ScreenLabelBinding::update(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");

    instance->update();
    return 0;
}

int ScreenLabelBinding::_NV_update(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");

    instance->_NV_update();
    return 0;
}

int ScreenLabelBinding::_DESTRUCTOR(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ScreenLabelBinding::destroy(lua_State* L)
{
    ScreenLabel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabel is nil");

    instance->destroy();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 49: void setTracking(...) - non-string reference arg
  line 50: void _NV_setTracking(...) - non-string reference arg
  line 55: void setColor(...) - unsupported arg type
  line 56: void _NV_setColor(...) - unsupported arg type
  line 63: ScreenLabel* _CONSTRUCTOR(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - ScreenLabel_get_textWidget: MyGUI::TextBox* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 69: color (MyGUI::Colour) - unsupported type
*/

int ScreenLabelBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ScreenLabelBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ScreenLabel object");
    return 1;
}

void ScreenLabelBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ScreenLabelBinding::gc },
        { "__tostring", ScreenLabelBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setCaption", ScreenLabelBinding::setCaption },
        { "_NV_setCaption", ScreenLabelBinding::_NV_setCaption },
        { "setRisingSpeed", ScreenLabelBinding::setRisingSpeed },
        { "_NV_setRisingSpeed", ScreenLabelBinding::_NV_setRisingSpeed },
        { "setPosition", ScreenLabelBinding::setPosition },
        { "_NV_setPosition", ScreenLabelBinding::_NV_setPosition },
        { "update", ScreenLabelBinding::update },
        { "_NV_update", ScreenLabelBinding::_NV_update },
        { "_DESTRUCTOR", ScreenLabelBinding::_DESTRUCTOR },
        { "destroy", ScreenLabelBinding::destroy },
        { 0, 0 }
    };

    registerClass(
        L, 
        ScreenLabelBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ScreenLabelBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "caption", ScreenLabel_get_caption);
    registerGetter(L, "textWidget", ScreenLabel_get_textWidget);
    registerGetter(L, "risingSpeed", ScreenLabel_get_risingSpeed);
    registerGetter(L, "risingHeight", ScreenLabel_get_risingHeight);
    registerGetter(L, "labelSize", ScreenLabel_get_labelSize);
    registerGetter(L, "trackingHandle", ScreenLabel_get_trackingHandle);
    registerGetter(L, "trackingOffset", ScreenLabel_get_trackingOffset);
    registerGetter(L, "destroyed", ScreenLabel_get_destroyed);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "caption", ScreenLabel_set_caption);
    registerSetter(L, "risingSpeed", ScreenLabel_set_risingSpeed);
    registerSetter(L, "risingHeight", ScreenLabel_set_risingHeight);
    registerSetter(L, "labelSize", ScreenLabel_set_labelSize);
    registerSetter(L, "trackingHandle", ScreenLabel_set_trackingHandle);
    registerSetter(L, "trackingOffset", ScreenLabel_set_trackingOffset);
    registerSetter(L, "destroyed", ScreenLabel_set_destroyed);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ScreenLabelInterface
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ScreenLabelBinding::getMetatableName(), ScreenLabelInterfaceBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua