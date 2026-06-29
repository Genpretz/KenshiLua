-- test_dialogue_callbacks.lua
-- Example script demonstrating KenshiLua Dialogue callback features.

KenshiLua.log("=== Loading: test_dialogue_callbacks.lua ===")

-- Build reverse mapping tables for enums to display string names in logs
local reverseEventTrigger = {}
if EventTrigger then
    for k, v in pairs(EventTrigger) do reverseEventTrigger[v] = k end
end

local reverseDialogCondition = {}
if DialogConditionEnum then
    for k, v in pairs(DialogConditionEnum) do reverseDialogCondition[v] = k end
end

local reverseComparison = {}
if Comparison then
    for k, v in pairs(Comparison) do reverseComparison[v] = k end
end

-- 1. Test Dialogue Condition Callback
-- Fires when dialogue conditions are checked.
-- Returning true/false overrides the game's check. Returning nil lets the original check run.
local conditionHandlerId = KenshiLua.registerHandler("onDialogueCondition", function(dialogue, conditionName, compareBy, val, target, actualTarget)
    local targetName = target and target:getName() or "nil"
    local actualTargetName = actualTarget and actualTarget:getName() or "nil"
    
    local condString = reverseDialogCondition[conditionName] or ("UnknownCondition(" .. tostring(conditionName) .. ")")
    local compString = reverseComparison[compareBy] or ("UnknownComparison(" .. tostring(compareBy) .. ")")
    
    KenshiLua.log(string.format("[DialogueCondition] Checked: condition=%s, compare=%s, val=%d, target=%s, actualTarget=%s",
        condString, compString, val, targetName, actualTargetName))

    -- Example: Intercept custom condition (e.g. 9999 for a custom sleeping or stat check)
    if conditionName == 9999 then
        KenshiLua.log("[DialogueCondition] Intercepted custom condition 9999! Forcing it to match (true).")
        return true
    end

    -- Return nil to fallback to normal game logic
    return nil
end)

-- 2. Test Dialogue Action Callback
-- Fires when dialogue actions are executed.
-- Returning false suppresses the original action execution.
local actionHandlerId = KenshiLua.registerHandler("onDialogueActions", function(dialogue, dialogLine)
    local lineName = dialogLine and dialogLine:getName() or "nil"
    KenshiLua.log(string.format("[DialogueActions] Triggered for line: %s", lineName))

    -- Print some information about the dialogue speaker and state
    local speakerChar = dialogue:getCharacter()
    local speakerName = speakerChar and speakerChar:getName() or "nil"
    KenshiLua.log("[DialogueActions] Speaker: " .. speakerName)
    KenshiLua.log("[DialogueActions] String ID: " .. tostring(dialogLine:getStringID()))
    KenshiLua.log("[DialogueActions] Money Cost: " .. tostring(dialogLine:getMoneyCostForLine()))
    
    -- Example: Suppress a specific line's actions if we want to handle them purely in Lua
    if lineName == "suppress_actions_test" then
        KenshiLua.log("[DialogueActions] Suppressing standard actions for line: suppress_actions_test")
        return false -- Suppress standard actions
    end

    -- Return true/nil to run standard actions
    return nil
end)

-- 3. Test Dialogue Event Callback
-- Fires when a dialogue event starts (covers sendEvent and sendEventOverride).
-- Returning true/false overrides the event trigger check. Returning nil runs the original.
local eventHandlerId = KenshiLua.registerHandler("onDialogueEvent", function(dialogue, character, eventTrigger, forceRepeat)
    local charName = character and character:getName() or "nil"
    local triggerString = reverseEventTrigger[eventTrigger] or ("UnknownTrigger(" .. tostring(eventTrigger) .. ")")
    
    KenshiLua.log(string.format("[DialogueEvent] Triggered event: trigger=%s, character=%s, forceRepeat=%s",
        triggerString, charName, tostring(forceRepeat)))

    -- Example: Intercept EV_PLAYER_TALK_TO_ME (which is EventTrigger.EV_PLAYER_TALK_TO_ME)
    -- If we want to block talking to specific characters:
    if eventTrigger == EventTrigger.EV_PLAYER_TALK_TO_ME then
        KenshiLua.log("[DialogueEvent] Player talked to me event intercepted for: " .. charName)
    end

    -- Return nil to let the engine handle it
    return nil
end)

KenshiLua.log("[test_dialogue_callbacks.lua] Registered Dialogue condition handler ID: " .. tostring(conditionHandlerId))
KenshiLua.log("[test_dialogue_callbacks.lua] Registered Dialogue actions handler ID: " .. tostring(actionHandlerId))
KenshiLua.log("[test_dialogue_callbacks.lua] Registered Dialogue event handler ID: " .. tostring(eventHandlerId))
