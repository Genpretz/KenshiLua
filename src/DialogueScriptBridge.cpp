#include "pch.h"
#include "Lua/LuaLock.h"
#include "DialogueScriptBridge.h"
#include "LuaScriptReference.h"
#include "Lua/ScopedLuaGlobal.h"

#include <kenshi/GameData.h>
#include <kenshi/Dialogue.h>

#include "Logger.h"
#include "Plugin.h"
#include "Lua/LuaState.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Dialogue/DialogueBinding.h"
#include "Bindings/Kenshi/Dialogue/DialogLineDataBinding.h"
#include "ScriptLoader.h"

namespace KenshiLua
{
    void DialogueScriptBridge(Dialogue* thisptr, DialogLineData* dialogLine)
    {
        if (!Plugin::get().isInitialized() || !Plugin::get().isLuaThread())
            return;
        KenshiLua::ScopedLuaLock luaLock;

        logToFileDebug("DialogueScriptBridge entered.");
        if (!dialogLine)
        {
            logToFileDebug("DialogueScriptBridge: dialogLine is null.");
            return;
        }
        if (!dialogLine->data)
        {
            logToFileDebug("DialogueScriptBridge: dialogLine->data is null.");
            return;
        }

        GameData* gd = dialogLine->data;
        logToFileDebug("DialogueScriptBridge: Checking GameData item Type="
            + std::to_string((long long)gd->type) + " ID=" + gd->stringID
            + " Name=" + gd->name);

        const Ogre::vector<GameDataReference>::type* refList =
            gd->getReferenceListIfExists("run lua script");
        if (!refList)
            return;

        for (Ogre::vector<GameDataReference>::type::const_iterator it = refList->begin();
             it != refList->end(); ++it)
        {
            const LuaScriptReferenceResult script = readLuaScriptReference(gd, *it);
            if (!script.isValid())
            {
                logToFileError("DialogueScriptBridge: invalid 'run lua script' reference '"
                    + it->sid + "' on item '" + gd->stringID + "': "
                    + describeLuaScriptReferenceError(script));
                continue;
            }

            logToFileDebug("DialogueScriptBridge: Found Lua script file: " + script.filename);
            const std::string absolutePath =
                ScriptLoader::get().resolveScriptPath(script.filename);
            if (absolutePath.empty())
            {
                logToFileError("DialogueScriptBridge: could not resolve Lua script file '"
                    + script.filename + "' for reference '" + it->sid
                    + "' on item '" + gd->stringID + "'");
                continue;
            }

            lua_State* L = g_luaState ? g_luaState->getState() : NULL;
            if (!L)
            {
                logToFileError("DialogueScriptBridge: Lua state is unavailable for reference '"
                    + it->sid + "' on item '" + gd->stringID + "'");
                continue;
            }

            logToFile("DialogueScriptBridge: triggered dialogue action Lua script: "
                + script.filename);

            ScopedLuaGlobal dialogueGlobal(L, "currentDialogue");
            ScopedLuaGlobal lineGlobal(L, "currentDialogueLine");

            pushObject<Dialogue>(L, thisptr, DialogueBinding::getMetatableName());
            lua_setglobal(L, "currentDialogue");

            pushObject<DialogLineData>(L, dialogLine,
                DialogLineDataBinding::getMetatableName());
            lua_setglobal(L, "currentDialogueLine");

            const std::string chunkName = "@" + script.filename;
            ScriptLoader::get().runScriptReplacingPrevious(
                L, absolutePath, chunkName);
        }
    }
}
