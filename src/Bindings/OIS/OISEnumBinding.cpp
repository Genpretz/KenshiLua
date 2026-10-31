#include "pch.h"

#include "Bindings/OIS/OISEnumBinding.h"
#include "Lua/BindingHelpers.h"

#include "OIS/OISPrereqs.h"
#include "OIS/OISKeyboard.h"
#include "OIS/OISMouse.h"
#include "OIS/OISException.h"
#include "OIS/OISInterface.h"
#include "OIS/OISInputManager.h"
#include "OIS/OISEffect.h"

#include <lua.hpp>

namespace KenshiLua
{
    // OIS/OISPrereqs.h

    void registerOISType(lua_State* L)
    {
        lua_createtable(L, 0, 5);

        setEnum(L, "OISUnknown", OIS::OISUnknown);
        setEnum(L, "OISKeyboard", OIS::OISKeyboard);
        setEnum(L, "OISMouse", OIS::OISMouse);
        setEnum(L, "OISJoyStick", OIS::OISJoyStick);
        setEnum(L, "OISTablet", OIS::OISTablet);

        setNestedClassTable(L, "OIS", "Type");
        lua_pop(L, 1);
    }

    void registerOISComponentType(lua_State* L)
    {
        lua_createtable(L, 0, 6);

        setEnum(L, "OIS_Unknown", OIS::OIS_Unknown);
        setEnum(L, "OIS_Button", OIS::OIS_Button);
        setEnum(L, "OIS_Axis", OIS::OIS_Axis);
        setEnum(L, "OIS_Slider", OIS::OIS_Slider);
        setEnum(L, "OIS_POV", OIS::OIS_POV);
        setEnum(L, "OIS_Vector3", OIS::OIS_Vector3);

        setNestedClassTable(L, "OIS", "ComponentType");
        lua_pop(L, 1);
    }

    // OIS/OISKeyboard.h

    void registerOISKeyCode(lua_State* L)
    {
        lua_createtable(L, 0, 145);

        setEnum(L, "KC_UNASSIGNED", OIS::KC_UNASSIGNED);
        setEnum(L, "KC_ESCAPE", OIS::KC_ESCAPE);
        setEnum(L, "KC_1", OIS::KC_1);
        setEnum(L, "KC_2", OIS::KC_2);
        setEnum(L, "KC_3", OIS::KC_3);
        setEnum(L, "KC_4", OIS::KC_4);
        setEnum(L, "KC_5", OIS::KC_5);
        setEnum(L, "KC_6", OIS::KC_6);
        setEnum(L, "KC_7", OIS::KC_7);
        setEnum(L, "KC_8", OIS::KC_8);
        setEnum(L, "KC_9", OIS::KC_9);
        setEnum(L, "KC_0", OIS::KC_0);
        setEnum(L, "KC_MINUS", OIS::KC_MINUS);
        setEnum(L, "KC_EQUALS", OIS::KC_EQUALS);
        setEnum(L, "KC_BACK", OIS::KC_BACK);
        setEnum(L, "KC_TAB", OIS::KC_TAB);
        setEnum(L, "KC_Q", OIS::KC_Q);
        setEnum(L, "KC_W", OIS::KC_W);
        setEnum(L, "KC_E", OIS::KC_E);
        setEnum(L, "KC_R", OIS::KC_R);
        setEnum(L, "KC_T", OIS::KC_T);
        setEnum(L, "KC_Y", OIS::KC_Y);
        setEnum(L, "KC_U", OIS::KC_U);
        setEnum(L, "KC_I", OIS::KC_I);
        setEnum(L, "KC_O", OIS::KC_O);
        setEnum(L, "KC_P", OIS::KC_P);
        setEnum(L, "KC_LBRACKET", OIS::KC_LBRACKET);
        setEnum(L, "KC_RBRACKET", OIS::KC_RBRACKET);
        setEnum(L, "KC_RETURN", OIS::KC_RETURN);
        setEnum(L, "KC_LCONTROL", OIS::KC_LCONTROL);
        setEnum(L, "KC_A", OIS::KC_A);
        setEnum(L, "KC_S", OIS::KC_S);
        setEnum(L, "KC_D", OIS::KC_D);
        setEnum(L, "KC_F", OIS::KC_F);
        setEnum(L, "KC_G", OIS::KC_G);
        setEnum(L, "KC_H", OIS::KC_H);
        setEnum(L, "KC_J", OIS::KC_J);
        setEnum(L, "KC_K", OIS::KC_K);
        setEnum(L, "KC_L", OIS::KC_L);
        setEnum(L, "KC_SEMICOLON", OIS::KC_SEMICOLON);
        setEnum(L, "KC_APOSTROPHE", OIS::KC_APOSTROPHE);
        setEnum(L, "KC_GRAVE", OIS::KC_GRAVE);
        setEnum(L, "KC_LSHIFT", OIS::KC_LSHIFT);
        setEnum(L, "KC_BACKSLASH", OIS::KC_BACKSLASH);
        setEnum(L, "KC_Z", OIS::KC_Z);
        setEnum(L, "KC_X", OIS::KC_X);
        setEnum(L, "KC_C", OIS::KC_C);
        setEnum(L, "KC_V", OIS::KC_V);
        setEnum(L, "KC_B", OIS::KC_B);
        setEnum(L, "KC_N", OIS::KC_N);
        setEnum(L, "KC_M", OIS::KC_M);
        setEnum(L, "KC_COMMA", OIS::KC_COMMA);
        setEnum(L, "KC_PERIOD", OIS::KC_PERIOD);
        setEnum(L, "KC_SLASH", OIS::KC_SLASH);
        setEnum(L, "KC_RSHIFT", OIS::KC_RSHIFT);
        setEnum(L, "KC_MULTIPLY", OIS::KC_MULTIPLY);
        setEnum(L, "KC_LMENU", OIS::KC_LMENU);
        setEnum(L, "KC_SPACE", OIS::KC_SPACE);
        setEnum(L, "KC_CAPITAL", OIS::KC_CAPITAL);
        setEnum(L, "KC_F1", OIS::KC_F1);
        setEnum(L, "KC_F2", OIS::KC_F2);
        setEnum(L, "KC_F3", OIS::KC_F3);
        setEnum(L, "KC_F4", OIS::KC_F4);
        setEnum(L, "KC_F5", OIS::KC_F5);
        setEnum(L, "KC_F6", OIS::KC_F6);
        setEnum(L, "KC_F7", OIS::KC_F7);
        setEnum(L, "KC_F8", OIS::KC_F8);
        setEnum(L, "KC_F9", OIS::KC_F9);
        setEnum(L, "KC_F10", OIS::KC_F10);
        setEnum(L, "KC_NUMLOCK", OIS::KC_NUMLOCK);
        setEnum(L, "KC_SCROLL", OIS::KC_SCROLL);
        setEnum(L, "KC_NUMPAD7", OIS::KC_NUMPAD7);
        setEnum(L, "KC_NUMPAD8", OIS::KC_NUMPAD8);
        setEnum(L, "KC_NUMPAD9", OIS::KC_NUMPAD9);
        setEnum(L, "KC_SUBTRACT", OIS::KC_SUBTRACT);
        setEnum(L, "KC_NUMPAD4", OIS::KC_NUMPAD4);
        setEnum(L, "KC_NUMPAD5", OIS::KC_NUMPAD5);
        setEnum(L, "KC_NUMPAD6", OIS::KC_NUMPAD6);
        setEnum(L, "KC_ADD", OIS::KC_ADD);
        setEnum(L, "KC_NUMPAD1", OIS::KC_NUMPAD1);
        setEnum(L, "KC_NUMPAD2", OIS::KC_NUMPAD2);
        setEnum(L, "KC_NUMPAD3", OIS::KC_NUMPAD3);
        setEnum(L, "KC_NUMPAD0", OIS::KC_NUMPAD0);
        setEnum(L, "KC_DECIMAL", OIS::KC_DECIMAL);
        setEnum(L, "KC_OEM_102", OIS::KC_OEM_102);
        setEnum(L, "KC_F11", OIS::KC_F11);
        setEnum(L, "KC_F12", OIS::KC_F12);
        setEnum(L, "KC_F13", OIS::KC_F13);
        setEnum(L, "KC_F14", OIS::KC_F14);
        setEnum(L, "KC_F15", OIS::KC_F15);
        setEnum(L, "KC_KANA", OIS::KC_KANA);
        setEnum(L, "KC_ABNT_C1", OIS::KC_ABNT_C1);
        setEnum(L, "KC_CONVERT", OIS::KC_CONVERT);
        setEnum(L, "KC_NOCONVERT", OIS::KC_NOCONVERT);
        setEnum(L, "KC_YEN", OIS::KC_YEN);
        setEnum(L, "KC_ABNT_C2", OIS::KC_ABNT_C2);
        setEnum(L, "KC_NUMPADEQUALS", OIS::KC_NUMPADEQUALS);
        setEnum(L, "KC_PREVTRACK", OIS::KC_PREVTRACK);
        setEnum(L, "KC_AT", OIS::KC_AT);
        setEnum(L, "KC_COLON", OIS::KC_COLON);
        setEnum(L, "KC_UNDERLINE", OIS::KC_UNDERLINE);
        setEnum(L, "KC_KANJI", OIS::KC_KANJI);
        setEnum(L, "KC_STOP", OIS::KC_STOP);
        setEnum(L, "KC_AX", OIS::KC_AX);
        setEnum(L, "KC_UNLABELED", OIS::KC_UNLABELED);
        setEnum(L, "KC_NEXTTRACK", OIS::KC_NEXTTRACK);
        setEnum(L, "KC_NUMPADENTER", OIS::KC_NUMPADENTER);
        setEnum(L, "KC_RCONTROL", OIS::KC_RCONTROL);
        setEnum(L, "KC_MUTE", OIS::KC_MUTE);
        setEnum(L, "KC_CALCULATOR", OIS::KC_CALCULATOR);
        setEnum(L, "KC_PLAYPAUSE", OIS::KC_PLAYPAUSE);
        setEnum(L, "KC_MEDIASTOP", OIS::KC_MEDIASTOP);
        setEnum(L, "KC_VOLUMEDOWN", OIS::KC_VOLUMEDOWN);
        setEnum(L, "KC_VOLUMEUP", OIS::KC_VOLUMEUP);
        setEnum(L, "KC_WEBHOME", OIS::KC_WEBHOME);
        setEnum(L, "KC_NUMPADCOMMA", OIS::KC_NUMPADCOMMA);
        setEnum(L, "KC_DIVIDE", OIS::KC_DIVIDE);
        setEnum(L, "KC_SYSRQ", OIS::KC_SYSRQ);
        setEnum(L, "KC_RMENU", OIS::KC_RMENU);
        setEnum(L, "KC_PAUSE", OIS::KC_PAUSE);
        setEnum(L, "KC_HOME", OIS::KC_HOME);
        setEnum(L, "KC_UP", OIS::KC_UP);
        setEnum(L, "KC_PGUP", OIS::KC_PGUP);
        setEnum(L, "KC_LEFT", OIS::KC_LEFT);
        setEnum(L, "KC_RIGHT", OIS::KC_RIGHT);
        setEnum(L, "KC_END", OIS::KC_END);
        setEnum(L, "KC_DOWN", OIS::KC_DOWN);
        setEnum(L, "KC_PGDOWN", OIS::KC_PGDOWN);
        setEnum(L, "KC_INSERT", OIS::KC_INSERT);
        setEnum(L, "KC_DELETE", OIS::KC_DELETE);
        setEnum(L, "KC_LWIN", OIS::KC_LWIN);
        setEnum(L, "KC_RWIN", OIS::KC_RWIN);
        setEnum(L, "KC_APPS", OIS::KC_APPS);
        setEnum(L, "KC_POWER", OIS::KC_POWER);
        setEnum(L, "KC_SLEEP", OIS::KC_SLEEP);
        setEnum(L, "KC_WAKE", OIS::KC_WAKE);
        setEnum(L, "KC_WEBSEARCH", OIS::KC_WEBSEARCH);
        setEnum(L, "KC_WEBFAVORITES", OIS::KC_WEBFAVORITES);
        setEnum(L, "KC_WEBREFRESH", OIS::KC_WEBREFRESH);
        setEnum(L, "KC_WEBSTOP", OIS::KC_WEBSTOP);
        setEnum(L, "KC_WEBFORWARD", OIS::KC_WEBFORWARD);
        setEnum(L, "KC_WEBBACK", OIS::KC_WEBBACK);
        setEnum(L, "KC_MYCOMPUTER", OIS::KC_MYCOMPUTER);
        setEnum(L, "KC_MAIL", OIS::KC_MAIL);
        setEnum(L, "KC_MEDIASELECT", OIS::KC_MEDIASELECT);

        setNestedClassTable(L, "OIS", "KeyCode");
        lua_pop(L, 1);
    }

    void registerOISKeyboardTextTranslationMode(lua_State* L)
    {
        lua_createtable(L, 0, 3);

        setEnum(L, "Off", OIS::Keyboard::Off);
        setEnum(L, "Unicode", OIS::Keyboard::Unicode);
        setEnum(L, "Ascii", OIS::Keyboard::Ascii);

        setNestedClassTable(L, "OIS.Keyboard", "TextTranslationMode");
        lua_pop(L, 1);
    }

    void registerOISKeyboardModifier(lua_State* L)
    {
        lua_createtable(L, 0, 3);

        setEnum(L, "Shift", OIS::Keyboard::Shift);
        setEnum(L, "Ctrl", OIS::Keyboard::Ctrl);
        setEnum(L, "Alt", OIS::Keyboard::Alt);

        setNestedClassTable(L, "OIS.Keyboard", "Modifier");
        lua_pop(L, 1);
    }

    // OIS/OISMouse.h

    void registerOISMouseButtonID(lua_State* L)
    {
        lua_createtable(L, 0, 8);

        setEnum(L, "MB_Left", OIS::MB_Left);
        setEnum(L, "MB_Right", OIS::MB_Right);
        setEnum(L, "MB_Middle", OIS::MB_Middle);
        setEnum(L, "MB_Button3", OIS::MB_Button3);
        setEnum(L, "MB_Button4", OIS::MB_Button4);
        setEnum(L, "MB_Button5", OIS::MB_Button5);
        setEnum(L, "MB_Button6", OIS::MB_Button6);
        setEnum(L, "MB_Button7", OIS::MB_Button7);

        setNestedClassTable(L, "OIS", "MouseButtonID");
        lua_pop(L, 1);
    }

    // OIS/OISException.h

    void registerOISOIS_ERROR(lua_State* L)
    {
        lua_createtable(L, 0, 9);

        setEnum(L, "E_InputDisconnected", OIS::E_InputDisconnected);
        setEnum(L, "E_InputDeviceNonExistant", OIS::E_InputDeviceNonExistant);
        setEnum(L, "E_InputDeviceNotSupported", OIS::E_InputDeviceNotSupported);
        setEnum(L, "E_DeviceFull", OIS::E_DeviceFull);
        setEnum(L, "E_NotSupported", OIS::E_NotSupported);
        setEnum(L, "E_NotImplemented", OIS::E_NotImplemented);
        setEnum(L, "E_Duplicate", OIS::E_Duplicate);
        setEnum(L, "E_InvalidParam", OIS::E_InvalidParam);
        setEnum(L, "E_General", OIS::E_General);

        setNestedClassTable(L, "OIS", "OIS_ERROR");
        lua_pop(L, 1);
    }

    // OIS/OISInterface.h

    void registerOISInterfaceIType(lua_State* L)
    {
        lua_createtable(L, 0, 2);

        setEnum(L, "ForceFeedback", OIS::Interface::ForceFeedback);
        setEnum(L, "Reserved", OIS::Interface::Reserved);

        setNestedClassTable(L, "OIS.Interface", "IType");
        lua_pop(L, 1);
    }

    // OIS/OISInputManager.h

    void registerOISInputManagerAddOnFactories(lua_State* L)
    {
        lua_createtable(L, 0, 3);

        setEnum(L, "AddOn_All", OIS::InputManager::AddOn_All);
        setEnum(L, "AddOn_LIRC", OIS::InputManager::AddOn_LIRC);
        setEnum(L, "AddOn_WiiMote", OIS::InputManager::AddOn_WiiMote);

        setNestedClassTable(L, "OIS.InputManager", "AddOnFactories");
        lua_pop(L, 1);
    }

    // OIS/OISEffect.h

    void registerOISEffectEForce(lua_State* L)
    {
        lua_createtable(L, 0, 6);

        setEnum(L, "UnknownForce", OIS::Effect::UnknownForce);
        setEnum(L, "ConstantForce", OIS::Effect::ConstantForce);
        setEnum(L, "RampForce", OIS::Effect::RampForce);
        setEnum(L, "PeriodicForce", OIS::Effect::PeriodicForce);
        setEnum(L, "ConditionalForce", OIS::Effect::ConditionalForce);
        setEnum(L, "CustomForce", OIS::Effect::CustomForce);

        setNestedClassTable(L, "OIS.Effect", "EForce");
        lua_pop(L, 1);
    }

    void registerOISEffectEType(lua_State* L)
    {
        lua_createtable(L, 0, 13);

        setEnum(L, "Unknown", OIS::Effect::Unknown);
        setEnum(L, "Constant", OIS::Effect::Constant);
        setEnum(L, "Ramp", OIS::Effect::Ramp);
        setEnum(L, "Square", OIS::Effect::Square);
        setEnum(L, "Triangle", OIS::Effect::Triangle);
        setEnum(L, "Sine", OIS::Effect::Sine);
        setEnum(L, "SawToothUp", OIS::Effect::SawToothUp);
        setEnum(L, "SawToothDown", OIS::Effect::SawToothDown);
        setEnum(L, "Friction", OIS::Effect::Friction);
        setEnum(L, "Damper", OIS::Effect::Damper);
        setEnum(L, "Inertia", OIS::Effect::Inertia);
        setEnum(L, "Spring", OIS::Effect::Spring);
        setEnum(L, "Custom", OIS::Effect::Custom);

        setNestedClassTable(L, "OIS.Effect", "EType");
        lua_pop(L, 1);
    }

    void registerOISEffectEDirection(lua_State* L)
    {
        lua_createtable(L, 0, 8);

        setEnum(L, "NorthWest", OIS::Effect::NorthWest);
        setEnum(L, "North", OIS::Effect::North);
        setEnum(L, "NorthEast", OIS::Effect::NorthEast);
        setEnum(L, "East", OIS::Effect::East);
        setEnum(L, "SouthEast", OIS::Effect::SouthEast);
        setEnum(L, "South", OIS::Effect::South);
        setEnum(L, "SouthWest", OIS::Effect::SouthWest);
        setEnum(L, "West", OIS::Effect::West);

        setNestedClassTable(L, "OIS.Effect", "EDirection");
        lua_pop(L, 1);
    }

    void registerOISEnumBindings(lua_State* L)
    {
        registerOISType(L);
        registerOISComponentType(L);
        registerOISKeyCode(L);
        registerOISKeyboardTextTranslationMode(L);
        registerOISKeyboardModifier(L);
        registerOISMouseButtonID(L);
        registerOISOIS_ERROR(L);
        registerOISInterfaceIType(L);
        registerOISInputManagerAddOnFactories(L);
        registerOISEffectEForce(L);
        registerOISEffectEType(L);
        registerOISEffectEDirection(L);
    }
}
