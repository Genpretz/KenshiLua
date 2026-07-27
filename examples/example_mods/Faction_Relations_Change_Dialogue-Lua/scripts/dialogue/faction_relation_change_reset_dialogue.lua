-- faction_relation_change_reset.lua
-- Sandboxed LUA_SCRIPT dialogue action to set speaker faction's relationship level.
-- Set as "run script" reference on a dialogue line in FCS.

KenshiLua.log("=== Running: set_speaker_faction_relation.lua ===")

-- 1. Retrieve active dialogue object from C++ DialogueScriptBridge hook
local dialogue = currentDialogue
if not dialogue then
    KenshiLua.log("[DialogueAction] Error: active dialogue (currentDialogue) not found.")
    return
end

-- 2: Target specific named faction (uncomment below if targeting named faction instead)
local gw = getGameWorld and getGameWorld() or GameWorld
local factionMgr = gw and gw.factionMgr
local targetFaction1 = factionMgr and factionMgr:getFactionByName("Starving Bandits")
local targetFaction2 = factionMgr and factionMgr:getFactionByName("Dust Bandits")

if not targetFaction1 then
    KenshiLua.log("[DialogueAction] Error: Target faction '%s' not found.", targetFaction1:getName())
    return
end

if not targetFaction2 then
    KenshiLua.log("[DialogueAction] Error: Target faction '%s' not found.", targetFaction2:getName())
    return
end

-- 3. Get relations for both target factions
local relations1 = targetFaction1.relations
local relations2 = targetFaction2.relations

-- 4. Check current relation level and set new relation value (-100 to 100)
local currentRel1 = relations1:getFactionRelation(targetFaction2)
local currentRel2 = relations2:getFactionRelation(targetFaction1)

local newRel1 = 0.0 -- Set to max alliance (+100.0)
local newRel2 = 0.0 -- Set to max alliance (+100.0)

KenshiLua.log(string.format("[FactionRelation] Modifying relations for '%s' -> '%s'. Current: %.1f, New: %.1f",
    targetFaction1:getName(), targetFaction2:getName(), currentRel1, newRel1))

KenshiLua.log(string.format("[FactionRelation] Modifying relations for '%s' -> '%s'. Current: %.1f, New: %.1f",
    targetFaction2:getName(), targetFaction1:getName(), currentRel2, newRel2))

-- 5. Apply relation change via FactionRelations bindings
relations1:setRelation(targetFaction2, newRel1)
relations2:setRelation(targetFaction1, newRel2)

-- 6. End dialogue conversation
dialogue:endDialogue(true)
