-- LuaLS regression fixture: documented dialogue globals, events, and enums.

if currentDialogue then
    local character = currentDialogue:getCharacter()
    if character then
        character:say("LuaLS fixture")
    end
end

local handlerId = Events.on("onGameLoaded", function()
    KenshiLua.logDebug("game loaded")
end)

Events.off(handlerId)

local longTermTag = CharacterPerceptionTags_LongTerm.LT_NONE
assert(type(longTermTag) == "number")
