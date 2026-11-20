#include "pch.h"
#include "LuaScriptDiagnostics.h"
#include "LuaScriptReference.h"

#include <kenshi/GameWorld.h>
#include <kenshi/Globals.h>
#include <kenshi/Enums.h>

#include <sstream>

namespace KenshiLua
{
    int luaCheckLuaScriptReferences(lua_State* L)
    {
        if (!::ou)
        {
            lua_pushstring(L, "Error: GameWorld (ou) is not initialized.");
            return 1;
        }

        std::stringstream ss;
        ss << "--- Scanning GameData for 'run lua script' references ---\n";

        int scriptFieldCount = 0;

        const ogre_unordered_set<GameData*>::type& mainList = ::ou->gamedata.mainList;
        ss << "Total GameData items in mainList: " << mainList.size() << "\n\n";

        for (ogre_unordered_set<GameData*>::type::const_iterator it = mainList.begin();
             it != mainList.end(); ++it)
        {
            GameData* gd = *it;
            if (!gd)
                continue;

            const Ogre::vector<GameDataReference>::type* refList =
                gd->getReferenceListIfExists("run lua script");
            if (!refList || refList->empty())
                continue;

            ++scriptFieldCount;
            ss << "- Item Type: " << static_cast<int>(gd->type)
               << " (\"" << gd->stringID << "\" / \"" << gd->name << "\")\n";

            for (Ogre::vector<GameDataReference>::type::const_iterator refIt = refList->begin();
                 refIt != refList->end(); ++refIt)
            {
                ss << "    Reference ID: \"" << refIt->sid << "\"\n";
                if (gd->type == WORLD_EVENT_STATE)
                    ss << "      World state run mode: " << refIt->values.value[0] << "\n";

                const LuaScriptReferenceResult script =
                    readLuaScriptReference(gd, *refIt);
                if (script.isValid())
                {
                    ss << "      -> Lua script file: \"" << script.filename << "\"\n";
                }
                else
                {
                    ss << "      -> Invalid reference: "
                       << describeLuaScriptReferenceError(script) << "\n";
                }
            }
        }

        ss << "Total items with 'run lua script' references: " << scriptFieldCount << "\n";
        ss << "--- Scan Complete ---\n";

        lua_pushstring(L, ss.str().c_str());
        return 1;
    }
}
