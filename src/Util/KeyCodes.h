#pragma once

#include <string>
#include <map>
#include <OISKeyboard.h>

namespace KenshiLua
{
    const std::map<std::string, OIS::KeyCode>& getKeyMap();
    OIS::KeyCode parseKeyCode(const std::string& keyStr);
    std::string keyCodeToString(OIS::KeyCode code);
    std::string formatKeybind(bool ctrl, bool shift, bool alt, OIS::KeyCode key);
}
