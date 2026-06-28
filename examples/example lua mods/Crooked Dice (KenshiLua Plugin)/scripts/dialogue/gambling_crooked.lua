-- gambling_crooked.lua
-- Sandboxed LUA_SCRIPT dialogue action for crooked/cheated dice gambling.
-- Set this as the "run script" reference on the "[Crooked Dice] Bet 1000 cats" line in FCS.

KenshiLua.log("=== Running: gambling_crooked.lua ===")

-- Retrieve the active dialogue object exposed by C++ hook
local dialogue = currentDialogue
if not dialogue then
    KenshiLua.log("[Gambling] Error: Active dialogue (currentDialogue) not found.")
    return
end

local npc = dialogue:getCharacter()
local playerHand = dialogue:getConversationTarget()
local playerChar = playerHand and playerHand:getCharacter()

if not npc or not playerChar then
    KenshiLua.log("[Gambling] Error: NPC or Player Character not found in dialogue.")
    return
end

-- 1. Perform stat check (Thieving & Dexterity vs NPC Perception)
local playerStats = playerChar:getStats()
local npcStats = npc:getStats()

local playerThieving = math.floor(playerStats and playerStats:getThieving() or 0)
local playerDexterity = math.floor(playerStats and playerStats:getDexterity() or 0)
local npcPerception = math.floor(npcStats and npcStats:getPerception() or 0)

local playerCapability = (playerThieving + playerDexterity) / 2
local cheatChance = math.floor(50 + (playerCapability - npcPerception) + 0.5)
-- Clamp success chance between 5% and 95%
cheatChance = math.max(5, math.min(95, cheatChance))

-- Initialize math.random seed
math.randomseed(os.time())
local roll = math.random(1, 100)

KenshiLua.log(string.format("[Dice Game] Crooked: Thieving=%d, Dexterity=%d, NPC Perception=%d. Chance=%d%%, Roll=%d",
    playerThieving, playerDexterity, npcPerception, cheatChance, roll))

-- 2. Close the dialogue window first to release the characters from the dialogue state lock
dialogue:endDialogue(true)

-- 3. Process check result in the game world, deferred to the next frame
local handlerId
handlerId = KenshiLua.registerHandler("onCharsUpdate", function()
    KenshiLua.unregisterHandler(handlerId)

    if roll <= cheatChance then
        -- Success: Player cheats successfully, wins 2000 cats (refund + 1000 cats)
        playerChar:takeMoney(-2000)
        npc:say("Unbelievable luck! You got a 6. Here is your 2,000 cats.")
    else
        -- Caught: NPC shouts catchphrase, marks player as criminal, and attacks
        npc:say("I dont play with cheats!")
        npc:rememberCharacter(playerChar, "criminal")
        npc:attackTarget(playerChar)
    end
end)

