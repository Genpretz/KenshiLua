#include "pch.h"
#include "LuaScriptReference.h"

#include <sstream>

namespace KenshiLua
{
    LuaScriptReferenceResult::LuaScriptReferenceResult()
        : status(LUA_SCRIPT_REFERENCE_TARGET_NOT_FOUND), scriptData(NULL)
    {
    }

    bool LuaScriptReferenceResult::isValid() const
    {
        return status == LUA_SCRIPT_REFERENCE_OK;
    }

    LuaScriptReferenceResult readLuaScriptReference(
        GameData* owner,
        const GameDataReference& reference)
    {
        LuaScriptReferenceResult result;

        if (!owner || !owner->sourceContainer)
        {
            result.status = LUA_SCRIPT_REFERENCE_NO_SOURCE_CONTAINER;
            return result;
        }

        result.scriptData = reference.getPtr(owner->sourceContainer);
        if (!result.scriptData)
        {
            result.status = LUA_SCRIPT_REFERENCE_TARGET_NOT_FOUND;
            return result;
        }

        if (result.scriptData->type != LUA_SCRIPT_ITEM_TYPE)
        {
            result.status = LUA_SCRIPT_REFERENCE_WRONG_ITEM_TYPE;
            return result;
        }

        const auto fileIt = result.scriptData->filesdata.find("file");
        if (fileIt == result.scriptData->filesdata.end())
        {
            result.status = LUA_SCRIPT_REFERENCE_MISSING_FILE;
            return result;
        }

        result.filename = fileIt->second;
        if (result.filename.empty())
        {
            result.status = LUA_SCRIPT_REFERENCE_EMPTY_FILE;
            return result;
        }

        result.status = LUA_SCRIPT_REFERENCE_OK;
        return result;
    }

    std::string describeLuaScriptReferenceError(
        const LuaScriptReferenceResult& result)
    {
        switch (result.status)
        {
        case LUA_SCRIPT_REFERENCE_NO_SOURCE_CONTAINER:
            return "source item has no GameData container";
        case LUA_SCRIPT_REFERENCE_TARGET_NOT_FOUND:
            return "reference target was not found in the source container";
        case LUA_SCRIPT_REFERENCE_WRONG_ITEM_TYPE:
        {
            std::stringstream message;
            message << "reference target is not a LUA_SCRIPT (item type "
                    << static_cast<int>(result.scriptData->type) << ")";
            return message.str();
        }
        case LUA_SCRIPT_REFERENCE_MISSING_FILE:
            return "LUA_SCRIPT target has no 'file' field";
        case LUA_SCRIPT_REFERENCE_EMPTY_FILE:
            return "LUA_SCRIPT target has an empty 'file' field";
        case LUA_SCRIPT_REFERENCE_OK:
            return "";
        default:
            return "unknown Lua script reference error";
        }
    }
}
