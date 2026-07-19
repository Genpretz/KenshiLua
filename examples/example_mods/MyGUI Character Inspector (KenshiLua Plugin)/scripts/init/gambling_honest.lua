-- gambling_honest.lua
-- Sandboxed LUA_SCRIPT dialogue action for honest dice gambling.
-- Set this as the "run script" reference on the "Bet 1000 cats" line in FCS.

KenshiLua.log("=== Running: gambling_honest.lua ===")

-- Retrieve the active dialogue object exposed by C++ hook
local dialogue = currentDialogue
if not dialogue then
    KenshiLua.log("[Gambling] Error: Active dialogue (currentDialogue) not found.")
    return
end

local npc = dialogue:getCharacter()
local playerChar = dialogue:getConversationTarget()

if not npc or not playerChar then
    KenshiLua.log("[Gambling] Error: NPC or Player Character not found in dialogue.")
    return
end

-- Initialize math.random seed
math.randomseed(os.time())

-- 1. Roll dice (1 to 6)
local playerRoll = math.random(1, 6)
local npcRoll = math.random(1, 6)

KenshiLua.log(string.format("[Dice Game] Honest: Player Rolled %d, NPC Rolled %d", playerRoll, npcRoll))

-- 2. Close the dialogue window first to release the characters from the dialogue state lock
dialogue:endDialogue(true)

-- 3. Payout and dialogue responses in the game world, deferred to the next frame
local handlerId
handlerId = KenshiLua.registerHandler("onCharsUpdate", function()
    KenshiLua.unregisterHandler(handlerId)

    if playerRoll > npcRoll then
        -- Player wins: payout 2,000 cats (refund + 1,000 cats winnings)
        playerChar:takeMoney(-2000)
        npc:say(string.format("You rolled a %d. I rolled a %d. You win! Here is your 2,000 cats.", playerRoll, npcRoll))
    elseif playerRoll == npcRoll then
        -- Tie: refund 1,000 cats
        playerChar:takeMoney(-1000)
        npc:say(string.format("We both rolled a %d. It's a tie. Here is your 1,000 cats back.", playerRoll))
    else
        -- Player loses: NPC keeps the 1000 cats (no payout)
        npc:say(string.format("You rolled a %d. I rolled a %d. I win! Better luck next time.", playerRoll, npcRoll))
    end
end)

