#pragma once

#include <string>
#include <kenshi/GameData.h>

namespace KenshiLua
{
    // Custom FCS item type declared in assets/config/fcs.def. This value is not
    // part of KenshiLib's native itemType enum.
    static const itemType LUA_SCRIPT_ITEM_TYPE = static_cast<itemType>(322);

    enum LuaScriptReferenceStatus
    {
        LUA_SCRIPT_REFERENCE_OK = 0,
        LUA_SCRIPT_REFERENCE_NO_SOURCE_CONTAINER,
        LUA_SCRIPT_REFERENCE_TARGET_NOT_FOUND,
        LUA_SCRIPT_REFERENCE_WRONG_ITEM_TYPE,
        LUA_SCRIPT_REFERENCE_MISSING_FILE,
        LUA_SCRIPT_REFERENCE_EMPTY_FILE
    };

    struct LuaScriptReferenceResult
    {
        LuaScriptReferenceResult();

        bool isValid() const;

        LuaScriptReferenceStatus status;
        GameData* scriptData;
        std::string filename;
    };

    LuaScriptReferenceResult readLuaScriptReference(
        GameData* owner,
        const GameDataReference& reference);

    std::string describeLuaScriptReferenceError(
        const LuaScriptReferenceResult& result);
}
